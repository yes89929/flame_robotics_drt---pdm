"""
Pose Detection Algorithm Plugin
"""

from python.base.plugin_pdm_base import PluginPDMBase

class Simple(PluginPDMBase):
    def find_pose(self):
        print("Find Pose with Simple")