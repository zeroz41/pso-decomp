#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/MenuText.h"
#include "pso/object/warp/TObjWarpString.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/charcreate/TObjCMAssignMenu.h"
#include "pso/unk/TLobby.h"

// Built with -inline off,deferred: .text comes out last function first, so the functions are written
// in reverse address order; the data below stays in source order.

// The player texture list loaded for the title: the Japanese build's, and the English one the other
// languages share (the loader below picks one by current_language).
static NJS_TEXNAME player_tex_eng_texture_names[1] = {  // inferred: from the file name
    { "f256_player_tex_eng", 0, 0 },
};

static NJS_TEXLIST player_tex_eng_texture_list = { player_tex_eng_texture_names, 1 };  // inferred

static NJS_TEXNAME player_tex_texture_names[1] = {  // inferred: from the file name
    { "f256_player_tex", 0, 0 },
};

static NJS_TEXLIST player_tex_texture_list = { player_tex_texture_names, 1 };  // inferred

const char *TAdTitleTexGC__name = "TAdTitleTexGC";

saddr lbl_805D6668;

extern "C" {

void release_texture_list(void*);

extern const s32 current_language;

s32 load_streamed_prs_texture(s32 name, s32 texlist);

void TLobby__sub_802A5154(void) {
    if (lbl_805D6668 != 0U) {
        return;
    }
    TLobby::update_menu_cursor();
    NJS_TEXLIST *lists[5] = {
        &player_tex_texture_list, &player_tex_eng_texture_list, &player_tex_eng_texture_list,
        &player_tex_eng_texture_list, &player_tex_eng_texture_list,
    };
    const char *files[5] = {
        "f256_player_tex", "f256_player_tex_eng", "f256_player_tex_eng", "f256_player_tex_eng", "f256_player_tex_eng",
    };
    s32 list = (saddr)lists[current_language];
    lbl_805D6668 = list;
    load_streamed_prs_texture((saddr)files[current_language], list);
}

void TLobby::free_dialing_gc() {
    if ((u32) lbl_805D6668 != 0U) {
        release_texture_list((void*)lbl_805D6668);
        lbl_805D6668 = 0U;
    }
}

TAdTitleTexGC::TAdTitleTexGC(TObject *parent) : TObject(parent) {
    m_name = TAdTitleTexGC__name;
    alpha = 51;
    frames = -1;
    rects[0].u1 = 0.8203125f;
    rects[0].v1 = 0.3828125f;
    rects[0].u0 = 0.7421875f;
    rects[0].v0 = 0.3046875f;
    rects[1].u0 = 0.828125f;
    rects[1].v0 = 0.3046875f;
    rects[1].u1 = 0.90625f;
    rects[1].v1 = 0.3828125f;
    rest_pos[0].x = 205.0f;
    rest_pos[0].y = 421.0f;
    rest_pos[1].x = 348.0f;
    rest_pos[1].y = 421.0f;
    rest_pos[2].x = 432.0f;
    rest_pos[2].y = 421.0f;
}

TAdTitleTexGC::~TAdTitleTexGC() {}

void TAdTitleTexGC::run_task() {
    u32 faded;

    if (frames < 0x14) {
        frames = frames + 1;
    }
    if (alpha < 0xFFU) {
        alpha = alpha + 0xC;
    }
    faded = alpha;
    alpha = (faded <= 0xFFU) ? faded : 0xFFU;
    update_title_tex_positions();
}

void TAdTitleTexGC::update_title_tex_positions() {
    NJS_POINT2 sp[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 t = 0x14 - frames;
        sp[i].x = ((640.0f - rest_pos[i].x) * (f32)(t * t)) / 400.0f;
        sp[i].y = 0.0f;
        rects[i].x0 = rest_pos[i].x + sp[i].x;
        rects[i].y0 = rest_pos[i].y + sp[i].y;
        rects[i].x1 = 20.0f + rects[i].x0;
        rects[i].y1 = 20.0f + rects[i].y0;
    }
}

void TAdTitleTexGC::render() {
    s32 temp_r31;

    if (TMainTask::get_render_pass() != 1) {
        render_status_pair((alpha << 0x18) | 0xFF0000 | 0xFFFF);
        sub_802A4D74((alpha << 0x18) | 0xFF0000 | 0xFFFF, (u8 *)(get_localized_text_entry(0x28, 0)), (u8 *)(get_localized_text_entry(0x28, 1)));
    }
}

}

void TAdTitleTexGC::render_status_pair(s32 color) {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D6668));
    set_draw_texture_and_color(0, color);
    draw_textured_quad_at_depth(&rects[0].x0, 0.1f);
    TWindowSubStatusDisp::get_player();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D6668));
    set_draw_texture_and_color(0, color);
    draw_textured_quad_at_depth(&rects[1].x0, 0.1f);
    TWindowSubStatusDisp::get_player();
}

#pragma push
#pragma opt_common_subs off
void TAdTitleTexGC::sub_802A4D74(s32 color, u8 *text, u8 *arg3) {
    draw_menu_text(22.0f + rects[0].x0, 1.0f + rects[0].y0, (const char *)text, color);
    draw_menu_text(22.0f + rects[1].x0, 1.0f + rects[1].y0, (const char *)arg3, color);
}
#pragma pop

