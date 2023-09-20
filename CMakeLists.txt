cmake_minimum_required(VERSION 3.18)

project(ref_test)

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(lib)

add_executable(${PROJECT_NAME}.exe main.cpp)

target_link_libraries(${PROJECT_NAME}.exe transform_lib shape_lib)
