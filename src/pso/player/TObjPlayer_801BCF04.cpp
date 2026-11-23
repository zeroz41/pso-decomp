#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

s32 is_lobby_floor_15__15TFontSmallLobbyFv();
s32 TObjPlayer__sub_801C2114();
s32 assign_inventory_item_ids(void *, s32, u8);
s32 bind_saved_inventory_equipment__10TObjPlayerFPvPvi(void *, s32, u8);

extern s32 player_shared_buffer_base;
extern s32 shared_state_flags;

void TObjPlayer::load_character_state(u8 *player) {
    u8 count;
    s32 temp_r30;

    count = *player;
    temp_r30 = (saddr)((TObjPlayer *)player)->get_ptr_4();
    create_inventory();
    set_action_provider_variant((s16) TObjPlayer__sub_801C2114());
    if ((obj_isState2_324() == 0) || (is_lobby_floor_15__15TFontSmallLobbyFv() == 0)) {
        if (!(shared_state_flags & 1)) {
            assign_inventory_item_ids(this, temp_r30, count);
        }
        bind_saved_inventory_equipment__10TObjPlayerFPvPvi(this, temp_r30, count);
    }
    this->m_db4 = (s32) (player_shared_buffer_base + (this->get_entity_id() * 0x600));
}

}
