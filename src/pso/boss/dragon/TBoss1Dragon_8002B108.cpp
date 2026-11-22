#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"

TBoss1DragonColli_C *TBoss1DragonColli::get_object(s32 index) {
    return this->objects[index];
}

void TBoss1DragonColli::disable_blocking_bodies() {
    s32 i;
    for (i = 0; i < 3; i++) {
        this->objects[i]->disable();
    }
}
