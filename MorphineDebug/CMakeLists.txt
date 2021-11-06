cmake_minimum_required (VERSION 3.8)

# Add source files
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/MorphineDebug "*.c" "*.h" "*.cpp")
add_executable(libs ${SOURCES})