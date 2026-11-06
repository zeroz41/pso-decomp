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
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, f32, f32, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern s32 TAdBackTxtGC__backtext_texture_list;
void TAdBackTxtGC::draw_character_background_frame(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
  f32 buffer_8[8];
  begin_screen_draw(1);
  TObjFish::set_global_param((s32)((void *) TAdBackTxtGC__backtext_texture_list));
  set_draw_texture_and_color(arg1, arg2);
  buffer_8[0] = 0.0f;
  buffer_8[1] = 0.0f;
  buffer_8[2] = 639.0f;
  buffer_8[3] = 479.0f;
  buffer_8[4] = 0.0f;
  buffer_8[5] = 0.0f;
  buffer_8[7] = (buffer_8[6] = 1.0f);
  draw_textured_quad_at_depth(&buffer_8[0], (f32) (*((f32 *) (((s8 *) arg0) + 0x20))), 639.0f, 0.0f);
  TWindowSubStatusDisp::get_player();
}

}

#pragma readonly_strings on

extern "C" {

void __ct__7TObjectFP7TObject(void *);
s32 defer_render__7TObjectFv();

void render__12TAdBackTxtGCFv(TAdBackTxtGC *ad_back_txt_gc) {
    if ((s32) *(s32 *)((s8 *)ad_back_txt_gc + 0x24) == 0) {
        if (defer_render__7TObjectFv() == 0) {
            set_depth_buffer_settings_2();
            goto block_4;
        }
    } else if (TMainTask::get_render_pass() != 1) {
block_4:
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        ad_back_txt_gc->draw_character_background_frame((s32) *(s32 *)((s8 *)ad_back_txt_gc + 0x1C) / 3, -1);
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        if ((s32) *(s32 *)((s8 *)ad_back_txt_gc + 0x24) == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

void run_task__12TAdBackTxtGCFv(void *arg0) {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x1C);
    if (temp_r4 >= 0xE) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = (temp_r4 + 1);
}

extern void *__vt__12TAdBackTxtGC[];
extern const char *TAdBackTxtGC__name;

}
TAdBackTxtGC::~TAdBackTxtGC() {

}
extern "C" {

void *__ct__12TAdBackTxtGCFv(void *ad_back_txt_gc) {
    __ct__7TObjectFP7TObject(ad_back_txt_gc);
    *(void ***)((s8 *)ad_back_txt_gc + 0x18) = __vt__12TAdBackTxtGC;
    ((TAdBackTxtGC *)ad_back_txt_gc)->m_name = TAdBackTxtGC__name;
    *(u32 *)((s8 *)ad_back_txt_gc + 0x1C) = -1;
    *(f32 *)((s8 *)ad_back_txt_gc + 0x20) = 0.0025641026f;
    *(u32 *)((s8 *)ad_back_txt_gc + 0x24) = 1;
    return ad_back_txt_gc;
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
void register_texture_f256_backtext(void) { (*(int *)&TAdBackTxtGC__backtext_texture_list) = (int)&TAdBackTxtGC_backtext_tex_list; TLobby__sub_8023E4B4((s32)"f256_backtext", (s32)&TAdBackTxtGC_backtext_tex_list); }

}
