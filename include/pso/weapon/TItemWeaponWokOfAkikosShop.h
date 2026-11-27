#ifndef PSO_WEAPON_TITEMWEAPONWOKOFAKIKOSSHOP_H
#define PSO_WEAPON_TITEMWEAPONWOKOFAKIKOSSHOP_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class: draw_held_model also
// draws the second model at joint 0x23. Made by TItemWeaponWokOfAkikosShop::create.
class TItemWeaponWokOfAkikosShop : public TItemWeapon {
public:
    virtual ~TItemWeaponWokOfAkikosShop();
    virtual void draw_held_model();
    TItemWeaponWokOfAkikosShop(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
