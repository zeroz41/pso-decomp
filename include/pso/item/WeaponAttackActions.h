#ifndef PSO_ITEM_WEAPONATTACKACTIONS_H
#define PSO_ITEM_WEAPONATTACKACTIONS_H

#include "types.h"

u32 pack_weapon_trail_color(void *weapon);

// TItemWeapon's virtuals under their own symbols, for the vtables still
// written as data.
extern "C" {
void vfunc_60__11TItemWeaponFv(void);
void vfunc_59__11TItemWeaponFv(void);
void vfunc_58__11TItemWeaponFv(void);
void vfunc_57__11TItemWeaponFv(void);
void update_idle__11TItemWeaponFv(void);
}

#endif
