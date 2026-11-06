#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H

#include "types.h"

struct TObjPlayer;
extern "C" {
void *TObjPlayer__sub_8012417C(void *arg0, s16 arg1);
void *TObjPlayer__sub_80124694(TObjPlayer *arg0);
u8 *TObjPlayer__sub_80124708(u8 *arg0);
void *__dt__13TUnk_804A204CFv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A2164Fv(void *arg0, s16 arg1);
}
u8 *create_drill_launcher(u8 *arg0);
extern "C" {
void create_icon__10TObjPlayerFiii(s32 parent, s32 arg1, s32 arg2);
void *ct_shoot_model__10TObjPlayerFPv(void *arg0);
}
s32 drill_launcher_create_shot(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
void *drill_launcher_ct(void *a0, s32 _w1, void *_w2);
void drill_launcher_return_timer(void *arg0);
extern "C" {
s32 get_burst_counter(void *p);
void increment_burst_counter(u8 *arg0);
}

#endif
