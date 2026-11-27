#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H

#include "types.h"

struct TItem;

struct TObjPlayer;
TItemShoot *drill_launcher_create_shot(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
void *drill_launcher_ct(void *weapon, s32 client, void *item);
void drill_launcher_return_timer(void *weapon);

#endif
