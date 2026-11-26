#include "types.h"
#include "pso/unk/text_8000F740.h"

u8 is_game_scene_phase(s32 *p) {
    s32 r = 0;
    s32 v = *p;
    if (v == 14 || v == 15) {
        r = 1;
    }
    return r;
}
