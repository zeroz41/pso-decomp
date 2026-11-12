#ifndef PSO_UNK_TEXT_8042EAD4_H
#define PSO_UNK_TEXT_8042EAD4_H

#include "types.h"
#include "pso/unk/SharedMemory.h"

extern "C" {
s32 fn_8042EAD4(u8 *arg0, u32 arg1);
void fn_8042EBA4(DolHeader *dol_image, s32 arg1);
s32 fn_8042ED98(s32 arg0, const char *arg1);
}

// --- C functions defined in text_8042EAD4.cpp ---
extern "C" {
s32 fn_8042EAD4(u8 *arg0, u32 arg1);
void fn_8042EBA4(DolHeader *dol_image, s32 arg1);
s32 fn_8042ED98(s32 arg0, const char *arg1);
}
// --- end of C functions

#endif
