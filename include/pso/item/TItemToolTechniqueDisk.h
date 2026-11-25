#ifndef PSO_ITEM_TITEMTOOLTECHNIQUEDISK_H
#define PSO_ITEM_TITEMTOOLTECHNIQUEDISK_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolTechniqueDisk : public TItemObject {
public:
    TItemToolTechniqueDisk(TObject *parent, u8 *item);
    virtual ~TItemToolTechniqueDisk();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
