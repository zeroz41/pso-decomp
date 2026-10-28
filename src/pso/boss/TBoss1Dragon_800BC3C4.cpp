#include "types.h"
#include "pso/boss/TBoss1Dragon_800BC3C4.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/TBoss1Dragon.h"

extern "C" {
int VecCopy__FP3VecPC3Vec(void*);

int TBoss1Dragon::get_position() { return VecCopy__FP3VecPC3Vec((char*)this + 0x38); }

void TUnk_804928CC::sub_800BC3E8(u8 *arg1) {
    *(void * *)&this->m_ac = arg1;
    *(s16 *)&this->room = (s16) *(s16 *)((s8 *)(*(void * *)&this->m_ac) + 0x28);
}
u8 is_area_attack_target_eligible(void *arg0, u32 arg1) {
    return !(arg1 & 0x04000000);
}

}
