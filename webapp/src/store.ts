// 앱 전역 상태 (zustand). 세 탭이 같은 URDF·점군·검사점을 공유한다.
// 작업 상태(마지막 URDF·열어 둔 점군·작업 대상·URDF별 PDM 링크 지정·파라미터·탭)는 서버(`/api/session`)에 남긴다.
// localStorage 는 브라우저·주소마다 따로라 다른 창에서 비어 보였다 — 이제는 옛 값을 서버로 옮길 때만 읽는다.
import { create } from 'zustand'
import { api, type CloudMeta, type PdmParams, type PdmResult, type PointRow, type Session, type UrdfModel } from './api'

export type Tab = 'urdf' | 'cloud' | 'pdm'

export interface Designation { ddaEnd: string; ddaTcp: string; rtEnd: string; rtTcp: string }
export const EMPTY_DESIGNATION: Designation = { ddaEnd: '', ddaTcp: '', rtEnd: '', rtTcp: '' }

export type ColorMode = 'rgb' | 'height' | 'solid'

export interface Layer {
  meta: CloudMeta
  positions: Float32Array
  colors: Uint8Array | null
  visible: boolean
  colorMode: ColorMode
  pointSize: number
}

export interface PointsState { csvPath: string; exists: boolean; rows: PointRow[]; dirty: boolean }

/** 예전 판이 브라우저에 남긴 값 (서버 이전용으로만 읽는다) */
function legacy<T>(key: string, fallback: T): T {
  try {
    const v = localStorage.getItem(`pdm-web:${key}`)
    return v ? (JSON.parse(v) as T) : fallback
  } catch {
    return fallback
  }
}

/** 서버 작업 상태의 사본. 바꿀 때마다 서버에도 보낸다(실패해도 화면은 계속 쓴다). */
let session: Session = {}
function persist(patch: Partial<Session>) {
  session = { ...session, ...patch, designations: { ...session.designations, ...patch.designations } }
  void api.saveSession(patch).catch((e) => console.warn('작업 상태 저장 실패', e))
}
const cloudList = (layers: Layer[]) => layers.map((l) => ({ path: l.meta.path, scale: l.meta.scale }))

/** 이름으로 PDM 링크 지정을 추정 (검사룸 URDF: link_1_DDA·tcp_DDA·link_4_RT·tcp_RT) */
function guessDesignation(model: UrdfModel): Designation {
  const withGeom = model.links.filter((l) => l.collisions.length > 0).map((l) => l.name)
  const tcps = model.links.filter((l) => /tcp/i.test(l.name)).map((l) => l.name)
  const pick = (names: string[], re: RegExp) => names.find((n) => re.test(n)) ?? ''
  return {
    ddaEnd: pick(withGeom, /^link_\d+_DDA$|dda_link_end/i) || pick(withGeom, /dda/i),
    ddaTcp: pick(tcps, /dda/i),
    rtEnd: pick(withGeom, /^link_\d+_RT$|rt_link_end/i) || pick(withGeom, /(^|_)rt(_|$)/i),
    rtTcp: pick(tcps, /(^|_)rt(_|$)/i),
  }
}

interface State {
  tab: Tab
  setTab: (t: Tab) => void

  // ── URDF ──
  urdf: UrdfModel | null
  urdfBusy: boolean
  urdfError: string | null
  joints: Record<string, number>
  selectedLink: string | null
  showVisual: boolean
  showCollision: boolean
  showLabels: boolean
  designation: Designation
  openUrdf: (path: string) => Promise<void>
  setJoint: (name: string, v: number) => void
  resetJoints: () => void
  selectLink: (name: string | null) => void
  setView: (patch: Partial<Pick<State, 'showVisual' | 'showCollision' | 'showLabels'>>) => void
  setDesignation: (patch: Partial<Designation>) => void

  // ── 점군 · 검사점 ──
  layers: Layer[]
  activeCloudId: string | null
  cloudBusy: string | null
  cloudError: string | null
  points: Record<string, PointsState>
  selectedPoint: number | null
  pickMode: boolean
  fitNonce: number
  focusNonce: number
  addCloud: (path: string, scale?: number | null) => Promise<void>
  removeCloud: (id: string) => void
  updateLayer: (id: string, patch: Partial<Pick<Layer, 'visible' | 'colorMode' | 'pointSize'>>) => void
  setActiveCloud: (id: string) => void
  requestFit: () => void
  focusPoint: (i: number | null) => void
  setPickMode: (v: boolean) => void
  addPoint: (p: [number, number, number]) => void
  updatePoint: (i: number, patch: Partial<PointRow>) => void
  removePoint: (i: number) => void
  movePoint: (i: number, delta: -1 | 1) => void
  reloadPoints: () => Promise<void>
  savePoints: (overwrite: boolean) => Promise<{ conflict: boolean; path: string }>

  // ── PDM ──
  params: PdmParams
  results: Record<string, Record<number, PdmResult>>
  running: { done: number; total: number } | null
  stopRequested: boolean
  pdmView: { candidates: boolean; rt2: boolean; profile: boolean; tcpAxes: boolean }
  setParams: (patch: PdmParams) => void
  setPdmView: (patch: Partial<State['pdmView']>) => void
  runPdm: (indices: number[]) => Promise<void>
  stopPdm: () => void
}

export const useStore = create<State>((set, get) => ({
  tab: 'urdf',
  setTab: (tab) => {
    persist({ tab })
    // 클릭 지정은 점군·검사점 탭 전용 — 다른 탭에서 클릭이 점을 추가하지 않게 끈다
    set({ tab, pickMode: tab === 'cloud' ? get().pickMode : false })
  },

  urdf: null,
  urdfBusy: false,
  urdfError: null,
  joints: {},
  selectedLink: null,
  showVisual: true,
  showCollision: false,
  showLabels: false,
  designation: EMPTY_DESIGNATION,

  openUrdf: async (path) => {
    set({ urdfBusy: true, urdfError: null })
    try {
      const model = await api.urdf(path)
      // 서버가 옛 데이터 경로를 지금 자리로 풀어 model.path 로 돌려준다 — 새 경로로 다시 기억하고,
      // 옛 경로에 저장된 링크 지정도 새 경로로 옮긴다
      const saved = session.designations?.[model.path] ?? session.designations?.[path] ?? null
      persist({ lastUrdf: model.path, ...(saved ? { designations: { [model.path]: saved } } : {}) })
      set({
        urdf: model,
        joints: {},
        selectedLink: null,
        designation: saved ?? guessDesignation(model),
      })
    } catch (e) {
      set({ urdfError: (e as Error).message })
    } finally {
      set({ urdfBusy: false })
    }
  },
  setJoint: (name, v) => set({ joints: { ...get().joints, [name]: v } }),
  resetJoints: () => set({ joints: {} }),
  selectLink: (selectedLink) => set({ selectedLink }),
  setView: (patch) => set(patch),
  setDesignation: (patch) => {
    const designation = { ...get().designation, ...patch }
    const path = get().urdf?.path
    if (path) persist({ designations: { [path]: designation } })
    set({ designation })
  },

  layers: [],
  activeCloudId: null,
  cloudBusy: null,
  cloudError: null,
  points: {},
  selectedPoint: null,
  pickMode: false,
  fitNonce: 0,
  focusNonce: 0,

  addCloud: async (path, scale = null) => {
    set({ cloudBusy: path.split(/[\\/]/).pop() ?? path, cloudError: null })
    try {
      const meta = await api.loadCloud(path, scale)
      if (get().layers.some((l) => l.meta.id === meta.id)) return
      const [positions, colors, pts] = await Promise.all([
        api.cloudPositions(meta.id),
        meta.has_colors ? api.cloudColors(meta.id) : Promise.resolve(null),
        api.points(meta.path),
      ])
      const layer: Layer = { meta, positions, colors, visible: true, colorMode: colors ? 'rgb' : 'height', pointSize: 2 }
      const layers = [...get().layers, layer]
      persist({ clouds: cloudList(layers) })
      set({
        layers,
        activeCloudId: get().activeCloudId ?? meta.id,
        points: { ...get().points, [meta.id]: { csvPath: pts.csv_path, exists: pts.exists, rows: pts.rows, dirty: false } },
        fitNonce: get().fitNonce + 1,
      })
    } catch (e) {
      set({ cloudError: (e as Error).message })
    } finally {
      set({ cloudBusy: null })
    }
  },
  removeCloud: (id) => {
    const layers = get().layers.filter((l) => l.meta.id !== id)
    persist({ clouds: cloudList(layers) })
    void api.unloadCloud(id)
    set({
      layers,
      activeCloudId: get().activeCloudId === id ? (layers[0]?.meta.id ?? null) : get().activeCloudId,
      selectedPoint: null,
    })
  },
  updateLayer: (id, patch) => set({ layers: get().layers.map((l) => (l.meta.id === id ? { ...l, ...patch } : l)) }),
  setActiveCloud: (activeCloudId) => {
    persist({ activeCloud: get().layers.find((l) => l.meta.id === activeCloudId)?.meta.path })
    set({ activeCloudId, selectedPoint: null })
  },
  requestFit: () => set({ fitNonce: get().fitNonce + 1 }),
  focusPoint: (i) => set({ selectedPoint: i, focusNonce: i === null ? get().focusNonce : get().focusNonce + 1 }),
  setPickMode: (pickMode) => set({ pickMode }),

  addPoint: ([x, y, z]) => {
    const id = get().activeCloudId
    if (!id) return
    const ps = get().points[id]
    const rows = [...ps.rows, { x, y, z, dx: 0, dy: 0, dz: 0 }]
    set({ points: { ...get().points, [id]: { ...ps, rows, dirty: true } }, selectedPoint: rows.length - 1 })
  },
  updatePoint: (i, patch) => {
    const id = get().activeCloudId
    if (!id) return
    const ps = get().points[id]
    const rows = ps.rows.map((r, k) => (k === i ? { ...r, ...patch } : r))
    set({ points: { ...get().points, [id]: { ...ps, rows, dirty: true } } })
  },
  removePoint: (i) => {
    const id = get().activeCloudId
    if (!id) return
    const ps = get().points[id]
    const rows = ps.rows.filter((_, k) => k !== i)
    // 결과는 번호로 묶여 있으므로 지운 점 뒤의 결과는 한 칸씩 당긴다
    const old = get().results[id] ?? {}
    const res: Record<number, PdmResult> = {}
    for (const [k, v] of Object.entries(old)) {
      const n = Number(k)
      if (n < i) res[n] = v
      else if (n > i) res[n - 1] = v
    }
    set({
      points: { ...get().points, [id]: { ...ps, rows, dirty: true } },
      results: { ...get().results, [id]: res },
      selectedPoint: null,
    })
  },
  movePoint: (i, delta) => {
    const id = get().activeCloudId
    if (!id) return
    const ps = get().points[id]
    const j = i + delta
    if (j < 0 || j >= ps.rows.length) return
    const rows = [...ps.rows]
    ;[rows[i], rows[j]] = [rows[j], rows[i]]
    const old = { ...(get().results[id] ?? {}) }
    ;[old[i], old[j]] = [old[j], old[i]]
    for (const k of [i, j]) if (old[k] === undefined) delete old[k]
    set({
      points: { ...get().points, [id]: { ...ps, rows, dirty: true } },
      results: { ...get().results, [id]: old },
      selectedPoint: j,
    })
  },
  reloadPoints: async () => {
    const layer = get().layers.find((l) => l.meta.id === get().activeCloudId)
    if (!layer) return
    const pts = await api.points(layer.meta.path)
    set({
      points: { ...get().points, [layer.meta.id]: { csvPath: pts.csv_path, exists: pts.exists, rows: pts.rows, dirty: false } },
      results: { ...get().results, [layer.meta.id]: {} },
      selectedPoint: null,
    })
  },
  savePoints: async (overwrite) => {
    const layer = get().layers.find((l) => l.meta.id === get().activeCloudId)
    if (!layer) return { conflict: false, path: '' }
    const ps = get().points[layer.meta.id]
    try {
      const r = await api.savePoints(layer.meta.path, ps.rows, overwrite)
      set({ points: { ...get().points, [layer.meta.id]: { ...ps, exists: true, dirty: false } } })
      return { conflict: false, path: r.csv_path }
    } catch (e) {
      if ((e as { status?: number }).status === 409) return { conflict: true, path: ps.csvPath }
      throw e
    }
  },

  params: {},
  results: {},
  running: null,
  stopRequested: false,
  pdmView: { candidates: true, rt2: false, profile: true, tcpAxes: true },
  setParams: (patch) => {
    const params = { ...get().params, ...patch }
    persist({ params })
    set({ params })
  },
  setPdmView: (patch) => set({ pdmView: { ...get().pdmView, ...patch } }),
  runPdm: async (indices) => {
    const { urdf, designation: d, activeCloudId, joints } = get()
    if (!urdf || !activeCloudId) return
    set({ running: { done: 0, total: indices.length }, stopRequested: false })
    try {
      for (const [k, i] of indices.entries()) {
        if (get().stopRequested) break
        const row = get().points[activeCloudId].rows[i]
        const result = await api.pdmRun({
          cloud_id: activeCloudId,
          urdf_path: urdf.path,
          dda: { end_link: d.ddaEnd, tcp_link: d.ddaTcp },
          rt: { end_link: d.rtEnd, tcp_link: d.rtTcp },
          joint_positions: joints,
          params: get().params,
          point: row,
        })
        const byCloud = { ...(get().results[activeCloudId] ?? {}), [i]: result }
        set({ results: { ...get().results, [activeCloudId]: byCloud }, running: { done: k + 1, total: indices.length } })
        // 한 점만 돌리면 그 점으로 카메라를 옮기고, 여러 점이면 첫 결과만 선택해 둔다
        if (indices.length === 1) get().focusPoint(i)
        else if (k === 0) set({ selectedPoint: i })
      }
    } finally {
      set({ running: null, stopRequested: false })
    }
  },
  stopPdm: () => set({ stopRequested: true }),
}))

/** 예전 판이 이 브라우저 localStorage 에 남긴 작업 상태 — 서버에 없는 항목만 서버로 옮긴다 */
function legacySession(): Session {
  const designations: NonNullable<Session['designations']> = {}
  for (let i = 0; i < localStorage.length; i++) {
    const k = localStorage.key(i) ?? ''
    if (k.startsWith('pdm-web:designation:')) designations[k.slice('pdm-web:designation:'.length)] = legacy(k.slice(8), EMPTY_DESIGNATION)
  }
  const out: Session = {}
  const lastUrdf = legacy<string | null>('lastUrdf', null)
  const clouds = legacy<Session['clouds'] | null>('clouds', null)
  const params = legacy<PdmParams | null>('params', null)
  const tab = legacy<Tab | null>('tab', null)
  if (lastUrdf) out.lastUrdf = lastUrdf
  if (clouds?.length) out.clouds = clouds
  if (params && Object.keys(params).length) out.params = params
  if (tab) out.tab = tab
  if (Object.keys(designations).length) out.designations = designations
  return out
}

/** 앱 시작 시 서버의 작업 상태로 마지막 URDF·점군·작업 대상·파라미터·탭을 복원 */
export async function restoreSession() {
  try {
    session = await api.session()
  } catch (e) {
    console.warn('작업 상태를 읽지 못했습니다', e)
  }
  const old = legacySession()
  const missing: Partial<Session> = {}
  for (const key of Object.keys(old) as (keyof Session)[]) {
    if (key === 'designations') {
      const add = Object.fromEntries(Object.entries(old.designations ?? {}).filter(([k]) => !session.designations?.[k]))
      if (Object.keys(add).length) missing.designations = add
    } else if (session[key] === undefined) {
      ;(missing as Record<string, unknown>)[key] = old[key]
    }
  }
  if (Object.keys(missing).length) persist(missing)

  const s = useStore.getState()
  if (session.tab) useStore.setState({ tab: session.tab })
  if (session.params) useStore.setState({ params: session.params })
  if (session.lastUrdf) void s.openUrdf(session.lastUrdf)
  const wantActive = session.activeCloud
  for (const c of session.clouds ?? []) await s.addCloud(c.path, c.scale)
  const active = useStore.getState().layers.find((l) => l.meta.path === wantActive)
  if (active) useStore.setState({ activeCloudId: active.meta.id })
}

export function activeLayer(s: State): Layer | undefined {
  return s.layers.find((l) => l.meta.id === s.activeCloudId)
}
