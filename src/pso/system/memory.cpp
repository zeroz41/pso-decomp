#include "types.h"
#include <string.h>
#include <dolphin/os/OSAlloc.h>
#include "pso/system/AllocatorCallbacks.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby_803DE778.h"

const AllocatorCallbacks *global_allocator;
OSHeapHandle sys_heap_handle;

// The system heap's allocator, installed as global_allocator.
extern const AllocatorCallbacks sys_allocator_func_table = { sys_alloc, free_to_sys_heap, sys_calloc, sys_heap_realloc };

#pragma push
#pragma scheduling off
#pragma peephole off
void fill_memory(void *p, u8 c, u32 n) {
    memset(p, c, n);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

void init_system_heap_and_global_allocator(u8 *start, s32 size) {
    sys_heap_handle = OSCreateHeap(start, start + size);
    global_allocator = &sys_allocator_func_table;
}
#pragma pop

#pragma push
#pragma scheduling off
void * xmalloc(u32 bytes) {
    return global_allocator->allocate(bytes);
}
#pragma pop

void *xcalloc(s32 count, s32 size) {
    return global_allocator->allocate_zeroed(count, size);
}

#pragma push
#pragma scheduling off
void xfree(void *p) {
    global_allocator->release(p);
}
#pragma pop

#pragma push
#pragma scheduling off
void *sys_alloc(u32 size) {
    return OSAllocFromHeap(sys_heap_handle, size);
}
#pragma pop

#pragma push
#pragma scheduling off
void free_to_sys_heap(void *ptr) {
    OSFreeToHeap(sys_heap_handle, ptr);
}
#pragma pop

void *sys_calloc(s32 count, s32 size) {
    void *p = OSAllocFromHeap(sys_heap_handle, count * size);
    fill_memory(p, 0, count * size);
    return p;
}

// Allocates size bytes, copies size bytes of ptr into them and frees ptr.
void *sys_heap_realloc(void *ptr, u32 size) {
    void *p = OSAllocFromHeap(sys_heap_handle, size);
    move_data((p), (ptr), size);
    OSFreeToHeap(sys_heap_handle, ptr);
    return p;
}
