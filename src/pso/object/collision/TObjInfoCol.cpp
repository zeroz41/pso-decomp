#include "pso/player/TObjPlayer_801AF2F0.h"
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
#include "pso/unk/TLobby.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

extern "C" {
const char *TObjInfoCol__class_name = "TObjInfoCol";

void TObjInfoCol::bswap_6x78() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

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
        open_lobby_warp_menu__6TLobbyFv();
    }
}

TObjInfoCol::TObjInfoCol(saddr arg1, saddr set_data) : TObjCollidable((TObject *)((void *)arg1)) {
    this->m_name = TObjInfoCol__class_name;
    ((TObjInfoCol *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    this->interaction_radius = (f32) this->scale.x;
}

TObjInfoCol::~TObjInfoCol() {

}
