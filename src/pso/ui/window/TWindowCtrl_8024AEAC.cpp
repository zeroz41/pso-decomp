#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024AEAC.h"

#include <stddef.h>
#include "pso/ui/window/TWindowCtrl.h"
struct Stack_8024B000 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_8024AFB8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_8024AF74 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_8024AEF0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_8024AEAC {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

extern "C" {
s32 TWindowCtrl__sub_8024B098(void *, void *);
struct RecoveredGlobal_lbl_804CE9D4 { s32 value; u8 remaining[0x8]; };
extern RecoveredGlobal_lbl_804CE9D4 lbl_804CE9D4;
struct WindowCtrlApplyDefaultVecCallbackEntry { s32 value; u8 remaining[0x8]; };
extern WindowCtrlApplyDefaultVecCallbackEntry window_ctrl_apply_default_vec_callback_entry;
struct Win_8024AF34 { virtual void m0(); };
typedef void (Win_8024AF34::*Pmf_8024AF34)();
void call_window_method__11TWindowCtrlFPvi(void *, Pmf_8024AF34);
Win_8024AF34 *get_window__11TWindowCtrlFl(void *self);

void TWindowCtrl::suppress_slot() {
    saddr arg0 = (saddr)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024AEAC, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024AEAC, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024AEAC, sp10) == 0x8);
    Stack_8024AEAC stack;
    stack.sp8 = *(s32 *)((s8 *)&TWindowCtrl__suppress_slot_cb.value + 0);
    stack.spC = *(s32 *)((s8 *)&TWindowCtrl__suppress_slot_cb.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&TWindowCtrl__suppress_slot_cb.value + 8);
    ((void (*)(void *, void *))call_window_method__11TWindowCtrlFPvi)((void *)arg0, (void *)&stack.sp8);
}

void TWindowCtrl::unsuppress_slot() {
    saddr arg0 = (saddr)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024AEF0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024AEF0, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024AEF0, sp10) == 0x8);
    Stack_8024AEF0 stack;
    stack.sp8 = *(s32 *)((s8 *)&TWindowCtrl__unsuppress_slot_cb.value + 0);
    stack.spC = *(s32 *)((s8 *)&TWindowCtrl__unsuppress_slot_cb.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&TWindowCtrl__unsuppress_slot_cb.value + 8);
    ((void (*)(void *, void *))call_window_method__11TWindowCtrlFPvi)((void *)arg0, (void *)&stack.sp8);
}

void call_window_method__11TWindowCtrlFPvi(void *self, Pmf_8024AF34 pmf) {
    Win_8024AF34 *w = get_window__11TWindowCtrlFl(self);
    if (w != NULL) {
        (w->*pmf)();
    }
}

void TWindowCtrl::has_player_active_menu() {
    saddr arg0 = (saddr)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024AF74, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024AF74, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024AF74, sp10) == 0x8);
    Stack_8024AF74 stack;
    stack.sp8 = *(s32 *)((s8 *)&TWindowCtrl__player_menu_query_cb.value + 0);
    stack.spC = *(s32 *)((s8 *)&TWindowCtrl__player_menu_query_cb.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&TWindowCtrl__player_menu_query_cb.value + 8);
    TWindowCtrl__sub_8024B098((void *)arg0, (void *)&stack.sp8);
}

void TWindowCtrl::apply_default_vec(s32 arg0, saddr arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024AFB8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024AFB8, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024AFB8, sp10) == 0x8);
    Stack_8024AFB8 stack;
    stack.sp8 = *(s32 *)((s8 *)&window_ctrl_apply_default_vec_callback_entry.value + 0);
    stack.spC = *(s32 *)((s8 *)&window_ctrl_apply_default_vec_callback_entry.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&window_ctrl_apply_default_vec_callback_entry.value + 8);
    TWindowCtrl__sub_8024B098((void *)arg1, (void *)&stack.sp8);
}

void TWindowCtrl__sub_8024B000(s32 arg0, saddr arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024B000, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024B000, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024B000, sp10) == 0x8);
    Stack_8024B000 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_804CE9D4.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804CE9D4.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804CE9D4.value + 8);
    TWindowCtrl__sub_8024B098((void *)arg1, (void *)&stack.sp8);
}

}
