#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

typedef struct SynthVoiceList {
    u8 prev;
    u8 next;
    u16 user;
} SynthVoiceList;

typedef struct SynthRootList {
    u16 next;
    u16 prev;
} SynthRootList;

static SynthVidList vidList[128];
static u8 synth_last_started[8][16];
static u8 synth_last_fxstarted[64];
static SynthVoiceList voicePrioSortVoices[64];
static u8 voicePrioSortVoicesRoot[256];
static SynthRootList voicePrioSortRootList[256];
static SynthVoiceList voiceList[64];

#define VID_UNLINK(n)                              \
    {                                              \
        SynthVidList *q = (n)->prev;               \
        if (q != NULL) {                           \
            q->next = (n)->next;                   \
        } else {                                   \
            vidRoot = (n)->next;                   \
        }                                          \
    }                                              \
    {                                              \
        SynthVidList *q = (n)->next;               \
        if (q != NULL) {                           \
            q->prev = (n)->prev;                   \
        }                                          \
    }

#define VID_PUSH_FREE(n)                           \
    (n)->next = vidFree;                           \
    if (vidFree != NULL) {                         \
        vidFree->prev = (n);                       \
    }                                              \
    (n)->prev = NULL;                              \
    vidFree = (n);

extern "C" {
u32 vidCurrentId;
SynthVidList *vidRoot;
SynthVidList *vidFree;
u16 voicePrioSortRootListRoot;
u8 voiceMusicRunning;
u8 voiceFxRunning;
u8 voiceListInsert;
u8 voiceListRoot;
}
extern "C" {

void vidInit(void) {
    s32 i;
    SynthVidList *n;
    SynthVidList *prev;

    n = vidList;
    vidFree = n;
    vidCurrentId = 0;
    vidRoot = NULL;
    prev = NULL;
    for (i = 0; i < 128; i++) {
        n->prev = prev;
        if (prev != NULL) {
            prev->next = n;
        }
        prev = n;
        n++;
    }
    prev->next = NULL;
}

SynthVidList *get_vidlist(u32 key) {
    SynthVidList *n;
    for (n = vidRoot; n != 0; n = n->next) {
        if (n->vid == key) {
            return n;
        }
        if (n->vid > key) {
            break;
        }
    }
    return 0;
}

void vidRemoveVoiceReferences(SynthVoice *p) {
    if (p->id != 0xFFFFFFFF) {
        voiceResetLastStarted(p);
        if (p->parent != 0xFFFFFFFF) {
            synthVoice[(u8)p->parent].child = p->child;
            if (p->child != 0xFFFFFFFF) {
                synthVoice[(u8)p->child].parent = p->parent;
            }
            VID_UNLINK(p->vidList)
            VID_PUSH_FREE(p->vidList)
            p->vidList = NULL;
        } else if (p->child != 0xFFFFFFFF) {
            p->vidList->root = p->child;
            synthVoice[(u8)p->child].parent = 0xFFFFFFFF;
            synthVoice[(u8)p->child].vidMasterList = p->vidMasterList;
            if (p->vidList != p->vidMasterList) {
                VID_UNLINK(p->vidList)
                VID_PUSH_FREE(p->vidList)
                p->vidList = NULL;
            }
            p->vidList = NULL;
            p->vidMasterList = NULL;
        } else if (p->vidList != p->vidMasterList) {
            VID_UNLINK(p->vidList)
            VID_PUSH_FREE(p->vidList)
            p->vidList = NULL;
            VID_UNLINK(p->vidMasterList)
            VID_PUSH_FREE(p->vidMasterList)
            p->vidMasterList = NULL;
        } else {
            VID_UNLINK(p->vidList)
            VID_PUSH_FREE(p->vidList)
            p->vidList = NULL;
            p->vidMasterList = NULL;
        }
    }
}

u32 vidMakeRoot(SynthVoice *svoice) {
    svoice->vidMasterList = svoice->vidList;
    return svoice->vidList->vid;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

static inline u32 get_newvid(void) {
    u32 vid;
    do {
        vid = vidCurrentId++;
    } while (vid == 0xFFFFFFFF);

    return vid;
}

u32 vidMakeNew(SynthVoice *svoice, u32 isMaster) {
    u32 vid;
    SynthVidList *nvl;
    SynthVidList *lvl;
    SynthVidList *vl;

    vid = get_newvid();
    lvl = NULL;
    nvl = vidRoot;

    while (nvl != NULL) {
        if (nvl->vid > vid) {
            break;
        }

        if (nvl->vid == vid) {
            vid = get_newvid();
        }
        lvl = nvl;
        nvl = nvl->next;
    }

    if ((vl = vidFree) == NULL) {
        return 0xFFFFFFFF;
    }

    if ((vidFree = vidFree->next) != NULL) {
        vidFree->prev = NULL;
    }

    if (lvl == NULL) {
        vidRoot = vl;
    } else {
        lvl->next = vl;
    }

    vl->prev = lvl;
    vl->next = nvl;

    if (nvl != NULL) {
        nvl->prev = vl;
    }

    vl->vid = vid;
    vl->root = svoice->id;
    svoice->vidMasterList = isMaster ? vl : NULL;
    svoice->vidList = vl;

    return isMaster ? vid : svoice->id;
}

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline SynthVidList *find_vid_node(u32 id) {
    SynthVidList *p;
    for (p = vidRoot; p != 0; p = p->next) {
        if (p->vid == id) {
            return p;
        }
        if (p->vid > id) {
            break;
        }
    }
    return 0;
}
u32 vidGetInternalId(u32 vid) {
    if (vid != 0xFFFFFFFF) {
        SynthVidList *p = find_vid_node(vid);
        if (p != 0) {
            return p->root;
        }
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
void voiceRemovePriority(SynthVoice *svoice) {
    SynthVoiceList *vps;
    SynthRootList *rps;

    vps = &voicePrioSortVoices[svoice->id & 0xFF];
    if (vps->user != 1) {
        return;
    }

    if (vps->prev != 0xFF) {
        voicePrioSortVoices[vps->prev].next = vps->next;
    } else {
        voicePrioSortVoicesRoot[svoice->prio] = vps->next;
    }

    if (vps->next != 0xFF) {
        voicePrioSortVoices[vps->next].prev = vps->prev;
    } else if (vps->prev == 0xFF) {
        rps = &voicePrioSortRootList[svoice->prio];

        if (rps->prev != 0xFFFF) {
            voicePrioSortRootList[rps->prev].next = rps->next;
        } else {
            voicePrioSortRootListRoot = rps->next;
        }

        if (rps->next != 0xFFFF) {
            voicePrioSortRootList[rps->next].prev = rps->prev;
        }
    }

    vps->user = 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on

void voiceSetPriority(SynthVoice *svoice, u8 prio) {
    u32 v;
    u16 li;
    SynthVoiceList *vps;
    u16 i;
    v = svoice->id & 0xFF;
    vps = &voicePrioSortVoices[v];
    if (vps->user == 1) {
        if (svoice->prio == prio) {
            return;
        }

        voiceRemovePriority(svoice);
    }

    vps->user = 1;
    vps->prev = 0xff;
    if ((vps->next = voicePrioSortVoicesRoot[prio]) != 0xFF) {
        voicePrioSortVoices[voicePrioSortVoicesRoot[prio]].prev = v;
    } else if (voicePrioSortRootListRoot != 0xFFFF) {
        if (prio >= voicePrioSortRootListRoot) {
            for (i = voicePrioSortRootListRoot; i != 0xFFFF; i = voicePrioSortRootList[i].next) {
                if ((u16)i > prio) {
                    break;
                }
                li = i;
            }

            voicePrioSortRootList[li].next = (u16)prio;
            voicePrioSortRootList[prio].prev = li;
            voicePrioSortRootList[prio].next = i;
            if (i != 0xFFFF) {
                voicePrioSortRootList[i].prev = prio;
            }

        } else {
            voicePrioSortRootList[prio].next = voicePrioSortRootListRoot;
            voicePrioSortRootList[prio].prev = 0xFFFF;
            voicePrioSortRootList[voicePrioSortRootListRoot].prev = prio;
            voicePrioSortRootListRoot = prio;
        }
    } else {
        voicePrioSortRootList[prio].next = 0xFFFF;
        voicePrioSortRootList[prio].prev = 0xFFFF;
        voicePrioSortRootListRoot = prio;
    }

    voicePrioSortVoicesRoot[prio] = v;
    svoice->prio = prio;
    hwSetPriority(svoice->id & 0xFF, ((u32)prio << 24) | (svoice->age >> 15));
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off

u32 voiceAllocate(u8 priority, u8 maxVoices, u16 allocId, u8 fxFlag) {
    s32 i;
    s32 num;
    s32 voice;
    u16 p;
    u32 type_alloc;
    SynthVoiceList *sfv;

    if (!synthIdleWaitActive) {
        if (fxFlag) {
            type_alloc = (voiceFxRunning >= synthInfo.maxSFX && synthInfo.voiceNum > synthInfo.maxSFX);

            if (synthInfo.maxSFX <= maxVoices) {
                goto _skip_alloc;
            }

            goto _do_alloc;
        } else {
            type_alloc = (voiceMusicRunning >= synthInfo.maxMusic && synthInfo.voiceNum > synthInfo.maxMusic);

            if (synthInfo.maxMusic <= maxVoices) {
                goto _skip_alloc;
            }

        _do_alloc:
            num = 0;
            voice = -1;

            p = voicePrioSortRootListRoot;
            while (p != 0xFFFF && priority >= p && voice == -1) {
                for (i = voicePrioSortVoicesRoot[p]; i != 0xff; i = voicePrioSortVoices[i].next) {
                    if (allocId != synthVoice[i].allocId)
                        continue;
                    ++num;
                    if (synthVoice[i].block)
                        continue;

                    if (!type_alloc || fxFlag == synthVoice[i].fxFlag) {
                        if ((synthVoice[i].cFlags & 2))
                            continue;
                        if (voice != -1) {
                            if (synthVoice[i].age < synthVoice[voice].age)
                                voice = i;
                        } else
                            voice = i;
                    }
                }

                p = voicePrioSortRootList[p].next;
            }
        }

        if (num < maxVoices) {
            while (p != 0xffff && num < maxVoices) {
                i = voicePrioSortVoicesRoot[p];
                while (i != 0xff) {
                    if (allocId == synthVoice[i].allocId) {
                        num++;
                    }

                    i = voicePrioSortVoices[i].next;
                }

                p = voicePrioSortRootList[p].next;
            }

            if (num < maxVoices) {
            _skip_alloc:
                voice = -1;
                if (voiceListRoot != 0xff && type_alloc == 0) {
                    voice = voiceListRoot;
                    goto _update;
                }

                if (priority < voicePrioSortRootListRoot) {
                    return -1;
                }
                p = voicePrioSortRootListRoot;

                while (p != 0xFFFF && priority >= p && voice == -1) {
                    for (i = voicePrioSortVoicesRoot[p]; i != 0xff; i = voicePrioSortVoices[i].next) {
                        if (synthVoice[i].block != 0)
                            continue;

                        if (!type_alloc || fxFlag == synthVoice[i].fxFlag) {
                            if ((synthVoice[i].cFlags & 2))
                                continue;
                            if (voice != -1) {
                                if (synthVoice[voice].age > synthVoice[i].age)
                                    voice = i;
                            } else
                                voice = i;
                        }
                    }
                    p = voicePrioSortRootList[p].next;
                }

                if (voice == -1) {
                    return 0xffffffff;
                }

            _update:
                if (synthVoice[voice].prio > priority) {
                    goto _fail;
                }
            }
        }

        if (voice == -1) {
            goto _fail;
        }

        if (voiceList[voice].user == 1) {
            sfv = voiceList + voice;
            i = sfv->prev;

            if (i != 0xff) {
                voiceList[i].next = sfv->next;
            } else {
                voiceListRoot = sfv->next;
            }

            i = sfv->next;
            if (i != 0xff) {
                voiceList[i].prev = sfv->prev;
            }

            if (voice == voiceListInsert) {
                voiceListInsert = sfv->prev;
            }

            sfv->user = 0;
        } else if (synthVoice[voice].fxFlag) {
            voiceFxRunning--;
        } else {
            voiceMusicRunning--;
        }
        if (fxFlag != 0) {
            ++voiceFxRunning;
        } else {
            ++voiceMusicRunning;
        }
        return voice;
    }

_fail:
    return -1;
}

#pragma pop

#pragma push
#pragma pool_data off
void voiceFree(SynthVoice *o) {
    u8 idx;
    SynthVoiceList *e;

    macMakeInactive(o, 2);
    voiceRemovePriority(o);
    o->addr = NULL;
    o->prio = 0;
    idx = o->id;
    e = &voiceList[(u8)o->id];
    if (e->user == 0) {
        e->user = 1;
        if (voiceListRoot != 0xFF) {
            e->next = 0xFF;
            e->prev = voiceListInsert;
            voiceList[voiceListInsert].next = idx;
        } else {
            e->next = 0xFF;
            e->prev = 0xFF;
            voiceListRoot = idx;
        }
        voiceListInsert = idx;
        if (o->fxFlag != 0) {
            voiceFxRunning--;
        } else {
            voiceMusicRunning--;
        }
    }
    o->id = -1;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

static inline void voiceInitPrioSort(void) {
    u32 i;

    for (i = 0; i < synthInfo.voiceNum; ++i) {
        voicePrioSortVoices[i].user = 0;
    }

    for (i = 0; i < 256; ++i) {
        voicePrioSortVoicesRoot[i] = 0xff;
    }

    voicePrioSortRootListRoot = 0xffff;
}

static inline void voiceInitFreeList(void) {
    u32 i;

    for (i = 0; i < synthInfo.voiceNum; ++i) {
        voiceList[i].prev = i - 1;
        voiceList[i].next = i + 1;
        voiceList[i].user = 1;
    }

    voiceList[0].prev = 0xff;
    voiceList[synthInfo.voiceNum - 1].next = 0xff;
    voiceListRoot = 0;
    voiceListInsert = synthInfo.voiceNum - 1;
}

void synthInitAllocationAids(void) {
    voiceInitFreeList();
    voiceInitPrioSort();
    voiceFxRunning = 0;
    voiceMusicRunning = 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on

u32 voiceBlock(u8 prio) {
    u32 voice;

    if ((voice = voiceAllocate(prio, 0xFF, 0xFFFF, 1)) != 0xFFFFFFFF) {
        synthVoice[voice].block = 1;
        synthVoice[voice].fxFlag = 1;

        vidRemoveVoiceReferences(&synthVoice[voice]);
        synthVoice[voice].id = voice | 0xFFFFFF00;

        if (hwIsActive(voice)) {
            hwBreak(voice);
        }

        macMakeInactive(&synthVoice[voice], 2);
        synthVoice[voice].addr = NULL;
        voiceSetPriority(&synthVoice[voice], prio);
    }

    return voice;
}

#pragma pop

#pragma push
#pragma opt_common_subs on

void voiceUnblock(s32 voice) {
    if (voice == 0xFFFFFFFF) {
        return;
    }

    if (hwIsActive(voice)) {
        hwBreak(voice);
    }

    synthVoice[voice].id = voice;
    voiceFree(&synthVoice[voice]);
    synthVoice[voice].block = 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on

void voiceKill(u32 vi) {
    SynthVoice *sv = &synthVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences(sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree(sv);
    }

    if (sv->block != 0) {
        streamKill(vi);
    }

    hwBreak(vi);
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

static inline u32 vidGetInternalIdInline(u32 vid) {
    SynthVidList *vl;

    if (vid != 0xffffffff) {
        if ((vl = get_vidlist(vid)) != NULL) {
            return vl->root;
        }
    }

    return 0xffffffff;
}

static inline void voiceKillInline(u32 vi) {
    SynthVoice *sv = &synthVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences(sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree(sv);
    }

    if (sv->block != 0) {
        streamKill(vi);
    }

    hwBreak(vi);
}

s32 voiceKillSound(u32 voiceid) {
    s32 ret = -1;
    u32 next_voiceid;
    u32 i;
    if (sndActive != 0) {
        for (voiceid = vidGetInternalIdInline(voiceid); voiceid != -1; voiceid = next_voiceid) {
            i = voiceid & 0xff;
            next_voiceid = synthVoice[i].child;
            if (voiceid == synthVoice[i].id) {
                voiceKillInline(i);
                ret = 0;
            }
        }
    }

    return ret;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

static inline void voiceKillByMacroInline(u32 vi) {
    SynthVoice *sv = &synthVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences(sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree(sv);
    }

    if (sv->block != 0) {
        streamKill(vi);
    }

    hwBreak(vi);
}

void synthKillVoicesByMacroReferences(u16 *ref) {
    u32 i;
    u16 id;

    for (i = 0; i < synthInfo.voiceNum; ++i) {
        if (synthVoice[i].addr == NULL && synthVoice[i].block == 0) {
            voiceKillByMacroInline(i);
        }
    }

    while (*ref != 0xFFFF) {
        if ((*ref & 0x8000)) {
            id = *ref & 0x3fff;
            while (id <= ref[1]) {
                for (i = 0; i < synthInfo.voiceNum; ++i) {
                    if (synthVoice[i].addr != NULL && id == synthVoice[i].macroId) {
                        voiceKillByMacroInline(i);
                    }
                }
                ++id;
            }
            ref += 2;
        } else {
            for (i = 0; i < synthInfo.voiceNum; ++i) {
                if (synthVoice[i].addr != NULL && *ref == synthVoice[i].macroId) {
                    voiceKillByMacroInline(i);
                }
            }
            ++ref;
        }
    }
}

#pragma pop

#pragma push
#pragma pool_data off
s32 voiceIsLastStarted(SynthVoice *svoice) {
    u32 id = svoice->id;
    if (id != 0xFFFFFFFF) {
        u8 a = svoice->midi;
        if (a != 0xFF) {
            u8 b = svoice->midiSet;
            u8 v = id;
            if (b == 0xFF) {
                if (synth_last_fxstarted[v] == v) {
                    return 1;
                }
            } else if (v == synth_last_started[b][a]) {
                return 1;
            }
        }
    }
    return 0;
}

void voiceSetLastStarted(SynthVoice *svoice) {
    u32 id = svoice->id;
    if (id != 0xFFFFFFFF) {
        u8 a = svoice->midi;
        if (a != 0xFF) {
            u8 b = svoice->midiSet;
            u8 v = id;
            if (b == 0xFF) {
                synth_last_fxstarted[v] = v;
            } else {
                synth_last_started[b][a] = v;
            }
        }
    }
}

void voiceResetLastStarted(SynthVoice *svoice) {
    u32 id = svoice->id;
    if (id != 0xFFFFFFFF) {
        u8 a = svoice->midi;
        if (a != 0xFF) {
            u8 b = svoice->midiSet;
            u8 v = id;
            if (b == 0xFF) {
                if (synth_last_fxstarted[v] == v) {
                    synth_last_fxstarted[v] = 0xFF;
                }
            } else if (v == synth_last_started[b][a]) {
                synth_last_started[b][a] = 0xFF;
            }
        }
    }
}

#pragma pop
#pragma push
#pragma opt_common_subs on

void voiceInitLastStarted(void) {
    u32 i;
    u32 j;

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 16; ++j) {
            synth_last_started[i][j] = 0xFF;
        }
    }

    for (j = 0; j < 64; ++j) {
        synth_last_fxstarted[j] = 0xFF;
    }
}

#pragma pop

}
