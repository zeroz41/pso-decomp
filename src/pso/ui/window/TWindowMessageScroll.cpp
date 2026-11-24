#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowMessageScroll__class_name = "TWindowMessageScroll";

void TWindowMessageScroll::run_task() {
    u8 *arg0 = (u8 *)this;
    this->scroll_offset[1] = (f32) (this->scroll_offset[1] + scroll_speed);
    TWindowMessage::retire_scrolled_lines();
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(&this->entry_list);
    if ((((TWindowBase *)arg0)->sub_80244994() != 0) && (this->next_line_y <= this->scroll_offset[1])) {
        *completion_register = 1;
    }
}

}
TWindowMessageScroll::~TWindowMessageScroll() {

}

TWindowMessageScroll::TWindowMessageScroll(s32 parent, s32 *completion) : TWindowMessageQuest(parent) {
    this->m_name = TWindowMessageScroll__class_name;
    scroll_speed = 0.0f;
    completion_register = completion;
    *completion_register = 0;
}
