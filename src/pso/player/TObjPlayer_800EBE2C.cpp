#include "pso/enemy/EnemyTargeting.h"
#include "types.h"
#include "pso/enemy/slime/TObjEneSlimeTailAttack.h"

extern "C" {

int TObjEneSlimeTailAttack::find_nearest_enemy_with_flag(f32 range) {
    s32 target_id;
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) | 0x02000000);
    target_id = find_nearest_hittable_enemy__10TObjPlayerFiPvf(reinterpret_cast<saddr>(this), NULL, range);
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) & 0xFDFFFFFF);
    return static_cast<u16>(target_id);
}

}
