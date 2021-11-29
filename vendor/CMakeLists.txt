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