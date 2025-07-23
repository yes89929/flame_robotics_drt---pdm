import matplotlib.pyplot as plt
from matplotlib.textpath import TextPath
from matplotlib.font_manager import FontProperties
from shapely.geometry import Polygon
from shapely.ops import unary_union
import trimesh
import open3d as o3d
import numpy as np

# 1) Matplotlib TextPath
fp = FontProperties(family="DejaVu Sans", weight='bold')
tp = TextPath((0, 0), "Hi!", prop=fp)

verts = tp.vertices
codes = tp.codes

# 2) Path -> Polygons
polygons = []
current = []
for v, c in zip(verts, codes):
    if c == 1:  # MOVETO
        if len(current) > 0:
            polygons.append(Polygon(current))
            current = []
        current.append(tuple(v))
    elif c == 2 or c == 4:  # LINETO, CLOSEPOLY
        current.append(tuple(v))

if len(current) > 0:
    polygons.append(Polygon(current))

# 3) Union (이 단계에서 MultiPolygon 가능!)
mp = unary_union(polygons)

# 4) MultiPolygon 처리
if isinstance(mp, Polygon):
    polys = [mp]
elif hasattr(mp, 'geoms'):
    polys = list(mp.geoms)
else:
    raise ValueError("Unknown geometry type")

# 5) 각각 extrude → 합치기
meshes = []
for poly in polys:
    meshes.append(trimesh.creation.extrude_polygon(poly, height=0.2))

# 6) 하나로 병합
mesh = trimesh.util.concatenate(meshes)

# 7) Open3D로 변환
o3d_mesh = o3d.geometry.TriangleMesh()
o3d_mesh.vertices = o3d.utility.Vector3dVector(mesh.vertices)
o3d_mesh.triangles = o3d.utility.Vector3iVector(mesh.faces)
o3d_mesh.compute_vertex_normals()

o3d.visualization.draw([o3d_mesh])