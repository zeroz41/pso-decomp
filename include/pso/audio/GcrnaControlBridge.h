#ifndef PSO_AUDIO_GCRNACONTROLBRIDGE_H
#define PSO_AUDIO_GCRNACONTROLBRIDGE_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void gcrna_set_loop_flag(GcrnaStream *stream, s32 enabled);
void gcrna_interrupt_lock_enter(void);
void gcrna_interrupt_lock_leave(void);
}

#endif
