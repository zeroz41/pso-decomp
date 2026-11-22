#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {

uaddr get_player_by_client_id(s32);

s32 TCameraCtrl::get_screen_width() {  return TCameraCtrl::viewport_y; }

s32 TCameraCtrl::get_screen_height() {  return TCameraCtrl::viewport_x; }

extern s32 local_client_id;

s32 TCameraCtrl::should_update() {
    s32 area;
    uaddr player;

    if (is_split_screen() == 0) {
        if (((player = get_player_by_client_id(local_client_id)) == 0U) || (((TLobby *)player)->check_player_state_flag_2() != 0)) {
            return 0;
        }
        if (is_quest_active() == 0) {
            return 0;
        }
        goto block_6;
    }
block_6:
    area = get_current_floor_area();
    if (area < 0xF) {
        if (area == AREA_PIONEER2_EP1) {
            goto block_10;
        }
        goto block_11;
    }
    if (area < 0x13) {
block_10:
        return 0;
    }
block_11:
    return 1;
}

}
