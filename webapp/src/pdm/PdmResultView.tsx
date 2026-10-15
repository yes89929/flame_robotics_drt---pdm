// 선택 검사점의 PDM 결과 3D 표시: 배관 피팅 원기둥, 후보 링, 채택 자세의 DDA·RT 엔드이펙터.
import { useMemo } from 'react'
import { Matrix4, Quaternion, Vector3 } from 'three'
import { activeLayer, useStore } from '../store'
import { rowMajor } from '../lib/urdf'
import { LinkView } from '../components/LinkGeometry'
import { Axes } from '../urdf/UrdfScene'

/** 채택 자세 슬롯 색 (0° / 120° / 240°) */
export const SLOT_COLORS: Record<string, string> = { '0': '#d9453b', '120': '#2f9e55', '240': '#3b6fd9' }
export const CAND_COLORS = { ok: '#9aa3b1', dda_collision: '#e0443a', rt_collision: '#f0a020' }

function ProfileCylinder({ direction, center, radius, near }: { direction: number[]; center: number[]; radius: number; near: number[] }) {
  const m = useMemo(() => {
    const d = new Vector3(...direction).normalize()
    const c = new Vector3(...center)
    const onAxis = c.clone().addScaledVector(d, new Vector3(...near).sub(c).dot(d))
    const q = new Quaternion().setFromUnitVectors(new Vector3(0, 1, 0), d)
    return new Matrix4().compose(onAxis, q, new Vector3(1, 1, 1))
  }, [direction, center, near])
  return (
    <group matrix={m} matrixAutoUpdate={false}>
      <mesh>
        <cylinderGeometry args={[radius, radius, 0.4, 48, 1, true]} />
        <meshBasicMaterial color="#8a3ffc" transparent opacity={0.12} depthWrite={false} side={2} />
      </mesh>
      <mesh>
        <cylinderGeometry args={[0.002, 0.002, 0.6, 8]} />
        <meshBasicMaterial color="#8a3ffc" />
      </mesh>
    </group>
  )
}

export function PdmResultView() {
  const { urdf, designation, selectedPoint, results, pdmView } = useStore()
  const layer = useStore(activeLayer)
  const res = layer && selectedPoint !== null ? results[layer.meta.id]?.[selectedPoint] : undefined
  const links = useMemo(() => new Map(urdf?.links.map((l) => [l.name, l]) ?? []), [urdf])
  if (!res) return null
  const dda = links.get(designation.ddaEnd)
  const rt = links.get(designation.rtEnd)
  const tcpToLink = res.tcp_to_link
  const place = (tcp: number[], role: 'DDA' | 'RT') => rowMajor(tcp).multiply(rowMajor(tcpToLink![role]))

  return (
    <>
      <mesh position={res.detection as [number, number, number]}>
        <boxGeometry args={[0.01, 0.01, 0.01]} />
        <meshBasicMaterial color="#1c8f5a" />
      </mesh>
      {pdmView.profile && res.profile && (
        <ProfileCylinder direction={res.profile.direction} center={res.profile.center} radius={res.profile.radius} near={res.inspection} />
      )}
      {pdmView.candidates &&
        res.candidates?.map((c, i) => {
          const p = new Vector3().setFromMatrixPosition(rowMajor(c.tcp))
          return (
            <mesh key={i} position={p}>
              <sphereGeometry args={[0.004, 8, 6]} />
              <meshBasicMaterial color={CAND_COLORS[c.status]} />
            </mesh>
          )
        })}
      {tcpToLink &&
        res.slots?.map((s) => {
          const color = SLOT_COLORS[s.label] ?? '#888'
          const rtPoses = [s.RT1 ?? s.RT2, pdmView.rt2 && s.RT1 && s.RT2 ? s.RT2 : null].filter(Boolean) as number[][]
          return (
            <group key={s.label}>
              {dda && <LinkView world={place(s.DDA, 'DDA')} geoms={dda.collisions} look={{ color, opacity: 0.85 }} />}
              {pdmView.tcpAxes && <Axes world={rowMajor(s.DDA)} size={0.08} />}
              {rt &&
                rtPoses.map((t, k) => (
                  <group key={k}>
                    <LinkView world={place(t, 'RT')} geoms={rt.collisions} look={{ color, opacity: k === 0 ? 0.55 : 0.3 }} />
                    {pdmView.tcpAxes && <Axes world={rowMajor(t)} size={0.08} />}
                  </group>
                ))}
            </group>
          )
        })}
    </>
  )
}
