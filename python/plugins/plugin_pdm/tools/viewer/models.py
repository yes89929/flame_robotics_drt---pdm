"""tools/viewer 의 도메인 dataclass.

UI / worker / signal 이 공유하는 단일 자료형 정의. ``InspectionResult`` 는
``BatchWorker`` 가 emit 직전 deepcopy 해서 메인 스레드로 전달한다.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path


class PointStatus(Enum):
    UNRUN = "unrun"
    SUCCESS = "success"
    FAILURE = "failure"


@dataclass(frozen=True)
class PipeData:
    pipe_id: str  # 예: "PIPE NO.1"
    ply_path: Path
    csv_path: Path


@dataclass(frozen=True)
class InspectionPoint:
    index: int  # CSV 행 인덱스 (1-base, CSV 첫 열 그대로)
    position: tuple[float, float, float]  # (x, y, z)
    offset: tuple[float, float, float]  # (dx, dy, dz), 누락 시 (0,0,0)

    @property
    def position_with_offset(self) -> tuple[float, float, float]:
        return (
            self.position[0] + self.offset[0],
            self.position[1] + self.offset[1],
            self.position[2] + self.offset[2],
        )


@dataclass
class InspectionResult:
    point_index: int
    success: bool
    pose_groups: list[dict] = field(default_factory=list)
    debuging_info: dict | None = None
    error_message: str | None = None
