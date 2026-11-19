#ifndef PSO_SYSTEM_ALLOCATORCALLBACKS_H
#define PSO_SYSTEM_ALLOCATORCALLBACKS_H

#include "types.h"

// An allocator's entry points; xmalloc, xfree and fn_803DE864 call slots 0-2 of global_allocator, and
// sys_allocator_func_table fills all four with the system heap's functions.
struct AllocatorCallbacks {
    void *(*allocate)(u32 size);
    void (*release)(void *ptr);
    void *(*allocate_zeroed)(s32 count, s32 size);
    void *(*reallocate)(void *ptr, u32 size);
};

extern "C" {
extern const AllocatorCallbacks *global_allocator;
}

#endif
