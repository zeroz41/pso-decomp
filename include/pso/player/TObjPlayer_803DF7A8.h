#ifndef PSO_PLAYER_TOBJPLAYER_803DF7A8_H
#define PSO_PLAYER_TOBJPLAYER_803DF7A8_H

#include "types.h"

struct Vec;

// One row per box face: its four corner indices, or (the adjacent-face table) the face across each of its edges.
struct BoxFaces { s32 v[6][4]; };

extern "C" {
// 1 if the boxes minA..maxA and minB..maxB (axis-aligned) overlap.
s32 test_aabb_overlap(Vec *minA, Vec *maxA, Vec *minB, Vec *maxB);
// 1 if two boxes (eight corners each, as built by build_collision_box_corners) touch.
s32 test_box_overlap(Vec *cornersA, Vec *cornersB);
}

#endif
