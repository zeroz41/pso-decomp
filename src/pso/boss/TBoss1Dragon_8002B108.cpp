#include "types.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/boss/TBoss1Dragon.h"

struct O_8002B108 { u8 pad[0x1c]; s32 arr[1]; };

struct Obj_8002B118 { u8 pad[0x1c]; void *colli[3]; };

extern "C" {
s32 TBoss1Dragon__sub_8002B108(O_8002B108 *self, s32 i);
void disable_dragon_blocking_bodies(Obj_8002B118 *self);
s32 TBoss1Dragon__sub_8002B108(O_8002B108 *self, s32 i) {
    return self->arr[i];
}
void disable_dragon_blocking_bodies(Obj_8002B118 *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        TBoss1DragonColli__sub_8002B35C(self->colli[i]);
    }
}

}
