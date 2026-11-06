#include "types.h"
#include "pso/system/vector.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "pso/enemy/TObjEnemyCustom.h"

extern "C" {
s32 project_actor_to_ground(void *, void *, s32);
#pragma push
#pragma fp_contract on
void TObjEneNanoDrago::sub_800D9BBC() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = this->m_388;
    if (temp_r4 & 0x40000) {
        this->m_388 = (s32) (temp_r4 & 0xFFFBFFFF);
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        project_actor_to_ground(arg0, (u8 *)&this->position, 0);
        return;
    }
    if ((s32) this->next_action == 7) {
        this->m_388 = (s32) (temp_r4 & 0xFFFFFFFE);
        ((TObjEnemyCustom *)arg0)->update_if_active(0);
    }
}
#pragma pop

}
