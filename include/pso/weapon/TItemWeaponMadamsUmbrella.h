#ifndef PSO_WEAPON_TITEMWEAPONMADAMSUMBRELLA_H
#define PSO_WEAPON_TITEMWEAPONMADAMSUMBRELLA_H
#include "pso/weapon/WeaponCanopyScale.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Madam's Umbrella weapon class (vtable 0x804A67D0): the canopy opens while
// idle and closes during an attack; on_equipped starts a regeneration timer.
class TItemWeaponMadamsUmbrella : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void on_equipped();
    virtual void update_idle();
    virtual void update_attack();
    virtual ~TItemWeaponMadamsUmbrella();
    TItemWeaponMadamsUmbrella(TObject *parent, u8 *item);
    WeaponCanopyScale scale;  // canopy scale (scale_current_matrix)
};

#endif
