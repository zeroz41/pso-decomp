#ifndef PSO_UNK_TEXT_80357058_H
#define PSO_UNK_TEXT_80357058_H

#include "types.h"

struct TItemEffOrgaFlowShot;
extern "C" {
void TBoss6Type2__sub_803570C8(s8 *arg0);
u8 *TItemEffOrgaFlowShot__ct(TItemEffOrgaFlowShot *arg0, s32 arg1, u8 *arg2);
void TItemEffOrgaFlowShot__sub_80357204(void);
void TItemEffOrgaFlowShot__sub_80357210(void);
void *__dt__20TItemEffOrgaFlowShotFv(void *arg0, s16 arg1);
}
void build_6xAD_olga_flow_subordinate_boss_actions(void *p);
void read_be16_field2_forward(void *p);
extern "C" {
void run_task__20TItemEffOrgaFlowShotFv(u8 *arg0);
}
void send_6xAD_olga_flow_subordinate_boss_actions(u8 *arg0);

#endif
