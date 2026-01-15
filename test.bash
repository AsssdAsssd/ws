rm -rf build install log
colcon build --packages-select yolo_xy_pkg center_msg_pkg
source install/setup.bash
ros2 run yolo_xy_pkg yolo_xy_node --ros-args --params-file src/yolo_xy_pkg/config/para.yaml
