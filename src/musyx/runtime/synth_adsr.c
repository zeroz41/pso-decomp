#include "musyx/runtime/musyx_runtime_a.h"

extern "C" {

u32 adsrConvertTimeCents(s32 arg0) {
    return (u32)(1000.0f * powf(2.0f, 1.27156579e-08f * (f32)arg0, 1.27156579e-08f));
}

#define arg0 ((u8 *)a0)
s32 salChangeADSRState(void *a0) {
    s32 var_r0;
    s32 var_r5;
    u32 temp_r4_3;
    u32 temp_r4_4;
    u32 temp_r4_6;
    u8 temp_r4;
    u8 temp_r4_2;
    u8 temp_r4_5;
    temp_r4 = *(u8 *)((s8 *)arg0 + 0);
    var_r0 = 0;
    switch ((s32) temp_r4) {
    case 0:
        temp_r4_2 = *(u8 *)((s8 *)arg0 + 1);
        switch ((s32) temp_r4_2) {
        case 0:
            temp_r4_3 = *(u32 *)((s8 *)arg0 + 0x14);
            *(u32 *)((s8 *)arg0 + 4) = temp_r4_3;
            if (temp_r4_3 != 0) {
                *(u8 *)((s8 *)arg0 + 1) = 1U;
                *(s32 *)((s8 *)arg0 + 8) = 0;
                *(u32 *)((s8 *)arg0 + 0x10) = (u32) (0x7FFF0000U / (u32) *(u32 *)((s8 *)arg0 + 0x14));
            } else {
            case 1:
                temp_r4_4 = *(u32 *)((s8 *)arg0 + 0x18);
                *(u32 *)((s8 *)arg0 + 4) = temp_r4_4;
                if (temp_r4_4 != 0) {
                    *(u8 *)((s8 *)arg0 + 1) = 2U;
                    *(s32 *)((s8 *)arg0 + 8) = 0x7FFF0000;
                    *(u32 *)((s8 *)arg0 + 0x10) = (u32) -(s32) ((u32) (0x7FFF0000 - (*(u16 *)((s8 *)arg0 + 0x1C) << 0x10)) / (u32) *(u32 *)((s8 *)arg0 + 0x18));
                } else {
                case 2:
                    if ((u16) *(u16 *)((s8 *)arg0 + 0x1C) != 0) {
                        *(u8 *)((s8 *)arg0 + 1) = 3U;
                        *(s32 *)((s8 *)arg0 + 8) = (s32) (*(u16 *)((s8 *)arg0 + 0x1C) << 0x10);
                        *(u32 *)((s8 *)arg0 + 0x10) = 0U;
                    } else {
                    case 4:
                        *(s32 *)((s8 *)arg0 + 8) = 0;
                        var_r0 = 1;
                    }
                }
            }
            break;
        }
        break;
    case 1:
        temp_r4_5 = *(u8 *)((s8 *)arg0 + 1);
        switch ((s32) temp_r4_5) {
        case 0:
            temp_r4_6 = *(u32 *)((s8 *)arg0 + 0x14);
            *(u32 *)((s8 *)arg0 + 4) = temp_r4_6;
            if (temp_r4_6 != 0) {
                *(u8 *)((s8 *)arg0 + 1) = 1U;
                if ((u8) *(u8 *)((s8 *)arg0 + 0x26) == 0) {
                    *(s32 *)((s8 *)arg0 + 8) = 0;
                    *(u32 *)((s8 *)arg0 + 0x10) = (u32) (0x7FFF0000U / (u32) *(u32 *)((s8 *)arg0 + 4));
                } else {
                    *(s32 *)((s8 *)arg0 + 0xC) = 0;
                    *(s32 *)((s8 *)arg0 + 8) = 0;
                    *(u32 *)((s8 *)arg0 + 0x10) = (u32) (0xC10000U / (u32) *(u32 *)((s8 *)arg0 + 4));
                }
            } else {
            case 1:
                *(u32 *)((s8 *)arg0 + 4) = (u32) ((u32) (*(u32 *)((s8 *)arg0 + 0x18) * ((u32)((0xC1 - *(u16 *)((s8 *)arg0 + 0x1C)) << 0x10) / 193)) >> 0x10U);
                if ((u32) *(u32 *)((s8 *)arg0 + 4) != 0) {
                    *(u8 *)((s8 *)arg0 + 1) = 2U;
                    *(s32 *)((s8 *)arg0 + 8) = 0x7FFF0000;
                    *(s32 *)((s8 *)arg0 + 0xC) = 0xC10000;
                    *(u32 *)((s8 *)arg0 + 0x10) = (u32) -(s32) ((u32) ((0xC1 - *(u16 *)((s8 *)arg0 + 0x1C)) << 0x10) / (u32) *(u32 *)((s8 *)arg0 + 4));
                } else {
                case 2:
                    if ((u16) *(u16 *)((s8 *)arg0 + 0x1C) != 0) {
                        *(u8 *)((s8 *)arg0 + 1) = 3U;
                        *(s32 *)((s8 *)arg0 + 0xC) = (s32) (*(u16 *)((s8 *)arg0 + 0x1C) << 0x10);
                        var_r5 = 0xC1 - ((s32) (*(s32 *)((s8 *)arg0 + 0xC) + 0x8000) >> 0x10);
                        if (var_r5 < 0) {
                            var_r5 = 0;
                        }
                        *(s32 *)((s8 *)arg0 + 8) = (s32) (*(u16 *)((s8 *)((u8 *)(lbl_804F6758) + (var_r5 * 2)) + 0) << 0x10);
                        *(u32 *)((s8 *)arg0 + 0x10) = 0U;
                    } else {
                    case 4:
                        *(s32 *)((s8 *)arg0 + 8) = 0;
                        var_r0 = 1;
                    }
                }
            }
            break;
        }
        break;
    }
    return var_r0;
}
#undef arg0

u32 adsrSetup(u8 *arg0) {
    struct Fields_arg0 { u8 pad_0[1]; s8 field_1; };
    ((Fields_arg0*)arg0)->field_1 = 0;
    return salChangeADSRState((void *)(arg0));
}
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

s32 adsrRelease(struct Envelope_803B431C *e) {
    switch (e->mode) {
    case 0:
    case 1:
        return adsrStartRelease((ADSR_VARS_803B41C8 *)e, e->release);
    default:
        return 0;
    }
}

#define e ((Env_803B4360 *)arg0)
#define out ((u16 *)arg1)
#define dlt ((u16 *)arg2)
u32 adsrHandle(void *arg0, void *arg1, void *arg2) {
    s32 ret = 0;
    s32 old;
    s32 d;
    s32 v;
    switch (e->mode) {
    case 0:
        if (e->phase != 3) {
            old = e->level;
            e->level = old + e->step;
            *out = old >> 16;
            if (e->step >= 0) {
                *dlt = e->step >> 21;
            } else {
                *dlt = -(-e->step >> 21);
            }
            if (--e->remaining == 0) {
                ret = salChangeADSRState(arg0);
            }
        } else {
            *out = e->level >> 16;
            *dlt = 0;
        }
        break;
    case 1:
        if (e->phase != 3) {
            old = e->level;
            if (e->f26 == 0 && e->phase == 1) {
                e->level = old + e->step;
            } else {
                e->c += e->step;
                v = 0xC1 - ((e->c + 0x8000) >> 16);
                if (v < 0) {
                    v = 0;
                }
                e->level = lbl_804F6758[v] << 16;
            }
            *out = old >> 16;
            d = e->level - old;
            if (d >= 0) {
                *dlt = d >> 21;
            } else {
                *dlt = -(-d >> 21);
            }
            if (--e->remaining == 0) {
                ret = salChangeADSRState(arg0);
            }
        } else {
            *out = e->level >> 16;
            *dlt = 0;
        }
        break;
    }
    return ret;
}
#undef e
#undef out
#undef dlt

u32 adsrHandleLowPrecision(void *arg0, void *arg1, void *arg2) {
    u8 i;

    for (i = 0; i < 15; i++) {
        if (adsrHandle((void *)(arg0), (void *)(arg1), (void *)(arg2)) != 0) {
            return 1;
        }
    }
    return 0;
}

}
