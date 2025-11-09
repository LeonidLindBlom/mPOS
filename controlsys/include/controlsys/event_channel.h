#ifndef CONTROLSYS_EVENT_CHANNEL_H
#define CONTROLSYS_EVENT_CHANNEL_H

#include <stdbool.h>
#include "controlsys/events.h"

void ctl_event_channel_init(void);
bool ctl_event_channel_next(CtlEvent* evt);

#endif /* CONTROLSYS_EVENT_CHANNEL_H */
