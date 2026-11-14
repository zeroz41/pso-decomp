#include "musyx/runtime/musyx_runtime_b.h"

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
static ChannelDefaults_803BADF8 inpChannelDefaults[8][16];
static ChannelDefaults_803BADF8 inpFXChannelDefaults[64];

void inpSetGlobalMIDIDirtyFlag(u8 a, u8 b, u32 v) {
    inpGlobalMIDIDirtyFlags[b][a] |= v;
}

#define synthInfo_voiceNum (((u8 *)synthInfo)[0x210])
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline void inpSetRPNHi_803BADF8(u8 set, u8 channel, u8 value) {
    u16 rpn;
    u32 i;
    u8 range;

    rpn = (midi_ctrl[set][channel][100]) | (midi_ctrl[set][channel][101] << 8);
    switch (rpn) {
    case 0:
        range = value > 24 ? 24 : value;
        inpChannelDefaults[set][channel].pbRange = range;

        for (i = 0; i < synthInfo_voiceNum; ++i) {
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

static inline void inpSetRPNLo_803BADF8(u8 set, u8 channel, u8 value) {
}

static inline void inpSetRPNDec_803BADF8(u8 set, u8 channel) {
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
        for (i = 0; i < synthInfo_voiceNum; ++i) {
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

static inline void inpSetRPNInc_803BADF8(u8 set, u8 channel) {
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
        for (i = 0; i < synthInfo_voiceNum; ++i) {
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
            inpSetRPNHi_803BADF8(set, channel, value);
            break;
        case 38:
            inpSetRPNLo_803BADF8(set, channel, value);
            break;
        case 96:
            inpSetRPNDec_803BADF8(set, channel);
            break;
        case 97:
            inpSetRPNInc_803BADF8(set, channel);
            break;
        }

        midi_ctrl[set][channel][ctrl] = (value & 0x7f);
        for (i = 0; i < synthInfo_voiceNum; ++i) {
            if (set == synthVoice[i].midiSet && channel == synthVoice[i].midi) {
                synthVoice[i].midiDirtyFlags = 0x1fff;
                synthKeyStateUpdate(&synthVoice[i]);
            }
        }
        inpGlobalMIDIDirtyFlags[set][channel] = 0xff;

    } else {
        switch (ctrl) {
        case 6:
            inpSetRPNHi_803BADF8(set, channel, value);
            break;
        case 38:
            inpSetRPNLo_803BADF8(set, channel, value);
            break;
        case 96:
            inpSetRPNDec_803BADF8(set, channel);
            break;
        case 97:
            inpSetRPNInc_803BADF8(set, channel);
            break;
        }

        fx_ctrl[channel][ctrl] = value & 0x7f;
        for (i = 0; i < synthInfo_voiceNum; ++i) {
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

void inpResetMidiCtrl(u8 arg0, u8 arg1, u32 arg2) {
    const u8 *src = arg2 != 0 ? lbl_8047C310 : lbl_8047C398;
    u8 *dst;
    s32 i;

    if (arg1 != 0xFF) {
        dst = midi_ctrl[arg1][arg0];
    } else {
        dst = fx_ctrl[arg0];
    }
    if (arg2 != 0) {
        memcpy(dst, src, 0x86);
    } else {
        for (i = 0; i < 0x86; i++) {
            if (src[i] != 0xFF) {
                dst[i] = src[i];
            }
        }
    }
    inpSetMidiLastNote(arg0, arg1, 0xFF);
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

u8 *inpGetChannelDefaults(u8 a, u8 b) {
    if (b == 0xff) {
        return &lbl_8056E118[a];
    }
    return &lbl_8056E098[b][a];
}

void inpResetChannelDefaults(u8 arg0, u8 arg1) {
    s8 *var_r3;
    if (arg1 != 0xFF) {
        var_r3 = (s8 *)&lbl_8056E098[arg1][arg0];
    } else {
        var_r3 = (s8 *)&lbl_8056E118[arg0];
    }
    *var_r3 = 2;
}

void inpAddCtrl(Obj_803BB8F0 *arg0, u8 arg1, s32 arg2, u8 arg3, u32 arg4) {
    u32 n;
    if (arg3 == 0) {
        arg0->count = 0;
    }
    n = arg0->count;
    if (n < 4) {
        arg0->count = n + 1;
        if (arg4 == 0) {
            arg1 = inpTranslateExCtrl(arg1);
        } else {
            arg3 |= 0x10;
        }
        arg0->ents[(u8)n].code = arg1;
        arg0->ents[(u8)n].flags = arg3;
        arg0->ents[(u8)n].val = arg2;
    }
}

void inpFXCopyCtrl(u8 ctrl, SynthVoice_803BADF8 *dvoice, SynthVoice_803BADF8 *svoice) {
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

void inpSetMidiLastNote(u8 arg0, u8 arg1, u8 arg2) {
    if (arg1 != 0xFF) {
        *(s8 *)((s8 *)((u8 *)(((u8 *)(midi_lastNote) + (arg1 * 0x10))) + arg0) + 0) = arg2;
        return;
    }
    *(s8 *)((s8 *)((u8 *)(fx_lastNote) + arg0) + 0) = arg2;
}

u8 inpGetMidiLastNote(u8 arg0, u8 arg1) {
    if (arg1 != 0xFF) {
        return *(u8 *)((s8 *)((u8 *)(((u8 *)(midi_lastNote) + (arg1 * 0x10))) + arg0) + 0);
    }
    return *(u8 *)((s8 *)((u8 *)(fx_lastNote) + arg0) + 0);
}

#define CLAMP(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define CLAMP_INV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
u16 _GetInputValue(Voice_803BBB30 *svoice, Inp_803BBB30 *inp, u8 midi, u8 midiSet) {
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
                    tmp = svoice->b12F << 7;
                } else {
                    tmp = 0;
                }
                break;
            case 163:
                tmp = svoice != NULL ? svoice->w158 >> 9 : 0;
                break;
            case 164:
                if (svoice != NULL) {
                    tmp = (synthRealTime - svoice->time) >> 8;
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

u16 inpGetVolume(Lob_803BBFB8 *arg0) {
    if (!(arg0->flags & 1)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~1;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x218), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPanning(Lob_803BC000 *arg0) {
    if (!(arg0->flags & 2)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~2;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x23C), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetSurPanning(Lob_803BC048 *arg0) {
    if (!(arg0->flags & 4)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~4;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x260), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPitchBend(Lob_803BC090 *arg0) {
    if (!(arg0->flags & 8)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~8;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x284), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetDoppler(Lob_803BC0D8 *arg0) {
    if (!(arg0->flags & 0x10)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x10;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x2A8), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetModulation(Lob_803BC120 *arg0) {
    if (!(arg0->flags & 0x20)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x20;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x2CC), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPedal(Lob_803BC168 *arg0) {
    if (!(arg0->flags & 0x40)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x40;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x2F0), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPreAuxA(Lob_803BC1B0 *arg0) {
    if (!(arg0->flags & 0x100)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x100;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x338), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetReverb(Lob_803BC1F8 *arg0) {
    if (!(arg0->flags & 0x200)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x200;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x35C), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPreAuxB(Lob_803BC240 *arg0) {
    if (!(arg0->flags & 0x400)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x400;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x380), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetPostAuxB(Lob_803BC288 *arg0) {
    if (!(arg0->flags & 0x800)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x800;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x3A4), (u8)(arg0->b121), (u8)(arg0->b122));
}

u16 inpGetTremolo(Lob_803BC2D0 *arg0) {
    if (!(arg0->flags & 0x1000)) {
        return arg0->v;
    }
    arg0->flags = arg0->flags & ~0x1000;
    return _GetInputValue((Voice_803BBB30 *)(arg0), (Inp_803BBB30 *)((u8 *)arg0 + 0x3C8), (u8)(arg0->b121), (u8)(arg0->b122));
}

#pragma push
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline u32 inpResetGlobalMIDIDirtyFlag_803BC318(u8 chan, u8 midiSet, u32 flag) {
    u32 ret;
    if ((ret = (flag & inpGlobalMIDIDirtyFlags[midiSet][chan]) != 0) != 0) {
        inpGlobalMIDIDirtyFlags[midiSet][chan] &= ~flag;
    }
    return ret;
}

static inline u16 GetGlobalInputValue_803BC318(Inp_803BBB30 *inp, u32 dirtyMask, u8 midi, u8 midiSet) {
    if (!inpResetGlobalMIDIDirtyFlag_803BC318(midi, midiSet, dirtyMask)) {
        return inp->oldValue;
    }
    return _GetInputValue(0, inp, midi, midiSet);
}

u32 lbl_804F7120[4] = {0x80000001, 0x80000002, 0x80000004, 0x80000008};
u32 lbl_804F7130[4] = {0x80000010, 0x80000020, 0x80000040, 0x80000080};

u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet) {
    return GetGlobalInputValue_803BC318(&inpAuxA[studio][index], lbl_804F7120[index], midi, midiSet);
}

u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet) {
    return GetGlobalInputValue_803BC318(&inpAuxB[studio][index], lbl_804F7130[index], midi, midiSet);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void reset_dirty_803BC490(void) {
    u32 i, j;
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 16; ++j) {
            inpGlobalMIDIDirtyFlags[i][j] = 0xFF;
        }
    }
}

void inpInit(u8 *arg0) {
    u32 i;
    u32 s;

    if (arg0 != NULL) {
        *(u8 *)((s8 *)arg0 + 0x218) = 7;
        *(u8 *)((s8 *)arg0 + 0x219) = 0;
        *(s32 *)((s8 *)arg0 + 0x21C) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x220) = 0xB;
        *(u8 *)((s8 *)arg0 + 0x221) = 2;
        *(s32 *)((s8 *)arg0 + 0x224) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x23A) = 2;
        *(u8 *)((s8 *)arg0 + 0x23C) = 0xA;
        *(u8 *)((s8 *)arg0 + 0x23D) = 0;
        *(s32 *)((s8 *)arg0 + 0x240) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x25E) = 1;
        *(u8 *)((s8 *)arg0 + 0x260) = 0x83;
        *(u8 *)((s8 *)arg0 + 0x261) = 0;
        *(s32 *)((s8 *)arg0 + 0x264) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x282) = 1;
        *(u8 *)((s8 *)arg0 + 0x284) = 0x80;
        *(u8 *)((s8 *)arg0 + 0x285) = 0;
        *(s32 *)((s8 *)arg0 + 0x288) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x2A6) = 1;
        *(u8 *)((s8 *)arg0 + 0x2CC) = 1;
        *(u8 *)((s8 *)arg0 + 0x2CD) = 0;
        *(s32 *)((s8 *)arg0 + 0x2D0) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x2EE) = 1;
        *(u8 *)((s8 *)arg0 + 0x2F0) = 0x40;
        *(u8 *)((s8 *)arg0 + 0x2F1) = 0;
        *(s32 *)((s8 *)arg0 + 0x2F4) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x312) = 1;
        *(u8 *)((s8 *)arg0 + 0x314) = 0x41;
        *(u8 *)((s8 *)arg0 + 0x315) = 0;
        *(s32 *)((s8 *)arg0 + 0x318) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x336) = 1;
        *(u8 *)((s8 *)arg0 + 0x35A) = 0;
        *(u8 *)((s8 *)arg0 + 0x35C) = 0x5B;
        *(u8 *)((s8 *)arg0 + 0x35D) = 0;
        *(s32 *)((s8 *)arg0 + 0x360) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x37E) = 1;
        *(u8 *)((s8 *)arg0 + 0x3A2) = 0;
        *(u8 *)((s8 *)arg0 + 0x3A4) = 0x5D;
        *(u8 *)((s8 *)arg0 + 0x3A5) = 0;
        *(s32 *)((s8 *)arg0 + 0x3A8) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x3C6) = 1;
        *(u8 *)((s8 *)arg0 + 0x2A8) = 0x84;
        *(u8 *)((s8 *)arg0 + 0x2A9) = 0;
        *(s32 *)((s8 *)arg0 + 0x2AC) = 0x10000;
        *(u8 *)((s8 *)arg0 + 0x2CA) = 1;
        *(u8 *)((s8 *)arg0 + 0x3EA) = 0;
        *(s32 *)((s8 *)arg0 + 0x214) = 0x1FFF;
        *(u8 *)((s8 *)arg0 + 0x1D4) = 0;
        *(u8 *)((s8 *)arg0 + 0x1D5) = 0;
        *(u8 *)((s8 *)arg0 + 0xA8) = 0;
    } else {
    for (s = 0; s < 8; ++s) {
        for (i = 0; i < 4; ++i) {
            inpAuxA[s][i].numSource = 0;
            inpAuxB[s][i].numSource = 0;
        }
    }
    reset_dirty_803BC490();
    }
}

#pragma pop

#pragma push
#pragma scheduling off
u8 inpTranslateExCtrl(u8 arg0) {
    switch (arg0) {
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
        return arg0;
    }
}
#pragma pop

u16 inpGetExCtrl(Obj_803BC7E4 *arg0, u8 arg1) {
    switch (inpTranslateExCtrl(arg1)) {
    case 0xA0:
        return arg0->v1c4 * 2 + 0x2000;
    case 0xA1:
        return arg0->v1d0 * 2 + 0x2000;
    default:
        return arg0->b121 != 0xFF ? inpGetMidiCtrl(arg1, arg0->b121, arg0->b122) : 0;
    }
}

void inpSetExCtrl(Obj_803BC884 *arg0, u8 arg1, s16 arg2) {
    s16 v = arg2 < 0 ? 0 : (arg2 > 0x3FFF ? 0x3FFF : arg2);
    s32 k;
    k = inpTranslateExCtrl(arg1);
    if ((k >= 0xA2 || k < 0xA0) && arg0->b121 != 0xFF) {
        inpSetMidiCtrl14(arg1, (u8)(arg0->b121), (u8)(arg0->b122), (u16)(v));
    }
}

}
