#ifndef PSO_WEAPON_WEAPONATTACKACTIONS_H
#define PSO_WEAPON_WEAPONATTACKACTIONS_H

#include "types.h"

struct TItemWeapon;

u32 pack_weapon_trail_color(TItemWeapon *weapon);

struct NJS_OBJECT;

void apply_weapon_node_material(NJS_OBJECT *);

// The weapon light's direction and colour (WeaponAttackActionData .rodata).
extern Vec weapon_light_direction[];
extern NJS_ARGB weapon_light_color[];
extern s16 weapon_node_ids[];
extern s16 weapon_node_material_index;
extern TItemWeapon *weapon_render_callback_object;
extern u8 weapon_unidentified_flag;
struct WeaponColorDescriptor { s32 mode; NJS_ARGB first, second; };

#endif
