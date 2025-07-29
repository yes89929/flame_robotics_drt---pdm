
"""
3D Visualization Window Module with Open3D
"""
import open3d as o3d
import zmq
import json
import importlib
import inspect
import threading
import time

from util.logger.console import ConsoleLogger
from .geomerty import GeometryAPI

class Open3DViewer(GeometryAPI):
    _geometry_container = {}

    def __init__(self, config:dict, pipe_context:zmq.Context):
        super().__init__()


        self.__config = config
        self.__console = ConsoleLogger.get_logger() # logger

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

        # flag for render polling
        self.__stop_render = False

        # o3d visualizer
        self._vis = o3d.visualization.VisualizerWithKeyCallback()
        self._vis.create_window(window_name=config["main_window_title"], 
                                width=self.__config.get("main_gui_window_size", [1280, 720])[0],
                                height=self.__config.get("main_gui_window_size", [1280, 720])[1], 
                                top=self.__config.get("main_gui_pos", [0,0])[0], 
                                left=self.__config.get("main_gui_pos", [0,0])[1])
        self._vis.get_render_option().background_color = self.__config.get("main_gui_bgcolor", [1.0, 1.0, 1.0])
        self._cam_params = self._vis.get_view_control().convert_to_pinhole_camera_parameters()

        # register keyboard callbacks
        self._vis.register_key_callback(ord("Q"), self.on_quit)
        self._vis.register_key_callback(ord("O"), self.on_show_origin_coord)


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

            except json.JSONDecodeError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
                continue
            except zmq.ZMQError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
            except Exception as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")

        poller.unregister(self.__socket_sub)

    def __call(self, topic:str, msg:str):
        """ for zmqrpc-like call function """
        if topic.decode() == "call":
            msg_decoded = json.loads(msg.decode('utf8').replace("'", '"'))
            try:
                function_name = msg_decoded["function"]
                function = getattr(super(), function_name)
                kwargs = msg_decoded["kwargs"]
                function(self._vis, **kwargs)
            except json.JSONDecodeError as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")
            except Exception as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")

    def close(self):
        """ close window and stop all """
        # zmq pipeline terminate
        self.__stop_pipe_event.set()
        self.__pipe_worker.join(timeout=3)

        try:
            self.__socket_sub.setsockopt(zmq.LINGER, 0)
            self.__socket_sub.close()
            self.__console.debug(f"({self.__class__.__name__}) Closed Pipeline")
        except zmq.ZMQError as e:
            print(f"({self.__class__.__name__}) {e}")

    def on_quit(self, vis):
        self.__stop_render = True
    
    def on_show_origin_coord(self, vis):
        """ Show origin coordinate """
        if "origin_coord" not in self._geometry_container:
            origin = o3d.geometry.TriangleMesh.create_coordinate_frame(size=1.0, origin=[0, 0, 0])
            self._geometry_container["origin_coord"] = origin
            self._vis.add_geometry(origin)
        else:
            self._vis.remove_geometry(self._geometry_container["origin_coord"])
            del self._geometry_container["origin_coord"]
        self._cam_params = self._vis.get_view_control().convert_to_pinhole_camera_parameters()

    def change_color(self, vis):
        self.mesh.paint_uniform_color([1.0, 0.0, 0.0])  # 빨간색으로 변경
        vis.update_geometry(self.mesh)
        return False
    
    def render(self):
        
        while not self.__stop_render:
            try:
                self._vis.get_view_control().convert_from_pinhole_camera_parameters(self._cam_params)

                self._vis.poll_events()
                self._vis.update_renderer()
                time.sleep(0.02)
            except Exception as e:
                self.__console.error(f"({self.__class__.__name__}) {e}")

        # close
        self.close()
        self._vis.destroy_window()
        self.__console.debug(f"({self.__class__.__name__}) Closed 3D Viewer")

        