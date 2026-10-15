// 앱 전역 상태 (zustand). 세 탭이 같은 URDF·점군·검사점을 공유한다.
// 브라우저 localStorage 에 남기는 것: 마지막 URDF 경로, URDF별 PDM 링크 지정, 열어 둔 점군 경로, PDM 파라미터.
import { create } from 'zustand'
import { api, type CloudMeta, type PdmParams, type PdmResult, type PointRow, type UrdfModel } from './api'

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

const LS = {
  get<T>(key: string, fallback: T): T {
    try {
      const v = localStorage.getItem(`pdm-web:${key}`)
      return v ? (JSON.parse(v) as T) : fallback
    } catch {
      return fallback
    }
  },
  set(key: string, value: unknown) {
    localStorage.setItem(`pdm-web:${key}`, JSON.stringify(value))
  },
}

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
  tab: LS.get<Tab>('tab', 'urdf'),
  setTab: (tab) => {
    LS.set('tab', tab)
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
      const saved = LS.get<Designation | null>(`designation:${path}`, null)
      LS.set('lastUrdf', path)
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
    if (path) LS.set(`designation:${path}`, designation)
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
      LS.set('clouds', layers.map((l) => ({ path: l.meta.path, scale: l.meta.scale })))
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
    LS.set('clouds', layers.map((l) => ({ path: l.meta.path, scale: l.meta.scale })))
    void api.unloadCloud(id)
    set({
      layers,
      activeCloudId: get().activeCloudId === id ? (layers[0]?.meta.id ?? null) : get().activeCloudId,
      selectedPoint: null,
    })
  },
  updateLayer: (id, patch) => set({ layers: get().layers.map((l) => (l.meta.id === id ? { ...l, ...patch } : l)) }),
  setActiveCloud: (activeCloudId) => set({ activeCloudId, selectedPoint: null }),
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

  params: LS.get<PdmParams>('params', {}),
  results: {},
  running: null,
  stopRequested: false,
  pdmView: { candidates: true, rt2: false, profile: true, tcpAxes: true },
  setParams: (patch) => {
    const params = { ...get().params, ...patch }
    LS.set('params', params)
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

/** 앱 시작 시 마지막 URDF·점군 복원 */
export async function restoreSession() {
  const s = useStore.getState()
  const urdf = LS.get<string | null>('lastUrdf', null)
  if (urdf) void s.openUrdf(urdf)
  for (const c of LS.get<{ path: string; scale: number }[]>('clouds', [])) await s.addCloud(c.path, c.scale)
}

export function activeLayer(s: State): Layer | undefined {
  return s.layers.find((l) => l.meta.id === s.activeCloudId)
}
