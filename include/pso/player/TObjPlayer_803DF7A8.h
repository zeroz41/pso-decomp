#ifndef PSO_PLAYER_TOBJPLAYER_803DF7A8_H
#define PSO_PLAYER_TOBJPLAYER_803DF7A8_H

#include "types.h"

struct Vec;

// The corner indices of a box's six faces.
struct Faces_803E0ED4 { s32 v[6][4]; };

extern "C" {
// 1 if the boxes minA..maxA and minB..maxB (axis-aligned) overlap.
s32 test_aabb_overlap(Vec *minA, Vec *maxA, Vec *minB, Vec *maxB);
}

#endif
