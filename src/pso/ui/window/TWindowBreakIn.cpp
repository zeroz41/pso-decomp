#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowLayout.h"

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


BreakInWindowLayout window_break_in_layout_entries = {
    8, 1,
    {
        {6, {72.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {76.0f, 0.0f}, {32.0f, 30.0f}, 185.0f, 62.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {48.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {52.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 185.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {24.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {28.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 152.0f, 0.6f, -1, &hud_texlist, 0, 10},
        {6, {0.0f, 0.0f}, {40.0f, 30.0f}, 137.0f, 203.0f, 0.4f, -1, &hud_texlist, 0, 6},
        {6, {4.0f, 0.0f}, {32.0f, 30.0f}, 224.0f, 119.0f, 0.6f, -1, &hud_texlist, 0, 10},
    },
};

WindowDescriptor window_break_in_layout = {
    {112.0f, 30.0f}, 50000.0f, &window_break_in_layout_entries, 0x823,
};

extern "C" {

void TWindowBreakIn::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowBreakIn::run_task() { ((TWindowSubStatusDisp *)this)->update_entry_visibility(); ((TWindowDD *)this)->initialize_subwindow(); update_window_entry_list(&entry_list); }

TWindowBreakIn::~TWindowBreakIn() {}
TWindowBreakIn::TWindowBreakIn() : TWindowBase((u8 *)&window_break_in_layout, (s16)(4), (u8 *)(get_window_layout_position(0xAA))) {
    m_name = TWindowBreakIn__name;
}

}
