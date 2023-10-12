cmake_minimum_required(VERSION 3.18)

project(tests)

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -pthread")

add_library(shape_lib "../lib/shape/shape.cpp")
add_library(line_lib "../lib/line/line.cpp")
add_library(rectangle_lib "../lib/rectangle/rectangle.cpp")
add_library(parallelepiped_lib "../lib/parallelepiped/parallelepiped.cpp")

add_executable(${PROJECT_NAME}.exe main.cpp)

target_link_libraries(${PROJECT_NAME}.exe shape_lib line_lib rectangle_lib parallelepiped_lib gtest pthread)
