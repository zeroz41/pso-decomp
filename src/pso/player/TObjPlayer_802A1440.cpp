#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerCharDataEntry.h"

extern "C" {

int clear_player_data_block(void*);

void PlayerCharDataEntry::clear() { role = 0; TAdSelectTxtGC__sub_802A16A8(&lobby_header); flags.reset(); char_data.initialize_player_data(); }

void PlayerCharDataEntry::copy_from_player(TObjPlayer *player) {
    flags.set(1);
    role = TAdSelectTxtGC__sub_802A16C0(player);
    ((TLobby *)&lobby_header)->copy_header_struct(&player->guild_card_tag);
    player->export_character_data(&char_data);
}

void TPlyCharData::initialize_player_data() { m_inventory.m_language = 0; m_inventory.m_tp_materials_used = 0; m_inventory.m_hp_materials_used = 0; m_inventory.m_num_items = 0; init_inventory_items(); ((TAdSelectTxtGC *)&m_stats)->reset_state(); clear_player_data_block(&m_disp_part2); m_config.init(); clear_technique_levels(); }

void TPlyCharData::clear_technique_levels() {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        m_tech_levels[i] = TObjPlayer::get_item_count_max();
    }
}

void TPlyDispConfig::init() { m_smth.init(); m_smth1.init(); }

}
