#include "types.h"
#include <string.h>
#include "pso/unk/text_803D31A4.h"
#include <stdarg.h>
#include <stdio.h>
#include "pso/unk/TLobby.h"

s32 lobby_callback_tables_refcount;

void TLobby__sub_803D3194(void) {
    lobby_callback_tables_refcount -= 1;
}

struct SvmTransitionSlot { AdxTransitionCallback fn; s32 arg; };
struct SvmMessageSlot { AdxMessageCallback fn; s32 arg; };
struct SvmWorkerSlot { AdxWorkerCallback fn; s32 arg; };

extern "C" {
SvmMessageSlot lbl_805D765C;
SvmTransitionSlot lbl_805D7664;
SvmTransitionSlot lbl_805D766C;
void TLobby__sub_803D38B4(const char *fmt, ...);
u32 worker_callback_slots[8];
char svm_callback_message_buffer[0x100];
}

SvmTransitionSlot svm_callback_single_table[7];
SvmWorkerSlot svm_callback_table[7][4];
WorkerCallbackFlagTable worker_callback_flag_table;
SvmCallbackCounts svm_callback_counts;

extern "C" {

void TLobby::init_callback_tables() {
    if ((s32) lobby_callback_tables_refcount == 0) {
        memset(worker_callback_flag_table.values, 0, 0x1C);
        memset((void *)&lbl_805D766C, 0, sizeof(lbl_805D766C));
        memset((void *)&lbl_805D7664, 0, sizeof(lbl_805D7664));
        svm_callback_counts.values[0] = 0;
        svm_callback_counts.values[1] = 0;
        svm_callback_counts.values[2] = 0;
        svm_callback_counts.values[3] = 0;
    }
    lobby_callback_tables_refcount += 1;
}
static inline s32 run_callbacks_803D3224(s32 idx) {
    SvmWorkerSlot *c;
    s32 i;
    s32 r = 0;
    c = svm_callback_table[idx];

    for (i = 0; i < 4; i++, c++) {
        if (c->fn != 0) {
            worker_callback_flag_table.values[idx] = 1;
            r |= c->fn(c->arg);
            worker_callback_flag_table.values[idx] = 0;
        }
    }
    svm_callback_counts.values[idx]++;
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
void TLobby__sub_803D33D4(AdxTransitionCallback arg0, s32 arg1) {
    lbl_805D7664.fn = arg0;
    lbl_805D7664.arg = arg1;
}

void TLobby__sub_803D33E4(AdxTransitionCallback arg0, s32 arg1) {
    lbl_805D766C.fn = arg0;
    lbl_805D766C.arg = arg1;
}
void TLobby::set_callback_params(AdxMessageCallback arg0, s32 context) {
    if (lbl_805D766C.fn != NULL) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
    lbl_805D765C.fn = arg0;
    lbl_805D765C.arg = context;
    if (lbl_805D7664.fn != NULL) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
}
void TLobby__sub_803D346C(s32 arg0) {
    if (svm_callback_single_table[arg0].fn != 0) {
        svm_callback_single_table[arg0].fn(svm_callback_single_table[arg0].arg);
    }
}

void TLobby__sub_803D34B0(s32 arg0, AdxTransitionCallback arg1, s32 arg2) {
    if (lbl_805D766C.fn != 0) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
    svm_callback_single_table[arg0].fn = arg1;
    svm_callback_single_table[arg0].arg = arg2;
    if (lbl_805D7664.fn != 0) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
}


void TLobby::SVM_SetCbSvrId(s32 arg0, s32 arg1, AdxWorkerCallback fn, s32 arg) {
    SvmWorkerSlot *c;
    if (arg1 < 0 || arg1 >= 4) {
        strncpy(svm_callback_message_buffer, "1071201:SVM_SetCbSvrId:illegal id", 0xFF);
        if (lbl_805D765C.fn != 0) {
            lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
        }
    }
    if (arg0 < 0 || arg1 >= 7) {
        strncpy(svm_callback_message_buffer, "1071202:SVM_SetCbSvrId:illegal svtype", 0xFF);
        if (lbl_805D765C.fn != 0) {
            lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
        }
    }
    if (lbl_805D766C.fn != 0) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
    c = &svm_callback_table[arg0][arg1];
    c->fn = fn;
    c->arg = arg;
    if (lbl_805D7664.fn != 0) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
}

void TLobby::SVM_DelCbSvr(s32 arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 4) {
        strncpy(svm_callback_message_buffer, "1051002:SVM_DelCbSvr:illegal id", 0xFF);
        if (lbl_805D765C.fn != 0) {
            lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
        }
    }
    if (lbl_805D766C.fn != 0) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
    svm_callback_table[arg0][arg1].fn = 0;
    svm_callback_table[arg0][arg1].arg = 0;
    if (lbl_805D7664.fn != 0) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
}

s32 TLobby::svm_set_cb_svr(s32 arg0, AdxWorkerCallback fn, s32 arg) {
    SvmWorkerSlot *c;
    s32 i;
    if (lbl_805D766C.fn != 0) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
    c = svm_callback_table[arg0];
    for (i = 0; i < 4; c++, i++) {
        if (c->fn == NULL) {
            c->fn = fn;
            c->arg = arg;
            break;
        }
    }
    if (i == 4) {
        strncpy(svm_callback_message_buffer, "1051001:SVM_SetCbSvr:too many server function", 0xFF);
        if (lbl_805D765C.fn != 0) {
            lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
        }
    }
    if (lbl_805D7664.fn != 0) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
    if (i == 4) {
        return -1;
    }
    return i;
}

void TLobby::set_message_and_notify(char *src) {
    strncpy(svm_callback_message_buffer, src, 0xFF);
    if (lbl_805D765C.fn != 0) {
        lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
    }
}
void TLobby__sub_803D38B4(const char *fmt, ...) {
    va_list ap;
    memset(svm_callback_message_buffer, 0, 0x100);
    va_start(ap, fmt);
    vsprintf(svm_callback_message_buffer, fmt, ap);
    if (lbl_805D765C.fn != 0) {
        lbl_805D765C.fn(lbl_805D765C.arg, svm_callback_message_buffer);
    }
}

}

void TLobby__sub_803D3988(void) {
    if (lbl_805D7664.fn != NULL) {
        lbl_805D7664.fn(lbl_805D7664.arg);
    }
}

void TLobby__sub_803D39C0(void) {
    if (lbl_805D766C.fn != NULL) {
        lbl_805D766C.fn(lbl_805D766C.arg);
    }
}
