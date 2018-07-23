cmake_minimum_required(VERSION 3.10)
project(simulation_framework)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(simulation_framework main.cpp src/Initializer.cpp include/Initializer.h include/sf.h)
target_link_libraries(simulation_framework ${SDL2_LIBRARIES})
