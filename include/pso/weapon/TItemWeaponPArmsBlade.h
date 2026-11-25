#ifndef PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#define PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name TObjPlayer__sub_8012B0F8), made by
// TItemWeaponPArmsBlade::create.
class TItemWeaponPArmsBlade : public TItemWeapon {
public:
    virtual ~TItemWeaponPArmsBlade();
    virtual void draw_held_model();
    TItemWeaponPArmsBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s16 get_photon_color_id();
    void set_photon_color_id(s16);
};

#endif
