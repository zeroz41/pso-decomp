#ifndef MUSYX_INTERNAL_H
#define MUSYX_INTERNAL_H

#include "types.h"
#include "musyx/musyx.h"
#include "musyx/runtime/hw_dspctrl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern u8 dspSlave[];
extern u16 dspSlaveLength;

struct SoundReverb;
void ReverbHICallback(void *left, void *right, void *surround, SoundReverb *rv);

typedef struct SynthITDInfo {
    u8 music;
    u8 sfx;
} SynthITDInfo;

typedef struct SynthVidList {
    struct SynthVidList *next;
    struct SynthVidList *prev;
    u32 vid;
    u32 root;
} SynthVidList;

typedef struct SynthInfo {
    u32 mixFrq;
    u32 numSamples;
    struct {
        u32 frq;
        u8 stereo;
        u8 bits;
        s8 deviceName[256];
        s8 versionText[256];
    } pbInfo;
    u8 voiceNum;
    u8 maxMusic;
    u8 maxSFX;
    u8 studioNum;
} SynthInfo;

/* Runtime-internal MusyX types and prototypes.
 * Note: SND_FVECTOR and SND_FMATRIX are defined in musyx/musyx.h. */

typedef struct FX_TAB {
    u16 id;
    u16 macro;
    u8 maxVoices;
    u8 priority;
    u8 volume;
    u8 panning;
    u8 key;
    u8 vGroup;
} FX_TAB;

typedef struct SynthMacroStep {
    u32 para[2];
} SynthMacroStep;

typedef struct SynthCallStack {
    SynthMacroStep *addr;
    SynthMacroStep *curAddr;
} SynthCallStack;

typedef struct SynthQueue {
    struct SynthQueue *next;
    struct SynthQueue *prev;
    u8 voice;
    u8 jobTabIndex;
} SynthQueue;

typedef struct SynthJobTab {
    SynthQueue *lowPrecision;
    SynthQueue *event;
    SynthQueue *zeroOffset;
} SynthJobTab;

typedef struct SynthLFO {
    u32 time;
    u32 period;
    s16 value;
    s16 lastValue;
} SynthLFO;

typedef struct SynthMasterFader {
    f32 volume;
    f32 target;
    f32 start;
    f32 time;
    f32 deltaTime;
    f32 pauseVol;
    f32 pauseTarget;
    f32 pauseStart;
    f32 pauseTime;
    f32 pauseDeltaTime;
    u32 seqId;
    u8 seqMode;
    u8 type;
} SynthMasterFader;

typedef struct CtrlSource {
    u8 midiCtrl;
    u8 combine;
    s32 scale;
} CtrlSource;

typedef struct CtrlDest {
    CtrlSource source[4];
    u16 oldValue;
    u8 numSource;
} CtrlDest;

#pragma pack(push, 4)
typedef struct SynthVoice {
    SynthQueue lowPrecisionJob;
    SynthQueue zeroOffsetJob;
    SynthQueue eventJob;
    u64 lastLowCallTime;
    u64 lastZeroCallTime;
    SynthMacroStep *addr;
    SynthMacroStep *curAddr;
    struct SynthVoice *nextMacActive;
    struct SynthVoice *prevMacActive;
    struct SynthVoice *nextTimeQueueMacro;
    struct SynthVoice *prevTimeQueueMacro;
    s32 macState;
    SynthMacroStep *trapEventAddr[3];
    SynthMacroStep *trapEventCurAddr[3];
    u8 trapEventAny;
    SynthCallStack callStack[4];
    u8 callStackEntryNum;
    u8 callStackIndex;
    u64 macStartTime;
    u64 wait;
    u64 waitTime;
    u8 timeUsedByInput;
    u16 loop;
    s32 local_vars[16];
    u32 child;
    u32 parent;
    u32 id;
    SynthVidList *vidList;
    SynthVidList *vidMasterList;
    u16 allocId;
    u16 macroId;
    u8 keyGroup;
    u32 lastVID;
    u8 prio;
    u16 ageSpeed;
    u32 age;
    u64 cFlags;
    u8 block;
    u8 fxFlag;
    u8 vGroup;
    u8 studio;
    u8 track;
    u8 midi;
    u8 midiSet;
    u8 section;
    u32 sInfo;
    u32 playFrq;
    u16 curNote;
    s8 curDetune;
    u8 orgNote;
    u8 lastNote;
    u8 portType;
    u16 portLastCtrlState;
    u32 portDuration;
    u32 portCurPitch;
    u32 portTime;
    u8 vibKeyRange;
    u8 vibCentRange;
    u32 vibPeriod;
    u32 vibCurTime;
    s32 vibCurOffset;
    s16 vibModAddScale;
    u32 volume;
    u32 orgVolume;
    f32 lastVolFaderScale;
    u32 lastPan;
    u32 lastSPan;
    f32 treCurScale;
    u16 treScale;
    u16 treModAddScale;
    u32 panning[2];
    s32 panDelta[2];
    u32 panTarget[2];
    u32 panTime[2];
    u8 revVolScale;
    u8 revVolOffset;
    u8 volTable;
    u8 itdMode;
    s32 envDelta;
    u32 envTarget;
    u32 envCurrent;
    u32 sweepOff[2];
    s32 sweepAdd[2];
    s32 sweepCnt[2];
    u8 sweepNum[2];
    SynthLFO lfo[2];
    u8 lfoUsedByInput[2];
    u8 pbLowerKeyRange;
    u8 pbUpperKeyRange;
    u16 pbLast;
    ADSR_VARS pitchADSR;
    s16 pitchADSRRange;
    u16 curPitch;
    struct {
        u8 vol;
        u8 pan;
        u8 midi;
        u8 midiSet;
        u8 section;
        u8 track;
        u8 vGroup;
        u8 studio;
        u8 itdMode;
    } setup;
    u32 midiDirtyFlags;
    CtrlDest inpVolume;
    CtrlDest inpPanning;
    CtrlDest inpSurroundPanning;
    CtrlDest inpPitchBend;
    CtrlDest inpDoppler;
    CtrlDest inpModulation;
    CtrlDest inpPedal;
    CtrlDest inpPortamento;
    CtrlDest inpPreAuxA;
    CtrlDest inpReverb;
    CtrlDest inpPreAuxB;
    CtrlDest inpPostAuxB;
    CtrlDest inpTremolo;
    u8 mesgNum;
    u8 mesgRead;
    u8 mesgWrite;
    s32 mesgQueue[4];
    u16 curOutputVolume;
} SynthVoice;
#pragma pack(pop)

typedef struct SynthLayer {
    u16 id;
    u8 keyLow;
    u8 keyHigh;
    s8 transpose;
    u8 volume;
    s16 prioOffset;
    u8 panning;
    u8 reserved[3];
} SynthLayer;

typedef struct SynthKeymap {
    u16 id;
    s8 transpose;
    u8 panning;
    s16 prioOffset;
    u8 reserved[2];
} SynthKeymap;

typedef struct SynthPoolMemData {
    u32 nextOff;
    u16 id;
    u16 reserved;
    union {
        struct {
            u32 num;
            SynthLayer entry[1];
        } layer;
        u8 map[1];
        u8 tab[1];
        u32 cmd[1][2];
    } data;
} SynthPoolMemData;

typedef struct SynthPoolData {
    u32 macroOff;
    u32 curveOff;
    u32 keymapOff;
    u32 layerOff;
} SynthPoolData;

typedef struct SynthSampleHeader {
    u32 info;
    u32 length;
    u32 loopOffset;
    u32 loopLength;
} SynthSampleHeader;

typedef struct SynthSDirData {
    u16 id;
    u16 ref_cnt;
    u32 offset;
    uaddr addr;
    SynthSampleHeader header;
    u32 extraData;
} SynthSDirData;

typedef struct SynthSeqPage {
    u16 macro;
    u8 prio;
    u8 maxVoices;
    u8 index;
    u8 reserved;
} SynthSeqPage;

typedef struct SynthMidiChannelSetup {
    u8 program;
    u8 volume;
    u8 panning;
    u8 reverb;
    u8 chorus;
} SynthMidiChannelSetup;

typedef struct SynthMidiSetup {
    u16 songId;
    u16 reserved;
    SynthMidiChannelSetup channel[16];
} SynthMidiSetup;

typedef struct SynthSeqVolDef {
    u8 track;
    u8 volGroup;
} SynthSeqVolDef;

typedef struct SynthPlayPara {
    u32 flags;
    u32 trackMute[2];
    u16 speed;
    struct {
        u16 time;
        u8 target;
    } volume;
    u8 numSeqVolDef;
    SynthSeqVolDef *seqVolDef;
    u8 numFaded;
    u8 *faded;
} SynthPlayPara;

typedef enum SynthMacState {
    MAC_STATE_RUNNABLE = 0,
    MAC_STATE_YIELDED,
    MAC_STATE_STOPPED
} SynthMacState;

typedef struct SynthADSRInfo {
    union {
        struct {
            s32 atime;
            s32 dtime;
            u16 slevel;
            u16 rtime;
            s32 ascale;
            s32 dscale;
        } dls;
        struct {
            u16 atime;
            u16 dtime;
            u16 slevel;
            u16 rtime;
        } linear;
    } data;
} SynthADSRInfo;

typedef struct SynthChannelDefaults {
    u8 pbRange;
} SynthChannelDefaults;

typedef struct SynthCrossfade {
    u32 seqId1;
    u16 time1;
    u32 seqId2;
    u16 time2;
    void *arr2;
    u16 gid2;
    u16 sid2;
    u8 vol2;
    u8 studio2;
    u32 trackMute2[2];
    u16 speed2;
    u8 flags;
} SynthCrossfade;

#define MUSYX_CLAMP(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define MUSYX_CLAMP_INV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define MUSYX_CACHED_TO_UNCACHED(addr) ((void *)((u8 *)(addr) + (0xC0000000 - 0x80000000)))

extern SynthInfo synthInfo;
extern SynthVoice *synthVoice;
extern s32 synthFlags;
extern SynthITDInfo synthITDDefault[8];
extern void *synthAuxAUser[8];
extern SND_AUX_CALLBACK synthAuxACallback[8];
extern void *synthAuxBUser[8];
extern SND_AUX_CALLBACK synthAuxBCallback[8];
extern u8 synthAuxAMIDISet[8];
extern u8 synthAuxAMIDI[8];
extern u8 synthAuxBMIDISet[8];
extern u8 synthAuxBMIDI[8];
extern u8 sndActive;
extern u8 synthIdleWaitActive;
extern u8 synthTrackVolume[64];
extern SynthMasterFader synthMasterFader[32];
extern u32 synthMasterFaderActiveFlags;
extern u32 synthMasterFaderPauseActiveFlags;
extern s64 synthRealTime;
extern u8 synthJobTableIndex;
extern s32 synthGlobalVariable[16];
extern void (*synthMessageCallback)(u32, s32);
extern CtrlDest inpAuxA[8][4];
extern CtrlDest inpAuxB[8][4];
extern u8 dspScale2IndexTab[];
extern f32 dspDLSVolTab[];

typedef void (*ARAMTransferCallback)(u32);

void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableHRTF(void);
void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB);
void hwActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);
void hwDeactivateStudio(u8 studio);
u32 hwIsActive(s32 v);
void hwOff(s32 vid);
void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void hwSetVolume(s32 v, u8 table, f32 vol, u32 pan, s32 span, f32 auxa, f32 auxb);
uaddr hwGetStreamPlayBuffer(u8 hwStreamHandle);
void hwInitSamplePlayback(s32 v, u16 smpID, SAMPLE_INFO *newsmp, u32 set_defadsr, s32 prio, s32 callbackUserValue, u32 setSRC, u8 itdMode);
void hwSetPitch(s32 v, u16 speed);
void hwStart(s32 v, u8 studio);
void hwKeyOff(s32 v);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 hwStreamHandle, ARAMTransferCallback callback, u32 user);
void hwSetStreamLoopPS(s32 voice, u8 ps);
u8 hwInitStream(u32 size);
void hwExitStream(u8 id);
void hwSetPriority(s32 v, s32 prio);
u8 hwGetTimeOffset(void);
void hwFrameDone(void);
void hwSetMesgCallback(SND_MESSAGE_CALLBACK callback);
void *hwTransAddr(void *samples);
void hwSyncSampleMem(void);
void hwSaveSample(SynthSampleHeader **header, uaddr *data);
void hwRemoveSample(SynthSampleHeader *header, u32 data);
void hwInitSampleMem(u32 baseAddr, u32 length);
void hwSetADSR(s32 v, void *_adsr, u8 mode);
void hwSetSRCType(s32 v, u8 salSRCType);
void hwSetPolyPhaseFilter(s32 v, u8 salCoefSel);
u32 hwFrq2Pitch(u32 frq);
void hwSetITDMode(s32 v, u8 mode);
void hwSetTimeOffset(s8 offset);
s32 hwGetVirtualSampleID(s32 voice);
s32 hwInit(u32 *frq, s32 numVoices, s32 numStudios, u32 flags);
void snd_handle_irq(void);
void hwInitIrq(void);
void hwIRQEnterCritical(void);
void hwIRQLeaveCritical(void);

extern s8 salTimeOffset;
extern SND_HOOKS salHooks;
extern u8 salMaxStudioNum;
extern u8 salNumVoices;
extern u8 salAuxFrame;
extern u8 salFrame;

extern u8 salAIBufferIndex;
extern u8 *salAIBufferBase;
extern void (*userCallback)(void);
extern volatile u32 salDspIsDone;
extern volatile u32 salDspInitIsDone;
extern volatile u32 salLogicIsWaiting;
extern volatile u32 salLogicActive;
extern volatile u32 salLastTick;
extern volatile u16 hwIrqLevel;
extern volatile s32 oldState;
void salCallback(void);
void dspInitCallback(void);
void dspResumeCallback(void);
u32 salInitAi(void (*callback)(void), u32 unk, u32 *outFreq);
void salStartAi(void);
void *salAiGetDest(void);
u32 salInitDsp(u32 flags);
void salCtrlDsp(saddr dest);
u32 salGetStartDelay(void);

extern u8 dspSlave[];
extern u16 dspSlaveLength;
extern u16 dspCmdFirstSize;
extern u16 *dspCmdList;
extern u32 dspHRTFOn;
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, u32 defaultStudioDPL2);
void salActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);
void salDeactivateStudio(u8 i);
void salBuildCommandList(s16 *dest, u32 nsDelay);
void salActivateVoice(DSPvoice *dsp_vptr, u8 studio);
void salDeactivateVoice(DSPvoice *dsp_vptr);
s32 salAddStudioInput(DSPstudioinfo *stp, SND_STUDIO_INPUT *desc);
s32 salRemoveStudioInput(DSPstudioinfo *stp, SND_STUDIO_INPUT *desc);
void salHandleAuxProcessing(void);
void salInitHRTFBuffer(void);
u32 salSynthSendMessage(DSPvoice *dsp_vptr, u32 mesg);
void salCalcVolume(u8 voltab_index, SAL_VOLINFO *vi, f32 vol, u32 pan, u32 span, f32 auxa, f32 auxb, u32 itd, u32 dpl2);

void aramInit(u32 length);
s32 aramStoreData(u8 *src, u32 size);
void aramRemoveData(s32 addr, s32 size);
u8 aramAllocateStreamBuffer(u32 len);
void aramFreeStreamBuffer(u8 id);
u32 aramGetZeroBuffer(void);

extern f32 toneup_tab[128];
extern f32 tonedown_tab[128];
extern u16 dspAttenuationTab[194];
s32 salChangeADSRState(ADSR_VARS *adsr);
u32 adsrStartRelease(ADSR_VARS *adsr, u32 rtime);
u32 adsrHandle(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta);

void synthInit(u32 mixFrq, u32 numVoices);
void synthActivateStudio(u8 studio, u32 isMaster, SND_STUDIO_TYPE type);
void synthDeactivateStudio(u8 studio);
void synthAddStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void synthRemoveStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void vsInit(void);
void s3dInit(s32 flags);

void salApplyMatrix(const SND_FMATRIX *mat, const SND_FVECTOR *in, SND_FVECTOR *out);
f32 salNormalizeVector(SND_FVECTOR *vec);

void streamInit(void);
void streamHandle(void);
void streamCorrectLoops(void);
void streamKill(s32 voice);
s32 GetPrivateIndex(u32 publicID);
void CheckOutputMode(s8 *pan, s8 *span);

s32 synthFXSetCtrl(u32 vid, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 vid, u8 ctrl, u16 value);
s32 synthSendKeyOff(int id);
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
void synthVolume(u8 volume, u16 time, u8 vGroup, s8 seqMode, s32 seqId);
u32 vidGetInternalId(u32 vid);
void streamOutputModeChanged(void);
u32 seqGetPrivateId(u32 seqId);
s32 voiceKillSound(u32 voiceid);
void synthAddJob(SynthVoice *svoice, s32 jobType, u32 deltaTime);
u32 StartKeymap(u16 keymapID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet,
                u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd);
u32 StartLayer(u16 layerID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet,
               u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd);
u32 synthStartSound(u16 id, u8 prio, u8 max, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet, u8 section, u16 step,
                    u16 trackid, u8 vGroup, s16 prioOffset, u8 studio, u32 itd);
void synthSetBpm(s32 bpm, u8 set, u8 section);
void synthSetMusicVolumeType(u8 i, u8 v);
s32 synthIsFadeOutActive(u8 vGroup);
void synthFXCloneMidiSetup(SynthVoice *dst, SynthVoice *src);
void synthKeyStateUpdate(SynthVoice *svoice);
void synthForceLowPrecisionUpdate(SynthVoice *svoice);
void synthInitPortamento(SynthVoice *svoice);
void synthStartSynthJobHandling(SynthVoice *voice);
s32 synthGetTicksPerSecond(SynthVoice *svoice);
void synthHandle(u32 deltaTime);
void vsSampleUpdates(void);
void s3dHandle(void);

void vidInit(void);
SynthVidList *get_vidlist(u32 key);
void vidRemoveVoiceReferences(SynthVoice *p);
u32 vidMakeRoot(SynthVoice *svoice);
u32 vidMakeNew(SynthVoice *svoice, u32 isMaster);
void voiceRemovePriority(SynthVoice *svoice);
void voiceSetPriority(SynthVoice *svoice, u8 prio);
u32 voiceAllocate(u8 priority, u8 maxVoices, u16 allocId, u8 fxFlag);
void voiceFree(SynthVoice *o);
void synthInitAllocationAids(void);
u32 voiceBlock(u8 prio);
void voiceUnblock(s32 voice);
void voiceKill(u32 vi);
void synthKillVoicesByMacroReferences(u16 *ref);
s32 voiceIsLastStarted(SynthVoice *svoice);
void voiceSetLastStarted(SynthVoice *svoice);
void voiceResetLastStarted(SynthVoice *svoice);
void voiceInitLastStarted(void);

s32 dataInsertKeymap(u16 cid, void *keymapdata);
s32 dataRemoveKeymap(u16 sid);
s32 dataInsertLayer(u16 cid, void *layerdata, u16 size);
s32 dataRemoveLayer(u16 sid);
s32 dataInsertCurve(u16 cid, void *curvedata);
s32 dataRemoveCurve(u16 sid);
u32 dataInsertSDir(SynthSDirData *sdir, void *smp_data);
s32 dataRemoveSDir(SynthSDirData *sdir);
s32 dataAddSampleReference(u16 sid);
s32 dataRemoveSampleReference(u16 id);
s32 dataInsertFX(u16 gid, FX_TAB *fx, u16 fxNum);
s32 dataRemoveFX(u16 gid);
s32 dataInsertMacro(u16 mid, void *macroaddr);
s32 dataRemoveMacro(u16 mid);
SynthMacroStep *dataGetMacro(u16 mid);
s32 dataGetSample(s16 sid, SAMPLE_INFO *newsmp);
saddr dataGetCurve(s16 cid);
SynthKeymap *dataGetKeymap(u16 cid);
SynthLayer *dataGetLayer(u16 cid, u16 *n);
FX_TAB *dataGetFX(s16 fid);
void dataInit(u32 smpBase, u32 smpLength);
void dataInitStack(void);
void InsertData(u16 id, void *data, u8 dataType, u32 remove);
void ScanIDList(u16 *p, void *data, u8 dataType, u32 remove);
void ScanIDListReverse(u16 *start, void *data, u8 dataType, u32 remove);
u32 seqPlaySong(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, u8 irq_call, s32 studio);
u32 sndSeqPlayEx(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, s32 studio);

void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
void sndConvertMs(u32 *time);
s32 sndPitchUpOne(s32 current);
u32 sndGetPitch(u8 note, u32 r);
s16 sndSin(u16 angle);
u16 sndRand(void);
void sndConvertTicks(u32 *ticks, SynthVoice *svoice);
u32 sndConvert2Ms(u32 time);
f32 floorf(f32 x);
void s3dKillEmitterByFXID(FX_TAB *fxTab, u32 num);
void seqKillInstancesByGroupID(u16 sgid);
#if !defined(MUSYX_SEQ_IMPL)
u32 seqStartPlay(SynthSeqPage *norm, SynthSeqPage *drum, SynthMidiSetup *midiSetup, u32 *song, SynthPlayPara *para,
                 s32 studio, u16 sgid);
#endif
void seqStop(s32 seqId);
void seqPause(s32 seqId);
void seqMute(s32 seqId, s32 mask1, s32 mask2);
u16 seqGetMIDIPriority(u8 midiSet, u8 midi);
void seqInit(void);
void seqHandle(u32 deltaTime);
void seqContinue(s32 seqId);
void seqSpeed(u32 id, s16 v);
void seqVolume(u8 volume, u16 time, u32 seqId, u8 mode);
void seqCrossFade(SynthCrossfade *ci, u32 *new_seqId, u8 irq_call);
extern u16 seqMIDIPriority[8][16];
void sndSeqSpeed(u32 seqId, u16 speed);
void sndSeqContinue(s32 seqId);
void sndSeqMute(s32 seqId, s32 mask1, s32 mask2);
void sndSeqVolume(u8 volume, u16 time, u32 seqId, u8 mode);

void macInit(void);
void macHandle(u32 deltaTime);
u32 macStart(u16 macid, u8 priority, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet,
             u8 section, u16 step, u16 trackid, u8 new_vid, u8 vGroup, u8 studio, u32 itd);
void macMakeInactive(SynthVoice *svoice, s32 state);
void macSetPedalState(SynthVoice *svoice, u32 hold);
void macSetExternalKeyoff(SynthVoice *svoice);
void macSampleEndNotify(SynthVoice *svoice);
s16 varGet(SynthVoice *svoice, u32 isExCtrl, u8 index);

u32 adsrConvertTimeCents(s32 timeCents);
u32 adsrSetup(ADSR_VARS *adsr);
u32 adsrHandleLowPrecision(ADSR_VARS *adsr, u16 *adsr_start, u16 *adsr_delta);
u32 adsrRelease(ADSR_VARS *adsr);
u32 vsSampleStartNotify(u8 voice);
void vsSampleEndNotify(u32 pubID);

void inpInit(SynthVoice *svoice);
u16 inpGetMidiCtrl(u8 ctrl, u8 channel, u8 set);
void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void inpSetMidiLastNote(u8 midi, u8 midiSet, u8 key);
void inpFXCopyCtrl(u8 ctrl, SynthVoice *dvoice, SynthVoice *svoice);
u8 inpTranslateExCtrl(u8 ctrl);
u16 inpGetExCtrl(SynthVoice *svoice, u8 ctrl);
void inpSetExCtrl(SynthVoice *svoice, u8 ctrl, s16 v);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
SynthChannelDefaults *inpGetChannelDefaults(u8 midi, u8 midiSet);
void inpAddCtrl(CtrlDest *dest, u8 ctrl, s32 scale, u8 comb, u32 isVar);
void inpSetGlobalMIDIDirtyFlag(u8 chan, u8 midiSet, u32 flag);
void inpResetMidiCtrl(u8 midi, u8 midiSet, u32 coldReset);
void inpResetChannelDefaults(u8 midi, u8 midiSet);
u16 inpGetTremolo(SynthVoice *svoice);
u16 inpGetPanning(SynthVoice *svoice);
u16 inpGetSurPanning(SynthVoice *svoice);
u16 inpGetVolume(SynthVoice *svoice);
u16 inpGetReverb(SynthVoice *svoice);
u16 inpGetPreAuxA(SynthVoice *svoice);
u16 inpGetPostAuxB(SynthVoice *svoice);
u16 inpGetPreAuxB(SynthVoice *svoice);
u16 inpGetPitchBend(SynthVoice *svoice);
u16 inpGetModulation(SynthVoice *svoice);
u16 inpGetDoppler(SynthVoice *svoice);
u16 inpGetPedal(SynthVoice *svoice);
u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet);
u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet);

u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void hwSetVirtualSampleLoopBuffer(s32 voice, uaddr addr, u32 len);
u16 hwGetSampleID(s32 voice);
u8 hwGetSampleType(s32 voice);
u32 hwGetVirtualSampleState(s32 voice);
u32 hwGetPos(s32 v);
u32 hwVoiceInStartup(s32 v);
void hwBreak(s32 vid);

f32 *salMalloc(s32 bytes);
void salFree(void *addr);
void aramQueueCallback(uaddr ptr);
void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, ARAMTransferCallback callback, u32 user);
void aramSyncTransferQueue(void);
void InitStreamBuffers(void);

#if defined(_DOLPHIN_AR_H)
typedef u8 *(*ARAMUploadCallback)(u8 *, u32);

typedef struct ARAMTransferJob {
    ARQRequest arq;
    ARAMTransferCallback callback;
    u32 user;
} ARAMTransferJob;

typedef struct ARAMTransferQueue {
    ARAMTransferJob queue[16];
    volatile u8 write;
    volatile u8 valid;
} ARAMTransferQueue;

typedef struct ARAMStreamBuffer {
    struct ARAMStreamBuffer *next;
    u32 aram;
    u32 length;
    u32 allocLength;
} ARAMStreamBuffer;
#endif

#ifdef __cplusplus
}
#endif

#endif
