#ifndef PSO_WEAPON_TITEMWEAPONNUG2000BAZOOKA_H
#define PSO_WEAPON_TITEMWEAPONNUG2000BAZOOKA_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

struct ActorBodyHit;

// The NUG2000-Bazooka (weapon group 0x8D): one shot from joint 1 that explodes where it hits.
class TItemWeaponNug2000Bazooka : public TItemWeapon {
public:
    virtual ~TItemWeaponNug2000Bazooka();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    TItemWeaponNug2000Bazooka(TObject *parent, u8 *item);
};

TItem *create_nug2000_bazooka(u8 *item);
// The shot's explosion at pos: a TExplosionCollider with the weapon's status and a TFireExplosion.
void spawn_fire_explosion_at(TItemWeapon *weapon, const Vec *pos);
// The wall_effect: the explosion where the shot hits a wall.
void spawn_nug2000_wall_explosion(s32 item_id, const Vec *pos);
// The hit_effect: the explosion at the centre of the body the shot hits.
void spawn_nug2000_hit_explosion(s32 item_id, ActorBodyHit *hit);

#endif
