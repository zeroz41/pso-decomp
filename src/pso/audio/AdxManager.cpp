#include <dolphin/os/OSThread.h>
#include "pso/audio/AdxFsServer.h"
#include "pso/audio/AdxManager.h"
#include "pso/audio/AdxTalk.h"
#include "pso/system/movie/Mfci.h"
#include <dolphin/os/OSInterrupt.h>
#include "pso/unk/TLobby.h"
#include "pso/system/CvFsStreamHandle.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/audio/CriSvm.h"
#include "pso/system/movie/Gcci.h"

extern "C" {

AdxmThreadConfig adxm_thread_config = {0};
AdxmPendingCallback adx_worker_thread_pending_callback = {NULL, 0};

s32 adxm_init_count;
s32 adxm_svm_lock_depth;
s32 adxm_worker_idle_requested;
volatile s32 adxm_busy_wait_spin_count;
s32 adxm_vblank_tick_count;
s32 adxm_worker_loop_count;
OSThread *adxm_main_thread;
s32 adxm_saved_thread_priority;
volatile s32 adxm_lock_transition_flag;
volatile s32 adxm_vblank_thread_stopped;
volatile s32 adxm_vblank_thread_run_flag;
volatile s32 adxm_worker_thread_stopped;
volatile s32 lobby_worker_thread_run_flag;
volatile s32 adxm_busy_wait_stopped;
volatile s32 adxm_busy_wait_run_flag;

void setup_adx_file_systems(s32 *read_mode) {
    cvFsEntryErrFunc(fs_error_notify, 0);
    cvFsAddDev(const_cast<char *>("MFS"), mfci_get_interface, 0);
    cvFsEntryErrFunc(fs_error_notify, 0);
    cvFsAddDev(const_cast<char *>("GCD"), initialize_dvd_file_driver, 0);
    cvFsSetDefDev(const_cast<char *>("GCD"));
    if (read_mode != NULL) {
        set_dvd_synchronous_read_mode(0, 0, 0, *read_mode);
    } else {
        set_dvd_synchronous_read_mode(0, 0, 0, 0);
    }
}

void fs_error_notify(s32, const char *message, void *) {
    TLobby::notify_error(message);
}

static const char *const volatile adxgc_version_pointer = "\nADXGC Ver.1.10 Build:Jun 13 2002 19:01:41\n";

void exec_adx_server(void) {
    adxgc_version_pointer;
    TLobby__sub_803C9608();
    ADXT_ExecFsSvr();
}

s32 is_adxm_initialized(void) {
    return adxm_init_count != 0;
}

OSThread adxm_worker_thread;
OSThread adxm_vblank_thread;
OSThread adxm_busy_wait_thread;
u8 adxm_worker_stack[ADXM_WORKER_STACK_BYTES];
u8 adxm_vblank_stack[ADXM_VBLANK_STACK_BYTES];
u8 adxm_busy_wait_stack[ADXM_BUSY_WAIT_STACK_BYTES];

typedef void *(*AdxmThreadEntry)(void *);

void init_runtime_threads(AdxmThreadConfig *cfg) {
    adxgc_version_pointer;
    if (adxm_init_count == 0) {
        TLobby::init_callback_tables();
        svm_set_lock_callback(__OSCallResetFunctions, 0);
        svm_set_unlock_callback(adxm_svm_unlock_callback, 0);
        if (cfg == NULL) {
            adxm_thread_config.pad_0c = 16;
            adxm_thread_config.prio0 = 1;
            adxm_thread_config.busy_wait_prio = 8;
            adxm_thread_config.vblank_prio = 12;
            adxm_thread_config.prio = 24;
        } else {
            __memcpy(&adxm_thread_config, cfg, sizeof(AdxmThreadConfig));
        }
        OSCreateThread(&adxm_busy_wait_thread, (AdxmThreadEntry)TLobby::wait_for_lock_release, NULL,
                       adxm_busy_wait_stack + sizeof(adxm_busy_wait_stack), sizeof(adxm_busy_wait_stack),
                       adxm_thread_config.busy_wait_prio, 1);
        OSCreateThread(&adxm_vblank_thread, (AdxmThreadEntry)vblank_thread_loop, NULL,
                       adxm_vblank_stack + sizeof(adxm_vblank_stack), sizeof(adxm_vblank_stack),
                       adxm_thread_config.vblank_prio, 1);
        OSCreateThread(&adxm_worker_thread, (AdxmThreadEntry)TLobby::worker_thread_loop, NULL,
                       adxm_worker_stack + sizeof(adxm_worker_stack), sizeof(adxm_worker_stack),
                       adxm_thread_config.prio, 1);
        adxm_main_thread = OSGetCurrentThread();
        lobby_worker_thread_run_flag = 1;
        adxm_vblank_thread_run_flag = 1;
        adxm_busy_wait_run_flag = 1;
        adxm_worker_thread_stopped = 0;
        adxm_vblank_thread_stopped = 0;
        adxm_busy_wait_stopped = 0;
        adxm_lock_transition_flag = 0;
        OSResumeThread(&adxm_vblank_thread);
        OSResumeThread(&adxm_worker_thread);
        svm_set_single_callback(5, TLobby::adxm_goto_mwidle_border, 0);
    }
    adxm_init_count++;
}

void adxm_set_error_callback(AdxMessageCallback callback, s32 context) {
    TLobby::set_callback_params(callback, context);
}

void exec_vsync_servers(void) {
    TLobby::run_callbacks_group2();
}

void TLobby::worker_thread_loop() {
    while (lobby_worker_thread_run_flag == 1) {
        adxm_worker_loop_count++;
        if (TLobby::run_worker_callbacks_slot5() == 0 || adxm_worker_idle_requested == 1) {
            if (adxm_worker_idle_requested == 1) {
                adxm_worker_idle_requested = 0;
                OSSetThreadPriority(&adxm_worker_thread, adxm_thread_config.prio);
            }
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
            OSSuspendThread(&adxm_worker_thread);
        }
    }
    adxm_worker_thread_stopped = 1;
}

void vblank_thread_loop(void) {
    while (adxm_vblank_thread_run_flag == 1) {
        VIWaitForRetrace();
        adxm_vblank_tick_count++;
        lbl_805D7540++;
        TLobby::run_callbacks_group2();
        if (adxm_worker_thread_stopped == 0) {
            OSResumeThread(&adxm_worker_thread);
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
        }
    }
    adxm_vblank_thread_stopped = 1;
}

void TLobby::wait_for_lock_release() {
    while (adxm_busy_wait_run_flag == 1) {
        adxm_busy_wait_spin_count++;
    }
    adxm_busy_wait_stopped = 1;
}
void TLobby::adxm_goto_mwidle_border(s32) {
    s32 i;
    if (adxm_worker_thread_stopped == 1) {
        return;
    }
    adxm_worker_idle_requested = 1;
    OSSetThreadPriority(&adxm_worker_thread, adxm_thread_config.prio0);
    for (i = 0; i < 200000000; i++) {
        OSResumeThread(&adxm_worker_thread);
        if (adxm_worker_idle_requested == 0) {
            break;
        }
    }
    if (i == 200000000) {
        TLobby::set_message_and_notify("1060102: Internal Error: adxm_goto_mwidle_border");
    }
    OSSetThreadPriority(&adxm_worker_thread, adxm_thread_config.prio);
}
void adxm_svm_unlock_callback(s32) {
    OSThread *t;
    if (--adxm_svm_lock_depth == 0) {
        t = OSGetCurrentThread();
        OSSuspendThread(&adxm_busy_wait_thread);
        OSSetThreadPriority(t, adxm_saved_thread_priority);
    }
}

void __OSCallResetFunctions(s32) {
    s32 enabled;
    OSThread *thread;
    s32 prio;
    if (adxm_svm_lock_depth == 0) {
        enabled = OSDisableInterrupts();
        OSDisableScheduler();
        adxm_lock_transition_flag = 1;
        thread = OSGetCurrentThread();
        prio = OSGetThreadPriority(thread);
        OSSetThreadPriority(thread, adxm_thread_config.prio0);
        adxm_saved_thread_priority = prio;
        adxm_lock_transition_flag = 0;
        OSEnableScheduler();
        OSRestoreInterrupts(enabled);
        OSResumeThread(&adxm_busy_wait_thread);
    }
    adxm_svm_lock_depth++;
}
}

void dispatch_lobby_callback(void) {
    svm_unlock();
}

void dispatch_callback(void) {
    svm_lock();
}
