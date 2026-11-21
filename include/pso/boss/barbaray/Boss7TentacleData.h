#ifndef PSO_BOSS_BARBARAY_BOSS7TENTACLEDATA_H
#define PSO_BOSS_BARBARAY_BOSS7TENTACLEDATA_H

#include "types.h"

// TBoss7Tentacle's and TBoss7TentacleNeedle's class names and angle tables. They live in their own
// unit ahead of TBoss7TentacleNeedle.cpp: its code addresses every table on its own, where tables
// defined in that unit would be reached off one hoisted .rodata base.

// The striking tentacle's draw scale (TBoss7Tentacle::render, state 3).
extern const f32 boss7_tentacle_draw_scale[3];
extern const s32 TBoss7Tentacle__target_angle_table[4];
extern const s32 boss7_tentacle_angle_table[4];
extern const char *TBoss7Tentacle__name;
extern const char *boss7_tentacle_needle_name_ptr;

#endif
