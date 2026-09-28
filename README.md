# flame_robotics_drt

## Setup

## Setup Environments (Python 3.10)

1. Install python prerequisites
```
$ pip install -r requirements.txt
```

2. Launch 3D Viewer
```
$ python -m venv venv
$ source ./venv/bin/activate
(venv)$ cd python
(venv)$ python viewer3d.py
```

3. Launch Simulation Controller
```
(venv)$ python controller.py
```

## PDM 웹 도구 (`webapp/`, Windows 개발 PC)

URDF 확인·PDM 엔드이펙터/TCP 링크 지정, 배관·검사룸 점군 표시와 검사점 지정, 검사점별 PDM 실행 결과 3D 확인을 브라우저 한 화면에서 한다.

1. 의존성 (conda env `drt-pdm` 에 plugin_pdm 의존성이 있는 상태에서)
```
> conda activate drt-pdm
> pip install -r webapp/server/requirements.txt
> cd webapp && npm install
```

2. 실행 — API(FastAPI, 127.0.0.1:2940)와 화면(Vite, 2941)을 함께 띄운다
```
> cd webapp && npm run dev
```
   개발 PC에서는 작업 스케줄러 작업 `PDM-web-dev`(`webapp/run-dev.ps1`)로 띄운다: `schtasks /run /tn PDM-web-dev`. 로그는 `webapp/logs/dev.log`.

3. 접속: http://127.0.0.1:2941

- 점군은 범위(최대 축 길이)가 100을 넘으면 mm 로 보고 m 로 환산한다. 검사점은 점군 옆 `<점군 이름>_testpoint.csv`(m 단위, plugin_pdm 형식)로 저장된다.
- 테스트: `cd webapp && npm run test:api` (드라이브 실데이터가 있으면 PDM 1점 실행까지 포함), `npm run typecheck`.
