project (controlsys)

# Connect the CMake library named nk for working with the NK compiler.
include (platform/nk)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

# Build IDL interfaces for individual domains.
set (CONTROLSYS_IDL_SOURCES
     InputGuardInterface
     OutputControllerInterface
     CardVerifierInterface
     TransactionGeneratorInterface
     StatusVerifierInterface
     AuthInterface
     JournalInterface
     UpdateLoaderInterface
     UpdateStorageInterface
     UpdateVerifierInterface
     UpdateInstallerInterface)

set (CONTROLSYS_IDL_TARGETS)
foreach (IDL_NAME ${CONTROLSYS_IDL_SOURCES})
    nk_build_idl_files (${IDL_NAME}_idl NK_MODULE "controlsys" IDL "${CMAKE_SOURCE_DIR}/resources/idl/${IDL_NAME}.idl")
    list (APPEND CONTROLSYS_IDL_TARGETS ${IDL_NAME}_idl)
endforeach ()

# Generate the *.edl.h file using the NK compiler for the ControlSys program.
nk_build_edl_files (controlsys_edl_files NK_MODULE "controlsys" EDL "${CMAKE_SOURCE_DIR}/resources/edl/ControlSys.edl")

set (CONTROLSYS_EDL_TARGETS)
macro(add_controlsys_edl target_name edl_file idl_dep)
    nk_build_edl_files (${target_name}_edl NK_MODULE "controlsys" EDL "${CMAKE_SOURCE_DIR}/resources/edl/${edl_file}.edl" IDL_TARGET ${idl_dep}_idl)
    list (APPEND CONTROLSYS_EDL_TARGETS ${target_name}_edl)
endmacro()

add_controlsys_edl (InputGuard InputGuard InputGuardInterface)
add_controlsys_edl (OutputController OutputController OutputControllerInterface)
add_controlsys_edl (CardVerifier CardVerifier CardVerifierInterface)
add_controlsys_edl (TransactionGenerator TransactionGenerator TransactionGeneratorInterface)
add_controlsys_edl (StatusVerifier StatusVerifier StatusVerifierInterface)
add_controlsys_edl (AuthModule AuthModule AuthInterface)
add_controlsys_edl (Journal Journal JournalInterface)
add_controlsys_edl (UpdateLoader UpdateLoader UpdateLoaderInterface)
add_controlsys_edl (UpdateStorage UpdateStorage UpdateStorageInterface)
add_controlsys_edl (UpdateVerifier UpdateVerifier UpdateVerifierInterface)
add_controlsys_edl (UpdateInstaller UpdateInstaller UpdateInstallerInterface)

set (CONTROLSYS_SOURCES
     src/main.c
     src/core/log.c
     src/core/state_machine.c
     src/core/tx.c
     src/core/event_script.c
     src/core/event_channel.c
     src/core/clients.c
     src/core/ipc_transport.c)

set (GENERATED_HEADERS_DIR "${CMAKE_BINARY_DIR}/_headers_")

add_executable (ControlSys ${CONTROLSYS_SOURCES})
add_dependencies (ControlSys controlsys_edl_files ${CONTROLSYS_IDL_TARGETS} ${CONTROLSYS_EDL_TARGETS})
target_include_directories (ControlSys PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${GENERATED_HEADERS_DIR}"
    "${GENERATED_HEADERS_DIR}/controlsys")
set_target_properties (ControlSys PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/ControlSys")

add_subdirectory (domains/InputGuard)
add_subdirectory (domains/OutputController)
add_subdirectory (domains/CardVerifier)
add_subdirectory (domains/TransactionGenerator)
add_subdirectory (domains/StatusVerifier)
add_subdirectory (domains/AuthModule)
add_subdirectory (domains/Journal)
add_subdirectory (domains/UpdateLoader)
add_subdirectory (domains/UpdateStorage)
add_subdirectory (domains/UpdateVerifier)
add_subdirectory (domains/UpdateInstaller)

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
