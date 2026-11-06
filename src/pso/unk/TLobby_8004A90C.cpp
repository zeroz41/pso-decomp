#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"

extern void* dark_falz_controller_instance;
extern s32 game_difficulty_selection;

int TLobby::is_boss_phase_reached() {
    s32 temp_r3;

    if (dark_falz_controller_instance == 0) {
        return 0;
    }
    temp_r3 = ((TBoss4Uro *)dark_falz_controller_instance)->get_phase();
    if (game_difficulty_selection == 0) {
        return (temp_r3 >= 9) ? 1 : 0;
    }
    return (temp_r3 >= 0xE) ? 1 : 0;
}
