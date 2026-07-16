"""엔드이펙터 자세(3쌍 120°) 일괄 계산 + JSON/시각화 출력 스크립트.

배관(PIPE NO.1/2/3)별 검사 포인트 전체에 대해
``calculate_DDA_RT_pose_for_taking_xray_3pair_120`` 을 실행하여
(1) 구조화된 JSON 결과와 (2) off-screen 렌더링 PNG 시각화를 산출한다.

사용 예:
    conda activate drt-pdm
    python tools/export_poses.py --pipe all
    python tools/export_poses.py --pipe "NO.1" --limit 1        # 스모크 테스트
    python tools/export_poses.py --pipe "NO.3" --no-render      # JSON 만

출력물:
    output/자세계산_<날짜>/PIPE NO.X/poses.json      # 구조화 JSON
    output/자세계산_<날짜>/PIPE NO.X/overview.png    # 전체 배관 + 검사점
    output/자세계산_<날짜>/PIPE NO.X/point_NN.png    # 포인트별 자세 시각화
"""

from __future__ import annotations

import argparse
import json
import sys
import time
import traceback
from pathlib import Path

import numpy as np
import pandas as pd
from scipy.spatial.transform import Rotation as R

# plugin_pdm 루트를 import 경로에 추가 (tools/ 의 부모)
PLUGIN_ROOT = Path(__file__).resolve().parent.parent
if str(PLUGIN_ROOT) not in sys.path:
    sys.path.insert(0, str(PLUGIN_ROOT))

# 한글 경로에서 Open3D verbose 로그가 UnicodeDecodeError 를 일으키는 것 차단
try:
    from tools.viewer import _open3d_compat

    _open3d_compat.apply()
except Exception:  # noqa: BLE001
    pass

import open3d as o3d  # noqa: E402
from EndEffectorPoseOptimizer import EndEffectorPoseOptimizer  # noqa: E402
import JupyterVisualizer as JV  # noqa: E402

DATA_DIR = PLUGIN_ROOT / "data"
ROBOT_DIR = DATA_DIR / "robot_models v1.5" / "robots"

# 엔드이펙터 모델 세트: rb10(기존 단일-mesh) / primitive(신규 box·cylinder + slab)
ENDEFFECTOR_URDFS = {
    "rb10": (ROBOT_DIR / "rb10_1300e_DDA.urdf", ROBOT_DIR / "rb10_1300e_RT.urdf"),
    "primitive": (ROBOT_DIR / "dda_endeffector.urdf", ROBOT_DIR / "rt_endeffector.urdf"),
}

# 계산 파라미터 (데모/성능 테스트와 동일 기준값)
PARAMS = dict(
    distance_from_dda_to_surface=0.01,
    distance_from_dda_to_rt=0.3,
    angle_of_rt=10.0,
    candidate_step_deg=3.0,
    gap_tolerance_deg=10.0,
    allow_2pair_fallback=True,
)

PIPES = ["PIPE NO.1_fill", "PIPE NO.2_fill", "PIPE NO.3_fill"]

# 회전 라벨별 시각화 색상
SLOT_COLORS = {
    "0": (230, 90, 90),     # 빨강 계열
    "120": (90, 200, 90),   # 초록 계열
    "240": (90, 130, 230),  # 파랑 계열
}


def _pose_to_mesh_T(pose6: list[float], tcp_to_mesh_inv: np.ndarray) -> np.ndarray:
    """[x,y,z,r,p,y] TCP 자세 + (mesh->tcp)^-1 → 메시 배치용 4x4 행렬."""
    rot = R.from_euler("xyz", pose6[3:]).as_matrix()
    tcp_T = np.eye(4)
    tcp_T[:3, :3] = rot
    tcp_T[:3, 3] = pose6[:3]
    return tcp_T @ tcp_to_mesh_inv


def _slot_rt_keys(slot: dict) -> list[str]:
    return [k for k in ("RT1", "RT2") if k in slot]


def render_overview(optimizer, inspection_pts, detection_pts, out_path: Path):
    """전체 배관 점군 + 모든 검사점을 번호 라벨과 함께 렌더링 (참조 이미지 1 스타일)."""
    from pyvista.plotting.plotter import Plotter

    pl = Plotter(off_screen=True, window_size=[1600, 1000])
    JV.visualize_pointclouds_simply(optimizer._scan_data, plotter=pl, bg_color="white", point_size=5)
    for i, insp in enumerate(inspection_pts):
        pl.add_point_labels(
            [list(insp)], [str(i + 1)], font_size=16,
            text_color="black", fill_shape=True, shape_color="lightgray",
            always_visible=True,
        )
    try:
        pl.add_axes()
    except Exception:  # noqa: BLE001
        pass
    pl.view_isometric()
    pl.screenshot(str(out_path))
    pl.close()


def _first_rt(slot: dict):
    """슬롯에서 사용 가능한 RT 자세 하나 (RT1 우선)."""
    for rk in ("RT1", "RT2"):
        if rk in slot:
            return slot[rk]
    return None


def build_render_configs(optimizer, mode, pose_groups, inspection_pt):
    """모드별로 이미지에 그릴 (dda_pose, rt_pose, dda_color, rt_color, draw_arrows) 목록 구성.

    - 3pair : 3개 자세 전부 (자세별 색으로 120° 분포 강조)
    - 2pair : 2개 자세 전부 (자세별 색)
    - 그 외 : 실패 → 후보 자세 1개 (충돌해도 렌더, 배관 상단 후보 선택)

    각 쌍(DDA + RT)은 동일 색으로 그려, 쌍끼리 색으로 구분한다.
    """
    palette = {"0": (210, 70, 70), "120": (70, 180, 70), "240": (70, 110, 210)}
    configs = []
    if pose_groups and mode in ("3pair", "2pair"):
        # 2쌍이면 2개, 3쌍이면 3개 — 그룹의 모든 슬롯을 각자 색으로 그림
        for label, slot in pose_groups[0].items():
            c = palette.get(label, (150, 150, 150))
            configs.append((slot["DDA"], _first_rt(slot), c, c, False))
    else:
        # 실패: 후보 자세 1개 생성 (calculate_pipe_profile 로 프로파일 이미 설정된 상태)
        try:
            radius = getattr(optimizer, "_EndEffectorPoseOptimizer__pipe_radius")
            gen = getattr(optimizer, "_EndEffectorPoseOptimizer__calculate_dda_pose_candidate")
            rt_fn = getattr(optimizer, "_EndEffectorPoseOptimizer__calculate_rt_pose_for_angle")
            cands = [np.asarray(c) for c in gen(np.asarray(inspection_pt), radius + 0.01, 120)]
            dda = max(cands, key=lambda c: c[2])  # 배관 상단(최대 z) 후보
            rt = np.asarray(rt_fn(dda, 10.0, 0.3))
            c = (210, 70, 70)  # 실패 후보도 쌍이므로 단일 색
            configs.append((dda.tolist(), rt.tolist(), c, c, False))
        except Exception as exc:  # noqa: BLE001
            print(f"    실패 후보 생성 오류: {exc}", flush=True)
    return configs


def render_point(optimizer, idx, inspection_pt, detection_pt, configs, out_path: Path):
    """단일 검사점: 주변 crop 점군 + 선택된 자세 config 렌더링 (참조 이미지 2 스타일)."""
    from pyvista.plotting.plotter import Plotter

    dda_mesh = getattr(optimizer, "_EndEffectorPoseOptimizer__dda_mesh")
    rt_mesh = getattr(optimizer, "_EndEffectorPoseOptimizer__rt_mesh")
    dda_inv = getattr(optimizer, "_EndEffectorPoseOptimizer__dda_invers_transform_mat")
    rt_inv = getattr(optimizer, "_EndEffectorPoseOptimizer__rt_invers_transform_mat")

    center = np.array(detection_pt)
    bbox = o3d.geometry.AxisAlignedBoundingBox(min_bound=center - 0.35, max_bound=center + 0.35)
    cropped = optimizer._scan_data.crop(bbox)

    pl = Plotter(off_screen=True, window_size=[1400, 1000])
    JV.visualize_pointclouds_simply(cropped, plotter=pl, bg_color="white", point_size=5)

    # 검사점 마커 (회색 큐브) + 번호
    import pyvista as pv
    pl.add_mesh(pv.Cube(center=list(inspection_pt), x_length=0.02, y_length=0.02, z_length=0.02),
                color="dimgray")
    pl.add_point_labels(
        [list(inspection_pt)], [str(idx + 1)], font_size=16,
        text_color="black", fill_shape=True, shape_color="lightgray", always_visible=True,
    )

    for dda_pose, rt_pose, dda_color, rt_color, draw_arrows in configs:
        JV.add_mesh(pl, dda_mesh, _pose_to_mesh_T(dda_pose, dda_inv), color=dda_color)
        if rt_pose is not None:
            JV.add_mesh(pl, rt_mesh, _pose_to_mesh_T(rt_pose, rt_inv), color=rt_color)
        if draw_arrows:
            da = JV.calculate_arrows_from_pose_candidates(np.vstack([dda_pose]))
            pl.add_arrows(da[..., 0:3], da[..., 3:6], 0.12, color="red")
            if rt_pose is not None:
                ra = JV.calculate_arrows_from_pose_candidates(np.vstack([rt_pose]))
                pl.add_arrows(ra[..., 0:3], ra[..., 3:6], 0.12, color="blue")

    try:
        pl.add_axes()
    except Exception:  # noqa: BLE001
        pass
    pl.set_focus(list(detection_pt))
    pl.view_isometric()
    pl.screenshot(str(out_path))
    pl.close()


def classify(pose_groups) -> tuple[str, str]:
    """(status, mode) 반환."""
    if not pose_groups:
        return "empty", "none"
    keys = set(pose_groups[0].keys())
    if keys == {"0", "120", "240"}:
        return "ok", "3pair"
    if keys == {"0", "120"}:
        return "ok", "2pair"
    return "ok", "unknown"


def process_pipe(pipe_name: str, out_root: Path, limit: int | None, render: bool,
                 dda_urdf: Path, rt_urdf: Path):
    ply = DATA_DIR / f"{pipe_name}.ply"
    csv = DATA_DIR / f"{pipe_name}_testpoint.csv"
    out_dir = out_root / pipe_name.replace("_fill", "")
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"[{pipe_name}] loading scan {ply.name} (endeffector: {dda_urdf.name}) ...", flush=True)
    optimizer = EndEffectorPoseOptimizer(debug_mode=False)
    optimizer.load_scan_data(str(ply))
    optimizer.load_DDA_from_urdf(str(dda_urdf))
    optimizer.load_RT_from_urdf(str(rt_urdf))

    df = pd.read_csv(csv).fillna(0)
    inspection_pts, detection_pts = [], []
    for _, row in df.iterrows():
        inspection_pts.append((float(row["x"]), float(row["y"]), float(row["z"])))
        detection_pts.append(
            (float(row["x"] + row["dx"]), float(row["y"] + row["dy"]), float(row["z"] + row["dz"]))
        )

    n = len(inspection_pts) if limit is None else min(limit, len(inspection_pts))

    if render:
        print(f"[{pipe_name}] rendering overview ...", flush=True)
        try:
            render_overview(optimizer, inspection_pts[:n], detection_pts[:n], out_dir / "overview.png")
        except Exception as exc:  # noqa: BLE001
            print(f"[{pipe_name}] overview render 실패: {exc}", flush=True)

    points_out = []
    for i in range(n):
        t0 = time.perf_counter()
        rec = {
            "index": i + 1,
            "inspection_point": list(inspection_pts[i]),
            "detection_point": list(detection_pts[i]),
        }
        try:
            optimizer.calculate_pipe_profile(detection_pts[i])
            _, pose_groups = optimizer.calculate_DDA_RT_pose_for_taking_xray_3pair_120(
                target_point=inspection_pts[i], **PARAMS
            )
            status, mode = classify(pose_groups)
            rec.update(status=status, mode=mode, pose_groups=pose_groups)
            if render:
                img = out_dir / f"point_{i + 1:02d}.png"
                try:
                    configs = build_render_configs(optimizer, mode, pose_groups, inspection_pts[i])
                    render_point(optimizer, i, inspection_pts[i], detection_pts[i], configs, img)
                    rec["image"] = img.name
                except Exception as exc:  # noqa: BLE001
                    print(f"[{pipe_name}] point {i+1} render 실패: {exc}", flush=True)
        except Exception as exc:  # noqa: BLE001
            rec.update(status="error", mode="none", pose_groups=[], error=str(exc))
            print(f"[{pipe_name}] point {i+1} 계산 실패: {exc}\n{traceback.format_exc()}", flush=True)
        dt = time.perf_counter() - t0
        rec["elapsed_sec"] = round(dt, 2)
        points_out.append(rec)
        print(f"[{pipe_name}] point {i+1}/{n} -> {rec['status']}/{rec['mode']} ({dt:.1f}s)", flush=True)

    result = {
        "pipe": pipe_name,
        "scan_file": ply.name,
        "testpoint_file": csv.name,
        "dda_urdf": dda_urdf.name,
        "rt_urdf": rt_urdf.name,
        "params": PARAMS,
        "num_points": n,
        "summary": {
            "3pair": sum(1 for p in points_out if p["mode"] == "3pair"),
            "2pair": sum(1 for p in points_out if p["mode"] == "2pair"),
            "empty": sum(1 for p in points_out if p["status"] == "empty"),
            "error": sum(1 for p in points_out if p["status"] == "error"),
        },
        "points": points_out,
    }
    (out_dir / "poses.json").write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    print(f"[{pipe_name}] 완료 -> {out_dir/'poses.json'}  summary={result['summary']}", flush=True)
    return result


def resolve_pipes(sel: str) -> list[str]:
    if sel.lower() == "all":
        return PIPES
    for p in PIPES:
        if sel in p:
            return [p]
    raise SystemExit(f"알 수 없는 파이프: {sel!r} (선택: all, NO.1, NO.2, NO.3)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--pipe", default="all", help="all | NO.1 | NO.2 | NO.3")
    ap.add_argument("--limit", type=int, default=None, help="검사점 개수 제한 (스모크 테스트)")
    ap.add_argument("--no-render", action="store_true", help="시각화 생략 (JSON 만)")
    ap.add_argument("--out", default=None, help="출력 루트 (기본: output/자세계산_<날짜>)")
    ap.add_argument("--date", default="2026-07-02", help="출력 폴더 날짜 프리픽스")
    ap.add_argument("--endeffector", default="rb10", choices=list(ENDEFFECTOR_URDFS),
                    help="엔드이펙터 모델: rb10(기존 mesh) | primitive(신규 box+slab)")
    args = ap.parse_args()

    out_root = Path(args.out) if args.out else (PLUGIN_ROOT / "output" / f"자세계산_{args.date}")
    out_root.mkdir(parents=True, exist_ok=True)

    dda_urdf, rt_urdf = ENDEFFECTOR_URDFS[args.endeffector]

    for pipe in resolve_pipes(args.pipe):
        process_pipe(pipe, out_root, args.limit, render=not args.no_render,
                     dda_urdf=dda_urdf, rt_urdf=rt_urdf)


if __name__ == "__main__":
    main()
