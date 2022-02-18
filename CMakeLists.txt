cmake_minimum_required(VERSION 3.21)
project(Velium)

set(CMAKE_CXX_STANDARD 23)

add_executable(Velium src/main.cpp src/graphics/window.cpp src/graphics/window.h)

target_link_libraries(Velium -lglfw -lglut -lGLEW -lGL -lGLU)
