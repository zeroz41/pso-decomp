#ifndef PSO_ITEM_TUNK_8049F770_H
#define PSO_ITEM_TUNK_8049F770_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049F770 : public TItemObject {
public:
    TUnk_8049F770(TObject *parent, u8 *item);
    virtual ~TUnk_8049F770();
    virtual void apply_use_effect();
    static TUnk_8049F770 *create(u8 *item);
};

#endif
