cmake_minimum_required(VERSION 2.8.3)
project(print_container)

add_compile_options(-std=c++17)


find_package(catkin REQUIRED)


find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES print_container
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
# include
# ${catkin_INCLUDE_DIRS}
)

add_executable(test_main
  src/test_main.cpp
)
add_dependencies(test_main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(test_main
  ${catkin_LIBRARIES}
)