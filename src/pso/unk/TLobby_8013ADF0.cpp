#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/THeap.h"


    void *alloc_from_obj_heap(size_t size) { return obj_heap->heap_alloc(size); }

