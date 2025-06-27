import open3d as o3d
import open3d.visualization.gui as gui
import open3d.visualization.rendering as rendering

def main():
    gui.Application.instance.initialize()
    w = gui.Application.instance.create_window("Transparent Box", 1024, 768)
    
    scene = gui.SceneWidget()
    scene.scene = rendering.Open3DScene(w.renderer)
    w.add_child(scene)

    # 박스 생성
    box = o3d.geometry.TriangleMesh.create_box(width=1, height=1, depth=1)
    box.compute_vertex_normals()

    # 박스 재질 설정 (투명도 포함)
    material = rendering.MaterialRecord()
    material.base_color = [1.0, 0.0, 0.0, 0.1]  # RGBA (0.5 = 50% 투명)
    material.shader = "defaultLitTransparency"  # 꼭 필요

    scene.scene.add_geometry("box", box, material)
    scene.setup_camera(60, box.get_axis_aligned_bounding_box(), [0, 0, 0])

    gui.Application.instance.run()

if __name__ == "__main__":
    main()