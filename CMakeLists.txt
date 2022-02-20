cmake_minimum_required(VERSION 3.21)
project(Velium)

set(CMAKE_CXX_STANDARD 23)

add_executable(Velium src/main.cpp
        src/graphics/Window.cpp
        src/graphics/Window.h
        src/graphics/WindowManager.cpp
        src/graphics/WindowManager.h
        lib/imgui/imgui.cpp
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_tables.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui-SFML.cpp
        )

target_include_directories(Velium PUBLIC lib/imgui/)

target_link_libraries(Velium -lGL -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
