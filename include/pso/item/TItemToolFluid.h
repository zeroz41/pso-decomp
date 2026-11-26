#ifndef PSO_ITEM_TITEMTOOLFLUID_H
#define PSO_ITEM_TITEMTOOLFLUID_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolFluid : public TItemObject {
public:
    TItemToolFluid(TObject *parent, u8 *item);
    virtual ~TItemToolFluid();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
    // The TP the three kinds give (by item index).
    s16 get_max_tp();
    s16 calc_large_tp();
    s16 calc_small_tp();
};

#endif
