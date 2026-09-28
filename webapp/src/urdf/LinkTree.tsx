// 링크 계층 트리. 링크 사이의 조인트 이름·종류를 함께 보여 주고, TCP·PDM 역할을 표시한다.
import { useMemo, useState } from 'react'
import { useStore } from '../store'
import { buildTree, isTcpLink, type TreeNode } from '../lib/urdf'

const JOINT_ICON: Record<string, string> = { fixed: '▪', revolute: '⟲', continuous: '⟳', prismatic: '⇕', floating: '✥', planar: '▭' }

export function LinkTree() {
  const { urdf, selectedLink, selectLink, designation } = useStore()
  const [filter, setFilter] = useState('')
  const tree = useMemo(() => (urdf ? buildTree(urdf) : []), [urdf])
  if (!urdf) return null

  const roleOf = (name: string) => {
    const tags: string[] = []
    if (name === designation.ddaEnd) tags.push('DDA EE')
    if (name === designation.ddaTcp) tags.push('DDA TCP')
    if (name === designation.rtEnd) tags.push('RT EE')
    if (name === designation.rtTcp) tags.push('RT TCP')
    return tags
  }
  const f = filter.trim().toLowerCase()
  const matches = (n: TreeNode): boolean =>
    !f || n.link.toLowerCase().includes(f) || (n.joint?.name.toLowerCase().includes(f) ?? false) || n.children.some(matches)

  const render = (n: TreeNode, depth: number) => {
    if (!matches(n)) return null
    const tcp = isTcpLink(urdf, n.link)
    const roles = roleOf(n.link)
    return (
      <div key={n.link}>
        <div
          className={`tree-row ${n.link === selectedLink ? 'sel' : ''}`}
          style={{ paddingLeft: 6 + depth * 12 }}
          onClick={() => selectLink(n.link === selectedLink ? null : n.link)}
          title={n.joint ? `조인트 ${n.joint.name} (${n.joint.type})` : '루트 링크'}
        >
          {n.joint && <span className="joint-icon">{JOINT_ICON[n.joint.type] ?? '?'}</span>}
          <span className="link-name">{n.link}</span>
          {tcp && <span className="badge tcp">TCP</span>}
          {roles.map((r) => (
            <span key={r} className={`badge ${r.startsWith('DDA') ? 'dda' : 'rt'}`}>{r}</span>
          ))}
        </div>
        {n.children.map((c) => render(c, depth + 1))}
      </div>
    )
  }

  return (
    <div className="panel-section grow">
      <div className="section-title">
        링크 트리 <span className="muted">링크 {urdf.links.length}개 · 조인트 {urdf.joints.length}개</span>
      </div>
      <input className="filter" placeholder="링크·조인트 이름 검색" value={filter} onChange={(e) => setFilter(e.target.value)} />
      <div className="tree">{tree.map((n) => render(n, 0))}</div>
      <div className="legend muted">▪ 고정 · ⟲ 회전(범위) · ⟳ 연속 회전 · ⇕ 직선</div>
    </div>
  )
}
