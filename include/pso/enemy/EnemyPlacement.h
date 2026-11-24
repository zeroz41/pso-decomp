#ifndef PSO_ENEMY_ENEMYPLACEMENT_H
#define PSO_ENEMY_ENEMYPLACEMENT_H

#include <stddef.h>
#include <dolphin/mtx.h>
#include "types.h"

// The placement stored in a live floor enemy row and passed to its factory.
struct EnemyPlacement {
    s16 enemy_index;
    s16 child_count;
    u8 unknown04[2];
    u16 id;
    s16 room;
    s16 wave;
    u8 unknown0c[4];
    Vec position;
    s32 rotation[3];
    f32 parameters[5];
    s16 variant;
    s16 unknown3e;
};

LAYOUT_ASSERT(EnemyPlacementSize, sizeof(EnemyPlacement) == 0x40);
LAYOUT_ASSERT(EnemyPlacementChildCountOffset, offsetof(EnemyPlacement, child_count) == 2);
LAYOUT_ASSERT(EnemyPlacementIdOffset, offsetof(EnemyPlacement, id) == 0x6);
LAYOUT_ASSERT(EnemyPlacementWaveOffset, offsetof(EnemyPlacement, wave) == 0xA);
LAYOUT_ASSERT(EnemyPlacementPositionOffset, offsetof(EnemyPlacement, position) == 0x10);
LAYOUT_ASSERT(EnemyPlacementParamsOffset, offsetof(EnemyPlacement, parameters) == 0x28);

#endif
