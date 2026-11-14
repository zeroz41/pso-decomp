#include "types.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"

extern "C" {
int is_quest_active(void);

extern s32 game_difficulty_selection;

s32 TLobby::is_online_ready() {
    if (((s32) game_difficulty_selection == 3) && (TLobby::get_instance() == 0)) {
        return 1;
    }
    if (TLobby::get_online_ready_flag() != 0) {
        return 1;
    }
    return 0;
}

s32 TLobby::is_camera_ctrl_active() {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return TCameraCtrl::get_instance();
    }
    return 1;
}

s32 TLobby::is_ready() {
    if ((get_game_play_mode() == 2) && (is_quest_active() == 1)) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_8030A770(void) {
    if ((get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        return 1;
    }
    return 0;
}
s32 get_game_play_mode(void) {
    s32 n;
    s32 r;
    if (TLobby::is_flag_set() == 1) {
        return 1;
    }
    if (is_challenge_mode_active() == 1) {
        return 1;
    }
    n = TObjPlayer::get_player_count();
    r = 0;
    if (n > 0) {
        r = 2;
    }
    return r;
}

}
