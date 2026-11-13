#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_8036D774.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/render_util.h"

#include "pso/ui/window/TWindowCtrlMain.h"
#include <stddef.h>
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Desc_8036D774 { f32 *pos; u32 *col; s32 a; s32 n; };

extern "C" {
extern s32 TBGMulti__textures;
s32 TCameraCtrl__sub_80068EF0();
extern s32 split_screen_hud_animation_frame;

void TWindowSubStatusDisp::draw_split_screen_dividers() {
    f32 verts[8];
    Desc_8036D774 d;
    u32 cols[4];
    d.pos = verts;
    d.col = cols;
    d.a = 0;
    d.n = 4;
    d.pos[0] = (1.6e+02f);
    d.pos[1] = (2.4e+02f);
    d.col[0] = 0xFF000000;
    d.pos[2] = (4.8e+02f);
    d.pos[3] = (2.4e+02f);
    d.col[1] = 0xFF000000;
    d.pos[4] = (4.8e+02f);
    d.pos[5] = (4.8e+02f);
    d.col[2] = 0xFF000000;
    d.pos[6] = (1.6e+02f);
    d.pos[7] = (4.8e+02f);
    d.col[3] = 0xFF000000;
    ((TWindowCtrlMain *)(&d))->draw_strip_swap_color(4, 0x16, (-2.0f));
    d.pos[0] = (0.0f);
    d.pos[1] = (0.0f);
    d.pos[2] = (6.4e+02f);
    d.pos[3] = (0.0f);
    d.pos[4] = (6.4e+02f);
    d.pos[5] = (2.4e+02f);
    d.pos[6] = (0.0f);
    d.pos[7] = (2.4e+02f);
    ((TWindowCtrlMain *)(&d))->draw_strip_swap_color(4, 0x16, (-2.0f));
}

void TWindowSubStatusDisp::draw_tiled_background() {
    s32 i;
    s32 j;
    f32 buf[8];
    begin_screen_draw(1);
    TObjFish::set_global_param(TBGMulti__textures);
    set_draw_texture_and_color(0, -1);
    i = 0;
    buf[4] = 0.5f;
    buf[5] = 0.0f;
    buf[6] = 1.0f;
    buf[7] = 0.5f;
    buf[0] = 0.0f;
    buf[2] = 64.0f;
    do {
        buf[1] = 192.0f;
        j = 0;
        buf[3] = 256.0f;
        do {
            draw_textured_quad_at_depth(buf, 0.5f);
            j++;
            buf[1] += 64.0f;
            buf[3] += 64.0f;
        } while (j < 5);
        i++;
        buf[0] += 64.0f;
        buf[2] += 64.0f;
    } while (i < 10);
    TWindowSubStatusDisp::get_player();
}

#pragma push
#pragma fp_contract on
void TWindowSubStatusDisp__sub_8036D994(void) {
    s32 i;
    f32 buf[8];
    if (split_screen_hud_animation_frame <= 0x1E) {
        set_additive_blend();
        begin_screen_draw(1);
        TObjFish::set_global_param(TBGMulti__textures);
        set_draw_texture_and_color(0, -1);
        i = 0;
        buf[0] = 0.0f;
        buf[1] = 10.133333f * split_screen_hud_animation_frame + 176.0f;
        buf[2] = 64.0f;
        buf[3] = buf[1] + 64.0f;
        buf[4] = 0.5f;
        buf[5] = 0.5f;
        buf[6] = 1.0f;
        buf[7] = 1.0f;
        do {
            draw_textured_quad_at_depth(buf, 0.5f);
            i++;
            buf[0] += 64.0f;
            buf[2] += 64.0f;
        } while (i < 10);
        TWindowSubStatusDisp::get_player();
        set_default_alpha_blend();
    }
}
#pragma pop

void TWindowSubStatusDisp::draw_bottom_bar() {
  s32 var_r31;
  f32 buffer_8[8];
  f32 temp_f31;
  begin_screen_draw(1);
  TObjFish::set_global_param((s32)((void *) TBGMulti__textures));
  set_draw_texture_and_color(0, -1);
  var_r31 = 0;
  ;
  buffer_8[0] = (0.0f);
  buffer_8[1] = (352.0f);
  buffer_8[2] = (64.0f);
  buffer_8[3] = (4.8e+02f);
  buffer_8[4] = (0.0f);
  buffer_8[5] = (0.0f);
  buffer_8[6] = (0.5f);
  buffer_8[7] = (1.0f);
  do
  {
    draw_textured_quad_at_depth((&buffer_8[0]), (f32) (0.5f));
    var_r31 += 1;
    buffer_8[0] += (64.0f);
    buffer_8[2] += (64.0f);
  }
  while (var_r31 < 0xA);
  TWindowSubStatusDisp::get_player();
}
void TWindowSubStatusDisp::draw_split_screen_hud() {
    s32 var_r3;
    if ((u32) (*(u32 *)&TBGMulti__textures) != 0U) {
        set_depth_buffer_settings_2();
        set_default_alpha_blend();
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        TWindowSubStatusDisp::draw_bottom_bar();
        TWindowSubStatusDisp__sub_8036D994();
        TWindowSubStatusDisp::draw_tiled_background();
        TWindowSubStatusDisp::draw_split_screen_dividers();
        TCameraCtrl__sub_80068EF0();
        TParticleCtrl::end_effect_render();
        restore_saved_depth_alpha_state();
        var_r3 = split_screen_hud_animation_frame;
        split_screen_hud_animation_frame = var_r3 + 1;
        if (var_r3 > 0x708) {
            split_screen_hud_animation_frame = 0;
        }
    }
}

}

#pragma readonly_strings on
#pragma pool_data off

extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
void set_global_param__8TObjFishFl();
extern s32 split_screen_hud_animation_frame;
s32 release_texture_list(void*);

void TLobby::free_singleton_805D7018() {
    if ((u32) TBGMulti__textures != 0U) {
        release_texture_list((void*)TBGMulti__textures);
        TAdSinglePlyChrSelectGC::safe_free(TBGMulti__textures);
        TBGMulti__textures = 0U;
    }
}
void TBGMulti__ct(void) {
    s32 sp8[4];
    if (TCameraCtrl::get_camera_id() == 3) {
        sp8[0] = TLobby::tmp_buf_use_req("TBGMulti");
        TLanguage::draw_string((void *)"f128_gr.gvp", sp8, 0x4D);
        TLobby::tmp_buf_release("TBGMulti");
        (*(s32 *)&TBGMulti__textures) = (s32)load_gvm_texture_file((s32)"bg_multi.gvm");
        set_global_param__8TObjFishFl();
        TLanguage::set_entry_index(0, 0x4D);
    }
    split_screen_hud_animation_frame = 0x384;
}

}
