#include "types.h"
#include "pso/boss/dragon/TBoss1Dragon_800BC3C4.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

#include "pso/system/vector.h"

void TUnk_804928CC::set_position_from(const Vec *pos) { VecCopy(&this->position, pos); }

void TUnk_804928CC::set_owner(TObjBase *actor) {
    owner = actor;
    room = owner->room;
}

extern "C" {
u8 is_area_attack_target_eligible(void *self, u32 arg1) {
    return !(arg1 & 0x04000000);
}

}
