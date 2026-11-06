#include "types.h"
#include "pso/unk/text_80338F3C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_80338F3C_lbl_804EF4CC {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80338F3C_lbl_804EF4E0 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * get_window_layout_position(s32);
extern RecoveredGlobal_80338F3C_lbl_804EF4CC lbl_804EF4CC;
extern RecoveredGlobal_80338F3C_lbl_804EF4E0 lbl_804EF4E0;
typedef char RecoveredGlobal_80338F3C_lbl_804EF4CC_size[sizeof(RecoveredGlobal_80338F3C_lbl_804EF4CC) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80338F3C_lbl_804EF4E0_size[sizeof(RecoveredGlobal_80338F3C_lbl_804EF4E0) == 0x20 ? 1 : -1];
u8 *fn_80338F3C(u8 *window_sub_status_disp, s32 arg1) {
    ((TWindowSubStatusDisp *)window_sub_status_disp)->ct_helper((s32)((int) (get_window_layout_position(0xB0))), arg1, 0x40, (s32)&lbl_804EF4CC.value);
    *(s32 **)((s8 *)window_sub_status_disp + 0x18) = &lbl_804EF4E0.value;
    return window_sub_status_disp;
}

}
