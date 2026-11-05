#include "pso/system/AdxmThreadStorage.h"
#include "pso/unk/text_803CBCA0.h"

#include "types.h"
#include <dolphin/os/OSThread.h>
#include <dolphin/os/OSInterrupt.h>
#include "pso/unk/text_803D31A4.h"

extern "C" {
extern s32 lbl_805D7594;
extern s32 lbl_805D75AC;
void fn_803CBCA0(void) {
    OSThread *t;
    if (--lbl_805D7594 == 0) {
        t = OSGetCurrentThread();
        OSSuspendThread(&adxm_busy_wait_thread);
        OSSetThreadPriority(t, lbl_805D75AC);
    }
}

}

extern "C" {
extern s32 lbl_804F9D80[];
extern s32 lbl_805D7594;
extern s32 lbl_805D75AC;
extern s32 lbl_805D75B0;

void __OSCallResetFunctions(void) {
    s32 enabled;
    OSThread *thread;
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
