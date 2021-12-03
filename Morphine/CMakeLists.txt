cmake_minimum_required (VERSION 3.8)

project(Morphine)
message("Morphine")

set(CMAKE_CXX_STANDARD 14)

set(MORPHINE_REQUIRED_LIBS)			# Container for library dependencies (aka pissmoveapi or something lol)

# Add source files
file(GLOB_RECURSE SOURCES_API RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "src/*.c" "src/*.h" "src/*.cpp")
file(GLOB_RECURSE SOURCES_HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/Morphine "include/*.h")
add_library(Morphine STATIC ${SOURCES_API} ${SOURCES_HEADERS})

target_include_directories(Morphine
	PUBLIC ${MORPHINE_REQUIRED_LIBS}
	PUBLIC ${CMAKE_SOURCE_DIR}
	PUBLIC ${CMAKE_SOURCE_DIR}/Morphine/include
	PUBLIC ${CMAKE_SOURCE_DIR}/vendor/psmoveapi/include)

target_link_libraries(Morphine
	PRIVATE glm
	PUBLIC usb
	PUBLIC usbcompat
	PUBLIC psmoveapi)