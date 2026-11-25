#ifndef PSO_UI_HUD_TLOCKONCURSOR_H
#define PSO_UI_HUD_TLOCKONCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TargetCursorList.h"
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

// A TargetCursorRecord (id 0xFFFF when the slot has no target) and a flag word.
struct LockOnTargetRecord : public TargetCursorRecord {
    FlagWord flags;

    LockOnTargetRecord();
    ~LockOnTargetRecord();
    s16 get_part();
    u16 get_entity_id();
};

// A count and eleven LockOnTargetRecord.
struct LockOnTargetRecordList {
    s32 count;
    LockOnTargetRecord records[11];

    LockOnTargetRecordList();
    ~LockOnTargetRecordList();
    void clear();
    LockOnTargetRecord *get_record(s32 index);
};

// TLockOnCursor +0x5C, four of them.
class LockOnActionSlot {
public:
    gc_tag unk_0;
    u8 pad_4[0x4];
    // Collision body flags a candidate body must have / must not have.
    s32 body_include_mask;
    s32 body_exclude_mask;
    // Actor flags a candidate must have / must not have.
    s32 actor_include_mask;
    s32 actor_exclude_mask;
    // The farthest candidate distance in target_list; a closer one replaces it once the list is full.
    f32 max_candidate_dist;
    Vec origin;
    // Added to a candidate's radius.
    f32 lock_range;
    // Cosines of the half-angles of the cone a candidate must lie in.
    f32 horizontal_cone_cos;
    f32 vertical_cone_cos;
    // Half-angles of that cone; the cosines above are taken from them.
    s32 horizontal_cone_angle;
    s32 vertical_cone_angle;
    // How far behind origin the cone's apex sits.
    f32 cone_apex_offset;
    TargetCursorList target_list;
    LockOnTargetRecordList target_records;

    LockOnActionSlot();
    ~LockOnActionSlot();
    void reset_target_list();
    void reset_state();
    s32 get_body_exclude_mask();
    s32 get_body_include_mask();
    s32 get_actor_exclude_mask();
    s32 get_actor_include_mask();
};

// TLockOnCursor::selection. When the player confirms a lock-on candidate, its
// entity id, part and palette action go into target; the player acts on that entity.
class LockOnSelection {
public:
    u16 unk_0;
    s16 unk_2;
    f32 unk_4;
    gc_tag unk_8;
    CursorTarget target;
    CursorTarget cursor_target;  // update_cursor_pos copies target here

    LockOnSelection();
    ~LockOnSelection();
    void reset_state();
    void update_cursor_pos();
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
    s32 get_candidate_part_index();
    f32 get_published_target_dist();
    u16 get_published_target_id();
};

struct TLockOnCursor : public TObject {
    FlagWord flags;
    u16 target_id; // read by get_target_id()
    TUnk_8013F0A0 unk_24;
    TUnk_8013F08C tasks;
    TUnk_804A7254 unk_48;
    LockOnActionSlot action_slots[4]; // inferred: one action palette tag and its targets each (find_by_pos)
    LockOnSelection selection;
    TUnk_8013EF3C target_part;
    TUnk_8013EF0C nearest_target;
    TUnk_804A7248 palette_override; // the palette action forced by update_cursor or the short list

    TLockOnCursor(TObject *parent, u16 target_id);
    virtual ~TLockOnCursor();
    u16 get_target_id();
    void sub_8013EEC0(u16 target_id);
    virtual void render();
    void renderSecondaryCursor(u8 *body, s16 type, s32 action);
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
    LockOnActionSlot *find_by_pos(s16 mode, s16 kind);
};

LAYOUT_ASSERT(TLockOnCursor_size, sizeof(TLockOnCursor) == 0x52C);
#endif
