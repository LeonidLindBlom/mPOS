project (Journal)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (Journal
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/journal.c)
add_dependencies (Journal JournalInterface_idl Journal_edl)

target_include_directories (Journal PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (Journal PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/Journal")
