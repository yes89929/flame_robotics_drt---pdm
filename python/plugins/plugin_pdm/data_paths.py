"""PDM 입력 데이터 경로 — 과제 구글 드라이브를 직접 참조한다.

배관 점군(PLY)·검사 지점(CSV)·로봇 모델(URDF/메쉬) 은 용량과 공유 때문에 git 이 아니라
구글 드라이브(Google Drive for Desktop) 에서 관리한다. 드라이브가 다른 위치에 마운트된
단말(드라이브 문자·"My Drive" 표기 차이 등)은 환경변수 ``PDM_DATA_ROOT`` 로
``3. 기타자료`` 폴더를 지정한다.

Open3D 는 한글 절대경로의 STL 을 읽지 못하므로(빈 mesh 반환) 이 경로의 URDF 를 로드하기 전에
``tools.viewer._open3d_compat.apply()`` 를 호출해야 한다.
"""

import os
from pathlib import Path

DATA_ROOT = Path(os.environ.get("PDM_DATA_ROOT", r"G:\내 드라이브\3. 진행 과제\P2413；DRT\3. 기타자료"))

# PIPE NO.{1,2,3}_fill.ply / _testpoint.csv
PIPE_DATA_DIR = DATA_ROOT / "배관 데이터" / "한화오션 3종 cad to ply"

# URDF 의 메쉬 경로가 "../meshes/..." 상대표기이므로 robots/ 와 meshes/ 의 형제 관계를 유지한다.
ROBOT_MODELS_DIR = DATA_ROOT / "로봇 모델" / "robot_models v1.5"
ROBOTS_DIR = ROBOT_MODELS_DIR / "robots"
