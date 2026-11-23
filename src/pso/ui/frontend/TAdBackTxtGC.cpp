#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"


extern "C" {
void begin_screen_draw(s32 mode);
s32 draw_textured_quad_at_depth(void *, f32, f32, f32);
void set_draw_texture_and_color(s32 idx, s32 color);
saddr TAdBackTxtGC__backtext_texture_list;
void TAdBackTxtGC::draw_character_background_frame(s32 arg1, s32 color) {
  f32 buffer_8[8];
  begin_screen_draw(1);
  TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *) TAdBackTxtGC__backtext_texture_list));
  set_draw_texture_and_color(arg1, color);
  buffer_8[0] = 0.0f;
  buffer_8[1] = 0.0f;
  buffer_8[2] = 639.0f;
  buffer_8[3] = 479.0f;
  buffer_8[4] = 0.0f;
  buffer_8[5] = 0.0f;
  buffer_8[7] = (buffer_8[6] = 1.0f);
  draw_textured_quad_at_depth(&buffer_8[0], m_depth, 639.0f, 0.0f);
  TWindowSubStatusDisp::get_player();
}

#pragma readonly_strings on
void TAdBackTxtGC::render() {
    if (m_24 == 0) {
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
    if (m_24 == 0) {
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

extern const char *TAdBackTxtGC__name;

}
TAdBackTxtGC::~TAdBackTxtGC() {

}
extern "C" {

TAdBackTxtGC::TAdBackTxtGC(TObject *parent) : TObject(parent) {
    m_name = TAdBackTxtGC__name;
    frame = -1;
    m_depth = 0.0025641026f;
    m_24 = 1;
}

    struct TexName_804DC098 { const char *name; s32 a; s32 b; };
    struct TexList_804DC0D4 { TexName_804DC098 *list; s32 n; };
    TexName_804DC098 lbl_804DC098[5] = {
        { "f256_backtext01", 0, 0 }, { "f256_backtext02", 0, 0 }, { "f256_backtext03", 0, 0 },
        { "f256_backtext04", 0, 0 }, { "f256_backtext05", 0, 0 },
    };
    __declspec(section ".data") TexList_804DC0D4 TAdBackTxtGC_backtext_tex_list = { lbl_804DC098, 5 };
const char *TAdBackTxtGC__name = "TAdBackTxtGC";
void release_texture_list(void*);

void TAdSinglePlyChrSelectGC::free_singleton_805D65C0() {
    if ((u32) TAdBackTxtGC__backtext_texture_list != 0U) {
        release_texture_list((void*)TAdBackTxtGC__backtext_texture_list);
        TAdBackTxtGC__backtext_texture_list = 0U;
    }
}
void register_texture_f256_backtext(void) { TAdBackTxtGC__backtext_texture_list = (saddr)&TAdBackTxtGC_backtext_tex_list; load_streamed_prs_texture((saddr)"f256_backtext", (saddr)&TAdBackTxtGC_backtext_tex_list); }

}
