#ifndef PSO_WEAPON_TITEMWEAPONFLOWERBOUQUET_H
#define PSO_WEAPON_TITEMWEAPONFLOWERBOUQUET_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponFlowerBouquet : public TItemWeapon {
public:
    virtual ~TItemWeaponFlowerBouquet();
    virtual void emit_marker_effects();
    TItemWeaponFlowerBouquet(TObject *parent, u8 *item);
};

// Factory
extern "C" {
TItem *TObjPlayer__sub_801229EC(u8 *item);
}

#endif
