#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

void TWindowOptionCtrl::add_menu_item(s32 arg1, s32 arg2, s32 arg3) {
    ((TWindowSubStatusDisp *)arg1)->append_entry(0, arg2, arg3, 1, 0);
}
