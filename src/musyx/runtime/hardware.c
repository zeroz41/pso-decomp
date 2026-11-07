#include "musyx/runtime/musyx_runtime_b.h"

#define synthInfo_voiceNum (((u8 *)synthInfo)[0x210])
#define CLAMP(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define CLAMP_INV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
extern "C" {

s8 salTimeOffset;
SND_HOOKS lbl_805D74BC;
u8 lbl_805D74C4;
u8 lbl_805D74C5;
u8 lbl_805D74C6;
u8 lbl_805D74C7;

u16 lbl_805D4638[3] = {0, 1, 2};
u16 lbl_805D4640[3] = {0, 1, 2};

const u16 lbl_8047C420[128] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4,
    5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 15, 15, 15, 16,
    16, 17, 17, 17, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 22, 22,
    22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27,
    28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31,
    31, 31, 31, 31, 31, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
};

void snd_handle_irq(void) {
    u8 j;
    u8 i;
    u8 v;

    if (sndActive == 0) {
        return;
    }
    streamCorrectLoops();
    hwIRQEnterCritical();
    salCtrlDsp((s32)salAiGetDest());
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    salHandleAuxProcessing();
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    lbl_805D74C7 ^= 1;
    lbl_805D74C6 = (lbl_805D74C6 + 1) % 3;
    for (v = 0; v < lbl_805D74C5; ++v) {
        for (i = 0; i < 5; ++i) {
            (*(Slot_803BCAA0 **)&lbl_805D748C)[v].changed[i] = 0;
        }
    }
    hwIRQLeaveCritical();
    for (j = 0; j < 5; ++j) {
        hwIRQEnterCritical();
        hwSetTimeOffset(j);
        seqHandle(0x100);
        synthHandle(0x100);
        hwIRQLeaveCritical();
    }
    hwIRQEnterCritical();
    hwSetTimeOffset(0);
    s3dHandle();
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    streamHandle();
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    vsSampleUpdates();
    hwIRQLeaveCritical();
}

s32 hwInit(u32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    hwInitIrq();
    lbl_805D74C7 = 0;
    lbl_805D74C6 = 0;
    salMessageCallback = 0;
    if (salInitAi(snd_handle_irq, arg3, (u32 *)arg0) != 0 &&
        salInitDspCtrl(arg1, arg2, (arg3 & 1) != 0) != 0 &&
        salInitDsp(arg3) != 0) {
        hwEnableIrq();
        salStartAi();
        return 0;
    }
    return -1;
}

void hwSetTimeOffset(s8 arg0) {
    salTimeOffset = arg0;
}
u8 hwGetTimeOffset(void) {
    return (*(u8 *)&salTimeOffset);
}

bool hwIsActive(s32 i) {
    return (*(Slot_803BCCE0 * *)&lbl_805D748C)[i].fec != 0;
}

void hwSetMesgCallback(s32 arg0) {
    salMessageCallback = arg0;
}

void hwSetPriority(s32 i, s32 v) {
    (*(Slot_803BCD08 * *)&lbl_805D748C)[i].f1c = v;
}

void hwInitSamplePlayback(s32 n, s16 arg1, Blk_803BCD1C *arg2, u32 arg3, s32 arg4, s32 arg5, u32 arg6, u8 arg7) {
    u8 i;
    s32 flags = 0;
    for (i = 0; i <= (u8)salTimeOffset; i++) {
        flags |= SLOTS_803BCD1C[n].f24[i] & 0x20;
        SLOTS_803BCD1C[n].f24[i] = 0;
    }
    SLOTS_803BCD1C[n].f24[0] = flags;
    SLOTS_803BCD1C[n].f1c = arg4;
    SLOTS_803BCD1C[n].f18 = arg5;
    SLOTS_803BCD1C[n].ff0 = 0;
    SLOTS_803BCD1C[n].f70 = arg1;
    SLOTS_803BCD1C[n].f74 = *arg2;
    if (arg3 != 0) {
        SLOTS_803BCD1C[n].fa4 = 0;
        SLOTS_803BCD1C[n].fb8 = 0;
        SLOTS_803BCD1C[n].fbc = 0;
        SLOTS_803BCD1C[n].fc0 = 0x7FFF;
        SLOTS_803BCD1C[n].fc4 = 0;
    }
    SLOTS_803BCD1C[n].fe4 = 0xFF;
    SLOTS_803BCD1C[n].fe5 = 0xFF;
    SLOTS_803BCD1C[n].fe6 = 0xFF;
    SLOTS_803BCD1C[n].fe7 = 0xFF;
    if (arg6 != 0) {
        hwSetSRCType(n, 0);
        hwSetPolyPhaseFilter(n, 1);
    }
    hwSetITDMode(n, arg7);
}

void hwBreak(s32 i) {
    Slot_803BCEC8 *s = &(*(Slot_803BCEC8 **)&lbl_805D748C)[i];
    if (s->fec == 1 && (u8)salTimeOffset == 0) {
        s->fee = 1;
    }
    (*(Slot_803BCEC8 **)&lbl_805D748C)[i].f24[(u8)salTimeOffset] |= 0x20;
}

void hwSetADSR(s32 n, void *arg1, u8 mode) {
    u32 v;
    switch (mode) {
    case 0: {
        ArgA_803BCF18 *a = (ArgA_803BCF18 *)arg1;
        SLOTS_803BCF18[n].fa4 = 0;
        SLOTS_803BCF18[n].fb8 = a->f0;
        SLOTS_803BCF18[n].fbc = a->f2;
        if ((v = a->f4 << 3) > 0x7FFF) {
            v = 0x7FFF;
        }
        SLOTS_803BCF18[n].fc0 = v;
        SLOTS_803BCF18[n].fc4 = a->f6;
        break;
    }
    case 1:
    case 2: {
        ArgB_803BCF18 *b = (ArgB_803BCF18 *)arg1;
        SLOTS_803BCF18[n].fa4 = 1;
        SLOTS_803BCF18[n].fca = 0;
        if (mode == 1) {
            SLOTS_803BCF18[n].fb8 = adsrConvertTimeCents(b->f0);
            SLOTS_803BCF18[n].fbc = adsrConvertTimeCents(b->f4);
            if ((v = b->f8 >> 2) > 0x3FF) {
                v = 0x3FF;
            }
            SLOTS_803BCF18[n].fc0 = 0xC1 - lbl_804F68DC[v];
        } else {
            SLOTS_803BCF18[n].fb8 = (u16)b->f0;
            SLOTS_803BCF18[n].fbc = (u16)b->f4;
            SLOTS_803BCF18[n].fc0 = b->f8;
        }
        SLOTS_803BCF18[n].fc4 = b->fa;
        break;
    }
    }
    SLOTS_803BCF18[n].f24 |= 0x10;
}

void hwSetVirtualSampleLoopBuffer(s32 i, s32 a, s32 b) {
    (*(Slot_803BD0C8 * *)&lbl_805D748C)[i].f94 = a; (*(Slot_803BD0C8 * *)&lbl_805D748C)[i].f98 = b;
}

u8 hwGetVirtualSampleState(s32 i) {
    return (*(Slot_803BD0E8 * *)&lbl_805D748C)[i].f9c;
}

u8 hwGetSampleType(s32 i) {
    return (*(Slot_803BD0FC * *)&lbl_805D748C)[i].f90;
}

u16 hwGetSampleID(s32 i) {
    return (*(Slot_803BD110 * *)&lbl_805D748C)[i].f70;
}

void hwSetStreamLoopPS(s32 i, u8 v) {
    (*(Slot_803BD124 * *)&lbl_805D748C)[i].fa0 = v;
}

void hwStart(s32 i, s32 x) {
    (*(Slot_803BD138 * *)&lbl_805D748C)[i].fd4 = salTimeOffset; salActivateVoice(&(*(Slot_803BD138 * *)&lbl_805D748C)[i], x);
}

void hwKeyOff(s32 i) {
    (*(Slot_803BD174 * *)&lbl_805D748C)[i].f24[(u8)salTimeOffset] |= 0x40;
}

void hwSetPitch(s32 i, u16 v) {
    Slot_803BD19C *s = &(*(Slot_803BD19C **)&lbl_805D748C)[i];
    if (v >= 0x4000U) {
        v = 0x3FFF;
    }
    if (s->fe4 == 0xFF || s->f38[s->fe4] != (u32)((v * 0x10) & 0xFFFF0)) {
        s->f38[(u8)salTimeOffset] = (v * 0x10) & 0xFFFF0;
        s->f24[(u8)salTimeOffset + 0] |= 8;
        s->fe4 = salTimeOffset;
    }
}

void hwSetSRCType(s32 index, u8 entry) {
    TLobbySlot_803BD214 *slot = &((TLobbySlot_803BD214 *)lbl_805D748C)[index];
    slot->code_cc = ((u16 *)&lbl_805D4638)[entry];
    slot->flags |= 0x100;
}
void hwSetPolyPhaseFilter(s32 index, u8 entry) {
    TLobbySlot_803BD214 *slot = &((TLobbySlot_803BD214 *)lbl_805D748C)[index];
    slot->code_ce = ((u16 *)&lbl_805D4640)[entry];
    slot->flags |= 0x80;
}

void hwSetITDMode(s32 i, u8 mode) {
    if (mode == 0) {
        (*(Slot_803BD26C **)&lbl_805D748C)[i].ff0 |= 0x80000000;
        (*(Slot_803BD26C **)&lbl_805D748C)[i].fd0 = 0x10;
        (*(Slot_803BD26C **)&lbl_805D748C)[i].fd2 = 0x10;
        return;
    }
    (*(Slot_803BD26C **)&lbl_805D748C)[i].ff0 &= 0x7FFFFFFF;
}

void hwSetVolume(s32 voice, u32 volumeCurve, u32 pan, s32 surroundPan, f32 direct, f32 auxiliaryA, f32 auxiliaryB) {
    SoundMixVoice *state = (*(SoundMixVoice **)&lbl_805D748C) + voice;
    SoundMixCurveOutput out[3];
    s32 left, right, surround;
    if (direct >= 1.0f) direct = 1.0f;
    if (auxiliaryA >= 1.0f) auxiliaryA = 1.0f;
    if (auxiliaryB >= 1.0f) auxiliaryB = 1.0f;
    salCalcVolume(volumeCurve, out, pan, surroundPan, (state->flags & 0x80000000) != 0,
        lbl_805663D8[state->studio].mode == 1, direct, auxiliaryA, auxiliaryB);
    left = 32767.0f * out[0].left;
    right = 32767.0f * out[0].right;
    surround = 32767.0f * out[0].surround;
    if (state->dirty[0] == 0xFF || state->coefficients[0].left != (u16)left || state->coefficients[0].right != (u16)right || state->coefficients[0].surround != (u16)surround) {
        state->coefficients[0].left = left;
        state->coefficients[0].right = right;
        state->coefficients[0].surround = surround;
        state->changed |= 1;
        state->dirty[0] = 0;
    }
    left = 32767.0f * out[1].left;
    right = 32767.0f * out[1].right;
    surround = 32767.0f * out[1].surround;
    if (state->dirty[1] == 0xFF || state->coefficients[1].left != (u16)left || state->coefficients[1].right != (u16)right || state->coefficients[1].surround != (u16)surround) {
        state->coefficients[1].left = left;
        state->coefficients[1].right = right;
        state->coefficients[1].surround = surround;
        state->changed |= 2;
        state->dirty[1] = 0;
    }
    left = 32767.0f * out[2].left;
    right = 32767.0f * out[2].right;
    surround = 32767.0f * out[2].surround;
    if (state->dirty[2] == 0xFF || state->coefficients[2].left != (u16)left || state->coefficients[2].right != (u16)right || state->coefficients[2].surround != (u16)surround) {
        state->coefficients[2].left = left;
        state->coefficients[2].right = right;
        state->coefficients[2].surround = surround;
        state->changed |= 4;
        state->dirty[2] = 0;
    }
    if (state->flags & 0x80000000) {
        const u16 *t = &lbl_8047C420[(u8)(pan >> 16)];
        state->leftDelay = *t;
        state->rightDelay = 0x20 - *t;
        state->changed |= 0x200;
    }
}

void hwOff(s32 arg0) {
    salDeactivateVoice((void *) (lbl_805D748C + (arg0 * 0xF4)));
}

#pragma push
#pragma scheduling off
void hwSetAUXProcessingCallbacks(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *temp_r3;
    temp_r3 = (u8 *)&lbl_805663D8 + (arg0 * 0xBC);
    *(s32 *)((s8 *)temp_r3 + 0xAC) = arg1;
    *(s32 *)((s8 *)temp_r3 + 0xB4) = arg2;
    *(s32 *)((s8 *)temp_r3 + 0xB0) = arg3;
    *(s32 *)((s8 *)temp_r3 + 0xB8) = arg4;
}
#pragma pop

void hwActivateStudio(u8 i, s32 a, s32 b) {
    salActivateStudio(i, a, b);
}

void hwDeactivateStudio(u8 i) {
    salDeactivateStudio(i);
}

void hwAddInput(u8 i, void *p) {
    salAddStudioInput(&((Rec_803BD62C *)&lbl_805663D8)[i], p);
}

void hwRemoveInput(u8 i, u32 x) {
    salRemoveStudioInput(&((Rec_803BD660 *)&lbl_805663D8)[i], x);
}

#define SLOTS_803BD694 (*(Slot_803BD694 **)&lbl_805D748C)
u32 hwGetPos(s32 arg0) {
    u32 r;
    u32 rem;
    if (SLOTS_803BD694[arg0].fec != 2) {
        return 0;
    }
    switch (SLOTS_803BD694[arg0].f90) {
    case 0:
    case 1:
    case 4:
    case 5:
        r = ((SLOTS_803BD694[arg0].f20 - SLOTS_803BD694[arg0].f78 * 2) >> 4) * 14;
        rem = SLOTS_803BD694[arg0].f20 & 0xF;
        if (rem >= 2) {
            r = r + (rem - 2);
        }
        break;
    case 3:
        r = SLOTS_803BD694[arg0].f20 - SLOTS_803BD694[arg0].f78;
        break;
    case 2:
        r = SLOTS_803BD694[arg0].f20 - (SLOTS_803BD694[arg0].f78 >> 1);
        break;
    }
    return r;
}

void hwFlushStream(u8 *base, u32 offset, u32 len, u8 i, void *cb, void *arg) {
    u32 sp20[2];
    u32 addr;
    u8 *p;
    addr = aramGetStreamBufferAddress(i, sp20);
    len += offset & 0x1F;
    offset &= ~0x1F;
    len = (len + 0x1F) & ~0x1F;
    p = base + offset;
    DCStoreRange(p, len);
    aramUploadData((u8 *)(p), (u32)(addr + offset), (u32)(len), (s32)(1), (void *)(cb), (void *)(arg));
}

void *hwInitStream(u32 size) {
    return aramAllocateStreamBuffer((u32)(size));
}

void hwExitStream(u8 i) {
    aramFreeStreamBuffer(i);
}

u32 hwGetStreamPlayBuffer(u8 i) {
    return aramGetStreamBufferAddress(i, (u32 *)(0));
}

void hwTransAddr(void) {
}

u32 hwFrq2Pitch(u32 arg0) {
    return (u32)(4096.0f * (f32)arg0 / (f32)synthInfo[0]);
}

void hwInitSampleMem(void *self, void *p) {
    aramInit((u32)p);
}

void hwSaveSample(Hdr_803BD8A8 **arg0, u32 *arg1) {
    u32 info = (*arg0)->info;
    u32 n = info & 0xFFFFFF;
    u32 fmt;
    u32 r;
    fmt = info >> 24;
    switch (fmt) {
    case 0:
    case 1:
    case 4:
    case 5:
        n = (n + 13) / 14 * 8;
        break;
    case 2:
        n *= 2;
        break;
    case 3:
        break;
    }
    r = aramStoreData((u8 *)((u8 *)*arg1), (u32)(n));
    *arg1 = r;
}

void hwRemoveSample(Hdr_803BD93C *arg0, u32 arg1) {
    u32 info = arg0->info;
    u32 n = info & 0xFFFFFF;
    switch (info >> 24) {
    case 0:
    case 1:
    case 4:
    case 5:
        n = (n + 13) / 14 * 8;
        break;
    case 2:
        n *= 2;
        break;
    case 3:
        break;
    }
    aramRemoveData(arg1, n);
}

void hwSyncSampleMem(void) {
    aramSyncTransferQueue();
}

void hwFrameDone(void) {
}

void sndSetHooks(Pair_803BD9E4 *arg0) {
    (*(Pair_803BD9E4 *)&lbl_805D74BC) = *arg0;
}

void hwDisableHRTF(void) {
    lbl_805D747C = 0;
}
s32 hwGetVirtualSampleID(s32 arg0) {
    u8 *temp_r3;
    temp_r3 = (unsigned char *) (lbl_805D748C + (arg0 * 0xF4));
    if ((u8) *(u8 *)((s8 *)temp_r3 + 0xEC) == 0) {
        return -1;
    }
    return *(s32 *)((s8 *)temp_r3 + 0xE8);
}

bool hwVoiceInStartup(s32 i) {
    return (*(Slot_803BDA2C * *)&lbl_805D748C)[i].fec == 1;
}

}
