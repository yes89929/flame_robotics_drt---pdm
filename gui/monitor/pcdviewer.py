'''
3D Visualizer for Simulation
@Author Byunghun Hwang<bh.hwang@iae.re.kr>
'''

import open3d as o3d
import time

class PCDViewer:
    def __init__(self):
        self.vis = o3d.visualization.Visualizer()
        self.vis.create_window(window_name='3D Viewer')
        self.geometry_list = []

    def draw_once(self):
        self.vis.poll_events()
        self.vis.update_renderer()

    def run(self):
        while True:
            self.draw_once()
            time.sleep(0.03)

    def destroy(self):
        self.vis.destroy_window()