cmake_minimum_required(VERSION 3.10)
project(simulation_framework)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(simulation_framework
        include/display/Rect.h
        include/display/RGBA.h
        include/display/Renderer.h
        include/display/Window.h
        include/event/Event.h
        include/event/EventDispatcher.h
        include/event/EventType.h
        include/Initializer.h
        include/Simulation.h

        src/display/Rect.cpp
        src/display/Renderer.cpp
        src/display/RGBA.cpp
        src/display/Window.cpp
        src/event/Event.cpp
        src/event/EventDispatcher.cpp
        src/Initializer.cpp
        src/Simulation.cpp
        src/main.cpp)
target_link_libraries(simulation_framework ${SDL2_LIBRARIES})
