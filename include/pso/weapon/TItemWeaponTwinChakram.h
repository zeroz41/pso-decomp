#ifndef PSO_WEAPON_TITEMWEAPONTWINCHAKRAM_H
#define PSO_WEAPON_TITEMWEAPONTWINCHAKRAM_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TObjPlayer::create_twin_chakram.
class TItemWeaponTwinChakram : public TItemWeapon {
public:
    virtual ~TItemWeaponTwinChakram();
    TItemWeaponTwinChakram(TObject *parent, u8 *item);
};

#endif
