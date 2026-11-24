#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/render/StripBufferPair.h"

extern "C" {

s32 TBoss4Type2::is_active() {
    return (u8)((u8) (dark_falz_controller_instance != 0));
}
void ModelNodeTables::scroll_strips() {
    s32 i;
    scroll_u += 8;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            items[i]->scroll_uvs(scroll_u, scroll_v);
        }
    }
}

}
