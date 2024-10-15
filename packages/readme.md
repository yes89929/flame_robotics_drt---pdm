# Setup ROS2+MoveIt Environments

## (develop) Create Packages
```
$ source /opt/ros/humble/setup.bash
$ cd <package path to generate>/src
$ ros2 pkg create dual_rb20_description
$ ros2 pkg create dual_rb10_description
$ ros2 pkg create dual_rb10_moveit
```

## build package
```
(venv) $ pip install catkin_pkg
workspace $ colcon build
```

## (develop) Moveit Configuration with Moveit Setup Assistant
```
$ ros2 launch moveit_setup_assistant setup_assistant.launch.py
```