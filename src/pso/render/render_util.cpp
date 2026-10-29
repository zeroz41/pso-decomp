// One original TU runs from calc_triangle_normal (0x801412D0) to the weak inline copies at
// 0x80142624-0x80142770, but its out-of-line copy of sqrt_double sits at the TU end while the
// copy's constants sit between the tev tables and the pulse constants. No compiler here emits
// that (a copy follows its first caller, its constants with it), so the TU is built as three
// units: render_util_head.cpp, this one (set_cull_none to save_model_draw_state) and
// render_util_tail.cpp.

#include "pso/render/render_util.h"
#include <dolphin/gx.h>
#include "pso/enemy/TObjEneMe3Stelth_803DC82C.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/render/model_render_state.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/system/ModelDrawContext.h"

#define RAD_TO_ANGLE (32768.0 / 3.141592f)

extern "C" {
void normalize_vector(Vec *v);
f32 vector_length(Vec *v);
s32 TCameraCtrl__sub_8006B370(f32 value);
}

NJS_ARGB chunk_material_color_half_alpha_f32 = {0.5f, 0.0f, 0.0f, 0.0f};
NJS_ARGB debug_color_purple_half_alpha = {0.5f, 0.5f, 0.0f, 0.5f};
NJS_ARGB debug_color_green_half_alpha = {0.5f, 0.0f, 1.0f, 0.0f};
NJS_ARGB debug_color_blue_alpha30 = {0.3f, 0.0f, 0.0f, 1.0f};
NJS_ARGB debug_color_blue = {1.0f, 0.0f, 0.0f, 1.0f};
NJS_ARGB trap_ancient_light_color = {0.2f, 1.0f, 1.0f, 1.0f};

u32 saved_model_render_flags;
u32 saved_chunk_polygon_flags_and_mask;
u32 saved_chunk_polygon_flags_or_mask;
u32 color_draw_saved_render_flags;
u32 color_draw_saved_and_mask;
u32 color_draw_saved_or_mask;

void set_cull_none() { GXSetCullMode(GX_CULL_NONE); }
void set_cull_front() { GXSetCullMode(GX_CULL_FRONT); }
void set_cull_back() { GXSetCullMode(GX_CULL_BACK); }

void set_shadow_material_state() {
    NJS_ARGB color;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    color.a = 0.65f;
    set_constant_material(&color);
    model_render_flags |= 0x400;
}

NJS_ARGB saved_model_draw_color;
NJS_ARGB lbl_8050BED0; // no reference in the game
f32 scratch_vec[8];
f32 lbl_8050BF00[8];
u32 lbl_8050BF20[8];
u32 lbl_8050BF40[8];
f32 lbl_8050BF60[16];
u32 scratch_rotation[16];
f32 player_feedback_light_color[4];
NJS_ARGB color_draw_saved_color;
DepthAlphaState depth_buffer_settings;
DepthAlphaState depth_buffer_config_copy;
DepthAlphaState saved_depth_alpha_scene_state;

void init_depth_alpha_state() {
    depth_buffer_settings.alpha_compare = GX_ALWAYS;
    depth_buffer_settings.z_before_tex = 1;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_LESS;
    depth_buffer_settings.z_update = 1;
    depth_buffer_settings.alpha_ref = 0xBF;
    depth_buffer_settings.draw_list_mask = 1;
    depth_buffer_config_copy.copy(&depth_buffer_settings);
    saved_depth_alpha_scene_state.copy(&depth_buffer_settings);
}

void DepthAlphaState::copy(DepthAlphaState *src) {
    alpha_compare = src->alpha_compare;
    z_before_tex = src->z_before_tex;
    z_compare = src->z_compare;
    z_func = src->z_func;
    z_update = src->z_update;
    alpha_ref = src->alpha_ref;
    draw_list_mask = src->draw_list_mask;
}

void install_depth_alpha_state() {
    depth_buffer_settings.alpha_compare = GX_ALWAYS;
    depth_buffer_settings.z_before_tex = 1;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_LESS;
    depth_buffer_settings.z_update = 1;
    depth_buffer_settings.alpha_ref = 0xBF;
    depth_buffer_settings.draw_list_mask = 1;
    depth_buffer_config_copy.copy(&depth_buffer_settings);
    saved_depth_alpha_scene_state.copy(&depth_buffer_settings);
    TObjPlayer::set_global_state((s32)((void *)restore_saved_depth_alpha_state));
    set_ginja_draw_end_callback((s32)restore_saved_depth_alpha_state);
}

void restore_draw_list_mask() {
    set_ginja_draw_list_mask(saved_depth_alpha_scene_state.draw_list_mask);
}

void set_draw_list_mask(u32 mask) {
    depth_buffer_settings.draw_list_mask = mask;
    set_ginja_draw_list_mask(mask);
}

void restore_depth_buffer_settings() {
    depth_buffer_settings.copy(&saved_depth_alpha_scene_state);
}

void save_depth_buffer_settings() {
    saved_depth_alpha_scene_state.copy(&depth_buffer_settings);
}

void restore_alpha_ref() {
    model_render_flags &= ~1;
    set_material_alpha_compare_reference(saved_depth_alpha_scene_state.alpha_ref);
}

void set_alpha_ref_override(u8 ref) {
    model_render_flags |= 1;
    depth_buffer_settings.alpha_ref = ref;
    set_material_alpha_compare_reference(ref);
}

void set_depth_buffer_settings_2() {
    depth_buffer_settings.z_before_tex = 0;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_ALWAYS;
    depth_buffer_settings.z_update = 0;
    depth_buffer_settings.alpha_ref = 0;
    GXSetZCompLoc(GX_FALSE);
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    set_material_alpha_compare_reference(0);
}

void setup_alpha_test_render_state(s32 ref) {
    depth_buffer_settings.z_before_tex = 0;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_LEQUAL;
    depth_buffer_settings.z_update = 1;
    depth_buffer_settings.alpha_ref = ref;
    GXSetZCompLoc(GX_FALSE);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetAlphaCompare(GX_GREATER, ref, GX_AOP_AND, GX_ALWAYS, 0);
}

void set_depth_buffer_settings_1() {
    depth_buffer_settings.z_before_tex = 0;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_LEQUAL;
    depth_buffer_settings.z_update = 0;
    depth_buffer_settings.alpha_ref = 0;
    GXSetZCompLoc(GX_FALSE);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    set_material_alpha_compare_reference(0);
}

void set_depth_buffer_settings_3() {
    depth_buffer_settings.alpha_compare = GX_ALWAYS;
    depth_buffer_settings.z_before_tex = 1;
    depth_buffer_settings.z_compare = 1;
    depth_buffer_settings.z_func = GX_LESS;
    depth_buffer_settings.z_update = 1;
    depth_buffer_settings.alpha_ref = 0xBF;
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetZCompLoc(GX_TRUE);
    GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
    set_material_alpha_compare_reference(depth_buffer_settings.alpha_ref);
}

extern "C" void restore_saved_depth_alpha_state(void) {
    depth_buffer_settings.copy(&saved_depth_alpha_scene_state);
    GXSetAlphaCompare((GXCompare)depth_buffer_settings.alpha_compare, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetZCompLoc(depth_buffer_settings.z_before_tex);
    GXSetZMode(depth_buffer_settings.z_compare, (GXCompare)depth_buffer_settings.z_func,
               depth_buffer_settings.z_update);
    set_material_alpha_compare_reference(depth_buffer_settings.alpha_ref);
}

u32 calc_pulse_flash_color(u8 r, u8 g, u8 b, s32 frame, s32 period, s32 start, s32 peak, s32 end) {
    f32 t;
    s32 phase;
    phase = frame % period;
    if (phase < start || phase > end) {
        return 0xFF000000 | (r << 16) | (g << 8) | b;
    }
    if (phase < peak) {
        t = (f32)(phase - start) / (f32)(peak - start);
    } else {
        t = (f32)(end - phase) / (f32)(end - peak);
    }
    r = (f32)(0xFF - r) * t + r;
    g = (f32)(0xFF - g) * t + g;
    b = (f32)(0xFF - b) * t + b;
    return 0xFF000000 | (r << 16) | (g << 8) | b;
}

extern "C" {

s32 TObjMapWarp__sub_80141C68(s32 self, s16 del) {
    if (self != 0 && del > 0) {
        operator delete((void *)self);
    }
    return self;
}

void TObjMapWarp__sub_80141CA4(void *self) { *(s32 *)self = 0; }

// Debug-draw entry points; their bodies are compiled out of the release game.
void debug_draw_line(const Vec *from, const Vec *to, u32 from_color, u32 to_color) {}
void fn_80141CB4(void) {}
void fn_80141CB8(void) {}

void fn_80141CBC(const Vec *pos, const NJS_ARGB *color, f32 size) {
    Vec scale;
    scale.x = size;
    scale.y = size;
    scale.z = size;
    fn_80141CF0(pos, &scale, color);
}

void fn_80141CF0(const Vec *pos, Vec *scale, const NJS_ARGB *color) {}
void debug_draw_sphere(const Vec *pos, const NJS_ARGB *color, f32 radius) {}

f32 horizontal_distance_squared(const Vec *a, const Vec *b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;
    return dx * dx + dz * dz;
}

// Normalizes v and returns 1, or returns 0 when v is (nearly) zero.
s32 normalize_if_nonzero(Vec *v) {
    if (vec_squared_length(v) < 1e-5f * 1e-5f) {
        return 0;
    }
    normalize_vector(v);
    return 1;
}

}

void calc_direction_vector(s32 angle, Vec *out, f32 length) {
    out->x = length * sin_table_lookup(angle);
    out->y = 0.0f;
    out->z = length * cos_table_lookup(angle);
}

void calc_circle_offset_pos(s32 angle, Vec *center, Vec *out, f32 radius) {
    out->x = radius * sin_table_lookup(angle) + center->x;
    out->y = center->y;
    out->z = radius * cos_table_lookup(angle) + center->z;
}

s32 calc_angle_to(Vec *from, Vec *to) {
    return RAD_TO_ANGLE * atan2_float(to->x - from->x, to->z - from->z);
}

extern "C" {

s32 f32_bits(f32 value) {
    union {
        f32 f;
        s32 i;
    } u;
    u.f = value;
    return u.i;
}

f32 bits_to_f32(s32 bits) {
    union {
        f32 f;
        s32 i;
    } u;
    u.i = bits;
    return u.f;
}

}

void set_inverse_alpha_blend() { set_color_blending_mode(0, 5); set_color_blending_mode(1, 6); }

void set_inverse_color_blend() { set_color_blending_mode(0, 5); set_color_blending_mode(1, 7); }

// Ninja's default blending: source alpha over inverse source alpha.
void set_default_alpha_blend() { set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); }

// Source alpha added onto the destination.
void set_additive_blend() { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); }

extern "C" {

s32 angle_difference_abs(s32 a, s32 b) {
    s16 d = (u16)b - (u16)a;
    if (d < 0) {
        d = -d;
    }
    return (u16)d;
}

s16 angle_diff_s16(s32 a, s32 b) {
    return (u16)b - (u16)a;
}

f32 approach_vector_fixed_distance(const Vec *from, const Vec *to, Vec *out, f32 step) {
    Vec d;
    f32 len;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    len = vector_length(&d);
    if (len <= step || 0.0f == len) {
        out->x = to->x;
        out->y = to->y;
        out->z = to->z;
        return 0.0f;
    }
    normalize_vector(&d);
    d.x *= step;
    d.y *= step;
    d.z *= step;
    d.x += from->x;
    d.y += from->y;
    d.z += from->z;
    out->x = d.x;
    out->y = d.y;
    out->z = d.z;
    return len;
}

}

s32 clamp_s32(s32 value, s32 min, s32 max) {
    if (value < min) {
        value = min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

void get_current_date_stamp(DateStamp *out) {
    DateStamp now;
    getDateStamp(&now);
    out->year = now.year;
    out->month = now.month;
    out->day = now.day;
    out->hour = now.hour;
    out->minute = now.minute;
    out->second = now.second;
    out->weekday = now.weekday;
}

void direction_to_rotation_yx(u8 *dir, s32 *rot_a, s32 *rot_b) {
    Vec *v = (Vec *)dir;
    *rot_a = -(s32)(RAD_TO_ANGLE * atan2_float(v->z, v->x));
    *rot_b = RAD_TO_ANGLE * atan2_float(v->y, newton_sqrtf(v->z * v->z + v->x * v->x));
}

void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b) {
    Vec *v = (Vec *)dir;
    *rot_b = -(s32)(RAD_TO_ANGLE * atan2_float(v->x, v->y));
    *rot_a = RAD_TO_ANGLE * atan2_float(v->z, newton_sqrtf(v->x * v->x + v->y * v->y));
}

void direction_to_rotation_xy(u8 *dir, s32 *rot_a, s32 *rot_b) {
    Vec *v = (Vec *)dir;
    *rot_a = -(s32)(RAD_TO_ANGLE * atan2_float(v->y, v->z));
    *rot_b = RAD_TO_ANGLE * atan2_float(v->x, newton_sqrtf(v->y * v->y + v->z * v->z));
}

extern "C" s32 approach_angle_adaptive(s32 from, s32 to) {
    u16 a = from;
    u16 b = to;
    s16 d = b - a;
    s32 step;
    if (d > -0x3000 && d < 0x3000) {
        step = (d >> 1) - (d >> 2);
    } else {
        step = d >> 1;
    }
    return (u16)(a + step);
}

s32 lerp_angle_half(s32 from, s32 to) {
    u16 a = from;
    u16 b = to;
    return (u16)(a + ((s16)(b - a) >> 1));
}

extern "C" s32 approach_angle_limited(s32 from, s32 to, s32 max_step) {
    s16 d = (u16)to - (u16)from;
    s16 out;
    if (d > max_step || d < -max_step) {
        if (d & 0x8000) {
            out = (u16)from - max_step;
        } else {
            out = (u16)from + max_step;
        }
        return (u16)out;
    }
    return (u16)to;
}

void vsub(void *a, void *b, void *out) {
    Vec *va = (Vec *)a;
    Vec *vb = (Vec *)b;
    Vec *vo = (Vec *)out;
    vo->x = vb->x - va->x;
    vo->y = vb->y - va->y;
    vo->z = vb->z - va->z;
}

f32 vec_distance_squared(u8 *a, u8 *b) {
    Vec *va = (Vec *)a;
    Vec *vb = (Vec *)b;
    f32 dx = vb->x - va->x;
    f32 dz = vb->z - va->z;
    return dz * dz + (dx * dx + (vb->y - va->y) * (vb->y - va->y));
}

// The original pools +1e-5f before -1e-5f although it loads -1e-5f first, which no source
// order reproduces here; the two constants are read by address (see render_util_head.cpp).
extern "C" const f32 lbl_805DB15C; // 1e-5f
extern "C" const f32 lbl_805DB160; // -1e-5f

s32 is_near_zero(f32 value) {
    if (lbl_805DB160 < value && value < lbl_805DB15C) {
        return 1;
    }
    return 0;
}

u8 vec_has_nonfinite(Vec *v) {
    s32 result = 0;
    if (TCameraCtrl__sub_8006B370(v->x) != 0 || TCameraCtrl__sub_8006B370(v->y) != 0 ||
        TCameraCtrl__sub_8006B370(v->z) != 0) {
        result = 1;
    }
    return result;
}

void begin_constant_color_draw_argb(void *owner, f32 a, f32 r, f32 g, f32 b) {
    NJS_ARGB color;
    color.a = a;
    color.r = r;
    color.g = g;
    color.b = b;
    set_global_draw_flag_bits(owner, 0x810);
    set_chunk_material_override_pair(-1, 0x800);
    set_constant_material(&color);
}

void begin_constant_color_draw(void *owner, const NJS_ARGB *color) {
    set_global_draw_flag_bits(owner, 0x810);
    set_chunk_material_override_pair(-1, 0x800);
    set_constant_material(color);
}

void begin_constant_color_draw_self(NJS_ARGB *color) {
    set_global_draw_flag_bits(color, 0x810);
    set_chunk_material_override_pair(-1, 0x800);
    set_constant_material(color);
}

void restore_model_draw_state(void *owner) {
    restore_chunk_polygon_masks(owner);
    restore_model_material_color(owner);
    restore_model_render_flags(owner);
}

void save_model_draw_state(void *owner) {
    save_model_render_flags(owner);
    save_model_material_color(owner);
    save_chunk_polygon_masks(owner);
}
