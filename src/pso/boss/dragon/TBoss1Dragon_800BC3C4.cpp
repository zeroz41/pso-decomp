#include "types.h"
#include "pso/boss/dragon/TBoss1Dragon_800BC3C4.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

extern "C" {
int VecCopy__FP3VecPC3Vec(void*, void*);

int TUnk_804928CC::set_position_from(void *pos) { return VecCopy__FP3VecPC3Vec(&this->position, pos); }

void TUnk_804928CC::sub_800BC3E8(u8 *arg1) {
    owner = (uaddr)arg1;
    room = ((TObjBase *)owner)->room;
}
u8 is_area_attack_target_eligible(void *arg0, u32 arg1) {
    return !(arg1 & 0x04000000);
}

}
