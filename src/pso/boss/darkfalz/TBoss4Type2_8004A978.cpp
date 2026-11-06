#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

struct Obj_8004A98C { s32 count; u8 pad[4]; s32 x; s32 y; void **items; };

extern "C" {
void scroll_strip_uvs(void *, s16, s16);
extern s32 dark_falz_controller_instance;

u8 TBoss4Type2::is_active() {
    return (u8) (dark_falz_controller_instance != 0);
}
void TBoss4Type2::scroll_strips() {
    Obj_8004A98C *self = (Obj_8004A98C *)this;
    s32 i;
    this->m_24 += 8;
    for (i = 0; i < self->count; i++) {
        if (self->items[i] != 0) {
            scroll_strip_uvs(self->items[i], this->m_24, self->y);
        }
    }
}

}
