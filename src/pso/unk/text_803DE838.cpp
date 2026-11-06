#include "pso/system/AllocatorCallbacks.h"
#include "pso/system/memory.h"
#include <stddef.h>
typedef char AllocatorAllocateOffset[(offsetof(AllocatorCallbacks, allocate) == 0) ? 1 : -1];
typedef char AllocatorReleaseOffset[(offsetof(AllocatorCallbacks, release) == 4) ? 1 : -1];

extern AllocatorCallbacks *global_allocator;
#pragma push
#pragma scheduling off
void * xmalloc(u32 bytes) {
    return global_allocator->allocate(bytes, global_allocator);
}

#pragma pop
