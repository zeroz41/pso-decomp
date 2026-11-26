#include "types.h"
#include "pso/system/MainPhaseCheck.h"

s32 is_game_scene_phase(MainPhaseState *state) {
    u8 result = 0;
    s32 phase = state->cur;
    if (phase == 14 || phase == 15) {
        result = 1;
    }
    return result;
}
