"""``QtInteractor(shape=(2,2))`` 캡슐화 + 4-view 카메라 프리셋.

PyVista ``Plotter`` 의 서브클래스인 ``QtInteractor`` 를 그대로 사용해
JupyterVisualizer 의 헬퍼를 수정 없이 재사용한다.
"""

from __future__ import annotations

from typing import Any

from pyvistaqt import QtInteractor

from ..viz import scene_builder


class PlotView(QtInteractor):
    """4-view (iso/XY/XZ/YZ) 메인 3D 뷰."""

    def __init__(self, parent=None) -> None:
        super().__init__(parent, shape=(2, 2))
        self._configure_views()

    def _configure_views(self) -> None:
        for r, c, view_fn in (
            (0, 0, "view_isometric"),
            (0, 1, "view_xy"),
            (1, 0, "view_xz"),
            (1, 1, "view_yz"),
        ):
            self.subplot(r, c)
            self.set_background("white", top="gray")
            getattr(self, view_fn)()
            self.add_axes()

    def clear_all(self) -> None:
        for r, c in ((0, 0), (0, 1), (1, 0), (1, 1)):
            self.subplot(r, c)
            self.clear()

    def set_pipe_only(
        self,
        scan_polydata: Any,
        target_point,
    ) -> None:
        self.clear_all()
        scene_builder.render_pipe(self, scan_polydata, target_point)
        self.render()

    def set_full_result(
        self,
        scan_polydata: Any,
        target_point,
        pose_groups: list[dict],
        optimizer: Any,
    ) -> None:
        self.clear_all()
        scene_builder.render_result(
            self,
            scan_polydata,
            target_point,
            pose_groups,
            optimizer,
        )
        self.render()
