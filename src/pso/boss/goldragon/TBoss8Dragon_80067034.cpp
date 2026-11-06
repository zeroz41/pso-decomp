#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
void TBoss8Dragon__sub_8028B0DC(void *, s32, s32);
extern u8 *boss5_ctrl_instance;
#pragma fp_contract on
s32 TBoss8Dragon::is_within_xz_distance(u8 *arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f2;
  f32 temp_f4;
  temp_f2 = (*((f32 *) (((s8 *) arg0) + 0))) - (*((f32 *) (((s8 *) arg1) + 8)));
  temp_f4 = (this->m_8) - (*((f32 *) (((s8 *) arg1) + 0x10)));
  return ((temp_f2 * temp_f2) + (temp_f4 * temp_f4)) < farg0;
}

f32 TBoss8Dragon::calc_sq_offset(f32 farg0) {
    f32 temp_f0;

    temp_f0 = this->m_8 + farg0;
    return temp_f0 * temp_f0;
}

void TBoss8Dragon__sub_80067074(s32 arg0, s32 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    if ((void *) boss5_ctrl_instance != NULL) {
        temp_r3 = *(u32 *)((s8 *)boss5_ctrl_instance + 0x1C);
        if (temp_r3 != 0U) {
            TBoss8Dragon__sub_8028A900((void *)temp_r3, (arg0), (arg1));
        }
        temp_r3_2 = *(u32 *)((s8 *)boss5_ctrl_instance + 0x20);
        if (temp_r3_2 != 0U) {
            TBoss8Dragon::trigger_switches_in_range((void *)temp_r3_2, (void *)arg0, (void *)arg1);
        }
    }
}

void TBoss8Dragon__sub_800670E0(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    if ((void *) boss5_ctrl_instance != NULL) {
        temp_r3 = (u8 *)(*(u8 **)((s8 *)boss5_ctrl_instance + 0x24));
        if (temp_r3 != NULL) {
            TBoss8Dragon__sub_8028B0DC(temp_r3, arg0, arg1);
        }
    }
}

}
