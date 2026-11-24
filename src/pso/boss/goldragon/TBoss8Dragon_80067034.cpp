#include "types.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
TObjBoss5Ctrl *boss5_ctrl_instance;
#pragma fp_contract on
s32 TBoss8Dragon::is_within_xz_distance(const Vec *pos, const NJS_OBJECT *node, f32 range_squared) {
    f32 dx = pos->x - node->pos[0];
    f32 dz = pos->z - node->pos[2];
    return (dx * dx + dz * dz) < range_squared;
}

f32 TBoss8Dragon::calc_sq_offset(const DragonAttackParams *params, f32 padding) {
    f32 range = params->radius + padding;
    return range * range;
}

void TBoss8Dragon__sub_80067074(const Vec *pos, const DragonAttackParams *params) {
    TObject *floor_grass;
    TObjBoss5FloorStone *floor_stone;
    if (boss5_ctrl_instance != NULL) {
        floor_grass = boss5_ctrl_instance->floor_grass;
        if (floor_grass != NULL) {
            TBoss8Dragon__sub_8028A900(floor_grass, pos, params);
        }
        floor_stone = boss5_ctrl_instance->floor_stone;
        if (floor_stone != NULL) {
            floor_stone->trigger_switches_in_range(pos, params);
        }
    }
}

void TBoss8Dragon__sub_800670E0(const Vec *pos, const DragonAttackParams *params) {
    TObjBoss5PillarCtrl *pillar_controller;
    if (boss5_ctrl_instance != NULL) {
        pillar_controller = boss5_ctrl_instance->pillar_controller;
        if (pillar_controller != NULL) {
            TBoss8Dragon__sub_8028B0DC(pillar_controller, pos, params);
        }
    }
}

}
