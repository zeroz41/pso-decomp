#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/AdxStreamLock.h"
#include "types.h"
#include "pso/unk/TLobby.h"

void TLobby::update_scroll_impl() {
    middleware_interrupt_lock_leave();
}

void TLobby__sub_803CE220(void) {
    middleware_interrupt_lock_enter();
}
