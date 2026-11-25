#ifndef PSO_WEAPON_TITEMWEAPONHEARTOFPOUMN_H
#define PSO_WEAPON_TITEMWEAPONHEARTOFPOUMN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponHeartOfPoumn : public TItemWeapon {
public:
    TItemWeaponHeartOfPoumn(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponHeartOfPoumn();
    virtual void draw_held_model();
};

#endif
