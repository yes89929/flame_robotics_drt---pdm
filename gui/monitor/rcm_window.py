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
            if "rcm_gui" in config:
                ui_path = pathlib.Path(config["app_path"]) / config["rcm_gui"]
                if os.path.isfile(ui_path):
                    loadUi(ui_path, self)
                else:
                    raise Exception(f"Cannot found UI file : {ui_path}")

        except Exception as e:
            self.__console.error(f"{e}")


    def closeEvent(self, event:QCloseEvent) -> None:
        """ Handle close event """
        self.__pipeline_context.destroy(0)
        return super().closeEvent(event)

