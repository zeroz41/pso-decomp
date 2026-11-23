#ifndef PSO_AUDIO_ADXMANAGER_H
#define PSO_AUDIO_ADXMANAGER_H

#include "types.h"
#include "pso/audio/AdxCallbacks.h"

struct AdxmPendingCallback {
    void (*fn)(s32);
    s32 arg;
};

struct AdxmThreadConfig {
    s32 prio0;
    s32 busy_wait_prio;
    s32 vblank_prio;
    s32 pad_0c;
    s32 prio;
};

// --- C functions and globals defined in AdxManager.cpp / AdxtInit.cpp ---
extern "C" {
extern s32 lbl_805D7540;
void VIWaitForRetrace(void);
void setup_adx_file_systems(s32 *read_mode);
void fs_error_notify(s32 context, const char *message, void *detail);
void exec_adx_server(void);
s32 is_adxm_initialized(void);
void adxm_set_error_callback(AdxMessageCallback callback, s32 context);
void exec_vsync_servers(void);
void vblank_thread_loop(void);
void __OSCallResetFunctions(s32 context);
void adxm_svm_unlock_callback(s32 context);
}
// --- end of C functions

#endif
