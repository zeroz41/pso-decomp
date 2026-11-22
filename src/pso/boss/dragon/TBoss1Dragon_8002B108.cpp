#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

extern "C" {
TObject *TBoss1Dragon__sub_8002B108(TBoss1DragonColli *self, s32 i) {
    return self->objects[i];
}
}
void disable_dragon_blocking_bodies(TBoss1DragonColli *self);
void disable_dragon_blocking_bodies(TBoss1DragonColli *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        TBoss1DragonColli__sub_8002B35C(self->objects[i]);
    }
}
