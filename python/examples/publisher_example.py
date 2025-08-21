#!/usr/bin/env python3
"""
Example usage of the Publisher class from the pipeline module.
This demonstrates how to use the Publisher API without directly dealing with ZMQ.
"""

import sys
import os
import time
import json

# Add the common module to the path
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'common'))

from pipeline import Publisher

def main():
    # Create a publisher instance
    publisher = Publisher(q_size=100)
    
    # Connect to an address (bind for publisher)
    address = "tcp://*:5555"
    publisher.join(address)
    print(f"Publisher bound to {address}")
    
    # Example 1: Publish string messages
    print("Publishing string messages...")
    for i in range(5):
        publisher.publish_string("status", f"System status update #{i}")
        time.sleep(0.5)
    
    # Example 2: Publish structured data
    print("Publishing structured data...")
    sensor_data = {
        "timestamp": time.time(),
        "temperature": 23.5,
        "humidity": 45.2,
        "location": "sensor_01"
    }
    publisher.publish_data("sensors", sensor_data)
    
    # Example 3: Publish different data types
    print("Publishing various data types...")
    
    # List data
    coordinates = [10.5, 20.3, 15.7]
    publisher.publish("coordinates", coordinates)
    
    # Dictionary data
    robot_status = {
        "position": {"x": 1.0, "y": 2.0, "z": 0.5},
        "battery": 85,
        "mode": "autonomous"
    }
    publisher.publish("robot_status", robot_status)
    
    # String data
    publisher.publish("alerts", "Low battery warning")
    
    print("Publishing complete!")
    
    # Check connection status
    print(f"Publisher connected: {publisher.is_connected()}")
    
    # Clean up
    publisher.close()
    print("Publisher closed")

if __name__ == "__main__":
    main()
