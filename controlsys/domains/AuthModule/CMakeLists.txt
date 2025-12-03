project (AuthModule)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (AuthModule
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/auth_module.c)
add_dependencies (AuthModule AuthInterface_idl AuthModule_edl)

target_include_directories (AuthModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (AuthModule PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/AuthModule")
