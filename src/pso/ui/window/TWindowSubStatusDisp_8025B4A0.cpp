#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B4A0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#pragma readonly_strings on
#pragma fp_contract on

struct Stack_8025B660 {
    f32 sp8;
    f32 spC;
};

extern "C" {
u32 calc_text_width(u32);
s32 measure_string_len__20TWindowSubStatusDispFv(u32);
void *mem_alloc(u32 size);
void mem_free(void *p);
s32 strncpy(s32, u32, s32);
s32 deleting_destructor__20TWindowSubStatusDispFs(void *, s32);
void reset_entry__20TWindowSubStatusDispFPv(void*, int);

void *window_label_value_part_vtable[6] = {
    0, 0,
    (void *)destroy_free_buffers__20TWindowSubStatusDispFPvs,
    (void *)TWindowSubStatusDisp__sub_8025B760,
    (void *)draw_label_value__20TWindowSubStatusDispFPvPv,
    0,
};

void TWindowSubStatusDisp::set_string(u32 arg1) {
    s32 temp_r3;

    mem_free((void *)(*(s32 *)((s8 *)this + 0x20)));
    *(s32 *)((s8 *)this + 0x20) = 0;
    if (arg1 != 0U) {
        *(f32 *)((s8 *)this + 8) = (f32) (0.0f);
        temp_r3 = measure_string_len__20TWindowSubStatusDispFv(arg1);
        *(s32 *)((s8 *)this + 0x20) = (s32)mem_alloc(temp_r3 + 1);
        strncpy(*(s32 *)((s8 *)this + 0x20), arg1, temp_r3 + 1);
    }
}

void TWindowSubStatusDisp::set_text(u32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    mem_free((void *)(*(s32 *)((s8 *)this + 0x1C)));
    *(s32 *)((s8 *)this + 0x1C) = 0;
    if (arg1 != 0U) {
        temp_r3 = measure_string_len__20TWindowSubStatusDispFv(arg1);
        *(s32 *)((s8 *)this + 0x1C) = (s32)mem_alloc(temp_r3 + 1);
        strncpy(*(s32 *)((s8 *)this + 0x1C), arg1, temp_r3 + 1);
    }
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(f32 *)((s8 *)this + 8) = (f32) (0.0f);
    *(u16 *)((s8 *)this + 0) = *(u16 *)((s8 *)this + 0) | 5;
    set_string(arg2);
}

void TWindowSubStatusDisp::set_text(u32 arg1, s32 arg2) {
    s32 temp_r3;
    f64 tmp;

    mem_free((void *)(*(s32 *)((s8 *)this + 0x1C)));
    *(s32 *)((s8 *)this + 0x1C) = 0;
    if (arg1 != 0U) {
        temp_r3 = measure_string_len__20TWindowSubStatusDispFv(arg1);
        *(s32 *)((s8 *)this + 0x1C) = (s32)mem_alloc(temp_r3 + 1);
        strncpy(*(s32 *)((s8 *)this + 0x1C), arg1, temp_r3 + 1);
    }
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x15);
    *(f32 *)((s8 *)this + 8) = (208.5f) - ((0.5f) * (f32) ::calc_text_width(arg1));
}
void draw_label_value__20TWindowSubStatusDispFPvPv(u8 *window_sub_com_card, u8 *arg1) {
    Stack_8025B660 stack;
    if ((((TWindowSubComCard *)window_sub_com_card)->is_flag_4_set() != 0) && ((s32) *(s32 *)((s8 *)arg1 + 0x30) >= 0)) {
        stack.sp8 = *(f32 *)((s8 *)arg1 + 0x10) + *(f32 *)((s8 *)window_sub_com_card + 8);
        stack.spC = *(f32 *)((s8 *)arg1 + 0x14) + *(f32 *)((s8 *)window_sub_com_card + 0xC);
        set_text_draw_params((s32) arg1, 1, 1, (-1.0f) / ((0.0897f) + *(f32 *)((s8 *)arg1 + 0x38)), (1e+05f));
        draw_window_text((f32 *)&stack.sp8, (const char *)(*(u8 **)((s8 *)window_sub_com_card + 0x1C)), (((TWindowSubComCard *)window_sub_com_card)->m_24), 1, (f32)(1e+05f));
        if (!(*(u16 *)((s8 *)window_sub_com_card + 0) & 0x10)) {
            stack.sp8 += (154.0f);
            draw_window_text(&stack.sp8, (const char *)((void *)":"), ((TWindowSubComCard *)window_sub_com_card)->m_24, 0, (1e+05f));
        }
        stack.sp8 += (12.0f);
        draw_window_text((f32 *)&stack.sp8, (const char *)(*(u8 **)((s8 *)window_sub_com_card + 0x20)), (((TWindowSubComCard *)window_sub_com_card)->m_24), 1, (f32)(1e+05f));
    }
}
void TWindowSubStatusDisp__sub_8025B760(void *p) {
    if (((TWindowSubComCard *)p)->is_flag_4_set()) return;
}

void *destroy_free_buffers__20TWindowSubStatusDispFPvs(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(void ***)((s8 *)window_sub_status_disp + 4) = window_label_value_part_vtable;
        mem_free((void *)(*(s32 *)((s8 *)window_sub_status_disp + 0x20)));
        mem_free((void *)(*(s32 *)((s8 *)window_sub_status_disp + 0x1C)));
        deleting_destructor__20TWindowSubStatusDispFs(window_sub_status_disp, 0);
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

void*TWindowSubComCard::init_fields(int a1, int a2) { reset_entry__20TWindowSubStatusDispFPv(this, a2); *(int*)((char*)this + 0x4) = (int)window_label_value_part_vtable; *(float*)((char*)this + 0x14) = (18.0f); this->m_24 = -1; *(int*)((char*)this + 0x1c) = 0; this->m_20 = 0; *(int*)((char*)this + 0x18) = 0; return this; }

int TWindowSubComCard::is_flag_4_set() { return *(u16*)((char*)this + 0x0) & 0x4; }

}
