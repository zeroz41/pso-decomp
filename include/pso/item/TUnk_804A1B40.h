#ifndef PSO_ITEM_TUNK_804A1B40_H
#define PSO_ITEM_TUNK_804A1B40_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Weapon class with vtable 0x804A1B40 (old ctor name TObjPlayer__sub_80123904): reserved_53 also
// draws the second model at joint 0x23. Made by TObjPlayer__sub_80123950.
class TUnk_804A1B40 : public TItemWeapon {
public:
    virtual ~TUnk_804A1B40();
    virtual void reserved_53();
    TUnk_804A1B40(TObject *parent, u8 *item);
};

extern "C" {
u8 *TObjPlayer__sub_80123950(u8 *item);
}

#endif
