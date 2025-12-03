project (UpdateVerifier)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (UpdateVerifier
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/update_verifier.c)
add_dependencies (UpdateVerifier UpdateVerifierInterface_idl UpdateVerifier_edl)

target_include_directories (UpdateVerifier PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (UpdateVerifier PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/UpdateVerifier")
