#ifndef PSO_UNK_TUNK_8049FBC0_H
#define PSO_UNK_TUNK_8049FBC0_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FBC0 : public TItemObject {
public:
    TUnk_8049FBC0(TObject *parent, u8 *item);
    virtual ~TUnk_8049FBC0();
    virtual void apply_use_effect();
};

TItem *create_material_item(u8 *item);

#endif
