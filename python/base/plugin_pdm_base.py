"""
DRT Pose Detection Plugin Base
@author bh.hwang@iae.re.kr
"""

from abc import ABC, abstractmethod

class PluginPDMBase(ABC):

    @abstractmethod
    def find_pose(self):
        pass