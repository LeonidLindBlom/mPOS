project (OutputController)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (OutputController
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/output_controller.c)

add_dependencies (OutputController OutputControllerInterface_idl OutputController_edl)

target_include_directories (OutputController PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (OutputController PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/OutputController")
