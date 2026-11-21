#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageInfomation.h"

#pragma readonly_strings on


const char *TWindowMessageInfomation__name = "TWindowMessageInfomation";


void TWindowMessageInfomation::render() {
    s32 arg0 = (saddr)this;
    s8 *tmp = reinterpret_cast<s8 *>(get_draw_context());
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24),
        reinterpret_cast<WindowDrawContext *>(tmp));
}

TWindowMessageInfomation::~TWindowMessageInfomation() {

}

TWindowMessageInfomation::TWindowMessageInfomation(s32 arg1, s32 arg2) : TWindowMessage(arg1, 0x10U, arg2) {
    this->m_name = TWindowMessageInfomation__name;
}
