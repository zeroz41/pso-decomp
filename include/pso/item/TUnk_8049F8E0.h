#ifndef PSO_ITEM_TUNK_8049F8E0_H
#define PSO_ITEM_TUNK_8049F8E0_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049F8E0 : public TItemObject {
public:
    TUnk_8049F8E0(TObject *parent, u8 *item);
    virtual ~TUnk_8049F8E0();
    virtual void apply_use_effect();
};

TItem *create_moon_atomizer_item(u8 *item);

#endif
