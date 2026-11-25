#ifndef PSO_UNK_TEXT_803DE8BC_H
#define PSO_UNK_TEXT_803DE8BC_H

#include "types.h"

void free_to_sys_heap(void *ptr);
void *sys_alloc(u32 size);
void *sys_calloc(s32 arg0, s32 arg1);

void *sys_heap_realloc(void *ptr, u32 size);

#endif
