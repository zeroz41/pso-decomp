#ifndef PSO_MAP_AREA_AREASCENE_H
#define PSO_MAP_AREA_AREASCENE_H

#include "types.h"

// Scene hooks of area_initializer_dispatch_table (FloorTransition.cpp), one source file per area
// under src/pso/map/area/, linked in the table's alphabetical area order. An init loads its area
// (0 while a disconnect is pending) and starts the area's bgm; a cleanup releases it.
s32 init_ancient1_area(void);           // ANCIENT01
void cleanup_ancient1_area(void);
s32 init_ancient2_area(void);           // ANCIENT02
void cleanup_ancient2_area(void);
s32 init_ancient3_area(void);           // ANCIENT03
void cleanup_ancient3_area(void);
void cleanup_dragon_area_scene(void);   // BOSS01
s32 init_dragon_area_scene(void);
s32 init_boss2_area(void);              // BOSS02
void cleanup_boss2_area(void);
s32 init_boss3_area(void);              // BOSS03
void cleanup_boss3_area(void);
s32 init_boss4_area(void);              // BOSS04
void cleanup_boss4_area(void);
s32 init_gryphon_area(void);            // BOSS05
void cleanup_gryphon_area(void);
s32 init_cave1_area(void);              // CAVE01
void cleanup_cave1_area(void);
s32 init_cave2_area(void);              // CAVE02
void cleanup_cave2_area(void);
s32 init_cave3_area(void);              // CAVE03
void cleanup_cave3_area(void);
s32 init_city_area(void);               // CITY, LABO
void cleanup_city_area(void);
s32 init_forest1_area(void);            // FOREST01
void cleanup_forest1_area(void);
s32 init_forest2_area(void);            // FOREST02
void cleanup_forest2_area(void);
s32 init_lobby_area(void);              // LOBBY
void cleanup_lobby_area(void);
s32 init_machine1_area(void);           // MACHINE01
void cleanup_machine1_area(void);
s32 init_machine2_area(void);           // MACHINE02
void cleanup_machine2_area(void);
s32 init_spaceship_area(void);          // VERSUS01, SPACE01, SPACE02
void cleanup_spaceship_area(void);
s32 init_temple_area(void);             // VERSUS02, RUINS01, RUINS02
void cleanup_temple_area(void);

// Empty; defined with BOSS02, and the CAVE, FOREST02, LOBBY, MACHINE and VERSUS02 inits call it with 0.
void debug_area_hook(s32 _w0);
// Defined in TFontSmallTask.cpp on its {load, release} pair type: runs each pair's load hook.
s32 run_load_callback_table(void *table, u32 size);

#endif
