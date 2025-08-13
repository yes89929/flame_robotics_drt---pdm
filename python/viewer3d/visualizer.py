"""
3D Visualizer using Open3D
"""
import os
import open3d as o3d
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering
import trimesh
import time
import zmq
import json
import numpy as np
import threading
# from pykin.robots.robot import Robot

from util.logger.console import ConsoleLogger
from urdf_parser import URDF
from viewer3d.geomerty import geometryAPI
from math import pi, cos, sin
from pytransform3d import rotations, transformations
import math

class Open3DVisualizer():
    _geometry_container = {}

    def __init__(self, config:dict, pipe_context:zmq.Context):
        super().__init__()

        # initialize
        self.__config = config
        self.__console = ConsoleLogger.get_logger() # logger
        gui.Application.instance.initialize() # gui

        # create window and scene
        self._window = gui.Application.instance.create_window(title=config["window_title"], 
                                                              width=self.__config.get("window_size", [1280, 720])[0],
                                                              height=self.__config.get("window_size", [1280, 720])[1])
        self._scene = gui.SceneWidget()
        self._scene.scene = rendering.Open3DScene(self._window.renderer)
        self._scene.scene.set_background(self.__config.get("background-color", [1.0, 1.0, 1.0, 1.0])) # RGBA
        self._scene.scene.scene.set_sun_light([-1, -1, -1], [1, 1, 1], 100000)
        self._scene.scene.scene.enable_sun_light(True)        

        # camera parameter
        intrinsics = o3d.camera.PinholeCameraIntrinsic(640, 480, 525, 525, 320, 240)
        extrinsic = np.eye(4)
        extrinsic[:3, :3] = rotations.active_matrix_from_extrinsic_euler_xyz([math.radians(90), 0, 0])
        extrinsic[0:3, 3] = [-2.5, 1.0, 4.0]

        # viewpoint 
        view_bbox = o3d.geometry.AxisAlignedBoundingBox([-3, -3, -3], [3, 3, 3])
        self._scene.setup_camera(intrinsics, extrinsic, view_bbox)
        # self._scene.setup_camera(60, view_bbox, [2.5, 2.5, 2])
        self._window.add_child(self._scene)

        # initial geometry show
        self.__show_origin_coord = self.__config.get("show_origin", False)
        self.on_show_origin_coord()
        self.__show_robot = self.__config.get("show_robot", False)
        self.on_show_urdf()
        self.__show_floor = self.__config.get("show_floor", False)
        self.on_show_floor()

        # close event
        self._window.set_on_close(self.close)

        # key event callbacks
        self._window.set_on_key(self.on_key_event)

        # zmq message/data pipeline
        self.__socket_sub = pipe_context.socket(zmq.SUB)
        self.__socket_sub.setsockopt(zmq.RCVHWM, 100)
        self.__socket_sub.setsockopt(zmq.RCVTIMEO, 500)
        self.__socket_sub.setsockopt(zmq.LINGER, 0)
        self.__socket_sub.connect(f"{config['pipeline_transport']}://localhost:{config['pipeline_port']}")
        self.__socket_sub.subscribe("call")

        # threading for meg pipeline subscriber
        self.__stop_pipe_event = threading.Event()
        self.__pipe_worker = threading.Thread(target=self.__pipe_sub_process, args=(self.__stop_pipe_event,), daemon=False)
        self.__pipe_worker.start()

        # flags
        self.__show_origin_coord = False

    def __pipe_sub_process(self, stop_event):
        """ subscriber process """
        poller = zmq.Poller()
        poller.register(self.__socket_sub, zmq.POLLIN)

        while not stop_event.is_set():
            try:
                events = dict(poller.poll(1000)) # wait 1 sec
                if self.__socket_sub in events:
                    if events[self.__socket_sub] == zmq.POLLIN:
                        topic, msg = self.__socket_sub.recv_multipart()
                        self.__call(topic, msg)
                        self._window.post_redraw()  # Redraw the GUI after processing the message
                        
            except json.JSONDecodeError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
                continue
            except zmq.ZMQError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
            except Exception as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")

        # close pipeline
        poller.unregister(self.__socket_sub)
        self.__socket_sub.setsockopt(zmq.LINGER, 0)
        self.__socket_sub.close()
        self.__console.debug(f"({self.__class__.__name__}) Closed Pipeline")

    def __call(self, topic:str, msg:str):
        """ for zmqrpc-like call function """
        if topic.decode() == "call":
            msg_decoded = json.loads(msg.decode('utf8').replace("'", '"'))
            try:
                function_name = msg_decoded["function"]
                function = getattr(super(), function_name)
                kwargs = msg_decoded["kwargs"]
                function(self._scene, **kwargs)
            except json.JSONDecodeError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
            except Exception as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")

    def close(self):
        """ close window and stop all """
        # zmq pipeline terminate (until exit)
        self.__stop_pipe_event.set()
        self.__pipe_worker.join(timeout=3)

        # self._window.close()
        gui.Application.instance.quit()
        self.__console.debug(f"({self.__class__.__name__}) Closed 3D Window")

        return True
    
    def on_key_event(self, event):
        """ key event"""
        if event.type == gui.KeyEvent.DOWN and event.key == gui.KeyName.O:
           self.__show_origin_coord = not self.__show_origin_coord
           self.on_show_origin_coord()
           return True
        elif event.type == gui.KeyEvent.DOWN and event.key == gui.KeyName.U:
            self.on_show_urdf()
            return True
        return False

    def run(self):
        gui.Application.instance.run()

    def on_show_origin_coord(self):
        """ Show origin coordinate """
        if self.__show_origin_coord:
            frame = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.1, origin=[0, 0, 0])
            material = rendering.MaterialRecord()
            material.shader = "defaultLit"
            self._scene.scene.add_geometry("origin_frame", frame, material)
        else:
            self._scene.scene.remove_geometry("origin_frame")

    def on_show_urdf(self):
        """ show robot URDF model"""
        if self.__show_robot:
            for urdf in self.__config["urdf"]:
                name = urdf["name"]
                urdf_file = os.path.join(self.__config["root_path"], urdf["path"])
                self.__console.debug(f"Loading URDF {name} from {urdf_file}")

                robot = URDF.load(urdf_file, lazy_load_meshes=False)
                base_pos = np.eye(4)
                base_pos[:3, 3] = np.array(urdf.get("base", [0.0, 0.0, 0.0]))
                fk = robot.visual_trimesh_fk(cfg=None)

                meshes = []
                a = 1
                for tm, T in fk.items():
                    
                    tm_copy = tm.copy()
                    tm_copy.apply_transform(base_pos@T)

                    # convert trimesh to Open3D mesh
                    o3d_mesh = o3d.geometry.TriangleMesh()
                    o3d_mesh.vertices = o3d.utility.Vector3dVector(tm_copy.vertices)
                    o3d_mesh.triangles = o3d.utility.Vector3iVector(tm_copy.faces)
                    o3d_mesh.compute_vertex_normals()

                    
                    material = rendering.MaterialRecord()
                    material.shader = "defaultLit"
                    #material.base_color = [1, 0, 0, 1]  # RGBA

                    self._scene.scene.add_geometry(f"{name}_{a}", o3d_mesh, material)
                    a = a+1
        else:
            pass

    def on_show_floor(self):
        if self.__show_floor:
            width = 5.0
            depth = 5.0   # y축 방향 길이
            height = 0.01  # 두께 (z축 방향), 너무 얇게 설정

            # Open3D 박스 생성 (box는 x, y, z 방향 크기)
            floor = o3d.geometry.TriangleMesh.create_box(width, depth, height)
            floor.compute_vertex_normals()

            # 기본 생성 시, 박스의 한 꼭지점이 원점 (0,0,0)에 위치함
            # 따라서 바닥면을 XY 평면(z=0)에 맞추려면 z방향으로 살짝 이동시킴
            floor.translate((0, 0, -height))

            # 바닥면 색깔 설정 (회색 계열)
            floor.paint_uniform_color([0.7, 0.7, 0.7])

            material = rendering.MaterialRecord()
            material.shader = "defaultLit"
            self._scene.scene.add_geometry("floor", floor, material)

        else:
            self._scene.scene.remove_geometry("floor")