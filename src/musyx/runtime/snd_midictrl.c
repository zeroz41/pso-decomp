#include <string.h>
#include "musyx/runtime/musyx_internal.h"
#pragma dont_inline on

extern "C" {

const u8 lbl_8047C310[134] = {
    0, 0, 0, 0, 0, 0, 0, 127, 0, 0, 64, 127, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    64, 0, 0, 0, 64, 0,
};

const u8 lbl_8047C398[134] = {
    255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    0, 0, 0, 0, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    64, 255, 255, 255, 255, 255,
};

static u8 midi_lastNote[8][16];
static u8 fx_lastNote[64];
static u8 midi_ctrl[8][16][134];
static u8 fx_ctrl[64][134];
static u32 inpGlobalMIDIDirtyFlags[8][16];
static SynthChannelDefaults inpChannelDefaults[8][16];
static SynthChannelDefaults inpFXChannelDefaults[64];

void inpSetGlobalMIDIDirtyFlag(u8 chan, u8 midiSet, u32 flag) {
    inpGlobalMIDIDirtyFlags[midiSet][chan] |= flag;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline void inpSetRPNHi(u8 set, u8 channel, u8 value) {
    u16 rpn;
    u32 i;
    u8 range;

    rpn = (midi_ctrl[set][channel][100]) | (midi_ctrl[set][channel][101] << 8);
    switch (rpn) {
    case 0:
        range = value > 24 ? 24 : value;
        inpChannelDefaults[set][channel].pbRange = range;

        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].pbUpperKeyRange = range;
                synthVoice[i].pbLowerKeyRange = range;
            }
        }
        break;
    default:
        break;
    }
}

static inline void inpSetRPNLo(u8 set, u8 channel, u8 value) {
}

static inline void inpSetRPNDec(u8 set, u8 channel) {
    u16 rpn;
    u32 i;
    u8 range;

    rpn = (midi_ctrl[set][channel][100]) | (midi_ctrl[set][channel][101] << 8);
    switch (rpn) {
    case 0:
        range = inpChannelDefaults[set][channel].pbRange;
        if (range != 0) {
            --range;
        }
        inpChannelDefaults[set][channel].pbRange = range;
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].pbUpperKeyRange = range;
                synthVoice[i].pbLowerKeyRange = range;
            }
        }
        break;
    default:
        break;
    }
}

static inline void inpSetRPNInc(u8 set, u8 channel) {
    u16 rpn;
    u32 i;
    u8 range;

    rpn = (midi_ctrl[set][channel][100]) | (midi_ctrl[set][channel][101] << 8);
    switch (rpn) {
    case 0:
        range = inpChannelDefaults[set][channel].pbRange;
        if (range < 24) {
            ++range;
        }

        inpChannelDefaults[set][channel].pbRange = range;
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].pbUpperKeyRange = range;
                synthVoice[i].pbLowerKeyRange = range;
            }
        }
        break;
    default:
        break;
    }
}

void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value) {
    u32 i;
    if (channel == 0xFF) {
        return;
    }

    if (set != 0xFF) {
        switch (ctrl) {
        case 6:
            inpSetRPNHi(set, channel, value);
            break;
        case 38:
            inpSetRPNLo(set, channel, value);
            break;
        case 96:
            inpSetRPNDec(set, channel);
            break;
        case 97:
            inpSetRPNInc(set, channel);
            break;
        }

        midi_ctrl[set][channel][ctrl] = (value & 0x7f);
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].midiDirtyFlags = 0x1fff;
                synthKeyStateUpdate(&synthVoice[i]);
            }
        }
        inpGlobalMIDIDirtyFlags[set][channel] = 0xff;

    } else {
        switch (ctrl) {
        case 6:
            inpSetRPNHi(set, channel, value);
            break;
        case 38:
            inpSetRPNLo(set, channel, value);
            break;
        case 96:
            inpSetRPNDec(set, channel);
            break;
        case 97:
            inpSetRPNInc(set, channel);
            break;
        }

        fx_ctrl[channel][ctrl] = value & 0x7f;
        for (i = 0; i < synthInfo.voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].midiDirtyFlags = 0x1fff;
                synthKeyStateUpdate(&synthVoice[i]);
            }
        }
    }
}
#pragma pop

void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value) {
    if (channel == 0xFF) {
        return;
    }
    if (ctrl < 64) {
        inpSetMidiCtrl(ctrl & 31, channel, set, value >> 7);
        inpSetMidiCtrl((ctrl & 31) + 32, channel, set, value & 0x7f);
    } else if (ctrl == 128 || ctrl == 129) {
        inpSetMidiCtrl(ctrl & 254, channel, set, value >> 7);
        inpSetMidiCtrl((ctrl & 254) + 1, channel, set, value & 0x7f);
    } else if (ctrl == 132 || ctrl == 133) {
        inpSetMidiCtrl(ctrl & 254, channel, set, value >> 7);
        inpSetMidiCtrl((ctrl & 254) + 1, channel, set, value & 0x7f);
    } else {
        inpSetMidiCtrl(ctrl, channel, set, value >> 7);
    }
}

void inpResetMidiCtrl(u8 midi, u8 midiSet, u32 coldReset) {
    const u8 *src = coldReset != 0 ? lbl_8047C310 : lbl_8047C398;
    u8 *dst;
    s32 i;

    if (midiSet != 0xFF) {
        dst = midi_ctrl[midiSet][midi];
    } else {
        dst = fx_ctrl[midi];
    }
    if (coldReset != 0) {
        memcpy(dst, src, 0x86);
    } else {
        for (i = 0; i < 0x86; i++) {
            if (src[i] != 0xFF) {
                dst[i] = src[i];
            }
        }
    }
    inpSetMidiLastNote(midi, midiSet, 0xFF);
}

u16 inpGetMidiCtrl(u8 ctrl, u8 channel, u8 set) {

    if (channel != 0xff) {
        if (set != 0xff) {

            if (ctrl < 0x40) {
                return midi_ctrl[set][channel][ctrl & 0x1f] << 7 | midi_ctrl[set][channel][(ctrl & 0x1f) + 0x20];
            }
            if (ctrl < 0x46) {
                return midi_ctrl[set][channel][ctrl] < 0x40 ? 0 : 0x3fff;
            }
            if (ctrl >= 0x60 && ctrl < 0x66) {
                return 0;
            }

            if ((ctrl == 0x80) || (ctrl == 0x81)) {
                return midi_ctrl[set][channel][ctrl & 0xfe] << 7 | midi_ctrl[set][channel][(ctrl & 0xfe) + 1];
            }
            if ((ctrl == 0x84) || (ctrl == 0x85)) {
                return midi_ctrl[set][channel][ctrl & 0xfe] << 7 | midi_ctrl[set][channel][(ctrl & 0xfe) + 1];
            }

            return midi_ctrl[set][channel][ctrl] << 7;
        }
        if (ctrl < 0x40) {
            return fx_ctrl[channel][ctrl & 0x1f] << 7 | fx_ctrl[channel][(ctrl & 0x1f) + 0x20];
        }
        if (ctrl < 0x46) {
            return fx_ctrl[channel][ctrl] < 0x40 ? 0 : 0x3fff;
        }
        if (ctrl >= 0x60 && ctrl < 0x66) {
            return 0;
        }
        if ((ctrl == 0x80) || (ctrl == 0x81)) {
            return fx_ctrl[channel][ctrl & 0xfe] << 7 | fx_ctrl[channel][(ctrl & 0xfe) + 1];
        }
        if ((ctrl == 0x84) || (ctrl == 0x85)) {
            return fx_ctrl[channel][ctrl & 0xfe] << 7 | fx_ctrl[channel][(ctrl & 0xfe) + 1];
        }
        return fx_ctrl[channel][ctrl] << 7;
    }
    return 0;
}

SynthChannelDefaults *inpGetChannelDefaults(u8 midi, u8 midiSet) {
    if (midiSet == 0xff) {
        return &inpFXChannelDefaults[midi];
    }
    return &inpChannelDefaults[midiSet][midi];
}

void inpResetChannelDefaults(u8 midi, u8 midiSet) {
    SynthChannelDefaults *channelDefaults;
    if (midiSet != 0xFF) {
        channelDefaults = &inpChannelDefaults[midiSet][midi];
    } else {
        channelDefaults = &inpFXChannelDefaults[midi];
    }
    channelDefaults->pbRange = 2;
}

void inpAddCtrl(CtrlDest *dest, u8 ctrl, s32 scale, u8 comb, u32 isVar) {
    u32 n;
    if (comb == 0) {
        dest->numSource = 0;
    }
    n = dest->numSource;
    if (n < 4) {
        dest->numSource = n + 1;
        if (isVar == 0) {
            ctrl = inpTranslateExCtrl(ctrl);
        } else {
            comb |= 0x10;
        }
        dest->source[(u8)n].midiCtrl = ctrl;
        dest->source[(u8)n].combine = comb;
        dest->source[(u8)n].scale = scale;
    }
}

void inpFXCopyCtrl(u8 ctrl, SynthVoice *dvoice, SynthVoice *svoice) {
    u8 di;
    u8 si;
    di = dvoice->id;
    si = svoice->id;

    if (ctrl < 64) {
        fx_ctrl[di][ctrl & 31] = fx_ctrl[si][ctrl & 31];
        fx_ctrl[di][(ctrl & 31) + 32] = fx_ctrl[si][(ctrl & 31) + 32];
    } else if (ctrl == 128 || ctrl == 129) {
        fx_ctrl[di][ctrl & 254] = fx_ctrl[si][ctrl & 254];
        fx_ctrl[di][(ctrl & 254) + 1] = fx_ctrl[si][(ctrl & 254) + 1];
    } else if (ctrl == 132 || ctrl == 133) {
        fx_ctrl[di][ctrl & 254] = fx_ctrl[si][ctrl & 254];
        fx_ctrl[di][(ctrl & 254) + 1] = fx_ctrl[si][(ctrl & 254) + 1];
    } else {
        fx_ctrl[di][ctrl] = fx_ctrl[si][ctrl];
    }
}

void inpSetMidiLastNote(u8 midi, u8 midiSet, u8 key) {
    if (midiSet != 0xFF) {
        midi_lastNote[midiSet][midi] = key;
        return;
    }
    fx_lastNote[midi] = key;
}

u8 inpGetMidiLastNote(u8 midi, u8 midiSet) {
    if (midiSet != 0xFF) {
        return midi_lastNote[midiSet][midi];
    }
    return fx_lastNote[midi];
}

#define CLAMP(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define CLAMP_INV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
u16 _GetInputValue(SynthVoice *svoice, CtrlDest *inp, u8 midi, u8 midiSet) {
    u32 i;
    u32 value;
    u8 ctrl;
    s32 tmp;
    s32 vtmp;
    u32 sign;
    for (value = 0, i = 0; i < inp->numSource; ++i) {
        if (inp->source[i].combine & 0x10) {
            tmp = (svoice != NULL ? varGet(svoice, 0, inp->source[i].midiCtrl) : 0);
            goto block_18;
        }
        ctrl = inp->source[i].midiCtrl;
        if (ctrl == 128 || ctrl == 1 || ctrl == 10 || ctrl == 160 || ctrl == 161 || ctrl == 131) {
            switch (ctrl) {
            case 160:
            case 161:
                if (svoice != NULL) {
                    tmp = svoice->lfo[ctrl - 160].value << 1;
                    svoice->lfoUsedByInput[ctrl - 160] = 1;
                } else {
                    tmp = 0;
                }
                break;
            default:
                tmp = inpGetMidiCtrl(ctrl, midi, midiSet) - 0x2000;
                break;
            }
        block_18:
            tmp = (tmp * (inp->source[i].scale >> 1)) >> 15;
            tmp = CLAMP_INV(tmp, -0x2000, 0x1FFF);
            switch (inp->source[i].combine & 15) {
            case 0:
                value = tmp + 0x2000;
                sign = 1;
                break;
            case 1:
                if (sign != 0) {
                    vtmp = (value + tmp);
                    vtmp -= 0x2000;
                    value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                } else {
                    vtmp = value + tmp;
                    value = CLAMP(vtmp, 0, 0x3FFF);
                }
                break;
            case 2:
                if (sign != 0) {
                    vtmp = (s32)((value - 0x2000) * tmp) >> 13;
                } else {
                    vtmp = (tmp * value) >> 13;
                    sign = 1;
                }
                value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                break;
            case 3:
                if (sign != 0) {
                    vtmp = (value - 0x2000) - tmp;
                    value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                } else {
                    vtmp = value - tmp;
                    value = CLAMP(vtmp, 0, 0x3FFF);
                }
                break;
            }
        } else {
            switch (ctrl) {
            case 162:
                if (svoice != NULL) {
                    tmp = svoice->orgNote << 7;
                } else {
                    tmp = 0;
                }
                break;
            case 163:
                tmp = svoice != NULL ? svoice->orgVolume >> 9 : 0;
                break;
            case 164:
                if (svoice != NULL) {
                    tmp = (synthRealTime - svoice->macStartTime) >> 8;
                    if (tmp > 0x3fff) {
                        tmp = 0x3fff;
                    }
                    svoice->timeUsedByInput = 1;
                } else {
                    tmp = 0;
                }
                break;
            default:
                tmp = inpGetMidiCtrl(ctrl, midi, midiSet);
                break;
            }
            tmp = (tmp * (inp->source[i].scale >> 1)) >> 15;
            if (tmp > 0x3FFF) {
                tmp = 0x3FFF;
            }
            switch (inp->source[i].combine & 0xF) {
            case 0:
                value = tmp;
                sign = 0;
                break;
            case 1:
                if (sign != 0) {
                    vtmp = (value + tmp);
                    vtmp -= 0x2000;
                    value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                } else {
                    value += tmp;
                    value = MIN(value, 0x3FFF);
                }
                break;
            case 2:
                if (sign != 0) {
                    vtmp = (s32)(tmp * (value - 0x2000)) >> 14;
                    value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                } else {
                    value = ((value * tmp) >> 0xE);
                    value = MIN(value, 0x3FFF);
                }
                break;
            case 3:
                if (sign != 0) {
                    vtmp = (value - 0x2000) - tmp;
                    value = CLAMP_INV(vtmp, -0x2000, 0x1FFF) + 0x2000;
                } else {
                    vtmp = value - tmp;
                    value = CLAMP(vtmp, 0, 0x3FFF);
                }
                break;
            }
        }
    }
    inp->oldValue = value;
    return value;
}

u16 inpGetVolume(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 1)) {
        return svoice->inpVolume.oldValue;
    }
    svoice->midiDirtyFlags &= ~1;
    return _GetInputValue(svoice, &svoice->inpVolume, svoice->midi, svoice->midiSet);
}

u16 inpGetPanning(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 2)) {
        return svoice->inpPanning.oldValue;
    }
    svoice->midiDirtyFlags &= ~2;
    return _GetInputValue(svoice, &svoice->inpPanning, svoice->midi, svoice->midiSet);
}

u16 inpGetSurPanning(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 4)) {
        return svoice->inpSurroundPanning.oldValue;
    }
    svoice->midiDirtyFlags &= ~4;
    return _GetInputValue(svoice, &svoice->inpSurroundPanning, svoice->midi, svoice->midiSet);
}

u16 inpGetPitchBend(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 8)) {
        return svoice->inpPitchBend.oldValue;
    }
    svoice->midiDirtyFlags &= ~8;
    return _GetInputValue(svoice, &svoice->inpPitchBend, svoice->midi, svoice->midiSet);
}

u16 inpGetDoppler(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x10)) {
        return svoice->inpDoppler.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x10;
    return _GetInputValue(svoice, &svoice->inpDoppler, svoice->midi, svoice->midiSet);
}

u16 inpGetModulation(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x20)) {
        return svoice->inpModulation.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x20;
    return _GetInputValue(svoice, &svoice->inpModulation, svoice->midi, svoice->midiSet);
}

u16 inpGetPedal(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x40)) {
        return svoice->inpPedal.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x40;
    return _GetInputValue(svoice, &svoice->inpPedal, svoice->midi, svoice->midiSet);
}

u16 inpGetPreAuxA(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x100)) {
        return svoice->inpPreAuxA.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x100;
    return _GetInputValue(svoice, &svoice->inpPreAuxA, svoice->midi, svoice->midiSet);
}

u16 inpGetReverb(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x200)) {
        return svoice->inpReverb.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x200;
    return _GetInputValue(svoice, &svoice->inpReverb, svoice->midi, svoice->midiSet);
}

u16 inpGetPreAuxB(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x400)) {
        return svoice->inpPreAuxB.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x400;
    return _GetInputValue(svoice, &svoice->inpPreAuxB, svoice->midi, svoice->midiSet);
}

u16 inpGetPostAuxB(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x800)) {
        return svoice->inpPostAuxB.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x800;
    return _GetInputValue(svoice, &svoice->inpPostAuxB, svoice->midi, svoice->midiSet);
}

u16 inpGetTremolo(SynthVoice *svoice) {
    if (!(svoice->midiDirtyFlags & 0x1000)) {
        return svoice->inpTremolo.oldValue;
    }
    svoice->midiDirtyFlags &= ~0x1000;
    return _GetInputValue(svoice, &svoice->inpTremolo, svoice->midi, svoice->midiSet);
}

#pragma push
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline u32 inpResetGlobalMIDIDirtyFlag(u8 chan, u8 midiSet, u32 flag) {
    u32 ret;
    if ((ret = (flag & inpGlobalMIDIDirtyFlags[midiSet][chan]) != 0) != 0) {
        inpGlobalMIDIDirtyFlags[midiSet][chan] &= ~flag;
    }
    return ret;
}

static inline u16 GetGlobalInputValue(CtrlDest *inp, u32 dirtyMask, u8 midi, u8 midiSet) {
    if (!inpResetGlobalMIDIDirtyFlag(midi, midiSet, dirtyMask)) {
        return inp->oldValue;
    }
    return _GetInputValue(0, inp, midi, midiSet);
}

u32 lbl_804F7120[4] = {0x80000001, 0x80000002, 0x80000004, 0x80000008};
u32 lbl_804F7130[4] = {0x80000010, 0x80000020, 0x80000040, 0x80000080};

u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet) {
    return GetGlobalInputValue(&inpAuxA[studio][index], lbl_804F7120[index], midi, midiSet);
}

u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet) {
    return GetGlobalInputValue(&inpAuxB[studio][index], lbl_804F7130[index], midi, midiSet);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void inpResetGlobalMIDIDirtyFlags(void) {
    u32 i, j;
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 16; ++j) {
            inpGlobalMIDIDirtyFlags[i][j] = 0xFF;
        }
    }
}

void inpInit(SynthVoice *svoice) {
    u32 i;
    u32 s;

    if (svoice != NULL) {
        svoice->inpVolume.source[0].midiCtrl = 7;
        svoice->inpVolume.source[0].combine = 0;
        svoice->inpVolume.source[0].scale = 0x10000;
        svoice->inpVolume.source[1].midiCtrl = 0xB;
        svoice->inpVolume.source[1].combine = 2;
        svoice->inpVolume.source[1].scale = 0x10000;
        svoice->inpVolume.numSource = 2;
        svoice->inpPanning.source[0].midiCtrl = 0xA;
        svoice->inpPanning.source[0].combine = 0;
        svoice->inpPanning.source[0].scale = 0x10000;
        svoice->inpPanning.numSource = 1;
        svoice->inpSurroundPanning.source[0].midiCtrl = 0x83;
        svoice->inpSurroundPanning.source[0].combine = 0;
        svoice->inpSurroundPanning.source[0].scale = 0x10000;
        svoice->inpSurroundPanning.numSource = 1;
        svoice->inpPitchBend.source[0].midiCtrl = 0x80;
        svoice->inpPitchBend.source[0].combine = 0;
        svoice->inpPitchBend.source[0].scale = 0x10000;
        svoice->inpPitchBend.numSource = 1;
        svoice->inpModulation.source[0].midiCtrl = 1;
        svoice->inpModulation.source[0].combine = 0;
        svoice->inpModulation.source[0].scale = 0x10000;
        svoice->inpModulation.numSource = 1;
        svoice->inpPedal.source[0].midiCtrl = 0x40;
        svoice->inpPedal.source[0].combine = 0;
        svoice->inpPedal.source[0].scale = 0x10000;
        svoice->inpPedal.numSource = 1;
        svoice->inpPortamento.source[0].midiCtrl = 0x41;
        svoice->inpPortamento.source[0].combine = 0;
        svoice->inpPortamento.source[0].scale = 0x10000;
        svoice->inpPortamento.numSource = 1;
        svoice->inpPreAuxA.numSource = 0;
        svoice->inpReverb.source[0].midiCtrl = 0x5B;
        svoice->inpReverb.source[0].combine = 0;
        svoice->inpReverb.source[0].scale = 0x10000;
        svoice->inpReverb.numSource = 1;
        svoice->inpPreAuxB.numSource = 0;
        svoice->inpPostAuxB.source[0].midiCtrl = 0x5D;
        svoice->inpPostAuxB.source[0].combine = 0;
        svoice->inpPostAuxB.source[0].scale = 0x10000;
        svoice->inpPostAuxB.numSource = 1;
        svoice->inpDoppler.source[0].midiCtrl = 0x84;
        svoice->inpDoppler.source[0].combine = 0;
        svoice->inpDoppler.source[0].scale = 0x10000;
        svoice->inpDoppler.numSource = 1;
        svoice->inpTremolo.numSource = 0;
        svoice->midiDirtyFlags = 0x1FFF;
        svoice->lfoUsedByInput[0] = 0;
        svoice->lfoUsedByInput[1] = 0;
        svoice->timeUsedByInput = 0;
    } else {
    for (s = 0; s < 8; ++s) {
        for (i = 0; i < 4; ++i) {
            inpAuxA[s][i].numSource = 0;
            inpAuxB[s][i].numSource = 0;
        }
    }
    inpResetGlobalMIDIDirtyFlags();
    }
}

#pragma pop

#pragma push
#pragma scheduling off
u8 inpTranslateExCtrl(u8 ctrl) {
    switch (ctrl) {
    case 0x80:
        return 0x80U;
    case 0x81:
        return 0x82U;
    case 0x82:
        return 0xA0U;
    case 0x83:
        return 0xA1U;
    case 0x84:
        return 0x83U;
    case 0x85:
        return 0x84U;
    case 0x86:
        return 0xA2U;
    case 0x87:
        return 0xA3U;
    case 0x88:
        return 0xA4U;
    default:
        return ctrl;
    }
}
#pragma pop

u16 inpGetExCtrl(SynthVoice *svoice, u8 ctrl) {
    switch (inpTranslateExCtrl(ctrl)) {
    case 0xA0:
        return svoice->lfo[0].value * 2 + 0x2000;
    case 0xA1:
        return svoice->lfo[1].value * 2 + 0x2000;
    default:
        return svoice->midi != 0xFF ? inpGetMidiCtrl(ctrl, svoice->midi, svoice->midiSet) : 0;
    }
}

void inpSetExCtrl(SynthVoice *svoice, u8 ctrl, s16 v) {
    v = v < 0 ? 0 : v > 0x3FFF ? 0x3FFF : v;
    switch (inpTranslateExCtrl(ctrl)) {
    case 0xA0:
    case 0xA1:
        break;
    default:
        if (svoice->midi != 0xFF) {
            inpSetMidiCtrl14(ctrl, svoice->midi, svoice->midiSet, v);
        }
        break;
    }
}

}
