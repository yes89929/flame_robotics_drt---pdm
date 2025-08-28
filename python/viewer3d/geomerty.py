
import open3d as o3d
import open3d.visualization.rendering as rendering
import numpy as np
from util.logger.console import ConsoleLogger

console = ConsoleLogger.get_logger() # logger


class geometryAPI:
    def __init__(self):
        self.__console = ConsoleLogger.get_logger() # logger
        self.__geometry_container = {}
        self.__geometry_container_original = {}  # Store original geometry data for transform reset

    def destory(self):
        self.__geometry_container.clear()
        self.__geometry_container_original.clear()


    def API_add_coord_frame(self, vis, name:str, pos:list=[0,0,0], ori:list=[0,0,0], size:float=0.1) -> None:
        """ add coordinate frame """
        self.__console.debug(f"Call API_add_coord_frame : {name}")
        obj = o3d.geometry.TriangleMesh.create_coordinate_frame(size=size, origin=pos)
        R_matrix = obj.get_rotation_matrix_from_axis_angle(rotation=ori) # rotation
        obj.rotate(R=R_matrix)
        obj.translate(translation=pos, relative=False)
        if not name in self.__geometry_container.keys():
            self.__geometry_container[name] = obj
            vis.add_geometry(obj, reset_bounding_box=True)
        else:
            self.__console.debug(f"({self.__class__.__name__}) Already added {name} in 3D window space")

    def API_remove_geometry(self, scene, name:str) -> None:
        """ Remove geometry """
        self.__console.debug(f"Call API_remove_geometry : {name}")
        if name in self.__geometry_container.keys():
            scene.scene.remove_geometry(name)
            del self.__geometry_container[name]
            # Also remove original data
            if name in self.__geometry_container_original:
                del self.__geometry_container_original[name]
        else:
            self.__console.debug(f"({self.__class__.__name__}) Nothing to remove the {name} in 3D window space")

    def API_clear_all_geometry(self, scene) -> None:
        self.__console.debug(f"Call API_clear_all_geometry")
        geometry_names = list(self.__geometry_container.keys())  # Create a copy of keys
        for geometry_name in geometry_names:
            self.__console.debug(f"Removing geometry: {geometry_name}")
            scene.scene.remove_geometry(geometry_name)
            del self.__geometry_container[geometry_name]
            # Also clear original data
            if geometry_name in self.__geometry_container_original:
                del self.__geometry_container_original[geometry_name]
    
    def API_add_pcd(self, scene, name:str, path:str, pos:list=[0,0,0], ori:list=[0,0,0], color:list=[0,0,0], point_size:float=1.0):
        """ add pcd geometry """
        self.__console.debug(f"Call API_add_pcd : {name} ({path})")
        obj = o3d.io.read_point_cloud(path)
        if not obj.has_points():
            self.__console.error(f"({self.__class__.__name__}) PCD has no points")
            return None
        
        # Store original data before any transforms
        original_points = np.asarray(obj.points).copy()
        
        R_matrix = obj.get_rotation_matrix_from_axis_angle(rotation=ori) # rotation
        obj.rotate(R=R_matrix)
        obj.translate(translation=pos, relative=False) # translation
        
        num_points = np.asarray(obj.points).shape[0]
        black_colors = np.tile(color, (num_points, 1))  # shape: (N, 3)
        obj.colors = o3d.utility.Vector3dVector(black_colors)

        if not name in self.__geometry_container.keys():
            mat = rendering.MaterialRecord()
            mat.shader = "defaultUnlit"
            mat.point_size = point_size  # Set point size
            scene.scene.add_geometry(name, obj, mat)
            self.__geometry_container[name] = obj
            
            # Store original data for efficient transform updates
            self.__geometry_container_original[name] = {
                'path': path,
                'original_points': original_points,
                'color': color,
                'point_size': point_size,
                'type': 'pcd'
            }
        else:
            print(f"[API_add_pcd] Already added {name} in geomery container")

    def API_update_geometry_transform(self, scene, name: str, pos: list = [0, 0, 0], ori: list = [0, 0, 0]):
        """Update geometry transform (position and orientation) efficiently"""
        self.__console.debug(f"Call API_update_geometry_transform : {name}")
        
        if name not in self.__geometry_container:
            self.__console.warning(f"Geometry {name} not found in container")
            return
        
        if name not in self.__geometry_container_original:
            self.__console.warning(f"Original data for {name} not found, using fallback method")
            self._fallback_transform_update(scene, name, pos, ori)
            return
        
        obj = self.__geometry_container[name]
        original_data = self.__geometry_container_original[name]
        
        # Create transformation matrix for absolute world coordinates
        transform_matrix = np.eye(4)
        
        # Apply rotation (absolute orientation in world space)
        R_matrix = o3d.geometry.get_rotation_matrix_from_axis_angle(ori)
        transform_matrix[:3, :3] = R_matrix
        
        # Apply translation (absolute position in world space)
        transform_matrix[:3, 3] = pos
        
        # Use set_geometry_transform for efficient update without remove/re-add
        scene.scene.set_geometry_transform(name, transform_matrix)
        
        self.__console.debug(f"Efficiently updated geometry {name} transform: pos={pos}, ori={ori}")
    
    def _fallback_transform_update(self, scene, name: str, pos: list, ori: list):
        """Fallback method for geometry without original data"""
        # Create transformation matrix for absolute world coordinates (fallback method)
        transform_matrix = np.eye(4)
        
        # Apply rotation (absolute orientation in world space)
        R_matrix = o3d.geometry.get_rotation_matrix_from_axis_angle(ori)
        transform_matrix[:3, :3] = R_matrix
        
        # Apply translation (absolute position in world space)
        transform_matrix[:3, 3] = pos
        
        # Use set_geometry_transform even for fallback
        scene.scene.set_geometry_transform(name, transform_matrix)
        self.__console.debug(f"Updated geometry {name} using fallback method with set_geometry_transform")

    def API_add_urdf(self, scene, name: str, robot, base_pos: list = [0, 0, 0], base_ori: list = [0, 0, 0], joint_config: dict = None):
        """Add URDF robot model to scene"""
        self.__console.debug(f"Call API_add_urdf : {name}")
        
        try:
            # Import required modules
            from scipy.spatial import transform as rotations
            from scipy.spatial import transform as transformations
            
            # Create base transformation matrix
            base_p = np.array(base_pos)
            base_R = rotations.Rotation.from_euler('xyz', base_ori).as_matrix()
            base_T = np.eye(4)
            base_T[:3, :3] = base_R
            base_T[:3, 3] = base_p
            
            # Use provided joint configuration or default to None (zero angles)
            cfg = joint_config if joint_config is not None else None
            
            # Compute forward kinematics
            fk = robot.visual_trimesh_fk(cfg=cfg)
            
            # Store URDF model info for potential updates
            self.__geometry_container[name] = {
                'type': 'urdf',
                'robot': robot,
                'base_transform': base_T,
                'joint_config': cfg if cfg else {},
                'mesh_count': len(fk)
            }
            
            # Add each mesh to the scene
            mesh_count = 1
            for tm, T in fk.items():
                tm_copy = tm.copy()
                tm_copy.apply_transform(base_T @ T)
                
                # Convert trimesh to Open3D mesh
                o3d_mesh = o3d.geometry.TriangleMesh()
                o3d_mesh.vertices = o3d.utility.Vector3dVector(tm_copy.vertices)
                o3d_mesh.triangles = o3d.utility.Vector3iVector(tm_copy.faces)
                o3d_mesh.compute_vertex_normals()
                
                # Create material
                material = rendering.MaterialRecord()
                material.shader = "defaultLit"
                
                # Add to scene with unique name
                mesh_name = f"{name}_{mesh_count}"
                scene.scene.add_geometry(mesh_name, o3d_mesh, material)
                mesh_count += 1
            
            self.__console.debug(f"Added URDF {name} with {len(fk)} meshes to scene")
            
        except Exception as e:
            self.__console.error(f"Failed to add URDF {name}: {e}")

    
