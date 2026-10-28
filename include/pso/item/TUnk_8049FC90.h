#ifndef PSO_ITEM_TUNK_8049FC90_H
#define PSO_ITEM_TUNK_8049FC90_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FC90 : public TItemObject {
public:
    TUnk_8049FC90(TObject *parent, u8 *item);
    virtual ~TUnk_8049FC90();
    virtual void apply_use_effect();
};

TItem *create_technique_disk_item(u8 *item);

#endif
