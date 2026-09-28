// URDF 링크 형상(box·cylinder·capsule·sphere·mesh) 렌더링. 메시는 경로별로 한 번만 받아 공유한다.
import { useEffect, useMemo, useState } from 'react'
import { BufferGeometry, Matrix4, Mesh, MeshStandardMaterial, Object3D } from 'three'
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader.js'
import { ColladaLoader } from 'three/examples/jsm/loaders/ColladaLoader.js'
import { OBJLoader } from 'three/examples/jsm/loaders/OBJLoader.js'
import type { ThreeEvent } from '@react-three/fiber'
import { api, type Geometry } from '../api'
import { originMatrix } from '../lib/urdf'

type Loaded = { kind: 'geometry'; geometry: BufferGeometry } | { kind: 'object'; object: Object3D }
const cache = new Map<string, Promise<Loaded>>()

function loadMesh(file: string): Promise<Loaded> {
  if (!cache.has(file)) {
    const url = api.rawUrl(file)
    const ext = file.split('.').pop()?.toLowerCase()
    let p: Promise<Loaded>
    if (ext === 'stl') {
      p = new STLLoader().loadAsync(url).then((g) => {
        g.computeVertexNormals()
        return { kind: 'geometry', geometry: g }
      })
    } else if (ext === 'dae') {
      // ColladaLoader 는 Z_UP 문서를 Y-up 으로 돌려 놓는다 — URDF 는 원래 좌표를 쓰므로 되돌린다
      p = new ColladaLoader().loadAsync(url).then((c) => {
        c.scene.rotation.set(0, 0, 0)
        c.scene.updateMatrixWorld(true)
        return { kind: 'object', object: c.scene }
      })
    } else if (ext === 'obj') {
      p = new OBJLoader().loadAsync(url).then((o) => ({ kind: 'object', object: o }))
    } else {
      p = Promise.reject(new Error(`지원하지 않는 메시 형식: ${file}`))
    }
    cache.set(file, p)
  }
  return cache.get(file)!
}

export interface Look { color: string; opacity: number; emissive?: string; wireframe?: boolean }

function Material({ look }: { look: Look }) {
  return (
    <meshStandardMaterial
      color={look.color}
      emissive={look.emissive ?? '#000000'}
      emissiveIntensity={look.emissive ? 0.55 : 0}
      transparent={look.opacity < 1}
      opacity={look.opacity}
      depthWrite={look.opacity >= 1}
      wireframe={look.wireframe}
      metalness={0.05}
      roughness={0.75}
    />
  )
}

function MeshFile({ g, look, onClick }: { g: Geometry; look: Look; onClick?: (e: ThreeEvent<MouseEvent>) => void }) {
  const [loaded, setLoaded] = useState<Loaded | null>(null)
  useEffect(() => {
    let alive = true
    loadMesh(g.file!).then((l) => alive && setLoaded(l)).catch(() => undefined)
    return () => {
      alive = false
    }
  }, [g.file])
  const object = useMemo(() => (loaded?.kind === 'object' ? loaded.object.clone(true) : null), [loaded])
  useEffect(() => {
    // DAE/OBJ: 원래 재질 대신 지정 색을 씌운다 (선택·역할 강조가 보여야 하므로)
    if (!object) return
    const mat = new MeshStandardMaterial({
      color: look.color,
      emissive: look.emissive ?? '#000000',
      emissiveIntensity: look.emissive ? 0.55 : 0,
      transparent: look.opacity < 1,
      opacity: look.opacity,
      depthWrite: look.opacity >= 1,
    })
    object.traverse((c) => {
      if ((c as Mesh).isMesh) (c as Mesh).material = mat
    })
    return () => mat.dispose()
  }, [object, look.color, look.emissive, look.opacity])
  if (!loaded) return null
  const scale = (g.scale ?? [1, 1, 1]) as [number, number, number]
  if (loaded.kind === 'geometry') {
    return (
      <mesh geometry={loaded.geometry} scale={scale} onClick={onClick}>
        <Material look={look} />
      </mesh>
    )
  }
  return <primitive object={object!} scale={scale} onClick={onClick} />
}

export function GeometryView({
  g,
  look,
  onClick,
}: {
  g: Geometry
  look: Look
  onClick?: (e: ThreeEvent<MouseEvent>) => void
}) {
  const m = useMemo(() => originMatrix(g.origin), [g.origin])
  let body = null
  switch (g.type) {
    case 'box':
      body = (
        <mesh onClick={onClick}>
          <boxGeometry args={g.size as [number, number, number]} />
          <Material look={look} />
        </mesh>
      )
      break
    case 'cylinder':
      // three 의 원기둥 축은 Y, URDF 는 Z
      body = (
        <mesh rotation={[Math.PI / 2, 0, 0]} onClick={onClick}>
          <cylinderGeometry args={[g.radius, g.radius, g.length, 32]} />
          <Material look={look} />
        </mesh>
      )
      break
    case 'capsule':
      body = (
        <mesh rotation={[Math.PI / 2, 0, 0]} onClick={onClick}>
          <capsuleGeometry args={[g.radius, g.length, 8, 24]} />
          <Material look={look} />
        </mesh>
      )
      break
    case 'sphere':
      body = (
        <mesh onClick={onClick}>
          <sphereGeometry args={[g.radius, 24, 16]} />
          <Material look={look} />
        </mesh>
      )
      break
    case 'mesh':
      body = g.exists ? <MeshFile g={g} look={look} onClick={onClick} /> : null
      break
  }
  return (
    <group matrix={m} matrixAutoUpdate={false}>
      {body}
    </group>
  )
}

/** 링크 하나: world 행렬에 형상 목록을 얹는다 */
export function LinkView({
  world,
  geoms,
  look,
  onClick,
}: {
  world: Matrix4
  geoms: Geometry[]
  look: Look
  onClick?: (e: ThreeEvent<MouseEvent>) => void
}) {
  return (
    <group matrix={world} matrixAutoUpdate={false}>
      {geoms.map((g, i) => (
        <GeometryView key={i} g={g} look={look} onClick={onClick} />
      ))}
    </group>
  )
}
