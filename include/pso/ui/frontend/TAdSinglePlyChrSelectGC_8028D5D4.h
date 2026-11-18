#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_8028D5D4_H

#include "types.h"

extern "C" {
u8 is_selection_done__23TAdSinglePlyChrSelectGCFPv(void *arg0);
}

void alloc_quest_download_buffer(void);
extern "C" {
void fn_8028D8F4(void);
void fn_8028D940(void);
}

// inferred: the three character-creation effect objects fn_8028D940 creates and fn_8028D8F4 destroys.
struct RecoveredGlobal_lbl_8051C070 { s32 value; u8 remaining[0x8]; };
extern RecoveredGlobal_lbl_8051C070 lbl_8051C070;

#endif
