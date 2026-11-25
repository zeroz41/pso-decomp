#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"


NJS_TEXLIST *TAdBackTxtGC::backtext_texture_list;

void TAdBackTxtGC::draw_character_background_frame(s32 texture_index, s32 color) {
    f32 quad[8];
    begin_screen_draw(1);
    TObjFish::set_global_param(backtext_texture_list);
    set_draw_texture_and_color(texture_index, color);
    quad[0] = 0.0f;
    quad[1] = 0.0f;
    quad[2] = 639.0f;
    quad[3] = 479.0f;
    quad[4] = 0.0f;
    quad[5] = 0.0f;
    quad[6] = 1.0f;
    quad[7] = 1.0f;
    draw_textured_quad_at_depth(quad, m_depth);
    TWindowSubStatusDisp::get_player();
}

void TAdBackTxtGC::render() {
    if (render_direct == 0) {
        if (defer_render() != 0) {
            return;
        }
        set_depth_buffer_settings_2();
    } else if (TMainTask::get_render_pass() == 1) {
        return;
    }
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 0xA);
    draw_character_background_frame(frame / 3, -1);
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    if (render_direct == 0) {
        restore_saved_depth_alpha_state();
    }
}

void TAdBackTxtGC::run_task() {
    if (frame >= 0xE) {
        frame = 0;
        return;
    }
    frame = frame + 1;
}

TAdBackTxtGC::~TAdBackTxtGC() {

}

TAdBackTxtGC::TAdBackTxtGC(TObject *parent) : TObject(parent) {
    m_name = TAdBackTxtGC::name;
    frame = -1;
    m_depth = 0.0025641026f;
    render_direct = 1;
}

#pragma readonly_strings on
NJS_TEXNAME TAdBackTxtGC_backtext_tex_names[5] = {
    { "f256_backtext01", 0, 0 }, { "f256_backtext02", 0, 0 }, { "f256_backtext03", 0, 0 },
    { "f256_backtext04", 0, 0 }, { "f256_backtext05", 0, 0 },
};
__declspec(section ".data") NJS_TEXLIST TAdBackTxtGC_backtext_tex_list = { TAdBackTxtGC_backtext_tex_names, 5 };
const char *TAdBackTxtGC::name = "TAdBackTxtGC";

void TAdSinglePlyChrSelectGC::free_singleton_805D65C0() {
    if (TAdBackTxtGC::backtext_texture_list != NULL) {
        release_texture_list(TAdBackTxtGC::backtext_texture_list);
        TAdBackTxtGC::backtext_texture_list = NULL;
    }
}
void register_texture_f256_backtext(void) { TAdBackTxtGC::backtext_texture_list = &TAdBackTxtGC_backtext_tex_list; load_streamed_prs_texture("f256_backtext", &TAdBackTxtGC_backtext_tex_list); }

