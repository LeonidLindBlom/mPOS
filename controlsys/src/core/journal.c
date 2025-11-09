#include "controlsys/services/journal.h"
#include "controlsys/log.h"

bool journal_append(const JournalRecord* rec) {
    if (!rec || !rec->tx_id) {
        log_ts("Journal: invalid record");
        return false;
    }
    log_ts("Journal: tx=%s amount=%d.%02d %s result=%s",
           rec->tx_id,
           rec->amount_cents / 100,
           rec->amount_cents % 100,
           rec->currency ? rec->currency : "RUB",
           rec->approved ? "APPROVED" : "DECLINED");
    return true;
}
