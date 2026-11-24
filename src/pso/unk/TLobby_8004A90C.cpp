#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

extern s32 game_difficulty_selection;

int TLobby::is_boss_phase_reached() {
    s32 phase;

    if (dark_falz_controller_instance == 0) {
        return 0;
    }
    phase = dark_falz_controller_instance->get_phase();
    if (game_difficulty_selection == 0) {
        return (phase >= 9) ? 1 : 0;
    }
    return (phase >= 0xE) ? 1 : 0;
}
