#include "musyx/runtime/musyx_runtime_b.h"
#include <dolphin/dsp.h>

extern "C" {

#define OSCachedToPhysical(caddr) ((uaddr)((u8 *)(caddr) - 0x80000000))
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
static inline void callUserCallback_803BE320(void) {
    if (salLogicActive) {
        return;
    }
    salLogicActive = 1;
    OSEnableInterrupts();

    userCallback();
    OSDisableInterrupts();

    salLogicActive = 0;
}

void salCallback(void) {
    salAIBufferIndex = (salAIBufferIndex + 1) % 4;
    AIInitDMA(OSCachedToPhysical(salAIBufferBase) + (salAIBufferIndex * 0x280), 0x280);
    salLastTick = OSGetTick();

    if (salDspIsDone) {
        callUserCallback_803BE320();
    } else {
        salLogicIsWaiting = 1;
    }
}

void dspInitCallback(void) {
    salDspIsDone = 1;
    salDspInitIsDone = 1;
}

void dspResumeCallback(void) {
    u8 _[8];

    salDspIsDone = 1;
    if (salLogicIsWaiting) {
        salLogicIsWaiting = 0;
        callUserCallback_803BE320();
    }
}

u32 salInitAi(void (*callback)(void), u32 unk, u32 *outFreq) {
    if ((salAIBufferBase = (Rec_803BE528 *)salMalloc(0x280 * 4)) != 0) {
        memset(salAIBufferBase, 0, 0x280 * 4);
        DCFlushRange(salAIBufferBase, 0x280 * 4);
        salAIBufferIndex = 1;
        salLogicIsWaiting = 0;
        salDspIsDone = 1;
        salLogicActive = 0;
        userCallback = callback;
        AIRegisterDMACallback(salCallback);
        AIInitDMA(OSCachedToPhysical(salAIBufferBase) + (salAIBufferIndex * 0x280), 0x280);
        synthInfo[1] = 0x20;
        *outFreq = 32000;
        return 1;
    }

    return 0;
}
#pragma pop

void salStartAi(void) {
    AIStartDMA();
}

Rec_803BE528 *salAiGetDest(void) {
    return &salAIBufferBase[(u8)((salAIBufferIndex + 2) % 4)];
}

extern u8 dspSlave[];
extern u16 dspSlaveLength;

static DSPTaskInfo dsp_task __attribute__((aligned(8)));
static u16 dram_image[4096] __attribute__((aligned(32)));


u32 salInitDsp(u32 flags) {
    dsp_task.iram_mmem_addr = (u16 *)dspSlave;
    dsp_task.iram_length = dspSlaveLength;
    dsp_task.iram_addr = 0;
    dsp_task.dram_mmem_addr = (u16 *)dram_image;
    dsp_task.dram_length = 0x2000;
    dsp_task.dram_addr = 0;
    dsp_task.dsp_init_vector = 0x10;
    dsp_task.dsp_resume_vector = 0x30;
    dsp_task.init_cb = (DSPCallback)dspInitCallback;
    dsp_task.res_cb = (DSPCallback)dspResumeCallback;
    dsp_task.done_cb = 0;
    dsp_task.req_cb = 0;
    dsp_task.priority = 0;
    DSPInit();
    DSPAddTask(&dsp_task);
    salDspInitIsDone = 0;
    hwEnableIrq();
    while (!salDspInitIsDone)
        ;
    hwDisableIrq();
    return 1;
}


void salCtrlDsp(saddr dest) {
    u16 *mail;
    salBuildCommandList((void *) (dest), (int) (salGetStartDelay()));
    mail = dspCmdList;
    salDspIsDone = 0;
    PPCSync();
    DSPSendMailToDSP(dspCmdFirstSize | 0xBABE0000);
    do {
    } while (DSPCheckMailToDSP() != 0U);
    DSPSendMailToDSP((uaddr)mail);
    do {
    } while (DSPCheckMailToDSP() != 0U);
}

u32 salGetStartDelay(void) {
    return (u32)((OSGetTick() - salLastTick) * 8) / (*(u32 *)0x800000F8 / 4 / 125000);
}

void hwInitIrq(void) {
    oldState = OSDisableInterrupts();
    hwIrqLevel = 1;
}

void hwEnableIrq(void) {
    if (--hwIrqLevel == 0) {
        OSRestoreInterrupts(oldState);
    }
}

void hwDisableIrq(void) {
    if (hwIrqLevel++ == 0) {
        oldState = OSDisableInterrupts();
    }
}

void hwIRQEnterCritical(void) {
    OSDisableInterrupts();
}

void hwIRQLeaveCritical(void) {
    OSEnableInterrupts();
}

void (*userCallback)(void);
Rec_803BE528 *salAIBufferBase;
volatile u32 salDspIsDone;
volatile u32 salLogicIsWaiting;
volatile u32 salLogicActive;
volatile u32 salLastTick;
volatile u32 salDspInitIsDone;
volatile u16 hwIrqLevel;
volatile s32 oldState;
u8 salAIBufferIndex;

}
