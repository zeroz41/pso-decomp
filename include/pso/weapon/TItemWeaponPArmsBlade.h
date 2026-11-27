#ifndef PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#define PSO_WEAPON_TITEMWEAPONPARMSBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class, made by TItemWeaponPArmsBlade::create.
class TItemWeaponPArmsBlade : public TItemWeapon {
public:
    virtual ~TItemWeaponPArmsBlade();
    virtual void draw_held_model();
    TItemWeaponPArmsBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    // Nonzero on 30% of calls: the blade keeps its photon colour then.
    s32 is_rand_below_threshold();
    s16 get_photon_color_id();
    void set_photon_color_id(s16);
};

#endif
