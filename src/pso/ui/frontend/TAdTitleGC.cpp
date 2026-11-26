#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/text_802A0A30.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/TextureState.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/ui/frontend/OpeningMovie.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/network/TLobby.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaTexture.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

// The title banner textures: English (title_midashi_texnames_eng/78) and Japanese (title_midashi_texnames/98) name lists and texlists.
NJS_TEXNAME title_midashi_texnames_eng[2] = { { "f512_midashi_eng", 0, 0 }, { "f512_midashi_eng_b", 0, 0 } };
NJS_TEXLIST title_midashi_texlist_eng = { title_midashi_texnames_eng, 2 };
NJS_TEXNAME title_midashi_texnames[2] = { { "f512_midashi", 0, 0 }, { "f512_midashi_b", 0, 0 } };
NJS_TEXLIST title_midashi_texlist = { title_midashi_texnames, 2 };

const char *ad_title_gc_class_name = "TAdTitleGC";

extern "C" {
uaddr title_midashi_texlist_current;

// The title texture helpers. The TU is compiled deferred, so its functions come out backwards:
// these are written first and land last.
extern const s32 current_language;
}

int game_files_modified() { return game_files_modified_flag; }

void load_title_midashi_texture() {
    TLobby::update_menu_cursor();
    const char *names[5] = { "f512_midashi", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng" };
    NJS_TEXLIST *lists[5] = { &title_midashi_texlist, &title_midashi_texlist_eng, &title_midashi_texlist_eng, &title_midashi_texlist_eng, &title_midashi_texlist_eng };
    title_midashi_texlist_current = (uaddr)lists[current_language];
    load_streamed_prs_texture(names[current_language], lists[current_language]);
}

void free_title_midashi_texture() {
    if ((u32) title_midashi_texlist_current != 0U) {
        release_texture_list((NJS_TEXLIST *)title_midashi_texlist_current);
        title_midashi_texlist_current = 0U;
    }
}


#pragma push
#pragma opt_common_subs off
TAdTitleGC::TAdTitleGC(TObject *parent, s32 idx) : TObject(parent) {
    s32 off;
    s32 i;
    m_name = ad_title_gc_class_name;
    title = idx;
    frames = -1;
    alpha = 0;
    render_direct = 1;
    draw_line_ctrl = NULL;
    off = (title > 11) ? -12 : 0;
    for (i = 0; i < 8; i++) {
        rects[i].u0 = (0.0f);
        rects[i].v0 = (4e+01f) * (f32)(title + off) / 512.0f;
        rects[i].u1 = 1.0f;
        rects[i].v1 = (4e+01f) * (f32)(title + off + 1) / 512.0f;
    }
    draw_line_ctrl = create_draw_line_ctrl(this, 8, 0.0f);
}

TAdTitleGC::~TAdTitleGC() {}
#pragma pop


void TAdTitleGC::run_task() {
    if (frames < 0xA) {
        frames = frames + 1;
    }
    alpha = alpha + 0xC;
    if (alpha > 0xFF) {
        alpha = 0xFF;
    }
    update_title_rects();
    calc_text_pos(text_pos, (const char *)get_localized_text_entry(0x13, title));
}

// Per-rect slide-in factor update_title_rects scales the remaining frames by.
const f32 title_rect_scale_table[8] = { 1.0f, 0.8f, 0.6f, 0.4f, -1.0f, -0.8f, -0.6f, -0.4f };

s32 TAdTitleGC::update_title_rects() {
    s32 i;
    for (i = 0; i < 8; i++) {
        rects[i].x0 = (64.0f) - ((f32)(10 - frames) * ((f32)(10 - frames) * title_rect_scale_table[i]));
        rects[i].y0 = (43.0f);
        rects[i].x1 = (512.0f) + rects[i].x0;
        rects[i].y1 = (4e+01f) + rects[i].y0;
    }
    return (saddr)this;
}

#pragma push
#pragma fp_contract on
void TAdTitleGC::calc_text_pos(f32 *pos, const char *text) {
    pos[0] = (f32) ((6.2e+02f) - (f32) calc_text_width((char *)text));
    pos[1] = 86.0f;
}
#pragma pop

void TAdTitleGC::render() {
    if (render_direct == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
    } else {
        if ((s32)this->defer_render() != 0) {
            return;
        }
        set_depth_buffer_settings_2();
    }
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 0xA);
    draw_title_layer(title, 0x1FFFFFFF);
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    fn_802A0A30((saddr)this, (u8 *)text_pos, title, (alpha << 0x18) | 0xFF0000 | 0xFFFF, get_localized_text_entry(0x13, title));
    if (render_direct == 0) {
        restore_saved_depth_alpha_state();
    }
}

void TAdTitleGC::draw_title_layer(s32 layer, s32 color) {
    s32 i;
    begin_screen_draw(1);
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(title_midashi_texlist_current));
    set_draw_texture_and_color(layer > 0xB, color);
    for (i = 0; i < 8; i++) {
        draw_textured_quad_at_depth(&rects[i].x0, (-1.0f) / -((113.0f) - (f32)i));
    }
    end_screen_draw();
}
