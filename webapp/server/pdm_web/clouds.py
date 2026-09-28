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

        pcd = o3d.io.read_point_cloud(str(path))
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
