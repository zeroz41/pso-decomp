#ifndef PSO_SYSTEM_SCENE_TENDING_8008C5C0_H
#define PSO_SYSTEM_SCENE_TENDING_8008C5C0_H

#include "types.h"

void ending_scene_nop_release(void);
void ending_scene_nop_load(void);

// --- C functions defined in TEnding_8008C5C0.cpp ---
void ending_scene_nop_release(void);
void ending_scene_nop_load(void);
// --- end of C functions

extern "C" {
void fn_8008C4F4(void);
}
void run_game_frame(void);

#endif
