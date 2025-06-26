"""
DRT Robot Control Plugin Base
@author bh.hwang@iae.re.kr
"""

from abc import ABC, abstractmethod

class PluginRCMBase(ABC):

    @abstractmethod
    def find_path(self):
        pass