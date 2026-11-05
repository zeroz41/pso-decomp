#ifndef PSO_PLAYER_TOBJPLAYER_8012105C_H
#define PSO_PLAYER_TOBJPLAYER_8012105C_H

#include "types.h"

extern "C" {
u8 get_motion_type__11TItemWeaponFv(void *p);
void TObjPlayer__sub_8012105C(void);
void TObjPlayer__sub_80121060(void);
}
void *get_model_joint_matrix(void *a0, int a1);
extern "C" {
void set_weapon_trail_joints(s32 weapon, s32 trail, s32 start_joint, s32 end_joint);
}

// --- C functions defined in TObjPlayer_8012105C.cpp ---
extern "C" {
u8 get_motion_type__11TItemWeaponFv(void *p);
void TObjPlayer__sub_8012105C(void);
void TObjPlayer__sub_80121060(void);
void set_weapon_trail_joints(s32 weapon, s32 trail, s32 start_joint, s32 end_joint);
}
// --- end of C functions

#endif
