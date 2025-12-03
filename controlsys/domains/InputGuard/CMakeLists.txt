project (InputGuard)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (InputGuard
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/net_verifier.c
    ../../src/core/power_verifier.c
    ../../src/core/init_module.c)

add_dependencies (InputGuard InputGuardInterface_idl InputGuard_edl)

target_include_directories (InputGuard PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)

set_target_properties (InputGuard PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/InputGuard")
