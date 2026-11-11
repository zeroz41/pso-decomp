// CRI adx_errs.c: ADX error reporting (ADXERR_ItoA2, ADXERR_CallErrFunc1/2, ADXERR_Init/Finish).
#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"

struct RecoveredGlobal_803C5850_lbl_80572020 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_803C588C_lbl_80572020 {
    s32 value;
    u8 remaining[0xFC];
};

typedef void (*RecoveredCallback_e2efd47cbcab)(s32, char *);

extern "C" {
s32 memset(void *, int, int);
extern RecoveredGlobal_803C5850_lbl_80572020 adx_error_message_buffer;
s32 lobby_error_callback;
s32 tlobby_error_callback_arg;
char *strncpy(char *dst, const char *src, u32 n);
void strncat(char *buf, s32 arg, s32 n);
void TLobby__sub_803D38B4(const char *fmt, ...);
s32 strlen(const char *);
char number_format_digit_buffer[0x20];
RecoveredGlobal_803C5850_lbl_80572020 adx_error_message_buffer;
const char lbl_805E0D28[2] = " ";
s32 set_callback_params__6TLobbyFll();
}

typedef void (*Callback_803C5744)(s32 ctx, char *msg);

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
    strncat(arg2, (s32)lbl_805E0D28, arg3 - strlen(arg2) - 1);
    num_to_str_803C526C(arg1, arg2 + strlen(arg2), 4 - strlen(arg2));
}

void TLobby::report_adx_error(const char *msg, s32 arg) {
    strncpy(((char *)&adx_error_message_buffer), msg, 0xFF);
    strncat(((char *)&adx_error_message_buffer), arg, 0xFF);
    if ((*(Callback_803C5744 *)&lobby_error_callback) != 0) {
        (*(Callback_803C5744 *)&lobby_error_callback)(tlobby_error_callback_arg, ((char *)&adx_error_message_buffer));
    }
    TLobby__sub_803D38B4(((char *)&adx_error_message_buffer));
}

void TLobby::notify_error(const char *arg0) {
    strncpy(((char *)&adx_error_message_buffer), arg0, 0xFF);
    if ((*(RecoveredCallback_e2efd47cbcab *)&lobby_error_callback) != NULL) {
        (*(RecoveredCallback_e2efd47cbcab *)&lobby_error_callback)(tlobby_error_callback_arg, ((char *)&adx_error_message_buffer));
    }
    TLobby__sub_803D38B4(((char *)&adx_error_message_buffer));
}

void TLobby::set_params(s32 arg0, s32 arg1) {
    lobby_error_callback = arg0;
    tlobby_error_callback_arg = arg1;
    set_callback_params__6TLobbyFll();
}

typedef char RecoveredGlobal_803C5850_lbl_80572020_size[sizeof(RecoveredGlobal_803C5850_lbl_80572020) == 0x100 ? 1 : -1];
void TLobby::clear_error_callback() {
    memset(&adx_error_message_buffer.value, 0, 0x100);
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}

typedef char RecoveredGlobal_803C588C_lbl_80572020_size[sizeof(RecoveredGlobal_803C588C_lbl_80572020) == 0x100 ? 1 : -1];
void TLobby::clear_error_callback_state() {
    memset((void *) (&(*(RecoveredGlobal_803C588C_lbl_80572020 *)&adx_error_message_buffer).value), 0, 0x100);
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}
