"""
DRT Viewer 3D Application
@author Byunghun Hwang <bh.hwang@iae.re.kr>
"""

import sys, os
import pathlib
import json
import open3d as o3d
import zmq
import argparse

from util.logger.console import ConsoleLogger
#from viewer3d.window import Open3DViewer
from viewer3d.visualizer import Open3DVisualizer

# root directory registration on system environment
ROOT_PATH = pathlib.Path(__file__).parent.parent
APP_NAME = pathlib.Path(__file__).stem
sys.path.append(ROOT_PATH.as_posix())


if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument('--config', nargs='?', required=False, help="Configuration File(*.cfg)", default="viewer3d.cfg")
    parser.add_argument('--verbose_level', nargs='?', required=False, help="Set Verbose Level", default="DEBUG")
    args = parser.parse_args()

    console = ConsoleLogger.get_logger(level="DEBUG")

    try:
        with open(args.config, "r") as cfile:
            configure = json.load(cfile)

            configure["root_path"] = ROOT_PATH
            configure["app_path"] = (pathlib.Path(__file__).parent / APP_NAME)
            configure["verbose_level"] = args.verbose_level.upper()

            if configure["verbose_level"] == "DEBUG":
                console.debug(f"Root Path : {configure['root_path']}")
                console.debug(f"Application Path : {configure['app_path']}")
                console.debug(f"Verbose Level : {configure['verbose_level']}")

            # zmq pipeline
            n_ctx_value = configure.get("n_io_context", configure.get("n_io_context", 10))
            pipeline_context = zmq.Context(n_ctx_value)

            # viewer (using open3d)
            viewer = Open3DVisualizer(config=configure, pipe_context=pipeline_context)
            viewer.run()

            # terminate pipeline context
            pipeline_context.term()
            console.info(f"Successfully terminated")

    except json.JSONDecodeError as e:
        console.critical(f"Configuration File Parse Exception : {e}")
    except Exception as e:
        console.critical(f"General Exception : {e}")
