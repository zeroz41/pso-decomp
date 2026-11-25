#ifndef PSO_ITEM_TITEMTOOLKILLCOUNTER_H
#define PSO_ITEM_TITEMTOOLKILLCOUNTER_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolKillCounter : public TItemObject {
public:
    TItemToolKillCounter(TObject *parent, u8 *item);
    virtual ~TItemToolKillCounter();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
