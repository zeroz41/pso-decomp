#ifndef PSO_ENEMY_DARKGUNNER_DARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_DARKGUNNER_H

#include "types.h"

struct TObjEneLappy;
extern "C" {
u8 *TObjEneDarkGunCenter__ct(u8 *arg0, s32 arg1, saddr arg2);
void TObjPlayer__sub_800A100C(s32 _w0);
void sub_800A1520__17TObjEneDarkGunnerFv(u8 *arg0_);
void TObjPlayer__sub_800A16C4(u8 *player);
int TObjPlayer__sub_800A1808(void *p);
void TObjPlayer__sub_800A1974(void);
void TObjPlayer__sub_800A1D70(u8 *arg0);
s32 TObjPlayer__sub_800A1FEC(void *arg0);
s32 TObjPlayer__sub_800A2390(void *arg0_);
f32 TObjPlayer__sub_800A3200(s32 arg0);
s32 TObjPlayer__sub_800A3210(s32 i, s32 _w1, s32 _w2);
void *__dt__13TUnk_804909C4Fv(void *arg0, s16 arg1);
void clear_lappy_flag_set_param(TObjEneLappy *ene_lappy);
f32 fmax_800A2390(f32 a, f32 b);
void fn_800A0FDC(TObjEneLappy *ene_lappy);
void init_scale_global__10TObjPlayerFv(void);
}

#endif
