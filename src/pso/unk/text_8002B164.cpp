#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
struct Obj_8002B164 { u8 pad[0x1c]; void *colli[3]; };

extern "C" {
void enable_dragon_blocking_bodies(Obj_8002B164 *self, void *a, void *b);
void enable_dragon_blocking_bodies(Obj_8002B164 *self, void *a, void *b) {
    s32 i;
    for (i = 0; i < 3; i++) {
        draw__17TBoss1DragonColliFPvPvPv(self->colli[i], a, b);
    }
}

}
