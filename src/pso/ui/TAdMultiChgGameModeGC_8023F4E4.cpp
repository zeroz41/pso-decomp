#include "types.h"
#include "pso/ui/TAdMultiChgGameModeGC_8023F4E4.h"
#include "pso/unk/text_8023F160.h"
#include "pso/system/main_loop.h"
#include "pso/ui/TAdMultiChgGameModeGC.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"

extern s32 multi_chg_game_mode_state;
    extern int lbl_805D384C;

void TAdMultiChgGameModeGC__sub_8023F4E4(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_mode_change_state(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F50C(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_change_mode_flags(); render_tick(); }

extern s32 lbl_805D63C8;

void TAdMultiChgGameModeGC::set_mode_1c() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1C;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC__sub_8023F564(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_mode_17(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F58C(void) { init_game_mode_select_scene(); TAdEnterSerialAccessGC::init_state(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F5B4(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_state_0x9(); render_tick(); }
void TAdMultiChgGameModeGC::render_scene() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::request_scene_change(); render_tick(); }
void TAdMultiChgGameModeGC::render_game_mode_change() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_game_mode_changed(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F62C(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::init_change_mode(); render_tick(); }
void TAdMultiChgGameModeGC::sync_mode_state() { lbl_805D384C = (*(int *)&multi_chg_game_mode_state); }
