#ifndef PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H
#define PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H

#include "pso/item/TItemAttackColBase.h"
#include "pso/system/NinjaTypes.h"
#include <stddef.h>

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
    void *wall_effect;
    void *hit_effect;
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
