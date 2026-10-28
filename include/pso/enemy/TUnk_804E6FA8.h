#ifndef PSO_ENEMY_TUNK_804E6FA8_H
#define PSO_ENEMY_TUNK_804E6FA8_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_804E6FA8 : public TItemObject {
public:
    TUnk_804E6FA8(TObject *parent, u8 *item);
    virtual ~TUnk_804E6FA8();
    virtual void apply_use_effect();
};

TItem *create_add_slot_item(u8 *item);

#endif
