#include "musyx/runtime/musyx_runtime_a.h"
#include "musyx/runtime/musyx_internal.h"

extern "C" {

u32 adsrConvertTimeCents(s32 timeCents) {
    return (u32)(1000.0f * powf(2.0f, 1.27156579e-08f * (f32)timeCents));
}

s32 salChangeADSRState(ADSR_VARS *adsr) {
    s32 ret;
    s32 index;
    u32 aTime;
    u32 dTime;
    u32 dlsATime;
    u8 mode;
    u8 state;
    u8 dlsState;
    mode = adsr->mode;
    ret = 0;
    switch ((s32) mode) {
    case 0:
        state = adsr->state;
        switch ((s32) state) {
        case 0:
            aTime = adsr->data.dls.aTime;
            adsr->cnt = aTime;
            if (aTime != 0) {
                adsr->state = 1U;
                adsr->currentVolume = 0;
                adsr->currentDelta = (u32) (0x7FFF0000U / adsr->data.dls.aTime);
            } else {
            case 1:
                dTime = adsr->data.dls.dTime;
                adsr->cnt = dTime;
                if (dTime != 0) {
                    adsr->state = 2U;
                    adsr->currentVolume = 0x7FFF0000;
                    adsr->currentDelta = (u32) -(s32) ((u32) (0x7FFF0000 - (adsr->data.dls.sLevel << 0x10)) / adsr->data.dls.dTime);
                } else {
                case 2:
                    if (adsr->data.dls.sLevel != 0) {
                        adsr->state = 3U;
                        adsr->currentVolume = (s32) (adsr->data.dls.sLevel << 0x10);
                        adsr->currentDelta = 0U;
                    } else {
                    case 4:
                        adsr->currentVolume = 0;
                        ret = 1;
                    }
                }
            }
            break;
        }
        break;
    case 1:
        dlsState = adsr->state;
        switch ((s32) dlsState) {
        case 0:
            dlsATime = adsr->data.dls.aTime;
            adsr->cnt = dlsATime;
            if (dlsATime != 0) {
                adsr->state = 1U;
                if (adsr->data.dls.aMode == 0) {
                    adsr->currentVolume = 0;
                    adsr->currentDelta = (u32) (0x7FFF0000U / adsr->cnt);
                } else {
                    adsr->currentIndex = 0;
                    adsr->currentVolume = 0;
                    adsr->currentDelta = (u32) (0xC10000U / adsr->cnt);
                }
            } else {
            case 1:
                adsr->cnt = (u32) ((u32) (adsr->data.dls.dTime * ((u32)((0xC1 - adsr->data.dls.sLevel) << 0x10) / 193)) >> 0x10U);
                if (adsr->cnt != 0) {
                    adsr->state = 2U;
                    adsr->currentVolume = 0x7FFF0000;
                    adsr->currentIndex = 0xC10000;
                    adsr->currentDelta = (u32) -(s32) ((u32) ((0xC1 - adsr->data.dls.sLevel) << 0x10) / adsr->cnt);
                } else {
                case 2:
                    if (adsr->data.dls.sLevel != 0) {
                        adsr->state = 3U;
                        adsr->currentIndex = (s32) (adsr->data.dls.sLevel << 0x10);
                        index = 0xC1 - ((s32) (adsr->currentIndex + 0x8000) >> 0x10);
                        if (index < 0) {
                            index = 0;
                        }
                        adsr->currentVolume = (s32) (lbl_804F6758[index] << 0x10);
                        adsr->currentDelta = 0U;
                    } else {
                    case 4:
                        adsr->currentVolume = 0;
                        ret = 1;
                    }
                }
            }
            break;
        }
        break;
    }
    return ret;
}

u32 adsrSetup(ADSR_VARS *adsr) {
    adsr->state = 0;
    return salChangeADSRState(adsr);
}
#pragma push
#pragma opt_common_subs on

u32 adsrStartRelease(ADSR_VARS *adsr, u32 rtime) {
    switch (adsr->mode) {
    case 0:
        adsr->state = 4;
        adsr->cnt = rtime;
        if (rtime == 0) {
            adsr->cnt = 1;
            adsr->currentDelta = 0;
            return 1;
        }
        adsr->currentDelta = -(adsr->currentVolume / rtime);
        break;
    case 1:
        if (adsr->data.dls.aMode == 0 && adsr->state == 1) {
            adsr->currentIndex = (193 - dspScale2IndexTab[adsr->currentVolume >> 21]) * 0x10000;
        }

        adsr->cnt = (u32)(3.238342E-4f * (float)adsr->currentIndex * (float)rtime) >> 12;
        adsr->state = 4;
        if (adsr->cnt == 0) {
            adsr->cnt = 1;
            adsr->currentDelta = adsr->currentIndex = adsr->currentVolume = 0;
            return 1;
        }

        adsr->currentDelta = -(adsr->currentIndex / adsr->cnt);
        break;
    }

    return 0;
}

#pragma pop

u32 adsrRelease(ADSR_VARS *adsr) {
    switch (adsr->mode) {
    case 0:
    case 1:
        return adsrStartRelease(adsr, adsr->data.dls.rTime);
    default:
        return 0;
    }
}

u32 adsrHandle(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta) {
    s32 ret = 0;
    s32 old;
    s32 d;
    s32 v;
    switch (adsr->mode) {
    case 0:
        if (adsr->state != 3) {
            old = adsr->currentVolume;
            adsr->currentVolume = old + adsr->currentDelta;
            *adsr_start = old >> 16;
            if (adsr->currentDelta >= 0) {
                *adsr_delta = adsr->currentDelta >> 21;
            } else {
                *adsr_delta = -(-adsr->currentDelta >> 21);
            }
            if (--adsr->cnt == 0) {
                ret = salChangeADSRState(adsr);
            }
        } else {
            *adsr_start = adsr->currentVolume >> 16;
            *adsr_delta = 0;
        }
        break;
    case 1:
        if (adsr->state != 3) {
            old = adsr->currentVolume;
            if (adsr->data.dls.aMode == 0 && adsr->state == 1) {
                adsr->currentVolume = old + adsr->currentDelta;
            } else {
                adsr->currentIndex += adsr->currentDelta;
                v = 0xC1 - ((adsr->currentIndex + 0x8000) >> 16);
                if (v < 0) {
                    v = 0;
                }
                adsr->currentVolume = lbl_804F6758[v] << 16;
            }
            *adsr_start = old >> 16;
            d = adsr->currentVolume - old;
            if (d >= 0) {
                *adsr_delta = d >> 21;
            } else {
                *adsr_delta = -(-d >> 21);
            }
            if (--adsr->cnt == 0) {
                ret = salChangeADSRState(adsr);
            }
        } else {
            *adsr_start = adsr->currentVolume >> 16;
            *adsr_delta = 0;
        }
        break;
    }
    return ret;
}

u32 adsrHandleLowPrecision(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta) {
    u8 i;

    for (i = 0; i < 15; i++) {
        if (adsrHandle(adsr, adsr_start, adsr_delta) != 0) {
            return 1;
        }
    }
    return 0;
}

}
