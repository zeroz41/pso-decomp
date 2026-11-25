#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/AdxStreamLock.h"
#include "types.h"
#include "pso/network/TLobby.h"

void adx_interrupt_lock_leave() {
    middleware_interrupt_lock_leave();
}

void TLobby__sub_803CE220(void) {
    middleware_interrupt_lock_enter();
}
