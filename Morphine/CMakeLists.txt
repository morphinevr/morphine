cmake_minimum_required (VERSION 3.8)

project(Morphine)

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCES_API RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "*.c" "*.h" "*.cpp")
add_library(Morphine STATIC ${SOURCES_API})