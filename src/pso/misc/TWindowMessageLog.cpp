#include "types.h"
#include "pso/misc/TWindowMessageLog.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Stack_8026A434 {
    f32 sp8;
    f32 spC;
};

struct Stack_8026A494 {
    f32 sp8;
    f32 spC;
};

extern "C" {
s32 clamp_list_scroll_offset(int, void *, void *, f32);
extern const f32 lbl_805DD240;
extern const f32 lbl_805DD244;
extern const f32 lbl_805DD248;
extern const f32 lbl_805DD24C;
s32 is_locally_controlled__10TObjPlayerFPv(s32);
s32 find_entity_by_id();
s32 obj_isState2_324__9TObjCharaFv();

s32 TWindowMessageLog::get_active_photon_object() {
    s32 temp_r3;
    s32 var_r3;

    temp_r3 = find_entity_by_id();
    if (temp_r3 == 0) {
        return 0;
    }
    if ((obj_isState2_324__9TObjCharaFv() == 0) && (is_locally_controlled__10TObjPlayerFPv(temp_r3) == 0)) {
        return 0;
    }
    var_r3 = temp_r3 + 0x85C;
    if (var_r3 == 0) {
        var_r3 = 0;
    }
    return var_r3;
}
void TWindowMessageLog::clamp_scroll_offset() {
    Stack_8026A434 stack;
    f32 temp_f1;
    stack.sp8 = lbl_805DD240;
    temp_f1 = *(f32 *)&this->m_4c;
    stack.spC = temp_f1 - lbl_805DD244;
    if (clamp_list_scroll_offset((int) (*(s32 *)((s8 *)((u8 *)this) + 0x90)), (void *) (((u8 *)this) + 0x68), &stack.sp8, temp_f1) != 0) {
        this->m_84 = (f32) this->m_6c;
    }
}
void TWindowMessageLog::update_scroll_position() {
    Stack_8026A494 stack;
    s32 temp_r31;
    s32 array_entry;
    s32 temp_r4;
    s32 var_r30;
    temp_r4 = this->next_line;
    var_r30 = temp_r4 - 1;
    if (var_r30 < 0) {
        var_r30 = this->line_count - 1;
    }
    temp_r31 = this->get_array_entry(temp_r4);
    array_entry = this->get_array_entry(var_r30);
    stack.sp8 = (this->m_48 - lbl_805DD248) - lbl_805DD24C;
    stack.spC = (*(f32 *)((s8 *)array_entry + 0xC) + *(f32 *)((s8 *)array_entry + 0x14)) - *(f32 *)((s8 *)temp_r31 + 0xC);
    ((TWindowMenu *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)))->copy_position(&stack.sp8);
    this->clamp_scroll_offset();
}

}
