#ifndef PSO_PLAYER_TOBJPLAYER_8012105C_H
#define PSO_PLAYER_TOBJPLAYER_8012105C_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct TObjPlayer;

extern "C" {
u8 get_motion_type__11TItemWeaponFv(void *p);
void TObjPlayer__sub_8012105C(void);
void TObjPlayer__sub_80121060(void);
}
MtxP get_model_joint_matrix(TObjPlayer *player, int joint);

// --- C functions defined in TObjPlayer_8012105C.cpp ---
extern "C" {
u8 get_motion_type__11TItemWeaponFv(void *p);
void TObjPlayer__sub_8012105C(void);
void TObjPlayer__sub_80121060(void);
}
// --- end of C functions

#endif
