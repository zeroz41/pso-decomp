#ifndef PSO_SYSTEM_SAVE_TCHECKMEMORYCARDTYPES_H
#define PSO_SYSTEM_SAVE_TCHECKMEMORYCARDTYPES_H

#include "types.h"

// Text of one card message: the entry is replaced by keyboard_entry while the keyboard controller is in use.
struct CheckMemoryCardText {
    s32 group;
    s32 entry;
    s32 keyboard_entry;
};

// One entry per state: enter is called by set_state, run by run_task every frame.
struct CheckMemoryCardState {
    void (TCheckMemoryCard::*enter)();
    void (TCheckMemoryCard::*run)();
};
LAYOUT_ASSERT(CheckMemoryCardState_size, sizeof(CheckMemoryCardState) == 0x18);
LAYOUT_ASSERT(CheckMemoryCardState_run_offset, offsetof(CheckMemoryCardState, run) == 0xC);

#endif
