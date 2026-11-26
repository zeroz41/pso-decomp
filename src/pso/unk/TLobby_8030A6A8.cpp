#include "types.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TLevelSelect.h"



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
        return TCameraCtrl::get_view_count();
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
    if (is_challenge_mode() == 1) {
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

