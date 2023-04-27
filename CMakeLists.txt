cmake_minimum_required(VERSION 3.0.2)
project(imu2txt)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rosbag
    geometry_msgs
    sensor_msgs
    # core_msgs
    std_msgs
)

find_package(jsoncpp REQUIRED)

catkin_package(
    CATKIN_DEPENDS 
        roscpp 
        rosbag 
        geometry_msgs 
        sensor_msgs 
        std_msgs 
        # core_msgs
)

file(GLOB SOURCES
     "classes/*.cpp"
     "classes/*.h"
     "parameters/*.cpp"
     "parameters/*.h")

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/classes
    ${PROJECT_SOURCE_DIR}/parameters
)

add_executable(${PROJECT_NAME}_node 
               src/imu2txt_node.cpp
               ${SOURCES})

target_link_libraries(${PROJECT_NAME}_node
                      ${catkin_LIBRARIES}
                      jsoncpp)