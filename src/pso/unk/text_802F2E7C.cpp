#include "types.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"

void TBoss8DragonColli::enable_blocking_bodies(Vec *pos, s32 angle) {
    s32 i;
    for (i = 0; i < 3; i++) {
        objects[i]->enable_at(pos, angle);
    }
}
