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
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

struct Rec_802A0A60 { u8 pad[0x20]; };

struct Title_802A0A60 { u8 pad[0x20]; Rec_802A0A60 recs[8]; };

typedef struct Rec_802A0E08 {
    f32 x0, y0, x1, y1;
    f32 a, b, c, d;
} Rec_802A0E08;

typedef struct TAdTitleGC_802A0E08 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vtable;
    s32 idx;
    Rec_802A0E08 recs[8];
    f32 f120;
    f32 f124;
    s32 f128;
    s32 f12C;
    u32 f130;
    s32 f134;
} TAdTitleGC_802A0E08;

struct Rec_802A0C84 {
    f32 x0, y0, x1, y1;
    u8 pad[0x10];
};

struct Title_802A0C84 {
    u8 pad[0x20];
    Rec_802A0C84 rects[8];
    u8 pad120[0x128 - 0x120];
    s32 f128;
};

// The title banner textures: English (lbl_804DCA60/78) and Japanese (lbl_804DCA80/98) name lists and texlists.
NJS_TEXNAME lbl_804DCA60[2] = { { (void *)"f512_midashi_eng", 0, 0 }, { (void *)"f512_midashi_eng_b", 0, 0 } };
NJS_TEXLIST lbl_804DCA78 = { lbl_804DCA60, 2 };
NJS_TEXNAME lbl_804DCA80[2] = { { (void *)"f512_midashi", 0, 0 }, { (void *)"f512_midashi_b", 0, 0 } };
NJS_TEXLIST lbl_804DCA98 = { lbl_804DCA80, 2 };

const char *ad_title_gc_class_name = "TAdTitleGC";

extern "C" {
u32 calc_text_width(char *s);
s32 get_player__20TWindowSubStatusDispFv();
u32 lbl_805D6630;
s32 get_localized_text_entry(s32, s32);
void restore_saved_depth_alpha_state(void);
s32 defer_render__7TObjectFv();

}

// The title texture helpers. The TU is compiled deferred, so its functions come out backwards:
// these are written first and land last.
extern "C" {
extern const s32 current_language;
extern int lobby_cursor_active_flag;
void release_texture_list(void*);

int TObjPlayer__sub_802A1018(void) { return lobby_cursor_active_flag; }

void TLobby__sub_802A0F70(void) {
    TLobby::update_menu_cursor();
    const char *names[5] = { "f512_midashi", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng", "f512_midashi_eng" };
    NJS_TEXLIST *lists[5] = { &lbl_804DCA98, &lbl_804DCA78, &lbl_804DCA78, &lbl_804DCA78, &lbl_804DCA78 };
    lbl_805D6630 = (u32)lists[current_language];
    TLobby__sub_8023E4B4((s32)names[current_language], (s32)lists[current_language]);
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
    ((TAdTitleGC_802A0E08 *)this)->name = ad_title_gc_class_name;
    ((TAdTitleGC_802A0E08 *)this)->idx = idx;
    ((TAdTitleGC_802A0E08 *)this)->f128 = -1;
    ((TAdTitleGC_802A0E08 *)this)->f12C = 0;
    ((TAdTitleGC_802A0E08 *)this)->f134 = 1;
    ((TAdTitleGC_802A0E08 *)this)->f130 = 0;
    off = (((TAdTitleGC_802A0E08 *)this)->idx > 11) ? -12 : 0;
    for (i = 0; i < 8; i++) {
        ((TAdTitleGC_802A0E08 *)this)->recs[i].a = (0.0f);
        ((TAdTitleGC_802A0E08 *)this)->recs[i].b = (4e+01f) * (f32)(((TAdTitleGC_802A0E08 *)this)->idx + off) / 512.0f;
        ((TAdTitleGC_802A0E08 *)this)->recs[i].c = 1.0f;
        ((TAdTitleGC_802A0E08 *)this)->recs[i].d = (4e+01f) * (f32)(((TAdTitleGC_802A0E08 *)this)->idx + off + 1) / 512.0f;
    }
    ((TAdTitleGC_802A0E08 *)this)->f130 = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)((TAdTitleGC_802A0E08 *)this), 8, 0.0f);
}

TAdTitleGC::~TAdTitleGC() {}
#pragma pop

extern "C" {
void run_task__10TAdTitleGCFv(u8 *ad_title_gc) {
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)ad_title_gc + 0x128);
    if (temp_r3 < 0xA) {
        *(s32 *)((s8 *)ad_title_gc + 0x128) = (temp_r3 + 1);
    }
    *(s32 *)((s8 *)ad_title_gc + 0x12C) = (s32) (*(s32 *)((s8 *)ad_title_gc + 0x12C) + 0xC);
    if ((s32) *(s32 *)((s8 *)ad_title_gc + 0x12C) > 0xFF) {
        *(s32 *)((s8 *)ad_title_gc + 0x12C) = 0xFF;
    }
    ((TAdTitleGC *)ad_title_gc)->update_title_rects();
    TAdTitleGC::calc_text_pos((s32)ad_title_gc, ad_title_gc + 0x120, (s32)(get_localized_text_entry(0x13, *(s32 *)((s8 *)ad_title_gc + 0x1C))));
}
}

// Per-rect slide-in factor update_title_rects scales the remaining frames by.
const f32 title_rect_scale_table[8] = { 1.0f, 0.8f, 0.6f, 0.4f, -1.0f, -0.8f, -0.6f, -0.4f };

s32 TAdTitleGC::update_title_rects() {
    Title_802A0C84 *arg0 = (Title_802A0C84 *)this;
    s32 i;
    for (i = 0; i < 8; i++) {
        arg0->rects[i].x0 = (64.0f) - ((f32)(10 - arg0->f128) * ((f32)(10 - arg0->f128) * title_rect_scale_table[i]));
        arg0->rects[i].y0 = (43.0f);
        arg0->rects[i].x1 = (512.0f) + arg0->rects[i].x0;
        arg0->rects[i].y1 = (4e+01f) + arg0->rects[i].y0;
    }
    return (s32)this;
}

#pragma push
#pragma fp_contract on
void TAdTitleGC::calc_text_pos(s32 arg0, u8 *arg1, s32 arg2) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) ((6.2e+02f) - (f32) calc_text_width((char *)(arg2)));
    *(f32 *)((s8 *)arg1 + 4) = 86.0f;
}
#pragma pop

void TAdTitleGC::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x134) == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if (defer_render__7TObjectFv() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        draw_title_layer((s32)(*(s32 *)((s8 *)arg0 + 0x1C)), 0x1FFFFFFF);
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        fn_802A0A30((s32)arg0, arg0 + 0x120, (s32)(*(s32 *)((s8 *)arg0 + 0x1C)), (s32)((*(s32 *)((s8 *)arg0 + 0x12C) << 0x18) | 0xFF0000 | 0xFFFF), (s32)(get_localized_text_entry(0x13, *(s32 *)((s8 *)arg0 + 0x1C))));
        if ((s32) *(s32 *)((s8 *)arg0 + 0x134) == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

s32 TAdTitleGC::draw_title_layer(s32 arg1, s32 arg2) {
    s32 i;
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D6630);
    set_draw_texture_and_color(arg1 > 0xB, arg2);
    for (i = 0; i < 8; i++) {
        draw_textured_quad_at_depth((f32 *)(&((Title_802A0A60 *)this)->recs[i]), (-1.0f) / -((113.0f) - (f32)i));
    }
    return get_player__20TWindowSubStatusDispFv();
}
