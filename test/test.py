import pybullet as p
import pybullet_data
import open3d as o3d
import numpy as np
import time

# PyBullet 초기화
physicsClient = p.connect(p.DIRECT)
p.setGravity(0, 0, -9.8)
p.setAdditionalSearchPath(pybullet_data.getDataPath())
plane_id = p.loadURDF("plane.urdf")
box_id = p.loadURDF("r2d2.urdf", [0, 0, 1])

# 시뮬레이션 수행
for _ in range(240):
    p.stepSimulation()
    time.sleep(1/240)

# 위치 가져오기
pos, orn = p.getBasePositionAndOrientation(box_id)

# Open3D로 시각화
mesh = o3d.geometry.TriangleMesh.create_sphere(radius=0.1)
mesh.translate(pos)
mesh.paint_uniform_color([1.0, 0.0, 0.0])
o3d.visualization.draw_geometries([mesh])