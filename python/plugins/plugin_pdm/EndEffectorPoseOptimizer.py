import open3d as o3d
from open3d.cpu.pybind.geometry import PointCloud  # type: ignore
import numpy as np
from numpy.typing import NDArray
from CylinderFitting import fit_cylinder
from urdf_parser_py.urdf import URDF
from pathlib import Path
from scipy.spatial.transform import Rotation as R
import json
import copy
from typing import Any


class EndEffectorPoseOptimizer:
    _scan_data: PointCloud

    # dda 정보
    __dda_mesh: o3d.geometry.TriangleMesh
    __dda_invers_transform_mat: np.ndarray

    # rt 정보
    __rt_mesh: o3d.geometry.TriangleMesh
    __rt_invers_transform_mat: np.ndarray

    # 파이프 프로파일 정보
    __pipe_direction: np.ndarray
    __pipe_center: np.ndarray
    __pipe_radius: float

    # 디버깅용
    __is_debug_mode: bool
    debuging_info: dict[str, Any]

    def __init__(self, debug_mode: bool = False):
        self.__is_debug_mode = debug_mode

    def load_scan_data(
        self,
        file_path: str,
        scale: float = 1.0,
    ):
        # 데이터 로드
        self._scan_data = o3d.io.read_point_cloud(file_path)  # type: ignore

        # 스케일
        self._scan_data.scale(scale, np.asarray([0.0, 0.0, 0.0]))  # type: ignore

    def load_DDA_from_urdf(
        self,
        file_path: str,
    ):
        self.__dda_mesh, self.__dda_invers_transform_mat = self.__extract_tcp_and_end(
            file_path,
            "dda_link_end",
            "dda_joint_tcp",
        )

    def load_RT_from_urdf(
        self,
        file_path: str,
    ):
        self.__rt_mesh, self.__rt_invers_transform_mat = self.__extract_tcp_and_end(
            file_path,
            "rt_link_end",
            "rt_joint_tcp",
        )

    def __extract_tcp_and_end(
        self,
        file_path: str,
        end_link_name: str,
        tcp_joint_name: str,
    ):
        # urdf 파일 로드---------------------------------------------------------
        urdf: URDF = URDF.from_xml_file(file_path)

        # 엔드이펙터 형상 추출-----------------------------------------------------
        # 형상 파일 경로
        end_geometry_file_path = urdf.link_map[end_link_name].collision.geometry.filename
        end_geometry_file_path = (Path(file_path) / Path(end_geometry_file_path.replace("file://", "../"))).resolve()
        link_mesh = o3d.io.read_triangle_mesh(end_geometry_file_path)

        # 형상 스케일
        end_geomtry_scale = urdf.link_map[end_link_name].collision.geometry.scale
        if isinstance(end_geomtry_scale, list):
            end_geomtry_scale = float(end_geomtry_scale[0])
        elif isinstance(end_geomtry_scale, (int, float)):
            end_geomtry_scale = float(end_geomtry_scale)
        else:
            raise ValueError("엔드이펙터 형상 스케일 정보가 잘못되었습니다.")

        link_mesh = link_mesh.scale(end_geomtry_scale, np.zeros(3, dtype=np.float64))  # type: ignore

        # 자세 변환
        end_pose_xyz = urdf.link_map[end_link_name].collision.origin.xyz
        end_pose_rpy = urdf.link_map[end_link_name].collision.origin.rpy
        T = np.eye(4)
        T[:3, :3] = R.from_euler("xyz", end_pose_rpy).as_matrix()
        T[:3, 3] = end_pose_xyz
        link_mesh = link_mesh.transform(T)  # type: ignore

        # tcp와 엔드이펙터 형상 위치관계 정보 추출-----------------------------------
        # end to tcp 정보 추출
        end_to_tcp_relative_pose_xyz = urdf.joint_map[tcp_joint_name].origin.xyz
        end_to_tcp_relative_pose_rpy = urdf.joint_map[tcp_joint_name].origin.rpy

        # tcp to end 변환 행렬 계산
        end_to_tcp_relative_pose_T = np.eye(4)
        end_to_tcp_relative_pose_T[:3, :3] = R.from_euler("xyz", end_to_tcp_relative_pose_rpy).as_matrix()
        end_to_tcp_relative_pose_T[:3, 3] = end_to_tcp_relative_pose_xyz
        tcp_to_origin_mat = np.linalg.inv(end_to_tcp_relative_pose_T)

        # ----------------------------------------------------------------------
        return link_mesh, tcp_to_origin_mat

    def calculate_DDA_pose_for_detecting_welding_point(
        self,
        target_point: tuple[float, float, float],  # x,y,z
        num_candidates: int = 8,
        distance: float = 0.3,
    ):
        """용접부 탐색을 위한 DDA 자세 후보 계산.

        DDA 자세 후보 조건:
            - TCP의 X축이 배관 중심을 향함
            - TCP의 Y축이 배관 길이 방향과 평행
            - 배관 표면에서 distance 거리에 위치
            - 배관과 충돌하지 않음

        Args:
            target_point: 직배관 표면 위의 한 점.
            num_candidates: 계산할 자세 후보의 수(자세별 간격은 등간격). Defaults to 8.
            distance: 배관 표면으로부터의 거리. Defaults to 0.3.

        Returns:
            tuple: DDA 자세 후보를 3가지 형태로 반환.
                - JSON str: [{dda: [x,y,z,r,p,y]}, ...]
                - filtered array: 충돌 체크를 통과한 자세 후보들
                - all candidates array: 모든 자세 후보들
        """
        # DDA 자세 후보 생성------------------------------------------------------
        dda_tcp_pose_candidates = self.__calculate_dda_pose_candidate(
            np.asarray(target_point),
            self.__pipe_radius + distance,
            num_candidates,
        )

        # 배관과 충돌하는 후보 제거------------------------------------------------
        mask = []
        for i in range(len(dda_tcp_pose_candidates)):
            is_collision = self.__check_collision(
                self.__dda_mesh,
                dda_tcp_pose_candidates[i],
                self.__dda_invers_transform_mat,
            )
            mask.append(not is_collision)

        dda_pose_candidates_filtered = dda_tcp_pose_candidates[mask]

        # 출력------------------------------------------------------------------
        # JSON 형태: [ {dda: [x,y,z,r,p,y]}, ... ]
        pose_list = []
        for row in dda_pose_candidates_filtered:
            pose_list.append({"dda": row.tolist()})

        dda_candidates_filtered_json = json.dumps(pose_list)

        return dda_candidates_filtered_json, dda_pose_candidates_filtered, dda_tcp_pose_candidates

    def __rotate_dda_pose_around_pipe_axis(
        self,
        dda_pose: np.ndarray,
        rotation_angle_deg: float = 90.0,
    ) -> np.ndarray:
        """DDA 자세를 배관 중심축 기준으로 회전시킴.

        Args:
            dda_pose: 원본 DDA 자세 [x, y, z, roll, pitch, yaw].
            rotation_angle_deg: 회전 각도 (도). Defaults to 90.0.

        Returns:
            np.ndarray: 회전된 DDA 자세 [x, y, z, roll, pitch, yaw].
        """
        # 배관 중심축 단위 벡터
        pipe_axis_unit = self.__pipe_direction / np.linalg.norm(self.__pipe_direction)

        # DDA 위치를 배관 중심축 기준으로 회전
        dda_position = dda_pose[:3]

        # 배관 축 위에 DDA 위치를 투영하여 회전 중심 계산
        vec_to_dda = dda_position - self.__pipe_center
        proj_len = np.dot(vec_to_dda, pipe_axis_unit)
        rotation_center = self.__pipe_center + proj_len * pipe_axis_unit

        # 회전 중심에서 DDA까지의 벡터
        radius_vector = dda_position - rotation_center

        # 로드리게스 회전 공식으로 위치 회전
        cos_angle = np.cos(np.radians(rotation_angle_deg))
        sin_angle = np.sin(np.radians(rotation_angle_deg))

        k_cross_v = np.cross(pipe_axis_unit, radius_vector)
        k_dot_v = np.dot(pipe_axis_unit, radius_vector)

        rotated_radius_vector = (
            radius_vector * cos_angle + k_cross_v * sin_angle + pipe_axis_unit * k_dot_v * (1 - cos_angle)
        )

        rotated_position = rotation_center + rotated_radius_vector

        # DDA 자세(회전)도 같은 각도만큼 회전
        original_rotation = R.from_euler("xyz", dda_pose[3:])
        axis_rotation = R.from_rotvec(pipe_axis_unit * np.radians(rotation_angle_deg))
        rotated_rotation = axis_rotation * original_rotation
        rotated_rpy = rotated_rotation.as_euler("xyz")

        return np.hstack([rotated_position, rotated_rpy])

    def __calculate_rt_pose_for_angle(
        self,
        dda_tcp_pose: np.ndarray,
        angle_deg: float,
        distance_from_dda_to_rt: float,
    ) -> np.ndarray:
        """주어진 DDA 자세와 각도에 대해 RT 자세 계산.

        Args:
            dda_tcp_pose: DDA TCP 자세 [x, y, z, roll, pitch, yaw].
            angle_deg: RT 배치 각도 (도).
            distance_from_dda_to_rt: DDA TCP와 RT TCP 사이의 거리 (m).

        Returns:
            np.ndarray: RT TCP 자세 [x, y, z, roll, pitch, yaw].
        """
        # DDA TCP 좌표계에서 회전 행렬 추출
        dda_rot_matrix = R.from_euler("xyz", dda_tcp_pose[3:]).as_matrix()
        dda_x_axis = dda_rot_matrix[:, 0]  # DDA TCP X축
        dda_z_axis = dda_rot_matrix[:, 2]  # DDA TCP Z축

        # DDA TCP의 Z축 단위 벡터 (XY 평면의 법선)
        dda_z_axis_unit = dda_z_axis / np.linalg.norm(dda_z_axis)

        # 로드리게스 회전 공식으로 DDA X축을 DDA Z축 주위로 angle_deg만큼 회전
        cos_angle = np.cos(np.radians(angle_deg))
        sin_angle = np.sin(np.radians(angle_deg))

        k_cross_v = np.cross(dda_z_axis_unit, dda_x_axis)
        k_dot_v = np.dot(dda_z_axis_unit, dda_x_axis)

        rt_y_direction = dda_x_axis * cos_angle + k_cross_v * sin_angle + dda_z_axis_unit * k_dot_v * (1 - cos_angle)

        # RT TCP 위치: DDA TCP에서 RT Y축 방향으로 distance_from_dda_to_rt만큼 떨어진 위치
        rt_position = dda_tcp_pose[:3] + rt_y_direction * distance_from_dda_to_rt

        # RT TCP 방향 계산
        # RT TCP X축: RT TCP에서 DDA TCP를 바라보는 방향
        rt_to_dda_vector = dda_tcp_pose[:3] - rt_position
        rt_x_axis = rt_to_dda_vector / np.linalg.norm(rt_to_dda_vector)

        # RT TCP Y축: 위에서 계산한 rt_y_direction 사용
        rt_y_axis = rt_y_direction / np.linalg.norm(rt_y_direction)

        # RT TCP Z축: X축과 Y축의 외적으로 계산하여 올바른 직교 좌표계 구성
        rt_z_axis = np.cross(rt_x_axis, rt_y_axis)
        rt_z_axis = rt_z_axis / np.linalg.norm(rt_z_axis)

        # Y축 재계산 (Z축과 X축의 외적으로 정확한 직교 좌표계 구성)
        rt_y_axis = np.cross(rt_z_axis, rt_x_axis)
        rt_y_axis = rt_y_axis / np.linalg.norm(rt_y_axis)

        # RT TCP 회전 행렬 생성
        rt_rot_matrix = np.column_stack([rt_x_axis, rt_y_axis, rt_z_axis])

        # 회전 행렬의 유효성 검사
        det = np.linalg.det(rt_rot_matrix)
        if det <= 0:
            # 좌수 좌표계인 경우 Z축의 방향을 뒤집어서 우수 좌표계로 변경
            rt_z_axis = -rt_z_axis
            rt_rot_matrix = np.column_stack([rt_x_axis, rt_y_axis, rt_z_axis])

        rt_rpy = R.from_matrix(rt_rot_matrix).as_euler("xyz")

        # RT TCP 자세 [x, y, z, roll, pitch, yaw]
        return np.hstack([rt_position, rt_rpy])

    def calculate_DDA_RT_pose_for_taking_xray(
        self,
        target_point: tuple[float, float, float] | np.ndarray,
        num_candidates: int,
        distance_from_dda_to_surface: float,
        distance_from_dda_to_rt: float,
        angle_of_rt: float,
    ):
        """x-ray 촬영을 위한 DDA, RT 자세 후보 계산.

        DDA 자세 후보 조건:
            - DDA TCP의 X축이 배관 중심을 향함
            - DDA TCP의 Y축이 배관 길이 방향과 평행
            - 배관 표면에서 distance_from_dda_to_surface 거리에 위치
            - 배관과 충돌하지 않음
            - 원본 자세(0도)와 배관 중심축 기준 90도 회전 자세 모두 검사

        RT 자세 후보 조건:
            - RT TCP의 X축이 DDA TCP의 중심을 향함
            - DDA TCP와 RT TCP 간 거리는 distance_from_dda_to_rt
            - DDA TCP의 XY 평면과 RT TCP의 XY 평면이 일치
            - DDA TCP의 XY 평면에서 DDA TCP의 X축과 RT TCP의 Y축이 ±angle_of_rt만큼 벌어짐
            - 배관과 충돌하지 않음

        Args:
            target_point: 직배관 표면 위의 한 점.
            num_candidates: 계산할 자세 후보의 수(자세별 간격은 등간격).
            distance_from_dda_to_surface: DDA TCP와 배관 표면 사이의 거리 (m).
            distance_from_dda_to_rt: DDA TCP와 RT TCP 사이의 거리 (m).
            angle_of_rt: RT TCP X축과 DDA TCP X축 사이의 각도 (degree).

        Returns:
            tuple: DDA-RT 자세 그룹을 2가지 형태로 반환.
                - JSON str 형식: 그룹화된 DDA-RT 자세 쌍
                - dict 형식: 그룹화된 DDA-RT 자세 쌍
        """

        # DDA 자세 후보 생성------------------------------------------------------
        dda_base_candidates = self.__calculate_dda_pose_candidate(
            np.asarray(target_point),
            self.__pipe_radius + distance_from_dda_to_surface,
            num_candidates,
        )

        # 배관과 충돌하지 않는 DDA 기본 자세만 필터링---------------------------------
        valid_base_dda_poses = []
        for dda_pose in dda_base_candidates:
            is_collision = self.__check_collision(
                self.__dda_mesh,
                dda_pose,
                self.__dda_invers_transform_mat,
            )
            if not is_collision:
                valid_base_dda_poses.append(dda_pose)

        # DDA-RT 자세 그룹 생성---------------------------------------------------
        pose_groups = []

        for base_dda_pose in valid_base_dda_poses:
            group_data = {}

            # 0도 (원본 자세) 처리
            group_0_data = self.__process_dda_rt_combination(base_dda_pose, angle_of_rt, distance_from_dda_to_rt)
            if group_0_data:
                group_data["0"] = group_0_data

            # 90도 회전 자세 처리
            rotated_dda_pose = self.__rotate_dda_pose_around_pipe_axis(base_dda_pose, 90.0)

            # 90도 회전된 DDA 자세의 충돌 검사
            is_rotated_dda_collision = self.__check_collision(
                self.__dda_mesh,
                rotated_dda_pose,
                self.__dda_invers_transform_mat,
            )

            if not is_rotated_dda_collision:
                group_90_data = self.__process_dda_rt_combination(
                    rotated_dda_pose, angle_of_rt, distance_from_dda_to_rt
                )
                if group_90_data:
                    group_data["90"] = group_90_data

            # "0"과 "90" 모두 유효할 때만 그룹에 추가
            if "0" in group_data and "90" in group_data:
                pose_groups.append(group_data)

        # JSON 형태 출력 생성-----------------------------------------------------
        pose_groups_json = json.dumps(pose_groups)

        return pose_groups_json, pose_groups

    def __process_dda_rt_combination(
        self,
        dda_pose: np.ndarray,
        angle_of_rt: float,
        distance_from_dda_to_rt: float,
    ) -> dict[str, list[float]] | None:
        """DDA 자세에 대해 RT1(+angle), RT2(-angle) 조합 처리.

        Args:
            dda_pose: DDA TCP 자세.
            angle_of_rt: RT 배치 각도.
            distance_from_dda_to_rt: DDA-RT 간 거리.

        Returns:
            dict | None: 유효한 RT 자세가 있으면 DDA-RT 조합 딕셔너리, 없으면 None.
        """
        result = {"DDA": dda_pose.tolist()}

        # RT1 (+angle) 계산 및 충돌 검사
        rt1_pose = self.__calculate_rt_pose_for_angle(dda_pose, angle_of_rt, distance_from_dda_to_rt)
        is_rt1_collision = self.__check_collision(
            self.__rt_mesh,
            rt1_pose,
            self.__rt_invers_transform_mat,
        )

        if not is_rt1_collision:
            result["RT1"] = rt1_pose.tolist()

        # RT2 (-angle) 계산 및 충돌 검사
        rt2_pose = self.__calculate_rt_pose_for_angle(dda_pose, -angle_of_rt, distance_from_dda_to_rt)
        is_rt2_collision = self.__check_collision(
            self.__rt_mesh,
            rt2_pose,
            self.__rt_invers_transform_mat,
        )

        if not is_rt2_collision:
            result["RT2"] = rt2_pose.tolist()

        # RT1이나 RT2 중 하나라도 유효하면 결과 반환
        if "RT1" in result or "RT2" in result:
            return result
        else:
            return None

    def calculate_pipe_profile(
        self,
        target_point: tuple[float, float, float] | np.ndarray,  # x,y,z
        sampling_size_for_calculating_normal: float = 0.01,
        radius_offset_for_sampling_points_in_sphere: float = 0.003,
    ):
        """직배관의 프로파일(방향벡터, 중심점, 반지름) 계산하여 멤버변수에 저장.

        Args:
            target_point: 직배관 표면 위의 한 점.
            sampling_size_for_calculating_normal: 법선 계산을 위한 샘플링 크기. Defaults to 0.01.
            radius_offset_for_sampling_points_in_sphere: 구 샘플링을 위한 반지름 오프셋. Defaults to 0.003.
        """

        if self.__is_debug_mode:
            self.debuging_info = {}

        # 검사 대상 주변 미소 점군 추출---------------------------------------------
        if not isinstance(target_point, np.ndarray):
            target_point = np.array(target_point)
        gap = np.full(3, sampling_size_for_calculating_normal, dtype=np.float64)
        min_bound = target_point - gap
        max_bound = target_point + gap
        box = o3d.geometry.AxisAlignedBoundingBox(min_bound, max_bound)  # type: ignore

        if self.__is_debug_mode:
            self.debuging_info["sampling_box"] = [min_bound, max_bound]

        indices = box.get_point_indices_within_bounding_box(self._scan_data.points)
        selected_points = self._scan_data.select_by_index(indices)
        if len(selected_points.points) == 0:
            selected_points = None
            raise RuntimeError(
                "target_point 주변에 점군이 없습니다. target_pont 또는 sampling_size_for_calculating_normal 값을 조절하세요."
            )

        if self.__is_debug_mode:
            self.debuging_info["selected_points"] = selected_points

        # 중앙 벡터 계산----------------------------------------------------------
        normals = np.asarray(selected_points.normals)
        x_m = np.median(normals[:, 0])
        y_m = np.median(normals[:, 1])
        z_m = np.median(normals[:, 2])
        normal_m = np.array([x_m, y_m, z_m])

        if self.__is_debug_mode:
            self.debuging_info["normal_m"] = normal_m

        # 직경 추정--------------------------------------------------------------
        # 가늘고 긴 실린더 ROI 생성 후 내부 점 추출
        points_in_cylinder = self.__extract_points_in_cylinder(
            np.asarray(self._scan_data.points),
            target_point,
            normal_m * -1,  # 법선 벡터의 반대 방향
            0.005,  # 배관 지름에 따라 조절 필요
            (-0.1, 0.3),  # 배관 직경 및 브랜치 간 거리에 따라 조절 필요
        )

        if self.__is_debug_mode:
            self.debuging_info["points_in_cylinder"] = points_in_cylinder

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

        if self.__is_debug_mode:
            self.debuging_info["estimated_center"] = estimated_center
            self.debuging_info["estimated_radius"] = estimated_radius

        # 배관 중심에서 배관 점군 추출----------------------------------------------
        # 배관 중심점에서 반지름 + α 범위 내의 점 추출
        points_in_sphere = self.__extract_points_in_sphere(
            np.asarray(self._scan_data.points),
            estimated_center,
            estimated_radius + radius_offset_for_sampling_points_in_sphere,  # 배관 지름에 따라 조절 필요
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
        """배관 중심에서 radius만큼 떨어지고, 배관 중심을 바라보는 DDA의 위치 및 방향 후보 계산.

        Args:
            point_on_pipe_surface: 직배관 표면 위의 한 점.
            radius: 직배관 중심으로부터의 거리.
            num_candidates: 계산할 자세 후보의 수(자세별 간격은 등간격).

        Returns:
            np.ndarray: 각 행이 [x, y, z, roll, pitch, yaw] 형태인 numpy array of shape (num_candidates, 6).
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
        # y축 방향(배관 축과 평행)
        y_unit = self.__pipe_direction / np.linalg.norm(self.__pipe_direction)
        y_axis = np.tile(y_unit, (num_candidates, 1))

        # x축 방향(DDA TCP 위치에서 배관 중심을 바라보는 방향, 배관 방향과 수직)
        x_axis = center - positions  # center는 배관 축 위의 투영된 중심점
        x_norm = np.linalg.norm(x_axis, axis=1, keepdims=True)
        x_norm[x_norm < 1e-12] = 1.0
        x_axis = x_axis / x_norm

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
        height_range: list[float] | tuple[float, float],  # 실린더 높이 범위 [min, max]
    ) -> np.ndarray:
        """실린더 내부에 있는 점들을 추출.

        Args:
            points: 점군.
            cylinder_start_point: 실린더 시작점.
            cylinder_axis: 실린더 축 (단위벡터).
            radius: 실린더 반지름.
            height_range: 실린더 높이 범위 [min, max].

        Returns:
            np.ndarray: 실린더 내부에 포함되는 점들.
        """
        # 실린더 축 단위 벡터로 정규화 및 시작점 배열로 변환
        axis = np.asarray(cylinder_axis)
        axis = axis / np.linalg.norm(axis)
        start = np.asarray(cylinder_start_point)
        # 직선에 점군 투영 (proj: 점에서 start까지의 축 성분 거리)
        vec = points - start
        proj = np.dot(vec, axis)

        # 실린더의 높이와 반지름에 대한 마스크 생성
        mask_height = (proj >= height_range[0]) & (proj <= height_range[1])
        radial = vec - np.outer(proj, axis)
        mask_radius = np.linalg.norm(radial, axis=1) <= radius
        mask = mask_height & mask_radius

        # 마스크에 해당하는 점군 반환
        return points[mask]

    @staticmethod
    def __extract_points_in_sphere(
        points: np.ndarray, sphere_center: np.ndarray | tuple, radius: float  # 점군  # 구의 중심점  # 구의 반지름
    ) -> np.ndarray:
        """구 내부에 있는 점들을 추출.

        Args:
            points: 점군.
            sphere_center: 구의 중심점.
            radius: 구의 반지름.

        Returns:
            np.ndarray: 구 내부에 포함되는 점들.
        """
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
        """직선을 따라 점들을 거리 기준으로 군집화.

        Args:
            points: 스캔 데이터의 일부.
            origin_point_of_line: 직선의 한 점.
            direction: 직선의 방향벡터 (단위벡터).
            cluster_distance: 군집화 기준 거리(투영값 기준). Defaults to 10.

        Returns:
            list[list[np.ndarray]]: 군집화된 점들의 리스트.
        """
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

    def __check_collision(
        self,
        link_model: o3d.geometry.TriangleMesh,
        tcp_pose: np.ndarray,
        tcp_to_link_pose_T: np.ndarray,
        margin: float = 0.05,
        sample_count: int = 5000,
    ) -> bool:
        """메쉬(변환된)와 로드된 스캔 점군 데이터 간 충돌 여부 검사.

        Args:
            link_model: 검사할 TriangleMesh.
            tcp_pose: TCP 자세 array(6) [x, y, z, roll, pitch, yaw] (라디안).
            tcp_to_link_pose_T: TCP에서 링크로의 변환 행렬.
            margin: 충돌 검사 마진. Defaults to 0.05.
            sample_count: 메쉬 샘플링 점 수. Defaults to 5000.

        Returns:
            bool: 충돌 시 True.
        """
        # 엔드이펙터를 검사 대상 위치로 이동-----------------------------------------
        tcp_pose_T = np.eye(4)
        tcp_pose_T[:3, :3] = R.from_euler("xyz", tcp_pose[3:]).as_matrix()
        tcp_pose_T[:3, 3] = tcp_pose[:3]

        link_pose_T = tcp_pose_T @ tcp_to_link_pose_T

        mesh_copy = copy.deepcopy(link_model)
        mesh_copy.transform(link_pose_T)  # type: ignore

        # 연산량을 줄이기 위해 스캔 데이터 필터링-------------------------------------
        # 엔드이펙터의 바운딩 박스 계산
        aabb = mesh_copy.get_axis_aligned_bounding_box()

        # 바운딩 박스에 마진 추가
        margin_vec = np.array([margin, margin, margin])
        min_b = aabb.min_bound - margin_vec
        max_b = aabb.max_bound + margin_vec
        crop_box = o3d.geometry.AxisAlignedBoundingBox(min_b, max_b)  # type: ignore

        # 바운딩 박스 내 점 추출
        idx = crop_box.get_point_indices_within_bounding_box(self._scan_data.points)
        if not idx:
            return False
        sub_pcd = self._scan_data.select_by_index(idx)

        # 엔드이펙터 표면 점 추출--------------------------------------------------
        mesh_pcd = mesh_copy.sample_points_uniformly(number_of_points=sample_count)

        # 점들간 거리 계산으로 충돌 여부 확인----------------------------------------
        distances = sub_pcd.compute_point_cloud_distance(mesh_pcd)
        threshold = 0.001
        return any(d <= threshold for d in distances)
