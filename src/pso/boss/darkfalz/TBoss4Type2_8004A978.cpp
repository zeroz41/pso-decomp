#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/unk/ModelNodeTables.h"

extern "C" {
void scroll_strip_uvs(void *, s16, s16);
extern s32 dark_falz_controller_instance;

u8 TBoss4Type2::is_active() {
    return (u8) (dark_falz_controller_instance != 0);
}
void ModelNodeTables::scroll_strips() {
    s32 i;
    scroll_u += 8;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            scroll_strip_uvs(items[i], scroll_u, scroll_v);
        }
    }
}

}
