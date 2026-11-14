#include "types.h"
#include "stdarg.h"
#include "pso/unk/TLobby.h"
#include "pso/system/MiddlewareInterruptLock.h"

typedef void (*RecoveredCallback_c88e8900640a)(s32, u8 *);

extern "C" {
int vsprintf(char *s, const char *fmt, va_list ap);
}
RecoveredCallback_c88e8900640a log_printf_callback;
s32 lobby_log_callback_arg;
u8 log_printf_buffer[0x100];

void TLobby::log_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)log_printf_buffer, fmt, ap);
    if (log_printf_callback != 0) {
        log_printf_callback(lobby_log_callback_arg, log_printf_buffer);
    }
}

void TLobby::set_callback(u32 arg0, s32 arg1) {
    if (arg0 == 0U) {
        log_printf_callback = 0U;
        lobby_log_callback_arg = 0;
        return;
    }
    log_printf_callback = (RecoveredCallback_c88e8900640a)arg0;
    lobby_log_callback_arg = arg1;
}

void TLobby::notify_dvd_read() {
    middleware_interrupt_lock_leave();
}

void TLobby::enter_lock() {
    middleware_interrupt_lock_enter();
}
