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
    from PyQt6.QtCore import QObject, Qt, QTimer, QThread, pyqtSignal
except ImportError:
    print("PyQt6 is required to run this application.")

import zmq
import os, sys
import pathlib

from util.logger.console import ConsoleLogger


class AppWindow(QMainWindow):
    def __init__(self, config:dict):
        """ initialization """
        super().__init__()
        
        self.__console = ConsoleLogger.get_logger() # logger
        self.__config = config  # copy configuration data

        ### configure zmq context
        n_ctx_value = config.get("n_io_context", 14)
        self.__pipeline_context = zmq.Context(n_ctx_value) # zmq context

        try:            
            if "main_gui" in config:
                ui_path = pathlib.Path(config["app_path"]) / config["main_gui"]
                if os.path.isfile(ui_path):
                    loadUi(ui_path, self)
                else:
                    raise Exception(f"Cannot found UI file : {ui_path}")
                
            # interface components callbacks
            self.btn_open_pcd.clicked.connect(self.on_open_pcd)
            self.btn_open_markers.clicked.connect(self.on_open_markers)

        except Exception as e:
            self.__console.error(f"{e}")


    def closeEvent(self, event:QCloseEvent) -> None:
        """ Handle close event """

        self.__pipeline_context.destroy(0)

        return super().closeEvent(event)
    
    def on_open_pcd(self):
        """ Open PCD file dialog """
        pcd_file, _ = QFileDialog.getOpenFileName(self, "Open PCD File", "", "PCD Files (*.pcd);;All Files (*)")
        if pcd_file:
            self.__console.info(f"Selected PCD file: {pcd_file}")
            # Here you can add code to handle the selected PCD file
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

