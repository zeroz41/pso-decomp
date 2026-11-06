#include "pso/system/AllocatorCallbacks.h"
#include "pso/system/memory.h"

extern AllocatorCallbacks *global_allocator;
#pragma push
#pragma scheduling off
void xfree(void *arg0) {
    global_allocator->release(arg0, global_allocator);
}

#pragma pop
