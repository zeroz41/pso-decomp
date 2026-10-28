#ifndef PSO_ITEM_TUNK_8049F998_H
#define PSO_ITEM_TUNK_8049F998_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049F998 : public TItemObject {
public:
    TUnk_8049F998(TObject *parent, u8 *item);
    virtual ~TUnk_8049F998();
    virtual void apply_use_effect();
};

TItem *create_status_cure_item(u8 *item);

#endif
