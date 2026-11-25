#ifndef PSO_ITEM_TITEMTOOLSTATUSCURE_H
#define PSO_ITEM_TITEMTOOLSTATUSCURE_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolStatusCure : public TItemObject {
public:
    TItemToolStatusCure(TObject *parent, u8 *item);
    virtual ~TItemToolStatusCure();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
