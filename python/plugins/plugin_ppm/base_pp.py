"""
PlugIn Base Classes for DRT
"""

from abc import ABC, abstractmethod
from typing import List, Tuple
import numpy as np
from util.logger.console import ConsoleLogger


class PluginPPBase(ABC):
    """ Path Planning & Trajectory Generation Plugin Base Class """

    @abstractmethod
    def find_path_cartesian(self, pcd:np.ndarray, pos_current:np.ndarray, pos_target:np.ndarray) -> List[np.ndarray]:
        """
        (input) pcd : PCD data as numpy array) (shape: (N, 3))
        (Input) pos_current : Current TCP Pose (shape: (4,4))
        (Input) pos_target : Target TCP Pose (shape: (4,4))
        (Output) trajectory : List of waypoints in Cartesian Space, each waypoint is represented as a numpy array of shape (4,4) transformation matrix
        """
        pass
    
    @abstractmethod
    def find_path_joint(self, pcd:np.ndarray, pos_current:np.ndarray, pos_target:np.ndarray) -> List[np.ndarray]:
        """
        (input) pcd : PCD data as numpy array) (shape: (N, 3))
        (Input) pos_current : Current Joint Position [j1.. jn] (shape: (n, 1))
        (Input) pos_target : Target Joint Position [j1.. jn] (shape: (n, 1))
        (Output) trajectory : List of waypoints in Joint Space, each waypoint is represented as a numpy array of shape (n, 1) joint positions
        """
        pass