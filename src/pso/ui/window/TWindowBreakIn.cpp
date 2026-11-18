#include "types.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"

#pragma push
#pragma readonly_strings on
const char *TWindowBreakIn__name = "TWindowBreakIn";
#pragma pop

// inferred: window_break_in_layout_entries, the layout table window_break_in_layout points at
// (eight sprite parts, cf. window_timer_layout_entries).
struct BreakInWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[8];
};

extern s32 lbl_805D63F0;

BreakInWindowLayout window_break_in_layout_entries = {
    8, 1,
    {
        {6, {72.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &lbl_805D63F0, 0, 6},
        {6, {76.0f, 0.0f}, {32.0f, 30.0f}, 185.0f, 62.0f, 0.6f, -1, &lbl_805D63F0, 0, 10},
        {6, {48.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &lbl_805D63F0, 0, 6},
        {6, {52.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 185.0f, 0.6f, -1, &lbl_805D63F0, 0, 10},
        {6, {24.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &lbl_805D63F0, 0, 6},
        {6, {28.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 152.0f, 0.6f, -1, &lbl_805D63F0, 0, 10},
        {6, {0.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &lbl_805D63F0, 0, 6},
        {6, {4.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 119.0f, 0.6f, -1, &lbl_805D63F0, 0, 10},
    },
};

WindowDescriptor window_break_in_layout = {
    {112.0f, 30.0f}, 50000.0f, &window_break_in_layout_entries, 0x823,
};

extern "C" {
u8 * get_window_layout_position(s32);
extern s32 __vt__14TWindowBreakIn[];
s32 draw_visible_window_entries(s32, s32, s32);
s32 draw_default_entry__9TWindowDDFl();

void TWindowBreakIn::render() {
    s32 arg0 = (s32)this;
    s32 tmp = draw_default_entry__9TWindowDDFl();
    draw_visible_window_entries(arg0, arg0 + 0x24, tmp);
}

void TWindowBreakIn::run_task() { ((TWindowSubStatusDisp *)this)->update_entry_visibility(); ((TWindowDD *)this)->initialize_subwindow(); update_window_entry_list((char*)this + 0x24); }

TWindowBreakIn::~TWindowBreakIn() {}
u8 *TWindowBreakIn__ct(u8 *window_dd) {
    __ct__11TWindowBaseFPUcsPUc(window_dd, (u8 *)&window_break_in_layout, (s16)(4), (u8 *)(get_window_layout_position(0xAA)));
    *(s32 **)((s8 *)window_dd + 0x18) = __vt__14TWindowBreakIn;
    *(s32 *)((s8 *)window_dd + 0) = (s32) TWindowBreakIn__name;
    return window_dd;
}

}
