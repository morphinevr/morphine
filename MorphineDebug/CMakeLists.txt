cmake_minimum_required (VERSION 3.8)

project(MorphineDebug)

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCES_DBG RELATIVE ${CMAKE_SOURCE_DIR}/MorphineDebug "src/*.c" "src/*.h" "src/*.cpp")
add_executable(MorphineDebug ${SOURCES_DBG})
target_link_libraries(MorphineDebug Morphine)