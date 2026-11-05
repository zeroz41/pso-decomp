#ifndef PSO_ITEM_TUNK_804A0CB8_H
#define PSO_ITEM_TUNK_804A0CB8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A0CB8 : public TItemWeapon {
public:
    virtual ~TUnk_804A0CB8();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
};

extern "C" {
void *belra_cannon_ct(void *player);
}

#endif
