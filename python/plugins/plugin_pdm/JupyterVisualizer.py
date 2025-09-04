import open3d as o3d
from open3d.cpu.pybind.geometry import PointCloud as o3dPointCloud
from open3d.cpu.pybind.utility import Vector3dVector
import numpy as np
import pyvista as pv
from pyvista.plotting.plotter import Plotter
from ipywidgets import Textarea, Layout
from IPython.display import display
from vtk import vtkPointPicker


def visualize_pointcloud(
    points: np.ndarray | None = None,
    colors: np.ndarray | None = None,
    point_size: int = 3,
    camera_pos: list = None,
    bg_color: str | tuple = ("white", "gray"),
) -> Plotter:
    if points is not None:
        pv_data = pv.PolyData(points)
    else:
        pv_data = None

    scalars = None
    rgb = False
    if colors is not None and len(points) == len(colors):
        pv_data["colors"] = colors
        scalars = "colors"
        rgb = True

    # Determine the grid layout based on the camera_pos
    grid_layout = (1, 1) if camera_pos is None or len(camera_pos) == 1 else (int(len(camera_pos) / 2 + 0.5), 2)

    # Create a plotter with the specified grid layout
    pl = Plotter(shape=grid_layout)

    if isinstance(bg_color, tuple):
        if len(bg_color) == 2:
            pl.set_background(bg_color[0], top=bg_color[1])
        else:
            pl.set_background(bg_color[0])
    else:
        pl.set_background(bg_color)

    for i in range(grid_layout[0] * grid_layout[1]):
        # Add the mesh to the subplot
        pl.subplot(i // grid_layout[1], i % grid_layout[1])
        if pv_data is not None:
            pl.add_mesh(pv_data, scalars=scalars, rgb=rgb, point_size=point_size)
        pl.camera.parallel_projection = True

        # Set the camera position if provided
        if camera_pos is not None and i < len(camera_pos):
            pl.camera_position = camera_pos[i]

    return pl


def visualize_pointclouds_simply(
    pcd: o3dPointCloud | np.ndarray | Vector3dVector | None = None,
    point_size: int = 3,
    camera_pos: list = None,
    bg_color: str | tuple = ("white", "gray"),
    visualize_normals: bool = False,
) -> Plotter:
    if isinstance(pcd, o3dPointCloud):
        points = np.asarray(pcd.points)
        colors = np.asarray(pcd.colors) if pcd.has_colors() else None
    elif isinstance(pcd, np.ndarray):
        points = pcd
        colors = None
    elif isinstance(pcd, Vector3dVector):
        points = np.asarray(pcd)
        colors = None
    else:
        points = None
        colors = None

    pl = visualize_pointcloud(points, colors, point_size, camera_pos, bg_color)

    if visualize_normals:
        pl.add_arrows(np.asarray(pcd.points), np.asarray(pcd.normals))

    pl.show()

    return pl


def visualize_selectable_pointcloud(
    pcd: o3dPointCloud | np.ndarray,
    point_size: int = 3,
    camera_pos: list = None,
    bg_color: str | tuple = ("white", "gray"),
) -> Plotter:
    # 3D 뷰어 생성---------------------------------------------------------------
    if isinstance(pcd, o3dPointCloud):
        points = np.asarray(pcd.points)
        colors = np.asarray(pcd.colors) if pcd.has_colors() else None
    else:
        points = pcd
        colors = None
    pl = visualize_pointcloud(points, colors, point_size, camera_pos, bg_color)

    # 텍스트 출력 위젯 생성--------------------------------------------------------
    output = Textarea(layout=Layout(width="auto", height="80px"))

    def print_selected_point(point: np.ndarray, picker: vtkPointPicker):
        output.value = f"""
XYZ==
{point[0]}, {point[1]}, {point[2]}
ID==
{picker.GetPointId()}
""".strip()

    pl.enable_point_picking(callback=print_selected_point, use_picker=True)

    display(pl.show())
    display(output)

    return pl


def add_sphere(
    plotter: Plotter,
    center: np.ndarray | list | tuple,
    radius: float = 0.1,
    color: str | tuple = "red",
    label: str = None,
    label_offset: tuple = (0.1, 0.1, 0.1),
    opacity: float = 1.0,
):
    # center 타입 확인 후 numpy로 변환--------------------------------------------
    if not isinstance(center, np.ndarray):
        if isinstance(center, (list, tuple)) and len(center) == 3:
            center = np.array(center, dtype=float)
        else:
            raise ValueError("center must be a numpy array, or a list/tuple of length 3.")

    # 해당 좌표에 구 형상 추가-----------------------------------------------------
    plotter.add_mesh(pv.Sphere(center=center, radius=radius), color=color, opacity=opacity)

    # 라벨 추가------------------------------------------------------------------
    if label:
        label_position = center + np.array(label_offset)  # 라벨 위치를 구체 중심에서 약간 이동
        plotter.add_point_labels(
            [label_position],  # 라벨 위치
            [label],  # 라벨 텍스트
            point_size=1,
            font_size=12,
            text_color="black",
            always_visible=True,
        )


def add_cylinder(
    plotter: Plotter,
    center: np.ndarray | list | tuple,
    direction: np.ndarray | list | tuple,
    radius: float,
    height: float,
    color: str | tuple = "blue",
    opacity: float = 1.0,
):
    # center 타입 확인 후 numpy로 변환--------------------------------------------
    if not isinstance(center, np.ndarray):
        if isinstance(center, (list, tuple)) and len(center) == 3:
            center = np.array(center, dtype=float)
        else:
            raise ValueError("center must be a numpy array, or a list/tuple of length 3.")

    # direction 타입 확인 후 numpy로 변환-----------------------------------------
    if not isinstance(direction, np.ndarray):
        if isinstance(direction, (list, tuple)) and len(direction) == 3:
            direction = np.array(direction, dtype=float)
        else:
            raise ValueError("direction must be a numpy array, or a list/tuple of length 3.")

    # 방향 벡터 정규화------------------------------------------------------------
    direction = direction / np.linalg.norm(direction)

    # 해당 좌표에 실린더 형상 추가--------------------------------------------------
    plotter.add_mesh(
        pv.Cylinder(center=center, direction=direction, radius=radius, height=height),
        color=color,
        opacity=opacity,
    )


def calculate_arrows_from_pose_cadidates(xyzrpy):
    """Convert an array of shape (n,6) [x,y,z,roll,pitch,yaw] to array of shape (n,6) [x,y,z, dx,dy,dz]."""
    # xyzrpy는 numpy 배열입니다
    xyz = xyzrpy[..., 0:3]
    roll = xyzrpy[..., 3]
    pitch = xyzrpy[..., 4]
    yaw = xyzrpy[..., 5]

    # x축 방향 벡터 컴포넌트 계산
    dx = np.cos(yaw) * np.cos(pitch)
    dy = np.sin(yaw) * np.cos(pitch)
    dz = -np.sin(pitch)

    direction = np.stack([dx, dy, dz], axis=-1)
    # xyz와 방향 벡터 결합
    return np.concatenate([xyz, direction], axis=-1)