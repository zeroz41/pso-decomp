#ifndef MUSYX_INTERNAL_H
#define MUSYX_INTERNAL_H

#include "types.h"
#include "musyx/musyx.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MUSYX_RUNTIME_A_H)
typedef Ent_803BA228 FX_TAB;
typedef ADSR_VARS_803B41C8 ADSRVars;
typedef Envelope_803B431C MusyxEnvelope;
#endif

#if !defined(MUSYX_RUNTIME_A_H) && !defined(MUSYX_RUNTIME_B_H)
struct SoundReverb;
void ReverbHICallback(void *left, void *right, void *surround, struct SoundReverb *rev);

typedef struct SndParaEntry {
    u8 type;
    u8 pad1;
    union {
        u16 w;
        u8 b;
    } v;
} SndParaEntry;

typedef struct SndParaInfo {
    u8 count;
    u8 pad[3];
    SndParaEntry *ents;
} SndParaInfo;

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

typedef u32 (*SND_STREAM_UPDATE_CALLBACK)(void *buffer1, u32 len1, void *buffer2, u32 len2, u32 user);

typedef struct SND_ADPCMSTREAM_INFO {
    s16 coefTab[8][2];
} SND_ADPCMSTREAM_INFO;

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

typedef struct ADSRVars {
    u8 mode;
    u8 state;
    u32 cnt;
    s32 currentVolume;
    s32 currentIndex;
    s32 currentDelta;
    union {
        struct {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
            u16 cutOff;
            u8 aMode;
        } dls;
        struct {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
        } linear;
    } data;
} ADSRVars;

typedef struct MusyxEnvelope {
    u8 mode;
    u8 phase;
    u8 pad[2];
    u32 remaining;
    u32 level;
    u32 logLevel;
    s32 step;
    u32 attack;
    u32 decay;
    u16 sustain;
    u16 pad2;
    u32 release;
} MusyxEnvelope;

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
    ADSRVars pitchADSR;
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

typedef struct SampleInfo {
    u32 key;
    u32 addr;
    u32 coef;
    u32 offset;
    u32 count;
    u32 loopStart;
    u32 loopLen;
    u8 format;
} SampleInfo;

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

void hwDisableIrq(void);
void hwEnableIrq(void);
void hwDisableHRTF(void);
void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB);
void hwActivateStudio(u8 studio, s32 isMaster, s32 type);
void hwDeactivateStudio(u8 studio);
u32 hwIsActive(s32 voice);
void hwOff(s32 voice);
void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc);
#if defined(MUSYX_STREAM_IMPL)
void hwSetVolume(u32 v, u8 table, f32 vol, u32 pan, u32 span, f32 auxa, f32 auxb);
#else
void hwSetVolume(s32 voice, u32 volumeCurve, u32 pan, s32 surroundPan, f32 direct, f32 auxiliaryA, f32 auxiliaryB);
#endif
uaddr hwGetStreamPlayBuffer(u8 streamHandle);
void hwInitSamplePlayback(u32 voice, u16 smpID, void *newsmp, u32 setDefAdsr, u32 prio, u32 callbackUserValue,
                          u32 setSRC, u8 itdMode);
void hwSetPitch(s32 voice, u16 speed);
void hwStart(s32 voice, u8 studio);
void hwKeyOff(s32 voice);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 streamHandle, void *cb, void *arg);
void hwSetStreamLoopPS(s32 voice, u8 ps);
u8 hwInitStream(u32 size);
void hwExitStream(u8 streamHandle);
void hwSetPriority(s32 voice, s32 prio);
u8 hwGetTimeOffset(void);
void hwFrameDone(void);
void hwSetMesgCallback(s32 cb);
void *hwTransAddr(void *samples);
void hwSyncSampleMem(void);
void hwSaveSample(SynthSampleHeader **header, uaddr *data);
void hwRemoveSample(SynthSampleHeader *header, u32 aramAddr);
void hwInitSampleMem(void *self, void *p);
void hwSetADSR(u8 voice, void *adsr, s32 mode);
void hwSetSRCType(u32 voice, u8 salSRCType);
void hwSetPolyPhaseFilter(u32 voice, u8 salCoefSel);
u32 hwFrq2Pitch(u32 frq);

void salApplyMatrix(const SND_FMATRIX *mat, const SND_FVECTOR *in, SND_FVECTOR *out);
f32 salNormalizeVector(SND_FVECTOR *vec);

void streamInit(void);
void streamHandle(void);
void streamCorrectLoops(void);
void streamKill(s32 voice);
s32 GetPrivateIndex(u32 publicID);
void CheckOutputMode(s8 *pan, s8 *span);
u32 sndStreamAllocLength(u32 samples, u32 flags);
u32 sndStreamAllocEx(u8 prio, void *buffer, u32 samples, u32 frq, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb, u8 studio,
                     u32 flags, SND_STREAM_UPDATE_CALLBACK updateFunction, u32 user, SND_ADPCMSTREAM_INFO *adpcmInfo);
void sndStreamARAMUpdate(u32 stid, u32 off1, u32 len1, u32 off2, u32 len2);
void sndStreamMixParameter(u32 stid, u8 vol, u8 pan, u8 span, u8 fxvol);
void sndStreamMixParameterEx(u32 stid, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb);
void sndStreamFrq(u32 stid, u32 frq);
void sndStreamFree(u32 stid);
u32 sndStreamActivate(u32 stid);
void sndStreamDeactivate(u32 stid);

s32 synthFXSetCtrl(u32 id, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 id, u8 ctrl, u16 value);
s32 synthSendKeyOff(int id);
u32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
void synthVolume(u8 vol, u16 time, u8 vGroup, s8 seq, s32 fade);
u32 vidGetInternalId(u32 vid);
void streamOutputModeChanged(void);
u32 seqGetPrivateId(u32 seqId);
s32 voiceKillSound(u32 id);
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
void synthStartSynthJobHandling(SynthVoice *svoice);

void vidInit(void);
SynthVidList *get_vidlist(u32 key);
void vidRemoveVoiceReferences(SynthVoice *svoice);
u32 vidMakeRoot(SynthVoice *svoice);
u32 vidMakeNew(SynthVoice *svoice, u32 isMaster);
void voiceRemovePriority(SynthVoice *svoice);
void voiceSetPriority(SynthVoice *svoice, u8 prio);
u32 voiceAllocate(u8 priority, u8 maxVoices, u16 allocId, u8 fxFlag);
void voiceFree(SynthVoice *svoice);
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
uaddr dataGetMacro(u16 mid);
s32 dataGetSample(s16 sid, SampleInfo *newsmp);
saddr dataGetCurve(s16 cid);
SynthKeymap *dataGetKeymap(u16 cid);
SynthLayer *dataGetLayer(u16 cid, u16 *n);
FX_TAB *dataGetFX(s16 fid);
void dataInit(void *self, void *p);
void dataInitStack(void);
void InsertData(u16 id, void *data, u8 dataType, u32 remove);
void ScanIDList(u16 *p, void *data, u8 dataType, u32 remove);
void ScanIDListReverse(u16 *start, void *data, u8 dataType, u32 remove);
u32 sndPushGroup(void *prj_data, u16 gid, void *samples, void *sdir, void *pool);
u32 sndPopGroup(void);
u32 seqPlaySong(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, u8 irq_call, s32 studio);
u32 sndSeqPlayEx(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, s32 studio);

void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
void sndConvertMs(void *time);
s32 sndPitchUpOne(s32 current);
u32 sndGetPitch(u8 note, u32 r);
s16 sndSin(u16 angle);
u16 sndRand(void);
void sndConvertTicks(void *ticks, void *svoice);
u32 sndConvert2Ms(u32 time);
u32 sndFXCheck(u32 id);
f32 floorf(f32 x);
void s3dKillEmitterByFXID(FX_TAB *fxTab, u32 num);
void seqKillInstancesByGroupID(u16 gid);
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
s16 varGet(SynthVoice *svoice, u32 isExCtrl, u32 index);

u32 adsrConvertTimeCents(s32 timeCents);
u32 adsrSetup(ADSRVars *adsr);
u32 adsrHandleLowPrecision(void *adsr, void *start, void *delta);
s32 adsrRelease(MusyxEnvelope *e);
u32 vsSampleStartNotify(u8 voice);
void vsSampleEndNotify(u32 pubID);

void inpInit(u8 *arg);
u16 inpGetMidiCtrl(u8 ctrl, u8 channel, u8 set);
void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void inpSetMidiLastNote(u8 midi, u8 midiSet, u8 key);
void inpFXCopyCtrl(u8 ctrl, SynthVoice *dvoice, SynthVoice *svoice);
u16 inpGetExCtrl(SynthVoice *svoice, s32 ctrl);
void inpSetExCtrl(SynthVoice *svoice, u8 ctrl, s16 v);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
SynthChannelDefaults *inpGetChannelDefaults(u8 midi, u8 midiSet);
void inpAddCtrl(CtrlDest *dest, u8 ctrl, s32 scale, u8 combine, bool isExCtrl);
void inpSetGlobalMIDIDirtyFlag(u8 midi, u8 midiSet, u32 flag);
void inpResetMidiCtrl(u8 channel, u8 set, u8 resetAll);
void inpResetChannelDefaults(u8 channel, u8 set);
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

u32 aramGetStreamBufferAddress(u8 channel, u32 *outLen);
void hwSetVirtualSampleLoopBuffer(s32 voice, s32 addr, s32 len);
u16 hwGetSampleID(s32 voice);
u8 hwGetSampleType(s32 voice);
u32 hwGetVirtualSampleState(s32 voice);
u32 hwGetPos(s32 voice);
s32 hwGetVirtualSampleID(u8 voice);
u32 hwVoiceInStartup(s32 voice);
void hwBreak(u32 voice);

f32 *salMalloc(s32 bytes);
void salFree(saddr addr);
void aramQueueCallback(uaddr ptr);
void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg);
void aramSyncTransferQueue(void);
void InitStreamBuffers(void);

#if defined(_DOLPHIN_AR_H)
typedef u8 *(*ARAMUploadCallback)(u8 *, u32);
typedef void (*ARAMTransferCallback)(u32);

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
#endif

#ifdef __cplusplus
}
#endif

#endif
