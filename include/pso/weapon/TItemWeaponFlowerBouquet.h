#ifndef PSO_WEAPON_TITEMWEAPONFLOWERBOUQUET_H
#define PSO_WEAPON_TITEMWEAPONFLOWERBOUQUET_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponFlowerBouquet : public TItemWeapon {
public:
    virtual ~TItemWeaponFlowerBouquet();
    virtual void emit_marker_effects();
    TItemWeaponFlowerBouquet(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
