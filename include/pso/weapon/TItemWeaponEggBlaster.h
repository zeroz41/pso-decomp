#ifndef PSO_WEAPON_TITEMWEAPONEGGBLASTER_H
#define PSO_WEAPON_TITEMWEAPONEGGBLASTER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponEggBlaster : public TItemWeapon {
public:
    virtual ~TItemWeaponEggBlaster();
    TItemWeaponEggBlaster(TObject *parent, u8 *item);
};

#endif
