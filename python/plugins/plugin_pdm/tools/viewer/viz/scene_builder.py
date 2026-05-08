"""4-view subplot 에 동일 actor 를 추가하는 빌더.

PyVista ``Plotter(shape=(2,2))`` 의 4 subplot (iso/XY/XZ/YZ) 에 동일한 객체
를 추가한다. 0도 / 90도 pose group 의 변별성은 노트북 demo (cell
``1ea8ce44`` line 626/640) 의 색상 정책을 그대로 재사용한다.
"""

from __future__ import annotations

from typing import Any, Iterable

import numpy as np

# JupyterVisualizer 는 plugin_pdm 루트에서 직접 import (sys.path 가드 후).
import JupyterVisualizer as jv  # type: ignore

from .visualizer_adapter import (
    get_dda_inv_transform,
    get_dda_mesh,
    get_rt_inv_transform,
    get_rt_mesh,
    link_transform_for_tcp_pose,
)

# 노트북 demo cell 1ea8ce44 의 색상 정책
COLOR_DDA_0DEG: tuple[int, int, int] = (255, 150, 150)
COLOR_DDA_90DEG: tuple[int, int, int] = (150, 150, 255)
COLOR_RT_0DEG: tuple[int, int, int] = (255, 150, 150)
COLOR_RT_90DEG: tuple[int, int, int] = (150, 150, 255)

COLOR_PIPE_DEFAULT: str = "lightgray"
COLOR_TARGET_SPHERE: str = "red"

_SUBPLOT_CELLS: tuple[tuple[int, int, str], ...] = (
    (0, 0, "view_isometric"),
    (0, 1, "view_xy"),
    (1, 0, "view_xz"),
    (1, 1, "view_yz"),
)


def for_each_subplot(plot_view: Any) -> Iterable[tuple[int, int, str]]:
    """4 subplot 을 순회. 각 yield 직전에 ``plot_view.subplot(r, c)`` 활성화."""

    for r, c, view_fn in _SUBPLOT_CELLS:
        plot_view.subplot(r, c)
        yield r, c, view_fn


def restore_camera_views(plot_view: Any) -> None:
    """``clear()`` 후 손상된 카메라 프리셋을 복원."""

    for r, c, view_fn in _SUBPLOT_CELLS:
        plot_view.subplot(r, c)
        getattr(plot_view, view_fn)()


def _draw_scan_and_target(
    plot_view: Any,
    scan_polydata: Any,
    target: np.ndarray,
    has_color: bool,
    sphere_radius: float,
) -> None:
    """현재 active subplot 에 배경·점군·타겟 sphere·좌표축을 일괄 추가."""

    plot_view.set_background("white", top="gray")
    if scan_polydata is not None:
        if has_color:
            plot_view.add_mesh(scan_polydata, scalars="colors", rgb=True, point_size=2)
        else:
            plot_view.add_mesh(scan_polydata, color=COLOR_PIPE_DEFAULT, point_size=2)
    jv.add_sphere(plot_view, target, radius=sphere_radius, color=COLOR_TARGET_SPHERE)
    jv.add_coordinate_frame(plot_view, origin=(0, 0, 0), length=0.05, size=0.001)


def render_pipe(
    plot_view: Any,
    scan_polydata: Any,
    target_point: tuple[float, float, float] | np.ndarray,
    sphere_radius: float = 0.01,
) -> None:
    """4 subplot 에 배관 점군 + 검사 포인트 sphere 만 표시."""

    has_color = scan_polydata is not None and "colors" in scan_polydata.array_names
    target = np.asarray(target_point, dtype=float)

    for _r, _c, _view_fn in for_each_subplot(plot_view):
        _draw_scan_and_target(plot_view, scan_polydata, target, has_color, sphere_radius)
    restore_camera_views(plot_view)


def render_result(
    plot_view: Any,
    scan_polydata: Any,
    target_point: tuple[float, float, float] | np.ndarray,
    pose_groups: list[dict],
    optimizer: Any,
    sphere_radius: float = 0.01,
) -> None:
    """4 subplot 에 배관 + 포인트 + 채택된 pose_group 의 DDA/RT 메시 동시 렌더.

    ``pose_groups`` 는 ``calculate_DDA_RT_pose_for_taking_xray`` 의 두 번째
    반환값. 각 dict 는 ``"0"`` / ``"90"`` 키를 가지며 그 아래 ``DDA`` /
    ``RT1`` / ``RT2`` 가 ``[x,y,z,r,p,y]`` 6-벡터.
    """

    has_color = scan_polydata is not None and "colors" in scan_polydata.array_names
    target = np.asarray(target_point, dtype=float)

    dda_mesh = get_dda_mesh(optimizer)
    rt_mesh = get_rt_mesh(optimizer)
    dda_inv = get_dda_inv_transform(optimizer)
    rt_inv = get_rt_inv_transform(optimizer)

    for _r, _c, _view_fn in for_each_subplot(plot_view):
        _draw_scan_and_target(plot_view, scan_polydata, target, has_color, sphere_radius)

        # 채택된 pose_group 모두 동시 표시 (0도/90도 색상 분리)
        for pg in pose_groups:
            for angle_key, dda_color, rt_color in (
                ("0", COLOR_DDA_0DEG, COLOR_RT_0DEG),
                ("90", COLOR_DDA_90DEG, COLOR_RT_90DEG),
            ):
                if angle_key not in pg:
                    continue
                slot = pg[angle_key]
                dda_pose = slot.get("DDA")
                if dda_pose is not None:
                    T = link_transform_for_tcp_pose(dda_pose, dda_inv)
                    jv.add_mesh(plot_view, dda_mesh, T, color=dda_color, show_edges=False)
                for rt_key in ("RT1", "RT2"):
                    rt_pose = slot.get(rt_key)
                    if rt_pose is None:
                        continue
                    T = link_transform_for_tcp_pose(rt_pose, rt_inv)
                    jv.add_mesh(plot_view, rt_mesh, T, color=rt_color, show_edges=False)

    restore_camera_views(plot_view)
