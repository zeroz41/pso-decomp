#ifndef PSO_UNK_TLOBBY_80207644_H
#define PSO_UNK_TLOBBY_80207644_H

#include "types.h"
#include <stddef.h>

struct FloorMapSelection {
    s32 area;
    s32 terrain;
    s32 entities;
};

LAYOUT_ASSERT(FloorMapSelectionSize, sizeof(FloorMapSelection) == 0xC);
LAYOUT_ASSERT(FloorMapSelectionTerrainOffset, offsetof(FloorMapSelection, terrain) == 4);

extern "C" {
void TLobby__sub_80207BB0(void);
s32 get_floor_map_selection(s32 floor, FloorMapSelection *selection);
s32 lookup_floor_map_selection(s32 floor, FloorMapSelection *selection);
s32 get_floor_map_terrain(s32 floor);
void randomize_adventure_maps(void);
}
s32 get_boss_warp_destination(void);
void init_floor_map_registry(void);
// The area id of the map on a floor, or -1 when it has none.
saddr get_floor_area(s32 floor);
s32 set_floor_map_selection(s32 floor, s32 area, s32 terrain, s32 entities);
void set_floor_map_variant(s32 floor, s32 terrain);

#endif
