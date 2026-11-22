#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"

void TBoss1DragonColli::enable_blocking_bodies(Vec *pos, s32 angle) {
    s32 i;
    for (i = 0; i < 3; i++) {
        this->objects[i]->enable_at(pos, angle);
    }
}
