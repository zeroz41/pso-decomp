#ifndef PSO_WEAPON_WEAPONATTACKACTIONS_H
#define PSO_WEAPON_WEAPONATTACKACTIONS_H

#include "types.h"

struct TItemWeapon;

u32 pack_weapon_trail_color(TItemWeapon *weapon);

struct NJS_OBJECT;

void apply_weapon_node_material(NJS_OBJECT *);

extern s16 weapon_node_ids[];
extern s16 weapon_node_material_index;
extern u8 *weapon_render_callback_object;
extern const f32 weapon_float_zero;
extern const u8 weapon_unidentified_flag;
struct WeaponColorDescriptor { s32 mode; NJS_ARGB first, second; };

#endif
