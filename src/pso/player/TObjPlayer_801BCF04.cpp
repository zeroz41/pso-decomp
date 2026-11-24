#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

s32 is_lobby_floor_15__15TFontSmallLobbyFv();

extern s32 shared_state_flags;

void TObjPlayer::load_character_state(TPlyCharData *record) {
    u8 count;
    TPlyInventoryItem *records;

    count = record->m_inventory.m_num_items;
    records = record->m_inventory.get_items();
    create_inventory();
    set_action_provider_variant((s16) default_action_provider_variant());
    if ((obj_isState2_324() == 0) || (is_lobby_floor_15__15TFontSmallLobbyFv() == 0)) {
        if (!(shared_state_flags & 1)) {
            assign_inventory_item_ids(this, records, count);
        }
        bind_saved_inventory_equipment(this, records, count);
    }
    this->item_node_matrices = player_shared_buffer_base[get_entity_id()];
}

}
