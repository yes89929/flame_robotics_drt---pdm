"""좌측 사이드 패널.

위→아래 순서: (1) 배관 데이터 콤보, (2) "엔드이펙터 최적 위치 탐지" 버튼,
(3) 검사 포인트 목록. 사용자 액션은 시그널로만 외부에 노출하며 내부 상태는
없다 (MainWindow 가 단일 출처).
"""

from __future__ import annotations

from PyQt6.QtCore import Qt, pyqtSignal
from PyQt6.QtGui import QBrush, QColor
from PyQt6.QtWidgets import (
    QComboBox,
    QLabel,
    QListWidget,
    QListWidgetItem,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

from ..models import InspectionPoint, PointStatus

_STATUS_BG = {
    PointStatus.UNRUN: QColor("#dcdcdc"),
    PointStatus.SUCCESS: QColor("#b6e6b6"),
    PointStatus.FAILURE: QColor("#f5b6b6"),
}


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

        layout.addWidget(QLabel("검사 포인트"))
        self._list = QListWidget(self)
        layout.addWidget(self._list, stretch=1)

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
        item.setToolTip(tooltip or "")

    def set_optimize_enabled(self, enabled: bool) -> None:
        self._optimize_btn.setEnabled(enabled)

    def set_optimize_label(self, text: str) -> None:
        self._optimize_btn.setText(text)

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
