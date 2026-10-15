// 점군·검사점 3D 장면: 점군 레이어, 검사점 마커·번호, 클릭 지정(피킹).
import { Html } from '@react-three/drei'
import { useThree } from '@react-three/fiber'
import { useEffect, useMemo, useRef, type ReactNode } from 'react'
import { Box3, BufferAttribute, BufferGeometry, Color, OrthographicCamera, Points, Raycaster, Vector2, Vector3 } from 'three'
import type { OrbitControls as OrbitControlsImpl } from 'three-stdlib'
import { activeLayer, useStore, type Layer } from '../store'
import { CameraFit } from '../components/Viewport'

const SOLID = new Color('#7d8796')

/** z 높이 → 파랑-청록-노랑 색 (Float32 RGB) */
function heightColors(pos: Float32Array): Float32Array {
  let lo = Infinity
  let hi = -Infinity
  for (let i = 2; i < pos.length; i += 3) {
    lo = Math.min(lo, pos[i])
    hi = Math.max(hi, pos[i])
  }
  const out = new Float32Array(pos.length)
  const span = hi - lo || 1
  const c = new Color()
  for (let i = 0; i < pos.length; i += 3) {
    const t = (pos[i + 2] - lo) / span
    c.setHSL(0.66 - 0.5 * t, 0.75, 0.45 + 0.1 * t)
    out[i] = c.r
    out[i + 1] = c.g
    out[i + 2] = c.b
  }
  return out
}

function CloudPoints({ layer, pointsRef }: { layer: Layer; pointsRef?: (p: Points | null) => void }) {
  const geometry = useMemo(() => {
    const g = new BufferGeometry()
    g.setAttribute('position', new BufferAttribute(layer.positions, 3))
    g.computeBoundingSphere()
    return g
  }, [layer.positions])
  const heights = useMemo(() => heightColors(layer.positions), [layer.positions])
  const invalidate = useThree((s) => s.invalidate)
  useEffect(() => {
    if (layer.colorMode === 'rgb' && layer.colors) geometry.setAttribute('color', new BufferAttribute(layer.colors, 3, true))
    else if (layer.colorMode === 'height') geometry.setAttribute('color', new BufferAttribute(heights, 3))
    else geometry.deleteAttribute('color')
    invalidate()
  }, [geometry, heights, layer.colorMode, layer.colors, invalidate])
  useEffect(() => () => geometry.dispose(), [geometry])
  const vertexColors = layer.colorMode !== 'solid'
  return (
    <points ref={pointsRef} geometry={geometry} visible={layer.visible} userData={{ cloudId: layer.meta.id }}>
      <pointsMaterial
        key={`${layer.colorMode}`}
        size={layer.pointSize}
        sizeAttenuation={false}
        vertexColors={vertexColors}
        color={vertexColors ? '#ffffff' : SOLID}
      />
    </points>
  )
}

/** 피킹 모드에서 클릭(드래그 아님) 위치의 가장 앞 점을 검사점으로 추가 */
function PointPicker({ target }: { target: React.MutableRefObject<Points | null> }) {
  const { gl, camera } = useThree()
  const pickMode = useStore((s) => s.pickMode)
  const addPoint = useStore((s) => s.addPoint)
  useEffect(() => {
    if (!pickMode) return
    const el = gl.domElement
    let down: { x: number; y: number } | null = null
    const onDown = (e: PointerEvent) => {
      if (e.button === 0) down = { x: e.clientX, y: e.clientY }
    }
    const onUp = (e: PointerEvent) => {
      if (!down || e.button !== 0) return
      const moved = Math.hypot(e.clientX - down.x, e.clientY - down.y)
      down = null
      if (moved > 4 || !target.current || !target.current.visible) return
      const rect = el.getBoundingClientRect()
      const ndc = new Vector2(((e.clientX - rect.left) / rect.width) * 2 - 1, -((e.clientY - rect.top) / rect.height) * 2 + 1)
      const rc = new Raycaster()
      rc.setFromCamera(ndc, camera)
      // 화면 6px 반경 안의 점 (직교 카메라: 월드 길이 = 픽셀 / zoom)
      rc.params.Points = { threshold: 6 / (camera as OrthographicCamera).zoom }
      const hits = rc.intersectObject(target.current, false)
      if (hits.length === 0) return
      // 교차 목록은 카메라에서 가까운 순 → 첫 점이 보이는 앞면. hit.point 는 광선 위 투영점이라
      // 실제 스캔 점 좌표는 버퍼에서 index 로 읽는다
      const arr = target.current.geometry.getAttribute('position').array as Float32Array
      const k = hits[0].index! * 3
      addPoint([arr[k], arr[k + 1], arr[k + 2]])
    }
    el.addEventListener('pointerdown', onDown)
    el.addEventListener('pointerup', onUp)
    return () => {
      el.removeEventListener('pointerdown', onDown)
      el.removeEventListener('pointerup', onUp)
    }
  }, [pickMode, gl, camera, target, addPoint])
  return null
}

/** 선택 검사점으로 카메라 중심 이동 (확대는 유지하되 너무 멀면 0.6 m 폭으로) */
function FocusSelected() {
  const { camera, controls, invalidate, size } = useThree()
  const focusNonce = useStore((s) => s.focusNonce)
  useEffect(() => {
    const s = useStore.getState()
    const ps = s.activeCloudId ? s.points[s.activeCloudId] : null
    if (s.selectedPoint === null || !ps || !controls) return
    const r = ps.rows[s.selectedPoint]
    if (!r) return
    const c = controls as unknown as OrbitControlsImpl
    const target = new Vector3(r.x, r.y, r.z)
    const delta = target.clone().sub(c.target)
    c.target.copy(target)
    camera.position.add(delta)
    const cam = camera as OrthographicCamera
    const minZoom = Math.min(size.width, size.height) / 0.6
    if (cam.zoom < minZoom) cam.zoom = minZoom
    cam.updateProjectionMatrix()
    c.update()
    invalidate()
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [focusNonce])
  return null
}

function InspectionMarkers() {
  const { activeCloudId, points, selectedPoint, focusPoint, pickMode } = useStore()
  const ps = activeCloudId ? points[activeCloudId] : null
  if (!ps) return null
  return (
    <>
      {ps.rows.map((r, i) => {
        const sel = i === selectedPoint
        const hasOffset = r.dx !== 0 || r.dy !== 0 || r.dz !== 0
        return (
          <group key={i}>
            <mesh position={[r.x, r.y, r.z]} renderOrder={5}>
              <sphereGeometry args={[sel ? 0.009 : 0.006, 16, 12]} />
              <meshBasicMaterial color={sel ? '#ffb000' : '#d62f2f'} depthTest={false} transparent />
            </mesh>
            {hasOffset && (
              <mesh position={[r.x + r.dx, r.y + r.dy, r.z + r.dz]} renderOrder={5}>
                <boxGeometry args={[0.008, 0.008, 0.008]} />
                <meshBasicMaterial color="#1c8f5a" depthTest={false} transparent />
              </mesh>
            )}
            <Html position={[r.x, r.y, r.z]} className={`pt-label ${sel ? 'sel' : ''}`} zIndexRange={[20, 0]} style={{ transform: 'translate(8px, -22px)', pointerEvents: pickMode ? 'none' : 'auto' }}>
              <span onClick={() => focusPoint(sel ? null : i)}>{i + 1}</span>
            </Html>
          </group>
        )
      })}
    </>
  )
}

export function CloudScene({ children }: { children?: ReactNode }) {
  const { layers, fitNonce } = useStore()
  const active = useStore(activeLayer)
  const activeRef = useRef<Points | null>(null)
  const box = useMemo(() => {
    const b = new Box3()
    for (const l of layers) {
      if (!l.visible) continue
      b.expandByPoint(new Vector3(...l.meta.bbox_min))
      b.expandByPoint(new Vector3(...l.meta.bbox_max))
    }
    return b.isEmpty() ? null : b
  }, [layers])
  return (
    <>
      <CameraFit box={box} nonce={fitNonce} margin={1.05} />
      {layers.map((l) => (
        <CloudPoints
          key={l.meta.id}
          layer={l}
          pointsRef={l.meta.id === active?.meta.id ? (p) => (activeRef.current = p) : undefined}
        />
      ))}
      <PointPicker target={activeRef} />
      <FocusSelected />
      <InspectionMarkers />
      {children}
    </>
  )
}
