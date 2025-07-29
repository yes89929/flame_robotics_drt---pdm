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

from util.logger.console import ConsoleLogger
# from dep.urdf_parser import URDF
from .geomerty import GeometryAPI

class Open3DVisualizer(GeometryAPI):
    _geometry_container = {}

    def __init__(self, config:dict, pipe_context:zmq.Context):
        super().__init__()

        self.__config = config
        self.__console = ConsoleLogger.get_logger() # logger

        # visualizer
        gui.Application.instance.initialize() # gui initialize
        self._window = gui.Application.instance.create_window(title=config["main_window_title"], 
                                width=self.__config.get("main_gui_window_size", [1280, 720])[0],
                                height=self.__config.get("main_gui_window_size", [1280, 720])[1])
        self._scene = gui.SceneWidget()
        self._scene.scene = rendering.Open3DScene(self._window.renderer)
        self._scene.scene.set_background(self.__config.get("main_gui_bgcolor", [1.0, 1.0, 1.0, 1.0])) # RGBA
        self._scene.scene.scene.set_sun_light([-1, -1, -1], [1, 1, 1], 100000)
        self._scene.scene.scene.enable_sun_light(True)

        bbox = o3d.geometry.AxisAlignedBoundingBox([-10, -10, -10], [10, 10, 10])
        self._scene.setup_camera(60, bbox, [0,0,0])
        self._window.add_child(self._scene)

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
        if not self.__show_origin_coord:
            frame = o3d.geometry.TriangleMesh.create_coordinate_frame(size=1.0, origin=[0, 0, 0])
            material = rendering.MaterialRecord()
            material.shader = "defaultLit"
            self._scene.scene.add_geometry("origin_frame", frame, material)
        else:
            self._scene.scene.remove_geometry("origin_frame")

        self.__show_origin_coord = not self.__show_origin_coord

    def on_show_urdf(self):
        """ Show URDF model """
        if "urdf" in self.__config:
            for urdf in self.__config["urdf"]:
                name = urdf["name"]
                path = os.path.join(self.__config["root_path"], urdf["path"])
                self.__console.debug(f"Loading URDF {name} from {path}")
                
                if name not in self._geometry_container:
                    try:
                        urdf_obj = URDF.load(path)
                        print(type(urdf_obj))
                        fk = urdf_obj.visual_trimesh_fk(cfg=None)

                        # meshes = []
                        # for tm, T in fk.items():
                        #     tm_copy = tm.copy()
                        #     tm_copy.apply_transform(T)

                        #     # convert trimesh to Open3D mesh
                        #     o3d_mesh = o3d.geometry.TriangleMesh()
                        #     o3d_mesh.vertices = o3d.utility.Vector3dVector(tm_copy.vertices)
                        #     o3d_mesh.triangles = o3d.utility.Vector3iVector(tm_copy.faces)

                        #     o3d_mesh.compute_vertex_normals()
                        #     meshes.append(o3d_mesh)

                        #     material = rendering.MaterialRecord()
                        #     material.shader = "defaultLit"
                        #     self._scene.scene.add_geometry(f"{name}", o3d_mesh, material)

                        # self.__console.info(f"URDF Meshes {len(meshes)}")

                    except Exception as e:
                        self.__console.error(f"Failed to load URDF {name}: {e}")
                else:
                    self.__console.debug(f"URDF {name} already loaded")
        else:
            self.__console.warning("No URDF configuration found")