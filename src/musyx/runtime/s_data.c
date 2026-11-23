#include "musyx/runtime/musyx_runtime_a.h"

#include "types.h"
typedef struct GROUP_DATA_803B50E8 {
    u32 nextOff;
    u16 id;
    u16 type;
    u32 macroOff;
    u32 sampleOff;
    u32 curveOff;
    u32 keymapOff;
    u32 layerOff;
    union {
        struct {
            u32 tableOff;
        } fx;
        struct {
            u32 normpageOff;
            u32 drumpageOff;
            u32 midiSetupOff;
        } song;
    } data;
} GROUP_DATA_803B50E8;

typedef struct GSTACK_803B50E8 {
    GROUP_DATA_803B50E8 *gAddr;
    void *sdirAddr;
    void *prjAddr;
} GSTACK_803B50E8;

typedef struct FX_DATA_803B50E8 {
    u16 num;
    u16 reserverd;
    u8 fx[1][10];
} FX_DATA_803B50E8;

extern "C" {
extern s16 sp;
extern u8 sndActive;
void *hwTransAddr(void *samples);
u32 dataInsertSDir(void *sdir, void *smp_data);
void ScanIDList(u16 *p, void *data, u8 dataType, u32 remove);
u32 seqStartPlay(PAGE_803A49C8 *norm, PAGE_803A49C8 *drum, MIDISETUP_803A3D8C *midiSetup, u32 *song,
                 SND_PLAYPARA_SEQ *para, s32 studio, u16 sgid);
s32 dataInsertFX(u16 gid, Rec_803ADBF0 *fx, u16 fxNum);
void hwSyncSampleMem(void);
u32 sndPushGroup(void *prj_data, u16 gid, void *samples, void *sdir, void *pool);
}

extern "C" {

void dataInitStack(void) {
    sp = 0;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline MEM_DATA_803B4CF8 *GetPoolAddr_803B4CF8(u16 id, MEM_DATA_803B4CF8 *m) {
    while (m->nextOff != 0xFFFFFFFF) {
        if (m->id == id) {
            return m;
        }

        m = (MEM_DATA_803B4CF8 *)((u8 *)m + m->nextOff);
    }
    return NULL;
}

static inline MEM_DATA_803B4CF8 *GetMacroAddr_803B4CF8(u16 id, POOL_DATA_803B4CF8 *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr_803B4CF8(id, (MEM_DATA_803B4CF8 *)((u8 *)pool + pool->macroOff));
}
static inline MEM_DATA_803B4CF8 *GetCurveAddr_803B4CF8(u16 id, POOL_DATA_803B4CF8 *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr_803B4CF8(id, (MEM_DATA_803B4CF8 *)((u8 *)pool + pool->curveOff));
}
static inline MEM_DATA_803B4CF8 *GetKeymapAddr_803B4CF8(u16 id, POOL_DATA_803B4CF8 *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr_803B4CF8(id, (MEM_DATA_803B4CF8 *)((u8 *)pool + pool->keymapOff));
}
static inline MEM_DATA_803B4CF8 *GetLayerAddr_803B4CF8(u16 id, POOL_DATA_803B4CF8 *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr_803B4CF8(id, (MEM_DATA_803B4CF8 *)((u8 *)pool + pool->layerOff));
}

void InsertData(u16 id, void *data, u8 dataType, u32 remove) {
    MEM_DATA_803B4CF8 *m;

    switch (dataType) {
    case 0:
        if (!remove) {
            if ((m = GetMacroAddr_803B4CF8(id, (POOL_DATA_803B4CF8 *)data)) != NULL) {
                dataInsertMacro(id, &m->data.cmd);
            } else {
                dataInsertMacro(id, NULL);
            }
        } else {
            dataRemoveMacro(id);
        }
        break;
    case 2: {
        id |= 0x4000;
        if (!remove) {
            if ((m = GetKeymapAddr_803B4CF8(id, (POOL_DATA_803B4CF8 *)data)) != NULL) {
                dataInsertKeymap(id, &m->data.map);
            } else {
                dataInsertKeymap(id, NULL);
            }
        } else {
            dataRemoveKeymap(id);
        }
    } break;
    case 3: {
        id |= 0x8000;
        if (!remove) {
            if ((m = GetLayerAddr_803B4CF8(id, (POOL_DATA_803B4CF8 *)data)) != NULL) {
                dataInsertLayer(id, &m->data.layer.entry, m->data.layer.num);
            } else {
                dataInsertLayer(id, NULL, 0);
            }
        } else {
            dataRemoveLayer(id);
        }
    } break;
    case 4:
        if (!remove) {
            if ((m = GetCurveAddr_803B4CF8(id, (POOL_DATA_803B4CF8 *)data)) != NULL) {
                dataInsertCurve(id, &m->data.tab);
            } else {
                dataInsertCurve(id, NULL);
            }
        } else {
            dataRemoveCurve(id);
        }
        break;
    case 1:
        if (!remove) {
            dataAddSampleReference(id);
        } else {
            dataRemoveSampleReference(id);
        }
        break;
    }
}

#pragma pop

void ScanIDList(u16 *p, void *data, u8 dataType, u32 remove) {
    u16 i;
    u16 v;

    while ((v = *p) != 0xFFFF) {
        if (v & 0x8000) {
            for (i = v & 0x3FFF; i <= p[1]; i++) {
                InsertData(i, data, dataType, remove);
            }
            p += 2;
        } else {
            InsertData(*p++, data, dataType, remove);
        }
    }
}

void ScanIDListReverse(u16 *start, void *data, u8 dataType, u32 remove) {
    s16 i;
    u16 *p;

    if (*start == 0xFFFF) {
        return;
    }
    p = start;
    while (*p != 0xFFFF) {
        p++;
    }
    p--;
    while (p >= start) {
        if (p != start) {
            if (p[-1] & 0x8000) {
                for (i = *p; i >= (s16)(p[-1] & 0x3FFF); i--) {
                    InsertData(i, data, dataType, remove);
                }
                p -= 2;
            } else {
                InsertData(*p, data, dataType, remove);
                p--;
            }
        } else {
            InsertData(*p, data, dataType, remove);
            p--;
        }
    }
}

static GSTACK_803B50E8 gs[128];
struct Rec_803ADBF0;
#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void InsertSamples_803B50E8(u16 *ref, void *samples, void *sdir) {
    samples = hwTransAddr(samples);
    if (dataInsertSDir(sdir, samples)) {
        ScanIDList(ref, sdir, 1, 0);
    }
}
static inline void InsertMacros_803B50E8(u16 *ref, void *pool) { ScanIDList(ref, pool, 0, 0); }
static inline void InsertCurves_803B50E8(u16 *ref, void *pool) { ScanIDList(ref, pool, 4, 0); }
static inline void InsertKeymaps_803B50E8(u16 *ref, void *pool) { ScanIDList(ref, pool, 2, 0); }
static inline void InsertLayers_803B50E8(u16 *ref, void *pool) { ScanIDList(ref, pool, 3, 0); }
static inline void InsertFXTab_803B50E8(u16 gid, FX_DATA_803B50E8 *fd) { dataInsertFX(gid, (Rec_803ADBF0 *)fd->fx, fd->num); }
u32 sndPushGroup(void *prj_data, u16 gid, void *samples, void *sdir, void *pool) {
    GROUP_DATA_803B50E8 *g;
    if (sndActive && sp < 128) {
        g = (GROUP_DATA_803B50E8 *)prj_data;
        while (g->nextOff != 0xFFFFFFFF) {
            if (g->id == gid) {
                gs[sp].gAddr = g;
                gs[sp].prjAddr = prj_data;
                gs[sp].sdirAddr = sdir;
                InsertSamples_803B50E8((u16 *)((u8 *)prj_data + g->sampleOff), samples, sdir);
                InsertMacros_803B50E8((u16 *)((u8 *)prj_data + g->macroOff), pool);
                InsertCurves_803B50E8((u16 *)((u8 *)prj_data + g->curveOff), pool);
                InsertKeymaps_803B50E8((u16 *)((u8 *)prj_data + g->keymapOff), pool);
                InsertLayers_803B50E8((u16 *)((u8 *)prj_data + g->layerOff), pool);
                if (g->type == 1) {
                    InsertFXTab_803B50E8(gid, (FX_DATA_803B50E8 *)((u8 *)prj_data + g->data.song.normpageOff));
                }
                hwSyncSampleMem();
                ++sp;
                return 1;
            }
            g = (GROUP_DATA_803B50E8 *)((u8 *)prj_data + g->nextOff);
        }
    }
    return 0;
}
#pragma pop

s32 dataRemoveSDir(void *sdir);
#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline void RemoveMacros_803B5258(u16 *ref) { ScanIDList(ref, NULL, 0, 1); }
static inline void RemoveCurves_803B5258(u16 *ref) { ScanIDList(ref, NULL, 4, 1); }
static inline void RemoveKeymaps_803B5258(u16 *ref) { ScanIDList(ref, NULL, 2, 1); }
static inline void RemoveLayers_803B5258(u16 *ref) { ScanIDList(ref, NULL, 3, 1); }
static inline void RemoveSamples_803B5258(u16 *ref, void *sdir) {
    ScanIDListReverse(ref, NULL, 1, 1);
    dataRemoveSDir(sdir);
}
static inline void RemoveFXTab_803B5258(u16 gid) { dataRemoveFX(gid); }

u32 sndPopGroup(void) {
    GROUP_DATA_803B50E8 *g;
    void *sdir;
    void *prj;
    FX_DATA_803B50E8 *fd;

    g = gs[--sp].gAddr;
    prj = gs[sp].prjAddr;
    sdir = gs[sp].sdirAddr;
    hwDisableIrq();

    if (g->type == 1) {
        fd = (FX_DATA_803B50E8 *)((u8 *)prj + g->data.song.normpageOff);
        s3dKillEmitterByFXID((Ent_803BA228 *)fd->fx, fd->num);
    } else {
        seqKillInstancesByGroupID(g->id);
    }

    synthKillVoicesByMacroReferences((u16 *)((u8 *)prj + g->macroOff));
    hwEnableIrq();
    RemoveSamples_803B5258((u16 *)((u8 *)prj + g->sampleOff), sdir);
    RemoveMacros_803B5258((u16 *)((u8 *)prj + g->macroOff));
    RemoveCurves_803B5258((u16 *)((u8 *)prj + g->curveOff));
    RemoveKeymaps_803B5258((u16 *)((u8 *)prj + g->keymapOff));
    RemoveLayers_803B5258((u16 *)((u8 *)prj + g->layerOff));
    if (g->type == 1) {
        RemoveFXTab_803B5258(g->id);
    }
    return 1;
}

#pragma pop

u32 seqPlaySong(u16 sgid, u16 sid, void *arrfile, SND_PLAYPARA_SEQ *para, u8 irq_call, s32 studio) {
    Ent_803B5398 *tbl = (Ent_803B5398 *)gs;
    Ent_803B5398 *e;
    s32 i;
    Desc_803B5398 *d;
    u8 *base;
    PAGE_803A49C8 *norm;
    PAGE_803A49C8 *drum;
    MIDISETUP_803A3D8C *midiSetup;
    u32 seqId;
    u16 c;

    e = tbl;
    i = 0;
    while (i < sp) {
        if (sgid == e->desc->id) {
            d = tbl[i].desc;
            if (d->kind == 0) {
            base = tbl[i].base;
            norm = (PAGE_803A49C8 *)(base + d->o1C);
            drum = (PAGE_803A49C8 *)(base + d->o20);
            midiSetup = (MIDISETUP_803A3D8C *)(base + d->o24);
            while ((c = midiSetup->songId) != 0xFFFF) {
                if (c == sid) {
                    if (irq_call) {
                        seqId = seqStartPlay(norm, drum, midiSetup, (u32 *)arrfile, para, studio, sgid);
                    } else {
                        hwDisableIrq();
                        seqId = seqStartPlay(norm, drum, midiSetup, (u32 *)arrfile, para, studio, sgid);
                        hwEnableIrq();
                    }
                    return seqId;
                }
                midiSetup++;
            }
            return 0xFFFFFFFF;
            }
            return 0xFFFFFFFF;
        }
        e++;
        i++;
    }
    return 0xFFFFFFFF;
}

u32 sndSeqPlayEx(u16 sgid, u16 sid, void *arrfile, SND_PLAYPARA_SEQ *para, s32 studio) {
    return seqPlaySong(sgid, sid, arrfile, para, 0, studio);
}

s16 sp;

}
