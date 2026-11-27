#include "pso/ui/frontend/TAdGameStartBackGC.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/render/render_util.h"

#pragma readonly_strings on

const char *TAdGameStartBackGC::class_name = "TAdGameStartBackGC";
s32 game_start_background_texture_list;

void TAdGameStartBackGC::render_background_status() {
    begin_screen_draw(1);
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(game_start_background_texture_list));
    set_draw_texture_and_color(0, ((m_alpha << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth(&m_quad.x0, 0.79f);
    end_screen_draw();
}

void TAdGameStartBackGC::render() { if (TMainTask::get_render_pass() != 1) { set_additive_blend(); render_background_status(); set_default_alpha_blend(); } }

#pragma push
#pragma fp_contract on

#pragma push
#pragma fp_contract on
void TAdGameStartBackGC::run_task() {
    f32 center;
    s32 frame;
    s32 alpha;
    m_frame = m_frame + 1;
    frame = m_frame;
    if (frame < 0xA) {
        m_scale_x = 5.0f - 0.4f * (f32)frame;
        m_scale_y = 5.0f - 0.4f * (f32)m_frame;
    } else if (frame > 0x1C) {
        m_alpha = m_alpha - 0x19;
        alpha = m_alpha;
        if (alpha < 0) {
            alpha = 0;
        }
        m_alpha = alpha;
    }
    center = m_center_x;
    m_quad.x0 = (m_scale_x * (m_rest.x0 - center)) + center;
    center = m_center_y;
    m_quad.y0 = (m_scale_y * (m_rest.y0 - center)) + center;
    center = m_center_x;
    m_quad.x1 = (m_scale_x * (m_rest.x1 - center)) + center;
    center = m_center_y;
    m_quad.y1 = (m_scale_y * (m_rest.y1 - center)) + center;
}
#pragma pop

TAdGameStartBackGC::~TAdGameStartBackGC() {}
TAdGameStartBackGC::TAdGameStartBackGC(TObject *parent) : TObject(parent) {
    m_name = TAdGameStartBackGC::class_name;
    m_origin.x = 106.0f;
    m_origin.y = 192.0f;
    m_alpha = 0xFF;
    m_frame = -1;
    m_scale_x = 5.0f;
    m_scale_y = 5.0f;
    game_start_background_texture_list = get_multiplay_texture_list();
    m_rest.x0 = m_origin.x;
    m_rest.y0 = m_origin.y;
    m_rest.x1 = 512.0f + m_origin.x;
    m_rest.y1 = 128.0f + m_origin.y;
    m_center_x = (0.5f * (m_rest.x1 - m_rest.x0)) + m_rest.x0;
    m_center_y = (0.5f * (m_rest.y1 - m_rest.y0)) + m_rest.y0;
    m_quad.u0 = 0.0f;
    m_quad.v0 = 0.25f;
    m_quad.u1 = 1.0f;
    m_quad.v1 = 0.5f;
}
#pragma pop
