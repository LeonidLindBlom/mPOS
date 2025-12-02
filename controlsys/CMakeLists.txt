project (controlsys)

# Connect the CMake library named nk for working with the NK compiler.
include (platform/nk)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

# Generate the *.edl.h file using the NK compiler for the ControlSys program.
nk_build_edl_files (controlsys_edl_files NK_MODULE "controlsys" EDL "${CMAKE_SOURCE_DIR}/resources/edl/ControlSys.edl")

set (CONTROLSYS_SOURCES
     src/main.c
     src/core/log.c
     src/core/state_machine.c
     src/core/tx.c
     src/core/event_script.c
     src/core/event_channel.c
     src/core/card_verifier.c
     src/core/status_verifier.c
     src/core/net_verifier.c
     src/core/power_verifier.c
     src/core/init_module.c
     src/core/output_controller.c
     src/core/auth_module.c
     src/core/journal.c
     src/core/update_loader.c
     src/core/update_storage.c
     src/core/update_verifier.c
     src/core/update_installer.c
     src/core/txn_builder.c)

add_executable (ControlSys ${CONTROLSYS_SOURCES})
add_dependencies (ControlSys controlsys_edl_files)
target_include_directories (ControlSys PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties (ControlSys PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/ControlSys")

add_custom_target(pal-test0
    COMMAND ${CMAKE_COMMAND} -E env BUILD_DIR=${CMAKE_BINARY_DIR} bash ${CMAKE_SOURCE_DIR}/tools/run_pal_tests.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ControlSys
    COMMENT "Running PAL tests"
)

add_custom_target(pal-test-negative
    COMMAND ${CMAKE_COMMAND} -E env BUILD_DIR=${CMAKE_BINARY_DIR} bash ${CMAKE_SOURCE_DIR}/tools/run_pal_negative_tests.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ControlSys
    COMMENT "Running PAL negative tests"
)
