#ifndef PSO_ENEMY_DARKGUNNER_DARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_DARKGUNNER_H

#include "types.h"

struct TObjEneDarkGunner;
extern "C" {
void TObjPlayer__sub_800A100C(s32 _w0);
void sub_800A1520__17TObjEneDarkGunnerFv(u8 *arg0_);
void TObjPlayer__sub_800A1974(void);
f32 TObjPlayer__sub_800A3200(s32 arg0);
s32 TObjPlayer__sub_800A3210(s32 i, s32 _w1, s32 _w2);
void *__dt__13TUnk_804909C4Fv(void *arg0, s16 arg1);
void clear_lappy_flag_set_param(TObjEneDarkGunner *gunner);
f32 fmax_800A2390(f32 a, f32 b);
void fn_800A0FDC(TObjEneDarkGunner *gunner);
void init_scale_global__10TObjPlayerFv(void);
}

#endif
