#include "musyx/runtime/musyx_runtime_a.h"


typedef struct SAMPLE_HEADER_D {
    u32 info;
    u32 length;
    u32 loopOffset;
    u32 loopLength;
} SAMPLE_HEADER_D;

typedef struct SDIR_DATA_D {
    u16 id;
    u16 ref_cnt;
    u32 offset;
    void *addr;
    SAMPLE_HEADER_D header;
    u32 extraData;
} SDIR_DATA_D;

typedef struct SDIR_TAB_D {
    SDIR_DATA_D *data;
    void *base;
    u16 numSmp;
    u16 res;
} SDIR_TAB_D;

typedef struct DATA_TAB_D {
    void *data;
    u16 id;
    u16 refCount;
} DATA_TAB_D;

typedef struct LAYER_TAB_D {
    void *data;
    u16 id;
    u16 num;
    u16 refCount;
    u16 reserved;
} LAYER_TAB_D;

typedef struct MAC_MAINTAB_D {
    u16 num;
    u16 subTabIndex;
} MAC_MAINTAB_D;

typedef struct MAC_SUBTAB_D {
    void *data;
    u16 id;
    u16 refCount;
} MAC_SUBTAB_D;

typedef struct FX_GROUP_D {
    u16 gid;
    u16 fxNum;
    void *fxTab;
} FX_GROUP_D;

static SDIR_TAB_D dataSmpSDirs[128];
static DATA_TAB_D dataCurveTab[2048];
static DATA_TAB_D dataKeymapTab[256];
static LAYER_TAB_D dataLayerTab[256];
static MAC_MAINTAB_D dataMacMainTab[512];
static MAC_SUBTAB_D dataMacSubTabmem[2048];
static FX_GROUP_D dataFXGroups[128];

extern "C" {

u16 dataSmpSDirNum;
u16 dataCurveNum;
u16 dataKeymapNum;
u16 dataLayerNum;
u16 dataMacTotal;
u16 dataFXGroupNum;
s32 lbl_805D73DC;
s32 lbl_805D73E0;
Req_803AE60C lbl_805D73E4;
s32 *lbl_805D73EC;
SDIR_DATA_D *dgs_result;
SAMPLE_HEADER_D *dgs_sheader;
Req_803AE60C lbl_805D73F8;
s32 *lbl_805D7400;
Req_803AE60C lbl_805D7404;
s32 *lbl_805D740C;
Res_803AE6DC *lbl_805D7410;

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

s32 dataInsertSDir(SDIR_DATA_D *sdir, void *smp_data) {
    s32 i;
    SDIR_DATA_D *s;
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

s32 dataRemoveSDir(SDIR_DATA_D *sdir) {
    long i;
    long j;
    long index;
    SDIR_DATA_D *data;

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
    Hdr_803ADA80 *header;
    SDIR_DATA_D *data;
    SDIR_DATA_D *sdir;

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
        sdir->addr = (void *)((u32)sdir->offset + (u32)dataSmpSDirs[i].base);
        header = (Hdr_803ADA80 *)&sdir->header;
        hwSaveSample(&header, &sdir->addr);
    }

    ++sdir->ref_cnt;
    return 1;
}

#pragma pop

s32 dataRemoveSampleReference(u16 id) {
    u32 i;

    for (i = 0; i < dataSmpSDirNum; i++) {
        Ent_803ADB58 *e;
        u16 v;
        for (e = ((Tbl_803ADB58 *)dataSmpSDirs)[i].list; (v = e->id) != 0xFFFF; e++) {
            if (v == id && e->ref != 0xFFFF) {
                e->ref--;
                if (e->ref == 0) {
                    hwRemoveSample(&e->fc, e->f8);
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
s32 dataInsertFX(u16 gid, Rec_803ADBF0 *fx, u16 fxNum) {
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
                fx->f9 = 31;
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

s32 maccmp(u8 *arg0, u8 *arg1) {
    return *(u16 *)((s8 *)arg0 + 4) - *(u16 *)((s8 *)arg1 + 4);
}

extern s32 lbl_805D73DC;
extern s32 lbl_805D73E0;
extern Req_803AE60C lbl_805D73E4;
extern s32 *lbl_805D73EC;
#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

u32 dataGetMacro(u16 mid) {
    lbl_805D73E0 = (mid >> 6) & 0x3fff;

    if (dataMacMainTab[lbl_805D73E0].num != 0) {
        lbl_805D73DC = dataMacMainTab[lbl_805D73E0].subTabIndex;
        lbl_805D73E4.f4 = mid;
        if ((lbl_805D73EC = sndBSearch(&lbl_805D73E4, &dataMacSubTabmem[lbl_805D73DC], dataMacMainTab[lbl_805D73E0].num,
                                                          sizeof(MAC_SUBTAB_D), maccmp)) != NULL) {
            return *lbl_805D73EC;
        }
    }

    return 0;
}

#pragma pop

s32 smpcmp(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataGetSample(s16 sid, Sample_803AE4D4 *newsmp) {
    static SDIR_DATA_D key;
    long i;

    key.id = sid;

    for (i = 0; i < dataSmpSDirNum; ++i) {
        if ((dgs_result = (SDIR_DATA_D *)sndBSearch((Req_803AE60C *)&key, dataSmpSDirs[i].data, dataSmpSDirs[i].numSmp, sizeof(SDIR_DATA_D),
                                                                       (s32 (*)(u8 *, u8 *))smpcmp)) != NULL) {
            if (dgs_result->ref_cnt != 0xFFFF) {
                dgs_sheader = &dgs_result->header;
                newsmp->key = dgs_sheader->info;
                newsmp->addr = (u32)dgs_result->addr;
                newsmp->offset = 0;
                newsmp->loopStart = dgs_sheader->loopOffset;
                newsmp->count = dgs_sheader->length & 0xffffff;
                newsmp->loopLen = dgs_sheader->loopLength;
                newsmp->format = dgs_sheader->length >> 24;

                if (dgs_result->extraData) {
                    newsmp->coef = (u32)&(dataSmpSDirs[i].data)->id + dgs_result->extraData;
                }
                return 0;
            }
        }
    }

    return -1;
}

#pragma pop

s32 curvecmp(u8 *arg0, u8 *arg1) {
    return *(u16 *)((s8 *)arg0 + 4) - *(u16 *)((s8 *)arg1 + 4);
}

s32 dataGetCurve(s16 arg0) {
    lbl_805D73F8.f4 = arg0;
    if ((lbl_805D7400 = sndBSearch(&lbl_805D73F8, dataCurveTab, dataCurveNum, 8, curvecmp)) != NULL) {
        return *lbl_805D7400;
    }
    return 0;
}

s32 dataGetKeymap(s16 arg0) {
    lbl_805D7404.f4 = arg0;
    if ((lbl_805D740C = sndBSearch(&lbl_805D7404, dataKeymapTab, dataKeymapNum, 8, curvecmp)) != NULL) {
        return *lbl_805D740C;
    }
    return 0;
}

s32 layercmp(u8 *arg0, u8 *arg1) {
    return *(u16 *)((s8 *)arg0 + 4) - *(u16 *)((s8 *)arg1 + 4);
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s32 dataGetLayer(s16 cid, u16 *n) {
    static LAYER_TAB_D key;

    key.id = cid;
    if ((lbl_805D7410 = (Res_803AE6DC *)sndBSearch((Req_803AE60C *)&key, dataLayerTab, dataLayerNum, sizeof(LAYER_TAB_D),
                                                                      (s32 (*)(u8 *, u8 *))layercmp)) != NULL) {
        *n = lbl_805D7410->h6;
        return lbl_805D7410->f0;
    }
    return 0;
}

#pragma pop

s32 fxcmp(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
typedef struct FX_TAB_D {
    u16 id;
    u16 macro;
    u8 maxVoices;
    u8 priority;
    u8 volume;
    u8 panning;
    u8 key;
    u8 vGroup;
} FX_TAB_D;
Se_803A9144 *dataGetFX(s16 fid) {
    static FX_TAB_D key;
    Se_803A9144 *ret;
    long i;

    key.id = fid;
    for (i = 0; i < dataFXGroupNum; ++i) {
        if ((ret = (Se_803A9144 *)sndBSearch((Req_803AE60C *)&key, dataFXGroups[i].fxTab, dataFXGroups[i].fxNum, sizeof(FX_TAB_D),
                                                                (s32 (*)(u8 *, u8 *))fxcmp))) {
            return ret;
        }
    }

    return NULL;
}

#pragma pop

void dataInit(void *arg0, void *arg1) {
    s32 i;

    dataSmpSDirNum = 0;
    dataCurveNum = 0;
    dataKeymapNum = 0;
    dataLayerNum = 0;
    dataFXGroupNum = 0;
    dataMacTotal = 0;
    for (i = 0; i < 0x200; i++) {
        ((Slot_803AE814 *)dataMacMainTab)[i].count = 0;
        ((Slot_803AE814 *)dataMacMainTab)[i].start = 0;
    }
    hwInitSampleMem(arg0, arg1);
}

}
