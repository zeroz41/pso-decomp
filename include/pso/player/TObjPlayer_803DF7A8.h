#ifndef PSO_PLAYER_TOBJPLAYER_803DF7A8_H
#define PSO_PLAYER_TOBJPLAYER_803DF7A8_H

#include "types.h"
struct Vec;

extern "C" {
// The straight-line distance between a and b.
f32 xyz_distance(Vec *a, Vec *b);
}

void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);
s32 spheres_overlap(u8 *arg0, u8 *arg1);

#endif
