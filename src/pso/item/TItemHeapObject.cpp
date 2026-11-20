#include "pso/item/TItemHeapObject.h"
#include "pso/system/THeap.h"
void TItemHeapObject::operator delete(void* ptr) { obj_heap->heap_free(ptr); }
void* TItemHeapObject::operator new(size_t size) { return obj_heap->heap_alloc(size); }
TItemHeapObject::TItemHeapObject(TObject* parent) : TObject(parent) {}
