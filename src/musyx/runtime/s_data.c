#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

typedef struct SynthGroupData {
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
} SynthGroupData;

typedef struct SynthGroupStack {
    SynthGroupData *gAddr;
    SynthSDirData *sdirAddr;
    u8 *prjAddr;
} SynthGroupStack;

typedef struct SynthFXData {
    u16 num;
    u16 reserved;
    FX_TAB fx[1];
} SynthFXData;

extern "C" {

extern s16 sp;

void dataInitStack(void) {
    sp = 0;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline SynthPoolMemData *GetPoolAddr(u16 id, SynthPoolMemData *m) {
    while (m->nextOff != 0xFFFFFFFF) {
        if (m->id == id) {
            return m;
        }

        m = (SynthPoolMemData *)((u8 *)m + m->nextOff);
    }
    return NULL;
}

static inline SynthPoolMemData *GetMacroAddr(u16 id, SynthPoolData *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr(id, (SynthPoolMemData *)((u8 *)pool + pool->macroOff));
}
static inline SynthPoolMemData *GetCurveAddr(u16 id, SynthPoolData *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr(id, (SynthPoolMemData *)((u8 *)pool + pool->curveOff));
}
static inline SynthPoolMemData *GetKeymapAddr(u16 id, SynthPoolData *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr(id, (SynthPoolMemData *)((u8 *)pool + pool->keymapOff));
}
static inline SynthPoolMemData *GetLayerAddr(u16 id, SynthPoolData *pool) {
    if (pool == NULL) {
        return NULL;
    }
    return GetPoolAddr(id, (SynthPoolMemData *)((u8 *)pool + pool->layerOff));
}

void InsertData(u16 id, void *data, u8 dataType, u32 remove) {
    SynthPoolMemData *m;

    switch (dataType) {
    case 0:
        if (!remove) {
            if ((m = GetMacroAddr(id, (SynthPoolData *)data)) != NULL) {
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
            if ((m = GetKeymapAddr(id, (SynthPoolData *)data)) != NULL) {
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
            if ((m = GetLayerAddr(id, (SynthPoolData *)data)) != NULL) {
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
            if ((m = GetCurveAddr(id, (SynthPoolData *)data)) != NULL) {
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

static SynthGroupStack gs[128];
#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void InsertSamples(u16 *ref, void *samples, SynthSDirData *sdir) {
    samples = hwTransAddr(samples);
    if (dataInsertSDir(sdir, samples)) {
        ScanIDList(ref, sdir, 1, 0);
    }
}
static inline void InsertMacros(u16 *ref, void *pool) { ScanIDList(ref, pool, 0, 0); }
static inline void InsertCurves(u16 *ref, void *pool) { ScanIDList(ref, pool, 4, 0); }
static inline void InsertKeymaps(u16 *ref, void *pool) { ScanIDList(ref, pool, 2, 0); }
static inline void InsertLayers(u16 *ref, void *pool) { ScanIDList(ref, pool, 3, 0); }
static inline void InsertFXTab(u16 gid, SynthFXData *fd) { dataInsertFX(gid, fd->fx, fd->num); }
u32 sndPushGroup(void *prj_data, u16 gid, void *samples, void *sdir, void *pool) {
    SynthGroupData *g;
    if (sndActive && sp < 128) {
        g = (SynthGroupData *)prj_data;
        while (g->nextOff != 0xFFFFFFFF) {
            if (g->id == gid) {
                gs[sp].gAddr = g;
                gs[sp].prjAddr = (u8 *)prj_data;
                gs[sp].sdirAddr = (SynthSDirData *)sdir;
                InsertSamples((u16 *)((u8 *)prj_data + g->sampleOff), samples, (SynthSDirData *)sdir);
                InsertMacros((u16 *)((u8 *)prj_data + g->macroOff), pool);
                InsertCurves((u16 *)((u8 *)prj_data + g->curveOff), pool);
                InsertKeymaps((u16 *)((u8 *)prj_data + g->keymapOff), pool);
                InsertLayers((u16 *)((u8 *)prj_data + g->layerOff), pool);
                if (g->type == 1) {
                    InsertFXTab(gid, (SynthFXData *)((u8 *)prj_data + g->data.fx.tableOff));
                }
                hwSyncSampleMem();
                ++sp;
                return 1;
            }
            g = (SynthGroupData *)((u8 *)prj_data + g->nextOff);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline void RemoveMacros(u16 *ref) { ScanIDList(ref, NULL, 0, 1); }
static inline void RemoveCurves(u16 *ref) { ScanIDList(ref, NULL, 4, 1); }
static inline void RemoveKeymaps(u16 *ref) { ScanIDList(ref, NULL, 2, 1); }
static inline void RemoveLayers(u16 *ref) { ScanIDList(ref, NULL, 3, 1); }
static inline void RemoveSamples(u16 *ref, SynthSDirData *sdir) {
    ScanIDListReverse(ref, NULL, 1, 1);
    dataRemoveSDir(sdir);
}
static inline void RemoveFXTab(u16 gid) { dataRemoveFX(gid); }

u32 sndPopGroup(void) {
    SynthGroupData *g;
    SynthSDirData *sdir;
    u8 *prj;
    SynthFXData *fd;

    g = gs[--sp].gAddr;
    prj = gs[sp].prjAddr;
    sdir = gs[sp].sdirAddr;
    hwDisableIrq();

    if (g->type == 1) {
        fd = (SynthFXData *)(prj + g->data.fx.tableOff);
        s3dKillEmitterByFXID(fd->fx, fd->num);
    } else {
        seqKillInstancesByGroupID(g->id);
    }

    synthKillVoicesByMacroReferences((u16 *)(prj + g->macroOff));
    hwEnableIrq();
    RemoveSamples((u16 *)(prj + g->sampleOff), sdir);
    RemoveMacros((u16 *)(prj + g->macroOff));
    RemoveCurves((u16 *)(prj + g->curveOff));
    RemoveKeymaps((u16 *)(prj + g->keymapOff));
    RemoveLayers((u16 *)(prj + g->layerOff));
    if (g->type == 1) {
        RemoveFXTab(g->id);
    }
    return 1;
}

#pragma pop

u32 seqPlaySong(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, u8 irq_call, s32 studio) {
    SynthGroupStack *tbl = gs;
    SynthGroupStack *e;
    s32 i;
    SynthGroupData *d;
    u8 *base;
    SynthSeqPage *norm;
    SynthSeqPage *drum;
    SynthMidiSetup *midiSetup;
    u32 seqId;
    u16 c;

    e = tbl;
    i = 0;
    while (i < sp) {
        if (sgid == e->gAddr->id) {
            d = tbl[i].gAddr;
            if (d->type == 0) {
                base = tbl[i].prjAddr;
                norm = (SynthSeqPage *)(base + d->data.song.normpageOff);
                drum = (SynthSeqPage *)(base + d->data.song.drumpageOff);
                midiSetup = (SynthMidiSetup *)(base + d->data.song.midiSetupOff);
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

u32 sndSeqPlayEx(u16 sgid, u16 sid, void *arrfile, SynthPlayPara *para, s32 studio) {
    return seqPlaySong(sgid, sid, arrfile, para, 0, studio);
}

s16 sp;

}
