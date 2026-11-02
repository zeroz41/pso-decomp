#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/misc/TKeyBoardControl_8025CB70.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowDD.h"
#include "pso/ui/Language.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pt_80260020 { f32 x, y; };

struct Ctx_80260020 { u8 pad0[0x10]; Pt_80260020 pos; u8 pad18[0x38 - 0x18]; f32 scale; };

struct State_80260020 { u8 pad0[0xB4]; s32 flags; };

struct Win_80260020 { u8 pad0[0x70]; State_80260020 *state; };

extern "C" {
extern s32 lbl_8044F0CC[];
extern s32 lbl_8044F0D4[];
extern s32 keyboard_hard_status_text_a[];
extern s32 keyboard_hard_status_text_b[];
extern s32 lbl_8044F0FC[];
extern s32 lbl_8044F104[];
s32 is_key_active__19TWindowKeyBoardHardFv();

void TWindowKeyBoardHard::release_keyboard() { void* m = *(void* *)&this->m_70; if (m) TWindowKeyBoardHard__sub_8025CC48(m); }

void TWindowKeyBoardHard::draw_status_text(void *ctx) {
    s32 flags;
    if (((Win_80260020 *)this)->state != NULL && current_language == LANGUAGE_JAPANESE) {
        f32 inv = -1.0f / ((Ctx_80260020 *)ctx)->scale;
        Pt_80260020 pt;
        pt.x = ((Ctx_80260020 *)ctx)->pos.x;
        pt.y = ((Ctx_80260020 *)ctx)->pos.y;
        set_text_draw_params((s32)((Ctx_80260020 *)ctx), 0, 0, (f32)inv, 100000.0f);
        flags = ((Win_80260020 *)this)->state->flags;
        if (!(flags & 1)) {
            draw_window_text((f32 *)&pt, (const char *)lbl_8044F0CC, -1, 0, 1000000.0f);
        } else if (flags & 2) {
            draw_window_text((f32 *)&pt, (const char *)lbl_8044F0D4, -1, 0, 1000000.0f);
        } else if (flags & 4) {
            if (flags & 8) {
                draw_window_text((f32 *)&pt, (const char *)keyboard_hard_status_text_a, -1, 0, 1000000.0f);
            } else {
                draw_window_text((f32 *)&pt, (const char *)keyboard_hard_status_text_b, -1, 0, 1000000.0f);
            }
        } else if (flags & 8) {
            draw_window_text((f32 *)&pt, (const char *)lbl_8044F0FC, -1, 0, 1000000.0f);
        } else {
            draw_window_text((f32 *)&pt, (const char *)lbl_8044F104, -1, 0, 1000000.0f);
        }
    }
}

void TWindowKeyBoardHard::render() {
    s32 temp;
    if (((s32) this->m_68 > 0) && (is_key_active__19TWindowKeyBoardHardFv() == 0)) {
        temp = TWindowDD::draw_default_entry((s32)this);
        draw_status_text((Ctx_80260020 *)(temp));
    }
}

}
