#include <string.h>
#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

extern "C" {

extern u8 DebugMacroSteps;
extern SynthVoice *macActiveList;
extern SynthVoice *macTimeQueue;
extern u64 macRealTime;
extern SynthMacroStep cstep;

void DoSetPitch(SynthVoice *svoice);
void varSet32(SynthVoice *svoice, u32 isExCtrl, u8 index, s32 val);
void TimeQueueAdd(SynthVoice *self);
void macMakeActive(SynthVoice *svoice);

#pragma push
#pragma bool off
s32 mcmdWait(SynthVoice *svoice, SynthMacroStep *op) {
    u32 v;
    u32 ms;

    if ((v = op->para[1] >> 16) == 0) {
        goto end;
    }
    if ((op->para[0] >> 8) & 1) {
        if ((svoice->cFlags & 8ULL) != 0) {
            if ((svoice->cFlags & 0x10000000000ULL) == 0) {
                return 0;
            }
            svoice->cFlags |= 0x40000000000ULL;
        }
        svoice->cFlags |= 4ULL;
    } else {
        svoice->cFlags &= ~4ULL;
    }
    if ((op->para[0] >> 24) & 1) {
        if ((svoice->cFlags & 0x20ULL) == 0 && hwIsActive((u8)svoice->id) == 0) {
            return 0;
        }
        svoice->cFlags |= 0x40000ULL;
    } else {
        svoice->cFlags &= ~0x40000ULL;
    }
    if ((op->para[0] >> 16) & 1) {
        v = sndRand() % v;
    }
    if (v != 0xFFFF) {
        if ((ms = ((u8)(op->para[1] >> 8) & 1) != 0)) {
            sndConvertMs(&v);
        } else {
            sndConvertTicks(&v, svoice);
        }
        if (ms != 0) {
            if (op->para[1] & 1) {
                svoice->wait = svoice->macStartTime + v;
            } else {
                svoice->wait = macRealTime + v;
            }
        } else {
            if (op->para[1] & 1) {
                svoice->wait = v;
            } else {
                svoice->wait = svoice->waitTime + v;
            }
        }
        if (svoice->wait <= macRealTime) {
            svoice->waitTime = svoice->wait;
            svoice->wait = 0;
        }
    } else {
        svoice->wait = -1;
    }
    if (svoice->wait != 0) {
        if (svoice->wait != (u64)-1) {
            TimeQueueAdd(svoice);
        }
        macMakeInactive(svoice, 1);
        return 1;
    }
end:
    return 0;
}
#pragma pop

void mcmdLoop(SynthVoice *svoice, SynthMacroStep *op) {
    u32 w;
    if (svoice->loop == 0) {
        if ((op->para[0] >> 16) & 1) {
            svoice->loop = sndRand() % (u16)(op->para[1] >> 16);
        } else {
            svoice->loop = op->para[1] >> 16;
        }
        if (svoice->loop == 0xFFFF) {
            goto body;
        }
        svoice->loop++;
    } else if (svoice->loop == 0xFFFF) {
        goto body;
    }
    if (--svoice->loop == 0) {
        return;
    }
body:
    w = op->para[0];
    if (((w >> 8) & 1) && (svoice->cFlags & 0x10000000008ULL) == 8) {
        svoice->loop = 0;
        return;
    }
    if (((w >> 24) & 1) && (svoice->cFlags & 0x20ULL) == 0 && hwIsActive((u8)svoice->id) == 0) {
        svoice->loop = 0;
        return;
    }
    svoice->curAddr = svoice->addr + (op->para[1] & 0xFFFF);
}

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdPlayMacro(SynthVoice *svoice, SynthMacroStep *step) {
    s32 key;
    u32 new_child;

    key = ((u32)svoice->orgNote + (s8)(u8)(step->para[0] >> 8));
    key = (key < 0) ? 0 : key > 0x7f ? 0x7f : key;

    if (svoice->fxFlag != 0) {
        key |= 0x80;
    }

    svoice->block = 1;
    new_child = macStart((u16)(step->para[0] >> 0x10), (u8)(step->para[1] >> 0x10),
                         (u8)(step->para[1] >> 0x18), svoice->allocId, key,
                         (u8)(svoice->volume >> 0x10), (u8)(svoice->panning[0] >> 0x10), svoice->midi,
                         svoice->midiSet, svoice->section, (u16)step->para[1], (u16)svoice->track, 0,
                         svoice->vGroup, svoice->studio, svoice->itdMode == 0);
    svoice->block = 0;
    if (new_child != 0xFFFFFFFF) {
        svoice->lastVID = synthVoice[(u8)new_child].vidList->vid;
        synthVoice[(u8)new_child].parent = svoice->id;
        if (svoice->child != -1) {
            synthVoice[(u8)new_child].child = svoice->child;
            synthVoice[(u8)svoice->child].parent = new_child;
        }
        svoice->child = new_child;
        if (svoice->fxFlag != 0) {
            synthFXCloneMidiSetup(&synthVoice[(u8)new_child], svoice);
        }
    } else {
        svoice->lastVID = 0xFFFFFFFF;
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdStartSample(SynthVoice *svoice, SynthMacroStep *step) {
    static SampleInfo newsmp;
    u16 smp;
    smp = step->para[0] >> 8;

    if (dataGetSample(smp, &newsmp) != 0) {
        return;
    }
    switch ((u8)(step->para[0] >> 0x18)) {
    case 0:
        newsmp.offset = step->para[1];
        break;
    case 1:
        newsmp.offset = ((u8)(0x7f - (svoice->volume >> 0x10)) * (u32)step->para[1]) / 0x7f;
        break;
    case 2:
        newsmp.offset = ((u8)((svoice->volume >> 0x10)) * (u32)step->para[1]) / 0x7f;
        break;
    default:
        newsmp.offset = 0;
        break;
    }

    if (newsmp.offset >= newsmp.count) {
        newsmp.offset = newsmp.count - 1;
    }

    hwInitSamplePlayback(svoice->id & 0xFF, smp, &newsmp, (svoice->cFlags & 0x100) == 0,
                         ((u32)svoice->prio << 24) | ((u32)svoice->age >> 15), svoice->id,
                         (svoice->cFlags & 0x80000000000) == 0, svoice->itdMode);

    svoice->sInfo = newsmp.key;

    if (svoice->playFrq != -1) {
        DoSetPitch(svoice);
    }
    svoice->cFlags |= 0x20;
    synthKeyStateUpdate(svoice);
}
#pragma pop

void mcmdVibrato(SynthVoice *svoice, SynthMacroStep *op) {
    u32 v;
    s8 hi;
    s8 lo;
    if ((op->para[0] >> 24) & 3) {
        svoice->cFlags |= 0x4000ULL;
    } else {
        svoice->cFlags &= ~0x4000ULL;
    }
    v = op->para[1] >> 16;
    if ((op->para[1] >> 8) & 1) {
        sndConvertMs(&v);
    } else {
        sndConvertTicks(&v, svoice);
    }
    if (v != 0) {
        svoice->cFlags |= 0x2000ULL;
        svoice->vibPeriod = v;
        hi = op->para[0] >> 8;
        lo = op->para[0] >> 16;
        if (hi < 0) {
            if (lo < 0) {
                svoice->vibCentRange = -lo;
            } else {
                svoice->vibCentRange = lo;
            }
            svoice->vibKeyRange = -hi;
            svoice->vibCurTime = svoice->vibPeriod >> 1;
        } else {
            if (lo < 0) {
                if (hi == 0) {
                    svoice->vibCentRange = -lo;
                    svoice->vibCurTime = svoice->vibPeriod >> 1;
                } else {
                    svoice->vibCentRange = 100 - lo;
                    hi--;
                    svoice->vibCurTime = 0;
                }
            } else {
                svoice->vibCentRange = lo;
                svoice->vibCurTime = 0;
            }
            svoice->vibKeyRange = hi;
        }
    } else {
        svoice->cFlags &= ~0x2000ULL;
    }
}

#pragma push
#pragma bool off
#pragma opt_common_subs on
void DoSetPitch(SynthVoice *svoice) {
    u32 f;
    u32 of;
    u32 i;
    u32 frq;
    u32 ofrq;
    u32 no;
    s32 key;
    static u16 kf[13] = {
        4096, 4339, 4597, 4871, 5160, 5467, 5792, 6137, 6502, 6888, 7298, 7732, 8192,
    };

    frq = svoice->playFrq & 0xFFFFFF;
    ofrq = svoice->sInfo & 0xFFFFFF;

    if (ofrq == frq) {
        svoice->curNote = (u8)(svoice->sInfo >> 24);
        svoice->curDetune = 0;
    } else if (ofrq < frq) {
        f = (frq << 12) / ofrq;
        of = f >> 12;

        for (no = 0; no < 11; no++) {
            if (of < (1 << (no + 1))) {
                break;
            }
        }

        f /= (1 << no);

        for (i = 11;; i--) {
            if (f > kf[i]) {
                break;
            }
        }

        svoice->curNote = (svoice->sInfo >> 24) + (no * 12) + i;
        svoice->curDetune = ((f - kf[i]) * 100) / (kf[i + 1] - kf[i]);
    } else {
        f = (ofrq << 12) / frq;
        of = f >> 12;

        for (no = 0; no < 11; no++) {
            if (of < (1 << (no + 1))) {
                break;
            }
        }

        f /= (1 << no);

        for (i = 11;; i--) {
            if (f > kf[i]) {
                break;
            }
        }

        key = i + (no * 12);
        if (key > (s32)(svoice->sInfo >> 24)) {
            svoice->curNote = svoice->curDetune = 0;
        } else {
            svoice->curNote = (svoice->sInfo >> 24) - key;
            svoice->curDetune = ((kf[i] - f) * 100) / (kf[i + 1] - kf[i]);
        }
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetADSR(SynthVoice *svoice, SynthMacroStep *step) {
    SynthADSRInfo adsr;
    SynthADSRInfo *adsr_ptr;
    s32 ascale;
    s32 dscale;
    f32 sScale;

    if ((adsr_ptr = (SynthADSRInfo *)dataGetCurve((u16)(step->para[0] >> 8))) != 0) {
        if (!(u8)(step->para[0] >> 24)) {
            adsr.data.linear.atime = adsr_ptr->data.linear.atime >> 8 | adsr_ptr->data.linear.atime << 8;
            adsr.data.linear.dtime = adsr_ptr->data.linear.dtime >> 8 | adsr_ptr->data.linear.dtime << 8;
            adsr.data.linear.slevel = adsr_ptr->data.linear.slevel >> 8 | adsr_ptr->data.linear.slevel << 8;
            adsr.data.linear.rtime = adsr_ptr->data.linear.rtime >> 8 | adsr_ptr->data.linear.rtime << 8;
            hwSetADSR(svoice->id & 0xFF, &adsr, 0);
        } else {
            sScale = dspDLSVolTab[(u16)(adsr_ptr->data.dls.slevel >> 8 | adsr_ptr->data.dls.slevel << 8) >> 5];
            adsr.data.dls.atime =
                ((u8 *)&adsr_ptr->data.dls.atime)[0] << 0 | ((u8 *)&adsr_ptr->data.dls.atime)[1] << 8 |
                ((u8 *)&adsr_ptr->data.dls.atime)[2] << 16 | ((u8 *)&adsr_ptr->data.dls.atime)[3] << 24;
            adsr.data.dls.dtime =
                ((u8 *)&adsr_ptr->data.dls.dtime)[0] << 0 | ((u8 *)&adsr_ptr->data.dls.dtime)[1] << 8 |
                ((u8 *)&adsr_ptr->data.dls.dtime)[2] << 16 | ((u8 *)&adsr_ptr->data.dls.dtime)[3] << 24;
            adsr.data.dls.slevel = 4096.f * sScale;
            adsr.data.dls.rtime = adsr_ptr->data.dls.rtime >> 8 | adsr_ptr->data.dls.rtime << 8;
            ascale =
                ((u8 *)&adsr_ptr->data.dls.ascale)[0] << 0 | ((u8 *)&adsr_ptr->data.dls.ascale)[1] << 8 |
                ((u8 *)&adsr_ptr->data.dls.ascale)[2] << 16 | ((u8 *)&adsr_ptr->data.dls.ascale)[3] << 24;

            dscale =
                ((u8 *)&adsr_ptr->data.dls.dscale)[0] << 0 | ((u8 *)&adsr_ptr->data.dls.dscale)[1] << 8 |
                ((u8 *)&adsr_ptr->data.dls.dscale)[2] << 16 | ((u8 *)&adsr_ptr->data.dls.dscale)[3] << 24;

            if (ascale != 0x80000000) {
                adsr.data.dls.atime += (s32)(1.1920929e-07f * svoice->orgVolume * ascale);
            }

            if (dscale != 0x80000000) {
                adsr.data.dls.dtime += (s32)(0.0078125f * svoice->orgNote * dscale);
            }

            hwSetADSR(svoice->id & 0xFF, &adsr, 1);
        }

        svoice->cFlags |= 0x100;
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetPitchADSR(SynthVoice *svoice, SynthMacroStep *step) {
    SynthADSRInfo adsr;
    SynthADSRInfo *adsr_ptr;
    u32 sl;
    s32 ascale;
    s32 dscale;

    if ((adsr_ptr = (SynthADSRInfo *)dataGetCurve((u16)(step->para[0] >> 8))) == 0) {
        return;
    }

    svoice->pitchADSRRange = ((s8)step->para[1] << 8);

    if (svoice->pitchADSRRange >= 0) {
        svoice->pitchADSRRange += ((s16)(s8)(step->para[1] >> 8) << 8) / 100;
    } else {
        svoice->pitchADSRRange -= ((s16)(s8)(step->para[1] >> 8) << 8) / 100;
    }

    adsr.data.dls.atime =
        (((u8 *)&adsr_ptr->data.dls.atime)[0] << 0) | (((u8 *)&adsr_ptr->data.dls.atime)[1] << 8) |
        (((u8 *)&adsr_ptr->data.dls.atime)[2] << 16) | (((u8 *)&adsr_ptr->data.dls.atime)[3] << 24);
    adsr.data.dls.dtime =
        (((u8 *)&adsr_ptr->data.dls.dtime)[0] << 0) | (((u8 *)&adsr_ptr->data.dls.dtime)[1] << 8) |
        (((u8 *)&adsr_ptr->data.dls.dtime)[2] << 16) | (((u8 *)&adsr_ptr->data.dls.dtime)[3] << 24);

    adsr.data.dls.slevel = (adsr_ptr->data.dls.slevel >> 8) | (adsr_ptr->data.dls.slevel << 8);
    adsr.data.dls.rtime = (adsr_ptr->data.dls.rtime >> 8) | (adsr_ptr->data.dls.rtime << 8);
    ascale =
        (((u8 *)&adsr_ptr->data.dls.ascale)[0] << 0) | (((u8 *)&adsr_ptr->data.dls.ascale)[1] << 8) |
        (((u8 *)&adsr_ptr->data.dls.ascale)[2] << 16) | (((u8 *)&adsr_ptr->data.dls.ascale)[3] << 24);
    dscale =
        (((u8 *)&adsr_ptr->data.dls.dscale)[0] << 0) | (((u8 *)&adsr_ptr->data.dls.dscale)[1] << 8) |
        (((u8 *)&adsr_ptr->data.dls.dscale)[2] << 16) | (((u8 *)&adsr_ptr->data.dls.dscale)[3] << 24);

    if (ascale != 0x80000000) {
        adsr.data.dls.atime += (s32)((1.1920929e-07f * svoice->orgVolume) * (f32)ascale);
    }
    if (dscale != 0x80000000) {
        adsr.data.dls.dtime += (s32)((0.0078125f * svoice->orgNote) * (f32)dscale);
    }

    svoice->pitchADSR.mode = 1;
    svoice->pitchADSR.data.dls.aMode = 0;
    svoice->pitchADSR.data.dls.aTime = adsrConvertTimeCents(adsr.data.dls.atime);
    svoice->pitchADSR.data.dls.dTime = adsrConvertTimeCents(adsr.data.dls.dtime);
    if ((sl = (adsr.data.dls.slevel >> 2)) > 0x3ff) {
        sl = 0x3ff;
    }

    svoice->pitchADSR.data.dls.sLevel = 193 - dspScale2IndexTab[sl];
    svoice->pitchADSR.data.dls.rTime = adsr.data.dls.rtime;
    adsrSetup(&svoice->pitchADSR);
    svoice->cFlags |= 0x20000000000;
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void DoPanningSetup(SynthVoice *svoice, SynthMacroStep *step, u8 pi) {
    u32 mstime;
    s32 width;
    width = (u16)(step->para[0] >> 16);
    svoice->panTime[pi] = width;
    sndConvertMs(&svoice->panTime[pi]);
    mstime = (s8)(step->para[1]);
    svoice->panning[pi] = ((u8)(step->para[0] >> 8)) << 16;
    svoice->panTarget[pi] = svoice->panning[pi] + (mstime << 16);
    if (svoice->panTime[pi] != 0) {
        svoice->panDelta[pi] = (s32)(mstime << 16) / width;
    } else {
        svoice->panDelta[pi] = (s32)(mstime << 16);
    }

    svoice->cFlags |= 0x200000000000;
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
u32 TranslateVolume(u32 volume, u16 curve) {
    u8 *ptr;
    u32 vlow;
    u32 vhigh;
    s32 d;

    if (curve != 0xFFFF) {
        if ((ptr = (u8 *)dataGetCurve(curve))) {
            vhigh = (volume >> 16) & 0xFFFF;
            vlow = volume & 0xFFFF;

            if (vhigh < 0x7f) {
                d = vlow * (ptr[vhigh + 1] - ptr[vhigh]);
                volume = d + (ptr[vhigh] << 16);
            } else {
                volume = ptr[vhigh] << 16;
            }
        }
    }

    return volume;
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
static inline u32 TranslateVolumeInline(u32 volume, u16 curve) {
    u8 *ptr;
    u32 vlow;
    u32 vhigh;
    s32 d;

    if (curve != 0xFFFF) {
        if ((ptr = (u8 *)dataGetCurve(curve))) {
            vhigh = (volume >> 16) & 0xFFFF;
            vlow = volume & 0xFFFF;

            if (vhigh < 0x7f) {
                d = vlow * (ptr[vhigh + 1] - ptr[vhigh]);
                volume = d + (ptr[vhigh] << 16);
            } else {
                volume = ptr[vhigh] << 16;
            }
        }
    }

    return volume;
}

void DoEnvelopeCalculation(SynthVoice *svoice, SynthMacroStep *step, s32 start_vol) {
    u32 tvol;
    u32 time;
    s32 mstime;
    u16 curve;

    time = (u16)(step->para[1] >> 16);

    if ((u8)(step->para[1] >> 8) & 1) {
        sndConvertMs(&time);
    } else {
        sndConvertTicks(&time, svoice);
    }

    mstime = sndConvert2Ms(time);
    if (mstime == 0) {
        mstime = 1;
    }

    tvol = (svoice->volume * (u8)(step->para[0] >> 8) >> 7);
    tvol += (u8)(step->para[0] >> 16) << 16;

    if (tvol > 0x7f0000) {
        tvol = 0x7f0000;
    }

    curve = (u16)(u8)(step->para[0] >> 0x18);
    curve |= (((u16)(u8)step->para[1]) << 8);
    tvol = TranslateVolumeInline(tvol, curve);
    svoice->envTarget = tvol;
    svoice->envCurrent = start_vol;
    svoice->envDelta = (s32)(tvol - start_vol) / mstime;
    svoice->volume = start_vol;
    svoice->cFlags |= 0x8000;
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
static inline u32 mcmdSetKeyInline(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->curNote = (u8)(step->para[0] >> 8) & 0x7f;
    svoice->curDetune = (s8)(step->para[0] >> 0x10);
    if ((u32)voiceIsLastStarted(svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote & 0xff);
    }
    step->para[0] = 4;
    return mcmdWait(svoice, step);
}

void mcmdRandomKey(SynthVoice *svoice, SynthMacroStep *step) {
    u8 k1;
    u8 k2;
    u8 t;
    s32 i1;
    s32 i2;
    u8 detune;

    if (!(u8)(step->para[1] >> 8)) {
        k1 = (step->para[0] >> 8);
        k2 = (step->para[0] >> 24);
        if (k1 > k2) {
            t = k1;
            k1 = k2;
            k2 = t;
        }
    } else {
        i1 = svoice->curNote - (u8)(step->para[0] >> 8);
        i2 = svoice->curNote + (u8)(step->para[0] >> 24);

        k1 = i1 < 0 ? 0 : i1 > 127 ? 127 : i1;
        k2 = i2 < 0 ? 0 : i2 > 127 ? 127 : i2;
    }

    if ((u8)step->para[1]) {
        detune = (sndRand() % 201) - 100;
    } else {
        detune = (u8)(step->para[0] >> 16);
    }

    step->para[0] = ((u8)detune << 16) | 0x19 | ((k1 + (sndRand() % ((k2 - k1) + 1))) * 0x100);
    step->para[1] = 0;
    mcmdSetKeyInline(svoice, step);
}
#pragma pop

void SelectSource(SynthVoice *svoice, CtrlDest *ch, SynthMacroStep *op, u64 mask, u32 flag) {
    u8 x;
    u32 w0;
    s32 v;

    if ((svoice->cFlags & mask) == 0) {
        svoice->cFlags |= mask;
        x = 0;
    } else {
        x = op->para[1];
    }
    w0 = op->para[0];
    v = (s32)(w0 & 0xFFFF0000) / 100;
    if (v < 0) {
        v -= ((s8)(op->para[1] >> 16) << 8) / 100;
    } else {
        v += ((s8)(op->para[1] >> 16) << 8) / 100;
    }
    inpAddCtrl(ch, w0 >> 8, v, x, (u8)(op->para[1] >> 8) != 0);
    if (flag & 0x80000000) {
        inpSetGlobalMIDIDirtyFlag(svoice->midi, svoice->midiSet, flag);
    } else {
        svoice->midiDirtyFlags |= flag;
    }
}

void mcmdPortamento(SynthVoice *svoice, SynthMacroStep *op) {
    u32 v;

    svoice->portType = op->para[0] >> 16;
    v = op->para[1] >> 16;
    if ((op->para[1] >> 8) & 1) {
        sndConvertMs(&v);
    } else {
        sndConvertTicks(&v, svoice);
    }
    svoice->portDuration = v;
    switch ((u8)(op->para[0] >> 8)) {
    case 0:
        if (svoice->midi != 0xFF) {
            inpSetMidiCtrl(0x41, svoice->midi, svoice->midiSet, 0);
        }
        svoice->cFlags &= ~0x400ULL;
        break;
    case 1:
        if (svoice->midi != 0xFF) {
            inpSetMidiCtrl(0x41, svoice->midi, svoice->midiSet, 0x7F);
        }
    on:
        if ((svoice->cFlags & 0x400ULL) == 0) {
            synthInitPortamento(svoice);
        }
        svoice->cFlags |= 0x400ULL;
        break;
    case 2:
        if (svoice->midi != 0xFF && inpGetMidiCtrl(0x41, svoice->midi, svoice->midiSet) > 0x1F80) {
            goto on;
        }
        break;
    }
}

s32 varGet32(SynthVoice *svoice, u32 isExCtrl, u32 index) {
    if (isExCtrl != 0) {
        return inpGetExCtrl(svoice, index);
    }
    index = index & 0x1F;
    if (index < 0x10) {
        return svoice->local_vars[index];
    }
    return synthGlobalVariable[index - 16];
}

s16 varGet(SynthVoice *svoice, u32 isExCtrl, u32 index) {
    s32 r;
    if (isExCtrl != 0) {
        r = (u16)inpGetExCtrl(svoice, index);
    } else {
        index = index & 0x1F;
        if (index < 0x10) {
            r = svoice->local_vars[index];
        } else {
            r = synthGlobalVariable[index - 16];
        }
    }
    return r;
}

void varSet32(SynthVoice *svoice, u32 isExCtrl, u8 index, s32 val) {
    if (isExCtrl != 0) {
        inpSetExCtrl(svoice, index, val);
        return;
    }
    index &= 0x1F;
    if (index < 0x10) {
        svoice->local_vars[index] = val;
        return;
    }
    synthGlobalVariable[index - 16] = val;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline s16 varGetInline(SynthVoice *svoice, u32 ctrl, u8 index) {
    return varGet32(svoice, ctrl, index);
}

static inline void varSetInline(SynthVoice *svoice, u32 ctrl, u8 index, s16 v) {
    varSet32(svoice, ctrl, index, v);
}

void mcmdVarCalculation(SynthVoice *svoice, SynthMacroStep *step, u8 op) {
    s16 s1;
    s16 s2;
    s32 t;

    s1 = varGetInline(svoice, (u8)(step->para[0] >> 24), step->para[1]);
    if (op == 4) {
        s2 = step->para[1] >> 8;
    } else {
        s2 = varGetInline(svoice, (u8)(step->para[1] >> 8), step->para[1] >> 16);
    }
    switch (op) {
    case 4:
    case 0:
        t = (s1 + s2);
        break;
    case 1:
        t = (s1 - s2);
        break;
    case 2:
        t = (s1 * s2);
        break;
    case 3:
        t = s2 != 0 ? (s1 / s2) : 0;
        break;
    }

    varSetInline(svoice, (u8)(step->para[0] >> 8), (u8)(step->para[0] >> 0x10),
                 (t < -0x8000 ? -0x8000 : t > 0x7FFF ? 0x7FFF : t));
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 varGetLocal32(SynthVoice *svoice, u32 ctrl, u8 index) {
    index &= 0x1f;
    return index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
}

static inline u32 ExecuteTrap(SynthVoice *svoice, u8 trapType) {
    if (svoice->trapEventAny != 0 && svoice->trapEventAddr[trapType] != NULL) {
        svoice->curAddr = svoice->trapEventCurAddr[trapType];
        svoice->addr = svoice->trapEventAddr[trapType];
        svoice->trapEventAddr[trapType] = NULL;
        macMakeActive(svoice);
        return 1;
    }
    return 0;
}

static inline u32 macPostMessage(u32 vid, s32 mesg) {
    SynthVoice *sv;
    if ((vid = vidGetInternalId(vid)) != -1 && (sv = &synthVoice[vid & 0xFF])->mesgNum < 4) {
        ++sv->mesgNum;
        sv->mesgQueue[sv->mesgWrite] = mesg;
        sv->mesgWrite = (sv->mesgWrite + 1) & 3;
        ExecuteTrap(sv, 2);
        return 1;
    }
    return 0;
}

void mcmdSendMessage(SynthVoice *svoice, SynthMacroStep *step) {
    u8 i;
    s32 mesg;
    u16 macro;

    {
        u8 index = (u8)(step->para[1] >> 8);
        index &= 0x1f;
        mesg = index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
    }

    if (!(u8)(step->para[0] >> 8)) {
        macro = (u16)(step->para[0] >> 16);
        if (macro != 0xFFFF) {
            i = 0;
            while (i < synthInfo.voiceNum) {
                if (synthVoice[i].addr != NULL && macro == synthVoice[i].macroId) {
                    macPostMessage(synthVoice[i].vidList->vid, mesg);
                }
                ++i;
            }
        } else if (synthMessageCallback != 0) {
            synthMessageCallback(svoice->vidList->vid, mesg);
        }
    } else {
        macPostMessage(varGetLocal32(svoice, 0, (u8)step->para[1]), mesg);
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetKeyGroup(SynthVoice *svoice, SynthMacroStep *step) {
    u32 i;
    u8 kg;
    u32 kill;

    svoice->keyGroup = 0;
    kg = (u8)(step->para[0] >> 8);
    kill = (u8)(step->para[0] >> 0x10) != 0;

    if (kg) {
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (synthVoice[i].addr != NULL && (synthVoice[i].cFlags & 0x2) == 0 &&
                kg == synthVoice[i].keyGroup) {
                if (!kill) {
                    macSetExternalKeyoff(&synthVoice[i]);
                } else {
                    voiceKill(i);
                }
            }
        }
        svoice->keyGroup = kg;
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
static inline int SendSingleKeyOff(u32 voiceid) {
    u32 i;
    if (voiceid != 0xFFFFFFFF) {
        i = voiceid & 0xFF;
        if (voiceid == synthVoice[i].id) {
            macSetExternalKeyoff(&synthVoice[i]);
            return 0;
        }
    }
    return -1;
}

static inline u32 mcmdWaitMs(SynthVoice *svoice, SynthMacroStep *step) {
    ((u8 *)&step->para[1])[2] = 1;
    return mcmdWait(svoice, step);
}

static inline u32 mcmdEndOfMacro(SynthVoice *svoice) {
    vidRemoveVoiceReferences(svoice);
    voiceFree(svoice);
    return 1;
}

static inline u32 mcmdStop(SynthVoice *svoice) {
    return mcmdEndOfMacro(svoice);
}

static inline u32 mcmdReturn(SynthVoice *svoice) {
    if (svoice->callStackEntryNum != 0) {
        svoice->addr = svoice->callStack[svoice->callStackIndex].addr;
        svoice->curAddr = svoice->callStack[svoice->callStackIndex].curAddr;
        svoice->callStackIndex = (svoice->callStackIndex - 1) & 3;
        --svoice->callStackEntryNum;
    }
    return 0;
}

static inline void mcmdIfKey(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    if (svoice->curNote < ((u8)(step->para[0] >> 8))) {
        return;
    }
    if ((addr = (SynthMacroStep *)dataGetMacro((step->para[0] >> 0x10))) != 0) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)step->para[1];
    }
}

static inline void mcmdIfVelocity(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    if (((u8)(svoice->volume >> 0x10)) < (u8)(step->para[0] >> 8)) {
        return;
    }
    if ((addr = (SynthMacroStep *)dataGetMacro(step->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)step->para[1];
    }
}

static inline void mcmdIfModulation(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    u8 mod;
    if (svoice->midi == 0xff) {
        return;
    }
    mod = inpGetModulation(svoice) >> 7;
    if (mod < (u8)(step->para[0] >> 8)) {
        return;
    }
    if ((addr = (SynthMacroStep *)dataGetMacro(step->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)(step->para[1]);
    }
}

static inline void mcmdIfRandom(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    if ((u8)sndRand() < (u8)(step->para[0] >> 8)) {
        return;
    }
    if ((addr = (SynthMacroStep *)dataGetMacro(step->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)step->para[1];
    }
}

static inline u32 mcmdGoto(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    if ((addr = (SynthMacroStep *)dataGetMacro(step->para[0] >> 0x10)) != 0) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)step->para[1];
        return 0;
    }
    return mcmdEndOfMacro(svoice);
}

static inline u32 mcmdGosub(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    if ((addr = (SynthMacroStep *)dataGetMacro((u16)(step->para[0] >> 0x10))) != 0) {
        svoice->callStackIndex = (svoice->callStackIndex + 1) & 3;
        svoice->callStack[svoice->callStackIndex].addr = svoice->addr;
        svoice->callStack[svoice->callStackIndex].curAddr = svoice->curAddr;
        if (++svoice->callStackEntryNum > 4) {
            svoice->callStackEntryNum = 4;
        }
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)step->para[1];
        return 0;
    }
    return mcmdEndOfMacro(svoice);
}

static inline void mcmdTrapEvent(SynthVoice *svoice, SynthMacroStep *step) {
    SynthMacroStep *addr;
    u8 t;
    if ((addr = (SynthMacroStep *)dataGetMacro(step->para[0] >> 0x10)) != 0) {
        t = (u8)(step->para[0] >> 8);
        svoice->trapEventAddr[t] = addr;
        svoice->trapEventCurAddr[t] = addr + (u16)step->para[1];
        svoice->trapEventAny = 1;
        if (t == 0 && (svoice->cFlags & 0x10000000008) == 0x10000000008) {
            svoice->cFlags |= 0x40000000000;
        }
    }
}

static inline void mcmdUntrapEvent(SynthVoice *svoice, SynthMacroStep *step) {
    u8 i;
    svoice->trapEventAddr[(u8)(step->para[0] >> 8)] = 0;
    for (i = 0; i < 3; ++i) {
        if (svoice->trapEventAddr[i] != 0) {
            return;
        }
    }
    svoice->trapEventAny = 0;
}

static inline void mcmdSendKeyOff(SynthVoice *svoice, SynthMacroStep *step) {
    u32 voiceid;
    u32 i;
    voiceid = (svoice->orgNote + (u8)(step->para[0] >> 8)) << 8;
    voiceid |= ((u16)(step->para[0] >> 16)) << 16;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        if (synthVoice[i].id == (voiceid | i)) {
            SendSingleKeyOff(voiceid | i);
        }
    }
}

static inline void mcmdAddAgeCounter(SynthVoice *svoice, SynthMacroStep *step) {
    s16 stepVal;
    s32 age;
    stepVal = (u16)(step->para[0] >> 16);
    age = (svoice->age >> 15) + stepVal;
    if (age < 0) {
        svoice->age = 0;
    } else if (age > 0xFFFF) {
        svoice->age = 0x7fff8000;
    } else {
        svoice->age = age * 0x8000;
    }
    hwSetPriority(svoice->id & 0xFF, ((u32)svoice->prio << 24) | ((u32)svoice->age >> 15));
}

static inline void mcmdSetAgeCounter(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->age = (u16)(step->para[0] >> 0x10) << 0xf;
    hwSetPriority(svoice->id & 0xff, (u32)svoice->prio << 0x18 | svoice->age >> 0xf);
}

static inline void mcmdSetAgeCounterSpeed(SynthVoice *svoice, SynthMacroStep *step) {
    u32 time = step->para[1];
    if (time != 0) {
        svoice->ageSpeed = (svoice->age >> 8) / time;
    } else {
        svoice->ageSpeed = 0;
    }
}

static inline void mcmdSetAgeCounterByVolume(SynthVoice *svoice, SynthMacroStep *step) {
    u32 age;
    age = (((u8)(svoice->volume >> 16) * (u16)step->para[1]) >> 7) + (u16)(step->para[0] >> 16);
    svoice->age = age > 60000 ? 0x75300000 : age * 0x8000;
    hwSetPriority(svoice->id & 0xff, (u32)svoice->prio << 0x18 | svoice->age >> 0xf);
}

static inline void mcmdAddPriority(SynthVoice *svoice, SynthMacroStep *step) {
    s16 add;
    s16 prio;
    add = (u16)(step->para[0] >> 16);
    prio = svoice->prio + add;
    prio = (prio < 0) ? 0 : (prio > 0xFF) ? 0xFF : prio;
    voiceSetPriority(svoice, prio);
}

static inline void mcmdSetPriority(SynthVoice *svoice, SynthMacroStep *step) {
    voiceSetPriority(svoice, step->para[0] >> 8);
}

static inline void mcmdSendFlag(SynthMacroStep *step) {
    synthGlobalVariable[(u8)(step->para[0] >> 8)] = (u8)(step->para[0] >> 16);
}

static inline void mcmdSetPitchWheelRange(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->pbLowerKeyRange = (u8)(step->para[0] >> 0x10);
    svoice->pbUpperKeyRange = (u8)(step->para[0] >> 8);
}

static inline u32 mcmdSetKey(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->curNote = (u8)(step->para[0] >> 8) & 0x7f;
    svoice->curDetune = (s8)(step->para[0] >> 0x10);
    if ((u32)voiceIsLastStarted(svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote & 0xff);
    }
    step->para[0] = 4;
    return mcmdWait(svoice, step);
}

static inline u32 mcmdAddKey(SynthVoice *svoice, SynthMacroStep *step) {
    if ((u8)(step->para[0] >> 0x18) == 0) {
        svoice->curNote += (s8)(u8)(step->para[0] >> 8);
    } else {
        svoice->curNote = (u16)svoice->orgNote + (s16)(s8)(u8)(step->para[0] >> 8);
    }
    svoice->curNote = (s16)svoice->curNote < 0 ? 0 : svoice->curNote > 0x7f ? 0x7f : svoice->curNote;
    svoice->curDetune = (s8)(step->para[0] >> 0x10);
    if ((u32)voiceIsLastStarted(svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote);
    }
    step->para[0] = 4;
    return mcmdWait(svoice, step);
}

static inline u32 mcmdLastKey(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->curNote = svoice->lastNote + (s8)(u8)(step->para[0] >> 8);
    svoice->curNote = (s16)svoice->curNote < 0 ? 0 : svoice->curNote > 0x7f ? 0x7f : svoice->curNote;
    svoice->curDetune = (s8)(step->para[0] >> 16);
    if (svoice->midi != 0xFF) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote);
    }
    step->para[0] = 4;
    return mcmdWait(svoice, step);
}

static inline void mcmdStopSample(SynthVoice *svoice) {
    hwBreak(svoice->id & 0xFF);
}

static inline void mcmdKeyOff(SynthVoice *svoice) {
    svoice->cFlags |= 0x80;
    synthKeyStateUpdate(svoice);
}

static inline void mcmdSetMod2Vibrato(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->vibModAddScale = (s8)(step->para[0] >> 8) << 8;
    if (svoice->vibModAddScale >= 0) {
        svoice->vibModAddScale += ((s16)(s8)(step->para[0] >> 0x10) << 8) / 100;
    } else {
        svoice->vibModAddScale -= ((s16)(s8)(step->para[0] >> 0x10) << 8) / 100;
    }
}

static inline void mcmdSetupLFO(SynthVoice *svoice, SynthMacroStep *step) {
    u32 time;
    u32 phase;
    u8 n;
    n = (u8)(step->para[0] >> 8);
    time = (u16)(step->para[0] >> 0x10);
    sndConvertMs(&time);
    if (svoice->lfo[n].period != 0) {
        phase = (u16)step->para[1];
        sndConvertMs(&phase);
        svoice->lfo[n].time = phase;
    }
    svoice->lfo[n].period = time;
}

static inline void mcmdSetPitch(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->playFrq = (u32)(step->para[0] >> 8);
    svoice->playFrq |= (u8)step->para[1];
    if (svoice->sInfo != -1) {
        DoSetPitch(svoice);
    }
}

static s32 midi2TimeTab[128] = {
    0,      10,     20,     30,     40,     50,     60,     70,     80,     90,     100,    110,    110,
    120,    130,    140,    150,    160,    170,    190,    200,    220,    230,    250,    270,    290,
    310,    330,    350,    380,    410,    440,    470,    500,    540,    580,    620,    660,    710,
    760,    820,    880,    940,    1000,   1000,   1100,   1200,   1300,   1400,   1500,   1600,   1700,
    1800,   2000,   2100,   2300,   2400,   2600,   2800,   3000,   3200,   3500,   3700,   4000,   4300,
    4600,   4900,   5300,   5700,   6100,   6500,   7000,   7500,   8100,   8600,   9300,   9900,   10000,
    11000,  12000,  13000,  14000,  15000,  16000,  17000,  18000,  19000,  21000,  22000,  24000,  26000,
    28000,  30000,  32000,  34000,  37000,  39000,  42000,  45000,  49000,  50000,  55000,  60000,  65000,
    70000,  75000,  80000,  85000,  90000,  95000,  100000, 105000, 110000, 115000, 120000, 125000, 130000,
    135000, 140000, 145000, 150000, 155000, 160000, 165000, 170000, 175000, 180000, 0,
};

static inline void mcmdSetADSRFromCtrl(SynthVoice *svoice, SynthMacroStep *step) {
    f32 sScale;
    SynthADSRInfo adsr;
    sScale = dspDLSVolTab[inpGetMidiCtrl(step->para[0] >> 24, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.atime = midi2TimeTab[inpGetMidiCtrl(step->para[0] >> 8, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.dtime = midi2TimeTab[inpGetMidiCtrl(step->para[0] >> 16, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.slevel = 193 - dspScale2IndexTab[(u32)(1023.f * sScale)];
    adsr.data.dls.rtime = midi2TimeTab[inpGetMidiCtrl(step->para[1], svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.ascale = -0x80000000;
    adsr.data.dls.dscale = -0x80000000;
    hwSetADSR((u8)svoice->id, &adsr, 2);
    svoice->cFlags |= 0x100;
}

static inline u32 mcmdPitchSweep(SynthVoice *svoice, SynthMacroStep *step, int num) {
    s32 delta;
    svoice->sweepOff[num] = 0;
    svoice->sweepNum[num] = (u8)(step->para[0] >> 8);
    svoice->sweepCnt[num] = (s32)svoice->sweepNum[num] << 0x10;
    delta = (int)(short)(step->para[0] >> 0x10);
    if (delta >= 0) {
        delta = hwFrq2Pitch(delta);
    } else {
        delta = -hwFrq2Pitch(-delta);
    }
    svoice->sweepAdd[num] = delta << 0x10;
    step->para[0] = 0;
    return mcmdWait(svoice, step);
}

static inline void mcmdSetPanning(SynthVoice *svoice, SynthMacroStep *step) {
    DoPanningSetup(svoice, step, 0);
}

static inline void mcmdSetSurroundPanning(SynthVoice *svoice, SynthMacroStep *step) {
    DoPanningSetup(svoice, step, 1);
}

static inline void mcmdSetPianoPanning(SynthVoice *svoice, SynthMacroStep *step) {
    s32 delta;
    s32 scale;
    delta = (svoice->curNote << 16) - ((u8)(step->para[0] >> 16) << 16);
    scale = (s8)((u8)(step->para[0] >> 8));
    delta = ((delta * scale) >> 7);
    delta += (u8)(step->para[0] >> 0x18) << 16;
    delta = delta < 0 ? 0 : delta > 0x7f0000 ? 0x7f0000 : delta;
    svoice->panTarget[0] = delta;
    svoice->panning[0] = delta;
}

static inline void mcmdScaleVolume(SynthVoice *svoice, SynthMacroStep *step) {
    u16 curve;
    u16 scale;
    scale = (u16)(u8)(step->para[0] >> 8);
    if ((u8)(step->para[1] >> 8) == 0) {
        svoice->volume = (svoice->volume * scale) / 0x7f;
    } else {
        svoice->volume = (svoice->orgVolume * scale) / 0x7f;
    }
    svoice->volume += (u8)(step->para[0] >> 16) << 16;
    if (svoice->volume > 0x7f0000) {
        svoice->volume = 0x7f0000;
    }
    curve = (u8)(step->para[0] >> 0x18);
    curve |= ((u16)((u8)step->para[1]) << 8);
    svoice->volume = TranslateVolume(svoice->volume, curve);
    svoice->cFlags |= 0x100000000000;
}

static inline void mcmdScaleVolumeDLS(SynthVoice *svoice, SynthMacroStep *step) {
    u16 scale;
    scale = (step->para[0] >> 8);
    if ((u8)(step->para[0] >> 0x18) == 0) {
        svoice->volume = ((svoice->volume >> 5) * scale) >> 7;
    } else {
        svoice->volume = ((svoice->orgVolume >> 5) * scale) >> 7;
    }
    if (svoice->volume > 0x7f0000) {
        svoice->volume = 0x7f0000;
    }
    svoice->cFlags |= 0x100000000000;
}

static inline void mcmdEnvelope(SynthVoice *svoice, SynthMacroStep *step) {
    DoEnvelopeCalculation(svoice, step, svoice->volume);
}

static inline void mcmdFadeIn(SynthVoice *svoice, SynthMacroStep *step) {
    DoEnvelopeCalculation(svoice, step, 0);
}

static inline void mcmdSetPitchbendAfterKeyOff(SynthVoice *svoice) {
    svoice->cFlags |= 0x10000;
}

static inline void mcmdScaleReverb(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->revVolScale = (u8)(step->para[0] >> 8);
    svoice->revVolOffset = (u8)(step->para[0] >> 0x10);
}

static inline void mcmdVolumeSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpVolume, step, 0x80000, 1);
}

static inline void mcmdPanningSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPanning, step, 0x100000, 2);
}

static inline void mcmdPitchWheelSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPitchBend, step, 0x200000, 8);
}

static inline void mcmdModWheelSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpModulation, step, 0x400000, 0x20);
}

static inline void mcmdPedalSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPedal, step, 0x2000000, 0x40);
}

static inline void mcmdPortamentoSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPortamento, step, 0x1000000, 0x80);
}

static inline void mcmdReverbSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpReverb, step, 0x800000, 0x200);
}

static inline void mcmdPreAuxASelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPreAuxA, step, 0x20000000, 0x100);
}

static inline void mcmdPreAuxBSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPreAuxB, step, 0x40000000, 0x400);
}

static inline void mcmdPostAuxBSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpPostAuxB, step, 0x80000000, 0x800);
}

static inline void mcmdSurroundPanningSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpSurroundPanning, step, 0x4000000, 4);
}

static inline void mcmdDopplerSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpDoppler, step, 0x8000000, 0x10);
}

static inline void mcmdTremoloSelect(SynthVoice *svoice, SynthMacroStep *step) {
    SelectSource(svoice, &svoice->inpTremolo, step, 0x10000000, 0x1000);
}

static inline void mcmdAuxAFXSelect(SynthVoice *svoice, SynthMacroStep *step) {
    u32 i;
    static u64 mask[4] = {0x100000000, 0x200000000, 0x400000000, 0x800000000};
    static u32 dirty[4] = {0x80000001, 0x80000002, 0x80000004, 0x80000008};
    i = (u8)(step->para[1] >> 0x18);
    SelectSource(svoice, &inpAuxA[svoice->studio][i], step, mask[i], dirty[i]);
}

static inline void mcmdAuxBFXSelect(SynthVoice *svoice, SynthMacroStep *step) {
    u32 i;
    static u64 mask[4] = {0x1000000000, 0x2000000000, 0x4000000000, 0x8000000000};
    static u32 dirty[4] = {0x80000010, 0x80000020, 0x80000040, 0x80000080};
    i = (u8)(step->para[1] >> 0x18);
    SelectSource(svoice, &inpAuxB[svoice->studio][i], step, mask[i], dirty[i]);
}

static inline s32 varGet32Inline(SynthVoice *svoice, u32 ctrl, u8 index) {
    if (ctrl != 0) {
        return inpGetExCtrl(svoice, index);
    }
    index &= 0x1f;
    return index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
}

static inline void mcmdSetVarImmediate(SynthVoice *svoice, SynthMacroStep *step) {
    varSetInline(svoice, (u8)(step->para[0] >> 8), (u8)(step->para[0] >> 0x10), (s16)step->para[1]);
}

static inline void mcmdIfVarCompare(SynthVoice *svoice, SynthMacroStep *step, u8 cmp) {
    s32 a;
    s32 b;
    u8 result;
    a = varGet32Inline(svoice, (u8)(step->para[0] >> 8), (u8)(step->para[0] >> 0x10));
    b = varGet32Inline(svoice, (u8)(step->para[0] >> 0x18), (u8)step->para[1]);
    switch (cmp) {
    case 0:
        result = !(b - a);
        break;
    case 1:
        result = (a < b);
        break;
    }
    if ((u8)(step->para[1] >> 8) != 0) {
        result = !result;
    }
    if ((u8)result != 0) {
        svoice->curAddr = svoice->addr + (u16)(step->para[1] >> 0x10);
    }
}

static inline void mcmdGetMessage(SynthVoice *svoice, SynthMacroStep *step) {
    s32 mesg;
    mesg = 0;
    if (svoice->mesgNum != 0) {
        mesg = svoice->mesgQueue[svoice->mesgRead];
        svoice->mesgRead = (svoice->mesgRead + 1) & 3;
        --svoice->mesgNum;
    }
    varSet32(svoice, 0, (u8)(step->para[0] >> 8), mesg);
}

static inline void mcmdGetVID(SynthVoice *svoice, SynthMacroStep *step) {
    if ((u8)(step->para[0] >> 0x10) == 0) {
        varSet32(svoice, 0, (u8)(step->para[0] >> 8), svoice->vidList->vid);
    } else {
        varSet32(svoice, 0, (u8)(step->para[0] >> 8), svoice->lastVID);
    }
}

static inline void mcmdModeSelect(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->volTable = (u8)(step->para[0] >> 8) ? 1 : 0;
    svoice->itdMode = (u8)(step->para[0] >> 0x10) ? 0 : 1;
}

static inline void mcmdSRCModeSelect(SynthVoice *svoice, SynthMacroStep *step) {
    hwSetSRCType(svoice->id & 0xff, (u8)(step->para[0] >> 8));
    hwSetPolyPhaseFilter(svoice->id & 0xff, (u8)(step->para[0] >> 0x10));
    svoice->cFlags |= 0x80000000000;
}

static inline void mcmdSetupTremolo(SynthVoice *svoice, SynthMacroStep *step) {
    svoice->treScale = (step->para[0] >> 8);
    svoice->treModAddScale = step->para[1];
    svoice->treCurScale = 1.f;
}

void macHandleActive(SynthVoice *svoice) {
    u8 i;
    u8 lastNote;
    u32 ex;
    SynthChannelDefaults *channelDefaults;
    if (svoice->cFlags & 3) {
        if (svoice->cFlags & 1) {
            svoice->cFlags &= ~1;
            hwBreak(svoice->id & 0xFF);
        }
        svoice->panning[0] = svoice->panTarget[0] = (u32)(svoice->setup.pan) << 16;
        svoice->panning[1] = svoice->panTarget[1] = 0;
        svoice->volume = (u32)(svoice->setup.vol << 16);
        svoice->volTable = 0;
        svoice->orgVolume = svoice->volume;
        svoice->midi = svoice->setup.midi;
        svoice->midiSet = svoice->setup.midiSet;
        svoice->section = svoice->setup.section;
        svoice->track = svoice->setup.track;
        svoice->itdMode = svoice->setup.itdMode;
        svoice->keyGroup = 0;
        svoice->vibModAddScale = 0;
        svoice->treScale = 0;
        inpInit((u8 *)svoice);
        if ((lastNote = inpGetMidiLastNote(svoice->midi, svoice->midiSet)) != 0xFF) {
            svoice->lastNote = lastNote;
        } else {
            svoice->lastNote = svoice->orgNote;
        }
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->orgNote);
        voiceSetLastStarted(svoice);
        svoice->vGroup = svoice->setup.vGroup;
        svoice->studio = svoice->setup.studio;
        svoice->portTime = 0;
        svoice->portDuration = 25600;
        svoice->portType = 0;
        if (svoice->midi != 0xff) {
            svoice->portLastCtrlState = inpGetMidiCtrl(65, svoice->midi, svoice->midiSet);
        } else {
            svoice->portLastCtrlState = 0;
        }
        channelDefaults = inpGetChannelDefaults(svoice->midi, svoice->midiSet);
        svoice->pbLowerKeyRange = channelDefaults->pbRange;
        svoice->pbUpperKeyRange = channelDefaults->pbRange;
        svoice->revVolScale = 128;
        svoice->revVolOffset = 0;
        svoice->loop = 0;
        svoice->sweepNum[0] = 0;
        svoice->sweepNum[1] = 0;
        svoice->sweepOff[0] = 0;
        svoice->sweepOff[1] = 0;
        svoice->lfo[0].period = 0;
        svoice->lfo[0].value = 0;
        svoice->lfo[0].lastValue = 0x7fff;
        svoice->lfo[1].period = 0;
        svoice->lfo[1].value = 0;
        svoice->lfo[1].lastValue = 0x7fff;
        for (i = 0; i < 3; ++i) {
            svoice->trapEventAddr[i] = 0;
        }
        svoice->trapEventAny = 0;
        svoice->sInfo = -1;
        svoice->playFrq = -1;
        svoice->pbLast = 0x2000;
        svoice->curOutputVolume = 0;
        svoice->cFlags &= 8;
        svoice->cFlags |= 0x300000000000;
        memset(svoice->local_vars, 0, sizeof(svoice->local_vars));
        svoice->waitTime = macRealTime;
        svoice->macStartTime = macRealTime;
        synthStartSynthJobHandling(svoice);
    }
    DebugMacroSteps = 0;
    do {
        if (++DebugMacroSteps > 32) {
            break;
        }
        cstep.para[0] = svoice->curAddr->para[0];
        cstep.para[1] = svoice->curAddr->para[1];
        ++svoice->curAddr;
        ex = 0;
        switch (cstep.para[0] & 0x7f) {
        case 0x0:
            ex = mcmdEndOfMacro(svoice);
            break;
        case 0x1:
            ex = mcmdStop(svoice);
            break;
        case 0x2:
            mcmdIfKey(svoice, &cstep);
            break;
        case 0x3:
            mcmdIfVelocity(svoice, &cstep);
            break;
        case 0x4:
            ex = mcmdWait(svoice, &cstep);
            break;
        case 0x5:
            mcmdLoop(svoice, &cstep);
            break;
        case 0x6:
            ex = mcmdGoto(svoice, &cstep);
            break;
        case 0x7:
            ex = mcmdWaitMs(svoice, &cstep);
            break;
        case 0x8:
            mcmdPlayMacro(svoice, &cstep);
            break;
        case 0x9:
            mcmdSendKeyOff(svoice, &cstep);
            break;
        case 0xa:
            mcmdIfModulation(svoice, &cstep);
            break;
        case 0xb:
            mcmdSetPianoPanning(svoice, &cstep);
            break;
        case 0xc:
            mcmdSetADSR(svoice, &cstep);
            break;
        case 0xd:
            mcmdScaleVolume(svoice, &cstep);
            break;
        case 0xe:
            mcmdSetPanning(svoice, &cstep);
            break;
        case 0xf:
            mcmdEnvelope(svoice, &cstep);
            break;
        case 0x10:
            mcmdStartSample(svoice, &cstep);
            break;
        case 0x11:
            mcmdStopSample(svoice);
            break;
        case 0x12:
            mcmdKeyOff(svoice);
            break;
        case 0x13:
            mcmdIfRandom(svoice, &cstep);
            break;
        case 0x14:
            mcmdFadeIn(svoice, &cstep);
            break;
        case 0x15:
            mcmdSetSurroundPanning(svoice, &cstep);
            break;
        case 0x16:
            mcmdSetADSRFromCtrl(svoice, &cstep);
            break;
        case 0x17:
            mcmdRandomKey(svoice, &cstep);
            break;
        case 0x18:
            ex = mcmdAddKey(svoice, &cstep);
            break;
        case 0x19:
            ex = mcmdSetKey(svoice, &cstep);
            break;
        case 0x1a:
            ex = mcmdLastKey(svoice, &cstep);
            break;
        case 0x1b:
            mcmdPortamento(svoice, &cstep);
            break;
        case 0x1c:
            mcmdVibrato(svoice, &cstep);
            break;
        case 0x1d:
            ex = mcmdPitchSweep(svoice, &cstep, 0);
            break;
        case 0x1e:
            ex = mcmdPitchSweep(svoice, &cstep, 1);
            break;
        case 0x1f:
            mcmdSetPitch(svoice, &cstep);
            break;
        case 0x20:
            mcmdSetPitchADSR(svoice, &cstep);
            break;
        case 0x21:
            mcmdScaleVolumeDLS(svoice, &cstep);
            break;
        case 0x22:
            mcmdSetMod2Vibrato(svoice, &cstep);
            break;
        case 0x23:
            mcmdSetupTremolo(svoice, &cstep);
            break;
        case 0x24:
            mcmdReturn(svoice);
            break;
        case 0x25:
            ex = mcmdGosub(svoice, &cstep);
            break;
        case 0x28:
            mcmdTrapEvent(svoice, &cstep);
            break;
        case 0x29:
            mcmdUntrapEvent(svoice, &cstep);
            break;
        case 0x2a:
            mcmdSendMessage(svoice, &cstep);
            break;
        case 0x2b:
            mcmdGetMessage(svoice, &cstep);
            break;
        case 0x2c:
            mcmdGetVID(svoice, &cstep);
            break;
        case 0x30:
            mcmdAddAgeCounter(svoice, &cstep);
            break;
        case 0x31:
            mcmdSetAgeCounter(svoice, &cstep);
            break;
        case 0x32:
            mcmdSendFlag(&cstep);
            break;
        case 0x33:
            mcmdSetPitchWheelRange(svoice, &cstep);
            break;
        case 0x34:
            mcmdScaleReverb(svoice, &cstep);
            break;
        case 0x35:
            mcmdSetPitchbendAfterKeyOff(svoice);
            break;
        case 0x36:
            mcmdSetPriority(svoice, &cstep);
            break;
        case 0x37:
            mcmdAddPriority(svoice, &cstep);
            break;
        case 0x38:
            mcmdSetAgeCounterSpeed(svoice, &cstep);
            break;
        case 0x39:
            mcmdSetAgeCounterByVolume(svoice, &cstep);
            break;
        case 0x40:
            mcmdVolumeSelect(svoice, &cstep);
            break;
        case 0x41:
            mcmdPanningSelect(svoice, &cstep);
            break;
        case 0x42:
            mcmdPitchWheelSelect(svoice, &cstep);
            break;
        case 0x43:
            mcmdModWheelSelect(svoice, &cstep);
            break;
        case 0x44:
            mcmdPedalSelect(svoice, &cstep);
            break;
        case 0x45:
            mcmdPortamentoSelect(svoice, &cstep);
            break;
        case 0x46:
            mcmdReverbSelect(svoice, &cstep);
            break;
        case 0x47:
            mcmdSurroundPanningSelect(svoice, &cstep);
            break;
        case 0x48:
            mcmdDopplerSelect(svoice, &cstep);
            break;
        case 0x49:
            mcmdTremoloSelect(svoice, &cstep);
            break;
        case 0x4a:
            mcmdPreAuxASelect(svoice, &cstep);
            break;
        case 0x4b:
            mcmdPreAuxBSelect(svoice, &cstep);
            break;
        case 0x4c:
            mcmdPostAuxBSelect(svoice, &cstep);
            break;
        case 0x4d:
            mcmdAuxAFXSelect(svoice, &cstep);
            break;
        case 0x4e:
            mcmdAuxBFXSelect(svoice, &cstep);
            break;
        case 0x50:
            mcmdSetupLFO(svoice, &cstep);
            break;
        case 0x58:
            mcmdModeSelect(svoice, &cstep);
            break;
        case 0x59:
            mcmdSetKeyGroup(svoice, &cstep);
            break;
        case 0x5a:
            mcmdSRCModeSelect(svoice, &cstep);
            break;
        case 0x60:
            mcmdVarCalculation(svoice, &cstep, 0);
            break;
        case 0x61:
            mcmdVarCalculation(svoice, &cstep, 1);
            break;
        case 0x62:
            mcmdVarCalculation(svoice, &cstep, 2);
            break;
        case 0x63:
            mcmdVarCalculation(svoice, &cstep, 3);
            break;
        case 0x64:
            mcmdVarCalculation(svoice, &cstep, 4);
            break;
        case 0x65:
            mcmdSetVarImmediate(svoice, &cstep);
            break;
        case 0x70:
            mcmdIfVarCompare(svoice, &cstep, 0);
            break;
        case 0x71:
            mcmdIfVarCompare(svoice, &cstep, 1);
            break;
        }
    } while (!ex);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline u32 HasHWEventTrap(SynthVoice *svoice) {
    if (svoice->trapEventAny != 0) {
        return svoice->trapEventAddr[1] != NULL;
    }
    return 0;
}

static inline void CheckHWEventTrap(SynthVoice *svoice) {
    if ((svoice->cFlags & 0x20) == 0 && !hwIsActive(svoice->id & 0xff)) {
        ExecuteTrap(svoice, 1);
    }
}

void macHandle(u32 deltaTime) {
    SynthVoice *sv;
    SynthVoice *nextSv;
    u64 w;

    for (sv = macTimeQueue; sv != NULL && sv->wait <= macRealTime;) {
        nextSv = sv->nextTimeQueueMacro;
        w = sv->wait;
        macMakeActive(sv);
        sv->waitTime = w;
        sv = nextSv;
    }

    for (sv = macActiveList; sv != NULL; sv = sv->nextMacActive) {
        nextSv = sv->nextMacActive;
        if (HasHWEventTrap(sv) != 0) {
            CheckHWEventTrap(sv);
        }
        macHandleActive(sv);
    }
    macRealTime += deltaTime;
}
#pragma pop

void macSampleEndNotify(SynthVoice *svoice) {
    u32 done;

    if (svoice->macState == 1) {
        if (svoice->trapEventAny != 0 && svoice->trapEventAddr[1] != NULL) {
            svoice->curAddr = svoice->trapEventCurAddr[1];
            svoice->addr = svoice->trapEventAddr[1];
            svoice->trapEventAddr[1] = NULL;
            macMakeActive(svoice);
            done = 1;
        } else {
            done = 0;
        }
        if (done == 0 && (svoice->cFlags & 0x40000) != 0) {
            macMakeActive(svoice);
        }
    }
}

void macSetExternalKeyoff(SynthVoice *svoice) {
    u32 done;

    svoice->cFlags |= 8;
    if (svoice->addr != NULL) {
        if ((svoice->cFlags & 0x10000000000ULL) == 0) {
            if (svoice->trapEventAny != 0 && svoice->trapEventAddr[0] != NULL) {
                svoice->curAddr = svoice->trapEventCurAddr[0];
                svoice->addr = svoice->trapEventAddr[0];
                svoice->trapEventAddr[0] = NULL;
                macMakeActive(svoice);
                done = 1;
            } else {
                done = 0;
            }
            if (done == 0 && (svoice->cFlags & 4) != 0) {
                macMakeActive(svoice);
            }
        } else {
            svoice->cFlags |= 0x40000000000ULL;
        }
    }
}

void macSetPedalState(SynthVoice *svoice, u32 hold) {
    u32 started;

    if (hold != 0) {
        svoice->cFlags |= 0x10000000000ULL;
        return;
    }
    if (svoice->addr != NULL && (svoice->cFlags & 0x40000000000ULL) != 0) {
        if (svoice->trapEventAny != 0 && svoice->trapEventAddr[0] != NULL) {
            svoice->curAddr = svoice->trapEventCurAddr[0];
            svoice->addr = svoice->trapEventAddr[0];
            svoice->trapEventAddr[0] = NULL;
            macMakeActive(svoice);
            started = 1;
        } else {
            started = 0;
        }
        if (started == 0 && (svoice->cFlags & 4ULL) != 0) {
            macMakeActive(svoice);
        }
    }
    svoice->cFlags &= ~0x50000000000ULL;
}

void TimeQueueAdd(SynthVoice *self) {
    SynthVoice *p;
    SynthVoice *prev;
    p = macTimeQueue;
    prev = NULL;
    while (p != NULL && p->wait < self->wait) {
        prev = p;
        p = p->nextTimeQueueMacro;
    }
    if (p == NULL) {
        if (prev == NULL) {
            macTimeQueue = self;
            self->nextTimeQueueMacro = NULL;
            self->prevTimeQueueMacro = NULL;
        } else {
            prev->nextTimeQueueMacro = self;
            self->prevTimeQueueMacro = prev;
            self->nextTimeQueueMacro = NULL;
        }
    } else {
        self->nextTimeQueueMacro = p;
        if ((self->prevTimeQueueMacro = p->prevTimeQueueMacro) != NULL) {
            p->prevTimeQueueMacro->nextTimeQueueMacro = self;
        } else {
            macTimeQueue = self;
        }
        p->prevTimeQueueMacro = self;
    }
}

void UnYieldMacro(SynthVoice *svoice, u32 noForceUpdate) {
    if (svoice->wait != 0) {
        if (svoice->wait != (u64)-1) {
            if (svoice->prevTimeQueueMacro == NULL) {
                macTimeQueue = svoice->nextTimeQueueMacro;
            } else {
                svoice->prevTimeQueueMacro->nextTimeQueueMacro = svoice->nextTimeQueueMacro;
            }
            if (svoice->nextTimeQueueMacro != NULL) {
                svoice->nextTimeQueueMacro->prevTimeQueueMacro = svoice->prevTimeQueueMacro;
            }
        }
        if (noForceUpdate == 0) {
            synthForceLowPrecisionUpdate(svoice);
        }
        svoice->wait = 0;
        svoice->waitTime = macRealTime;
        svoice->cFlags &= ~0x40004ULL;
    }
}

void macMakeActive(SynthVoice *svoice) {
    if (svoice->macState != 0) {
        if (svoice->wait != 0) {
            if (svoice->wait != 0xFFFFFFFFFFFFFFFFULL) {
                if (svoice->prevTimeQueueMacro == NULL) {
                    macTimeQueue = svoice->nextTimeQueueMacro;
                } else {
                    svoice->prevTimeQueueMacro->nextTimeQueueMacro = svoice->nextTimeQueueMacro;
                }
                if (svoice->nextTimeQueueMacro != NULL) {
                    svoice->nextTimeQueueMacro->prevTimeQueueMacro = svoice->prevTimeQueueMacro;
                }
            }
            synthForceLowPrecisionUpdate(svoice);
            svoice->wait = 0;
            svoice->waitTime = macRealTime;
            svoice->cFlags &= ~0x40004ULL;
        }
        if ((svoice->nextMacActive = macActiveList) != NULL) {
            macActiveList->prevMacActive = svoice;
        }
        svoice->prevMacActive = NULL;
        macActiveList = svoice;
        svoice->macState = 0;
    }
}

void macMakeInactive(SynthVoice *svoice, s32 state) {
    if (svoice->macState == state) {
        return;
    }
    if (svoice->macState == 0) {
        if (svoice->prevMacActive == NULL) {
            macActiveList = svoice->nextMacActive;
        } else {
            svoice->prevMacActive->nextMacActive = svoice->nextMacActive;
        }
        if (svoice->nextMacActive != NULL) {
            svoice->nextMacActive->prevMacActive = svoice->prevMacActive;
        }
    }
    if (state == 2) {
        if (svoice->wait != 0) {
            if (svoice->wait != (u64)-1) {
                if (svoice->prevTimeQueueMacro == NULL) {
                    macTimeQueue = svoice->nextTimeQueueMacro;
                } else {
                    svoice->prevTimeQueueMacro->nextTimeQueueMacro = svoice->nextTimeQueueMacro;
                }
                if (svoice->nextTimeQueueMacro != NULL) {
                    svoice->nextTimeQueueMacro->prevTimeQueueMacro = svoice->prevTimeQueueMacro;
                }
            }
            svoice->wait = 0;
            svoice->waitTime = macRealTime;
            svoice->cFlags &= ~0x40004ULL;
        }
    }
    svoice->macState = state;
}

u32 macStart(u16 macid, u8 priority, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
             u8 midiSet, u8 section, u16 step, u16 trackid, u8 new_vid, u8 vGroup, u8 studio, u32 itd) {
    uaddr macro;
    s32 flag;
    u16 r;
    u32 id;
    SynthVoice *v;
    u32 vid;

    macro = dataGetMacro(macid);
    if (macro != 0) {
        flag = key & 0x80;
        if (flag == 0) {
            r = seqGetMIDIPriority(midiSet, midi);
            if (r != 0xFFFF) {
                priority = r;
            }
        }
        id = voiceAllocate(priority, maxVoices, allocId, flag != 0 ? 1 : 0);
        if (id != 0xFFFFFFFF) {
            v = &synthVoice[id];
            vidRemoveVoiceReferences(v);
            if (v->macState != 2) {
                if (v->macState == 0) {
                    if (v->prevMacActive == NULL) {
                        macActiveList = v->nextMacActive;
                    } else {
                        v->prevMacActive->nextMacActive = v->nextMacActive;
                    }
                    if (v->nextMacActive != NULL) {
                        v->nextMacActive->prevMacActive = v->prevMacActive;
                    }
                }
                UnYieldMacro(v, 1);
                v->macState = 2;
            }
            v->cFlags = (v->cFlags & 0x10) | 2;
            if (hwIsActive(id) != 0) {
                v->cFlags |= 1;
            }
            v->wait = 0;
            if (flag != 0) {
                v->fxFlag = 1;
                key &= 0x7F;
                inpResetMidiCtrl(id, 0xFF, 1);
                inpResetChannelDefaults(id, 0xFF);
                v->setup.midi = id;
                v->setup.midiSet = 0xFF;
                v->setup.section = 0;
            } else {
                v->fxFlag = 0;
                v->setup.midi = midi;
                v->setup.midiSet = midiSet;
                v->setup.section = section;
            }
            v->macroId = macid;
            v->allocId = allocId;
            v->age = 0x75300000;
            v->ageSpeed = 0x400;
            v->addr = (SynthMacroStep *)macro;
            v->curAddr = (SynthMacroStep *)macro + step;
            v->orgNote = key;
            v->curNote = key;
            v->curDetune = 0;
            v->setup.vol = vol;
            v->setup.pan = panning;
            v->setup.track = trackid;
            v->callStackEntryNum = 0;
            v->callStackIndex = 0;
            v->child = -1;
            v->parent = -1;
            v->lastVID = -1;
            v->setup.vGroup = vGroup;
            v->setup.studio = studio;
            v->setup.itdMode = itd != 0 ? 0 : 1;
            v->mesgWrite = 0;
            v->mesgRead = 0;
            v->mesgNum = 0;
            v->id = id | ((macid << 16) | ((key << 8) & 0xFF00));
            voiceSetPriority(v, priority);
            vid = vidMakeNew(v, new_vid);
            if (vid != 0xFFFFFFFF) {
                if (v->macState != 0) {
                    UnYieldMacro(v, 0);
                    if ((v->nextMacActive = macActiveList) != NULL) {
                        macActiveList->prevMacActive = v;
                    }
                    v->prevMacActive = NULL;
                    macActiveList = v;
                    v->macState = 0;
                }
                return vid;
            }
            if (hwIsActive(id) != 0) {
                hwBreak(id);
            }
            voiceFree(v);
        }
    }
    return -1;
}

#pragma push
#pragma opt_common_subs on
void macInit(void) {
    u32 i;
    macActiveList = NULL;
    macTimeQueue = NULL;
    macRealTime = 0;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        synthVoice[i].addr = NULL;
        synthVoice[i].macState = 2;
        synthVoice[i].loop = 0;
    }
}
#pragma pop

u8 DebugMacroSteps;
SynthVoice *macActiveList;
SynthVoice *macTimeQueue;
u64 macRealTime;
SynthMacroStep cstep;

}
