#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024ADAC.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

void TWindowCtrl::set_flag_bit2() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 4);
    }
}

void TWindowCtrl::clear_flag_bit2() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFFFFFB);
    }
}

#include <stddef.h>
struct Stack_8024ADAC {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8024ADAC_lbl_804CEA1C {
    s32 value;
    u8 remaining[0x8];
};

struct Stack_8024ADF0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8024ADF0_lbl_804CEA10 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 call_window_method__11TWindowCtrlFPvi(void *, void *);
extern RecoveredGlobal_8024ADAC_lbl_804CEA1C lbl_804CEA1C;
extern RecoveredGlobal_8024ADF0_lbl_804CEA10 lbl_804CEA10;
typedef char RecoveredGlobal_8024ADAC_lbl_804CEA1C_size[sizeof(RecoveredGlobal_8024ADAC_lbl_804CEA1C) == 0xC ? 1 : -1];
void TWindowCtrl__sub_8024ADAC(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_8024ADAC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8024ADAC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8024ADAC, sp10) == 0x8) ? 1 : -1];
    Stack_8024ADAC stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_804CEA1C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804CEA1C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804CEA1C.value + 8);
    call_window_method__11TWindowCtrlFPvi((void *)arg0, (void *)&stack.sp8);
}
typedef char RecoveredGlobal_8024ADF0_lbl_804CEA10_size[sizeof(RecoveredGlobal_8024ADF0_lbl_804CEA10) == 0xC ? 1 : -1];
void TWindowCtrl__sub_8024ADF0(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_8024ADF0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8024ADF0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8024ADF0, sp10) == 0x8) ? 1 : -1];
    Stack_8024ADF0 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_804CEA10.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804CEA10.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804CEA10.value + 8);
    call_window_method__11TWindowCtrlFPvi((void *)arg0, (void *)&stack.sp8);
}

}
