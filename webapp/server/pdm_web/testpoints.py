"""검사점 CSV 읽기·쓰기.

형식은 plugin_pdm 의 `<점군 stem>_testpoint.csv` 와 같다 — 첫 열은 헤더가 빈 1부터의 번호,
나머지는 `x,y,z,dx,dy,dz`(m). x,y,z 는 검사점(배관 표면), x+dx… 는 배관 프로파일을 잡을
탐지점이다(tools/export_poses.py 참조). 점군을 mm→m 로 환산해 읽었다면 좌표도 환산된 m 이다.
"""

from __future__ import annotations

import csv
import io
from pathlib import Path

COLUMNS = ("x", "y", "z", "dx", "dy", "dz")


def csv_path_for(cloud_path: Path) -> Path:
    return cloud_path.with_name(f"{cloud_path.stem}_testpoint.csv")


def read_points(path: Path) -> list[dict[str, float]]:
    rows = []
    with path.open(encoding="utf-8-sig", newline="") as f:
        for rec in csv.DictReader(f):
            rows.append({c: float(rec.get(c) or 0.0) for c in COLUMNS})
    return rows


def _fmt(v: float) -> str:
    s = f"{v:.6f}".rstrip("0").rstrip(".")
    return "0" if s in ("", "-0") else s


def points_to_csv(rows: list[dict[str, float]]) -> str:
    buf = io.StringIO()
    buf.write("," + ",".join(COLUMNS) + "\n")
    for i, r in enumerate(rows, start=1):
        buf.write(f"{i}," + ",".join(_fmt(float(r.get(c, 0.0))) for c in COLUMNS) + "\n")
    return buf.getvalue()


def write_points(path: Path, rows: list[dict[str, float]]) -> None:
    path.write_text(points_to_csv(rows), encoding="utf-8", newline="")
