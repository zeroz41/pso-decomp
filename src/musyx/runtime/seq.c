#define seqVolume TLobby__sub_803A5078_header_view
#include "musyx/runtime/musyx_runtime_a.h"
#undef seqVolume

extern "C" {

void ResetNotes(Owner_803A3C24 *o) {
    u32 i;
    Node_803A3C24 *p;
    Node_803A3C24 *q;

    for (i = 0; i < 2; i++) {
        if ((p = o->lists[i]) != NULL) {
            while ((q = p->next) != NULL) {
                p = q;
            }
            if (lbl_805D7364 != NULL) {
                p->next = lbl_805D7364;
                lbl_805D7364->prev = p;
            }
            lbl_805D7364 = o->lists[i];
            o->lists[i] = NULL;
        }
    }
    if ((p = o->head) != NULL) {
        while ((q = p->next) != NULL) {
            p = q;
        }
        if (lbl_805D7364 != NULL) {
            p->next = lbl_805D7364;
            lbl_805D7364->prev = p;
        }
        lbl_805D7364 = o->head;
        o->head = NULL;
    }
}

Node_803A3C24 *AllocateNote(s32 key, u8 ch) {
    Node_803A3C24 *n = lbl_805D7364;
    Node_803A3C24 *cur;
    Node_803A3C24 *prev;

    if (n != NULL) {
        if ((lbl_805D7364 = n->next) != NULL) {
            lbl_805D7364->prev = NULL;
        }
        n->key = key;
        n->ch = ch;
        n->grp = lbl_805D7360->chans[ch].grp;
        prev = NULL;
        for (cur = lbl_805D7360->lists[n->grp]; cur != NULL; prev = cur, cur = cur->next) {
            if (cur->key > n->key) {
                n->next = cur;
                n->prev = prev;
                if (prev != NULL) {
                    prev->next = n;
                } else {
                    lbl_805D7360->lists[n->grp] = n;
                }
                cur->prev = n;
                return n;
            }
        }
        n->prev = prev;
        if (prev != NULL) {
            prev->next = n;
        } else {
            lbl_805D7360->lists[n->grp] = n;
        }
        n->next = NULL;
    }
    return n;
}

s32 HandleNotes(void) {
    Node_803A3C24 *n;
    u32 i;
    s32 r;
    for (i = 0; i < 2; i++) {
        n = lbl_805D7360->lists[i];
        if (n == NULL) {
            continue;
        }
        while (n->key <= ((Tbl_803A3A28 *)lbl_805D7360)->ch[n->ch].lim[i].v) {
            synthSendKeyOff(n->f8);
            if ((lbl_805D7360->lists[i] = n->next) != NULL) {
                lbl_805D7360->lists[i]->prev = NULL;
            }
            if ((n->next = lbl_805D7360->head) != NULL) {
                lbl_805D7360->head->prev = n;
            }
            lbl_805D7360->head = n;
            n = lbl_805D7360->lists[i];
            if (n == NULL) {
                break;
            }
        }
    }
    r = 1;
    if (lbl_805D7360->lists[0] == NULL && lbl_805D7360->lists[1] == NULL) {
        r = 0;
    }
    return r;
}

void KeyOffNotes(void) {
    Node_803A3C24 *n;
    Node_803A3C24 *next;
    u32 i;

    for (i = 0; i < 2; i++) {
        for (n = lbl_805D7360->lists[i]; n != NULL; n = next) {
            next = n->next;
            synthSendKeyOff(n->f8);
            if ((lbl_805D7360->lists[i] = n->next) != NULL) {
                lbl_805D7360->lists[i]->prev = NULL;
            }
            if ((n->next = lbl_805D7360->head) != NULL) {
                lbl_805D7360->head->prev = n;
            }
            lbl_805D7360->head = n;
        }
    }
}

void seqFreeKeyOffNote(Node_803A3C24 *arg0) {
    if (arg0->next != 0) {
        arg0->next->prev = arg0->prev;
    }
    if (arg0->prev != 0) {
        arg0->prev->next = arg0->next;
    } else {
        lbl_805D7360->head = arg0->next;
    }
    if ((arg0->next = lbl_805D7364) != 0) {
        lbl_805D7364->prev = arg0;
    }
    arg0->prev = 0;
    lbl_805D7364 = arg0;
}
#pragma push
#pragma opt_common_subs on
u32 GetPublicId(u32 seqId) {
    u32 pub_id;
    SeqInst_803A3C84 *si;

    do {
        pub_id = lbl_805D7370++;
        lbl_805D7370 &= ~0x80000000;

        for (si = (SeqInst_803A3C84 *)lbl_805D737C; si != NULL; si = si->next) {
            if (si->publicId == pub_id) {
                pub_id = 0xFFFFFFFF;
                break;
            }
        }
        for (si = (SeqInst_803A3C84 *)lbl_805D7378; si != NULL; si = si->next) {
            if (si->publicId == pub_id) {
                pub_id = 0xFFFFFFFF;
                break;
            }
        }
    } while (pub_id == 0xFFFFFFFF);

    lbl_8054AB48[seqId].n.id = pub_id;
    return pub_id;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
u32 seqGetPrivateId(u32 seqId) {
    SeqInst_803A3D20 *si;
    for (si = (*(SeqInst_803A3D20 * *)&lbl_805D737C); si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = (*(SeqInst_803A3D20 * *)&lbl_805D7378); si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}
#pragma pop

#define ARR_GET_803A3D8C(arr, offset) ((void *)(offset + (u32)arr))
#define SEQ_CUR (*(SEQ_INSTANCE_803A49C8 **)&lbl_805D7360)
#define SEQ_FREE_LIST ((SEQ_INSTANCE_803A49C8 *)lbl_805D7378)
#define SEQ_RUN_LIST ((SEQ_INSTANCE_803A49C8 *)lbl_805D737C)
#define SEQ_RUN_L (*(SEQ_INSTANCE_803A49C8 **)&lbl_805D737C)
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void DoPrgChange_803A3D8C(SEQ_INSTANCE_803A49C8 *seq, u8 prg, u8 midi) {
    extern u16 lbl_80556E88[8][16];
    lbl_80556E88[lbl_805D7368][midi] = 0xFFFF;
    if (midi != 9) {
        prg = seq->normTrans[prg];
        if (prg == 0xFF) {
            return;
        }
        seq->prgState[midi].macId = seq->normtab[prg].macro;
        seq->prgState[midi].priority = seq->normtab[prg].prio;
        seq->prgState[midi].maxVoices = seq->normtab[prg].maxVoices;
        return;
    }

    prg = seq->drumTrans[prg];
    if (prg == 0xFF) {
        return;
    }
    seq->prgState[midi].macId = seq->drumtab[prg].macro;
    seq->prgState[midi].priority = seq->drumtab[prg].prio;
    seq->prgState[midi].maxVoices = seq->drumtab[prg].maxVoices;
}

static inline void BuildTransTab_803A3D8C(u8 *tab, PAGE_803A49C8 *page) {
    u8 i;

    for (i = 0; i < 128; ++i) {
        tab[i] = 0xff;
    }

    for (i = 0; page->index != 0xFF; ++i, page++) {
        tab[page->index] = i;
    }
}

u32 seqStartPlay(PAGE_803A49C8 *norm, PAGE_803A49C8 *drum, MIDISETUP_803A3D8C *midiSetup, u32 *song,
                         SND_PLAYPARA_SEQ *para, u8 studio, u16 sgid) {
    extern u16 lbl_80556E88[8][16];
    void synthVolume(u8 volume, u16 time, u8 vGroup, u8 seqMode, u32 seqId);
    void synthSetMusicVolumeType(u8 i, u8 v);
    void inpResetMidiCtrl(u8, u8, u8);
    void inpResetChannelDefaults(u8, u8);
    void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
    void InitTrackEvents(void);
    ARR_803A49C8 *arr;
    u32 *tracktab;
    s32 i;
    SEQ_INSTANCE_803A49C8 *nseq;
    SEQ_INSTANCE_803A49C8 *oldCSeq;
    u32 seqId;
    u32 bpm;

    if ((nseq = lbl_805D7374) == NULL) {
        return 0xFFFFFFFF;
    }
    if ((lbl_805D7374 = nseq->next) != NULL) {
        lbl_805D7374->prev = NULL;
    }
    if ((nseq->next = SEQ_RUN_L) != NULL) {
        SEQ_RUN_L->prev = nseq;
    }

    nseq->prev = NULL;
    SEQ_RUN_L = nseq;
    nseq->state = 1;
    for (i = 0; i < 16; ++i) {
        nseq->section[i].globalEventRoot = NULL;
    }

    seqId = nseq->index;
    nseq->syncActive = 0;
    nseq->normtab = norm;
    nseq->drumtab = drum;
    nseq->arrbase = (ARR_803A49C8 *)song;
    nseq->groupID = sgid;
    BuildTransTab_803A3D8C(nseq->normTrans, nseq->normtab);
    BuildTransTab_803A3D8C(nseq->drumTrans, nseq->drumtab);
    nseq->defVGroup = seqId + 23;
    for (i = 0; i < 64; ++i) {
        nseq->trackVolGroup[i] = nseq->defVGroup;
    }

    nseq->defStudio = studio;
    if (para == NULL) {
        nseq->trackMute[0] = -1;
        nseq->trackMute[1] = -1;
        for (i = 0; i < 16; ++i) {
            nseq->section[i].speed = 256;
        }

        synthVolume(0x7F, 0, nseq->defVGroup, 0, 0xFFFFFFFF);
    } else {
        if (para->flags & 1) {
            nseq->trackMute[0] = para->trackMute[0];
            nseq->trackMute[1] = para->trackMute[1];
        } else {
            nseq->trackMute[0] = -1;
            nseq->trackMute[1] = -1;
        }

        if (para->flags & 2) {
            for (i = 0; i < 16; ++i) {
                nseq->section[i].speed = para->speed;
            }
        } else {
            for (i = 0; i < 16; ++i) {
                nseq->section[i].speed = 256;
            }
        }

        if (para->flags & 8) {
            for (i = 0; i < para->numSeqVolDef; ++i) {
                nseq->trackVolGroup[para->seqVolDef[i].track] = para->seqVolDef[i].volGroup;
                synthSetMusicVolumeType(para->seqVolDef[i].volGroup, 0);
            }
        }

        if (para->flags & 4) {
            synthVolume(para->volume.target, para->volume.time, nseq->defVGroup, 0, 0xFFFFFFFF);

            for (i = 0; i < para->numFaded; ++i) {
                synthVolume(para->volume.target, para->volume.time, para->faded[i], 0, 0xFFFFFFFF);
            }
        }
    }

    arr = (ARR_803A49C8 *)song;
    if (arr->info & 0x80000000) {
        nseq->trackSectionTab = (u8 *)ARR_GET_803A3D8C(arr, arr->tsTab);
    } else {
        nseq->trackSectionTab = NULL;
    }

    bpm = arr->info & 0x0fffffff;

    if (!(arr->info & 0x40000000)) {
        bpm <<= 10;
    }

    for (i = 0; i < 16; ++i) {
        nseq->section[i].bpm = bpm;
        synthSetBpm(bpm >> 10, seqId, i);

        if (arr->mTrack != 0) {
            nseq->section[i].mTrack.base = (MTRACK_DATA_803A49C8 *)ARR_GET_803A3D8C(arr, arr->mTrack);
            nseq->section[i].mTrack.addr = nseq->section[i].mTrack.base;
        } else {
            nseq->section[i].mTrack.base = NULL;
        }

        nseq->section[i].loopDisable = 0;
        nseq->section[i].loopCnt = 0;
    }

    tracktab = (u32 *)ARR_GET_803A3D8C(arr, arr->tTab);
    for (i = 0; i < 64; ++i) {
        synthTrackVolume[i] = 0x7F;
        nseq->pattern[i].addr = NULL;
        if (tracktab[i] != 0) {
            nseq->track[i].addr = nseq->track[i].base = (TENTRY_803A49C8 *)ARR_GET_803A3D8C(arr, tracktab[i]);
        } else {
            nseq->track[i].addr = nseq->track[i].base = NULL;
        }
    }

    nseq->noteUsed[0] = NULL;
    nseq->noteUsed[1] = NULL;
    nseq->noteKeyOff = NULL;

    for (i = 0; i < 16; ++i) {
        inpResetMidiCtrl(i, seqId, 1);
    }
    for (i = 0; i < 16; ++i) {
        nseq->prgState[i].macId = 0xffff;
    }
    for (i = 0; i < 16; ++i) {
        inpResetChannelDefaults(i, seqId);
    }
    if (midiSetup != NULL) {
        for (i = 0; i < 16; ++i) {
            DoPrgChange_803A3D8C(nseq, midiSetup->channel[i].program, i);
            inpSetMidiCtrl(7, i, seqId, midiSetup->channel[i].volume);
            inpSetMidiCtrl(10, i, seqId, midiSetup->channel[i].panning);
            inpSetMidiCtrl(0x5B, i, seqId, midiSetup->channel[i].reverb);
            inpSetMidiCtrl(0x5D, i, seqId, midiSetup->channel[i].chorus);
        }
    }
    for (i = 0; i < 16; ++i) {
        lbl_80556E88[seqId][i] = 0xffff;
    }
    for (i = 0; i < 16; ++i) {
        nseq->section[i].time[0].high = 0;
        nseq->section[i].time[0].low = 0;
        nseq->section[i].time[1].high = 0;
        nseq->section[i].time[1].low = 0;
        nseq->section[i].timeIndex = 0;
    }
    nseq->keyOffCheck = 0;

    if (para != NULL && (para->flags & 0x10) != 0) {
        StartPause((Node_803A4964 *)nseq);
    }

    oldCSeq = SEQ_CUR;
    SEQ_CUR = nseq;
    InitTrackEvents();
    SEQ_CUR = oldCSeq;
    seqId = GetPublicId(seqId);
    return seqId;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
void HandleMasterTrack(u8 secIndex) {
    SEQ_SECTION_803A487C *section;
    section = &(*(SEQ_INSTANCE_803A487C * *)&lbl_805D7360)->section[secIndex];
    if (section->mTrack.base != NULL) {
        while (section->mTrack.addr->time != -1) {
            if (section->mTrack.addr->time > section->time[section->timeIndex].high) {
                break;
            }
            if (((*(SEQ_INSTANCE_803A487C * *)&lbl_805D7360)->arrbase->info & 0x40000000) != 0) {
                synthSetBpm((section->bpm = section->mTrack.addr->bpm) >> 10, lbl_805D7368, secIndex);
            } else {
                synthSetBpm(section->mTrack.addr->bpm, lbl_805D7368, secIndex);
                section->bpm = section->mTrack.addr->bpm << 10;
            }
            ++section->mTrack.addr;
        }
    }
}
#pragma pop

void StartPause(Node_803A4964 *arg0) {
    if (arg0->prev != 0) {
        arg0->prev->next = arg0->next;
    } else {
        lbl_805D737C = arg0->next;
    }
    if (arg0->next != 0) {
        arg0->next->prev = arg0->prev;
    }
    if ((arg0->next = lbl_805D7378) != 0) {
        lbl_805D7378->prev = arg0;
    }
    arg0->prev = 0;
    lbl_805D7378 = arg0;
    arg0->state = 2;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateId_803A49C8(u32 seqId) {
    SEQ_INSTANCE_803A49C8 *si;
    for (si = (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D737C); si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D7378); si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}
static inline void StartPause_803A49C8(SEQ_INSTANCE_803A49C8 *si) {
    if (si->prev != NULL) {
        si->prev->next = si->next;
    } else {
        (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D737C) = si->next;
    }
    if (si->next != NULL) {
        si->next->prev = si->prev;
    }
    if ((si->next = (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D7378)) != NULL) {
        (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D7378)->prev = si;
    }
    si->prev = NULL;
    (*(SEQ_INSTANCE_803A49C8 * *)&lbl_805D7378) = si;
    si->state = 2;
}
static inline void KillNotes_803A49C8(SEQ_INSTANCE_803A49C8 *seq) {
    NOTE_803A49C8 *n;
    u32 i;
    for (i = 0; i < 2; ++i) {
        for (n = seq->noteUsed[i]; n != NULL; n = n->next) {
            voiceKillSound(n->id);
        }
    }
    for (n = seq->noteKeyOff; n != NULL; n = n->next) {
        voiceKillSound(n->id);
    }
}
void seqPause(s32 seqId) {
    SEQ_INSTANCE_803A49C8 *si;
    seqId = seqGetPrivateId_803A49C8(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }
    if ((seqId & 0x80000000) == 0) {
        si = &((SEQ_INSTANCE_803A49C8 *)&lbl_8054AB48)[seqId];
        if (si->state == 1) {
            StartPause_803A49C8(si);
            KillNotes_803A49C8(si);
            ResetNotes((Owner_803A3C24 *)si);
        }
    } else {
        si = &((SEQ_INSTANCE_803A49C8 *)&lbl_8054AB48)[seqId & ~0x80000000];
        if (si->state != 0) {
            si->syncCrossInfo.flags |= 8;
        }
    }
}
#pragma pop

typedef struct PAGE_803A4B7C { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A4B7C;
typedef struct ARR_803A4B7C { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A4B7C;
typedef struct TENTRY_803A4B7C { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A4B7C;
typedef struct TRACK_803A4B7C { TENTRY_803A4B7C *base; TENTRY_803A4B7C *addr; } TRACK_803A4B7C;
typedef struct NOTE_803A4B7C { struct NOTE_803A4B7C *next; struct NOTE_803A4B7C *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A4B7C;
typedef struct NOTE_DATA_803A4B7C { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A4B7C;
typedef struct PRG_STATE_803A4B7C { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A4B7C;
typedef struct SEQ_STREAM_803A4B7C { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A4B7C;
typedef struct CPAT_803A4B7C { u32 lTime; u32 baseTime; NOTE_DATA_803A4B7C *addr; TENTRY_803A4B7C *patternInfo; SEQ_STREAM_803A4B7C pitchBend; SEQ_STREAM_803A4B7C modulation; u8 midi; } CPAT_803A4B7C;
typedef struct SEQ_EVENT_803A4B7C {
    struct SEQ_EVENT_803A4B7C *next; struct SEQ_EVENT_803A4B7C *prev; u32 time;
    union { TENTRY_803A4B7C *trackAddr; struct { NOTE_DATA_803A4B7C *addr; CPAT_803A4B7C *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A4B7C;
typedef struct MTRACK_DATA_803A4B7C { volatile u32 time; u32 bpm; } MTRACK_DATA_803A4B7C;
typedef struct MTRACK_803A4B7C { MTRACK_DATA_803A4B7C *base; MTRACK_DATA_803A4B7C *addr; } MTRACK_803A4B7C;
typedef struct TICKS_803A4B7C { u32 low; s32 high; } TICKS_803A4B7C;
typedef struct SEQ_SECTION_803A4B7C {
    MTRACK_803A4B7C mTrack; u32 bpm; TICKS_803A4B7C tickDelta[2]; SEQ_EVENT_803A4B7C *globalEventRoot; TICKS_803A4B7C time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A4B7C;
typedef struct SND_CROSSFADE_803A4B7C {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A4B7C;
typedef struct SEQ_INSTANCE_803A4B7C {
    struct SEQ_INSTANCE_803A4B7C *next; struct SEQ_INSTANCE_803A4B7C *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A4B7C *normtab; u8 normTrans[128]; PAGE_803A4B7C *drumtab; u8 drumTrans[128];
    ARR_803A4B7C *arrbase; u32 trackMute[2]; TRACK_803A4B7C track[64]; u8 trackVolGroup[64]; CPAT_803A4B7C pattern[64];
    NOTE_803A4B7C *noteUsed[2]; NOTE_803A4B7C *noteKeyOff; PRG_STATE_803A4B7C prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A4B7C syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A4B7C event[64]; u8 *trackSectionTab; SEQ_SECTION_803A4B7C section[16];
} SEQ_INSTANCE_803A4B7C;

typedef struct SeqBss_803A4B7C {
    NOTE_803A4B7C seqNote[256];
    SEQ_INSTANCE_803A4B7C seqInstance[8];
} SeqBss_803A4B7C;

}
namespace seq_803A4B7C {
extern "C" NOTE_803A4B7C lbl_80549748[256];
extern "C" SEQ_INSTANCE_803A4B7C lbl_8054AB48[8];
extern "C" u16 lbl_80556E88[8][16];
NOTE_803A4B7C lbl_80549748[256];
SEQ_INSTANCE_803A4B7C lbl_8054AB48[8];
u16 lbl_80556E88[8][16];
extern "C" SEQ_INSTANCE_803A4B7C *lbl_805D7374;
extern "C" SEQ_INSTANCE_803A4B7C *lbl_805D7378;
extern "C" SEQ_INSTANCE_803A4B7C *lbl_805D737C;
}
extern "C" {
#define seqInstance_803A4B7C seq_803A4B7C::lbl_8054AB48
#define SEQ_FREE_803A4B7C seq_803A4B7C::lbl_805D7374
#define SEQ_PAUSED_803A4B7C seq_803A4B7C::lbl_805D7378
#define SEQ_RUN_803A4B7C seq_803A4B7C::lbl_805D737C

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateId_803A4B7C(u32 seqId) {
    SEQ_INSTANCE_803A4B7C *si;
    for (si = SEQ_RUN_803A4B7C; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = SEQ_PAUSED_803A4B7C; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}

static inline void KillNotes_803A4B7C(SEQ_INSTANCE_803A4B7C *seq) {
    NOTE_803A4B7C *n;
    u32 i;
    for (i = 0; i < 2; ++i) {
        for (n = seq->noteUsed[i]; n != NULL; n = n->next) {
            voiceKillSound(n->id);
        }
    }
    for (n = seq->noteKeyOff; n != NULL; n = n->next) {
        voiceKillSound(n->id);
    }
}

void seqStop(s32 seqId) {
    SEQ_INSTANCE_803A4B7C *si;

    if ((seqId = seqGetPrivateId_803A4B7C(seqId)) == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance_803A4B7C[seqId];
        switch (si->state) {
        case 1:
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                SEQ_RUN_803A4B7C = si->next;
            }
            KillNotes_803A4B7C(&seqInstance_803A4B7C[seqId]);
            ResetNotes((Owner_803A3C24 *)&seqInstance_803A4B7C[seqId]);
            break;
        case 2:
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                SEQ_PAUSED_803A4B7C = si->next;
            }
            break;
        }

        if (si->next != NULL) {
            si->next->prev = si->prev;
        }
        si->state = 0;
        if (SEQ_FREE_803A4B7C != NULL) {
            SEQ_FREE_803A4B7C->prev = si;
        }
        si->next = SEQ_FREE_803A4B7C;
        si->prev = NULL;
        SEQ_FREE_803A4B7C = si;
    } else {
        si = &seqInstance_803A4B7C[seqId & ~0x80000000];
        if (si->state != 0) {
            si->syncSeqIdPtr = NULL;
        }
    }
}
#pragma pop

void seqKillInstancesByGroupID(u16 sgid) {
    SeqInst_803A4D4C *si;
    for (si = (*(SeqInst_803A4D4C * *)&lbl_805D737C); si != NULL; si = si->next) {
        if (si->groupID == sgid) {
            seqStop(si->publicId);
        }
    }
    for (si = (*(SeqInst_803A4D4C * *)&lbl_805D7378); si != NULL; si = si->next) {
        if (si->groupID == sgid) {
            seqStop(si->publicId);
        }
    }
}

void seqSpeed(u32 id, s16 v) {
    u8 *base = lbl_80549748;
    Node_803A4964 *n;
    u32 key = id & 0x7FFFFFFF;
    s32 h;

    for (n = lbl_805D737C; n != NULL; n = n->next) {
        if (n->id == key) {
            h = (n->idx & 0x7FFFFFFF) | (id & 0x80000000);
            goto found;
        }
    }
    for (n = lbl_805D7378; n != NULL; n = n->next) {
        if (n->id == key) {
            h = (n->idx & 0x7FFFFFFF) | (id & 0x80000000);
            goto found;
        }
    }
    h = -1;
found:
    if (!(h & 0x80000000)) {
        {
            Slot_803A4DDC *sl = (Slot_803A4DDC *)(base + h * 0x1868);
            sl->voices[0].vol = v;
            sl->voices[1].vol = v;
            sl->voices[2].vol = v;
            sl->voices[3].vol = v;
            sl->voices[4].vol = v;
            sl->voices[5].vol = v;
            sl->voices[6].vol = v;
            sl->voices[7].vol = v;
            sl->voices[8].vol = v;
            sl->voices[9].vol = v;
            sl->voices[10].vol = v;
            sl->voices[11].vol = v;
            sl->voices[12].vol = v;
            sl->voices[13].vol = v;
            sl->voices[14].vol = v;
            sl->voices[15].vol = v;
        }
    } else {
        Slot_803A4DDC *s = (Slot_803A4DDC *)(base + (h & 0x7FFFFFFF) * 0x1868);
        s->flags |= 0x20;
        s->f0 = v;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
void seqContinue(s32 seqId) {
    SEQ_INSTANCE_803A4B7C *si;

    seqId = seqGetPrivateId_803A4B7C(seqId);

    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance_803A4B7C[seqId];

        if (si->state == 2) {
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                SEQ_PAUSED_803A4B7C = si->next;
            }

            if (si->next != NULL) {
                si->next->prev = si->prev;
            }

            if ((si->next = SEQ_RUN_803A4B7C) != NULL) {
                SEQ_RUN_803A4B7C->prev = si;
            }

            si->prev = NULL;
            SEQ_RUN_803A4B7C = si;
            si->state = 1;
        }
    } else {
        seqInstance_803A4B7C[seqId & ~0x80000000].syncCrossInfo.flags &= ~8;
    }
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateId_803A4FC4(u32 seqId) {
    SEQ_INSTANCE_803A49C8 *si;
    for (si = SEQ_RUN_LIST; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = SEQ_FREE_LIST; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}

void seqMute(s32 seqId, s32 mask1, s32 mask2) {
    SeqBss_803A4FC4 *bss = (SeqBss_803A4FC4 *)lbl_80549748;
    seqId = seqGetPrivateId_803A4FC4(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        bss->seqInstance[seqId].trackMute[0] = mask1;
        bss->seqInstance[seqId].trackMute[1] = mask2;
    } else {
        seqId &= ~0x80000000;
        bss->seqInstance[seqId].syncCrossInfo.flags |= 0x10;
        bss->seqInstance[seqId].syncCrossInfo.trackMute2[0] = mask1;
        bss->seqInstance[seqId].syncCrossInfo.trackMute2[1] = mask2;
    }
}
#pragma pop

typedef struct PAGE_803A5078 { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A5078;
typedef struct ARR_803A5078 { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A5078;
typedef struct TENTRY_803A5078 { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A5078;
typedef struct TRACK_803A5078 { TENTRY_803A5078 *base; TENTRY_803A5078 *addr; } TRACK_803A5078;
typedef struct NOTE_803A5078 { struct NOTE_803A5078 *next; struct NOTE_803A5078 *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A5078;
typedef struct NOTE_DATA_803A5078 { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A5078;
typedef struct PRG_STATE_803A5078 { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A5078;
typedef struct SEQ_STREAM_803A5078 { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A5078;
typedef struct CPAT_803A5078 { u32 lTime; u32 baseTime; NOTE_DATA_803A5078 *addr; TENTRY_803A5078 *patternInfo; SEQ_STREAM_803A5078 pitchBend; SEQ_STREAM_803A5078 modulation; u8 midi; } CPAT_803A5078;
typedef struct SEQ_EVENT_803A5078 {
    struct SEQ_EVENT_803A5078 *next; struct SEQ_EVENT_803A5078 *prev; u32 time;
    union { TENTRY_803A5078 *trackAddr; struct { NOTE_DATA_803A5078 *addr; CPAT_803A5078 *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A5078;
typedef struct MTRACK_DATA_803A5078 { volatile u32 time; u32 bpm; } MTRACK_DATA_803A5078;
typedef struct MTRACK_803A5078 { MTRACK_DATA_803A5078 *base; MTRACK_DATA_803A5078 *addr; } MTRACK_803A5078;
typedef struct TICKS_803A5078 { u32 low; s32 high; } TICKS_803A5078;
typedef struct SEQ_SECTION_803A5078 {
    MTRACK_803A5078 mTrack; u32 bpm; TICKS_803A5078 tickDelta[2]; SEQ_EVENT_803A5078 *globalEventRoot; TICKS_803A5078 time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A5078;
typedef struct SND_CROSSFADE_803A5078 {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A5078;
typedef struct SEQ_INSTANCE_803A5078 {
    struct SEQ_INSTANCE_803A5078 *next; struct SEQ_INSTANCE_803A5078 *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A5078 *normtab; u8 normTrans[128]; PAGE_803A5078 *drumtab; u8 drumTrans[128];
    ARR_803A5078 *arrbase; u32 trackMute[2]; TRACK_803A5078 track[64]; u8 trackVolGroup[64]; CPAT_803A5078 pattern[64];
    NOTE_803A5078 *noteUsed[2]; NOTE_803A5078 *noteKeyOff; PRG_STATE_803A5078 prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A5078 syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A5078 event[64]; u8 *trackSectionTab; SEQ_SECTION_803A5078 section[16];
} SEQ_INSTANCE_803A5078;

typedef struct SeqBss_803A5078 {
    NOTE_803A5078 seqNote[256];
    SEQ_INSTANCE_803A5078 seqInstance[8];
} SeqBss_803A5078;

}
namespace seq_803A5078 {
extern "C" SEQ_INSTANCE_803A5078 *lbl_805D7378;
extern "C" SEQ_INSTANCE_803A5078 *lbl_805D737C;
}
extern "C" {
#define seqInstance_803A5078 seq_803A4B7C::lbl_8054AB48
#define SEQ_FREE_803A5078 seq_803A5078::lbl_805D7378
#define SEQ_RUN_803A5078 seq_803A5078::lbl_805D737C

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateId_803A5078(u32 seqId) {
    SEQ_INSTANCE_803A5078 *si;
    for (si = SEQ_RUN_803A5078; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = SEQ_FREE_803A5078; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}

void seqVolume(u8 volume, u16 time, u32 seqId, u8 mode) {
    u32 i;
    u32 pub_id;

    pub_id = seqId;
    seqId = seqGetPrivateId_803A5078(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        synthVolume(volume, time, seqInstance_803A5078[seqId].defVGroup, mode, pub_id);
        for (i = 0; i < 64; ++i) {
            if (seqInstance_803A5078[seqId].trackVolGroup[i] != seqInstance_803A5078[seqId].defVGroup) {
                synthVolume(volume, time, seqInstance_803A5078[seqId].trackVolGroup[i], 0, 0xFFFFFFFF);
            }
        }
    } else {
        seqId &= ~0x80000000;
        switch (mode & 0xF) {
        case 0:
            seqInstance_803A5078[seqId].syncCrossInfo.vol2 = volume;
            break;
        case 1:
            seqInstance_803A5078[seqId].syncSeqIdPtr = NULL;
            break;
        case 2:
            seqInstance_803A5078[seqId].syncCrossInfo.flags |= 8;
            seqInstance_803A5078[seqId].syncCrossInfo.vol2 = volume;
            break;
        case 3:
            seqInstance_803A5078[seqId].syncCrossInfo.flags |= 0x80;
            seqInstance_803A5078[seqId].syncCrossInfo.vol2 = volume;
            break;
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateId_X5214(u32 seqId) {
    SEQ_INSTANCE_803A49C8 *si;
    for (si = SEQ_RUN_LIST; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = SEQ_FREE_LIST; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}
static inline void seqSpeed_X5214(SeqBss_803A4FC4 *bss, u32 seqId, u16 speed) {
    u32 i;

    seqId = seqGetPrivateId(seqId);
    if ((seqId & 0x80000000) == 0) {
        for (i = 0; i < 16; ++i) {
            bss->seqInstance[seqId].section[i].speed = speed;
        }
    } else {
        seqId &= ~0x80000000;
        bss->seqInstance[seqId].syncCrossInfo.flags |= 0x20;
        bss->seqInstance[seqId].syncCrossInfo.speed2 = speed;
    }
}

static inline void seqMute_X5214(SeqBss_803A4FC4 *bss, u32 seqId, u32 mask1, u32 mask2) {
    seqId = seqGetPrivateId(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        bss->seqInstance[seqId].trackMute[0] = mask1;
        bss->seqInstance[seqId].trackMute[1] = mask2;
    } else {
        seqId &= ~0x80000000;
        bss->seqInstance[seqId].syncCrossInfo.flags |= 0x10;
        bss->seqInstance[seqId].syncCrossInfo.trackMute2[0] = mask1;
        bss->seqInstance[seqId].syncCrossInfo.trackMute2[1] = mask2;
    }
}

void seqCrossFade(SND_CROSSFADE_803A49C8 *ci, u32 *new_seqId, u8 irq_call) {
    void seqVolume(u8 volume, u16 time, u32 seqId, u8 mode);
    void sndSeqVolume(u8 volume, u16 time, u32 seqId, u8 mode);
    void seqContinue(s32 arg0);
    u32 seqGetPrivateId(u32 seqId);
    void sndSeqContinue(s32 arg0);
    void sndSeqMute(s32 arg0, s32 arg1, s32 arg2);
    void sndSeqSpeed(u32 seqId, u16 speed);
    u32 seqPlaySong(u16 sgid, u16 sid, void *arrfile, SND_PLAYPARA_SEQ *para, u8 irq_call, u8 studio);
    u32 sndSeqPlayEx(u16 sgid, u16 sid, void *arrfile, SND_PLAYPARA_SEQ *para, u8 studio);
    SND_PLAYPARA_SEQ pp;
    u32 seqId;
    u16 time;
    SeqBss_803A4FC4 *bss = (SeqBss_803A4FC4 *)lbl_80549748;

    seqId = seqGetPrivateId_X5214(ci->seqId1);

    if ((ci->flags & 4) != 0) {
        bss->seqInstance[seqId].syncCrossInfo = *ci;
        bss->seqInstance[seqId].syncActive = 1;
        bss->seqInstance[seqId].syncSeqIdPtr = new_seqId;
        bss->seqInstance[seqId].syncCrossInfo.flags &= ~4;
        *new_seqId = ci->seqId1 | 0x80000000;
        return;
    }

    if (irq_call) {
        time = ci->time1 < 5 ? 5 : ci->time1;
        if ((ci->flags & 1) != 0) {
            seqVolume(0, time, ci->seqId1, 2);
        } else if ((ci->flags & 0x40) != 0) {
            seqVolume(0, time, ci->seqId1, 3);
        } else {
            seqVolume(0, time, ci->seqId1, 1);
        }
    } else {
        if ((ci->flags & 1) != 0) {
            sndSeqVolume(0, ci->time1, ci->seqId1, 2);
        } else if ((ci->flags & 0x40) != 0) {
            sndSeqVolume(0, ci->time1, ci->seqId1, 3);
        } else {
            sndSeqVolume(0, ci->time1, ci->seqId1, 1);
        }
    }

    if (new_seqId == NULL) {
        return;
    }

    if ((ci->flags & 2) != 0) {
        if (seqGetPrivateId_X5214(ci->seqId2) != 0xFFFFFFFF) {
            if (irq_call) {
                seqContinue(ci->seqId2);
                seqVolume(ci->vol2, ci->time2, ci->seqId2, 0);
                if ((ci->flags & 0x10) != 0) {
                    seqMute_X5214(bss, ci->seqId2, ci->trackMute2[0], ci->trackMute2[1]);
                }
                if ((ci->flags & 0x20) != 0) {
                    seqSpeed_X5214(bss, ci->seqId2, ci->speed2);
                }
            } else {
                sndSeqContinue(ci->seqId2);
                sndSeqVolume(ci->vol2, ci->time2, ci->seqId2, 0);
                if ((ci->flags & 0x10) != 0) {
                    sndSeqMute(ci->seqId2, ci->trackMute2[0], ci->trackMute2[1]);
                }
                if ((ci->flags & 0x20) != 0) {
                    sndSeqSpeed(ci->seqId2, ci->speed2);
                }
            }
            *new_seqId = ci->seqId2;
        } else {
            *new_seqId = 0xFFFFFFFF;
        }
    } else {
        pp.flags = 4;
        if ((ci->flags & 8) != 0) {
            pp.flags |= 0x10;
        }
        if ((ci->flags & 0x20) != 0) {
            pp.flags |= 2;
            pp.speed = ci->speed2;
        }
        if ((ci->flags & 0x10) != 0) {
            pp.flags |= 1;
            pp.trackMute[0] = ci->trackMute2[0];
            pp.trackMute[1] = ci->trackMute2[1];
        }
        pp.volume.time = ci->time2;
        pp.volume.target = ci->vol2;
        pp.numFaded = 0;
        if (irq_call != 0) {
            if ((*new_seqId = seqPlaySong(ci->gid2, ci->sid2, ci->arr2, &pp, 1, ci->studio2)) !=
                    0xFFFFFFFF &&
                (ci->flags & 0x80) != 0) {
                seqMute_X5214(bss, *new_seqId, 0, 0);
            }
        } else {
            if ((*new_seqId = sndSeqPlayEx(ci->gid2, ci->sid2, ci->arr2, &pp, ci->studio2)) !=
                    0xFFFFFFFF &&
                (ci->flags & 0x80) != 0) {
                sndSeqMute(*new_seqId, 0, 0);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs on
u8 *GetStreamValue(u8 *stream, u16 *deltaTime, s16 *deltaData) {
    u8 b1;
    u8 b2;
    s16 v;

    b1 = stream[0];
    b2 = stream[1];
    if (b1 == 0x80 && b2 == 0) {
        return NULL;
    }

    if ((b1 & 0x80) != 0) {
        *deltaTime = ((b1 & 0x7f) << 8) | b2;
        stream += 2;
    } else {
        *deltaTime = b1;
        stream += 1;
    }

    b1 = stream[0];
    b2 = stream[1];
    if ((b1 & 0x80) != 0) {
        v = ((b1 & 0x7f) << 8) | b2;
        v <<= 1;
        v >>= 1;
        *deltaData = v;
        stream += 2;
    } else {
        v = b1;
        v <<= 9;
        v >>= 9;
        *deltaData = v;
        stream += 1;
    }

    return stream;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
Node_803A5A04 *GenerateNextTrackEvent(u8 trackId) {
    TRACK_803A49C8 *track;
    CPAT_803A49C8 *pattern;
    SEQ_EVENT_803A49C8 *ev;
    u32 patternTime;
    u32 pitchTime;
    u32 modTime;

    track = &SEQ_CUR->track[trackId];
    pattern = &SEQ_CUR->pattern[trackId];

    if (track->addr != NULL) {
        ev = &SEQ_CUR->event[trackId];
        ev->trackId = trackId;
        ev->info.pattern.base = pattern;

        if (pattern->addr == NULL) {
        null_pattern_addr:
            if (track->addr->pattern == 0xffff) {
                track->addr = NULL;
                return NULL;
            }

            if (track->addr->pattern == 0xfffe) {
                if (SEQ_CUR->trackSectionTab == NULL) {
                    if (SEQ_CUR->section[0].loopDisable) {
                        track->addr = NULL;
                        return NULL;
                    }
                } else if (SEQ_CUR->section[SEQ_CUR->trackSectionTab[trackId]].loopDisable) {
                    track->addr = NULL;
                    return NULL;
                }

                ev->type = 3;
                ev->time = track->addr->time;
                track->addr = &track->base[*((u16 *)&track->addr->transpose)];
                return (Node_803A5A04 *)ev;
            }

            ev->type = 4;
            ev->time = track->addr->time;
            ev->info.trackAddr = track->addr;
            ++track->addr;
            return (Node_803A5A04 *)ev;
        }

        pitchTime = pattern->pitchBend.nextTime;
        modTime = pattern->modulation.nextTime;

    loop:
        patternTime = pattern->addr->time + pattern->lTime;
        if (patternTime >= pitchTime) {
            goto use_pitch_time;
        }
        if (patternTime >= modTime) {
            goto use_mod_time;
        }
        if (pattern->addr->key == 0xff && pattern->addr->velocity == 0xff) {
            pattern->addr = NULL;
            goto null_pattern_addr;
        }

        ev->info.trackAddr = (TENTRY_803A49C8 *)pattern->addr;
        pattern->lTime = patternTime;

        if ((pattern->addr->key & 0x80) != 0) {
            pattern->addr = (NOTE_DATA_803A49C8 *)((u8 *)pattern->addr + 4);
            goto use_pattern_time;
        }
        if ((pattern->addr->key | pattern->addr->velocity) == 0) {
            pattern->addr = (NOTE_DATA_803A49C8 *)((u8 *)pattern->addr + 4);
            goto loop;
        }
        ++pattern->addr;

    use_pattern_time:
        ev->type = 0;
        ev->time = patternTime + pattern->baseTime;
        goto end;

    use_pitch_time:
        if (pitchTime < modTime) {
            ev->time = pitchTime + pattern->baseTime;
            ev->type = 2;
            goto end;
        }

    use_mod_time:
        ev->time = modTime + pattern->baseTime;
        ev->type = 1;

    end:
        return (Node_803A5A04 *)ev;
    }

    return NULL;
}
#pragma pop

void InsertGlobalEvent(List_803A5A04 *arg0, Node_803A5A04 *arg1) {
    Node_803A5A04 *p = arg0->head;
    Node_803A5A04 *q = 0;
    while (p != 0) {
        if (p->key > arg1->key) {
            arg1->next = p;
            arg1->prev = q;
            if (q != 0) {
                q->next = arg1;
            } else {
                arg0->head = arg1;
            }
            p->prev = arg1;
            return;
        }
        q = p;
        p = p->next;
    }
    arg1->prev = q;
    if (q != 0) {
        q->next = arg1;
    } else {
        arg0->head = arg1;
    }
    arg1->next = 0;
}

#define ARR_GET_803A5A78(arr, offset) ((void *)(offset + (u32)arr))
#define CSEQ_5A78 (*(SEQ_INSTANCE_803A6364 **)&lbl_805D7360)
#define NOTEFREE_5A78 (*(NOTE_803A6364 **)&lbl_805D7364)
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void InitStream_803A5A78(SEQ_STREAM_803A6364 *stream, u32 streamDataOffset) {
    u16 delta;
    if (streamDataOffset != 0) {
        if ((stream->nextAddr = GetStreamValue((u8 *)ARR_GET_803A5A78(CSEQ_5A78->arrbase, streamDataOffset), &delta,
                                                     &stream->nextDelta)) != NULL) {
            stream->nextTime = delta;
        } else {
            stream->nextTime = 0x7fffffff;
        }
    } else {
        stream->nextTime = 0x7fffffff;
    }
}

static inline u16 HandleStream_803A5A78(SEQ_STREAM_803A6364 *stream) {
    u16 delta;
    stream->value += stream->nextDelta;
    if (stream->nextAddr != NULL) {
        if ((stream->nextAddr = GetStreamValue(stream->nextAddr, &delta, &stream->nextDelta)) != NULL) {
            stream->nextTime += delta;
        } else {
            stream->nextTime = 0x7fffffff;
        }
    } else {
        stream->nextTime = 0x7fffffff;
    }
    return stream->value;
}

static inline void DoPrgChange_803A5A78(SeqBss_803A5A78 *bss, SEQ_INSTANCE_803A6364 *seq, u8 prg, u8 midi) {
    bss->seqMIDIPriority[lbl_805D7368][midi] = 0xFFFF;
    if (midi != 9) {
        prg = seq->normTrans[prg];
        if (prg == 0xFF) {
            return;
        }
        seq->prgState[midi].macId = seq->normtab[prg].macro;
        seq->prgState[midi].priority = seq->normtab[prg].prio;
        seq->prgState[midi].maxVoices = seq->normtab[prg].maxVoices;
        return;
    }

    prg = seq->drumTrans[prg];
    if (prg == 0xFF) {
        return;
    }
    seq->prgState[midi].macId = seq->drumtab[prg].macro;
    seq->prgState[midi].priority = seq->drumtab[prg].prio;
    seq->prgState[midi].maxVoices = seq->drumtab[prg].maxVoices;
}

static inline void FreeNote_803A5A78(NOTE_803A6364 *n) {
    if (n->next != NULL) {
        n->next->prev = n->prev;
    }
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        CSEQ_5A78->noteUsed[n->timeIndex] = n->next;
    }
    if ((n->next = NOTEFREE_5A78) != NULL) {
        NOTEFREE_5A78->prev = n;
    }
    n->prev = NULL;
    NOTEFREE_5A78 = n;
}

SEQ_EVENT_803A6364 *HandleEvent(SEQ_EVENT_803A6364 *event, u8 secIndex, u32 *loopFlag) {
    u32 synthStartSound(u16 id, u8 prio, u8 max, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet,
                             u8 section, u16 step, u16 trackid, u8 vGroup, s16 prioOffset, u8 studio, u32 itd);
    SeqBss_803A5A78 *bss = (SeqBss_803A5A78 *)lbl_80549748;
    CPAT_803A6364 *pa;
    NOTE_DATA_803A6364 *pe;
    s32 velocity;
    s32 key;
    u8 midi;
    u16 macId;
    NOTE_803A6364 *note;
    TENTRY_803A6364 *tEntry;
    CPAT_803A6364 *pattern;
    u32 *pTab;
    SEQ_PATTERN_803A5A78 *pptr;

    switch (event->type) {
    case 4:
        tEntry = event->info.trackAddr;
        pattern = &CSEQ_5A78->pattern[event->trackId];
        pTab = (u32 *)ARR_GET_803A5A78(CSEQ_5A78->arrbase, CSEQ_5A78->arrbase->pTab);
        pptr = (SEQ_PATTERN_803A5A78 *)ARR_GET_803A5A78(CSEQ_5A78->arrbase, pTab[tEntry->pattern]);
        pattern->addr = (NOTE_DATA_803A6364 *)&pptr->noteData;
        pattern->lTime = 0;
        pattern->baseTime = tEntry->time;
        pattern->patternInfo = tEntry;
        InitStream_803A5A78(&pattern->pitchBend, pptr->pitchBend);
        pattern->pitchBend.value = 0x2000;
        InitStream_803A5A78(&pattern->modulation, pptr->modulation);
        pattern->modulation.value = 0;
        pattern->midi = ((u8 *)ARR_GET_803A5A78(CSEQ_5A78->arrbase, CSEQ_5A78->arrbase->tmTab))[event->trackId];
        if (tEntry->prgChange != 0xff) {
            DoPrgChange_803A5A78(bss, CSEQ_5A78, tEntry->prgChange, pattern->midi);
        }
        if (tEntry->velocity != 0xff) {
            inpSetMidiCtrl(7, pattern->midi, lbl_805D7368, tEntry->velocity);
        }
        break;

    case 0:
        pe = event->info.pattern.addr;
        pa = event->info.pattern.base;
        key = pe->key;
        velocity = pe->velocity;
        midi = pa->midi;

        if ((key & 0x80) != 0) {
            switch (velocity) {
            case 0:
                DoPrgChange_803A5A78(bss, CSEQ_5A78, key & 0x7f, midi);
                break;
            case 1:
                inpSetMidiCtrl(0x82, midi, lbl_805D7368, key & 0x7f);
                break;
            default:
                if ((velocity & 0x80) != 0x80) {
                    break;
                }
                switch (velocity & 0x7f) {
                case 0x68:
                    if (CSEQ_5A78->syncActive) {
                        seqCrossFade((SND_CROSSFADE_803A49C8 *)&CSEQ_5A78->syncCrossInfo, CSEQ_5A78->syncSeqIdPtr, 1);
                        CSEQ_5A78->syncActive = 0;
                    }
                    break;
                case 0x69:
                    bss->seqMIDIPriority[lbl_805D7368][midi] = key & 0x7f;
                    break;
                case 0x6a:
                    bss->seqMIDIPriority[lbl_805D7368][midi] = (key & 0x7f) + 0x80;
                    break;
                case 0x79:
                    inpResetMidiCtrl(midi, lbl_805D7368, 0);
                    break;
                case 0x7b:
                    KeyOffNotes();
                    break;
                default:
                    inpSetMidiCtrl(velocity & 0x7f, midi, lbl_805D7368, key & 0x7f);
                    break;
                }
            }
            break;
        }

        if ((CSEQ_5A78->trackMute[event->trackId / 32] & (1 << (event->trackId & 0x1f))) != 0) {
            if ((macId = CSEQ_5A78->prgState[midi].macId) != 0xffff) {
                key += pa->patternInfo->transpose;
                key = key > 0x7f ? 0x7f : key < 0 ? 0 : key;

                velocity += pa->patternInfo->velocityAdd;
                velocity = velocity > 0x7f ? 0x7f : velocity < 0 ? 0 : velocity;

                if ((note = (NOTE_803A6364 *)AllocateNote(event->time + pe->length, secIndex)) != NULL) {
                    if ((note->id = synthStartSound(
                             macId, CSEQ_5A78->prgState[midi].priority, CSEQ_5A78->prgState[midi].maxVoices,
                             key, velocity, 64, midi, lbl_805D7368, secIndex, 0, event->trackId,
                             CSEQ_5A78->trackVolGroup[event->trackId], lbl_805D736C ? -1 : 0,
                             CSEQ_5A78->defStudio, synthITDDefault[CSEQ_5A78->defStudio].b0)) == 0xFFFFFFFF) {
                        FreeNote_803A5A78(note);
                    }
                }
            }
        }
        break;

    case 2:
        pa = event->info.pattern.base;
        inpSetMidiCtrl14(0x80, pa->midi, lbl_805D7368, HandleStream_803A5A78(&pa->pitchBend));
        break;

    case 1:
        pa = event->info.pattern.base;
        inpSetMidiCtrl14(1, pa->midi, lbl_805D7368, HandleStream_803A5A78(&pa->modulation));
        break;

    case 3:
        *loopFlag |= 1;
        return NULL;
    }

    return (SEQ_EVENT_803A6364 *)GenerateNextTrackEvent(event->trackId);
}
#pragma pop
#undef CSEQ_5A78
#undef NOTEFREE_5A78

void InitTrackEvents(void) {
    u32 i;
    Node_803A5A04 *n;

    if (((Owner_803A61F8 *)lbl_805D7360)->map == NULL) {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&((Owner_803A61F8 *)lbl_805D7360)->chans[0], n);
            }
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&((Owner_803A61F8 *)lbl_805D7360)->chans[((Owner_803A61F8 *)lbl_805D7360)->map[i]], n);
            }
        }
    }
}

void InitTrackEventsSection(u8 ch) {
    u32 i;
    Node_803A5A04 *n;

    if (((Owner_803A61F8 *)lbl_805D7360)->map == NULL) {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&((Owner_803A61F8 *)lbl_805D7360)->chans[0], n);
            }
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            if (ch == ((Owner_803A61F8 *)lbl_805D7360)->map[i]) {
                n = GenerateNextTrackEvent(i);
                if (n != NULL) {
                    InsertGlobalEvent(&((Owner_803A61F8 *)lbl_805D7360)->chans[ch], n);
                }
            }
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline float fmodf_803A6364(float x, float m) {
    float a = __fabsf(m);
    float b = __fabsf(x);
    if (a > b)
        return x;
    else {
        return x - m * (long long)(x / m);
    }
}
static inline void SetTickDelta_803A6364(SEQ_SECTION_803A6364 *section, u32 deltaTime) {
    float tickDelta = (float)section->bpm * (float)deltaTime * (1.f / (40960000.f));
    tickDelta *= section->speed * (1.f / 256.f);
    section->tickDelta[section->timeIndex].low = fmodf_803A6364(tickDelta * 65536.f, 65536.f);
    section->tickDelta[section->timeIndex].high = floorf(tickDelta);
}
static inline void RewindMTrack_803A6364(u8 secIndex, u32 deltaTime) {
    if ((*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->section[secIndex].mTrack.base == NULL) {
        return;
    }
    (*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->section[secIndex].mTrack.addr = (*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->section[secIndex].mTrack.base;
    HandleMasterTrack(secIndex);
    SetTickDelta_803A6364((*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->section + secIndex, deltaTime);
}
static inline u32 GetNextEventTime_803A6364(SEQ_SECTION_803A6364 *section) {
    if (section->globalEventRoot == NULL) {
        return 0;
    }
    return section->globalEventRoot->time;
}
static inline SEQ_EVENT_803A6364 *GetGlobalEvent_803A6364(SEQ_SECTION_803A6364 *section) {
    SEQ_EVENT_803A6364 *ev;
    ev = section->globalEventRoot;
    if (ev != NULL && ((section->globalEventRoot = ev->next) != NULL)) {
        section->globalEventRoot->prev = NULL;
    }
    return ev;
}
u32 HandleTrackEvents(u8 secIndex, u32 deltaTime) {
    SEQ_EVENT_803A6364 *ev;
    u32 loopFlag;
    SEQ_SECTION_803A6364 *section;
    u8 unused[4];
    section = &(*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->section[secIndex];
    loopFlag = 0;
    while (GetNextEventTime_803A6364(section) <= section->time[section->timeIndex].high) {
        if ((ev = GetGlobalEvent_803A6364(section)) == NULL) {
            if (!loopFlag) {
                return 0;
            }
            loopFlag = 0;
            section->timeIndex ^= 1;
            section->time[section->timeIndex].high = (*(SEQ_INSTANCE_803A6364 * *)&lbl_805D7360)->arrbase->loopPoint[secIndex];
            section->time[section->timeIndex].low = section->time[section->timeIndex ^ 1].low;
            RewindMTrack_803A6364(secIndex, deltaTime);
            section->loopCnt += 1;
            InitTrackEventsSection(secIndex);
            continue;
        }
        if ((ev = HandleEvent(ev, secIndex, &loopFlag)) != NULL) {
            InsertGlobalEvent((List_803A5A04 *)(section), (Node_803A5A04 *)(ev));
        }
    }
    return 1;
}
#pragma pop

typedef struct PAGE_803A65D8 { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A65D8;
typedef struct ARR_803A65D8 { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A65D8;
typedef struct TENTRY_803A65D8 { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A65D8;
typedef struct TRACK_803A65D8 { TENTRY_803A65D8 *base; TENTRY_803A65D8 *addr; } TRACK_803A65D8;
typedef struct NOTE_803A65D8 { struct NOTE_803A65D8 *next; struct NOTE_803A65D8 *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A65D8;
typedef struct NOTE_DATA_803A65D8 { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A65D8;
typedef struct PRG_STATE_803A65D8 { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A65D8;
typedef struct SEQ_STREAM_803A65D8 { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A65D8;
typedef struct CPAT_803A65D8 { u32 lTime; u32 baseTime; NOTE_DATA_803A65D8 *addr; TENTRY_803A65D8 *patternInfo; SEQ_STREAM_803A65D8 pitchBend; SEQ_STREAM_803A65D8 modulation; u8 midi; } CPAT_803A65D8;
typedef struct SEQ_EVENT_803A65D8 {
    struct SEQ_EVENT_803A65D8 *next; struct SEQ_EVENT_803A65D8 *prev; u32 time;
    union { TENTRY_803A65D8 *trackAddr; struct { NOTE_DATA_803A65D8 *addr; CPAT_803A65D8 *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A65D8;
typedef struct MTRACK_DATA_803A65D8 { volatile u32 time; u32 bpm; } MTRACK_DATA_803A65D8;
typedef struct MTRACK_803A65D8 { MTRACK_DATA_803A65D8 *base; MTRACK_DATA_803A65D8 *addr; } MTRACK_803A65D8;
typedef struct TICKS_803A65D8 { u32 low; s32 high; } TICKS_803A65D8;
typedef struct SEQ_SECTION_803A65D8 {
    MTRACK_803A65D8 mTrack; u32 bpm; TICKS_803A65D8 tickDelta[2]; SEQ_EVENT_803A65D8 *globalEventRoot; TICKS_803A65D8 time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A65D8;
typedef struct SND_CROSSFADE_803A65D8 {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A65D8;
typedef struct SEQ_INSTANCE_803A65D8 {
    struct SEQ_INSTANCE_803A65D8 *next; struct SEQ_INSTANCE_803A65D8 *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A65D8 *normtab; u8 normTrans[128]; PAGE_803A65D8 *drumtab; u8 drumTrans[128];
    ARR_803A65D8 *arrbase; u32 trackMute[2]; TRACK_803A65D8 track[64]; u8 trackVolGroup[64]; CPAT_803A65D8 pattern[64];
    NOTE_803A65D8 *noteUsed[2]; NOTE_803A65D8 *noteKeyOff; PRG_STATE_803A65D8 prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A65D8 syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A65D8 event[64]; u8 *trackSectionTab; SEQ_SECTION_803A65D8 section[16];
} SEQ_INSTANCE_803A65D8;

}
namespace seq_803A65D8 { extern "C" SEQ_INSTANCE_803A65D8 *lbl_805D7360; }
extern "C" {
#define SEQ_CUR_803A65D8 seq_803A65D8::lbl_805D7360
#define SEQ_RUN_803A65D8 (*(SEQ_INSTANCE_803A65D8 **)&lbl_805D737C)
#define SEQ_FREE_803A65D8 (*(SEQ_INSTANCE_803A65D8 **)&lbl_805D7374)

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline float fmodf_803A65D8(float x, float m) {
    float a = __fabsf(m);
    float b = __fabsf(x);
    if (a > b)
        return x;
    else {
        return x - m * (long long)(x / m);
    }
}

static inline void SetTickDelta_803A65D8(SEQ_SECTION_803A65D8 *section, u32 deltaTime) {
    float tickDelta = (float)section->bpm * (float)deltaTime * (1.f / (40960000.f));
    tickDelta *= section->speed * (1.f / 256.f);

    section->tickDelta[section->timeIndex].low = fmodf_803A65D8(tickDelta * 65536.f, 65536.f);
    section->tickDelta[section->timeIndex].high = floorf(tickDelta);
}

static inline void HandleMasterTrack_803A65D8(u8 secIndex) {
    SEQ_SECTION_803A65D8 *section;

    section = &SEQ_CUR_803A65D8->section[secIndex];
    if (section->mTrack.base != NULL) {
        while (section->mTrack.addr->time != -1) {
            if (section->mTrack.addr->time > section->time[section->timeIndex].high) {
                break;
            }

            if ((SEQ_CUR_803A65D8->arrbase->info & 0x40000000) != 0) {
                synthSetBpm((section->bpm = section->mTrack.addr->bpm) >> 10, lbl_805D7368, secIndex);
            } else {
                synthSetBpm(section->mTrack.addr->bpm, lbl_805D7368, secIndex);
                section->bpm = section->mTrack.addr->bpm << 10;
            }

            ++section->mTrack.addr;
        }
    }
}

static inline void HandleKeyOffNotes_803A65D8(void) {
    NOTE_803A65D8 *n;
    NOTE_803A65D8 *nn;
    if (!SEQ_CUR_803A65D8->keyOffCheck) {
        n = SEQ_CUR_803A65D8->noteKeyOff;
        while (n != NULL) {
            nn = n->next;
            if (n->id != 0xFFFFFFFF && sndFXCheck(n->id) == 0xFFFFFFFF) {
                seqFreeKeyOffNote((Node_803A3C24 *)n);
            }
            n = nn;
        }
    }

    SEQ_CUR_803A65D8->keyOffCheck = (SEQ_CUR_803A65D8->keyOffCheck + 1) % 5;
}

void seqHandle(u32 deltaTime) {
    u32 x;
    u32 i;
    u32 j;
    u32 eventsActive;
    u32 notesActive;
    SEQ_INSTANCE_803A65D8 *si;
    SEQ_INSTANCE_803A65D8 *nextSi;
    u8 unused[24];

    if (deltaTime == 0) {
        return;
    }

    si = SEQ_RUN_803A65D8;
    while (si != NULL) {
        nextSi = si->next;
        SEQ_CUR_803A65D8 = si;
        lbl_805D7368 = si->index;
        lbl_805D736C = synthIsFadeOutActive(si->defVGroup);

        if (SEQ_CUR_803A65D8->trackSectionTab == NULL) {
            HandleMasterTrack_803A65D8(0);
            SetTickDelta_803A65D8(SEQ_CUR_803A65D8->section, deltaTime);
            eventsActive = HandleTrackEvents(0, deltaTime);
            notesActive = HandleNotes();
            HandleKeyOffNotes_803A65D8();

            for (i = 0; i < 2; ++i) {
                x = SEQ_CUR_803A65D8->section[0].time[i].low + SEQ_CUR_803A65D8->section[0].tickDelta[i].low;
                SEQ_CUR_803A65D8->section[0].time[i].low = x & 0xffff;
                x >>= 16;
                SEQ_CUR_803A65D8->section[0].time[i].high += x + SEQ_CUR_803A65D8->section[0].tickDelta[i].high;
            }
        } else {
            eventsActive = 0;
            for (i = 0; i < 16; ++i) {
                HandleMasterTrack_803A65D8(i);
                SetTickDelta_803A65D8(&SEQ_CUR_803A65D8->section[i], deltaTime);
                eventsActive |= HandleTrackEvents(i, deltaTime);
            }
            notesActive = HandleNotes();
            HandleKeyOffNotes_803A65D8();

            for (i = 0; i < 16; ++i) {
                for (j = 0; j < 2; ++j) {
                    x = SEQ_CUR_803A65D8->section[i].time[j].low + SEQ_CUR_803A65D8->section[i].tickDelta[j].low;
                    SEQ_CUR_803A65D8->section[i].time[j].low = x & 0xffff;
                    x >>= 16;
                    SEQ_CUR_803A65D8->section[i].time[j].high += x + SEQ_CUR_803A65D8->section[i].tickDelta[j].high;
                }
            }
        }

        if (eventsActive == 0 && notesActive == 0) {
            if (si->prev != NULL) {
                si->prev->next = nextSi;
            } else {
                SEQ_RUN_803A65D8 = nextSi;
            }
            if (nextSi != NULL) {
                nextSi->prev = si->prev;
            }
            ResetNotes((Owner_803A3C24 *)si);
            si->state = 0;
            si->prev = NULL;
            if ((si->next = SEQ_FREE_803A65D8) != NULL) {
                SEQ_FREE_803A65D8->prev = si;
            }
            SEQ_FREE_803A65D8 = si;
        }
        si = nextSi;
    }
}
#pragma pop

}
namespace seq_803A6CA0 { extern "C" NOTE_803A4B7C *lbl_805D7364; }
extern "C" {
#define seqNote_803A6CA0 seq_803A4B7C::lbl_80549748
#define seqInstance_803A6CA0 seq_803A4B7C::lbl_8054AB48
#define seqMIDIPriority_803A6CA0 seq_803A4B7C::lbl_80556E88
#define noteFree_803A6CA0 seq_803A6CA0::lbl_805D7364
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline void ClearNotes_803A6CA0(void) {
    NOTE_803A4B7C *ln = NULL;
    s32 i;

    noteFree_803A6CA0 = &seqNote_803A6CA0[0];
    for (i = 0; i < 256; ++i) {
        seqNote_803A6CA0[i].prev = ln;
        if (ln != NULL) {
            ln->next = &seqNote_803A6CA0[i];
        }
        ln = &seqNote_803A6CA0[i];
    }

    ln->next = NULL;
}

static inline void InitPublicIds_803A6CA0(void) { lbl_805D7370 = 0; }

void seqInit(void) {
    u32 i;
    u32 j;

    SEQ_RUN_803A4B7C = NULL;
    SEQ_PAUSED_803A4B7C = NULL;
    for (i = 0; i < 8; ++i) {
        if (i == 0) {
            SEQ_FREE_803A4B7C = &seqInstance_803A6CA0[i];
            seqInstance_803A6CA0[i].prev = NULL;
        } else {
            seqInstance_803A6CA0[i - 1].next = &seqInstance_803A6CA0[i];
            seqInstance_803A6CA0[i].prev = &seqInstance_803A6CA0[i - 1];
        }
        seqInstance_803A6CA0[i].index = i;
        seqInstance_803A6CA0[i].state = 0;
        for (j = 0; j < 0x10; ++j) {
            seqMIDIPriority_803A6CA0[i][j] = 0xffff;
        }
    }
    seqInstance_803A6CA0[i - 1].next = NULL;
    ClearNotes_803A6CA0();
    InitPublicIds_803A6CA0();
}
#pragma pop

Owner_803A3C24 *lbl_805D7360;
Node_803A3C24 *lbl_805D7364;
u32 lbl_805D7368;
u8 lbl_805D736C;
u32 lbl_805D7370;
SEQ_INSTANCE_803A49C8 *lbl_805D7374;
Node_803A4964 *lbl_805D7378;
Node_803A4964 *lbl_805D737C;

}
