#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H

#include "types.h"

extern "C" {
bool is_vec_xz_cross_negative(u8 *arg0, u8 *arg1);
void rotate_vec_xz(void *arg0, void *arg1, s32 angle);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 angle);
}

#endif
