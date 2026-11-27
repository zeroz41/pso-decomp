// Byte-swap and copy helpers for the lobby packets, and the small accessors the lobby calls.
#include "pso/system/TLanguage.h"
#include "pso/enemy/EnemyStateRecord.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/network/TGameProtocol.h"
#include "pso/map/FloorPopulation.h"
#include "pso/network/LegacyEnemyKill.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/map/MapSetData.h"
#include "pso/object/TObjControl.h"

void render_idle_timeout(void) {  }
void GameStateSyncScratch::bswap() {
    bswap_16(&total_size);
    bswap_16(&floor_flags_size);
    bswap_16(&sync_records_size);
    bswap_16(&switch_table_size);
}
s32 TLobby::open_hard_keyboard(s32 client_id) { return TWindowKeyBoardHard::test_card_flag(client_id, 0x40000); }
void TLobby::bswap_player_data(PlayerSyncRecord *record) {
    s32 i;
    bswap_16(&record->client_id);
    bswap_16((u16 *)&record->room_id);
    bswap_32(&record->game_flags);
    bswap_32((u32 *)&record->position.x);
    bswap_32((u32 *)&record->position.y);
    bswap_32((u32 *)&record->position.z);
    bswap_32((u32 *)&record->angle[0]);
    bswap_32((u32 *)&record->angle[1]);
    bswap_32((u32 *)&record->angle[2]);
    bswap_16((u16 *)&record->phase);
    bswap_16((u16 *)&record->current_hp);
    bswap_16((u16 *)&record->hp_material_bonus);
    bswap_16((u16 *)&record->tp_material_bonus);
    for (i = 0; i < 5; i++) {
        record->status_effects[i].bswap();
    }
    bswap_32(&record->language);
    record->guild_card_tag.bswap();
    record->pk_state.bswap();
    record->telepipe.bswap();
    bswap_32((u32 *)&record->death_flags);
    bswap_32(&record->area);
    bswap_32(&record->floor);
    bswap_32(&record->player_flags);
    record->visual.bswap();
    record->stats.bswap();
    record->inventory.bswap();
}
void InventoryItemList::bswap() {
    s32 i;
    bswap_32((u32 *)&count);
    for (i = 0; i < 30; i++) {
        items[i].bswap();
    }
}
void TLobby::set_player_count(int a0) { lobby_player_count = a0; }


#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void bswap_and_send_extended_subcommand(void *p, u32 client_id) {
    bswap_extended_subcommand_header((extended_game_command_header *)p);
    ((long_game_command_union *)p)->send_to_client(client_id);
}

void bswap_extended_subcommand_header(extended_game_command_header *header) { TLobby::bswap_header_fields(header); }
void TLobby::bswap_header_fields(extended_game_command_header *header) { header->bswap(); }
void bswap_and_handle_packet(void *packet, int client_id) {
    bswap_client_id_header((G_ClientIDHeader *)packet);
    ((game_command *)packet)->send_to_client(client_id);
}
void init_6x6F_quest_flags_packet(G_SetQuestFlags_V2_V3_6x6F *packet) {
    packet->header.subcommand = 0x6F;
    packet->header.size = sizeof(G_SetQuestFlags_V2_V3_6x6F) / 4;
}
void TLobby::send_packet_60(void *packet) {
    bswap_client_id_header((G_ClientIDHeader *)packet);
    send_subcommand(packet);
}
void init_6x72_resume_packet(G_DoneLoadingIntoGame_6x72 *packet) {
    packet->header.subcommand = 0x72;
    packet->header.size = sizeof(G_DoneLoadingIntoGame_6x72) / 4;
}
void *TLobby::copy_member_record(void *to, void *from) {
    TPlyJoinLobbyEntry *dst = (TPlyJoinLobbyEntry *)to;
    TPlyJoinLobbyEntry *src = (TPlyJoinLobbyEntry *)from;
    __memcpy(&dst->tag, &src->tag, sizeof(dst->tag));
    dst->ip_addr = src->ip_addr;
    dst->client_id = src->client_id;
    __memcpy(dst->name, src->name, sizeof(dst->name));
    dst->char_data = src->char_data;
    return dst;
}

TPlyCharData &TPlyCharData::operator=(TPlyCharData &src) {
    m_inventory.m_num_items = src.m_inventory.m_num_items;
    m_inventory.m_hp_materials_used = src.m_inventory.m_hp_materials_used;
    m_inventory.m_tp_materials_used = src.m_inventory.m_tp_materials_used;
    m_inventory.m_language = src.m_inventory.m_language;
    __memcpy(m_inventory.m_items, src.m_inventory.m_items, sizeof(m_inventory.m_items));
    __memcpy(&m_stats, &src.m_stats, sizeof(m_stats));
    __memcpy(&m_disp_part2, &src.m_disp_part2, sizeof(m_disp_part2));
    copy_disp_config(&m_config, &src.m_config);
    __memcpy(m_tech_levels, src.m_tech_levels, sizeof(m_tech_levels));
    return *this;
}

TPlyDispConfig *copy_disp_config(TPlyDispConfig *dst, TPlyDispConfig *src) {
    copy_disp_config_palette(&dst->m_smth, &src->m_smth);
    copy_disp_config_palette(&dst->m_smth1, &src->m_smth1);
    return dst;
}

TPlyDispConfigSmth *copy_disp_config_palette(TPlyDispConfigSmth *dst, TPlyDispConfigSmth *src) {
    dst->bank = src->bank;
    copy_gc_tag(&dst->m_tags[0], &src->m_tags[0]);
    copy_gc_tag(&dst->m_tags[1], &src->m_tags[1]);
    copy_gc_tag(&dst->m_tags[2], &src->m_tags[2]);
    copy_gc_tag(&dst->m_tags[3], &src->m_tags[3]);
    copy_gc_tag(&dst->m_tags1[0], &src->m_tags1[0]);
    copy_gc_tag(&dst->m_tags1[1], &src->m_tags1[1]);
    copy_gc_tag(&dst->m_tags1[2], &src->m_tags1[2]);
    copy_gc_tag(&dst->m_tags1[3], &src->m_tags1[3]);
    return dst;
}
void copy_gc_tag(gc_tag *dst, gc_tag *src) {
    dst->tag0 = src->tag0;
    dst->tag1 = src->tag1;
    dst->tag2 = *(s16 *)&src->tag2;
}

#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


void TPlyInventoryItem::bswap() {
    bswap_32(&m_flags);
    m_data.bswap();
}

extern "C" {

void PlayerGuildCardTag::bswap() { bswap_16(&tag2); bswap_32(&guildcard_number); }

void StatusEffect::bswap() { bswap_32((u32 *)&type); bswap_32((u32 *)&amount); bswap_32((u32 *)&timer); }

void disp_data_part2::bswap() {
    s32 i;

    bswap_32(&name_colour);
    bswap_32(&name_colour_checksum);
    bswap_32(&v1_flags);
    for (i = 0; i < 8; i++) {
        bswap_16(&appearance_data[i]);
    }
    bswap_32((u32 *)&proportions.x);
    bswap_32((u32 *)&proportions.y);
}
}

void PlayerTelepipe::bswap() {
    bswap_16(&state.owner_client_id);
    bswap_16((u16 *)&state.floor);
    bswap_32(&state.room_id);
    bswap_32((u32 *)&state.pos.x);
    bswap_32((u32 *)&state.pos.y);
    bswap_32((u32 *)&state.pos.z);
    bswap_32(&state.angle_y);
    bswap_32((u32 *)&flags.bits);
}

void PlayerPkState::bswap() {
    bswap_32((u32 *)&enabled);
    bswap_32((u32 *)&team);
}

void QuestObjectEntry::bswap() {
    bswap_16((u16 *)&flags);
    bswap_16(&drop_id_base);
}

void EnemyStateRecord::bswap() {
    bswap_32(reinterpret_cast<u32 *>(&flags));
    bswap_16(&drop_id);
    bswap_16(reinterpret_cast<u16 *>(&damage));
}
u8 *copy_join_lobby_entry(u8 *to, u8 *from) {
    TPlyJoinLobbyEntry *dst = (TPlyJoinLobbyEntry *)to;
    TPlyJoinLobbyEntry *src = (TPlyJoinLobbyEntry *)from;
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&dst->tag, &src->tag);
    dst->ip_addr = src->ip_addr;
    dst->client_id = src->client_id;
    __memcpy(dst->name, src->name, sizeof(dst->name));
    copy_char_data(&dst->char_data, &src->char_data);
    return to;
}

TPlyCharData *copy_char_data(TPlyCharData *dst, TPlyCharData *src) {
    dst->m_inventory.m_num_items = src->m_inventory.m_num_items;
    dst->m_inventory.m_hp_materials_used = src->m_inventory.m_hp_materials_used;
    dst->m_inventory.m_tp_materials_used = src->m_inventory.m_tp_materials_used;
    dst->m_inventory.m_language = src->m_inventory.m_language;
    __memcpy(dst->m_inventory.m_items, src->m_inventory.m_items, sizeof(dst->m_inventory.m_items));
    __memcpy(&dst->m_stats, &src->m_stats, sizeof(dst->m_stats));
    __memcpy(&dst->m_disp_part2, &src->m_disp_part2, sizeof(dst->m_disp_part2));
    dst->m_config.copy_full(&src->m_config);
    __memcpy(dst->m_tech_levels, src->m_tech_levels, sizeof(dst->m_tech_levels));
    return dst;
}

#pragma pop


TPlyDispConfig *TPlyDispConfig::copy_full(TPlyDispConfig *src) {
    m_smth.copy(&src->m_smth);
    m_smth1.copy(&src->m_smth1);
    return this;
}
TPlyDispConfigSmth *TPlyDispConfigSmth::copy(TPlyDispConfigSmth *src) {
    bank = src->bank;
    copy_guild_card_tag_triplet(&m_tags[0], &src->m_tags[0]);
    copy_guild_card_tag_triplet(&m_tags[1], &src->m_tags[1]);
    copy_guild_card_tag_triplet(&m_tags[2], &src->m_tags[2]);
    copy_guild_card_tag_triplet(&m_tags[3], &src->m_tags[3]);
    copy_guild_card_tag_triplet(&m_tags1[0], &src->m_tags1[0]);
    copy_guild_card_tag_triplet(&m_tags1[1], &src->m_tags1[1]);
    copy_guild_card_tag_triplet(&m_tags1[2], &src->m_tags1[2]);
    copy_guild_card_tag_triplet(&m_tags1[3], &src->m_tags1[3]);
    return this;
}
void copy_guild_card_tag_triplet(gc_tag *dst, gc_tag *src) {
    dst->tag0 = src->tag0;
    dst->tag1 = src->tag1;
    dst->tag2 = *(s16 *)&src->tag2;
}
void __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *to, void *from) {
    TPlyGuildCardTag *dst = (TPlyGuildCardTag *)to;
    TPlyGuildCardTag *src = (TPlyGuildCardTag *)from;
    dst->m_tag0 = src->m_tag0;
    dst->m_tag1 = src->m_tag1;
    dst->m_tag2 = src->m_tag2;
    dst->m_guildcard_number = src->m_guildcard_number;
}
void set_item_drop_server_seed(int a0) { item_drop_server_seed = a0; }
void set_area_random_seed(int seed) { area_random_seed = seed; }

void set_quest_list_online_state(s32 state) {
    if (quest_list_online_instance != NULL) {
        quest_list_online_instance->set_state(state);
    }
}

void TWindowMenu::set_ready_flag() { menu_flags |= 0x1; }


int TWindowMenuIconLine::is_decided() { return (this->state_flags >> 1) & 0x1; }
int TWindowMenuIconLine::is_cancelled() { return (this->state_flags >> 2) & 0x1; }
int TWindowMakeTeam::test_flag_1d_bit1() { return (flags >> 1) & 1; }
s32 TWindowMakeTeam::get_kind() { return kind; }
u8 TWindowMakeTeam::get_mode() { return mode; }
u8 TWindowMakeTeam::read_mode() { return mode; }
int TWindowMakeTeam::test_flag_1d_bit0() { return flags & 1; }
u8 *get_access_key_input_buffer(void) {
    return (u8 *)TAdEnterSerialAccessGC::access_key_input_buffer;
}

char *TLobby::init_serial_access() { return TAdEnterSerialAccessGC::hex_to_decimal_string((const char *)get_raw_serial_input_buffer()); }

u8 *get_raw_serial_input_buffer(void) {
    return (u8 *)TAdEnterSerialAccessGC::raw_serial_buffer;
}

const char *get_connection_message_text(s32 id) {
    return text_language_group_table[12][id];
}

const char *get_online_message_text(s32 id) {
    return text_language_group_table[14][id];
}

u8 *get_password_input_buffer(void) {
    return ((u8 *)&TAdEnterPasswordGC::input_buffer);
}

void *TProtocol::operator new(size_t size) { return obj_heap->heap_alloc(size); }
