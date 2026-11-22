#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H

#include "types.h"

struct Vec;

extern "C" {
// True when b lies clockwise of a in the XZ plane (a.z * b.x - a.x * b.z < 0).
s32 is_vec_xz_cross_negative(const Vec *a, const Vec *b);
void rotate_vec_xz(void *arg0, void *arg1, s32 angle);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 angle);
}

#endif
