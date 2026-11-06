#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

extern s32 lbl_805D6C84;

void TLobby::apply_state_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->set(2);
}

void TLobby::apply_player_flag_2() {
    test_flags_any(&lbl_805D6C84, 2);
}

void TLobby::init_object_flag() {
    ((FlagWord *)(&lbl_805D6C84))->set(1);
}

void TLobby::set_flag_1_at_6c84() {
    test_flags_any(&lbl_805D6C84, 1);
}

void TLobby::clear_flag_at_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->reset();
}
