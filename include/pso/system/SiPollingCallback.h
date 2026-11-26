#ifndef PSO_SYSTEM_SIPOLLINGCALLBACK_H
#define PSO_SYSTEM_SIPOLLINGCALLBACK_H

#include "types.h"

void call_si_polling_callback(s32 unused, void *saved_context);
uaddr set_si_polling_callback(uaddr callback);

// --- C functions defined in SiPollingCallback.cpp ---
void call_si_polling_callback(s32 unused, void *saved_context);
uaddr set_si_polling_callback(uaddr callback);
// --- end of C functions

#endif
