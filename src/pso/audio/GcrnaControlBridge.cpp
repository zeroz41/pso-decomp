#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/GcrnaControlBridge.h"
#include "pso/audio/GcrnaStream.h"
#include "types.h"

void gcrna_interrupt_lock_leave(void) {
    middleware_interrupt_lock_leave();
}

void gcrna_interrupt_lock_enter(void) {
    middleware_interrupt_lock_enter();
}

void gcrna_set_loop_flag(GcrnaStream *stream, s32 enabled) {
    if (stream != NULL) {
        stream->frequency_mode = enabled;
    }
}
