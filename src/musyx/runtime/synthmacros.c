#define synthKeyStateUpdate TLobby__sub_803A8D04_hdr_view
#define dataGetSample find_sound_sample_hdr_view
#define macHandleActive macHandleActive_hdr_view
#define varSet32 varSet32_hdr_view
#define inpSetExCtrl inpSetExCtrl_hdr_view
#include "musyx/runtime/musyx_runtime_a.h"
#undef synthKeyStateUpdate
#undef dataGetSample
#undef macHandleActive
#undef varSet32
#undef inpSetExCtrl
extern "C" {
void varSet32(Obj_803B0004 *arg0, u32 arg1, u8 arg2, s32 arg3);
void inpSetExCtrl(void *svoice, u8 ctrl, s16 v);
struct Voice_803AEEF0;
void synthKeyStateUpdate(Voice_803AEEF0 *svoice);
s32 dataGetSample(u16 id, Sample_803AE4D4 *s);
}

extern "C" {

#define FLAGS (*(u64 *)&o->fh)
#pragma push
#pragma bool off
s32 mcmdWait(Obj_803AE8F8 *o, Op_803AE8F8 *op) {
    u32 v;
    u32 ms;

    if ((v = op->w4 >> 16) == 0) {
        goto end;
    }
    if ((op->w0 >> 8) & 1) {
        if ((FLAGS & 8ULL) != 0) {
            if ((FLAGS & 0x10000000000ULL) == 0) {
                return 0;
            }
            FLAGS |= 0x40000000000ULL;
        }
        FLAGS |= 4ULL;
    } else {
        FLAGS &= ~4ULL;
    }
    if ((op->w0 >> 24) & 1) {
        if ((FLAGS & 0x20ULL) == 0 && hwIsActive((u8)o->iF4) == 0) {
            return 0;
        }
        FLAGS |= 0x40000ULL;
    } else {
        FLAGS &= ~0x40000ULL;
    }
    if ((op->w0 >> 16) & 1) {
        v = sndRand() % v;
    }
    if (v != 0xFFFF) {
        if ((ms = ((u8)(op->w4 >> 8) & 1) != 0)) {
            sndConvertMs(&v);
        } else {
            sndConvertTicks(&v, o);
        }
        if (ms != 0) {
            if (op->w4 & 1) {
                o->deadline = o->f90 + v;
            } else {
                o->deadline = macRealTime + v;
            }
        } else {
            if (op->w4 & 1) {
                o->deadline = v;
            } else {
                o->deadline = o->fa0 + v;
            }
        }
        if (o->deadline <= macRealTime) {
            o->fa0 = o->deadline;
            o->deadline = 0;
        }
    } else {
        o->deadline = -1;
    }
    if (o->deadline != 0) {
        if (o->deadline != (u64)-1) {
            TimeQueueAdd((Program_803B1DA4 *)o);
        }
        macMakeInactive((Obj_803B312C *)o, 1);
        return 1;
    }
end:
    return 0;
}
#pragma pop
#undef FLAGS

#define FLAGS (*(u64 *)&o->fh)
void mcmdLoop(Obj_803AEC00 *o, Op_803AEC00 *op) {
    u32 w;
    if (o->cnt == 0) {
        if ((op->w0 >> 16) & 1) {
            o->cnt = sndRand() % (u16)(op->w4 >> 16);
        } else {
            o->cnt = op->w4 >> 16;
        }
        if (o->cnt == 0xFFFF) {
            goto body;
        }
        o->cnt++;
    } else if (o->cnt == 0xFFFF) {
        goto body;
    }
    if (--o->cnt == 0) {
        return;
    }
body:
    w = op->w0;
    if (((w >> 8) & 1) && (FLAGS & 0x10000000008ULL) == 8) {
        o->cnt = 0;
        return;
    }
    if (((w >> 24) & 1) && (FLAGS & 0x20ULL) == 0 && hwIsActive((u8)o->iF4) == 0) {
        o->cnt = 0;
        return;
    }
    o->i38 = o->i34 + ((op->w4 & 0xFFFF) << 3);
}

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdPlayMacro(Voice_803AED58 *svoice, MSTEP_803AED58 *cstep) {
    u32 macStart(u16 arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u16 arg10, u16 arg11, u8 arg12, u8 arg13, u8 arg14, u32 arg15);
    s32 key;
    u32 new_child;

    key = ((u32)svoice->orgNote + (s8)(u8)(cstep->para[0] >> 8));
    key = (key < 0) ? 0 : key > 0x7f ? 0x7f : key;

    if (svoice->fxFlag != 0) {
        key |= 0x80;
    }

    svoice->block = 1;
    new_child = macStart((u16)(cstep->para[0] >> 0x10), (u8)(cstep->para[1] >> 0x10),
                                  (u8)(cstep->para[1] >> 0x18), svoice->allocId, key,
                                  (u8)(svoice->volume >> 0x10), (u8)(svoice->panning[0] >> 0x10), svoice->midi,
                                  svoice->midiSet, svoice->section, (u16)cstep->para[1], (u16)svoice->track, 0,
                                  svoice->vGroup, svoice->studio, svoice->itdMode == 0);
    svoice->block = 0;
    if (new_child != 0xFFFFFFFF) {
        svoice->lastVID = (*(Voice_803AED58 **)&synthVoice)[(u8)new_child].vidList->vid;
        (*(Voice_803AED58 **)&synthVoice)[(u8)new_child].parent = svoice->id;
        if (svoice->child != -1) {
            (*(Voice_803AED58 **)&synthVoice)[(u8)new_child].child = svoice->child;
            (*(Voice_803AED58 **)&synthVoice)[(u8)svoice->child].parent = new_child;
        }
        svoice->child = new_child;
        if (svoice->fxFlag != 0) {
            synthFXCloneMidiSetup((u8 *)&(*(Voice_803AED58 **)&synthVoice)[(u8)new_child], (u8 *)svoice);
        }
    } else {
        svoice->lastVID = 0xFFFFFFFF;
    }
}
#pragma pop

#pragma pack(4)
typedef struct MSTEP_803AEEF0 { u32 para[2]; } MSTEP_803AEEF0;
typedef struct VIDL_803AEEF0 { struct VIDL_803AEEF0 *next; struct VIDL_803AEEF0 *prev; u32 vid; u32 root; } VIDL_803AEEF0;
typedef struct LFO_803AEEF0 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AEEF0;
typedef struct CSRC_803AEEF0 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AEEF0;
typedef struct CDEST_803AEEF0 { CSRC_803AEEF0 source[4]; u16 oldValue; u8 numSource; } CDEST_803AEEF0;
typedef struct Voice_803AEEF0 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AEEF0 *addr;
  MSTEP_803AEEF0 *curAddr;
  struct Voice_803AEEF0 *nextMacActive;
  struct Voice_803AEEF0 *prevMacActive;
  struct Voice_803AEEF0 *nextTimeQueueMacro;
  struct Voice_803AEEF0 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AEEF0 *trapEventAddr[3];
  MSTEP_803AEEF0 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AEEF0 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AEEF0 *vidList;
  VIDL_803AEEF0 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AEEF0 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AEEF0 inpVolume;
  CDEST_803AEEF0 inpPanning;
  CDEST_803AEEF0 inpSurroundPanning;
  CDEST_803AEEF0 inpPitchBend;
  CDEST_803AEEF0 inpDoppler;
  CDEST_803AEEF0 inpModulation;
  CDEST_803AEEF0 inpPedal;
  CDEST_803AEEF0 inpPortamento;
  CDEST_803AEEF0 inpPreAuxA;
  CDEST_803AEEF0 inpReverb;
  CDEST_803AEEF0 inpPreAuxB;
  CDEST_803AEEF0 inpPostAuxB;
  CDEST_803AEEF0 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AEEF0;
#pragma pack()

void hwInitSamplePlayback(u32 v, u16 smpID, void *newsmp, u32 set_defadsr, u32 prio, u32 callbackUserValue, u32 setSRC, u8 itdMode);
void DoSetPitch(Voice_803AEEF0 *);

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdStartSample(Voice_803AEEF0 *svoice, MSTEP_803AEEF0 *cstep) {
    static Sample_803AE4D4 newsmp;
    u16 smp;
    smp = cstep->para[0] >> 8;

    if (dataGetSample(smp, &newsmp) != 0) {
        return;
    }
    switch ((u8)(cstep->para[0] >> 0x18)) {
    case 0:
        newsmp.offset = cstep->para[1];
        break;
    case 1:
        newsmp.offset = ((u8)(0x7f - (svoice->volume >> 0x10)) * (u32)cstep->para[1]) / 0x7f;
        break;
    case 2:
        newsmp.offset = ((u8)((svoice->volume >> 0x10)) * (u32)cstep->para[1]) / 0x7f;
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

#define FLAGS (*(u64 *)&o->fh)

void mcmdVibrato(Obj_803AF0CC *o, Op_803AF0CC *op) {
    u32 v;
    s8 hi;
    s8 lo;
    if ((op->w0 >> 24) & 3) {
        FLAGS |= 0x4000ULL;
    } else {
        FLAGS &= ~0x4000ULL;
    }
    v = op->w4 >> 16;
    if ((op->w4 >> 8) & 1) {
        sndConvertMs(&v);
    } else {
        sndConvertTicks(&v, o);
    }
    if (v != 0) {
        FLAGS |= 0x2000ULL;
        o->i144 = v;
        hi = op->w0 >> 8;
        lo = op->w0 >> 16;
        if (hi < 0) {
            if (lo < 0) {
                o->b141 = -lo;
            } else {
                o->b141 = lo;
            }
            o->b140 = -hi;
            o->i148 = o->i144 >> 1;
        } else {
            if (lo < 0) {
                if (hi == 0) {
                    o->b141 = -lo;
                    o->i148 = o->i144 >> 1;
                } else {
                    o->b141 = 100 - lo;
                    hi--;
                    o->i148 = 0;
                }
            } else {
                o->b141 = lo;
                o->i148 = 0;
            }
            o->b140 = hi;
        }
    } else {
        FLAGS &= ~0x2000ULL;
    }
}

#pragma push
#pragma bool off
#pragma opt_common_subs on
void DoSetPitch(Voice_803AEEF0 *svoice) {
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

#undef FLAGS
#define FLAGS (*(u64 *)&o->fh)

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetADSR(Voice_803AF3DC *svoice, MSTEP_803AF3DC *cstep) {
    ADSR_803AF3DC adsr;
    ADSR_803AF3DC *adsr_ptr;
    s32 ascale;
    s32 dscale;
    f32 sScale;

    if ((adsr_ptr = (ADSR_803AF3DC *)dataGetCurve((u16)(cstep->para[0] >> 8))) != 0) {
        if (!(u8)(cstep->para[0] >> 24)) {
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

#pragma pack(4)
typedef struct MSTEP_803AF634 { u32 para[2]; } MSTEP_803AF634;
typedef struct VIDL_803AF634 { struct VIDL_803AF634 *next; struct VIDL_803AF634 *prev; u32 vid; u32 root; } VIDL_803AF634;
typedef struct LFO_803AF634 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AF634;
typedef struct CSRC_803AF634 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AF634;
typedef struct CDEST_803AF634 { CSRC_803AF634 source[4]; u16 oldValue; u8 numSource; } CDEST_803AF634;
typedef struct ADSRV_803AF634 { u8 mode; u8 state; u32 cnt; s32 currentVolume; s32 currentIndex; s32 currentDelta;
  union { struct { u32 aTime; u32 dTime; u16 sLevel; u32 rTime; u16 cutOff; u8 aMode; } dls; } data; } ADSRV_803AF634;
typedef struct Voice_803AF634 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AF634 *addr;
  MSTEP_803AF634 *curAddr;
  struct Voice_803AF634 *nextMacActive;
  struct Voice_803AF634 *prevMacActive;
  struct Voice_803AF634 *nextTimeQueueMacro;
  struct Voice_803AF634 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AF634 *trapEventAddr[3];
  MSTEP_803AF634 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AF634 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AF634 *vidList;
  VIDL_803AF634 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AF634 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  ADSRV_803AF634 pitchADSR;
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AF634 inpVolume;
  CDEST_803AF634 inpPanning;
  CDEST_803AF634 inpSurroundPanning;
  CDEST_803AF634 inpPitchBend;
  CDEST_803AF634 inpDoppler;
  CDEST_803AF634 inpModulation;
  CDEST_803AF634 inpPedal;
  CDEST_803AF634 inpPortamento;
  CDEST_803AF634 inpPreAuxA;
  CDEST_803AF634 inpReverb;
  CDEST_803AF634 inpPreAuxB;
  CDEST_803AF634 inpPostAuxB;
  CDEST_803AF634 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AF634;
#pragma pack()

typedef struct ADSR_803AF634 {
    union {
        struct { s32 atime; s32 dtime; u16 slevel; u16 rtime; s32 ascale; s32 dscale; } dls;
        struct { u16 atime; u16 dtime; u16 slevel; u16 rtime; } linear;
    } data;
} ADSR_803AF634;
s32 dataGetCurve(s16 arg0);
u32 adsrConvertTimeCents(s32 arg0);
u32 adsrSetup(u8 *arg0);

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetPitchADSR(Voice_803AF634 *svoice, MSTEP_803AF634 *cstep) {
    ADSR_803AF634 adsr;
    ADSR_803AF634 *adsr_ptr;
    u32 sl;
    s32 ascale;
    s32 dscale;

    if ((adsr_ptr = (ADSR_803AF634 *)dataGetCurve((u16)(cstep->para[0] >> 8))) == 0) {
        return;
    }

    svoice->pitchADSRRange = ((s8)cstep->para[1] << 8);

    if (svoice->pitchADSRRange >= 0) {
        svoice->pitchADSRRange += ((s16)(s8)(cstep->para[1] >> 8) << 8) / 100;
    } else {
        svoice->pitchADSRRange -= ((s16)(s8)(cstep->para[1] >> 8) << 8) / 100;
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
    adsrSetup((u8 *)&svoice->pitchADSR);
    svoice->cFlags |= 0x20000000000;
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void DoPanningSetup(Voice_803AF634 *svoice, MSTEP_803AF634 *cstep, u8 pi) {
    u32 mstime;
    s32 width;
    width = (u16)(cstep->para[0] >> 16);
    svoice->panTime[pi] = width;
    sndConvertMs(&svoice->panTime[pi]);
    mstime = (s8)(cstep->para[1]);
    svoice->panning[pi] = ((u8)(cstep->para[0] >> 8)) << 16;
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
static inline u32 TranslateVolume_803AF9D4(u32 volume, u16 curve) {
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

void DoEnvelopeCalculation(Voice_803AF9D4 *svoice, MSTEP_803AF9D4 *cstep, s32 start_vol) {
    u32 tvol;
    u32 time;
    s32 mstime;
    u16 curve;

    time = (u16)(cstep->para[1] >> 16);

    if ((u8)(cstep->para[1] >> 8) & 1) {
        sndConvertMs(&time);
    } else {
        sndConvertTicks(&time, svoice);
    }

    mstime = sndConvert2Ms(time);
    if (mstime == 0) {
        mstime = 1;
    }

    tvol = (svoice->volume * (u8)(cstep->para[0] >> 8) >> 7);
    tvol += (u8)(cstep->para[0] >> 16) << 16;

    if (tvol > 0x7f0000) {
        tvol = 0x7f0000;
    }

    curve = (u16)(u8)(cstep->para[0] >> 0x18);
    curve |= (((u16)(u8)cstep->para[1]) << 8);
    tvol = TranslateVolume_803AF9D4(tvol, curve);
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
static inline u32 mcmdSetKey_803AFB00(Voice_803AFB00 *svoice, MSTEP_803AFB00 *cstep) {
    svoice->curNote = (u8)(cstep->para[0] >> 8) & 0x7f;
    svoice->curDetune = (s8)(cstep->para[0] >> 0x10);
    if ((u32)voiceIsLastStarted((Obj_803B3AA8 *)svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote & 0xff);
    }
    cstep->para[0] = 4;
    return mcmdWait((Obj_803AE8F8 *)svoice, (Op_803AE8F8 *)cstep);
}

void mcmdRandomKey(Voice_803AFB00 *svoice, MSTEP_803AFB00 *cstep) {
    u8 k1;
    u8 k2;
    u8 t;
    s32 i1;
    s32 i2;
    u8 detune;

    if (!(u8)(cstep->para[1] >> 8)) {
        k1 = (cstep->para[0] >> 8);
        k2 = (cstep->para[0] >> 24);
        if (k1 > k2) {
            t = k1;
            k1 = k2;
            k2 = t;
        }
    } else {
        i1 = svoice->curNote - (u8)(cstep->para[0] >> 8);
        i2 = svoice->curNote + (u8)(cstep->para[0] >> 24);

        k1 = i1 < 0 ? 0 : i1 > 127 ? 127 : i1;
        k2 = i2 < 0 ? 0 : i2 > 127 ? 127 : i2;
    }

    if ((u8)cstep->para[1]) {
        detune = (sndRand() % 201) - 100;
    } else {
        detune = (u8)(cstep->para[0] >> 16);
    }

    cstep->para[0] = ((u8)detune << 16) | 0x19 | ((k1 + (sndRand() % ((k2 - k1) + 1))) * 0x100);
    cstep->para[1] = 0;
    mcmdSetKey_803AFB00(svoice, cstep);
}
#pragma pop

void SelectSource(Obj_803AFCA0 *o, s32 ch, Op_803AFCA0 *op, u64 mask, u32 flag) {
    u8 x;
    u32 w0;
    s32 v;

    if ((FLAGS & mask) == 0) {
        FLAGS |= mask;
        x = 0;
    } else {
        x = op->w4;
    }
    w0 = op->w0;
    v = (s32)(w0 & 0xFFFF0000) / 100;
    if (v < 0) {
        v -= ((s8)(op->w4 >> 16) << 8) / 100;
    } else {
        v += ((s8)(op->w4 >> 16) << 8) / 100;
    }
    inpAddCtrl(ch, w0 >> 8, v, x, (u8)(op->w4 >> 8) != 0);
    if (flag & 0x80000000) {
        inpSetGlobalMIDIDirtyFlag(o->b121, o->b122, flag);
    } else {
        o->i214 |= flag;
    }
}

void mcmdPortamento(Obj_803AFDD4 *o, Op_803AFDD4 *op) {
    u32 v;

    o->b131 = op->w0 >> 16;
    v = op->w4 >> 16;
    if ((op->w4 >> 8) & 1) {
        sndConvertMs(&v);
    } else {
        sndConvertTicks(&v, o);
    }
    o->i134 = v;
    switch ((u8)(op->w0 >> 8)) {
    case 0:
        if (o->b121 != 0xFF) {
            inpSetMidiCtrl(0x41, o->b121, o->b122, 0);
        }
        FLAGS &= ~0x400ULL;
        break;
    case 1:
        if (o->b121 != 0xFF) {
            inpSetMidiCtrl(0x41, o->b121, o->b122, 0x7F);
        }
    on:
        if ((FLAGS & 0x400ULL) == 0) {
            synthInitPortamento((Obj_803A6F4C *)o);
        }
        FLAGS |= 0x400ULL;
        break;
    case 2:
        if (o->b121 != 0xFF && inpGetMidiCtrl(0x41, o->b121, o->b122) > 0x1F80) {
            goto on;
        }
        break;
    }
}

s32 varGet32(Obj_803AFF38 *arg0, u32 arg1, u32 arg2) {
    if (arg1 != 0) {
        return inpGetExCtrl(arg0, arg2);
    }
    arg2 = arg2 & 0x1F;
    if (arg2 < 0x10) {
        return arg0->v[arg2];
    }
    return synthGlobalVariable[arg2 - 16];
}

s16 varGet(Obj_803AFF9C *arg0, u32 arg1, u32 arg2) {
    s32 r;
    if (arg1 != 0) {
        r = (u16)inpGetExCtrl(arg0, arg2);
    } else {
        arg2 = arg2 & 0x1F;
        if (arg2 < 0x10) {
            r = arg0->v[arg2];
        } else {
            r = synthGlobalVariable[arg2 - 16];
        }
    }
    return r;
}

void varSet32(Obj_803B0004 *arg0, u32 arg1, u8 arg2, s32 arg3) {
    if (arg1 != 0) {
        inpSetExCtrl(arg0, arg2, arg3);
        return;
    }
    arg2 &= 0x1F;
    if (arg2 < 0x10) {
        arg0->v[arg2] = arg3;
        return;
    }
    synthGlobalVariable[arg2 - 16] = arg3;
}

#pragma pack(4)
typedef struct MSTEP_803B0068 { u32 para[2]; } MSTEP_803B0068;
typedef struct VIDL_803B0068 { struct VIDL_803B0068 *next; struct VIDL_803B0068 *prev; u32 vid; u32 root; } VIDL_803B0068;
typedef struct LFO_803B0068 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803B0068;
typedef struct CSRC_803B0068 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803B0068;
typedef struct CDEST_803B0068 { CSRC_803B0068 source[4]; u16 oldValue; u8 numSource; } CDEST_803B0068;
typedef struct Voice_803B0068 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803B0068 *addr;
  MSTEP_803B0068 *curAddr;
  struct Voice_803B0068 *nextMacActive;
  struct Voice_803B0068 *prevMacActive;
  struct Voice_803B0068 *nextTimeQueueMacro;
  struct Voice_803B0068 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803B0068 *trapEventAddr[3];
  MSTEP_803B0068 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803B0068 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803B0068 *vidList;
  VIDL_803B0068 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803B0068 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803B0068 inpVolume;
  CDEST_803B0068 inpPanning;
  CDEST_803B0068 inpSurroundPanning;
  CDEST_803B0068 inpPitchBend;
  CDEST_803B0068 inpDoppler;
  CDEST_803B0068 inpModulation;
  CDEST_803B0068 inpPedal;
  CDEST_803B0068 inpPortamento;
  CDEST_803B0068 inpPreAuxA;
  CDEST_803B0068 inpReverb;
  CDEST_803B0068 inpPreAuxB;
  CDEST_803B0068 inpPostAuxB;
  CDEST_803B0068 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803B0068;
#pragma pack()

struct Obj_803AFF38;
struct Obj_803B0004;
s32 varGet32(Obj_803AFF38 *arg0, u32 arg1, u32 arg2);
void varSet32(Obj_803B0004 *arg0, u32 arg1, u8 arg2, s32 arg3);

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline s16 varGet_803B0068(Voice_803B0068 *svoice, u32 ctrl, u8 index) {
    return varGet32((Obj_803AFF38 *)svoice, ctrl, index);
}

static inline void varSet_803B0068(Voice_803B0068 *svoice, u32 ctrl, u8 index, s16 v) {
    varSet32((Obj_803B0004 *)svoice, ctrl, index, v);
}

void mcmdVarCalculation(Voice_803B0068 *svoice, MSTEP_803B0068 *cstep, u8 op) {
    s16 s1;
    s16 s2;
    s32 t;

    s1 = varGet_803B0068(svoice, (u8)(cstep->para[0] >> 24), cstep->para[1]);
    if (op == 4) {
        s2 = cstep->para[1] >> 8;
    } else {
        s2 = varGet_803B0068(svoice, (u8)(cstep->para[1] >> 8), cstep->para[1] >> 16);
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

    varSet_803B0068(svoice, (u8)(cstep->para[0] >> 8), (u8)(cstep->para[0] >> 0x10),
                    (t < -0x8000 ? -0x8000 : t > 0x7FFF ? 0x7FFF : t));
}
#pragma pop

#define o ((Rec_803B1AF4 *)ov)

#pragma push
#pragma bool off
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 varGet32_803B0198(Voice_803B0198 *svoice, u32 ctrl, u8 index) {
    index &= 0x1f;
    return index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
}

static inline u32 ExecuteTrap_803B0198(Voice_803B0198 *svoice, u8 trapType) {
    if (svoice->trapEventAny != 0 && svoice->trapEventAddr[trapType] != 0) {
        svoice->curAddr = svoice->trapEventCurAddr[trapType];
        svoice->addr = svoice->trapEventAddr[trapType];
        svoice->trapEventAddr[trapType] = 0;
        macMakeActive(svoice);
        return 1;
    }
    return 0;
}

static inline u32 macPostMessage_803B0198(u32 vid, s32 mesg) {
    Voice_803B0198 *sv;
    if ((vid = vidGetInternalId(vid)) != -1 && (sv = &(*(Voice_803B0198 **)&synthVoice)[vid & 0xFF])->mesgNum < 4) {
        ++sv->mesgNum;
        sv->mesgQueue[sv->mesgWrite] = mesg;
        sv->mesgWrite = (sv->mesgWrite + 1) & 3;
        ExecuteTrap_803B0198(sv, 2);
        return 1;
    }
    return 0;
}

void mcmdSendMessage(Voice_803B0198 *svoice, MSTEP_803B0198 *cstep) {
    u8 i;
    s32 mesg;
    u16 macro;

    {
        u8 index = (u8)(cstep->para[1] >> 8);
        index &= 0x1f;
        mesg = index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
    }

    if (!(u8)(cstep->para[0] >> 8)) {
        macro = (u16)(cstep->para[0] >> 16);
        if (macro != 0xFFFF) {
            i = 0;
            while (i < synthInfo.voiceNum) {
                if ((*(Voice_803B0198 **)&synthVoice)[i].addr != 0 && macro == (*(Voice_803B0198 **)&synthVoice)[i].macroId) {
                    macPostMessage_803B0198((*(Voice_803B0198 **)&synthVoice)[i].vidList->vid, mesg);
                }
                ++i;
            }
        } else if (synthMessageCallback != 0) {
            synthMessageCallback(svoice->vidList->vid, mesg);
        }
    } else {
        macPostMessage_803B0198(varGet32_803B0198(svoice, 0, (u8)cstep->para[1]), mesg);
    }
}
#pragma pop

#pragma push
#pragma bool off
#pragma opt_common_subs on
void mcmdSetKeyGroup(Voice_803B03CC *svoice, MSTEP_803B03CC *cstep) {
    void voiceKill(u32 vi);
    u32 i;
    u8 kg;
    u32 kill;

    svoice->keyGroup = 0;
    kg = (u8)(cstep->para[0] >> 8);
    kill = (u8)(cstep->para[0] >> 0x10) != 0;

    if (kg) {
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if ((*(Voice_803B03CC **)&synthVoice)[i].addr != 0 && ((*(Voice_803B03CC **)&synthVoice)[i].cFlags & 0x2) == 0 &&
                kg == (*(Voice_803B03CC **)&synthVoice)[i].keyGroup) {
                if (!kill) {
                    macSetExternalKeyoff((Rec_803A9454 *)&(*(Voice_803B03CC **)&synthVoice)[i]);
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
#pragma pack(4)
typedef struct ADSR_INFO_803B04A0 {
    union ai_data_803B04A0 {
        struct {
            s32 atime;
            s32 dtime;
            u16 slevel;
            u16 rtime;
            s32 ascale;
            s32 dscale;
        } dls;
        struct {
            u16 atime;
            u16 dtime;
            u16 slevel;
            u16 rtime;
        } linear;
    } data;
} ADSR_INFO_803B04A0;
typedef struct ADSR_VARS_803B04A0 {
    u8 mode;
    u8 state;
    u32 cnt;
    s32 currentVolume;
    s32 currentIndex;
    s32 currentDelta;
    union data_803B04A0 {
        struct _dls_803B04A0 {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
            u16 cutOff;
            u8 aMode;
        } dls;
        struct _linear_803B04A0 {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
        } linear;
    } data;
} ADSR_VARS_803B04A0;
typedef enum {
    MAC_STATE_RUNNABLE_803B04A0 = 0,
    MAC_STATE_YIELDED_803B04A0,
    MAC_STATE_STOPPED_803B04A0
} MAC_STATE_803B04A0;
typedef struct MSTEP_803B04A0 {
    u32 para[2];
} MSTEP_803B04A0;
typedef struct CALLSTACK_803B04A0 {
    MSTEP_803B04A0 *addr;
    MSTEP_803B04A0 *curAddr;
} CALLSTACK_803B04A0;
typedef struct VID_LIST_803B04A0 {
    struct VID_LIST_803B04A0 *next;
    struct VID_LIST_803B04A0 *prev;
    u32 vid;
    u32 root;
} VID_LIST_803B04A0;
typedef struct SYNTH_QUEUE_803B04A0 {
    struct SYNTH_QUEUE_803B04A0 *next;
    struct SYNTH_QUEUE_803B04A0 *prev;
    u8 voice;
    u8 jobTabIndex;
} SYNTH_QUEUE_803B04A0;
typedef struct SYNTH_LFO_803B04A0 {
    u32 time;
    u32 period;
    s16 value;
    s16 lastValue;
} SYNTH_LFO_803B04A0;
typedef struct CTRL_SOURCE_803B04A0 {
    u8 midiCtrl;
    u8 combine;
    s32 scale;
} CTRL_SOURCE_803B04A0;
typedef struct CTRL_DEST_803B04A0 {
    CTRL_SOURCE_803B04A0 source[4];
    u16 oldValue;
    u8 numSource;
} CTRL_DEST_803B04A0;
typedef struct SYNTH_VOICE_803B04A0 {
    SYNTH_QUEUE_803B04A0 lowPrecisionJob;
    SYNTH_QUEUE_803B04A0 zeroOffsetJob;
    SYNTH_QUEUE_803B04A0 eventJob;
    u64 lastLowCallTime;
    u64 lastZeroCallTime;
    MSTEP_803B04A0 *addr;
    MSTEP_803B04A0 *curAddr;
    struct SYNTH_VOICE_803B04A0 *nextMacActive;
    struct SYNTH_VOICE_803B04A0 *prevMacActive;
    struct SYNTH_VOICE_803B04A0 *nextTimeQueueMacro;
    struct SYNTH_VOICE_803B04A0 *prevTimeQueueMacro;
    MAC_STATE_803B04A0 macState;
    MSTEP_803B04A0 *trapEventAddr[3];
    MSTEP_803B04A0 *trapEventCurAddr[3];
    u8 trapEventAny;
    CALLSTACK_803B04A0 callStack[4];
    u8 callStackEntryNum;
    u8 callStackIndex;
    u64 macStartTime;
    u64 wait;
    u64 waitTime;
    u8 timeUsedByInput;
    u16 loop;
    s32 local_vars[16];
    u32 child;
    u32 parent;
    u32 id;
    VID_LIST_803B04A0 *vidList;
    VID_LIST_803B04A0 *vidMasterList;
    u16 allocId;
    u16 macroId;
    u8 keyGroup;
    u32 lastVID;
    u8 prio;
    u16 ageSpeed;
    u32 age;
    u64 cFlags;
    u8 block;
    u8 fxFlag;
    u8 vGroup;
    u8 studio;
    u8 track;
    u8 midi;
    u8 midiSet;
    u8 section;
    u32 sInfo;
    u32 playFrq;
    u16 curNote;
    s8 curDetune;
    u8 orgNote;
    u8 lastNote;
    u8 portType;
    u16 portLastCtrlState;
    u32 portDuration;
    u32 portCurPitch;
    u32 portTime;
    u8 vibKeyRange;
    u8 vibCentRange;
    u32 vibPeriod;
    u32 vibCurTime;
    s32 vibCurOffset;
    s16 vibModAddScale;
    u32 volume;
    u32 orgVolume;
    float lastVolFaderScale;
    u32 lastPan;
    u32 lastSPan;
    float treCurScale;
    u16 treScale;
    u16 treModAddScale;
    u32 panning[2];
    s32 panDelta[2];
    u32 panTarget[2];
    u32 panTime[2];
    u8 revVolScale;
    u8 revVolOffset;
    u8 volTable;
    u8 itdMode;
    s32 envDelta;
    u32 envTarget;
    u32 envCurrent;
    u32 sweepOff[2];
    s32 sweepAdd[2];
    s32 sweepCnt[2];
    u8 sweepNum[2];
    SYNTH_LFO_803B04A0 lfo[2];
    u8 lfoUsedByInput[2];
    u8 pbLowerKeyRange;
    u8 pbUpperKeyRange;
    u16 pbLast;
    ADSR_VARS_803B04A0 pitchADSR;
    s16 pitchADSRRange;
    u16 curPitch;
    struct setup_803B04A0 {
        u8 vol;
        u8 pan;
        u8 midi;
        u8 midiSet;
        u8 section;
        u8 track;
        u8 vGroup;
        u8 studio;
        u8 itdMode;
    } setup;
    u32 midiDirtyFlags;
    CTRL_DEST_803B04A0 inpVolume;
    CTRL_DEST_803B04A0 inpPanning;
    CTRL_DEST_803B04A0 inpSurroundPanning;
    CTRL_DEST_803B04A0 inpPitchBend;
    CTRL_DEST_803B04A0 inpDoppler;
    CTRL_DEST_803B04A0 inpModulation;
    CTRL_DEST_803B04A0 inpPedal;
    CTRL_DEST_803B04A0 inpPortamento;
    CTRL_DEST_803B04A0 inpPreAuxA;
    CTRL_DEST_803B04A0 inpReverb;
    CTRL_DEST_803B04A0 inpPreAuxB;
    CTRL_DEST_803B04A0 inpPostAuxB;
    CTRL_DEST_803B04A0 inpTremolo;
    u8 mesgNum;
    u8 mesgRead;
    u8 mesgWrite;
    s32 mesgQueue[4];
    u16 curOutputVolume;
} SYNTH_VOICE_803B04A0;
typedef struct CHANNEL_DEFAULTS_803B04A0 {
    u8 pbRange;
} CHANNEL_DEFAULTS_803B04A0;
#pragma pack()
extern u8 DebugMacroSteps;
extern CTRL_DEST_803B04A0 inpAuxB[8][4];
extern CTRL_DEST_803B04A0 inpAuxA[8][4];
void inpInit(SYNTH_VOICE_803B04A0 *svoice);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
CHANNEL_DEFAULTS_803B04A0 *inpGetChannelDefaults(u8 midi, u8 midiSet);
u32 hwFrq2Pitch(u32 frq);
void hwSetPriority(u32 v, u32 prio);
void hwSetSRCType(u32 v, u8 salSRCType);
void hwSetPolyPhaseFilter(u32 v, u8 salCoefSel);

#define synthVoice (*(SYNTH_VOICE_803B04A0 **)&synthVoice)
#define mcmdWait(s, c) mcmdWait((Obj_803AE8F8 *)(s), (Op_803AE8F8 *)(c))
#define mcmdLoop(s, c) mcmdLoop((Obj_803AEC00 *)(s), (Op_803AEC00 *)(c))
#define mcmdPlayMacro(s, c) mcmdPlayMacro((Voice_803AED58 *)(s), (MSTEP_803AED58 *)(c))
#define mcmdStartSample(s, c) mcmdStartSample((Voice_803AEEF0 *)(s), (MSTEP_803AEEF0 *)(c))
#define mcmdVibrato(s, c) mcmdVibrato((Obj_803AF0CC *)(s), (Op_803AF0CC *)(c))
#define DoSetPitch(s) DoSetPitch((Voice_803AEEF0 *)(s))
#define mcmdSetADSR(s, c) mcmdSetADSR((Voice_803AF3DC *)(s), (MSTEP_803AF3DC *)(c))
#define mcmdSetPitchADSR(s, c) mcmdSetPitchADSR((Voice_803AF634 *)(s), (MSTEP_803AF634 *)(c))
#define DoPanningSetup(s, c, p) DoPanningSetup((Voice_803AF634 *)(s), (MSTEP_803AF634 *)(c), p)
#define DoEnvelopeCalculation(s, c, v) DoEnvelopeCalculation((Voice_803AF9D4 *)(s), (MSTEP_803AF9D4 *)(c), v)
#define mcmdRandomKey(s, c) mcmdRandomKey((Voice_803AFB00 *)(s), (MSTEP_803AFB00 *)(c))
#define SelectSource(s, d, c, m, f) SelectSource((Obj_803AFCA0 *)(s), (s32)(d), (Op_803AFCA0 *)(c), m, f)
#define mcmdPortamento(s, c) mcmdPortamento((Obj_803AFDD4 *)(s), (Op_803AFDD4 *)(c))
#define varSet32(s, c, i, v) varSet32((Obj_803B0004 *)(s), c, i, v)
#define mcmdVarCalculation(s, c, o) mcmdVarCalculation((Voice_803B0068 *)(s), (MSTEP_803B0068 *)(c), o)
#define mcmdSendMessage(s, c) mcmdSendMessage((Voice_803B0198 *)(s), (MSTEP_803B0198 *)(c))
#define mcmdSetKeyGroup(s, c) mcmdSetKeyGroup((Voice_803B03CC *)(s), (MSTEP_803B03CC *)(c))
#define macSetExternalKeyoff(s) macSetExternalKeyoff((Rec_803A9454 *)(s))
#define voiceFree(s) voiceFree((Obj_803B312C *)(s))
#define vidRemoveVoiceReferences(s) vidRemoveVoiceReferences((Prog_803B25CC *)(s))
#define voiceIsLastStarted(s) ((u32)voiceIsLastStarted((Obj_803B3AA8 *)(s)))
#define voiceSetLastStarted(s) voiceSetLastStarted((Obj_803B3B24 *)(s))
#define voiceSetPriority(s, p) voiceSetPriority((Voice_803B2128 *)(s), p)
#define synthStartSynthJobHandling(s) synthStartSynthJobHandling((Obj_803A8C5C *)(s))
#define synthKeyStateUpdate(s) synthKeyStateUpdate((Voice_803AEEF0 *)(s))
#define inpGetModulation(s) inpGetModulation((SYNTH_VOICE_SV *)(s))
#define inpGetExCtrl(s, c) inpGetExCtrl(s, (u8)(c))
#define inpGetMidiCtrl(c, m, s) inpGetMidiCtrl((u8)(c), m, s)
static inline int SendSingleKeyOff_803B04A0(u32 voiceid) {
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
static inline u32 mcmdWaitMs_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    ((u8 *)&cstep->para[1])[2] = 1;
    return mcmdWait(svoice, cstep);
}
static inline u32 mcmdEndOfMacro_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    vidRemoveVoiceReferences(svoice);
    voiceFree(svoice);
    return 1;
}
static inline u32 mcmdStop_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    return mcmdEndOfMacro_803B04A0(svoice);
}
static inline u32 mcmdReturn_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    if (svoice->callStackEntryNum != 0) {
        svoice->addr = svoice->callStack[svoice->callStackIndex].addr;
        svoice->curAddr = svoice->callStack[svoice->callStackIndex].curAddr;
        svoice->callStackIndex = (svoice->callStackIndex - 1) & 3;
        --svoice->callStackEntryNum;
    }
    return 0;
}
static inline void mcmdIfKey_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    if (svoice->curNote < ((u8)(cstep->para[0] >> 8))) {
        return;
    }
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro((cstep->para[0] >> 0x10))) != 0) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)cstep->para[1];
    }
}
static inline void mcmdIfVelocity_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    if (((u8)(svoice->volume >> 0x10)) < (u8)(cstep->para[0] >> 8)) {
        return;
    }
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro(cstep->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)cstep->para[1];
    }
}
static inline void mcmdIfModulation_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    u8 mod;
    if (svoice->midi == 0xff) {
        return;
    }
    mod = inpGetModulation(svoice) >> 7;
    if (mod < (u8)(cstep->para[0] >> 8)) {
        return;
    }
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro(cstep->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)(cstep->para[1]);
    }
}
static inline void mcmdIfRandom_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    if ((u8)sndRand() < (u8)(cstep->para[0] >> 8)) {
        return;
    }
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro(cstep->para[0] >> 0x10))) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)cstep->para[1];
    }
}
static inline u32 mcmdGoto_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro(cstep->para[0] >> 0x10)) != 0) {
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)cstep->para[1];
        return 0;
    }
    return mcmdEndOfMacro_803B04A0(svoice);
}
static inline u32 mcmdGosub_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro((u16)(cstep->para[0] >> 0x10))) != 0) {
        svoice->callStackIndex = (svoice->callStackIndex + 1) & 3;
        svoice->callStack[svoice->callStackIndex].addr = svoice->addr;
        svoice->callStack[svoice->callStackIndex].curAddr = svoice->curAddr;
        if (++svoice->callStackEntryNum > 4) {
            svoice->callStackEntryNum = 4;
        }
        svoice->addr = addr;
        svoice->curAddr = addr + (u16)cstep->para[1];
        return 0;
    }
    return mcmdEndOfMacro_803B04A0(svoice);
}
static inline void mcmdTrapEvent_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    MSTEP_803B04A0 *addr;
    u8 t;
    if ((addr = (MSTEP_803B04A0 *)dataGetMacro(cstep->para[0] >> 0x10)) != 0) {
        t = (u8)(cstep->para[0] >> 8);
        svoice->trapEventAddr[t] = addr;
        svoice->trapEventCurAddr[t] = addr + (u16)cstep->para[1];
        svoice->trapEventAny = 1;
        if (t == 0 && (svoice->cFlags & 0x10000000008) == 0x10000000008) {
            svoice->cFlags |= 0x40000000000;
        }
    }
}
static inline void mcmdUntrapEvent_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u8 i;
    svoice->trapEventAddr[(u8)(cstep->para[0] >> 8)] = 0;
    for (i = 0; i < 3; ++i) {
        if (svoice->trapEventAddr[i] != 0) {
            return;
        }
    }
    svoice->trapEventAny = 0;
}
static inline void mcmdSendKeyOff_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 voiceid;
    u32 i;
    voiceid = (svoice->orgNote + (u8)(cstep->para[0] >> 8)) << 8;
    voiceid |= ((u16)(cstep->para[0] >> 16)) << 16;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        if (synthVoice[i].id == (voiceid | i)) {
            SendSingleKeyOff_803B04A0(voiceid | i);
        }
    }
}
static inline void mcmdAddAgeCounter_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    s16 step;
    s32 age;
    step = (u16)(cstep->para[0] >> 16);
    age = (svoice->age >> 15) + step;
    if (age < 0) {
        svoice->age = 0;
    } else if (age > 0xFFFF) {
        svoice->age = 0x7fff8000;
    } else {
        svoice->age = age * 0x8000;
    }
    hwSetPriority(svoice->id & 0xFF, ((u32)svoice->prio << 24) | ((u32)svoice->age >> 15));
}
static inline void mcmdSetAgeCounter_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->age = (u16)(cstep->para[0] >> 0x10) << 0xf;
    hwSetPriority(svoice->id & 0xff, (u32)svoice->prio << 0x18 | svoice->age >> 0xf);
}
static inline void mcmdSetAgeCounterSpeed_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 time = cstep->para[1];
    if (time != 0) {
        svoice->ageSpeed = (svoice->age >> 8) / time;
    } else {
        svoice->ageSpeed = 0;
    }
}
static inline void mcmdSetAgeCounterByVolume_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 age;
    age = (((u8)(svoice->volume >> 16) * (u16)cstep->para[1]) >> 7) + (u16)(cstep->para[0] >> 16);
    svoice->age = age > 60000 ? 0x75300000 : age * 0x8000;
    hwSetPriority(svoice->id & 0xff, (u32)svoice->prio << 0x18 | svoice->age >> 0xf);
}
static inline void mcmdAddPriority_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    s16 add;
    s16 prio;
    add = (u16)(cstep->para[0] >> 16);
    prio = svoice->prio + add;
    prio = (prio < 0) ? 0 : (prio > 0xFF) ? 0xFF : prio;
    voiceSetPriority(svoice, prio);
}
static inline void mcmdSetPriority_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    voiceSetPriority(svoice, cstep->para[0] >> 8);
}
static inline void mcmdSendFlag_803B04A0(MSTEP_803B04A0 *cstep) {
    synthGlobalVariable[(u8)(cstep->para[0] >> 8)] = (u8)(cstep->para[0] >> 16);
}
static inline void mcmdSetPitchWheelRange_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->pbLowerKeyRange = (u8)(cstep->para[0] >> 0x10);
    svoice->pbUpperKeyRange = (u8)(cstep->para[0] >> 8);
}
static inline u32 mcmdSetKey_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->curNote = (u8)(cstep->para[0] >> 8) & 0x7f;
    svoice->curDetune = (s8)(cstep->para[0] >> 0x10);
    if (voiceIsLastStarted(svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote & 0xff);
    }
    cstep->para[0] = 4;
    return mcmdWait(svoice, cstep);
}
static inline u32 mcmdAddKey_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    if ((u8)(cstep->para[0] >> 0x18) == 0) {
        svoice->curNote += (s8)(u8)(cstep->para[0] >> 8);
    } else {
        svoice->curNote = (u16)svoice->orgNote + (s16)(s8)(u8)(cstep->para[0] >> 8);
    }
    svoice->curNote = (s16)svoice->curNote < 0 ? 0 : svoice->curNote > 0x7f ? 0x7f : svoice->curNote;
    svoice->curDetune = (s8)(cstep->para[0] >> 0x10);
    if (voiceIsLastStarted(svoice) != 0) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote);
    }
    cstep->para[0] = 4;
    return mcmdWait(svoice, cstep);
}
static inline u32 mcmdLastKey_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->curNote = svoice->lastNote + (s8)(u8)(cstep->para[0] >> 8);
    svoice->curNote = (s16)svoice->curNote < 0 ? 0 : svoice->curNote > 0x7f ? 0x7f : svoice->curNote;
    svoice->curDetune = (s8)(cstep->para[0] >> 16);
    if (svoice->midi != 0xFF) {
        inpSetMidiLastNote(svoice->midi, svoice->midiSet, svoice->curNote);
    }
    cstep->para[0] = 4;
    return mcmdWait(svoice, cstep);
}
static inline void mcmdStopSample_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    hwBreak(svoice->id & 0xFF);
}
static inline void mcmdKeyOff_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    svoice->cFlags |= 0x80;
    synthKeyStateUpdate(svoice);
}
static inline void mcmdSetMod2Vibrato_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->vibModAddScale = (s8)(cstep->para[0] >> 8) << 8;
    if (svoice->vibModAddScale >= 0) {
        svoice->vibModAddScale += ((s16)(s8)(cstep->para[0] >> 0x10) << 8) / 100;
    } else {
        svoice->vibModAddScale -= ((s16)(s8)(cstep->para[0] >> 0x10) << 8) / 100;
    }
}
static inline void mcmdSetupLFO_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 time;
    u32 phase;
    u8 n;
    n = (u8)(cstep->para[0] >> 8);
    time = (u16)(cstep->para[0] >> 0x10);
    sndConvertMs(&time);
    if (svoice->lfo[n].period != 0) {
        phase = (u16)cstep->para[1];
        sndConvertMs(&phase);
        svoice->lfo[n].time = phase;
    }
    svoice->lfo[n].period = time;
}
static inline void mcmdSetPitch_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->playFrq = (u32)(cstep->para[0] >> 8);
    svoice->playFrq |= (u8)cstep->para[1];
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
static inline void mcmdSetADSRFromCtrl_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    f32 sScale;
    ADSR_INFO_803B04A0 adsr;
    sScale = dspDLSVolTab[inpGetMidiCtrl(cstep->para[0] >> 24, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.atime = midi2TimeTab[inpGetMidiCtrl(cstep->para[0] >> 8, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.dtime = midi2TimeTab[inpGetMidiCtrl(cstep->para[0] >> 16, svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.slevel = 193 - dspScale2IndexTab[(u32)(1023.f * sScale)];
    adsr.data.dls.rtime = midi2TimeTab[inpGetMidiCtrl(cstep->para[1], svoice->midi, svoice->midiSet) >> 7];
    adsr.data.dls.ascale = -0x80000000;
    adsr.data.dls.dscale = -0x80000000;
    hwSetADSR((u8)svoice->id, &adsr, 2);
    svoice->cFlags |= 0x100;
}
static inline u32 mcmdPitchSweep_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep, int num) {
    s32 delta;
    svoice->sweepOff[num] = 0;
    svoice->sweepNum[num] = (u8)(cstep->para[0] >> 8);
    svoice->sweepCnt[num] = (s32)svoice->sweepNum[num] << 0x10;
    delta = (int)(short)(cstep->para[0] >> 0x10);
    if (delta >= 0) {
        delta = hwFrq2Pitch(delta);
    } else {
        delta = -hwFrq2Pitch(-delta);
    }
    svoice->sweepAdd[num] = delta << 0x10;
    cstep->para[0] = 0;
    return mcmdWait(svoice, cstep);
}
static inline void mcmdSetPanning_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    DoPanningSetup(svoice, cstep, 0);
}
static inline void mcmdSetSurroundPanning_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    DoPanningSetup(svoice, cstep, 1);
}
static inline void mcmdSetPianoPanning_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    s32 delta;
    s32 scale;
    delta = (svoice->curNote << 16) - ((u8)(cstep->para[0] >> 16) << 16);
    scale = (s8)((u8)(cstep->para[0] >> 8));
    delta = ((delta * scale) >> 7);
    delta += (u8)(cstep->para[0] >> 0x18) << 16;
    delta = delta < 0 ? 0 : delta > 0x7f0000 ? 0x7f0000 : delta;
    svoice->panTarget[0] = delta;
    svoice->panning[0] = delta;
}
static inline void mcmdScaleVolume_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u16 curve;
    u16 scale;
    scale = (u16)(u8)(cstep->para[0] >> 8);
    if ((u8)(cstep->para[1] >> 8) == 0) {
        svoice->volume = (svoice->volume * scale) / 0x7f;
    } else {
        svoice->volume = (svoice->orgVolume * scale) / 0x7f;
    }
    svoice->volume += (u8)(cstep->para[0] >> 16) << 16;
    if (svoice->volume > 0x7f0000) {
        svoice->volume = 0x7f0000;
    }
    curve = (u8)(cstep->para[0] >> 0x18);
    curve |= ((u16)((u8)cstep->para[1]) << 8);
    svoice->volume = TranslateVolume(svoice->volume, curve);
    svoice->cFlags |= 0x100000000000;
}
static inline void mcmdScaleVolumeDLS_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u16 scale;
    scale = (cstep->para[0] >> 8);
    if ((u8)(cstep->para[0] >> 0x18) == 0) {
        svoice->volume = ((svoice->volume >> 5) * scale) >> 7;
    } else {
        svoice->volume = ((svoice->orgVolume >> 5) * scale) >> 7;
    }
    if (svoice->volume > 0x7f0000) {
        svoice->volume = 0x7f0000;
    }
    svoice->cFlags |= 0x100000000000;
}
static inline void mcmdEnvelope_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    DoEnvelopeCalculation(svoice, cstep, svoice->volume);
}
static inline void mcmdFadeIn_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    DoEnvelopeCalculation(svoice, cstep, 0);
}
static inline void mcmdSetPitchbendAfterKeyOff_803B04A0(SYNTH_VOICE_803B04A0 *svoice) {
    svoice->cFlags |= 0x10000;
}
static inline void mcmdScaleReverb_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->revVolScale = (u8)(cstep->para[0] >> 8);
    svoice->revVolOffset = (u8)(cstep->para[0] >> 0x10);
}
static inline void mcmdVolumeSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpVolume, cstep, 0x80000, 1);
}
static inline void mcmdPanningSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPanning, cstep, 0x100000, 2);
}
static inline void mcmdPitchWheelSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPitchBend, cstep, 0x200000, 8);
}
static inline void mcmdModWheelSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpModulation, cstep, 0x400000, 0x20);
}
static inline void mcmdPedalSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPedal, cstep, 0x2000000, 0x40);
}
static inline void mcmdPortamentoSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPortamento, cstep, 0x1000000, 0x80);
}
static inline void mcmdReverbSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpReverb, cstep, 0x800000, 0x200);
}
static inline void mcmdPreAuxASelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPreAuxA, cstep, 0x20000000, 0x100);
}
static inline void mcmdPreAuxBSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPreAuxB, cstep, 0x40000000, 0x400);
}
static inline void mcmdPostAuxBSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpPostAuxB, cstep, 0x80000000, 0x800);
}
static inline void mcmdSurroundPanningSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpSurroundPanning, cstep, 0x4000000, 4);
}
static inline void mcmdDopplerSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpDoppler, cstep, 0x8000000, 0x10);
}
static inline void mcmdTremoloSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    SelectSource(svoice, &svoice->inpTremolo, cstep, 0x10000000, 0x1000);
}
static inline void mcmdAuxAFXSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 i;
    static u64 mask[4] = {0x100000000, 0x200000000, 0x400000000, 0x800000000};
    static u32 dirty[4] = {0x80000001, 0x80000002, 0x80000004, 0x80000008};
    i = (u8)(cstep->para[1] >> 0x18);
    SelectSource(svoice, &inpAuxA[svoice->studio][i], cstep, mask[i], dirty[i]);
}
static inline void mcmdAuxBFXSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    u32 i;
    static u64 mask[4] = {0x1000000000, 0x2000000000, 0x4000000000, 0x8000000000};
    static u32 dirty[4] = {0x80000010, 0x80000020, 0x80000040, 0x80000080};
    i = (u8)(cstep->para[1] >> 0x18);
    SelectSource(svoice, &inpAuxB[svoice->studio][i], cstep, mask[i], dirty[i]);
}
static inline s32 varGet32_803B04A0(SYNTH_VOICE_803B04A0 *svoice, u32 ctrl, u8 index) {
    if (ctrl != 0) {
        return inpGetExCtrl(svoice, index);
    }
    index &= 0x1f;
    return index < 16 ? svoice->local_vars[index] : synthGlobalVariable[index - 16];
}
static inline void varSet_803B04A0(SYNTH_VOICE_803B04A0 *svoice, u32 ctrl, u8 index, s16 v) {
    varSet32(svoice, ctrl, index, v);
}
static inline void mcmdSetVarImmediate_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    varSet_803B04A0(svoice, (u8)(cstep->para[0] >> 8), (u8)(cstep->para[0] >> 0x10), (s16)cstep->para[1]);
}
static inline void mcmdIfVarCompare_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep, u8 cmp) {
    s32 a;
    s32 b;
    u8 result;
    a = varGet32_803B04A0(svoice, (u8)(cstep->para[0] >> 8), (u8)(cstep->para[0] >> 0x10));
    b = varGet32_803B04A0(svoice, (u8)(cstep->para[0] >> 0x18), (u8)cstep->para[1]);
    switch (cmp) {
    case 0:
        result = !(b - a);
        break;
    case 1:
        result = (a < b);
        break;
    }
    if ((u8)(cstep->para[1] >> 8) != 0) {
        result = !result;
    }
    if ((u8)result != 0) {
        svoice->curAddr = svoice->addr + (u16)(cstep->para[1] >> 0x10);
    }
}
static inline void mcmdGetMessage_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    s32 mesg;
    mesg = 0;
    if (svoice->mesgNum != 0) {
        mesg = svoice->mesgQueue[svoice->mesgRead];
        svoice->mesgRead = (svoice->mesgRead + 1) & 3;
        --svoice->mesgNum;
    }
    varSet32(svoice, 0, (u8)(cstep->para[0] >> 8), mesg);
}
static inline void mcmdGetVID_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    if ((u8)(cstep->para[0] >> 0x10) == 0) {
        varSet32(svoice, 0, (u8)(cstep->para[0] >> 8), svoice->vidList->vid);
    } else {
        varSet32(svoice, 0, (u8)(cstep->para[0] >> 8), svoice->lastVID);
    }
}
static inline void mcmdModeSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->volTable = (u8)(cstep->para[0] >> 8) ? 1 : 0;
    svoice->itdMode = (u8)(cstep->para[0] >> 0x10) ? 0 : 1;
}
static inline void mcmdSRCModeSelect_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    hwSetSRCType(svoice->id & 0xff, (u8)(cstep->para[0] >> 8));
    hwSetPolyPhaseFilter(svoice->id & 0xff, (u8)(cstep->para[0] >> 0x10));
    svoice->cFlags |= 0x80000000000;
}
static inline void mcmdSetupTremolo_803B04A0(SYNTH_VOICE_803B04A0 *svoice, MSTEP_803B04A0 *cstep) {
    svoice->treScale = (cstep->para[0] >> 8);
    svoice->treModAddScale = cstep->para[1];
    svoice->treCurScale = 1.f;
}
extern MSTEP_803B04A0 cstep;
void macHandleActive(SYNTH_VOICE_803B04A0 *svoice) {
    u8 i;
    u8 lastNote;
    u32 ex;
    CHANNEL_DEFAULTS_803B04A0 *channelDefaults;
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
        inpInit(svoice);
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
            ex = mcmdEndOfMacro_803B04A0(svoice);
            break;
        case 0x1:
            ex = mcmdStop_803B04A0(svoice);
            break;
        case 0x2:
            mcmdIfKey_803B04A0(svoice, &cstep);
            break;
        case 0x3:
            mcmdIfVelocity_803B04A0(svoice, &cstep);
            break;
        case 0x4:
            ex = mcmdWait(svoice, &cstep);
            break;
        case 0x5:
            mcmdLoop(svoice, &cstep);
            break;
        case 0x6:
            ex = mcmdGoto_803B04A0(svoice, &cstep);
            break;
        case 0x7:
            ex = mcmdWaitMs_803B04A0(svoice, &cstep);
            break;
        case 0x8:
            mcmdPlayMacro(svoice, &cstep);
            break;
        case 0x9:
            mcmdSendKeyOff_803B04A0(svoice, &cstep);
            break;
        case 0xa:
            mcmdIfModulation_803B04A0(svoice, &cstep);
            break;
        case 0xb:
            mcmdSetPianoPanning_803B04A0(svoice, &cstep);
            break;
        case 0xc:
            mcmdSetADSR(svoice, &cstep);
            break;
        case 0xd:
            mcmdScaleVolume_803B04A0(svoice, &cstep);
            break;
        case 0xe:
            mcmdSetPanning_803B04A0(svoice, &cstep);
            break;
        case 0xf:
            mcmdEnvelope_803B04A0(svoice, &cstep);
            break;
        case 0x10:
            mcmdStartSample(svoice, &cstep);
            break;
        case 0x11:
            mcmdStopSample_803B04A0(svoice);
            break;
        case 0x12:
            mcmdKeyOff_803B04A0(svoice);
            break;
        case 0x13:
            mcmdIfRandom_803B04A0(svoice, &cstep);
            break;
        case 0x14:
            mcmdFadeIn_803B04A0(svoice, &cstep);
            break;
        case 0x15:
            mcmdSetSurroundPanning_803B04A0(svoice, &cstep);
            break;
        case 0x16:
            mcmdSetADSRFromCtrl_803B04A0(svoice, &cstep);
            break;
        case 0x17:
            mcmdRandomKey(svoice, &cstep);
            break;
        case 0x18:
            ex = mcmdAddKey_803B04A0(svoice, &cstep);
            break;
        case 0x19:
            ex = mcmdSetKey_803B04A0(svoice, &cstep);
            break;
        case 0x1a:
            ex = mcmdLastKey_803B04A0(svoice, &cstep);
            break;
        case 0x1b:
            mcmdPortamento(svoice, &cstep);
            break;
        case 0x1c:
            mcmdVibrato(svoice, &cstep);
            break;
        case 0x1d:
            ex = mcmdPitchSweep_803B04A0(svoice, &cstep, 0);
            break;
        case 0x1e:
            ex = mcmdPitchSweep_803B04A0(svoice, &cstep, 1);
            break;
        case 0x1f:
            mcmdSetPitch_803B04A0(svoice, &cstep);
            break;
        case 0x20:
            mcmdSetPitchADSR(svoice, &cstep);
            break;
        case 0x21:
            mcmdScaleVolumeDLS_803B04A0(svoice, &cstep);
            break;
        case 0x22:
            mcmdSetMod2Vibrato_803B04A0(svoice, &cstep);
            break;
        case 0x23:
            mcmdSetupTremolo_803B04A0(svoice, &cstep);
            break;
        case 0x24:
            mcmdReturn_803B04A0(svoice);
            break;
        case 0x25:
            ex = mcmdGosub_803B04A0(svoice, &cstep);
            break;
        case 0x28:
            mcmdTrapEvent_803B04A0(svoice, &cstep);
            break;
        case 0x29:
            mcmdUntrapEvent_803B04A0(svoice, &cstep);
            break;
        case 0x2a:
            mcmdSendMessage(svoice, &cstep);
            break;
        case 0x2b:
            mcmdGetMessage_803B04A0(svoice, &cstep);
            break;
        case 0x2c:
            mcmdGetVID_803B04A0(svoice, &cstep);
            break;
        case 0x30:
            mcmdAddAgeCounter_803B04A0(svoice, &cstep);
            break;
        case 0x31:
            mcmdSetAgeCounter_803B04A0(svoice, &cstep);
            break;
        case 0x32:
            mcmdSendFlag_803B04A0(&cstep);
            break;
        case 0x33:
            mcmdSetPitchWheelRange_803B04A0(svoice, &cstep);
            break;
        case 0x34:
            mcmdScaleReverb_803B04A0(svoice, &cstep);
            break;
        case 0x35:
            mcmdSetPitchbendAfterKeyOff_803B04A0(svoice);
            break;
        case 0x36:
            mcmdSetPriority_803B04A0(svoice, &cstep);
            break;
        case 0x37:
            mcmdAddPriority_803B04A0(svoice, &cstep);
            break;
        case 0x38:
            mcmdSetAgeCounterSpeed_803B04A0(svoice, &cstep);
            break;
        case 0x39:
            mcmdSetAgeCounterByVolume_803B04A0(svoice, &cstep);
            break;
        case 0x40:
            mcmdVolumeSelect_803B04A0(svoice, &cstep);
            break;
        case 0x41:
            mcmdPanningSelect_803B04A0(svoice, &cstep);
            break;
        case 0x42:
            mcmdPitchWheelSelect_803B04A0(svoice, &cstep);
            break;
        case 0x43:
            mcmdModWheelSelect_803B04A0(svoice, &cstep);
            break;
        case 0x44:
            mcmdPedalSelect_803B04A0(svoice, &cstep);
            break;
        case 0x45:
            mcmdPortamentoSelect_803B04A0(svoice, &cstep);
            break;
        case 0x46:
            mcmdReverbSelect_803B04A0(svoice, &cstep);
            break;
        case 0x47:
            mcmdSurroundPanningSelect_803B04A0(svoice, &cstep);
            break;
        case 0x48:
            mcmdDopplerSelect_803B04A0(svoice, &cstep);
            break;
        case 0x49:
            mcmdTremoloSelect_803B04A0(svoice, &cstep);
            break;
        case 0x4a:
            mcmdPreAuxASelect_803B04A0(svoice, &cstep);
            break;
        case 0x4b:
            mcmdPreAuxBSelect_803B04A0(svoice, &cstep);
            break;
        case 0x4c:
            mcmdPostAuxBSelect_803B04A0(svoice, &cstep);
            break;
        case 0x4d:
            mcmdAuxAFXSelect_803B04A0(svoice, &cstep);
            break;
        case 0x4e:
            mcmdAuxBFXSelect_803B04A0(svoice, &cstep);
            break;
        case 0x50:
            mcmdSetupLFO_803B04A0(svoice, &cstep);
            break;
        case 0x58:
            mcmdModeSelect_803B04A0(svoice, &cstep);
            break;
        case 0x59:
            mcmdSetKeyGroup(svoice, &cstep);
            break;
        case 0x5a:
            mcmdSRCModeSelect_803B04A0(svoice, &cstep);
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
            mcmdSetVarImmediate_803B04A0(svoice, &cstep);
            break;
        case 0x70:
            mcmdIfVarCompare_803B04A0(svoice, &cstep, 0);
            break;
        case 0x71:
            mcmdIfVarCompare_803B04A0(svoice, &cstep, 1);
            break;
        }
    } while (!ex);
}

#undef synthVoice
#undef synthInfo
#undef synthGlobalVariable
#undef inpAuxA
#undef inpAuxB
#undef mcmdWait
#undef mcmdLoop
#undef mcmdPlayMacro
#undef mcmdStartSample
#undef mcmdVibrato
#undef DoSetPitch
#undef mcmdSetADSR
#undef mcmdSetPitchADSR
#undef DoPanningSetup
#undef DoEnvelopeCalculation
#undef mcmdRandomKey
#undef SelectSource
#undef mcmdPortamento
#undef varSet32
#undef mcmdVarCalculation
#undef mcmdSendMessage
#undef mcmdSetKeyGroup
#undef macSetExternalKeyoff
#undef voiceFree
#undef vidRemoveVoiceReferences
#undef voiceIsLastStarted
#undef voiceSetLastStarted
#undef voiceSetPriority
#undef synthStartSynthJobHandling
#undef synthKeyStateUpdate
#undef inpGetModulation
#undef inpGetExCtrl
#undef inpGetMidiCtrl
#pragma pop

#define macTimeQueueRoot ((SYNTH_VOICE_803B19AC *)lbl_805D7420)
#define macActiveMacroRoot ((SYNTH_VOICE_803B19AC *)lbl_805D741C)

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline u32 ExecuteTrap_803B19AC(SYNTH_VOICE_803B19AC *svoice, u8 trapType) {
    if (svoice->trapEventAny != 0 && svoice->trapEventAddr[trapType] != NULL) {
        svoice->curAddr = svoice->trapEventCurAddr[trapType];
        svoice->addr = svoice->trapEventAddr[trapType];
        svoice->trapEventAddr[trapType] = NULL;
        macMakeActive(svoice);
        return 1;
    }

    return 0;
}

static inline u32 HasHWEventTrap_803B19AC(SYNTH_VOICE_803B19AC *svoice) {
    if (svoice->trapEventAny != 0) {
        return svoice->trapEventAddr[1] != NULL;
    }
    return 0;
}

static inline void CheckHWEventTrap_803B19AC(SYNTH_VOICE_803B19AC *svoice) {
    if ((svoice->cFlags & 0x20) == 0 && !hwIsActive(svoice->id & 0xff)) {
        ExecuteTrap_803B19AC(svoice, 1);
    }
}

void macHandle(u32 deltaTime) {
    SYNTH_VOICE_803B19AC *sv;
    SYNTH_VOICE_803B19AC *nextSv;
    u64 w;

    for (sv = macTimeQueueRoot; sv != NULL && sv->wait <= macRealTime;) {
        nextSv = sv->nextTimeQueueMacro;
        w = sv->wait;
        macMakeActive(sv);
        sv->waitTime = w;
        sv = nextSv;
    }

    for (sv = macActiveMacroRoot; sv != NULL; sv = sv->nextMacActive) {
        nextSv = sv->nextMacActive;
        if (HasHWEventTrap_803B19AC(sv) != 0) {
            CheckHWEventTrap_803B19AC(sv);
        }
        macHandleActive((SYNTH_VOICE_803B04A0 *)sv);
    }
    macRealTime += deltaTime;
}

#pragma pop

void macSampleEndNotify(Rec_803A996C *ov) {
    u32 done;

    if (o->f4c == 1) {
        if (o->f68 != 0 && o->f54 != 0) {
            o->f38 = o->f60;
            o->f34 = o->f54;
            o->f54 = 0;
            macMakeActive(o);
            done = 1;
        } else {
            done = 0;
        }
        if (done == 0 && (o->flags & 0x40000) != 0) {
            macMakeActive(o);
        }
    }
}
#undef o

void macSetExternalKeyoff(Rec_803A9454 *arg0) {
    Ch_803B1BA4 *o = (Ch_803B1BA4 *)arg0;
    u32 done;

    o->flags |= 8;
    if (o->f34 != 0) {
        if ((o->flags & 0x10000000000ULL) == 0) {
            if (o->f68 != 0 && o->f50 != 0) {
                o->f38 = o->f5c;
                o->f34 = o->f50;
                o->f50 = 0;
                macMakeActive(o);
                done = 1;
            } else {
                done = 0;
            }
            if (done == 0 && (o->flags & 4) != 0) {
                macMakeActive(o);
            }
        } else {
            o->flags |= 0x40000000000ULL;
        }
    }
}

#undef FLAGS
#define FLAGS (*(u64 *)&v->fh)
void macSetPedalState(Voice_803B1C98 *v, u32 hold) {
    u32 started;

    if (hold != 0) {
        FLAGS |= 0x10000000000ULL;
        return;
    }
    if (v->i34 != 0 && (FLAGS & 0x40000000000ULL) != 0) {
        if (v->b68 != 0 && v->i50 != 0) {
            v->i38 = v->i5C;
            v->i34 = v->i50;
            v->i50 = 0;
            macMakeActive(v);
            started = 1;
        } else {
            started = 0;
        }
        if (started == 0 && (FLAGS & 4ULL) != 0) {
            macMakeActive(v);
        }
    }
    FLAGS &= ~0x50000000000ULL;
}
#undef FLAGS

void TimeQueueAdd(Program_803B1DA4 *self) {
    Program_803B1DA4 *p;
    Program_803B1DA4 *prev;
    p = lbl_805D7420;
    prev = NULL;
    while (p != NULL && p->deadline < self->deadline) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        if (prev == NULL) {
            lbl_805D7420 = self;
            self->next = NULL;
            self->prev = NULL;
        } else {
            prev->next = self;
            self->prev = prev;
            self->next = NULL;
        }
    } else {
        self->next = p;
        if ((self->prev = p->prev) != NULL) {
            p->prev->next = self;
        } else {
            lbl_805D7420 = self;
        }
        p->prev = self;
    }
}

void UnYieldMacro(Ch_803B1E48 *o, u32 arg1) {
    if (o->f98 != 0) {
        if (o->f98 != -1) {
            if (o->prev == NULL) {
                lbl_805D7420 = o->next;
            } else {
                o->prev->next = o->next;
            }
            if (o->next != NULL) {
                o->next->prev = o->prev;
            }
        }
        if (arg1 == 0) {
            synthForceLowPrecisionUpdate(o);
        }
        o->f98 = 0;
        o->fa0 = macRealTime;
        o->flags &= ~0x40004ULL;
    }
}

#define p1F24 ((V_803B1F24 *)arg0)
#define FLAGS (*(u64 *)&p1F24->fh)
void macMakeActive(void *arg0) {
    if (p1F24->i4C != 0) {
        if (p1F24->deadline != 0) {
            if (p1F24->deadline != 0xFFFFFFFFFFFFFFFFULL) {
                if (p1F24->prev == 0) {
                    lbl_805D7420 = (Program_803B1DA4 *)p1F24->next;
                } else {
                    p1F24->prev->next = p1F24->next;
                }
                if (p1F24->next != 0) {
                    p1F24->next->prev = p1F24->prev;
                }
            }
            synthForceLowPrecisionUpdate(p1F24);
            p1F24->deadline = 0;
            p1F24->started = macRealTime;
            FLAGS &= ~0x40004ULL;
        }
        if ((p1F24->vnext = lbl_805D741C) != 0) {
            lbl_805D741C->vprev = p1F24;
        }
        p1F24->vprev = 0;
        lbl_805D741C = p1F24;
        p1F24->i4C = 0;
    }
}
#undef p1F24
#undef FLAGS

#define o ((Ch_803B202C *)ov)
void macMakeInactive(Obj_803B312C *ov, s32 state) {
    if (o->state == state) {
        return;
    }
    if (o->state == 0) {
        if (o->wprev == NULL) {
            lbl_805D741C = o->wnext;
        } else {
            o->wprev->vnext = o->wnext;
        }
        if (o->wnext != NULL) {
            o->wnext->vprev = o->wprev;
        }
    }
    if (state == 2) {
        if (o->f98 != 0) {
            if (o->f98 != -1) {
                if (o->prev == NULL) {
                    lbl_805D7420 = o->next;
                } else {
                    o->prev->next = o->next;
                }
                if (o->next != NULL) {
                    o->next->prev = o->prev;
                }
            }
            o->f98 = 0;
            o->fa0 = macRealTime;
            o->flags &= ~0x40004ULL;
        }
    }
    o->state = state;
}
#undef o

#define HEAD (*(Voice_803B2128 **)&lbl_805D741C)

u32 macStart(u16 arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7,
                      u8 arg8, u8 arg9, u16 arg10, u16 arg11, u8 arg12, u8 arg13, u8 arg14, u32 arg15) {
    u32 macro;
    s32 flag;
    u16 r;
    u32 id;
    Voice_803B2128 *v;
    u32 vid;

    macro = dataGetMacro(arg0);
    if (macro != 0) {
        flag = arg4 & 0x80;
        if (flag == 0) {
            r = seqGetMIDIPriority(arg8, arg7);
            if (r != 0xFFFF) {
                arg1 = r;
            }
        }
        id = voiceAllocate(arg1, arg2, arg3, flag != 0 ? 1 : 0);
        if (id != 0xFFFFFFFF) {
            v = (Voice_803B2128 *)((u8 *)synthVoice + id * 0x404);
            vidRemoveVoiceReferences((Prog_803B25CC *)v);
            if (v->state != 2) {
                if (v->state == 0) {
                    if (v->prev == NULL) {
                        HEAD = v->next;
                    } else {
                        v->prev->next = v->next;
                    }
                    if (v->next != NULL) {
                        v->next->prev = v->prev;
                    }
                }
                UnYieldMacro((Ch_803B1E48 *)v, 1);
                v->state = 2;
            }
            v->flags = (v->flags & 0x10) | 2;
            if (hwIsActive(id) != 0) {
                v->flags |= 1;
            }
            v->f98 = 0;
            if (flag != 0) {
                v->f11D = 1;
                arg4 &= 0x7F;
                inpResetMidiCtrl(id, 0xFF, 1);
                inpResetChannelDefaults(id, 0xFF);
                v->f20A = id;
                v->f20B = 0xFF;
                v->f20C = 0;
            } else {
                v->f11D = 0;
                v->f20A = arg7;
                v->f20B = arg8;
                v->f20C = arg9;
            }
            v->f102 = arg0;
            v->f100 = arg3;
            v->f110 = 0x75300000;
            v->f10E = 0x400;
            v->macroStart = macro;
            v->macroCur = macro + arg10 * 8;
            v->f12F = arg4;
            v->f12C = arg4;
            v->f12E = 0;
            v->f208 = arg5;
            v->f209 = arg6;
            v->f20D = arg11;
            v->f8C = 0;
            v->f8D = 0;
            v->fEC = -1;
            v->fF0 = -1;
            v->f108 = -1;
            v->f20E = arg13;
            v->f20F = arg14;
            v->f210 = arg15 != 0 ? 0 : 1;
            v->f3EE = 0;
            v->f3ED = 0;
            v->f3EC = 0;
            v->fF4 = id | ((arg0 << 16) | ((arg4 << 8) & 0xFF00));
            voiceSetPriority(v, arg1);
            vid = vidMakeNew((SYNTH_VOICE_SV *)v, arg12);
            if (vid != 0xFFFFFFFF) {
                if (v->state != 0) {
                    UnYieldMacro((Ch_803B1E48 *)v, 0);
                    if ((v->next = HEAD) != NULL) {
                        HEAD->prev = v;
                    }
                    v->prev = NULL;
                    HEAD = v;
                    v->state = 0;
                }
                return vid;
            }
            if (hwIsActive(id) != 0) {
                hwBreak(id);
            }
            voiceFree((Obj_803B312C *)v);
        }
    }
    return -1;
}

#pragma push
#pragma opt_common_subs on
#define synthVoice ((SYNTH_VOICE_803B2438 *)synthVoice)
void macInit(void) {
    u32 i;
    lbl_805D741C = 0;
    lbl_805D7420 = 0;
    macRealTime = 0;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        synthVoice[i].addr = 0;
        synthVoice[i].macState = 2;
        synthVoice[i].loop = 0;
    }
}
#pragma pop

u8 DebugMacroSteps;
V_803B1F24 *lbl_805D741C;
Program_803B1DA4 *lbl_805D7420;
u64 macRealTime;
MSTEP_803B04A0 cstep;

}
