
add_executable(Game
        src/main.cpp src/debug/ImGuiLayer.cpp src/debug/ImGuiLayer.h)

target_link_libraries(Game Velium)

add_custom_target(copy_game_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/src/res
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/game
        COMMENT "Copying game resources into binary directory")

add_dependencies(Game copy_game_resources)
