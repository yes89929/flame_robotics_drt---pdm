'''
3D Visualizer for Simulation
@Author Byunghun Hwang<bh.hwang@iae.re.kr>
'''

try:
    # using PyQt6
    from PyQt6.QtGui import QImage, QPixmap, QCloseEvent, QStandardItem, QStandardItemModel
    from PyQt6.QtWidgets import QApplication, QFrame, QMainWindow, QLabel, QPushButton, QCheckBox, QComboBox, QDialog
    from PyQt6.QtWidgets import QMessageBox, QProgressBar, QFileDialog, QComboBox, QLineEdit, QSlider, QVBoxLayout
    from PyQt6.QtCore import QObject, Qt, QTimer, QThread, pyqtSignal
except ImportError:
    print("PyQt6 is required to run this application.")

import open3d as o3d
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering
import os
import time
import threading
from multiprocessing import Process, Event
from util.logger.console import ConsoleLogger


class Graphic3DWindow:
    def __init__(self, config:dict):
        super().__init__()

        self.__config = config  # copy configuration data
        self.__stop_event = Event()
        self.__vis = None
        self.__geometries = []

        self.__render_proc = Process(target=self._run, args=(self.__stop_event,), daemon=True)
    
    def start(self):
        """ start graphic 3d viewer """
        self.__render_proc.start()

    def close(self):
        """ close graphic 3d viewer """
        self.__stop_event.set()
        self.__render_proc.join(timeout=3)

    def _run(self, stop_event):
        self.__vis = o3d.visualization.Visualizer()
        self.__vis.create_window(window_name='3D Graphic Viewer')
        self.__vis.get_render_option().background_color = [0.9, 0.9, 0.9]

        box = o3d.geometry.TriangleMesh.create_box()
        box.paint_uniform_color([0.2, 0.8, 0.2])
        box.compute_vertex_normals()
        self.__vis.add_geometry(box)
        self.__geometries.append(box)

        while not stop_event.is_set():
            self.__vis.poll_events()
            self.__vis.update_renderer()
            time.sleep(0.03)
            self.__console.debug("Rendering...")

        self.__vis.destroy_window()
        

    def add_box(self):
        box = o3d.geometry.TriangleMesh.create_box()
        box.paint_uniform_color([0.2, 0.8, 0.2])
        box.compute_vertex_normals()
        self.geometry_list.append(box)
        self.vis.add_geometry(box)



    def _add_geometry(self, geometry, name):
        # 각 지오메트리에 고유한 이름 부여
        key = f"{name}_{self.counter}"
        self.scene.scene.add_geometry(key, geometry, rendering.MaterialRecord())
        self.geometry_map[key] = geometry
        self.counter += 1
        self._fit_scene()

    def _add_box(self):
        mesh = o3d.geometry.TriangleMesh.create_box(1, 1, 1)
        mesh.paint_uniform_color([0.2, 0.8, 0.2])
        mesh.compute_vertex_normals()
        self._add_geometry(mesh, "box")

    def _add_sphere(self):
        mesh = o3d.geometry.TriangleMesh.create_sphere(radius=0.5)
        mesh.paint_uniform_color([1, 0.5, 0])
        mesh.compute_vertex_normals()
        self._add_geometry(mesh, "sphere")

    def _add_pcd(self):
        if not os.path.exists("example.pcd"):
            print("example.pcd 파일이 현재 폴더에 없습니다.")
            return
        pcd = o3d.io.read_point_cloud("example.pcd")
        mat = rendering.MaterialRecord()
        mat.shader = "defaultUnlit"
        mat.point_size = 5
        key = f"pcd_{self.counter}"
        self.scene.scene.add_geometry(key, pcd, mat)
        self.geometry_map[key] = pcd
        self.counter += 1
        self._fit_scene()

    def _add_stl(self):
        if not os.path.exists("model.stl"):
            print("model.stl 파일이 현재 폴더에 없습니다.")
            return
        mesh = o3d.io.read_triangle_mesh("model.stl")
        mesh.compute_vertex_normals()
        mesh.paint_uniform_color([0.4, 0.4, 1.0])
        self._add_geometry(mesh, "stl")

    def _clear_all(self):
        for name in list(self.geometry_map.keys()):
            self.scene.scene.remove_geometry(name)
        self.geometry_map.clear()
        self.counter = 0

    def _fit_scene(self):
        bounds = self.scene.scene.bounding_box
        self.scene.setup_camera(60, bounds, bounds.get_center())



    # def run(self):
    #     """ run render """
    #     while not self.__render_stop_event.is_set():
    #         try:
    #             self.__vis.poll_events()
    #             time.sleep(0.1)  # Control the frame rate
    #             print("render")
    #         except Exception as e:
    #             self.__console.error(f"Error in PCDViewer : {e}")
    #             break

    #     # while not self.isInterruptionRequested():
    #     #     try:
    #     #         # self.__vis.poll_events()
    #     #         # self.__vis.update_renderer()
    #     #         time.sleep(0.1)  # Control the frame rate
    #     #         print("render")
    #     #     except Exception as e:
    #     #         self.__console.error(f"Error in PCDViewer : {e}")
    #     #         break

    # def add_geometry(self, geometry):
    #     if geometry is not None:
    #         self.__geometry_list.append(geometry)
    #         self.__vis.add_geometry(geometry)
    #     else:
    #         print("Geometry is None, cannot add to viewer.")

    # def remove_geometry(self, geometry):
    #     if geometry in self.__geometry_list:
    #         self.__geometry_list.remove(geometry)
    #         self.__vis.remove_geometry(geometry)
    #     else:
    #         print("Geometry not found in viewer.")

    # def add_pcd(self, pcd_file:str):
    #     pcd = o3d.io.read_point_cloud(pcd_file)
    #     self.add_geometry(pcd)

        """
        # ✅ 2. Box 생성 및 추가
box = o3d.geometry.TriangleMesh.create_box(width=1.0, height=1.0, depth=1.0)
box.paint_uniform_color([0.2, 0.8, 0.2])
box.translate([2, 0, 0])
viewer.add_geometry(box)

# ✅ 3. STL 파일 로드 및 추가
stl = o3d.io.read_triangle_mesh("model.stl")  # 🔁 파일 경로 수정 필요
stl.compute_vertex_normals()
stl.paint_uniform_color([0.5, 0.5, 1.0])
stl.translate([-2, 0, 0])
viewer.add_geometry(stl)
"""

