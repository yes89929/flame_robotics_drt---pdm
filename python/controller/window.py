'''
DRT Monitor Application Window class
@Author Byunghun Hwang<bh.hwang@iae.re.kr>
'''

try:
    # using PyQt6
    from PyQt6.QtGui import QImage, QPixmap, QCloseEvent, QStandardItem, QStandardItemModel
    from PyQt6.QtWidgets import QApplication, QFrame, QMainWindow, QLabel, QPushButton, QCheckBox, QComboBox, QDialog
    from PyQt6.QtWidgets import QMessageBox, QProgressBar, QFileDialog, QComboBox, QLineEdit, QSlider, QVBoxLayout
    from PyQt6.uic import loadUi
    from PyQt6.QtCore import QObject, Qt, QTimer, QThread, pyqtSignal, QRegularExpression
except ImportError:
    print("PyQt6 is required to run this application.")

import zmq
import os, sys
import pathlib
import json
import threading
import re
import numpy as np
import math
from functools import partial


from util.logger.console import ConsoleLogger
from python.common.urdf_parser import URDFParser
from python.common.pipeline import Publisher as Pub
from python.common.pipeline import Subscriber as Sub

# global variable
scale_factor = 1000


class AppWindow(QMainWindow):
    def __init__(self, config:dict, pipe_context:zmq.Context):
        """ initialization """
        super().__init__()
        
        self.__console = ConsoleLogger.get_logger() # logger
        self.__config = config  # copy configuration data

        # self.publisher = Pub(context=pipe_context)
        # self.subscriber = Sub(context=pipe_context)

        # # publisher
        # self._socket_pub = pipe_context.socket(zmq.PUB)
        # self._socket_pub.setsockopt(zmq.SNDHWM, 100)
        # self._socket_pub.setsockopt(zmq.LINGER, 0)
        # self._socket_pub.bind("tcp://localhost:9001")

        # # subscriber
        # self._socket_sub = pipe_context.socket(zmq.SUB)
        # self._socket_sub.setsockopt(zmq.RCVHWM, 100)
        # self._socket_sub.setsockopt(zmq.RCVTIMEO, 500)
        # self._socket_sub.setsockopt(zmq.LINGER, 0)
        # self._socket_sub.connect("tcp://localhost:9000")
        # self._socket_sub.subscribe("call")

        # self._stop_zmq_event = threading.Event()
        # self._zmq_pipeline_thread = threading.Thread(target=self.zmq_recv_process, args=(self._stop_zmq_event,), daemon=True)
        # self._zmq_pipeline_thread.start()

        # sub windows
        # self.__pdm_window = PDMWindow(context, self._socket_pub, config)
        # self.__rcm_window = RCMWindow(context, self._socket_pub, config)

        try:            
            if "gui" in config:
                ui_path = pathlib.Path(config["app_path"]) / config["gui"]
                if os.path.isfile(ui_path):
                    loadUi(ui_path, self)
                    self.setWindowTitle(config.get("window_title", "DRT Control Window"))

                    # Initialize URDF parser and joint limits
                    self.urdf_parser = None
                    _rt_joint_limits = {}
                    _dda_joint_limits = {}
                    
                    # Load URDF and parse joint limits
                    if "urdf" in self.__config and self.__config["urdf"]:
                        for urdf_info in self.__config["urdf"]:
                            urdf_file = os.path.join(self.__config["root_path"], urdf_info["path"])
                            if os.path.exists(urdf_file):
                                parser = URDFParser(urdf_file)
                                if "dda" in urdf_info["name"]:
                                    _dda_joint_limits = parser.get_all_joint_limits()
                                    self.__console.info(f"Found {len(_dda_joint_limits)} joints with limits for DDA-side Manipulator")
                                elif "rt" in urdf_info["name"]:
                                    _rt_joint_limits = parser.get_all_joint_limits()
                                    self.__console.info(f"Found {len(_rt_joint_limits)} joints with limits for RT-side Manipulator")
                            else:
                                self.__console.warning(f"URDF file not found: {urdf_file}")

                    # menu actions
                    self.actionUtilGeneratePCD.triggered.connect(self.on_select_generate_pcd)

                    # Initialize sliders with URDF joint limits
                    self._setup_sliders(dda_side_joint_limits=_dda_joint_limits, rt_side_joint_limits=_rt_joint_limits)

                    # button actions
                    self.btn_open_pcd.clicked.connect(self.on_open_pcd)
                    self.btn_run_simulation.clicked.connect(self.on_run_simulation)
                    self.btn_stop_simulation.clicked.connect(self.on_stop_simulation)
                    self.btn_geometry_remove_all.clicked.connect(self.on_btn_geometry_remove_all)

                else:
                    raise Exception(f"Cannot found UI file : {ui_path}")
                
        except Exception as e:
            self.__console.error(f"{e}")
    
    def zmq_recv_process(self, stop_event):
        """ zmq pipeline process for receiving data """

        poller = zmq.Poller()
        poller.register(self._socket_sub, zmq.POLLIN)
        
        while not stop_event.is_set():
            try:
                events = dict(poller.poll(1000)) # wait 1 sec
                if self._socket_sub in events:
                    if events[self._socket_sub] == zmq.POLLIN:
                        # for 'call' topic
                        topic, msg = self._socket_sub.recv_multipart()
                        if topic.decode() == "call":
                            data = json.loads(msg.decode('utf8').replace("'", '"'))
                            print(f"recv : {data}")
                
            except json.JSONDecodeError as e:
                print(f"[Graphic 3D Window] {e}")
                continue
            except zmq.ZMQError as e:
                print(f"[Graphic 3D Window] {e}")
                break
            except Exception as e:
                print(f"[Graphic 3D Window] {e}")
                break

        poller.unregister(self._socket_sub)

    
    def closeEvent(self, event:QCloseEvent) -> None:
        """ Handle close event """

        # zmq pipeline terminate
        # self._stop_zmq_event.set()
        # self._zmq_pipeline_thread.join(timeout=3)

        # try:
        #     self._socket_sub.setsockopt(zmq.LINGER, 0)
        #     self._socket_sub.close()
        # except zmq.ZMQError as e:
        #     print(f"[Graphic 3D Window] {e}")

        self.__console.info("Successfully Closed")
        return super().closeEvent(event)
    
    def on_open_pcd(self):
        """ Open PCD file dialog """
        pcd_file, _ = QFileDialog.getOpenFileName(self, "Open PCD File", "", "PCD Files (*.pcd);;All Files (*)")
        if pcd_file:
            self.__console.info(f"Selected PCD file: {pcd_file}")
            self.edit_pcd_file.setText(pcd_file)
            self.__call(socket=self._socket_pub, function="API_add_pcd", kwargs={"name":os.path.basename(pcd_file), "path":pcd_file, "pos":[0.0, 0.0, 0.0]})
        else:
            self.__console.warning("No PCD file selected.")

    def on_run_simulation(self):
        """ Run Simulation """
        self.__console.info(f"({self.__class__.__name__}) Running Simulation")
        

    def on_stop_simulation(self):
        """ Stop Simulation """
        self.__console.info(f"({self.__class__.__name__}) Stop Simulation")

    def on_btn_geometry_remove_all(self):
        """ Clear all geometry """
        self.__console.info(f"({self.__class__.__name__}) Clear all geometry")
        self.__call(socket=self._socket_pub, function="API_clear_all_geometry", kwargs={})

    def on_slide_control_update(self, value, joint:str):
        slider = self.sender()
        self.findChild(QLineEdit, f"edit_{slider.objectName()}").setText(str(value/scale_factor))
        print(f"{joint}:{value/scale_factor}")
        
        # self.__call(socket=self._socket_pub, function="API_set_rt_gx", kwargs={"value":value})

    def _setup_sliders(self, dda_side_joint_limits:dict, rt_side_joint_limits:dict):
        """Setup sliders with URDF joint limits"""
        try:
            # RT-side Manipulator joint control
            rt_labels = self.findChildren(QLabel, QRegularExpression(r"label_rt_\d+"))
            rt_edits = self.findChildren(QLineEdit, QRegularExpression(r"edit_slide_rt_\d+"))
            rt_sliders = self.findChildren(QSlider, QRegularExpression(r"slide_rt_\d+"))
            rt_labels.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))
            rt_edits.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))
            rt_sliders.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))

            for label, key in zip(rt_labels, rt_side_joint_limits.keys()):
                label.setText(key)
            for label, slider, key in zip(rt_labels, rt_sliders, rt_side_joint_limits.keys()):
                # slider.valueChanged.connect(lambda v: self.on_slide_control_update(v, key))
                slider.valueChanged.connect(partial(self.on_slide_control_update, joint=key))
                

                limits = rt_side_joint_limits[label.text()]
                lower_deg = int(limits['lower'] * 180 / 3.14)*scale_factor
                upper_deg = int(limits['upper'] * 180 / 3.14)*scale_factor
                slider.setRange(lower_deg, upper_deg)
                slider.setValue(0)
                self.findChild(QLineEdit, f"edit_{slider.objectName()}").setText(str(0))
        except Exception as e:
            self.__console.warning(f"{e}")

        try:
            # DDA-side Manipulator joint control
            dda_labels = self.findChildren(QLabel, QRegularExpression(r"label_dda_\d+"))
            dda_edits = self.findChildren(QLineEdit, QRegularExpression(r"edit_slide_dda_\d+"))
            dda_sliders = self.findChildren(QSlider, QRegularExpression(r"slide_dda_\d+"))
            dda_labels.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))
            dda_edits.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))
            dda_sliders.sort(key=lambda lbl: int(re.search(r"\d+", lbl.objectName()).group()))

            for label, key in zip(dda_labels, dda_side_joint_limits.keys()):
                label.setText(key)
            for label, slider, key in zip(dda_labels, dda_sliders, dda_side_joint_limits.keys()):
                slider.valueChanged.connect(lambda v: self.on_slide_control_update(v, key))

                limits = dda_side_joint_limits[label.text()]
                lower_deg = int(limits['lower'] * 180 / 3.14)*scale_factor
                upper_deg = int(limits['upper'] * 180 / 3.14)*scale_factor
                slider.setRange(lower_deg, upper_deg)
                slider.setValue(0)
                self.findChild(QLineEdit, f"edit_{slider.objectName()}").setText(str(0))
        except Exception as e:
            self.__console.warning(f"{e}")

        

    def on_select_generate_pcd(self):
        """ 3D Model to PCD file generation """
        from python.manager.util_gen_pcd import AppWindow as GenPCDWindow
        model_file, _ = QFileDialog.getOpenFileName(self, "Open STL File", "", "STL Files (*.stl);;All Files (*)")
        if model_file:
            wnd = GenPCDWindow(config=self.__config, target=model_file)
            wnd.show()

            self.__console.info(f"Selected 3D model file: {model_file}")
        
    def __call(self, socket, function:str, kwargs:dict):
        try:
            topic = "call"
            message = { "function":function,"kwargs":kwargs}
            if socket:
                socket.send_multipart([topic.encode(), json.dumps(message).encode()])
                print(f"send {topic}, {function}")
            else:
                self.__console.warning(f"Failed send")
        except zmq.ZMQError as e:
            self.__console.error(f"[Main Window] {e}")
        except json.JSONDecodeError as e:
            self.__console.error(f"[Main Window] JSON Decode Error: {e}")

    


        


