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
    """ subscriber """
    def __init__(self, context=None, q_size:int=10):
        super().__init__(context)
        self.socket = self.context.socket(zmq.SUB)
        self.socket.setsockopt(zmq.RCVHWM, q_size)
        self.socket.setsockopt(zmq.RCVTIMEO, 500)
        self.socket.setsockopt(zmq.LINGER, 0)

    def join(self, addr:str):
        self.socket.connect(addr)

    def on_subscribe(self, topic:str, message:json):
        pass

class Publisher(Pipe):
    """ publisher """
    def __init__(self, context=None, q_size:int=10):
        super().__init__(context)
        self.socket = self.context.socket(zmq.PUB)
        self.socket.setsockopt(zmq.SNDHWM, q_size)
        self.socket.setsockopt(zmq.LINGER, 0)

    def join(self, addr:str):
        self.socket.bind(addr)

    def publish(self, topic:str, message:json):
        pass