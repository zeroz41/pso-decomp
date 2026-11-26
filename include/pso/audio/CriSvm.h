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
void svm_finish(void);
void svm_set_unlock_callback(AdxTransitionCallback callback, s32 context);
void svm_set_lock_callback(AdxTransitionCallback callback, s32 context);
void svm_invoke_single_callback(s32 group);
void svm_set_single_callback(s32 group, AdxTransitionCallback callback, s32 context);
void svm_report_error(const char *fmt, ...);
void svm_unlock(void);
void svm_lock(void);
}

extern "C" {
void svm_init();
s32 svm_exec_group5();
s32 svm_exec_group4();
s32 svm_exec_group2();
void svm_set_message_callback(AdxMessageCallback callback, s32 context);
void SVM_SetCbSvrId(s32 group, s32 slot, AdxWorkerCallback callback, s32 context);
void SVM_DelCbSvr(s32 group, s32 id);
s32 SVM_SetCbSvr(s32 group, AdxWorkerCallback callback, s32 context);
void svm_report_message(char *src);
}

#endif
