"""tools/viewer 진입점.

호출:
    python -m plugins.plugin_pdm.tools.viewer        # python/ 디렉토리 기준
    python python/plugins/plugin_pdm/tools/viewer/__main__.py
"""

from __future__ import annotations

import sys
from pathlib import Path


def _ensure_plugin_pdm_on_sys_path() -> None:
    """plugin_pdm 디렉토리를 sys.path 에 추가.

    노트북/`controller.py:24` 가 사용하는 ``sys.path.append`` 패턴을 따르며
    중복 추가 방지를 위한 idempotent 가드를 둔다.
    """

    plugin_root = str(Path(__file__).resolve().parents[2])
    if plugin_root not in sys.path:
        sys.path.append(plugin_root)


def main() -> int:
    _ensure_plugin_pdm_on_sys_path()

    # PyQt6 import 는 path 셋업 이후
    from PyQt6.QtWidgets import QApplication

    from .widgets.main_window import MainWindow

    app = QApplication.instance() or QApplication(sys.argv)
    window = MainWindow()
    window.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
