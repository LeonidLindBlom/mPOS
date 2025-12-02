#include <env/env.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    printf("[ENV] Env service start\n");
    ENV_REGISTER_VARS("ControlSys", NULL);

    envServerRun();
    return EXIT_SUCCESS;
}
