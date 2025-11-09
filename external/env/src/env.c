#include <env/env.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    printf("[ENV] Env service start\n");
    const char* NetVfsArgs[] = {
        "-l", "devfs /dev devfs 0"
    };
    const char* NetVfsEnvs[] = {
        "_VFS_NETWORK_BACKEND=server:VFS1",
        "_VFS_FILESYSTEM_BACKEND=server:VFS1"
    };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("NetVfs", NetVfsArgs, NetVfsEnvs);

    const char* ControlSysEnvs[] = {
        "_VFS_NETWORK_BACKEND=client:VFS1",
        "_VFS_FILESYSTEM_BACKEND=client:VFS1"
    };
    ENV_REGISTER_VARS("ControlSys", ControlSysEnvs);

    envServerRun();
    return EXIT_SUCCESS;
}
