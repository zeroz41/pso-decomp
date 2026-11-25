#ifndef PSO_ITEM_TITEMTOOLMOONATOMIZER_H
#define PSO_ITEM_TITEMTOOLMOONATOMIZER_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolMoonAtomizer : public TItemObject {
public:
    TItemToolMoonAtomizer(TObject *parent, u8 *item);
    virtual ~TItemToolMoonAtomizer();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
