rm -rf build install log
colcon build
source install/setup.bash
ros2 run yolo_xy_pkg yolo_xy_node --ros-args --params-file src/yolo_xy_pkg/config/para.yaml
