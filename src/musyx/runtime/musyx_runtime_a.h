#ifndef MUSYX_RUNTIME_A_H
#define MUSYX_RUNTIME_A_H

#include "types.h"
#include "musyx/musyx.h"
#include <string.h>
#include "musyx/runtime/musyx_dspvoice.h"

struct Ent_803B89B4 { u8 pad0[0xC]; Ent_803B89B4 *next; Ent_803B89B4 *prev; u8 pad14[0xD8]; u8 active; u8 padED[2]; u8 idx; };
typedef struct DSPhostDPop_SV { s32 l; s32 r; s32 s; s32 lA; s32 rA; s32 sA; s32 lB; s32 rB; s32 sB; } DSPhostDPop_SV;
struct Rec_803B59E4 {
    void *spb;
    DSPhostDPop_SV hostDPopSum;
    s32 *main[2];
    s32 *auxA[3];
    s32 *auxB[3];
    union { void *voiceRoot; Ent_803B89B4 *head; };
    void *alienVoiceRoot;
    union { u8 state; u8 f50; };
    u8 isMaster;
    u8 numInputs;
    u32 type;
    u8 in[0x54];
    void *auxAHandler;
    void *auxBHandler;
    u8 padB4[0xBC - 0xB4];
};

struct Envelope_803B431C {
    u8 mode, phase, pad[2];
    u32 remaining, level, logLevel;
    s32 step;
    u32 attack, decay;
    u16 sustain, pad2;
    u32 release;
};

typedef struct SynthInfo_SV { u32 mixFrq; u32 numSamples; struct { u32 frq; u8 stereo; u8 bits; s8 deviceName[256]; s8 versionText[256]; } pbInfo; u8 voiceNum; u8 maxMusic; u8 maxSFX; u8 studioNum; } SynthInfo_SV;

extern "C" {
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void synthAddStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void synthRemoveStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
u32 adsrSetup(u8 *arg0);
s32 DCFlushRangeNoSync(void *, int);
void salInitHRTFBuffer(void);
extern s32 (*salMessageCallback)(s32, s32);
s32 salSynthSendMessage(u8 *arg0, s32 arg1);
void s3dInit(s32 flags);
extern Rec_803B59E4 dspStudio[];
void salDeactivateStudio(u8 i);
extern u8 sndActive;
u32 sndFXCheck(u32 id);
s32 adsrRelease(struct Envelope_803B431C *e);
void salDeactivateVoice(Ent_803B89B4 *arg0);
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
extern u8 sndActive;
s32 synthSendKeyOff(int id);
s32 synthSendKeyOff(int id);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 sndPitchUpOne(s32 current);
f32 powf(f32, f32);
u32 adsrConvertTimeCents(s32 arg0);
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern f32 lbl_804F6358[];
extern f32 lbl_804F6558[];
u32 sndGetPitch(u8 note, u32 r);
extern u16 lbl_804F6758[];
s32 salChangeADSRState(void *a0);
s32 salChangeADSRState(void *a0);
extern u16 lbl_804F6758[];
u32 adsrHandle(void *arg0, void *arg1, void *arg2);
void seqInit(void);
void synthInit(u32 mixFrq, u32 numVoices);
void streamInit(void);
void dataInit(void *arg0, void *arg1);
void vsInit(void);
void dataInitStack(void);
void s3dInit(s32 flags);
s32 hwInit(u32 *frq, u32 numVoices, u32 numStudios, u32 flags);
extern u8 sndActive;
extern u8 synthIdleWaitActive;
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
void UpdateRoomDistances(void);
s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void synthDeactivateStudio(u8 studio);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
}

extern "C" {

extern SynthInfo_SV synthInfo;

struct Ent_803B5DB0 {
    u8 pad[0x1C];
    u32 key;
};
struct Ent_803BA228 { u16 id; u8 pad[8]; };
}

extern "C" {

typedef void (*Cb_803B8B40)(s32, s32 *, s32, s32);
struct Voice_803B8B40 {
    u8 pad0[0x30]; s32 bufA[3]; s32 bufB[3]; u8 pad48[8];
    u8 b50; u8 pad51[3]; s32 i54; u8 pad58[0x54];
    Cb_803B8B40 cbA; Cb_803B8B40 cbB; s32 argA; s32 argB;
};
extern u8 salMaxStudioNum;
extern u8 salAuxFrame;
extern u8 salFrame;
void dataInitStack(void);

extern "C" {
extern SynthInfo_SV synthInfo;
}

extern "C" {
extern SynthInfo_SV synthInfo;
}

extern "C" {
extern SynthInfo_SV synthInfo;
}

extern "C" {
extern SynthInfo_SV synthInfo;
}

u32 adsrHandleLowPrecision(void *pitchADSR, void *arg1, void *arg2);

void hwEnableIrq(void);
void hwDisableIrq(void);

extern f32 dspDLSVolTab[];

extern void (*synthMessageCallback)(u32, s32);

extern "C" {

}

typedef struct ADSR_VARS_803B41C8 {
    u8 mode;
    u8 state;
    u32 cnt;
    s32 currentVolume;
    s32 currentIndex;
    s32 currentDelta;
    union data_803B41C8 {
        struct _dls_803B41C8 {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
            u16 cutOff;
            u8 aMode;
        } dls;
    } data;
} ADSR_VARS_803B41C8;

extern u8 dspScale2IndexTab[];

extern u8 salNumVoices;
extern u32 dspARAMZeroBuffer;
extern u16 *dspCmdList;
extern s32 *dspSurround;
extern void *dspITDBuffer;
extern void *dspHrtfHistoryBuffer;

u32 aramGetZeroBuffer(void);
void *salMalloc(u32 size);
void DCFlushRange(void *, int);
void DCInvalidateRange(void *, int);
void DCStoreRangeNoSync(void *, int);
s32 DCFlushRangeNoSync(void *, int);
void salInitHRTFBuffer(void);
void salActivateStudio(u8 studio, u32 isMaster, u32 type);

typedef struct _PBDPOP_803B5AF8 {
    u16 aL;
    u16 aAuxAL;
    u16 aAuxBL;
    u16 aR;
    u16 aAuxAR;
    u16 aAuxBR;
    u16 aS;
    u16 aAuxAS;
    u16 aAuxBS;
} _PBDPOP_803B5AF8;
typedef struct _PB_803B5AF8 {
    u8 pad0[0xC];
    u16 mixerCtrl;
    u16 state;
    u8 pad10[0x52 - 0x10];
    _PBDPOP_803B5AF8 dpop;
} _PB_803B5AF8;
typedef struct DSPvoice_803B5AF8 {
    _PB_803B5AF8 *pb;
    u8 pad4[0xED - 0x4];
    u8 postBreak;
} DSPvoice_803B5AF8;
typedef struct DSPhostDPop_803B5AF8 {
    s32 l;
    s32 r;
    s32 s;
    s32 lA;
    s32 rA;
    s32 sA;
    s32 lB;
    s32 rB;
    s32 sB;
} DSPhostDPop_803B5AF8;
typedef struct DSPstudioinfo_803B5AF8 {
    void *spb;
    DSPhostDPop_803B5AF8 hostDPopSum;
} DSPstudioinfo_803B5AF8;

struct Ent_803B8910 { u8 pad0[0xC]; Ent_803B8910 *next; Ent_803B8910 *prev; u8 pad14[0x10]; s32 flags; u8 pad28[0xC4]; u8 active; u8 fED; u8 fEE; u8 idx; };

struct FVec_S3D { f32 x; f32 y; f32 z; };
struct FMat_S3D { f32 m[3][3]; f32 t[3]; };
struct Room_S3D {
    Room_S3D *next;
    Room_S3D *prev;
    u32 flags;
    FVec_S3D pos;
    f32 distance;
    u8 studio;
    void (*activateReverb)(u8 studio, void *para);
    void (*deActivateReverb)(u8 studio);
    void *user;
    u32 curMVol;
};

struct Door_S3D {
    Door_S3D *next;
    Door_S3D *prev;
    FVec_S3D pos;
    f32 open;
    f32 dampen;
    u8 fxVol;
    u8 destStudio;
    Room_S3D *a;
    Room_S3D *b;
    u32 flags;
    s16 filterCoef[4];
    SND_STUDIO_INPUT input;
};

struct Listener_S3D {
    Listener_S3D *next;
    Listener_S3D *prev;
    Room_S3D *room;
    u32 flags;
    FVec_S3D pos;
    f32 volPosOff;
    FVec_S3D dir;
    FVec_S3D heading;
    FVec_S3D right;
    FVec_S3D up;
    FMat_S3D mat;
    f32 surroundDisFront;
    f32 surroundDisBack;
    f32 soundSpeed;
    f32 vol;
};

union ParaData_S3D { u8 value7; u16 value14; };
struct Param_S3D { u8 ctrl; ParaData_S3D paraData; };
struct ParaInfo_S3D { u8 numPara; Param_S3D *paraArray; };

struct Emitter_S3D {
    Emitter_S3D *next;
    Emitter_S3D *prev;
    Room_S3D *room;
    ParaInfo_S3D *paraInfo;
    u32 flags;
    FVec_S3D pos;
    FVec_S3D dir;
    f32 maxDis;
    f32 maxVol;
    f32 minVol;
    f32 volPush;
    u32 vid;
    u32 group;
    u16 fxid;
    u8 studio;
    u8 maxVoices;
    u16 VolLevelCnt;
    f32 fade;
};

extern u8 s3dCallCnt;
extern Emitter_S3D *s3dEmitterRoot;
extern Listener_S3D *s3dListenerRoot;
extern Room_S3D *s3dRoomRoot;
extern Door_S3D *s3dDoorRoot;
extern u32 snd_used_studios;
extern u8 snd_base_studio;
extern u8 snd_max_studios;
extern u8 s3dUseMaxVoices;

s32 synthSendKeyOff(int id);
void synthActivateStudio(u8 studio, u32 isMaster, u32 type);
void synthDeactivateStudio(u8 studio);
void UpdateRoomDistances(void);

void salApplyMatrix(void *mat, void *in, void *out);
f32 salNormalizeVector(FVec_S3D *vec);

s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);

struct StartList_S3D {
    StartList_S3D *next;
    f32 vol;
    f32 xPan;
    f32 yPan;
    f32 zPan;
    f32 pitch;
    Emitter_S3D *em;
};

struct RunList_S3D {
    RunList_S3D *next;
    f32 vol;
    Emitter_S3D *em;
};

struct StartGroup_S3D {
    u32 id;
    StartList_S3D *list;
    RunList_S3D *running;
    u16 numRunning;
};
extern u8 startGroupNum;
extern u8 startListNum;
extern u8 runListNum;

void SetFXParameters(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);

s32 synthSendKeyOff(int id);
u32 sndFXCheck(u32 id);
void CheckRoomStatus(void);
void CheckDoorStatus(void);
void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan);
void SetFXParameters(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);
void AddRunningEmitter(Emitter_S3D *em, f32 vol);
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch);
void StartContinousEmitters(void);

}

extern "C" {
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
s32 synthFXSetCtrl(u32 vid, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 vid, u8 ctrl, u16 value);
s32 synthSendKeyOff(int id);
u32 sndFXCheck(u32 id);
void synthActivateStudio(u8 studio, u32 isMaster, u32 type);
void synthDeactivateStudio(u8 studio);
void synthAddStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void synthRemoveStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void dataInit(void *arg0, void *arg1);
s32 sndPitchUpOne(s32 current);
u32 sndGetPitch(u8 note, u32 r);
u32 adsrConvertTimeCents(s32 arg0);
s32 salChangeADSRState(void *a0);
u32 adsrSetup(u8 *arg0);
s32 DCFlushRangeNoSync(void *, int);
u32 adsrStartRelease(ADSR_VARS_803B41C8 *adsr, u32 rtime);
s32 adsrRelease(struct Envelope_803B431C *e);
u32 adsrHandle(void *arg0, void *arg1, void *arg2);
u32 adsrHandleLowPrecision(void *pitchADSR, void *arg1, void *arg2);
void vsInit(void);
void dataInitStack(void);
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, u32 defaultStudioDPL2);
void salInitHRTFBuffer(void);
void salActivateStudio(u8 studio, u32 isMaster, u32 type);
void salDeactivateStudio(u8 i);
u32 salCheckVolErrorAndResetDelta(u16 *dsp_vol, u16 *dsp_delta, u16 *last_vol, u16 targetVol,
                         u16 *resetFlags, u16 resetMask);
void HandleDepopVoice(DSPstudioinfo_803B5AF8 *stp, DSPvoice_803B5AF8 *dsp_vptr);
void SortVoices(Ent_803B5DB0 **v, s32 left, s32 right);
s32 salSynthSendMessage(u8 *arg0, s32 arg1);
void salActivateVoice(Ent_803B8910 *dsp_vptr, u8 studio);
void salDeactivateVoice(Ent_803B89B4 *arg0);
void salHandleAuxProcessing(void);
void UpdateRoomDistances(void);
void CheckRoomStatus(void);
void CheckDoorStatus(void);
void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan);
void SetFXParameters(Emitter_S3D *const em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);
void EmitterShutdown(Emitter_S3D *arg0);
void s3dKillEmitterByFXID(Ent_803BA228 *arg0, u32 num);
void AddRunningEmitter(Emitter_S3D *em, f32 vol);
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch);
void StartContinousEmitters(void);
void s3dHandle(void);
void s3dInit(s32 flags);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
}

#endif
