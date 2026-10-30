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

# 옛 묶음 폴더 표기로 적고 resolve_path 로 지금 자리(attachments/<id>)를 찾는다 — 실데이터 경로 풀이도 함께 확인된다
ROOM_URDF = paths.resolve_path(paths.DATA_ROOT / "검사룸 URDF" / "export_v2 2026-09-14" / "model.urdf")
PIPE3_PLY = paths.resolve_path(paths.DATA_ROOT / "배관 데이터" / "한화오션 3종 cad to ply" / "PIPE NO.3_fill.ply")


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


def test_resolve_path_maps_legacy_bundle_to_attachments(tmp_path, monkeypatch):
    """옛 `<옛 루트>/<묶음>/...` 경로를 데이터 페이지 id 의 첨부 폴더로 옮겨 찾는다."""
    data = tmp_path / "데이터"
    target = data / "attachments" / "20261010104901454" / "export_v2" / "model.urdf"
    target.parent.mkdir(parents=True)
    target.write_text("<robot/>", encoding="utf-8")
    (data / "검사룸 URDF.md").write_text(
        "---\nid: 20261010104901454\ntitle: 검사룸 URDF\n---\n", encoding="utf-8"
    )
    old_root = tmp_path / "3. 기타자료"
    monkeypatch.setattr(paths, "DATA_ROOT", data)
    monkeypatch.setattr(paths, "LEGACY_DATA_ROOTS", [old_root, data])

    assert paths.resolve_path(old_root / "검사룸 URDF" / "export_v2" / "model.urdf") == target
    assert paths.resolve_path(data / "검사룸 URDF" / "export_v2" / "model.urdf") == target
    assert paths.resolve_path(old_root) == data
    missing = old_root / "없는 묶음" / "a.ply"
    assert paths.resolve_path(missing) == missing  # 못 찾으면 원래 경로 그대로 → 호출부가 404

    # 파일 선택 창: 페이지 폴더에서는 묶음 첨부 폴더로 바로 가는 항목에, 숫자 id 폴더에는 페이지 제목을 붙인다
    monkeypatch.setitem(paths.ROOTS, "과제 데이터", data)
    top = client.get("/api/fs/list", params={"path": str(data)}).json()
    assert top["dirs"] == ["attachments\\20261010104901454"]
    assert top["labels"] == {"attachments\\20261010104901454": "검사룸 URDF"}
    att = client.get("/api/fs/list", params={"path": str(data / "attachments")}).json()
    assert att["labels"] == {"20261010104901454": "검사룸 URDF"}


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


def test_session_store_merges_and_persists(tmp_path, monkeypatch):
    """작업 상태는 서버 파일에 남아 어느 브라우저로 열어도 같다. designations 는 URDF 별로 합친다."""
    monkeypatch.setenv("PDM_WEB_LOCAL_DIR", str(tmp_path))
    assert client.get("/api/session").json() == {}
    d1 = {"ddaEnd": "a", "ddaTcp": "b", "rtEnd": "c", "rtTcp": "d"}
    client.put("/api/session", json={"lastUrdf": "X.urdf", "designations": {"X.urdf": d1}, "bogus": 1})
    s = client.put("/api/session", json={"clouds": [{"path": "p.ply", "scale": 1.0}], "designations": {"Y.urdf": d1}}).json()
    assert s["lastUrdf"] == "X.urdf" and set(s["designations"]) == {"X.urdf", "Y.urdf"} and "bogus" not in s
    assert client.get("/api/session").json() == s
    assert (tmp_path / "session.json").is_file()


def test_pdm_results_saved_per_cloud(tmp_path, monkeypatch):
    """PDM 결과는 점군 파일별로 저장돼 다시 열면 돌아온다."""
    monkeypatch.setenv("PDM_WEB_LOCAL_DIR", str(tmp_path))
    a, b = str(tmp_path / "a.ply"), str(tmp_path / "b.ply")
    assert client.get("/api/pdm/results", params={"cloud_path": a}).json() == {"results": {}}
    client.put("/api/pdm/results", json={"cloud_path": a, "results": {"0": {"status": "ok", "mode": "3pair"}}})
    client.put("/api/pdm/results", json={"cloud_path": b, "results": {"1": {"status": "empty"}}})
    assert client.get("/api/pdm/results", params={"cloud_path": a}).json()["results"] == {"0": {"status": "ok", "mode": "3pair"}}
    assert client.get("/api/pdm/results", params={"cloud_path": b}).json()["results"] == {"1": {"status": "empty"}}
