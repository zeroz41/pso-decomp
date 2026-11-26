#ifndef PSO_WEAPON_TITEMWEAPONTWINCHAKRAM_H
#define PSO_WEAPON_TITEMWEAPONTWINCHAKRAM_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TItemWeaponTwinChakram::create.
class TItemWeaponTwinChakram : public TItemWeapon {
public:
    virtual ~TItemWeaponTwinChakram();
    TItemWeaponTwinChakram(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
