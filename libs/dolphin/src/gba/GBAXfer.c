#define __GBA lbl_805D2200
#define __GBAReset lbl_805D7CF8

#include "gba/__gba.h"
#include <dolphin/si.h>
#include "os/sdk2002/__os.h"

static void __GBAHandler(s32 chan, u32 error, OSContext* context) {
    GBAControl* gba;
    GBATransferCallback proc;
    GBACallback callback;
    OSContext exceptionContext;

    gba = &__GBA[chan];
    if (__GBAReset != 0) {
        return;
    }

    if ((error & 0xf)) {
        gba->ret = 1;
    } else {
        gba->ret = 0;
    }

    if (gba->proc != NULL) {
        proc = gba->proc;
        gba->proc = NULL;
        proc(chan);
    }

    if (gba->callback == NULL) {
        return;
    }

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    callback = gba->callback;
    gba->callback = NULL;
    callback(chan, gba->ret);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void TypeAndStatusCallback(s32 chan, u32 type) {
    GBAControl* gba;
    GBATransferCallback proc;
    GBACallback callback;
    OSContext exceptionContext;
    OSContext* context;

    gba = &__GBA[chan];
    if (__GBAReset != 0) {
        return;
    }

    if ((type & 0xFF) != 0 || (type & 0xffff0000) != 0x40000) {
        gba->ret = GBA_NOT_READY;
    } else {
        if (SITransfer(chan, gba->output, gba->outputBytes, gba->input, gba->inputBytes, __GBAHandler, gba->delay)) {
            return;
        }
        gba->ret = GBA_BUSY;
    }

    if (gba->proc != NULL) {
        proc = gba->proc;
        gba->proc = NULL;
        proc(chan);
    }

    if (gba->callback != NULL) {
        context = OSGetCurrentContext();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback = gba->callback;
        gba->callback = NULL;
        callback(chan, gba->ret);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
        __OSReschedule();
    }
}

s32 __GBATransfer(s32 chan, u32 w1, u32 w2, GBATransferCallback callback) {
    s32 enabled;
    GBAControl* gba;
    gba = &__GBA[chan];
    enabled = OSDisableInterrupts();
    gba->proc = callback;
    gba->outputBytes = w1;
    gba->inputBytes = w2;
    SIGetTypeAsync(chan, TypeAndStatusCallback);
    OSRestoreInterrupts(enabled);

    return GBA_READY;
}

OSTime __GBASetDelay(s32 chan, OSTime delay) {
    OSTime oldDelay;
    GBAControl* gba;
    gba = &__GBA[chan];
    oldDelay = gba->delay;
    gba->delay = delay;
    return oldDelay;
}
