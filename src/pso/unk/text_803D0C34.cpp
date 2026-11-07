#include "types.h"
#include "pso/unk/text_803D0C34.h"

#include "stdarg.h"
#include "pso/system/GcciRequests.h"
#include "pso/unk/TLobby.h"
#include "string.h"
#include "pso/system/MiddlewareInterruptLock.h"

typedef void (*RecoveredCallback_c88e8900640a)(s32, u8 *);

extern s32 dvd_synchronous_read_enabled;
extern "C" {
int vsprintf(char *s, const char *fmt, va_list ap);
extern u8 log_printf_buffer[];
extern RecoveredCallback_c88e8900640a log_printf_callback;
extern s32 lobby_log_callback_arg;
void DCInvalidateRange(void *, u32);
s32 DVDGetTransferredSize(void *);
s32 DVDGetCommandBlockStatus(void *);
}
extern GcciStatus dvd_active_request;
extern GcciRequest dvd_request_table[40];
extern char dvd_default_path_buffer[0x100];
volatile s32 lbl_805D7610;
extern s32 fileio_error_callback;
extern s32 fileio_error_context;
extern void *dvd_file_driver_interface[];

void TLobby::poll_dvd_requests() {
    GcciRequest *r;
    s32 i;
    s32 n;
    s8 st;
    for (i = 0; i < 40; i++) {
        r = &dvd_request_table[i];
        if ((s32)r->active == 1 && (s32)r->state == 2) {
            r->status = DVDGetCommandBlockStatus(r->block);
            dvd_active_request.status = r->status;
            switch (r->status) {
            case -1:
            case 11:
                r->state = 3;
                dvd_active_request.state = 3;
                break;
            case 0:
                n = r->count * r->unit;
                DCInvalidateRange(r->buf, n);
                r->done = n;
                r->pos += r->count;
                r->state = dvd_active_request.state = 1;
                break;
            case 10:
                n = DVDGetTransferredSize(r->block);
                DCInvalidateRange(r->buf, n);
                r->done = r->unit * (n / r->unit);
                r->pos += n / r->unit;
                r->state = dvd_active_request.state = 0;
                break;
            }
        }
    }
}

void **initialize_dvd_file_driver(void) {
    lbl_805D7610 = lbl_805D7610;
    memset(dvd_default_path_buffer, 0, sizeof(dvd_default_path_buffer));
    fileio_error_callback = 0;
    fileio_error_context = 0;
    memset(&dvd_active_request, 0, sizeof(dvd_active_request));
    return dvd_file_driver_interface;
}

#pragma push
#pragma scheduling off
void set_dvd_synchronous_read_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    dvd_synchronous_read_enabled = arg3;
}
#pragma pop
extern "C" {

void TLobby::log_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf((char *)log_printf_buffer, fmt, ap);
    if (log_printf_callback != 0) {
        log_printf_callback(lobby_log_callback_arg, log_printf_buffer);
    }
}

GcciStatus dvd_active_request;
GcciRequest dvd_request_table[40];
char dvd_default_path_buffer[0x100] ATTRIBUTE_ALIGN(8);
}
u8 log_printf_buffer[0x100];

extern s32 lobby_log_callback_arg;

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
