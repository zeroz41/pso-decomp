#include "types.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

s32 TQuestListOnline::get_selection_stage() { return selection_stage; }

void TWindowMenu::clear_flag_and_release() {
    uaddr temp;
    m_70 &= ~2;
    temp = reinterpret_cast<uaddr>(m_88);
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(1);
    }
}
