#include "types.h"
#include <stdarg.h>
#include <stdio.h>
#include "pso/unk/TLobby.h"
#include "pso/system/MiddlewareInterruptLock.h"

typedef void (*LscLogCallback)(s32, u8 *);

LscLogCallback log_printf_callback;
s32 lobby_log_callback_arg;
u8 log_printf_buffer[0x100];

void TLobby::log_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)log_printf_buffer, fmt, ap);
    if (log_printf_callback != NULL) {
        log_printf_callback(lobby_log_callback_arg, log_printf_buffer);
    }
}

void TLobby::set_callback(uaddr callback_addr, s32 context) {
    if (callback_addr == 0U) {
        log_printf_callback = NULL;
        lobby_log_callback_arg = 0;
        return;
    }
    log_printf_callback = (LscLogCallback)callback_addr;
    lobby_log_callback_arg = context;
}

extern "C" {
void lsc_interrupt_lock_leave(void *) {
    middleware_interrupt_lock_leave();
}

void lsc_interrupt_lock_enter(void *) {
    middleware_interrupt_lock_enter();
}
}
