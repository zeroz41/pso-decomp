#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/THeap.h"

extern "C" {

void TLobby::heap_alloc(void* a0) { obj_heap->heap_alloc((size_t)a0); }

}
