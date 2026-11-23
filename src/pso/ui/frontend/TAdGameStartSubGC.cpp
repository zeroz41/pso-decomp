#include "pso/ui/frontend/TAdGameStartSubGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

__declspec(section ".rodata") extern const char TAdGameStartSubGC__class_name_string[] = "TAdGameStartSubGC";
extern void *lbl_805D3FB0[2];

#pragma push
#pragma fp_contract on

s32 game_start_player_instance;

void TAdGameStartSubGC::draw_background() {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(game_start_player_instance));
    set_draw_texture_and_color(0, ((m_alpha << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth(&m_quad.x0, 0.01f * (f32)m_cell + 0.8f);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TAdGameStartSubGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_background(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }
#pragma push
#pragma fp_contract on
void TAdGameStartSubGC::run_task() {
    f32 center;
    s32 frame;
    s32 alpha;
    m_frame = (s32) (m_frame + 1);
    frame = m_frame;
    if (frame < 4) {
        m_scale_x = (f32) ((3.0f) - ((0.6666667f) * (f32) frame));
        m_scale_y = (f32) ((3.0f) - ((0.6666667f) * (f32) m_frame));
    } else if (frame > 0x1C) {
        m_scale_x = (f32) ((1.0f) - ((-0.6666667f) * (frame - 0x1D)));
        m_scale_y = (f32) ((1.0f) - ((-0.6666667f) * (f32) (m_frame - 0x1D)));
        if ((s32) m_frame > 0x1D) {
            m_alpha = (s32) (m_alpha - 0x55);
        }
        alpha = m_alpha;
        if (alpha < 0) {
            alpha = 0;
        }
        m_alpha = alpha;
    }
    center = m_center_x;
    m_quad.x0 = (f32) ((m_scale_x * (m_rest.x0 - center)) + center);
    center = m_center_y;
    m_quad.y0 = (f32) ((m_scale_y * (m_rest.y0 - center)) + center);
    center = m_center_x;
    m_quad.x1 = (f32) ((m_scale_x * (m_rest.x1 - center)) + center);
    center = m_center_y;
    m_quad.y1 = (f32) ((m_scale_y * (m_rest.y1 - center)) + center);
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdGameStartSubGC::~TAdGameStartSubGC() {}
TAdGameStartSubGC::TAdGameStartSubGC(TObject *parent, GameStartLetterLayout *layout) : TObject(parent) {
    s32 color;
    m_name = (const char *)lbl_805D3FB0[0];
    m_cell = layout->cell;
    copy_vec2(&m_origin, &layout->x);
    color = layout->color;
    m_color = color;
    m_frame = -1;
    m_scale_x = (3.0f);
    m_scale_y = (3.0f);
    m_alpha = 0xFF;
    game_start_player_instance = TObjPlayer::get_instance();
    m_rest.x0 = (64.0f) * (f32)m_cell + m_origin.x;
    m_rest.y0 = m_origin.y;
    m_rest.x1 = (64.0f) * (f32)(m_cell + 1) + m_origin.x;
    m_rest.y1 = (128.0f) + m_origin.y;
    m_center_x = (0.5f) * (m_rest.x1 - m_rest.x0) + m_rest.x0;
    m_center_y = (0.5f) * (m_rest.y1 - m_rest.y0) + m_rest.y0;
    m_quad.u0 = (64.0f) * (f32)m_cell / 512.0f;
    m_quad.v0 = (0.0f);
    m_quad.u1 = ((64.0f) * (f32)(m_cell + 1) - (1.0f)) / 512.0f;
    m_quad.v1 = (0.25f);
}
#pragma pop

void *lbl_805D3FB0[2] = {(void *)TAdGameStartSubGC__class_name_string, 0};
