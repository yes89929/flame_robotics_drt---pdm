// URDF 순기구학과 트리 구성.
// rpy 는 URDF 표준(고정축 X→Y→Z = scipy from_euler("xyz"))이다. three.js 에서는
// Euler(roll, pitch, yaw, 'ZYX') 가 같은 회전 Rz·Ry·Rx 를 만든다.
import { Euler, Matrix4, Vector3 } from 'three'
import type { Origin, UrdfJoint, UrdfModel } from '../api'

export const MOVABLE = new Set(['revolute', 'continuous', 'prismatic'])

export function originMatrix(o: Origin): Matrix4 {
  const [r, p, y] = o.rpy
  const m = new Matrix4().makeRotationFromEuler(new Euler(r, p, y, 'ZYX'))
  m.setPosition(o.xyz[0], o.xyz[1], o.xyz[2])
  return m
}

/** 행 우선 16개 배열 → Matrix4 */
export function rowMajor(a: number[]): Matrix4 {
  return new Matrix4().set(...(a as [number, number, number, number, number, number, number, number, number, number, number, number, number, number, number, number]))
}

/** mimic 을 반영한 조인트 실제 값 */
export function jointValue(j: UrdfJoint, values: Record<string, number>): number {
  if (j.mimic) return (values[j.mimic.joint] ?? 0) * j.mimic.multiplier + j.mimic.offset
  return values[j.name] ?? 0
}

function motion(j: UrdfJoint, q: number): Matrix4 {
  const axis = new Vector3(...j.axis).normalize()
  if (q === 0) return new Matrix4()
  if (j.type === 'revolute' || j.type === 'continuous') return new Matrix4().makeRotationAxis(axis, q)
  if (j.type === 'prismatic') return new Matrix4().makeTranslation(axis.x * q, axis.y * q, axis.z * q)
  return new Matrix4()
}

/** 모든 링크의 루트 기준 월드 행렬 */
export function linkWorld(model: UrdfModel, values: Record<string, number>): Map<string, Matrix4> {
  const byParent = new Map<string, UrdfJoint[]>()
  for (const j of model.joints) byParent.set(j.parent, [...(byParent.get(j.parent) ?? []), j])
  const out = new Map<string, Matrix4>()
  const stack: [string, Matrix4][] = model.roots.map((r) => [r, new Matrix4()])
  while (stack.length) {
    const [name, T] = stack.pop()!
    out.set(name, T)
    for (const j of byParent.get(name) ?? []) {
      const child = T.clone().multiply(originMatrix(j.origin)).multiply(motion(j, jointValue(j, values)))
      stack.push([j.child, child])
    }
  }
  return out
}

export interface TreeNode { link: string; joint: UrdfJoint | null; children: TreeNode[] }

export function buildTree(model: UrdfModel): TreeNode[] {
  const byParent = new Map<string, UrdfJoint[]>()
  for (const j of model.joints) byParent.set(j.parent, [...(byParent.get(j.parent) ?? []), j])
  const make = (link: string, joint: UrdfJoint | null): TreeNode => ({
    link,
    joint,
    children: (byParent.get(link) ?? []).map((j) => make(j.child, j)),
  })
  return model.roots.map((r) => make(r, null))
}

/** 두 링크를 잇는 트리 경로 위의 가동 조인트 이름 (mimic 포함). 비어 있으면 상대 변환이 조인트 값과 무관하다. */
export function movableJointsBetween(model: UrdfModel, a: string, b: string): string[] {
  const parentJoint = new Map(model.joints.map((j) => [j.child, j]))
  const chain = (link: string) => {
    const out: UrdfJoint[] = []
    for (let j = parentJoint.get(link); j; j = parentJoint.get(j.parent)) out.push(j)
    return out
  }
  const ca = chain(a)
  const cb = chain(b)
  const shared = new Set(ca.filter((j) => cb.includes(j)).map((j) => j.name))
  return [...ca, ...cb].filter((j) => !shared.has(j.name) && MOVABLE.has(j.type)).map((j) => j.name)
}

/** TCP 프레임으로 보이는 링크: 이름에 tcp 가 들어가고 형상이 없는 링크 */
export function isTcpLink(model: UrdfModel, name: string): boolean {
  const l = model.links.find((x) => x.name === name)
  return /tcp/i.test(name) && !!l && l.visuals.length === 0 && l.collisions.length === 0
}

/** 위치(m)와 rpy(rad, URDF 규약) */
export function decompose(m: Matrix4): { xyz: number[]; rpy: number[] } {
  const e = new Euler().setFromRotationMatrix(m, 'ZYX')
  const p = new Vector3().setFromMatrixPosition(m)
  return { xyz: [p.x, p.y, p.z], rpy: [e.x, e.y, e.z] }
}
