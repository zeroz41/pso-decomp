#ifndef PSO_ITEM_TUNK_8049FD48_H
#define PSO_ITEM_TUNK_8049FD48_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FD48 : public TItemObject {
public:
    TUnk_8049FD48(TObject *parent, u8 *item);
    virtual ~TUnk_8049FD48();
    virtual void apply_use_effect();
};

TItem *create_telepipe_item(u8 *item);

#endif
