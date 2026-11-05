#ifndef PSO_ITEM_TUNK_804A0EA8_H
#define PSO_ITEM_TUNK_804A0EA8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A0EA8 : public TItemWeapon {
public:
    virtual ~TUnk_804A0EA8();
    virtual void reserved_53();
    virtual void emit_marker_effects();
};

extern "C" {
void *guld_milla_ct(void *player);
}

#endif
