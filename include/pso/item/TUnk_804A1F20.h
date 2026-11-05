#ifndef PSO_ITEM_TUNK_804A1F20_H
#define PSO_ITEM_TUNK_804A1F20_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1F20 : public TItemWeapon {
public:
    virtual ~TUnk_804A1F20();
    virtual void update_weapon();
    TUnk_804A1F20(TObject *parent, u8 *item);
};

#endif
