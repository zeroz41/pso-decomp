#include "types.h"
#include "pso/boss/DragonAttackParams.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"
#include "pso/object/door/GreenDoorResource.h"
#include "pso/boss/goldragon/DragonAttackRange.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

TObjBoss5Ctrl *boss5_ctrl_instance;
#pragma fp_contract on
s32 is_within_xz_distance(const Vec *pos, const NJS_OBJECT *node, f32 range_squared) {
    f32 dx = pos->x - node->pos[0];
    f32 dz = pos->z - node->pos[2];
    return (dx * dx + dz * dz) < range_squared;
}

f32 calc_sq_offset(const DragonAttackParams *params, f32 padding) {
    f32 range = params->radius + padding;
    return range * range;
}

void boss5_attack_floor_in_range(const Vec *pos, const DragonAttackParams *params) {
    TObject *floor_grass;
    TObjBoss5FloorStone *floor_stone;
    if (boss5_ctrl_instance != NULL) {
        floor_grass = boss5_ctrl_instance->floor_grass;
        if (floor_grass != NULL) {
            break_floor_grass_in_range(floor_grass, pos, params);
        }
        floor_stone = boss5_ctrl_instance->floor_stone;
        if (floor_stone != NULL) {
            floor_stone->trigger_switches_in_range(pos, params);
        }
    }
}

void boss5_attack_pillars_in_range(const Vec *pos, const DragonAttackParams *params) {
    TObjBoss5PillarCtrl *pillar_controller;
    if (boss5_ctrl_instance != NULL) {
        pillar_controller = boss5_ctrl_instance->pillar_controller;
        if (pillar_controller != NULL) {
            trigger_pillars_in_range(pillar_controller, pos, params);
        }
    }
}
