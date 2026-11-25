#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/player/TObjPlayer_802C422C.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/system/date.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/network/TPlyOnCreated.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/network/TPlyJoinLobbyEntry.h"

#include "pso/network/client_id.h"

extern "C" {
s32 copy_player_visual_record(void *, void *);
}

// Saves the local player into `record`. With no local player yet it asks for one and returns 0.
s32 capture_local_player_state(TPlyCharData *record) {
    TObjPlayer *player = get_local_player();
    if (player == NULL) {
        TPlyOnCreated::create((u16)local_client_id, fn_802C4748);
        return 0;
    }
    player->export_state_to_record(record);
    return 1;
}

s32 TObjPlayer::sync_char_select_state() { return capture_local_player_state(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

s32 TPlyCharData::capture_client_player(u16 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0;
    }
    copy_from_player(player);
    return 1;
}

s32 capture_local_player(TPlyCharData *record) {
    TObjPlayer *player = get_local_player();
    if (player == NULL) {
        return 0;
    }
    record->copy_from_player(player);
    return 1;
}

void TObjPlayer::init_battle_selection() { capture_local_player(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

void TPlyCharData::copy_from_player(TObjPlayer *player) {
    u8 *overflow;
    s32 i;
    player->set_flag_80000();
    copy_player_visual_record(&m_disp_part2, player->name);
    m_inventory.m_num_items = player->query_state_if_present(m_inventory.get_items());
    player->inventory_objects->set_flag_and_update(player);
    player->clamp_stats(&m_stats, TObjPlayer::get_class_stat_entry((u8 *)player));
    m_inventory.m_hp_materials_used = player->get_hp_material_points();
    m_inventory.m_tp_materials_used = player->get_tp_materials_clamped();
    set_power_materials_used(player->get_power_materials_used());
    set_mind_materials_used(player->get_mind_materials_used());
    set_evade_materials_used(player->get_evade_materials_used());
    set_def_materials_used(player->get_def_materials_used());
    set_luck_materials_used(player->get_luck_materials_used());
    copy_disp_config(&m_config, &player->action_palettes);
    for (i = 0; i < 0x13; i++) {
        overflow = technique_level_overflow(i);
        TObjPlayer::split_capped_value(player->technique_state.get_learned_level(i),
            technique_level(i), overflow);
    }
    m_inventory.m_language = current_language;
    if (game_files_modified() != 0) {
        mark_game_files_modified();
    }
    player->apply_pending_action((saddr)this);
    player->copy_mag_level_to_record((u8 *)this);
    player->copy_byte_339_to_record((u8 *)this);
    player->copy_battle_mode((u8 *)this);
    player->clear_flag_80000();
}

void TPlyCharData::set_mag_level(u8 level) { m_inventory.m_items[13].m_present[3] = level; }

void TPlyCharData::clear_inventory() {
    int i;
    for (i = 0; i < 30; i++) {
        ((TAdSinglePlyChrSelectGC *)&m_inventory.m_items[i])->clear_inventory_slot();
    }
}

void TPlyCharData::set_technique_level_overflow(s32 tech, u8 level) {
    m_inventory.m_items[tech].m_present[2] = level;
}

void TPlyCharData::set_technique_level(s32 tech, u8 level) {
    TObjPlayer::is_slot_within_limit(m_disp_part2.char_class, (s16)tech, level);
    m_tech_levels[tech] = level;
}

u8 *TPlyCharData::get_technique_levels() { return m_tech_levels; }
void TPlyCharData::set_luck_materials_used(u8 count) { m_inventory.m_items[12].m_present[3] = count; }
void TPlyCharData::set_def_materials_used(u8 count) { m_inventory.m_items[11].m_present[3] = count; }
void TPlyCharData::set_evade_materials_used(u8 count) { m_inventory.m_items[10].m_present[3] = count; }
void TPlyCharData::set_mind_materials_used(u8 count) { m_inventory.m_items[9].m_present[3] = count; }
void TPlyCharData::set_power_materials_used(u8 count) { m_inventory.m_items[8].m_present[3] = count; }
void TPlyCharData::set_battle_mode(u8 mode) { m_inventory.m_items[15].m_present[3] = mode; }
void TPlyCharData::set_field_18f(u8 value) { m_inventory.m_items[14].m_present[3] = value; }

void TPlyCharData::stamp_save_time() {
    DateStamp date;
    int seconds;
    getDateStamp(&date);
    DateToSeconds(&date, &seconds);
    set_save_time(seconds);
}

// The seconds are kept a byte at a time in the last m_present byte of inventory slots 4-7.
void TPlyCharData::set_save_time(u32 seconds) {
    m_inventory.m_items[4].m_present[3] = seconds;
    m_inventory.m_items[5].m_present[3] = (u8)(seconds >> 8);
    m_inventory.m_items[6].m_present[3] = (u8)(seconds >> 16);
    m_inventory.m_items[7].m_present[3] = (u8)(seconds >> 24);
}

// Kept a byte at a time in the last m_present byte of inventory slots 0-3.
void TPlyCharData::set_pending_action(u32 action) {
    m_inventory.m_items[0].m_present[3] = action;
    m_inventory.m_items[1].m_present[3] = (u8)(action >> 8);
    m_inventory.m_items[2].m_present[3] = (u8)(action >> 16);
    m_inventory.m_items[3].m_present[3] = (u8)(action >> 24);
}

u8 *TPlyCharData::technique_level(s32 tech) {
    return &m_tech_levels[tech];
}

u8 *TPlyCharData::technique_level_overflow(s32 tech) {
    return (u8 *)&m_inventory.m_items[tech].m_present[2];
}

void TPlyCharData::mark_game_files_modified() { m_inventory.m_items[0].m_present[3] |= 0x40; }

void init_character_action_config(TPlyDispConfig *config) { config->m_smth1.init(); }

void TObjPlayer__sub_802C46E0(TPlyDispConfigSmth *palette, s32 row, s32 index, s32 mode, u16 slot) { palette->set_tag(row, index, mode, slot); }

void TObjPlayer::clear_flag_80000() { clear_state_flags((saddr)((void*)524288)); }
void TObjPlayer::set_flag_80000() { set_state_flags((uaddr)((void*)524288)); }
