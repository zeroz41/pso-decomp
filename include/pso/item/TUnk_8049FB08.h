#ifndef PSO_ITEM_TUNK_8049FB08_H
#define PSO_ITEM_TUNK_8049FB08_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FB08 : public TItemObject {
public:
    TUnk_8049FB08(TObject *parent, u8 *item);
    virtual ~TUnk_8049FB08();
    virtual void apply_use_effect();
};

TItem *create_star_atomizer_item(u8 *item);

#endif
