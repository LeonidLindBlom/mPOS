#ifndef CONTROLSYS_SERVICES_JOURNAL_H
#define CONTROLSYS_SERVICES_JOURNAL_H

#include <stdbool.h>

typedef struct {
    const char* tx_id;
    int amount_cents;
    const char* currency;
    bool approved;
} JournalRecord;

bool journal_append(const JournalRecord* rec);

#endif /* CONTROLSYS_SERVICES_JOURNAL_H */
