"""프리미티브 기반 엔드이펙터 URDF 로더/충돌엔진 단위 테스트.

배경:
    자매 프로젝트(model_simplifier)에서 저작한 프리미티브 우선(box/cylinder + slab mesh)
    엔드이펙터 URDF 를 로드·충돌검사에 쓸 수 있도록 확장한 로더/충돌엔진을 검증한다.

검증 대상:
    - 다중 <collision> 순회 + Box/Mesh 타입 분기 (dda=box8, rt=box7+mesh1)
    - collision.origin rpy 를 scipy intrinsic "xyz"(소문자) 로 해석 (URDF 표준 아님;
      model_simplifier 저작 규약. 구 상세 mesh 형상과 라운드트립으로 확인)
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
from data_paths import ROBOTS_DIR  # noqa: E402
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
    저작 origin xyz 와 정확히 일치해야 하고, 회전은 **intrinsic "xyz"(소문자)** 규약과
    일치해야 한다. (대상 URDF 는 model_simplifier 가 scipy 기본 intrinsic 으로 rpy 를
    저작했고, 구 상세 mesh 형상과 라운드트립 결과 xyz 만 일치한다 — extrinsic "XYZ" 로
    읽으면 회전 박스가 돌출부처럼 오배치된다.) 이 rpy 에서 두 규약 결과가 실제로 달라
    규약 선택이 유의미함도 함께 확인한다.
    """
    box = _get(loaded, "dda_collision")[5]
    expected_xyz = np.array([-0.0425, -0.0045, 0.109964])
    expected_rot = R.from_euler("xyz", [-1.5708, -1.5708, 0.0]).as_matrix()
    wrong_rot = R.from_euler("XYZ", [-1.5708, -1.5708, 0.0]).as_matrix()

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

    회귀 방지: 파일을 인코딩 없이 open() 하면 로케일 기본값이 UTF-8 이 아닐 때 한글 주석
    URDF 가 UnicodeDecodeError 로 실패한다. 파서(urdf_model.load_urdf_model)는 UTF-8 명시
    읽기로 이를 회피해야 하며, 이 테스트는 자식 프로세스를 `-X utf8=0`(UTF-8 모드 강제 해제)
    으로 띄워 로케일 독립적으로 검증한다. (인코딩 없는 읽기로 되돌리면 이 테스트가 실패한다.)
    """
    _require(DDA_URDF, RT_URDF)
    plugin_root = str(PLUGIN_PDM_ROOT)
    child = textwrap.dedent(
        f"""
        import sys
        sys.path.insert(0, {plugin_root!r})
        from tools.viewer import _open3d_compat
        _open3d_compat.apply()  # 한글 경로(구글 드라이브) STL 로드 — conftest 와 동일
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
# 임의 URDF 링크 지정 적재 (load_end_effector_from_urdf)
# ============================================================================


def test_generic_loader_matches_fixed_name_loader(loaded):
    """엔드이펙터 전용 URDF 를 링크 이름으로 지정해 읽어도 고정 이름 로더와 같은 결과."""
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_end_effector_from_urdf("DDA", str(DDA_URDF), "dda_link_end", "dda_link_tcp")
    opt.load_end_effector_from_urdf("RT", str(RT_URDF), "rt_link_end", "rt_link_tcp")
    for key in ("dda", "rt"):
        assert np.allclose(_get(opt, f"{key}_invers_transform_mat"), _get(loaded, f"{key}_invers_transform_mat"))
        assert [e["kind"] for e in _get(opt, f"{key}_collision")] == [e["kind"] for e in _get(loaded, f"{key}_collision")]


def _write_urdf(tmp_path: Path, body: str, version: str = "1.0") -> Path:
    path = tmp_path / "room.urdf"
    path.write_text(f'<?xml version="1.0"?>\n<robot name="room" version="{version}">{body}</robot>', encoding="utf-8")
    return path


_ROOM_BODY = """
<link name="base"/>
<link name="ee"><collision><geometry><box size="0.1 0.1 0.1"/></geometry></collision></link>
<link name="tcp"/>
<joint name="j_ee" type="fixed"><parent link="base"/><child link="ee"/><origin xyz="1 0 0"/></joint>
<joint name="j_slide" type="prismatic"><parent link="base"/><child link="tcp"/>
  <origin xyz="1 0 0.5"/><axis xyz="0 0 1"/><limit lower="-1" upper="1" effort="1" velocity="1"/></joint>
"""


def test_generic_loader_tcp_on_sibling_branch(tmp_path):
    """TCP 가 엔드이펙터의 자식이 아니어도(형제 가지) 순기구학으로 상대 변환을 구한다.

    검사룸 URDF(export_v2)는 tcp_DDA 가 base_link 에 직접 붙어 있어 이 경우에 해당한다.
    version="1.1"(model_simplifier 방출값)도 읽어야 한다.
    """
    path = _write_urdf(tmp_path, _ROOM_BODY, version="1.1")
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_end_effector_from_urdf("DDA", str(path), "ee", "tcp")
    # ee=(1,0,0), tcp=(1,0,0.5) → tcp→ee 는 z -0.5 이동
    expected = np.eye(4)
    expected[2, 3] = -0.5
    assert np.allclose(_get(opt, "dda_invers_transform_mat"), expected)

    opt.load_end_effector_from_urdf("DDA", str(path), "ee", "tcp", joint_positions={"j_slide": 0.2})
    expected[2, 3] = -0.7
    assert np.allclose(_get(opt, "dda_invers_transform_mat"), expected)


def test_generic_loader_rejects_link_without_collision(tmp_path):
    path = _write_urdf(tmp_path, _ROOM_BODY)
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    with pytest.raises(ValueError):
        opt.load_end_effector_from_urdf("DDA", str(path), "tcp", "tcp")
    with pytest.raises(KeyError):
        opt.load_end_effector_from_urdf("DDA", str(path), "ee", "no_such_link")


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


def _capsule(radius=0.1, half_len=0.2, T=None):
    return {"kind": "capsule", "radius": radius, "half_len": half_len, "T": np.eye(4) if T is None else T}


def test_analytic_capsule_cylinder_part():
    """캡슐 원기둥부: 반경 안 점은 충돌, 반경 밖 점은 비충돌."""
    inside = _get(_fake_with_scan(np.array([[0.05, 0.0, 0.1]])), "check_collision")
    outside = _get(_fake_with_scan(np.array([[0.3, 0.0, 0.1]])), "check_collision")
    assert inside([_capsule()], _IDENTITY_POSE, np.eye(4)) is True
    assert outside([_capsule()], _IDENTITY_POSE, np.eye(4)) is False


def test_analytic_capsule_hemisphere_cap():
    """반구 캡: 원기둥 끝(z=h)을 넘은 캡 안 점은 충돌, 캡 너머 점은 비충돌.

    h=0.2, r=0.1. 점 (0,0,h+0.5r) 는 원기둥(|z|<=h)으로 판정했다면 비충돌이지만 캡 안이라
    충돌이어야 한다. 점 (0,0,h+r+0.01) 는 캡 너머라 비충돌 -- length 를 전체 길이로 잘못
    읽어 half_len 을 h+r 로 잡았다면 이 점 근처가 충돌로 바뀐다. 모서리 점 (0.09,0,h+0.09)
    는 축 위 끝점까지 거리 0.127 > r 라 반구 밖이다(원기둥+높이 확장이나 박스 근사였다면
    충돌로 나왔을 위치).
    """
    h, r = 0.2, 0.1
    in_cap = _get(_fake_with_scan(np.array([[0.0, 0.0, h + 0.5 * r]])), "check_collision")
    beyond = _get(_fake_with_scan(np.array([[0.0, 0.0, h + r + 0.01]])), "check_collision")
    corner = _get(_fake_with_scan(np.array([[0.09, 0.0, h + 0.09]])), "check_collision")
    assert in_cap([_capsule(r, h)], _IDENTITY_POSE, np.eye(4)) is True
    assert beyond([_capsule(r, h)], _IDENTITY_POSE, np.eye(4)) is False
    assert corner([_capsule(r, h)], _IDENTITY_POSE, np.eye(4)) is False


def test_analytic_capsule_respects_rotation():
    """회전 캡슐: 로컬 z 축을 world x 로 눕히면 world x=+0.25 (캡 안) 충돌, z=+0.25 비충돌."""
    T = np.eye(4)
    T[:3, :3] = R.from_euler("XYZ", [0.0, np.pi / 2, 0.0]).as_matrix()  # 로컬 z -> world x
    cap = _capsule(0.1, 0.2, T)
    along = _get(_fake_with_scan(np.array([[0.25, 0.0, 0.0]])), "check_collision")
    across = _get(_fake_with_scan(np.array([[0.0, 0.0, 0.25]])), "check_collision")
    assert along([cap], _IDENTITY_POSE, np.eye(4)) is True
    assert across([cap], _IDENTITY_POSE, np.eye(4)) is False


def test_capsule_urdf_loads_with_render_mesh(tmp_path):
    """<capsule> collision 을 가진 version="1.1" URDF 를 적재하면 capsule 요소와 렌더 메시가 나온다."""
    body = """
<link name="base"/>
<link name="ee"><collision><origin xyz="0 0 0.1"/><geometry><capsule radius="0.05" length="0.2"/></geometry></collision></link>
<link name="tcp"/>
<joint name="j_ee" type="fixed"><parent link="base"/><child link="ee"/><origin xyz="1 0 0"/></joint>
<joint name="j_tcp" type="fixed"><parent link="ee"/><child link="tcp"/><origin xyz="0 0 0.3"/></joint>
"""
    path = _write_urdf(tmp_path, body, version="1.1")
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_end_effector_from_urdf("DDA", str(path), "ee", "tcp")
    elements = _get(opt, "dda_collision")
    assert [e["kind"] for e in elements] == ["capsule"]
    assert elements[0]["radius"] == pytest.approx(0.05)
    assert elements[0]["half_len"] == pytest.approx(0.1)  # length/2 (반구 캡 제외 규약)
    mesh = _get(opt, "dda_mesh")
    assert len(mesh.vertices) > 0
    # 렌더 메시 z 범위 = origin 0.1 +- (half_len + r) = [-0.05, 0.25]
    bb = mesh.get_axis_aligned_bounding_box()
    assert bb.min_bound[2] == pytest.approx(-0.05, abs=1e-6)
    assert bb.max_bound[2] == pytest.approx(0.25, abs=1e-6)


def test_empty_scan_no_collision():
    """스캔 점군이 비어있으면 충돌 없음."""
    opt = _fake_with_scan(np.zeros((0, 3)))
    cc = _get(opt, "check_collision")
    box = {"kind": "box", "half": np.array([0.1, 0.1, 0.1]), "T": np.eye(4)}
    assert cc([box], _IDENTITY_POSE, np.eye(4)) is False


# ============================================================================
# 잘못된 형상은 조용히 버리지 않는다 (자체 파서 urdf_model)
# ============================================================================


@pytest.mark.parametrize("bad", ['<cone radius="1"/>', ""])
def test_unknown_collision_geometry_is_rejected(tmp_path, bad):
    """모르는 태그·빈 <geometry> 의 collision 을 빼고 적재하면 그 부분의 충돌이 오류 없이 사라진다 — 거부해야 한다."""
    body = f"""
<link name="base"/>
<link name="ee">
  <collision><geometry><box size="0.1 0.1 0.1"/></geometry></collision>
  <collision><geometry>{bad}</geometry></collision>
</link>
<link name="tcp"/>
<joint name="j_ee" type="fixed"><parent link="base"/><child link="ee"/></joint>
<joint name="j_tcp" type="fixed"><parent link="base"/><child link="tcp"/></joint>
"""
    path = _write_urdf(tmp_path, body)
    with pytest.raises(ValueError, match="지원하지 않는 collision geometry"):
        EndEffectorPoseOptimizer().load_end_effector_from_urdf("DDA", str(path), "ee", "tcp")


@pytest.mark.parametrize("shape", ['<cylinder length="1"/>', '<box size="1 1"/>', "<sphere/>", '<capsule radius="0.1"/>'])
def test_missing_geometry_attribute_names_link(tmp_path, shape):
    """필수 속성이 빠지면 0 으로 채우지 않고 링크·태그를 밝힌 오류를 낸다."""
    body = (f'<link name="base"/><link name="ee"><collision><geometry>{shape}</geometry></collision></link>'
            '<joint name="j" type="fixed"><parent link="base"/><child link="ee"/></joint>')
    path = _write_urdf(tmp_path, body)
    with pytest.raises(ValueError, match="링크 ee"):
        EndEffectorPoseOptimizer().load_end_effector_from_urdf("DDA", str(path), "ee", "base")


def test_missing_collision_mesh_file_is_rejected(tmp_path):
    """collision 메시 파일이 없으면 빈 메시(충돌 없음)로 넘어가지 않고 적재를 거부한다."""
    body = ('<link name="base"/><link name="ee"><collision><geometry><mesh filename="meshes/none.stl"/></geometry></collision></link>'
            '<joint name="j" type="fixed"><parent link="base"/><child link="ee"/></joint>')
    path = _write_urdf(tmp_path, body)
    with pytest.raises(FileNotFoundError, match="none.stl"):
        EndEffectorPoseOptimizer().load_end_effector_from_urdf("DDA", str(path), "ee", "base")


def test_generic_loader_applies_mimic_joint(tmp_path):
    """엔드이펙터–TCP 사슬의 mimic 조인트는 따라가는 조인트 값×배율+오프셋으로 움직인다 (검사룸v2 구조)."""
    body = """
<link name="base"/><link name="carrier"/><link name="other"/>
<link name="ee"><collision><geometry><box size="0.1 0.1 0.1"/></geometry></collision></link>
<link name="tcp"/>
<joint name="j_drive" type="prismatic"><parent link="base"/><child link="other"/><axis xyz="1 0 0"/>
  <limit lower="-1" upper="1" effort="1" velocity="1"/></joint>
<joint name="j_follow" type="prismatic"><parent link="base"/><child link="carrier"/><axis xyz="0 0 1"/>
  <limit lower="-1" upper="1" effort="1" velocity="1"/><mimic joint="j_drive" multiplier="2" offset="0.1"/></joint>
<joint name="j_ee" type="fixed"><parent link="carrier"/><child link="ee"/></joint>
<joint name="j_tcp" type="fixed"><parent link="base"/><child link="tcp"/></joint>
"""
    path = _write_urdf(tmp_path, body, version="1.1")
    opt = EndEffectorPoseOptimizer(debug_mode=False)
    opt.load_end_effector_from_urdf("DDA", str(path), "ee", "tcp", joint_positions={"j_drive": 0.2})
    # ee 는 z 로 0.2×2+0.1 = 0.5 올라가고 tcp 는 원점 → tcp 프레임에서 본 ee 는 z +0.5
    # (mimic 을 무시하면 0 이 된다)
    expected = np.eye(4)
    expected[2, 3] = 0.5
    assert np.allclose(_get(opt, "dda_invers_transform_mat"), expected)
