#include "pso/system/MiddlewareInterruptLock.h"
#include "types.h"
#include <dolphin/os/OSInterrupt.h>

extern volatile s32 middleware_interrupt_lock_depth;
extern s32 middleware_saved_interrupt_state;

void middleware_interrupt_lock_leave(void) {
    middleware_interrupt_lock_depth--;
    if (middleware_interrupt_lock_depth == 0) {
        OSRestoreInterrupts(middleware_saved_interrupt_state);
    }
}

void middleware_interrupt_lock_enter(void) {
    if ((s32) middleware_interrupt_lock_depth == 0) {
        middleware_saved_interrupt_state = OSDisableInterrupts();
    }
    middleware_interrupt_lock_depth += 1;
}

volatile s32 middleware_interrupt_lock_depth;
s32 middleware_saved_interrupt_state;
