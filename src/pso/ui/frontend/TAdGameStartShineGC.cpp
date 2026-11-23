#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdGameStartShineGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

#pragma readonly_strings on

s32 lbl_805D6E88;

void TAdGameStartShineGC::render_status_box() {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D6E88));
    set_draw_texture_and_color(0, ((m_alpha << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth(&m_quad.x0, 0.899f);
    TWindowSubStatusDisp::get_player();
}

// Shine quad origin and extent the constructor lays the quad out from.
static const vec2f game_start_shine_origin = {94.0f, 196.0f};
static const vec2f game_start_shine_extent = {512.0f, 128.0f};
const char *lbl_805D4320 = "TAdGameStartShineGC";

void TAdGameStartShineGC::render() {
    if ((TMainTask::get_render_pass() != 1) && ((s32) m_visible != 0)) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        render_status_box();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}
#pragma push
#pragma fp_contract on
void TAdGameStartShineGC::run_task() {
    f32 center;
    s32 frame;
    s32 alpha;
    frame = m_frame;
    m_frame = (frame + 1);
    if (frame >= 0xA) {
        m_visible = 1;
        m_alpha = (s32) (m_alpha - 0xE);
        alpha = m_alpha;
        if (alpha < 0) {
            alpha = 0;
        }
        m_alpha = alpha;
        m_scale_x = 1.0f - -0.011111114f * (f32) (m_frame - 0xB);
        m_scale_y = 1.0f;
        center = m_center_x;
        m_quad.x0 = (f32) ((m_scale_x * (m_rest_x0 - center)) + center);
        center = m_center_y;
        m_quad.y0 = (f32) ((m_scale_y * (m_rest_y0 - center)) + center);
        center = m_center_x;
        m_quad.x1 = (f32) ((m_scale_x * (m_rest_x1 - center)) + center);
        center = m_center_y;
        m_quad.y1 = (f32) ((m_scale_y * (m_rest_y1 - center)) + center);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdGameStartShineGC::~TAdGameStartShineGC() {}
TAdGameStartShineGC::TAdGameStartShineGC(TObject *parent) : TObject(parent) {
    m_name = lbl_805D4320;
    m_scale_x = 1.0f;
    m_scale_y = 1.0f;
    copy_vec2(&m_origin, (void *)&game_start_shine_origin);
    m_rest_x0 = m_origin.x;
    m_rest_y0 = m_origin.y;
    m_rest_x1 = m_origin.x + game_start_shine_extent.x;
    m_rest_y1 = m_origin.y + game_start_shine_extent.y;
    m_quad.u0 = 0.0f;
    m_quad.v0 = 0.0f;
    m_quad.u1 = 1.0f;
    m_quad.v1 = 0.25f;
    m_center_x = 0.5f * (m_rest_x1 - m_rest_x0) + m_rest_x0;
    m_center_y = 0.5f * (m_rest_y1 - m_rest_y0) + m_rest_y0;
    m_alpha = 0xFF;
    m_frame = -1;
    m_visible = 0;
    lbl_805D6E88 = TObjPlayer::get_instance();
}
#pragma pop
