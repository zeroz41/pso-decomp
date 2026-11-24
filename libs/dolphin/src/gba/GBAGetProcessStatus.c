#include "gba/__gba.h"

s32 GBAGetProcessStatus(s32 chan, u8* percentp) {
    BOOL enabled;
    s32 ret;
    GBAControl* gba = &__GBA[chan];
    GBABootInfo* bootInfo;
    u8 percent;
    OSTime t;

    bootInfo = &__GBA[chan].bootInfo;
    enabled = OSDisableInterrupts();
    if (bootInfo->callback != NULL) {
        ret = GBA_BUSY;
        percent = (bootInfo->curOffset * 100) / bootInfo->realLength;
        if (bootInfo->begin != 0) {
            t = OSGetTime() - bootInfo->begin;
            if (OSTicksToMilliseconds(t) < 5500) {
                percent = (percent * t) / OSMillisecondsToTicks(5500ll);
            }

            if (percent >= 100) {
                percent = 100;
            }
        }

        if (percentp != NULL) {
            *percentp = percent;
        }
    } else if (gba->callback != NULL) {
        ret = GBA_BUSY;
    } else {
        ret = GBA_READY;
    }

    OSRestoreInterrupts(enabled);
    return ret;
}
