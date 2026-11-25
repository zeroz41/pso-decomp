#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"

#pragma readonly_strings on

const char *TWindowMessageScroll__class_name = "TWindowMessageScroll";

void TWindowMessageScroll::run_task() {
    this->scroll_offset[1] = (f32) (this->scroll_offset[1] + scroll_speed);
    TWindowMessage::retire_scrolled_lines();
    update_window();
    this->update_fade();
    this->update_window_entry_list(&this->entry_list);
    if ((this->is_open_and_unblocked() != 0) && (this->next_line_y <= this->scroll_offset[1])) {
        *completion_register = 1;
    }
}

TWindowMessageScroll::~TWindowMessageScroll() {

}

TWindowMessageScroll::TWindowMessageScroll(const NJS_POINT2 *position, s32 *completion) : TWindowMessageQuest(position) {
    this->m_name = TWindowMessageScroll__class_name;
    scroll_speed = 0.0f;
    completion_register = completion;
    *completion_register = 0;
}
