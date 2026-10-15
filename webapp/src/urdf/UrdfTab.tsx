// URDF 뷰어 탭: 왼쪽 파일·링크 트리, 가운데 3D, 오른쪽 조인트·선택 링크·PDM 지정.
import { useState } from 'react'
import { useStore } from '../store'
import { FilePicker } from '../components/FilePicker'
import { Viewport } from '../components/Viewport'
import { UrdfScene } from './UrdfScene'
import { LinkTree } from './LinkTree'
import { JointPanel } from './JointPanel'
import { DesignationPanel, LinkInfo } from './LinkInfo'

export function UrdfTab() {
  const { urdf, urdfBusy, urdfError, openUrdf, showVisual, showCollision, showLabels, setView } = useStore()
  const [picking, setPicking] = useState(false)
  const [fitNonce, setFitNonce] = useState(0)

  return (
    <div className="tab-body">
      <aside className="side left">
        <div className="panel-section">
          <div className="section-title">URDF 파일</div>
          <button onClick={() => setPicking(true)}>열기…</button>
          {urdfBusy && <span className="muted"> 읽는 중…</span>}
          {urdfError && <div className="error">{urdfError}</div>}
          {urdf && (
            <div className="file-path" title={urdf.path}>
              <b>{urdf.name}</b> <span className="muted">v{urdf.version ?? '1.0'}</span>
              <div className="muted">{urdf.path}</div>
            </div>
          )}
        </div>
        <LinkTree />
      </aside>
      <main className="view">
        <div className="view-toolbar">
          <label><input type="checkbox" checked={showVisual} onChange={(e) => setView({ showVisual: e.target.checked })} /> 시각 형상</label>
          <label><input type="checkbox" checked={showCollision} onChange={(e) => setView({ showCollision: e.target.checked })} /> 충돌 형상</label>
          <label><input type="checkbox" checked={showLabels} onChange={(e) => setView({ showLabels: e.target.checked })} /> 모든 링크 이름</label>
          <button className="small" onClick={() => setFitNonce((n) => n + 1)}>화면 맞춤</button>
          <span className="muted">좌클릭 회전 · 우클릭 이동 · 휠 확대 · 링크 클릭 선택</span>
        </div>
        <div className="canvas-wrap">
          {!urdf && <div className="empty-hint">왼쪽 “열기…”로 URDF 파일을 고르세요.</div>}
          <Viewport>
            <UrdfScene fitNonce={fitNonce} />
          </Viewport>
        </div>
      </main>
      <aside className="side right">
        <LinkInfo />
        <DesignationPanel />
        <JointPanel />
      </aside>
      {picking && (
        <FilePicker
          kind="urdf"
          title="URDF 열기"
          exts={['.urdf']}
          onClose={() => setPicking(false)}
          onPick={(p) => {
            setPicking(false)
            void openUrdf(p)
          }}
        />
      )}
    </div>
  )
}
