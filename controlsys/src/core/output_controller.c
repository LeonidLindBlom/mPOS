#include "controlsys/services/output_controller.h"
#include "controlsys/log.h"

#include <stdio.h>

void output_controller_reset(void) {
    log_box("OutputCtrl", "reset display/printer state");
}

static const char* tx_amount(const struct TxContext* ctx, char* buf, size_t buf_sz) {
    if (!ctx) {
        snprintf(buf, buf_sz, "n/a");
    } else {
        snprintf(buf, buf_sz, "%d.%02d %s",
                 ctx->amount_cents / 100,
                 ctx->amount_cents % 100,
                 ctx->currency);
    }
    return buf;
}

void output_controller_invite_card(const struct TxContext* ctx) {
    char tmp[32];
    log_box("OutputCtrl", "DISPLAY\nПриложите карту (%s)", tx_amount(ctx, tmp, sizeof(tmp)));
}

void output_controller_request_pin(const struct TxContext* ctx) {
    log_box("OutputCtrl", "DISPLAY\nВведите ПИН-код\ntx=%s", ctx ? ctx->tx_id : "n/a");
}

void output_controller_show_status(const struct TxContext* ctx, const char* status) {
    log_box("OutputCtrl", "DISPLAY\n%s\ntx=%s",
            status ? status : "(null)",
            ctx ? ctx->tx_id : "n/a");
}

void output_controller_show_error(const char* detail) {
    log_box("OutputCtrl", "DISPLAY ERROR\n%s", detail ? detail : "unknown");
}

void output_controller_print_receipt(const struct TxContext* ctx, bool approved) {
    char tmp[32];
    log_box("OutputCtrl", "PRINTER\nчек %s (%s)",
            approved ? "APPROVED" : "DECLINED",
            tx_amount(ctx, tmp, sizeof(tmp)));
}
