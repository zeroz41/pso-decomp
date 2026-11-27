#ifndef PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H
#define PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H

#include "pso/item/TItemAttackColBase.h"
#include "pso/system/NinjaTypes.h"
#include <stddef.h>

// Called when the collider hits a wall (or at once for an instant one):
// the weapon's item id, where it is and its velocity.
typedef void (*TItemAttackColHitWall)(s32 item_id, const Vec *position, Vec *velocity);
// Called for each target it hits: the weapon's item id, the target's
// ActorBodyHit entry and the collider's velocity.
typedef void (*TItemAttackColHitObject)(s32 item_id, ActorBodyHit *hit, Vec *velocity);

// Weapon overrides and the collider constructor share this shot record.
struct WeaponEffectDescriptor : AttackColParams {
    s32 rotation_y;
    Vec direction;
    f32 speed;
    f32 range;
    u32 flags;
    NJS_OBJECT *model;
    NJS_TEXLIST *texlist;
    f32 scale;
    s32 spin[3];
    f32 star_width;
    NJS_ARGB color;
    TItemAttackColHitWall wall_effect;
    TItemAttackColHitObject hit_effect;
    s32 particle;
    s32 trail_particle;
};

LAYOUT_ASSERT(WeaponEffectDescriptorSize, sizeof(WeaponEffectDescriptor) == 0x80);
LAYOUT_ASSERT(WeaponEffectDescriptorModelOffset, offsetof(WeaponEffectDescriptor, model) == 0x44);
LAYOUT_ASSERT(WeaponEffectDescriptorColorOffset, offsetof(WeaponEffectDescriptor, color) == 0x60);
LAYOUT_ASSERT(WeaponEffectDescriptorWallOffset, offsetof(WeaponEffectDescriptor, wall_effect) == 0x70);
LAYOUT_ASSERT(WeaponEffectDescriptorHitOffset, offsetof(WeaponEffectDescriptor, hit_effect) == 0x74);

WeaponEffectDescriptor *reset_weapon_effect_descriptor(WeaponEffectDescriptor *params);

#endif
