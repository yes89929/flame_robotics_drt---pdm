// 서버 파일 탐색 창. 허용 루트(드라이브 기타자료·저장소) 안에서만 이동한다.
import { useEffect, useState } from 'react'
import { api, type FsList } from '../api'

const LAST_DIR_KEY = (kind: string) => `pdm-web:lastDir:${kind}`

export function FilePicker({
  kind,
  title,
  exts,
  onPick,
  onClose,
}: {
  kind: string
  title: string
  exts: string[]
  onPick: (path: string) => void
  onClose: () => void
}) {
  const [roots, setRoots] = useState<{ label: string; path: string }[]>([])
  const [list, setList] = useState<FsList | null>(null)
  const [error, setError] = useState<string | null>(null)
  const [busy, setBusy] = useState(false)

  /** 폴더로 이동. 성공 여부를 돌려준다. */
  const go = async (path: string): Promise<boolean> => {
    setBusy(true)
    setError(null)
    try {
      const l = await api.list(path, exts)
      setList(l)
      localStorage.setItem(LAST_DIR_KEY(kind), l.path)
      return true
    } catch (e) {
      setError((e as Error).message)
      return false
    } finally {
      setBusy(false)
    }
  }

  useEffect(() => {
    void api.roots().then(async (r) => {
      setRoots(r)
      // 마지막 폴더가 없어졌으면(데이터 폴더 이동 등) 첫 루트에서 시작한다
      const last = localStorage.getItem(LAST_DIR_KEY(kind))
      if (!last || !(await go(last))) await go(r[0].path)
    })
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [])

  const join = (dir: string, name: string) => `${dir.replace(/[\\/]$/, '')}\\${name}`

  return (
    <div className="modal-backdrop" onClick={onClose}>
      <div className="modal file-picker" onClick={(e) => e.stopPropagation()}>
        <div className="modal-head">
          <b>{title}</b>
          <span className="muted">확장자 {exts.join(' ')}</span>
          <button className="icon" onClick={onClose} title="닫기">✕</button>
        </div>
        <div className="fp-roots">
          {roots.map((r) => (
            <button key={r.path} onClick={() => go(r.path)}>{r.label}</button>
          ))}
        </div>
        <div className="fp-path" title={list?.path}>{list?.path ?? '…'}</div>
        {error && <div className="error">{error}</div>}
        <ul className={`fp-list ${busy ? 'busy' : ''}`}>
          {list?.parent && (
            <li className="dir" onClick={() => go(list.parent!)}>⬑ 상위 폴더</li>
          )}
          {list?.dirs.map((d) => (
            <li key={d} className="dir" onClick={() => go(join(list.path, d))}>📁 {d}</li>
          ))}
          {list?.files.map((f) => (
            <li key={f.name} className="file" onClick={() => onPick(join(list.path, f.name))}>
              📄 {f.name} <span className="muted">{(f.size / 1e6).toFixed(1)} MB</span>
            </li>
          ))}
          {list && list.dirs.length === 0 && list.files.length === 0 && <li className="muted">해당 확장자 파일 없음</li>}
        </ul>
      </div>
    </div>
  )
}
