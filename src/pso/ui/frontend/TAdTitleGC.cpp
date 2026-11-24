#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/text_802A0A30.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/unk/text_802A1020.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

// The title banner textures: English (lbl_804DCA60/78) and Japanese (lbl_804DCA80/98) name lists and texlists.
NJS_TEXNAME lbl_804DCA60[2] = { { "f512_midashi_eng", 0, 0 }, { "f512_midashi_eng_b", 0, 0 } };
NJS_TEXLIST lbl_804DCA78 = { lbl_804DCA60, 2 };
NJS_TEXNAME lbl_804DCA80[2] = { { "f512_midashi", 0, 0 }, { "f512_midashi_b", 0, 0 } };
NJS_TEXLIST lbl_804DCA98 = { lbl_804DCA80, 2 };

const char *ad_title_gc_class_name = "TAdTitleGC";

extern "C" {
u32 calc_text_width(char *s);
s32 get_player__20TWindowSubStatusDispFv();
uaddr lbl_805D6630;
saddr get_localized_text_entry(s32, s32);
void restore_saved_depth_alpha_state(void);

// The title texture helpers. The TU is compiled deferred, so its functions come out backwards:
// these are written first and land last.
extern const s32 current_language;
void release_texture_list(void*);
}

int game_files_modified() { return game_files_modified_flag; }

extern "C" {
void TLobby__sub_802A0F70(void) {
    TLobby::update_menu_cursor();
    const char *names[5] = { "f512_midashi", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng" };
    NJS_TEXLIST *lists[5] = { &lbl_804DCA98, &lbl_804DCA78, &lbl_804DCA78, &lbl_804DCA78, &lbl_804DCA78 };
    lbl_805D6630 = (uaddr)lists[current_language];
    load_streamed_prs_texture((saddr)names[current_language], (saddr)lists[current_language]);
}

void TLobby::free_dialog_global() {
    if ((u32) lbl_805D6630 != 0U) {
        release_texture_list((void*)lbl_805D6630);
        lbl_805D6630 = 0U;
    }
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
    draw_line_ctrl = create_draw_line_ctrl((TObject *)this, 8, 0.0f);
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
        goto block_5;
    }
    if ((s32)this->defer_render() == 0) {
        set_depth_buffer_settings_2();
block_5:
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
}

s32 TAdTitleGC::draw_title_layer(s32 arg1, s32 color) {
    s32 i;
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D6630));
    set_draw_texture_and_color(arg1 > 0xB, color);
    for (i = 0; i < 8; i++) {
        draw_textured_quad_at_depth(&rects[i].x0, (-1.0f) / -((113.0f) - (f32)i));
    }
    return get_player__20TWindowSubStatusDispFv();
}
