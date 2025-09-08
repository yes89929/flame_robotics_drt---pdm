import open3d as o3d
from open3d.cpu.pybind.geometry import PointCloud  # type: ignore
import numpy as np
from numpy.typing import NDArray
from CylinderFitting import fit_cylinder
from urdf_parser_py.urdf import URDF
from pathlib import Path
from scipy.spatial.transform import Rotation as R
import json


class EndEffectorPoseOptimizer:
    _scan_data: PointCloud

    # dda 정보
    _dda_geometry_file_path: Path
    _dda_geometry_scale: float
    _dda_mesh: o3d.geometry.TriangleMesh
    _dda_to_tcp_pose_xyz: list[float]
    _dda_to_tcp_pose_rpy: list[float]

    # rt 정보
    # 파이프 프로파일 정보
    __pipe_direction: np.ndarray
    __pipe_center: np.ndarray
    __pipe_radius: float

    def __init__(self):
        pass

    def load_scan_data(
        self,
        file_path: str,
        scale: float = 1.0,
    ):
        # 데이터 로드
        self._scan_data = o3d.io.read_point_cloud(file_path)  # type: ignore

        # 스케일
        self._scan_data.scale(scale, np.asarray([0.0, 0.0, 0.0]))  # type: ignore

    def calculate_DDA_pose_for_detecting_welding_point(
        self,
        target_point: tuple[float, float, float],  # x,y,z
        num_candidates: int = 8,
        distance: float = 0.3,
    ):
        """
        용접부 탐색을 위한 DDA 자세 후보 계산

        DDA 자세 후보 조건
            - TCP의 X축이 배관 중심을 향함
            - TCP의 Y축이 배관 길이 방향과 평행
            - 배관 표면에서 {distance} 거리에 위치
            - 배관과 충돌하지 않음

        :param target_point: 직배관 표면 위의 한 점
        :param num_candidates: 계산할 자세 후보의 수(자세별 간격은 등간격)

        :return:
            - JSON str: [ {dda: [x,y,z,r,p,y]}, ... ]\n
            - array: 각 행이 [x, y, z, r, p, y] 형태인 array(num_candidates, 6)
        """
        # DDA 자세 후보 생성------------------------------------------------------
        dda_tcp_pose_candidates = self.__calculate_dda_pose_candidate(
            np.asarray(target_point),
            self.__pipe_radius + distance,
            num_candidates,
        )

        # todo: 배관과 충돌하는 후보 제거------------------------------------------
        # 출력------------------------------------------------------------------
        # JSON 형태: [ {dda: [x,y,z,r,p,y]}, ... ]
        pose_list = []
        for row in dda_pose_candidates:
            pose_list.append({"dda": row.tolist()})
        return json.dumps(pose_list), dda_pose_candidates

    def __calculate_pipe_profile(
        self,
        target_point: tuple[float, float, float] | np.ndarray,  # x,y,z
    ) -> None:
        """
        직배관의 프로파일(방향벡터, 중심점, 반지름) 계산하여 멤버변수에 저장

        :param target_point: 직배관 표면 위의 한 점
        """
        # 검사 대상 주변 미소 점군 추출---------------------------------------------
        if not isinstance(target_point, np.ndarray):
            target_point = np.array(target_point)
        gap = np.array([0.05, 0.05, 0.05])  # 점군 밀도나 배관 직경에 따라 조절 필요
        min_bound = target_point - gap
        max_bound = target_point + gap
        box = o3d.geometry.AxisAlignedBoundingBox(min_bound, max_bound)  # type: ignore

        indices = box.get_point_indices_within_bounding_box(self._scan_data.points)
        selected_points = self._scan_data.select_by_index(indices)

        # 중앙 벡터 계산----------------------------------------------------------
        normals = np.asarray(selected_points.normals)
        x_m = np.median(normals[:, 0])
        y_m = np.median(normals[:, 1])
        z_m = np.median(normals[:, 2])
        normal_m = np.array([x_m, y_m, z_m])

        # 직경 추정--------------------------------------------------------------
        # 가늘고 긴 실린더 ROI 생성 후 내부 점 추출
        points_in_cylinder = self.__extract_points_in_cylinder(
            np.asarray(self._scan_data.points),
            target_point,
            normal_m * -1,  # 법선 벡터의 반대 방향
            radius=0.005,  # 배관 지름에 따라 조절 필요
            height=0.3,  # 배관 직경 및 브랜치 간 거리에 따라 조절 필요
        )

        # 중앙 벡터에 투영 후 군집화
        clusters = self.__cluster_points_along_line(
            points_in_cylinder,
            target_point,
            normal_m * -1,
            0.005,  # 점군 밀도에 따라 조절 필요
        )

        # 가장 먼 군집에서 가장 먼 점의 거리
        estimated_opposite_point = clusters[1][-1]
        estimated_center = (target_point + estimated_opposite_point) / 2
        estimated_radius = float(np.linalg.norm(estimated_opposite_point - estimated_center))

        # 배관 중심에서 배관 점군 추출----------------------------------------------
        # 배관 중심점에서 반지름 + α 범위 내의 점 추출
        points_in_sphere = self.__extract_points_in_sphere(
            np.asarray(self._scan_data.points),
            estimated_center,
            estimated_radius + 0.01,  # 배관 지름에 따라 조절 필요
        )

        # 실린더 피팅------------------------------------------------------------
        direction, center, radius, _ = fit_cylinder(points_in_sphere)

        # 멤버변수에 파이프 프로파일 저장-------------------------------------------
        self.__pipe_direction = direction
        self.__pipe_center = center
        self.__pipe_radius = radius

    def __calculate_dda_pose_candidate(
        self,
        point_on_pipe_surface: np.ndarray,
        radius: float,
        num_candidates: int,
    ):
        """
        배관 중심에서 radius만큼 떨어지고, 배관 중심을 바라보는 DDA의 위치 및 방향 후보 계산

        :param point_on_pipe_surface: 직배관 표면 위의 한 점
        :param radius: 직배관 중심으로 부터의 거리
        :param num_candidates: 계산할 자세 후보의 수(자세별 간격은 등간격)
        """

        # 동적 중심 계산: surface point를 pipe 축 위에 투영
        # pipe_direction 단위 벡터로 정규화
        direction_unit = self.__pipe_direction / np.linalg.norm(self.__pipe_direction)
        vec_to_surface = point_on_pipe_surface - self.__pipe_center
        proj_len = np.dot(vec_to_surface, direction_unit)
        center = self.__pipe_center + proj_len * direction_unit

        # 배관 축에 수직인 벡터 2개 구하기------------------------------------------
        # 배관 축에 평행하지 않는 기준 벡터 선택(x축 or y축)
        basis = np.array([1.0, 0.0, 0.0])
        if abs(np.dot(basis, self.__pipe_direction)) > 0.9:
            basis = np.array([0.0, 1.0, 0.0])

        # 수직 벡터 생성
        v1 = np.cross(self.__pipe_direction, basis)  # 배관 축에 수직인 벡터 v1
        v1 /= np.linalg.norm(v1)  # 길이로 나눠서 방향 벡터 계산
        v2 = np.cross(self.__pipe_direction, v1)  # 배관 축에 수직인 벡터 v2
        v2 /= np.linalg.norm(v2)

        # 위치 계산--------------------------------------------------------------
        # 반지름이 1인 원 위의 점 좌표 계산. 원 공식 (cos θ, sin θ)
        angles = 2 * np.pi * np.arange(num_candidates) / num_candidates
        cos_a = np.cos(angles)
        sin_a = np.sin(angles)

        # v1, v2는 배관 축에 수직인 벡터, 위에서 구한 원 위의 점 좌표를 원점이 (0,0,0)이고 v1, v2로 구성된 평면위로 이동
        offsets = np.outer(cos_a, v1) + np.outer(sin_a, v2)

        # 투영된 중심 주변 원형 궤도상 위치 계산
        positions = center + offsets * radius

        # 방향 자세--------------------------------------------------------------
        # x축 방향(배관 중심을 향함)
        x_axis = self.__pipe_center - positions
        x_norm = np.linalg.norm(x_axis, axis=1, keepdims=True)
        x_norm[x_norm < 1e-12] = 1.0
        x_axis = x_axis / x_norm

        # y축 방향(배관 축과 평행)
        y_unit = self.__pipe_direction / np.linalg.norm(self.__pipe_direction)
        y_axis = np.tile(y_unit, (num_candidates, 1))

        # z축 방향(x축과 y축에 의해 결정됨)
        z_axis = np.cross(x_axis, y_axis)
        z_norm = np.linalg.norm(z_axis, axis=1, keepdims=True)
        z_norm[z_norm < 1e-12] = 1.0
        z_axis = z_axis / z_norm

        # rpy 계산
        rot_mats = np.stack([x_axis, y_axis, z_axis], axis=2)
        rpy_array = R.from_matrix(rot_mats).as_euler("xyz", degrees=False)

        # 출력 포맷 설정----------------------------------------------------------
        # 각 행이 [x, y, z, roll, pitch, yaw] 형태인 numpy array of shape (num_candidates, 6)
        poses = np.hstack((positions, rpy_array))
        return poses

    @staticmethod
    def __extract_points_in_cylinder(
        points: np.ndarray,  # 점군
        cylinder_start_point: np.ndarray | tuple[float, float, float],  # 실린더 시작점
        cylinder_axis: np.ndarray | tuple[float, float, float],  # 실린더 축 (단위벡터)
        radius: float,  # 실린더 반지름
        height: float,  # 실린더 높이
    ) -> np.ndarray:
        # 실린더 축 단위 벡터로 정규화 및 시작점 배열로 변환
        axis = np.asarray(cylinder_axis)
        axis = axis / np.linalg.norm(axis)
        start = np.asarray(cylinder_start_point)
        # 직선에 점군 투영 (proj: 점에서 start까지의 축 성분 거리)
        vec = points - start
        proj = np.dot(vec, axis)

        # 실린더의 높이와 반지름에 대한 마스크 생성
        mask_height = (proj >= 0) & (proj <= height)
        radial = vec - np.outer(proj, axis)
        mask_radius = np.linalg.norm(radial, axis=1) <= radius
        mask = mask_height & mask_radius

        # 마스크에 해당하는 점군 반환
        return points[mask]

    @staticmethod
    def __extract_points_in_sphere(
        points: np.ndarray, sphere_center: np.ndarray | tuple, radius: float  # 점군  # 구의 중심점  # 구의 반지름
    ) -> np.ndarray:
        # 구에 점군 투영----------------------------------------------------------
        vec = points - sphere_center
        dists = np.linalg.norm(vec, axis=1)

        # 구의 반지름에 대한 마스크 생성--------------------------------------------
        mask = dists <= radius

        # 마스크에 해당하는 점군 반환-----------------------------------------------
        return points[mask]

    @staticmethod
    def __cluster_points_along_line(
        points: np.ndarray,  # 스캔 데이터의 일부
        origin_point_of_line: np.ndarray | tuple,  # 직선의 한 점
        direction: np.ndarray | tuple,  # 직선의 방향벡터 (단위벡터)
        # min_distance: float = 5,  # position으로부터 최소 거리,
        cluster_distance: float = 10,  # 군집화 기준 거리(투영값 기준)
    ) -> list[list[np.ndarray]]:
        # 군집화 사전 준비--------------------------------------------------------
        # 투영
        shifted_points = points - origin_point_of_line  # 투영하기 위해 원점으로 이동
        proj_points = np.dot(shifted_points, direction)  # 각 점의 position으로부터의 투영값(스칼라)
        # projected_points = np.outer(proj, direction) + position  # 직선 위 투영점

        # min_distance보다 가까운 점 제외
        # mask = proj_points > min_distance
        # proj_points = proj_points[mask]
        # points = points[mask]
        # projected_points = projected_points[mask]

        # proj 기준 정렬
        sort_idx = np.argsort(proj_points)
        proj_sorted = proj_points[sort_idx]
        points_sorted = points[sort_idx]

        # 군집화: proj 값이 cluster_distance 이내면 같은 군집-----------------------
        clusters: list[list[np.ndarray]] = []
        if len(points_sorted) == 0:
            return clusters
        # 첫번째 클러스터에 첫번째 점 추가
        current_cluster = [points_sorted[0]]

        for i in range(1, len(points_sorted)):
            # 이전 점과 거리가 기준 이하이면 클러스터에 추가
            if abs(proj_sorted[i] - proj_sorted[i - 1]) <= cluster_distance:
                current_cluster.append(points_sorted[i])

            # 이전 점과 거리가 기준 이상이면 새로운 클러스터 시작
            else:
                clusters.append(current_cluster)
                current_cluster = [points_sorted[i]]

        # 마지막 클러스터 추가
        if current_cluster:
            clusters.append(current_cluster)
        # ----------------------------------------------------------------------
        return clusters
