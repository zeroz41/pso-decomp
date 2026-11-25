#ifndef PSO_WEAPON_TITEMWEAPONSWORD_H
#define PSO_WEAPON_TITEMWEAPONSWORD_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class made by TItemWeaponSword::create (old ctor name
// TObjPlayer::init_from_item).
class TItemWeaponSword : public TItemWeapon {
public:
    virtual ~TItemWeaponSword();
    virtual void transform_model_node();
    virtual void update_weapon();
    TItemWeaponSword(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 glows;  // item[2] == 5 or item[1] == 0x8F: projection-tex model pass, weapon flag 0x800 (name inferred)
};

#endif
