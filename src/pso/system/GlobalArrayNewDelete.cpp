#include "types.h"
#include "pso/system/memory.h"

void operator delete[](void *allocation) {
    if (allocation != NULL) {
        xfree(allocation);
    }
}

void *operator new[](size_t size) { return xmalloc(size); }

