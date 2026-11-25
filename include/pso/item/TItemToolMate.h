#ifndef PSO_ITEM_TITEMTOOLMATE_H
#define PSO_ITEM_TITEMTOOLMATE_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolMate : public TItemObject {
public:
    TItemToolMate(TObject *parent, u8 *item);
    virtual ~TItemToolMate();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
