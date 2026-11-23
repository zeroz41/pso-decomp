#ifndef PSO_UNK_TLOBBY_800FD78C_H
#define PSO_UNK_TLOBBY_800FD78C_H

#include "types.h"
#include <stddef.h>

// Frames run by the current main phase's update loop (main counts it up).
extern s32 actor_frame_tick;

// The 0x28-byte global at 0x80515BA0 (address-named: no symbol, string or vtable names its class). Its methods were
// spelled as TLobby members, but TLobby is a 0x1C-byte TObject and init_range writes 0x00-0x20 of this object.
// Field names are inferred from the area code: promote_area_floor copies current -> previous and next -> current,
// load_area_scene_and_init hands current_floor to set_current_floor_area and current_map to TScene::set_scene, and
// set_area stores next_floor and get_floor_map_terrain(next_floor) into next_map.
class Obj_80515BA0 {
public:
    Obj_80515BA0();
    void init_range(s32 floor);
    s32 get_next_floor();
    void set_next_floor_index(s32 floor);
    void set_next_floor(s32 floor, s32 terrain_hint);
    void clear_ready_flag_unless_locked();

    s32 previous_floor;
    s32 current_floor;
    s32 f8;
    s32 next_floor;
    s32 current_map;
    s32 f14;
    s32 next_map;
    s32 f1C;
    s32 state_flags;
    u8 pad_24[4];
};

LAYOUT_ASSERT(FloorTransitionState_size, sizeof(Obj_80515BA0) == 0x28);
LAYOUT_ASSERT(FloorTransitionState_next_floor_offset, offsetof(Obj_80515BA0, next_floor) == 0xC);
LAYOUT_ASSERT(FloorTransitionState_flags_offset, offsetof(Obj_80515BA0, state_flags) == 0x20);
extern Obj_80515BA0 floor_transition_state;

extern "C" {
void initialize_floor_transition(Obj_80515BA0 *transition, s32 floor, s32 map);
void set_floor_transition_ready(Obj_80515BA0 *transition);
}
s32 select_area_entrance(Obj_80515BA0 *transition);
void run_area_scene_cleanup(Obj_80515BA0 *transition);
void promote_area_floor(Obj_80515BA0 *transition);

// The control role create_player_object hands the local player(s) (name inferred).
extern s32 player_control_role_base;

// --- C functions defined in TLobby_800FD78C.cpp ---
extern "C" {
u8 fn_800FD7C0(f32 *xz);
s32 has_nonfinite_position(f32 *xz);
}
// --- end of C functions

#endif
