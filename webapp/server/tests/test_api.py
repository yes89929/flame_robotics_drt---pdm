"""PDM 웹 도구 백엔드 API 테스트.

합성 데이터로 URDF 해석·점군 단위 판정·검사점 CSV 를 검증하고, 드라이브 실데이터가 있으면
PIPE NO.3 점군 + 검사룸 URDF(export_v2)로 PDM 한 점을 끝까지 돌린다(없으면 skip).
"""

from __future__ import annotations

import sys
from pathlib import Path

import numpy as np
import open3d as o3d
import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from fastapi.testclient import TestClient  # noqa: E402

from pdm_web import paths  # noqa: E402
from pdm_web.app import app  # noqa: E402
from pdm_web.testpoints import points_to_csv  # noqa: E402

client = TestClient(app)

ROOM_URDF = paths.DATA_ROOT / "검사룸 URDF" / "export_v2 2026-09-14" / "model.urdf"
PIPE3_PLY = paths.DATA_ROOT / "배관 데이터" / "한화오션 3종 cad to ply" / "PIPE NO.3_fill.ply"


def test_urdf_model_parses_v11_capsule_mimic_package(tmp_path):
    pkg = tmp_path / "my_pkg" / "meshes"
    pkg.mkdir(parents=True)
    (pkg / "a.stl").write_bytes(b"solid a\nendsolid a\n")
    urdf_dir = tmp_path / "my_pkg" / "urdf"
    urdf_dir.mkdir()
    urdf = urdf_dir / "r.urdf"
    urdf.write_text(
        """<robot name="r" version="1.1">
        <material name="red"><color rgba="1 0 0 1"/></material>
        <link name="base"><visual><geometry><mesh filename="package://my_pkg/meshes/a.stl" scale="0.001 0.001 0.001"/></geometry>
          <material name="red"/></visual></link>
        <link name="arm"><collision><origin xyz="0 0 0.1" rpy="0 1.5708 0"/><geometry><capsule radius="0.02" length="0.2"/></geometry></collision></link>
        <link name="arm2"/>
        <joint name="j1" type="revolute"><parent link="base"/><child link="arm"/><axis xyz="0 0 1"/>
          <limit lower="-1" upper="1" effort="1" velocity="1"/></joint>
        <joint name="j2" type="continuous"><parent link="arm"/><child link="arm2"/><mimic joint="j1" multiplier="2" offset="0.1"/></joint>
        </robot>""",
        encoding="utf-8",
    )
    m = client.get("/api/urdf", params={"path": str(urdf)}).json()
    assert m["version"] == "1.1" and m["roots"] == ["base"]
    links = {l["name"]: l for l in m["links"]}
    vis = links["base"]["visuals"][0]
    assert vis["type"] == "mesh" and vis["exists"] and vis["color"] == [1, 0, 0, 1]
    assert Path(vis["file"]) == (pkg / "a.stl").resolve()
    col = links["arm"]["collisions"][0]
    assert col["type"] == "capsule" and col["origin"]["rpy"] == [0, 1.5708, 0]
    joints = {j["name"]: j for j in m["joints"]}
    assert joints["j1"]["limit"] == {"lower": -1.0, "upper": 1.0}
    assert joints["j2"]["limit"] is None and joints["j2"]["axis"] == [1.0, 0.0, 0.0]
    assert joints["j2"]["mimic"] == {"joint": "j1", "multiplier": 2.0, "offset": 0.1}


def test_cloud_load_guesses_mm_and_serves_binary(tmp_path):
    pts = np.array([[0, 0, 0], [1000, 0, 0], [0, 2000, 0], [0, 0, 500]], dtype=float)
    pc = o3d.geometry.PointCloud(o3d.utility.Vector3dVector(pts))
    path = tmp_path / "mm.ply"
    o3d.io.write_point_cloud(str(path), pc)

    meta = client.post("/api/cloud/load", json={"path": str(path)}).json()
    assert meta["scale"] == 0.001 and meta["n_points"] == 4 and meta["bbox_max"] == [1.0, 2.0, 0.5]
    raw = client.get(f"/api/cloud/{meta['id']}/positions").content
    assert np.allclose(np.frombuffer(raw, "<f4").reshape(-1, 3), pts * 0.001)
    assert client.get("/api/cloud/nope/positions").status_code == 404


def test_read_pcd_with_comment_and_uint_rgb(tmp_path):
    """현장 스캔 PCD 형식: 첫 줄 주석, rgb 가 U(uint32), normal_x..z — Open3D 는 0점으로 읽는다."""
    from pdm_web.clouds import read_pcd

    rec = np.zeros(2, dtype=[("x", "<f4"), ("y", "<f4"), ("z", "<f4"), ("rgb", "<u4"),
                             ("normal_x", "<f4"), ("normal_y", "<f4"), ("normal_z", "<f4")])
    rec["x"] = [1000, 2000]
    rec["rgb"] = [0xFF0000, 0x0000FF]
    rec["normal_z"] = 1
    header = (
        "# Post-capture rigid camera/rail refinement\nVERSION 0.7\nFIELDS x y z rgb normal_x normal_y normal_z\n"
        "SIZE 4 4 4 4 4 4 4\nTYPE F F F U F F F\nCOUNT 1 1 1 1 1 1 1\nWIDTH 2\nHEIGHT 1\n"
        "VIEWPOINT 0 0 0 1 0 0 0\nPOINTS 2\nDATA binary\n"
    )
    path = tmp_path / "scan.pcd"
    path.write_bytes(header.encode("ascii") + rec.tobytes())

    pcd = read_pcd(path)
    assert np.allclose(np.asarray(pcd.points)[:, 0], [1000, 2000])
    assert np.allclose(np.asarray(pcd.colors), [[1, 0, 0], [0, 0, 1]])
    assert np.allclose(np.asarray(pcd.normals)[:, 2], 1)


def test_points_roundtrip_and_overwrite_guard(tmp_path):
    cloud = tmp_path / "pipe.ply"
    rows = [{"x": 0.00127, "y": -5.16521, "z": -0.03731, "dx": 0.0, "dy": 0.02, "dz": 0.0}]
    assert points_to_csv(rows) == ",x,y,z,dx,dy,dz\n1,0.00127,-5.16521,-0.03731,0,0.02,0\n"

    r = client.put("/api/points", json={"cloud_path": str(cloud), "rows": rows})
    assert r.status_code == 200 and Path(r.json()["csv_path"]).name == "pipe_testpoint.csv"
    assert client.put("/api/points", json={"cloud_path": str(cloud), "rows": rows}).status_code == 409
    got = client.get("/api/points", params={"cloud_path": str(cloud)}).json()
    assert got["exists"] and got["rows"] == rows


@pytest.mark.skipif(not (ROOM_URDF.is_file() and PIPE3_PLY.is_file()), reason="드라이브 실데이터 없음")
def test_pdm_run_with_room_urdf_on_pipe3():
    meta = client.post("/api/cloud/load", json={"path": str(PIPE3_PLY)}).json()
    assert meta["scale"] == 1.0
    pts = client.get("/api/points", params={"cloud_path": str(PIPE3_PLY)}).json()["rows"]
    body = {
        "cloud_id": meta["id"],
        "urdf_path": str(ROOM_URDF),
        "dda": {"end_link": "link_1_DDA", "tcp_link": "tcp_DDA"},
        "rt": {"end_link": "link_4_RT", "tcp_link": "tcp_RT"},
        "point": pts[0],
    }
    res = client.post("/api/pdm/run", json=body).json()
    assert res["status"] in ("ok", "empty"), res.get("error")
    assert len(res["candidates"]) == 120
    assert 0.01 < res["profile"]["radius"] < 0.5
    if res["status"] == "ok":
        assert res["mode"] in ("3pair", "2pair") and len(res["slots"][0]["DDA"]) == 16
