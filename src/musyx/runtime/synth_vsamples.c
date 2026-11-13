#include "types.h"

extern "C" {

typedef struct SND_VIRTUALSAMPLE_INFO {
    u16 smpID;
    u16 instID;
    union {
        struct {
            u32 off1;
            u32 len1;
            u32 off2;
            u32 len2;
        } update;
    } data;
} SND_VIRTUALSAMPLE_INFO;

typedef struct VS_BUFFER {
    u8 state;
    u8 hwId;
    u8 smpType;
    u8 voice;
    u32 last;
    u32 finalGoodSamples;
    u32 finalLast;
    SND_VIRTUALSAMPLE_INFO info;
} VS_BUFFER;

typedef struct VS {
    u8 numBuffers;
    u32 bufferLength;
    VS_BUFFER streamBuffer[64];
    u8 voices[64];
    u16 nextInstID;
    u32 (*callback)(u8, const SND_VIRTUALSAMPLE_INFO *);
} VS;

struct Rec_803A8D2C {
    u8 pad0[0x206];
    u16 curPitch;
    u8 pad208[0x404 - 0x208];
};
extern Rec_803A8D2C *synthVoice;

u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void hwSetVirtualSampleLoopBuffer(s32 i, s32 a, s32 b);
u16 hwGetSampleID(s32 i);
u8 hwGetSampleType(s32 i);
u32 hwGetVirtualSampleState(s32 i);
u32 hwGetPos(s32 arg0);
s32 hwGetVirtualSampleID(u8);
u32 hwVoiceInStartup(s32 i);
void hwBreak(u32);

static VS vs;

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

void vsInit(void) {
    u32 i;
    vs.numBuffers = 0;
    for (i = 0; i < 64; i++) {
        vs.voices[i] = 0xFF;
    }

    vs.nextInstID = 0;
    vs.callback = NULL;
}

static inline u16 vsNewInstanceID(void) {
    u8 i;
    u16 instID;
    do {
        instID = vs.nextInstID++;
        for (i = 0; i < vs.numBuffers; ++i) {
            if (vs.streamBuffer[i].state != 0 && vs.streamBuffer[i].info.instID == instID) {
                break;
            }
        }
    } while (i != vs.numBuffers);

    return instID;
}

static inline u8 vsAllocateBuffer(void) {
    u8 i;

    for (i = 0; i < vs.numBuffers; ++i) {
        if (vs.streamBuffer[i].state != 0) {
            continue;
        }
        vs.streamBuffer[i].state = 1;
        vs.streamBuffer[i].last = 0;
        return i;
    }

    return 0xFF;
}

static inline void vsFreeBuffer(u8 bufferIndex) {
    vs.streamBuffer[bufferIndex].state = 0;
    vs.voices[vs.streamBuffer[bufferIndex].voice] = 0xFF;
}

u32 vsSampleStartNotify(u8 voice) {
    u8 sb;
    u8 i;
    u32 addr;

    for (i = 0; i < vs.numBuffers; ++i) {
        if (vs.streamBuffer[i].state != 0 && vs.streamBuffer[i].voice == voice) {
            vsFreeBuffer(i);
        }
    }

    sb = vs.voices[voice] = vsAllocateBuffer();
    if (sb != 0xFF) {
        addr = aramGetStreamBufferAddress(vs.voices[voice], 0);
        hwSetVirtualSampleLoopBuffer(voice, addr, vs.bufferLength);
        vs.streamBuffer[sb].info.smpID = hwGetSampleID(voice);
        vs.streamBuffer[sb].info.instID = vsNewInstanceID();
        vs.streamBuffer[sb].smpType = hwGetSampleType(voice);
        vs.streamBuffer[sb].voice = voice;
        if (vs.callback != NULL) {
            vs.callback(0, &vs.streamBuffer[sb].info);
            return (vs.streamBuffer[sb].info.instID << 8) | voice;
        }
        hwSetVirtualSampleLoopBuffer(voice, 0, 0);
    } else {
        hwSetVirtualSampleLoopBuffer(voice, 0, 0);
    }

    return 0xFFFFFFFF;
}

void vsSampleEndNotify(u32 pubID) {
    u8 sb;
    u8 voice;

    if (pubID != 0xFFFFFFFF) {
        u8 id = (u8)pubID;
        sb = vs.voices[id];
        if (sb != 0xFF) {
            if (vs.streamBuffer[sb].info.instID == ((pubID >> 8) & 0xFFFF)) {
                if (vs.callback != NULL) {
                    vs.callback(2, &vs.streamBuffer[sb].info);
                }
                vsFreeBuffer(sb);
            }
        }
    }
}

void vsUpdateBuffer(VS_BUFFER *sb, u32 cpos) {
    u32 len;
    if (sb->last == cpos) {
        return;
    }
    if ((s32)sb->last < cpos) {
        switch (sb->smpType) {
        case 5: {
            u32 off = (sb->last / 14) * 8;
            sb->info.data.update.off1 = off;
            sb->info.data.update.len1 = cpos - sb->last;
            sb->info.data.update.off2 = 0;
            sb->info.data.update.len2 = 0;
            if ((len = vs.callback(1, &sb->info)) != 0) {
                sb->last = (sb->last + len) % vs.bufferLength;
            }
        } break;
        default:
            break;
        }
    } else if (cpos == 0) {
        switch (sb->smpType) {
        case 5: {
            u32 off = (sb->last / 14) * 8;
            sb->info.data.update.off1 = off;
            sb->info.data.update.len1 = vs.bufferLength - sb->last;
            sb->info.data.update.off2 = 0;
            sb->info.data.update.len2 = 0;
            if ((len = vs.callback(1, &sb->info)) != 0) {
                sb->last = (sb->last + len) % vs.bufferLength;
            }
        } break;
        default:
            break;
        }
    } else {
        switch (sb->smpType) {
        case 5: {
            u32 off = (sb->last / 14) * 8;
            sb->info.data.update.off1 = off;
            sb->info.data.update.len1 = vs.bufferLength - sb->last;
            sb->info.data.update.off2 = 0;
            sb->info.data.update.len2 = cpos;
            if ((len = vs.callback(1, &sb->info)) != 0) {
                sb->last = (sb->last + len) % vs.bufferLength;
            }
        } break;
        default:
            break;
        }
    }
}

void vsSampleUpdates(void) {
    u32 i;
    u32 cpos;
    u32 realCPos;
    VS_BUFFER *sb;
    u32 nextSamples;

    if (vs.callback == NULL) {
        return;
    }

    for (i = 0; i < 64; ++i) {
        if (vs.voices[i] != 0xFF && hwGetVirtualSampleState(i) != 0) {
            sb = &vs.streamBuffer[vs.voices[i]];
            realCPos = hwGetPos(i);
            if (sb->smpType == 5) {
                cpos = (realCPos / 14) * 14;
            } else {
                cpos = realCPos;
            }

            switch (sb->state) {
            case 1:
                vsUpdateBuffer(sb, cpos);
                break;
            case 2:
                if (((sb->info.instID << 8) | sb->voice) == (u32)hwGetVirtualSampleID(sb->voice)) {
                    vsUpdateBuffer(sb, cpos);

                    if (realCPos >= sb->finalLast) {
                        sb->finalGoodSamples -= (realCPos - sb->finalLast);
                    } else {
                        sb->finalGoodSamples -= (vs.bufferLength - (sb->finalLast - realCPos));
                    }

                    sb->finalLast = realCPos;
                    nextSamples = (synthVoice[sb->voice].curPitch * 160 + 0xFFF) / 4096;
                    if ((s32)nextSamples > (s32)sb->finalGoodSamples) {
                        if (!hwVoiceInStartup(sb->voice)) {
                            hwBreak(sb->voice);
                        }

                        sb->state = 0;
                        vs.voices[sb->voice] = 0xFF;
                    }
                } else {
                    sb->state = 0;
                    vs.voices[sb->voice] = 0xFF;
                }
                break;
            }
        }
    }
}

#pragma pop

}
