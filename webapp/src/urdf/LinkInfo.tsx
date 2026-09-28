// 선택 링크 정보와 PDM 링크 지정.
import { useMemo } from 'react'
import { Matrix4 } from 'three'
import { useStore, type Designation } from '../store'
import { decompose, isTcpLink, linkWorld } from '../lib/urdf'

const DEG = 180 / Math.PI
const fmtPose = (m: Matrix4) => {
  const { xyz, rpy } = decompose(m)
  return {
    xyz: xyz.map((v) => (v * 1000).toFixed(1)).join(', '),
    rpy: rpy.map((v) => (v * DEG).toFixed(2)).join(', '),
  }
}

export function LinkInfo() {
  const { urdf, joints, selectedLink } = useStore()
  const world = useMemo(() => (urdf ? linkWorld(urdf, joints) : null), [urdf, joints])
  if (!urdf || !world || !selectedLink) {
    return (
      <div className="panel-section">
        <div className="section-title">선택 링크</div>
        <div className="muted">3D 화면이나 트리에서 링크를 클릭하세요.</div>
      </div>
    )
  }
  const link = urdf.links.find((l) => l.name === selectedLink)!
  const parentJoint = urdf.joints.find((j) => j.child === selectedLink)
  const w = world.get(selectedLink) ?? new Matrix4()
  const p = fmtPose(w)
  const count = (gs: { type: string }[]) =>
    Object.entries(gs.reduce<Record<string, number>>((a, g) => ({ ...a, [g.type]: (a[g.type] ?? 0) + 1 }), {}))
      .map(([k, v]) => `${k} ${v}`)
      .join(', ') || '없음'
  return (
    <div className="panel-section">
      <div className="section-title">선택 링크</div>
      <table className="kv">
        <tbody>
          <tr><th>이름</th><td><b>{link.name}</b>{isTcpLink(urdf, link.name) && <span className="badge tcp">TCP</span>}</td></tr>
          <tr><th>부모 조인트</th><td>{parentJoint ? `${parentJoint.name} (${parentJoint.type}) ← ${parentJoint.parent}` : '루트'}</td></tr>
          <tr><th>월드 위치 (mm)</th><td>{p.xyz}</td></tr>
          <tr><th>월드 rpy (°)</th><td>{p.rpy}</td></tr>
          <tr><th>시각 형상</th><td>{count(link.visuals)}</td></tr>
          <tr><th>충돌 형상</th><td>{count(link.collisions)}</td></tr>
        </tbody>
      </table>
    </div>
  )
}

const ROLES: { key: keyof Designation; label: string; kind: 'ee' | 'tcp' }[] = [
  { key: 'ddaEnd', label: 'DDA 엔드이펙터 링크', kind: 'ee' },
  { key: 'ddaTcp', label: 'DDA TCP 링크', kind: 'tcp' },
  { key: 'rtEnd', label: 'RT 엔드이펙터 링크', kind: 'ee' },
  { key: 'rtTcp', label: 'RT TCP 링크', kind: 'tcp' },
]

export function DesignationPanel() {
  const { urdf, joints, designation, setDesignation, selectedLink } = useStore()
  const world = useMemo(() => (urdf ? linkWorld(urdf, joints) : null), [urdf, joints])
  if (!urdf || !world) return null

  const eeLinks = urdf.links.filter((l) => l.collisions.length > 0).map((l) => l.name)
  const allLinks = urdf.links.map((l) => l.name)
  const tcpFirst = [...allLinks.filter((n) => isTcpLink(urdf, n)), ...allLinks.filter((n) => !isTcpLink(urdf, n))]

  const relation = (end: string, tcp: string) => {
    const we = world.get(end)
    const wt = world.get(tcp)
    if (!we || !wt) return null
    return fmtPose(we.clone().invert().multiply(wt))
  }
  const rel = [
    { name: 'DDA', r: relation(designation.ddaEnd, designation.ddaTcp) },
    { name: 'RT', r: relation(designation.rtEnd, designation.rtTcp) },
  ]

  return (
    <div className="panel-section">
      <div className="section-title">PDM 링크 지정</div>
      <div className="muted small-text">
        PDM은 엔드이펙터 링크의 <b>충돌(collision) 형상</b>으로 배관 점군과의 충돌을 검사하고, TCP 링크를 자세 기준점으로 씁니다.
        지정은 URDF 파일별로 브라우저에 저장됩니다.
      </div>
      {ROLES.map((r) => {
        const options = r.kind === 'ee' ? eeLinks : tcpFirst
        const canUseSelected = selectedLink && (r.kind === 'tcp' || eeLinks.includes(selectedLink))
        return (
          <div key={r.key} className="designation-row">
            <label>{r.label}</label>
            <select value={designation[r.key]} onChange={(e) => setDesignation({ [r.key]: e.target.value })}>
              <option value="">(지정 안 함)</option>
              {options.map((n) => (
                <option key={n} value={n}>{n}</option>
              ))}
            </select>
            <button
              className="small"
              disabled={!canUseSelected}
              title={canUseSelected ? `${selectedLink} 로 지정` : r.kind === 'ee' ? '충돌 형상이 있는 링크를 선택하세요' : '링크를 선택하세요'}
              onClick={() => selectedLink && setDesignation({ [r.key]: selectedLink })}
            >
              선택 링크
            </button>
          </div>
        )
      })}
      <table className="kv">
        <tbody>
          {rel.map(({ name, r }) => (
            <tr key={name}>
              <th>{name} 엔드이펙터→TCP</th>
              <td>{r ? <>위치 {r.xyz} mm<br />rpy {r.rpy} °</> : <span className="muted">두 링크를 지정하세요</span>}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <div className="muted small-text">위 상대 변환은 현재 조인트 값 기준이며, PDM 실행에도 현재 조인트 값이 그대로 쓰입니다.</div>
    </div>
  )
}
