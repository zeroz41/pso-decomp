#include "types.h"
#include "pso/misc/TWindowSubEquip.h"
#include "pso/misc/TWindowShortListCtrl.h"

extern "C" {
s32 get_cursor_value__19TWindowMenuIconLineFv(int);
void TWindowSubEquip::apply_slot_selection() {
    s32 temp_r31;
    temp_r31 = get_cursor_value__19TWindowMenuIconLineFv(this->m_34);
    TWindowShortListCtrl::assign_shortcut(temp_r31, (int) (get_cursor_value__19TWindowMenuIconLineFv(this->m_38)), this->m_28);
}

}
