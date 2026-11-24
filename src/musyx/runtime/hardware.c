#include <dolphin/os/OSCache.h>
#include "musyx/runtime/musyx_internal.h"
#pragma bool off

extern "C" {

s8 salTimeOffset;
SND_HOOKS salHooks;
u8 salMaxStudioNum;
u8 salNumVoices;
u8 salAuxFrame;
u8 salFrame;

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
    salCtrlDsp((saddr)salAiGetDest());
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    salHandleAuxProcessing();
    hwIRQLeaveCritical();
    hwIRQEnterCritical();
    salFrame ^= 1;
    salAuxFrame = (salAuxFrame + 1) % 3;
    for (v = 0; v < salNumVoices; ++v) {
        for (i = 0; i < 5; ++i) {
            dspVoice[v].changed[i] = 0;
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

s32 hwInit(u32 *frq, s32 numVoices, s32 numStudios, u32 flags) {
    hwInitIrq();
    salFrame = 0;
    salAuxFrame = 0;
    salMessageCallback = NULL;
    if (salInitAi(snd_handle_irq, flags, frq) != 0 &&
        salInitDspCtrl(numVoices, numStudios, (flags & 1) != 0) != 0 &&
        salInitDsp(flags) != 0) {
        hwEnableIrq();
        salStartAi();
        return 0;
    }
    return -1;
}

void hwSetTimeOffset(s8 offset) {
    salTimeOffset = offset;
}
u8 hwGetTimeOffset(void) {
    return (u8)salTimeOffset;
}

u32 hwIsActive(s32 v) {
    return dspVoice[v].state != 0;
}

void hwSetMesgCallback(SND_MESSAGE_CALLBACK callback) {
    salMessageCallback = callback;
}

void hwSetPriority(s32 v, s32 prio) {
    dspVoice[v].prio = prio;
}

void hwInitSamplePlayback(s32 v, u16 smpID, SAMPLE_INFO *newsmp, u32 set_defadsr, s32 prio, s32 callbackUserValue, u32 setSRC, u8 itdMode) {
    u8 i;
    s32 flags = 0;
    for (i = 0; i <= (u8)salTimeOffset; i++) {
        flags |= dspVoice[v].changed[i] & 0x20;
        dspVoice[v].changed[i] = 0;
    }
    dspVoice[v].changed[0] = flags;
    dspVoice[v].prio = prio;
    dspVoice[v].mesgCallBackUserValue = callbackUserValue;
    dspVoice[v].flags = 0;
    dspVoice[v].smp_id = smpID;
    dspVoice[v].smp_info = *newsmp;
    if (set_defadsr != 0) {
        dspVoice[v].adsr.mode = 0;
        dspVoice[v].adsr.data.linear.aTime = 0;
        dspVoice[v].adsr.data.linear.dTime = 0;
        dspVoice[v].adsr.data.linear.sLevel = 0x7FFF;
        dspVoice[v].adsr.data.linear.rTime = 0;
    }
    dspVoice[v].lastUpdate.pitch = 0xFF;
    dspVoice[v].lastUpdate.vol = 0xFF;
    dspVoice[v].lastUpdate.volA = 0xFF;
    dspVoice[v].lastUpdate.volB = 0xFF;
    if (setSRC != 0) {
        hwSetSRCType(v, 0);
        hwSetPolyPhaseFilter(v, 1);
    }
    hwSetITDMode(v, itdMode);
}

void hwBreak(s32 vid) {
    if (dspVoice[vid].state == 1 && (u8)salTimeOffset == 0) {
        dspVoice[vid].startupBreak = 1;
    }
    dspVoice[vid].changed[(u8)salTimeOffset] |= 0x20;
}

void hwSetADSR(s32 v, void *_adsr, u8 mode) {
    u32 sl;
    ADSR_INFO *adsr = (ADSR_INFO *)_adsr;
    switch (mode) {
    case 0:
        dspVoice[v].adsr.mode = 0;
        dspVoice[v].adsr.data.linear.aTime = adsr->data.linear.atime;
        dspVoice[v].adsr.data.linear.dTime = adsr->data.linear.dtime;
        if ((sl = adsr->data.linear.slevel << 3) > 0x7FFF) {
            sl = 0x7FFF;
        }
        dspVoice[v].adsr.data.linear.sLevel = sl;
        dspVoice[v].adsr.data.linear.rTime = adsr->data.linear.rtime;
        break;
    case 1:
    case 2:
        dspVoice[v].adsr.mode = 1;
        dspVoice[v].adsr.data.dls.aMode = 0;
        if (mode == 1) {
            dspVoice[v].adsr.data.dls.aTime = adsrConvertTimeCents(adsr->data.dls.atime) & 0xFFFF;
            dspVoice[v].adsr.data.dls.dTime = adsrConvertTimeCents(adsr->data.dls.dtime) & 0xFFFF;
            if ((sl = adsr->data.dls.slevel >> 2) > 0x3FF) {
                sl = 0x3FF;
            }
            dspVoice[v].adsr.data.dls.sLevel = 0xC1 - dspScale2IndexTab[sl];
        } else {
            dspVoice[v].adsr.data.dls.aTime = (u16)adsr->data.dls.atime;
            dspVoice[v].adsr.data.dls.dTime = (u16)adsr->data.dls.dtime;
            dspVoice[v].adsr.data.dls.sLevel = adsr->data.dls.slevel;
        }
        dspVoice[v].adsr.data.dls.rTime = adsr->data.dls.rtime;
        break;
    }
    dspVoice[v].changed[0] |= 0x10;
}

void hwSetVirtualSampleLoopBuffer(s32 voice, uaddr addr, u32 len) {
    dspVoice[voice].vSampleInfo.loopBufferAddr = (void *)addr;
    dspVoice[voice].vSampleInfo.loopBufferLength = len;
}

u32 hwGetVirtualSampleState(s32 voice) {
    return dspVoice[voice].vSampleInfo.inLoopBuffer;
}

u8 hwGetSampleType(s32 voice) {
    return dspVoice[voice].smp_info.compType;
}

u16 hwGetSampleID(s32 voice) {
    return dspVoice[voice].smp_id;
}

void hwSetStreamLoopPS(s32 voice, u8 ps) {
    dspVoice[voice].streamLoopPS = ps;
}

void hwStart(s32 v, u8 studio) {
    dspVoice[v].singleOffset = salTimeOffset;
    salActivateVoice(&dspVoice[v], studio);
}

void hwKeyOff(s32 v) {
    dspVoice[v].changed[(u8)salTimeOffset] |= 0x40;
}

void hwSetPitch(s32 v, u16 speed) {
    DSPvoice *dsp_vptr = &dspVoice[v];
    if (speed >= 0x4000U) {
        speed = 0x3FFF;
    }
    if (dsp_vptr->lastUpdate.pitch == 0xFF || dsp_vptr->pitch[dsp_vptr->lastUpdate.pitch] != (u32)((speed * 0x10) & 0xFFFF0)) {
        dsp_vptr->pitch[(u8)salTimeOffset] = (speed * 0x10) & 0xFFFF0;
        dsp_vptr->changed[(u8)salTimeOffset] |= 8;
        dsp_vptr->lastUpdate.pitch = salTimeOffset;
    }
}

void hwSetSRCType(s32 v, u8 salSRCType) {
    DSPvoice *dsp_vptr = &dspVoice[v];
    dsp_vptr->srcTypeSelect = lbl_805D4638[salSRCType];
    dsp_vptr->changed[0] |= 0x100;
}
void hwSetPolyPhaseFilter(s32 v, u8 salCoefSel) {
    DSPvoice *dsp_vptr = &dspVoice[v];
    dsp_vptr->srcCoefSelect = lbl_805D4640[salCoefSel];
    dsp_vptr->changed[0] |= 0x80;
}

void hwSetITDMode(s32 v, u8 mode) {
    if (mode == 0) {
        dspVoice[v].flags |= 0x80000000;
        dspVoice[v].itdShiftL = 0x10;
        dspVoice[v].itdShiftR = 0x10;
        return;
    }
    dspVoice[v].flags &= 0x7FFFFFFF;
}

void hwSetVolume(s32 v, u8 table, f32 vol, u32 pan, s32 span, f32 auxa, f32 auxb) {
    DSPvoice *dsp_vptr = &dspVoice[v];
    SAL_VOLINFO vi;
    s32 il, ir, is;
    if (vol >= 1.0f) vol = 1.0f;
    if (auxa >= 1.0f) auxa = 1.0f;
    if (auxb >= 1.0f) auxb = 1.0f;
    salCalcVolume(table, &vi, vol, pan, span, auxa, auxb, (dsp_vptr->flags & 0x80000000) != 0,
        dspStudio[dsp_vptr->studio].type == SND_STUDIO_TYPE_DPL2);
    il = 32767.0f * vi.volL;
    ir = 32767.0f * vi.volR;
    is = 32767.0f * vi.volS;
    if (dsp_vptr->lastUpdate.vol == 0xFF || dsp_vptr->volL != (u16)il || dsp_vptr->volR != (u16)ir || dsp_vptr->volS != (u16)is) {
        dsp_vptr->volL = il;
        dsp_vptr->volR = ir;
        dsp_vptr->volS = is;
        dsp_vptr->changed[0] |= 1;
        dsp_vptr->lastUpdate.vol = 0;
    }
    il = 32767.0f * vi.volAuxAL;
    ir = 32767.0f * vi.volAuxAR;
    is = 32767.0f * vi.volAuxAS;
    if (dsp_vptr->lastUpdate.volA == 0xFF || dsp_vptr->volLa != (u16)il || dsp_vptr->volRa != (u16)ir || dsp_vptr->volSa != (u16)is) {
        dsp_vptr->volLa = il;
        dsp_vptr->volRa = ir;
        dsp_vptr->volSa = is;
        dsp_vptr->changed[0] |= 2;
        dsp_vptr->lastUpdate.volA = 0;
    }
    il = 32767.0f * vi.volAuxBL;
    ir = 32767.0f * vi.volAuxBR;
    is = 32767.0f * vi.volAuxBS;
    if (dsp_vptr->lastUpdate.volB == 0xFF || dsp_vptr->volLb != (u16)il || dsp_vptr->volRb != (u16)ir || dsp_vptr->volSb != (u16)is) {
        dsp_vptr->volLb = il;
        dsp_vptr->volRb = ir;
        dsp_vptr->volSb = is;
        dsp_vptr->changed[0] |= 4;
        dsp_vptr->lastUpdate.volB = 0;
    }
    if (dsp_vptr->flags & 0x80000000) {
        const u16 *itd = &lbl_8047C420[(u8)(pan >> 16)];
        dsp_vptr->itdShiftL = *itd;
        dsp_vptr->itdShiftR = 0x20 - *itd;
        dsp_vptr->changed[0] |= 0x200;
    }
}

void hwOff(s32 vid) {
    salDeactivateVoice(&dspVoice[vid]);
}

void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB) {
    dspStudio[studio].auxAHandler = auxA;
    dspStudio[studio].auxAUser = userA;
    dspStudio[studio].auxBHandler = auxB;
    dspStudio[studio].auxBUser = userB;
}

void hwActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type) {
    salActivateStudio(studio, isMaster, type);
}

void hwDeactivateStudio(u8 studio) {
    salDeactivateStudio(studio);
}

void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc) {
    salAddStudioInput(&dspStudio[studio], in_desc);
}

void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc) {
    salRemoveStudioInput(&dspStudio[studio], in_desc);
}


u32 hwGetPos(s32 v) {
    u32 pos;
    u32 off;
    if (dspVoice[v].state != 2) {
        return 0;
    }
    switch (dspVoice[v].smp_info.compType) {
    case 0:
    case 1:
    case 4:
    case 5:
        pos = ((dspVoice[v].currentAddr - (uaddr)dspVoice[v].smp_info.addr * 2) >> 4) * 14;
        off = dspVoice[v].currentAddr & 0xF;
        if (off >= 2) {
            pos = pos + (off - 2);
        }
        break;
    case 3:
        pos = dspVoice[v].currentAddr - (uaddr)dspVoice[v].smp_info.addr;
        break;
    case 2:
        pos = dspVoice[v].currentAddr - ((uaddr)dspVoice[v].smp_info.addr >> 1);
        break;
    }
    return pos;
}

void hwFlushStream(u8 *base, u32 offset, u32 len, u8 hwStreamHandle, void *cb, void *arg) {
    u32 sp20[2];
    u32 addr;
    u8 *p;
    addr = aramGetStreamBufferAddress(hwStreamHandle, sp20);
    len += offset & 0x1F;
    offset &= ~0x1F;
    len = (len + 0x1F) & ~0x1F;
    p = base + offset;
    DCStoreRange(p, len);
    aramUploadData((u8 *)(p), (u32)(addr + offset), (u32)(len), (s32)(1), (void *)(cb), (void *)(arg));
}

u8 hwInitStream(u32 size) {
    return aramAllocateStreamBuffer(size);
}

void hwExitStream(u8 id) {
    aramFreeStreamBuffer(id);
}

uaddr hwGetStreamPlayBuffer(u8 hwStreamHandle) {
    return aramGetStreamBufferAddress(hwStreamHandle, (u32 *)(0));
}

void *hwTransAddr(void *samples) {
    return samples;
}

u32 hwFrq2Pitch(u32 frq) {
    return (u32)(4096.0f * (f32)frq / (f32)synthInfo.mixFrq);
}

void hwInitSampleMem(void *self, void *p) {
    aramInit((uaddr)p);
}

void hwSaveSample(SynthSampleHeader **header, uaddr *data) {
    u32 info = (*header)->length;
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
    r = aramStoreData((u8 *)*data, n);
    *data = r;
}

void hwRemoveSample(SynthSampleHeader *header, u32 data) {
    u32 info = header->length;
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
    aramRemoveData(data, n);
}

void hwSyncSampleMem(void) {
    aramSyncTransferQueue();
}

void hwFrameDone(void) {
}

void sndSetHooks(SND_HOOKS *hooks) {
    salHooks = *hooks;
}

void hwDisableHRTF(void) {
    dspHRTFOn = 0;
}
s32 hwGetVirtualSampleID(s32 voice) {
    if (dspVoice[voice].state == 0) {
        return -1;
    }
    return dspVoice[voice].virtualSampleID;
}

u32 hwVoiceInStartup(s32 v) {
    return dspVoice[v].state == 1;
}

}
