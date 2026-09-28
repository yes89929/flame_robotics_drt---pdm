// 가동 조인트 슬라이더. 회전은 도(°), 직선은 mm 로 보여 주고 내부 값은 rad·m 이다.
import { useStore } from '../store'
import { MOVABLE } from '../lib/urdf'

const DEG = 180 / Math.PI

export function JointPanel() {
  const { urdf, joints, setJoint, resetJoints } = useStore()
  if (!urdf) return null
  const movable = urdf.joints.filter((j) => MOVABLE.has(j.type) && !j.mimic)
  const mimics = urdf.joints.filter((j) => j.mimic)

  return (
    <div className="panel-section">
      <div className="section-title">
        조인트 조작 <span className="muted">가동 {movable.length}개</span>
        <button className="small" onClick={resetJoints}>모두 0</button>
      </div>
      {movable.length === 0 && <div className="muted">가동 조인트가 없습니다.</div>}
      <div className="joint-list">
        {movable.map((j) => {
          const rot = j.type !== 'prismatic'
          const k = rot ? DEG : 1000
          const lo = j.limit ? j.limit.lower : -Math.PI
          const hi = j.limit ? j.limit.upper : Math.PI
          const v = joints[j.name] ?? 0
          return (
            <div key={j.name} className="joint-row">
              <div className="joint-name" title={`${j.parent} → ${j.child}`}>
                {j.name} <span className="muted">{rot ? (j.type === 'continuous' ? '연속 회전' : '회전') : '직선'}</span>
              </div>
              <input
                type="range"
                min={lo}
                max={hi}
                step={(hi - lo) / 1000}
                value={v}
                onChange={(e) => setJoint(j.name, Number(e.target.value))}
              />
              <input
                className="num"
                type="number"
                step={rot ? 1 : 1}
                value={Number((v * k).toFixed(2))}
                onChange={(e) => setJoint(j.name, Number(e.target.value) / k)}
              />
              <span className="unit">{rot ? '°' : 'mm'}</span>
            </div>
          )
        })}
      </div>
      {mimics.length > 0 && (
        <div className="muted small-text">
          따라 움직이는(mimic) 조인트: {mimics.map((m) => `${m.name} ← ${m.mimic!.joint}×${m.mimic!.multiplier}`).join(', ')}
        </div>
      )}
    </div>
  )
}
