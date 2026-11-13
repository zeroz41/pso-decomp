// CRI adx_errs.c: ADX error reporting (ADXERR_ItoA2, ADXERR_CallErrFunc1/2, ADXERR_Init/Finish).
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"

typedef void (*AdxErrorCallback)(s32 ctx, char *msg);

extern "C" {
AdxErrorCallback lobby_error_callback;
s32 tlobby_error_callback_arg;
void TLobby__sub_803D38B4(const char *fmt, ...);
char number_format_digit_buffer[0x20];
char adx_error_message_buffer[0x100];
const char lbl_805E0D28[2] = " ";
s32 set_callback_params__6TLobbyFll();
}

inline void num_to_str_803C526C(s32 v, char *out, s32 n) {
    s32 i;
    s32 len;
    for (i = 0; i < 32; i++) {
        out[i] = v % 10;
        v /= 10;
        if (v == 0) {
            out[i] = 0;
            break;
        }
    }
    s32 sl = strlen(number_format_digit_buffer);
    len = n - 1;
    if (sl < len) {
        len = sl;
    }
    for (i = 0; i < len; i++) {
        out[i] = number_format_digit_buffer[len - 1 - i];
    }
    out[i] = 0;
}

void TLobby::format_number_pair(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    num_to_str_803C526C(arg0, arg2, arg3);
    strncat(arg2, lbl_805E0D28, arg3 - strlen(arg2) - 1);
    num_to_str_803C526C(arg1, arg2 + strlen(arg2), 4 - strlen(arg2));
}

void TLobby::report_adx_error(const char *msg, const char *arg) {
    strncpy(adx_error_message_buffer, msg, 0xFF);
    strncat(adx_error_message_buffer, arg, 0xFF);
    if (lobby_error_callback != NULL) {
        lobby_error_callback(tlobby_error_callback_arg, adx_error_message_buffer);
    }
    TLobby__sub_803D38B4(adx_error_message_buffer);
}

void TLobby::notify_error(const char *arg0) {
    strncpy(adx_error_message_buffer, arg0, 0xFF);
    if (lobby_error_callback != NULL) {
        lobby_error_callback(tlobby_error_callback_arg, adx_error_message_buffer);
    }
    TLobby__sub_803D38B4(adx_error_message_buffer);
}

void TLobby::set_params(s32 arg0, s32 arg1) {
    lobby_error_callback = (AdxErrorCallback)arg0;
    tlobby_error_callback_arg = arg1;
    set_callback_params__6TLobbyFll();
}

void TLobby::clear_error_callback() {
    memset(adx_error_message_buffer, 0, sizeof(adx_error_message_buffer));
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}

void TLobby::clear_error_callback_state() {
    memset(adx_error_message_buffer, 0, sizeof(adx_error_message_buffer));
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}
