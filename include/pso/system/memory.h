#ifndef PSO_SYSTEM_MEMORY_H
#define PSO_SYSTEM_MEMORY_H

#include "types.h"

extern "C" {
void *mem_alloc(u32 bytes);
void mem_free(void *allocation);
}

void move_words(void *destination, const void *source, s32 count);

void safe_free(void *allocation);
void xfree(void *p);
void * xmalloc(u32 bytes);

#endif
