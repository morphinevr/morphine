cmake_minimum_required (VERSION 3.8)

project(MorphineDebug)

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCES_DBG RELATIVE ${CMAKE_SOURCE_DIR}/MorphineDebug "src/*.c" "src/*.h" "src/*.cpp")
add_executable(MorphineDebug ${SOURCES_DBG})

target_include_directories(MorphineDebug
	PUBLIC ${MORPHINE_REQUIRED_LIBS}
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glew/include
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glfw/include)

target_link_libraries(MorphineDebug
	Morphine
	glew
	GLFW)