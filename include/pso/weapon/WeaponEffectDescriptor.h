#ifndef PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H
#define PSO_WEAPON_WEAPONEFFECTDESCRIPTOR_H

#include "pso/item/TUnk_804E355C.h"
#include "pso/system/NinjaTypes.h"
#include <stddef.h>

// Weapon overrides and the collider constructor share this shot record.
struct Desc_8011E5C4 : S_802E451C {
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

LAYOUT_ASSERT(WeaponEffectDescriptorSize, sizeof(Desc_8011E5C4) == 0x80);
LAYOUT_ASSERT(WeaponEffectDescriptorModelOffset, offsetof(Desc_8011E5C4, model) == 0x44);
LAYOUT_ASSERT(WeaponEffectDescriptorColorOffset, offsetof(Desc_8011E5C4, color) == 0x60);
LAYOUT_ASSERT(WeaponEffectDescriptorWallOffset, offsetof(Desc_8011E5C4, wall_effect) == 0x70);
LAYOUT_ASSERT(WeaponEffectDescriptorHitOffset, offsetof(Desc_8011E5C4, hit_effect) == 0x74);

extern "C" Desc_8011E5C4 *TObjPlayer__sub_802E449C(Desc_8011E5C4 *params);

#endif
