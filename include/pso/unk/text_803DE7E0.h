#ifndef PSO_UNK_TEXT_803DE7E0_H
#define PSO_UNK_TEXT_803DE7E0_H

#include "types.h"

void fill_memory(void *p, u8 c, u32 n);
extern "C" {
void init_system_heap_and_global_allocator(u8 *start, s32 size);
}

// --- C functions defined in text_803DE7E0.cpp ---
extern "C" {
void init_system_heap_and_global_allocator(u8 *start, s32 size);
}
// --- end of C functions

#endif
