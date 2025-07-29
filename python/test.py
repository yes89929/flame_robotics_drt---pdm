import open3d as o3d
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering
from dep.urdf_parser import URDF
import numpy as np


class ManipulatorViewer:
    def __init__(self, urdf_path):
        self.urdf = URDF.load(urdf_path)

        # FK를 위한 초기 Joint 값 (조인트 이름: 값)
        self.joint_values = {joint.name: 0.0 for joint in self.urdf.joints if joint.joint_type != 'fixed'}

        # Open3D GUI 초기화
        self.app = gui.Application.instance
        self.app.initialize()
        self.window = self.app.create_window("URDF Manipulator Viewer", 1024, 768)

        self.scene_widget = gui.SceneWidget()
        self.scene_widget.scene = rendering.Open3DScene(self.window.renderer)
        self.window.add_child(self.scene_widget)

        # 링크별로 geometry 추가
        self.link_nodes = {}  # {link_name: {'mesh': TriangleMesh, 'node_name': str}}

        self._load_links()

        # 카메라
        bounds = self.get_robot_bounds()
        self.scene_widget.setup_camera(60, bounds, bounds.get_center())

        # 버튼: 조인트 업데이트 예시
        btn = gui.Button("Rotate Joint 1 by +0.1 rad")
        btn.set_on_clicked(self.increment_joint)
        self.window.add_child(btn)

    def _load_links(self):
        """URDF 로드 후 Open3D 씬에 추가"""
        fk = self.urdf.link_fk(cfg=self.joint_values)

        for link in self.urdf.links:
            visuals = link.visuals
            for i, visual in enumerate(visuals):
                mesh = visual.geometry.mesh.meshes  # urdfpy의 trimesh
                vertices = np.asarray(mesh.vertices)
                triangles = np.asarray(mesh.faces)

                o3d_mesh = o3d.geometry.TriangleMesh()
                o3d_mesh.vertices = o3d.utility.Vector3dVector(vertices)
                o3d_mesh.triangles = o3d.utility.Vector3iVector(triangles)
                o3d_mesh.compute_vertex_normals()

                # FK로 pose 계산
                T = fk[link]
                o3d_mesh.transform(T)

                node_name = f"{link.name}_{i}"
                self.scene_widget.scene.add_geometry(node_name, o3d_mesh, self.get_material())

                # 저장
                self.link_nodes[link.name] = {
                    'mesh': o3d_mesh,
                    'node_name': node_name
                }

    def get_material(self):
        mat = rendering.MaterialRecord()
        mat.shader = "defaultLit"
        return mat

    def get_robot_bounds(self):
        """전체 로봇 bounds 계산"""
        all_points = []
        for link in self.link_nodes.values():
            all_points.append(np.asarray(link['mesh'].vertices))
        all_points = np.vstack(all_points)
        aabb = o3d.geometry.AxisAlignedBoundingBox.create_from_points(o3d.utility.Vector3dVector(all_points))
        return aabb

    def increment_joint(self):
        """조인트1을 조금 회전 -> FK -> 링크 transform 갱신"""
        joint_names = list(self.joint_values.keys())
        if not joint_names:
            print("No movable joints")
            return

        joint_name = joint_names[0]
        self.joint_values[joint_name] += 0.1
        print(f"Updated {joint_name} to {self.joint_values[joint_name]:.3f} rad")

        self.update_link_poses()

    def update_link_poses(self):
        """FK 다시 계산 후 Open3D에 반영"""
        fk = self.urdf.link_fk(cfg=self.joint_values)

        for link in self.urdf.links:
            T = fk[link]

            if link.name in self.link_nodes:
                mesh = self.link_nodes[link.name]['mesh']
                node_name = self.link_nodes[link.name]['node_name']

                # 원본 메쉬 다시 가져와서 transform 적용
                mesh_copy = o3d.geometry.TriangleMesh(mesh)
                mesh_copy.transform(T)

                self.scene_widget.scene.remove_geometry(node_name)
                self.scene_widget.scene.add_geometry(node_name, mesh_copy, self.get_material())

                # 갱신
                self.link_nodes[link.name]['mesh'] = mesh_copy

    def run(self):
        self.app.run()


if __name__ == "__main__":
    viewer = ManipulatorViewer("/Users/byunghunhwang/dev/flame_robotics_drt/urdf/rb10_1300e/rb10_1300e.urdf")
    viewer.run()