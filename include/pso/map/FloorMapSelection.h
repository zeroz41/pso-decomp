#ifndef PSO_MAP_FLOORMAPSELECTION_H
#define PSO_MAP_FLOORMAPSELECTION_H

#include "types.h"
#include <stddef.h>

struct FloorMapSelection {
    s32 area;
    s32 terrain;
    s32 entities;
};

LAYOUT_ASSERT(FloorMapSelectionSize, sizeof(FloorMapSelection) == 0xC);
LAYOUT_ASSERT(FloorMapSelectionTerrainOffset, offsetof(FloorMapSelection, terrain) == 4);

void reset_floor_map_registry(void);

// The story-select state TLobby::reset_story_select clears to -1.
extern s32 story_select_pending_state;
// The episode select_episode last picked.
extern int selected_episode;
// The model file suffixes TSceneSora::load_sky_resources puts on a floor's sky name.
extern const char sky_model_ext_s_njm[];
extern const char sky_model_ext_sm_gj[];
extern const char sky_model_ext_s_gj[];
// Picks episode 0 or 1 and resets the floor map registry for it.
void select_episode(s32 episode);
// Copies the game variations' (terrain, entities) pairs into the floor map registry.
void copy_table_entries(u32 *src, u32 size);
s32 get_floor_map_selection(s32 floor, FloorMapSelection *selection);
s32 lookup_floor_map_selection(s32 floor, FloorMapSelection *selection);
s32 get_floor_map_terrain(s32 floor);
void randomize_adventure_maps(void);
s32 get_boss_warp_destination(void);
void init_floor_map_registry(void);
// The area id of the map on a floor, or -1 when it has none.
saddr get_floor_area(s32 floor);
s32 set_floor_map_selection(s32 floor, s32 area, s32 terrain, s32 entities);
void set_floor_map_variant(s32 floor, s32 terrain);

struct TLobbyIds { s32 w[18]; };

struct GetBossWarpDestinationTable { s32 w[2][18]; };

void reset_story_select_state();

#endif
