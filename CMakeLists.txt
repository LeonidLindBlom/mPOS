cmake_minimum_required (VERSION 3.12)

project (controlsys_project)

# Initialize the CMake library for the KasperskyOS SDK.
include (platform)
# Statically link executable files.
initialize_platform (FORCE_STATIC)

# Connect the CMake library named doxygen for documentation of source texts.
include (platform/doxygen)
add_project_documentation_main_target ()

add_subdirectory (controlsys)
add_subdirectory (einit)
