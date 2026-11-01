#include "types.h"
#include "pso/misc/TUnk_804CE7E8.h"
#include "pso/misc/TWindowSubStatusDisp.h"

void TWindowSubStatusDisp::draw_status(s32 arg1, s32 arg2, s32 arg3) {
    ((TWindowSubStatusDisp *)arg1)->append_entry(0, arg2, arg3, 0, 1);
}

void TWindowSubStatusDisp::dispatch_without_flags(s32 arg1, s32 arg2, s32 arg3) {
    ((TWindowSubStatusDisp *)arg1)->append_entry(0, arg2, arg3, 0, 0);
}

void TUnk_804CE7E8::sync_level_field() {
    s16 temp_r4;

    if (*(s16 *)((s8 *)this + 0x88) != (temp_r4 = *(s16 *)&this->cursor)) {
        *(s16 *)((s8 *)this + 0x88) = temp_r4;
        advance_all_entries(1);
    }
}
