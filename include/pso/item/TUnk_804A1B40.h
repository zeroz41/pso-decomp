#ifndef PSO_ITEM_TUNK_804A1B40_H
#define PSO_ITEM_TUNK_804A1B40_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1B40 : public TItemWeapon {
public:
    virtual ~TUnk_804A1B40();
    virtual void reserved_53();
};

extern "C" {
u8 *TObjPlayer__sub_80123904(u8 *player, u8 *arg1, s32 _w2);
u8 *TObjPlayer__sub_80123950(u8 *arg0);
}

#endif
