project (einit)

include (platform/image)
include (${KL_SDK_ROOT_PATH}/common/build-sd-image.cmake)

project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

find_package (dnet REQUIRED COMPONENTS ENTITY)

set (SECURITY_PSL_FILE    "src/security.psl.in")
set (CONNECTIONS_CFG_FILE "src/init.yaml.in")
set (HOSTFWD_FLAGS "$ENV{CONTROL_SYS_QEMU_HOSTFWD}")
if (NOT HOSTFWD_FLAGS OR HOSTFWD_FLAGS STREQUAL "")
    set (HOSTFWD_FLAGS ",hostfwd=tcp::28080-:28080,hostfwd=tcp::28081-:8081,hostfwd=tcp::28082-:8082,hostfwd=tcp::28083-:8083,hostfwd=tcp::28084-:8084,hostfwd=tcp::29090-:9090")
endif ()
set (EVENT_PORT "$ENV{CONTROL_SYS_EVENT_PORT}")
if (NOT EVENT_PORT OR EVENT_PORT STREQUAL "")
    set (EVENT_PORT "28090")
endif ()
set (EVENT_HOST "$ENV{CONTROL_SYS_EVENT_HOST}")
if (NOT EVENT_HOST OR EVENT_HOST STREQUAL "")
    set (EVENT_HOST "127.0.0.1")
endif ()

set (QEMU_FLAGS "--nographic -monitor none -chardev socket,id=eventbus,host=${EVENT_HOST},port=${EVENT_PORT},server=on,wait=off -serial chardev:eventbus -netdev user,id=hostnet0${HOSTFWD_FLAGS} -device virtio-net-device,netdev=hostnet0")
set (QEMU_ENV             "QEMU_AUDIO_DRV=none")

set (ENTITIES
     ControlSys
     InputGuard
     OutputController
     CardVerifier
     TransactionGenerator
     StatusVerifier
     AuthModule
     Journal
     UpdateLoader
     UpdateStorage
     UpdateVerifier
     UpdateInstaller
     Env
     ${dnet_ENTITY})

build_kos_hw_image (kos-image
                    EINIT_ENTITY EinitHw
                    CONNECTIONS_CFG ${CONNECTIONS_CFG_FILE}
                    SECURITY_PSL ${SECURITY_PSL_FILE}
                    IMAGE_FILES ${ENTITIES})

build_sd_image (sd-image
                KOS_IMAGE_TARGET kos-image)

build_kos_qemu_image (kos-qemu-image
                      EINIT_ENTITY EinitQeu
                      QEMU_FLAGS ${QEMU_FLAGS}
                      QEMU_ENV ${QEMU_ENV}
                      CONNECTIONS_CFG ${CONNECTIONS_CFG_FILE}
                      SECURITY_PSL ${SECURITY_PSL_FILE}
                      IMAGE_FILES ${ENTITIES})
