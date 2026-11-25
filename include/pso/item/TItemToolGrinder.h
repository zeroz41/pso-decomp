#ifndef PSO_ITEM_TITEMTOOLGRINDER_H
#define PSO_ITEM_TITEMTOOLGRINDER_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TItemToolGrinder : public TItemObject {
public:
    TItemToolGrinder(TObject *parent, u8 *item);
    virtual ~TItemToolGrinder();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};


#endif
