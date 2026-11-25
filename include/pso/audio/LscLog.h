#ifndef PSO_AUDIO_LSC_LOG_H
#define PSO_AUDIO_LSC_LOG_H

#include "types.h"

extern "C" {
void lsc_log_printf(const char *fmt, ...);
void lsc_set_log_callback(uaddr callback_addr, s32 context);
}

#endif
