#ifndef PSO_AUDIO_ADXSTREAMLOCK_H
#define PSO_AUDIO_ADXSTREAMLOCK_H

#include "types.h"

extern "C" {
void adx_interrupt_lock_enter(void);
}

extern "C" {
void adx_interrupt_lock_leave();
}

#endif
