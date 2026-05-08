"""좌측 사이드 패널.

위→아래 순서:
  1. 배관 데이터 콤보
  2. "엔드이펙터 최적 위치 탐지" 버튼
  3. 배관 전체 오버뷰 위젯 (점군 + 검사 포인트 sphere + 인덱스 라벨)
  4. 검사 포인트 목록 (글자색 검정, 선택 항목 굵은 표시)

사용자 액션은 시그널로만 외부에 노출하며 내부 상태는 없다 (MainWindow 가
단일 출처). 오버뷰 위젯은 ``update_overview()`` 로 외부에서 재렌더링한다.
"""

from __future__ import annotations

from typing import Any

from PyQt6.QtCore import Qt, pyqtSignal
from PyQt6.QtGui import QBrush, QColor, QPalette
from PyQt6.QtWidgets import (
    QComboBox,
    QLabel,
    QListWidget,
    QListWidgetItem,
    QPushButton,
    QVBoxLayout,
    QWidget,
)
from pyvistaqt import QtInteractor

from ..models import InspectionPoint, PointStatus
from ..viz import scene_builder

# 시스템 다크 테마에서도 가시성을 유지하기 위해 채도/명도를 강하게 잡는다.
_STATUS_BG = {
    PointStatus.UNRUN: QColor("#e8e8e8"),    # 밝은 회색
    PointStatus.SUCCESS: QColor("#7ed87e"),  # 진한 녹색 (성공)
    PointStatus.FAILURE: QColor("#e87a7a"),  # 진한 분홍/빨강 (실패)
}

_TEXT_BLACK = QBrush(QColor("black"))

# Stylesheet 는 ``QListWidget::item:selected`` 에 background 를 지정하지 않아
# ``setBackground`` 로 그린 상태색이 그대로 보이도록 한다. 선택 강조는 굵은
# 글씨 + 두꺼운 좌측 주황 테두리로만 처리.
_LIST_STYLESHEET = """
QListWidget {
    background-color: white;
    color: black;
    font-size: 11pt;
    outline: 0;
    border: 1px solid #909090;
    selection-background-color: rgba(255, 102, 0, 110);
    selection-color: black;
}
QListWidget::item {
    color: black;
    padding: 6px 10px;
    border-left: 4px solid transparent;
}
QListWidget::item:selected {
    color: black;
    font-weight: bold;
    border-left: 4px solid #ff6600;
}
QListWidget::item:selected:!active {
    color: black;
    font-weight: bold;
    border-left: 4px solid #ff6600;
}
"""


def _force_light_palette(widget: QWidget) -> None:
    """다크 테마 환경에서도 흰 배경 + 검정 글자가 강제되도록 팔레트 재설정."""

    palette = widget.palette()
    palette.setColor(QPalette.ColorRole.Base, QColor("white"))
    palette.setColor(QPalette.ColorRole.AlternateBase, QColor("white"))
    palette.setColor(QPalette.ColorRole.Window, QColor("white"))
    palette.setColor(QPalette.ColorRole.Text, QColor("black"))
    palette.setColor(QPalette.ColorRole.WindowText, QColor("black"))
    palette.setColor(QPalette.ColorRole.HighlightedText, QColor("black"))
    widget.setPalette(palette)


class SidePanel(QWidget):
    pipe_changed = pyqtSignal(int)            # 콤보 currentIndex
    optimize_clicked = pyqtSignal()
    point_selected = pyqtSignal(int)          # InspectionPoint.index

    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)

        layout = QVBoxLayout(self)
        layout.setContentsMargins(8, 8, 8, 8)
        layout.setSpacing(6)

        layout.addWidget(QLabel("배관 데이터"))
        self._combo = QComboBox(self)
        layout.addWidget(self._combo)

        self._optimize_btn = QPushButton("엔드이펙터 최적 위치 탐지", self)
        self._optimize_btn.setEnabled(False)
        layout.addWidget(self._optimize_btn)

        # 배관 전체 오버뷰 (검사 포인트 sphere + 인덱스 라벨)
        layout.addWidget(QLabel("배관 전체"))
        self._overview = QtInteractor(self)
        self._overview.setMinimumHeight(220)
        self._overview.set_background("white")
        self._overview.add_axes()
        # CAD 스타일 평행 투영 (notebook 의 ``visualize_pointcloud`` 기본값과 동일).
        self._overview.camera.parallel_projection = True
        layout.addWidget(self._overview, stretch=2)

        layout.addWidget(QLabel("검사 포인트"))
        self._list = QListWidget(self)
        self._list.setStyleSheet(_LIST_STYLESHEET)
        _force_light_palette(self._list)
        # 항목 폰트 크기 일관성을 위해 명시적 스타일.
        list_font = self._list.font()
        list_font.setPointSize(11)
        self._list.setFont(list_font)
        layout.addWidget(self._list, stretch=3)

        # 시그널 라우팅
        self._combo.currentIndexChanged.connect(self._on_combo_changed)
        self._optimize_btn.clicked.connect(self.optimize_clicked.emit)
        self._list.currentItemChanged.connect(self._on_list_item_changed)

    # ----- public API -------------------------------------------------------

    def set_pipes(self, pipe_ids: list[str]) -> None:
        self._combo.blockSignals(True)
        self._combo.clear()
        for pid in pipe_ids:
            self._combo.addItem(pid)
        self._combo.blockSignals(False)

    def current_pipe_index(self) -> int:
        return self._combo.currentIndex()

    def set_current_pipe_index_silent(self, index: int) -> None:
        self._combo.blockSignals(True)
        self._combo.setCurrentIndex(index)
        self._combo.blockSignals(False)

    def set_pipe_combo_enabled(self, enabled: bool) -> None:
        self._combo.setEnabled(enabled)

    def set_points(self, points: list[InspectionPoint]) -> None:
        self._list.blockSignals(True)
        self._list.clear()
        for point in points:
            item = QListWidgetItem(f"#{point.index}")
            item.setData(Qt.ItemDataRole.UserRole, point.index)
            item.setBackground(QBrush(_STATUS_BG[PointStatus.UNRUN]))
            item.setForeground(_TEXT_BLACK)
            self._list.addItem(item)
        self._list.blockSignals(False)

    def update_point_status(
        self,
        list_position: int,
        status: PointStatus,
        tooltip: str | None = None,
    ) -> None:
        item = self._list.item(list_position)
        if item is None:
            return
        item.setBackground(QBrush(_STATUS_BG[status]))
        item.setForeground(_TEXT_BLACK)
        item.setToolTip(tooltip or "")

    def set_optimize_enabled(self, enabled: bool) -> None:
        self._optimize_btn.setEnabled(enabled)

    def set_optimize_label(self, text: str) -> None:
        self._optimize_btn.setText(text)

    def update_overview(
        self,
        scan_polydata: Any,
        points: list[InspectionPoint],
    ) -> None:
        """오버뷰 위젯을 (배관 전체 점군 + 검사 포인트 sphere + 라벨) 로 재렌더."""

        scene_builder.render_overview(self._overview, scan_polydata, points)
        self._overview.render()

    def clear_overview(self) -> None:
        self._overview.clear()
        self._overview.render()

    def cleanup(self) -> None:
        """``MainWindow.closeEvent`` 에서 호출. QtInteractor 안전 종료."""

        try:
            self._overview.close()
        except Exception:  # noqa: BLE001
            pass

    # ----- 내부 -------------------------------------------------------------

    def _on_combo_changed(self, index: int) -> None:
        self.pipe_changed.emit(index)

    def _on_list_item_changed(
        self,
        current: QListWidgetItem | None,
        _previous: QListWidgetItem | None,
    ) -> None:
        if current is None:
            return
        idx = current.data(Qt.ItemDataRole.UserRole)
        if isinstance(idx, int):
            self.point_selected.emit(idx)
