#!/usr/bin/env python3
"""
Example usage of the Subscriber class from the pipeline module.
This demonstrates how to use the Subscriber API without directly dealing with ZMQ.
"""

import sys
import os
import time

# Add the common module to the path
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'common'))

from pipeline import Subscriber

def main():
    # Create a subscriber instance
    subscriber = Subscriber(q_size=100)
    
    # Connect to publisher address
    address = "tcp://localhost:5555"
    subscriber.join(address)
    print(f"Subscriber connected to {address}")
    
    # Subscribe to specific topics
    subscriber.subscribe("status")
    subscriber.subscribe("sensors")
    subscriber.subscribe("robot_status")
    subscriber.subscribe("alerts")
    subscriber.subscribe("coordinates")
    
    print(f"Subscribed to topics: {subscriber.get_subscribed_topics()}")
    print("Listening for messages... (Press Ctrl+C to stop)")
    
    try:
        while True:
            # Receive messages with a timeout
            topic, message = subscriber.receive_message(timeout_ms=1000)
            
            if topic is not None:
                print(f"Received on '{topic}': {message}")
                
                # Handle different message types
                if topic == "sensors" and isinstance(message, dict):
                    print(f"  -> Temperature: {message.get('temperature', 'N/A')}°C")
                    print(f"  -> Humidity: {message.get('humidity', 'N/A')}%")
                
                elif topic == "robot_status" and isinstance(message, dict):
                    pos = message.get('position', {})
                    print(f"  -> Robot at ({pos.get('x', 0)}, {pos.get('y', 0)}, {pos.get('z', 0)})")
                    print(f"  -> Battery: {message.get('battery', 'N/A')}%")
                
                elif topic == "alerts":
                    print(f"  -> ALERT: {message}")
            else:
                print(".", end="", flush=True)  # Show we're still listening
                
    except KeyboardInterrupt:
        print("\nShutting down subscriber...")
    
    # Clean up
    subscriber.close()
    print("Subscriber closed")

if __name__ == "__main__":
    main()
