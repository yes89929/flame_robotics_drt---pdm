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

import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering
import os
import open3d as o3d
import time
import threading
import multiprocessing
from util.logger.console import ConsoleLogger
import zmq
import json
import numpy as np


class Graphic3DWindow():
    
    # geometry container to manage the visualizing object
    _geometry_container = {}

    def __init__(self, config:dict):
        super().__init__()

        # multiprocessing.set_start_method('spawn')
        self.__console = ConsoleLogger.get_logger() # logger

        self._config = config  # copy configuration data
        self._stop_render_event = multiprocessing.Event()
        self._stop_zmq_event = threading.Event()
        self._vis = None

        # manage zmq interface
        self.context = zmq.Context(1)
        self._socket = self.context.socket(zmq.SUB)
        self._socket.setsockopt(zmq.RCVBUF .RCVHWM, 100)
        self._socket.setsockopt(zmq.RCVTIMEO, 500)
        self._socket.setsockopt(zmq.LINGER, 0)
        self._socket.connect("tcp://localhost:9000")
        self._socket.subscribe("call")

        try:
            # [note!!] shared queue must be passed to the multiprocessing process first
            self._shared_queue = multiprocessing.Queue()
            self._render_proc = multiprocessing.Process(target=self._render_process, args=(self._stop_render_event, self._shared_queue,), daemon=True)
            self._render_proc.start()

            self._zmq_pipeline_thread = threading.Thread(target=self.zmq_recv_process, args=(self._stop_zmq_event, self._shared_queue,), daemon=True)
            self._zmq_pipeline_thread.start()
        except Exception as e:
            self.__console.debug("[Graphic 3D Window] Failed to create 3D rendering process")

        self.__console.debug("[Graphic 3D Window] Start Graphic 3D Viewer")

    def zmq_recv_process(self, stop_event, queue:multiprocessing.Queue):
        """ zmq pipeline process for receiving data """

        poller = zmq.Poller()
        poller.register(self._socket, zmq.POLLIN)
        
        while not stop_event.is_set():
            try:
                events = dict(poller.poll(1000)) # wait 1 sec
                if self._socket in events:
                    if events[self._socket] == zmq.POLLIN:
                        # for 'call' topic
                        topic, msg = self._socket.recv_multipart()
                        if topic.decode() == "call":
                            data = json.loads(msg.decode('utf8').replace("'", '"'))
                            queue.put(data)  # put data into the shared queue
                
            except json.JSONDecodeError as e:
                print(f"[Graphic 3D Window] {e}")
                continue
            except zmq.ZMQError as e:
                print(f"[Graphic 3D Window] {e}")
                break
            except Exception as e:
                print(f"[Graphic 3D Window] {e}")
                break

        poller.unregister(self._socket)

    def close(self):
        """ close graphic 3d viewer """
        # terminate process
        self._stop_render_event.set()
        self._render_proc.join(timeout=3)

        # zmq pipeline terminate
        self._stop_zmq_event.set()
        self._zmq_pipeline_thread.join(timeout=3)

        try:
            self._socket.setsockopt(zmq.LINGER, 0)
            #self._poller.unregister(self.__socket)
            self._socket.close()

            self.context.destroy(0)
        except zmq.ZMQError as e:
            print(f"[Graphic 3D Window] {e}")


    @staticmethod
    def _render_process(stop_event, queue:multiprocessing.Queue):
        try:
            console = ConsoleLogger.get_logger()
            import open3d as o3d

            # create 3d window
            _vis = o3d.visualization.Visualizer()
            _vis.create_window(window_name='3D Graphic Viewer', width=1920, height=1920, left=50, top=50)
            _vis.get_render_option().background_color = [1.0, 1.0, 1.0]

            while not stop_event.is_set():
                while not queue.empty():
                    msg = queue.get()
                    Graphic3DWindow.geometry_manage(_vis, msg) # JSON-style message process interface
                _vis.poll_events()
                _vis.update_renderer()
                time.sleep(0.03)
        except Exception as e:
            console.error(f"[Graphic 3D Window] Error in rendering: {e}")

        _vis.destroy_window()
        Graphic3DWindow._geometry_container.clear()
        console.debug("[Graphic 3D Window] Render process terminated.")
    
    @staticmethod
    def geometry_manage(visualizer:o3d.visualization.Visualizer, msg:dict) -> None:
        try:
            # static function call
            function_name = msg["function"]
            function = getattr(Graphic3DWindow, function_name)
            kwargs = msg["kwargs"]
            function(visualizer, **kwargs)
        except Exception as e:
            print(f"[3D Viewer] Exception : {e}")

    @staticmethod
    def API_add_pcd(vis, name:str, path:str, pos:list=[0,0,0], ori:list=[0,0,0], color:list=[0,0,0]):
        obj = o3d.io.read_point_cloud(path)
        if not obj.has_points():
            print(f"[API_add_pcd] PCD has no points")
            return None
        
        R = obj.get_rotation_matrix_from_axis_angle(axis_angle=ori) # rotation
        obj.rotate(R, center=(0, 0, 0))
        obj.translate(translation=pos, relative=False) # translation
        
        num_points = np.asarray(obj.points).shape[0]
        black_colors = np.tile(color, (num_points, 1))  # shape: (N, 3)
        obj.colors = o3d.utility.Vector3dVector(black_colors)

        if not name in Graphic3DWindow._geometry_container.keys():
            Graphic3DWindow._geometry_container[name] = obj
            vis.add_geometry(obj, reset_bounding_box=True)
        else:
            print(f"[API_add_pcd] Already added {name} in geomery container")

    @staticmethod
    def API_remove_geometry(vis, name:str) -> None:
        if name in Graphic3DWindow._geometry_container.keys():
            vis.remove_geometry(Graphic3DWindow._geometry_container[name])
            del Graphic3DWindow._geometry_container[name]
        else:
            print(f"[API_remove_geometry] {name} geometry cannot find in geometry container")
        
    
    @staticmethod
    def API_add_coord_frame(vis, name:str, pos:list=[0,0,0], ori:list=[0,0,0], size:float=0.1) -> None:
        obj = o3d.geometry.TriangleMesh.create_coordinate_frame(size=size, origin=pos)
        R = obj.get_rotation_matrix_from_axis_angle(axis_angle=np.array(ori).reshape(3, 1)) # rotation
        print("rotation matrix:", R)
        obj.rotate(rotation=R, center=(0, 0, 0))
        obj.translate(translation=pos, relative=False)
        if not name in Graphic3DWindow._geometry_container.keys():
            Graphic3DWindow._geometry_container[name] = obj
            vis.add_geometry(obj, reset_bounding_box=True)
        else:
            print(f"[api_add_coord_frame] Already added {name} in geomery container")

    @staticmethod
    def API_add_box(vis, name:str, pos:list=[0,0,0], ori:list=[0,0,0], size:list=[1.0, 1.0, 1.0], color:list=[0,0,0]):
        obj = o3d.geometry.TriangleMesh.create_box(width=size[0], height=size[1], depth=size[2])
        obj.compute_vertex_normals()
        obj.paint_uniform_color(color=color)
        R = obj.get_rotation_matrix_from_axis_angle(axis_angle=ori) # rotation
        obj.rotate(R, center=(0, 0, 0))
        obj.translate(translation=pos, relative=False)
        if not name in Graphic3DWindow._geometry_container.keys():
            Graphic3DWindow._geometry_container[name] = obj
            vis.add_geometry(obj, reset_bounding_box=True)
        else:
            print(f"[api_add_coord_frame] Already added {name} in geomery container")

        # if "function" in msg:
        #     print(f"{msg}")
        #     # show origin coord function
        #     if msg["function"] == "show_origin_coord":
        #         args = msg["args"]
        #         if args["show"]:
        #             print(f"add geometry : {_geometries.keys()}")
        #             if not "origin_coord" in _geometries.keys():
        #                 _geometries["origin_coord"] = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.1, origin=[0, 0, 0])
        #                 _vis.add_geometry(_geometries["origin_coord"], reset_bounding_box=True)
        #                 # _vis.update_geometry(_geometries["origin_coord"])                                   

        #         else:
        #             _vis.remove_geometry(_geometries["origin_coord"], reset_bounding_box=False)
        #             del _geometries["origin_coord"]
        #             print(f"remove geometry : {_geometries.keys()}")

        #     # open pcd
        #     elif msg["function"] == "open_pcd":
        #         args = msg["args"]
        #         print(f"path : {args['path']}")

    # def add_box(self):
    #     box = o3d.geometry.TriangleMesh.create_box()
    #     box.paint_uniform_color([0.2, 0.8, 0.2])
    #     box.compute_vertex_normals()
    #     self.geometry_list.append(box)
    #     self.vis.add_geometry(box)



    # def _add_geometry(self, geometry, name):
    #     # 각 지오메트리에 고유한 이름 부여
    #     key = f"{name}_{self.counter}"
    #     self.scene.scene.add_geometry(key, geometry, rendering.MaterialRecord())
    #     self.geometry_map[key] = geometry
    #     self.counter += 1
    #     self._fit_scene()

    # def _add_box(self):
    #     mesh = o3d.geometry.TriangleMesh.create_box(1, 1, 1)
    #     mesh.paint_uniform_color([0.2, 0.8, 0.2])
    #     mesh.compute_vertex_normals()
    #     self._add_geometry(mesh, "box")

    # def _add_sphere(self):
    #     mesh = o3d.geometry.TriangleMesh.create_sphere(radius=0.5)
    #     mesh.paint_uniform_color([1, 0.5, 0])
    #     mesh.compute_vertex_normals()
    #     self._add_geometry(mesh, "sphere")

    # def _add_pcd(self):
    #     if not os.path.exists("example.pcd"):
    #         print("example.pcd 파일이 현재 폴더에 없습니다.")
    #         return
    #     pcd = o3d.io.read_point_cloud("example.pcd")
    #     mat = rendering.MaterialRecord()
    #     mat.shader = "defaultUnlit"
    #     mat.point_size = 5
    #     key = f"pcd_{self.counter}"
    #     self.scene.scene.add_geometry(key, pcd, mat)
    #     self.geometry_map[key] = pcd
    #     self.counter += 1
    #     self._fit_scene()

    # def _add_stl(self):
    #     if not os.path.exists("model.stl"):
    #         print("model.stl 파일이 현재 폴더에 없습니다.")
    #         return
    #     mesh = o3d.io.read_triangle_mesh("model.stl")
    #     mesh.compute_vertex_normals()
    #     mesh.paint_uniform_color([0.4, 0.4, 1.0])
    #     self._add_geometry(mesh, "stl")

    # def _clear_all(self):
    #     for name in list(self.geometry_map.keys()):
    #         self.scene.scene.remove_geometry(name)
    #     self.geometry_map.clear()
    #     self.counter = 0

    # def _fit_scene(self):
    #     bounds = self.scene.scene.bounding_box
    #     self.scene.setup_camera(60, bounds, bounds.get_center())



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

