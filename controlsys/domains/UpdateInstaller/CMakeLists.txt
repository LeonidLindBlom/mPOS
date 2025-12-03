project (UpdateInstaller)

include (platform/nk)
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (UpdateInstaller
    src/main.c
    ../../src/core/ipc_transport.c
    ../../src/core/log.c
    ../../src/core/update_installer.c)
add_dependencies (UpdateInstaller UpdateInstallerInterface_idl UpdateInstaller_edl)

target_include_directories (UpdateInstaller PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/_headers_
    ${CMAKE_BINARY_DIR}/_headers_/controlsys)
set_target_properties (UpdateInstaller PROPERTIES ENTITY_PATH "${CMAKE_BINARY_DIR}/controlsys/UpdateInstaller")
