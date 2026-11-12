#include "musyx/runtime/musyx_runtime_b.h"

#define synthInfo_voiceNum (((u8 *)synthInfo)[0x210])
#define CLAMP(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define CLAMP_INV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define SLOTS_803BD694 (*(Slot_803BD694 **)&lbl_805D748C)
extern "C" {

#define userCallback lbl_805D74E8
#define salAIBufferBase lbl_805D74EC
#define salDspIsDone (*(volatile u32 *)&lbl_805D74F0)
#define salLogicIsWaiting (*(volatile u32 *)&lbl_805D74F4)
#define salLogicActive (*(volatile u32 *)&lbl_805D74F8)
#define salLastTick (*(volatile u32 *)&lbl_805D74FC)
#define salAIBufferIndex lbl_805D750C
#define OSCachedToPhysical(caddr) ((u32)((u8 *)(caddr) - 0x80000000))
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
    lbl_805D74F0 = 1;
    lbl_805D7500 = 1;
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
    return &lbl_805D74EC[(u8)((lbl_805D750C + 2) % 4)];
}

typedef struct DSPTaskInfo_803BE554 {
    u32 state;
    u32 priority;
    u32 flags;
    u16 *iram_mmem_addr;
    u32 iram_length;
    u32 iram_addr;
    u16 *dram_mmem_addr;
    u32 dram_length;
    u32 dram_addr;
    u16 dsp_init_vector;
    u16 dsp_resume_vector;
    void (*init_cb)(void *);
    void (*res_cb)(void *);
    void (*done_cb)(void *);
    void (*req_cb)(void *);
    DSPTaskInfo_803BE554 *next;
    DSPTaskInfo_803BE554 *prev;
    s64 t_context;
    s64 t_task;
} DSPTaskInfo_803BE554;

void DSPInit(void);
void DSPAddTask(void *);
extern u8 dspSlave[];
extern u16 dspSlaveLength;

static DSPTaskInfo_803BE554 dsp_task_803BE554 __attribute__((aligned(8)));
static u16 dram_image_803BE554[4096] __attribute__((aligned(32)));

#define dsp_task dsp_task_803BE554
#define dram_image dram_image_803BE554
#define salDspInitIsDone (*(volatile u32 *)&lbl_805D7500)

u32 salInitDsp(u32 flags) {
    dsp_task.iram_mmem_addr = (u16 *)dspSlave;
    dsp_task.iram_length = dspSlaveLength;
    dsp_task.iram_addr = 0;
    dsp_task.dram_mmem_addr = (u16 *)dram_image;
    dsp_task.dram_length = 0x2000;
    dsp_task.dram_addr = 0;
    dsp_task.dsp_init_vector = 0x10;
    dsp_task.dsp_resume_vector = 0x30;
    dsp_task.init_cb = (void (*)(void *))dspInitCallback;
    dsp_task.res_cb = (void (*)(void *))dspResumeCallback;
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

#undef dsp_task
#undef dram_image
#undef salDspInitIsDone

void salCtrlDsp(s32 arg0) {
    s32 temp_r31;
    salBuildCommandList((void *) (arg0), (int) (salGetStartDelay()));
    temp_r31 = lbl_805D7478;
    lbl_805D74F0 = 0;
    PPCSync();
    DSPSendMailToDSP((void *) (lbl_805D7474 | 0xBABE0000));
    do {
    } while (DSPCheckMailToDSP() != 0U);
    DSPSendMailToDSP((void *) (temp_r31));
    do {
    } while (DSPCheckMailToDSP() != 0U);
}

u32 salGetStartDelay(void) {
    return (u32)((OSGetTick() - lbl_805D74FC) * 8) / (*(u32 *)0x800000F8 / 4 / 125000);
}

#pragma push
#pragma scheduling off
void hwInitIrq(void) {
    lbl_805D7508 = OSDisableInterrupts();
    lbl_805D7504 = 1;
}
#pragma pop

void hwEnableIrq(void) {
    if (--lbl_805D7504 == 0) {
        OSRestoreInterrupts(lbl_805D7508);
    }
}

void hwDisableIrq(void) {
    if (lbl_805D7504++ == 0) {
        lbl_805D7508 = OSDisableInterrupts();
    }
}

void hwIRQEnterCritical(void) {
    OSDisableInterrupts();
}

void hwIRQLeaveCritical(void) {
    OSEnableInterrupts();
}

void (*lbl_805D74E8)(void);
Rec_803BE528 *lbl_805D74EC;
s32 lbl_805D74F0;
s32 lbl_805D74F4;
s32 lbl_805D74F8;
s32 lbl_805D74FC;
s32 lbl_805D7500;
u16 lbl_805D7504;
s32 lbl_805D7508;
u8 lbl_805D750C;

}
