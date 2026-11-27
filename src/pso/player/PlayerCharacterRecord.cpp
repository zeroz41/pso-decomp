#include "pso/player/PlayerLevelTable.h"
#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/player/PlayerCharacterRecord.h"
#include "pso/player/StartingInventory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/InventoryEntryCopy.h"
#include "pso/player/TPlyInventory.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerState.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/Language.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_CardSequence.h"
#include "pso/item/TItem.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TPlyItem.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/system/date.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/network/TPlyOnCreated.h"
#include "pso/network/client_id.h"

int init_new_character_data(TPlyCharData *record) {
    record->m_inventory.m_num_items = 0;
    record->clear_inventory();
    init_character_action_config(&record->m_config);
    init_class_starting_inventory(record);
    record->m_stats.meseta = 300;
    record->set_mag_level(1);
    return 1;
}

void TPlyCharData::clear_technique_level_overflows() {
    int i;
    for (i = 0; i < 30; i++) {
        set_technique_level_overflow(i, 0);
    }
}

void TPlyCharData::reset_technique_levels() {
    s32 i;
    u8 *p;
    p = get_technique_levels();
    for (i = 0; i < 0x14; i++) {
        *p = get_item_count_max();
        p++;
    }
    if (m_disp_part2.v1_flags & 0x80) {
        set_technique_level(0, 0);
    }
    clear_technique_level_overflows();
}

void init_technique_levels(s32 flags, u8 *counts) {
    s32 i;
    u8 *p = counts;
    for (i = 0; i < 0x14; i++, p++) {
        *p = get_item_count_max();
    }
    if (flags & 0x80) {
        *counts = 0;
    }
}

void TObjPlayer::setup_effect_slots(s32 v1_flags, TPlyDispConfigSmth *palette) {
    palette->init_tag(0, 0, 1, 0);
    palette->init_tag(1, 0, 1, 0);
    palette->init_tag(0, 1, 2, 0);
    palette->init_tag(0, 2, 2, 1);
    if (v1_flags & 0x60) {
        palette->init_tag(0, 3, 4, 0);
        return;
    }
    palette->init_tag(0, 3, 3, 0);
}

void init_character_stats_for_level(s8 cls, TPlyCharData *c, s32 level) {
    struct stats st;
    level = TObjPlayer::clamp_index_to_max(level);
    copy_stats(&st, get_class_base_stats(cls));
    if (level != 0) {
        apply_class_level_growth(cls, level, &st);
    }
    c->m_stats.stats.atp = st.atp;
    c->m_stats.stats.mst = st.mst;
    c->m_stats.stats.evp = st.evp;
    c->m_stats.stats.hp = st.hp;
    c->m_stats.stats.dfp = st.dfp;
    c->m_stats.stats.ata = st.ata;
    c->m_stats.stats.lck = st.lck;
    c->m_stats.esp = 0x28;
    c->m_stats.knockback_resist = 10.0f;
    c->m_stats.level = level;
    c->m_stats.exp = TObjPlayer::get_current_state_field(cls, level);
    c->m_stats.meseta = 300;
    c->m_inventory.m_hp_materials_used = 0;
    c->m_inventory.m_tp_materials_used = 0;
    c->set_power_materials_used(0);
    c->set_mind_materials_used(0);
    c->set_evade_materials_used(0);
    c->set_def_materials_used(0);
    c->set_luck_materials_used(0);
}

void init_new_character_stats(TPlyCharData *character) {
    init_character_stats_for_level(character->m_disp_part2.char_class, character, 0);
}

void copy_entries(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *destination) {
    s32 i;
    for (i = 0; i < count; i++) {
        copy_inventory_item(destination++, source++);
    }
}

// The template copy keeps the two reserved presence bytes already in the destination.
void copy_item_entry_array(s32 count, const TPlyInventoryItem *src, TPlyInventoryItem *dst) {
    s32 i;
    for (i = 0; i < count; i++) {
        // The retail copy stores the presence bytes before the flags word.
        *reinterpret_cast<volatile u8 *>(&dst->m_present[0]) = *reinterpret_cast<const u8 *>(&src->m_present[0]);
        *reinterpret_cast<volatile u8 *>(&dst->m_present[1]) = *reinterpret_cast<const volatile u8 *>(&src->m_present[1]);
        *static_cast<volatile u32 *>(&dst->m_flags) = *static_cast<const volatile u32 *>(&src->m_flags);
        dst->m_data.copy_from(const_cast<TItemData *>(&src->m_data));
        dst++;
        src++;
    }
}

void init_class_starting_inventory(TPlyCharData *character) {
    s8 class_index = character->m_disp_part2.char_class;
    character->m_inventory.m_num_items = 5;
    copy_item_entry_array(character->m_inventory.m_num_items,
        get_class_starting_inventory(class_index),
        character->m_inventory.get_items());
}

s32 TObjPlayer::begin_action_state(TPlyCharData *character) {
    s8 class_index;

    if (character == NULL) {
        return 0;
    }
    class_index = character->m_disp_part2.char_class;
    character->m_inventory.m_num_items = 5;
    copy_entries(5, get_class_starting_inventory(class_index), character->m_inventory.get_items());
    character->set_mag_level(1);
    init_new_character_stats(character);
    setup_effect_slots(character->m_disp_part2.v1_flags, &character->m_config.m_smth);
    init_technique_levels(character->m_disp_part2.v1_flags, character->get_technique_levels());
    character->m_inventory.m_language = current_language;
    return 1;
}

void begin_action_from_char_select() { TObjPlayer::begin_action_state(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

void TObjPlayer::copy_battle_mode(TPlyCharData *record) {
    record->set_battle_mode(get_battle_mode());
}

void TObjPlayer::copy_byte_339_to_record(TPlyCharData *record) {
    record->set_class_flag_1(get_class_flag_1());
}

void TObjPlayer::copy_mag_level_to_record(TPlyCharData *record) {
    record->set_mag_level(get_mag_level());
}

void TObjPlayer::apply_pending_action(TPlyCharData *record) {
    s32 action = pending_actions.get_bits();
    if (action != 0) {
        record->set_pending_action(action);
        record->stamp_save_time();
    }
}


s32 TNpcPlayer::send_command(s8 cls, s32 count, const TPlyInventoryItem *source, s32 level, TPlyCharData *character) {
    character->m_inventory.m_num_items = count;
    copy_item_entry_array(count, source,
        character->m_inventory.get_items());
    init_character_stats_for_level(cls, character, level);
    return 1;
}

void TObjPlayer::export_character_data(TPlyCharData *character) {
    s32 i;
    s16 hp;
    s16 tp;
    TItem *item;
    u8 *overflow;
    s32 j;
    s32 k;
    set_flag_80000();
    character->m_inventory.m_num_items = query_state_if_present(character->m_inventory.get_items());
    hp = get_actor_hp();
    tp = get_actor_tp();
    for (i = 0; i != 0xD; i++) {
        item = get_equipped_item(i);
        if (item != NULL) {
            item->remove_equip_stats(1);
        }
    }
    character->m_inventory.m_hp_materials_used = get_hp_material_points();
    character->m_inventory.m_tp_materials_used = get_tp_materials_clamped();
    character->set_power_materials_used(get_power_materials_used());
    character->set_mind_materials_used(get_mind_materials_used());
    character->set_evade_materials_used(get_evade_materials_used());
    character->set_def_materials_used(get_def_materials_used());
    character->set_luck_materials_used(get_luck_materials_used());
    character->m_stats = *get_stats();
    clamp_stats(&character->m_stats, get_class_stat_entry());
    copy_player_visual_record(&character->m_disp_part2, (disp_data_part2 *)&appearance);
    copy_disp_config(&character->m_config, &action_palettes);
    for (j = 0; j < 0x13; j++) {
        overflow = character->technique_level_overflow(j);
        split_capped_value(technique_state.get_learned_level(j),
            character->technique_level(j), overflow);
    }
    for (k = 0; k != 0xD; k++) {
        item = get_equipped_item(k);
        if (item != NULL) {
            item->add_equip_stats(1);
        }
    }
    set_hp_clamped(hp);
    set_tp(tp);
    character->m_inventory.m_language = get_language();
    apply_pending_action(character);
    copy_mag_level_to_record(character);
    copy_byte_339_to_record(character);
    copy_battle_mode(character);
    clear_flag_80000();
}

void TObjPlayer::export_state_to_record(TPlyCharData *record) {
    TItem *items[30];
    s16 hp;
    s16 tp;
    TItem *item;
    s32 i;
    s32 n;
    TItem **p;
    s32 k;
    s32 i2;
    TPlyInventoryItem *entry;
    u8 *overflow;
    s32 m;
    set_flag_80000();
    record->m_inventory.m_num_items = query_state_if_present(record->m_inventory.get_items());
    hp = get_actor_hp();
    tp = get_actor_tp();
    p = items;
    for (i = 0; i < 30; i++) {
        *p++ = NULL;
    }
    p = items;
    n = 0;
    for (i2 = 0; i2 != 13; i2++) {
        item = get_equipped_item(i2);
        if (item != NULL) {
            item->remove_equip_stats(1);
            *p++ = item;
            n++;
        }
    }
    record->m_inventory.m_num_items = n;
    entry = record->m_inventory.get_items();
    p = items;
    for (i = 0; i < 30; i++) {
        if (*p != NULL) {
            (*p)->export_inventory_entry(entry);
            p++;
        } else {
            ::reset(entry);
        }
        entry++;
    }
    record->m_inventory.m_hp_materials_used = get_hp_material_points();
    record->m_inventory.m_tp_materials_used = get_tp_materials_clamped();
    record->set_power_materials_used(get_power_materials_used());
    record->set_mind_materials_used(get_mind_materials_used());
    record->set_evade_materials_used(get_evade_materials_used());
    record->set_def_materials_used(get_def_materials_used());
    record->set_luck_materials_used(get_luck_materials_used());
    clamp_stats(&record->m_stats, get_class_stat_entry());
    copy_player_visual_record(&record->m_disp_part2, (disp_data_part2 *)&appearance);
    copy_disp_config(&record->m_config, &action_palettes);
    for (k = 0; k < 19; k++) {
        overflow = record->technique_level_overflow(k);
        split_capped_value(technique_state.get_learned_level(k), record->technique_level(k), overflow);
    }
    for (m = 0; m != 13; m++) {
        item = get_equipped_item(m);
        if (item != NULL) {
            item->add_equip_stats(1);
        }
    }
    set_hp_clamped(hp);
    set_tp(tp);
    record->m_inventory.m_language = get_language();
    if (game_files_modified() != 0) {
        record->mark_game_files_modified();
    }
    apply_pending_action(record);
    copy_mag_level_to_record(record);
    copy_byte_339_to_record(record);
    copy_battle_mode(record);
    clear_flag_80000();
}


// Saves the local player into `record`. With no local player yet it asks for one and returns 0.
s32 capture_local_player_state(TPlyCharData *record) {
    TObjPlayer *player = get_local_player();
    if (player == NULL) {
        TPlyOnCreated::create((u16)local_client_id, on_local_player_created);
        return 0;
    }
    player->export_state_to_record(record);
    return 1;
}

s32 sync_char_select_state() { return capture_local_player_state(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

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

void init_battle_selection() { capture_local_player(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)); }

void TPlyCharData::copy_from_player(TObjPlayer *player) {
    u8 *overflow;
    s32 i;
    player->set_flag_80000();
    copy_player_visual_record(&m_disp_part2, (disp_data_part2 *)&player->appearance);
    m_inventory.m_num_items = player->query_state_if_present(m_inventory.get_items());
    player->inventory_objects->set_flag_and_update(player);
    player->clamp_stats(&m_stats, player->get_class_stat_entry());
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
    player->apply_pending_action(this);
    player->copy_mag_level_to_record(this);
    player->copy_byte_339_to_record(this);
    player->copy_battle_mode(this);
    player->clear_flag_80000();
}

void TPlyCharData::set_mag_level(u8 level) { m_inventory.m_items[13].m_present[3] = level; }

void TPlyCharData::clear_inventory() {
    int i;
    for (i = 0; i < 30; i++) {
        m_inventory.m_items[i].clear();
    }
}

void TPlyCharData::set_technique_level_overflow(s32 tech, u8 level) {
    m_inventory.m_items[tech].m_present[2] = level;
}

void TPlyCharData::set_technique_level(s32 tech, u8 level) {
    TObjPlayer::is_slot_within_limit(m_disp_part2.char_class, tech, level);
    m_tech_levels[tech] = level;
}

u8 *TPlyCharData::get_technique_levels() { return m_tech_levels; }
void TPlyCharData::set_luck_materials_used(u8 count) { m_inventory.m_items[12].m_present[3] = count; }
void TPlyCharData::set_def_materials_used(u8 count) { m_inventory.m_items[11].m_present[3] = count; }
void TPlyCharData::set_evade_materials_used(u8 count) { m_inventory.m_items[10].m_present[3] = count; }
void TPlyCharData::set_mind_materials_used(u8 count) { m_inventory.m_items[9].m_present[3] = count; }
void TPlyCharData::set_power_materials_used(u8 count) { m_inventory.m_items[8].m_present[3] = count; }
void TPlyCharData::set_battle_mode(u8 mode) { m_inventory.m_items[15].m_present[3] = mode; }
void TPlyCharData::set_class_flag_1(u8 value) { m_inventory.m_items[14].m_present[3] = value; }

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

void TPlyDispConfigSmth::init_tag(s32 row, s32 index, s32 mode, u16 slot) { set_tag(row, index, mode, slot); }

void TObjPlayer::clear_flag_80000() { clear_state_flags((saddr)((void*)524288)); }
void TObjPlayer::set_flag_80000() { set_state_flags((uaddr)((void*)524288)); }
