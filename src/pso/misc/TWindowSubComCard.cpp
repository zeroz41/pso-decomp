#include "types.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

s32 TQuestListOnline::get_selection_stage() { return selection_stage; }

void TWindowSubComCard::clear_flag_and_release() {
    u32 temp;
    *(u16 *)((s8 *)this + 0x70) = (u16) (*(u16 *)((s8 *)this + 0x70) & 0xFFFFFFFD);
    temp = (u32) *(u32 *)((s8 *)this + 0x88);
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(1);
    }
}
