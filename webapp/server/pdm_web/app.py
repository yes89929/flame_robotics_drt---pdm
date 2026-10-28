"""FastAPI 앱 — 화면(Vite)이 `/api/*` 로 호출한다.

동기 핸들러(def)는 FastAPI 가 스레드풀에서 돌리므로 점군 적재·PDM 실행이 서버 전체를
막지 않는다. PDM 자체는 PdmRunner 가 잠금으로 직렬화한다.
"""

from __future__ import annotations

from pathlib import Path
from typing import Any

from fastapi import FastAPI, HTTPException, Response
from fastapi.responses import FileResponse, JSONResponse
from pydantic import BaseModel

from . import paths
from .clouds import CloudStore
from .pdm_runner import DEFAULT_PARAMS, PdmRunner
from .testpoints import csv_path_for, read_points, write_points
from .urdf_model import load_urdf_model

app = FastAPI(title="PDM 웹 도구")
clouds = CloudStore()
runner = PdmRunner()


@app.exception_handler(KeyError)
def _missing(_request, exc: KeyError) -> JSONResponse:
    # 서버 재기동으로 점군 캐시가 비었는데 화면이 옛 id 로 요청하는 경우 등
    return JSONResponse({"detail": str(exc.args[0] if exc.args else exc)}, status_code=404)

#: 메시 원본 파일 제공을 허용하는 확장자 (URDF 가 참조하는 메시는 루트 밖에 있을 수 있다).
MESH_EXTS = {".stl", ".dae", ".obj", ".ply"}


def _existing(path: str) -> Path:
    # 옛 데이터 경로(브라우저에 저장된 것 등)는 지금 자리로 풀어 읽는다 — 응답의 path 로 새 경로가 돌아간다
    p = paths.resolve_path(path)
    if not p.exists():
        raise HTTPException(404, f"파일이 없습니다: {path}")
    return p


# ── 파일 탐색 ───────────────────────────────────────────────────────────────


@app.get("/api/fs/roots")
def fs_roots() -> list[dict[str, str]]:
    return [{"label": k, "path": str(v)} for k, v in paths.ROOTS.items()]


@app.get("/api/fs/list")
def fs_list(path: str, exts: str = "") -> dict[str, Any]:
    d = _existing(path)
    if not d.is_dir() or not paths.is_under_roots(d):
        raise HTTPException(400, f"탐색할 수 없는 폴더입니다: {path}")
    want = {e.lower() for e in exts.split(",") if e}
    dirs, files = [], []
    for child in sorted(d.iterdir(), key=lambda c: c.name.lower()):
        if child.name.startswith("."):
            continue
        if child.is_dir():
            dirs.append(child.name)
        elif not want or child.suffix.lower() in want:
            files.append({"name": child.name, "size": child.stat().st_size})
    parent = d.parent if d.parent != d and paths.is_under_roots(d.parent) else None
    return {"path": str(d), "parent": str(parent) if parent else None, "dirs": dirs, "files": files}


@app.get("/api/fs/raw")
def fs_raw(path: str) -> FileResponse:
    p = _existing(path)
    if p.suffix.lower() not in MESH_EXTS and not paths.is_under_roots(p):
        raise HTTPException(403, "제공할 수 없는 파일입니다")
    return FileResponse(p)


# ── URDF ────────────────────────────────────────────────────────────────────


@app.get("/api/urdf")
def urdf(path: str) -> dict[str, Any]:
    try:
        return load_urdf_model(_existing(path))
    except HTTPException:
        raise
    except Exception as exc:  # noqa: BLE001
        raise HTTPException(400, f"URDF 해석 실패: {exc}") from exc


# ── 점군 ────────────────────────────────────────────────────────────────────


class CloudLoad(BaseModel):
    path: str
    scale: float | None = None  # None = 범위로 mm/m 자동 판정
    max_points: int = 1_500_000


@app.post("/api/cloud/load")
def cloud_load(req: CloudLoad) -> dict[str, Any]:
    try:
        return clouds.load(_existing(req.path), req.scale, req.max_points).meta()
    except HTTPException:
        raise
    except Exception as exc:  # noqa: BLE001
        raise HTTPException(400, f"점군 적재 실패: {exc}") from exc


@app.get("/api/cloud/{cloud_id}/positions")
def cloud_positions(cloud_id: str) -> Response:
    return Response(clouds.get(cloud_id).display_positions(), media_type="application/octet-stream")


@app.get("/api/cloud/{cloud_id}/colors")
def cloud_colors(cloud_id: str) -> Response:
    return Response(clouds.get(cloud_id).display_colors(), media_type="application/octet-stream")


@app.delete("/api/cloud/{cloud_id}")
def cloud_unload(cloud_id: str) -> dict[str, bool]:
    clouds.unload(cloud_id)
    return {"ok": True}


# ── 검사점 ──────────────────────────────────────────────────────────────────


@app.get("/api/points")
def points_get(cloud_path: str) -> dict[str, Any]:
    csv = csv_path_for(paths.resolve_path(cloud_path))
    rows = read_points(csv) if csv.is_file() else []
    return {"csv_path": str(csv), "exists": csv.is_file(), "rows": rows}


class PointsSave(BaseModel):
    cloud_path: str
    rows: list[dict[str, float]]
    overwrite: bool = False


@app.put("/api/points")
def points_put(req: PointsSave) -> dict[str, Any]:
    csv = csv_path_for(paths.resolve_path(req.cloud_path))
    if csv.exists() and not req.overwrite:
        raise HTTPException(409, f"이미 있는 파일입니다: {csv.name}")
    write_points(csv, req.rows)
    return {"csv_path": str(csv), "count": len(req.rows)}


# ── PDM ─────────────────────────────────────────────────────────────────────


@app.get("/api/pdm/defaults")
def pdm_defaults() -> dict[str, Any]:
    return DEFAULT_PARAMS


class EeLinks(BaseModel):
    end_link: str
    tcp_link: str


class PdmRun(BaseModel):
    cloud_id: str
    urdf_path: str
    dda: EeLinks
    rt: EeLinks
    joint_positions: dict[str, float] = {}
    params: dict[str, Any] = {}
    point: dict[str, float]


@app.post("/api/pdm/run")
def pdm_run(req: PdmRun) -> dict[str, Any]:
    return runner.run(
        clouds.get(req.cloud_id), str(paths.resolve_path(req.urdf_path)), req.dda.model_dump(), req.rt.model_dump(), req.joint_positions, req.params, req.point
    )
