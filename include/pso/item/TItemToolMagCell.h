#ifndef PSO_ITEM_TITEMTOOLMAGCELL_H
#define PSO_ITEM_TITEMTOOLMAGCELL_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolMagCell : public TItemObject {
public:
    TItemToolMagCell(TObject *parent, u8 *item);
    virtual ~TItemToolMagCell();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
