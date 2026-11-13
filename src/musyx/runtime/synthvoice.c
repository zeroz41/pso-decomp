#include "musyx/runtime/musyx_runtime_a.h"

#define synthVoice ((SYNTH_VOICE_803B2438 *)synthVoice)

typedef struct SYNTH_VOICELIST_V {
    u8 prev;
    u8 next;
    u16 user;
} SYNTH_VOICELIST_V;

typedef struct SYNTH_ROOTLIST_V {
    u16 next;
    u16 prev;
} SYNTH_ROOTLIST_V;

static VID_LIST_SV vidList[128];
static u8 synth_last_started[8][16];
static u8 synth_last_fxstarted[64];
static SYNTH_VOICELIST_V voicePrioSortVoices[64];
static u8 voicePrioSortVoicesRoot[256];
static SYNTH_ROOTLIST_V voicePrioSortRootList[256];
static SYNTH_VOICELIST_V voiceList[64];


extern "C" {
u32 vidCurrentId;
VID_LIST_SV *vidRoot;
VID_LIST_SV *vidFree;
u16 voicePrioSortRootListRoot;
u8 voiceMusicRunning;
u8 voiceFxRunning;
u8 voiceListInsert;
u8 voiceListRoot;
}
extern "C" {

void vidInit(void) {
    s32 i;
    VID_LIST_SV *n;
    VID_LIST_SV *prev;

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

VID_LIST_SV *get_vidlist(u32 key) {
    VID_LIST_SV *n;
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

void vidRemoveVoiceReferences(Prog_803B25CC *p) {
    if (p->id != 0xFFFFFFFF) {
        voiceResetLastStarted((Obj_803B3B80 *)p);
        if (p->prevId != 0xFFFFFFFF) {
            VOICES_803B25CC[(u8)p->prevId].nextId = p->nextId;
            if (p->nextId != 0xFFFFFFFF) {
                VOICES_803B25CC[(u8)p->nextId].prevId = p->prevId;
            }
            UNLINK_803B25CC(p->node)
            PUSH_803B25CC(p->node)
            p->node = NULL;
        } else if (p->nextId != 0xFFFFFFFF) {
            p->node->root = p->nextId;
            VOICES_803B25CC[(u8)p->nextId].prevId = 0xFFFFFFFF;
            VOICES_803B25CC[(u8)p->nextId].node2 = p->node2;
            if (p->node != p->node2) {
                UNLINK_803B25CC(p->node)
                PUSH_803B25CC(p->node)
                p->node = NULL;
            }
            p->node = NULL;
            p->node2 = NULL;
        } else if (p->node != p->node2) {
            UNLINK_803B25CC(p->node)
            PUSH_803B25CC(p->node)
            p->node = NULL;
            UNLINK_803B25CC(p->node2)
            PUSH_803B25CC(p->node2)
            p->node2 = NULL;
        } else {
            UNLINK_803B25CC(p->node)
            PUSH_803B25CC(p->node)
            p->node = NULL;
            p->node2 = NULL;
        }
    }
}

s32 vidMakeRoot(u8 *arg0) {
    SYNTH_VOICE_SV *svoice = (SYNTH_VOICE_SV *)arg0;
    svoice->vidMasterList = svoice->vidList;
    return svoice->vidList->vid;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)

static inline u32 get_newvid_SV(void) {
    u32 vid;
    do {
        vid = vidCurrentId++;
    } while (vid == 0xFFFFFFFF);

    return vid;
}

u32 vidMakeNew(SYNTH_VOICE_SV *svoice, u32 isMaster) {
    u32 vid;
    VID_LIST_SV *nvl;
    VID_LIST_SV *lvl;
    VID_LIST_SV *vl;

    vid = get_newvid_SV();
    lvl = NULL;
    nvl = vidRoot;

    while (nvl != NULL) {
        if (nvl->vid > vid) {
            break;
        }

        if (nvl->vid == vid) {
            vid = get_newvid_SV();
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
inline VID_LIST_SV *find_node_803B2A30(u32 id) {
    VID_LIST_SV *p;
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
u32 vidGetInternalId(u32 arg0) {
    if (arg0 != 0xFFFFFFFF) {
        VID_LIST_SV *p = find_node_803B2A30(arg0);
        if (p != 0) {
            return p->root;
        }
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
void voiceRemovePriority(Obj_803B312C *svoice) {
    SYNTH_VOICELIST_V *vps;
    SYNTH_ROOTLIST_V *rps;

    vps = &voicePrioSortVoices[svoice->id & 0xFF];
    if (vps->user != 1) {
        return;
    }

    if (vps->prev != 0xFF) {
        voicePrioSortVoices[vps->prev].next = vps->next;
    } else {
        voicePrioSortVoicesRoot[svoice->grp] = vps->next;
    }

    if (vps->next != 0xFF) {
        voicePrioSortVoices[vps->next].prev = vps->prev;
    } else if (vps->prev == 0xFF) {
        rps = &voicePrioSortRootList[svoice->grp];

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

extern "C" void hwSetPriority(s32 i, s32 v);
#pragma push
#pragma opt_common_subs on

void voiceSetPriority(Voice_803B2128 *svoice, u8 prio) {
    u32 v;
    u16 li;
    SYNTH_VOICELIST_V *vps;
    u16 i;
    v = svoice->fF4 & 0xFF;
    vps = &voicePrioSortVoices[v];
    if (vps->user == 1) {
        if (svoice->pad10C[0] == prio) {
            return;
        }

        voiceRemovePriority((Obj_803B312C *)svoice);
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
    svoice->pad10C[0] = prio;
    hwSetPriority(svoice->fF4 & 0xFF, ((u32)prio << 24) | (svoice->f110 >> 15));
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
    SYNTH_VOICELIST_V *sfv;

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
                    if (allocId != SV_VOICES[i].allocId)
                        continue;
                    ++num;
                    if (SV_VOICES[i].block)
                        continue;

                    if (!type_alloc || fxFlag == SV_VOICES[i].fxFlag) {
                        if ((SV_VOICES[i].cFlags & 2))
                            continue;
                        if (voice != -1) {
                            if (SV_VOICES[i].age < SV_VOICES[voice].age)
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
                    if (allocId == SV_VOICES[i].allocId) {
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
                        if (SV_VOICES[i].block != 0)
                            continue;

                        if (!type_alloc || fxFlag == SV_VOICES[i].fxFlag) {
                            if ((SV_VOICES[i].cFlags & 2))
                                continue;
                            if (voice != -1) {
                                if (SV_VOICES[voice].age > SV_VOICES[i].age)
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
                if (SV_VOICES_L[voice].prio > priority) {
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
        } else if (SV_VOICES_L[voice].fxFlag) {
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
void voiceFree(Obj_803B312C *o) {
    u8 idx;
    SYNTH_VOICELIST_V *e;

    macMakeInactive(o, 2);
    voiceRemovePriority(o);
    o->f34 = 0;
    o->grp = 0;
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
        if (o->f11d != 0) {
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

static inline void voiceInitPrioSort_803B3210(void) {
    u32 i;

    for (i = 0; i < synthInfo.voiceNum; ++i) {
        voicePrioSortVoices[i].user = 0;
    }

    for (i = 0; i < 256; ++i) {
        voicePrioSortVoicesRoot[i] = 0xff;
    }

    voicePrioSortRootListRoot = 0xffff;
}

static inline void voiceInitFreeList_803B3210(void) {
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
    voiceInitFreeList_803B3210();
    voiceInitPrioSort_803B3210();
    voiceFxRunning = 0;
    voiceMusicRunning = 0;
}

#pragma pop

#define svVoice (*(SYNTH_VOICE_SV **)&synthVoice)
#pragma push
#pragma opt_common_subs on

u32 voiceBlock(u8 prio) {
    u32 voice;

    if ((voice = voiceAllocate(prio, 0xFF, 0xFFFF, 1)) != 0xFFFFFFFF) {
        svVoice[voice].block = 1;
        svVoice[voice].fxFlag = 1;

        vidRemoveVoiceReferences((Prog_803B25CC *)&svVoice[voice]);
        svVoice[voice].id = voice | 0xFFFFFF00;

        if (hwIsActive(voice)) {
            hwBreak(voice);
        }

        macMakeInactive((Obj_803B312C *)&svVoice[voice], 2);
        svVoice[voice].addr = NULL;
        voiceSetPriority((Voice_803B2128 *)&svVoice[voice], prio);
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

    svVoice[voice].id = voice;
    voiceFree((Obj_803B312C *)&svVoice[voice]);
    svVoice[voice].block = 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on

void voiceKill(u32 vi) {
    SYNTH_VOICE_SV *sv = &svVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences((Prog_803B25CC *)sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree((Obj_803B312C *)sv);
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

static inline u32 vidGetInternalId_803B3748(u32 vid) {
    VID_LIST_SV *vl;

    if (vid != 0xffffffff) {
        if ((vl = get_vidlist(vid)) != NULL) {
            return vl->root;
        }
    }

    return 0xffffffff;
}

static inline void voiceKill_803B3748(u32 vi) {
    SYNTH_VOICE_SV *sv = &svVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences((Prog_803B25CC *)sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree((Obj_803B312C *)sv);
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
        for (voiceid = vidGetInternalId_803B3748(voiceid); voiceid != -1; voiceid = next_voiceid) {
            i = voiceid & 0xff;
            next_voiceid = svVoice[i].child;
            if (voiceid == svVoice[i].id) {
                voiceKill_803B3748(i);
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

static inline void voiceKill_803B3858(u32 vi) {
    SYNTH_VOICE_SV *sv = &svVoice[vi];
    if (sv->addr != NULL) {
        vidRemoveVoiceReferences((Prog_803B25CC *)sv);
        sv->cFlags &= ~3;
        sv->age = 0;
        voiceFree((Obj_803B312C *)sv);
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
        if (svVoice[i].addr == NULL && svVoice[i].block == 0) {
            voiceKill_803B3858(i);
        }
    }

    while (*ref != 0xFFFF) {
        if ((*ref & 0x8000)) {
            id = *ref & 0x3fff;
            while (id <= ref[1]) {
                for (i = 0; i < synthInfo.voiceNum; ++i) {
                    if (svVoice[i].addr != NULL && id == svVoice[i].macroId) {
                        voiceKill_803B3858(i);
                    }
                }
                ++id;
            }
            ref += 2;
        } else {
            for (i = 0; i < synthInfo.voiceNum; ++i) {
                if (svVoice[i].addr != NULL && *ref == svVoice[i].macroId) {
                    voiceKill_803B3858(i);
                }
            }
            ++ref;
        }
    }
}

#pragma pop

#undef svVoice

#pragma push
#pragma pool_data off
s32 voiceIsLastStarted(Obj_803B3AA8 *arg0) {
    u32 id = arg0->id;
    if (id != 0xFFFFFFFF) {
        u8 a = arg0->b121;
        if (a != 0xFF) {
            u8 b = arg0->b122;
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

void voiceSetLastStarted(Obj_803B3B24 *arg0) {
    u32 id = arg0->id;
    if (id != 0xFFFFFFFF) {
        u8 a = arg0->b121;
        if (a != 0xFF) {
            u8 b = arg0->b122;
            u8 v = id;
            if (b == 0xFF) {
                synth_last_fxstarted[v] = v;
            } else {
                synth_last_started[b][a] = v;
            }
        }
    }
}

void voiceResetLastStarted(Obj_803B3B80 *arg0) {
    u32 id = arg0->id;
    if (id != 0xFFFFFFFF) {
        u8 a = arg0->b121;
        if (a != 0xFF) {
            u8 b = arg0->b122;
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
