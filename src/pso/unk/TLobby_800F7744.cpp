#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/unk/TLobby_800F7744.h"
#include "pso/unk/TLobby.h"

void TLobby__sub_800F7744(void) {  }

extern s32 area_random_seed;

void TLobby::clear_flag_on_phase_e() {
    if (get_main_phase() == 0xE) {
        area_random_seed = 0;
    }
}
