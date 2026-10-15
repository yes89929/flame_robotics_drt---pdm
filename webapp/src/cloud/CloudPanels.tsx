// 점군 레이어 목록과 검사점 표·편집.
import { useState } from 'react'
import { activeLayer, useStore, type ColorMode } from '../store'
import { FilePicker } from '../components/FilePicker'
import type { PointRow } from '../api'

export function LayerPanel() {
  const { layers, activeCloudId, cloudBusy, cloudError, addCloud, removeCloud, updateLayer, setActiveCloud, requestFit } = useStore()
  const [picking, setPicking] = useState(false)
  const [unit, setUnit] = useState<'auto' | 'm' | 'mm'>('auto')
  return (
    <div className="panel-section">
      <div className="section-title">
        점군 <span className="muted">{layers.length}개</span>
        <button className="small" onClick={requestFit} disabled={!layers.length}>화면 맞춤</button>
      </div>
      <div style={{ display: 'flex', gap: 6, alignItems: 'center' }}>
        <button onClick={() => setPicking(true)} disabled={!!cloudBusy}>점군 추가…</button>
        <label className="muted">
          단위{' '}
          <select value={unit} onChange={(e) => setUnit(e.target.value as typeof unit)}>
            <option value="auto">자동(범위 100 초과면 mm)</option>
            <option value="m">m</option>
            <option value="mm">mm</option>
          </select>
        </label>
      </div>
      {cloudBusy && <div className="muted">“{cloudBusy}” 읽는 중… (드라이브 파일은 수십 초 걸릴 수 있음)</div>}
      {cloudError && <div className="error">{cloudError}</div>}
      {layers.map((l) => {
        const active = l.meta.id === activeCloudId
        return (
          <div key={l.meta.id} className={`layer ${active ? 'active' : ''}`}>
            <div className="layer-head">
              <input type="checkbox" checked={l.visible} title="보이기" onChange={(e) => updateLayer(l.meta.id, { visible: e.target.checked })} />
              <span className="layer-name" title={l.meta.path}>{l.meta.name}</span>
              <button className="icon danger" title="닫기" onClick={() => removeCloud(l.meta.id)}>✕</button>
            </div>
            <div className="muted small-text">
              점 {l.meta.n_points.toLocaleString()}개 (화면 {l.meta.n_display.toLocaleString()}개) · 단위 {l.meta.unit}
              {!l.meta.has_normals && ' · 법선 없음(PDM 실행 시 추정)'}
            </div>
            <div className="layer-opts">
              <label>
                <input type="radio" checked={active} onChange={() => setActiveCloud(l.meta.id)} /> 작업 대상
              </label>
              <select value={l.colorMode} onChange={(e) => updateLayer(l.meta.id, { colorMode: e.target.value as ColorMode })}>
                {l.colors && <option value="rgb">원본 색</option>}
                <option value="height">높이 색</option>
                <option value="solid">단색</option>
              </select>
              <label>
                점 크기{' '}
                <input type="range" min={1} max={6} step={0.5} value={l.pointSize} onChange={(e) => updateLayer(l.meta.id, { pointSize: Number(e.target.value) })} style={{ width: 70 }} />
              </label>
            </div>
          </div>
        )
      })}
      <div className="muted small-text">검사점 지정·PDM 실행은 “작업 대상” 점군에만 적용됩니다.</div>
      {picking && (
        <FilePicker
          kind="cloud"
          title="점군 추가"
          exts={['.ply', '.pcd']}
          onClose={() => setPicking(false)}
          onPick={(p) => {
            setPicking(false)
            void addCloud(p, unit === 'auto' ? null : unit === 'mm' ? 0.001 : 1)
          }}
        />
      )}
    </div>
  )
}

const F = (v: number) => v.toFixed(4)
const FIELDS: { key: keyof PointRow; label: string }[] = [
  { key: 'x', label: 'x (m)' },
  { key: 'y', label: 'y (m)' },
  { key: 'z', label: 'z (m)' },
  { key: 'dx', label: '탐지 dx (m)' },
  { key: 'dy', label: '탐지 dy (m)' },
  { key: 'dz', label: '탐지 dz (m)' },
]

export function PointsPanel({ compact = false }: { compact?: boolean }) {
  const s = useStore()
  const layer = useStore(activeLayer)
  const ps = layer ? s.points[layer.meta.id] : null
  const results = layer ? (s.results[layer.meta.id] ?? {}) : {}
  const [msg, setMsg] = useState<string | null>(null)
  if (!layer || !ps) {
    return (
      <div className="panel-section">
        <div className="section-title">검사점</div>
        <div className="muted">점군을 먼저 추가하세요.</div>
      </div>
    )
  }
  const sel = s.selectedPoint
  const row = sel !== null ? ps.rows[sel] : null

  const save = async () => {
    setMsg(null)
    try {
      let r = await s.savePoints(false)
      if (r.conflict) {
        if (!window.confirm(`이미 있는 파일을 덮어씁니다.\n${r.path}\n\n계속할까요?`)) return
        r = await s.savePoints(true)
      }
      setMsg(`저장함: ${r.path}`)
    } catch (e) {
      setMsg(`저장 실패: ${(e as Error).message}`)
    }
  }
  const reload = async () => {
    if (ps.dirty && !window.confirm('저장하지 않은 변경을 버리고 파일에서 다시 읽을까요?')) return
    await s.reloadPoints()
    setMsg(null)
  }

  return (
    <div className="panel-section">
      <div className="section-title">
        검사점 <span className="muted">{ps.rows.length}개{ps.dirty ? ' · 저장 안 됨 ●' : ''}</span>
      </div>
      <div className="muted small-text" title={ps.csvPath}>
        파일: {ps.csvPath.split(/[\\/]/).pop()} {ps.exists ? '' : '(아직 없음)'}
      </div>
      {!compact && (
        <div className="row-actions">
          <button className={s.pickMode ? 'on' : ''} onClick={() => s.setPickMode(!s.pickMode)}>
            {s.pickMode ? '클릭 지정 중 — 끄기' : '점군 클릭으로 추가'}
          </button>
          <button className="primary" onClick={save} disabled={!ps.dirty && ps.exists}>CSV 저장</button>
          <button onClick={reload}>다시 읽기</button>
        </div>
      )}
      {s.pickMode && !compact && <div className="muted small-text">점군 위를 클릭(끌지 않고)하면 가장 앞의 스캔 점이 검사점으로 추가됩니다.</div>}
      {msg && <div className="small-text">{msg}</div>}
      <div className="table-wrap" style={{ marginTop: 6 }}>
        <table className="grid">
          <thead>
            <tr>
              <th className="l">#</th>
              <th>x</th>
              <th>y</th>
              <th>z</th>
              <th>탐지 오프셋</th>
              {compact && <th className="l">PDM</th>}
            </tr>
          </thead>
          <tbody>
            {ps.rows.map((r, i) => {
              const res = results[i]
              return (
                <tr key={i} className={i === sel ? 'sel' : ''} onClick={() => s.focusPoint(i === sel ? null : i)}>
                  <td className="l">{i + 1}</td>
                  <td>{F(r.x)}</td>
                  <td>{F(r.y)}</td>
                  <td>{F(r.z)}</td>
                  <td>{r.dx || r.dy || r.dz ? `${(r.dx * 1000).toFixed(0)}, ${(r.dy * 1000).toFixed(0)}, ${(r.dz * 1000).toFixed(0)} mm` : '—'}</td>
                  {compact && (
                    <td className="l">
                      {res ? <span className={`mode-${res.mode}`}>{res.status === 'error' ? '오류' : res.mode === 'none' ? '실패' : res.mode === '3pair' ? '3쌍' : '2쌍'}</span> : <span className="muted">—</span>}
                    </td>
                  )}
                </tr>
              )
            })}
          </tbody>
        </table>
      </div>
      {row && !compact && (
        <>
          <div className="point-edit">
            {FIELDS.map((f) => (
              <label key={f.key}>
                {f.label}
                <input
                  type="number"
                  step={0.001}
                  value={Number(row[f.key].toFixed(6))}
                  onChange={(e) => s.updatePoint(sel!, { [f.key]: Number(e.target.value) })}
                />
              </label>
            ))}
          </div>
          <div className="muted small-text">
            탐지 오프셋: PDM은 배관 프로파일(축·반지름)을 “검사점 + (dx, dy, dz)”에서 잡고, 자세 후보는 검사점 기준으로 만듭니다(tools/export_poses.py와 같은 규칙).
          </div>
          <div className="row-actions">
            <button onClick={() => s.movePoint(sel!, -1)} disabled={sel === 0}>▲ 위로</button>
            <button onClick={() => s.movePoint(sel!, 1)} disabled={sel === ps.rows.length - 1}>▼ 아래로</button>
            <button className="danger" onClick={() => s.removePoint(sel!)}>삭제</button>
          </div>
        </>
      )}
    </div>
  )
}
