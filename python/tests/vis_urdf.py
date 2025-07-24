"""
Test Sample for URDF Load & Visualization
"""

import sys
sys.path.append("./")

from dep.urdf_parser import URDF
import open3d as o3d
import numpy as np
import trimesh
import os

""" URDF path """
urdf_root = os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../urdf")
print(f"URDF Root Directory: {urdf_root}")
robot = URDF.load(os.path.join(urdf_root, "rb20_1900es/rb20_1900es.urdf"))
print(f"Robot Name: {robot.name}")


fk = robot.visual_trimesh_fk(cfg=None)
meshes = []

for tm, T in fk.items():
    tm_copy = tm.copy()
    tm_copy.apply_transform(T)

    # convert trimesh to Open3D mesh
    o3d_mesh = o3d.geometry.TriangleMesh()
    o3d_mesh.vertices = o3d.utility.Vector3dVector(tm_copy.vertices)
    o3d_mesh.triangles = o3d.utility.Vector3iVector(tm_copy.faces)

    o3d_mesh.compute_vertex_normals()
    meshes.append(o3d_mesh)

o3d.visualization.draw_geometries(meshes)
