#include "types.h"
#include "pso/ui/window/TWindowMessageInfomation.h"

#pragma readonly_strings on


const char *TWindowMessageInfomation__name = "TWindowMessageInfomation";


extern "C" {
u8 * TWindowMessage__ct(void *, s32, u32, s16);
extern s32 __vt__24TWindowMessageInfomation[];
extern const char *TWindowMessageInfomation__name;
u8 *TWindowMessageInfomation__ct(u8 *arg0, s32 arg1, s16 arg2);
saddr get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(s32, s32, s32);

void TWindowMessageInfomation::render() {
    s32 arg0 = (saddr)this;
    s8 *tmp = (s8 *)get_draw_context__11TWindowBaseFPv();
    draw_visible_window_entries(arg0, arg0 + 0x24, (saddr)tmp);
}

}
TWindowMessageInfomation::~TWindowMessageInfomation() {

}

u8 *TWindowMessageInfomation__ct(u8 *arg0, s32 arg1, s16 arg2) {
    TWindowMessage__ct(arg0, arg1, 0x10U, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TWindowMessageInfomation;
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((saddr)TWindowMessageInfomation__name);
    return arg0;
}

