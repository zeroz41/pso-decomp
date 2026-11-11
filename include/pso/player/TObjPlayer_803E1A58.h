#ifndef PSO_PLAYER_TOBJPLAYER_803E1A58_H
#define PSO_PLAYER_TOBJPLAYER_803E1A58_H

#include "types.h"
struct Vec;

struct Vec_803E1B1C { f32 x, y, z; };

extern "C" {
// The smallest and largest corner of the eight points of a box.
void calc_bounds_min_max__10TObjPlayerFPvPvPv(Vec_803E1B1C *pts, Vec_803E1B1C *mn, Vec_803E1B1C *mx);
// The straight-line distance between a and b.
f32 xyz_distance(Vec *a, Vec *b);
// The paired-single matrix-stack helpers (hand-written assembly).
void translate_current_matrix_ps(f32 x, f32 y, f32 z);
// sin of angle in f1 and its cos in f2, for the assembly callers.
f32 TObjPlayer__sub_803E1CA4(s32 angle);
void rotate_current_matrix_x_ps(s32 angle);
void reorder_current_matrix_ps(void);
// Entry inside reorder_current_matrix_ps after it loads the matrix pointer; push_reordered_matrix_ps branches here.
void reorder_matrix_ps_entry(void);
void push_reordered_matrix_ps(void);
// Sets the current matrix to the identity.
void TObjPlayer__sub_803E1F60(void);
// Entry inside TObjPlayer__sub_803E1F60 after it loads the matrix pointer; push_identity_matrix_ps branches here.
void identity_matrix_ps_entry(void);
void push_identity_matrix_ps(void);
}

void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

#endif
