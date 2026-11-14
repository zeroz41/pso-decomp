#include "pso/ui/frontend/TAdTitleTexGC.h"
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
    { (void *)"f256_player_tex_eng", 0, 0 },
};

static NJS_TEXLIST player_tex_eng_texture_list = { player_tex_eng_texture_names, 1 };  // inferred

static NJS_TEXNAME player_tex_texture_names[1] = {  // inferred: from the file name
    { (void *)"f256_player_tex", 0, 0 },
};

static NJS_TEXLIST player_tex_texture_list = { player_tex_texture_names, 1 };  // inferred

const char *TAdTitleTexGC__name = "TAdTitleTexGC";

extern s32 lbl_805D6668;

struct V_802A4EF4 { f32 x, y; };

struct B_802A4EF4 {
    f32 x, y, x2, y2;
    u8 pad[0x10];
};

struct Obj_802A4EF4 {
    u8 pad[0x1C];
    B_802A4EF4 b[3];
    u8 pad7C[4];
    s32 f80;
    V_802A4EF4 a[3];
};

extern "C" {

void update_title_tex_positions__13TAdTitleTexGCFPv(Obj_802A4EF4 *arg0);

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__13TAdTitleTexGC[];

void release_texture_list(void*);

extern const s32 current_language;

void TLobby__sub_8023E4B4(s32, s32);

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
    s32 list = (s32)lists[current_language];
    lbl_805D6668 = list;
    TLobby__sub_8023E4B4((s32)files[current_language], list);
}

void TLobby::free_dialing_gc() {
    if ((u32) lbl_805D6668 != 0U) {
        release_texture_list((void*)lbl_805D6668);
        lbl_805D6668 = 0U;
    }
}

void *__ct__13TAdTitleTexGCFv(void *ad_title_tex_gc) {
    __ct__7TObjectFP7TObject(ad_title_tex_gc);
    *(s32 **)((s8 *)ad_title_tex_gc + 0x18) = __vt__13TAdTitleTexGC;
    ((TAdTitleTexGC *)ad_title_tex_gc)->m_name = TAdTitleTexGC__name;
    *(u32 *)((s8 *)ad_title_tex_gc + 0x7C) = 51;
    *(u32 *)((s8 *)ad_title_tex_gc + 0x80) = -1;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x34) = 0.8203125f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x38) = 0.3828125f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x2C) = 0.7421875f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x30) = 0.3046875f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x4C) = 0.828125f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x50) = 0.3046875f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x54) = 0.90625f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x58) = 0.3828125f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x84) = 205.0f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x88) = 421.0f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x8C) = 348.0f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x90) = 421.0f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x94) = 432.0f;
    *(f32 *)((s8 *)ad_title_tex_gc + 0x98) = 421.0f;
    return ad_title_tex_gc;
}

TAdTitleTexGC::~TAdTitleTexGC() {}

void TAdTitleTexGC::run_task() {
    s32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;

    temp_r4 = *(s32 *)((s8 *)this + 0x80);
    if (temp_r4 < 0x14) {
        *(s32 *)((s8 *)this + 0x80) = (temp_r4 + 1);
    }
    temp_r4_2 = *(u32 *)((s8 *)this + 0x7C);
    if (temp_r4_2 < 0xFFU) {
        *(u32 *)((s8 *)this + 0x7C) = (temp_r4_2 + 0xC);
    }
    temp_r4_3 = *(u32 *)((s8 *)this + 0x7C);
    *(u32 *)((s8 *)this + 0x7C) = (temp_r4_3 <= 0xFFU) ? temp_r4_3 : 0xFFU;
    update_title_tex_positions__13TAdTitleTexGCFPv((Obj_802A4EF4 *)(this));
}

void update_title_tex_positions__13TAdTitleTexGCFPv(Obj_802A4EF4 *arg0) {
    V_802A4EF4 sp[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 t = 0x14 - arg0->f80;
        sp[i].x = ((640.0f - arg0->a[i].x) * (f32)(t * t)) / 400.0f;
        sp[i].y = 0.0f;
        arg0->b[i].x = arg0->a[i].x + sp[i].x;
        arg0->b[i].y = arg0->a[i].y + sp[i].y;
        arg0->b[i].x2 = 20.0f + arg0->b[i].x;
        arg0->b[i].y2 = 20.0f + arg0->b[i].y;
    }
}

void TAdTitleTexGC::render() {
    s32 temp_r31;

    if (TMainTask::get_render_pass() != 1) {
        render_status_pair((*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF);
        sub_802A4D74((s32)((*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF), (u8 *)(get_localized_text_entry(0x28, 0)), (u8 *)(get_localized_text_entry(0x28, 1)));
    }
}

}

void TAdTitleTexGC::render_status_pair(s32 arg1) {
    s32 arg0 = (s32)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D6668);
    set_draw_texture_and_color(0, arg1);
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x1C), 0.1f);
    TWindowSubStatusDisp::get_player();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D6668);
    set_draw_texture_and_color(0, arg1);
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x3C), 0.1f);
    TWindowSubStatusDisp::get_player();
}

#pragma push
#pragma opt_common_subs off
void TAdTitleTexGC::sub_802A4D74(s32 arg1, u8 *arg2, u8 *arg3) {
    u8 *arg0 = (u8 *)this;
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x1C), 1.0f + *(f32 *)((s8 *)arg0 + 0x20), (const char *)arg2, arg1);
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x3C), 1.0f + *(f32 *)((s8 *)arg0 + 0x40), (const char *)arg3, arg1);
}
#pragma pop

