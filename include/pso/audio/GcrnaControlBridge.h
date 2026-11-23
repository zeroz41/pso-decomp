#ifndef PSO_AUDIO_GCRNACONTROLBRIDGE_H
#define PSO_AUDIO_GCRNACONTROLBRIDGE_H

#include "types.h"

struct GcrnaLoopTarget {
    u8 pad_00[0x74];
    s32 loop_flag;
};

extern "C" {
void gcrna_set_loop_flag(GcrnaLoopTarget *target, s32 enabled);
void gcrna_interrupt_lock_enter(void);
void gcrna_interrupt_lock_leave(void);
}

#endif
