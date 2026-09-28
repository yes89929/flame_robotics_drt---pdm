// PDM 실행 패널: 엔드이펙터 지정 확인, 파라미터, 실행, 선택 검사점 결과 요약.
import { useEffect, useState } from 'react'
import { api, type PdmParams } from '../api'
import { activeLayer, useStore } from '../store'
import { CAND_COLORS, SLOT_COLORS } from './PdmResultView'

const PARAM_META: { key: string; label: string; unit: string; k: number }[] = [
  { key: 'distance_from_dda_to_surface', label: 'DDA–배관 표면 거리', unit: 'mm', k: 1000 },
  { key: 'distance_from_dda_to_rt', label: 'DDA–RT 거리', unit: 'mm', k: 1000 },
  { key: 'angle_of_rt', label: 'RT 기울임 각', unit: '°', k: 1 },
  { key: 'candidate_step_deg', label: '후보 간격', unit: '°', k: 1 },
  { key: 'gap_tolerance_deg', label: '120° 간격 허용 편차', unit: '°', k: 1 },
]

const MODE_TEXT: Record<string, string> = { '3pair': '3쌍 성공 (120° 간격)', '2pair': '2쌍 폴백', none: '자세 없음' }

export function PdmPanel() {
  const s = useStore()
  const layer = useStore(activeLayer)
  const [defaults, setDefaults] = useState<PdmParams>({})
  useEffect(() => {
    void api.pdmDefaults().then(setDefaults)
  }, [])
  const params = { ...defaults, ...s.params }
  const d = s.designation
  const ps = layer ? s.points[layer.meta.id] : null
  const ready = !!(s.urdf && d.ddaEnd && d.ddaTcp && d.rtEnd && d.rtTcp && layer && ps && ps.rows.length)
  const res = layer && s.selectedPoint !== null ? s.results[layer.meta.id]?.[s.selectedPoint] : undefined
  const row = ps && s.selectedPoint !== null ? ps.rows[s.selectedPoint] : null
  const stale =
    res && row && [row.x, row.y, row.z].some((v, i) => Math.abs(v - res.inspection[i]) > 1e-9)
  const allResults = layer ? Object.values(s.results[layer.meta.id] ?? {}) : []
  const tally = (m: string) => allResults.filter((r) => r.mode === m && r.status !== 'error').length
  const movedJoints = Object.entries(s.joints).filter(([, v]) => v !== 0).length

  return (
    <>
      <div className="panel-section">
        <div className="section-title">엔드이펙터 (URDF 뷰어 탭에서 지정)</div>
        {!s.urdf ? (
          <div className="error">URDF 뷰어 탭에서 URDF를 열고 DDA·RT 링크를 지정하세요.</div>
        ) : (
          <table className="kv">
            <tbody>
              <tr><th>URDF</th><td title={s.urdf.path}>{s.urdf.path.split(/[\\/]/).slice(-2).join('/')}</td></tr>
              <tr><th>DDA</th><td>{d.ddaEnd || <span className="error">미지정</span>} / TCP {d.ddaTcp || <span className="error">미지정</span>}</td></tr>
              <tr><th>RT</th><td>{d.rtEnd || <span className="error">미지정</span>} / TCP {d.rtTcp || <span className="error">미지정</span>}</td></tr>
              <tr><th>조인트 값</th><td>{movedJoints ? `${movedJoints}개 조인트가 0이 아님 (URDF 탭 값 사용)` : '전부 0'}</td></tr>
            </tbody>
          </table>
        )}
      </div>
      <div className="panel-section">
        <div className="section-title">
          파라미터 <button className="small" onClick={() => useStore.setState({ params: {} })}>기본값</button>
        </div>
        <div className="params">
          {PARAM_META.map((p) => (
            <label key={p.key} style={{ display: 'contents' }}>
              <span>{p.label} ({p.unit})</span>
              <input
                className="num"
                type="number"
                value={Number(((params[p.key] as number) * p.k).toFixed(3)) || 0}
                onChange={(e) => s.setParams({ [p.key]: Number(e.target.value) / p.k })}
              />
            </label>
          ))}
          <label style={{ display: 'contents' }}>
            <span>3쌍 불가 시 2쌍 허용</span>
            <input type="checkbox" checked={!!params.allow_2pair_fallback} onChange={(e) => s.setParams({ allow_2pair_fallback: e.target.checked })} />
          </label>
        </div>
      </div>
      <div className="panel-section">
        <div className="section-title">실행</div>
        <div className="row-actions">
          <button className="primary" disabled={!ready || !!s.running || s.selectedPoint === null} onClick={() => s.runPdm([s.selectedPoint!])}>
            선택 검사점 실행
          </button>
          <button disabled={!ready || !!s.running} onClick={() => s.runPdm(ps!.rows.map((_, i) => i))}>
            전체 실행 ({ps?.rows.length ?? 0}개)
          </button>
          {s.running && <button className="danger" onClick={s.stopPdm}>중지</button>}
        </div>
        {s.running && (
          <>
            <div className="progress"><div style={{ width: `${(100 * s.running.done) / s.running.total}%` }} /></div>
            <div className="muted small-text">{s.running.done} / {s.running.total} 완료 (첫 실행은 엔드이펙터 적재·법선 추정으로 느릴 수 있음)</div>
          </>
        )}
        {allResults.length > 0 && (
          <div className="small-text">
            결과 {allResults.length}개: <span className="mode-3pair">3쌍 {tally('3pair')}</span> ·{' '}
            <span className="mode-2pair">2쌍 {tally('2pair')}</span> ·{' '}
            <span className="mode-none">실패 {allResults.filter((r) => r.mode === 'none').length}</span>
          </div>
        )}
      </div>
      <div className="panel-section">
        <div className="section-title">
          선택 검사점 결과 {s.selectedPoint !== null && <span className="muted">#{s.selectedPoint + 1}</span>}
        </div>
        {!res ? (
          <div className="muted">{s.selectedPoint === null ? '검사점을 선택하세요.' : '아직 실행하지 않았습니다.'}</div>
        ) : (
          <>
            {stale && <div className="error">검사점 좌표가 실행 뒤 바뀌었습니다 — 다시 실행하세요.</div>}
            <div className={`mode-${res.mode}`}>{res.status === 'error' ? '오류' : MODE_TEXT[res.mode]}</div>
            {res.error && <div className="error">{res.error}</div>}
            <table className="kv">
              <tbody>
                {res.profile && (
                  <tr><th>배관 반지름</th><td>{(res.profile.radius * 1000).toFixed(1)} mm (지름 {(res.profile.radius * 2000).toFixed(1)} mm)</td></tr>
                )}
                {res.candidates && (
                  <tr>
                    <th>후보 {res.candidates.length}개</th>
                    <td>
                      <span className="swatch" style={{ background: CAND_COLORS.ok }} />충돌 없음 {res.candidates.filter((c) => c.status === 'ok').length} ·{' '}
                      <span className="swatch" style={{ background: CAND_COLORS.dda_collision }} />DDA 충돌 {res.candidates.filter((c) => c.status === 'dda_collision').length} ·{' '}
                      <span className="swatch" style={{ background: CAND_COLORS.rt_collision }} />RT 충돌 {res.candidates.filter((c) => c.status === 'rt_collision').length}
                    </td>
                  </tr>
                )}
                {res.slots?.map((sl) => (
                  <tr key={sl.label}>
                    <th><span className="swatch" style={{ background: SLOT_COLORS[sl.label] }} />{sl.label}° 자리</th>
                    <td>
                      실제 {sl.actual_deg}° · RT {[sl.RT1 && '+기울임', sl.RT2 && '−기울임'].filter(Boolean).join(', ')}
                      {sl.arc_deg != null && ` · 호 ${sl.arc_deg}°`}
                    </td>
                  </tr>
                ))}
                <tr><th>계산 시간</th><td>{res.elapsed_sec} 초</td></tr>
              </tbody>
            </table>
            {res.traceback && (
              <details>
                <summary className="muted">추적 정보</summary>
                <pre className="small-text" style={{ whiteSpace: 'pre-wrap' }}>{res.traceback}</pre>
              </details>
            )}
          </>
        )}
        <div className="layer-opts">
          <label><input type="checkbox" checked={s.pdmView.profile} onChange={(e) => s.setPdmView({ profile: e.target.checked })} /> 배관 피팅</label>
          <label><input type="checkbox" checked={s.pdmView.candidates} onChange={(e) => s.setPdmView({ candidates: e.target.checked })} /> 후보 링</label>
          <label><input type="checkbox" checked={s.pdmView.rt2} onChange={(e) => s.setPdmView({ rt2: e.target.checked })} /> RT 양쪽 기울임</label>
          <label><input type="checkbox" checked={s.pdmView.tcpAxes} onChange={(e) => s.setPdmView({ tcpAxes: e.target.checked })} /> TCP 축</label>
        </div>
      </div>
    </>
  )
}
