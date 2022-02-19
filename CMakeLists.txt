cmake_minimum_required(VERSION 3.21)
project(Velium)

set(CMAKE_CXX_STANDARD 23)

add_executable(Velium src/main.cpp src/graphics/Window.cpp src/graphics/Window.h src/graphics/WindowManager.cpp src/graphics/WindowManager.h)

target_link_libraries(Velium -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio)
