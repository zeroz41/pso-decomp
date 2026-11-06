#ifndef PSO_RENDER_NINJAUTIL_H
#define PSO_RENDER_NINJAUTIL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/NinjaTypes.h"

void clear_texlist_names(NJS_TEXLIST *texlist);
f32 vec_set_length(Vec *v, f32 length);
f32 vec_xz_distance(Vec *a, Vec *b);

extern "C" {
f32 xz_distance_squared(const Vec *a, const Vec *b);
f32 xyz_distance_squared(const Vec *a, const Vec *b);
}

NJS_OBJECT *find_object_node(NJS_OBJECT *root, s32 index);
// `root` and the result are model handles as the BML resources store them.
s32 find_model_node(u32 root, s32 index);

extern "C" {
void debug_printf_nop(const char *format, ...);
}

#endif
