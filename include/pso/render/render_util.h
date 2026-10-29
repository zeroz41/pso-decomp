#ifndef PSO_RENDER_RENDER_UTIL_H
#define PSO_RENDER_RENDER_UTIL_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/NinjaTypes.h"
#include "pso/system/date.h"

// Render-state and vector/angle helpers shared by the object renderers:
// TEV swap and cull modes, the depth/alpha state the Ginja draw restores
// after each list, blend presets, colour-override draws that save and
// restore the model render state, and small vector and angle math.

// The z and alpha-compare state every draw list starts from.
struct DepthAlphaState {
    s32 alpha_compare;    // GXCompare for the first alpha test
    u8 z_before_tex;      // GXSetZCompLoc
    u8 z_compare;         // GXSetZMode compare enable
    s32 z_func;           // GXSetZMode GXCompare
    u8 z_update;          // GXSetZMode update enable
    u8 alpha_ref;         // reference for the material alpha compare
    u32 draw_list_mask;   // Ginja draw-list mask

    void copy(DepthAlphaState *src);
};

extern DepthAlphaState depth_buffer_settings;
extern DepthAlphaState depth_buffer_config_copy;
extern DepthAlphaState saved_depth_alpha_scene_state;

// Translucent colours the debug and effect renderers draw with.
extern NJS_ARGB chunk_material_color_half_alpha_f32;
extern NJS_ARGB debug_color_purple_half_alpha;
extern NJS_ARGB debug_color_green_half_alpha;
extern NJS_ARGB debug_color_blue_alpha30;
extern NJS_ARGB debug_color_blue;
extern NJS_ARGB trap_ancient_light_color;

s32 calc_triangle_normal(const Vec *tri, Vec *out);
u32 calc_gx_tile_index(u32 x, u32 y, s16 width);

void init_tev_swap();
void set_tev_swap_mode(u8 table);
void set_tev_swap_channels(u8 r, u8 g, u8 b, u8 a);

void set_cull_none();
void set_cull_front();
void set_cull_back();

void set_shadow_material_state();

void init_depth_alpha_state();
void install_depth_alpha_state();
void restore_draw_list_mask();
void set_draw_list_mask(u32 mask);
void restore_depth_buffer_settings();
void save_depth_buffer_settings();
void restore_alpha_ref();
void set_alpha_ref_override(u8 ref);
void set_depth_buffer_settings_2();
void setup_alpha_test_render_state(s32 ref);
void set_depth_buffer_settings_1();
void set_depth_buffer_settings_3();

u32 calc_pulse_flash_color(u8 r, u8 g, u8 b, s32 frame, s32 period, s32 start, s32 peak, s32 end);

void calc_direction_vector(s32 angle, Vec *out, f32 length);
void calc_circle_offset_pos(s32 angle, Vec *center, Vec *out, f32 radius);
s32 calc_angle_to(Vec *from, Vec *to);

// Colour blending presets (set_color_blending_mode source/destination).
void set_inverse_alpha_blend();
void set_inverse_color_blend();
void set_default_alpha_blend();
void set_additive_blend();

s32 clamp_s32(s32 value, s32 min, s32 max);
void get_current_date_stamp(DateStamp *out);
void direction_to_rotation_yx(u8 *dir, s32 *rot_a, s32 *rot_b);
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
void direction_to_rotation_xy(u8 *dir, s32 *rot_a, s32 *rot_b);
s32 lerp_angle_half(s32 from, s32 to);
void vsub(void *a, void *b, void *out);
f32 vec_distance_squared(u8 *a, u8 *b);
s32 is_near_zero(f32 value);
u8 vec_has_nonfinite(Vec *v);

// A constant-colour draw: save the model render state, draw with a fixed
// material colour, restore it. `owner` is the caller's draw object; the
// state lives in this module.
void begin_constant_color_draw_argb(void *owner, f32 a, f32 r, f32 g, f32 b);
void begin_constant_color_draw(void *owner, const NJS_ARGB *color);
void begin_constant_color_draw_self(NJS_ARGB *color);
void restore_model_draw_state(void *owner);
void save_model_draw_state(void *owner);
f64 sqrt_double(f64 x);
void restore_model_render_flags(void *owner);
void restore_model_material_color(void *owner);
void restore_chunk_polygon_masks(void *owner);
void save_chunk_polygon_masks(void *owner);
void save_model_material_color(void *owner);
void save_model_render_flags(void *owner);

// What a constant-colour draw saved (restored by restore_model_draw_state).
extern u32 color_draw_saved_render_flags;
extern u32 color_draw_saved_and_mask;
extern u32 color_draw_saved_or_mask;
extern NJS_ARGB color_draw_saved_color;

extern "C" {
void restore_saved_depth_alpha_state(void);
s32 TObjMapWarp__sub_80141C68(s32 self, s16 del);
void TObjMapWarp__sub_80141CA4(void *self);
// Debug-draw entry points; their bodies are compiled out of the release game.
void debug_draw_line(const Vec *from, const Vec *to, u32 from_color, u32 to_color);
void fn_80141CB4(void);
void fn_80141CB8(void);
void fn_80141CBC(const Vec *pos, const NJS_ARGB *color, f32 size);
void fn_80141CF0(const Vec *pos, Vec *scale, const NJS_ARGB *color);
void debug_draw_sphere(const Vec *pos, const NJS_ARGB *color, f32 radius);
f32 horizontal_distance_squared(const Vec *a, const Vec *b);
// Normalizes v and returns 1, or returns 0 when v is (nearly) zero.
s32 normalize_if_nonzero(Vec *v);
s32 f32_bits(f32 value);
f32 bits_to_f32(s32 bits);
s32 angle_difference_abs(s32 a, s32 b);
s16 angle_diff_s16(s32 a, s32 b);
f32 approach_vector_fixed_distance(const Vec *from, const Vec *to, Vec *out, f32 step);
s32 approach_angle_adaptive(s32 from, s32 to);
s32 approach_angle_limited(s32 from, s32 to, s32 max_step);
void set_global_draw_flag_bits(void *owner, u32 bits);
}

#endif
