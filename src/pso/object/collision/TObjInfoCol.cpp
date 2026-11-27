#include "pso/player/PlayerCommands.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/ControllerInputState.h"
#include "types.h"
#include "pso/object/collision/TObjInfoCol.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/system/byteswap.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/system/ControllerInput.h"
#include "pso/network/TLobby.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

extern "C" {
const char *info_col_class_name = "TObjInfoCol";

void G_Unknown_6x78::bswap() {
    header.bswap();
    bswap_16(&client_id);
    bswap_16(&unused1);
    bswap_32(&unused2);
}

}

s32 TObjInfoCol::is_target_in_range(f32 radius_squared) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != 0 &&
        xyz_distance_squared(&player->position, &position) < radius_squared) {
        return 1;
    }
    return 0;
}

void TObjInfoCol::run_task() {
    f32 radius = interaction_radius;
    TObjPlayer *player;
    if (is_target_in_range(radius * radius) == 1 &&
        test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0 &&
        ((player = get_player_by_client_id(local_client_id)) == NULL ||
         player->is_controls_locked() == 0) &&
        (player == NULL || player->is_inactive() != 0) &&
        TLobby::is_idle() != 0) {
        TLobby::open_lobby_warp_menu();
    }
}

TObjInfoCol::TObjInfoCol(TObject *parent, ObjectSetData *set_data) : TObjCollidable(parent) {
    this->m_name = info_col_class_name;
    apply_object_set_data(set_data);
    this->interaction_radius = (f32) this->scale.x;
}

TObjInfoCol::~TObjInfoCol() {

}
