// CRI adx_errs.c: ADX error reporting (ADXERR_ItoA2, ADXERR_CallErrFunc1/2, ADXERR_Init/Finish).
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/CriSvm.h"

extern "C" {
AdxMessageCallback lobby_error_callback;
s32 tlobby_error_callback_arg;
char number_format_digit_buffer[0x20];
char adx_error_message_buffer[0x100];
const char adx_error_space_sep[2] = " ";
}

inline void adxerr_itoa2(s32 v, char *out, s32 n) {
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

void TLobby::format_number_pair(s32 first_val, s32 second_val, char *out_buf, s32 max_len) {
    adxerr_itoa2(first_val, out_buf, max_len);
    strncat(out_buf, adx_error_space_sep, max_len - strlen(out_buf) - 1);
    adxerr_itoa2(second_val, out_buf + strlen(out_buf), 4 - strlen(out_buf));
}

void TLobby::report_adx_error(const char *msg, const char *arg) {
    strncpy(adx_error_message_buffer, msg, 0xFF);
    strncat(adx_error_message_buffer, arg, 0xFF);
    if (lobby_error_callback != NULL) {
        lobby_error_callback(tlobby_error_callback_arg, adx_error_message_buffer);
    }
    svm_report_error(adx_error_message_buffer);
}

void TLobby::notify_error(const char *msg) {
    strncpy(adx_error_message_buffer, msg, 0xFF);
    if (lobby_error_callback != NULL) {
        lobby_error_callback(tlobby_error_callback_arg, adx_error_message_buffer);
    }
    svm_report_error(adx_error_message_buffer);
}

void TLobby::set_params(AdxMessageCallback callback, s32 context) {
    lobby_error_callback = callback;
    tlobby_error_callback_arg = context;
    TLobby::set_callback_params(callback, context);
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
