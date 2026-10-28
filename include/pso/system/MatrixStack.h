#ifndef PSO_SYSTEM_MATRIXSTACK_H
#define PSO_SYSTEM_MATRIXSTACK_H

#include "types.h"
#include <dolphin/mtx.h>

// The model matrix stack the Ninja-style draw code works on (the
// text_803D96A8 unit), and the screen projection it feeds.
extern "C" {
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(const f32 *v);
void scale_current_matrix(const f32 *v);
// ang is an NJS_OBJECT ang[3]; zxy != 0 applies the angles in Z, X, Y order.
void rotate_matrix_by_node_angles(const s32 *ang, u32 zxy);
void transform_point_by_current_matrix(const f32 *src, Vec *dst);
// Projects a world point through `mtx` (the current view when NULL) to
// screen x/y.
void project_world_to_screen(u8 *mtx, const Vec *pos, f32 *screen);
}

#endif
