#ifndef CONTROLSYS_SERVICES_OUTPUT_CONTROLLER_H
#define CONTROLSYS_SERVICES_OUTPUT_CONTROLLER_H

#include <stdbool.h>
#include "controlsys/tx.h"

void output_controller_reset(void);
void output_controller_invite_card(const TxContext* ctx);
void output_controller_request_pin(const TxContext* ctx);
void output_controller_show_status(const TxContext* ctx, const char* status);
void output_controller_show_error(const char* detail);
void output_controller_print_receipt(const TxContext* ctx, bool approved);

#endif /* CONTROLSYS_SERVICES_OUTPUT_CONTROLLER_H */
