#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void TWindowSubStatusDisp::set_selected_index(s16 arg1) {
    *(s16 *)((s8 *)this + 0x88) = arg1;
    *(s16 *)((s8 *)this + 0x74) = arg1;
    refresh_selected_entry(0);
}
