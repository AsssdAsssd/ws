cmake_minimum_required(VERSION 3.5)
project(yolo_xy_pkg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(ament_index_cpp REQUIRED)  # 新增这行

include_directories(
  include
${OpenCV_INCLUDE_DIRS})


set(PROJECT_SOURCES
    src/main.cpp
    src/inference.cpp
)


add_executable(yolo_xy_node ${PROJECT_SOURCES})
target_link_libraries(yolo_xy_node ${OpenCV_LIBS})

# 链接ROS2依赖（核心：ament_target_dependencies是ROS2的关键）
ament_target_dependencies(yolo_xy_node
  rclcpp
  std_msgs
  OpenCV
   ament_index_cpp
)

install(TARGETS yolo_xy_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
