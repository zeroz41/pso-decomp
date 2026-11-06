#include "types.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/ui/TAdMultiChgGameModeGC.h"

extern s32 multi_chg_game_mode_state;
extern s32 lbl_805D63C8;

void TAdEnterSerialAccessGC::init_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x10;
    lbl_805D63C8 = 1;
}
