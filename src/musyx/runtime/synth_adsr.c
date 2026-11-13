#include "musyx/runtime/musyx_runtime_a.h"

extern "C" {

u32 adsrConvertTimeCents(s32 arg0) {
    return (u32)(1000.0f * powf(2.0f, 1.27156579e-08f * (f32)arg0, 1.27156579e-08f));
}

s32 salChangeADSRState(void *a0) {
    ADSR_VARS_803B41C8 *adsr = (ADSR_VARS_803B41C8 *)a0;
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

u32 adsrSetup(u8 *arg0) {
    ((ADSR_VARS_803B41C8 *)arg0)->state = 0;
    return salChangeADSRState(arg0);
}
#define dspScale2IndexTab lbl_804F68DC
#pragma push
#pragma opt_common_subs on

u32 adsrStartRelease(ADSR_VARS_803B41C8 *adsr, u32 rtime) {
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
#undef dspScale2IndexTab

s32 adsrRelease(struct Envelope_803B431C *e) {
    switch (e->mode) {
    case 0:
    case 1:
        return adsrStartRelease((ADSR_VARS_803B41C8 *)e, e->release);
    default:
        return 0;
    }
}

u32 adsrHandle(void *arg0, void *arg1, void *arg2) {
    ADSR_VARS_803B41C8 *e = (ADSR_VARS_803B41C8 *)arg0;
    u16 *out = (u16 *)arg1;
    u16 *dlt = (u16 *)arg2;
    s32 ret = 0;
    s32 old;
    s32 d;
    s32 v;
    switch (e->mode) {
    case 0:
        if (e->state != 3) {
            old = e->currentVolume;
            e->currentVolume = old + e->currentDelta;
            *out = old >> 16;
            if (e->currentDelta >= 0) {
                *dlt = e->currentDelta >> 21;
            } else {
                *dlt = -(-e->currentDelta >> 21);
            }
            if (--e->cnt == 0) {
                ret = salChangeADSRState(e);
            }
        } else {
            *out = e->currentVolume >> 16;
            *dlt = 0;
        }
        break;
    case 1:
        if (e->state != 3) {
            old = e->currentVolume;
            if (e->data.dls.aMode == 0 && e->state == 1) {
                e->currentVolume = old + e->currentDelta;
            } else {
                e->currentIndex += e->currentDelta;
                v = 0xC1 - ((e->currentIndex + 0x8000) >> 16);
                if (v < 0) {
                    v = 0;
                }
                e->currentVolume = lbl_804F6758[v] << 16;
            }
            *out = old >> 16;
            d = e->currentVolume - old;
            if (d >= 0) {
                *dlt = d >> 21;
            } else {
                *dlt = -(-d >> 21);
            }
            if (--e->cnt == 0) {
                ret = salChangeADSRState(e);
            }
        } else {
            *out = e->currentVolume >> 16;
            *dlt = 0;
        }
        break;
    }
    return ret;
}

u32 adsrHandleLowPrecision(void *arg0, void *arg1, void *arg2) {
    u8 i;

    for (i = 0; i < 15; i++) {
        if (adsrHandle(arg0, arg1, arg2) != 0) {
            return 1;
        }
    }
    return 0;
}

}
