'''
3D Pipe Inspection Pose Detection Tool
@auhtor Byunghun Hwang<bh.hwnag@iae.re.kr>
'''

import sys, os, platform
import pathlib
import json
import numpy as np
import open3d as o3d
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering

# root directory registration on system environment
ROOT_PATH = pathlib.Path(__file__).parent.parent
APP_NAME = pathlib.Path(__file__).stem
sys.path.append(ROOT_PATH.as_posix())

import argparse
from pdtool.window import AppWindow
from util.logger.console import ConsoleLogger


if __name__ == "__main__":
    
    console = ConsoleLogger.get_logger()
    gui.Application.instance.initialize()

    parser = argparse.ArgumentParser()
    parser.add_argument('--config', nargs='?', required=False, help="Configuration File(*.cfg)", default="default.cfg")
    parser.add_argument('--verbose', nargs='?', required=False, help="Enable/Disable verbose", default=True)
    args = parser.parse_args()

    app = None
    try:
        with open(args.config, "r") as cfile:
            configure = json.load(cfile)

            configure["root_path"] = ROOT_PATH
            configure["app_path"] = (pathlib.Path(__file__).parent / APP_NAME)
            configure["verbose"] = args.verbose

            if args.verbose:
                console.info(f"+ Root Path : {configure['root_path']}")
                console.info(f"+ Application Path : {configure['app_path']}")
                console.info(f"+ Verbose Level : {configure['verbose']}")

            app_window = AppWindow(config=configure)
            
            gui.Application.instance.run()

    except json.JSONDecodeError as e:
        console.critical(f"Configuration File Load Error : {e}")
    except Exception as e:
        console.critical(f"{e}")
        
    
        
    