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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/unk/TLobby.h"
#include "pso/network/client_id.h"

#pragma readonly_strings on

extern "C" {
s32 check_flag_100__10TObjPlayerFPv();
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
    uaddr player;
    if (is_target_in_range(radius * radius) == 1 &&
        TWindowShortListCtrl__check_controller_button((u8 *)&controller_input_state + 0x20, 4) != 0 &&
        ((player = (uaddr)get_player_by_client_id(local_client_id), player == 0) ||
         check_flag_100__10TObjPlayerFPv() == 0) &&
        (player == 0 || ((TObjPlayer *)player)->is_inactive() != 0) &&
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
