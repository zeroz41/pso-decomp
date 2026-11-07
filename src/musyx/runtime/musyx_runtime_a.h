#ifndef MUSYX_RUNTIME_A_H
#define MUSYX_RUNTIME_A_H

#include "types.h"

struct RecoveredGlobal_803AA0C0_lbl_80556E88 {
    s32 value;
    u8 remaining[0xFC];
};

struct Ent_803B89B4 { u8 pad0[0xC]; Ent_803B89B4 *next; Ent_803B89B4 *prev; u8 pad14[0xD8]; u8 active; u8 padED[2]; u8 idx; };
typedef struct DSPhostDPop_SV { s32 l; s32 r; s32 s; s32 lA; s32 rA; s32 sA; s32 lB; s32 rB; s32 sB; } DSPhostDPop_SV;
struct Rec_803B59E4 {
    void *spb;
    DSPhostDPop_SV hostDPopSum;
    s32 *main[2];
    s32 *auxA[3];
    s32 *auxB[3];
    union { void *voiceRoot; Ent_803B89B4 *head; };
    void *alienVoiceRoot;
    union { u8 state; u8 f50; };
    u8 isMaster;
    u8 numInputs;
    u32 type;
    u8 in[0x54];
    void *auxAHandler;
    void *auxBHandler;
    u8 padB4[0xBC - 0xB4];
};

struct Node_803B2598 { Node_803B2598 *next; u32 pad; u32 key; };

struct Rec_803A9944 { u8 pad[0x2d]; u8 f2d; u8 pad2[2]; };

struct Program_803B1DA4 {
    u8 pad[0x44];
    Program_803B1DA4 *next;
    Program_803B1DA4 *prev;
    u8 pad4c[0x98 - 0x4C];
    u64 deadline;
};

struct Envelope_803B431C {
    u8 mode, phase, pad[2];
    u32 remaining, level, logLevel;
    s32 step;
    u32 attack, decay;
    u16 sustain, pad2;
    u32 release;
};

typedef struct Req_803AE60C { u8 pad0[4]; s16 f4; u8 pad1[2]; } Req_803AE60C;

typedef s32 (*RecoveredCallback_bdb219c29499)(s32, s32);

struct Node_803A3C24 { Node_803A3C24 *next; Node_803A3C24 *prev; s32 f8; s32 key; u8 ch; u8 grp; };
struct Chan_803A3934 { u8 grp; u8 pad[0x37]; };

struct Owner_803A3C24 { u8 pad[0xE64]; Node_803A3C24 *lists[2]; Node_803A3C24 *head; u8 padE70[0x1518 - 0xE70]; Chan_803A3934 chans[1]; };

struct Node_803A4964 { Node_803A4964 *next; Node_803A4964 *prev; s8 state; u8 idx; u8 padA[2]; u32 id; };

struct Node_803A5A04 { Node_803A5A04 *next; Node_803A5A04 *prev; u32 key; };

struct List_803A5A04 { u8 pad[0x1C]; Node_803A5A04 *head; u8 pad20[0x18]; };

struct Obj_803A6F18 { u8 pad0[0x122]; u8 b122; u8 b123; };

struct Obj_803A6F4C { u8 pad0[0x114]; u32 fh; u32 fl_; u8 pad11C[0x14]; u8 b130; u8 b131; u8 pad132[2]; s32 i134; s32 i138; s32 i13C; };

typedef struct Req_803AE6DC { u8 pad0[4]; s16 f4; u8 pad1[2]; } Req_803AE6DC;

typedef struct Res_803AE6DC { s32 f0; u16 pad4; u16 h6; } Res_803AE6DC;

struct Obj_803AFF38 { u8 pad0[0xAC]; s32 v[16]; };

struct Obj_803AFF9C { u8 pad0[0xAC]; s32 v[16]; };

struct Obj_803B0004 { u8 pad0[0xAC]; s32 v[16]; };

struct Obj_803B3AA8 { u8 pad0[0xF4]; u32 id; u8 pad1[0x29]; u8 b121; u8 b122; };

struct Obj_803B3B24 { u8 pad0[0xF4]; u32 id; u8 pad1[0x29]; u8 b121; u8 b122; };

struct Obj_803B3B80 { u8 pad0[0xF4]; u32 id; u8 pad1[0x29]; u8 b121; u8 b122; };

struct Node_803BA1B8 { Node_803BA1B8 *next; Node_803BA1B8 *prev; u8 pad8[8]; u32 f10; u8 pad14[0x28]; u32 id; };

struct Node_803A8D2C { Node_803A8D2C *next; u32 f4; u8 idx; u8 f9; };

struct Rec_803A8D2C { u8 pad[0x11C]; u8 busy; u8 pad11D[0x404 - 0x11D]; };

struct Se_803A9144 { u16 f0; u16 id; u8 b4; u8 b5; u8 b6; u8 b7; u8 b8; u8 b9; };

struct Rec_803A9454 {
    u8 pad0[0xEC];
    u32 next;
    u8 padF0[4];
    u32 id;
    u8 padF8[0x404 - 0xF8];
};

struct Rec_803A996C {
    u8 pad0[0xF4];
    u32 id;
    u8 padF8[0x11C - 0xF8];
    u8 busy;
    u8 pad11D[0x404 - 0x11D];
};

struct Lim_803A3A28 { s32 v; s32 pad; };

struct Ch_803A3A28 { Lim_803A3A28 lim[2]; u8 pad[0x28]; };

struct Tbl_803A3A28 { u8 pad[0x150C]; Ch_803A3A28 ch[1]; };

struct Slot_803A4EB8 { Node_803A4964 n; u8 pad10[0xEDA - 0x10]; u8 fEDA; u8 padEDB[0x1868 - 0xEDB]; };

struct Rec_803ADBF0 { u8 pad[9]; u8 f9; };

struct Ent_803ADBF0 { u16 id; u16 count; Rec_803ADBF0 *data; };

struct Tbl_803ADBF0 { u8 pad[0xA200]; Ent_803ADBF0 ents[1]; };

struct Ent_803ADD18 { u16 id; u16 f2; u32 f4; };

struct Obj_803AEC00 { u8 pad0[0x34]; s32 i34; s32 i38; u8 pad3C[0x6E]; u16 cnt; u8 padAC[0x48]; u32 iF4; u8 padF8[0x1C]; u32 fh; u32 fl; };

struct Op_803AEC00 { u32 w0; u32 w4; };

struct Obj_803AF0CC { u8 pad0[0x114]; u32 fh; u32 fl; u8 pad11C[0x24]; s8 b140; s8 b141; u8 pad142[2]; u32 i144; u32 i148; };

struct Op_803AF0CC { u32 w0; u32 w4; };

struct Node_803B2598;
struct Node_803B24A0;
struct Rec_803A8D2C;
struct Obj_803B3B80;
#define HEAD_803B25CC (*(Node_803B25CC **)&lbl_805D743C)
#define FREE_803B25CC (*(Node_803B25CC **)&lbl_805D7440)
#define VOICES_803B25CC (*(Prog_803B25CC **)&synthVoice)
#define UNLINK_803B25CC(n)                         \
    {                                              \
        Node_803B25CC *q = (n)->prev;              \
        if (q != NULL) {                           \
            q->next = (n)->next;                   \
        } else {                                   \
            HEAD_803B25CC = (n)->next;              \
        }                                          \
    }                                              \
    {                                              \
        Node_803B25CC *q = (n)->next;              \
        if (q != NULL) {                           \
            q->prev = (n)->prev;                   \
        }                                          \
    }
#define PUSH_803B25CC(n)                           \
    (n)->next = FREE_803B25CC;                      \
    if (FREE_803B25CC != NULL) {                    \
        FREE_803B25CC->prev = (n);                  \
    }                                              \
    (n)->prev = NULL;                              \
    FREE_803B25CC = (n);
struct Node_803B25CC {
    Node_803B25CC *next;
    Node_803B25CC *prev;
    u32 pad8;
    u32 owner;
};

struct Prog_803B25CC {
    u8 pad0[0xEC];
    u32 nextId;
    u32 prevId;
    u32 id;
    Node_803B25CC *node;
    Node_803B25CC *node2;
    u8 pad100[0x404 - 0x100];
};

struct Ent_803AA1E0 {
    u8 type;
    u8 pad1;
    union {
        u16 w;
        u8 b;
    } v;
};

struct Req_803AA1E0 {
    u8 count;
    u8 pad[3];
    Ent_803AA1E0 *ents;
};

struct Tbl_803AA1E0 { u8 b0; u8 b1; };

struct Node_803B2A30 { Node_803B2A30 *next; u32 pad4; u32 key; s32 val; };

struct Env_803B4360 {
    u8 mode; u8 phase; u8 pad2[2];
    u32 remaining; s32 level; s32 c; s32 step;
    u8 pad14[0x12]; u8 f26;
};

struct Src_803B8A14 { u8 vol; u8 volA; u8 volB; u8 srcStudio; };

struct Slot_803B8A14 { u8 studio; u8 pad; u16 vol; u16 volA; u16 volB; Src_803B8A14 *desc; };

struct Obj_803B8A14 { u8 pad[0x52]; u8 numInputs; u8 pad53[5]; Slot_803B8A14 in[7]; };

struct SynthInfo_803BAB54 {
    u8 pad[0x210];
    u8 voiceNum;
    u8 maxMusic;
    u8 maxSFX;
    u8 studioNum;
};

struct Vec_803B9438 { f32 x; f32 y; f32 z; };

struct A_803B9438 { A_803B9438 *next; u8 pad4[0xC]; Vec_803B9438 pos; };

struct B_803B9438 { B_803B9438 *next; u8 pad4[8]; Vec_803B9438 pos; f32 distance; u8 studio; };

struct SYNTH_VOICE_803B2438 {
    u8 pad0[0x34];
    void *addr;
    u8 pad38[0x4C - 0x38];
    u32 macState;
    u8 pad50[0xAA - 0x50];
    u16 loop;
    u8 padAC[0x404 - 0xAC];
};

typedef struct SeqInst_803A3D20 {
    struct SeqInst_803A3D20 *next;
    struct SeqInst_803A3D20 *prev;
    u8 state;
    u8 index;
    u16 groupID;
    u32 publicId;
} SeqInst_803A3D20;

typedef struct PAGE_803A487C { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A487C;

typedef struct ARR_803A487C { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A487C;

typedef struct TENTRY_803A487C { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A487C;

typedef struct TRACK_803A487C { TENTRY_803A487C *base; TENTRY_803A487C *addr; } TRACK_803A487C;

typedef struct NOTE_803A487C { struct NOTE_803A487C *next; struct NOTE_803A487C *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A487C;

typedef struct NOTE_DATA_803A487C { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A487C;

typedef struct PRG_STATE_803A487C { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A487C;

typedef struct SEQ_STREAM_803A487C { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A487C;

typedef struct CPAT_803A487C { u32 lTime; u32 baseTime; NOTE_DATA_803A487C *addr; TENTRY_803A487C *patternInfo; SEQ_STREAM_803A487C pitchBend; SEQ_STREAM_803A487C modulation; u8 midi; } CPAT_803A487C;

typedef struct SEQ_EVENT_803A487C {
    struct SEQ_EVENT_803A487C *next; struct SEQ_EVENT_803A487C *prev; u32 time;
    union { TENTRY_803A487C *trackAddr; struct { NOTE_DATA_803A487C *addr; CPAT_803A487C *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A487C;

typedef struct MTRACK_DATA_803A487C { volatile u32 time; u32 bpm; } MTRACK_DATA_803A487C;

typedef struct MTRACK_803A487C { MTRACK_DATA_803A487C *base; MTRACK_DATA_803A487C *addr; } MTRACK_803A487C;

typedef struct TICKS_803A487C { u32 low; s32 high; } TICKS_803A487C;

typedef struct SEQ_SECTION_803A487C {
    MTRACK_803A487C mTrack; u32 bpm; TICKS_803A487C tickDelta[2]; SEQ_EVENT_803A487C *globalEventRoot; TICKS_803A487C time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A487C;

typedef struct SND_CROSSFADE_803A487C {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A487C;

typedef struct SEQ_INSTANCE_803A487C {
    struct SEQ_INSTANCE_803A487C *next; struct SEQ_INSTANCE_803A487C *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A487C *normtab; u8 normTrans[128]; PAGE_803A487C *drumtab; u8 drumTrans[128];
    ARR_803A487C *arrbase; u32 trackMute[2]; TRACK_803A487C track[64]; u8 trackVolGroup[64]; CPAT_803A487C pattern[64];
    NOTE_803A487C *noteUsed[2]; NOTE_803A487C *noteKeyOff; PRG_STATE_803A487C prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A487C syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A487C event[64]; u8 *trackSectionTab; SEQ_SECTION_803A487C section[16];
} SEQ_INSTANCE_803A487C;

typedef struct PAGE_803A49C8 { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A49C8;

typedef struct ARR_803A49C8 { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A49C8;

typedef struct TENTRY_803A49C8 { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A49C8;

typedef struct TRACK_803A49C8 { TENTRY_803A49C8 *base; TENTRY_803A49C8 *addr; } TRACK_803A49C8;

typedef struct NOTE_803A49C8 { struct NOTE_803A49C8 *next; struct NOTE_803A49C8 *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A49C8;

typedef struct NOTE_DATA_803A49C8 { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A49C8;

typedef struct PRG_STATE_803A49C8 { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A49C8;

typedef struct SEQ_STREAM_803A49C8 { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A49C8;

typedef struct CPAT_803A49C8 { u32 lTime; u32 baseTime; NOTE_DATA_803A49C8 *addr; TENTRY_803A49C8 *patternInfo; SEQ_STREAM_803A49C8 pitchBend; SEQ_STREAM_803A49C8 modulation; u8 midi; } CPAT_803A49C8;

typedef struct SEQ_EVENT_803A49C8 {
    struct SEQ_EVENT_803A49C8 *next; struct SEQ_EVENT_803A49C8 *prev; u32 time;
    union { TENTRY_803A49C8 *trackAddr; struct { NOTE_DATA_803A49C8 *addr; CPAT_803A49C8 *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A49C8;

typedef struct MTRACK_DATA_803A49C8 { volatile u32 time; u32 bpm; } MTRACK_DATA_803A49C8;

typedef struct MTRACK_803A49C8 { MTRACK_DATA_803A49C8 *base; MTRACK_DATA_803A49C8 *addr; } MTRACK_803A49C8;

typedef struct TICKS_803A49C8 { u32 low; s32 high; } TICKS_803A49C8;

typedef struct SEQ_SECTION_803A49C8 {
    MTRACK_803A49C8 mTrack; u32 bpm; TICKS_803A49C8 tickDelta[2]; SEQ_EVENT_803A49C8 *globalEventRoot; TICKS_803A49C8 time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A49C8;

typedef struct SND_CROSSFADE_803A49C8 {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A49C8;

typedef struct SEQ_INSTANCE_803A49C8 {
    struct SEQ_INSTANCE_803A49C8 *next; struct SEQ_INSTANCE_803A49C8 *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A49C8 *normtab; u8 normTrans[128]; PAGE_803A49C8 *drumtab; u8 drumTrans[128];
    ARR_803A49C8 *arrbase; u32 trackMute[2]; TRACK_803A49C8 track[64]; u8 trackVolGroup[64]; CPAT_803A49C8 pattern[64];
    NOTE_803A49C8 *noteUsed[2]; NOTE_803A49C8 *noteKeyOff; PRG_STATE_803A49C8 prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A49C8 syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A49C8 event[64]; u8 *trackSectionTab; SEQ_SECTION_803A49C8 section[16];
} SEQ_INSTANCE_803A49C8;

typedef struct SeqInst_803A4D4C {
    struct SeqInst_803A4D4C *next;
    struct SeqInst_803A4D4C *prev;
    u8 state;
    u8 index;
    u16 groupID;
    u32 publicId;
} SeqInst_803A4D4C;

typedef struct PAGE_803A6364 { u16 macro; u8 prio; u8 maxVoices; u8 index; u8 reserved; } PAGE_803A6364;

typedef struct ARR_803A6364 { u32 tTab; u32 pTab; u32 tmTab; u32 mTrack; u32 info; u32 loopPoint[16]; u32 tsTab; } ARR_803A6364;

typedef struct TENTRY_803A6364 { u32 time; u8 prgChange; u8 velocity; u8 res[2]; u16 pattern; s8 transpose; s8 velocityAdd; } TENTRY_803A6364;

typedef struct TRACK_803A6364 { TENTRY_803A6364 *base; TENTRY_803A6364 *addr; } TRACK_803A6364;

typedef struct NOTE_803A6364 { struct NOTE_803A6364 *next; struct NOTE_803A6364 *prev; u32 id; s32 endTime; u8 section; u8 timeIndex; u8 reserved[2]; } NOTE_803A6364;

typedef struct NOTE_DATA_803A6364 { u16 time; u8 key; u8 velocity; u16 length; } NOTE_DATA_803A6364;

typedef struct PRG_STATE_803A6364 { u16 macId; u8 priority; u8 maxVoices; } PRG_STATE_803A6364;

typedef struct SEQ_STREAM_803A6364 { u8 *nextAddr; u16 value; s16 nextDelta; u32 nextTime; } SEQ_STREAM_803A6364;

typedef struct CPAT_803A6364 { u32 lTime; u32 baseTime; NOTE_DATA_803A6364 *addr; TENTRY_803A6364 *patternInfo; SEQ_STREAM_803A6364 pitchBend; SEQ_STREAM_803A6364 modulation; u8 midi; } CPAT_803A6364;

typedef struct SEQ_EVENT_803A6364 {
    struct SEQ_EVENT_803A6364 *next; struct SEQ_EVENT_803A6364 *prev; u32 time;
    union { TENTRY_803A6364 *trackAddr; struct { NOTE_DATA_803A6364 *addr; CPAT_803A6364 *base; } pattern; } info;
    u8 type; u8 trackId;
} SEQ_EVENT_803A6364;

typedef struct MTRACK_DATA_803A6364 { volatile u32 time; u32 bpm; } MTRACK_DATA_803A6364;

typedef struct MTRACK_803A6364 { MTRACK_DATA_803A6364 *base; MTRACK_DATA_803A6364 *addr; } MTRACK_803A6364;

typedef struct TICKS_803A6364 { u32 low; s32 high; } TICKS_803A6364;

typedef struct SEQ_SECTION_803A6364 {
    MTRACK_803A6364 mTrack; u32 bpm; TICKS_803A6364 tickDelta[2]; SEQ_EVENT_803A6364 *globalEventRoot; TICKS_803A6364 time[2];
    u8 timeIndex; u16 speed; u16 loopCnt; u8 loopDisable;
} SEQ_SECTION_803A6364;

typedef struct SND_CROSSFADE_803A6364 {
    u32 seqId1; u16 time1; u32 seqId2; u16 time2; void *arr2; u16 gid2; u16 sid2; u8 vol2; u8 studio2;
    u32 trackMute2[2]; u16 speed2; u8 flags;
} SND_CROSSFADE_803A6364;

typedef struct SEQ_INSTANCE_803A6364 {
    struct SEQ_INSTANCE_803A6364 *next; struct SEQ_INSTANCE_803A6364 *prev; u8 state; u8 index; u16 groupID; u32 publicId;
    PAGE_803A6364 *normtab; u8 normTrans[128]; PAGE_803A6364 *drumtab; u8 drumTrans[128];
    ARR_803A6364 *arrbase; u32 trackMute[2]; TRACK_803A6364 track[64]; u8 trackVolGroup[64]; CPAT_803A6364 pattern[64];
    NOTE_803A6364 *noteUsed[2]; NOTE_803A6364 *noteKeyOff; PRG_STATE_803A6364 prgState[16]; u8 defVGroup;
    SND_CROSSFADE_803A6364 syncCrossInfo; u32 *syncSeqIdPtr; u8 syncActive; u8 defStudio; u8 keyOffCheck;
    SEQ_EVENT_803A6364 event[64]; u8 *trackSectionTab; SEQ_SECTION_803A6364 section[16];
} SEQ_INSTANCE_803A6364;

struct Sub_803AA66C { u8 pad[8]; u32 vid; };

struct Rec_803AA66C {
    u8 pad0[0xF4];
    u32 id;
    Sub_803AA66C *vidList;
    u8 padFC[0x11F - 0xFC];
    u8 studio;
    u8 pad120[0x404 - 0x120];
};

struct Cfg_803AA66C { u8 pad[0x210]; u8 voiceNum; };

struct Ent_803ACD40 { s32 f0; u16 id; u16 ref; };

struct Tbl_803ACD40 { u8 pad[0x4600]; Ent_803ACD40 ents[1]; };

struct Ent_803ACEC4 { void *p; u16 key; u16 f6; u16 count; u16 padA; };

struct Tbl_803ACEC4 { u8 pad[0x4E00]; Ent_803ACEC4 ents[256]; };

struct Ent_803AD10C { u32 a; u16 key; u16 pad6; u16 count; u16 padA; };

struct Tbl_803AD10C { u8 pad[0x4E00]; Ent_803AD10C ents[256]; };

struct Ent_803AD4D0 { s32 f0; u16 id; u16 ref; };

struct Tbl_803AD4D0 { u8 pad[0x600]; Ent_803AD4D0 ents[1]; };

typedef struct MSTEP_SV { u32 para[2]; } MSTEP_SV;
typedef struct CALLSTACK_SV { MSTEP_SV *addr; MSTEP_SV *curAddr; } CALLSTACK_SV;
typedef struct VID_LIST_SV { struct VID_LIST_SV *next; struct VID_LIST_SV *prev; u32 vid; u32 root; } VID_LIST_SV;
typedef struct SYNTH_QUEUE_SV { struct SYNTH_QUEUE_SV *next; struct SYNTH_QUEUE_SV *prev; u8 voice; u8 jobTabIndex; } SYNTH_QUEUE_SV;
typedef struct SYNTH_JOBTAB_SV { SYNTH_QUEUE_SV *lowPrecision; SYNTH_QUEUE_SV *event; SYNTH_QUEUE_SV *zeroOffset; } SYNTH_JOBTAB_SV;
typedef struct SYNTH_LFO_SV { u32 time; u32 period; s16 value; s16 lastValue; } SYNTH_LFO_SV;
typedef struct SYNTHMasterFader_SV {
    f32 volume; f32 target; f32 start; f32 time; f32 deltaTime; f32 pauseVol; f32 pauseTarget; f32 pauseStart;
    f32 pauseTime; f32 pauseDeltaTime; u32 seqId; u8 seqMode; u8 type;
} SYNTHMasterFader_SV;
typedef struct CTRL_SOURCE_SV { u8 midiCtrl; u8 combine; s32 scale; } CTRL_SOURCE_SV;
typedef struct CTRL_DEST_SV { CTRL_SOURCE_SV source[4]; u16 oldValue; u8 numSource; } CTRL_DEST_SV;
typedef struct ADSR_VARS_SV {
    u8 mode; u8 state; u32 cnt; s32 currentVolume; s32 currentIndex; s32 currentDelta;
    union {
        struct { u32 aTime; u32 dTime; u16 sLevel; u32 rTime; u16 cutOff; u8 aMode; } dls;
        struct { u32 aTime; u32 dTime; u16 sLevel; u32 rTime; } linear;
    } data;
} ADSR_VARS_SV;
#pragma pack(push, 4)
typedef struct SYNTH_VOICE_SV {
    SYNTH_QUEUE_SV lowPrecisionJob; SYNTH_QUEUE_SV zeroOffsetJob; SYNTH_QUEUE_SV eventJob;
    u64 lastLowCallTime; u64 lastZeroCallTime; MSTEP_SV *addr; MSTEP_SV *curAddr;
    struct SYNTH_VOICE_SV *nextMacActive; struct SYNTH_VOICE_SV *prevMacActive;
    struct SYNTH_VOICE_SV *nextTimeQueueMacro; struct SYNTH_VOICE_SV *prevTimeQueueMacro;
    u32 macState; MSTEP_SV *trapEventAddr[3]; MSTEP_SV *trapEventCurAddr[3]; u8 trapEventAny;
    CALLSTACK_SV callStack[4]; u8 callStackEntryNum; u8 callStackIndex;
    u64 macStartTime; u64 wait; u64 waitTime; u8 timeUsedByInput; u16 loop; s32 local_vars[16];
    u32 child; u32 parent; u32 id; VID_LIST_SV *vidList; VID_LIST_SV *vidMasterList;
    u16 allocId; u16 macroId; u8 keyGroup; u32 lastVID; u8 prio; u16 ageSpeed; u32 age; u64 cFlags;
    u8 block; u8 fxFlag; u8 vGroup; u8 studio; u8 track; u8 midi; u8 midiSet; u8 section;
    u32 sInfo; u32 playFrq; u16 curNote; s8 curDetune; u8 orgNote; u8 lastNote; u8 portType;
    u16 portLastCtrlState; u32 portDuration; u32 portCurPitch; u32 portTime;
    u8 vibKeyRange; u8 vibCentRange; u32 vibPeriod; u32 vibCurTime; s32 vibCurOffset; s16 vibModAddScale;
    u32 volume; u32 orgVolume; float lastVolFaderScale; u32 lastPan; u32 lastSPan; float treCurScale;
    u16 treScale; u16 treModAddScale; u32 panning[2]; s32 panDelta[2]; u32 panTarget[2]; u32 panTime[2];
    u8 revVolScale; u8 revVolOffset; u8 volTable; u8 itdMode; s32 envDelta; u32 envTarget; u32 envCurrent;
    u32 sweepOff[2]; s32 sweepAdd[2]; s32 sweepCnt[2]; u8 sweepNum[2]; SYNTH_LFO_SV lfo[2];
    u8 lfoUsedByInput[2]; u8 pbLowerKeyRange; u8 pbUpperKeyRange; u16 pbLast;
    ADSR_VARS_SV pitchADSR; s16 pitchADSRRange; u16 curPitch;
    struct { u8 vol; u8 pan; u8 midi; u8 midiSet; u8 section; u8 track; u8 vGroup; u8 studio; u8 itdMode; } setup;
    u32 midiDirtyFlags;
    CTRL_DEST_SV inpVolume; CTRL_DEST_SV inpPanning; CTRL_DEST_SV inpSurroundPanning; CTRL_DEST_SV inpPitchBend;
    CTRL_DEST_SV inpDoppler; CTRL_DEST_SV inpModulation; CTRL_DEST_SV inpPedal; CTRL_DEST_SV inpPortamento;
    CTRL_DEST_SV inpPreAuxA; CTRL_DEST_SV inpReverb; CTRL_DEST_SV inpPreAuxB; CTRL_DEST_SV inpPostAuxB;
    CTRL_DEST_SV inpTremolo;
    u8 mesgNum; u8 mesgRead; u8 mesgWrite; s32 mesgQueue[4]; u16 curOutputVolume;
} SYNTH_VOICE_SV;
typedef struct synthITDInfo_SV { u8 music; u8 sfx; } synthITDInfo_SV;
#pragma pack(pop)
typedef struct LAYER_SV { u16 id; u8 keyLow; u8 keyHigh; s8 transpose; u8 volume; s16 prioOffset; u8 panning; u8 reserved[3]; } LAYER_SV;
typedef struct KEYMAP_SV { u16 id; s8 transpose; u8 panning; s16 prioOffset; u8 reserved[2]; } KEYMAP_SV;
typedef struct FX_TAB_SV { u16 id; u16 macro; u8 maxVoices; u8 priority; u8 volume; u8 panning; u8 key; u8 vGroup; } FX_TAB_SV;
typedef struct SynthInfo_SV { u32 mixFrq; u32 numSamples; struct { u32 frq; u8 stereo; u8 bits; s8 deviceName[256]; s8 versionText[256]; } pbInfo; u8 voiceNum; u8 maxMusic; u8 maxSFX; u8 studioNum; } SynthInfo_SV;
typedef void (*SND_AUX_CALLBACK_SV)(u8 reason, void *info, void *user);
typedef struct SynthBss_SV {
    u32 synthTicksPerSecond[9][16];
    SYNTH_JOBTAB_SV synthJobTable[32];
    SynthInfo_SV synthInfo;
    SYNTHMasterFader_SV synthMasterFader[32];
    u8 synthTrackVolume[64];
    void *synthAuxAUser[8];
    SND_AUX_CALLBACK_SV synthAuxACallback[8];
    void *synthAuxBUser[8];
    SND_AUX_CALLBACK_SV synthAuxBCallback[8];
    synthITDInfo_SV synthITDDefault[8];
    s32 synthGlobalVariable[16];
    CTRL_DEST_SV inpAuxB[8][4];
    CTRL_DEST_SV inpAuxA[8][4];
} SynthBss_SV;

#define CLAMP_SV(value, min, max) ((value) > (max) ? (max) : (value) < (min) ? (min) : (value))
#define CLAMP_INV_SV(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
#define SV_VOICES ((SYNTH_VOICE_SV *)synthVoice)
#define SV_VOICES_L (*(SYNTH_VOICE_SV **)&synthVoice)

extern "C" {
void seqStop(s32);
void seqMute(s32, s32, s32);
void HandleFaderTermination(u8 *arg0);
void inpFXCopyCtrl(u8, void *, void *);
void synthFXCloneMidiSetup(u8 *arg0, u8 *arg1);
void seqSpeed(u32, s16);
void hwEnableIrq(void);
void hwDisableIrq(void);
void sndSeqSpeed(s32 arg0, s16 arg1);
void hwEnableIrq(void);
void hwDisableIrq(void);
void sndSeqContinue(s32 arg0);
void seqMute(s32, s32, s32);
void hwEnableIrq(void);
void hwDisableIrq(void);
void sndSeqMute(s32 arg0, s32 arg1, s32 arg2);
void seqVolume(s8, s32, s32, s32);
void hwEnableIrq(void);
void hwDisableIrq(void);
void sndSeqVolume(s8 arg0, s32 arg1, s32 arg2, s32 arg3);
u16 seqGetMIDIPriority(u8 arg0, u8 arg1);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 sndFXKeyOff(s32 arg0);
void synthVolume(u8, u16, u8, s8, s32);
void hwEnableIrq(void);
void hwDisableIrq(void);
void sndVolume(u8 arg0, u16 arg1, u8 arg2);
void hwAddInput(u8);
void synthAddStudioInput(u8 arg0, void *in_desc);
void hwRemoveInput(u8);
void synthRemoveStudioInput(u8 arg0, void *in_desc);
extern s32 synthFlags;
void CheckOutputMode(s8 *arg0, s8 *arg1);
u32 adsrSetup(u8 *arg0);
s32 DCFlushRangeNoSync(void *, int);
s32 memset(void *, int, int);
extern s32 lbl_805D7480;
void salInitHRTFBuffer(void);
extern s32 (*salMessageCallback)(s32, s32);
s32 salSynthSendMessage(u8 *arg0, s32 arg1);
extern s8 lbl_805D7498;
extern s32 lbl_805D749C;
extern s32 lbl_805D74A0;
extern s32 lbl_805D74A4;
extern s32 lbl_805D74A8;
extern s32 lbl_805D74AC;
extern s8 lbl_805D74B0;
extern s8 lbl_805D74B1;
extern s8 lbl_805D74B2;
void s3dInit(s32 arg0);
#pragma pack(push, 4)
struct Obj_803A8C5C { u8 pad0[0x24]; s64 p24; s64 p2C; };
#pragma pack(pop)
extern s64 synthRealTime;
void synthKeyStateUpdate(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u32 synthMasterFaderActiveFlags;
s32 synthIsFadeOutActive(u8 arg0);
s32 seqPlaySong(u16, u16, s32, s32, u8, s32);
void sndSeqPlayEx(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern Rec_803B59E4 lbl_805663D8[];
void salDeactivateStudio(u8 i);
extern Node_803B2598 *lbl_805D743C;
Node_803B2598 *get_vidlist(u32 key);
extern u8 sndActive;
extern SYNTHMasterFader_SV synthMasterFader[];
void synthSetMusicVolumeType(u8 i, u8 v);
u32 sndFXCheck(u32 id);
extern Program_803B1DA4 *lbl_805D7420;
void TimeQueueAdd(Program_803B1DA4 *self);
s32 adsrRelease(struct Envelope_803B431C *e);
s32 curvecmp(u8 *arg0, u8 *arg1);
s32 *sndBSearch(Req_803AE60C *, void *, u16, s32, s32 (*)(u8 *, u8 *));
extern Req_803AE60C lbl_805D73F8;
extern u8 lbl_8055A470[];
extern u16 lbl_805D73D2;
extern s32 *lbl_805D7400;
s32 dataGetCurve(s16 arg0);
s32 curvecmp(u8 *arg0, u8 *arg1);
s32 *sndBSearch(Req_803AE60C *, void *, u16, s32, s32 (*)(u8 *, u8 *));
extern Req_803AE60C lbl_805D7404;
extern u8 lbl_8055E470[];
extern u16 lbl_805D73D4;
extern s32 *lbl_805D740C;
s32 dataGetKeymap(s16 arg0);
extern Owner_803A3C24 *lbl_805D7360;
extern Node_803A3C24 *lbl_805D7364;
void seqFreeKeyOffNote(Node_803A3C24 *arg0);
extern Node_803A4964 *lbl_805D7378;
extern Node_803A4964 *lbl_805D737C;
void StartPause(Node_803A4964 *arg0);
void InsertGlobalEvent(List_803A5A04 *arg0, Node_803A5A04 *arg1);
void synthSetBpm(s32 arg0, u8 arg1, u8 arg2);
void synthInitPortamento(Obj_803A6F4C *arg0);
s32 synthGetTicksPerSecond(Obj_803A6F18 *arg0);
void synthForceLowPrecisionUpdate(void *arg0);
void salDeactivateVoice(Ent_803B89B4 *arg0);
u32 sndStreamAllocLength(u32 arg0, u32 arg1);
s32 *sndBSearch(Req_803AE60C *, void *, u16, s32, s32 (*)(u8 *, u8 *));
s32 layercmp(u8 *arg0, u8 *arg1);
extern u16 lbl_805D73D6;
extern Res_803AE6DC *lbl_805D7410;
s32 dataGetLayer(s16 arg0, u16 *arg1);
u16 inpGetExCtrl(void *, s32);
extern s32 synthGlobalVariable[];
s32 varGet32(Obj_803AFF38 *arg0, u32 arg1, u32 arg2);
u16 inpGetExCtrl(void *, s32);
extern s32 synthGlobalVariable[];
s16 varGet(Obj_803AFF9C *arg0, u32 arg1, u32 arg2);
void inpSetExCtrl(void *, s32, s16);
extern s32 synthGlobalVariable[];
void varSet32(Obj_803B0004 *arg0, u32 arg1, u32 arg2, s32 arg3);
extern u8 lbl_80564CC8[][16];
extern u8 lbl_80564D48[];
s32 voiceIsLastStarted(Obj_803B3AA8 *arg0);
extern u8 lbl_80564CC8[][16];
extern u8 lbl_80564D48[];
void voiceSetLastStarted(Obj_803B3B24 *arg0);
extern u8 lbl_80564CC8[][16];
extern u8 lbl_80564D48[];
void voiceResetLastStarted(Obj_803B3B80 *arg0);
extern s32 lbl_805D749C;
void EmitterShutdown(Node_803BA1B8 *arg0);
extern Rec_803A8D2C *synthVoice;
void HandleJobQueue(Node_803A8D2C **list, void (*cb)(u8));
u32 synthStartSound(u16 id, u8 prio, u8 max, u8 key, u8 vol, u8 panning, u8 midi, u8 midiSet, u8 section, u16 step, u16 trackid, u8 vGroup, s16 prioOffset, u8 studio, u32 itd);
Se_803A9144 *dataGetFX(s16);
s32 synthFXStart(s16 arg0, u8 arg1, u8 arg2, s32 arg3, s32 arg4);
extern u8 sndActive;
extern Rec_803A8D2C *synthVoice;
void macSetExternalKeyoff(Rec_803A9454 *);
s32 synthSendKeyOff(int id);
extern Rec_803A8D2C *synthVoice;
s32 hwGetVirtualSampleID(u8);
void vsSampleEndNotify(s32);
void macSampleEndNotify(Rec_803A996C *);
s32 vsSampleStartNotify(u8);
s32 synthHWMessageHandler(s32 op, u32 idx);
s32 synthSendKeyOff(int id);
extern Owner_803A3C24 *lbl_805D7360;
s32 HandleNotes(void);
extern Node_803A4964 *lbl_805D7378;
extern Node_803A4964 *lbl_805D737C;
extern Slot_803A4EB8 lbl_8054AB48[];
void seqContinue(s32 arg0);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern u16 lbl_805D73DA;
s32 dataInsertFX(u16 arg0, Rec_803ADBF0 *arg1, u16 arg2);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern Ent_803ADD18 lbl_80564070[];
extern u16 lbl_805D73DA;
s32 dataRemoveFX(u16 id);
u16 sndRand(void);
u32 hwIsActive(s32 i);
void mcmdLoop(Obj_803AEC00 *o, Op_803AEC00 *op);
void sndConvertMs(void *);
void sndConvertTicks(void *, void *);
void mcmdVibrato(Obj_803AF0CC *o, Op_803AF0CC *op);
extern const f32 lbl_805E0B78;
s32 sndPitchUpOne(s32 current);
f32 powf(f32, f32, f32);
extern const f32 lbl_805E0B90;
extern const f32 lbl_805E0B94;
extern const f32 lbl_805E0B98;
u32 adsrConvertTimeCents(s32 arg0);
void voiceResetLastStarted(Obj_803B3B80 *arg0);
void vidRemoveVoiceReferences(Prog_803B25CC *p);
extern Tbl_803AA1E0 synthITDDefault[];
s32 synthFXStart(s16 arg0, u8 arg1, u8 arg2, s32 arg3, s32 arg4);
s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 sndFXStartParaInfo(s16 arg0, u8 arg1, u8 arg2, s32 arg3, Req_803AA1E0 *req);
extern Node_803B2598 *lbl_805D743C;
u32 vidGetInternalId(u32 arg0);
extern f32 lbl_804F6358[];
extern f32 lbl_804F6558[];
extern const f32 lbl_805E0B88;
u32 sndGetPitch(u8 note, u32 r);
extern u16 lbl_804F6758[];
s32 salChangeADSRState(void *a0);
s32 salChangeADSRState(void *a0);
extern u16 lbl_804F6758[];
u32 adsrHandle(void *arg0, void *arg1, void *arg2);
s32 salAddStudioInput(Obj_803B8A14 *stp, Src_803B8A14 *desc);
void seqInit(void);
void synthInit(u32 mixFrq, u32 numVoices);
void streamInit(void);
void dataInit(void *arg0, void *arg1);
void vsInit(void);
void dataInitStack(void);
void s3dInit(s32 arg0);
s32 hwInit(u32 *frq, u32 numVoices, u32 numStudios, u32 flags);
extern u8 sndActive;
extern u8 synthIdleWaitActive;
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
extern s32 lbl_805D74A0;
extern s32 lbl_805D74A4;
void UpdateRoomDistances(void);
extern Rec_803A8D2C *synthVoice;
extern Program_803B1DA4 *lbl_805D7420;
extern u64 lbl_805D7428;
void macInit(void);
extern Node_803A4964 *lbl_805D7378;
extern Node_803A4964 *lbl_805D737C;
u32 seqGetPrivateId(u32 seqId);
extern Owner_803A3C24 *lbl_805D7360;
extern u32 lbl_805D7368;
void synthSetBpm(s32 arg0, u8 arg1, u8 arg2);
void HandleMasterTrack(u8 secIndex);
extern Slot_803A4EB8 lbl_8054AB48[];
extern Node_803A4964 *lbl_805D7378;
extern Node_803A4964 *lbl_805D737C;
s32 voiceKillSound(u32 id);
void ResetNotes(Owner_803A3C24 *o);
void seqPause(s32 seqId);
extern Node_803A4964 *lbl_805D7378;
extern Node_803A4964 *lbl_805D737C;
void seqStop(s32);
void seqKillInstancesByGroupID(u16 sgid);
extern Owner_803A3C24 *lbl_805D7360;
void HandleMasterTrack(u8 secIndex);
void InitTrackEventsSection(u8 ch);
SEQ_EVENT_803A6364 *HandleEvent(SEQ_EVENT_803A6364 *event, u8 secIndex, u32 *loopFlag);
void InsertGlobalEvent(List_803A5A04 *arg0, Node_803A5A04 *arg1);
float floorf(float);
u32 HandleTrackEvents(u8 secIndex, u32 deltaTime);
s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 sndFXCtrl(u32 vid, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);
void hwEnableIrq(void);
void hwDisableIrq(void);
s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value);
u32 seqGetPrivateId(u32 seqId);
void hwSetAUXProcessingCallbacks(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern s32 synthAuxAUser[8];
extern void *synthAuxACallback[8];
extern s32 synthAuxBUser[8];
extern void *synthAuxBCallback[8];
extern u8 synthAuxBMIDISet[8];
extern u8 synthAuxBMIDI[8];
extern u8 synthAuxAMIDISet[8];
extern u8 synthAuxAMIDI[8];
void sndSetAuxProcessingCallbacks(u8 studio, void *auxA, s32 userA, u8 midiA, u32 seqIDA, void *auxB, s32 userB, u8 midiB, u32 seqIDB);
extern Rec_803A8D2C *synthVoice;
extern void *synthAuxACallback[8];
extern void *synthAuxBCallback[8];
extern u8 synthAuxBMIDI[8];
extern u8 synthAuxAMIDI[8];
s32 voiceKillSound(u32 id);
u32 hwIsActive(s32 i);
void hwOff(s32 arg0);
void hwDeactivateStudio(u8 i);
void hwEnableIrq(void);
void hwDisableIrq(void);
void synthDeactivateStudio(u8 studio);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern u16 lbl_805D73D4;
s32 dataRemoveKeymap(u16 arg0);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern u16 lbl_805D73D6;
s32 dataInsertLayer(u16 key, void *p, u16 f6);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern u16 lbl_805D73D6;
s32 dataRemoveLayer(u16 key);
void hwEnableIrq(void);
void hwDisableIrq(void);
extern u16 lbl_805D73D2;
s32 dataRemoveCurve(u16 arg0);
}

extern "C" {

struct Voice_803A4DDC { u8 pad[0x32]; s16 vol; u8 pad34[4]; };
struct Slot_803A4DDC {
    u8 pad0[0x22D8];
    s16 f0;
    u8 flags;
    u8 pad3[0x28E8 - 0x22DB];
    Voice_803A4DDC voices[16];
};
extern u8 lbl_80549748[];
struct Owner_803A61F8 {
    u8 pad0[0x14E4];
    u8 *map;
    List_803A5A04 chans[1];
};
Node_803A5A04 *GenerateNextTrackEvent(u8);

#pragma pack(push, 4)
struct Rec_803AA35C {
    u8 pad0[0x114];
    u64 flags;
    u8 pad11C[0x404 - 0x11C];
};
#pragma pack(pop)

extern SynthInfo_SV synthInfo;
void hwDisableHRTF(void);
void streamOutputModeChanged(void);
typedef void (*Cb_803AB0E4)(s32, s32, s32, s32, s32);
struct Rec_803AB0E4 { u8 pad[8]; u8 state; u8 pad9[3]; Cb_803AB0E4 cb; u8 pad10[0x38]; s32 f48; s32 f4c; u8 pad50[0x14]; };

void voiceUnblock(s32);
struct Ent_803ADB58 { u16 id; u16 ref; s32 f4; s32 f8; s32 fc; u8 pad10[0x10]; };
struct Tbl_803ADB58 { Ent_803ADB58 *list; s32 base; s32 f8; };

s32 hwRemoveSample(void *, s32);
extern u16 lbl_805D73D0;
struct Grp_803AE76C { u16 f0; u16 n; void *base; };
struct Key_803AE76C { s16 key; };
struct Grps_803AE76C { Grp_803AE76C g[0x85]; };
struct Blk_803AE76C { u8 pad0[0xA200]; Grps_803AE76C grps; u8 pad428[4]; Key_803AE76C k; };
extern u16 lbl_805D73DA;
struct Slot_803AE814 { u16 count; u16 start; };

void hwInitSampleMem(void *, void *);
extern Slot_803AE814 lbl_8055F870[];
extern u16 lbl_805D73D0;
extern u16 lbl_805D73D2;
extern u16 lbl_805D73D4;
extern u16 lbl_805D73D6;
extern u16 lbl_805D73D8;
extern u16 lbl_805D73DA;
#pragma pack(push, 4)
struct Rec_803B1AF4 {
    u8 pad0[0x34]; u32 f34; s32 f38; u8 pad3c[0x10]; s32 f4c; u8 pad50[4]; u32 f54; u8 pad58[8]; s32 f60;
    u8 pad64[4]; u8 f68; u8 pad69[0x114 - 0x69]; u64 flags;
};
#pragma pack(pop)
void macMakeActive(void *);
#pragma pack(push, 4)
struct Ch_803B1BA4 {
    u8 pad0[0x34]; u32 f34; s32 f38; u8 pad3c[0x14]; u32 f50; u8 pad54[8]; s32 f5c;
    u8 pad60[8]; u8 f68; u8 pad69[0x114 - 0x69]; u64 flags;
};
#pragma pack(pop)
struct Node_803B24A0 { Node_803B24A0 *next; Node_803B24A0 *prev; u32 f8; u32 fc; };

extern Node_803B24A0 lbl_805644C8[];
extern s32 lbl_805D7438;
extern Node_803B24A0 *lbl_805D7440;
struct Slot_803B312C { u8 prev; u8 next; u16 refs; };
struct Obj_803B312C { u8 pad0[0x34]; s32 f34; u8 pad38[0xBC]; s32 id; u8 padF8[0x14]; u8 grp; u8 pad10d[0x10]; u8 f11d; };

void macMakeInactive(Obj_803B312C *, s32);
void voiceRemovePriority(Obj_803B312C *);
extern Slot_803B312C lbl_80565388[];
extern u8 lbl_805D7446;
extern u8 lbl_805D7447;
extern u8 lbl_805D7448;
extern u8 lbl_805D7449;
struct Ent_803B5DB0 {
    u8 pad[0x1C];
    u32 key;
};
struct Slot_803B8ABC { u32 a; u32 b; u32 src; };
struct Obj_803B8ABC { u8 pad[0x52]; u8 count; u8 pad53[5]; Slot_803B8ABC slots[7]; };
struct Node_803BA228 { Node_803BA228 *next; Node_803BA228 *prev; u8 pad8[8]; u32 f10; u8 pad14[0x30]; u16 id; };
struct Ent_803BA228 { u16 id; u8 pad[8]; };
}

extern "C" {

struct Voice_803B1C98 {
    u8 pad0[0x34]; u32 i34; u32 i38; u8 pad3C[0x14]; u32 i50; u8 pad54[8]; u32 i5C;
    u8 pad60[8]; u8 b68; u8 pad69[0xAB]; u32 fh; u32 fl;
};
#pragma pack(push, 4)
struct Ch_803A897C {
    u8 pad0[0x34]; u32 f34; u8 pad38[0xA8 - 0x38]; u8 fA8; u8 padA9[0x114 - 0xA9];
    u64 flags; u8 pad11C[3]; u8 f11F; u8 pad120[0x1DC - 0x120]; u8 env[0x214 - 0x1DC]; s32 f214;
};
#pragma pack(pop)
struct Obj_803AFCA0 { u8 pad0[0x114]; u32 fh; u32 fl; u8 pad11C[5]; u8 b121; u8 b122; u8 pad123[0xF1]; u32 i214; };
struct Op_803AFCA0 { u32 w0; u32 w4; };
struct Obj_803AFDD4 { u8 pad0[0x114]; u32 fh; u32 fl; u8 pad11C[5]; u8 b121; u8 b122; u8 pad123[0xE]; u8 b131; u8 pad132[2]; u32 i134; };
struct Op_803AFDD4 { u32 w0; u32 w4; };
struct Desc_803B5398 { u8 pad0[4]; u16 id; u16 kind; u8 pad8[0x14]; s32 o1C; s32 o20; s32 o24; };
struct Ent_803B5398 { Desc_803B5398 *desc; s32 b; u8 *base; };
typedef void (*Cb_803B8B40)(s32, s32 *, s32, s32);
struct Voice_803B8B40 {
    u8 pad0[0x30]; s32 bufA[3]; s32 bufB[3]; u8 pad48[8];
    u8 b50; u8 pad51[3]; s32 i54; u8 pad58[0x54];
    Cb_803B8B40 cbA; Cb_803B8B40 cbB; s32 argA; s32 argB;
};
struct Row_803AE4D4 { u16 id; u16 ref; u32 src; u32 addr; u32 key; u32 fmt; u32 loopStart; u32 loopLen; u32 coef; };
struct Part_803AE4D4 { u32 key; u32 fmt; u32 loopStart; u32 loopLen; };
struct Reg_803AE4D4 { u32 rows; u32 unused; u16 count; u16 pad; };
struct Sample_803AE4D4 { u32 key; u32 addr; u32 coef; u32 offset; u32 count; u32 loopStart; u32 loopLen; u8 format; };
struct V_803B1F24 {
    u8 pad0[0x3C]; V_803B1F24 *vnext; V_803B1F24 *vprev; V_803B1F24 *next; V_803B1F24 *prev; s32 i4C;
    u8 pad50[0x48]; u64 deadline; u64 started; u8 padA8[0x6C]; u32 fh; u32 fl;
};
#pragma pack(push, 4)
struct Ch_803B202C {
    u8 pad0[0x3C]; V_803B1F24 *wnext; V_803B1F24 *wprev;
    Program_803B1DA4 *next; Program_803B1DA4 *prev; s32 state; u8 pad50[0x48];
    s64 f98; s64 fa0; u8 padA8[0x114 - 0xA8]; u64 flags;
};
#pragma pack(pop)
#pragma pack(push, 4)
struct Ch_803B1E48 {
    u8 pad0[0x44]; Program_803B1DA4 *next; Program_803B1DA4 *prev; u8 pad4c[0x4C];
    s64 f98; s64 fa0; u8 padA8[0x114 - 0xA8]; u64 flags;
};
#pragma pack(pop)
void macSetPedalState(Voice_803B1C98 *, u32);
u16 inpGetPedal(Ch_803A897C *);
void hwStart(s32, u8);
void hwKeyOff(s32);
void inpSetGlobalMIDIDirtyFlag(u8, u8, u32);
void inpAddCtrl(s32, u8, s32, u8, bool);
void inpSetMidiCtrl(s32, u8, u8, s32);
u16 inpGetMidiCtrl(s32, u8, u8);
extern Ent_803B5398 lbl_80565DD8[];
extern u8 lbl_805D74C4;
extern u8 lbl_805D74C6;
extern Row_803AE4D4 *lbl_805D73F0;
extern Part_803AE4D4 *lbl_805D73F4;
extern V_803B1F24 *lbl_805D741C;
extern u64 lbl_805D7428;
void streamCorrectLoops(void);
s32 maccmp(u8 *arg0, u8 *arg1);
s32 smpcmp(u16 *arg0, u16 *arg1);
s32 curvecmp(u8 *arg0, u8 *arg1);
s32 layercmp(u8 *arg0, u8 *arg1);
s32 fxcmp(u16 *arg0, u16 *arg1);
s32 vidMakeRoot(u8 *arg0);
void dataInitStack(void);

extern "C" {
extern SynthInfo_SV synthInfo;
}

extern "C" {
extern SynthInfo_SV synthInfo;
}

extern "C" {
extern SynthInfo_SV synthInfo;
extern V_803B1F24 *lbl_805D741C;
}

extern "C" {
extern SynthInfo_SV synthInfo;
}

typedef struct SeqInst_803A3C84 {
    struct SeqInst_803A3C84 *next;
    struct SeqInst_803A3C84 *prev;
    u8 pad8[4];
    u32 publicId;
    u8 pad10[0x1868 - 0x10];
} SeqInst_803A3C84;
extern u32 lbl_805D7370;
typedef struct SND_SEQVOLDEF_SEQ { u8 track; u8 volGroup; } SND_SEQVOLDEF_SEQ;
typedef struct SND_PLAYPARA_SEQ {
    u32 flags; u32 trackMute[2]; u16 speed;
    struct { u16 time; u8 target; } volume;
    u8 numSeqVolDef; SND_SEQVOLDEF_SEQ *seqVolDef; u8 numFaded; u8 *faded;
} SND_PLAYPARA_SEQ;
typedef struct MIDI_CHANNEL_SETUP_803A3D8C { u8 program; u8 volume; u8 panning; u8 reverb; u8 chorus; } MIDI_CHANNEL_SETUP_803A3D8C;
typedef struct MIDISETUP_803A3D8C { u16 songId; u16 reserved; MIDI_CHANNEL_SETUP_803A3D8C channel[16]; } MIDISETUP_803A3D8C;
extern SEQ_INSTANCE_803A49C8 *lbl_805D7374;
extern u8 synthTrackVolume[64];

struct Owner_803A3C24;

typedef struct SeqBss_803A4FC4 {
    NOTE_803A49C8 seqNote[256];
    SEQ_INSTANCE_803A49C8 seqInstance[8];
} SeqBss_803A4FC4;

typedef struct SeqBss_803A5A78 {
    NOTE_803A6364 seqNote[256];
    SEQ_INSTANCE_803A6364 seqInstance[8];
    u16 seqMIDIPriority[8][16];
} SeqBss_803A5A78;
typedef struct SEQ_PATTERN_803A5A78 { u32 headerLen; u32 pitchBend; u32 modulation; u32 noteData; } SEQ_PATTERN_803A5A78;
extern u8 lbl_805D736C;
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void inpResetMidiCtrl(u8, u8, u8);

void synthAddJob(SYNTH_VOICE_SV *svoice, s32 jobType, u32 deltaTime);
s16 sndSin(u16 angle);
u16 inpGetPitchBend(SYNTH_VOICE_SV *svoice);
u16 inpGetModulation(SYNTH_VOICE_SV *svoice);
u16 inpGetDoppler(SYNTH_VOICE_SV *svoice);
void hwSetPitch(u32 v, u16 speed);
u32 adsrHandleLowPrecision(void *arg0, void *arg1, void *arg2);

extern u8 synthJobTableIndex;

typedef char RecoveredGlobal_803AA0C0_lbl_80556E88_size[sizeof(RecoveredGlobal_803AA0C0_lbl_80556E88) == 0x100 ? 1 : -1];

void hwActivateStudio(u8 i, s32 a, s32 b);

typedef u32 (*StreamCb_803AB5A8)(void *buffer1, u32 len1, void *buffer2, u32 len2, u32 user);

typedef struct ADPCMInfo_803AB5A8 {
    u16 numCoef;
    u8 initialPS;
    u8 loopPS;
    s16 loopY0;
    s16 loopY1;
    s16 coefTab[8][2];
} ADPCMInfo_803AB5A8;

typedef struct Stream_803AB5A8 {
    u32 stid;
    u32 flags;
    u8 state;
    u8 type;
    StreamCb_803AB5A8 updateFunction;
    s16 *buffer;
    u32 size;
    u32 bytes;
    u32 last;
    ADPCMInfo_803AB5A8 adpcmInfo;
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
} Stream_803AB5A8;

typedef struct SynthInfo_803AB5A8 {
    u32 mixFrq;
    u32 numSamples;
    u8 pbInfo[0x208];
    u8 voiceNum;
    u8 maxMusic;
    u8 maxSFX;
    u8 studioNum;
} SynthInfo_803AB5A8;

void hwSetVolume(s32 idx, u32 p, u32 x, s32 a3, f32 a, f32 b, f32 c);
void hwEnableIrq(void);
void hwDisableIrq(void);

struct Hdr_803ADA80 { u32 info; u32 length; u32 loopOffset; u32 loopLength; };
struct SDir_803ADA80 { u16 id; u16 ref_cnt; u32 offset; void *addr; Hdr_803ADA80 header; u32 extraData; };
struct Tbl_803ADA80 { SDir_803ADA80 *data; void *base; u16 numSmp; u16 res; };

void hwSaveSample(Hdr_803ADA80 **arg0, void **arg1);

struct Obj_803AE8F8 {
    u8 pad0[0x90];
    u64 f90;
    u64 deadline;
    u64 fa0;
    u8 padA8[0xF4 - 0xA8];
    u32 iF4;
    u8 padF8[0x114 - 0xF8];
    u32 fh;
    u32 fl;
};
struct Op_803AE8F8 { u32 w0; u32 w4; };

u16 sndRand(void);
void sndConvertMs(void *);
void sndConvertTicks(void *, void *);
u32 hwIsActive(s32 i);
void TimeQueueAdd(Program_803B1DA4 *self);
void macMakeInactive(Obj_803B312C *, s32);
extern u64 lbl_805D7428;

#pragma pack(push, 4)
typedef struct MSTEP_803AED58 { u32 para[2]; } MSTEP_803AED58;
typedef struct VIDL_803AED58 { struct VIDL_803AED58 *next; struct VIDL_803AED58 *prev; u32 vid; u32 root; } VIDL_803AED58;
typedef struct LFO_803AED58 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AED58;
typedef struct CSRC_803AED58 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AED58;
typedef struct CDEST_803AED58 { CSRC_803AED58 source[4]; u16 oldValue; u8 numSource; } CDEST_803AED58;
typedef struct Voice_803AED58 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AED58 *addr;
  MSTEP_803AED58 *curAddr;
  struct Voice_803AED58 *nextMacActive;
  struct Voice_803AED58 *prevMacActive;
  struct Voice_803AED58 *nextTimeQueueMacro;
  struct Voice_803AED58 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AED58 *trapEventAddr[3];
  MSTEP_803AED58 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AED58 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AED58 *vidList;
  VIDL_803AED58 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AED58 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AED58 inpVolume;
  CDEST_803AED58 inpPanning;
  CDEST_803AED58 inpSurroundPanning;
  CDEST_803AED58 inpPitchBend;
  CDEST_803AED58 inpDoppler;
  CDEST_803AED58 inpModulation;
  CDEST_803AED58 inpPedal;
  CDEST_803AED58 inpPortamento;
  CDEST_803AED58 inpPreAuxA;
  CDEST_803AED58 inpReverb;
  CDEST_803AED58 inpPreAuxB;
  CDEST_803AED58 inpPostAuxB;
  CDEST_803AED58 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AED58;
#pragma pack(pop)

#pragma pack(push, 4)
typedef struct MSTEP_803AF3DC { u32 para[2]; } MSTEP_803AF3DC;
typedef struct VIDL_803AF3DC { struct VIDL_803AF3DC *next; struct VIDL_803AF3DC *prev; u32 vid; u32 root; } VIDL_803AF3DC;
typedef struct LFO_803AF3DC { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AF3DC;
typedef struct CSRC_803AF3DC { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AF3DC;
typedef struct CDEST_803AF3DC { CSRC_803AF3DC source[4]; u16 oldValue; u8 numSource; } CDEST_803AF3DC;
typedef struct Voice_803AF3DC {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AF3DC *addr;
  MSTEP_803AF3DC *curAddr;
  struct Voice_803AF3DC *nextMacActive;
  struct Voice_803AF3DC *prevMacActive;
  struct Voice_803AF3DC *nextTimeQueueMacro;
  struct Voice_803AF3DC *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AF3DC *trapEventAddr[3];
  MSTEP_803AF3DC *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AF3DC *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AF3DC *vidList;
  VIDL_803AF3DC *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AF3DC lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AF3DC inpVolume;
  CDEST_803AF3DC inpPanning;
  CDEST_803AF3DC inpSurroundPanning;
  CDEST_803AF3DC inpPitchBend;
  CDEST_803AF3DC inpDoppler;
  CDEST_803AF3DC inpModulation;
  CDEST_803AF3DC inpPedal;
  CDEST_803AF3DC inpPortamento;
  CDEST_803AF3DC inpPreAuxA;
  CDEST_803AF3DC inpReverb;
  CDEST_803AF3DC inpPreAuxB;
  CDEST_803AF3DC inpPostAuxB;
  CDEST_803AF3DC inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AF3DC;
#pragma pack(pop)

typedef struct ADSR_803AF3DC {
    union {
        struct { s32 atime; s32 dtime; u16 slevel; u16 rtime; s32 ascale; s32 dscale; } dls;
        struct { u16 atime; u16 dtime; u16 slevel; u16 rtime; } linear;
    } data;
} ADSR_803AF3DC;
s32 dataGetCurve(s16 arg0);
void hwSetADSR(u8, void *, s32);
extern f32 lbl_804F6CDC[];

#pragma pack(push, 4)
typedef struct MSTEP_803AF954 { u32 para[2]; } MSTEP_803AF954;
typedef struct VIDL_803AF954 { struct VIDL_803AF954 *next; struct VIDL_803AF954 *prev; u32 vid; u32 root; } VIDL_803AF954;
typedef struct LFO_803AF954 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AF954;
typedef struct CSRC_803AF954 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AF954;
typedef struct CDEST_803AF954 { CSRC_803AF954 source[4]; u16 oldValue; u8 numSource; } CDEST_803AF954;
typedef struct Voice_803AF954 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AF954 *addr;
  MSTEP_803AF954 *curAddr;
  struct Voice_803AF954 *nextMacActive;
  struct Voice_803AF954 *prevMacActive;
  struct Voice_803AF954 *nextTimeQueueMacro;
  struct Voice_803AF954 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AF954 *trapEventAddr[3];
  MSTEP_803AF954 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AF954 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AF954 *vidList;
  VIDL_803AF954 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AF954 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AF954 inpVolume;
  CDEST_803AF954 inpPanning;
  CDEST_803AF954 inpSurroundPanning;
  CDEST_803AF954 inpPitchBend;
  CDEST_803AF954 inpDoppler;
  CDEST_803AF954 inpModulation;
  CDEST_803AF954 inpPedal;
  CDEST_803AF954 inpPortamento;
  CDEST_803AF954 inpPreAuxA;
  CDEST_803AF954 inpReverb;
  CDEST_803AF954 inpPreAuxB;
  CDEST_803AF954 inpPostAuxB;
  CDEST_803AF954 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AF954;
#pragma pack(pop)

s32 dataGetCurve(s16 arg0);

#pragma pack(push, 4)
typedef struct MSTEP_803AF9D4 { u32 para[2]; } MSTEP_803AF9D4;
typedef struct VIDL_803AF9D4 { struct VIDL_803AF9D4 *next; struct VIDL_803AF9D4 *prev; u32 vid; u32 root; } VIDL_803AF9D4;
typedef struct LFO_803AF9D4 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AF9D4;
typedef struct CSRC_803AF9D4 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AF9D4;
typedef struct CDEST_803AF9D4 { CSRC_803AF9D4 source[4]; u16 oldValue; u8 numSource; } CDEST_803AF9D4;
typedef struct Voice_803AF9D4 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AF9D4 *addr;
  MSTEP_803AF9D4 *curAddr;
  struct Voice_803AF9D4 *nextMacActive;
  struct Voice_803AF9D4 *prevMacActive;
  struct Voice_803AF9D4 *nextTimeQueueMacro;
  struct Voice_803AF9D4 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AF9D4 *trapEventAddr[3];
  MSTEP_803AF9D4 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AF9D4 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AF9D4 *vidList;
  VIDL_803AF9D4 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AF9D4 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AF9D4 inpVolume;
  CDEST_803AF9D4 inpPanning;
  CDEST_803AF9D4 inpSurroundPanning;
  CDEST_803AF9D4 inpPitchBend;
  CDEST_803AF9D4 inpDoppler;
  CDEST_803AF9D4 inpModulation;
  CDEST_803AF9D4 inpPedal;
  CDEST_803AF9D4 inpPortamento;
  CDEST_803AF9D4 inpPreAuxA;
  CDEST_803AF9D4 inpReverb;
  CDEST_803AF9D4 inpPreAuxB;
  CDEST_803AF9D4 inpPostAuxB;
  CDEST_803AF9D4 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AF9D4;
#pragma pack(pop)

s32 dataGetCurve(s16 arg0);
void sndConvertMs(void *);
void sndConvertTicks(void *, void *);
u32 sndConvert2Ms(u32 arg0);

#pragma pack(push, 4)
typedef struct MSTEP_803AFB00 { u32 para[2]; } MSTEP_803AFB00;
typedef struct VIDL_803AFB00 { struct VIDL_803AFB00 *next; struct VIDL_803AFB00 *prev; u32 vid; u32 root; } VIDL_803AFB00;
typedef struct LFO_803AFB00 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803AFB00;
typedef struct CSRC_803AFB00 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803AFB00;
typedef struct CDEST_803AFB00 { CSRC_803AFB00 source[4]; u16 oldValue; u8 numSource; } CDEST_803AFB00;
typedef struct Voice_803AFB00 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803AFB00 *addr;
  MSTEP_803AFB00 *curAddr;
  struct Voice_803AFB00 *nextMacActive;
  struct Voice_803AFB00 *prevMacActive;
  struct Voice_803AFB00 *nextTimeQueueMacro;
  struct Voice_803AFB00 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803AFB00 *trapEventAddr[3];
  MSTEP_803AFB00 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803AFB00 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803AFB00 *vidList;
  VIDL_803AFB00 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803AFB00 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803AFB00 inpVolume;
  CDEST_803AFB00 inpPanning;
  CDEST_803AFB00 inpSurroundPanning;
  CDEST_803AFB00 inpPitchBend;
  CDEST_803AFB00 inpDoppler;
  CDEST_803AFB00 inpModulation;
  CDEST_803AFB00 inpPedal;
  CDEST_803AFB00 inpPortamento;
  CDEST_803AFB00 inpPreAuxA;
  CDEST_803AFB00 inpReverb;
  CDEST_803AFB00 inpPreAuxB;
  CDEST_803AFB00 inpPostAuxB;
  CDEST_803AFB00 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803AFB00;
#pragma pack(pop)

struct Obj_803B3AA8;
u16 sndRand(void);
s32 voiceIsLastStarted(Obj_803B3AA8 *arg0);
void inpSetMidiLastNote(u8 arg0, u8 arg1, u8 arg2);
struct Obj_803AE8F8;
struct Op_803AE8F8;
s32 mcmdWait(Obj_803AE8F8 *o, Op_803AE8F8 *op);

#pragma pack(push, 4)
typedef struct MSTEP_803B0198 { u32 para[2]; } MSTEP_803B0198;
typedef struct VIDL_803B0198 { struct VIDL_803B0198 *next; struct VIDL_803B0198 *prev; u32 vid; u32 root; } VIDL_803B0198;
typedef struct LFO_803B0198 { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803B0198;
typedef struct CSRC_803B0198 { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803B0198;
typedef struct CDEST_803B0198 { CSRC_803B0198 source[4]; u16 oldValue; u8 numSource; } CDEST_803B0198;
typedef struct Voice_803B0198 {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803B0198 *addr;
  MSTEP_803B0198 *curAddr;
  struct Voice_803B0198 *nextMacActive;
  struct Voice_803B0198 *prevMacActive;
  struct Voice_803B0198 *nextTimeQueueMacro;
  struct Voice_803B0198 *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803B0198 *trapEventAddr[3];
  MSTEP_803B0198 *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803B0198 *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803B0198 *vidList;
  VIDL_803B0198 *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803B0198 lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803B0198 inpVolume;
  CDEST_803B0198 inpPanning;
  CDEST_803B0198 inpSurroundPanning;
  CDEST_803B0198 inpPitchBend;
  CDEST_803B0198 inpDoppler;
  CDEST_803B0198 inpModulation;
  CDEST_803B0198 inpPedal;
  CDEST_803B0198 inpPortamento;
  CDEST_803B0198 inpPreAuxA;
  CDEST_803B0198 inpReverb;
  CDEST_803B0198 inpPreAuxB;
  CDEST_803B0198 inpPostAuxB;
  CDEST_803B0198 inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803B0198;
#pragma pack(pop)

typedef struct SynthInfo_803B0198 { u32 mixFrq; u32 numSamples; u8 pbInfo[0x208]; u8 voiceNum; u8 maxMusic; u8 maxSFX; u8 studioNum; } SynthInfo_803B0198;
u32 vidGetInternalId(u32 id);
void macMakeActive(void *arg0);
extern void (*synthMessageCallback)(u32, s32);

#pragma pack(push, 4)
typedef struct MSTEP_803B03CC { u32 para[2]; } MSTEP_803B03CC;
typedef struct VIDL_803B03CC { struct VIDL_803B03CC *next; struct VIDL_803B03CC *prev; u32 vid; u32 root; } VIDL_803B03CC;
typedef struct LFO_803B03CC { u32 time; u32 period; s16 value; s16 lastValue; } LFO_803B03CC;
typedef struct CSRC_803B03CC { u8 midiCtrl; u8 combine; s32 scale; } CSRC_803B03CC;
typedef struct CDEST_803B03CC { CSRC_803B03CC source[4]; u16 oldValue; u8 numSource; } CDEST_803B03CC;
typedef struct Voice_803B03CC {
  u32 lowPrecisionJob[3];
  u32 zeroOffsetJob[3];
  u32 eventJob[3];
  u64 lastLowCallTime;
  u64 lastZeroCallTime;
  MSTEP_803B03CC *addr;
  MSTEP_803B03CC *curAddr;
  struct Voice_803B03CC *nextMacActive;
  struct Voice_803B03CC *prevMacActive;
  struct Voice_803B03CC *nextTimeQueueMacro;
  struct Voice_803B03CC *prevTimeQueueMacro;
  u32 macState;
  MSTEP_803B03CC *trapEventAddr[3];
  MSTEP_803B03CC *trapEventCurAddr[3];
  u8 trapEventAny;
  MSTEP_803B03CC *callStack[4][2];
  u8 callStackEntryNum;
  u8 callStackIndex;
  u64 macStartTime;
  u64 wait;
  u64 waitTime;
  u8 timeUsedByInput;
  u16 loop;
  s32 local_vars[16];
  u32 child;
  u32 parent;
  u32 id;
  VIDL_803B03CC *vidList;
  VIDL_803B03CC *vidMasterList;
  u16 allocId;
  u16 macroId;
  u8 keyGroup;
  u32 lastVID;
  u8 prio;
  u16 ageSpeed;
  u32 age;
  u64 cFlags;
  u8 block;
  u8 fxFlag;
  u8 vGroup;
  u8 studio;
  u8 track;
  u8 midi;
  u8 midiSet;
  u8 section;
  u32 sInfo;
  u32 playFrq;
  u16 curNote;
  s8 curDetune;
  u8 orgNote;
  u8 lastNote;
  u8 portType;
  u16 portLastCtrlState;
  u32 portDuration;
  u32 portCurPitch;
  u32 portTime;
  u8 vibKeyRange;
  u8 vibCentRange;
  u32 vibPeriod;
  u32 vibCurTime;
  s32 vibCurOffset;
  s16 vibModAddScale;
  u32 volume;
  u32 orgVolume;
  float lastVolFaderScale;
  u32 lastPan;
  u32 lastSPan;
  float treCurScale;
  u16 treScale;
  u16 treModAddScale;
  u32 panning[2];
  s32 panDelta[2];
  u32 panTarget[2];
  u32 panTime[2];
  u8 revVolScale;
  u8 revVolOffset;
  u8 volTable;
  u8 itdMode;
  s32 envDelta;
  u32 envTarget;
  u32 envCurrent;
  u32 sweepOff[2];
  s32 sweepAdd[2];
  s32 sweepCnt[2];
  u8 sweepNum[2];
  LFO_803B03CC lfo[2];
  u8 lfoUsedByInput[2];
  u8 pbLowerKeyRange;
  u8 pbUpperKeyRange;
  u16 pbLast;
  u32 pitchADSR[10];
  s16 pitchADSRRange;
  u16 curPitch;
  struct { u8 vol, pan, midi, midiSet, section, track, vGroup, studio, itdMode; } setup;
  u32 midiDirtyFlags;
  CDEST_803B03CC inpVolume;
  CDEST_803B03CC inpPanning;
  CDEST_803B03CC inpSurroundPanning;
  CDEST_803B03CC inpPitchBend;
  CDEST_803B03CC inpDoppler;
  CDEST_803B03CC inpModulation;
  CDEST_803B03CC inpPedal;
  CDEST_803B03CC inpPortamento;
  CDEST_803B03CC inpPreAuxA;
  CDEST_803B03CC inpReverb;
  CDEST_803B03CC inpPreAuxB;
  CDEST_803B03CC inpPostAuxB;
  CDEST_803B03CC inpTremolo;
  u8 mesgNum;
  u8 mesgRead;
  u8 mesgWrite;
  s32 mesgQueue[4];
  u16 curOutputVolume;
} Voice_803B03CC;
#pragma pack(pop)

typedef struct SynthInfo_803B03CC { u32 mixFrq; u32 numSamples; u8 pbInfo[0x208]; u8 voiceNum; u8 maxMusic; u8 maxSFX; u8 studioNum; } SynthInfo_803B03CC;
struct Rec_803A9454;
void macSetExternalKeyoff(Rec_803A9454 *);

#pragma pack(push, 4)
struct SYNTH_VOICE_803B19AC {
    u8 pad0[0x34];
    void *addr;
    void *curAddr;
    SYNTH_VOICE_803B19AC *nextMacActive;
    SYNTH_VOICE_803B19AC *prevMacActive;
    SYNTH_VOICE_803B19AC *nextTimeQueueMacro;
    SYNTH_VOICE_803B19AC *prevTimeQueueMacro;
    u32 macState;
    void *trapEventAddr[3];
    void *trapEventCurAddr[3];
    u8 trapEventAny;
    u8 pad69[0x98 - 0x69];
    u64 wait;
    u64 waitTime;
    u8 padA8[0xF4 - 0xA8];
    u32 id;
    u8 padF8[0x114 - 0xF8];
    u64 cFlags;
};
#pragma pack(pop)
struct V_803B1F24;
struct Program_803B1DA4;

void macMakeActive(void *);
void macHandleActive(SYNTH_VOICE_803B19AC *);
u32 hwIsActive(s32 i);
extern Program_803B1DA4 *lbl_805D7420;
extern V_803B1F24 *lbl_805D741C;
extern u64 lbl_805D7428;

struct Prog_803B25CC;
struct Ch_803B1E48;
struct Obj_803B312C;
struct Rec_803A8D2C;
struct V_803B1F24;

#pragma pack(push, 4)
struct Voice_803B2128 {
    u8 pad0[0x34];
    u32 macroStart;
    u32 macroCur;
    Voice_803B2128 *next;
    Voice_803B2128 *prev;
    u8 pad44[0x4C - 0x44];
    s32 state;
    u8 pad50[0x8C - 0x50];
    u8 f8C;
    u8 f8D;
    u8 pad8E[0x98 - 0x8E];
    s64 f98;
    u8 padA0[0xEC - 0xA0];
    s32 fEC;
    s32 fF0;
    u32 fF4;
    u8 padF8[0x100 - 0xF8];
    u16 f100;
    u16 f102;
    u8 pad104[0x108 - 0x104];
    s32 f108;
    u8 pad10C[0x10E - 0x10C];
    u16 f10E;
    u32 f110;
    u64 flags;
    u8 pad11C;
    u8 f11D;
    u8 pad11E[0x12C - 0x11E];
    u16 f12C;
    u8 f12E;
    u8 f12F;
    u8 pad130[0x208 - 0x130];
    u8 f208;
    u8 f209;
    u8 f20A;
    u8 f20B;
    u8 f20C;
    u8 f20D;
    u8 f20E;
    u8 f20F;
    u8 f210;
    u8 pad211[0x3EC - 0x211];
    u8 f3EC;
    u8 f3ED;
    u8 f3EE;
    u8 pad3EF[0x404 - 0x3EF];
};
#pragma pack(pop)

extern "C" {
void voiceFree(Obj_803B312C *o);

u32 dataGetMacro(u16);
u32 vidMakeNew(SYNTH_VOICE_SV *svoice, u32 isMaster);
void voiceSetPriority(Voice_803B2128 *, u8);
u32 voiceAllocate(u8, u8, u16, u8);
void inpResetMidiCtrl(u8, u8, u8);
void inpResetChannelDefaults(u8, u8);
void hwBreak(u32);

}
struct Program_803B1DA4;

extern s16 lbl_805D7450;

typedef struct ADSR_VARS_803B41C8 {
    u8 mode;
    u8 state;
    u32 cnt;
    s32 currentVolume;
    s32 currentIndex;
    s32 currentDelta;
    union data_803B41C8 {
        struct _dls_803B41C8 {
            u32 aTime;
            u32 dTime;
            u16 sLevel;
            u32 rTime;
            u16 cutOff;
            u8 aMode;
        } dls;
    } data;
} ADSR_VARS_803B41C8;

extern u8 lbl_804F68DC[];
extern u8 lbl_804F68DC[];

typedef struct LAYER_803B4CF8 {
    u16 id;
    u8 keyLow;
    u8 keyHigh;
    s8 transpose;
    u8 volume;
    s16 prioOffset;
    u8 panning;
    u8 reserved[3];
} LAYER_803B4CF8;
typedef struct MEM_DATA_803B4CF8 {
    u32 nextOff;
    u16 id;
    u16 reserved;
    union {
        struct {
            u32 num;
            LAYER_803B4CF8 entry[1];
        } layer;
        u8 map[1];
        u8 tab[1];
        u32 cmd[1][2];
    } data;
} MEM_DATA_803B4CF8;
typedef struct POOL_DATA_803B4CF8 {
    u32 macroOff;
    u32 curveOff;
    u32 keymapOff;
    u32 layerOff;
} POOL_DATA_803B4CF8;

s32 dataInsertMacro(u16 mid, void *macroaddr);
s32 dataRemoveMacro(u16 mid);
s32 dataInsertKeymap(u16 cid, void *keymapdata);
s32 dataRemoveKeymap(u16 sid);
s32 dataInsertLayer(u16 cid, void *layerdata, u16 size);
s32 dataRemoveLayer(u16 sid);
s32 dataInsertCurve(u16 cid, void *curvedata);
s32 dataRemoveCurve(u16 sid);
s32 dataAddSampleReference(u16 sid);
s32 dataRemoveSampleReference(u16 id);

typedef struct _PB_803B5500 {
    u8 pad0[0x4];
    u16 currHi;
    u16 currLo;
    u8 pad8[0x38 - 0x8];
    u16 itdBufferHi;
    u16 itdBufferLo;
    u8 pad3C[0x4E - 0x3C];
    u16 updateDataHi;
    u16 updateDataLo;
    u8 pad52[0xBC - 0x52];
} _PB_803B5500;
typedef struct DSPvoice_803B5500 {
    _PB_803B5500 *pb;
    void *patchData;
    void *itdBuffer;
    u8 padC[0x24 - 0xC];
    u32 changed[5];
    u8 pad38[0xE4 - 0x38];
    u8 lastUpdatePitch;
    u8 lastUpdateVol;
    u8 lastUpdateVolA;
    u8 lastUpdateVolB;
    u32 virtualSampleID;
    u8 state;
    u8 postBreak;
    u8 startupBreak;
    u8 padEF[0xF4 - 0xEF];
} DSPvoice_803B5500;

extern u8 lbl_805D74C5;
extern u32 lbl_805D7458;
extern u16 *lbl_805D7478;
extern s32 *lbl_805D7484;
extern DSPvoice_803B5500 *lbl_805D748C;
extern void *lbl_805D7488;
extern s32 lbl_805D7480;

u32 aramGetZeroBuffer(void);
void *salMalloc(u32 size);
s32 memset(void *, int, int);
void DCFlushRange(void *, int);
void DCInvalidateRange(void *, int);
void DCStoreRangeNoSync(void *, int);
s32 DCFlushRangeNoSync(void *, int);
void salInitHRTFBuffer(void);
void salActivateStudio(u8 studio, u32 isMaster, u32 type);

typedef struct _PBDPOP_803B5AF8 {
    u16 aL;
    u16 aAuxAL;
    u16 aAuxBL;
    u16 aR;
    u16 aAuxAR;
    u16 aAuxBR;
    u16 aS;
    u16 aAuxAS;
    u16 aAuxBS;
} _PBDPOP_803B5AF8;
typedef struct _PB_803B5AF8 {
    u8 pad0[0xC];
    u16 mixerCtrl;
    u16 state;
    u8 pad10[0x52 - 0x10];
    _PBDPOP_803B5AF8 dpop;
} _PB_803B5AF8;
typedef struct DSPvoice_803B5AF8 {
    _PB_803B5AF8 *pb;
    u8 pad4[0xED - 0x4];
    u8 postBreak;
} DSPvoice_803B5AF8;
typedef struct DSPhostDPop_803B5AF8 {
    s32 l;
    s32 r;
    s32 s;
    s32 lA;
    s32 rA;
    s32 sA;
    s32 lB;
    s32 rB;
    s32 sB;
} DSPhostDPop_803B5AF8;
typedef struct DSPstudioinfo_803B5AF8 {
    void *spb;
    DSPhostDPop_803B5AF8 hostDPopSum;
} DSPstudioinfo_803B5AF8;

struct Ent_803B8910 { u8 pad0[0xC]; Ent_803B8910 *next; Ent_803B8910 *prev; u8 pad14[0x10]; s32 flags; u8 pad28[0xC4]; u8 active; u8 fED; u8 fEE; u8 idx; };

struct FVec_S3D { f32 x; f32 y; f32 z; };
struct FMat_S3D { f32 m[3][3]; f32 t[3]; };
struct StudioInput_S3D { u8 vol; u8 volA; u8 volB; u8 srcStudio; };

struct Room_S3D {
    Room_S3D *next;
    Room_S3D *prev;
    u32 flags;
    FVec_S3D pos;
    f32 distance;
    u8 studio;
    void (*activateReverb)(u8 studio, void *para);
    void (*deActivateReverb)(u8 studio);
    void *user;
    u32 curMVol;
};

struct Door_S3D {
    Door_S3D *next;
    Door_S3D *prev;
    FVec_S3D pos;
    f32 open;
    f32 dampen;
    u8 fxVol;
    u8 destStudio;
    Room_S3D *a;
    Room_S3D *b;
    u32 flags;
    s16 filterCoef[4];
    StudioInput_S3D input;
};

struct Listener_S3D {
    Listener_S3D *next;
    Listener_S3D *prev;
    Room_S3D *room;
    u32 flags;
    FVec_S3D pos;
    f32 volPosOff;
    FVec_S3D dir;
    FVec_S3D heading;
    FVec_S3D right;
    FVec_S3D up;
    FMat_S3D mat;
    f32 surroundDisFront;
    f32 surroundDisBack;
    f32 soundSpeed;
    f32 vol;
};

union ParaData_S3D { u8 value7; u16 value14; };
struct Param_S3D { u8 ctrl; ParaData_S3D paraData; };
struct ParaInfo_S3D { u8 numPara; Param_S3D *paraArray; };

struct Emitter_S3D {
    Emitter_S3D *next;
    Emitter_S3D *prev;
    Room_S3D *room;
    ParaInfo_S3D *paraInfo;
    u32 flags;
    FVec_S3D pos;
    FVec_S3D dir;
    f32 maxDis;
    f32 maxVol;
    f32 minVol;
    f32 volPush;
    u32 vid;
    u32 group;
    u16 fxid;
    u8 studio;
    u8 maxVoices;
    u16 VolLevelCnt;
    f32 fade;
};

extern s8 lbl_805D7498;
extern s32 lbl_805D749C;
extern s32 lbl_805D74A0;
extern s32 lbl_805D74A4;
extern s32 lbl_805D74A8;
extern s32 lbl_805D74AC;
extern s8 lbl_805D74B0;
extern s8 lbl_805D74B1;
extern s8 lbl_805D74B2;

s32 synthSendKeyOff(int id);
void synthActivateStudio(u8 studio, u32 isMaster, u32 type);
void synthDeactivateStudio(u8 studio);
void UpdateRoomDistances(void);

void salApplyMatrix(void *mat, void *in, void *out);
f32 salNormalizeVector(FVec_S3D *vec);

s32 synthFXSetCtrl(u32 id, u8 a1, u8 a2);
s32 synthFXSetCtrl14(u32 id, u8 a1, u16 a2);

struct StartList_S3D {
    StartList_S3D *next;
    f32 vol;
    f32 xPan;
    f32 yPan;
    f32 zPan;
    f32 pitch;
    Emitter_S3D *em;
};

struct RunList_S3D {
    RunList_S3D *next;
    f32 vol;
    Emitter_S3D *em;
};

struct StartGroup_S3D {
    u32 id;
    StartList_S3D *list;
    RunList_S3D *running;
    u16 numRunning;
};
extern u8 lbl_805D74B3;
extern u8 lbl_805D74B4;
extern u8 lbl_805D74B5;

void SetFXParameters(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);

s32 synthSendKeyOff(int id);
u32 sndFXCheck(u32 id);
void CheckRoomStatus(void);
void CheckDoorStatus(void);
void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan);
void SetFXParameters(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);
void AddRunningEmitter(Emitter_S3D *em, f32 vol);
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch);
void StartContinousEmitters(void);

}

extern "C" {
void ResetNotes(Owner_803A3C24 *o);
Node_803A3C24 *AllocateNote(s32 key, u8 ch);
s32 HandleNotes(void);
void KeyOffNotes(void);
void seqFreeKeyOffNote(Node_803A3C24 *arg0);
u32 GetPublicId(u32 seqId);
u32 seqGetPrivateId(u32 seqId);
u32 seqStartPlay(PAGE_803A49C8 *norm, PAGE_803A49C8 *drum, MIDISETUP_803A3D8C *midiSetup, u32 *song,
                         SND_PLAYPARA_SEQ *para, u8 studio, u16 sgid);
void HandleMasterTrack(u8 secIndex);
void StartPause(Node_803A4964 *arg0);
void seqPause(s32 seqId);
void seqKillInstancesByGroupID(u16 sgid);
void seqSpeed(u32 id, s16 v);
void seqContinue(s32 arg0);
void seqMute(s32 seqId, s32 mask1, s32 mask2);
void seqCrossFade(SND_CROSSFADE_803A49C8 *ci, u32 *new_seqId, u8 irq_call);
u8 *GetStreamValue(u8 *stream, u16 *deltaTime, s16 *deltaData);
Node_803A5A04 *GenerateNextTrackEvent(u8 trackId);
void InsertGlobalEvent(List_803A5A04 *arg0, Node_803A5A04 *arg1);
SEQ_EVENT_803A6364 *HandleEvent(SEQ_EVENT_803A6364 *event, u8 secIndex, u32 *loopFlag);
void InitTrackEvents(void);
void InitTrackEventsSection(u8 ch);
u32 HandleTrackEvents(u8 secIndex, u32 deltaTime);
void synthSetBpm(s32 arg0, u8 arg1, u8 arg2);
s32 synthGetTicksPerSecond(Obj_803A6F18 *arg0);
void synthInitPortamento(Obj_803A6F4C *arg0);
u32 do_voice_portamento(u8 key, u8 midi, u8 midiSet, u32 isMaster, u32 *rejected);
u32 StartLayer(u16 layerID, s16 prio, u8 maxVoices, u16 allocId, u8 key, u8 vol, u8 panning, u8 midi,
                         u8 midiSet, u8 section, u16 step, u16 trackid, u32 vidFlag, u8 vGroup, u8 studio, u32 itd);
void LowPrecisionHandler(u32 i);
void EventHandler(s32 arg0);
void synthAddJob(SYNTH_VOICE_SV *svoice, s32 jobType, u32 deltaTime);
void synthStartSynthJobHandling(Obj_803A8C5C* voice);
void synthForceLowPrecisionUpdate(void *arg0);
void synthKeyStateUpdate(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void HandleJobQueue(Node_803A8D2C **list, void (*cb)(u8));
void HandleFaderTermination(u8 *arg0);
s32 synthFXStart(s16 arg0, u8 arg1, u8 arg2, s32 arg3, s32 arg4);
s32 synthFXSetCtrl(u32 vid, u8 ctrl, u8 value);
s32 synthFXSetCtrl14(u32 vid, u8 ctrl, u16 value);
void synthFXCloneMidiSetup(u8 *arg0, u8 *arg1);
s32 synthSendKeyOff(int id);
s32 synthIsFadeOutActive(u8 arg0);
void synthSetMusicVolumeType(u8 i, u8 v);
s32 synthHWMessageHandler(s32 op, u32 idx);
void sndSeqSpeed(s32 arg0, s16 arg1);
void sndSeqContinue(s32 arg0);
void sndSeqMute(s32 arg0, s32 arg1, s32 arg2);
void sndSeqVolume(s8 arg0, s32 arg1, s32 arg2, s32 arg3);
u16 seqGetMIDIPriority(u8 arg0, u8 arg1);
s32 sndFXCtrl(u32 vid, u8 ctrl, u8 value);
s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value);
s32 sndFXKeyOff(s32 arg0);
s32 sndFXStartParaInfo(s16 arg0, u8 arg1, u8 arg2, s32 arg3, Req_803AA1E0 *req);
u32 sndFXCheck(u32 id);
void sndVolume(u8 arg0, u16 arg1, u8 arg2);
void sndOutputMode(s32 mode);
void sndSetAuxProcessingCallbacks(u8 studio, void *auxA, s32 userA, u8 midiA, u32 seqIDA, void *auxB, s32 userB, u8 midiB, u32 seqIDB);
void synthActivateStudio(u8 studio, u32 isMaster, u32 type);
void synthDeactivateStudio(u8 studio);
void synthAddStudioInput(u8 arg0, void *in_desc);
void synthRemoveStudioInput(u8 arg0, void *in_desc);
void streamCorrectLoops(void);
void streamKill(s32 arg0);
s32 GetPrivateIndex(u32 arg0);
void CheckOutputMode(s8 *arg0, s8 *arg1);
void streamOutputModeChanged(void);
u32 sndStreamAllocLength(u32 arg0, u32 arg1);
s32 dataRemoveKeymap(u16 arg0);
s32 dataInsertLayer(u16 key, void *p, u16 f6);
s32 dataRemoveLayer(u16 key);
s32 dataRemoveCurve(u16 arg0);
s32 dataAddSampleReference(u16 sid);
s32 dataRemoveSampleReference(u16 id);
s32 dataInsertFX(u16 arg0, Rec_803ADBF0 *arg1, u16 arg2);
s32 dataRemoveFX(u16 id);
s32 maccmp(u8 *arg0, u8 *arg1);
s32 smpcmp(u16 *arg0, u16 *arg1);
s32 dataGetSample(s16 id, Sample_803AE4D4 *s);
s32 curvecmp(u8 *arg0, u8 *arg1);
s32 dataGetCurve(s16 arg0);
s32 dataGetKeymap(s16 arg0);
s32 layercmp(u8 *arg0, u8 *arg1);
s32 dataGetLayer(s16 arg0, u16 *arg1);
s32 fxcmp(u16 *arg0, u16 *arg1);
Se_803A9144 *dataGetFX(s16 arg0);
void dataInit(void *arg0, void *arg1);
s32 mcmdWait(Obj_803AE8F8 *o, Op_803AE8F8 *op);
void mcmdLoop(Obj_803AEC00 *o, Op_803AEC00 *op);
void mcmdPlayMacro(Voice_803AED58 *svoice, MSTEP_803AED58 *cstep);
void mcmdVibrato(Obj_803AF0CC *o, Op_803AF0CC *op);
void mcmdSetADSR(Voice_803AF3DC *svoice, MSTEP_803AF3DC *cstep);
u32 TranslateVolume(u32 volume, u16 curve);
void DoEnvelopeCalculation(Voice_803AF9D4 *svoice, MSTEP_803AF9D4 *cstep, s32 start_vol);
void mcmdRandomKey(Voice_803AFB00 *svoice, MSTEP_803AFB00 *cstep);
void SelectSource(Obj_803AFCA0 *o, s32 ch, Op_803AFCA0 *op, u64 mask, u32 flag);
void mcmdPortamento(Obj_803AFDD4 *o, Op_803AFDD4 *op);
s32 varGet32(Obj_803AFF38 *arg0, u32 arg1, u32 arg2);
s16 varGet(Obj_803AFF9C *arg0, u32 arg1, u32 arg2);
void varSet32(Obj_803B0004 *arg0, u32 arg1, u32 arg2, s32 arg3);
void mcmdSendMessage(Voice_803B0198 *svoice, MSTEP_803B0198 *cstep);
void mcmdSetKeyGroup(Voice_803B03CC *svoice, MSTEP_803B03CC *cstep);
void macHandle(u32 deltaTime);
void macSampleEndNotify(Rec_803A996C *ov);
void macSetExternalKeyoff(Rec_803A9454 *arg0);
void macSetPedalState(Voice_803B1C98 *v, u32 hold);
void TimeQueueAdd(Program_803B1DA4 *self);
void UnYieldMacro(Ch_803B1E48 *o, u32 arg1);
void macMakeActive(void *arg0);
void macMakeInactive(Obj_803B312C *ov, s32 state);
u32 macStart(u16 arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7,
                      u8 arg8, u8 arg9, u16 arg10, u16 arg11, u8 arg12, u8 arg13, u8 arg14, u32 arg15);
void macInit(void);
void vidInit(void);
Node_803B2598 *get_vidlist(u32 key);
void vidRemoveVoiceReferences(Prog_803B25CC *p);
s32 vidMakeRoot(u8 *arg0);
u32 vidMakeNew(SYNTH_VOICE_SV *svoice, u32 isMaster);
u32 vidGetInternalId(u32 arg0);
void voiceFree(Obj_803B312C *o);
u32 voiceBlock(u8 prio);
void voiceUnblock(s32 voice);
void voiceKill(u32 vi);
s32 voiceKillSound(u32 voiceid);
void synthKillVoicesByMacroReferences(u16 *ref);
s32 voiceIsLastStarted(Obj_803B3AA8 *arg0);
void voiceSetLastStarted(Obj_803B3B24 *arg0);
void voiceResetLastStarted(Obj_803B3B80 *arg0);
void voiceInitLastStarted(void);
s32 sndPitchUpOne(s32 current);
u32 sndGetPitch(u8 note, u32 r);
u32 adsrConvertTimeCents(s32 arg0);
s32 salChangeADSRState(void *a0);
u32 adsrSetup(u8 *arg0);
u32 adsrStartRelease(ADSR_VARS_803B41C8 *adsr, u32 rtime);
s32 adsrRelease(struct Envelope_803B431C *e);
u32 adsrHandle(void *arg0, void *arg1, void *arg2);
u32 adsrHandleLowPrecision(void *arg0, void *arg1, void *arg2);
void vsInit(void);
void dataInitStack(void);
void InsertData(u16 id, void *data, u8 dataType, u32 remove);
void ScanIDList(u16 *p, void *a, void *b, void *c);
void ScanIDListReverse(u16 *start, void *a, void *b, void *c);
s32 seqPlaySong(u16 id, u16 sub, s32 a2, s32 a3, u8 locked, s32 a5);
void sndSeqPlayEx(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, u32 defaultStudioDPL2);
void salInitHRTFBuffer(void);
void salActivateStudio(u8 studio, u32 isMaster, u32 type);
void salDeactivateStudio(u8 i);
u32 salCheckVolErrorAndResetDelta(u16 *dsp_vol, u16 *dsp_delta, u16 *last_vol, u16 targetVol,
                         u16 *resetFlags, u16 resetMask);
void HandleDepopVoice(DSPstudioinfo_803B5AF8 *stp, DSPvoice_803B5AF8 *dsp_vptr);
void SortVoices(Ent_803B5DB0 **v, s32 left, s32 right);
s32 salSynthSendMessage(u8 *arg0, s32 arg1);
void salActivateVoice(Ent_803B8910 *dsp_vptr, u8 studio);
void salDeactivateVoice(Ent_803B89B4 *arg0);
s32 salAddStudioInput(Obj_803B8A14 *stp, Src_803B8A14 *desc);
s32 salRemoveStudioInput(Obj_803B8ABC *arg0, u32 arg1);
void salHandleAuxProcessing(void);
void UpdateRoomDistances(void);
void CheckRoomStatus(void);
void CheckDoorStatus(void);
void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan);
void SetFXParameters(Emitter_S3D *const em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler);
void EmitterShutdown(Node_803BA1B8 *arg0);
void s3dKillEmitterByFXID(Ent_803BA228 *arg0, u32 arg1);
void AddRunningEmitter(Emitter_S3D *em, f32 vol);
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch);
void StartContinousEmitters(void);
void s3dHandle(void);
void s3dInit(s32 arg0);
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize);
}

#endif
