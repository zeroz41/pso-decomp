#include "types.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
struct Obj_8002B164 { u8 pad[0x1c]; void *colli[3]; };

extern "C" {
void fn_802F2E7C(Obj_8002B164 *self, void *a, void *b);
void fn_802F2E7C(Obj_8002B164 *self, void *a, void *b) {
    s32 i;
    for (i = 0; i < 3; i++) {
        init__17TBoss8DragonColliFPvPvPv(self->colli[i], a, b);
    }
}

}
