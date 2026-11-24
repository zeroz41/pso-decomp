#include "types.h"
#include "pso/item/InventoryEntryCopy.h"
#include "pso/item/TItem.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_802C367C.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyItem.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_802A0F3C.h"

extern "C" {
void copy_player_visual_record(void *, void *);
void clamp_stats__10TObjPlayerFiPv(void *, void *, s32);
u8 TObjPlayer__sub_801C0124(void *, s16);
saddr reset(void *);
}

s32 TNpcPlayer::send_command(s32 cls, s32 count, const TPlyInventoryItem *source, s32 level, TPlyCharData *character) {
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
    character->m_inventory.m_num_items = query_state_if_present__10TObjPlayerFPv(this, character->m_inventory.get_items());
    hp = get_actor_hp();
    tp = get_actor_tp(this);
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
    TLobby::copy_data(&character->m_stats, get_stats());
    clamp_stats__10TObjPlayerFiPv(this, &character->m_stats, (saddr)get_class_stat_entry((u8 *)this));
    copy_player_visual_record(&character->m_disp_part2, name);
    TObjPlayer__sub_8013A748(&character->m_config, &action_palettes);
    for (j = 0; j < 0x13; j++) {
        overflow = character->technique_level_overflow(j);
        split_capped_value(TObjPlayer__sub_801C0124(&technique_state, j),
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
    apply_pending_action((saddr)character);
    copy_mag_level_to_record((u8 *)character);
    copy_byte_339_to_record((u8 *)character);
    copy_battle_mode((u8 *)character);
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
    record->m_inventory.m_num_items = query_state_if_present__10TObjPlayerFPv(this, record->m_inventory.get_items());
    hp = get_actor_hp();
    tp = get_actor_tp(this);
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
    clamp_stats__10TObjPlayerFiPv(this, &record->m_stats, (saddr)get_class_stat_entry((u8 *)this));
    copy_player_visual_record(&record->m_disp_part2, name);
    TObjPlayer__sub_8013A748(&record->m_config, &action_palettes);
    for (k = 0; k < 19; k++) {
        overflow = record->technique_level_overflow(k);
        split_capped_value(TObjPlayer__sub_801C0124(&technique_state, k), record->technique_level(k), overflow);
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
    apply_pending_action((saddr)record);
    copy_mag_level_to_record((u8 *)record);
    copy_byte_339_to_record((u8 *)record);
    copy_battle_mode((u8 *)record);
    clear_flag_80000();
}
