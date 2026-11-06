#ifndef PSO_UNK_TEXT_80198A2C_H
#define PSO_UNK_TEXT_80198A2C_H

#include "types.h"

extern "C" {
void TObjPlayer__sub_801994DC(s32 arg0, void *arg1, void *arg2, s32 arg3, void *arg4, f32 farg0);
void TWindowTimer__sub_80198D98(void);
void TWindowTimer__sub_8019A098(void);
void TWindowTimer__sub_8019A6F8(void *p);
int TWindowTimer__sub_8019A770(void *p);
}
void add_gogo_ball_one_point_score(s32 i);
void add_gogo_ball_three_point_score(s32 i);
extern "C" {
void bswap_6x79_gogo_ball__12TWindowTimerFi(s32 arg0);
}
void draw_shadow_on_ground(u8 *arg0);
extern "C" {
void fn_80198E84(void);
s16 get_timer_value__12TWindowTimerFl(s32 i);
}
void handle_6x79_gogo_ball(u8 *arg0);
extern "C" {
void send_gogo_ball__12TWindowTimerFv(s32 arg0);
int set_timer_value__12TWindowTimerFii(int a0, int a1);
void throw_gogo_ball__12TWindowTimerFll(u8 *arg0, s32 arg1, s32 arg2);
}

#endif
