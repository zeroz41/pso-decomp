#ifndef PSO_ITEM_TITEMHEAPOBJECT_H
#define PSO_ITEM_TITEMHEAPOBJECT_H
#include "pso/system/task/TObject.h"
class TItemHeapObject : public TObject {
public:
    TItemHeapObject(TObject* parent);
    virtual ~TItemHeapObject();
    void* operator new(size_t size);
    void operator delete(void* ptr);
};
LAYOUT_ASSERT(ItemHeapObjectSize, sizeof(TItemHeapObject)==0x1C);
#endif
