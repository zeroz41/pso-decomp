#ifndef PSO_UNK_TEXT_803D31A4_H
#define PSO_UNK_TEXT_803D31A4_H

#include "pso/audio/AdxCallbacks.h"

extern "C" {
void TLobby__sub_803D33D4(AdxTransitionCallback callback, s32 context);
void TLobby__sub_803D33E4(AdxTransitionCallback callback, s32 context);
void TLobby__sub_803D346C(s32 group);
void TLobby__sub_803D34B0(s32 group, AdxTransitionCallback callback, s32 context);
}

extern "C" {
void TLobby__sub_803D3194(void);
}

extern "C" {
void TLobby__sub_803D3988(void);
void TLobby__sub_803D39C0(void);
}

// svm_callback_counts: layout known from its uses only.
struct SvmCallbackCounts { s32 values[7]; };
extern SvmCallbackCounts svm_callback_counts;
// worker_callback_flag_table: layout known from its uses only.
struct WorkerCallbackFlagTable { s32 values[7]; };
extern WorkerCallbackFlagTable worker_callback_flag_table;

#endif
