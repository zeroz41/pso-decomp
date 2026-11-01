#include "types.h"
#include "pso/misc/TWindowCtrlMain_8024674C.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowBreakIn.h"
#include "pso/misc/TWindowDD.h"

struct RecoveredGlobal_80246C58_lbl_804CE1B8 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80246C58___vt__14TWindowBreakIn {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
u8 * get_window_layout_position(s32);
extern RecoveredGlobal_80246C58_lbl_804CE1B8 window_break_in_layout;
extern s32 __vt__14TWindowBreakIn[];
extern s32 lbl_805D3890;
s32 draw_visible_window_entries(s32, s32, s32);
void __dl__7TObjectFPv(void *);
s32 draw_default_entry__9TWindowDDFl();
int initialize_subwindow__9TWindowDDFv(void*);

void TWindowBreakIn::render() {
    s32 arg0 = (s32)this;
    s32 tmp = draw_default_entry__9TWindowDDFl();
    draw_visible_window_entries(arg0, arg0 + 0x24, tmp);
}

void TWindowBreakIn::run_task() { update_entry_visibility__20TWindowSubStatusDispFv((s32)this); initialize_subwindow__9TWindowDDFv(this); update_window_entry_list((char*)this + 0x24); }

void *__dt__14TWindowBreakInFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowBreakIn;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80246C58_lbl_804CE1B8_size[sizeof(RecoveredGlobal_80246C58_lbl_804CE1B8) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80246C58___vt__14TWindowBreakIn_size[sizeof(RecoveredGlobal_80246C58___vt__14TWindowBreakIn) == 0x1C ? 1 : -1];
u8 *TWindowBreakIn__ct(u8 *window_dd) {
    ((TWindowDD *)window_dd)->construct_base((u8 *)&window_break_in_layout.value, (s16)(4), (u8 *)(get_window_layout_position(0xAA)));
    *(s32 **)((s8 *)window_dd + 0x18) = &(*(RecoveredGlobal_80246C58___vt__14TWindowBreakIn *)&__vt__14TWindowBreakIn).value;
    *(s32 *)((s8 *)window_dd + 0) = (s32) lbl_805D3890;
    return window_dd;
}

}
