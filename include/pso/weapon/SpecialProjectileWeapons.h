#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONS_H

#include "types.h"

struct TItem;

struct TObjPlayer;
extern "C" {
void *TObjPlayer__sub_8012417C(void *object, s16 delete_mode);
void *TObjPlayer__sub_80124694(TObjPlayer *player);
TItem *TObjPlayer__sub_80124708(u8 *item);
void *__dt__13TUnk_804A204CFv(void *object, s16 delete_mode);
void *__dt__13TUnk_804A2164Fv(void *object, s16 delete_mode);
}
TItem *create_drill_launcher(u8 *item);
extern "C" {
void create_icon__10TObjPlayerFiii(saddr parent, s32 item_id, s32 joint);
void *ct_shoot_model__10TObjPlayerFPv(void *owner);
}
s32 drill_launcher_create_shot(s32 owner, s32 pos, s32 dir, f32 life);
void *drill_launcher_ct(void *weapon, s32 client, void *item);
void drill_launcher_return_timer(void *weapon);
s32 get_burst_counter(void *p);
void increment_burst_counter(u8 *counter);

#endif
