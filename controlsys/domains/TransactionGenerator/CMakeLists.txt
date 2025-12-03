project (TransactionGenerator)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (TransactionGenerator
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/tx.c
    ../../src/core/txn_builder.c)
add_dependencies (TransactionGenerator TransactionGeneratorInterface_idl TransactionGenerator_edl)

target_include_directories (TransactionGenerator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (TransactionGenerator PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/TransactionGenerator")
