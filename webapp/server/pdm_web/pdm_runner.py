"""검사점 하나에 대해 PDM(EndEffectorPoseOptimizer)을 실행하고 화면용 결과로 정리.

엔드이펙터 적재(메시 파일 읽기 포함)는 느리므로 (URDF·링크 지정·조인트 값)이 같으면
옵티마이저를 재사용한다. 옵티마이저는 스레드 안전하지 않아 전역 잠금으로 직렬 실행한다.
행렬은 모두 4×4 행 우선(row-major) 16개 리스트로 내보낸다.
"""

from __future__ import annotations

import json
import threading
import time
import traceback
from typing import Any

import numpy as np
from scipy.spatial.transform import Rotation as R

from .clouds import Cloud

from EndEffectorPoseOptimizer import EndEffectorPoseOptimizer  # noqa: E402  (paths 가 sys.path 설정)

#: tools/export_poses.py PARAMS 와 같은 기준값.
DEFAULT_PARAMS: dict[str, Any] = dict(
    distance_from_dda_to_surface=0.01,
    distance_from_dda_to_rt=0.3,
    angle_of_rt=10.0,
    candidate_step_deg=3.0,
    gap_tolerance_deg=10.0,
    allow_2pair_fallback=True,
)

_MANGLE = "_EndEffectorPoseOptimizer__"


def pose_to_matrix(pose6: list[float]) -> np.ndarray:
    """PDM 자세 [x,y,z,roll,pitch,yaw](m, rad; scipy "xyz") → 4×4."""
    T = np.eye(4)
    T[:3, :3] = R.from_euler("xyz", pose6[3:]).as_matrix()
    T[:3, 3] = pose6[:3]
    return T


def _flat(T: np.ndarray) -> list[float]:
    return [round(float(v), 7) for v in np.asarray(T).reshape(-1)]


class PdmRunner:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._opt: EndEffectorPoseOptimizer | None = None
        self._ee_key: str | None = None
        self._cloud_id: str | None = None

    def _prepare(self, cloud: Cloud, urdf_path: str, dda: dict, rt: dict, joint_positions: dict) -> EndEffectorPoseOptimizer:
        ee_key = json.dumps([urdf_path, dda, rt, joint_positions], sort_keys=True)
        if self._opt is None or self._ee_key != ee_key:
            opt = EndEffectorPoseOptimizer(debug_mode=False)
            opt.load_end_effector_from_urdf("DDA", urdf_path, dda["end_link"], dda["tcp_link"], joint_positions)
            opt.load_end_effector_from_urdf("RT", urdf_path, rt["end_link"], rt["tcp_link"], joint_positions)
            self._opt, self._ee_key, self._cloud_id = opt, ee_key, None
        if self._cloud_id != cloud.id:
            cloud.ensure_normals()
            self._opt._scan_data = cloud.pcd
            self._cloud_id = cloud.id
        return self._opt

    def run(
        self,
        cloud: Cloud,
        urdf_path: str,
        dda: dict,
        rt: dict,
        joint_positions: dict[str, float],
        params: dict[str, Any],
        point: dict[str, float],
    ) -> dict[str, Any]:
        p = {**DEFAULT_PARAMS, **(params or {})}
        inspection = [point["x"], point["y"], point["z"]]
        detection = [point["x"] + point.get("dx", 0.0), point["y"] + point.get("dy", 0.0), point["z"] + point.get("dz", 0.0)]
        out: dict[str, Any] = {"inspection": inspection, "detection": detection, "params": p}
        t0 = time.perf_counter()
        stage = "엔드이펙터 적재"
        with self._lock:
            try:
                opt = self._prepare(cloud, urdf_path, dda, rt, joint_positions)
                out["tcp_to_link"] = {
                    "DDA": _flat(getattr(opt, _MANGLE + "dda_invers_transform_mat")),
                    "RT": _flat(getattr(opt, _MANGLE + "rt_invers_transform_mat")),
                }
                stage = "배관 프로파일"
                opt.calculate_pipe_profile(detection)
                out["profile"] = opt.pipe_profile
                stage = "3쌍 자세 탐색"
                _, groups = opt.calculate_DDA_RT_pose_for_taking_xray_3pair_120(target_point=inspection, **p)
                out["candidates"] = [
                    {"deg": c["deg"], "status": c["status"], "tcp": _flat(pose_to_matrix(c["DDA"]))}
                    for c in opt.last_candidates
                ]
                slots = []
                for label, slot in (groups[0].items() if groups else []):
                    slots.append({
                        "label": label,
                        "actual_deg": slot.get("_actual_deg"),
                        "arc_deg": slot.get("_arc_deg"),
                        "DDA": _flat(pose_to_matrix(slot["DDA"])),
                        "RT1": _flat(pose_to_matrix(slot["RT1"])) if "RT1" in slot else None,
                        "RT2": _flat(pose_to_matrix(slot["RT2"])) if "RT2" in slot else None,
                        "raw": {k: v for k, v in slot.items() if not k.startswith("_")},
                    })
                out["slots"] = slots
                out["mode"] = {3: "3pair", 2: "2pair"}.get(len(slots), "none")
                out["status"] = "ok" if slots else "empty"
            except Exception as exc:  # noqa: BLE001 — 화면에 그대로 보여 준다
                out["status"] = "error"
                out["mode"] = "none"
                out["error"] = f"{stage} 단계 실패: {type(exc).__name__}: {exc}"
                out["traceback"] = traceback.format_exc(limit=4)
        out["elapsed_sec"] = round(time.perf_counter() - t0, 2)
        return out
