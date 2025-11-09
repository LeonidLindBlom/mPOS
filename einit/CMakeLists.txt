project (einit)

include (platform/image)
include (${KL_SDK_ROOT_PATH}/common/build-sd-image.cmake)

project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

set (SECURITY_PSL_FILE    "src/security.psl.in")
set (CONNECTIONS_CFG_FILE "src/init.yaml.in")
set (HOSTFWD_FLAGS "$ENV{CONTROL_SYS_QEMU_HOSTFWD}")
set (QEMU_FLAGS           "--nographic -monitor none -netdev user,id=hostnet0${HOSTFWD_FLAGS} -device virtio-net-device,netdev=hostnet0")
set (QEMU_ENV             "QEMU_AUDIO_DRV=none")

set (ENTITIES ControlSys)

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
