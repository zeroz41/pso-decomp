#include "types.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {
void TWindowSubEquip::apply_slot_selection() {
    s32 temp_r31;
    temp_r31 = ((TWindowMenuIconLine *)this->m_34)->get_cursor_value();
    TWindowShortListCtrl::assign_shortcut(temp_r31, (int) (((TWindowMenuIconLine *)this->m_38)->get_cursor_value()), this->m_28);
}

}
