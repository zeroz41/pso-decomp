#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

extern s32 lbl_805D6C84;

void TLobby::apply_state_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->set(2);
}

s32 TLobby::test_flag_2_at_6c84() {
    return test_flags_any(&lbl_805D6C84, 2);
}

void TLobby::init_object_flag() {
    ((FlagWord *)(&lbl_805D6C84))->set(1);
}

s32 TLobby::test_flag_1_at_6c84() {
    return test_flags_any(&lbl_805D6C84, 1);
}

void TLobby::clear_flag_at_6c84() {
    ((FlagWord *)(&lbl_805D6C84))->reset();
}
