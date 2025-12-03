project (UpdateLoader)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (UpdateLoader
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/update_loader.c)
add_dependencies (UpdateLoader UpdateLoaderInterface_idl UpdateLoader_edl)

target_include_directories (UpdateLoader PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (UpdateLoader PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/UpdateLoader")
