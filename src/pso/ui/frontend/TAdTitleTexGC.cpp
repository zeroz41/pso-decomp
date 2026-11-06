#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/MenuText.h"
#include "pso/object/warp/TObjWarpString.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

#pragma push
#pragma opt_common_subs off
void TAdTitleTexGC::sub_802A4D74(s32 arg1, u8 *arg2, u8 *arg3) {
    u8 *arg0 = (u8 *)this;
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x1C), 1.0f + *(f32 *)((s8 *)arg0 + 0x20), (const char *)arg2, arg1);
    draw_menu_text(22.0f + *(f32 *)((s8 *)arg0 + 0x3C), 1.0f + *(f32 *)((s8 *)arg0 + 0x40), (const char *)arg3, arg1);
}

#pragma pop

extern s32 lbl_805D6668;

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

#include "types.h"
#include "pso/system/task/TMainTask.h"

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

void TAdTitleTexGC::render() {
    s32 temp_r31;

    if (TMainTask::get_render_pass() != 1) {
        render_status_pair((*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF);
        sub_802A4D74((s32)((*(s32 *)((s8 *)this + 0x7C) << 0x18) | 0xFF0000 | 0xFFFF), (u8 *)(get_localized_text_entry(0x28, 0)), (u8 *)(get_localized_text_entry(0x28, 1)));
    }
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

extern s32 __vt__13TAdTitleTexGC[];
extern void *TAdTitleTexGC__name;
TAdTitleTexGC::~TAdTitleTexGC() {}
void *__ct__13TAdTitleTexGCFv(void *ad_title_tex_gc) {
    __ct__7TObjectFP7TObject(ad_title_tex_gc);
    *(s32 **)((s8 *)ad_title_tex_gc + 0x18) = __vt__13TAdTitleTexGC;
    *(void * *)&((TAdTitleTexGC *)ad_title_tex_gc)->m_name = TAdTitleTexGC__name;
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

}
