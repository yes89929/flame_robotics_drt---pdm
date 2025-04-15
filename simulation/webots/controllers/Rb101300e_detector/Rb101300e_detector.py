from controller import Robot

robot = Robot()
timestep = int(robot.getBasicTimeStep())

# Joint 이름이 "joint1", "joint2" 라고 가정
joint_base = robot.getDevice("base")

joint_base.setPosition(1.57)  # 라디안 단위로 위치 설정 (ex: 90도)

while robot.step(timestep) != -1:
    pass