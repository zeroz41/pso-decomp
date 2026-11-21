#include "types.h"
#include "pso/ui/window/TWindowMessageInfomation.h"

#pragma readonly_strings on


const char *TWindowMessageInfomation__name = "TWindowMessageInfomation";


extern "C" {
extern const char *TWindowMessageInfomation__name;
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

TWindowMessageInfomation::TWindowMessageInfomation(s32 arg1, s32 arg2) : TWindowMessage(arg1, 0x10U, arg2) {
    this->m_name = TWindowMessageInfomation__name;
}
