#ifndef MUSYX_MUSYX_H
#define MUSYX_MUSYX_H

#include "types.h"

typedef u32 SND_SEQID;

typedef struct SND_FVECTOR {
    f32 x;
    f32 y;
    f32 z;
} SND_FVECTOR;

typedef struct SND_FMATRIX {
    f32 m[3][3];
    f32 t[3];
} SND_FMATRIX;

typedef struct SND_AUX_INFO {
    union SND_AUX_DATA {
        struct SND_AUX_BUFFERUPDATE {
            s32 *left;
            s32 *right;
            s32 *surround;
        } bufferUpdate;
        struct SND_AUX_PARAMETERUPDATE {
            u16 para[4];
        } parameterUpdate;
    } data;
} SND_AUX_INFO;

typedef void (*SND_AUX_CALLBACK)(u8 reason, SND_AUX_INFO *info, void *user);

typedef struct SND_STUDIO_INPUT {
    u8 vol;
    u8 volA;
    u8 volB;
    u8 srcStudio;
} SND_STUDIO_INPUT;

typedef struct SND_PARAMETER {
    u8 ctrl;
    union {
        u8 value7;
        u16 value14;
    } paraData;
} SND_PARAMETER;

typedef struct SND_PARAMETER_INFO {
    u8 numPara;
    SND_PARAMETER *paraArray;
} SND_PARAMETER_INFO;

typedef struct SND_ROOM {
    struct SND_ROOM *next;
    struct SND_ROOM *prev;
    u32 flags;
    SND_FVECTOR pos;
    f32 distance;
    u8 studio;
    void (*activateReverb)(u8 studio, void *para);
    void (*deActivateReverb)(u8 studio);
    void *user;
    u32 curMVol;
} SND_ROOM;

typedef struct SND_DOOR {
    struct SND_DOOR *next;
    struct SND_DOOR *prev;
    SND_FVECTOR pos;
    f32 open;
    f32 dampen;
    u8 fxVol;
    u8 destStudio;
    SND_ROOM *a;
    SND_ROOM *b;
    u32 flags;
    s16 filterCoef[4];
    SND_STUDIO_INPUT input;
} SND_DOOR;

typedef struct SND_LISTENER {
    struct SND_LISTENER *next;
    struct SND_LISTENER *prev;
    SND_ROOM *room;
    u32 flags;
    SND_FVECTOR pos;
    f32 volPosOff;
    SND_FVECTOR dir;
    SND_FVECTOR heading;
    SND_FVECTOR right;
    SND_FVECTOR up;
    SND_FMATRIX mat;
    f32 surroundDisFront;
    f32 surroundDisBack;
    f32 soundSpeed;
    f32 vol;
} SND_LISTENER;

typedef struct SND_EMITTER {
    struct SND_EMITTER *next;
    struct SND_EMITTER *prev;
    SND_ROOM *room;
    SND_PARAMETER_INFO *paraInfo;
    u32 flags;
    SND_FVECTOR pos;
    SND_FVECTOR dir;
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
} SND_EMITTER;

typedef struct _SND_CHORUS_SRCINFO {
    s32 *dest;
    s32 *smpBase;
    s32 *old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
    u32 trigger;
    u32 target;
} _SND_CHORUS_SRCINFO;

typedef struct _SND_CHORUS_WORK {
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
    _SND_CHORUS_SRCINFO src;
} _SND_CHORUS_WORK;

typedef struct SND_AUX_CHORUS {
    _SND_CHORUS_WORK work;
    u32 baseDelay;
    u32 variation;
    u32 period;
} SND_AUX_CHORUS;

typedef u32 (*SND_STREAM_UPDATE_CALLBACK)(void *buffer1, u32 len1, void *buffer2, u32 len2, u32 user);

typedef struct SND_ADPCMSTREAM_INFO {
    s16 coefTab[8][2];
} SND_ADPCMSTREAM_INFO;

typedef struct SND_HOOKS {
    void *(*malloc)(u32 addr);
    void (*free)(void *addr);
} SND_HOOKS;

extern "C" {
void sndSetHooks(SND_HOOKS *hooks);
void sndSetAuxProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, u8 midiA, SND_SEQID seqIDA,
                                  SND_AUX_CALLBACK auxB, void *userB, u8 midiB, SND_SEQID seqIDB);
void sndAuxCallbackReverbHI(u8 reason, SND_AUX_INFO *info, void *user);
void sndAuxCallbackChorus(u8 reason, SND_AUX_INFO *info, void *user);
u32 sndAuxCallbackPrepareChorus(SND_AUX_CHORUS *chorus);
u32 sndFXStartParaInfo(u16 fid, u8 vol, u8 pan, u8 studio, SND_PARAMETER_INFO *paraInfo);
u32 sndFXCheck(u32 vid);
s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value);
s32 sndFXKeyOff(s32 vid);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
void sndVolume(u8 volume, u16 time, u8 vGroup);
void sndOutputMode(s32 mode);
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
u32 sndPushGroup(void *prj_data, u16 gid, void *samples, void *sdir, void *pool);
u32 sndPopGroup(void);
}

#endif
