#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void TWindowSubStatusDisp::set_selected_index(s16 selected_index) {
    *(s16 *)((s8 *)this + 0x88) = selected_index;
    *(s16 *)((s8 *)this + 0x74) = selected_index;
    refresh_selected_entry(0);
}
