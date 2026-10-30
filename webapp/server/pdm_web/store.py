"""웹 도구 작업 상태·PDM 결과 저장소 (`webapp/.local/`, git 무시).

브라우저 localStorage 는 브라우저·주소(127.0.0.1 / Tailscale)마다 따로라, 다른 창으로 열면 URDF·점군이
비어 보였다. 그래서 작업 상태(마지막 URDF·열어 둔 점군·작업 대상·PDM 링크 지정·파라미터·탭)를
서버 파일로 둔다.

자리는 **메인 체크아웃** 기준이다 — git 무시 파일은 워크트리에 따라오지 않으므로 워크트리에서 서버를 띄워도
같은 상태를 보게 한다. `PDM_WEB_LOCAL_DIR` 로 바꿀 수 있다(테스트용).
"""

from __future__ import annotations

import hashlib
import json
import os
import subprocess
import threading
from pathlib import Path
from typing import Any

from . import paths

_lock = threading.Lock()


def _main_checkout(repo_root: Path) -> Path:
    try:
        common = subprocess.run(
            ["git", "rev-parse", "--path-format=absolute", "--git-common-dir"],
            cwd=repo_root, capture_output=True, text=True, timeout=10, check=True,
        ).stdout.strip()
        return Path(common).parent
    except Exception:  # noqa: BLE001 — git 이 없으면 이 저장소 자리를 쓴다
        return repo_root


def local_dir() -> Path:
    env = os.environ.get("PDM_WEB_LOCAL_DIR")
    return Path(env) if env else _main_checkout(paths.REPO_ROOT) / "webapp" / ".local"


def _read(path: Path, default: Any) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError):
        return default


def _write(path: Path, data: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding="utf-8")
    tmp.replace(path)  # 쓰다 끊겨도 반쪽 파일이 남지 않게


# ── 작업 상태 ────────────────────────────────────────────────────────────────

#: 저장하는 키. designations 는 URDF 경로 → 링크 지정이라 키 단위로 합친다.
SESSION_KEYS = ("lastUrdf", "clouds", "activeCloud", "designations", "params", "tab")


def get_session() -> dict[str, Any]:
    return _read(local_dir() / "session.json", {})


def update_session(patch: dict[str, Any]) -> dict[str, Any]:
    with _lock:
        cur = get_session()
        for key, value in patch.items():
            if key not in SESSION_KEYS:
                continue
            if key == "designations" and isinstance(value, dict):
                cur["designations"] = {**cur.get("designations", {}), **value}
            else:
                cur[key] = value
        _write(local_dir() / "session.json", cur)
        return cur


# ── PDM 결과 ─────────────────────────────────────────────────────────────────
# 점군 파일마다 한 파일: {"cloud_path", "results": {"<검사점 번호(0부터)>": PDM 결과}}.
# 화면이 검사점을 지우거나 옮기면 번호를 다시 매긴 묶음 전체를 다시 저장한다.


def _results_file(cloud_path: str) -> Path:
    key = str(paths.resolve_path(cloud_path).resolve()).lower()
    return local_dir() / "pdm_results" / f"{hashlib.sha1(key.encode('utf-8')).hexdigest()[:16]}.json"


def get_results(cloud_path: str) -> dict[str, Any]:
    return _read(_results_file(cloud_path), {}).get("results", {})


def save_results(cloud_path: str, results: dict[str, Any]) -> None:
    with _lock:
        _write(_results_file(cloud_path), {"cloud_path": str(paths.resolve_path(cloud_path)), "results": results})
