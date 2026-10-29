#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/TAdMcSelectCursorGC_8032A610.h"
#include "pso/render/render_util.h"
#include "pso/TAdMcSelectMcGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"


struct Rect_8032A7C8 { f32 x, y, x2, y2; u8 pad[0x10]; };

struct Mc_8032A7C8 {
    u8 pad0[0x20];
    Rect_8032A7C8 rects[8];
    u32 f120;
    s32 f124;
    u8 pad128[4];
    s32 f12C;
};

extern "C" {
u32 get_mc_count__13TAdMcSelectGCFv(void);
void *get_cursor_type__19TAdMcSelectCursorGCFi(s32);
s32 TAdMcSelectMcGC__sub_8032AAC4(void);
extern const f32 lbl_805DF74C;
extern const f32 lbl_805DF750;
extern const f32 lbl_805DF754;
extern const f32 lbl_805DF758;
void restore_saved_depth_alpha_state(void);
s32 defer_render__7TObjectFv();

extern s32 TAdMcSelectMcGC__texture_list_ptr;
extern const f32 lbl_805DF748;

void TAdMcSelectMcGC::draw_status_window() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(TAdMcSelectMcGC__texture_list_ptr);
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x120) << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x20), lbl_805DF748);
    TWindowSubStatusDisp::get_player();
}

void TAdMcSelectMcGC::render() {
    if ((s32) *(s32 *)((s8 *)this + 0x1C) == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if (defer_render__7TObjectFv() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_additive_blend();
        draw_status_window();
        set_default_alpha_blend();
        if ((s32) *(s32 *)((s8 *)this + 0x1C) == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}
#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TAdMcSelectMcGC::run_task() {
    Mc_8032A7C8 *o = (Mc_8032A7C8 *)this;
    s32 i;
    void *cursor;
    for (i = 0; i < 8; i++) {
        o->rects[i].x = lbl_805DF750 * (f32)o->f12C + lbl_805DF74C;
        o->rects[i].y = lbl_805DF754;
        o->rects[i].x2 = lbl_805DF758 + o->rects[i].x;
        o->rects[i].y2 = lbl_805DF758 + o->rects[i].y;
    }
    if (get_mc_count__13TAdMcSelectGCFv() != 0 && o->f12C == TAdMcSelectMcGC__sub_8032AAC4()) {
        o->f120 >>= 1;
    }
    cursor = get_cursor_type__19TAdMcSelectCursorGCFi(o->f12C);
    if (cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(cursor) == 0) {
        o->f124 = 0;
    }
    switch (o->f124) {
    case 0:
        if (cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(cursor) > 0) {
            o->f124 = 1;
        }
        o->f120 = 0;
        break;
    case 1:
        if (cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(cursor) > 3) {
            o->f124 = 2;
        }
        o->f120 = 0;
        break;
    case 2:
        if (cursor != NULL && TAdMcSelectCursorGC__sub_8032A6D8(cursor) > 4) {
            o->f124 = 3;
        }
        o->f120 = 0;
        break;
    case 3:
        o->f120 = 0xFF;
        break;
    }
}
#pragma pop

}
