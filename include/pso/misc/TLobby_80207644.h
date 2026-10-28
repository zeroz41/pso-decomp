#ifndef PSO_MISC_TLOBBY_80207644_H
#define PSO_MISC_TLOBBY_80207644_H

#include "types.h"

extern "C" {
void TLobby__sub_80207BB0(void);
s32 get_boss_warp_destination(void);
s32 get_floor_map_selection(s32 arg0, u8 *arg1);
s32 get_floor_map_terrain(s32 arg0);
}
void init_floor_map_registry(void);
// The area id of the map on a floor (as get_current_area), -1 when it has none.
s32 get_floor_area(s32 floor);
extern "C" {
void randomize_adventure_maps(void);
}
s32 set_floor_map_selection(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void set_floor_map_variant(s32 arg0, s32 arg1);

// --- C functions defined in TLobby_80207644.cpp ---
extern "C" {
void TLobby__sub_80207BB0(void);
s32 get_boss_warp_destination(void);
s32 get_floor_map_selection(s32 arg0, u8 *arg1);
s32 get_floor_map_terrain(s32 arg0);
void randomize_adventure_maps(void);
}
// --- end of C functions

#endif
