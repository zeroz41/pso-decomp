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
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/TLobby_803CE478.h"


typedef struct Cb_803CBA58 {
    void (*fn)(s32);
    s32 arg;
} Cb_803CBA58;

typedef struct Cfg_803CBA58 {
    s32 prio0;
    s32 busy_wait_prio;
    s32 vblank_prio;
    s32 pad_0c;
    s32 prio;
} Cfg_803CBA58;

extern "C" {
s32 VIWaitForRetrace();
extern s32 lbl_805D7540;

Cfg_803CBA58 lbl_804F9D80 = {0};
Cb_803CBA58 adx_worker_thread_pending_callback = {NULL, 0};

s32 lbl_805D7590;
s32 lbl_805D7594;
s32 lbl_805D7598;
volatile s32 lbl_805D759C;
s32 lbl_805D75A0;
s32 lbl_805D75A4;
OSThread *lbl_805D75A8;
s32 lbl_805D75AC;
volatile s32 lbl_805D75B0;
volatile s32 lbl_805D75B4;
volatile s32 lbl_805D75B8;
volatile s32 lbl_805D75BC;
volatile s32 lobby_worker_thread_run_flag;
volatile s32 lbl_805D75C4;
volatile s32 lbl_805D75C8;
}
void set_dvd_synchronous_read_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {

void setup_adx_file_systems(s32 *arg0) {
    cvFsEntryErrFunc(fs_error_notify, 0);
    cvFsAddDev(const_cast<char *>("MFS"), mfci_get_interface, 0);
    cvFsEntryErrFunc(fs_error_notify, 0);
    cvFsAddDev(const_cast<char *>("GCD"), initialize_dvd_file_driver, 0);
    cvFsSetDefDev(const_cast<char *>("GCD"));
    if (arg0 != NULL) {
        set_dvd_synchronous_read_mode(0, 0, 0, *arg0);
    } else {
        set_dvd_synchronous_read_mode(0, 0, 0, 0);
    }
}

void fs_error_notify(s32, const char *message, void *) {
    TLobby::notify_error(message);
}

static const char *const volatile lbl_805E0D78 = "\nADXGC Ver.1.10 Build:Jun 13 2002 19:01:41\n";

void exec_adx_server(void) {
    lbl_805E0D78;
    TLobby__sub_803C9608();
    ADXT_ExecFsSvr();
}

s32 is_adxm_initialized(void) {
    return lbl_805D7590 != 0;
}

OSThread adxm_worker_thread;
OSThread adxm_vblank_thread;
OSThread adxm_busy_wait_thread;
u8 adxm_worker_stack[ADXM_WORKER_STACK_BYTES];
u8 adxm_vblank_stack[ADXM_VBLANK_STACK_BYTES];
u8 adxm_busy_wait_stack[ADXM_BUSY_WAIT_STACK_BYTES];

void init_runtime_threads(Cfg_803CBA58 *cfg) {
    lbl_805E0D78;
    if (lbl_805D7590 == 0) {
        TLobby::init_callback_tables();
        TLobby__sub_803D33E4(__OSCallResetFunctions, 0);
        TLobby__sub_803D33D4(adxm_svm_unlock_callback, 0);
        if (cfg == NULL) {
            lbl_804F9D80.pad_0c = 16;
            lbl_804F9D80.prio0 = 1;
            lbl_804F9D80.busy_wait_prio = 8;
            lbl_804F9D80.vblank_prio = 12;
            lbl_804F9D80.prio = 24;
        } else {
            __memcpy(&lbl_804F9D80, cfg, sizeof(Cfg_803CBA58));
        }
        OSCreateThread(&adxm_busy_wait_thread, (void *(*)(void *))TLobby::wait_for_lock_release, NULL,
                       adxm_busy_wait_stack + sizeof(adxm_busy_wait_stack), sizeof(adxm_busy_wait_stack),
                       lbl_804F9D80.busy_wait_prio, 1);
        OSCreateThread(&adxm_vblank_thread, (void *(*)(void *))vblank_thread_loop, NULL,
                       adxm_vblank_stack + sizeof(adxm_vblank_stack), sizeof(adxm_vblank_stack),
                       lbl_804F9D80.vblank_prio, 1);
        OSCreateThread(&adxm_worker_thread, (void *(*)(void *))TLobby::worker_thread_loop, NULL,
                       adxm_worker_stack + sizeof(adxm_worker_stack), sizeof(adxm_worker_stack),
                       lbl_804F9D80.prio, 1);
        lbl_805D75A8 = OSGetCurrentThread();
        lobby_worker_thread_run_flag = 1;
        lbl_805D75B8 = 1;
        lbl_805D75C8 = 1;
        lbl_805D75BC = 0;
        lbl_805D75B4 = 0;
        lbl_805D75C4 = 0;
        lbl_805D75B0 = 0;
        OSResumeThread(&adxm_vblank_thread);
        OSResumeThread(&adxm_worker_thread);
        TLobby__sub_803D34B0(5, TLobby::adxm_goto_mwidle_border, 0);
    }
    lbl_805D7590++;
}

void adxm_set_error_callback(AdxMessageCallback callback, s32 context) {
    TLobby::set_callback_params(callback, context);
}

void exec_vsync_servers(void) {
    TLobby::run_callbacks_group2();
}

void TLobby::worker_thread_loop() {
    while (lobby_worker_thread_run_flag == 1) {
        lbl_805D75A4++;
        if (TLobby::run_worker_callbacks_slot5() == 0 || lbl_805D7598 == 1) {
            if (lbl_805D7598 == 1) {
                lbl_805D7598 = 0;
                OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio);
            }
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
            OSSuspendThread(&adxm_worker_thread);
        }
    }
    lbl_805D75BC = 1;
}

void vblank_thread_loop(void) {
    while (lbl_805D75B8 == 1) {
        VIWaitForRetrace();
        lbl_805D75A0++;
        lbl_805D7540++;
        TLobby::run_callbacks_group2();
        if (lbl_805D75BC == 0) {
            OSResumeThread(&adxm_worker_thread);
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
        }
    }
    lbl_805D75B4 = 1;
}

void TLobby::wait_for_lock_release() {
    while (lbl_805D75C8 == 1) {
        lbl_805D759C++;
    }
    lbl_805D75C4 = 1;
}
void TLobby::adxm_goto_mwidle_border(s32) {
    s32 i;
    if (lbl_805D75BC == 1) {
        return;
    }
    lbl_805D7598 = 1;
    OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio0);
    for (i = 0; i < 200000000; i++) {
        OSResumeThread(&adxm_worker_thread);
        if (lbl_805D7598 == 0) {
            break;
        }
    }
    if (i == 200000000) {
        TLobby::set_message_and_notify("1060102: Internal Error: adxm_goto_mwidle_border");
    }
    OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio);
}
void adxm_svm_unlock_callback(s32) {
    OSThread *t;
    if (--lbl_805D7594 == 0) {
        t = OSGetCurrentThread();
        OSSuspendThread(&adxm_busy_wait_thread);
        OSSetThreadPriority(t, lbl_805D75AC);
    }
}

void __OSCallResetFunctions(s32) {
    s32 enabled;
    OSThread *thread;
    s32 prio;
    if (lbl_805D7594 == 0) {
        enabled = OSDisableInterrupts();
        OSDisableScheduler();
        lbl_805D75B0 = 1;
        thread = OSGetCurrentThread();
        prio = OSGetThreadPriority(thread);
        OSSetThreadPriority(thread, lbl_804F9D80.prio0);
        lbl_805D75AC = prio;
        lbl_805D75B0 = 0;
        OSEnableScheduler();
        OSRestoreInterrupts(enabled);
        OSResumeThread(&adxm_busy_wait_thread);
    }
    lbl_805D7594++;
}
}

void dispatch_lobby_callback(void) {
    TLobby__sub_803D3988();
}

void dispatch_callback(void) {
    TLobby__sub_803D39C0();
}
