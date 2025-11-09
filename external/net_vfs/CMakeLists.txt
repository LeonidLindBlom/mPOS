project (net_vfs)

include (platform/nk)
find_package (vfs REQUIRED COMPONENTS SERVER_LIB IMPLEMENTATION_LIB)
find_package (dnet REQUIRED COMPONENTS IMPLEMENTATION_LIB)
find_package (blkdev REQUIRED COMPONENTS ENTITY)

project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (net_vfs_edl_files NK_MODULE "vfs" EDL "${CMAKE_CURRENT_SOURCE_DIR}/resources/edl/NetVfs.edl")

add_executable (NetVfs "src/net_vfs.c")
add_dependencies (NetVfs net_vfs_edl_files)
target_link_libraries (NetVfs ${vfs_SERVER_LIB}
                              ${vfs_IMPLEMENTATION_LIB}
                              ${dnet_IMPLEMENTATION_LIB})
set_target_properties (NetVfs PROPERTIES ${blkdev_ENTITY}_REPLACEMENT "")
