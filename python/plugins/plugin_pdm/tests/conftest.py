"""pytest 공용 설정.

본 디렉토리의 테스트는 plugin_pdm 루트에서 직접 모듈을 import 한다
(예: ``from EndEffectorPoseOptimizer import EndEffectorPoseOptimizer``).
플러그인이 패키지로 배포되기 전이라 sys.path 에 루트를 추가해 둔다.
"""

import sys
from pathlib import Path

PLUGIN_PDM_ROOT = Path(__file__).resolve().parent.parent
if str(PLUGIN_PDM_ROOT) not in sys.path:
    sys.path.insert(0, str(PLUGIN_PDM_ROOT))
