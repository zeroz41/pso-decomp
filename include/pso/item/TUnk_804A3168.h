#ifndef PSO_ITEM_TUNK_804A3168_H
#define PSO_ITEM_TUNK_804A3168_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3168 : public TItemWeapon {
public:
    virtual ~TUnk_804A3168();
    virtual void emit_marker_effects();
};

extern "C" {
u8 *TObjPlayer__sub_801272B4(void *self_, s32 a, void *b);
u8 *TObjPlayer__sub_80127314(u8 *arg0);
}

#endif
