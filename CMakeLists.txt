cmake_minimum_required(VERSION 3.21)
project(VelDev)

set(CMAKE_CXX_STANDARD 23)

set(VELIUM_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/Velium)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Velium)

include_directories(${VELIUM_INCLUDE_DIR}/src)
message(STATUS "test: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_custom_target(copy_engine_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${VELIUM_INCLUDE_DIR}/resources
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/engine
        COMMENT "Copying engine resources into binary directory")

add_dependencies(Velium copy_engine_resources)

add_subdirectory(Game)
