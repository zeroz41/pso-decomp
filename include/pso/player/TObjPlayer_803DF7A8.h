#ifndef PSO_PLAYER_TOBJPLAYER_803DF7A8_H
#define PSO_PLAYER_TOBJPLAYER_803DF7A8_H

#include "types.h"
struct Vec;

extern "C" {
// The straight-line distance between a and b.
f32 xyz_distance(Vec *a, Vec *b);
// The paired-single matrix-stack helpers (hand-written assembly).
void translate_current_matrix_ps(f32 x, f32 y, f32 z);
// sin of angle in f1 and its cos in f2, for the assembly callers.
f32 TObjPlayer__sub_803E1CA4(s32 angle);
void rotate_current_matrix_x_ps(s32 angle);
void reorder_current_matrix_ps(void);
void push_reordered_matrix_ps(void);
// Sets the current matrix to the identity.
void TObjPlayer__sub_803E1F60(void);
void push_identity_matrix_ps(void);
}

void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);
s32 spheres_overlap(u8 *arg0, u8 *arg1);

#endif
