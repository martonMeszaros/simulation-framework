cmake_minimum_required(VERSION 3.10)
project(simulation_framework)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES
        src/display/Rect.cpp
        src/display/Renderer.cpp
        src/display/RGBA.cpp
        src/display/Window.cpp
        src/event/Event.cpp
        src/event/EventDispatcher.cpp
        src/Initializer.cpp
        src/Simulation.cpp
        src/simulation_framework.cpp include/enums/SubSystems.h)

add_executable(simulation_framework ${SOURCE_FILES})
target_link_libraries(simulation_framework ${SDL2_LIBRARIES})
