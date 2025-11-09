#ifndef CONTROLSYS_SERVICES_TXN_BUILDER_H
#define CONTROLSYS_SERVICES_TXN_BUILDER_H

#include <stdbool.h>
#include "controlsys/tx.h"

bool txn_builder_build(const TxContext* ctx, bool approved);

#endif /* CONTROLSYS_SERVICES_TXN_BUILDER_H */
