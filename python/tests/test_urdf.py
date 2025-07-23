
import sys
sys.path.append("../")

from dep.urdfpy import URDF

robot_ur5 = URDF.load("../urdf/robots/ur5.urdf")
robot_rb10 = URDF.load("../urdf/robots/rb10_1300e.urdf")
for link in robot_ur5.links:
    print(link.name)
for link in robot_rb10.links:
    print(link.name)