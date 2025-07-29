"""
Robot Control Algorithm Plugin
"""

from python.base.plugin_pd import PluginPDMBase

class Simple(PluginPDMBase):
    def find_pose(self):
        print("Find Pose with Simple")