#ifndef PSO_UNK_TEXT_803DE7E0_H
#define PSO_UNK_TEXT_803DE7E0_H

#include "types.h"

void fill_memory(void *p, u8 c, u32 n);
void init_system_heap_and_global_allocator(u8 *start, s32 size);

void free_to_sys_heap(void *ptr);
void *sys_alloc(u32 size);
void *sys_calloc(s32 count, s32 size);

void *sys_heap_realloc(void *ptr, u32 size);

#endif
