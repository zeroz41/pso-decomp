#include "types.h"

#include <stddef.h>
#include "pso/ui/window/TWindowCtrl.h"
struct Stack_8024B054 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

extern "C" {
struct Win_8024B098 { virtual s32 m0(); };
typedef s32 (Win_8024B098::*Pmf_8024B098)();
s32 TWindowCtrl__sub_8024B098(void *, Pmf_8024B098);
Win_8024B098 *get_window__11TWindowCtrlFl(void *self);
struct WindowCtrlIsVisibleCallbackEntry { s32 value; u8 remaining[0x8]; };
extern WindowCtrlIsVisibleCallbackEntry window_ctrl_is_visible_callback_entry;
void TWindowCtrl::is_slot_visible() {
    s32 arg0 = (saddr)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8024B054, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8024B054, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8024B054, sp10) == 0x8);
    Stack_8024B054 stack;
    stack.sp8 = *(s32 *)((s8 *)&window_ctrl_is_visible_callback_entry.value + 0);
    stack.spC = *(s32 *)((s8 *)&window_ctrl_is_visible_callback_entry.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&window_ctrl_is_visible_callback_entry.value + 8);
    ((s32 (*)(void *, void *))TWindowCtrl__sub_8024B098)((void *)arg0, (void *)&stack.sp8);
}

s32 TWindowCtrl__sub_8024B098(void *self, Pmf_8024B098 pmf) {
    Win_8024B098 *w = get_window__11TWindowCtrlFl(self);
    if (w == NULL) {
        return 0;
    }
    return (w->*pmf)();
}

}
