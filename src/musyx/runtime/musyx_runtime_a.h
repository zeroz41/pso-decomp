#ifndef MUSYX_RUNTIME_A_H
#define MUSYX_RUNTIME_A_H

#include "types.h"
#include "musyx/musyx.h"
#include <string.h>
#include "musyx/runtime/hw_dspctrl.h"

typedef struct SynthInfo_SV { u32 mixFrq; u32 numSamples; struct { u32 frq; u8 stereo; u8 bits; s8 deviceName[256]; s8 versionText[256]; } pbInfo; u8 voiceNum; u8 maxMusic; u8 maxSFX; u8 studioNum; } SynthInfo_SV;

extern "C" {
void hwEnableIrq(void);
void hwDisableIrq(void);
void synthAddStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void synthRemoveStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
u32 adsrSetup(ADSR_VARS *adsr);
s32 DCFlushRangeNoSync(void *, int);
void salInitHRTFBuffer(void);
u32 salSynthSendMessage(DSPvoice *dsp_vptr, u32 mesg);
void s3dInit(s32 flags);
void salDeactivateStudio(u8 i);
extern u8 sndActive;
u32 sndFXCheck(u32 id);
u32 adsrRelease(ADSR_VARS *adsr);
void salDeactivateVoice(DSPvoice *dsp_vptr);
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
s32 synthSendKeyOff(int id);
s32 sndPitchUpOne(s32 current);
f32 powf(f32, f32);
u32 adsrConvertTimeCents(s32 arg0);
s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);
extern f32 lbl_804F6358[];
extern f32 lbl_804F6558[];
u32 sndGetPitch(u8 note, u32 r);
extern u16 lbl_804F6758[];
s32 salChangeADSRState(ADSR_VARS *adsr);
u32 adsrHandle(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta);
void seqInit(void);
void synthInit(u32 mixFrq, u32 numVoices);
void streamInit(void);
void dataInit(void *arg0, void *arg1);
void vsInit(void);
void dataInitStack(void);
s32 hwInit(u32 *frq, u32 numVoices, u32 numStudios, u32 flags);
extern u8 synthIdleWaitActive;
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
void UpdateRoomDistances(void);
void synthDeactivateStudio(u8 studio);
}

extern "C" {

extern SynthInfo_SV synthInfo;

struct Ent_803BA228 { u16 id; u8 pad[8]; };
}

extern "C" {

extern u8 salMaxStudioNum;
extern u8 salAuxFrame;
extern u8 salFrame;

u32 adsrHandleLowPrecision(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta);

extern f32 dspDLSVolTab[];

extern void (*synthMessageCallback)(u32, s32);

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
void salActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);

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

void synthActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);

void salApplyMatrix(void *mat, void *in, void *out);
f32 salNormalizeVector(FVec_S3D *vec);

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

void CheckRoomStatus(void);
void CheckDoorStatus(void);
void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan);
void AddRunningEmitter(Emitter_S3D *em, f32 vol);
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch);
void StartContinousEmitters(void);

}

extern "C" {
s32 synthFXSetCtrl(u32 vid, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 vid, u8 ctrl, u16 value);
u32 adsrStartRelease(ADSR_VARS *adsr, u32 rtime);
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, u32 defaultStudioDPL2);
u32 salCheckVolErrorAndResetDelta(u16 *dsp_vol, u16 *dsp_delta, u16 *last_vol, u16 targetVol,
                         u16 *resetFlags, u16 resetMask);
void HandleDepopVoice(DSPstudioinfo *stp, DSPvoice *dsp_vptr);
void SortVoices(DSPvoice **v, s32 left, s32 right);
void salActivateVoice(DSPvoice *dsp_vptr, u8 studio);
void salHandleAuxProcessing(void);
void SetFXParameters(Emitter_S3D *const em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);
void EmitterShutdown(Emitter_S3D *arg0);
void s3dKillEmitterByFXID(Ent_803BA228 *arg0, u32 num);
void s3dHandle(void);
}

#endif
