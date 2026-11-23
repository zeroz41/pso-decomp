#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

extern "C" {

s32 get_game_play_mode();
s32 reset_volopt_state__10TObjPlayerFv(s32);
void *get_player_by_client_id(s32 i);
s32 TObjPlayer__sub_80354C7C(u16);
s32 is_local_client(u16);

s32 TObjPlayer::is_final_phase() {
    return (u8)((u8) (get_main_phase() == 0xF));
}
s32 TObjPlayer::is_camera_ready() {
    int var_r31;

    var_r31 = 0;
    if ((TObjPlayer::check_camera_mode() != 0) && (get_game_play_mode() == 2)) {
        var_r31 = 1;
    }
    return (u8)((u8)var_r31);
}
s32 TObjPlayer::is_camera_mode_active() {
    int var_r31;

    var_r31 = 0;
    if ((TObjPlayer::check_camera_mode() != 0) && (get_game_play_mode() == 1)) {
        var_r31 = 1;
    }
    return (u8)((u8)var_r31);
}
s32 TObjPlayer::is_single_screen() {
    return (u8) (TRaderMapCore::is_not_split_screen() == 1);
}
s32 TObjPlayer::is_player_valid_target(u16 client_index) {
    saddr temp_r31;

    if (is_local_client(client_index) == 0) {
        return 0;
    }
    temp_r31 = (saddr)get_player_by_client_id((u16) client_index);
    if ((TObjPlayer__sub_80354C7C(client_index) == 0) || (((TObjPlayer *)temp_r31)->is_controls_locked() != 0) || (reset_volopt_state__10TObjPlayerFv(temp_r31) == 0)) {
        return 0;
    }
    return 1;
}

}
