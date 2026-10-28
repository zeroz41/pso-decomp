#ifndef PSO_ITEM_TUNK_8049FF88_H
#define PSO_ITEM_TUNK_8049FF88_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FF88 : public TItemObject {
public:
    TUnk_8049FF88(TObject *parent, u8 *item);
    virtual ~TUnk_8049FF88();
    virtual void apply_use_effect();
};

TItem *create_item_grinder(u8 *item);

#endif
