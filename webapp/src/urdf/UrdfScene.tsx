// URDF 3D 장면: 링크 형상, 선택 강조, TCP·선택 링크 좌표축, 이름 라벨.
import { Html } from '@react-three/drei'
import { useMemo } from 'react'
import { Box3, Matrix4, Vector3 } from 'three'
import { useStore } from '../store'
import { isTcpLink, linkWorld } from '../lib/urdf'
import { LinkView, type Look } from '../components/LinkGeometry'
import { CameraFit } from '../components/Viewport'

export const ROLE_COLORS = { dda: '#2f6fdb', rt: '#e0782b', tcp: '#8a3ffc' }

export function Axes({ world, size = 0.12 }: { world: Matrix4; size?: number }) {
  return (
    <group matrix={world} matrixAutoUpdate={false}>
      <axesHelper args={[size]} />
    </group>
  )
}

export function UrdfScene({ fitNonce }: { fitNonce: number }) {
  const { urdf, joints, selectedLink, showVisual, showCollision, showLabels, designation, selectLink } = useStore()
  const world = useMemo(() => (urdf ? linkWorld(urdf, joints) : new Map<string, Matrix4>()), [urdf, joints])

  const box = useMemo(() => {
    const b = new Box3()
    world.forEach((m) => b.expandByPoint(new Vector3().setFromMatrixPosition(m)))
    b.expandByScalar(0.3)
    return b
    // 조인트를 움직일 때마다 화면을 다시 맞추지 않도록 URDF 가 바뀔 때만 계산
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [urdf])

  // 다른 URDF 를 열면 화면을 다시 맞춘다
  const urdfSeq = useMemo(() => Math.random(), [urdf])

  if (!urdf) return null

  const lookFor = (name: string, collision: boolean): Look => {
    const selected = name === selectedLink
    let color = collision ? '#5fb37a' : '#aab2bf'
    if (name === designation.ddaEnd) color = ROLE_COLORS.dda
    if (name === designation.rtEnd) color = ROLE_COLORS.rt
    return {
      color,
      opacity: collision && showVisual ? 0.45 : 1,
      emissive: selected ? '#ffd400' : undefined,
    }
  }

  return (
    <>
      <CameraFit box={box} nonce={fitNonce + urdfSeq} />
      {urdf.links.map((l) => {
        const w = world.get(l.name)
        if (!w) return null
        const onClick = (e: { stopPropagation: () => void }) => {
          e.stopPropagation()
          selectLink(l.name === selectedLink ? null : l.name)
        }
        return (
          <group key={l.name}>
            {showVisual && <LinkView world={w} geoms={l.visuals} look={lookFor(l.name, false)} onClick={onClick} />}
            {showCollision && <LinkView world={w} geoms={l.collisions} look={lookFor(l.name, true)} onClick={onClick} />}
          </group>
        )
      })}
      {urdf.links.map((l) => {
        const w = world.get(l.name)
        if (!w) return null
        const tcp = isTcpLink(urdf, l.name) || l.name === designation.ddaTcp || l.name === designation.rtTcp
        const selected = l.name === selectedLink
        if (!tcp && !selected && !showLabels) return null
        const p = new Vector3().setFromMatrixPosition(w)
        return (
          <group key={`f-${l.name}`}>
            {(tcp || selected) && <Axes world={w} size={selected ? 0.2 : 0.12} />}
            {(showLabels || tcp || selected) && (
              <Html position={p} className={`label ${tcp ? 'tcp' : ''} ${selected ? 'sel' : ''}`} zIndexRange={[10, 0]}>
                <span onClick={() => selectLink(l.name)}>{l.name}</span>
              </Html>
            )}
          </group>
        )
      })}
    </>
  )
}
