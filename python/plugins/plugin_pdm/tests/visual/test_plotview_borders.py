"""PlotView 4-view 의 subplot 경계선 시각 검증.

pytest-qt + (a) ``plot_view.screenshot()`` (VTK off-screen render)
+ (b) ``plot_view.grab()`` (Qt OpenGL displayed pixels) 두 경로로
PNG 를 만들어 ``tests/visual/_artifacts/`` 에 저장. 사람(또는 멀티모달
LLM) 이 두 PNG 를 비교해 border 가 실제 화면에서 보이는지 확인한다.
"""

from __future__ import annotations

from pathlib import Path

import numpy as np
import pyvista as pv

# tools.viewer.widgets.plot_view 는 conftest.py 에서 sys.path 가 셋업된 후 import
from tools.viewer.widgets.plot_view import PlotView

ARTIFACT_DIR = Path(__file__).resolve().parent / "_artifacts"


def _ensure_artifact_dir() -> None:
    ARTIFACT_DIR.mkdir(parents=True, exist_ok=True)


def _make_dummy_polydata() -> pv.PolyData:
    n = 8
    xs = np.linspace(-0.1, 0.1, n)
    ys = np.linspace(-0.1, 0.1, n)
    zs = np.linspace(-0.1, 0.1, n)
    pts = np.array(np.meshgrid(xs, ys, zs)).reshape(3, -1).T
    return pv.PolyData(pts)


def test_plotview_borders_vtk_screenshot(qtbot):
    """VTK off-screen ``screenshot()`` 경로 — 항상 완전한 렌더링."""

    _ensure_artifact_dir()
    plot_view = PlotView()
    qtbot.addWidget(plot_view)
    plot_view.resize(1200, 800)
    plot_view.show()
    qtbot.waitExposed(plot_view)

    pcd = _make_dummy_polydata()
    for r, c in ((0, 0), (0, 1), (1, 0), (1, 1)):
        plot_view.subplot(r, c)
        plot_view.add_mesh(pcd, color="skyblue", point_size=3)
    plot_view.render()
    qtbot.wait(500)

    png_path = ARTIFACT_DIR / "plotview_4view_vtk_screenshot.png"
    plot_view.screenshot(filename=str(png_path))
    assert png_path.exists()
    plot_view.close()


def test_plotview_borders_qt_grab(qtbot):
    """Qt ``QWidget.grab()`` — 실제 화면에 표시되는 픽셀 (OpenGL 포함).

    이 경로가 사용자가 실제로 보는 화면과 동일하다. ``screenshot()`` 과
    이 PNG 가 다르면 QtInteractor 의 OpenGL 렌더가 border 를 그리지 않는
    것 — 그 경우 Qt 위젯 레벨 우회가 필요하다.
    """

    _ensure_artifact_dir()
    plot_view = PlotView()
    qtbot.addWidget(plot_view)
    plot_view.resize(1200, 800)
    plot_view.show()
    qtbot.waitExposed(plot_view)

    pcd = _make_dummy_polydata()
    for r, c in ((0, 0), (0, 1), (1, 0), (1, 1)):
        plot_view.subplot(r, c)
        plot_view.add_mesh(pcd, color="skyblue", point_size=3)
    plot_view.render()
    # OpenGL 페인트가 끝나도록 충분히 대기
    qtbot.wait(800)

    pixmap = plot_view.grab()
    png_path = ARTIFACT_DIR / "plotview_4view_qt_grab.png"
    pixmap.save(str(png_path))
    assert png_path.exists()
    assert png_path.stat().st_size > 5000
    plot_view.close()
