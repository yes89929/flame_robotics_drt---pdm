// 백엔드(pdm_web) 호출과 응답 타입. 모든 길이는 m, 행렬은 4×4 행 우선 16개 배열.

export interface Origin { xyz: number[]; rpy: number[] }

export interface Geometry {
  type: 'box' | 'cylinder' | 'capsule' | 'sphere' | 'mesh'
  origin: Origin
  size?: number[]
  radius?: number
  length?: number
  file?: string
  exists?: boolean
  scale?: number[]
  color?: number[]
}

export interface UrdfLink { name: string; visuals: Geometry[]; collisions: Geometry[] }

export interface UrdfJoint {
  name: string
  type: string
  parent: string
  child: string
  origin: Origin
  axis: number[]
  limit: { lower: number; upper: number } | null
  mimic: { joint: string; multiplier: number; offset: number } | null
}

export interface UrdfModel {
  path: string
  name: string
  version: string | null
  roots: string[]
  links: UrdfLink[]
  joints: UrdfJoint[]
}

export interface FsList { path: string; parent: string | null; dirs: string[]; files: { name: string; size: number }[] }

export interface CloudMeta {
  id: string
  path: string
  name: string
  scale: number
  unit: string
  n_points: number
  n_display: number
  has_colors: boolean
  has_normals: boolean
  normals_estimated: boolean
  bbox_min: number[]
  bbox_max: number[]
}

export interface PointRow { x: number; y: number; z: number; dx: number; dy: number; dz: number }

export interface PointsFile { csv_path: string; exists: boolean; rows: PointRow[] }

export type PdmParams = Record<string, number | boolean>

export interface PdmSlot {
  label: string
  actual_deg: number
  arc_deg: number | null
  DDA: number[]
  RT1: number[] | null
  RT2: number[] | null
}

export interface PdmResult {
  status: 'ok' | 'empty' | 'error'
  mode: '3pair' | '2pair' | 'none'
  inspection: number[]
  detection: number[]
  params: PdmParams
  tcp_to_link?: { DDA: number[]; RT: number[] }
  profile?: { direction: number[]; center: number[]; radius: number }
  candidates?: { deg: number; status: 'ok' | 'dda_collision' | 'rt_collision'; tcp: number[] }[]
  slots?: PdmSlot[]
  error?: string
  traceback?: string
  elapsed_sec: number
}

async function json<T>(res: Response): Promise<T> {
  if (!res.ok) {
    let detail = `${res.status} ${res.statusText}`
    try {
      const body = await res.json()
      if (body?.detail) detail = typeof body.detail === 'string' ? body.detail : JSON.stringify(body.detail)
    } catch {
      /* 본문 없음 */
    }
    const err = new Error(detail) as Error & { status?: number }
    err.status = res.status
    throw err
  }
  return res.json() as Promise<T>
}

const q = (params: Record<string, string>) => new URLSearchParams(params).toString()

export const api = {
  roots: () => fetch('/api/fs/roots').then(json<{ label: string; path: string }[]>),
  list: (path: string, exts: string[]) =>
    fetch(`/api/fs/list?${q({ path, exts: exts.join(',') })}`).then(json<FsList>),
  rawUrl: (path: string) => `/api/fs/raw?${q({ path })}`,
  urdf: (path: string) => fetch(`/api/urdf?${q({ path })}`).then(json<UrdfModel>),
  loadCloud: (path: string, scale: number | null) =>
    fetch('/api/cloud/load', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ path, scale }),
    }).then(json<CloudMeta>),
  cloudPositions: async (id: string) =>
    new Float32Array(await (await fetch(`/api/cloud/${id}/positions`)).arrayBuffer()),
  cloudColors: async (id: string) => {
    const buf = await (await fetch(`/api/cloud/${id}/colors`)).arrayBuffer()
    return buf.byteLength ? new Uint8Array(buf) : null
  },
  unloadCloud: (id: string) => fetch(`/api/cloud/${id}`, { method: 'DELETE' }),
  points: (cloudPath: string) => fetch(`/api/points?${q({ cloud_path: cloudPath })}`).then(json<PointsFile>),
  savePoints: (cloudPath: string, rows: PointRow[], overwrite: boolean) =>
    fetch('/api/points', {
      method: 'PUT',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ cloud_path: cloudPath, rows, overwrite }),
    }).then(json<{ csv_path: string; count: number }>),
  pdmDefaults: () => fetch('/api/pdm/defaults').then(json<PdmParams>),
  pdmRun: (body: unknown) =>
    fetch('/api/pdm/run', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(body),
    }).then(json<PdmResult>),
}
