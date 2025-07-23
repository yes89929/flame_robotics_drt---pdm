'''
DRT User Control App.
@Author Byunghun Hwang<bh.hwang@iae.re.kr>
'''

try:
    # using PyQt6
    from PyQt6.QtGui import QImage, QPixmap, QCloseEvent, QStandardItem, QStandardItemModel
    from PyQt6.QtWidgets import QApplication, QFrame, QMainWindow, QLabel, QPushButton, QCheckBox, QComboBox, QDialog
    from PyQt6.QtWidgets import QMessageBox, QProgressBar, QFileDialog, QComboBox, QLineEdit, QSlider, QVBoxLayout
    from PyQt6.uic import loadUi
    from PyQt6.QtCore import QObject, Qt, QTimer, QThread, pyqtSignal
except ImportError:
    print("PyQt6 is required to run this application.")

import zmq
import os, sys
import pathlib
import json
import threading


from util.logger.console import ConsoleLogger
from python.monitor.pdm_window import AppWindow as PDMWindow
from python.monitor.rcm_window import AppWindow as RCMWindow


class AppWindow(QMainWindow):
    def __init__(self, context:zmq.Context, config:dict):
        """ initialization """
        super().__init__()
        
        self.__console = ConsoleLogger.get_logger() # logger
        self.__config = config  # copy configuration data

        # publisher
        self._socket_pub = context.socket(zmq.PUB)
        self._socket_pub.setsockopt(zmq.SNDHWM, 100)
        self._socket_pub.setsockopt(zmq.LINGER, 0)
        self._socket_pub.bind("tcp://localhost:9001")

        # subscriber
        self._socket_sub = context.socket(zmq.SUB)
        self._socket_sub.setsockopt(zmq.RCVHWM, 100)
        self._socket_sub.setsockopt(zmq.RCVTIMEO, 500)
        self._socket_sub.setsockopt(zmq.LINGER, 0)
        self._socket_sub.connect("tcp://localhost:9000")
        self._socket_sub.subscribe("call")

        self._stop_zmq_event = threading.Event()
        self._zmq_pipeline_thread = threading.Thread(target=self.zmq_recv_process, args=(self._stop_zmq_event,), daemon=True)
        self._zmq_pipeline_thread.start()

        # sub windows
        self.__pdm_window = PDMWindow(context, self._socket_pub, config)
        self.__rcm_window = RCMWindow(context, self._socket_pub, config)

        try:            
            if "main_gui" in config:
                ui_path = pathlib.Path(config["app_path"]) / config["main_gui"]
                if os.path.isfile(ui_path):
                    loadUi(ui_path, self)

                    self.setWindowTitle(config.get("main_window_title", "DRT Control Simulation Window"))

                    # actions
                    self.actionUtilGeneratePCD.triggered.connect(self.on_select_generate_pcd)

                    # interface components callbacks
                    self.btn_open_pcd.clicked.connect(self.on_open_pcd)
                    self.btn_open_markers.clicked.connect(self.on_open_markers)
                    self.chk_show_origin_coord.toggled.connect(self.on_show_origin_coord)
                    self.chk_show_floor_plane.toggled.connect(self.on_show_floor_plane)
                    self.btn_update_geometry.clicked.connect(self.on_update_geometry)
                    self.btn_clear_all_geometry.clicked.connect(self.on_clear_geometry_all)
                    self.config_geometry_tableview()

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

    def config_geometry_tableview(self):
        self.table_geometry_columns = ["Name", "X", "Y", "Z", "R", "P", "Y"]
        self.geometry_model = QStandardItemModel()
        self.geometry_model.setColumnCount(len(self.table_geometry_columns))
        self.geometry_model.setHorizontalHeaderLabels(self.table_geometry_columns)
        self.table_geometry.setModel(self.geometry_model)

    def closeEvent(self, event:QCloseEvent) -> None:
        """ Handle close event """
        for sub in [self.__pdm_window, self.__rcm_window]:
            if sub.isVisible():
                sub.close()

        # zmq pipeline terminate
        self._stop_zmq_event.set()
        self._zmq_pipeline_thread.join(timeout=3)

        try:
            self._socket_sub.setsockopt(zmq.LINGER, 0)
            self._socket_sub.close()
        except zmq.ZMQError as e:
            print(f"[Graphic 3D Window] {e}")

        self.__console.info("Closing Main Window")
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

    def on_open_markers(self):
        """ Open Markers file dialog """
        markers_file, _ = QFileDialog.getOpenFileName(self, "Open Markers File", "", "Markers Files (*.markers);;All Files (*)")
        if markers_file:
            self.__console.info(f"Selected Markers file: {markers_file}")
            # Here you can add code to handle the selected Markers file
        else:
            self.__console.warning("No Markers file selected.")

    def on_select_generate_pcd(self):
        """ 3D Model to PCD file generation """
        from python.monitor.util_gen_pcd import AppWindow as GenPCDWindow
        model_file, _ = QFileDialog.getOpenFileName(self, "Open STL File", "", "STL Files (*.stl);;All Files (*)")
        if model_file:
            wnd = GenPCDWindow(config=self.__config, target=model_file)
            wnd.show()

            self.__console.info(f"Selected 3D model file: {model_file}")

    def on_show_origin_coord(self, checked:bool):
        if checked:
            self.__call(socket=self._socket_pub, function="API_add_coord_frame", kwargs={"name":"origin", "size":0.5, "pos":[0.0, 0.0, 0.0], "ori":[0.0, 0.0, 0.0]})
            data = ["origin", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
            self.geometry_model.appendRow([QStandardItem(str(value)) for value in data])
            #self.geometry_model.appendRow([QStandardItem("origin"), QStandardItem(0), QStandardItem(0), QStandardItem(0), QStandardItem(0), QStandardItem(0), QStandardItem(0)])
            # self.table_geometry.resizeColumnsToContents()
        else:
            self.__call(socket=self._socket_pub, function="API_remove_geometry", kwargs={"name":"origin"})

    def on_show_floor_plane(self, checked:bool):
        if checked:
            self.__call(socket=self._socket_pub, function="API_add_floor", kwargs={"name":"floor", "size":[40.0, 70.0, 0.005], "pos":[0.1, 0.0, 0.0]})
        else:
            self.__call(socket=self._socket_pub, function="API_remove_geometry", kwargs={"name":"floor"})
    
    def on_update_geometry(self):
        pass

    def on_clear_geometry_all(self):
        self.__call(socket=self._socket_pub, function="API_clear_geometry_all", kwargs={})
        self.geometry_model.setRowCount(0) # clear table
        #self.scenario_model.appendRow([QStandardItem(str(data["time"])), QStandardItem(event["mapi"]), QStandardItem(event["message"])])
        self.table_geometry.resizeColumnsToContents()
        
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

    


        


