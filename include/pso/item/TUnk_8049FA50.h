#ifndef PSO_ITEM_TUNK_8049FA50_H
#define PSO_ITEM_TUNK_8049FA50_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FA50 : public TItemObject {
public:
    TUnk_8049FA50(TObject *parent, u8 *item);
    virtual ~TUnk_8049FA50();
    virtual void apply_use_effect();
};

TItem *create_sol_atomizer_item(u8 *item);

#endif
