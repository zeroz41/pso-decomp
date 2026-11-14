#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {

s32 check_camera_mode__10TObjPlayerFv();
s32 get_game_play_mode();
s32 get_main_phase();
s32 reset_volopt_state__10TObjPlayerFv(s32);
int check_flag_100__10TObjPlayerFPv(void *p);
void *get_player_by_client_id(s32 i);
s32 TObjPlayer__sub_80354C7C(s32);
s32 TObjPlayer__sub_80354E3C();

u8 TObjPlayer::is_final_phase() {
    return (u8) (get_main_phase() == 0xF);
}
u8 TObjPlayer::is_camera_ready() {
    int var_r31;

    var_r31 = 0;
    if ((check_camera_mode__10TObjPlayerFv() != 0) && (get_game_play_mode() == 2)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}
u8 TObjPlayer::is_camera_mode_active() {
    int var_r31;

    var_r31 = 0;
    if ((check_camera_mode__10TObjPlayerFv() != 0) && (get_game_play_mode() == 1)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}
s32 TObjPlayer::is_single_screen() {
    return (u8) (TRaderMapCore::is_not_split_screen() == 1);
}
s32 TObjPlayer::is_player_valid_target(s32 arg0) {
    s32 temp_r31;

    if (TObjPlayer__sub_80354E3C() == 0) {
        return 0;
    }
    temp_r31 = (s32)get_player_by_client_id((u16) arg0);
    if ((TObjPlayer__sub_80354C7C(arg0) == 0) || (check_flag_100__10TObjPlayerFPv((void *)temp_r31) != 0) || (reset_volopt_state__10TObjPlayerFv(temp_r31) == 0)) {
        return 0;
    }
    return 1;
}

}
