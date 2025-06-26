import open3d as o3d
import numpy as np

# 1. Adding 3D labels to a point cloud
pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(np.random.rand(10, 3))
labels = ["Point " + str(i) for i in range(10)]
colors = [[1, 0, 0] for _ in range(10)] # Red color for all labels

# Create 3D labels
for i, label in enumerate(labels):
    pcd.colors.append(colors[i])

# Add labels to visualization
o3d.visualization.draw_geometries([pcd], point_show_normal=False,
                                 zoom=0.7, front=[0.5, -0.2, -0.8],
                                 lookat=[2.0211, -0.0776, -1.1173],
                                 up=[0.0, -1.0, 0.0])
# 2. Creating a TextEdit widget
# This example requires a UI application.
# See the Open3D GUI examples for more details.
# app = o3d.visualization.gui.Application.instance()
# app.initialize()
#
# window = app.create_window("TextEdit Example", 640, 480)
#
# text_edit = o3d.visualization.gui.TextEdit()
# text_edit.text_value = "Initial Text"
#
# # Set up a callback for when the text is changed
# def on_text_changed(text):
#    print(f"Text changed to: {text}")
#
# text_edit.set_on_text_changed(on_text_changed)
#
# window.add_child(text_edit)
# app.run()