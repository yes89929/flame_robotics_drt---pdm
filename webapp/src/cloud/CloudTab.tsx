// 점군·검사점 탭과 PDM 테스트 탭. 3D 장면(점군·검사점)은 공유하고 오른쪽 패널만 바뀐다.
import { useStore } from '../store'
import { Viewport } from '../components/Viewport'
import { CloudScene } from './CloudScene'
import { LayerPanel, PointsPanel } from './CloudPanels'
import { PdmPanel } from '../pdm/PdmPanel'
import { PdmResultView } from '../pdm/PdmResultView'

export function CloudTab({ mode }: { mode: 'points' | 'pdm' }) {
  const { layers, cloudBusy, pickMode } = useStore()
  const picking = pickMode && mode === 'points'
  return (
    <div className="tab-body">
      <aside className="side left">
        <LayerPanel />
        {mode === 'pdm' && <PointsPanel compact />}
      </aside>
      <main className="view">
        <div className="view-toolbar">
          <span className="muted">
            좌클릭 회전 · 우클릭 이동 · 휠 확대 · 번호 클릭 = 검사점 선택
            {picking && ' · 클릭 = 검사점 추가'}
          </span>
        </div>
        <div className={`canvas-wrap ${picking ? 'picking' : ''}`}>
          {!layers.length && !cloudBusy && <div className="empty-hint">왼쪽 “점군 추가…”로 .ply / .pcd 파일을 여세요.</div>}
          {cloudBusy && <div className="busy-hint">“{cloudBusy}” 읽는 중…</div>}
          <Viewport gridSize={40}>
            <CloudScene>{mode === 'pdm' && <PdmResultView />}</CloudScene>
          </Viewport>
        </div>
      </main>
      <aside className="side right">{mode === 'points' ? <PointsPanel /> : <PdmPanel />}</aside>
    </div>
  )
}
