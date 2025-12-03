project (CardVerifier)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (CardVerifier
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/card_verifier.c)
add_dependencies (CardVerifier CardVerifierInterface_idl CardVerifier_edl)

target_include_directories (CardVerifier PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (CardVerifier PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/CardVerifier")
