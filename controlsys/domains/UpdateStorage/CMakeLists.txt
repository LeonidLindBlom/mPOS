project (UpdateStorage)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (UpdateStorage
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/update_storage.c)
add_dependencies (UpdateStorage UpdateStorageInterface_idl UpdateStorage_edl)

target_include_directories (UpdateStorage PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (UpdateStorage PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/UpdateStorage")
