cmake_minimum_required (VERSION 3.8)

# Libs

message("Setting up 3rd Party Libraries...")

message("glew")
set(glew-cmake_BUILD_SHARED OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glew)

message("glfw")
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glfw)

message("glm")
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glm)

# PSMoveAPI
message("PSMoveAPI")

set(PSMOVE_USE_PS3EYE_DRIVER 0)

set(PSMOVE_BUILD_JAVA_BINDINGS 0)
set(PSMOVE_BUILD_CSHARP_BINDINGS 0)
set(PSMOVE_BUILD_PROCESSING_BINDINGS 0)
set(PSMOVE_BUILD_PYTHON_BINDINGS 0)

set(PSMOVE_BUILD_EXAMPLES 0)
set(PSMOVE_BUILD_OPENGL_EXAMPLES 0)
set(PSMOVE_BUILD_TESTS 0)
set(PSMOVE_BUILD_NAVCON_TEST 0)

# set(PSMOVE_API_EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/vendor/psmoveapi/external)
# set(LIBUSB_DIR ${PSMOVE_API_EXTERNAL_DIR}/libusb-1.0)
# set(OPENCV_DIR ${PSMOVE_API_EXTERNAL_DIR}/opencv)

add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/psmoveapi)

adjust_bin_paths(psmoveapi)
adjust_bin_paths(psmove)
adjust_bin_paths(usb)
adjust_bin_paths(usbcompat)

# Configure dependencies
message("Configuring dependencies...")

# PSMoveAPI
set_target_properties (psmoveapi PROPERTIES FOLDER vendor/psmoveapi)
set_target_properties (psmove PROPERTIES FOLDER vendor/psmoveapi)
set_target_properties (usb PROPERTIES FOLDER vendor/psmoveapi)
set_target_properties (usbcompat PROPERTIES FOLDER vendor/psmoveapi)

# GLFW
set_target_properties (glfw PROPERTIES FOLDER vendor/GLFW3)
set_target_properties (uninstall PROPERTIES FOLDER vendor/GLFW3)
set_target_properties (update_mappings PROPERTIES FOLDER vendor/GLFW3)

# GLM
set_target_properties (glm PROPERTIES FOLDER vendor)

# GLEW
set_target_properties (libglew_static PROPERTIES FOLDER vendor/glew)

# ImGUI
project (ImGUI)
message ("ImGUI")

set (CMAKE_CXX_STANDARD 14)

set (IMGUI_FILES
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp

	${CMAKE_SOURCE_DIR}/vendor/imgui/misc/cpp/imgui_stdlib.cpp
#	${CMAKE_SOURCE_DIR}/vendor/imgui/misc/freetype/imgui_freetype.cpp
	
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx10.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx11.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl2.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_win32.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx12.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx9.cpp

	)

set (IMGUI_HEADERS
	${CMAKE_SOURCE_DIR}/vendor/imgui/imconfig.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_internal.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/imstb_textedit.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/imstb_rectpack.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/imstb_truetype.h

	${CMAKE_SOURCE_DIR}/vendor/imgui/misc/cpp/imgui_stdlib.h
#	${CMAKE_SOURCE_DIR}/vendor/imgui/misc/freetype/imgui_freetype.h
	
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_allegro5.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glut.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_sdl.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_marmalade.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx10.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_metal.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_vulkan.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx11.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl2.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_wgpu.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx12.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_win32.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_dx9.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3_loader.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.h
	${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_osx.h


	)

add_library (ImGUI STATIC ${IMGUI_FILES} ${IMGUI_HEADERS})
target_include_directories (ImGUI
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/imgui)
	
target_link_libraries(ImGUI
	PRIVATE glfw)

set_target_properties (ImGUI PROPERTIES FOLDER vendor/imgui)