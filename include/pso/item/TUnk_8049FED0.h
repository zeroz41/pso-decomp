#ifndef PSO_ITEM_TUNK_8049FED0_H
#define PSO_ITEM_TUNK_8049FED0_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FED0 : public TItemObject {
public:
    TUnk_8049FED0(TObject *parent, u8 *item);
    virtual ~TUnk_8049FED0();
    virtual void apply_use_effect();
    static TUnk_8049FED0 *create(u8 *item);
};

#endif
