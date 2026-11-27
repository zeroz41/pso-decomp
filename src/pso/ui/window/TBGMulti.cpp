#include "pso/system/memory.h"
#include "pso/render/GinjaTextureHeader.h"
#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/render/render_util.h"

#include "pso/ui/window/TWindowCtrlMain.h"
#include <stddef.h>
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResource.h"

NJS_TEXLIST *bg_multi_textures;
s32 split_screen_hud_animation_frame;

void draw_split_screen_dividers() {
    ColorLineVertex verts[4];
    ColorLineList d;
    u32 cols[4];
    d.verts = verts;
    d.colors = cols;
    d.tex = NULL;
    d.count = 4;
    d.verts[0].x = (1.6e+02f);
    d.verts[0].y = (2.4e+02f);
    d.colors[0] = 0xFF000000;
    d.verts[1].x = (4.8e+02f);
    d.verts[1].y = (2.4e+02f);
    d.colors[1] = 0xFF000000;
    d.verts[2].x = (4.8e+02f);
    d.verts[2].y = (4.8e+02f);
    d.colors[2] = 0xFF000000;
    d.verts[3].x = (1.6e+02f);
    d.verts[3].y = (4.8e+02f);
    d.colors[3] = 0xFF000000;
    d.draw_strip_swap_color(4, 0x16, (-2.0f));
    d.verts[0].x = (0.0f);
    d.verts[0].y = (0.0f);
    d.verts[1].x = (6.4e+02f);
    d.verts[1].y = (0.0f);
    d.verts[2].x = (6.4e+02f);
    d.verts[2].y = (2.4e+02f);
    d.verts[3].x = (0.0f);
    d.verts[3].y = (2.4e+02f);
    d.draw_strip_swap_color(4, 0x16, (-2.0f));
}

void draw_tiled_background() {
    s32 i;
    s32 j;
    f32 buf[8];
    begin_screen_draw(1);
    set_texture_list(bg_multi_textures);
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
    end_screen_draw();
}

#pragma push
#pragma fp_contract on
void draw_scanline_sweep() {
    s32 i;
    f32 buf[8];
    if (split_screen_hud_animation_frame <= 0x1E) {
        set_additive_blend();
        begin_screen_draw(1);
        set_texture_list(bg_multi_textures);
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
        end_screen_draw();
        set_default_alpha_blend();
    }
}
#pragma pop

void draw_bottom_bar() {
  s32 i;
  f32 buffer_8[8];
  begin_screen_draw(1);
  set_texture_list(bg_multi_textures);
  set_draw_texture_and_color(0, -1);
  i = 0;
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
    i += 1;
    buffer_8[0] += (64.0f);
    buffer_8[2] += (64.0f);
  }
  while (i < 0xA);
  end_screen_draw();
}
void draw_split_screen_hud() {
    s32 frame;
    if (bg_multi_textures != NULL) {
        set_depth_buffer_settings_2();
        set_default_alpha_blend();
        begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        draw_bottom_bar();
        draw_scanline_sweep();
        draw_tiled_background();
        draw_split_screen_dividers();
        TCameraCtrl::restore_saved_view();
        end_effect_render();
        restore_saved_depth_alpha_state();
        frame = split_screen_hud_animation_frame;
        split_screen_hud_animation_frame = frame + 1;
        if (frame > 0x708) {
            split_screen_hud_animation_frame = 0;
        }
    }
}

#pragma readonly_strings on
#pragma pool_data off
extern s32 split_screen_hud_animation_frame;

void release_bg_multi_textures() {
    if (bg_multi_textures != NULL) {
        release_texture_list(bg_multi_textures);
        safe_free(bg_multi_textures);
        bg_multi_textures = NULL;
    }
}
void load_bg_multi_textures() {
    GvplPalette palette;
    if (TCameraCtrl::get_camera_id() == 3) {
        palette.data = tmp_buf_use_req("TBGMulti");
        TLanguage::load_palette_tlut("f128_gr.gvp", &palette, 0x4D);
        tmp_buf_release("TBGMulti");
        set_texture_list(bg_multi_textures = LoadPvmFileTls("bg_multi.gvm"));
        set_context_texture_palette_bank(0, 0x4D);
    }
    split_screen_hud_animation_frame = 0x384;
}
