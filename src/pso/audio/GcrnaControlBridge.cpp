#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/GcrnaControlBridge.h"
#include "types.h"

void gcrna_interrupt_lock_leave(void) {
    middleware_interrupt_lock_leave();
}

void gcrna_interrupt_lock_enter(void) {
    middleware_interrupt_lock_enter();
}

void gcrna_set_loop_flag(GcrnaLoopTarget *target, s32 enabled) {
    if (target != NULL) {
        target->loop_flag = enabled;
    }
}
