#include "controlsys/log.h"
#include "controlsys/state_machine.h"

int main(void) {
    log_ts("ControlSys: boot");
    sm_run_demo();
    return 0;
}
