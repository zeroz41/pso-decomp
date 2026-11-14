#include "types.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowBase.h"

extern "C" {

s32 get_cursor_pos__14TWindowSubItemFv();

void TWindowOptionCtrl::update_selected_item() {
    ((TWindowBase *)this)->get_array_entry(*(s16 *)((s8 *)this + 0x88));
    get_cursor_pos__14TWindowSubItemFv();
}

}
