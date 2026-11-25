#ifndef PSO_WEAPON_TITEMWEAPONTWINKLESTAR_H
#define PSO_WEAPON_TITEMWEAPONTWINKLESTAR_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Twinkle Star weapon class: update_weapon spins the
// stars, transform_model_node turns model nodes 1 and 3 by star_angle. Made by
// TItemWeaponTwinkleStar::create.
class TItemWeaponTwinkleStar : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual ~TItemWeaponTwinkleStar();
    TItemWeaponTwinkleStar(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 star_angle;  // BAMS, +0xCCC per update_weapon
};

#endif
