
import sys, os, platform
import open3d as o3d
import numpy as np
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering

class AppWindow:

    def __init__(self, config:dict):
        self.__config = config
        pass