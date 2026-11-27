#ifndef PSO_UI_HUD_TLOCKONCURSOR_H
#define PSO_UI_HUD_TLOCKONCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/player/TargetCursorList.h"
#include "pso/ui/hud/LockOnPaletteOverride.h"
#include "pso/ui/hud/MarkerColor.h"

// A priority and an index into the player's action palette.
struct CollisionBody;

class ActionPriorityEntry {
public:
    s16 priority;
    s16 index;

    ActionPriorityEntry();
    s16 get_priority();
    s16 get_index();
    void set_priority(s16 v);
    void set_index(s16 v);
};

// A count and a pointer to that many entries; the base of ActionPriorityList.
class ActionListBase {
public:
    s32 count;
    ActionPriorityEntry *entries;

    ActionListBase();
    ~ActionListBase();
    s32 get_count();
    ActionPriorityEntry *get_entries();
    void set_count(s32 v);
    void set_entries(s32 v);
};

// TLockOnCursor +0x24.
class ActionPriorityList : public ActionListBase {
public:
    ActionPriorityEntry slots[4];

    ActionPriorityList();
    ~ActionPriorityList();
    // Bubble sorts entries by priority, lowest first.
    s32 sort_actions_by_priority();
};

// TLockOnCursor +0x3C: the TLOC_Start, TLOC_End and TLOC_ListClear tasks that
// reset_and_spawn_cursors creates and ~TLockOnCursor deletes. Each task clears its
// own slot when it is destroyed.
class LockOnTasks {
public:
    TObject *start_task;
    TObject *end_task;
    TObject *list_clear_task;

    LockOnTasks();
    ~LockOnTasks();
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
    // Bit 1: the selected (primary) target, drawn by its own TMainCursor.
    int is_primary();
    void set_primary();
    void clear_primary();
    // Bit 2: shown in the list but not lockable (inactive cursor, button test, body flag 0x08000000).
    int is_excluded();
    void set_excluded();
    void clear_excluded();
};

// A count and eleven LockOnTargetRecord.
struct LockOnTargetRecordList {
    s32 count;
    LockOnTargetRecord records[11];

    LockOnTargetRecordList();
    ~LockOnTargetRecordList();
    void clear();
    LockOnTargetRecord *get_record(s32 index);
    s32 get_count();
    void set_count(s32 count);
};

// TLockOnCursor +0x5C, four of them.
class LockOnActionSlot {
public:
    gc_tag palette_tag;
    // How many targets publish_target_list keeps.
    s32 max_targets;
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
    s32 get_max_targets();
    // Sorts records[lo..hi] by value, nearest first.
    void quick_sort(TargetCursorRecord *records, s32 lo, s32 hi);
    s32 quick_sort_partition(TargetCursorRecord *a, s32 lo, s32 hi);
    void store_sorted_record(TargetCursorRecord *src, TargetCursorRecord *dst);
    s32 get_body_exclude_mask();
    int get_selected_entry();
    u8 get_active();
    s32 get_body_include_mask();
    s32 get_actor_exclude_mask();
    s32 get_actor_include_mask();
    void set_max_targets(s32 v);
    void set_body_include_mask(s32 v);
    void set_body_exclude_mask(s32 v);
    void set_actor_include_mask(s32 v);
    void set_actor_exclude_mask(s32 v);
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
    CursorTarget *get_target();
    // target and cursor_target name the same entity, part and palette action.
    int is_cursor_on_target();
};

// TLockOnCursor +0x508.
class LockOnTargetPart {
public:
    u16 actor_id;
    s16 collider;
    u16 unk_4;

    LockOnTargetPart();
};

// TLockOnCursor +0x510. TMainCursor::try_add_target_candidate keeps the closest
// candidate here while it scans; publish() copies its id and distance to the
// published pair.
class LockOnNearestTarget {
public:
    s32 candidate_part_index; // the candidate's collision entry
    u16 published_target_id;
    u16 candidate_target_id;
    f32 published_target_dist;
    f32 candidate_target_dist;

    LockOnNearestTarget();
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
    static NJS_OBJECT *target_cursor_model;
    FlagWord flags;
    u16 target_id; // read by get_target_id()
    ActionPriorityList action_list;
    LockOnTasks tasks;
    MarkerColor marker;
    LockOnActionSlot action_slots[4]; // inferred: one action palette tag and its targets each (find_by_pos)
    LockOnSelection selection;
    LockOnTargetPart target_part;
    LockOnNearestTarget nearest_target;
    LockOnPaletteOverride palette_override; // the palette action forced by update_cursor or the short list

    TLockOnCursor(TObject *parent, u16 target_id);
    virtual ~TLockOnCursor();
    u16 get_target_id();
    void set_target_id(u16 target_id);
    virtual void render();
    void renderSecondaryCursor(CollisionBody *body, s16 type, s32 action);
    virtual void run_task();
    static void free_cursor_resources();
    int is_inactive();
    LockOnActionSlot *get_action_slot(s32 i);
    // Copies the best of an action slot's sorted candidates into its target_records.
    void publish_target_list(s32 slot);
    // Sorts an action slot's candidates by distance.
    void sort_list(s32 index);
    void set_list_clear_task(TObject *task);
    void set_end_task(TObject *task);
    void set_start_task(TObject *task);
    TObject *get_list_clear_task();
    TObject *get_end_task();
    TObject *get_start_task();
    void reset_and_spawn_cursors();
    LockOnActionSlot *find_by_pos(s16 mode, s16 kind);
    // Fills the four action slots from the player's action palette.
    void bind_action_channels();
    void setup_action_channel(TObjPlayer *player, s32 slot, s32 kind, s16 id);
    s32 get_action_cursor_priority(TObjPlayer *player, s32 index);
    void set_cursor_color(TObjPlayer *player, LockOnActionSlot *main_cursor);
    void set_display_flags(TObjPlayer *player, LockOnActionSlot *main_cursor);
    void setup_flags(TObjPlayer *player, LockOnActionSlot *main_cursor);
    void init_slots();
    void init_slot(s32 i);
    void reset_slots();
    void set_cursor_pos(u16 part, s32 index);
    int is_cursor_clear();
    void set_flags_bit2();
    void set_flags_bit1();
    void clear_flag_1_at_1c();
};

LAYOUT_ASSERT(TLockOnCursor_size, sizeof(TLockOnCursor) == 0x52C);
#endif
