#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

typedef struct SynthSDirTab {
    SynthSDirData *data;
    void *base;
    u16 numSmp;
    u16 res;
} SynthSDirTab;

typedef struct SynthDataTab {
    void *data;
    u16 id;
    u16 refCount;
} SynthDataTab;

typedef struct SynthLayerTab {
    void *data;
    u16 id;
    u16 num;
    u16 refCount;
    u16 reserved;
} SynthLayerTab;

typedef struct SynthMacMainTab {
    u16 num;
    u16 subTabIndex;
} SynthMacMainTab;

typedef struct SynthMacSubTab {
    void *data;
    u16 id;
    u16 refCount;
} SynthMacSubTab;

typedef struct SynthFXGroup {
    u16 gid;
    u16 fxNum;
    FX_TAB *fxTab;
} SynthFXGroup;

static SynthSDirTab dataSmpSDirs[128];
static SynthDataTab dataCurveTab[2048];
static SynthDataTab dataKeymapTab[256];
static SynthLayerTab dataLayerTab[256];
static SynthMacMainTab dataMacMainTab[512];
static SynthMacSubTab dataMacSubTabmem[2048];
static SynthFXGroup dataFXGroups[128];

extern "C" {

u16 dataSmpSDirNum;
u16 dataCurveNum;
u16 dataKeymapNum;
u16 dataLayerNum;
u16 dataMacTotal;
u16 dataFXGroupNum;
s32 lbl_805D73DC;
s32 lbl_805D73E0;
SynthMacSubTab lbl_805D73E4;
s32 *lbl_805D73EC;
SynthSDirData *dgs_result;
SynthSampleHeader *dgs_sheader;
SynthDataTab lbl_805D73F8;
s32 *lbl_805D7400;
SynthDataTab lbl_805D7404;
SynthDataTab *lbl_805D740C;
SynthLayerTab *lbl_805D7410;

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

s32 dataInsertKeymap(u16 cid, void *keymapdata) {
    long i;
    long j;
    hwDisableIrq();

    for (i = 0; i < dataKeymapNum && dataKeymapTab[i].id < cid; ++i)
        ;

    if (i < dataKeymapNum) {
        if (cid != dataKeymapTab[i].id) {
            if (dataKeymapNum < 256) {
                for (j = dataKeymapNum - 1; j >= i; --j)
                    dataKeymapTab[j + 1] = dataKeymapTab[j];
                ++dataKeymapNum;
            } else {
                hwEnableIrq();
                return 0;
            }
        } else {
            dataKeymapTab[i].refCount++;
            hwEnableIrq();
            return 0;
        }
    } else if (dataKeymapNum < 256) {
        ++dataKeymapNum;
    } else {
        hwEnableIrq();
        return 0;
    }

    dataKeymapTab[i].id = cid;
    dataKeymapTab[i].data = keymapdata;
    dataKeymapTab[i].refCount = 1;
    hwEnableIrq();
    return 1;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataRemoveKeymap(u16 sid) {
    long i;
    long j;

    hwDisableIrq();
    for (i = 0; i < dataKeymapNum && dataKeymapTab[i].id != sid; ++i)
        ;

    if (i != dataKeymapNum && --dataKeymapTab[i].refCount == 0) {
        for (j = i + 1; j < dataKeymapNum; j++) {
            dataKeymapTab[j - 1] = dataKeymapTab[j];
        }

        --dataKeymapNum;
        hwEnableIrq();
        return 1;
    }

    hwEnableIrq();
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataInsertLayer(u16 cid, void *layerdata, u16 size) {
    long i;
    long j;

    hwDisableIrq();

    for (i = 0; i < dataLayerNum && dataLayerTab[i].id < cid; ++i)
        ;

    if (i < dataLayerNum) {
        if (cid != dataLayerTab[i].id) {
            if (dataLayerNum < 256) {
                for (j = dataLayerNum - 1; j >= i; --j)
                    dataLayerTab[j + 1] = dataLayerTab[j];
                ++dataLayerNum;
            } else {
                hwEnableIrq();
                return 0;
            }
        } else {
            dataLayerTab[i].refCount++;
            hwEnableIrq();
            return 0;
        }
    } else if (dataLayerNum < 256) {
        ++dataLayerNum;
    } else {
        hwEnableIrq();
        return 0;
    }

    dataLayerTab[i].id = cid;
    dataLayerTab[i].data = layerdata;
    dataLayerTab[i].num = size;
    dataLayerTab[i].refCount = 1;
    hwEnableIrq();
    return 1;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataRemoveLayer(u16 sid) {
    long i;
    long j;

    hwDisableIrq();
    for (i = 0; i < dataLayerNum && dataLayerTab[i].id != sid; ++i)
        ;

    if (i != dataLayerNum && --dataLayerTab[i].refCount == 0) {
        for (j = i + 1; j < dataLayerNum; j++) {
            dataLayerTab[j - 1] = dataLayerTab[j];
        }

        --dataLayerNum;
        hwEnableIrq();
        return 1;
    }

    hwEnableIrq();
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

s32 dataInsertCurve(u16 cid, void *curvedata) {
    long i;
    long j;

    hwDisableIrq();

    for (i = 0; i < dataCurveNum && dataCurveTab[i].id < cid; ++i)
        ;

    if (i < dataCurveNum) {
        if (cid != dataCurveTab[i].id) {
            if (dataCurveNum < 2048) {
                for (j = dataCurveNum - 1; j >= i; --j)
                    dataCurveTab[j + 1] = dataCurveTab[j];
                ++dataCurveNum;
            } else {
                hwEnableIrq();
                return 0;
            }
        } else {
            hwEnableIrq();
            dataCurveTab[i].refCount++;
            return 0;
        }
    } else if (dataCurveNum < 2048) {
        ++dataCurveNum;
    } else {
        hwEnableIrq();
        return 0;
    }

    dataCurveTab[i].id = cid;
    dataCurveTab[i].data = curvedata;
    dataCurveTab[i].refCount = 1;
    hwEnableIrq();
    return 1;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataRemoveCurve(u16 sid) {
    long i;
    long j;

    hwDisableIrq();
    for (i = 0; i < dataCurveNum && dataCurveTab[i].id != sid; ++i)
        ;

    if (i != dataCurveNum && --dataCurveTab[i].refCount == 0) {
        for (j = i + 1; j < dataCurveNum; j++) {
            dataCurveTab[j - 1] = dataCurveTab[j];
        }

        --dataCurveNum;
        hwEnableIrq();
        return 1;
    }

    hwEnableIrq();
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

u32 dataInsertSDir(SynthSDirData *sdir, void *smp_data) {
    s32 i;
    SynthSDirData *s;
    u16 n;
    u16 j;
    u16 k;

    for (i = 0; i < dataSmpSDirNum && dataSmpSDirs[i].data != sdir; ++i)
        ;

    if (i == dataSmpSDirNum) {
        if (dataSmpSDirNum < 128) {
            n = 0;
            for (s = sdir; s->id != 0xffff; ++s) {
                ++n;
            }
            hwDisableIrq();
            for (j = 0; j < n; ++j) {
                for (i = 0; i < dataSmpSDirNum; ++i) {
                    for (k = 0; k < dataSmpSDirs[i].numSmp; ++k) {
                        if (sdir[j].id == dataSmpSDirs[i].data[k].id)
                            goto found_id;
                    }
                }
            found_id:
                if (i != dataSmpSDirNum) {
                    sdir[j].ref_cnt = 0xffff;
                } else {
                    sdir[j].ref_cnt = 0;
                }
            }

            dataSmpSDirs[dataSmpSDirNum].data = sdir;
            dataSmpSDirs[dataSmpSDirNum].numSmp = n;
            dataSmpSDirs[dataSmpSDirNum].base = smp_data;
            ++dataSmpSDirNum;
            hwEnableIrq();
            return 1;
        } else {
            return 0;
        }
    }

    return 1;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

s32 dataRemoveSDir(SynthSDirData *sdir) {
    long i;
    long j;
    long index;
    SynthSDirData *data;

    index = 0;
    for (; index < dataSmpSDirNum && dataSmpSDirs[index].data != sdir; ++index) {
    }

    if (index != dataSmpSDirNum) {
        hwDisableIrq();

        for (data = sdir; data->id != 0xFFFF; ++data) {
            if (data->ref_cnt != 0xFFFF && data->ref_cnt != 0)
                break;
        }

        if (data->id == 0xFFFF) {
            data = sdir;

            for (data = sdir; data->id != 0xFFFF; ++data) {
                if (data->ref_cnt != 0xFFFF) {
                    for (i = 0; i < dataSmpSDirNum; ++i) {
                        if (dataSmpSDirs[i].data == sdir)
                            continue;
                        for (j = 0; j < dataSmpSDirs[i].numSmp; ++j) {
                            if (data->id == dataSmpSDirs[i].data[j].id && dataSmpSDirs[i].data[j].ref_cnt == 0xFFFF) {
                                dataSmpSDirs[i].data[j].ref_cnt = 0;
                                break;
                            }
                        }

                        if (j != dataSmpSDirs[i].numSmp) {
                            break;
                        }
                    }
                }
            }

            for (data = sdir; data->id != 0xFFFF; ++data) {
                data->ref_cnt = 0;
            }

            for (j = index + 1; j < dataSmpSDirNum; ++j) {
                dataSmpSDirs[j - 1] = dataSmpSDirs[j];
            }

            --dataSmpSDirNum;
            hwEnableIrq();
            return 1;
        }

        hwEnableIrq();
    }
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

s32 dataAddSampleReference(u16 sid) {
    u32 i;
    SynthSampleHeader *header;
    SynthSDirData *data;
    SynthSDirData *sdir;

    data = NULL;
    sdir = NULL;
    for (i = 0; i < dataSmpSDirNum; ++i) {
        for (data = dataSmpSDirs[i].data; data->id != 0xFFFF; ++data) {
            if (data->id == sid && data->ref_cnt != 0xFFFF) {
                sdir = data;
                goto done;
            }
        }
    }
done:

    if (sdir->ref_cnt == 0) {
        sdir->addr = sdir->offset + (uaddr)dataSmpSDirs[i].base;
        header = &sdir->header;
        hwSaveSample(&header, &sdir->addr);
    }

    ++sdir->ref_cnt;
    return 1;
}

#pragma pop

s32 dataRemoveSampleReference(u16 id) {
    u32 i;

    for (i = 0; i < dataSmpSDirNum; i++) {
        SynthSDirData *e;
        u16 v;
        for (e = dataSmpSDirs[i].data; (v = e->id) != 0xFFFF; e++) {
            if (v == id && e->ref_cnt != 0xFFFF) {
                e->ref_cnt--;
                if (e->ref_cnt == 0) {
                    hwRemoveSample(&e->header, e->addr);
                }
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataInsertFX(u16 gid, FX_TAB *fx, u16 fxNum) {
    long i;

    for (i = 0; i < dataFXGroupNum && gid != dataFXGroups[i].gid; ++i) {
    }

    if (i == dataFXGroupNum) {
        if (dataFXGroupNum < 128) {
            hwDisableIrq();
            dataFXGroups[dataFXGroupNum].gid = gid;
            dataFXGroups[dataFXGroupNum].fxNum = fxNum;
            dataFXGroups[dataFXGroupNum].fxTab = fx;

            for (i = 0; i < fxNum; ++i, ++fx) {
                fx->vGroup = 31;
            }

            dataFXGroupNum++;
            hwEnableIrq();
            return 1;
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
s32 dataRemoveFX(u16 gid) {
    long i;
    long j;

    for (i = 0; i < dataFXGroupNum && gid != dataFXGroups[i].gid; ++i) {
    }

    if (i != dataFXGroupNum) {
        hwDisableIrq();
        for (j = i + 1; j < dataFXGroupNum; j++) {
            dataFXGroups[j - 1] = dataFXGroups[j];
        }

        --dataFXGroupNum;
        hwEnableIrq();
        return 1;
    }
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataInsertMacro(u16 mid, void *macroaddr) {
    long main;
    long pos;
    long base;
    long i;

    hwDisableIrq();

    main = mid >> 6;

    if (dataMacMainTab[main].num == 0) {
        pos = base = dataMacMainTab[main].subTabIndex = dataMacTotal;
    } else {
        base = dataMacMainTab[main].subTabIndex;
        for (i = 0; i < dataMacMainTab[main].num && dataMacSubTabmem[base + i].id < mid; ++i) {
        }

        if (i < dataMacMainTab[main].num) {
            pos = base + i;
            if (mid == dataMacSubTabmem[pos].id) {
                dataMacSubTabmem[pos].refCount++;
                hwEnableIrq();
                return 0;
            }
        } else {
            pos = base + i;
        }
    }

    if (dataMacTotal < 2048) {
        for (i = 0; i < 512; ++i) {
            if (dataMacMainTab[i].subTabIndex > base) {
                dataMacMainTab[i].subTabIndex++;
            }
        }

        i = dataMacTotal - 1;
        for (; i >= pos; --i) {
            dataMacSubTabmem[i + 1] = dataMacSubTabmem[i];
        }

        dataMacSubTabmem[pos].id = mid;
        dataMacSubTabmem[pos].data = macroaddr;
        dataMacSubTabmem[pos].refCount = 1;
        dataMacMainTab[main].num++;
        dataMacTotal++;
        hwEnableIrq();
        return 1;
    }
    hwEnableIrq();
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

s32 dataRemoveMacro(u16 mid) {
    s32 main;
    s32 base;
    s32 i;

    hwDisableIrq();
    main = (mid >> 6) & 0x3fff;

    if (dataMacMainTab[main].num != 0) {
        base = dataMacMainTab[main].subTabIndex;
        for (i = 0; i < dataMacMainTab[main].num && mid != dataMacSubTabmem[base + i].id; ++i) {
        }

        if (i < dataMacMainTab[main].num) {
            if (--dataMacSubTabmem[base + i].refCount == 0) {
                for (i = base + i + 1; i < dataMacTotal; ++i) {
                    dataMacSubTabmem[i - 1] = dataMacSubTabmem[i];
                }

                for (i = 0; i < 512; ++i) {
                    if (dataMacMainTab[i].subTabIndex > base) {
                        --dataMacMainTab[i].subTabIndex;
                    }
                }

                --dataMacMainTab[main].num;
                --dataMacTotal;
            }
        }
    }

    hwEnableIrq();
    return 0;
}

#pragma pop

s32 maccmp(void *key, void *entry) {
    return ((SynthMacSubTab *)key)->id - ((SynthMacSubTab *)entry)->id;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

uaddr dataGetMacro(u16 mid) {
    lbl_805D73E0 = (mid >> 6) & 0x3fff;

    if (dataMacMainTab[lbl_805D73E0].num != 0) {
        lbl_805D73DC = dataMacMainTab[lbl_805D73E0].subTabIndex;
        lbl_805D73E4.id = mid;
        if ((lbl_805D73EC = (s32 *)sndBSearch(&lbl_805D73E4, &dataMacSubTabmem[lbl_805D73DC], dataMacMainTab[lbl_805D73E0].num,
                                              sizeof(SynthMacSubTab), maccmp)) != NULL) {
            return *lbl_805D73EC;
        }
    }

    return 0;
}

#pragma pop

s32 smpcmp(void *key, void *entry) {
    return ((SynthSDirData *)key)->id - ((SynthSDirData *)entry)->id;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataGetSample(s16 sid, SampleInfo *newsmp) {
    static SynthSDirData key;
    long i;

    key.id = sid;

    for (i = 0; i < dataSmpSDirNum; ++i) {
        if ((dgs_result = (SynthSDirData *)sndBSearch(&key, dataSmpSDirs[i].data, dataSmpSDirs[i].numSmp, sizeof(SynthSDirData),
                                                      smpcmp)) != NULL) {
            if (dgs_result->ref_cnt != 0xFFFF) {
                dgs_sheader = &dgs_result->header;
                newsmp->key = dgs_sheader->info;
                newsmp->addr = dgs_result->addr;
                newsmp->offset = 0;
                newsmp->loopStart = dgs_sheader->loopOffset;
                newsmp->count = dgs_sheader->length & 0xffffff;
                newsmp->loopLen = dgs_sheader->loopLength;
                newsmp->format = dgs_sheader->length >> 24;

                if (dgs_result->extraData) {
                    newsmp->coef = (uaddr)&(dataSmpSDirs[i].data)->id + dgs_result->extraData;
                }
                return 0;
            }
        }
    }

    return -1;
}

#pragma pop

s32 curvecmp(void *key, void *entry) {
    return ((SynthDataTab *)key)->id - ((SynthDataTab *)entry)->id;
}

saddr dataGetCurve(s16 cid) {
    lbl_805D73F8.id = cid;
    if ((lbl_805D7400 = (s32 *)sndBSearch(&lbl_805D73F8, dataCurveTab, dataCurveNum, sizeof(SynthDataTab), curvecmp)) != NULL) {
        return *lbl_805D7400;
    }
    return 0;
}

SynthKeymap *dataGetKeymap(u16 cid) {
    lbl_805D7404.id = cid;
    if ((lbl_805D740C = (SynthDataTab *)sndBSearch(&lbl_805D7404, dataKeymapTab, dataKeymapNum, sizeof(SynthDataTab), curvecmp)) != NULL) {
        return (SynthKeymap *)lbl_805D740C->data;
    }
    return NULL;
}

s32 layercmp(void *key, void *entry) {
    return ((SynthLayerTab *)key)->id - ((SynthLayerTab *)entry)->id;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
SynthLayer *dataGetLayer(u16 cid, u16 *n) {
    static SynthLayerTab key;

    key.id = cid;
    if ((lbl_805D7410 = (SynthLayerTab *)sndBSearch(&key, dataLayerTab, dataLayerNum, sizeof(SynthLayerTab),
                                                    layercmp)) != NULL) {
        *n = lbl_805D7410->num;
        return (SynthLayer *)lbl_805D7410->data;
    }
    return NULL;
}

#pragma pop

s32 fxcmp(void *key, void *entry) {
    return ((FX_TAB *)key)->id - ((FX_TAB *)entry)->id;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
FX_TAB *dataGetFX(s16 fid) {
    static FX_TAB key;
    FX_TAB *ret;
    long i;

    key.id = fid;
    for (i = 0; i < dataFXGroupNum; ++i) {
        if ((ret = (FX_TAB *)sndBSearch(&key, dataFXGroups[i].fxTab, dataFXGroups[i].fxNum, sizeof(FX_TAB),
                                        fxcmp))) {
            return ret;
        }
    }

    return NULL;
}

#pragma pop

void dataInit(void *self, void *p) {
    s32 i;

    dataSmpSDirNum = 0;
    dataCurveNum = 0;
    dataKeymapNum = 0;
    dataLayerNum = 0;
    dataFXGroupNum = 0;
    dataMacTotal = 0;
    for (i = 0; i < 0x200; i++) {
        dataMacMainTab[i].num = 0;
        dataMacMainTab[i].subTabIndex = 0;
    }
    hwInitSampleMem(self, p);
}

}
