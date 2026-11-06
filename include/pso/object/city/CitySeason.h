#ifndef PSO_OBJECT_CITY_CITYSEASON_H
#define PSO_OBJECT_CITY_CITYSEASON_H

#include "types.h"

extern "C" {
void *TObjCity_Season_21_21__create(void *arg0);
u8 *TObjCity_Season_21_21__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjCity_Season_Board__create(void *arg0);
u8 *TObjCity_Season_Board__ct(u8 *arg0, s32 parent, s32 arg2);
void *TObjCity_Season_EasterEgg__create(void *arg0);
u8 *TObjCity_Season_EasterEgg__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjCity_Season_FireWorkCtrl__create(void *arg0);
u8 *TObjCity_Season_FireWorkCtrl__ct(u8 *arg0, s32 parent, s32 arg2);
void *TObjCity_Season_HalloweenPumpkin__create(void *arg0);
u8 *TObjCity_Season_HalloweenPumpkin__ct(u8 *arg0, s32 parent, s32 arg2);
void *TObjCity_Season_SonicAdv2__create(void *arg0);
u8 *TObjCity_Season_SonicAdv2__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjCity_Season_ValentineHeart__create(void *arg0);
u8 *TObjCity_Season_ValentineHeart__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjCity_Season_XmasTree__create(void *arg0);
u8 *TObjCity_Season_XmasTree__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjCity_Season_XmasWreath__create(void *arg0);
u8 *TObjCity_Season_XmasWreath__ct(u8 *arg0, s32 parent, s32 arg2);
void *__dt__21TObjCity_Season_21_21Fv(void *arg0, s16 arg1);
void *__dt__25TObjCity_Season_EasterEggFv(void *arg0, s16 arg1);
void *__dt__30TObjCity_Season_ValentineHeartFv(void *arg0, s16 arg1);
u8 *init_city_season_object(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
}

#endif
