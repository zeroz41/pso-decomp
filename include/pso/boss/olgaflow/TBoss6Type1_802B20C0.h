#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE1_802B20C0_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE1_802B20C0_H

#include "types.h"
#include <dolphin/mtx.h>

struct TBoss6Type1;
extern "C" {
void init_work__11TBoss6Type1Fv(u8 *arg0);
void TBoss6Type1__sub_802B4A9C(TBoss6Type1 *boss);
void TBoss6Type1__sub_802B4B04(TBoss6Type1 *boss);
void TBoss6Type1__sub_802B5140(TBoss6Type1 *boss, s32 arg1, s32 arg2);
void TBoss6Type1__sub_802B5598(TBoss6Type1 *boss, Vec *out);
s32 TBoss6Type1__sub_802B6060(const TBoss6Type1 *boss);
void TBoss6Type1__sub_802B6C30(TBoss6Type1 *boss);
void TBoss6Type1__sub_802B73AC(TBoss6Type1 *boss);
void TBoss6Type1__sub_802B8A70(TBoss6Type1 *self);
void TBoss6Type1__sub_802B8BB4(TBoss6Type1 *boss);
void TBoss6Type1__sub_802B8E1C(TBoss6Type1 *boss);
void send_flow_action_if_idle(TBoss6Type1 *boss, s32 action);
void calc_grid_cell_position__11TBoss6Type1FPvPv(TBoss6Type1 *boss, Vec *out);
}

#endif
