#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageInfomation.h"

#pragma readonly_strings on


const char *TWindowMessageInfomation::class_name = "TWindowMessageInfomation";


void TWindowMessageInfomation::render() {
    WindowDrawContext *context = get_draw_context();
    draw_visible_window_entries(
        this,
        &entry_list,
        context);
}

TWindowMessageInfomation::~TWindowMessageInfomation() {

}

TWindowMessageInfomation::TWindowMessageInfomation(const NJS_POINT2 *position, s32 client) : TWindowMessage(position, 0x10U, client) {
    this->m_name = TWindowMessageInfomation::class_name;
}
