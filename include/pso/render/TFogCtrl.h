#ifndef PSO_RENDER_TFOGCTRL_H
#define PSO_RENDER_TFOGCTRL_H

#include "types.h"

struct FogParam_800FBC5C;
#include "pso/system/task/TObject.h"

// One fogentry.dat record.
struct FogEntry {
    u32 flags;           // 2: waves move the distances, 4: the slot's scroll advances
    u32 color;
    f32 end;
    f32 start;
    f32 rate;            // blend step per frame when a transition moves to this entry
    u32 pad_14;
    f32 waves[8];        // [0] wave speed, [2] end amplitude, [4] start amplitude, [6] width
    u8 wave_phases[8];   // degrees added to the [2], [4] and [6] waves
};
LAYOUT_ASSERT(FogEntry_size, sizeof(FogEntry) == 0x40);

struct FogSlot {
    FogEntry params;
    s32 entry;           // index into fogentry.dat
    f32 scroll;          // 0..128, advanced by waves[0] while flags & 4
    s32 pad_48[3];
};
LAYOUT_ASSERT(FogSlot_size, sizeof(FogSlot) == 0x54);

struct TFogCtrl : public TObject {
    TFogCtrl(TObject *parent, s32 index);
    virtual ~TFogCtrl();
    virtual void run_task();
    u32 dirty;           // 1: color/end/start/width changed since the last apply_fog_entry
    s32 mode;            // 0 idle, 1 swap slots, 2 start a blend, 3 blending
    FogSlot slot_storage[4];
    FogSlot *slots[4];   // [3] holds the mix while blending
    s32 selected;
    u32 color;
    f32 end;
    f32 start;
    f32 width;
    u32 pad_198;
    s32 request_from;
    s32 request_to;
    s32 request_selected;
    u32 pad_1a8;
    s32 blend_from;
    s32 blend_to;
    s32 blend_selected;
    f32 blend_amount;
    f32 blend_rate;
    s32 locked;          // while set, select_fog and restore_fog refuse
    s32 index;           // the view this controller belongs to
    static TFogCtrl *fog_instance_table[4];  // one per view, NULL when none
    static s32 select_fog_for_viewport(s32 arg0, s32 entry, s32 arg2);
    static s32 restore_fog_for_player(s32 owner_client_id, s32 player);
    static FogEntry *get_entry(int a0);
    static void clear_split_screen_fog();
    static void update_all();
    void clear_active_flag();
    s32 restore_fog(s32 arg1);
    void request_transition(s32 arg1, s32 arg2);
    s32 get_param();
    void apply_slot_params(s32 idx);
    s32 is_controller_animated(s32 idx);
    void load_entry_into_slot(s32 i, s32 entry);
    virtual void render();
    static void update_fog_entries();
    static void reset();
    static void create_instance();
    static s32 update_all(s32 entry, s32 flags);
    static s32 apply_all(s32 entry, s32 arg1);
    static s32 update_first_active_fog();
    static s32 update_all(s32 arg0);
    s32 select_fog(s32 entry, s32 arg2);
    s32 request_fog(s32 entry, s32 flags);
    void swap_slots(s32 i, s32 j);
    void apply_fog_entry();
    s32 get_current_entry();
    void on_entries_loaded();          // empty
    void on_entries_released();        // empty
    // The session resource unload callback paired with update_fog_entries.
    static void release_fog_entries();
};

LAYOUT_ASSERT(TFogCtrl_size, sizeof(TFogCtrl) == 0x1C8);
void init_scene_fog_system(void);
#endif
