#ifndef PSO_WEAPON_TITEMWEAPONSABER_H
#define PSO_WEAPON_TITEMWEAPONSABER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class made by TItemWeaponSaber::create (old ctor name
// TObjPlayer::init_state(long, void *)).
class TItemWeaponSaber : public TItemWeapon {
public:
    virtual ~TItemWeaponSaber();
    virtual void update_weapon();
    TItemWeaponSaber(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
