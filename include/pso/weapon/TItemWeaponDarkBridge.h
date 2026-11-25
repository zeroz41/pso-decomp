#ifndef PSO_WEAPON_TITEMWEAPONDARKBRIDGE_H
#define PSO_WEAPON_TITEMWEAPONDARKBRIDGE_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Built by dark_bridge_create. While the owner's TP drops, half of the loss
// is taken from their HP and given back as TP (update_weapon).
class TItemWeaponDarkBridge : public TItemWeapon {
public:
    TItemWeaponDarkBridge(TObject *parent, u8 *item);
    virtual ~TItemWeaponDarkBridge();
    virtual void update_weapon();
    virtual void on_equipped();
    virtual void on_unequipped();
    s32 pad_1f8;
    s16 owner_tp;  // the owner's TP last frame (get_actor_tp)
    u8 pad_1fe[0x2];
};

TItem *dark_bridge_create(u8 *item);

#endif
