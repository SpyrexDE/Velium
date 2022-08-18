
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
        src/graphics/DebugGUIStyle.cpp src/Velium.h src/resources/ResHandler.cpp src/resources/ResHandler.h)

target_include_directories(Velium PUBLIC lib/imgui/ lib/sfml/include/)

find_package(OpenGL REQUIRED)

# find SFML 2.5
set(SFML_DIR lib/sfml/lib/cmake/SFML/)
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

if(WIN32 OR WIN64)
  target_link_libraries(Velium opengl32 sfml-network sfml-graphics sfml-window sfml-system sfml-audio)
else()
  target_link_libraries(Velium -lGL -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lX11)
endif()