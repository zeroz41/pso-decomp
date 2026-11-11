#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803CBCA0.h"
#include "pso/unk/text_803D31A4.h"

extern "C" {
void ARAlloc(void);
void TLobby__sub_803C9608(void);
s32 TLobby__sub_803CB844();
void TLobby__sub_803CBA38(void);

}

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

extern Cb_803CBA58 adx_worker_thread_pending_callback;
extern s32 lbl_805D7540;
extern s32 lbl_805D75A0;
void TLobby__sub_803CBB14(void);
}

extern "C" {
void TLobby__sub_803CB7F8(s32 arg0, s32 arg1);
extern s32 lbl_805D7590;
s32 TLobby__sub_803CB844(void);
extern const char *const volatile lbl_805E0D78;
void TLobby__sub_803CB81C(void);
void TLobby__sub_803CE544(void *, int);
void TLobby__sub_803CFAA8(const char *, void *, int);
char *TLobby__sub_803D43B8(void);
extern const char lbl_805E0D70[4];
extern const char lbl_805E0D74[4];
void TLobby__sub_803CB74C(s32 *arg0);
s32 run_worker_callbacks_slot5__6TLobbyFv(int);
extern Cfg_803CBA58 lbl_804F9D80;
extern OSThread *lbl_805D75A8;

extern s32 lbl_805D7598;
extern s32 lbl_805D75A4;
extern char adxm_idle_border_internal_error[];

void TLobby__sub_803CBA18(void);
s32 set_callback_params__6TLobbyFll();

}
void * *initialize_dvd_file_driver(void);
void set_dvd_synchronous_read_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {

void TLobby__sub_803CB74C(s32 *arg0) {
    TLobby__sub_803CE544((void *)TLobby__sub_803CB7F8, 0);
    TLobby__sub_803CFAA8(lbl_805E0D70, (void *)TLobby__sub_803D43B8, 0);
    TLobby__sub_803CE544((void *)TLobby__sub_803CB7F8, 0);
    TLobby__sub_803CFAA8(lbl_805E0D74, (void *)initialize_dvd_file_driver, 0);
    ((TLobby *)lbl_805E0D74)->cvFsSetDefDev();
    if (arg0 != NULL) {
        set_dvd_synchronous_read_mode(0, 0, 0, *arg0);
    } else {
        set_dvd_synchronous_read_mode(0, 0, 0, 0);
    }
}

void TLobby__sub_803CB7F8(s32 arg0, s32 arg1) {
    TLobby::notify_error((const char *)arg1);
}

void TLobby__sub_803CB81C(void) {
    lbl_805E0D78;
    TLobby__sub_803C9608();
    ARAlloc();
}

s32 TLobby__sub_803CB844(void) {
    return lbl_805D7590 != 0;
}

OSThread adxm_worker_thread;
OSThread adxm_vblank_thread;
OSThread adxm_busy_wait_thread;
u8 adxm_worker_stack[ADXM_WORKER_STACK_BYTES];
u8 adxm_vblank_stack[ADXM_VBLANK_STACK_BYTES];
u8 adxm_busy_wait_stack[ADXM_BUSY_WAIT_STACK_BYTES];

void TLobby__sub_803CB858(Cfg_803CBA58 *cfg) {
    lbl_805E0D78;
    if (lbl_805D7590 == 0) {
        TLobby::init_callback_tables();
        TLobby__sub_803D33E4((s32)__OSCallResetFunctions, 0);
        TLobby__sub_803D33D4((s32)fn_803CBCA0, 0);
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
        OSCreateThread(&adxm_vblank_thread, (void *(*)(void *))TLobby__sub_803CBB14, NULL,
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
        TLobby__sub_803D34B0(5, (void (*)(s32))TLobby::adxm_goto_mwidle_border, 0);
    }
    lbl_805D7590++;
}

void TLobby__sub_803CBA18(void) {
    set_callback_params__6TLobbyFll();
}

void TLobby__sub_803CBA38(void) {
    TLobby::run_callbacks_group2();
}

void TLobby::worker_thread_loop() {
    while (lobby_worker_thread_run_flag == 1) {
        if (run_worker_callbacks_slot5__6TLobbyFv(lbl_805D75A4++) == 0 || lbl_805D7598 == 1) {
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

void TLobby__sub_803CBB14(void) {
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
void TLobby::adxm_goto_mwidle_border() {
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
        TLobby::set_message_and_notify(adxm_idle_border_internal_error);
    }
    OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio);
}
}
