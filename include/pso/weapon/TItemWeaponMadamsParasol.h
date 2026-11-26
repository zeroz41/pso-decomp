#ifndef PSO_WEAPON_TITEMWEAPONMADAMSPARASOL_H
#define PSO_WEAPON_TITEMWEAPONMADAMSPARASOL_H
#include "pso/weapon/WeaponCanopyScale.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Madam's Parasol weapon class: the canopy opens while
// idle and closes during an attack; on_equipped starts a regeneration timer.
class TItemWeaponMadamsParasol : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void on_equipped();
    virtual void update_idle();
    virtual void update_attack();
    virtual ~TItemWeaponMadamsParasol();
    TItemWeaponMadamsParasol(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    WeaponCanopyScale scale;  // canopy scale (scale_current_matrix)
};


#endif
