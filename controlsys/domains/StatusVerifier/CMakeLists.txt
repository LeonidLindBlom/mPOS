project (StatusVerifier)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (StatusVerifier
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/tx.c
    ../../src/core/status_verifier.c)
add_dependencies (StatusVerifier StatusVerifierInterface_idl StatusVerifier_edl)

target_include_directories (StatusVerifier PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (StatusVerifier PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/StatusVerifier")
