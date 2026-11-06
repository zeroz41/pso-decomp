#include "types.h"
#include "pso/ui/window/TWindowMessageInfomation.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3988 = "TWindowMessageInfomation";
}



struct RecoveredGlobal_8026A100___vt__24TWindowMessageInfomation {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 * TWindowMessage__ct(void *, s32, u32, s16);
extern s32 __vt__24TWindowMessageInfomation[];
extern const char *lbl_805D3988;
u8 *TWindowMessageInfomation__ct(u8 *arg0, s32 arg1, s16 arg2);
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(s32, s32, s32);

void TWindowMessageInfomation::render() {
    s32 arg0 = (s32)this;
    s8 *tmp = (s8 *)get_draw_context__11TWindowBaseFPv();
    draw_visible_window_entries(arg0, arg0 + 0x24, (s32)tmp);
}

}
TWindowMessageInfomation::~TWindowMessageInfomation() {

}

typedef char RecoveredGlobal_8026A100___vt__24TWindowMessageInfomation_size[sizeof(RecoveredGlobal_8026A100___vt__24TWindowMessageInfomation) == 0x18 ? 1 : -1];
u8 *TWindowMessageInfomation__ct(u8 *arg0, s32 arg1, s16 arg2) {
    TWindowMessage__ct(arg0, arg1, 0x10U, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8026A100___vt__24TWindowMessageInfomation *)&__vt__24TWindowMessageInfomation).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((s32)lbl_805D3988);
    return arg0;
}

