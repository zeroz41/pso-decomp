#include "types.h"

extern "C" {

typedef u32 (*SND_STREAM_UPDATE_CALLBACK)(void *buffer1, u32 len1, void *buffer2, u32 len2, u32 user);

typedef struct SND_ADPCMSTREAM_INFO {
    s16 coefTab[8][2];
} SND_ADPCMSTREAM_INFO;

typedef struct ADPCM_INFO {
    u16 numCoef;
    u8 initialPS;
    u8 loopPS;
    s16 loopY0;
    s16 loopY1;
    s16 coefTab[8][2];
} ADPCM_INFO;

typedef struct STREAM_INFO {
    u32 stid;
    u32 flags;
    u8 state;
    u8 type;
    SND_STREAM_UPDATE_CALLBACK updateFunction;
    s16 *buffer;
    u32 size;
    u32 bytes;
    u32 last;
    ADPCM_INFO adpcmInfo;
    u32 voice;
    u32 user;
    u32 frq;
    u8 prio;
    u8 vol;
    u8 pan;
    u8 span;
    u8 auxa;
    u8 auxb;
    u8 orgPan;
    u8 orgSPan;
    u8 studio;
    u8 hwStreamHandle;
    u32 nextStreamHandle;
} STREAM_INFO;

typedef struct SAMPLE_INFO {
    u32 info;
    void *addr;
    void *extraData;
    u32 offset;
    u32 length;
    u32 loop;
    u32 loopLength;
    u8 compType;
} SAMPLE_INFO;

typedef struct SynthInfo_Stream {
    u32 mixFrq;
    u32 numSamples;
    u8 pbInfo[0x208];
    u8 voiceNum;
    u8 maxMusic;
    u8 maxSFX;
    u8 studioNum;
} SynthInfo_Stream;

typedef struct Voice_Stream {
    u8 pad0[0xF4];
    u32 id;
    u8 padF8[0x404 - 0xF8];
} Voice_Stream;

extern SynthInfo_Stream synthInfo;
extern u32 synthFlags;
extern Voice_Stream *synthVoice;

void hwEnableIrq(void);
void hwDisableIrq(void);
void hwSetVolume(u32 v, u8 table, f32 vol, u32 pan, u32 span, f32 auxa, f32 auxb);
u32 hwGetStreamPlayBuffer(u8 i);
void DCInvalidateRange(void *addr, u32 nBytes);
void hwInitSamplePlayback(u32 v, u16 smpID, void *newsmp, u32 set_defadsr, u32 prio, u32 callbackUserValue, u32 setSRC, u8 itdMode);
void hwSetPitch(s32 i, u16 v);
void hwStart(s32, u8);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 i, void *cb, void *arg);
u32 hwGetPos(s32 arg0);
void hwSetStreamLoopPS(s32 i, u8 v);
u8 hwInitStream(u32 size);
void hwExitStream(u8 i);
u32 voiceBlock(u8 prio);
void voiceUnblock(s32);

s32 GetPrivateIndex(u32 arg0);
void CheckOutputMode(s8 *arg0, s8 *arg1);
u32 sndStreamAllocLength(u32 arg0, u32 arg1);
void sndStreamMixParameter(u32 stid, u8 vol, u8 pan, u8 span, u8 fxvol);
void sndStreamMixParameterEx(u32 stid, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb);
void sndStreamFrq(u32 stid, u32 frq);
void sndStreamFree(u32 stid);
u32 sndStreamActivate(u32 stid);
void sndStreamDeactivate(u32 stid);

static STREAM_INFO streamInfo[64];
static u8 streamCallCnt;
static u8 streamCallDelay;
static u32 nextPublicID;

#pragma push
#pragma opt_common_subs on
void streamInit(void) {
    s32 i;
    streamCallCnt = 0;
    streamCallDelay = 3;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        streamInfo[i].state = 0;
    }
    nextPublicID = 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
static void SetHWMix(const STREAM_INFO *si) {
    hwSetVolume(si->voice, 0, si->vol * (1 / 127.f), (si->pan << 16), (si->span << 16), si->auxa * (1 / 127.f), si->auxb * (1 / 127.f));
}

void streamHandle(void) {
    u32 i;
    u32 cpos;
    u32 len;
    SAMPLE_INFO newsmp;
    STREAM_INFO *si;
    float f;

    if (streamCallCnt != 0) {
        --streamCallCnt;
        return;
    }
    streamCallCnt = streamCallDelay;
    si = &streamInfo[0];
    for (i = 0; i < synthInfo.voiceNum; ++i, ++si) {
        switch (si->state) {
        case 1:
            newsmp.info = si->frq | 0x40000000;
            newsmp.addr = (void *)hwGetStreamPlayBuffer(si->hwStreamHandle);
            newsmp.offset = 0;
            newsmp.length = si->size;
            newsmp.loop = 0;
            newsmp.loopLength = si->size;
            si->adpcmInfo.loopPS = si->adpcmInfo.initialPS = *(u8 *)si->buffer;
            DCInvalidateRange(si->buffer, 1);
            switch (si->type) {
            case 0:
                newsmp.compType = 2;
                break;
            case 1:
                newsmp.extraData = &si->adpcmInfo;
                newsmp.compType = 4;
                break;
            }
            hwInitSamplePlayback(si->voice, -1, &newsmp, 1, -1, synthVoice[si->voice].id, 1, 1);
            f = (si->frq / (float)synthInfo.mixFrq);
            hwSetPitch(si->voice, f * 4096.f);
            SetHWMix(si);
            hwStart(si->voice, si->studio);
            si->state = 2;
            if (!(si->flags & 0x20000)) {
                hwFlushStream((u8 *)si->buffer, 0, si->bytes, si->hwStreamHandle, 0, 0);
            }
            break;
        case 2: {
            cpos = hwGetPos(si->voice);

            if (si->type == 1) {
                cpos = (cpos / 14) * 14;
            }

            if (si->last != cpos) {
                if (si->last < cpos) {
                    switch (si->type) {
                    case 0: {
                        if ((len = si->updateFunction(si->buffer + si->last, cpos - si->last, 0, 0, si->user)) != 0 &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (cpos != 0) {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (cpos - si->last) * 2, si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (si->size - si->last) * 2, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                    } break;
                    case 1: {
                        u32 off = (si->last / 14) * 8;
                        if ((len = si->updateFunction((void *)((u32)si->buffer + off), cpos - si->last, 0, 0, si->user)) != 0 &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (cpos != 0) {
                                    hwFlushStream((u8 *)si->buffer, off, ((cpos + 13) / 14) * 8 - off, si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, off, (si->bytes) - off, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                    } break;
                    }
                } else if (cpos == 0) {
                    switch (si->type) {
                    case 0:
                        if ((len = si->updateFunction(si->buffer + si->last, si->size - si->last, 0, 0, si->user)) &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (cpos == 0) {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, si->bytes - (si->last * 2), si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (cpos - si->last) * 2, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                        break;
                    case 1: {
                        u32 off = ((si->last / 14) * 8);
                        if ((len = si->updateFunction((void *)((u32)si->buffer + off), si->size - si->last, 0, 0, si->user)) &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (cpos == 0) {
                                    hwFlushStream((u8 *)si->buffer, off, si->bytes - off, si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, off, ((cpos + 13) / 14) * 8 - off, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                    } break;
                    }
                } else {
                    switch (si->type) {
                    case 0:
                        if ((len = si->updateFunction(si->buffer + si->last, si->size - si->last, si->buffer, cpos, si->user)) &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (len > si->size - si->last) {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (si->bytes - si->last * 2), si->hwStreamHandle, 0, 0);
                                    hwFlushStream((u8 *)si->buffer, 0, cpos * 2, si->hwStreamHandle, 0, 0);
                                } else if (cpos == 0) {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (si->bytes - si->last * 2), si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, si->last * 2, (cpos - si->last) * 2, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                        break;
                    case 1: {
                        u32 off = (si->last / 14) * 8;
                        if ((len = si->updateFunction((void *)((u32)si->buffer + off), si->size - si->last, si->buffer, cpos, si->user)) &&
                            si->state == 2) {
                            cpos = (si->last + len) % si->size;
                            if (!(si->flags & 0x20000)) {
                                if (len > si->size - si->last) {
                                    hwFlushStream((u8 *)si->buffer, off, si->bytes - off, si->hwStreamHandle, 0, 0);
                                    hwFlushStream((u8 *)si->buffer, 0, (cpos / 14) << 3, si->hwStreamHandle, 0, 0);
                                } else if (cpos == 0) {
                                    hwFlushStream((u8 *)si->buffer, off, si->bytes - off, si->hwStreamHandle, 0, 0);
                                } else {
                                    hwFlushStream((u8 *)si->buffer, off, ((cpos + 13) / 14) * 8 - off, si->hwStreamHandle, 0, 0);
                                }
                            }
                            si->last = cpos;
                        }
                    } break;
                    }
                }

                if (si->state == 2 && !(si->flags & 0x20000) && si->type == 1) {
                    hwSetStreamLoopPS(si->voice, *(u32 *)((u8 *)si->buffer + 0x40000000) >> 24);
                }
            }
        } break;
        }
    }
}
#pragma pop

void streamCorrectLoops(void) {

}

void streamKill(s32 arg0) {
    STREAM_INFO *r = &streamInfo[arg0];

    switch (r->state) {
    case 1:
    case 2:
        if (r->state == 2) {
            voiceUnblock(r->voice);
        }
        r->state = 3;
        r->updateFunction(0, 0, 0, 0, r->user);
        break;
    }
}

s32 GetPrivateIndex(u32 arg0) {
    STREAM_INFO *r = streamInfo;
    s32 i;

    for (i = 0; i < 64; r++, i++) {
        if (r->state != 0 && arg0 == r->stid) {
            return i;
        }
    }
    return -1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803AB2C8(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

void sndStreamARAMUpdate(u32 stid, u32 off1, u32 len1, u32 off2, u32 len2) {
    u32 i;

    hwDisableIrq();
    i = GetPrivateIndex_803AB2C8(stid);
    if (i != -1) {
        switch (streamInfo[i].type) {
        case 0:
            off1 *= 2;
            len1 *= 2;
            off2 *= 2;
            len2 *= 2;
            break;
        case 1:
            off1 = (off1 / 14) * 8;
            len1 = ((len1 + 13) / 14) * 8;
            off2 = (off2 / 14) * 8;
            len2 = ((len2 + 13) / 14) * 8;
            break;
        }

        if (len1 != 0) {
            hwFlushStream((u8 *)streamInfo[i].buffer, off1, len1, streamInfo[i].hwStreamHandle, 0, 0);
        }

        if (len2 != 0) {
            hwFlushStream((u8 *)streamInfo[i].buffer, off2, len2, streamInfo[i].hwStreamHandle, 0, 0);
        }

        if (streamInfo[i].type == 1) {
            hwSetStreamLoopPS(streamInfo[i].voice, *(u32 *)((u8 *)streamInfo[i].buffer + 0x40000000) >> 24);
        }
    }
    hwEnableIrq();
}
#pragma pop

void CheckOutputMode(s8 *arg0, s8 *arg1) {
    if (synthFlags & 1) {
        *arg0 = 0x40;
        *arg1 = 0;
        return;
    }
    if (!(synthFlags & 2)) {
        *arg1 = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline void CheckOutputMode_803AB5A8(u8 *pan, u8 *span) {
    if (synthFlags & 1) {
        *pan = 64;
        *span = 0;
    } else if (!(synthFlags & 2)) {
        *span = 0;
    }
}

void streamOutputModeChanged(void) {
    u32 i;

    hwDisableIrq();
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        if (streamInfo[i].state != 0) {
            streamInfo[i].pan = streamInfo[i].orgPan;
            streamInfo[i].span = streamInfo[i].orgSPan;
            CheckOutputMode_803AB5A8(&streamInfo[i].pan, &streamInfo[i].span);
            if (streamInfo[i].state != 3) {
                SetHWMix(&streamInfo[i]);
            }
        }
    }
    hwEnableIrq();
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GeneratePublicID_803AB6F0(void) {
    u32 id;
    u32 i;

    do {
        if ((id = nextPublicID++) == -1) {
            id = nextPublicID++;
        }
        for (i = 0; i < 64; ++i) {
            if (streamInfo[i].state != 0 && id == streamInfo[i].stid) {
                break;
            }
        }
    } while (i != 64);

    return id;
}

static inline void CheckOutputMode_803AB6F0(u8 *pan, u8 *span) {
    if (synthFlags & 1) {
        *pan = 64;
        *span = 0;
    } else if (!(synthFlags & 2)) {
        *span = 0;
    }
}

static inline void SetupVolumeAndPan_803AB6F0(STREAM_INFO *si, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    si->orgPan = pan;
    si->orgSPan = span;
    CheckOutputMode_803AB6F0(&pan, &span);
    si->vol = vol;
    si->pan = pan;
    si->span = span;
    si->auxa = auxa;
    si->auxb = auxb;
}

u32 sndStreamAllocEx(u8 prio, void *buffer, u32 samples, u32 frq, u8 vol, u8 pan, u8 span,
                         u8 auxa, u8 auxb, u8 studio, u32 flags, SND_STREAM_UPDATE_CALLBACK updateFunction,
                         u32 user, SND_ADPCMSTREAM_INFO *adpcmInfo) {
    u32 stid;
    u32 i;
    u32 bytes;
    u32 j;

    hwDisableIrq();

    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state == 0) {
            break;
        }
    }

    if (i != 64) {
        stid = GeneratePublicID_803AB6F0();
        streamInfo[i].stid = stid;
        streamInfo[i].flags = flags;
        bytes = sndStreamAllocLength(samples, flags);
        streamInfo[i].buffer = (s16 *)buffer;
        streamInfo[i].size = samples;
        streamInfo[i].bytes = bytes;
        streamInfo[i].updateFunction = updateFunction;
        streamInfo[i].voice = -1;
        if (flags & 1) {
            if (adpcmInfo != 0) {
                for (j = 0; j < 8; j++) {
                    streamInfo[i].adpcmInfo.coefTab[j][0] = adpcmInfo->coefTab[j][0];
                    streamInfo[i].adpcmInfo.coefTab[j][1] = adpcmInfo->coefTab[j][1];
                }
                streamInfo[i].adpcmInfo.numCoef = 8;
            }
            streamInfo[i].type = 1;
        } else {
            streamInfo[i].type = 0;
        }

        streamInfo[i].frq = frq;
        streamInfo[i].studio = studio;
        streamInfo[i].prio = prio;
        SetupVolumeAndPan_803AB6F0(&streamInfo[i], vol, pan, span, auxa, auxb);
        streamInfo[i].user = user;
        streamInfo[i].nextStreamHandle = -1;
        streamInfo[i].state = 3;
        if ((streamInfo[i].hwStreamHandle = hwInitStream(bytes)) != 0xFF) {
            if (!(flags & 0x10000) && !sndStreamActivate(stid)) {
                stid = -1;
            }
        } else {
            stid = -1;
        }
        if (stid == -1) {
            streamInfo[i].state = 0;
        }
    } else {
        stid = -1;
    }

    hwEnableIrq();

    return stid;
}
#pragma pop

u32 sndStreamAllocLength(u32 arg0, u32 arg1) {
    if (arg1 & 1) {
        return (((arg0 + 13) / 7 * 4 & ~7) + 31) & ~31;
    }
    return ((arg0 * 2) + 31) & ~31;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803ABB54(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

static inline void CheckOutputMode_803ABB54(u8 *pan, u8 *span) {
    if (synthFlags & 1) {
        *pan = 64;
        *span = 0;
    } else if (!(synthFlags & 2)) {
        *span = 0;
    }
}

static inline void SetupVolumeAndPan_803ABB54(STREAM_INFO *si, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    si->orgPan = pan;
    si->orgSPan = span;
    CheckOutputMode_803ABB54(&pan, &span);
    si->vol = vol;
    si->pan = pan;
    si->span = span;
    si->auxa = auxa;
    si->auxb = auxb;
}

static inline void SetupVolumeAndPan2_803ABB54(STREAM_INFO *si, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    si->orgPan = pan;
    si->orgSPan = span;
    CheckOutputMode((s8 *)&pan, (s8 *)&span);
    si->vol = vol;
    si->pan = pan;
    si->span = span;
    si->auxa = auxa;
    si->auxb = auxb;
}

static inline void MixParameterInner_803ABB54(u32 stid, u8 vol, u8 pan, u8 span, u8 fxvol) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex(stid);
    if (i != -1) {
        SetupVolumeAndPan2_803ABB54(&streamInfo[i], vol, pan, span, fxvol, 0);
        SetHWMix(&streamInfo[i]);
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            sndStreamMixParameter(streamInfo[i].nextStreamHandle, vol, pan, span, fxvol);
        }
    }
    hwEnableIrq();
}

void sndStreamMixParameter(u32 stid, u8 vol, u8 pan, u8 span, u8 fxvol) {
    u32 i;

    hwDisableIrq();
    i = GetPrivateIndex_803ABB54(stid);
    if (i != -1) {
        SetupVolumeAndPan_803ABB54(&streamInfo[i], vol, pan, span, fxvol, 0);
        SetHWMix(&streamInfo[i]);
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            MixParameterInner_803ABB54(streamInfo[i].nextStreamHandle, vol, pan, span, fxvol);
        }
    }
    hwEnableIrq();
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803ABECC(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

static inline void CheckOutputMode_803ABECC(u8 *pan, u8 *span) {
    if (synthFlags & 1) {
        *pan = 64;
        *span = 0;
    } else if (!(synthFlags & 2)) {
        *span = 0;
    }
}

static inline void SetupVolumeAndPan_803ABECC(STREAM_INFO *si, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    si->orgPan = pan;
    si->orgSPan = span;
    CheckOutputMode_803ABECC(&pan, &span);
    si->vol = vol;
    si->pan = pan;
    si->span = span;
    si->auxa = auxa;
    si->auxb = auxb;
}

static inline void SetupVolumeAndPan2_803ABECC(STREAM_INFO *si, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    si->orgPan = pan;
    si->orgSPan = span;
    CheckOutputMode((s8 *)&pan, (s8 *)&span);
    si->vol = vol;
    si->pan = pan;
    si->span = span;
    si->auxa = auxa;
    si->auxb = auxb;
}

static inline void MixParameterInner_803ABECC(u32 stid, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex(stid);
    if (i != -1) {
        SetupVolumeAndPan2_803ABECC(&streamInfo[i], vol, pan, span, auxa, auxb);
        if (streamInfo[i].state == 2) {
            SetHWMix(&streamInfo[i]);
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            sndStreamMixParameterEx(streamInfo[i].nextStreamHandle, vol, pan, span, auxa, auxb);
        }
    }
    hwEnableIrq();
}

void sndStreamMixParameterEx(u32 stid, u8 vol, u8 pan, u8 span, u8 auxa, u8 auxb) {
    u32 i;

    hwDisableIrq();
    i = GetPrivateIndex_803ABECC(stid);
    if (i != -1) {
        SetupVolumeAndPan_803ABECC(&streamInfo[i], vol, pan, span, auxa, auxb);
        if (streamInfo[i].state == 2) {
            SetHWMix(&streamInfo[i]);
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            MixParameterInner_803ABECC(streamInfo[i].nextStreamHandle, vol, pan, span, auxa, auxb);
        }
    }
    hwEnableIrq();
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803AC268(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

void hwSetPitch(s32 i, u16 v);
void sndStreamFrq(u32 stid, u32 frq);

static inline void FrqInner_803AC268(u32 stid, u32 frq) {
    u32 i;
    u16 pitch;

    hwDisableIrq();
    if ((i = GetPrivateIndex(stid)) != -1) {
        streamInfo[i].frq = frq;
        if (streamInfo[i].state == 2) {
            pitch = (4096.f * frq) / synthInfo.mixFrq;
            hwSetPitch(streamInfo[i].voice, pitch);
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            sndStreamFrq(streamInfo[i].nextStreamHandle, frq);
        }
    }
    hwEnableIrq();
}

void sndStreamFrq(u32 stid, u32 frq) {
    u32 i;
    u16 pitch;

    hwDisableIrq();
    if ((i = GetPrivateIndex_803AC268(stid)) != -1) {
        streamInfo[i].frq = frq;
        if (streamInfo[i].state == 2) {
            pitch = (4096.f * frq) / synthInfo.mixFrq;
            hwSetPitch(streamInfo[i].voice, pitch);
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            FrqInner_803AC268(streamInfo[i].nextStreamHandle, frq);
        }
    }
    hwEnableIrq();
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803AC510(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

void sndStreamDeactivate(u32 stid);
void hwExitStream(u8 i);
void sndStreamFree(u32 stid);

static inline void FreeInner_803AC510(u32 stid) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex(stid);
    if (i != -1) {
        sndStreamDeactivate(stid);
        hwExitStream(streamInfo[i].hwStreamHandle);
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            sndStreamFree(streamInfo[i].nextStreamHandle);
        }
        streamInfo[i].state = 0;
    }
    hwEnableIrq();
}

void sndStreamFree(u32 stid) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex_803AC510(stid);
    if (i != -1) {
        sndStreamDeactivate(stid);
        hwExitStream(streamInfo[i].hwStreamHandle);
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            FreeInner_803AC510(streamInfo[i].nextStreamHandle);
        }
        streamInfo[i].state = 0;
    }
    hwEnableIrq();
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803AC720(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

u32 voiceBlock(u8 prio);

u32 sndStreamActivate(u32 stid) {
    u32 i;
    u32 ret = 0;

    hwDisableIrq();
    i = GetPrivateIndex_803AC720(stid);
    if (i != -1) {
        if (streamInfo[i].state == 3) {
            if ((streamInfo[i].voice = voiceBlock(streamInfo[i].prio)) == -1) {
                hwEnableIrq();
                return 0;
            }

            streamInfo[i].last = 0;
            streamInfo[i].state = 1;
        }

        if (streamInfo[i].nextStreamHandle != -1) {
            ret = sndStreamActivate(streamInfo[i].nextStreamHandle);
        } else {
            ret = 1;
        }
    }
    hwEnableIrq();
    return ret;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 GetPrivateIndex_803AC920(u32 publicID) {
    u32 i;
    for (i = 0; i < 64; ++i) {
        if (streamInfo[i].state != 0 && publicID == streamInfo[i].stid) {
            return i;
        }
    }
    return -1;
}

void voiceUnblock(s32);
void sndStreamDeactivate(u32 stid);

static inline void DeactivateInner_803AC920(u32 stid) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex(stid);
    if (i != -1) {
        if (streamInfo[i].state == 1 || streamInfo[i].state == 2) {
            voiceUnblock(streamInfo[i].voice);
            streamInfo[i].state = 3;
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            sndStreamDeactivate(streamInfo[i].nextStreamHandle);
        }
    }
    hwEnableIrq();
}

void sndStreamDeactivate(u32 stid) {
    u32 i;
    hwDisableIrq();
    i = GetPrivateIndex_803AC920(stid);
    if (i != -1) {
        if (streamInfo[i].state == 1 || streamInfo[i].state == 2) {
            voiceUnblock(streamInfo[i].voice);
            streamInfo[i].state = 3;
        }
        if (streamInfo[i].nextStreamHandle != 0xffffffff) {
            DeactivateInner_803AC920(streamInfo[i].nextStreamHandle);
        }
    }
    hwEnableIrq();
}
#pragma pop
}
