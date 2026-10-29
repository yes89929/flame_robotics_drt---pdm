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


def _geometry(el: ET.Element, urdf_dir: Path, materials: dict[str, list[float]]) -> dict[str, Any] | None:
    g = el.find("geometry")
    if g is None or len(g) == 0:
        return None
    shape = g[0]
    out: dict[str, Any] = {"origin": _origin(el)}
    tag = shape.tag
    if tag == "box":
        out.update(type="box", size=_floats(shape.get("size"), 3))
    elif tag in ("cylinder", "capsule"):
        out.update(type=tag, radius=float(shape.get("radius", 0)), length=float(shape.get("length", 0)))
    elif tag == "sphere":
        out.update(type="sphere", radius=float(shape.get("radius", 0)))
    elif tag == "mesh":
        path = resolve_mesh_path(shape.get("filename", ""), urdf_dir)
        out.update(type="mesh", file=str(path), exists=path.is_file(), scale=_floats(shape.get("scale"), 3, 1.0))
    else:
        return None

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
        visuals = [g for v in link.findall("visual") if (g := _geometry(v, urdf_dir, materials))]
        collisions = [g for c in link.findall("collision") if (g := _geometry(c, urdf_dir, materials))]
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
