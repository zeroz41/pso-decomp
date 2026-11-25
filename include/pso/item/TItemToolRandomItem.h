#ifndef PSO_ITEM_TITEMTOOLRANDOMITEM_H
#define PSO_ITEM_TITEMTOOLRANDOMITEM_H
#include "types.h"
#include "pso/item/TItemObject.h"

// Turns into one of the items its ItemPMT entry lists, picked at random.
class TItemToolRandomItem : public TItemObject {
public:
    TItemToolRandomItem(TObject *parent, u8 *item);
    virtual ~TItemToolRandomItem();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
