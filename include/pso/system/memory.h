#ifndef PSO_SYSTEM_MEMORY_H
#define PSO_SYSTEM_MEMORY_H

#include "types.h"

void *mem_alloc(u32 bytes);
// C linkage: the runtime's __destroy_new_array frees through it.
extern "C" void mem_free(void *allocation);

// new[] takes its block, array header included, from mem_alloc.
inline void *operator new[](size_t size) { return mem_alloc(size); }
inline void operator delete[](void *allocation) { mem_free(allocation); }

void move_words(void *destination, const void *source, s32 count);

void safe_free(void *allocation);
void xfree(void *p);
void * xmalloc(u32 bytes);
void *xcalloc(s32 count, s32 size);

void fill_memory(void *p, u8 c, u32 n);
void init_system_heap_and_global_allocator(u8 *start, s32 size);

// The system heap's entry points (sys_allocator_func_table).
void *sys_alloc(u32 size);
void free_to_sys_heap(void *ptr);
void *sys_calloc(s32 count, s32 size);
void *sys_heap_realloc(void *ptr, u32 size);

#endif
