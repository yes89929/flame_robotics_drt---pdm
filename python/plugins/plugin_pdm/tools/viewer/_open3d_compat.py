"""Windows 한글 경로용 Open3D 호환 박막.

``open3d.io.read_triangle_mesh`` / ``read_point_cloud`` 등이 Windows 의
한글(또는 비-ASCII) 절대경로를 받으면 내부에서 UTF-8 디코딩 오류로 실패한다
(예: ``UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb3 …``).
원인은 Open3D 가 std::string 으로 받은 경로를 fopen 에 그대로 전달하면서
Windows 의 system code page 와 UTF-8 사이의 불일치를 처리하지 않는 것.

본 모듈은 진입점 (`__main__.py`) 에서 한 번 ``apply()`` 를 호출해 위 두
함수를 *경로를 Windows 8.3 단축경로 (순수 ASCII) 로 변환한 뒤 Open3D 에
전달하는 wrapper* 로 교체한다. 알고리즘 측 ``EndEffectorPoseOptimizer`` /
``JupyterVisualizer`` 코드는 한 줄도 수정하지 않으며, 이 박막은 viewer 가
존재하지 않을 때(예: 노트북 실행) 아무 영향도 주지 않는다.
"""

from __future__ import annotations

import ctypes
import os
from pathlib import Path
from typing import Any

_PATCHED = False


def _to_short_path(path: Any) -> Any:
    """Windows 에서 가능한 경우 경로를 8.3 단축형으로 변환. 비-Windows / 변환
    실패 시 원본 그대로 반환."""

    if os.name != "nt":
        return path
    if isinstance(path, Path):
        path_str = str(path)
    elif isinstance(path, (bytes, bytearray)):
        return path
    else:
        path_str = str(path)

    if not os.path.exists(path_str):
        # 존재하지 않는 경로는 단축이 불가능 — 원본 반환 (에러는 호출자가 처리)
        return path

    GetShortPathNameW = ctypes.windll.kernel32.GetShortPathNameW  # type: ignore[attr-defined]
    GetShortPathNameW.argtypes = [ctypes.c_wchar_p, ctypes.c_wchar_p, ctypes.c_uint]
    GetShortPathNameW.restype = ctypes.c_uint

    needed = GetShortPathNameW(path_str, None, 0)
    if needed == 0:
        return path
    buf = ctypes.create_unicode_buffer(needed)
    written = GetShortPathNameW(path_str, buf, needed)
    if written == 0:
        return path
    return buf.value


def apply() -> None:
    """``open3d.io`` 의 mesh/pcd 로더를 한글 경로 호환 wrapper 로 교체. 멱등."""

    global _PATCHED
    if _PATCHED:
        return

    import open3d as _o3d  # type: ignore
    import open3d.io as _o3dio  # type: ignore

    # Open3D 가 비-UTF-8 경로에 대해 system code page 로 로그 출력하면 pybind11
    # 가 그 메시지를 UTF-8 로 디코딩하려다 실패한다. 로그를 끔으로써 회피.
    try:
        _o3d.utility.set_verbosity_level(_o3d.utility.VerbosityLevel.Error)
    except Exception:  # noqa: BLE001
        pass

    _orig_read_triangle_mesh = _o3dio.read_triangle_mesh
    _orig_read_point_cloud = _o3dio.read_point_cloud

    def _patched_read_triangle_mesh(filename, *args, **kwargs):
        return _orig_read_triangle_mesh(_to_short_path(filename), *args, **kwargs)

    def _patched_read_point_cloud(filename, *args, **kwargs):
        return _orig_read_point_cloud(_to_short_path(filename), *args, **kwargs)

    _o3dio.read_triangle_mesh = _patched_read_triangle_mesh
    _o3dio.read_point_cloud = _patched_read_point_cloud

    _PATCHED = True
