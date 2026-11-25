#ifndef PSO_ITEM_TITEMTOOLTRAPVISION_H
#define PSO_ITEM_TITEMTOOLTRAPVISION_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolTrapVision : public TItemObject {
public:
    TItemToolTrapVision(TObject *parent, u8 *item);
    virtual ~TItemToolTrapVision();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
