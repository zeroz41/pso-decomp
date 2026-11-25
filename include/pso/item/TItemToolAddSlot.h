#ifndef PSO_ITEM_TITEMTOOLADDSLOT_H
#define PSO_ITEM_TITEMTOOLADDSLOT_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolAddSlot : public TItemObject {
public:
    TItemToolAddSlot(TObject *parent, u8 *item);
    virtual ~TItemToolAddSlot();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
