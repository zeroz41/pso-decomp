// The end of the render_util TU (see render_util_head.cpp): the original's out-of-line copies
// of its inline helpers, in definition order. Built as its own unit, sqrt_double cannot pool its
// constants where the original has them (before the pulse constants of render_util.cpp), so it
// reads the three doubles by address.
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/ModelDrawContext.h"

extern "C" {
extern const f32 __float_nan[];
extern const f32 __float_huge[];
extern const f64 lbl_8043F298[]; // 0.0
extern const f64 lbl_8043F2A0[]; // 0.5
extern const f64 lbl_8043F2A8[]; // 3.0
}

// MSL's double sqrt.
f64 sqrt_double(f64 x) {
    if (x > lbl_8043F298[0]) {
        f64 guess = __frsqrte(x);
        guess = lbl_8043F2A0[0] * guess * (lbl_8043F2A8[0] - x * (guess * guess));
        guess = lbl_8043F2A0[0] * guess * (lbl_8043F2A8[0] - x * (guess * guess));
        guess = lbl_8043F2A0[0] * guess * (lbl_8043F2A8[0] - x * (guess * guess));
        guess = lbl_8043F2A0[0] * guess * (lbl_8043F2A8[0] - x * (guess * guess));
        return x * guess;
    }
    if (lbl_8043F298[0] == x) {
        return lbl_8043F298[0];
    }
    if (x != lbl_8043F298[0]) {
        return __float_nan[0];
    }
    return __float_huge[0];
}

extern "C" void set_global_draw_flag_bits(void *owner, u32 bits) {
    model_render_flags |= bits;
}

void restore_model_render_flags(void *owner) { model_render_flags = color_draw_saved_render_flags; }

void restore_model_material_color(void *owner) {
    copy_argb(&model_material_color, &color_draw_saved_color);
}

void restore_chunk_polygon_masks(void *owner) {
    chunk_polygon_flags_and_mask = color_draw_saved_and_mask;
    chunk_polygon_flags_or_mask = color_draw_saved_or_mask;
}

void save_chunk_polygon_masks(void *owner) {
    color_draw_saved_and_mask = chunk_polygon_flags_and_mask;
    color_draw_saved_or_mask = chunk_polygon_flags_or_mask;
}

void save_model_material_color(void *owner) {
    copy_argb(&color_draw_saved_color, &model_material_color);
}

void save_model_render_flags(void *owner) { color_draw_saved_render_flags = model_render_flags; }
