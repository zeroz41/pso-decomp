#ifndef MUSYX_RUNTIME_B_H
#define MUSYX_RUNTIME_B_H

#pragma dont_inline on
#include "types.h"
#include "musyx/musyx.h"
#include <string.h>
#include "musyx/runtime/hw_dspctrl.h"
#include "pso/audio/SoundReverb.h"

struct Rec_803BE528 { u8 data[0x280]; };

struct Ent_803BB8F0 { u8 code; u8 flags; u8 pad[2]; s32 val; };

struct Obj_803BB8F0 { Ent_803BB8F0 ents[4]; u8 pad20[2]; u8 count; };

struct Obj_803BC7E4 { u8 pad[0x121]; u8 b121; u8 b122; u8 pad123[0x1C4 - 0x123]; s16 v1c4; u8 pad1c6[0x1D0 - 0x1C6]; s16 v1d0; };

struct Obj_803BC884 { u8 pad[0x121]; u8 b121; u8 b122; };

struct Hdr_803BD8A8 { u32 f0; u32 info; };

struct Hdr_803BD93C { u32 f0; u32 info; };

typedef struct S_803BF408 {
    u8 pad0[0x1A8];
    f32 f1A8;
    u8 pad1AC[0x1C4 - 0x1AC];
    u8 disabled;
} S_803BF408;

struct Src_803BF884 {
    s32 *dest;
    s32 *smpBase;
    s32 *old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
};

struct Work_803BF884 {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 currentPosLo;
    u32 currentPosHi;
    s32 pitchOffset;
    u32 pitchOffsetPeriodCount;
    u32 pitchOffsetPeriod;
    Src_803BF884 src;
};

typedef struct CTRL_SOURCE {
    u8 midiCtrl;
    u8 combine;
    s32 scale;
} CTRL_SOURCE;

typedef struct CTRL_DEST {
    CTRL_SOURCE source[4];
    u16 oldValue;
    u8 numSource;
} CTRL_DEST;

typedef struct SYNTH_LFO {
    u32 time;
    u32 period;
    s16 value;
    s16 lastValue;
} SYNTH_LFO;

typedef struct SYNTH_VOICE {
    u8 pad_0[0x90];
    u64 time;
    u8 pad_98[0xA8 - 0x98];
    u8 timeUsedByInput;
    u8 pad_a9[0x121 - 0xA9];
    u8 midi;
    u8 midiSet;
    u8 pad_123[0x12F - 0x123];
    u8 b12F;
    u8 pad_130[0x158 - 0x130];
    u32 w158;
    u8 pad_15c[0x1BC - 0x15C];
    SYNTH_LFO lfo[2];
    u8 lfoUsedByInput[2];
    u8 pad_1d6[0x214 - 0x1D6];
    u32 midiDirtyFlags;
    CTRL_DEST inpVolume;
    CTRL_DEST inpPanning;
    CTRL_DEST inpSurroundPanning;
    CTRL_DEST inpPitchBend;
    CTRL_DEST inpDoppler;
    CTRL_DEST inpModulation;
    CTRL_DEST inpPedal;
    CTRL_DEST inpPortamento;
    CTRL_DEST inpPreAuxA;
    CTRL_DEST inpReverb;
    CTRL_DEST inpPreAuxB;
    CTRL_DEST inpPostAuxB;
    CTRL_DEST inpTremolo;
} SYNTH_VOICE;

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
u8 inpTranslateExCtrl(u8 arg0);
s32 OSDisableInterrupts(void);
void hwIRQEnterCritical(void);
s32 OSRestoreInterrupts(s32 level);
extern volatile s32 oldState;
extern volatile u16 hwIrqLevel;
void hwEnableIrq(void);
s32 ReverbHICreate(SoundReverb *self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
s32 OSEnableInterrupts(void);
void hwIRQLeaveCritical(void);
void hwInitIrq(void);
extern u8 salAIBufferIndex;
extern Rec_803BE528 *salAIBufferBase;
Rec_803BE528 *salAiGetDest(void);
void hwDisableIrq(void);
struct ChannelDefaults_803BADF8 { u8 pbRange; };
struct SynthVoice_803BADF8 {
    u8 pad0[0xF4];
    u32 id;
    u8 padF8[0x121 - 0xF8];
    u8 midi;
    u8 midiSet;
    u8 pad123[0x1D6 - 0x123];
    u8 pbLowerKeyRange;
    u8 pbUpperKeyRange;
    u8 pad1D8[0x214 - 0x1D8];
    u32 midiDirtyFlags;
    u8 pad218[0x404 - 0x218];
};
extern SynthVoice_803BADF8 *synthVoice;
void synthKeyStateUpdate(SynthVoice_803BADF8 *svoice);
void inpFXCopyCtrl(u8 ctrl, SynthVoice_803BADF8 *dvoice, SynthVoice_803BADF8 *svoice);
#define lbl_8056E098 ((u8 (*)[16])inpChannelDefaults)
#define lbl_8056E118 ((u8 *)inpFXChannelDefaults)
u8 *inpGetChannelDefaults(u8 a, u8 b);
extern CTRL_DEST inpAuxB[8][4];
extern CTRL_DEST inpAuxA[8][4];
extern u32 lbl_804F7120[];
extern u32 lbl_804F7130[];
void inpSetGlobalMIDIDirtyFlag(u8 a, u8 b, u32 v);
bool hwIsActive(s32 i);
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
bool hwVoiceInStartup(s32 i);
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
void inpResetChannelDefaults(u8 arg0, u8 arg1);
void inpSetMidiLastNote(u8 arg0, u8 arg1, u8 arg2);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
u16 inpGetVolume(SYNTH_VOICE *svoice);
u16 inpGetPanning(SYNTH_VOICE *svoice);
u16 inpGetSurPanning(SYNTH_VOICE *svoice);
u16 inpGetPitchBend(SYNTH_VOICE *svoice);
u16 inpGetDoppler(SYNTH_VOICE *svoice);
u16 inpGetModulation(SYNTH_VOICE *svoice);
u16 inpGetPedal(SYNTH_VOICE *svoice);
u16 inpGetPreAuxA(SYNTH_VOICE *svoice);
u16 inpGetReverb(SYNTH_VOICE *svoice);
u16 inpGetPreAuxB(SYNTH_VOICE *svoice);
u16 inpGetPostAuxB(SYNTH_VOICE *svoice);
u16 inpGetTremolo(SYNTH_VOICE *svoice);
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
void inpAddCtrl(Obj_803BB8F0 *ch, u8 arg1, s32 arg2, u8 x, u32 arg4);
u16 inpGetMidiCtrl(u8 arg0, u8 channel, u8 set);
u16 inpGetExCtrl(Obj_803BC7E4 *arg0, u8 arg1);
void inpSetExCtrl(Obj_803BC884 *svoice, u8 arg1, s16 arg2);
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
void DoCrossTalk(void *, void *, f32, f32);
void HandleReverb(void *, void *, int);
void ReverbHICallback(void *sptr, void *arg1, void *arg2, S_803BF408 *rv);
void salCalcVolume(u8 voltab_index, SAL_VOLINFO *vi, f32 vol, u32 pan, u32 span, f32 auxa, f32 auxb, u32 itd, u32 dpl2);
void do_src1(void *);
void do_src2(void *);
extern u32 synthInfo[];
u32 hwFrq2Pitch(u32 frq);
void sndSetHooks(SND_HOOKS *hooks);
s16 varGet(SYNTH_VOICE *, u32, u32);
extern u64 synthRealTime;
u16 _GetInputValue(SYNTH_VOICE *svoice, CTRL_DEST *inp, u8 midi, u8 midiSet);
void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
}

extern "C" {

void sndConvertMs(s32 *time);
u32 sndConvert2Ms(u32 time);
extern "C" {
f32 powf(f32, f32);
}

typedef struct ChorusSrcInfo_803BFBF0 {
    s32 *dest;
    s32 *smpBase;
    s32 *old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
    u32 trigger;
    u32 target;
} ChorusSrcInfo_803BFBF0;

typedef struct ChorusWork_803BFBF0 {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 currentPosLo;
    u32 currentPosHi;
    s32 pitchOffset;
    u32 pitchOffsetPeriodCount;
    u32 pitchOffsetPeriod;
    ChorusSrcInfo_803BFBF0 src;
} ChorusWork_803BFBF0;

typedef struct AuxChorus_803BFBF0 {
    ChorusWork_803BFBF0 work;
    u32 baseDelay;
    u32 variation;
    u32 period;
} AuxChorus_803BFBF0;

}

extern "C" {
void inpResetMidiCtrl(u8 midi, u8 midiSet, u32 arg2);
u16 inpGetMidiCtrl(u8 ctrl, u8 channel, u8 set);
u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet);
u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet);
void inpInit(SYNTH_VOICE *svoice);
void hwSetVolume(s32 v, u8 table, u32 pan, s32 span, f32 vol, f32 auxa, f32 auxb);
void aramFreeStreamBuffer(u8 id);
void dspResumeCallback(void);
s32 ReverbHICreate(SoundReverb * rv, float coloration, float time, float mix, float damping, float preDelay, float crossTalk);
u32 sndAuxCallbackPrepareChorus(AuxChorus_803BFBF0 *chorus);
}

#endif
