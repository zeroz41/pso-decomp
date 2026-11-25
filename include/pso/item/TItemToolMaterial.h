#ifndef PSO_ITEM_TITEMTOOLMATERIAL_H
#define PSO_ITEM_TITEMTOOLMATERIAL_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolMaterial : public TItemObject {
public:
    TItemToolMaterial(TObject *parent, u8 *item);
    virtual ~TItemToolMaterial();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
