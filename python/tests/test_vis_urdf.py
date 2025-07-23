import sys
import os
sys.path.append("../")

from dep.urdfpy import URDF
import open3d as o3d
import numpy as np
import trimesh

# 1. URDF 파싱
urdf_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "../urdf/robots")
print(urdf_dir)
robot = URDF.load(os.path.join(urdf_dir, "rb10_1300e.urdf"))

# 2. 모든 링크 순회
o3d_meshes = []
for link in robot.links:
    print(f"Link: {link.name}")
    for visual in link.visuals:
        if not hasattr(visual.geometry, "mesh") or visual.geometry.mesh is None:
            continue

        mesh_filename = visual.geometry.mesh.filename
        if not os.path.isabs(mesh_filename):
            mesh_filename = os.path.join(urdf_dir, mesh_filename)


        # 3. Open3D로 메쉬 로드
        mesh = trimesh.load(mesh_filename)
        if isinstance(mesh, trimesh.Scene):
            geoms = mesh.geometry.values()
        else:
            geoms = [mesh]

        for geom in geoms:
            o3d_mesh = o3d.geometry.TriangleMesh()
            o3d_mesh.vertices = o3d.utility.Vector3dVector(geom.vertices)
            o3d_mesh.triangles = o3d.utility.Vector3iVector(geom.faces)
            o3d_mesh.compute_vertex_normals()
            # o3d_meshes.append(o3d_mesh)
            print(f"{mesh_filename}")
            
            o3d_mesh.transform(visual.origin)
            o3d_meshes.append(o3d_mesh)

# 5. 시각화
print(len(o3d_meshes))
o3d.visualization.draw_geometries(o3d_meshes)