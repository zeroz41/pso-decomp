#ifndef MUSYX_RUNTIME_B_H
#define MUSYX_RUNTIME_B_H

#pragma dont_inline on
#include "types.h"
#include "musyx/musyx.h"
#include <string.h>
#include "musyx/runtime/hw_dspctrl.h"
#include "pso/audio/SoundReverb.h"

struct Rec_803BE528 { u8 data[0x280]; };

struct Hdr_803BD8A8 { u32 f0; u32 info; };

struct Hdr_803BD93C { u32 f0; u32 info; };

extern "C" {
extern s8 salTimeOffset;
void hwSetTimeOffset(s8 arg0);
u8 hwGetTimeOffset(void);
void hwSetMesgCallback(SND_MESSAGE_CALLBACK callback);
void hwSetSRCType(s32 v, u8 salSRCType);
void hwSetPolyPhaseFilter(s32 v, u8 salCoefSel);
void hwSetITDMode(s32 i, u8 mode);
void salDeactivateVoice(DSPvoice *dsp_vptr);
void hwOff(s32 arg0);
void hwTransAddr(void);
void hwFrameDone(void);
extern u32 dspHRTFOn;
void hwDisableHRTF(void);
s32 hwGetVirtualSampleID(s32 arg0);
void aramRemoveData(s32 arg0, s32 arg1);
extern volatile u32 salDspIsDone;
extern volatile u32 salDspInitIsDone;
extern void (*userCallback)(void);
extern volatile u32 salLogicIsWaiting;
extern volatile u32 salLogicActive;
void AIInitDMA(uaddr addr, u32 length);
void AIRegisterDMACallback(void (*)(void));
void salCallback(void);
void dspInitCallback(void);
void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB);
s32 OSDisableInterrupts(void);
void hwIRQEnterCritical(void);
s32 OSRestoreInterrupts(s32 level);
extern volatile s32 oldState;
extern volatile u16 hwIrqLevel;
void hwEnableIrq(void);
s32 OSEnableInterrupts(void);
void hwIRQLeaveCritical(void);
void hwInitIrq(void);
extern u8 salAIBufferIndex;
extern Rec_803BE528 *salAIBufferBase;
Rec_803BE528 *salAiGetDest(void);
void hwDisableIrq(void);
u32 hwIsActive(s32 i);
u16 hwGetSampleID(s32 i);
void hwSetStreamLoopPS(s32 i, u8 v);
extern u32 lbl_805D4630;
u16 sndRand(void);
u8 hwGetSampleType(s32 i);
void hwSetPriority(s32 i, s32 v);
void hwSetVirtualSampleLoopBuffer(s32 voice, uaddr addr, u32 len);
u8 hwGetVirtualSampleState(s32 i);
void hwKeyOff(s32 i);
void salActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);
void hwActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);
uaddr hwGetStreamPlayBuffer(u8 i);
void hwSyncSampleMem(void);
void aramInit(u32 length);
void hwInitSampleMem(void *self, void *p);
void aramFreeStreamBuffer(u8 i);
void hwExitStream(u8 i);
void salDeactivateStudio(u8 i);
void hwDeactivateStudio(u8 i);
u32 hwVoiceInStartup(s32 i);
u8 hwInitStream(u32 size);
void aramSyncTransferQueue(void);
u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void AIStartDMA(void);
void salStartAi(void);
extern s8 salTimeOffset; void salActivateVoice(DSPvoice *dsp_vptr, u8 studio);
void hwStart(s32 voice, u8 studio);
s32 salAddStudioInput(DSPstudioinfo *stp, SND_STUDIO_INPUT *desc);
void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc);
s32 salRemoveStudioInput(DSPstudioinfo *stp, SND_STUDIO_INPUT *desc);
void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc);
extern s16 lbl_804F7168[];
s16 sndSin(s32 angle);
u32 synthGetTicksPerSecond(void *);
void sndConvertTicks(u32 *ticks, saddr seqId);
void hwBreak(s32 i);
void hwSetPitch(s32 i, u16 v);
s32 PPCSync();
s32 salBuildCommandList(void *, int);
extern u16 dspCmdFirstSize;
extern u16 *dspCmdList;
void salCtrlDsp(saddr dest);
extern volatile u32 salLastTick;
u32 salGetStartDelay(void);
typedef struct SND_HOOKS {
    void *(*malloc)(u32 addr);
    void (*free)(void *addr);
} SND_HOOKS;
extern SND_HOOKS salHooks;
f32* salMalloc(s32 bytes);
void salFree(saddr arg0);
u32 hwGetPos(s32 arg0);
void DCStoreRange(void *addr, u32 nBytes);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 i, void *cb, void *arg);
void hwSaveSample(Hdr_803BD8A8 **header, uaddr *data);
void hwRemoveSample(Hdr_803BD93C *arg0, u32 arg1);
u32 salInitAi(void (*callback)(void), u32 unk, u32 *outFreq);
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, bool defaultStudioDPL2);
u32 salInitDsp(u32 flags);
void snd_handle_irq(void);
extern u8 salAuxFrame;
extern u8 salFrame;
extern u8 salNumVoices;
extern u8 sndActive;
void seqHandle(s32);
void synthHandle(s32);
void streamHandle(void);
void streamCorrectLoops(void);
void vsSampleUpdates(void);
void salHandleAuxProcessing(void);
void s3dHandle(void);
s32 hwInit(uaddr frq, s32 numVoices, s32 numStudios, u32 flags);
void DCFlushRange(void *addr, u32 nBytes);
s32 aramStoreData(u8 *src, u32 size);
u8 aramAllocateStreamBuffer(u32 len);
void hwInitSamplePlayback(s32 n, s16 smpID, SAMPLE_INFO *newsmp, u32 set_defadsr, s32 prio, s32 callbackUserValue, u32 setSRC, u8 itdMode);
u16 adsrConvertTimeCents(s32);
extern u8 dspScale2IndexTab[];
void hwSetADSR(s32 n, void *_adsr, u8 mode);
void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg);
void salCalcVolume(u8 voltab_index, SAL_VOLINFO *vi, f32 vol, u32 pan, u32 span, f32 auxa, f32 auxb, u32 itd, u32 dpl2);
extern u32 synthInfo[];
u32 hwFrq2Pitch(u32 frq);
void sndSetHooks(SND_HOOKS *hooks);
void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
}

extern "C" {

void sndConvertMs(s32 *time);
u32 sndConvert2Ms(u32 time);

}

extern "C" {
void hwSetVolume(s32 v, u8 table, u32 pan, s32 span, f32 vol, f32 auxa, f32 auxb);
void aramFreeStreamBuffer(u8 id);
void dspResumeCallback(void);
}

#endif
