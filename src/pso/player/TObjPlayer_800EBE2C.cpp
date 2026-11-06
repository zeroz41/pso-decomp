#include "types.h"
#include "pso/enemy/slime/TObjEneSlimeTailAttack.h"

extern "C" {
s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, int, f32);

int TObjEneSlimeTailAttack::find_nearest_enemy_with_flag(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf(arg0, 0, farg0);
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) & 0xFDFFFFFF);
    return temp_r3;
}

}
