#ifndef PSO_AUDIO_CRISVM_H
#define PSO_AUDIO_CRISVM_H

#include "pso/audio/AdxCallbacks.h"

struct SvmTransitionSlot { AdxTransitionCallback fn; s32 arg; };
struct SvmMessageSlot { AdxMessageCallback fn; s32 arg; };
struct SvmWorkerSlot { AdxWorkerCallback fn; s32 arg; };

// svm_callback_counts: layout known from its uses only.
struct SvmCallbackCounts { s32 values[7]; };
extern SvmCallbackCounts svm_callback_counts;
// worker_callback_flag_table: layout known from its uses only.
struct WorkerCallbackFlagTable { s32 values[7]; };
extern WorkerCallbackFlagTable worker_callback_flag_table;

extern "C" {
void TLobby__sub_803D3194(void);
void svm_set_unlock_callback(AdxTransitionCallback callback, s32 context);
void svm_set_lock_callback(AdxTransitionCallback callback, s32 context);
void svm_invoke_single_callback(s32 group);
void svm_set_single_callback(s32 group, AdxTransitionCallback callback, s32 context);
void svm_report_error(const char *fmt, ...);
void svm_unlock(void);
void svm_lock(void);
}

#endif
