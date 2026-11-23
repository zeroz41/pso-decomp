#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H

#include "types.h"

struct TItem;

struct TObjPlayer;
extern "C" {
void *__dt__13TUnk_804A2164Fv(void *arg0, s16 arg1);
}
TItem *create_drill_launcher(u8 *arg0);
extern "C" {
void *ct_shoot_model__10TObjPlayerFPv(void *arg0);
}
s32 drill_launcher_create_shot(s32 owner, s32 pos, s32 dir, f32 life);
void *drill_launcher_ct(void *a0, s32 _w1, void *_w2);
void drill_launcher_return_timer(void *arg0);
s32 get_burst_counter(void *p);
void increment_burst_counter(u8 *counter);

#endif
