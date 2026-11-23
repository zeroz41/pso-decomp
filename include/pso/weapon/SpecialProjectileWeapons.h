#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H

#include "types.h"

struct TItem;

struct TObjPlayer;
extern "C" {
void *__dt__13TUnk_804A2164Fv(void *object, s16 delete_mode);
}
TItem *create_drill_launcher(u8 *item);
extern "C" {
void *ct_shoot_model__10TObjPlayerFPv(void *owner);
}
s32 drill_launcher_create_shot(s32 owner, s32 pos, s32 dir, f32 life);
void *drill_launcher_ct(void *weapon, s32 client, void *item);
void drill_launcher_return_timer(void *weapon);
s32 get_burst_counter(void *p);
void increment_burst_counter(u8 *counter);

#endif
