import open3d as o3d
from open3d.t.geometry import TriangleMesh

hello_open3d_mesh: TriangleMesh = o3d.t.geometry.TriangleMesh.create_text("Hello Open3D", depth=0.1).to_legacy()
hello_open3d_mesh.paint_uniform_color((0.4, 0.1, 0.9))


# Scale down since default mesh is quite big
# Location
location = (1, 3, 6)  # The mesh is not centered at origin, so there is already an offset.
# I am adding another location shift as an example.
hello_open3d_mesh.transform([[0.1, 0, 0, location[0]], [0, 0.1, 0, location[1]], [0, 0, 0.1, location[2]],
                             [0, 0, 0, 1]])
origin = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.3, origin=[0, 0, 0])

o3d.visualization.draw_geometries([origin, hello_open3d_mesh], mesh_show_back_face=True)