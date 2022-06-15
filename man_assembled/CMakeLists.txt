cmake_minimum_required(VERSION 2.8.3)

project(man_assembled)

find_package(catkin REQUIRED COMPONENTS
roscpp
std_msgs
  )

catkin_package()

find_package(roslaunch)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(joint_1     src/joint_1.cpp)
add_executable(joint_2     src/joint_2.cpp)
target_link_libraries(joint_1 ${catkin_LIBRARIES})
target_link_libraries(joint_2 ${catkin_LIBRARIES})
foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
