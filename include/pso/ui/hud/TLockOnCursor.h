#ifndef PSO_UI_HUD_TLOCKONCURSOR_H
#define PSO_UI_HUD_TLOCKONCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/unk/TUnk_804A7248.h"
#include "pso/unk/TUnk_804A7254.h"

// Two words, the base of TUnk_8013F0A0.
class TUnk_8013F114 {
public:
    s32 unk_0;
    s32 unk_4;

    TUnk_8013F114();
    ~TUnk_8013F114();
};

// Two halfwords. TUnk_8013F0A0 holds four; TMainCursor::sort_actions_by_priority builds one on the stack.
class TUnk_8013E2B0 {
public:
    s16 unk_0;
    s16 unk_2;

    TUnk_8013E2B0();
};

// TLockOnCursor +0x24.
class TUnk_8013F0A0 : public TUnk_8013F114 {
public:
    TUnk_8013E2B0 unk_8[4];

    TUnk_8013F0A0();
    ~TUnk_8013F0A0();
};

// TLockOnCursor +0x3C: the TLOC_Start, TLOC_End and TLOC_ListClear tasks that
// reset_and_spawn_cursors creates and ~TLockOnCursor deletes. Each task clears its
// own slot when it is destroyed.
class TUnk_8013F08C {
public:
    TObject *start_task;
    TObject *end_task;
    TObject *list_clear_task;

    TUnk_8013F08C();
    ~TUnk_8013F08C();
    void set_list_clear_task(TObject *task);
    void set_end_task(TObject *task);
    void set_start_task(TObject *task);
    TObject *get_list_clear_task();
    TObject *get_end_task();
    TObject *get_start_task();
};

// A TargetCursorRecord and a flag word. Built and destroyed by the
// static TLockOnCursor::init_sub and the free function destroy_target_record, so both stay untyped here.
// TargetCursorList.h is not included: its C declarations clash with the cursor units' own.
struct TUnk_8013F054 {
    u8 unk_0[0x8];
    s32 unk_8;
};

// A count and eleven TUnk_8013F054, built by TLockOnCursor__sub_8013F000 and destroyed
// by destroy_target_records (no real constructor until TUnk_8013F054 has one).
struct TUnk_8013F000 {
    s32 unk_0;
    TUnk_8013F054 unk_4[11];
};

// TLockOnCursor +0x5C, four of them.
class LockOnActionSlot {
public:
    gc_tag unk_0;
    u8 pad_4[0x3C];
    u8 target_list[0x5C]; // a TargetCursorList, built by its constructor
    TUnk_8013F000 target_records;

    LockOnActionSlot();
    ~LockOnActionSlot();
};

// TLockOnCursor::selection. When the player confirms a lock-on candidate, its
// entity id, part and palette action go into target; the player acts on that entity.
class TUnk_8013EF6C {
public:
    u16 unk_0;
    s16 unk_2;
    f32 unk_4;
    gc_tag unk_8;
    TUnk_8013E780 target;
    TUnk_8013E780 unk_14;

    TUnk_8013EF6C();
    ~TUnk_8013EF6C();
    void reset_state();
};

// TLockOnCursor +0x508.
class TUnk_8013EF3C {
public:
    u16 actor_id;
    s16 collider;
    u16 unk_4;

    TUnk_8013EF3C();
};

// TLockOnCursor +0x510. TMainCursor::try_add_target_candidate keeps the closest
// candidate here while it scans; publish() copies its id and distance to the
// published pair.
class TUnk_8013EF0C {
public:
    s32 candidate_part_index; // the candidate's collision entry
    u16 published_target_id;
    u16 candidate_target_id;
    f32 published_target_dist;
    f32 candidate_target_dist;

    TUnk_8013EF0C();
    void publish();
    void set_published_target_dist(f32 dist);
    f32 get_candidate_target_dist();
    void set_published_target_id(u16 id);
    u16 get_candidate_target_id();
    void reset();
};

struct TLockOnCursor : public TObject {
    FlagWord flags;
    u16 target_id; // read by get_target_id()
    TUnk_8013F0A0 unk_24;
    TUnk_8013F08C tasks;
    TUnk_804A7254 unk_48;
    LockOnActionSlot action_slots[4]; // inferred: one action palette tag and its targets each (find_by_pos)
    TUnk_8013EF6C selection;
    TUnk_8013EF3C target_part;
    TUnk_8013EF0C nearest_target;
    TUnk_804A7248 palette_override; // the palette action forced by update_cursor or the short list

    TLockOnCursor(TObject *parent, u16 target_id);
    virtual ~TLockOnCursor();
    u16 get_target_id();
    void sub_8013EEC0(u16 target_id);
    virtual void render();
    void renderSecondaryCursor(u8* body, s32 type, s32 action);
    virtual void run_task();
    static void free_cursor_resources();
    int render_part();
    int update_cursor_pos();
    void set_flag_8_bit0();
    void update_ring();
    void is_bit1_set();
    int is_inactive();
    void update_ring_sub();
    int test_flag_1_at_8();
    s32 get_target();
    void set_list_clear_task(TObject *task);
    void set_end_task(TObject *task);
    void set_start_task(TObject *task);
    TObject *get_list_clear_task();
    TObject *get_end_task();
    TObject *get_start_task();
    void reset_and_spawn_cursors();
    static void *init_sub(void* p);
    LockOnActionSlot *find_by_pos(s16 mode, s16 kind);
};

LAYOUT_ASSERT(TLockOnCursor_size, sizeof(TLockOnCursor) == 0x52C);
#endif
