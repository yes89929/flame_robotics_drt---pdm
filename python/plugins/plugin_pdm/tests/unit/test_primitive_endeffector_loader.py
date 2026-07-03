"""프리미티브 기반 엔드이펙터 URDF 로더/충돌엔진 단위 테스트.

배경:
    자매 프로젝트(model_simplifier)에서 저작한 프리미티브 우선(box/cylinder + slab mesh)
    엔드이펙터 URDF 를 로드·충돌검사에 쓸 수 있도록 확장한 로더/충돌엔진을 검증한다.

검증 대상:
    - 다중 <collision> 순회 + Box/Mesh 타입 분기 (dda=box8, rt=box7+mesh1)
    - collision.origin rpy 를 URDF 표준 고정축 XYZ(대문자, extrinsic) 로 해석
    - 회전 박스(rpy 2축)의 world 배치 라운드트립
    - mesh 경로 resolve (file:// 및 순수 상대경로)
    - 기존 단일-mesh URDF 하위호환
    - box/cylinder 해석적 포함검사 정확성

데이터 의존:
    robot_models v1.5 URDF 만 사용(스캔 데이터 불필요). 파일 부재 시 skip.
"""

from __future__ import annotations

import subprocess
import sys
import textwrap
from pathlib import Path

import numpy as np
import open3d as o3d
import pytest
from scipy.spatial.transform import Rotation as R

from EndEffectorPoseOptimizer import EndEffectorPoseOptimizer  # noqa: WPS433

_MANGLE = "_EndEffectorPoseOptimizer__"

PLUGIN_PDM_ROOT = Path(__file__).resolve().parents[2]
ROBOTS_DIR = PLUGIN_PDM_ROOT / "data" / "robot_models v1.5" / "robots"
DDA_URDF = ROBOTS_DIR / "dda_endeffector.urdf"
RT_URDF = ROBOTS_DIR / "rt_endeffector.urdf"
OLD_DDA_URDF = ROBOTS_DIR / "rb10_1300e_DDA.urdf"
OLD_RT_URDF = ROBOTS_DIR / "rb10_1300e_RT.urdf"


def _get(opt, name):
    return getattr(opt, _MANGLE + name)


def _require(*paths: Path):
    missing = [str(p) for p in paths if not p.exists()]
    if missing:
        pytest.skip(f"필요 URDF/mesh 부재: {missing}")


@pytest.fixture
def loaded():
    _require(DDA_URDF, RT_URDF)
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_DDA_from_urdf(str(DDA_URDF))
    opt.load_RT_from_urdf(str(RT_URDF))
    return opt


# ============================================================================
# 프리미티브 로딩 (개수/타입)
# ============================================================================


def test_dda_loads_eight_boxes(loaded):
    """DDA 엔드이펙터 = box collision 8개."""
    dda = _get(loaded, "dda_collision")
    assert len(dda) == 8
    assert all(e["kind"] == "box" for e in dda)


def test_rt_loads_seven_boxes_one_mesh(loaded):
    """RT 엔드이펙터 = box 7개 + mesh(slab) 1개."""
    rt = _get(loaded, "rt_collision")
    kinds = [e["kind"] for e in rt]
    assert kinds.count("box") == 7
    assert kinds.count("mesh") == 1
    assert len(rt) == 8


def test_render_mesh_backward_compat(loaded):
    """__dda_mesh/__rt_mesh 는 하위호환용 병합 렌더 메시로 유지되며 비어있지 않다."""
    dda_mesh = _get(loaded, "dda_mesh")
    rt_mesh = _get(loaded, "rt_mesh")
    assert isinstance(dda_mesh, o3d.geometry.TriangleMesh)
    assert isinstance(rt_mesh, o3d.geometry.TriangleMesh)
    assert len(dda_mesh.vertices) > 0
    assert len(rt_mesh.vertices) > 0


# ============================================================================
# 회전 박스 world 배치 라운드트립 + rpy 규약 (XYZ extrinsic)
# ============================================================================


def test_rotated_box_roundtrip_and_convention(loaded):
    """DDA box[5] (rpy=[-1.5708,-1.5708,0], 2축 회전)의 origin 변환 라운드트립.

    joint_tcp origin 이 identity 라 TCP==link_end 이므로, 요소 T 의 translation 은
    저작 origin xyz 와 정확히 일치해야 하고, 회전은 XYZ(대문자, extrinsic) 규약과
    일치해야 한다. 또한 이 rpy 에서는 XYZ 와 xyz(소문자) 결과가 실제로 달라
    규약 선택이 유의미함을 함께 확인한다.
    """
    box = _get(loaded, "dda_collision")[5]
    expected_xyz = np.array([-0.0425, -0.0045, 0.109964])
    expected_rot = R.from_euler("XYZ", [-1.5708, -1.5708, 0.0]).as_matrix()
    wrong_rot = R.from_euler("xyz", [-1.5708, -1.5708, 0.0]).as_matrix()

    assert np.allclose(box["T"][:3, 3], expected_xyz, atol=1e-6)
    assert np.allclose(box["T"][:3, :3], expected_rot, atol=1e-9)
    # 규약이 실제로 중요함을 lock-in (동일하면 이 테스트의 의미가 사라짐)
    assert not np.allclose(expected_rot, wrong_rot, atol=1e-6)
    assert np.allclose(box["half"], np.array([0.0855, 0.015, 0.3]) / 2.0)


# ============================================================================
# 하위호환: 기존 단일-mesh URDF
# ============================================================================


def test_loads_under_non_utf8_locale():
    """비ASCII(한글 주석) URDF 를 non-UTF8(cp949 등) 로케일에서도 로드해야 한다.

    회귀 방지: urdf_parser_py 의 from_xml_file 은 인코딩 없이 open() 하므로 로케일 기본값이
    UTF-8 이 아니면 한글 주석 URDF 가 UnicodeDecodeError 로 실패한다. 로더는 UTF-8 명시
    읽기로 이를 회피해야 하며, 이 테스트는 자식 프로세스를 `-X utf8=0`(UTF-8 모드 강제 해제)
    으로 띄워 로케일 독립적으로 검증한다. (from_xml_file 로 되돌리면 이 테스트가 실패한다.)
    """
    _require(DDA_URDF, RT_URDF)
    plugin_root = str(PLUGIN_PDM_ROOT)
    child = textwrap.dedent(
        f"""
        import sys
        sys.path.insert(0, {plugin_root!r})
        from EndEffectorPoseOptimizer import EndEffectorPoseOptimizer
        opt = EndEffectorPoseOptimizer()
        opt.load_DDA_from_urdf({str(DDA_URDF)!r})
        opt.load_RT_from_urdf({str(RT_URDF)!r})
        print("OK")
        """
    )
    proc = subprocess.run(
        [sys.executable, "-X", "utf8=0", "-c", child],
        capture_output=True,
        text=True,
    )
    assert proc.returncode == 0, (
        f"non-UTF8 로케일 로드 실패 (from_xml_file 회귀 가능성):\n"
        f"stdout={proc.stdout!r}\nstderr={proc.stderr[-800:]!r}"
    )
    assert "OK" in proc.stdout


def test_old_urdf_single_mesh_backward_compat():
    """기존 rb10_1300e URDF 는 mesh 요소 1개로 로드되고 TCP 역변환은 identity."""
    _require(OLD_DDA_URDF, OLD_RT_URDF)
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_DDA_from_urdf(str(OLD_DDA_URDF))
    opt.load_RT_from_urdf(str(OLD_RT_URDF))

    dda = _get(opt, "dda_collision")
    assert len(dda) == 1 and dda[0]["kind"] == "mesh"
    assert len(_get(opt, "dda_mesh").vertices) > 0
    assert np.allclose(_get(opt, "dda_invers_transform_mat"), np.eye(4))


# ============================================================================
# 해석적 충돌 (box / cylinder) 정확성 — 합성 스캔
# ============================================================================


def _fake_with_scan(points: np.ndarray) -> EndEffectorPoseOptimizer:
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    pc = o3d.geometry.PointCloud()
    pc.points = o3d.utility.Vector3dVector(points)
    opt._scan_data = pc
    return opt


_IDENTITY_POSE = np.zeros(6)
_FAR_POSE = np.array([5.0, 0.0, 0.0, 0.0, 0.0, 0.0])


def test_analytic_box_inside_and_outside():
    """원점 중심 박스: 내부 점은 충돌, 멀리 떨어진 배치는 비충돌."""
    opt = _fake_with_scan(np.array([[0.0, 0.0, 0.0], [1.0, 1.0, 1.0]]))
    cc = _get(opt, "check_collision")
    box = {"kind": "box", "half": np.array([0.1, 0.1, 0.1]), "T": np.eye(4)}
    assert cc([box], _IDENTITY_POSE, np.eye(4)) is True
    assert cc([box], _FAR_POSE, np.eye(4)) is False


def test_analytic_box_respects_rotation():
    """회전 박스: 얇은 축 방향으로 벗어난 점은 회전을 반영해 정확히 비충돌 판정.

    half=[0.3,0.02,0.02] 박스를 로컬 z축 기준 90° 회전(원래 긴 x축이 world y축으로).
    world x=+0.2 점은 회전 후 박스 로컬에서 얇은 축(±0.02)을 벗어나 비충돌,
    world y=+0.2 점은 긴 축(±0.3) 안이라 충돌.
    """
    T = np.eye(4)
    T[:3, :3] = R.from_euler("XYZ", [0.0, 0.0, np.pi / 2]).as_matrix()
    box = {"kind": "box", "half": np.array([0.3, 0.02, 0.02]), "T": T}

    opt_x = _fake_with_scan(np.array([[0.2, 0.0, 0.0]]))
    assert _get(opt_x, "check_collision")([box], _IDENTITY_POSE, np.eye(4)) is False

    opt_y = _fake_with_scan(np.array([[0.0, 0.2, 0.0]]))
    assert _get(opt_y, "check_collision")([box], _IDENTITY_POSE, np.eye(4)) is True


def test_analytic_cylinder_inside_and_outside():
    """원점 중심 실린더(축=z): 내부 점 충돌, 반경 밖 점 비충돌."""
    # 내부(0,0,0)과 반경 밖(0.5,0,0)
    opt = _fake_with_scan(np.array([[0.0, 0.0, 0.0], [0.5, 0.0, 0.0]]))
    cc = _get(opt, "check_collision")
    cyl = {"kind": "cylinder", "radius": 0.1, "half_len": 0.2, "T": np.eye(4)}
    assert cc([cyl], _IDENTITY_POSE, np.eye(4)) is True
    assert cc([cyl], _FAR_POSE, np.eye(4)) is False


def test_analytic_cylinder_axial_limit():
    """실린더 축 방향 길이 제한: |z| > half_len+margin 인 점은 비충돌."""
    opt = _fake_with_scan(np.array([[0.0, 0.0, 0.5]]))  # z=0.5, half_len=0.2
    cc = _get(opt, "check_collision")
    cyl = {"kind": "cylinder", "radius": 0.1, "half_len": 0.2, "T": np.eye(4)}
    assert cc([cyl], _IDENTITY_POSE, np.eye(4)) is False


def test_empty_scan_no_collision():
    """스캔 점군이 비어있으면 충돌 없음."""
    opt = _fake_with_scan(np.zeros((0, 3)))
    cc = _get(opt, "check_collision")
    box = {"kind": "box", "half": np.array([0.1, 0.1, 0.1]), "T": np.eye(4)}
    assert cc([box], _IDENTITY_POSE, np.eye(4)) is False
