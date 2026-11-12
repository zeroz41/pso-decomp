#include "musyx/runtime/musyx_runtime_a.h"

extern "C" {

static u32 synthTicksPerSecond[9][16];
static SYNTH_JOBTAB_SV synthJobTable[32];
SynthInfo_SV synthInfo;
SYNTHMasterFader_SV synthMasterFader[32];
u8 synthTrackVolume[64];
s32 synthAuxAUser[8];
void *synthAuxACallback[8];
s32 synthAuxBUser[8];
void *synthAuxBCallback[8];
Tbl_803AA1E0 synthITDDefault[8];
s32 synthGlobalVariable[16];
CTRL_DEST_SV inpAuxB[8][4];
CTRL_DEST_SV inpAuxA[8][4];
u8 sndActive;
u8 synthJobTableIndex;
u8 synthAuxBMIDISet[8];
u8 synthAuxBMIDI[8];
u8 synthAuxAMIDISet[8];
u8 synthAuxAMIDI[8];
u32 synthMasterFaderPauseActiveFlags;
u32 synthMasterFaderActiveFlags;
s32 synthFlags;
Rec_803A8D2C *synthVoice;
void (*synthMessageCallback)(u32, s32);
u8 synthIdleWaitActive;
s64 synthRealTime;
#define synthInfo (*(SynthInfo_SV *)&synthInfo)

void synthSetBpm(s32 arg0, u8 arg1, u8 arg2) {
    if (arg1 == 0xFF) {
        arg1 = 8;
    }
    synthTicksPerSecond[arg1][arg2] = (u32)((arg0 << 3) * 0x600) / 240;
}

s32 synthGetTicksPerSecond(Obj_803A6F18 *arg0) {
    u32 r = arg0->b122;
    if (r == 0xFF) {
        r = 8;
    }
    return synthTicksPerSecond[r][arg0->b123];
}

void synthInitPortamento(Obj_803A6F4C *arg0) {
    u64 fl = *(u64 *)&arg0->fh;
    if ((fl & 0x20000) == 0) {
        if (arg0->b131 == 1) {
            if ((fl & 0x1000) == 0) {
                arg0->i13C = 0;
            } else {
                arg0->i13C = arg0->i134;
            }
        } else {
            arg0->i13C = arg0->i134;
        }
        arg0->i138 = arg0->b130 << 16;
    }
}

#pragma push
#pragma opt_common_subs on
u32 do_voice_portamento(u8 key, u8 midi, u8 midiSet, u32 isMaster, u32 *rejected) {
    void inpSetMidiLastNote(u8 midi, u8 midiSet, u8 key);
    u32 vidMakeNew(SYNTH_VOICE_SV *svoice, u32 isMaster);
    u32 i;
    u32 vid;
    u32 id;
    SYNTH_VOICE_SV *sv;
    SYNTH_VOICE_SV *last_sv;
    u32 legatoVoiceIsStarting;

    legatoVoiceIsStarting = 0;
    vid = 0xFFFFFFFF;

    i = 0;
    sv = SV_VOICES;
    while (i < synthInfo.voiceNum) {
        if (sv->block == 0 && sv->id != 0xFFFFFFFF && sv->midi == midi && sv->midiSet == midiSet) {
            if ((sv->cFlags & 2) != 0) {
                legatoVoiceIsStarting = 1;
            }
            if ((sv->cFlags & 0x10) != 0 && (sv->cFlags & 0x10000000008) != 0x8 && hwIsActive(i)) {
                if (vid == 0xFFFFFFFF && (sv->cFlags & 0x20002) == 0x20002) {
                    *rejected = 1;
                    return 0xFFFFFFFF;
                }
                last_sv = sv;
                sv->portCurPitch = (sv->curNote * 65536) + (sv->curDetune * 65536) / 100;
                sv->lastNote = sv->curNote;
                sv->curNote = key + ((sv->curNote & 0xff) - sv->orgNote);
                sv->orgNote = key;
                sv->curDetune = 0;
                sv->portTime = 0;
                sv->cFlags |= 0x20000;
                vidRemoveVoiceReferences((Prog_803B25CC *)&SV_VOICES[i]);
                if (vid == 0xFFFFFFFF) {
                    sv->child = 0xFFFFFFFF;
                    sv->parent = 0xFFFFFFFF;
                    vid = vidMakeNew(&SV_VOICES[i], isMaster);
                    id = sv->id;
                } else {
                    SV_VOICES[id & 0xff].child = sv->id;
                    sv->parent = id;
                    id = sv->id;
                    vidMakeNew(&SV_VOICES[i], 0);
                }
            }
        }
        ++i;
        sv++;
    }

    if (vid != 0xFFFFFFFF) {
        voiceSetLastStarted((Obj_803B3B24 *)last_sv);
        inpSetMidiLastNote(last_sv->midi, last_sv->midiSet, last_sv->curNote);
        *rejected = 0;
    } else {
        *rejected = legatoVoiceIsStarting;
    }
    return vid;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline u32 check_portamento_SV(u8 key, u8 midi, u8 midiSet, u32 newVID, u32 *vid) {
    u32 rejected;

    if (inpGetMidiCtrl(65, midi, midiSet) > 8064) {
        *vid = do_voice_portamento(key & 0x7f, midi, midiSet, newVID, &rejected);
        return (u32)__cntlzw(rejected) >> 5;
    }
    *vid = 0xFFFFFFFF;
    return 1;
}

u32 StartLayer(u16 layerID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                         u8 midiSet, u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd) {
    LAYER_SV *dataGetLayer(u16 layerID, u16 *n);
    u32 macStart(u16 macid, u8 priority, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                          u8 midiSet, u8 section, u16 step, u16 trackid, u8 new_vid, u8 vGroup, u8 studio, u32 itd);
    u32 StartKeymap(u16 keymapID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                             u8 midiSet, u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd);
    u32 vidMakeRoot(SYNTH_VOICE_SV *svoice);
    u16 n;
    u32 vid;
    u32 new_id;
    u32 id;
    LAYER_SV *l;
    s32 p;
    s32 k;
    u8 v;
    u8 mKey;

    vid = 0xFFFFFFFF;
    if ((l = dataGetLayer(layerID, &n)) == NULL) {
        goto end;
    }

    mKey = key & 0x7f;
    for (; n != 0; --n, l++) {
        if (l->id == 0xffff || l->keyLow > mKey || l->keyHigh < mKey) {
            continue;
        }

        k = mKey + l->transpose;
        k = CLAMP_SV(k, 0, 127);

        if ((l->id & 0xC000) == 0) {
            if (check_portamento_SV(k, midi, midiSet, 0, &new_id)) {
                if (new_id != 0xFFFFFFFF) {
                    goto apply_new_id;
                } else {
                    goto start_new_id;
                }
            }
            continue;
        }

    start_new_id:
        if ((l->panning & 0x80) == 0) {
            p = l->panning - 0x40;
            p += panning;
            p = CLAMP_INV_SV(p, 0, 0x7f);
        } else {
            p = 0x80;
        }

        v = (vol * l->volume) / 0x7f;
        prio += l->prioOffset;
        prio = CLAMP_SV(prio, 0, 0xff);

        switch (l->id & 0xC000) {
        case 0:
            new_id = macStart(l->id, prio, maxVoices, allocId, k | (key & 0x80), v, p, midi, midiSet,
                                       section, step, trackid, 0, vGroup, studio, itd);
            break;
        case 0x4000:
            new_id = StartKeymap(l->id, prio, maxVoices, allocId, k | (key & 0x80), v, p, midi, midiSet,
                                          section, step, trackid, 0, vGroup, studio, itd);
            break;
        case 0x8000:
            new_id = StartLayer(l->id, prio, maxVoices, allocId, k | (key & 0x80), v, p, midi, midiSet,
                                          section, step, trackid, 0, vGroup, studio, itd);
            break;
        }

        if (new_id != 0xFFFFFFFF) {
        apply_new_id:
            if (vid == 0xFFFFFFFF) {
                if (vidFlag != 0) {
                    vid = vidMakeRoot(&SV_VOICES[new_id & 0xff]);
                } else {
                    vid = new_id;
                }
            } else {
                SV_VOICES[id & 0xff].child = new_id;
                SV_VOICES[new_id & 0xff].parent = id;
            }
            id = new_id;
            while (SV_VOICES[id & 0xff].child != 0xFFFFFFFF) {
                SV_VOICES[id & 0xff].block = 1;
                id = SV_VOICES[id & 0xff].child;
            }
            SV_VOICES[id & 0xff].block = 1;
        }
    }

end:
    return vid;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
#pragma push
#pragma optimization_level 2
u32 StartKeymap(u16 keymapID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                u8 midiSet, u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd) {
    KEYMAP_SV *dataGetKeymap(u16 keymapID);
    u32 macStart(u16 macid, u8 priority, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                 u8 midiSet, u8 section, u16 step, u16 trackid, u8 new_vid, u8 vGroup, u8 studio, u32 itd);
    s32 k;
    u8 o;
    KEYMAP_SV *keymap;
    s32 p;
    u32 vid;

    if ((keymap = dataGetKeymap(keymapID)) != NULL) {
        o = key & 0x7f;
        if (keymap[o].id != 0xffff && (keymap[o].id & 0xc000) != 0x4000) {
            if ((keymap[o].panning & 0x80) == 0) {
                p = (keymap[key].panning - 0x40);
                p += panning;
                if (p < 0) {
                    panning = 0;
                } else if (p > 0x7f) {
                    panning = 0x7f;
                } else {
                    panning = p;
                }
            } else {
                panning = 0x80;
            }

            k = (key & 0x7f) + keymap[o].transpose;
            k = CLAMP_SV(k, 0, 127);

            prio += keymap[o].prioOffset;
            prio = CLAMP_SV(prio, 0, 0xff);

            if ((keymap[o].id & 0xc000) == 0) {
                if (!check_portamento_SV(k & 0xff, midi, midiSet, vidFlag, &vid)) {
                    return 0xffffffff;
                }
                if (vid != 0xffffffff) {
                    return vid;
                }
                return macStart(keymap[o].id, prio, maxVoices, allocId, k | (key & 0x80), vol, panning, midi,
                                midiSet, section, step, trackid, vidFlag, vGroup, studio, itd);
            }

            return StartLayer(keymap[o].id, prio, maxVoices, allocId, k | (key & 0x80), vol, panning, midi,
                              midiSet, section, step, trackid, vidFlag & 0xff, vGroup, studio, itd);
        }
    }

    return 0xFFFFFFFF;
}

#pragma pop
static inline void unblockAllAllocatedVoices_SV(u32 vid) {
    u32 id;

    id = vidGetInternalId(vid);
    while (id != 0xFFFFFFFF) {
        SV_VOICES[id & 0xff].block = 0;
        id = SV_VOICES[id & 0xff].child;
    }
}

u32 synthStartSound(u16 id, u8 prio, u8 max, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet, u8 section,
                    u16 step, u16 trackid, u8 vGroup, s16 prioOffset, u8 studio, u32 itd) {
    u32 macStart(u16 macid, u8 priority, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                 u8 midiSet, u8 section, u16 step, u16 trackid, u8 new_vid, u8 vGroup, u8 studio, u32 itd);
    u32 StartKeymap(u16 keymapID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                    u8 midiSet, u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd);
    u16 allocId = id;

    prio += prioOffset;
    prio = CLAMP_SV(prio, 0, 0xff);

    switch (id & 0xC000) {
    case 0: {
        u32 vid;
        if (!check_portamento_SV(key, midi, midiSet, 1, &vid)) {
            return 0xFFFFFFFF;
        }
        if (vid != 0xFFFFFFFF) {
            return vid;
        }
        return macStart(id, prio, max, allocId, key, vol, panning, midi, midiSet, section, step, trackid, 1,
                        vGroup, studio, itd);
    }
    case 0x4000: {
        u32 vid = StartKeymap(id, prio, max, allocId, key, vol, panning, midi, midiSet, section, step, trackid,
                              1, vGroup, studio, itd);
        if (vid != 0xFFFFFFFF) {
            unblockAllAllocatedVoices_SV(vid);
        }
        return vid;
    }
    case 0x8000: {
        u32 vid = StartLayer(id, prio, max, allocId, key, vol, panning, midi, midiSet, section, step, trackid,
                             1, vGroup, studio, itd);
        if (vid != 0xFFFFFFFF) {
            unblockAllAllocatedVoices_SV(vid);
        }
        return vid;
    }
    default:
        return 0xFFFFFFFF;
    }
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline u32 apply_portamento_SV(SYNTH_VOICE_SV *svoice, u32 ccents, u32 deltaTime) {
    u32 old_portCurPitch;

    if ((svoice->cFlags & 0x400) != 0 && (int)((svoice->portDuration - svoice->portTime) >> 8) > 0) {
        old_portCurPitch = svoice->portCurPitch;
        svoice->portCurPitch += (int)deltaTime * ((int)(ccents - svoice->portCurPitch) >> 8) /
                                (int)((svoice->portDuration - svoice->portTime) >> 8);

        if ((old_portCurPitch < ccents && svoice->portCurPitch < ccents) ||
            (old_portCurPitch > ccents && (svoice->portCurPitch > ccents))) {
            ccents = svoice->portCurPitch;
            svoice->portTime += deltaTime;
        } else {
            svoice->portTime = svoice->portDuration;
        }
    }
    return ccents;
}

static inline void synthInitPortamento_SV(SYNTH_VOICE_SV *svoice) {
    if (svoice->cFlags & 0x20000) {
        return;
    }

    if (svoice->portType == 1) {
        if (!(svoice->cFlags & 0x1000)) {
            svoice->portTime = 0;
        } else {
            svoice->portTime = svoice->portDuration;
        }
    } else {
        svoice->portTime = svoice->portDuration;
    }

    svoice->portCurPitch = svoice->lastNote << 16;
}

static inline u32 convert_cents_SV(SYNTH_VOICE_SV *svoice, u32 ccents) {
    u32 curDetune;
    u32 cpitch;

    cpitch = sndGetPitch(ccents / 65536, svoice->sInfo) * 65536;
    if ((curDetune = ccents & 0xffff) != 0) {
        cpitch += curDetune * ((sndPitchUpOne(cpitch / 65536) & 0xffff) - (cpitch / 65536));
    }
    return cpitch;
}

static inline void UpdateTimeMIDICtrl_SV(SYNTH_VOICE_SV *sv) {
    if (!sv->timeUsedByInput) {
        return;
    }

    sv->timeUsedByInput = 0;
    sv->midiDirtyFlags = 0x1fff;
}

void LowPrecisionHandler(u32 i) {
    u32 j;
    s32 pbend;
    u32 ccents;
    u32 cpitch;
    u16 Modulation;
    u16 portamento;
    u32 lowDeltaTime;
    SYNTH_VOICE_SV *sv;
    u32 cntDelta;
    u32 addFactor;
    u16 adsr_start;
    u16 adsr_delta;
    s32 vrange;
    s32 voff;

    sv = &SV_VOICES[i];
    if (!hwIsActive(i) && sv->addr == NULL) {
        goto end;
    }

    lowDeltaTime = synthRealTime - sv->lastLowCallTime;
    sv->lastLowCallTime = synthRealTime;
    for (j = 0; j < 2; ++j) {
        if (sv->lfo[j].period == 0) {
            continue;
        }
        sv->lfo[j].time += lowDeltaTime;
        sv->lfo[j].value =
            sndSin((sv->lfo[j].time % sv->lfo[j].period * 16) / (sv->lfo[j].period / 256));
        if (sv->lfo[j].value != sv->lfo[j].lastValue) {
            sv->lfo[j].lastValue = sv->lfo[j].value;
            if (sv->lfoUsedByInput[j]) {
                sv->lfoUsedByInput[j] = 0;
                sv->midiDirtyFlags |= 0x1fff;
            }
        }
    }

    if ((sv->cFlags & 0x2000) != 0) {
        sv->vibCurTime += lowDeltaTime;
        sv->vibCurOffset = sndSin((sv->vibCurTime % sv->vibPeriod * 16) / (sv->vibPeriod / 256));
    }

    if (sv->sweepNum[0] | sv->sweepNum[1]) {
        cntDelta = (lowDeltaTime << 8) >> 4;
        addFactor = (lowDeltaTime << 4) >> 4;
        for (j = 0; j < 2; ++j) {
            if (sv->sweepNum[j] == 0) {
                continue;
            }
            sv->sweepCnt[j] -= cntDelta;
            if (sv->sweepCnt[j] <= 0) {
                sv->sweepCnt[j] = sv->sweepNum[j] << 16;
                sv->sweepOff[j] = 0;
            } else {
                sv->sweepOff[j] += (sv->sweepAdd[j] >> 12) * addFactor;
            }
        }
    }

    for (j = 0; j < 2; ++j) {
        if (sv->panning[j] == sv->panTarget[j]) {
            continue;
        }
        sv->panTime[j] -= lowDeltaTime;
        if ((s32)sv->panTime[j] <= 0) {
            sv->panning[j] = sv->panTarget[j];
            sv->panTime[j] = 0;
        } else {
            sv->panning[j] = sv->panTarget[j] - (sv->panTime[j] / 256) * sv->panDelta[j];
            sv->panning[j] = CLAMP_INV_SV((s32)sv->panning[j], 0, 0x7f0000u);
        }

        sv->cFlags |= 0x200000000000;
    }

    if ((sv->cFlags & 0x20000000000) != 0 &&
        adsrHandleLowPrecision(&sv->pitchADSR, &adsr_start, &adsr_delta)) {
        sv->cFlags &= ~0x20000000000;
    }

    ccents = sv->curNote * 65536 + (sv->curDetune * 65536) / 100;
    if ((sv->cFlags & 0x10030) != 0) {
        if (sv->midi != 0xff) {
            pbend = inpGetPitchBend(sv);
            sv->pbLast = pbend;
            goto pbend_adjust;
        }
    } else {
        pbend = sv->pbLast;
    pbend_adjust:
        if (pbend != 0x2000) {
            pbend -= 0x2000;
            if (pbend < 0) {
                ccents += sv->pbLowerKeyRange * pbend * 8;
            } else {
                ccents += sv->pbUpperKeyRange * pbend * 8;
            }
        }
    }

    if ((sv->cFlags & 0x2000) != 0) {
        Modulation = inpGetModulation(sv);
        vrange = sv->vibKeyRange * 256 + (sv->vibCentRange * 256) / 100;
        if (sv->vibModAddScale != 0) {
            vrange += (sv->vibModAddScale * ((Modulation >> 7) & 0x1ff)) >> 7;
        }
        if ((sv->cFlags & 0x4000) != 0) {
            voff = (sv->vibCurOffset * ((Modulation >> 7) & 0x1ff)) >> 7;
        } else {
            voff = sv->vibCurOffset;
        }
        ccents += (vrange * voff) >> 4;
    }

    if (sv->midi != 0xff) {
        portamento = inpGetMidiCtrl(65, sv->midi, sv->midiSet);
        if (portamento != sv->portLastCtrlState || (sv->cFlags & 0x21000) == 0x20000) {
            if (portamento <= 0x1f80) {
                sv->cFlags &= ~0x400;
            } else {
                if ((sv->cFlags & 0x400) == 0) {
                    synthInitPortamento_SV(sv);
                }
                sv->cFlags |= 0x400;
            }
            sv->cFlags |= 0x1000;
            sv->portLastCtrlState = portamento;
        }
    }

    ccents = apply_portamento_SV(sv, ccents, lowDeltaTime);
    if ((sv->cFlags & 0x20000000000) != 0) {
        ccents += sv->pitchADSRRange * (sv->pitchADSR.currentVolume >> 16) >> 7;
    }

    cpitch = convert_cents_SV(sv, ccents);
    cpitch += sv->sweepOff[0] + sv->sweepOff[1];
    cpitch = ((cpitch >> 16) * inpGetDoppler(sv)) >> 13;
    sv->curPitch = cpitch;

    hwSetPitch(i, cpitch);
    synthAddJob(sv, 0, 0xf00);

end:
    UpdateTimeMIDICtrl_SV(sv);
}
#pragma pop

u16 inpGetTremolo(SYNTH_VOICE_SV *svoice);
u16 inpGetPanning(SYNTH_VOICE_SV *svoice);
u16 inpGetSurPanning(SYNTH_VOICE_SV *svoice);
u16 inpGetVolume(SYNTH_VOICE_SV *svoice);
u16 inpGetReverb(SYNTH_VOICE_SV *svoice);
u16 inpGetPreAuxA(SYNTH_VOICE_SV *svoice);
u16 inpGetPostAuxB(SYNTH_VOICE_SV *svoice);
u16 inpGetPreAuxB(SYNTH_VOICE_SV *svoice);
void hwSetPriority(u32 v, u32 prio);
u8 hwGetTimeOffset(void);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
#pragma bool off

void ZeroOffsetHandler(u32 i) {
    SYNTH_VOICE_SV *sv;
    u32 lowDeltaTime;
    u16 Modulation;
    f32 vol;
    f32 auxa;
    f32 auxb;
    f32 f;
    f32 voiceVol;
    u32 volUpdate;
    f32 lfo;
    f32 scale;
    f32 mscale;
    s32 pan;
    f32 preVol;
    f32 postVol;

    sv = &SV_VOICES[i];
    if (!hwIsActive(i) && sv->addr == NULL) {
        goto end;
    }

    lowDeltaTime = synthRealTime - sv->lastZeroCallTime;
    sv->lastZeroCallTime = synthRealTime;

    if ((sv->cFlags & 0x8000) != 0) {
        sv->envCurrent += sv->envDelta * (lowDeltaTime >> 8);
        if (sv->envDelta < 0) {
            if ((s32)sv->envTarget >= (s32)sv->envCurrent) {
                sv->envCurrent = sv->envTarget;
                sv->cFlags &= ~0x8000;
            }
        } else if ((s32)sv->envTarget <= (s32)sv->envCurrent) {
            sv->envCurrent = sv->envTarget;
            sv->cFlags &= ~0x8000;
        }
        sv->volume = sv->envCurrent;
        volUpdate = 1;
    } else {
        volUpdate = (sv->cFlags & 0x100000000000) != 0;
    }

    sv->cFlags &= ~0x100000000000;

    f = synthMasterFader[sv->vGroup].pauseVol * synthMasterFader[sv->vGroup].volume *
        synthMasterFader[sv->fxFlag ? 22 : 21].volume;

    if (sv->track != 0xff) {
        vol = f * (f32)synthTrackVolume[sv->track] * (1.f / 127.f);
    } else {
        vol = f;
    }

    if (vol != sv->lastVolFaderScale) {
        sv->lastVolFaderScale = vol;
        volUpdate = 1;
    }

    voiceVol = (f32)sv->volume * (1.f / (8192.f * 1016.f));

    if ((sv->treScale | sv->treModAddScale) != 0) {
        Modulation = inpGetModulation(sv);
        lfo = (f32)(8192 - ((8192 - ((s16)inpGetTremolo(sv) - 8192)) >> 1)) * (1.f / 8192.f);
        mscale = 1.f - (f32)Modulation * (4096 - sv->treModAddScale) * 1.490207e-08f;
        scale = (f32)sv->treScale * mscale * (1.f / 4096.f);
        if (sv->treCurScale < scale) {
            if ((sv->treCurScale += 0.2f) > scale) {
                sv->treCurScale = scale;
            }
        } else if (sv->treCurScale > scale) {
            if ((sv->treCurScale -= 0.2f) < scale) {
                sv->treCurScale = scale;
            }
        }
        voiceVol *= 1.f - lfo * (1.f - sv->treCurScale);
        volUpdate = 1;
    }

    if ((synthFlags & 1) == 0) {
        if ((sv->cFlags & 0x200000000000) != 0 || (sv->midiDirtyFlags & 0x6) != 0) {
            sv->cFlags &= ~0x200000000000;
            pan = sv->panning[0] + (inpGetPanning(sv) - 8192) * 0x200;
            sv->lastPan = CLAMP_INV_SV(pan, 0, 0x7f0000);

            if ((synthFlags & 2) != 0) {
                if ((sv->lastSPan = sv->panning[1] + inpGetSurPanning(sv) * 512) > 0x7f0000) {
                    sv->lastSPan = 0x7f0000;
                }
            } else {
                sv->lastSPan = 0;
            }

            volUpdate = 1;
        } else if ((synthFlags & 2) == 0) {
            sv->lastSPan = 0;
        }
    } else {
        sv->lastPan = 0x400000;
        sv->lastSPan = 0;
        volUpdate |= (sv->cFlags & 0x200000000000) != 0;
        sv->cFlags &= ~0x200000000000;
    }

    if (volUpdate || (sv->midiDirtyFlags & 0xf01) != 0) {
        preVol = voiceVol;
        postVol = voiceVol * vol * (f32)inpGetVolume(sv) * (1.f / 16383.f);
        auxa = ((f32)sv->revVolOffset * (1.f / 127.f)) +
               ((preVol * (f32)inpGetPreAuxA(sv) * (1.f / 16383.f)) +
                ((f32)sv->revVolScale * (postVol * (f32)inpGetReverb(sv) * (1.f / 16383.f)) * (1.f / 127.f)));
        auxb = (preVol * (f32)inpGetPreAuxB(sv) * (1.f / 16383.f)) +
               (postVol * (f32)inpGetPostAuxB(sv) * (1.f / 16383.f));
        sv->curOutputVolume = (u16)(postVol * 32767.f);
        hwSetVolume(i, sv->volTable, sv->lastPan, sv->lastSPan, postVol, auxa, auxb);
    }
    if (sv->age != 0) {
        if ((s32)(sv->age -= sv->ageSpeed * lowDeltaTime) < 0) {
            sv->age = 0;
        }
        hwSetPriority(i, sv->prio << 24 | sv->age >> 15);
    }

    synthAddJob(sv, 1, (5 - hwGetTimeOffset()) * 256);

end:
    UpdateTimeMIDICtrl_SV(sv);
}
#pragma pop

void EventHandler(s32 arg0) {
    Ch_803A897C *o = (Ch_803A897C *)&synthVoice[arg0];

    if (hwIsActive(arg0) != 0 || o->f34 != 0) {
        macSetPedalState((Voice_803B1C98 *)o, (u32)(0x1F80 - inpGetPedal(o)) >> 31);
        if ((o->flags & 0x20) != 0) {
            o->flags &= ~0x20ULL;
            o->flags |= 0x10;
            hwStart(arg0, o->f11F);
        }
        if ((o->flags & 0x10000000090ULL) == 0x90) {
            o->flags &= ~0x90ULL;
            hwKeyOff(arg0);
            if ((o->flags & 0x20000000000ULL) != 0 && (u32)adsrRelease((struct Envelope_803B431C *)o->env) != 0) {
                o->flags &= ~0x20000000000ULL;
            }
        }
    }
    if (o->fA8 != 0) {
        o->fA8 = 0;
        o->f214 = 0x1FFF;
    }
}
#pragma push
#pragma opt_common_subs on
void synthAddJob(SYNTH_VOICE_SV *svoice, s32 jobType, u32 deltaTime) {
    SYNTH_QUEUE_SV *newJq;
    SYNTH_QUEUE_SV **root;
    u8 jobTabIndex;
    SYNTH_JOBTAB_SV *jobTab;

    jobTabIndex = ((deltaTime / 256) + synthJobTableIndex) & 0x1f;
    jobTab = &synthJobTable[jobTabIndex];

    switch (jobType) {
    case 0:
        newJq = &svoice->lowPrecisionJob;
        if (newJq->jobTabIndex != 0xff) {
            if (newJq->jobTabIndex == jobTabIndex) {
                return;
            }
            if (newJq->next != NULL) {
                newJq->next->prev = newJq->prev;
            }
            if (newJq->prev != NULL) {
                newJq->prev->next = newJq->next;
            } else {
                synthJobTable[newJq->jobTabIndex].lowPrecision = newJq->next;
            }
        }
        root = &jobTab->lowPrecision;
        break;
    case 1:
        newJq = &svoice->zeroOffsetJob;
        if (newJq->jobTabIndex != 0xff) {
            if (newJq->jobTabIndex == jobTabIndex) {
                return;
            }
            if (newJq->next != NULL) {
                newJq->next->prev = newJq->prev;
            }
            if (newJq->prev != NULL) {
                newJq->prev->next = newJq->next;
            } else {
                synthJobTable[newJq->jobTabIndex].zeroOffset = newJq->next;
            }
        }
        root = &jobTab->zeroOffset;
        break;
    case 2:
        newJq = &svoice->eventJob;
        if (newJq->jobTabIndex != 0xff) {
            return;
        }
        root = &jobTab->event;
        break;
    default:
        break;
    }

    newJq->jobTabIndex = jobTabIndex;
    if ((newJq->next = *root) != NULL) {
        (*root)->prev = newJq;
    }
    newJq->prev = NULL;
    *root = newJq;
}
#pragma pop

void synthStartSynthJobHandling(Obj_803A8C5C* voice) {
    voice->p24 = synthRealTime;
    voice->p2C = synthRealTime;
    synthAddJob((SYNTH_VOICE_SV *)voice, 0, 0);
    synthAddJob((SYNTH_VOICE_SV *)voice, 1, 0);
}

void synthForceLowPrecisionUpdate(void *arg0) {
    synthAddJob((SYNTH_VOICE_SV *)arg0, 0, 0);
    synthAddJob((SYNTH_VOICE_SV *)arg0, 1, 0);
}

void synthKeyStateUpdate(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    synthAddJob((SYNTH_VOICE_SV *) (arg0), (int) (2), (int) (0));
}

void HandleJobQueue(Node_803A8D2C **list, void (*cb)(u8)) {
    Node_803A8D2C *n;
    Node_803A8D2C *next;
    for (n = *list; n != NULL; n = next) {
        next = n->next;
        n->f9 = 0xFF;
        if (synthVoice[n->idx].busy == 0) {
            cb(n->idx);
        }
    }
    *list = NULL;
}

void HandleFaderTermination(u8 *arg0) {
    struct Fields_arg0 { u8 pad_0[40]; s32 field_28; u8 field_2C; };
    u8 temp_r0;
    temp_r0 = ((Fields_arg0*)arg0)->field_2C;
    switch ((s32) temp_r0) {
    case 1:
        seqStop(((Fields_arg0*)arg0)->field_28);
        return;
    case 2:
        seqPause((s32)(((Fields_arg0*)arg0)->field_28));
        return;
    case 3:
        seqMute(((Fields_arg0*)arg0)->field_28, 0, 0);
        return;
    }
}

typedef struct SND_AUX_INFO_SV { union { struct { s32 *left; s32 *right; s32 *surround; } bufferUpdate; struct { u16 para[4]; } parameterUpdate; } data; } SND_AUX_INFO_SV;
u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet);
u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet);
void hwFrameDone(void);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
#pragma bool off

static inline void HandleVoices_SV(void) {
    SYNTH_JOBTAB_SV *jTab = &synthJobTable[synthJobTableIndex];
    HandleJobQueue((Node_803A8D2C **)&jTab->lowPrecision, (void (*)(u8))LowPrecisionHandler);
    HandleJobQueue((Node_803A8D2C **)&jTab->event, (void (*)(u8))EventHandler);
    HandleJobQueue((Node_803A8D2C **)&jTab->zeroOffset, (void (*)(u8))ZeroOffsetHandler);
    synthJobTableIndex = (synthJobTableIndex + 1) & 0x1f;
}

static inline void HandleFaderTermination_SV(SYNTHMasterFader_SV *smf) {
    switch (smf->seqMode) {
    case 1:
        seqStop(smf->seqId);
        break;
    case 2:
        seqPause(smf->seqId);
        break;
    case 3:
        seqMute(smf->seqId, 0, 0);
        break;
    }
}

void synthHandle(u32 deltaTime) {
    u32 i;
    u32 s;
    SYNTHMasterFader_SV *smf;
    u32 testFlag;

    if (synthInfo.numSamples == 0) {
        return;
    }

    macHandle(deltaTime);
    HandleVoices_SV();

    if (hwGetTimeOffset() == 0) {
        if ((synthMasterFaderActiveFlags | synthMasterFaderPauseActiveFlags) != 0) {
            for (i = 0, smf = synthMasterFader, testFlag = 1; i < 32; testFlag <<= 1, ++i, ++smf) {
                if ((synthMasterFaderActiveFlags & testFlag) != 0) {
                    smf->volume = smf->target - smf->time * (smf->target - smf->start);
                    if ((smf->time -= smf->deltaTime) <= 0.f) {
                        smf->volume = smf->target;
                        HandleFaderTermination_SV(smf);
                        if ((synthMasterFaderActiveFlags &= ~testFlag) == 0 && synthMasterFaderPauseActiveFlags == 0) {
                            break;
                        }
                    }
                }

                if ((synthMasterFaderPauseActiveFlags & testFlag) != 0) {
                    smf->pauseVol = smf->pauseTarget - smf->pauseTime * (smf->pauseTarget - smf->pauseStart);
                    if ((smf->pauseTime -= smf->pauseDeltaTime) <= 0.f) {
                        smf->pauseVol = smf->pauseTarget;
                        if ((synthMasterFaderPauseActiveFlags &= ~testFlag) == 0 && synthMasterFaderActiveFlags == 0) {
                            break;
                        }
                    }
                }
            }
        }

        for (s = 0; s < 8; ++s) {
            if (synthAuxAMIDI[s] != 0xff) {
                SND_AUX_INFO_SV info;
                for (i = 0; i < 4; ++i) {
                    info.data.parameterUpdate.para[i] = inpGetAuxA(s, i, synthAuxAMIDI[s], synthAuxAMIDISet[s]);
                }
                ((SND_AUX_CALLBACK_SV)synthAuxACallback[s])(1, &info, (void *)synthAuxAUser[s]);
            }

            if (synthAuxBMIDI[s] != 0xff) {
                SND_AUX_INFO_SV info;
                for (i = 0; i < 4; ++i) {
                    info.data.parameterUpdate.para[i] = inpGetAuxB(s, i, synthAuxBMIDI[s], synthAuxBMIDISet[s]);
                }
                ((SND_AUX_CALLBACK_SV)synthAuxBCallback[s])(1, &info, (void *)synthAuxBUser[s]);
            }
        }
    }

    hwFrameDone();
    synthRealTime += deltaTime;
}
#pragma pop

s32 synthFXStart(s16 arg0, u8 arg1, u8 arg2, s32 arg3, s32 arg4) {
    s32 synthStartSound(s32, s32, s32, s32, u8, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    s32 ret = -1;
    Se_803A9144 *p = dataGetFX(arg0);
    if (p != NULL) {
        if (arg1 == 0xFF) {
            arg1 = p->b6;
        }
        if (arg2 == 0xFF) {
            arg2 = p->b7;
        }
        ret = synthStartSound(p->id, p->b5, p->b4, p->b8 | 0x80, arg1, arg2, 0xFF, 0xFF,
                                   0, 0, 0xFF, p->b9, 0, arg3, arg4);
    }
    return ret;
}

#pragma push
#pragma opt_common_subs on
s32 synthFXSetCtrl(u32 vid, u8 ctrl, u8 value) {
    void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
    u32 i;
    u32 ret;

    ret = 0;
    vid = vidGetInternalId(vid);

    while (vid != 0xFFFFFFFF) {
        i = vid & 0xff;
        if (vid == SV_VOICES[i].id) {
            if ((SV_VOICES[i].cFlags & 0x2) != 0) {
                inpSetMidiCtrl(ctrl, i, SV_VOICES[i].setup.midiSet, value);
            } else {
                inpSetMidiCtrl(ctrl, i, SV_VOICES[i].midiSet, value);
            }

            vid = SV_VOICES[i].child;
            ret = 1;
        } else {
            return ret;
        }
    }

    return ret;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 synthFXSetCtrl14(u32 vid, u8 ctrl, u16 value) {
    void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
    u32 i;
    u32 ret;

    ret = 0;
    vid = vidGetInternalId(vid);

    while (vid != 0xFFFFFFFF) {
        i = vid & 0xff;
        if (vid == SV_VOICES[i].id) {
            if ((SV_VOICES[i].cFlags & 0x2) != 0) {
                inpSetMidiCtrl14(ctrl, i, SV_VOICES[i].setup.midiSet, value);
            } else {
                inpSetMidiCtrl14(ctrl, i, SV_VOICES[i].midiSet, value);
            }

            vid = SV_VOICES[i].child;
            ret = 1;
        } else {
            return ret;
        }
    }

    return ret;
}
#pragma pop

void synthFXCloneMidiSetup(u8 *arg0, u8 *arg1) {
    inpFXCopyCtrl(7U, arg0, arg1);
    inpFXCopyCtrl(0xAU, arg0, arg1);
    inpFXCopyCtrl(0x5BU, arg0, arg1);
    inpFXCopyCtrl(0x80U, arg0, arg1);
    inpFXCopyCtrl(0x84U, arg0, arg1);
}

s32 synthSendKeyOff(int id) {
    u8 idx;
    s32 found = 0;
    u32 cur;
    if (sndActive != 0) {
        cur = vidGetInternalId((u32)(id));
        while (cur != 0xFFFFFFFF) {
            idx = cur;
            if (cur == (*(Rec_803A9454 * *)&synthVoice)[idx].id) {
                macSetExternalKeyoff(&(*(Rec_803A9454 * *)&synthVoice)[idx]);
                found = 1;
            }
            cur = (*(Rec_803A9454 * *)&synthVoice)[idx].next;
        }
    }
    return found;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void SetupFader_803A94E0(SYNTHMasterFader_SV *smf, u8 volume, u32 time, u8 seqMode, u32 seqId) {
    smf->seqMode = seqMode;
    smf->seqId = seqId;
    if (time != 0) {
        smf->start = smf->volume;
        smf->target = (f32)volume * (1.f / 127.f);
        smf->time = 1.f;
        smf->deltaTime = 1280.f / (f32)time;
    } else {
        smf->volume = smf->target = (f32)volume * (1.f / 127.f);
        if (smf->seqId != 0xFFFFFFFF) {
            HandleFaderTermination((u8 *)smf);
        }
    }
}

void synthVolume(u8 volume, u16 time, u8 vGroup, s8 seqMode, s32 seqId) {
    u32 ltime;
    u32 i;
    u8 type;
    SYNTHMasterFader_SV *smf;

    if ((ltime = time) != 0) {
        sndConvertMs(&ltime);
    }

    switch (vGroup) {
    case 0xFF:
        for (smf = synthMasterFader, i = 0; i < 32; ++i, ++smf) {
            if (smf->type == 0 || smf->type == 1) {
                SetupFader_803A94E0(smf, volume, ltime, seqMode, 0xFFFFFFFF);
                synthMasterFaderActiveFlags |= 1 << i;
            }
        }
        return;

    case 0xFC:
        for (smf = synthMasterFader, i = 0; i < 32; ++i, ++smf) {
            if (smf->type == 2 || smf->type == 3) {
                SetupFader_803A94E0(smf, volume, ltime, seqMode, 0xFFFFFFFF);
                synthMasterFaderActiveFlags |= 1 << i;
            }
        }
        return;

    case 0xFA:
        type = 2;
        goto setup_type;

    case 0xFB:
        type = 3;
        goto setup_type;

    case 0xFD:
        type = 0;
        goto setup_type;

    case 0xFE:
        type = 1;
        goto setup_type;

    setup_type:
        for (smf = synthMasterFader, i = 0; i < 32; ++i, ++smf) {
            if (smf->type == type) {
                SetupFader_803A94E0(smf, volume, ltime, seqMode, 0xFFFFFFFF);
                synthMasterFaderActiveFlags |= 1 << i;
            }
        }
        return;

    default:
        SetupFader_803A94E0(&synthMasterFader[vGroup], volume, ltime, seqMode, seqId);
        synthMasterFaderActiveFlags |= 1 << vGroup;
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 synthIsFadeOutActive(u8 arg0) {
    if (synthMasterFader[arg0].type != 4 && (synthMasterFaderActiveFlags & (1 << arg0)) &&
        synthMasterFader[arg0].start > synthMasterFader[arg0].target) {
        return 1;
    }
    return 0;
}
#pragma pop

void synthSetMusicVolumeType(u8 i, u8 v) {
    if (sndActive != 0) {
        synthMasterFader[i].type = v;
    }
}

s32 synthHWMessageHandler(s32 op, u32 idx) {
    void voiceKill(u8);
    s32 ret = 0;
    switch (op) {
    case 0:
        if ((*(Rec_803A996C * *)&synthVoice)[(u8)idx].busy == 0) {
            vsSampleEndNotify(hwGetVirtualSampleID(idx));
            if (idx == (*(Rec_803A996C * *)&synthVoice)[(u8)idx].id) {
                macSampleEndNotify(&(*(Rec_803A996C * *)&synthVoice)[(u8)idx]);
            }
        }
        break;
    case 1:
        voiceKill(idx);
        break;
    case 2:
        ret = vsSampleStartNotify(idx);
        break;
    case 3:
        vsSampleEndNotify(hwGetVirtualSampleID(idx));
        break;
    }
    return ret;
}

void inpInit(u8 *arg0);
void synthInitAllocationAids(void);
void hwSetMesgCallback(s32 arg0);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void synthSetBpm_SV(u32 bpm, u8 set, u8 section) {
    if (set == 0xFF) {
        set = 8;
    }
    synthTicksPerSecond[set][section] = ((bpm << 3) * 1536) / 240;
}

static inline void synthInitJobQueue_SV(void) {
    u8 i;

    for (i = 0; i < 32; ++i) {
        synthJobTable[i].lowPrecision = NULL;
        synthJobTable[i].event = NULL;
        synthJobTable[i].zeroOffset = NULL;
    }

    synthJobTableIndex = 0;
}

void synthInit(u32 mixFrq, u32 numVoices) {
    u32 i;

    synthRealTime = 0;
    synthInfo.mixFrq = mixFrq;
    synthSetBpm_SV(120, 255, 0);
    synthFlags = 0;
    synthMessageCallback = NULL;

    SV_VOICES_L = (SYNTH_VOICE_SV *)salMalloc(numVoices * sizeof(SYNTH_VOICE_SV));
    memset(synthVoice, 0, numVoices * sizeof(SYNTH_VOICE_SV));

    for (i = 0; i < numVoices; ++i) {
        SV_VOICES[i].id = 0xffffffff;
        SV_VOICES[i].cFlags = 0;
        SV_VOICES[i].age = 0;
        SV_VOICES[i].prio = 0;
        SV_VOICES[i].midi = 0xff;
        SV_VOICES[i].volume = 0;
        SV_VOICES[i].volTable = 0;
        SV_VOICES[i].revVolScale = 128;
        SV_VOICES[i].revVolOffset = 0;
        SV_VOICES[i].panning[0] = SV_VOICES[i].panTarget[0] = 0x400000;
        SV_VOICES[i].panning[1] = SV_VOICES[i].panTarget[1] = 0;
        SV_VOICES[i].sweepOff[0] = 0;
        SV_VOICES[i].sweepOff[1] = 0;
        SV_VOICES[i].sweepNum[0] = 0;
        SV_VOICES[i].sweepNum[1] = 0;
        SV_VOICES[i].block = 0;
        SV_VOICES[i].vGroup = 23;
        SV_VOICES[i].keyGroup = 0;
        SV_VOICES[i].itdMode = 1;
        SV_VOICES[i].lfo[0].period = 0;
        SV_VOICES[i].lfo[0].value = 0;
        SV_VOICES[i].lfo[0].lastValue = 0x7fff;
        SV_VOICES[i].lfo[1].period = 0;
        SV_VOICES[i].lfo[1].value = 0;
        SV_VOICES[i].lfo[1].lastValue = 0x7fff;
        SV_VOICES[i].portTime = 25600;
        SV_VOICES[i].portType = 0;
        SV_VOICES[i].studio = 0;
        SV_VOICES[i].lowPrecisionJob.voice = i;
        SV_VOICES[i].lowPrecisionJob.jobTabIndex = 0xff;
        SV_VOICES[i].zeroOffsetJob.voice = i;
        SV_VOICES[i].zeroOffsetJob.jobTabIndex = 0xff;
        SV_VOICES[i].eventJob.voice = i;
        SV_VOICES[i].eventJob.jobTabIndex = 0xff;
    }

    for (i = 0; i < 32; ++i) {
        synthMasterFader[i].volume = 0.f;
        synthMasterFader[i].pauseVol = 1.f;
        synthMasterFader[i].type = 4;
    }

    synthMasterFaderActiveFlags = 0;
    synthMasterFaderPauseActiveFlags = 0;
    synthMasterFader[31].type = 1;

    for (i = 0; i < 8; ++i) {
        synthMasterFader[i + 23].type = 0;
    }

    synthMasterFader[21].volume = 1.f;
    synthMasterFader[22].volume = 1.f;
    inpInit(0);

    for (i = 0; i < 8; ++i) {
        synthAuxACallback[i] = NULL;
        synthAuxAMIDI[i] = 0xff;
        synthAuxBCallback[i] = NULL;
        synthAuxBMIDI[i] = 0xff;
        synthITDDefault[i].b1 = 0;
        synthITDDefault[i].b0 = 0;
    }

    macInit();
    vidInit();
    synthInitAllocationAids();

    for (i = 0; i < 16; ++i) {
        synthGlobalVariable[i] = 0;
    }

    voiceInitLastStarted();
    synthInitJobQueue_SV();
    hwSetMesgCallback((s32)synthHWMessageHandler);
}
#pragma pop

}
