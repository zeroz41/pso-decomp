#define MUSYX_SEQ_IMPL
#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

#define ARR_PTR(arr, offset) ((void *)((offset) + (uaddr)(arr)))

typedef struct SynthSeqArr {
    u32 tTab;
    u32 pTab;
    u32 tmTab;
    u32 mTrack;
    u32 info;
    u32 loopPoint[16];
    u32 tsTab;
} SynthSeqArr;

typedef struct SynthSeqTrackEntry {
    u32 time;
    u8 prgChange;
    u8 velocity;
    u8 res[2];
    u16 pattern;
    union {
        struct {
            s8 transpose;
            s8 velocityAdd;
        } note;
        u16 jumpTarget;
    } data;
} SynthSeqTrackEntry;

typedef struct SynthSeqTrack {
    SynthSeqTrackEntry *base;
    SynthSeqTrackEntry *addr;
} SynthSeqTrack;

typedef struct SynthSeqNote {
    struct SynthSeqNote *next;
    struct SynthSeqNote *prev;
    u32 id;
    s32 endTime;
    u8 section;
    u8 timeIndex;
    u8 reserved[2];
} SynthSeqNote;

typedef struct SynthSeqCtrlData {
    u16 time;
    u8 key;
    u8 velocity;
} SynthSeqCtrlData;

typedef struct SynthSeqNoteData {
    u16 time;
    u8 key;
    u8 velocity;
    u16 length;
} SynthSeqNoteData;

typedef struct SynthSeqPrgState {
    u16 macId;
    u8 priority;
    u8 maxVoices;
} SynthSeqPrgState;

typedef struct SynthSeqStream {
    u8 *nextAddr;
    u16 value;
    s16 nextDelta;
    u32 nextTime;
} SynthSeqStream;

typedef struct SynthSeqPattern {
    u32 headerLen;
    u32 pitchBend;
    u32 modulation;
    u32 noteData;
} SynthSeqPattern;

typedef struct SynthSeqPatternState {
    u32 lTime;
    u32 baseTime;
    SynthSeqNoteData *addr;
    SynthSeqTrackEntry *patternInfo;
    SynthSeqStream pitchBend;
    SynthSeqStream modulation;
    u8 midi;
} SynthSeqPatternState;

typedef struct SynthSeqEvent {
    struct SynthSeqEvent *next;
    struct SynthSeqEvent *prev;
    u32 time;
    union {
        SynthSeqTrackEntry *trackAddr;
        struct {
            SynthSeqNoteData *addr;
            SynthSeqPatternState *base;
        } pattern;
    } info;
    u8 type;
    u8 trackId;
} SynthSeqEvent;

typedef struct SynthSeqMasterTrackEntry {
    volatile u32 time;
    u32 bpm;
} SynthSeqMasterTrackEntry;

typedef struct SynthSeqMasterTrack {
    SynthSeqMasterTrackEntry *base;
    SynthSeqMasterTrackEntry *addr;
} SynthSeqMasterTrack;

typedef struct SynthSeqTicks {
    u32 low;
    s32 high;
} SynthSeqTicks;

typedef struct SynthSeqSection {
    SynthSeqMasterTrack mTrack;
    u32 bpm;
    SynthSeqTicks tickDelta[2];
    SynthSeqEvent *globalEventRoot;
    SynthSeqTicks time[2];
    u8 timeIndex;
    u16 speed;
    u16 loopCnt;
    u8 loopDisable;
} SynthSeqSection;

typedef struct SynthSeqInstance {
    struct SynthSeqInstance *next;
    struct SynthSeqInstance *prev;
    u8 state;
    u8 index;
    u16 groupID;
    u32 publicId;
    SynthSeqPage *normtab;
    u8 normTrans[128];
    SynthSeqPage *drumtab;
    u8 drumTrans[128];
    SynthSeqArr *arrbase;
    u32 trackMute[2];
    SynthSeqTrack track[64];
    u8 trackVolGroup[64];
    SynthSeqPatternState pattern[64];
    SynthSeqNote *noteUsed[2];
    SynthSeqNote *noteKeyOff;
    SynthSeqPrgState prgState[16];
    u8 defVGroup;
    SynthCrossfade syncCrossInfo;
    u32 *syncSeqIdPtr;
    u8 syncActive;
    u8 defStudio;
    u8 keyOffCheck;
    SynthSeqEvent event[64];
    u8 *trackSectionTab;
    SynthSeqSection section[16];
} SynthSeqInstance;

typedef struct SynthSeqBss {
    SynthSeqNote seqNote[256];
    SynthSeqInstance seqInstance[8];
    u16 seqMIDIPriority[8][16];
} SynthSeqBss;

extern "C" {

SynthSeqNote seqNote[256];
SynthSeqInstance seqInstance[8];
u16 seqMIDIPriority[8][16];

extern SynthSeqInstance *seqCurrent;
extern SynthSeqNote *seqNoteFree;
extern u32 seqCurrentId;
extern u8 seqFadeOutActive;
extern u32 seqPublicId;
extern SynthSeqInstance *seqFreeList;
extern SynthSeqInstance *seqPausedList;
extern SynthSeqInstance *seqActiveList;

void StartPause(SynthSeqInstance *si);
void HandleMasterTrack(u8 secIndex);
SynthSeqEvent *GenerateNextTrackEvent(u8 trackId);
void InsertGlobalEvent(SynthSeqSection *section, SynthSeqEvent *ev);
SynthSeqEvent *HandleEvent(SynthSeqEvent *event, u8 secIndex, u32 *loopFlag);
void InitTrackEvents(void);
void InitTrackEventsSection(u8 ch);
u32 HandleTrackEvents(u8 secIndex, u32 deltaTime);

void ResetNotes(SynthSeqInstance *o) {
    u32 i;
    SynthSeqNote *p;
    SynthSeqNote *q;

    for (i = 0; i < 2; i++) {
        if ((p = o->noteUsed[i]) != NULL) {
            while ((q = p->next) != NULL) {
                p = q;
            }
            if (seqNoteFree != NULL) {
                p->next = seqNoteFree;
                seqNoteFree->prev = p;
            }
            seqNoteFree = o->noteUsed[i];
            o->noteUsed[i] = NULL;
        }
    }
    if ((p = o->noteKeyOff) != NULL) {
        while ((q = p->next) != NULL) {
            p = q;
        }
        if (seqNoteFree != NULL) {
            p->next = seqNoteFree;
            seqNoteFree->prev = p;
        }
        seqNoteFree = o->noteKeyOff;
        o->noteKeyOff = NULL;
    }
}

SynthSeqNote *AllocateNote(s32 endTime, u8 section) {
    SynthSeqNote *n = seqNoteFree;
    SynthSeqNote *cur;
    SynthSeqNote *prev;

    if (n != NULL) {
        if ((seqNoteFree = n->next) != NULL) {
            seqNoteFree->prev = NULL;
        }
        n->endTime = endTime;
        n->section = section;
        n->timeIndex = seqCurrent->section[section].timeIndex;
        prev = NULL;
        for (cur = seqCurrent->noteUsed[n->timeIndex]; cur != NULL; prev = cur, cur = cur->next) {
            if (cur->endTime > n->endTime) {
                n->next = cur;
                n->prev = prev;
                if (prev != NULL) {
                    prev->next = n;
                } else {
                    seqCurrent->noteUsed[n->timeIndex] = n;
                }
                cur->prev = n;
                return n;
            }
        }
        n->prev = prev;
        if (prev != NULL) {
            prev->next = n;
        } else {
            seqCurrent->noteUsed[n->timeIndex] = n;
        }
        n->next = NULL;
    }
    return n;
}

s32 HandleNotes(void) {
    SynthSeqNote *n;
    u32 i;
    s32 r;
    for (i = 0; i < 2; i++) {
        n = seqCurrent->noteUsed[i];
        if (n == NULL) {
            continue;
        }
        while (n->endTime <= seqCurrent->section[n->section].time[i].high) {
            synthSendKeyOff(n->id);
            if ((seqCurrent->noteUsed[i] = n->next) != NULL) {
                seqCurrent->noteUsed[i]->prev = NULL;
            }
            if ((n->next = seqCurrent->noteKeyOff) != NULL) {
                seqCurrent->noteKeyOff->prev = n;
            }
            seqCurrent->noteKeyOff = n;
            n = seqCurrent->noteUsed[i];
            if (n == NULL) {
                break;
            }
        }
    }
    r = 1;
    if (seqCurrent->noteUsed[0] == NULL && seqCurrent->noteUsed[1] == NULL) {
        r = 0;
    }
    return r;
}

void KeyOffNotes(void) {
    SynthSeqNote *n;
    SynthSeqNote *next;
    u32 i;

    for (i = 0; i < 2; i++) {
        for (n = seqCurrent->noteUsed[i]; n != NULL; n = next) {
            next = n->next;
            synthSendKeyOff(n->id);
            if ((seqCurrent->noteUsed[i] = n->next) != NULL) {
                seqCurrent->noteUsed[i]->prev = NULL;
            }
            if ((n->next = seqCurrent->noteKeyOff) != NULL) {
                seqCurrent->noteKeyOff->prev = n;
            }
            seqCurrent->noteKeyOff = n;
        }
    }
}

void seqFreeKeyOffNote(SynthSeqNote *note) {
    if (note->next != NULL) {
        note->next->prev = note->prev;
    }
    if (note->prev != NULL) {
        note->prev->next = note->next;
    } else {
        seqCurrent->noteKeyOff = note->next;
    }
    if ((note->next = seqNoteFree) != NULL) {
        seqNoteFree->prev = note;
    }
    note->prev = NULL;
    seqNoteFree = note;
}

#pragma push
#pragma opt_common_subs on
u32 GetPublicId(u32 seqId) {
    u32 pub_id;
    SynthSeqInstance *si;

    do {
        pub_id = seqPublicId++;
        seqPublicId &= ~0x80000000;

        for (si = seqActiveList; si != NULL; si = si->next) {
            if (si->publicId == pub_id) {
                pub_id = 0xFFFFFFFF;
                break;
            }
        }
        for (si = seqPausedList; si != NULL; si = si->next) {
            if (si->publicId == pub_id) {
                pub_id = 0xFFFFFFFF;
                break;
            }
        }
    } while (pub_id == 0xFFFFFFFF);

    seqInstance[seqId].publicId = pub_id;
    return pub_id;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
u32 seqGetPrivateId(u32 seqId) {
    SynthSeqInstance *si;
    for (si = seqActiveList; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = seqPausedList; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void DoPrgChange(SynthSeqInstance *seq, u8 prg, u8 midi) {
    seqMIDIPriority[seqCurrentId][midi] = 0xFFFF;
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

static inline void BuildTransTab(u8 *tab, SynthSeqPage *page) {
    u8 i;

    for (i = 0; i < 128; ++i) {
        tab[i] = 0xff;
    }

    for (i = 0; page->index != 0xFF; ++i, page++) {
        tab[page->index] = i;
    }
}

u32 seqStartPlay(SynthSeqPage *norm, SynthSeqPage *drum, SynthMidiSetup *midiSetup, u32 *song,
                 SynthPlayPara *para, u8 studio, u16 sgid) {
    SynthSeqArr *arr;
    u32 *tracktab;
    s32 i;
    SynthSeqInstance *nseq;
    SynthSeqInstance *oldCSeq;
    u32 seqId;
    u32 bpm;

    if ((nseq = seqFreeList) == NULL) {
        return 0xFFFFFFFF;
    }
    if ((seqFreeList = nseq->next) != NULL) {
        seqFreeList->prev = NULL;
    }
    if ((nseq->next = seqActiveList) != NULL) {
        seqActiveList->prev = nseq;
    }

    nseq->prev = NULL;
    seqActiveList = nseq;
    nseq->state = 1;
    for (i = 0; i < 16; ++i) {
        nseq->section[i].globalEventRoot = NULL;
    }

    seqId = nseq->index;
    nseq->syncActive = 0;
    nseq->normtab = norm;
    nseq->drumtab = drum;
    nseq->arrbase = (SynthSeqArr *)song;
    nseq->groupID = sgid;
    BuildTransTab(nseq->normTrans, nseq->normtab);
    BuildTransTab(nseq->drumTrans, nseq->drumtab);
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

    arr = (SynthSeqArr *)song;
    if (arr->info & 0x80000000) {
        nseq->trackSectionTab = (u8 *)ARR_PTR(arr, arr->tsTab);
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
            nseq->section[i].mTrack.base = (SynthSeqMasterTrackEntry *)ARR_PTR(arr, arr->mTrack);
            nseq->section[i].mTrack.addr = nseq->section[i].mTrack.base;
        } else {
            nseq->section[i].mTrack.base = NULL;
        }

        nseq->section[i].loopDisable = 0;
        nseq->section[i].loopCnt = 0;
    }

    tracktab = (u32 *)ARR_PTR(arr, arr->tTab);
    for (i = 0; i < 64; ++i) {
        synthTrackVolume[i] = 0x7F;
        nseq->pattern[i].addr = NULL;
        if (tracktab[i] != 0) {
            nseq->track[i].addr = nseq->track[i].base = (SynthSeqTrackEntry *)ARR_PTR(arr, tracktab[i]);
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
            DoPrgChange(nseq, midiSetup->channel[i].program, i);
            inpSetMidiCtrl(7, i, seqId, midiSetup->channel[i].volume);
            inpSetMidiCtrl(10, i, seqId, midiSetup->channel[i].panning);
            inpSetMidiCtrl(0x5B, i, seqId, midiSetup->channel[i].reverb);
            inpSetMidiCtrl(0x5D, i, seqId, midiSetup->channel[i].chorus);
        }
    }
    for (i = 0; i < 16; ++i) {
        seqMIDIPriority[seqId][i] = 0xffff;
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
        StartPause(nseq);
    }

    oldCSeq = seqCurrent;
    seqCurrent = nseq;
    InitTrackEvents();
    seqCurrent = oldCSeq;
    seqId = GetPublicId(seqId);
    return seqId;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
void HandleMasterTrack(u8 secIndex) {
    SynthSeqSection *section;
    section = &seqCurrent->section[secIndex];
    if (section->mTrack.base != NULL) {
        while (section->mTrack.addr->time != -1) {
            if (section->mTrack.addr->time > section->time[section->timeIndex].high) {
                break;
            }
            if ((seqCurrent->arrbase->info & 0x40000000) != 0) {
                synthSetBpm((section->bpm = section->mTrack.addr->bpm) >> 10, seqCurrentId, secIndex);
            } else {
                synthSetBpm(section->mTrack.addr->bpm, seqCurrentId, secIndex);
                section->bpm = section->mTrack.addr->bpm << 10;
            }
            ++section->mTrack.addr;
        }
    }
}
#pragma pop

void StartPause(SynthSeqInstance *si) {
    if (si->prev != NULL) {
        si->prev->next = si->next;
    } else {
        seqActiveList = si->next;
    }
    if (si->next != NULL) {
        si->next->prev = si->prev;
    }
    if ((si->next = seqPausedList) != NULL) {
        seqPausedList->prev = si;
    }
    si->prev = NULL;
    seqPausedList = si;
    si->state = 2;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline u32 seqGetPrivateIdInline(u32 seqId) {
    SynthSeqInstance *si;
    for (si = seqActiveList; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    for (si = seqPausedList; si != NULL; si = si->next) {
        if (si->publicId == (seqId & ~0x80000000)) {
            return si->index | (seqId & 0x80000000);
        }
    }
    return 0xFFFFFFFF;
}

static inline void StartPauseInline(SynthSeqInstance *si) {
    if (si->prev != NULL) {
        si->prev->next = si->next;
    } else {
        seqActiveList = si->next;
    }
    if (si->next != NULL) {
        si->next->prev = si->prev;
    }
    if ((si->next = seqPausedList) != NULL) {
        seqPausedList->prev = si;
    }
    si->prev = NULL;
    seqPausedList = si;
    si->state = 2;
}

static inline void KillNotes(SynthSeqInstance *seq) {
    SynthSeqNote *n;
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
    SynthSeqInstance *si;
    seqId = seqGetPrivateIdInline(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }
    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance[seqId];
        if (si->state == 1) {
            StartPauseInline(si);
            KillNotes(si);
            ResetNotes(si);
        }
    } else {
        si = &seqInstance[seqId & ~0x80000000];
        if (si->state != 0) {
            si->syncCrossInfo.flags |= 8;
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
void seqStop(s32 seqId) {
    SynthSeqInstance *si;

    if ((seqId = seqGetPrivateIdInline(seqId)) == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance[seqId];
        switch (si->state) {
        case 1:
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                seqActiveList = si->next;
            }
            KillNotes(&seqInstance[seqId]);
            ResetNotes(&seqInstance[seqId]);
            break;
        case 2:
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                seqPausedList = si->next;
            }
            break;
        }

        if (si->next != NULL) {
            si->next->prev = si->prev;
        }
        si->state = 0;
        if (seqFreeList != NULL) {
            seqFreeList->prev = si;
        }
        si->next = seqFreeList;
        si->prev = NULL;
        seqFreeList = si;
    } else {
        si = &seqInstance[seqId & ~0x80000000];
        if (si->state != 0) {
            si->syncSeqIdPtr = NULL;
        }
    }
}
#pragma pop

void seqKillInstancesByGroupID(u16 sgid) {
    SynthSeqInstance *si;
    for (si = seqActiveList; si != NULL; si = si->next) {
        if (si->groupID == sgid) {
            seqStop(si->publicId);
        }
    }
    for (si = seqPausedList; si != NULL; si = si->next) {
        if (si->groupID == sgid) {
            seqStop(si->publicId);
        }
    }
}

void seqSpeed(u32 id, s16 v) {
    SynthSeqBss *bss = (SynthSeqBss *)seqNote;
    SynthSeqInstance *n;
    u32 key = id & 0x7FFFFFFF;
    s32 h;

    for (n = seqActiveList; n != NULL; n = n->next) {
        if (n->publicId == key) {
            h = (n->index & 0x7FFFFFFF) | (id & 0x80000000);
            goto found;
        }
    }
    for (n = seqPausedList; n != NULL; n = n->next) {
        if (n->publicId == key) {
            h = (n->index & 0x7FFFFFFF) | (id & 0x80000000);
            goto found;
        }
    }
    h = -1;
found:
    if (!(h & 0x80000000)) {
        bss->seqInstance[h].section[0].speed = v;
        bss->seqInstance[h].section[1].speed = v;
        bss->seqInstance[h].section[2].speed = v;
        bss->seqInstance[h].section[3].speed = v;
        bss->seqInstance[h].section[4].speed = v;
        bss->seqInstance[h].section[5].speed = v;
        bss->seqInstance[h].section[6].speed = v;
        bss->seqInstance[h].section[7].speed = v;
        bss->seqInstance[h].section[8].speed = v;
        bss->seqInstance[h].section[9].speed = v;
        bss->seqInstance[h].section[10].speed = v;
        bss->seqInstance[h].section[11].speed = v;
        bss->seqInstance[h].section[12].speed = v;
        bss->seqInstance[h].section[13].speed = v;
        bss->seqInstance[h].section[14].speed = v;
        bss->seqInstance[h].section[15].speed = v;
    } else {
        bss->seqInstance[h & 0x7FFFFFFF].syncCrossInfo.flags |= 0x20;
        bss->seqInstance[h & 0x7FFFFFFF].syncCrossInfo.speed2 = v;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
void seqContinue(s32 seqId) {
    SynthSeqInstance *si;

    seqId = seqGetPrivateIdInline(seqId);

    if ((seqId & 0x80000000) == 0) {
        si = &seqInstance[seqId];

        if (si->state == 2) {
            if (si->prev != NULL) {
                si->prev->next = si->next;
            } else {
                seqPausedList = si->next;
            }

            if (si->next != NULL) {
                si->next->prev = si->prev;
            }

            if ((si->next = seqActiveList) != NULL) {
                seqActiveList->prev = si;
            }

            si->prev = NULL;
            seqActiveList = si;
            si->state = 1;
        }
    } else {
        seqInstance[seqId & ~0x80000000].syncCrossInfo.flags &= ~8;
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
void seqMute(s32 seqId, s32 mask1, s32 mask2) {
    SynthSeqBss *bss = (SynthSeqBss *)seqNote;
    seqId = seqGetPrivateIdInline(seqId);
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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
void seqVolume(u8 volume, u16 time, u32 seqId, u8 mode) {
    u32 i;
    u32 pub_id;

    pub_id = seqId;
    seqId = seqGetPrivateIdInline(seqId);
    if (seqId == 0xFFFFFFFF) {
        return;
    }

    if ((seqId & 0x80000000) == 0) {
        synthVolume(volume, time, seqInstance[seqId].defVGroup, mode, pub_id);
        for (i = 0; i < 64; ++i) {
            if (seqInstance[seqId].trackVolGroup[i] != seqInstance[seqId].defVGroup) {
                synthVolume(volume, time, seqInstance[seqId].trackVolGroup[i], 0, 0xFFFFFFFF);
            }
        }
    } else {
        seqId &= ~0x80000000;
        switch (mode & 0xF) {
        case 0:
            seqInstance[seqId].syncCrossInfo.vol2 = volume;
            break;
        case 1:
            seqInstance[seqId].syncSeqIdPtr = NULL;
            break;
        case 2:
            seqInstance[seqId].syncCrossInfo.flags |= 8;
            seqInstance[seqId].syncCrossInfo.vol2 = volume;
            break;
        case 3:
            seqInstance[seqId].syncCrossInfo.flags |= 0x80;
            seqInstance[seqId].syncCrossInfo.vol2 = volume;
            break;
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline void seqSpeedCrossfade(SynthSeqBss *bss, u32 seqId, u16 speed) {
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

static inline void seqMuteCrossfade(SynthSeqBss *bss, u32 seqId, u32 mask1, u32 mask2) {
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

void seqCrossFade(SynthCrossfade *ci, u32 *new_seqId, u8 irq_call) {
    SynthPlayPara pp;
    u32 seqId;
    u16 time;
    SynthSeqBss *bss = (SynthSeqBss *)seqNote;

    seqId = seqGetPrivateIdInline(ci->seqId1);

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
        if (seqGetPrivateIdInline(ci->seqId2) != 0xFFFFFFFF) {
            if (irq_call) {
                seqContinue(ci->seqId2);
                seqVolume(ci->vol2, ci->time2, ci->seqId2, 0);
                if ((ci->flags & 0x10) != 0) {
                    seqMuteCrossfade(bss, ci->seqId2, ci->trackMute2[0], ci->trackMute2[1]);
                }
                if ((ci->flags & 0x20) != 0) {
                    seqSpeedCrossfade(bss, ci->seqId2, ci->speed2);
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
                seqMuteCrossfade(bss, *new_seqId, 0, 0);
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
SynthSeqEvent *GenerateNextTrackEvent(u8 trackId) {
    SynthSeqTrack *track;
    SynthSeqPatternState *pattern;
    SynthSeqEvent *ev;
    u32 patternTime;
    u32 pitchTime;
    u32 modTime;

    track = &seqCurrent->track[trackId];
    pattern = &seqCurrent->pattern[trackId];

    if (track->addr != NULL) {
        ev = &seqCurrent->event[trackId];
        ev->trackId = trackId;
        ev->info.pattern.base = pattern;

        if (pattern->addr == NULL) {
        null_pattern_addr:
            if (track->addr->pattern == 0xffff) {
                track->addr = NULL;
                return NULL;
            }

            if (track->addr->pattern == 0xfffe) {
                if (seqCurrent->trackSectionTab == NULL) {
                    if (seqCurrent->section[0].loopDisable) {
                        track->addr = NULL;
                        return NULL;
                    }
                } else if (seqCurrent->section[seqCurrent->trackSectionTab[trackId]].loopDisable) {
                    track->addr = NULL;
                    return NULL;
                }

                ev->type = 3;
                ev->time = track->addr->time;
                track->addr = &track->base[track->addr->data.jumpTarget];
                return ev;
            }

            ev->type = 4;
            ev->time = track->addr->time;
            ev->info.trackAddr = track->addr;
            ++track->addr;
            return ev;
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

        ev->info.trackAddr = (SynthSeqTrackEntry *)pattern->addr;
        pattern->lTime = patternTime;

        if ((pattern->addr->key & 0x80) != 0) {
            pattern->addr = (SynthSeqNoteData *)((SynthSeqCtrlData *)pattern->addr + 1);
            goto use_pattern_time;
        }
        if ((pattern->addr->key | pattern->addr->velocity) == 0) {
            pattern->addr = (SynthSeqNoteData *)((SynthSeqCtrlData *)pattern->addr + 1);
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
        return ev;
    }

    return NULL;
}
#pragma pop

void InsertGlobalEvent(SynthSeqSection *section, SynthSeqEvent *ev) {
    SynthSeqEvent *p = section->globalEventRoot;
    SynthSeqEvent *q = NULL;
    while (p != NULL) {
        if (p->time > ev->time) {
            ev->next = p;
            ev->prev = q;
            if (q != NULL) {
                q->next = ev;
            } else {
                section->globalEventRoot = ev;
            }
            p->prev = ev;
            return;
        }
        q = p;
        p = p->next;
    }
    ev->prev = q;
    if (q != NULL) {
        q->next = ev;
    } else {
        section->globalEventRoot = ev;
    }
    ev->next = NULL;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void InitStream(SynthSeqStream *stream, u32 streamDataOffset) {
    u16 delta;
    if (streamDataOffset != 0) {
        if ((stream->nextAddr = GetStreamValue((u8 *)ARR_PTR(seqCurrent->arrbase, streamDataOffset), &delta,
                                               &stream->nextDelta)) != NULL) {
            stream->nextTime = delta;
        } else {
            stream->nextTime = 0x7fffffff;
        }
    } else {
        stream->nextTime = 0x7fffffff;
    }
}

static inline u16 HandleStream(SynthSeqStream *stream) {
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

static inline void DoPrgChangeBss(SynthSeqBss *bss, SynthSeqInstance *seq, u8 prg, u8 midi) {
    bss->seqMIDIPriority[seqCurrentId][midi] = 0xFFFF;
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

static inline void FreeNote(SynthSeqNote *n) {
    if (n->next != NULL) {
        n->next->prev = n->prev;
    }
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        seqCurrent->noteUsed[n->timeIndex] = n->next;
    }
    if ((n->next = seqNoteFree) != NULL) {
        seqNoteFree->prev = n;
    }
    n->prev = NULL;
    seqNoteFree = n;
}

SynthSeqEvent *HandleEvent(SynthSeqEvent *event, u8 secIndex, u32 *loopFlag) {
    SynthSeqBss *bss = (SynthSeqBss *)seqNote;
    SynthSeqPatternState *pa;
    SynthSeqNoteData *pe;
    s32 velocity;
    s32 key;
    u8 midi;
    u16 macId;
    SynthSeqNote *note;
    SynthSeqTrackEntry *tEntry;
    SynthSeqPatternState *pattern;
    u32 *pTab;
    SynthSeqPattern *pptr;

    switch (event->type) {
    case 4:
        tEntry = event->info.trackAddr;
        pattern = &seqCurrent->pattern[event->trackId];
        pTab = (u32 *)ARR_PTR(seqCurrent->arrbase, seqCurrent->arrbase->pTab);
        pptr = (SynthSeqPattern *)ARR_PTR(seqCurrent->arrbase, pTab[tEntry->pattern]);
        pattern->addr = (SynthSeqNoteData *)&pptr->noteData;
        pattern->lTime = 0;
        pattern->baseTime = tEntry->time;
        pattern->patternInfo = tEntry;
        InitStream(&pattern->pitchBend, pptr->pitchBend);
        pattern->pitchBend.value = 0x2000;
        InitStream(&pattern->modulation, pptr->modulation);
        pattern->modulation.value = 0;
        pattern->midi = ((u8 *)ARR_PTR(seqCurrent->arrbase, seqCurrent->arrbase->tmTab))[event->trackId];
        if (tEntry->prgChange != 0xff) {
            DoPrgChangeBss(bss, seqCurrent, tEntry->prgChange, pattern->midi);
        }
        if (tEntry->velocity != 0xff) {
            inpSetMidiCtrl(7, pattern->midi, seqCurrentId, tEntry->velocity);
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
                DoPrgChangeBss(bss, seqCurrent, key & 0x7f, midi);
                break;
            case 1:
                inpSetMidiCtrl(0x82, midi, seqCurrentId, key & 0x7f);
                break;
            default:
                if ((velocity & 0x80) != 0x80) {
                    break;
                }
                switch (velocity & 0x7f) {
                case 0x68:
                    if (seqCurrent->syncActive) {
                        seqCrossFade(&seqCurrent->syncCrossInfo, seqCurrent->syncSeqIdPtr, 1);
                        seqCurrent->syncActive = 0;
                    }
                    break;
                case 0x69:
                    bss->seqMIDIPriority[seqCurrentId][midi] = key & 0x7f;
                    break;
                case 0x6a:
                    bss->seqMIDIPriority[seqCurrentId][midi] = (key & 0x7f) + 0x80;
                    break;
                case 0x79:
                    inpResetMidiCtrl(midi, seqCurrentId, 0);
                    break;
                case 0x7b:
                    KeyOffNotes();
                    break;
                default:
                    inpSetMidiCtrl(velocity & 0x7f, midi, seqCurrentId, key & 0x7f);
                    break;
                }
            }
            break;
        }

        if ((seqCurrent->trackMute[event->trackId / 32] & (1 << (event->trackId & 0x1f))) != 0) {
            if ((macId = seqCurrent->prgState[midi].macId) != 0xffff) {
                key += pa->patternInfo->data.note.transpose;
                key = key > 0x7f ? 0x7f : key < 0 ? 0 : key;

                velocity += pa->patternInfo->data.note.velocityAdd;
                velocity = velocity > 0x7f ? 0x7f : velocity < 0 ? 0 : velocity;

                if ((note = AllocateNote(event->time + pe->length, secIndex)) != NULL) {
                    if ((note->id = synthStartSound(
                             macId, seqCurrent->prgState[midi].priority, seqCurrent->prgState[midi].maxVoices,
                             key, velocity, 64, midi, seqCurrentId, secIndex, 0, event->trackId,
                             seqCurrent->trackVolGroup[event->trackId], seqFadeOutActive ? -1 : 0,
                             seqCurrent->defStudio, synthITDDefault[seqCurrent->defStudio].music)) == 0xFFFFFFFF) {
                        FreeNote(note);
                    }
                }
            }
        }
        break;

    case 2:
        pa = event->info.pattern.base;
        inpSetMidiCtrl14(0x80, pa->midi, seqCurrentId, HandleStream(&pa->pitchBend));
        break;

    case 1:
        pa = event->info.pattern.base;
        inpSetMidiCtrl14(1, pa->midi, seqCurrentId, HandleStream(&pa->modulation));
        break;

    case 3:
        *loopFlag |= 1;
        return NULL;
    }

    return GenerateNextTrackEvent(event->trackId);
}
#pragma pop

void InitTrackEvents(void) {
    u32 i;
    SynthSeqEvent *n;

    if (seqCurrent->trackSectionTab == NULL) {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&seqCurrent->section[0], n);
            }
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&seqCurrent->section[seqCurrent->trackSectionTab[i]], n);
            }
        }
    }
}

void InitTrackEventsSection(u8 ch) {
    u32 i;
    SynthSeqEvent *n;

    if (seqCurrent->trackSectionTab == NULL) {
        for (i = 0; i < 0x40; i++) {
            n = GenerateNextTrackEvent(i);
            if (n != NULL) {
                InsertGlobalEvent(&seqCurrent->section[0], n);
            }
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            if (ch == seqCurrent->trackSectionTab[i]) {
                n = GenerateNextTrackEvent(i);
                if (n != NULL) {
                    InsertGlobalEvent(&seqCurrent->section[ch], n);
                }
            }
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline float seqFmodf(float x, float m) {
    float a = __fabsf(m);
    float b = __fabsf(x);
    if (a > b)
        return x;
    else {
        return x - m * (long long)(x / m);
    }
}

static inline void SetTickDelta(SynthSeqSection *section, u32 deltaTime) {
    float tickDelta = (float)section->bpm * (float)deltaTime * (1.f / (40960000.f));
    tickDelta *= section->speed * (1.f / 256.f);
    section->tickDelta[section->timeIndex].low = seqFmodf(tickDelta * 65536.f, 65536.f);
    section->tickDelta[section->timeIndex].high = floorf(tickDelta);
}

static inline void RewindMTrack(u8 secIndex, u32 deltaTime) {
    if (seqCurrent->section[secIndex].mTrack.base == NULL) {
        return;
    }
    seqCurrent->section[secIndex].mTrack.addr = seqCurrent->section[secIndex].mTrack.base;
    HandleMasterTrack(secIndex);
    SetTickDelta(seqCurrent->section + secIndex, deltaTime);
}

static inline u32 GetNextEventTime(SynthSeqSection *section) {
    if (section->globalEventRoot == NULL) {
        return 0;
    }
    return section->globalEventRoot->time;
}

static inline SynthSeqEvent *GetGlobalEvent(SynthSeqSection *section) {
    SynthSeqEvent *ev;
    ev = section->globalEventRoot;
    if (ev != NULL && ((section->globalEventRoot = ev->next) != NULL)) {
        section->globalEventRoot->prev = NULL;
    }
    return ev;
}

u32 HandleTrackEvents(u8 secIndex, u32 deltaTime) {
    SynthSeqEvent *ev;
    u32 loopFlag;
    SynthSeqSection *section;
    u8 unused[4];
    section = &seqCurrent->section[secIndex];
    loopFlag = 0;
    while (GetNextEventTime(section) <= section->time[section->timeIndex].high) {
        if ((ev = GetGlobalEvent(section)) == NULL) {
            if (!loopFlag) {
                return 0;
            }
            loopFlag = 0;
            section->timeIndex ^= 1;
            section->time[section->timeIndex].high = seqCurrent->arrbase->loopPoint[secIndex];
            section->time[section->timeIndex].low = section->time[section->timeIndex ^ 1].low;
            RewindMTrack(secIndex, deltaTime);
            section->loopCnt += 1;
            InitTrackEventsSection(secIndex);
            continue;
        }
        if ((ev = HandleEvent(ev, secIndex, &loopFlag)) != NULL) {
            InsertGlobalEvent(section, ev);
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on

static inline void HandleMasterTrackInline(u8 secIndex) {
    SynthSeqSection *section;

    section = &seqCurrent->section[secIndex];
    if (section->mTrack.base != NULL) {
        while (section->mTrack.addr->time != -1) {
            if (section->mTrack.addr->time > section->time[section->timeIndex].high) {
                break;
            }

            if ((seqCurrent->arrbase->info & 0x40000000) != 0) {
                synthSetBpm((section->bpm = section->mTrack.addr->bpm) >> 10, seqCurrentId, secIndex);
            } else {
                synthSetBpm(section->mTrack.addr->bpm, seqCurrentId, secIndex);
                section->bpm = section->mTrack.addr->bpm << 10;
            }

            ++section->mTrack.addr;
        }
    }
}

static inline void HandleKeyOffNotes(void) {
    SynthSeqNote *n;
    SynthSeqNote *nn;
    if (!seqCurrent->keyOffCheck) {
        n = seqCurrent->noteKeyOff;
        while (n != NULL) {
            nn = n->next;
            if (n->id != 0xFFFFFFFF && sndFXCheck(n->id) == 0xFFFFFFFF) {
                seqFreeKeyOffNote(n);
            }
            n = nn;
        }
    }

    seqCurrent->keyOffCheck = (seqCurrent->keyOffCheck + 1) % 5;
}

void seqHandle(u32 deltaTime) {
    u32 x;
    u32 i;
    u32 j;
    u32 eventsActive;
    u32 notesActive;
    SynthSeqInstance *si;
    SynthSeqInstance *nextSi;
    u8 unused[24];

    if (deltaTime == 0) {
        return;
    }

    si = seqActiveList;
    while (si != NULL) {
        nextSi = si->next;
        seqCurrent = si;
        seqCurrentId = si->index;
        seqFadeOutActive = synthIsFadeOutActive(si->defVGroup);

        if (seqCurrent->trackSectionTab == NULL) {
            HandleMasterTrackInline(0);
            SetTickDelta(seqCurrent->section, deltaTime);
            eventsActive = HandleTrackEvents(0, deltaTime);
            notesActive = HandleNotes();
            HandleKeyOffNotes();

            for (i = 0; i < 2; ++i) {
                x = seqCurrent->section[0].time[i].low + seqCurrent->section[0].tickDelta[i].low;
                seqCurrent->section[0].time[i].low = x & 0xffff;
                x >>= 16;
                seqCurrent->section[0].time[i].high += x + seqCurrent->section[0].tickDelta[i].high;
            }
        } else {
            eventsActive = 0;
            for (i = 0; i < 16; ++i) {
                HandleMasterTrackInline(i);
                SetTickDelta(&seqCurrent->section[i], deltaTime);
                eventsActive |= HandleTrackEvents(i, deltaTime);
            }
            notesActive = HandleNotes();
            HandleKeyOffNotes();

            for (i = 0; i < 16; ++i) {
                for (j = 0; j < 2; ++j) {
                    x = seqCurrent->section[i].time[j].low + seqCurrent->section[i].tickDelta[j].low;
                    seqCurrent->section[i].time[j].low = x & 0xffff;
                    x >>= 16;
                    seqCurrent->section[i].time[j].high += x + seqCurrent->section[i].tickDelta[j].high;
                }
            }
        }

        if (eventsActive == 0 && notesActive == 0) {
            if (si->prev != NULL) {
                si->prev->next = nextSi;
            } else {
                seqActiveList = nextSi;
            }
            if (nextSi != NULL) {
                nextSi->prev = si->prev;
            }
            ResetNotes(si);
            si->state = 0;
            si->prev = NULL;
            if ((si->next = seqFreeList) != NULL) {
                seqFreeList->prev = si;
            }
            seqFreeList = si;
        }
        si = nextSi;
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
static inline void ClearNotes(void) {
    SynthSeqNote *ln = NULL;
    s32 i;

    seqNoteFree = &seqNote[0];
    for (i = 0; i < 256; ++i) {
        seqNote[i].prev = ln;
        if (ln != NULL) {
            ln->next = &seqNote[i];
        }
        ln = &seqNote[i];
    }

    ln->next = NULL;
}

static inline void InitPublicIds(void) {
    seqPublicId = 0;
}

void seqInit(void) {
    u32 i;
    u32 j;

    seqActiveList = NULL;
    seqPausedList = NULL;
    for (i = 0; i < 8; ++i) {
        if (i == 0) {
            seqFreeList = &seqInstance[i];
            seqInstance[i].prev = NULL;
        } else {
            seqInstance[i - 1].next = &seqInstance[i];
            seqInstance[i].prev = &seqInstance[i - 1];
        }
        seqInstance[i].index = i;
        seqInstance[i].state = 0;
        for (j = 0; j < 0x10; ++j) {
            seqMIDIPriority[i][j] = 0xffff;
        }
    }
    seqInstance[i - 1].next = NULL;
    ClearNotes();
    InitPublicIds();
}
#pragma pop

SynthSeqInstance *seqCurrent;
SynthSeqNote *seqNoteFree;
u32 seqCurrentId;
u8 seqFadeOutActive;
u32 seqPublicId;
SynthSeqInstance *seqFreeList;
SynthSeqInstance *seqPausedList;
SynthSeqInstance *seqActiveList;

}
