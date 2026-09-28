"""저장소·PDM 플러그인 경로와 파일 탐색 허용 루트.

plugin_pdm 은 패키지가 아니라 sys.path 에 디렉터리를 넣고 모듈명으로 임포트하는 구조라
(노트북·tools/viewer 와 같은 방식) 여기서 한 번 경로를 잡고 Open3D 한글 경로 박막을 켠다.
"""

from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[3]
PLUGIN_PDM_DIR = REPO_ROOT / "python" / "plugins" / "plugin_pdm"

if str(PLUGIN_PDM_DIR) not in sys.path:
    sys.path.insert(0, str(PLUGIN_PDM_DIR))

from tools.viewer import _open3d_compat  # noqa: E402

_open3d_compat.apply()

from data_paths import DATA_ROOT  # noqa: E402

#: 파일 선택 창이 보여 주는 최상위 폴더 (라벨 → 경로).
ROOTS: dict[str, Path] = {
    "드라이브 기타자료": DATA_ROOT,
    "저장소": REPO_ROOT,
}


def is_under_roots(path: Path) -> bool:
    resolved = path.resolve()
    return any(resolved == root.resolve() or root.resolve() in resolved.parents for root in ROOTS.values())
