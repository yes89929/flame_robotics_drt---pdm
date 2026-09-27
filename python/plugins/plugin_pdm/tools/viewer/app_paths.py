"""tools/viewer 가 사용하는 경로 상수.

데이터 위치는 plugin_pdm 루트의 ``data_paths`` (구글 드라이브) 를 따르고,
robot URDF 경로를 함수로 노출한다. plugin_pdm 루트가 sys.path 에 있어야 한다.
"""

from pathlib import Path

from data_paths import PIPE_DATA_DIR as DATA_DIR, ROBOT_MODELS_DIR


def dda_urdf_path() -> Path:
    return ROBOT_MODELS_DIR / "robots" / "rb10_1300e_DDA.urdf"


def rt_urdf_path() -> Path:
    return ROBOT_MODELS_DIR / "robots" / "rb10_1300e_RT.urdf"
