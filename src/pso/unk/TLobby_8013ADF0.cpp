#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/THeap.h"
#include "pso/network/TProtocol.h"


void *TProtocol::operator new(size_t size) { return obj_heap->heap_alloc(size); }

