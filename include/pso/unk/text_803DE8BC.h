#ifndef PSO_UNK_TEXT_803DE8BC_H
#define PSO_UNK_TEXT_803DE8BC_H

#include "types.h"

void free_to_sys_heap(void *ptr);
void *sys_alloc(u32 size);
void *sys_calloc(s32 arg0, s32 arg1);

// --- C functions defined in text_803DE8BC.cpp ---
extern "C" {
void *fn_803DE960(void *ptr, u32 size);
}
// --- end of C functions

#endif
