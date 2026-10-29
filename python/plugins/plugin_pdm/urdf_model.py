"""PDM·웹 도구가 함께 쓰는 URDF 파서 (URDF → dict 모델).

ElementTree 로 직접 읽는다 — model_simplifier 가 방출하는
`version="1.1"`·`<capsule>`·`<mimic>` 을 그대로 전달하기 위해서다. 변환 행렬은 만들지 않고
xyz·rpy 원값을 넘긴다. rpy 는 URDF 표준(고정축 X→Y→Z, scipy `from_euler("xyz")`)이며
화면(three.js)은 Euler 순서 'ZYX' 로 같은 회전을 만든다.
"""

from __future__ import annotations

import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Any

MOVABLE = ("revolute", "continuous", "prismatic")


def _floats(text: str | None, n: int, default: float = 0.0) -> list[float]:
    if not text:
        return [default] * n
    vals = [float(v) for v in text.split()]
    return (vals + [default] * n)[:n]


def _origin(el: ET.Element | None) -> dict[str, list[float]]:
    o = el.find("origin") if el is not None else None
    return {
        "xyz": _floats(o.get("xyz") if o is not None else None, 3),
        "rpy": _floats(o.get("rpy") if o is not None else None, 3),
    }


def resolve_mesh_path(filename: str, urdf_dir: Path) -> Path:
    """URDF mesh filename 을 실제 파일 경로로.

    - `file://` 접두 제거 후 절대/상대(URDF 디렉터리 기준) 해석
    - `package://<pkg>/<rest>` 는 URDF 디렉터리에서 위로 올라가며 `<pkg>/<rest>` 또는
      `<rest>` 가 있는 곳을 찾는다 (ROS 없이 패키지 폴더를 흉내).
    """
    if filename.startswith("file://"):
        filename = filename[len("file://"):]
    if filename.startswith("package://"):
        pkg, _, rest = filename[len("package://"):].partition("/")
        for base in (urdf_dir, *urdf_dir.parents):
            for cand in (base / pkg / rest, base / rest):
                if cand.is_file():
                    return cand.resolve()
        return (urdf_dir / rest).resolve()
    p = Path(filename)
    return (p if p.is_absolute() else urdf_dir / p).resolve()


def _required(shape: ET.Element, attr: str, link: str, count: int = 1) -> list[float]:
    """형상의 필수 숫자 속성. 없거나 개수가 틀리면 링크·태그를 밝혀 ValueError.

    0 으로 채워 넘기면 PDM 에서 원인을 알 수 없는 Open3D 오류(반지름 ≤ 0 등)로 터진다.
    """
    text = shape.get(attr)
    vals = [float(v) for v in text.split()] if text else []
    if len(vals) != count:
        raise ValueError(f"링크 {link}: <{shape.tag}> 의 {attr} 속성은 숫자 {count}개여야 합니다 (값: {text!r})")
    return vals


def _geometry(el: ET.Element, urdf_dir: Path, materials: dict[str, list[float]], link: str) -> dict[str, Any]:
    """`<visual>`/`<collision>` 하나 → 형상 dict.

    모르는 태그나 빈 `<geometry>` 는 버리지 않고 `type="unknown"` 으로 남긴다 — 조용히 빼면
    PDM 엔드이펙터의 충돌 형상 일부가 오류 없이 사라진다. 화면은 unknown 을 그리지 않고,
    PDM 충돌 엔진은 unknown 을 만나면 적재를 거부한다.
    """
    g = el.find("geometry")
    out: dict[str, Any] = {"origin": _origin(el)}
    if g is None or len(g) == 0:
        out.update(type="unknown", tag="")
        return out
    shape = g[0]
    tag = shape.tag
    if tag == "box":
        out.update(type="box", size=_required(shape, "size", link, 3))
    elif tag in ("cylinder", "capsule"):
        out.update(type=tag, radius=_required(shape, "radius", link)[0], length=_required(shape, "length", link)[0])
    elif tag == "sphere":
        out.update(type="sphere", radius=_required(shape, "radius", link)[0])
    elif tag == "mesh":
        if not shape.get("filename"):
            raise ValueError(f"링크 {link}: <mesh> 에 filename 속성이 없습니다")
        path = resolve_mesh_path(shape.get("filename"), urdf_dir)
        out.update(type="mesh", file=str(path), exists=path.is_file(), scale=_floats(shape.get("scale"), 3, 1.0))
    else:
        out.update(type="unknown", tag=tag)
        return out

    mat = el.find("material")
    if mat is not None:
        color = mat.find("color")
        if color is not None:
            out["color"] = _floats(color.get("rgba"), 4, 1.0)
        elif mat.get("name") in materials:
            out["color"] = materials[mat.get("name")]
    return out


def load_urdf_model(path: Path) -> dict[str, Any]:
    root = ET.fromstring(path.read_text(encoding="utf-8"))
    urdf_dir = path.resolve().parent

    materials: dict[str, list[float]] = {}
    for mat in root.findall("material"):
        color = mat.find("color")
        if color is not None and mat.get("name"):
            materials[mat.get("name")] = _floats(color.get("rgba"), 4, 1.0)

    links = []
    for link in root.findall("link"):
        name = link.get("name")
        visuals = [_geometry(v, urdf_dir, materials, name) for v in link.findall("visual")]
        collisions = [_geometry(c, urdf_dir, materials, name) for c in link.findall("collision")]
        links.append({"name": link.get("name"), "visuals": visuals, "collisions": collisions})

    joints = []
    for j in root.findall("joint"):
        jtype = j.get("type", "fixed")
        axis_el = j.find("axis")
        limit_el = j.find("limit")
        mimic_el = j.find("mimic")
        joints.append({
            "name": j.get("name"),
            "type": jtype,
            "parent": j.find("parent").get("link"),
            "child": j.find("child").get("link"),
            "origin": _origin(j),
            "axis": _floats((axis_el.get("xyz") if axis_el is not None else None) or "1 0 0", 3),
            "limit": (
                {"lower": float(limit_el.get("lower", 0)), "upper": float(limit_el.get("upper", 0))}
                if limit_el is not None and jtype in ("revolute", "prismatic") else None
            ),
            "mimic": (
                {
                    "joint": mimic_el.get("joint"),
                    "multiplier": float(mimic_el.get("multiplier", 1)),
                    "offset": float(mimic_el.get("offset", 0)),
                }
                if mimic_el is not None else None
            ),
        })

    child_links = {j["child"] for j in joints}
    roots = [l["name"] for l in links if l["name"] not in child_links]
    return {
        "path": str(path),
        "name": root.get("name"),
        "version": root.get("version"),
        "roots": roots,
        "links": links,
        "joints": joints,
    }
