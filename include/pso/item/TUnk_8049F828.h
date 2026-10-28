#ifndef PSO_ITEM_TUNK_8049F828_H
#define PSO_ITEM_TUNK_8049F828_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049F828 : public TItemObject {
public:
    TUnk_8049F828(TObject *parent, u8 *item);
    virtual ~TUnk_8049F828();
    virtual void apply_use_effect();
    static TUnk_8049F828 *create(u8 *item);
};

#endif
