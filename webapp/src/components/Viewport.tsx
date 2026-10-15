// 공용 3D 뷰포트: 직교 카메라(Z 위), 궤도 조작, XY 격자, 축 기즈모, 화면 맞춤.
import { Canvas, useThree } from '@react-three/fiber'
import { GizmoHelper, GizmoViewport, OrbitControls } from '@react-three/drei'
import { useEffect, useRef, type ReactNode } from 'react'
import { Box3, OrthographicCamera, Vector3 } from 'three'
import type { OrbitControls as OrbitControlsImpl } from 'three-stdlib'

/** nonce 가 바뀔 때마다 box 를 화면에 맞춘다. 시선 방향은 유지한다. */
export function CameraFit({ box, nonce, margin = 1.15 }: { box: Box3 | null; nonce: number; margin?: number }) {
  const camera = useThree((s) => s.camera) as OrthographicCamera
  const controls = useThree((s) => s.controls) as unknown as OrbitControlsImpl | null
  const size = useThree((s) => s.size)
  const invalidate = useThree((s) => s.invalidate)
  // 숨겨진 탭(크기 0)이거나 조작기가 아직 없으면 미뤘다가 조건이 갖춰질 때 한 번 맞춘다
  const done = useRef<number | null>(null)
  useEffect(() => {
    if (done.current === nonce) return
    if (!box || box.isEmpty() || !controls || size.width === 0 || size.height === 0) return
    done.current = nonce
    const center = box.getCenter(new Vector3())
    const diag = Math.max(box.getSize(new Vector3()).length(), 1e-3)
    const dir = camera.position.clone().sub(controls.target)
    if (dir.lengthSq() < 1e-12) dir.set(1, -1, 1)
    dir.normalize()
    controls.target.copy(center)
    camera.position.copy(center).addScaledVector(dir, diag * 2)
    camera.zoom = Math.min(size.width, size.height) / (diag * margin)
    camera.near = -diag * 10
    camera.far = diag * 10
    camera.updateProjectionMatrix()
    controls.update()
    invalidate()
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [nonce, controls, size.width, size.height, box])
  return null
}

export function Viewport({ children, gridSize = 20 }: { children: ReactNode; gridSize?: number }) {
  return (
    <Canvas
      orthographic
      frameloop="demand"
      camera={{ position: [4, -6, 4], up: [0, 0, 1], zoom: 80, near: -1000, far: 1000 }}
      gl={{ antialias: true, preserveDrawingBuffer: true }}
      onCreated={({ gl }) => gl.setClearColor('#f7f8fa')}
    >
      <ambientLight intensity={0.7} />
      <directionalLight position={[3, -4, 6]} intensity={1.6} />
      <directionalLight position={[-4, 3, -2]} intensity={0.5} />
      <gridHelper args={[gridSize, gridSize, '#b8bfcc', '#e1e5ec']} rotation={[Math.PI / 2, 0, 0]} />
      <OrbitControls makeDefault enableDamping={false} />
      <GizmoHelper alignment="bottom-right" margin={[70, 70]}>
        <GizmoViewport axisColors={['#d9453b', '#3ba55c', '#3b6fd9']} labelColor="white" />
      </GizmoHelper>
      {children}
    </Canvas>
  )
}
