cmake_minimum_required (VERSION 3.8)

# Add source files
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "*.c" "*.h" "*.cpp")
add_library(libs ${SOURCES})