#include "types.h"
#include "pso/unk/text_803D31A4.h"

struct RecoveredGlobal_803D31A4_lbl_8058B6B8 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_803D31A4_lbl_8058B6D4 {
    s32 value;
    u8 remaining[0x18];
};

struct P_803D33D4 { s32 a; s32 b; };
struct P_803D33E4 { s32 a; s32 b; };

struct P_803D346C { void (*fn)(s32); s32 arg; };

struct P_803D3860 { void (*fn)(s32, u8 *); s32 arg; };

struct Cb_803D3678 { s32 fn; s32 arg; };

#include "stdarg.h"
#include "pso/misc/TLobby.h"

extern "C" {
s32 memset(void *, int, int);
extern s32 lobby_callback_tables_refcount;
extern P_803D33D4 lbl_805D7664;
extern P_803D33E4 lbl_805D766C;
extern s32 lbl_805D765C;
char *strncpy(char *, const char *, unsigned long);
void TLobby__sub_803D34B0(s32 arg0, void (*arg1)(s32), s32 arg2);
int vsprintf(char *s, const char *fmt, va_list ap);
void TLobby__sub_803D38B4(const char *fmt, ...);
typedef char RecoveredGlobal_803D31A4_lbl_8058B6B8_size[sizeof(RecoveredGlobal_803D31A4_lbl_8058B6B8) == 0x1C ? 1 : -1];
typedef char RecoveredGlobal_803D31A4_lbl_8058B6D4_size[sizeof(RecoveredGlobal_803D31A4_lbl_8058B6D4) == 0x1C ? 1 : -1];
u32 worker_callback_slots[8];
u8 svm_callback_message_buffer[0x100];
P_803D346C svm_callback_single_table[7];
Cb_803D3678 svm_callback_table[7][4];
RecoveredGlobal_803D31A4_lbl_8058B6B8 worker_callback_flag_table;
RecoveredGlobal_803D31A4_lbl_8058B6D4 svm_callback_counts;

void TLobby::init_callback_tables() {
    if ((s32) lobby_callback_tables_refcount == 0) {
        memset((void *)&worker_callback_flag_table.value, 0, 0x1C);
        memset((void *)&lbl_805D766C, 0, 8);
        memset((void *)&lbl_805D7664, 0, 8);
        *(s32 *)((s8 *)&svm_callback_counts.value + 0) = 0;
        *(s32 *)((s8 *)&svm_callback_counts.value + 4) = 0;
        *(s32 *)((s8 *)&svm_callback_counts.value + 8) = 0;
        *(s32 *)((s8 *)&svm_callback_counts.value + 0xC) = 0;
    }
    lobby_callback_tables_refcount += 1;
}
struct Cb_803D3224 { s32 (*fn)(s32); s32 arg; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 run_callbacks_803D3224(s32 idx) {
    Cb_803D3224 *c;
    s32 i;
    s32 r = 0;
    c = (Cb_803D3224 *)svm_callback_table[idx];

    for (i = 0; i < 4; i++, c++) {
        if (c->fn != 0) {
            ((s32 *)&worker_callback_flag_table)[idx] = 1;
            r |= c->fn(c->arg);
            ((s32 *)&worker_callback_flag_table)[idx] = 0;
        }
    }
    ((s32 *)&svm_callback_counts)[idx]++;
    return r;
}

s32 TLobby::run_worker_callbacks_slot5() {
    return run_callbacks_803D3224(5);
}
s32 TLobby::run_worker_callbacks_slot4() {
    return run_callbacks_803D3224(4);
}
s32 TLobby::run_callbacks_group2() {
    return run_callbacks_803D3224(2);
}
#pragma pop
void TLobby__sub_803D33D4(s32 arg0, s32 arg1) {
    lbl_805D7664.a = arg0;
    lbl_805D7664.b = arg1;
}

void TLobby__sub_803D33E4(s32 arg0, s32 arg1) {
    lbl_805D766C.a = arg0;
    lbl_805D766C.b = arg1;
}
void TLobby::set_callback_params(s32 arg0, s32 arg1) {
    if (((s32 (*)(s32)) *(s32 (**)(s32))((s8 *)&lbl_805D766C + 0)) != NULL) {
        (*(s32 (**)(s32))((s8 *)&lbl_805D766C + 0))(*(s32 *)((s8 *)&lbl_805D766C + 4));
    }
    *(s32 *)((s8 *)&lbl_805D765C + 0) = arg0;
    *(s32 *)((s8 *)&lbl_805D765C + 4) = arg1;
    if (((s32 (*)(s32)) *(s32 (**)(s32))((s8 *)&lbl_805D7664 + 0)) != NULL) {
        (*(s32 (**)(s32))((s8 *)&lbl_805D7664 + 0))(*(s32 *)((s8 *)&lbl_805D7664 + 4));
    }
}
void TLobby__sub_803D346C(s32 arg0) {
    if (svm_callback_single_table[arg0].fn != 0) {
        svm_callback_single_table[arg0].fn(svm_callback_single_table[arg0].arg);
    }
}

void TLobby__sub_803D34B0(s32 arg0, void (*arg1)(s32), s32 arg2) {
    if ((void (*)(s32))lbl_805D766C.a != 0) {
        ((void (*)(s32))lbl_805D766C.a)(lbl_805D766C.b);
    }
    svm_callback_single_table[arg0].fn = arg1;
    svm_callback_single_table[arg0].arg = arg2;
    if ((void (*)(s32))lbl_805D7664.a != 0) {
        ((void (*)(s32))lbl_805D7664.a)(lbl_805D7664.b);
    }
}

#define CB765C (*(P_803D3860 *)&lbl_805D765C)

#define CB765C (*(P_803D3860 *)&lbl_805D765C)
void TLobby::SVM_SetCbSvrId(s32 arg0, s32 arg1, s32 fn, s32 arg) {
    Cb_803D3678 *c;
    if (arg1 < 0 || arg1 >= 4) {
        strncpy((char *)svm_callback_message_buffer, "1071201:SVM_SetCbSvrId:illegal id", 0xFF);
        if (CB765C.fn != 0) {
            CB765C.fn(CB765C.arg, svm_callback_message_buffer);
        }
    }
    if (arg0 < 0 || arg1 >= 7) {
        strncpy((char *)svm_callback_message_buffer, "1071202:SVM_SetCbSvrId:illegal svtype", 0xFF);
        if (CB765C.fn != 0) {
            CB765C.fn(CB765C.arg, svm_callback_message_buffer);
        }
    }
    if ((void (*)(s32))lbl_805D766C.a != 0) {
        ((void (*)(s32))lbl_805D766C.a)(lbl_805D766C.b);
    }
    c = &svm_callback_table[arg0][arg1];
    c->fn = fn;
    c->arg = arg;
    if ((void (*)(s32))lbl_805D7664.a != 0) {
        ((void (*)(s32))lbl_805D7664.a)(lbl_805D7664.b);
    }
}

void TLobby::SVM_DelCbSvr(s32 arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 4) {
        strncpy((char *)svm_callback_message_buffer, "1051002:SVM_DelCbSvr:illegal id", 0xFF);
        if (CB765C.fn != 0) {
            CB765C.fn(CB765C.arg, svm_callback_message_buffer);
        }
    }
    if ((void (*)(s32))lbl_805D766C.a != 0) {
        ((void (*)(s32))lbl_805D766C.a)(lbl_805D766C.b);
    }
    svm_callback_table[arg0][arg1].fn = 0;
    svm_callback_table[arg0][arg1].arg = 0;
    if ((void (*)(s32))lbl_805D7664.a != 0) {
        ((void (*)(s32))lbl_805D7664.a)(lbl_805D7664.b);
    }
}

#define CB765C (*(P_803D3860 *)&lbl_805D765C)
s32 TLobby::svm_set_cb_svr(s32 arg0, s32 fn, s32 arg) {
    Cb_803D3678 *c;
    s32 i;
    if ((void (*)(s32))lbl_805D766C.a != 0) {
        ((void (*)(s32))lbl_805D766C.a)(lbl_805D766C.b);
    }
    c = svm_callback_table[arg0];
    for (i = 0; i < 4; c++, i++) {
        if ((void *)c->fn == 0) {
            c->fn = fn;
            c->arg = arg;
            break;
        }
    }
    if (i == 4) {
        strncpy((char *)svm_callback_message_buffer, "1051001:SVM_SetCbSvr:too many server function", 0xFF);
        if (CB765C.fn != 0) {
            CB765C.fn(CB765C.arg, svm_callback_message_buffer);
        }
    }
    if ((void (*)(s32))lbl_805D7664.a != 0) {
        ((void (*)(s32))lbl_805D7664.a)(lbl_805D7664.b);
    }
    if (i == 4) {
        return -1;
    }
    return i;
}

void TLobby::set_message_and_notify(char *arg0) {
    strncpy((char *)svm_callback_message_buffer, arg0, 0xFF);
    if ((*(P_803D3860 *)&lbl_805D765C).fn != 0) {
        (*(P_803D3860 *)&lbl_805D765C).fn((*(P_803D3860 *)&lbl_805D765C).arg, svm_callback_message_buffer);
    }
}
#define CB765C (*(P_803D3860 *)&lbl_805D765C)
void TLobby__sub_803D38B4(const char *fmt, ...) {
    va_list ap;
    memset(svm_callback_message_buffer, 0, 0x100);
    va_start(ap, fmt);
    vsprintf((char *)svm_callback_message_buffer, fmt, ap);
    if (CB765C.fn != 0) {
        CB765C.fn(CB765C.arg, svm_callback_message_buffer);
    }
}

}
