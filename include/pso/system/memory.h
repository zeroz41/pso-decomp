#ifndef PSO_SYSTEM_MEMORY_H
#define PSO_SYSTEM_MEMORY_H

#include "types.h"

void move_words(void *destination, const void *source, s32 count);

void xfree(void *p);
void * xmalloc(u32 bytes);

#endif
