#ifndef PSO_MISC_TLOBBY_800FD78C_H
#define PSO_MISC_TLOBBY_800FD78C_H

#include "types.h"

// The 0x28-byte global at 0x80515BA0 (address-named: no symbol, string or vtable names its class). Its methods were
// spelled as TLobby members, but TLobby is a 0x1C-byte TObject and init_range writes 0x00-0x20 of this object.
// Field names are inferred from the area code: promote_area_floor copies current -> previous and next -> current,
// load_area_scene_and_init hands current_floor to set_current_floor_area and current_map to TScene::set_scene, and
// set_area stores next_floor and get_floor_map_terrain(next_floor) into next_map.
class Obj_80515BA0 {
public:
    Obj_80515BA0();
    void init_range(s32 floor);

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

extern "C" {
u8 fn_800FD7C0(void *arg0);
}

// --- C functions defined in TLobby_800FD78C.cpp ---
extern "C" {
u8 fn_800FD7C0(void *arg0);
}
// --- end of C functions

#endif
