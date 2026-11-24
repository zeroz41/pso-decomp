#ifndef PSO_UNK_TEXT_8042EAD4_H
#define PSO_UNK_TEXT_8042EAD4_H

#include "types.h"
#include "pso/unk/SharedMemory.h"

extern "C" {
s32 fn_8042EAD4(u8 *source, u32 size);
void fn_8042EBA4(DolHeader *dol_image, s32 arg1);
void TAdTrialModemChkGC__sub_8042EC14();
s32 fn_8042ED98(s32 index, const char *text);
}

#endif
