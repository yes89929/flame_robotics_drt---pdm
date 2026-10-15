"""점군 적재·단위 환산·화면용 축소.

원본 점군은 미터로 환산해 메모리에 둔다(PDM 은 m 단위 — plugin_pdm AGENTS.md "단위 주의").
화면에는 최대 `max_points` 개를 균일 무작위로 골라 보낸다. 무작위 추출은 원본 좌표를 그대로
유지하므로, 화면에서 찍은 점은 항상 실제 스캔 점이다.
"""

from __future__ import annotations

import hashlib
import threading
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np
import open3d as o3d

#: 범위(최대 축 길이)가 이 값(원본 단위)을 넘으면 mm 로 보고 0.001 을 곱한다.
#: 배관·검사룸은 수 m 규모라 m 단위면 100 을 넘지 않고, mm 단위면 수천이다.
MM_GUESS_EXTENT = 100.0


_PCD_TYPES = {("F", 4): "<f4", ("F", 8): "<f8", ("U", 1): "u1", ("U", 2): "<u2", ("U", 4): "<u4",
              ("I", 1): "i1", ("I", 2): "<i2", ("I", 4): "<i4"}


def read_pcd(path: Path) -> o3d.geometry.PointCloud:
    """PCD(ascii·binary)를 직접 읽는다.

    Open3D 는 현장 스캔 PCD(2026-09-15 보정본 등)를 0점으로 읽는다 — 첫 줄이 VERSION 이 아닌
    주석이고 rgb 가 U(uint32)형이라서다. 필드는 x y z 필수, rgb/rgba·normal_x..z(또는 nx..nz) 선택.
    binary_compressed 는 지원하지 않으므로 Open3D 로 넘긴다.
    """
    header: dict[str, list[str]] = {}
    with path.open("rb") as f:
        while True:
            line = f.readline()
            if not line:
                raise ValueError("PCD 헤더가 끝나지 않았습니다")
            text = line.decode("ascii", "replace").strip()
            if not text or text.startswith("#"):
                continue
            key, *vals = text.split()
            header[key.upper()] = vals
            if key.upper() == "DATA":
                break
        data_kind = header["DATA"][0].lower()
        if data_kind not in ("ascii", "binary"):
            return o3d.io.read_point_cloud(str(path))
        names = header["FIELDS"]
        counts = [int(c) for c in header.get("COUNT", ["1"] * len(names))]
        dtype = np.dtype([
            (n, _PCD_TYPES[(t, int(s))], (c,)) if c > 1 else (n, _PCD_TYPES[(t, int(s))])
            for n, t, s, c in zip(names, header["TYPE"], header["SIZE"], counts)
        ])
        n_pts = int(header.get("POINTS", [0])[0])
        if data_kind == "binary":
            rec = np.frombuffer(f.read(dtype.itemsize * n_pts), dtype=dtype, count=n_pts)
        else:
            rec = np.loadtxt(f, dtype=dtype, max_rows=n_pts, ndmin=1)

    xyz = np.stack([rec["x"], rec["y"], rec["z"]], axis=1).astype(np.float64)
    ok = np.isfinite(xyz).all(axis=1)
    pcd = o3d.geometry.PointCloud(o3d.utility.Vector3dVector(xyz[ok]))
    color_field = next((c for c in ("rgb", "rgba") if c in names), None)
    if color_field:
        packed = np.ascontiguousarray(rec[color_field]).view(np.uint32)[ok]
        rgb = np.stack([(packed >> 16) & 255, (packed >> 8) & 255, packed & 255], axis=1) / 255.0
        pcd.colors = o3d.utility.Vector3dVector(rgb)
    for nx, ny, nz in (("normal_x", "normal_y", "normal_z"), ("nx", "ny", "nz")):
        if nx in names:
            nrm = np.stack([rec[nx], rec[ny], rec[nz]], axis=1).astype(np.float64)[ok]
            pcd.normals = o3d.utility.Vector3dVector(nrm)
            break
    return pcd


def read_cloud(path: Path) -> o3d.geometry.PointCloud:
    if path.suffix.lower() == ".pcd":
        return read_pcd(path)
    return o3d.io.read_point_cloud(str(path))


@dataclass
class Cloud:
    id: str
    path: Path
    scale: float
    pcd: o3d.geometry.PointCloud
    display_idx: np.ndarray
    normals_estimated: bool = False
    lock: threading.Lock = field(default_factory=threading.Lock)

    def meta(self) -> dict:
        pts = np.asarray(self.pcd.points)
        return {
            "id": self.id,
            "path": str(self.path),
            "name": self.path.name,
            "scale": self.scale,
            "unit": "mm→m" if self.scale == 0.001 else ("m" if self.scale == 1.0 else f"×{self.scale:g}"),
            "n_points": int(len(pts)),
            "n_display": int(len(self.display_idx)),
            "has_colors": self.pcd.has_colors(),
            "has_normals": self.pcd.has_normals(),
            "normals_estimated": self.normals_estimated,
            "bbox_min": pts.min(axis=0).tolist() if len(pts) else [0, 0, 0],
            "bbox_max": pts.max(axis=0).tolist() if len(pts) else [0, 0, 0],
        }

    def display_positions(self) -> bytes:
        pts = np.asarray(self.pcd.points)[self.display_idx]
        return pts.astype("<f4").tobytes()

    def display_colors(self) -> bytes:
        if not self.pcd.has_colors():
            return b""
        cols = np.asarray(self.pcd.colors)[self.display_idx]
        return np.clip(cols * 255.0 + 0.5, 0, 255).astype(np.uint8).tobytes()

    def ensure_normals(self) -> None:
        """PDM 배관 프로파일은 점 법선의 중앙값을 쓴다. 법선이 없는 파일이면 추정한다."""
        with self.lock:
            if self.pcd.has_normals():
                return
            self.pcd.estimate_normals(o3d.geometry.KDTreeSearchParamHybrid(radius=0.01, max_nn=30))
            self.normals_estimated = True


class CloudStore:
    def __init__(self) -> None:
        self._clouds: dict[str, Cloud] = {}
        self._lock = threading.Lock()

    def get(self, cloud_id: str) -> Cloud:
        if cloud_id not in self._clouds:
            raise KeyError(f"적재되지 않은 점군입니다: {cloud_id}")
        return self._clouds[cloud_id]

    def load(self, path: Path, scale: float | None, max_points: int) -> Cloud:
        key = f"{path.resolve()}|{scale}|{max_points}"
        cloud_id = hashlib.sha1(key.encode("utf-8")).hexdigest()[:12]
        with self._lock:
            if cloud_id in self._clouds:
                return self._clouds[cloud_id]

        pcd = read_cloud(path)
        pts = np.asarray(pcd.points)
        if len(pts) == 0:
            raise ValueError(f"점이 없는 파일이거나 읽을 수 없는 형식입니다: {path.name}")
        if scale is None:
            extent = float((pts.max(axis=0) - pts.min(axis=0)).max())
            scale = 0.001 if extent > MM_GUESS_EXTENT else 1.0
        if scale != 1.0:
            pcd.scale(scale, np.zeros(3))

        n = len(pts)
        if n > max_points:
            rng = np.random.default_rng(0)
            display_idx = np.sort(rng.choice(n, size=max_points, replace=False))
        else:
            display_idx = np.arange(n)

        cloud = Cloud(id=cloud_id, path=path, scale=scale, pcd=pcd, display_idx=display_idx)
        with self._lock:
            self._clouds[cloud_id] = cloud
        return cloud

    def unload(self, cloud_id: str) -> None:
        with self._lock:
            self._clouds.pop(cloud_id, None)
