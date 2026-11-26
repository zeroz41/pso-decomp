#ifndef PSO_RENDER_GINJADRAWUTIL_H
#define PSO_RENDER_GINJADRAWUTIL_H

#include "types.h"
struct Vec;
struct CollisionSphere;

extern "C" {
// The straight-line distance between a and b.
f32 xyz_distance(const Vec *a, const Vec *b);
// The paired-single matrix-stack helpers (hand-written assembly).
void translate_current_matrix_ps(f32 x, f32 y, f32 z);
// sin of angle in f1 and its cos in f2 (sin_cos_table), for the assembly callers.
f32 lookup_sin_cos(s32 angle);
void rotate_current_matrix_x_ps(s32 angle);
void reorder_current_matrix_ps(void);
// Entry inside reorder_current_matrix_ps after it loads the matrix pointer; push_reordered_matrix_ps branches here.
void reorder_matrix_ps_entry(void);
void push_reordered_matrix_ps(void);
}

// The smallest and largest corner of the eight corners of a box.
void calc_box_bounds(Vec *corners, Vec *min, Vec *max);
// The smallest and largest corner of the cube around a sphere.
void calc_sphere_bounds(CollisionSphere *sphere, Vec *min, Vec *max);

// Loads the current matrix as GX position matrix index (0-9).
void load_current_pos_matrix(s32 index);
// Loads the current matrix as GX texture matrix index (0-9).
void load_current_tex_matrix(s32 index);
// Loads texture index of the current render context's texture list into GX texture map map.
void load_list_texture(s32 index, s32 wrap_s, s32 wrap_t, s32 map);

#endif
