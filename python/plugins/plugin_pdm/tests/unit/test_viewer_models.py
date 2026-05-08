"""tools/viewer.models 단위 테스트."""

from __future__ import annotations

from pathlib import Path

from tools.viewer.models import (
    InspectionPoint,
    InspectionResult,
    PipeData,
    PointStatus,
)


def test_point_status_enum_complete() -> None:
    assert {s.name for s in PointStatus} == {"UNRUN", "SUCCESS", "FAILURE"}


def test_inspection_point_position_with_offset_default_zero() -> None:
    point = InspectionPoint(index=1, position=(1.0, 2.0, 3.0), offset=(0.0, 0.0, 0.0))
    assert point.position_with_offset == (1.0, 2.0, 3.0)


def test_inspection_point_position_with_offset_added() -> None:
    point = InspectionPoint(index=2, position=(1.0, 2.0, 3.0), offset=(0.1, -0.2, 0.05))
    assert point.position_with_offset == (1.1, 1.8, 3.05)


def test_inspection_result_default_pose_groups_empty() -> None:
    result = InspectionResult(point_index=0, success=False)
    assert result.pose_groups == []
    assert result.debuging_info is None
    assert result.error_message is None


def test_inspection_result_success_with_pose_groups() -> None:
    pose_groups = [{"0": {"DDA": [0, 0, 0, 0, 0, 0]}}]
    result = InspectionResult(
        point_index=3,
        success=True,
        pose_groups=pose_groups,
        debuging_info={"k": "v"},
        error_message=None,
    )
    assert result.success is True
    assert result.pose_groups is pose_groups  # 동일 ref (deepcopy 는 호출자 책임)
    assert result.debuging_info == {"k": "v"}


def test_pipe_data_is_immutable_pathy() -> None:
    pipe = PipeData(
        pipe_id="PIPE NO.1",
        ply_path=Path("a.ply"),
        csv_path=Path("a.csv"),
    )
    assert pipe.pipe_id == "PIPE NO.1"
    assert pipe.ply_path == Path("a.ply")
