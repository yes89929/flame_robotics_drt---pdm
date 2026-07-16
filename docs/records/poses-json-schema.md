# 자세 계산 결과 JSON 구조 설명

`tools/export_poses.py` 가 배관별로 생성하는 `PIPE NO.X/poses.json` 의 스키마 설명이다.
자세 계산 엔진은 [EndEffectorPoseOptimizer.calculate_DDA_RT_pose_for_taking_xray_3pair_120](../../python/plugins/plugin_pdm/EndEffectorPoseOptimizer.py) 이다.

## 생성 방법

```bash
conda activate drt-pdm
python tools/export_poses.py --pipe all          # 3개 배관 전부
python tools/export_poses.py --pipe "NO.1"       # 특정 배관
python tools/export_poses.py --pipe "NO.3" --no-render   # JSON 만
```

## 최상위 구조

```jsonc
{
  "pipe": "PIPE NO.1_fill",            // 배관 이름
  "scan_file": "PIPE NO.1_fill.ply",   // 입력 점군 스캔 파일
  "testpoint_file": "PIPE NO.1_fill_testpoint.csv", // 검사점 좌표 CSV
  "dda_urdf": "rb10_1300e_DDA.urdf",   // DDA 엔드이펙터 모델
  "rt_urdf": "rb10_1300e_RT.urdf",     // RT 엔드이펙터 모델
  "params": { ... },                   // 계산 파라미터 (아래)
  "num_points": 12,                    // 처리한 검사점 수
  "summary": {                         // 결과 집계
    "3pair": 4, "2pair": 6, "empty": 1, "error": 1
  },
  "points": [ { ...검사점별 결과... } ] // 핵심 데이터
}
```

### `params` — 계산 파라미터 (모든 검사점 공통)

| 키 | 값(기본) | 의미 |
|---|---|---|
| `distance_from_dda_to_surface` | 0.01 | DDA TCP ↔ 배관 표면 거리 (m) |
| `distance_from_dda_to_rt` | 0.3 | DDA TCP ↔ RT TCP 거리 (m) |
| `angle_of_rt` | 10.0 | DDA X축 대비 RT X축 벌어짐 각도 (deg) |
| `candidate_step_deg` | 3.0 | 배관 둘레 후보 자세 생성 간격 (deg) → 후보 120개 |
| `gap_tolerance_deg` | 10.0 | 이상 간격 120°에서 허용 편차 (deg). 박스 제약 |
| `allow_2pair_fallback` | true | 3쌍 불가 시 2쌍 폴백 허용 |

### `summary` — 결과 모드 집계

- `3pair`: 120° 간격 3쌍 자세를 찾은 검사점 수
- `2pair`: 3쌍 불가로 2쌍(≈120°)으로 폴백한 수
- `empty`: 충돌 등으로 유효 자세가 없는 수 (`pose_groups: []`)
- `error`: 계산 중 예외 발생 수 (`error` 필드에 메시지)

## 검사점 단위 (`points[]`)

```jsonc
{
  "index": 1,                              // CSV 1-기반 순번
  "inspection_point": [x, y, z],           // 검사(촬영 대상) 좌표 (m)
  "detection_point":  [x, y, z],           // 배관 프로파일 추정용 탐지 좌표 (= inspection + CSV의 dx,dy,dz)
  "status": "ok" | "empty" | "error",
  "mode":   "3pair" | "2pair" | "none",
  "pose_groups": [ { ...자세 그룹... } ],   // 0개 또는 1개 그룹
  "image": "point_01.png",                 // (렌더링 시) 시각화 파일명
  "elapsed_sec": 7.16,                     // 이 검사점 계산+렌더 소요 시간
  "error": "..."                           // status=="error" 일 때만
}
```

- `inspection_point` 는 X-ray로 **촬영할 용접부 좌표**, `detection_point` 는 그 주변 배관의
  방향/중심/반지름을 추정하기 위한 좌표다. CSV의 `dx,dy,dz` 오프셋이 없으면 둘은 같다.

## 자세 그룹 (`pose_groups[0]`)

`pose_groups` 는 **0개 또는 1개**의 그룹만 담는다(최적 1개 선택). 그룹의 **키가 곧 이상 회전 라벨**이다.

- 3쌍 성공: 키 = `"0"`, `"120"`, `"240"`
- 2쌍 폴백: 키 = `"0"`, `"120"`
- 유효 자세 없음: `pose_groups` 는 `[]`

```jsonc
{
  "0":   { "DDA": [...], "RT1": [...], "RT2": [...], "_actual_deg": 0,   "_arc_deg": 120 },
  "120": { "DDA": [...], "RT1": [...], "RT2": [...], "_actual_deg": 240, "_arc_deg": 120 }
}
```

### 슬롯(각 회전 위치) 필드

| 키 | 타입 | 의미 |
|---|---|---|
| `DDA` | `[x,y,z,roll,pitch,yaw]` | DDA 엔드이펙터 **TCP 자세** (위치 m, 각도 rad) |
| `RT1` | `[x,y,z,roll,pitch,yaw]` | RT를 `+angle_of_rt` 로 배치한 자세 (충돌 시 생략됨) |
| `RT2` | `[x,y,z,roll,pitch,yaw]` | RT를 `-angle_of_rt` 로 배치한 자세 (충돌 시 생략됨) |
| `_actual_deg` | int | 배관 둘레에서의 **실측 양자화 각도** (0~359). 그룹 키(이상 라벨)와 다를 수 있음 |
| `_arc_deg` | int | **2쌍 폴백일 때만** 존재. 채택된 두 자세 사이 실측 호 각도 |

- **`DDA`/`RT1`/`RT2` 는 모두 6-DOF 자세** `[x, y, z, roll, pitch, yaw]`.
  - 앞 3개는 미터 단위 위치, 뒤 3개는 **라디안** 오일러각(`scipy` `"xyz"` 순서).
  - `RT1` 과 `RT2` 는 DDA 기준 좌/우 대칭 후보이며, **둘 중 충돌 없는 것만** 남는다.
    (둘 다 유효하면 둘 다, 하나만 유효하면 하나만, 둘 다 충돌이면 그 슬롯 자체가 생성 안 됨)
- **그룹 키 vs `_actual_deg`**: 키(`"0"/"120"/"240"`)는 *이상적인* 120° 라벨이고,
  `_actual_deg` 는 충돌 회피 후 실제로 선택된 둘레 각도다.
  예: 키 `"120"` 인데 `_actual_deg: 240` 일 수 있다(폴백에서 실측 240° 자세가 두 번째 슬롯이 된 경우).

## TCP 자세 → 3D 배치 변환 (시각화/로봇 적용 시)

`DDA`/`RT1`/`RT2` 는 **TCP(공구 중심점) 자세**다. 엔드이펙터 메시나 로봇에 적용하려면
TCP→원점 역변환을 곱한다 (스크립트의 `_pose_to_mesh_T`, 데모 노트북과 동일 방식):

```python
from scipy.spatial.transform import Rotation as R
import numpy as np

def tcp_to_matrix(pose6):                      # [x,y,z,roll,pitch,yaw] → 4x4
    T = np.eye(4)
    T[:3, :3] = R.from_euler("xyz", pose6[3:]).as_matrix()
    T[:3, 3]  = pose6[:3]
    return T

# 메시 배치용 행렬 = TCP자세 @ (mesh→tcp)^-1
dda_mesh_T = tcp_to_matrix(slot["DDA"]) @ optimizer._EndEffectorPoseOptimizer__dda_invers_transform_mat
rt_mesh_T  = tcp_to_matrix(slot["RT1"]) @ optimizer._EndEffectorPoseOptimizer__rt_invers_transform_mat
```

## 시각화 산출물

배관 폴더마다:

- `overview.png` — 전체 배관 점군 + 모든 검사점(번호 라벨). 검사=탐지 동일점은 초록, 다르면 검사=빨강·탐지=파랑.
- `point_NN.png` — 검사점 NN 주변 crop 점군 + 선택된 자세의 DDA/RT 메시.
  라벨별 색: `"0"`=빨강, `"120"`=초록, `"240"`=파랑. `pose_groups` 가 비면 메시 없이 점군만.
