// 탭 셸. 두 3D 캔버스(URDF / 점군·PDM)는 탭을 바꿔도 카메라가 유지되도록 계속 마운트해 둔다.
import { useStore, type Tab } from './store'
import { UrdfTab } from './urdf/UrdfTab'
import { CloudTab } from './cloud/CloudTab'

const TABS: { id: Tab; label: string }[] = [
  { id: 'urdf', label: 'URDF 뷰어' },
  { id: 'cloud', label: '점군 · 검사점' },
  { id: 'pdm', label: 'PDM 테스트' },
]

export function App() {
  const { tab, setTab } = useStore()
  return (
    <div className="app">
      <header className="topbar">
        <span className="brand">PDM 웹 도구</span>
        <nav>
          {TABS.map((t) => (
            <button key={t.id} className={tab === t.id ? 'active' : ''} onClick={() => setTab(t.id)}>
              {t.label}
            </button>
          ))}
        </nav>
      </header>
      <div className="tab-host" style={{ display: tab === 'urdf' ? 'flex' : 'none' }}>
        <UrdfTab />
      </div>
      <div className="tab-host" style={{ display: tab === 'urdf' ? 'none' : 'flex' }}>
        <CloudTab mode={tab === 'pdm' ? 'pdm' : 'points'} />
      </div>
    </div>
  )
}
