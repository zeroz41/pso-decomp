#include "types.h"
#include <string.h>
#include "pso/audio/CriSvm.h"
#include <stdarg.h>
#include <stdio.h>
#include "pso/unk/TLobby.h"

s32 lobby_callback_tables_refcount;

void TLobby__sub_803D3194(void) {
    lobby_callback_tables_refcount -= 1;
}

extern "C" {
SvmMessageSlot svm_message_slot;
SvmTransitionSlot svm_unlock_slot;
SvmTransitionSlot svm_lock_slot;
u32 worker_callback_slots[8];
char svm_callback_message_buffer[0x100];
}

SvmTransitionSlot svm_callback_single_table[7];
SvmWorkerSlot svm_callback_table[7][4];
WorkerCallbackFlagTable worker_callback_flag_table;
SvmCallbackCounts svm_callback_counts;

extern "C" {

void TLobby::init_callback_tables() {
    if (lobby_callback_tables_refcount == 0) {
        memset(worker_callback_flag_table.values, 0, sizeof(worker_callback_flag_table.values));
        memset(&svm_lock_slot, 0, sizeof(svm_lock_slot));
        memset(&svm_unlock_slot, 0, sizeof(svm_unlock_slot));
        svm_callback_counts.values[0] = 0;
        svm_callback_counts.values[1] = 0;
        svm_callback_counts.values[2] = 0;
        svm_callback_counts.values[3] = 0;
    }
    lobby_callback_tables_refcount += 1;
}

static inline s32 svm_run_callbacks(s32 idx) {
    SvmWorkerSlot *c;
    s32 i;
    s32 r = 0;
    c = svm_callback_table[idx];

    for (i = 0; i < 4; i++, c++) {
        if (c->fn != NULL) {
            worker_callback_flag_table.values[idx] = 1;
            r |= c->fn(c->arg);
            worker_callback_flag_table.values[idx] = 0;
        }
    }
    svm_callback_counts.values[idx]++;
    return r;
}

s32 TLobby::run_worker_callbacks_slot5() {
    return svm_run_callbacks(5);
}

s32 TLobby::run_worker_callbacks_slot4() {
    return svm_run_callbacks(4);
}

s32 TLobby::run_callbacks_group2() {
    return svm_run_callbacks(2);
}

void svm_set_unlock_callback(AdxTransitionCallback callback, s32 context) {
    svm_unlock_slot.fn = callback;
    svm_unlock_slot.arg = context;
}

void svm_set_lock_callback(AdxTransitionCallback callback, s32 context) {
    svm_lock_slot.fn = callback;
    svm_lock_slot.arg = context;
}

void TLobby::set_callback_params(AdxMessageCallback callback, s32 context) {
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
    svm_message_slot.fn = callback;
    svm_message_slot.arg = context;
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
}

void svm_invoke_single_callback(s32 group) {
    if (svm_callback_single_table[group].fn != NULL) {
        svm_callback_single_table[group].fn(svm_callback_single_table[group].arg);
    }
}

void svm_set_single_callback(s32 group, AdxTransitionCallback callback, s32 context) {
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
    svm_callback_single_table[group].fn = callback;
    svm_callback_single_table[group].arg = context;
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
}

void TLobby::SVM_SetCbSvrId(s32 group, s32 id, AdxWorkerCallback fn, s32 arg) {
    SvmWorkerSlot *c;
    if (id < 0 || id >= 4) {
        strncpy(svm_callback_message_buffer, "1071201:SVM_SetCbSvrId:illegal id", 0xFF);
        if (svm_message_slot.fn != NULL) {
            svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
        }
    }
    if (group < 0 || id >= 7) {
        strncpy(svm_callback_message_buffer, "1071202:SVM_SetCbSvrId:illegal svtype", 0xFF);
        if (svm_message_slot.fn != NULL) {
            svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
        }
    }
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
    c = &svm_callback_table[group][id];
    c->fn = fn;
    c->arg = arg;
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
}

void TLobby::SVM_DelCbSvr(s32 group, s32 id) {
    if (id < 0 || id >= 4) {
        strncpy(svm_callback_message_buffer, "1051002:SVM_DelCbSvr:illegal id", 0xFF);
        if (svm_message_slot.fn != NULL) {
            svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
        }
    }
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
    svm_callback_table[group][id].fn = NULL;
    svm_callback_table[group][id].arg = 0;
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
}

s32 TLobby::svm_set_cb_svr(s32 group, AdxWorkerCallback fn, s32 arg) {
    SvmWorkerSlot *c;
    s32 i;
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
    c = svm_callback_table[group];
    for (i = 0; i < 4; c++, i++) {
        if (c->fn == NULL) {
            c->fn = fn;
            c->arg = arg;
            break;
        }
    }
    if (i == 4) {
        strncpy(svm_callback_message_buffer, "1051001:SVM_SetCbSvr:too many server function", 0xFF);
        if (svm_message_slot.fn != NULL) {
            svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
        }
    }
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
    if (i == 4) {
        return -1;
    }
    return i;
}

void TLobby::set_message_and_notify(char *src) {
    strncpy(svm_callback_message_buffer, src, 0xFF);
    if (svm_message_slot.fn != NULL) {
        svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
    }
}

void svm_report_error(const char *fmt, ...) {
    va_list ap;
    memset(svm_callback_message_buffer, 0, sizeof(svm_callback_message_buffer));
    va_start(ap, fmt);
    vsprintf(svm_callback_message_buffer, fmt, ap);
    if (svm_message_slot.fn != NULL) {
        svm_message_slot.fn(svm_message_slot.arg, svm_callback_message_buffer);
    }
}

}

void svm_unlock(void) {
    if (svm_unlock_slot.fn != NULL) {
        svm_unlock_slot.fn(svm_unlock_slot.arg);
    }
}

void svm_lock(void) {
    if (svm_lock_slot.fn != NULL) {
        svm_lock_slot.fn(svm_lock_slot.arg);
    }
}
