#ifndef PSO_WEAPON_TITEMWEAPONTSUMIKIRI_H
#define PSO_WEAPON_TITEMWEAPONTSUMIKIRI_H
#include <stddef.h>
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Tsumikiri J-Sword (weapon group 0x32) and the Berdysh (0x3D, smaller effect radius): each
// spawns a TItemEffPG wave of effect_radius around its owner from activate_effect.
class TItemWeaponTsumikiri : public TItemWeapon {
public:
    TItemWeaponTsumikiri(TObject *parent, u8 *item);
    virtual ~TItemWeaponTsumikiri();
    virtual void activate_effect(s32);
    void spawn_pg_effect(const Vec *origin, saddr item, f32 radius);
    virtual void emit_marker_effects();
    f32 effect_radius;
};

LAYOUT_ASSERT(TItemWeaponTsumikiri_size, sizeof(TItemWeaponTsumikiri) == 0x1FC);
LAYOUT_ASSERT(TItemWeaponTsumikiri_radius_offset, offsetof(TItemWeaponTsumikiri, effect_radius) == 0x1F8);

// Made for weapon groups 0x32 and 0x3D.
TItem *create_photon_field_weapon(u8 *item);

#endif
