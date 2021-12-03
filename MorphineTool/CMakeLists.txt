cmake_minimum_required (VERSION 3.8)

project(MorphineTool)
message("MorphineTool")

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCES_TOOL RELATIVE ${CMAKE_SOURCE_DIR}/MorphineConfig "src/*.c" "src/*.h" "src/*.cpp")
add_executable(MorphineTool ${SOURCES_TOOL})

target_include_directories(MorphineTool
	PUBLIC ${MORPHINE_REQUIRED_LIBS}
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glew/include
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glfw/include)

target_link_libraries(MorphineTool
	PRIVATE Morphine
	PRIVATE libglew_static
	PRIVATE glfw
	PRIVATE ImGUI)

adjust_bin_paths(MorphineTool)