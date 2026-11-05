#ifndef PSO_ITEM_TUNK_804A2770_H
#define PSO_ITEM_TUNK_804A2770_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2770 : public TItemWeapon {
public:
    virtual ~TUnk_804A2770();
    virtual void emit_marker_effects();
};

extern "C" {
void *TObjPlayer__sub_80125F24(void *weapon, s32 parent, void *item);
}

#endif
