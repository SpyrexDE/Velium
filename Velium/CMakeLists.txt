cmake_minimum_required(VERSION 3.12)
project(Velium)

set(CMAKE_CXX_STANDARD 17)

add_library(Velium STATIC
        src/graphics/Window.cpp
        src/graphics/Window.h
        src/graphics/WindowManager.cpp
        src/graphics/WindowManager.h
        lib/imgui/imgui.cpp
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_tables.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui-SFML.cpp
        src/graphics/DebugGUIStyle.cpp
        src/Velium.h
        src/resources/ResHandler.cpp
        src/resources/ResHandler.h
)

target_include_directories(Velium PUBLIC lib/imgui/)

find_package(OpenGL REQUIRED)

if(APPLE)
  execute_process(COMMAND brew --prefix sfml OUTPUT_VARIABLE BREW_SFML_ROOT OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(SFML_DIR "${BREW_SFML_ROOT}/lib/cmake/SFML")
endif()

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

if(WIN32)
  target_link_libraries(Velium sfml-network sfml-graphics sfml-window sfml-system sfml-audio)
elseif(APPLE)
  target_link_libraries(Velium sfml-network sfml-graphics sfml-window sfml-system sfml-audio OpenGL::GL "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
elseif(UNIX AND NOT APPLE)
  target_link_libraries(Velium sfml-network sfml-graphics sfml-window sfml-system sfml-audio)
endif()
