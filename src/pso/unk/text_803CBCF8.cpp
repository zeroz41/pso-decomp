#include "pso/system/AdxmThreadStorage.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/text_803CBCF8.h"

#include "types.h"

extern "C" {
s32 OSDisableInterrupts(void);
void OSDisableScheduler(void);
void OSEnableScheduler(void);
void OSRestoreInterrupts(s32);
void *OSGetCurrentThread(void);
void OSResumeThread(void *);
void OSSetThreadPriority(void *, s32);
s32 OSGetThreadPriority(void *);
extern s32 lbl_804F9D80[];
extern s32 lbl_805D7594;
extern s32 lbl_805D75AC;
extern s32 lbl_805D75B0;

void __OSCallResetFunctions(void) {
    s32 enabled;
    void *thread;
    s32 prio;
    if (lbl_805D7594 == 0) {
        enabled = OSDisableInterrupts();
        OSDisableScheduler();
        lbl_805D75B0 = 1;
        thread = OSGetCurrentThread();
        prio = OSGetThreadPriority(thread);
        OSSetThreadPriority(thread, lbl_804F9D80[0]);
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
