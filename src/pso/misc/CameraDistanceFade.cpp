#include "types.h"
#include "pso/misc/CameraDistanceFade.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/render/model_render_state.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/NinjaUtil.h"
#include "pso/unk/text_803DC86C.h"

// The camera controller; no module header owns it yet (its fields are
// still TCameraCtrl's m_178... placeholders, 0x178 is the camera position).
extern u8 *camera_ctrl_instance;

s32 CameraDistanceFade::update_visibility(const Vec *pos) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return 1;
    }
    if (xz_distance_squared((const Vec *)(camera_ctrl_instance + 0x178), pos) < fade_distance * fade_distance) {
        fade_out = 0;
    } else {
        fade_out = 1;
    }
    return is_visible();
}

s32 CameraDistanceFade::is_translucent() {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return 0;
    }
    return color.a < 0.0f;
}

s32 CameraDistanceFade::is_visible() {
    return color.a > -1.0f;
}

void CameraDistanceFade::step_fade() {
    f32 a = color.a;
    if (fade_out == 0) {
        a += 0.04f;
        if (a > 0.0f) a = 0.0f;
    } else {
        a -= 0.04f;
        if (a < -1.0f) a = -1.0f;
    }
    color.a = a;
}

void CameraDistanceFade::reset() {
    fade_out = 1;
    fade_distance = 300.0f;
    reset_obstruction_fade();
}

void CameraDistanceFade::clear_flag_and_notify() {
    copy_argb(&model_material_color, &saved_model_draw_color);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

void CameraDistanceFade::set_flags_and_apply_damage_color() {
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb(&saved_model_draw_color, &model_material_color);
    model_render_flags |= 0x8021;
    set_constant_material(&color);
    set_color_blend_mode(1, 4, 5, 0);
}

CameraDistanceFade::~CameraDistanceFade() {}

CameraDistanceFade::CameraDistanceFade() {
    reset();
}
