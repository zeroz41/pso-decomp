#include "types.h"
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
    f32 temp_f1;
    temp_f1 = this->m_6c;
    this->m_6c = (f32) (temp_f1 + *(f32 *)((s8 *)arg0 + 0x94));
    TWindowMessage::retire_scrolled_lines();
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
    if ((((TWindowBase *)arg0)->sub_80244994() != 0) && (this->unk_80 <= this->m_6c)) {
        *this->m_98 = 1;
    }
}

}
TWindowMessageScroll::~TWindowMessageScroll() {

}

TWindowMessageScroll::TWindowMessageScroll(s32 arg1, s32 *arg2) : TWindowMessageQuest(arg1) {
    this->m_name = TWindowMessageScroll__class_name;
    *(f32 *)((s8 *)this + 0x94) = 0.0f;
    this->m_98 = arg2;
    *this->m_98 = 0;
}
