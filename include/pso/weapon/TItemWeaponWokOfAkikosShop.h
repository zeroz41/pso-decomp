#ifndef PSO_WEAPON_TITEMWEAPONWOKOFAKIKOSSHOP_H
#define PSO_WEAPON_TITEMWEAPONWOKOFAKIKOSSHOP_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name TObjPlayer__sub_80123904): draw_held_model also
// draws the second model at joint 0x23. Made by TObjPlayer__sub_80123950.
class TItemWeaponWokOfAkikosShop : public TItemWeapon {
public:
    virtual ~TItemWeaponWokOfAkikosShop();
    virtual void draw_held_model();
    TItemWeaponWokOfAkikosShop(TObject *parent, u8 *item);
};

extern "C" {
TItem *TObjPlayer__sub_80123950(u8 *item);
}

#endif
