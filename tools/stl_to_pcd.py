"""
STL Mesh to Point Cloud Data File (pcd, ply)
"""

import open3d as o3d
import trimesh
import argparse
import os

from util.logger.console import ConsoleLogger

if __name__ == "__main__":

    console = ConsoleLogger.get_logger()

    parser = argparse.ArgumentParser()
    parser.add_argument('--file', nargs='?', required=True, help="Polygon File Format(*.ply)", default="default.ply")
    parser.add_argument('--sample', nargs='?', required=False, help="Number of Samples", default=10000)
    parser.add_argument('--ext', nargs='?', required=False, help="Converting File (PCD, PLY)", default="pcd")
    args = parser.parse_args()

    try:
        mesh = trimesh.load(args.file)
        points = mesh.sample(int(args.sample))
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(points)

        path_no_ext, ext = os.path.splitext(args.file)
        o3d.io.write_point_cloud(f"{path_no_ext}.{args.ext}", pcd)
        o3d.io.write_point_cloud(f"{path_no_ext}.{args.ext}", pcd)

    except Exception as e:
        console.error(f"{e}")