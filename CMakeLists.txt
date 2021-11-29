cmake_minimum_required (VERSION 3.8)

# Libs
add_subdirectory ("vendor")

project("Morphine")

# Include projects
add_subdirectory ("Morphine")
add_subdirectory ("MorphineDebug")
add_subdirectory ("MorphineTool")