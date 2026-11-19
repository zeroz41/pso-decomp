#ifndef PSO_MAP_AREA_AREASCENE_H
#define PSO_MAP_AREA_AREASCENE_H

#include "types.h"

// Scene hooks of area_initializer_dispatch_table (TLobby_80228154.cpp), one source file per area
// under src/pso/map/area/, linked in the table's alphabetical area order. An init loads its area
// (0 while a disconnect is pending) and starts the area's bgm; a cleanup releases it. The TLobby
// statics among them are declared in TLobby.h.
s32 ship_scene_update(void);          // ANCIENT01
s32 init_ship_scene(void);            // ANCIENT02
s32 load_scene_ship_b(void);          // ANCIENT03
void cleanup_dragon_area_scene(void); // BOSS01
s32 init_dragon_area_scene(void);
void cleanup_boss2_area(void);        // BOSS02
void cleanup_boss3_area(void);        // BOSS03
s32 init_cave_b_stage(void);          // CAVE01
s32 load_scene_cave_b(void);          // CAVE02
s32 init_stage_cave_b(void);          // CAVE03
s32 init_stage_forest_b(void);        // FOREST01
s32 init_forest_b(void);              // FOREST02
s32 init_machine_scene(void);         // MACHINE01
s32 init_machine_b_scene(void);       // MACHINE02
s32 init_spaceship_area(void);        // VERSUS01, SPACE01, SPACE02
s32 init_temple_area(void);           // VERSUS02, RUINS01, RUINS02

extern "C" {
// Empty; defined with BOSS02, and the CAVE, FOREST02, LOBBY, MACHINE and VERSUS02 inits call it with 0.
void TLobby__sub_801403B4(s32 _w0);
// Defined in TFontSmallTask.cpp on its {load, release} pair type: runs each pair's load hook.
s32 run_load_callback_table(void *table, u32 size);
// The CITY and LOBBY inits reset it through TLobby::reset_settings_to_default; no unit owns it yet.
extern s32 lobby_rule_settings[];
}

#endif
