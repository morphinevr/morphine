cmake_minimum_required (VERSION 3.8)

project(Morphine)

set(CMAKE_CXX_STANDARD 14)

set(MORPHINE_REQUIRED_LIBS)			# Container for library dependencies

# Add source files
file(GLOB_RECURSE SOURCES_API RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "src/*.c" "src/*.h" "src/*.cpp")
file(GLOB_RECURSE SOURCES_HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "*include/.h")
add_library(Morphine STATIC ${SOURCES_API})
include_directories(${CMAKE_BINARY_DIR} ${SOURCES_HEADERS})