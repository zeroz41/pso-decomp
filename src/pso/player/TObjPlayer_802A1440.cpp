#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerCharDataEntry.h"

extern "C" {

void PlayerCharDataEntry::clear() { role = 0; lobby_header.clear(); flags.reset(); char_data.initialize_player_data(); }

void PlayerCharDataEntry::copy_from_player(TObjPlayer *player) {
    flags.set(1);
    role = player->get_control_role();
    lobby_header.copy_from(&player->guild_card_tag);
    player->export_character_data(&char_data);
}

void TPlyCharData::initialize_player_data() { m_inventory.m_language = 0; m_inventory.m_tp_materials_used = 0; m_inventory.m_hp_materials_used = 0; m_inventory.m_num_items = 0; init_inventory_items(); m_stats.clear(); m_disp_part2.clear(); m_config.init(); clear_technique_levels(); }

void TPlyCharData::clear_technique_levels() {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        m_tech_levels[i] = TObjPlayer::get_item_count_max();
    }
}

void TPlyDispConfig::init() { m_smth.init(); m_smth1.init(); }

}
