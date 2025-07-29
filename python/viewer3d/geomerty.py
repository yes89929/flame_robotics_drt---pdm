
import open3d as o3d
import open3d.visualization.rendering as rendering
import numpy as np
from util.logger.console import ConsoleLogger

class GeometryAPI:
    def __init__(self):
        self.__console = ConsoleLogger.get_logger() # logger
        self.__geometry_container = {}

    def destory(self):
        self.__geometry_container.clear()


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

    def API_remove_geometry(self, vis, name:str) -> None:
        """ Remove geometry """
        self.__console.debug(f"Call API_remove_geometry : {name}")
        if name in self.__geometry_container.keys():
            vis.remove_geometry(self.__geometry_container[name])
            del self.__geometry_container[name]
        else:
            self.__console.debug(f"({self.__class__.__name__}) Nothing to remove the {name} in 3D window space")

    def API_clear_all_geometry(self, scene) -> None:
        self.__console.debug(f"Call API_clear_all_geometry")
        for geometry_name in self.__geometry_container.keys():
            self.__console.debug(f"Removing geometry: {geometry_name}")
            scene.scene.remove_geometry(geometry_name)
            del self.__geometry_container[geometry_name]
    
    def API_add_pcd(self, scene, name:str, path:str, pos:list=[0,0,0], ori:list=[0,0,0], color:list=[0,0,0]):
        """ add pcd geometry """
        self.__console.debug(f"Call API_add_pcd : {name} ({path})")
        obj = o3d.io.read_point_cloud(path)
        if not obj.has_points():
            self.__console.error(f"({self.__class__.__name__}) PCD has no points")
            return None
        
        R_matrix = obj.get_rotation_matrix_from_axis_angle(rotation=ori) # rotation
        obj.rotate(R=R_matrix)
        obj.translate(translation=pos, relative=False) # translation
        
        num_points = np.asarray(obj.points).shape[0]
        black_colors = np.tile(color, (num_points, 1))  # shape: (N, 3)
        obj.colors = o3d.utility.Vector3dVector(black_colors)

        if not name in self.__geometry_container.keys():
            mat = rendering.MaterialRecord()
            mat.shader = "defaultUnlit"
            scene.scene.add_geometry(name, obj, mat)
            self.__geometry_container[name] = obj
        else:
            print(f"[API_add_pcd] Already added {name} in geomery container")

    
