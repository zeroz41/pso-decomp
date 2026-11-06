#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int heap_alloc__5THeapFUl(void*, void*);

    extern int obj_heap;
void TLobby::heap_alloc(void* a0) { heap_alloc__5THeapFUl((void*)obj_heap, a0); }

}
