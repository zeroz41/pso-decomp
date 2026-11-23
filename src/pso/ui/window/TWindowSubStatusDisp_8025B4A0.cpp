#include "types.h"
#include "pso/unk/TUnk_804CF998.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B4A0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/NinjaTypes.h"
#include <string.h>
#pragma readonly_strings on
#pragma fp_contract on

extern "C" {
u32 calc_text_width(u32);

void *window_label_value_part_vtable[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp::destroy_free_buffers,
    (void *)TWindowSubStatusDisp__sub_8025B760,
    (void *)draw_label_value__20TWindowSubStatusDispFPvPv,
    0,
};

void TWindowSubStatusDisp::set_string(uaddr string) {
    s32 temp_r3;

    mem_free((void *)(*(saddr *)((s8 *)this + 0x20)));
    *(s32 *)((s8 *)this + 0x20) = 0;
    if (string != 0U) {
        *(f32 *)((s8 *)this + 8) = (f32) (0.0f);
        temp_r3 = (s32)measure_string_len((const char *)(string));
        *(s32 *)((s8 *)this + 0x20) = (saddr)mem_alloc(temp_r3 + 1);
        strncpy((char *)(*(saddr *)((s8 *)this + 0x20)), (const char *)string, (u32)temp_r3 + 1);
    }
}

void TWindowSubStatusDisp::set_text(uaddr arg1, s32 string, s32 arg3) {
    s32 temp_r3;

    mem_free((void *)(*(saddr *)((s8 *)this + 0x1C)));
    *(s32 *)((s8 *)this + 0x1C) = 0;
    if (arg1 != 0U) {
        temp_r3 = (s32)measure_string_len((const char *)(arg1));
        *(s32 *)((s8 *)this + 0x1C) = (saddr)mem_alloc(temp_r3 + 1);
        strncpy((char *)(*(saddr *)((s8 *)this + 0x1C)), (const char *)arg1, (u32)temp_r3 + 1);
    }
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(f32 *)((s8 *)this + 8) = (f32) (0.0f);
    *(u16 *)((s8 *)this + 0) = *(u16 *)((s8 *)this + 0) | 5;
    set_string(string);
}

void TWindowSubStatusDisp::set_text(uaddr arg1, s32 arg2) {
    s32 temp_r3;
    f64 tmp;

    mem_free((void *)(*(saddr *)((s8 *)this + 0x1C)));
    *(s32 *)((s8 *)this + 0x1C) = 0;
    if (arg1 != 0U) {
        temp_r3 = (s32)measure_string_len((const char *)(arg1));
        *(s32 *)((s8 *)this + 0x1C) = (saddr)mem_alloc(temp_r3 + 1);
        strncpy((char *)(*(saddr *)((s8 *)this + 0x1C)), (const char *)arg1, (u32)temp_r3 + 1);
    }
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x15);
    *(f32 *)((s8 *)this + 8) = (208.5f) - ((0.5f) * (f32) ::calc_text_width(arg1));
}
void draw_label_value__20TWindowSubStatusDispFPvPv(u8 *window_sub_com_card, u8 *arg1) {
    NJS_POINT2 pos;
    if ((((TWindowSubComCard *)window_sub_com_card)->is_flag_4_set() != 0) && ((s32) *(s32 *)((s8 *)arg1 + 0x30) >= 0)) {
        pos.x = *(f32 *)((s8 *)arg1 + 0x10) + *(f32 *)((s8 *)window_sub_com_card + 8);
        pos.y = *(f32 *)((s8 *)arg1 + 0x14) + *(f32 *)((s8 *)window_sub_com_card + 0xC);
        set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 1, 1, (-1.0f) / ((0.0897f) + *(f32 *)((s8 *)arg1 + 0x38)), (1e+05f));
        draw_window_text(&pos.x, (const char *)(*(u8 **)((s8 *)window_sub_com_card + 0x1C)), (((TWindowSubComCard *)window_sub_com_card)->m_24), 1, 1e+05f);
        if (!(*(u16 *)((s8 *)window_sub_com_card + 0) & 0x10)) {
            pos.x += (154.0f);
            draw_window_text(&pos.x, ":", ((TWindowSubComCard *)window_sub_com_card)->m_24, 0, (1e+05f));
        }
        pos.x += (12.0f);
        draw_window_text(&pos.x, (const char *)(*(u8 **)((s8 *)window_sub_com_card + 0x20)), (((TWindowSubComCard *)window_sub_com_card)->m_24), 1, 1e+05f);
    }
}
void TWindowSubStatusDisp__sub_8025B760(void *p) {
    if (((TWindowSubComCard *)p)->is_flag_4_set()) return;
}

void *TWindowSubStatusDisp::destroy_free_buffers(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(void ***)((s8 *)window_sub_status_disp + 4) = window_label_value_part_vtable;
        mem_free((void *)(*(saddr *)((s8 *)window_sub_status_disp + 0x20)));
        mem_free((void *)(*(saddr *)((s8 *)window_sub_status_disp + 0x1C)));
        __dt__13TUnk_804CF998Fv(window_sub_status_disp, 0);
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

void*TWindowSubComCard::init_fields(int rec, int client) { __ct__13TUnk_804CF998Fl(this, client); *(int*)((char*)this + 0x4) = (saddr)window_label_value_part_vtable; *(float*)((char*)this + 0x14) = (18.0f); this->m_24 = -1; *(int*)((char*)this + 0x1c) = 0; this->m_20 = 0; *(int*)((char*)this + 0x18) = 0; return this; }

int TWindowSubComCard::is_flag_4_set() { return *(u16*)((char*)this + 0x0) & 0x4; }

}
