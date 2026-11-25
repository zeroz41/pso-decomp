#ifndef PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#define PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name TObjPlayer__sub_8012B0F8), made by
// TObjPlayer::create_obj_8012B140.
class TItemWeaponPArmsBlade : public TItemWeapon {
public:
    virtual ~TItemWeaponPArmsBlade();
    virtual void draw_held_model();
    TItemWeaponPArmsBlade(TObject *parent, u8 *item);
    s16 sub_8012B1F8();
    void sub_8012B1F0(s16);
};

#endif
