#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
void TBoss8Dragon__sub_8028B0DC(void *, Vec *, DragonAttackParams *);
TObjBoss5Ctrl *boss5_ctrl_instance;
#pragma fp_contract on
s32 TBoss8Dragon::is_within_xz_distance(u8 *arg1, f32 off) {
    u8 *self = (u8 *)this;
  f32 temp_f2;
  f32 temp_f4;
  temp_f2 = (*((f32 *) (((s8 *) self) + 0))) - (*((f32 *) (((s8 *) arg1) + 8)));
  temp_f4 = (*((f32 *) (((s8 *) self) + 8))) - (*((f32 *) (((s8 *) arg1) + 0x10)));
  return ((temp_f2 * temp_f2) + (temp_f4 * temp_f4)) < off;
}

f32 TBoss8Dragon::calc_sq_offset(f32 farg0) {
    f32 temp_f0;

    temp_f0 = *(f32 *)((u8 *)this + 8) + farg0;
    return temp_f0 * temp_f0;
}

void TBoss8Dragon__sub_80067074(Vec *pos, DragonAttackParams *params) {
    TObject *floor_grass;
    TObject *floor_stone;
    if (boss5_ctrl_instance != NULL) {
        floor_grass = boss5_ctrl_instance->floor_grass;
        if (floor_grass != NULL) {
            TBoss8Dragon__sub_8028A900(floor_grass, pos, params);
        }
        floor_stone = boss5_ctrl_instance->floor_stone;
        if (floor_stone != NULL) {
            TBoss8Dragon::trigger_switches_in_range(floor_stone, pos, params);
        }
    }
}

void TBoss8Dragon__sub_800670E0(Vec *pos, DragonAttackParams *params) {
    TObject *pillar_controller;
    if (boss5_ctrl_instance != NULL) {
        pillar_controller = boss5_ctrl_instance->pillar_controller;
        if (pillar_controller != NULL) {
            TBoss8Dragon__sub_8028B0DC(pillar_controller, pos, params);
        }
    }
}

}
