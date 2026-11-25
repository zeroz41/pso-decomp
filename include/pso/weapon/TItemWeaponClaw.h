#ifndef PSO_WEAPON_TITEMWEAPONCLAW_H
#define PSO_WEAPON_TITEMWEAPONCLAW_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponClaw : public TItemWeapon {
public:
    virtual ~TItemWeaponClaw();
    TItemWeaponClaw(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void draw_held_model();
};

#endif
