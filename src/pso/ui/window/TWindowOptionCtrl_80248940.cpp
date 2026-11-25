#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItem.h"

s32 TWindowOptionCtrl::update_selected_item() {
    return ((ItemListRow *)((TWindowBase *)this)->get_array_entry(*(s16 *)((s8 *)this + 0x88)))->get_item();
}

void TWindowSubStatusDisp::set_selected_index(s16 selected_index) {
    *(s16 *)((s8 *)this + 0x88) = selected_index;
    *(s16 *)((s8 *)this + 0x74) = selected_index;
    refresh_selected_entry(0);
}
