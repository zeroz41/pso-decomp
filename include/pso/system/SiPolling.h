#ifndef PSO_SYSTEM_SIPOLLING_H
#define PSO_SYSTEM_SIPOLLING_H

#include "types.h"
#include <dolphin/os/OSInterrupt.h>

void call_si_polling_callback(__OSInterrupt interrupt, OSContext *saved_context);
uaddr set_si_polling_callback(uaddr callback);

#endif
