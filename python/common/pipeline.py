"""
Data & Message Pipeline
"""

import zmq
from abc import ABCMeta, abstractmethod
import json

class Pipe(metaclass=ABCMeta):
    def __init__(self, context=None):
        self.context = context or zmq.Context.instance()
        self.socket = None

    @abstractmethod
    def join(self, addr:str):
        pass

    def close(self):
        if self.socket:
            self.socket.close()

class Subscriber(Pipe):
    """ 
    Subscriber class for receiving messages from publishers.
    Provides a clean API that abstracts ZMQ implementation details.
    """
    def __init__(self, context=None, q_size:int=10):
        super().__init__(context)
        self.socket = self.context.socket(zmq.SUB)
        self.socket.setsockopt(zmq.RCVHWM, q_size)
        self.socket.setsockopt(zmq.RCVTIMEO, 500)
        self.socket.setsockopt(zmq.LINGER, 0)
        self._subscribed_topics = set()

    def join(self, addr:str):
        """
        Connect to the specified publisher address.
        
        Args:
            addr (str): Address to connect to (e.g., "tcp://localhost:5555")
        """
        self.socket.connect(addr)

    def subscribe(self, topic:str=""):
        """
        Subscribe to a specific topic or all topics.
        
        Args:
            topic (str): Topic to subscribe to. Empty string subscribes to all topics.
        """
        self.socket.setsockopt(zmq.SUBSCRIBE, topic.encode('utf-8'))
        self._subscribed_topics.add(topic)

    def unsubscribe(self, topic:str=""):
        """
        Unsubscribe from a specific topic.
        
        Args:
            topic (str): Topic to unsubscribe from
        """
        self.socket.setsockopt(zmq.UNSUBSCRIBE, topic.encode('utf-8'))
        self._subscribed_topics.discard(topic)

    def receive_message(self, timeout_ms:int=None):
        """
        Receive a message from any subscribed topic.
        
        Args:
            timeout_ms (int): Timeout in milliseconds. None uses default socket timeout.
            
        Returns:
            tuple: (topic, message) or (None, None) if timeout
        """
        if timeout_ms is not None:
            original_timeout = self.socket.getsockopt(zmq.RCVTIMEO)
            self.socket.setsockopt(zmq.RCVTIMEO, timeout_ms)
        
        try:
            # Receive multipart message: [topic, message]
            parts = self.socket.recv_multipart(zmq.NOBLOCK)
            if len(parts) >= 2:
                topic = parts[0].decode('utf-8')
                message_str = parts[1].decode('utf-8')
                
                # Try to parse as JSON, fall back to string
                try:
                    message = json.loads(message_str)
                except json.JSONDecodeError:
                    message = message_str
                
                return topic, message
        except zmq.Again:
            # Timeout occurred
            return None, None
        finally:
            if timeout_ms is not None:
                self.socket.setsockopt(zmq.RCVTIMEO, original_timeout)
        
        return None, None

    def get_subscribed_topics(self):
        """
        Get the list of currently subscribed topics.
        
        Returns:
            set: Set of subscribed topic strings
        """
        return self._subscribed_topics.copy()

    def on_subscribe(self, topic:str, message:json):
        """
        Override this method to handle incoming messages.
        This is called automatically when a message is received.
        
        Args:
            topic (str): Topic of the received message
            message: Parsed message data
        """
        pass



class Publisher(Pipe):
    """ 
    Publisher class for sending messages to subscribers.
    Provides a clean API that abstracts ZMQ implementation details.
    """
    def __init__(self, context=None, q_size:int=10):
        super().__init__(context)
        self.socket = self.context.socket(zmq.PUB)
        self.socket.setsockopt(zmq.SNDHWM, q_size)
        self.socket.setsockopt(zmq.LINGER, 0)
        self._is_connected = False

    def join(self, addr:str):
        """
        Bind to the specified address to start publishing.
        
        Args:
            addr (str): Address to bind to (e.g., "tcp://*:5555")
        """
        self.socket.bind(addr)
        self._is_connected = True

    def publish(self, topic:str, message):
        """
        Publish a message to a specific topic.
        
        Args:
            topic (str): Topic name for the message
            message: Message data (dict, list, str, or any JSON-serializable object)
        
        Raises:
            RuntimeError: If publisher is not connected to an address
            ValueError: If message cannot be serialized to JSON
        """
        if not self._is_connected:
            raise RuntimeError("Publisher must be connected to an address before publishing. Call join() first.")
        
        try:
            # Convert message to JSON string if it's not already a string
            if isinstance(message, str):
                message_str = message
            else:
                message_str = json.dumps(message)
            
            # Send multipart message: [topic, message]
            self.socket.send_multipart([
                topic.encode('utf-8'),
                message_str.encode('utf-8')
            ])
        except (TypeError, ValueError) as e:
            raise ValueError(f"Message cannot be serialized to JSON: {e}")

    def publish_string(self, topic:str, message:str):
        """
        Publish a string message to a specific topic.
        
        Args:
            topic (str): Topic name for the message
            message (str): String message to publish
        """
        self.publish(topic, message)

    def publish_data(self, topic:str, data:dict):
        """
        Publish structured data to a specific topic.
        
        Args:
            topic (str): Topic name for the message
            data (dict): Dictionary data to publish
        """
        self.publish(topic, data)

    def is_connected(self) -> bool:
        """
        Check if the publisher is connected and ready to publish.
        
        Returns:
            bool: True if connected, False otherwise
        """
        return self._is_connected