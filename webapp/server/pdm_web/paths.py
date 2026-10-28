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
    "과제 데이터": DATA_ROOT,
    "저장소": REPO_ROOT,
}

#: 과제 폴더 재정리(2026-10) 전의 데이터 루트. 그 아래 `<묶음 폴더>\...` 가 지금은
#: `DATA_ROOT\attachments\<묶음 페이지 id>\...` 로 옮겨졌다. 브라우저(localStorage)에 남은
#: 옛 경로를 `resolve_path` 가 새 자리로 풀어 준다. DATA_ROOT 자신도 넣는 이유는 재정리 도중
#: 한때 `DATA_ROOT\<묶음 폴더>\...` 였기 때문이다(커밋 7beaf4f).
LEGACY_DATA_ROOTS: list[Path] = [
    Path(r"G:\내 드라이브\3. 진행 과제\P2413；DRT\3. 기타자료"),
    DATA_ROOT,
]


def bundle_dirs(data_root: Path) -> dict[str, Path]:
    """묶음 이름(데이터 페이지 파일 이름) → 그 페이지의 첨부 폴더 `attachments\\<id>`.

    과제 폴더 규칙상 묶음의 파일은 페이지 frontmatter `id:` 이름의 첨부 폴더에 있다. 옛 묶음
    폴더 이름이 페이지 제목(파일 이름)과 같으므로 이 표로 옛 경로를 옮길 수 있다.
    """
    out: dict[str, Path] = {}
    for page in data_root.glob("*.md"):
        with page.open(encoding="utf-8") as f:
            head = [next(f, "") for _ in range(30)]  # id 는 frontmatter 맨 앞에 있다
        for line in head:
            if line.startswith("id:"):
                out[page.stem] = data_root / "attachments" / line.split(":", 1)[1].strip()
                break
    return out


def resolve_path(path: str | Path) -> Path:
    """있는 경로는 그대로, 없는 옛 데이터 경로는 지금 자리로 바꿔 돌려준다(못 찾으면 원래 경로)."""
    p = Path(path)
    if p.exists():
        return p
    bundles: dict[str, Path] | None = None
    for legacy in LEGACY_DATA_ROOTS:
        try:
            rel = p.relative_to(legacy)
        except ValueError:
            continue
        if not rel.parts:
            return DATA_ROOT
        bundles = bundles if bundles is not None else bundle_dirs(DATA_ROOT)
        target = bundles.get(rel.parts[0])
        if target is not None and target.joinpath(*rel.parts[1:]).exists():
            return target.joinpath(*rel.parts[1:])
    return p


def is_under_roots(path: Path) -> bool:
    resolved = path.resolve()
    return any(resolved == root.resolve() or root.resolve() in resolved.parents for root in ROOTS.values())
