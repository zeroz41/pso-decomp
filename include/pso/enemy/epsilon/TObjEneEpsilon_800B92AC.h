#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILON_800B92AC_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILON_800B92AC_H

#include "types.h"

extern "C" {
void TObjEneEpsilon__sub_800B92AC(u8 *arg0, s32 arg1, f32 farg0);
void TObjEneEpsilon__sub_800B92F8(u8 *arg0, s32 arg1, f32 farg0);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
int vfunc_104__12TObjEneDD_STFf(void *p);
s32 enemy_bind_or_clear_target(void *self, u16 x);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern "C" {
s32 enemy_validate_retained_target(u8 *arg0);
void select_nearest_target__12TObjEneDD_STFf(s32 arg0);
}

// --- C functions defined in TObjEneEpsilon_800B92AC.cpp ---
extern "C" {
void TObjEneEpsilon__sub_800B92AC(u8 *ene_epsilon, s32 arg1, f32 farg0);
void TObjEneEpsilon__sub_800B92F8(u8 *ene_epsilon, s32 arg1, f32 farg0);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
int vfunc_104__12TObjEneDD_STFf(void *p);
s32 enemy_bind_or_clear_target(void *self, u16 x);
s32 enemy_validate_retained_target(u8 *ene_dd_st);
}
// --- end of C functions

#endif
