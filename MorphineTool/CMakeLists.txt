cmake_minimum_required (VERSION 3.8)

project(MorphineTool)

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCES_TOOL RELATIVE ${CMAKE_SOURCE_DIR}/MorphineConfig "src/*.c" "src/*.h" "src/*.cpp")
add_executable(MorphineTool ${SOURCES_TOOL})
target_link_libraries(MorphineTool Morphine)