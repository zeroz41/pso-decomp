#include "types.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern "C" {

s32 is_quest_active();
u32 get_player_by_client_id(s32);
s32 check_player_state_flag_2__6TLobbyFv();
s32 is_split_screen();

    extern short TCameraCtrl__viewport_y;
short TCameraCtrl::get_screen_width() {  return TCameraCtrl__viewport_y; }

    extern short TCameraCtrl__viewport_x;
short TCameraCtrl::get_screen_height() {  return TCameraCtrl__viewport_x; }

extern s32 local_client_id;

s32 TCameraCtrl::should_update() {
    s32 global_state;

    if (is_split_screen() == 0) {
        if ((get_player_by_client_id(local_client_id) == 0U) || (check_player_state_flag_2__6TLobbyFv() != 0)) {
            return 0;
        }
        if (is_quest_active() == 0) {
            return 0;
        }
        goto block_6;
    }
block_6:
    global_state = get_current_area();
    if (global_state < 0xF) {
        if (global_state == 0) {
            goto block_10;
        }
        goto block_11;
    }
    if (global_state < 0x13) {
block_10:
        return 0;
    }
block_11:
    return 1;
}

}
