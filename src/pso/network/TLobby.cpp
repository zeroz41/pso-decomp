#include "pso/system/TLanguage.h"
#include "pso/enemy/EnemyStateRecord.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/GuildCardRecord.h"
#include "pso/player/LocalClientId.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/unk/TLobbyIdleTimer.h"
#include "pso/system/date.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
#include "pso/system/Lzss.h"
#include "pso/system/main_loop.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include <stddef.h>
#include <string.h>
#include "pso/network/TPacket.h"
#include "pso/network/TGameProtocol.h"
#include "pso/network/TLobby.h"
#include "pso/map/AreaEventSet.h"
#include "pso/unk/TLobbyAutoReply.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/map/FloorPopulation.h"
#include "pso/network/LegacyEnemyKill.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/Language.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/player/TPlyInventory.h"
#include <stdio.h>
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/unk/TLobby_8013AD38.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCardEntries.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/map/TSetManager.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/network/client_id.h"
#include "pso/network/NetworkWaitIcon.h"
#include "pso/ui/window/TWindowMenuTeamStatus.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/warp/TObjLaboMapWarp.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/network/NetworkConnect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/unk/TTitleScene.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TObjPlayerCreate.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/ui/frontend/TAdPlayerLoadGCMemCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/system/scene/OnlineLobbyScene.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/map/MapSetData.h"
#include "pso/object/TObjControl.h"
#include "pso/ui/city/THunterGuildSeqOnline.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"


#pragma readonly_strings on

typedef char LobbyPlayerName[16];
struct ByteBlock_8 { u8 bytes[0x8]; };
struct ByteBlock_10 { u8 bytes[0x10]; };
struct ByteBlock_24 { u8 bytes[0x24]; };
struct ByteBlock_50 { u8 bytes[0x50]; };
struct ByteBlock_348 { u8 bytes[0x348]; };
struct ByteBlock_14 { u8 bytes[0x14]; };

extern "C" {
void handle_quest_download_chunk__6TLobbyFv();
void *__dt__15TLobbyIdleTimerFv(void *object, s16 free_flags);
void queue_destruction__7TObjectFv(void *task);
}
void lobby_debug_printf_stub(const char *fmt, ...);
extern "C" {
s32 online_lobby_check_stub();
s32 __ct__7TObjectFP7TObject(void *, void *);
extern const NJS_POINT2 card_list_message_window_size[1];
extern NJS_POINT2 idle_timeout_window_size[1];
void render_shadows__7TObjectFv();
}
extern "C" {
void __register_global_object(int, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __destroy_arr(void *block, void *dtor, u32 size, u32 n);
}
void set_area_random_seed(int a0);


LAYOUT_ASSERT(ProtocolGameEntriesOffset, offsetof(TProtocol, m_game_entries) == 0x1DA8);
LAYOUT_ASSERT(ProtocolEntryCountOffset, offsetof(TProtocol, m_entry_count) == 0x1920);
LAYOUT_ASSERT(ProtocolInvalidPacketOffset, offsetof(TProtocol, m_is_invalid_packet) == 0x2A);
TProtocol *TLobby::protocol_instance;
s32 TLobby::lobby_entered_flag;
s32 TLobby::room_change_pending;
s16 TLobby::pending_local_client_id;
s16 TLobby::pending_member_count;
s32 TLobby::deferred_player_setup_state;
s32 TLobby::lobby_state;
s32 TLobby::join_state_flag;
s32 TLobby::date_seconds;
s32 TLobby::event_theme_id;
s32 TLobby::card_list_selected_index;
s32 TLobby::idle_timeout_active;
s32 TLobby::block_number;
s32 TLobby::lobby_number;
s32 TLobby::join_lobby_idle_timer;
s32 TLobby::lobby_block_high;
s32 TLobby::login_pending_flag;
s32 TLobby::connection_lost;
s32 lobby_login_result_flag;
TWindowMessage *TLobby::card_list_window;
TWindowMessage *TLobby::download_list_window;
TWindowMenuIconLine *TLobby::list_window;
TObject *lobby_player_construction_window;
TWindowMessage *TLobby::current_dialog_window;
TWindowMessage *TLobby::join_entry_window_obj;
TWindowMenu *TLobby_warp_menu_window;
TWindowMenu *lobby_com_card_window;
TWindowMenu *lobby_make_team_menu_window;
TWindowMakeTeam *lobby_make_team_window;
TWindowMenu *lobby_keyboard_prompt_window;
TKeyBoardControl *lobby_keyboard_controller;
TAdScrollWinGC *lobby_scroll_text_window;
s32 TLobby::player_setup_pending;
s32 lobby_selected_game_list_index;
TLobby * TLobby::join_lobby_controller;
TWindowMessage *lobby_idle_timeout_window;

const char *lobby_class_name = "TLobby";
// Lobby server host names (each listed twice in its table).
const char join_lobby_game04_server_host[] = "game04.st-pso.games.sega.net";
const char join_lobby_ss702_server_host[] = "ss702.sonicteam.com";
const char join_lobby_ddplanet_server_host[] = "ddplanet.sega.co.jp";
LobbyServerAddress join_lobby_server_table[2] = { { join_lobby_game04_server_host, 0x238F }, { join_lobby_game04_server_host, 0x238F } };
LobbyServerAddress join_lobby_ss702_server_table[2] = { { join_lobby_ss702_server_host, 0x238C }, { join_lobby_ss702_server_host, 0x238C } };
LobbyServerAddress join_lobby_ddplanet_server_table[2] = { { join_lobby_ddplanet_server_host, 0x2329 }, { join_lobby_ddplanet_server_host, 0x2329 } };
void *lobby_idle_timer_vtable[6] = { 0, 0, (void *)__dt__15TLobbyIdleTimerFv, (void *)TLobby::update_idle_timeout, (void *)render_idle_timeout, (void *)render_shadows__7TObjectFv };

u32 TLobby::join_entries_dtor_registration[3];
#pragma push
#pragma suppress_init_code on
#pragma no_static_dtors on
TPlyJoinLobbyEntry lobby_join_entries[12];
#pragma pop
char lobby_room_title[0x20];
TPlyChallenge lobby_player_status_records[12];
char lobby_ship_name[0x28];
char selected_game_name[0x14];
LobbyPlayerName lobby_player_names[12];
s32 game_join_pending_clients[4];
#pragma push
#pragma suppress_init_code on
TPlyJoinLobbyData game_join_player_records[4];
#pragma pop
u32 lobby_join_message_buffer[64];
char player_joined_message[0x80];
char lobby_idle_timeout_text_buffer[0x100];
u8 lobby_scroll_text_buffer[0x1000];

extern "C" {
void __dt__7TObjectFv(void *, int);
void *__dt__15TLobbyIdleTimerFv(void *object, s16 dtor_flags) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = (s32 *)lobby_idle_timer_vtable;
        __dt__7TObjectFv(object, 0);
        if (dtor_flags > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
}

TQuestThread *create_quest_stats_thread(s32 label) { return TQuestThread::create_in_root(label); }



void TLobby::dispatch_by_index(s32 index) {
    if (index > 3 || index < 0) {
        index = 0;
    }
    switch (index) {
    case 0:
        clear_state();
        return;
    case 1:
        TAdEnterSerialAccessGC::store_serial_access_key((saddr)protocol_instance->m_serial_number2, (saddr)protocol_instance->m_access_key2, (saddr)protocol_instance->m_password);
        return;
    case 2:
        TAdEnterSerialAccessGC::clear_serial_buffer();
        return;
    }
}

void TLobby::open_scroll_text_window(saddr src) {
    void *obj;
    if (lobby_scroll_text_window == 0) {
        strncpy((char *)lobby_scroll_text_buffer, (const char *)src, 0x1000);
        lobby_scroll_text_buffer[0xFFF] = 0;
        lobby_scroll_text_window = new TAdScrollWinGC(tl_window, 2, (const char *)lobby_scroll_text_buffer);
    }
    lobby_state = 0x1A;
}

void TLobby::render() { { (void)(TAdPlayerLoadGC::get_instance()); return; } }


// C5: the server's player records for the lobby.
void TLobby::copy_player_records(TPlyChallenge *records, s32 count) {
    for (s32 i = 0; i < count; i++) {
        if (records[i].client_id > 12) {
            return;
        }
        lobby_player_status_records[records[i].client_id] = records[i];
    }
}

// The 88 handler: the players whose guild card number matches an entry get that arrow colour.
void apply_arrow_colors(TArrowColorList *list) {
    TArrowColorEntry *e = list->entries;
    s32 i;
    for (i = 0; i < list->header.flags; i++, e++) {
        s32 j;
        for (j = 0; j < 12; j++) {
            TObjPlayer *p = get_player_by_client_id(j);
            if (p != NULL && p->guild_card_tag.guildcard_number == e->tag.m_guildcard_number) {
                p->set_lobby_marker(e->color);
            }
        }
    }
}


s32 TLobby::get_option_state() {

    switch (TWindowOptionCtrl::get_udp_option()) {
    case 0:
        return net_session_mode;
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        return 0;
    }
}

void TLobby::install_game_join_handlers() {
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = (recv_packet_handler_handle_64_recv_start_game3)TLobby::handle_game_join;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = TLobby::on_game_player_add;
}



void TLobby::clear_counters() {
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = NULL;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = NULL;
}



void TLobby::disconnect_protocol() {
    TProtocol *protocol;
    protocol = protocol_instance;
    if (protocol != NULL) {
        protocol->send_logout();
    }
}


void TLobby::set_lobby_event_theme(int theme) { event_theme_id = theme; }

void TLobby::handle_info_board(TRecvInfoBoard *info_board) { init_once(info_board); }
void TLobby::handle_choice_search_results(ChoiceSearchResultList *results) { store_choice_search_results(results); }
void TLobby::handle_choice_search_options(TRecvChoiceSearchOptions *options) { store_choice_search_options(options); }

void TLobby::reset_lobby_state(char *time) {
    set_clock_offset_from_server_time(time);
    protocol_instance->send_server_time_accepted();
}


void TLobby::send_game_character() {
    TPlyChoiceSearchConfig choice_search_config;
    TBlockedSenders blocked_senders;
    char c[0xAC];
    TPlyChallenge challenge;
    TPlyText<512> auto_reply;
    CharacterSaveRecord *card;
    TAdSinglePlyChrSelectGC::init();
    card = get_character_save_record(0xFFFF);
    memset(&choice_search_config, 0, sizeof(choice_search_config));
    choice_search_config.disabled = TLobby::open_hard_keyboard(local_client_id) != 0 ? 1 : 0;
    copy_choice_search_selections(card->choice_search.entries, &choice_search_config);
    memset(c, 0, sizeof(c));
    strncpy(c, TLobby::get_info_board_text(), 0xAC);
    memset(&blocked_senders, 0, sizeof(blocked_senders));
    ((TLobby *)&blocked_senders)->collect_active_card_ids();
    memset(&auto_reply, 0, sizeof(auto_reply));
    if (get_flag_bit0() != 0) {
        auto_reply.header.flags = 1;
        strncpy(auto_reply.text, (char *)get_card_window_area(), 0x200);
    }
    memset(&challenge, 0, sizeof(challenge));
    challenge.challenge = card->challenge;
    challenge.battle_place_count_1 = card->online_battle.place_counts[0];
    challenge.battle_place_count_2 = card->online_battle.place_counts[1];
    challenge.battle_place_count_3 = card->online_battle.place_counts[2];
    challenge.battle_place_count_4 = card->online_battle.place_counts[3];
    challenge.battle_disconnect_count = card->online_battle.disconnect_count;
    challenge.battle_reserved_count_1 = card->online_battle.reserved_counts[0];
    challenge.battle_reserved_count_2 = card->online_battle.reserved_counts[1];
    challenge.battle_reserved_value_1 = card->online_battle.reserved_values[0];
    challenge.battle_reserved_value_2 = card->online_battle.reserved_values[1];
    protocol_instance->send_update_chara_data_v2(*TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), challenge, choice_search_config, blocked_senders, auto_reply, c);
}
void TLobby::update_idle_timeout(TLobbyIdleTimer *t) {
    NJS_POINT2 tmp = idle_timeout_window_size[0];
    DateStamp ds;
    u32 limit;
    u32 elapsed;
    getDateStamp(&ds);
    DateToSeconds(&ds, &t->now);
    if (has_window_task_root() == 0) {
        lobby_idle_timeout_window = 0;
    }
    if (hardware_keyboard_state.has_any_key_pressed() != 0 || any_pad_input_active() != 0) {
        t->start = t->now;
        t->state = 0;
        if (lobby_idle_timeout_window != 0) {
            delete lobby_idle_timeout_window;
            lobby_idle_timeout_window = 0;
        }
    }
    t->limit = get_idle_timeout_limit(local_client_id);
    elapsed = t->now - t->start;
    switch (t->state) {
    case 0:
        if (t->limit != 0 && elapsed + 0x1E > t->limit) {
            t->state = 1;
            if (lobby_idle_timeout_window == 0 && has_window_task_root() != 0) {
                sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), t->limit - elapsed);
                lobby_idle_timeout_window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xCA)), (const f32 *)(&tmp), 1);
                lobby_idle_timeout_window->append_line(lobby_idle_timeout_text_buffer, (int)0x80);
                lobby_idle_timeout_window->set_depth(30000.0f);
                lobby_idle_timeout_window->complete_reveal();
            }
        }
        break;
    case 1:
        limit = t->limit;
        if (elapsed > limit) {
            delete lobby_idle_timeout_window;
            lobby_idle_timeout_window = 0;
            idle_timeout_active = 1;
            t->queue_destruction();
        } else {
            sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), limit - elapsed);
        }
        break;
    }
}

u8 *init_idle_timeout_timer(u8 *timer, TObject *parent) {
    TLobbyIdleTimer *t = (TLobbyIdleTimer *)timer;
    DateStamp date;
    __ct__7TObjectFP7TObject(timer, parent);
    *(void ***)((s8 *)timer + 0x18) = lobby_idle_timer_vtable;
    getDateStamp(&date);
    DateToSeconds(&date, (int *)(timer + 0x1C));
    t->start = t->now;
    t->limit = get_idle_timeout_limit(local_client_id);
    t->state = 0;
    lobby_idle_timeout_window = 0;
    return timer;
}

void TLobby::open_udp_socket_for_player(s32 client) {
    TPacket *o = new TPacket((TObject *)game_protocol_instance);
    if (o != NULL) {
        o->m_id = client;
        o->set_ip_address(game_join_player_records[client].ip_addr);
        o->m_dst_port = local_client_id + 0xFA0;
        o->m_src_port = client + 0xFA0;
        s32 v = o->open();
        lobby_debug_printf_stub(lobby_debug_udp_open_format, v, o->m_dst_addr.addr_bytes[0], o->m_dst_addr.addr_bytes[1], o->m_dst_addr.addr_bytes[2], o->m_dst_addr.addr_bytes[3]);
    }
}

void handle_6x71_unblock_game_join(void) {
    TPlyJoinLobbyEntry *e;
    s32 *pend;
    TObjPlayer *p;
    saddr i;

    if (lobby_floor_reload_pending == 0) {
        p = create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        p->guild_card_tag.copy_from((PlayerGuildCardTag *)&TLobby::protocol_instance->m_guildcard_tag);
        p->reset_motion_fields();
        strncpy(lobby_player_names[local_client_id], p->get_name(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        pend = game_join_pending_clients;
        for (i = 0; i < 4; i++) {
            if (pend[i] != 0) {
                TLobby::send_6x70_player_data(i);
                if (get_player_by_client_id(i) == NULL) {
                    e = lobby_join_entries;
                    e += i;
                    p = create_player_object(i, 4, &e->char_data);
                    p->guild_card_tag.copy_from((PlayerGuildCardTag *)&e->tag);
                    p->reset_motion_fields();
                    TLobby::open_udp_socket_for_player(i);
                    lobby_debug_printf_stub(lobby_debug_burst_player_format, i);
                } else {
                    lobby_debug_printf_stub(lobby_debug_duplicate_player_format, i);
                }
            }
            pend[i] = 0;
        }
        TLobby::protocol_instance->send_6F_burst_done();
        TAdSinglePlyChrSelectGC::load_character_from_card(0);
        TLobby::lobby_state = 0xF;
    }
}

void TLobby::send_6x71_to_player(s32 client_id) {
    G_ClientIDHeader packet;
    packet.subcommand = 0x71;
    packet.size = 1;
    packet.client_id = 0;
    bswap_client_id_header(&packet);
    ((game_command *)&packet)->send_to_client(client_id);
}

void handle_6x70_sync_player_disp_and_inventory(PlayerSyncPacket *pkt) {
    TObjPlayer *plr;
    PlayerSyncRecord *disp;
    TObjPlayer *p;
    if (lobby_floor_reload_pending == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        disp = &pkt->record;
        TLobby::bswap_player_data(disp);
        if (disp->client_id != local_client_id) {
            p = get_player_by_client_id(disp->client_id);
            if (p != NULL) {
                delete p;
            }
            plr = create_remote_player_object(disp);
            strncpy(lobby_player_names[plr->get_entity_id()], plr->get_name(), 0x10);
            TLobby::open_udp_socket_for_player(disp->client_id);
            lobby_debug_printf_stub(lobby_debug_create_player_format, plr->get_entity_id());
        }
    }
}
void TLobby::send_6x70_player_data(int size) {
    PlayerSyncRecord record;
    PlayerSyncPacket *packet;
    packet = (PlayerSyncPacket *)mem_alloc(0x494);
    if (packet != NULL) {
        get_player_by_client_id(local_client_id)->fill_player_record(&packet->record);
        packet->header.subcommand = 0x70;
        packet->header.size = 0;
        packet->header.client_id = local_client_id;
        packet->total_size = 0x494;
        bswap_and_send_extended_subcommand(packet, size);
        mem_free(packet);
    }
}

#pragma push
#pragma peephole off
void handle_6x6F_set_quest_flags_v2(G_SetQuestFlags_V2_V3_6x6F *pkt) {
    if (((s16) lobby_floor_reload_pending == 0) && (((s32) TLobby::lobby_state == 0xE) || ((s32) TLobby::lobby_state == 0xF))) {
        memcpy(quest_story_flags_by_difficulty, pkt->quest_flags, 0x200);
    }
}
#pragma pop

void handle_6x6E_sync_game_state(CompressedSyncPacket *pkt) {
  Lzss *lz;
  GameStateSyncScratch *buf;
  s32 n;
  if ((lobby_floor_reload_pending == 0) && ((TLobby::lobby_state == 0xE) || (TLobby::lobby_state == 0xF)))
  {
    lobby_debug_printf_stub(lobby_debug_rcv_set_flag_format, pkt->total_size);
    buf = static_cast<GameStateSyncScratch *>(::operator new(sizeof(GameStateSyncScratch)));
    if (buf != 0)
    {
      lz = new Lzss;
      if (lz != 0)
      {
        lz->decode(pkt->data, pkt->total_size, buf);
        delete lz;
        buf->bswap();
        apply_floor_set_flags_packet(reinterpret_cast<FloorSetFlagsHeader *>(buf->payload), buf->floor_flags_size);
        n = buf->floor_flags_size;
        import_floor_event_flags(reinterpret_cast<s16 *>(&buf->payload[n]), buf->sync_records_size);

        if ((buf->sync_records_size && buf->sync_records_size) && buf->sync_records_size)
        {
        }
        n += buf->sync_records_size;
        restore_switch_table(&buf->payload[n], buf->switch_table_size);
        activate_triggered_floor_events();
      }
      ::operator delete((0, buf));
    }
  }
}

void handle_6x6D_sync_game_state(CompressedSyncPacket *pkt) {
    s32 len;
    G_SyncItemState_6x6D_Decompressed *buf;
    Lzss *lz;
    if (lobby_floor_reload_pending == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        len = pkt->total_size - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_item_condition_format, pkt->total_size);
        buf = (G_SyncItemState_6x6D_Decompressed *)mem_alloc(0x8000);
        if (buf != NULL) {
            lz = new Lzss;
            if (lz != NULL) {
                lz->decode(pkt->data + 0, len, buf);
                delete lz;
            }
            buf->apply();
            mem_free(buf);
        }
    }
}

void handle_6x6C_sync_game_state(CompressedSyncPacket *pkt) {
    u32 r;
    QuestObjectEntry *p;
    Lzss *lz;
    s32 n;
    s32 i;
    if (lobby_floor_reload_pending == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        n = pkt->total_size - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_object_condition_format, pkt->total_size);
        lz = new Lzss;
        if (lz != NULL) {
            r = lz->decode(pkt->data, n, quest_object_entries);
            delete lz;
            n = r >> 2;
            p = quest_object_entries;
            object_condition_count = n;
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
        }
    }
}

void handle_6x6B_sync_game_state(CompressedSyncPacket *pkt) {
    u32 r;
    EnemyStateRecord *p;
    Lzss *lz;
    s32 n;
    s32 i;
    if (lobby_floor_reload_pending == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        n = pkt->total_size - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_enemy_condition_format, pkt->total_size);
        lz = new Lzss;
        if (lz != NULL) {
            r = lz->decode(pkt->data, n, enemy_state_records);
            delete lz;
            n = r / sizeof(EnemyStateRecord);
            p = enemy_state_records;
            enemy_condition_count = n;
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
        }
    }
}

void send_6x6F_quest_flags(saddr size) {
    G_SetQuestFlags_V2_V3_6x6F packet;
    init_6x6F_quest_flags_packet(&packet);
    memcpy(packet.quest_flags, quest_story_flags_by_difficulty, sizeof(packet.quest_flags));
    TLobby::bswap_and_handle_packet(&packet, size);
}
void TLobby::send_6x6E_sync_game_state(int size) {
    s32 n;
    s32 len;
    CompressedSyncPacket *buf;
    GameStateSyncScratch *hdr;
    Lzss *lz;
    buf = (CompressedSyncPacket *)mem_alloc(0x4000);
    if (buf != NULL) {
        memset(buf, 0, 0x4000);
        hdr = static_cast<GameStateSyncScratch *>(::operator new(sizeof(GameStateSyncScratch)));
        if (hdr != NULL) {
            memset(hdr, 0, sizeof(*hdr));
            hdr->floor_flags_size = serialize_area_set_flags(reinterpret_cast<FloorSetFlagsPayload *>(hdr->payload));
            n = hdr->floor_flags_size;
            hdr->sync_records_size = export_floor_event_flags(reinterpret_cast<s16 *>(&hdr->payload[n]));
            n += hdr->sync_records_size;
            hdr->switch_table_size = copy_switch_table(&hdr->payload[n]);
            n += hdr->switch_table_size;
            hdr->total_size = n;
            hdr->bswap();
            lz = new Lzss;
            if (lz != NULL) {
                len = lz->encode(hdr, n, buf->data);
                delete lz;
            }
            ::operator delete(hdr);
        }
        buf->header.subcommand = 0x6E;
        buf->header.size = 0;
        buf->header.unused = 0;
        buf->total_size = ((len + 3) & ~3) + 8;
        bswap_and_send_extended_subcommand(buf, size);
        mem_free(buf);
    }
}

void TLobby::send_6x6D_item_state(s32 client) {
    s32 n;
    s32 len;
    CompressedSyncPacket *buf;
    G_SyncItemState_6x6D_Decompressed *src;
    Lzss *lz;
    buf = (CompressedSyncPacket *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        src = (G_SyncItemState_6x6D_Decompressed *)mem_alloc(0x8000);
        if (src != NULL) {
            memset(src, 0, 0x8000);
            n = src->write();
            lz = new Lzss;
            if (lz != NULL) {
                len = lz->encode(src, n, buf->data);
                delete lz;
            }
            mem_free(src);
        }
        buf->header.subcommand = 0x6D;
        buf->header.size = 0;
        buf->header.unused = 0;
        buf->total_size = ((len + 3) & ~3) + 8;
        bswap_and_send_extended_subcommand(buf, client);
        mem_free(buf);
    }
}

void TLobby::send_compressed_packet_6c(s32 client) {
    QuestObjectEntry *src;
    s32 len;
    u32 size;
    CompressedSyncPacket *buf;
    Lzss *lz;
    u32 n;
    QuestObjectEntry *p;
    u32 i;
    buf = (CompressedSyncPacket *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        lz = new Lzss;
        if (lz != NULL) {
            src = quest_object_entries;
            size = object_condition_count * 4;
            n = size / 4;
            p = (QuestObjectEntry *)mem_alloc(size);
            memcpy(p, src, size);
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
            len = lz->encode(p, size, buf->data);
            mem_free(p);
            delete lz;
            buf->header.subcommand = 0x6C;
            buf->header.size = 0;
            buf->header.unused = 0;
            buf->total_size = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand(buf, client);
        }
        mem_free(buf);
    }
}

void TLobby::send_cmd_6B(s32 client) {
    EnemyStateRecord *src;
    s32 len;
    u32 size;
    CompressedSyncPacket *buf;
    Lzss *lz;
    u32 n;
    EnemyStateRecord *p;
    u32 i;
    buf = (CompressedSyncPacket *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        lz = new Lzss;
        if (lz != NULL) {
            src = enemy_state_records;
            size = enemy_condition_count * sizeof(EnemyStateRecord);
            n = size / sizeof(EnemyStateRecord);
            p = (EnemyStateRecord *)mem_alloc((s32)(n * sizeof(EnemyStateRecord)));
            memcpy(p, src, size);
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
            len = lz->encode(p, size, buf->data);
            mem_free(p);
            delete lz;
            buf->header.subcommand = 0x6B;
            buf->header.size = 0;
            buf->header.unused = 0;
            buf->total_size = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand(buf, client);
        }
        mem_free(buf);
    }
}

void show_card_list_message(TPlyText<288> &info) {
    if (TLobby::card_list_window != 0) {
        TLobby::card_list_window->close();
        TLobby::card_list_window = 0;
    }
    if (TLobby::lobby_state == 0x11) {
        NJS_POINT2 p = card_list_message_window_size[0];
        TLobby::card_list_window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xC9)), (const f32 *)(&p), 1);
        TLobby::card_list_window->append_line(info.text, (int)3);
        TLobby::card_list_window->set_depth(37000.0f);
    }
}

#pragma defer_codegen on
void TLobby::show_seq_phase_message(int id) {
    if (current_dialog_window == 0) {
        NJS_POINT2 tmp = { 342.0f, 144.0f };
        current_dialog_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        current_dialog_window->set_depth(30001.0f);
    }
    current_dialog_window->append_line((TLobby::get_seq_phase(id)), (int)1);
}

void show_dialog_value_line(const char *text) {
    if (TLobby::current_dialog_window == 0) {
        NJS_POINT2 tmp = { 342.0f, 144.0f };
        TLobby::current_dialog_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        TLobby::current_dialog_window->set_depth(30001.0f);
    }
    TLobby::current_dialog_window->append_line(text, (int)1);
}
void TLobby::close_com_card_window() {
    if (current_dialog_window != 0U) {
        current_dialog_window->close();
        current_dialog_window = 0U;
    }
}

void show_join_entry_message(s32 id) {
    if (TLobby::join_entry_window_obj == 0) {
        NJS_POINT2 tmp = { 558.0f, 224.0f };
        TLobby::join_entry_window_obj = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc2), &tmp);
    }
    TLobby::join_entry_window_obj->append_line((TLobby::get_seq_phase(id)), (int)1);
}

void TLobby::run_task() {
    s32 r;
    switch ((u32)lobby_state) {
    case 1:
        handle_team_select();
        break;
    case 2:
        handle_team_select();
        break;
    case 3:
        handle_warp_menu_input();
        break;
    case 4:
        update_menu_window();
        break;
    case 6:
        update_game_list_menu();
        break;
    case 9:
        handle_comcard_window();
        break;
    case 10:
        handle_create_game_window();
        break;
    case 5:
        handle_com_card();
        break;
    case 7:
        update_ship_select_window();
        break;
    case 8:
        update_block_jump_list();
        break;
    case 12:
        queue_join_entry_exit_on_input(this);
        return;
    case 13:
        update();
        break;
    case 17:
        update_card_list_window();
        break;
    case 20:
        update_short_list();
        break;
    case 22:
        handle_short_list_input();
        break;
    case 21:
        handle_game_list_select();
        break;
    case 24:
        update_make_team_menu();
        break;
    case 26:
        update_scroll_close();
        break;
    case 25:
        update_com_card_window();
        break;
    case 23:
        return;
    }
    if (quest_download_active != 0) {
        update_network_wait_icon();
    }
    r = query_task_active();
    if (protocol_instance->m_is_invalid_packet != 0 || get_link_status() == 0 || r < 0) {
        protocol_instance->m_is_invalid_packet = 0;
        TQuestListOnline::close_windows_and_reset();
        if (r < 0) {
            TLobby::update_state();
            return;
        }
        while (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) == -1) {
        }
        update_state_with_location();
    }
}
void TLobby::handle_team_select() {
    s32 idx;
    if (list_window != 0U) {
        if (list_window->is_decided() != 0) {
            idx = list_window->get_cursor_value();
            list_window->close();
            list_window = 0U;
            protocol_instance->send_action(
                protocol_instance->m_game_entries[idx],
                (char *)lobby_window_title_taisen_team, "");
            TLobby::close_and_set_state_12();
            return;
        }
        if (controller_input_state.sources[0]->pressed & 0x400) {
            idx = list_window->get_cursor_value();
            protocol_instance->send_info(protocol_instance->m_game_entries[idx].tag);
        }
    }
}
void TLobby::handle_game_list_select() {
    s32 cursor_value;

    if (list_window != 0U) {
        if (list_window->is_decided() != 0) {
            cursor_value = list_window->get_cursor_value();
            list_window->close();
            list_window = 0U;
            protocol_instance->send_action(
                protocol_instance->m_game_entries[cursor_value],
                "", "");
            TLobby::close_and_set_state_12();
            return;
        }
        if (list_window->is_cancelled() != 0) {
            list_window->close();
            list_window = 0U;
            TLobby::close_all_windows();
        }
    }
}
void TLobby::handle_warp_menu_input() {
    s32 selected_menu_value;

    if (TLobby_warp_menu_window != NULL) {
        if (TLobby_warp_menu_window->is_decided() != 0) {
            selected_menu_value = TLobby_warp_menu_window->get_selected_value();
            switch (selected_menu_value) {
            case 0:
                TLobby::create_warp_menu();
                return;
            case 1:
                TLobby::open_warp_menu();
                return;
            case 2:
                TLobby::close_and_send_text_list();
                return;
            case 3:
                TLobby::open_city_warp_menu();
                return;
            }
        } else if (TLobby_warp_menu_window->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::update_menu_window() {
    s32 selected_menu_value;

    if (lobby_com_card_window != NULL) {
        selected_menu_value = lobby_com_card_window->get_selected_value();
        if (lobby_com_card_window->is_decided() != 0) {
            switch (selected_menu_value) {
            case 0:
                TLobby::request_game_list();
                return;
            case 1:
                TLobby::open_menu_window();
                return;
            case 2:
                // The callee is called with no argument here; the (void *) in its symbol is a guess
                ((void (*)())(void (*)(void *))TLobby::close_all_windows)();
                return;
            }
        } else if (lobby_com_card_window->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::update_game_list_menu() {
    if (list_window != 0U) {
        if (list_window->is_decided() != 0) {
            lobby_selected_game_list_index = list_window->get_cursor_value();
            list_window->close();
            list_window = 0U;
            if (protocol_instance->m_game_entries[lobby_selected_game_list_index].flags & 2) {
                TLobby::open_keyboard_window();
                return;
            }
            protocol_instance->send_action(
                protocol_instance->m_game_entries[lobby_selected_game_list_index],
                "", "");
            TLobby::destroy_lobby_ui();
            return;
        }
        if (list_window->is_cancelled() != 0) {
            list_window->close();
            list_window = 0U;
            TLobby::close_all_windows();
            return;
        }
        if (controller_input_state.sources[0]->pressed & 0x400) {
            lobby_selected_game_list_index = list_window->get_cursor_value();
            if (lobby_selected_game_list_index < protocol_instance->m_entry_count) {
                protocol_instance->send_info(protocol_instance->m_game_entries[lobby_selected_game_list_index].tag);
            }
        }
    }
}
void TLobby::handle_com_card() {
    s32 selected_value;

    if (lobby_com_card_window != NULL) {
        if (lobby_com_card_window->is_decided() != 0) {
            TLobby::close_com_card_window();
            selected_value = lobby_com_card_window->get_selected_value();
            switch (selected_value) {
            case 0:
                TLobby::return_to_main_menu();
                return;
            case 1:
                TLobby::close_menu_windows();
                return;
            }
        } else if (lobby_com_card_window->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::update_ship_select_window() {
    s32 idx;
    if (list_window != 0U) {
        if (list_window->is_decided() != 0) {
            idx = list_window->get_cursor_value();
            list_window->close();
            list_window = 0U;
            protocol_instance->send_action(
                protocol_instance->m_game_entries[idx],
                (char *)lobby_window_title_ship_jump, "");
            TLobby::close_and_set_state_12();
            return;
        }
        if (controller_input_state.sources[0]->pressed & 0x400) {
            idx = list_window->get_cursor_value();
            protocol_instance->send_info(protocol_instance->m_game_entries[idx].tag);
        }
    }
}
void TLobby::update_block_jump_list() {
    s32 idx;
    if (list_window != 0U) {
        if (list_window->is_decided() != 0) {
            idx = list_window->get_cursor_value();
            list_window->close();
            list_window = 0U;
            protocol_instance->send_action(
                protocol_instance->m_game_entries[idx],
                (char *)lobby_window_title_block_jump, "");
            TLobby::close_and_set_state_12();
            return;
        }
        if (controller_input_state.sources[0]->pressed & 0x400) {
            idx = list_window->get_cursor_value();
            protocol_instance->send_info(protocol_instance->m_game_entries[idx].tag);
        }
    }
}

void queue_join_entry_exit_on_input(TObject *task) {
    if ((controller_input_state.sources[0]->pressed & 8) || TLobby::join_lobby_idle_timer++ > 0xe10) {
        TAdSinglePlyChrSelectGC::init();
        set_queued_main_phase(2);
        request_main_phase(0x12);
        task->queue_destruction();
    }
}
void TLobby::update() {
    if (join_entry_window_obj != 0U) {
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 8) != 0) {
            if (((TWindowMessagePage *)join_entry_window_obj)->is_message_window_ready() == 0) {
                join_entry_window_obj->complete_reveal();
            } else {
                join_entry_window_obj->close();
                join_entry_window_obj = 0U;
                TLobby::close_all_windows();
                protocol_instance->send_server_time_accepted();
            }
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}
// The create-game call uses the low byte of the team's word result in r3.
extern "C" u8 get_field_20__15TWindowMakeTeamFv(TWindowMakeTeam *window);

void TLobby::handle_create_game_window() {
    const char *name;
    const char *password;
    u8 battle_mode;
    u8 difficulty;
    u8 challenge_mode;
    u8 episode;

    if (lobby_make_team_window != NULL) {
        if (lobby_make_team_window->test_flag_1d_bit0() != 0) {
            name = lobby_make_team_window->get_name();
            if (name != NULL) {
                password = lobby_make_team_window->get_comment();
                battle_mode = (s8)lobby_make_team_window->read_mode() == 2;
                difficulty = lobby_make_team_window->is_enabled();
                challenge_mode = (s8)lobby_make_team_window->get_mode() == 1;
                episode = get_field_20__15TWindowMakeTeamFv(lobby_make_team_window);
                protocol_instance->send_create_game((char *)name, (char *)password, difficulty, battle_mode, challenge_mode, episode);
                TLobby::destroy_lobby_ui();
                return;
            }
            TLobby::close_all_windows();
            return;
        }
        if (lobby_make_team_window->test_flag_1d_bit1() != 0) {
            TLobby::close_all_windows();
        }
    }
}
void TLobby::update_make_team_menu() {
    s32 selected_menu_value;
    static s32 last_selection = 0;
    if (lobby_make_team_menu_window != NULL) {
        selected_menu_value = lobby_make_team_menu_window->get_selected_value();
        if (last_selection != selected_menu_value) {
            last_selection = selected_menu_value;
            switch (selected_menu_value) {
            case 0:
                TLobby::show_seq_phase_message(0x11);
                break;
            case 1:
                TLobby::show_seq_phase_message(0x12);
                break;
            }
        }
        if (lobby_make_team_menu_window->is_decided() != 0) {
            lobby_make_team_menu_window->close();
            lobby_make_team_menu_window = NULL;
            TLobby::close_com_card_window();
            if (TLobby_warp_menu_window != NULL) {
                TLobby_warp_menu_window->close();
                TLobby_warp_menu_window = NULL;
            }
            if (lobby_com_card_window != NULL) {
                lobby_com_card_window->close();
                lobby_com_card_window = NULL;
            }
            switch (selected_menu_value) {
            case 0:
                TLobby::open_make_team_window(1);
                return;
            case 1:
                TLobby::open_make_team_window(2);
                return;
            }
        } else if (lobby_make_team_menu_window->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    }
}
void TLobby::handle_comcard_window() {
    char *text;

    if (lobby_keyboard_controller != NULL) {
        if (lobby_keyboard_controller->is_cancelled() != 0) {
            lobby_keyboard_controller->queue_destruction();
            lobby_keyboard_controller = NULL;
            TLobby::close_all_windows();
            return;
        }
        if (lobby_keyboard_controller->is_confirmed() != 0) {
            text = lobby_keyboard_controller->realloc_buffer();
            protocol_instance->send_action(
                protocol_instance->m_game_entries[lobby_selected_game_list_index],
                "", text);
            mem_free(text);
            lobby_keyboard_controller->queue_destruction();
            lobby_keyboard_controller = NULL;
            lobby_keyboard_prompt_window->close();
            lobby_keyboard_prompt_window = NULL;
            TLobby::destroy_lobby_ui();
        }
    }
}

GameListEntry::GameListEntry() {}
void TLobby::update_card_list_window() {
    s32 sel;
    u32 btn;
    if (list_window == 0) {
        return;
    }
    if (list_window->is_decided() != 0) {
        sel = list_window->get_cursor_value();
        list_window->close();
        list_window = 0;
        GameListEntry e;
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e, &protocol_instance->m_quest_entries[sel]);
        protocol_instance->send_action(e, "", "");
        if (card_list_window != 0) {
            card_list_window->close();
            card_list_window = 0;
        }
        TLobby::close_all_windows();
        return;
    }
    if (download_list_window != 0) {
        sel = list_window->get_cursor_value();
        if (sel != card_list_selected_index) {
            download_list_window->append_line(protocol_instance->m_quest_entries[sel].short_description, (int)3);
            download_list_window->complete_reveal();
            if (card_list_window != 0) {
                card_list_window->close();
                card_list_window = 0;
            }
            card_list_selected_index = sel;
            return;
        }
    }
    btn = controller_input_state.sources[0]->pressed;
    if (btn & 0x400) {
        sel = list_window->get_cursor_value();
        GameListEntry e2;
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e2, &protocol_instance->m_quest_entries[sel]);
        protocol_instance->send_info(e2.tag);
    } else if (btn & 2) {
        if (card_list_window != 0) {
            card_list_window->close();
            card_list_window = 0;
        } else {
            TLobby::return_to_main_menu();
        }
    }
}
void TLobby::update_short_list() {
    void *context;

    if (download_list_window != NULL) {
        context = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(context, 4) != 0) {
            if (((TWindowMessagePage *)download_list_window)->is_message_window_ready() == 0) {
                download_list_window->complete_reveal();
            } else {
                download_list_window->close();
                download_list_window = 0U;
                TLobby::close_all_windows();
            }
        } else if (test_pressed_buttons_packed(context, 2) != 0) {
            download_list_window->close();
            download_list_window = 0U;
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}
void TLobby::handle_short_list_input() {
    void *context;

    if (join_entry_window_obj != 0U) {
        context = &controller_input_state.controllers[0];
        if (test_pressed_buttons_packed(context, 4) != 0) {
            if (((TWindowMessagePage *)join_entry_window_obj)->is_message_window_ready() == 0) {
                join_entry_window_obj->complete_reveal();
            } else {
                join_entry_window_obj->close();
                join_entry_window_obj = 0U;
                TLobby::close_all_windows();
            }
        } else if (test_pressed_buttons_packed(context, 2) != 0) {
            join_entry_window_obj->close();
            join_entry_window_obj = 0U;
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}
void TLobby::update_scroll_close() {
    if (lobby_scroll_text_window != NULL) {
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0xE) != 0) {
            lobby_scroll_text_window->close();
            lobby_scroll_text_window = NULL;
            TLobby::destroy_lobby_ui();
            reset_controller_input_state();
            protocol_instance->send_message_box_closed();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::close_all_windows() {
    if (card_list_window != NULL) {
        card_list_window->close();
        card_list_window = 0U;
    }
    if (download_list_window != NULL) {
        download_list_window->close();
        download_list_window = 0U;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = 0U;
    }
    if (current_dialog_window != 0U) {
        current_dialog_window->close();
        current_dialog_window = 0U;
    }
    if (join_entry_window_obj != 0U) {
        join_entry_window_obj->close();
        join_entry_window_obj = 0U;
    }
    if (TLobby_warp_menu_window != NULL) {
        TLobby_warp_menu_window->close();
        TLobby_warp_menu_window = NULL;
    }
    if (lobby_com_card_window != NULL) {
        lobby_com_card_window->close();
        lobby_com_card_window = NULL;
    }
    if (lobby_make_team_menu_window != NULL) {
        lobby_make_team_menu_window->close();
        lobby_make_team_menu_window = NULL;
    }
    if (lobby_make_team_window != NULL) {
        lobby_make_team_window->queue_destruction();
        lobby_make_team_window = NULL;
    }
    if (lobby_keyboard_prompt_window != NULL) {
        lobby_keyboard_prompt_window->queue_destruction();
        lobby_keyboard_prompt_window = NULL;
    }
    if (lobby_keyboard_controller != NULL) {
        lobby_keyboard_controller->queue_destruction();
        lobby_keyboard_controller = NULL;
    }
    if (lobby_scroll_text_window != NULL) {
        lobby_scroll_text_window->queue_destruction();
        lobby_scroll_text_window = NULL;
    }
    TLobby::update_player_window();
    lobby_state = 0;
}
void TLobby::destroy_lobby_ui() {
    if (card_list_window != NULL) {
        card_list_window->close();
        card_list_window = NULL;
    }
    if (download_list_window != NULL) {
        download_list_window->close();
        download_list_window = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    if (current_dialog_window != NULL) {
        current_dialog_window->close();
        current_dialog_window = NULL;
    }
    if (join_entry_window_obj != NULL) {
        join_entry_window_obj->close();
        join_entry_window_obj = NULL;
    }
    if (TLobby_warp_menu_window != NULL) {
        TLobby_warp_menu_window->close();
        TLobby_warp_menu_window = NULL;
    }
    if (lobby_com_card_window != NULL) {
        lobby_com_card_window->close();
        lobby_com_card_window = NULL;
    }
    if (lobby_make_team_menu_window != NULL) {
        lobby_make_team_menu_window->close();
        lobby_make_team_menu_window = NULL;
    }
    if (lobby_make_team_window != NULL) {
        lobby_make_team_window->queue_destruction();
        lobby_make_team_window = NULL;
    }
    if (lobby_keyboard_prompt_window != NULL) {
        lobby_keyboard_prompt_window->queue_destruction();
        lobby_keyboard_prompt_window = NULL;
    }
    if (lobby_scroll_text_window != NULL) {
        lobby_scroll_text_window->queue_destruction();
        lobby_scroll_text_window = NULL;
    }
    lobby_state = 0xE;
}
void TLobby::set_menu_mode_0() {
    TLobby::show_seq_phase_message(0);
    lobby_state = 1;
}
void TLobby::set_menu_mode_1() {
    TLobby::show_seq_phase_message(1);
    lobby_state = 1;
}
void TLobby::set_menu_mode_2() {
    TLobby::show_seq_phase_message(2);
    lobby_state = 0x15;
}
void TLobby::open_lobby_warp_menu() {
    const NJS_POINT2 *window_layout_position;
    TLobby::show_seq_phase_message(3);
    window_layout_position = get_window_layout_position(0xB4);
    if ((s32) lobby_number < 0xD) {
        TLobby_warp_menu_window = create_window_menu_default(window_layout_position, 2);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x35), 6, 0);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x36), 6, 1);
    } else {
        TLobby_warp_menu_window = create_window_menu_default(window_layout_position, 3);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x35), 6, 0);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x36), 6, 1);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x47), 6, 3);
    }
    TLobby_warp_menu_window->calc_window_size();
    TLobby_warp_menu_window->align_menu_entry_positions();
    TLobby_warp_menu_window->set_ready_flag();
    TLobby::init_player_window_effect();
    lobby_state = 3;
}

void update_state_with_location(void) {
    if (TLobby::join_lobby_controller != NULL) {
        if ((s32) TLobby::player_setup_pending == 0) {
            if ((s32) TLobby::lobby_state != 0xC) {
                sprintf((char *)lobby_join_message_buffer, (const char *)TLobby::get_seq_phase(7), lobby_room_title);
                show_dialog_value_line((const char *)lobby_join_message_buffer);
                TLobby::current_dialog_window->reparent_to_main_ctrl();
                TLobby::init_player_window_effect();
                TLobby::join_lobby_idle_timer = 0;
                TLobby::lobby_state = 0xC;
                if (TLobby::protocol_instance != NULL) {
                    TLobby::protocol_instance->m_is_invalid_packet |= 1;
                }
            }
        } else {
            TLobby::deferred_player_setup_state = 5;
            TLobby::lobby_state = 0x17;
        }
        TLobby::connection_lost = 1;
    }
}
void TLobby::update_state() {
    if (join_lobby_controller != NULL) {
        if ((s32) player_setup_pending == 0) {
            if ((s32) lobby_state != 0xC) {
                TLobby::show_seq_phase_message(0x21);
                current_dialog_window->reparent_to_main_ctrl();
                TLobby::init_player_window_effect();
                join_lobby_idle_timer = 0;
                lobby_state = 0xC;
                if (protocol_instance != NULL) {
                    protocol_instance->m_is_invalid_packet |= 1;
                }
            }
        } else {
            deferred_player_setup_state = 5;
            lobby_state = 0x17;
        }
        TLobby::connection_lost = 1;
    }
}
void TLobby::reset_state(int msg) {
    show_join_entry_message(msg);
    TLobby::init_player_window_effect();
    join_lobby_idle_timer = 0;
    lobby_state = 0xC;
    TLobby::connection_lost = 1;
}
void TLobby::close_and_set_state_13(int msg) {
    show_join_entry_message(msg);
    TLobby::init_player_window_effect();
    lobby_state = 0xD;
}
void TLobby::create_warp_menu() {
    const NJS_POINT2 *window_layout_position;
    TLobby_warp_menu_window->open();
    window_layout_position = get_window_layout_position(0xB5);
    lobby_com_card_window = create_window_menu_default(window_layout_position, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x39), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3A), 6, 1);
    lobby_com_card_window->calc_window_size();
    lobby_com_card_window->align_menu_entry_positions();
    lobby_com_card_window->set_ready_flag();
    lobby_state = 4;
}
void TLobby::request_game_list() {
    TLobby::show_seq_phase_message(4);
    if (TLobby_warp_menu_window != NULL) {
        TLobby_warp_menu_window->close();
        TLobby_warp_menu_window = NULL;
    }
    if (lobby_com_card_window != NULL) {
        lobby_com_card_window->close();
        lobby_com_card_window = NULL;
    }
    protocol_instance->send_game_list();
    lobby_state = 6;
}
void TLobby::open_menu_window() {
    TWindowMenu *menu = lobby_com_card_window;
    if (menu != NULL) {
        menu->open();
    }
    TLobby::show_seq_phase_message(0x11);
    lobby_make_team_menu_window = create_window_menu_default(get_window_layout_position(0xB6), 2);
    lobby_make_team_menu_window->add_text_entry(TLobby::get_seq_phase(0x45), 6, 0);
    lobby_make_team_menu_window->add_text_entry(TLobby::get_seq_phase(0x46), 6, 1);
    lobby_make_team_menu_window->calc_window_size();
    lobby_make_team_menu_window->align_menu_entry_positions();
    lobby_make_team_menu_window->set_ready_flag();
    lobby_make_team_menu_window->set_selected_index(0);
    lobby_state = 0x18;
}
void TLobby::open_make_team_window(int mode) {
    lobby_make_team_window = new TWindowMakeTeam((TObject *)join_lobby_controller, mode);
    lobby_state = 0xA;
}
void TLobby::close_all_windows(void *) { TLobby::close_all_windows(); }
void TLobby::open_warp_menu() {
    const NJS_POINT2 *window_layout_position;
    TLobby_warp_menu_window->open();
    window_layout_position = get_window_layout_position(0xB5);
    lobby_com_card_window = create_window_menu_default(window_layout_position, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3E), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3F), 6, 1);
    lobby_com_card_window->calc_window_size();
    lobby_com_card_window->align_menu_entry_positions();
    lobby_com_card_window->set_ready_flag();
    lobby_state = 5;
}
void TLobby::return_to_main_menu() {
    TWindowBase *t;

    TLobby::show_seq_phase_message(6);
    t = TLobby_warp_menu_window;
    if (t != NULL) {
        t->close();
        TLobby_warp_menu_window = NULL;
    }
    t = lobby_com_card_window;
    if (t != NULL) {
        t->close();
        lobby_com_card_window = NULL;
    }
    t = download_list_window;
    if (t != NULL) {
        t->close();
        download_list_window = 0U;
    }
    t = card_list_window;
    if (t != NULL) {
        t->close();
        card_list_window = 0U;
    }
    t = list_window;
    if (t != NULL) {
        t->close();
        list_window = 0U;
    }
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = TLobby::open_ship_block_select_menu;
    protocol_instance->send_ship_list_request();
    lobby_state = 7;
}
void TLobby::close_menu_windows() {
    TLobby::show_seq_phase_message(6);
    TLobby_warp_menu_window->close();
    TLobby_warp_menu_window = NULL;
    lobby_com_card_window->close();
    lobby_com_card_window = NULL;
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = TLobby::open_ship_block_select_menu;
    protocol_instance->send_block_list_request();
    lobby_state = 8;
}
void TLobby::close_and_send_text_list() {
    TLobby::close_all_windows();
    TLobby::init_player_window_effect();
    protocol_instance->send_text_list();
}
void TLobby::open_keyboard_window() {
    const NJS_POINT2 *window_layout_position;

    if (current_dialog_window != 0U) {
        current_dialog_window->close();
        current_dialog_window = 0U;
    }
    if (lobby_keyboard_prompt_window == NULL) {
        static const char *blank_entry = " ";
        window_layout_position = get_window_layout_position(0xC3);
        lobby_keyboard_prompt_window = create_window_menu_default(window_layout_position, 2);
        lobby_keyboard_prompt_window->add_text_entry(TLobby::get_seq_phase(0x44), 2, 0);
        lobby_keyboard_prompt_window->add_text_entry(blank_entry, 2, 1);
        lobby_keyboard_prompt_window->calc_window_size();
        lobby_keyboard_prompt_window->align_menu_entry_positions();
        lobby_keyboard_prompt_window->disable_input();
    }
    lobby_keyboard_controller = new TKeyBoardControl(join_lobby_controller, 0x10, 0, 0, local_client_id);
    lobby_keyboard_controller->set_sub_position((u8 *)(get_window_layout_position(0xC4)));
    lobby_keyboard_controller->set_hard_position((u8 *)get_window_layout_position(0xC5));
    lobby_state = 9;
}
void TLobby::close_and_set_state_12() {
    TLobby::close_all_windows();
    TLobby::init_player_window_effect();
    lobby_state = 0x12;
}
void TLobby::send_room_change(int idx) {
    room_change_pending = 1;
    TLobby::init_player_window_effect();
    protocol_instance->send_room_change(idx);
    lobby_state = 0x13;
}
void TLobby::open_city_warp_menu() {
    const NJS_POINT2 *window_layout_position;
    TLobby_warp_menu_window->open();
    window_layout_position = get_window_layout_position(0xB5);
    lobby_com_card_window = create_window_menu_default(window_layout_position, 5);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4C), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x48), 6, 1);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x49), 6, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4A), 6, 3);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4B), 6, 4);
    lobby_com_card_window->calc_window_size();
    lobby_com_card_window->align_menu_entry_positions();
    lobby_com_card_window->set_ready_flag();
    lobby_state = 0x19;
}
void TLobby::update_com_card_window() {
    s32 selected_menu_value;

    if (lobby_com_card_window != NULL) {
        selected_menu_value = lobby_com_card_window->get_selected_value();
        if (lobby_com_card_window->is_decided() != 0) {
            protocol_instance->send_lobby_arrow(selected_menu_value);
            TLobby::close_all_windows();
            return;
        }
        if (lobby_com_card_window->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::init_player_window_effect() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        player->init_effect_5f0();
    }
    TWindowCtrl::suppress_slot(local_client_id);
}
void TLobby::update_player_window() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer::clear_lobby_flag(player);
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
}

void handle_error(const char *text) {
    if (TLobby::download_list_window == 0) {
        NJS_POINT2 tmp = { 224.0f, 188.0f };
        TLobby::download_list_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc6), &tmp);
    }
    TLobby::download_list_window->append_line(text, (int)3);
    TLobby::lobby_state = 0x14;
    set_quest_list_online_state(0xb);
}

TLobby::~TLobby() {
    TLobby::destroy_all_objects();
    protocol_instance = NULL;
    lobby_entered_flag = 0;
    room_change_pending = 0;
    pending_local_client_id = 0;
    pending_member_count = 0;
    deferred_player_setup_state = 0;
    lobby_state = 0;
    join_state_flag = 1;
    date_seconds = 0;
    event_theme_id = 0;
    card_list_selected_index = 0;
    idle_timeout_active = 0;
    block_number = 0;
    lobby_number = 0;
    join_lobby_idle_timer = 0;
    lobby_block_high = 0;
    login_pending_flag = 1;
    TLobby::connection_lost = 0;
    player_setup_pending = 0;
    lobby_selected_game_list_index = 0;
    join_lobby_controller = NULL;
    lobby_challenge_mode = 0;
}
void TLobby::destroy_all_objects() {
    if (card_list_window != NULL) {
        card_list_window->queue_destruction();
        card_list_window = 0U;
    }
    if (download_list_window != NULL) {
        download_list_window->queue_destruction();
        download_list_window = 0U;
    }
    if (list_window != NULL) {
        list_window->queue_destruction();
        list_window = 0U;
    }
    if (lobby_player_construction_window != NULL) {
        lobby_player_construction_window->queue_destruction();
        lobby_player_construction_window = 0U;
    }
    if (current_dialog_window != 0U) {
        current_dialog_window->queue_destruction();
        current_dialog_window = 0U;
    }
    if (join_entry_window_obj != 0U) {
        join_entry_window_obj->queue_destruction();
        join_entry_window_obj = 0U;
    }
    if (TLobby_warp_menu_window != NULL) {
        TLobby_warp_menu_window->queue_destruction();
        TLobby_warp_menu_window = NULL;
    }
    if (lobby_com_card_window != NULL) {
        lobby_com_card_window->queue_destruction();
        lobby_com_card_window = NULL;
    }
    if (lobby_make_team_window != NULL) {
        lobby_make_team_window->queue_destruction();
        lobby_make_team_window = NULL;
    }
    if (lobby_keyboard_prompt_window != NULL) {
        lobby_keyboard_prompt_window->queue_destruction();
        lobby_keyboard_prompt_window = NULL;
    }
    if (lobby_keyboard_controller != NULL) {
        lobby_keyboard_controller->queue_destruction();
        lobby_keyboard_controller = NULL;
    }
    if (lobby_scroll_text_window != NULL) {
        lobby_scroll_text_window->queue_destruction();
        lobby_scroll_text_window = NULL;
    }
}
void TLobby::reset_state_flags() {
    buffer_reset();
    protocol_instance->m_handle_pings_only = 1;
    player_setup_pending = 1;
    if ((s32) lobby_state == 0xC) {
        deferred_player_setup_state = 5;
        lobby_state = 0x17;
    }
    current_dialog_window = 0;
}
void TLobby::process_deferred_player_setup() {
    player_setup_pending = 0;
    switch (deferred_player_setup_state) {
    case 1:
    case 2:
        construct_lobby_players((LobbyPlayerEntry *)lobby_join_entries, pending_member_count, pending_local_client_id, designated_client_id);
        break;
    case 3:
    case 4:
        TLobby::make_players();
        break;
    case 5:
        update_state_with_location();
        break;
    }
    if (protocol_instance != NULL) {
        protocol_instance->m_handle_pings_only = 0;
        TLobby::drain_deferred_packets();
    }
    deferred_player_setup_state = 0;
    pending_member_count = 0;
    pending_local_client_id = 0;
}
void TLobby::add_lobby_members(TPlyJoinLobbyEntry *src, int n, int client_id, int leader) {
    s32 i;
    deferred_player_setup_state = 2;
    pending_local_client_id = client_id;
    for (i = pending_member_count; i < pending_member_count + n; i++) {
        TLobby::copy_member_record(&lobby_join_entries[i], &src[i]);
    }
    pending_member_count += n;
    designated_client_id = leader;
}
void TLobby::handle_regist_check(int ok) {
    if (ok) {
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        protocol_instance->send_login2(TLobby::get_option_state());
    } else {
        protocol_instance->send_regist();
    }
}
void TLobby::handle_verify_result(unsigned int result) {
    s32 option_state;
    switch (result) {
    case 0:
    case 2:
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        TLobby::dispatch_by_index(1);
        option_state = TLobby::get_option_state();
        protocol_instance->send_login_9e_extended(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2.name, (int)option_state);
        return;
    case 1:
        protocol_instance->send_register_9c();
        return;
    case 3:
        TLobby::dispatch_by_index(0);
        TLobby::reset_state(0x4E);
        return;
    case 4:
        TLobby::dispatch_by_index(0);
        TLobby::reset_state(0x4F);
        return;
    case 7:
        TLobby::reset_state(0x1B);
        return;
    case 8:
        TLobby::reset_state(0x1A);
        return;
    case 11:
        TLobby::reset_state(0x16);
        return;
    case 12:
        TLobby::reset_state(0x17);
        return;
    case 13:
        TLobby::reset_state(0x18);
        return;
    case 14:
        TLobby::reset_state(0x19);
        return;
    case 15:
    case 16:
        TLobby::reset_state(0x15);
        return;
    case 17:
        TLobby::reset_state(0x1A);
        return;
    case 18:
        TLobby::reset_state(0x1B);
        return;
    case 19:
        TLobby::reset_state(0x1C);
        return;
    case 26:
        TLobby::reset_state(0x1D);
        return;
    case 27:
        TLobby::reset_state(0x1E);
        return;
    default:
        TLobby::reset_state(0x1D);
        return;
    }
}
void TLobby::handle_register_name_result(int ok) {
    if (ok) {
        lobby_debug_printf_stub(lobby_msg_registed);
        protocol_instance->send_login2(TLobby::get_option_state());
    } else {
        lobby_debug_printf_stub(lobby_msg_name_taken);
        TLobby::dispatch_by_index(2);
        TLobby::reset_state(0xd);
    }
}
void TLobby::handle_register_result(int registered) {
    s32 opt;
    if (registered != 0) {
        lobby_debug_printf_stub(lobby_msg_registed);
        get_player_by_client_id(local_client_id);
        opt = TLobby::get_option_state();
        protocol_instance->send_login_9e_extended(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2.name, opt);
        TLobby::dispatch_by_index(1);
        return;
    }
    lobby_debug_printf_stub(lobby_msg_name_taken);
    TLobby::dispatch_by_index(2);
    TLobby::reset_state(0x50);
}
void TLobby::handle_login_result(unsigned int result) {
    s32 event_counter;
    switch (result) {
    case 0:
        lobby_debug_printf_stub(lobby_msg_login_success);
        TAdEnterSerialAccessGC::store_serial_access_key((saddr)protocol_instance->m_serial_number2, (saddr)protocol_instance->m_access_key2, (saddr)protocol_instance->m_password);
        if (login_pending_flag != 0) {
            event_counter = TAdSinglePlyChrSelectGC::increment_frame();
            protocol_instance->send_character_save_info(TAdSinglePlyChrSelectGC::get_player_count(), event_counter);
            login_pending_flag = 0;
        }
        break;
    case 1:
        TLobby::reset_state(0xA);
        break;
    case 2:
        TLobby::dispatch_by_index(0);
        TLobby::reset_state(0xB);
        break;
    case 3:
        TLobby::dispatch_by_index(2);
        TLobby::reset_state(0xD);
        break;
    case 4:
        TLobby::dispatch_by_index(0);
        TLobby::reset_state(0xE);
        break;
    case 5:
        TLobby::dispatch_by_index(0);
        TLobby::reset_state(0xF);
        break;
    case 6:
        lobby_login_result_flag = 1;
        TLobby::dispatch_by_index(2);
        TLobby::reset_state(0x50);
        break;
    default:
        TLobby::reset_state(8);
        break;
    }
}
void TLobby::send_selected_character() {
    TPlyChoiceSearchConfig choice_search_config;
    TBlockedSenders blocked_senders;
    char c[0xAC];
    TPlyChallenge challenge;
    TPlyText<512> auto_reply;
    CharacterSaveRecord *card;
    card = get_character_save_record(0xFFFF);
    memset(&choice_search_config, 0, sizeof(choice_search_config));
    choice_search_config.disabled = TLobby::open_hard_keyboard(local_client_id) != 0 ? 1 : 0;
    copy_choice_search_selections(card->choice_search.entries, &choice_search_config);
    memset(c, 0, sizeof(c));
    strncpy(c, TLobby::get_info_board_text(), 0xAC);
    memset(&blocked_senders, 0, sizeof(blocked_senders));
    ((TLobby *)&blocked_senders)->collect_active_card_ids();
    memset(&auto_reply, 0, sizeof(auto_reply));
    if (get_flag_bit0() != 0) {
        auto_reply.header.flags = 1;
        strncpy(auto_reply.text, (char *)get_card_window_area(), 0x200);
    }
    memset(&challenge, 0, sizeof(challenge));
    challenge.challenge = card->challenge;
    challenge.battle_place_count_1 = card->online_battle.place_counts[0];
    challenge.battle_place_count_2 = card->online_battle.place_counts[1];
    challenge.battle_place_count_3 = card->online_battle.place_counts[2];
    challenge.battle_place_count_4 = card->online_battle.place_counts[3];
    challenge.battle_disconnect_count = card->online_battle.disconnect_count;
    challenge.battle_reserved_count_1 = card->online_battle.reserved_counts[0];
    challenge.battle_reserved_count_2 = card->online_battle.reserved_counts[1];
    challenge.battle_reserved_value_1 = card->online_battle.reserved_values[0];
    challenge.battle_reserved_value_2 = card->online_battle.reserved_values[1];
    protocol_instance->send_chara_data_v2(*TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), challenge, choice_search_config, blocked_senders, auto_reply, c);
}
void TLobby::queue_static_object_destruction() {
    join_lobby_controller->queue_destruction();
}
void TLobby::send_position_update() {
    s32 event_counter;
    s32 player_count;

    event_counter = TAdSinglePlyChrSelectGC::increment_frame();
    player_count = TAdSinglePlyChrSelectGC::get_player_count();
    protocol_instance->send_character_save_info(player_count, event_counter);
}
void TLobby::handle_state(int checksum_ok) {
    if (checksum_ok != 0) {
        TAdSinglePlyChrSelectGC::save_online_character();
        switch (get_post_save_lobby_action()) {
        case 0:
            protocol_instance->send_server_time_request();
            return;
        case 1:
            TLobby::close_and_set_state_13(0x13);
            return;
        case 2:
            TLobby::close_and_set_state_13(0x14);
            return;
        }
    } else {
        TLobby::reset_state(0x20);
        TAdSinglePlyChrSelectGC::reset_character_data();
        TAdSinglePlyChrSelectGC::save_online_character();
    }
}

void handle_server_message(const char *text) {
    if (TLobby::download_list_window == 0) {
        NJS_POINT2 tmp = { 224.0f, 188.0f };
        TLobby::download_list_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc7), &tmp);
    }
    TLobby::download_list_window->append_line(text, (int)3);
}

void handle_lobby_text(const char *text) {
    if (TLobby::join_entry_window_obj == 0) {
        NJS_POINT2 tmp = { 558.0f, 224.0f };
        TLobby::join_entry_window_obj = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc8), &tmp);
    }
    TLobby::join_entry_window_obj->append_line(text, (int)3);
    TLobby::lobby_state = 0x16;
}
void TLobby::disable_window_flags(void*flags) { TWindowCtrl::append_client_message(local_client_id, (const char *)flags); }
void TLobby::open_ship_block_select_menu(int count, GameListEntry *list, GameListEntry &entry) {
    static void *tblA = (void *)lobby_window_title_ship_select;
    static void *tblB = (void *)lobby_window_title_block_select;
    void *tbl;
    s32 cmp;
    s32 i;

    cmp = strncmp(list->name, lobby_list_header_block, 5);
    if (cmp == 0) {
        tbl = tblB;
    } else {
        tbl = tblA;
    }
    if (list_window != 0) {
        list_window->queue_destruction();
        list_window = 0;
    }
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((const char *)tbl);
    for (i = 0; i < count; i++) {
        list_window->add_text_entry(list[i].name, i);
    }
    list_window->calc_content_extent();
    if (cmp == 0) {
        TLobby::set_menu_mode_1();
    } else {
        TLobby::set_menu_mode_0();
    }
    if (strncmp(entry.name, lobby_list_header_block, 5) != 0) {
        memset(lobby_ship_name, 0, 0x11);
        strncpy(lobby_ship_name, entry.name, 0x10);
    }
}
void TLobby::open_information_list(int count, GameListEntry *list, GameListEntry &) {
    void *w = (void *)lobby_window_title_information;
    s32 i;
    TObject *old = list_window;
    if (old != 0) {
        old->queue_destruction();
        list_window = 0;
    }
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((const char *)w);
    for (i = 0; i < count; i++) {
        list_window->add_text_entry(list[i].name, i);
    }
    list_window->calc_content_extent();
    TLobby::set_menu_mode_2();
}

void handle_game_list(int count, GameListEntry *entries, GameListEntry &selected) {
    static const char *tbl = lobby_msg_information_counter;
    TWindowMenuTeamStatus *w;
    s32 i;

    if (TLobby::list_window != 0) {
        TLobby::list_window->queue_destruction();
        TLobby::list_window = 0;
    }
    w = TWindowMenuTeamStatus::create(tbl);
    for (i = 0; i < count; i++) {
        GameListEntry *e = &entries[i];
        s32 flags = e->flags;
        s32 mode = 0;
        s8 episode;
        if (flags & 0x10) {
            mode = 2;
        }
        if (flags & 0x20) {
            mode = 1;
        }
        episode = 0;
        if (flags & 0x40) {
            episode = 1;
        }
        if (flags & 0x80) {
            episode = 2;
        }
        w->add_entry(flags & 2, e->name, e->num_players, 4, e->difficulty_tag - 0x22, mode, episode, i);
    }
    w->calc_content_extent();
    TLobby::list_window = w;
    memset(selected_game_name, 0, 0x11);
    strncpy(selected_game_name, selected.name, 0x11);
}
void TLobby::handle_game_join(TPlyJoinGame *pkt) {
    PlayerGuildCardTag tag;
    TObjPlayer *p;
    saddr i;
    s32 j;
    memcpy(game_join_player_records, pkt->lobby_data, 0x80);
    bswap_32(&game_join_player_records[0].ip_addr);
    bswap_32(&game_join_player_records[1].ip_addr);
    bswap_32(&game_join_player_records[2].ip_addr);
    bswap_32(&game_join_player_records[3].ip_addr);
    TLobby::destroy_all_objects();
    lobby_debug_printf_stub(lobby_debug_game_start_format, pkt->client_id);
    local_client_id = pkt->client_id;
    designated_client_id = pkt->leader_id;
    join_state_flag = pkt->disable_udp;
    TLobby::set_player_count(pkt->battle_mode);
    lobby_challenge_mode = pkt->challenge_mode;
    game_difficulty_selection = pkt->difficulty;
    event_theme_id = pkt->event;
    set_area_random_seed(pkt->rare_seed);
    leader_selection.set_section_id(pkt->section_id);
    if ((s32)pkt->episode == 2) {
        request_story_select_state(1);
    } else {
        request_story_select_state(0);
    }
    set_item_drop_server_seed(pkt->rare_seed);
    for (i = 0; i < 0xC; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            delete p;
            lobby_debug_printf_stub(lobby_debug_delete_player_format, i);
        }
    }
    for (j = 0; j < 4; j++) {
        game_join_pending_clients[j] = 0;
    }
    clear_enabled_main_warps();
    deferred_player_setup_state = 4;
    floor_transition_state.set_next_floor(0, 0);
    TLobby::set_flag_and_update();
    mark_area_change_pending();
}

void TLobby::make_players() {
    TObjPlayer *p;
    TObjPlayer *q;
    if (online_lobby_check_stub() != 0) {
        p = create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        p->guild_card_tag.copy_from((PlayerGuildCardTag *)&protocol_instance->m_guildcard_tag);
        p->reset_motion_fields();
        strncpy(lobby_player_names[local_client_id], p->get_name(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        protocol_instance->send_6F_burst_done();
        lobby_state = 0xF;
        p = create_player_object(1 - local_client_id, 4, TAdSinglePlyChrSelectGC::get_char_index(0));
        if (p != NULL) {
            PlayerSyncRecord record;
            p->fill_player_record(&record);
            TLobby::bswap_player_data(&record);
            record.area = 0;
            record.floor = 0;
            delete p;
            q = create_remote_player_object(&record);
            if (q != NULL) {
                q->reset_motion_fields();
            }
        }
    } else if (local_client_id == designated_client_id) {
        p = create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        p->guild_card_tag.copy_from((PlayerGuildCardTag *)&protocol_instance->m_guildcard_tag);
        p->reset_motion_fields();
        strncpy(lobby_player_names[local_client_id], p->get_name(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        protocol_instance->send_6F_burst_done();
        lobby_state = 0xF;
    }
}

#pragma push
#pragma opt_propagation off
void TLobby::handle_lobby_enter(TPlyJoinLobbyEntry *ents, int n, int client_id, int leader, int lobby, int block, int block_high, int event_theme) {
    s32 v4;
    TObjPlayer *p;
    saddr i;
    s32 j;
    TPacket *node;
    TLobby::destroy_all_objects();
    lobby_debug_printf_stub(lobby_debug_lobby_start_format, client_id);
    local_client_id = client_id;
    v4 = lobby;
    lobby_entered_flag = 1;
    join_state_flag = 1;
    lobby_number = lobby;
    block_number = block;
    lobby_block_high = block_high;
    TLobby::set_player_count(0);
    room_change_pending = 0;
    designated_client_id = leader;
    for (node = (TPacket *)game_protocol_instance->m_down; node != NULL; node = (TPacket *)node->m_next) {
        lobby_debug_printf_stub(lobby_debug_udp_close_ip_format, node->m_dst_addr.addr_bytes[0], node->m_dst_addr.addr_bytes[1], node->m_dst_addr.addr_bytes[2], node->m_dst_addr.addr_bytes[3]);
        delete node;
    }
    for (j = 0; j < 12; j++) {
        lobby_player_names[j][0] = 0;
    }
    for (i = 0; i < n; i++) {
        strncpy(lobby_player_names[ents[i].client_id], ents[i].name, 0x10);
    }
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            delete p;
            lobby_debug_printf_stub(lobby_debug_delete_player_format, i);
        }
    }
    TLobby::add_lobby_members(ents, n, client_id, leader);
    set_floor_map_variant(get_current_floor(), v4);
    event_theme_id = event_theme;
    activate_keyboard();
    protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)handle_lobby_text;
}
#pragma pop

void construct_lobby_players(LobbyPlayerEntry *records, s32 count, int self_id, s32 unused) {
    s32 j;
    s32 i;
    TObjPlayer *plr;
    TObject *room;

    for (i = 0; i < count; i++) {
        if (self_id == records[i].client_id) {
            if (get_player_by_client_id(self_id) == NULL) {
                plr = create_player_object(self_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
                plr->guild_card_tag.copy_from((PlayerGuildCardTag *)records[i].tag);
                plr->reset_motion_fields();
                lobby_debug_printf_stub(lobby_debug_my_player_format, self_id);
                lobby_debug_printf_stub(lobby_list_savedata_format, sizeof(records->char_data));
            } else {
                lobby_debug_printf_stub(lobby_list_duplicate_my_player_format, i);
            }
        }
    }
    for (j = 0; j < count; j++) {
        if (self_id != records[j].client_id) {
            if (get_player_by_client_id(records[j].client_id) == NULL) {
                plr = create_player_object(records[j].client_id, 4, reinterpret_cast<TPlyCharData *>(records[j].char_data));
                plr->guild_card_tag.copy_from((PlayerGuildCardTag *)records[j].tag);
                plr->reset_motion_fields();
                lobby_debug_printf_stub(lobby_debug_create_player_format, records[j].client_id);
            } else {
                lobby_debug_printf_stub(lobby_debug_duplicate_player_format, records[j].client_id);
            }
        }
    }
    TLobby::protocol_instance->m_recv_handlers.handle_06_recv_chat = TWindowCtrl::handle_recv_chat;
    if (lobby_player_construction_window != NULL) {
        lobby_player_construction_window->queue_destruction();
        lobby_player_construction_window = NULL;
    }
    sprintf(lobby_room_title, lobby_list_block_range_format, lobby_ship_name, TLobby::block_number, TLobby::lobby_number + 1);
    room = new TWindowRoom(lobby_room_title);
    lobby_player_construction_window = room;
    TLobby::close_all_windows();
}
void TLobby::on_game_player_add(TPlyJoinLobbyEntry *entries, int leader_id, int disable_udp) {
    LobbyPlayerEntry e;
    G_DoneLoadingIntoGame_6x72 pkt;
    TObjPlayer *p;
    TPacket *n;
    TObjPlayer *plr;
    if (lobby_state != 0xE && lobby_state != 0xF) {
        return;
    }
    copy_join_lobby_entry((u8 *)&e, (u8 *)entries);
    if (e.client_id == local_client_id) {
        ((TPlyJoinLobbyEntry *)&e)->~TPlyJoinLobbyEntry();
        return;
    }
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&game_join_player_records[e.client_id], &e);
    game_join_player_records[e.client_id].ip_addr = e.ip_addr;
    game_join_player_records[e.client_id].client_id = e.client_id;
    strncpy(game_join_player_records[e.client_id].name, e.name, 0x10);
    join_state_flag = disable_udp;
    sprintf(player_joined_message, (const char *)TLobby::get_seq_phase(0x10), e.name);
    show_dialog_value_line(player_joined_message);
    current_dialog_window->complete_reveal();
    current_dialog_window->reparent_to_main_ctrl();
    main_task.begin_frame();
    main_task.run_tl_camera_tasks();
    main_task.render();
    main_task.render_screen_overlay();
    render_tick();
    main_task.begin_frame();
    main_task.run_tl_camera_tasks();
    main_task.render();
    main_task.render_screen_overlay();
    render_tick();
    main_task.begin_frame();
    main_task.run_tl_camera_tasks();
    main_task.render();
    main_task.render_screen_overlay();
    render_tick();
    main_task.toggle_pause_layers();
    designated_client_id = leader_id;
    p = get_player_by_client_id(e.client_id);
    if (p != NULL) {
        for (n = (TPacket *)game_protocol_instance->m_down; n != NULL; n = (TPacket *)n->m_next) {
            if (n->m_id == e.client_id) {
                lobby_debug_printf_stub(lobby_debug_udp_close_player_format, e.client_id, n->m_dst_addr.addr_bytes[0], n->m_dst_addr.addr_bytes[1], n->m_dst_addr.addr_bytes[2], n->m_dst_addr.addr_bytes[3]);
                delete n;
                break;
            }
        }
        delete p;
        lobby_debug_printf_stub(lobby_debug_delete_player_format, e.client_id);
    }
    if (local_client_id == designated_client_id) {
        TLobby::send_6x6D_item_state(e.client_id);
        TLobby::send_cmd_6B(e.client_id);
        TLobby::send_compressed_packet_6c(e.client_id);
        TLobby::send_6x6E_sync_game_state(e.client_id);
        send_6x6F_quest_flags(e.client_id);
        TLobby::send_6x71_to_player(e.client_id);
    }
    if (get_player_by_client_id(local_client_id) != NULL) {
        TLobby::send_6x70_player_data(e.client_id);
        if (get_player_by_client_id(e.client_id) == NULL) {
            plr = create_player_object(e.client_id, 4, reinterpret_cast<TPlyCharData *>(e.char_data));
            plr->guild_card_tag.copy_from((PlayerGuildCardTag *)e.tag);
            plr->reset_motion_fields();
            TLobby::open_udp_socket_for_player(e.client_id);
            lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
        }
    } else {
        game_join_pending_clients[e.client_id] = 1;
        TLobby::copy_member_record(&lobby_join_entries[e.client_id], (TPlyJoinLobbyEntry *)&e);
    }
    if (local_client_id == designated_client_id) {
        init_6x72_resume_packet(&pkt);
        TLobby::send_packet_60(&pkt);
    }
    ((TPlyJoinLobbyEntry *)&e)->~TPlyJoinLobbyEntry();
}

void handle_6x72_done_loading_into_game(void) {
    if (TLobby::current_dialog_window != NULL) {
        TLobby::current_dialog_window->close();
        TLobby::current_dialog_window = NULL;
    }
    main_task.resume_layers();
}
void TLobby::remove_player(unsigned int client, int new_leader_id, int join_state) {
    TObjPlayer *p;
    TPacket *n;
    designated_client_id = new_leader_id;
    join_state_flag = join_state;
    p = get_player_by_client_id(client);
    if (p != NULL) {
        for (n = (TPacket *)game_protocol_instance->m_down; n != NULL; n = (TPacket *)n->m_next) {
            if (n->m_id == client) {
                lobby_debug_printf_stub(lobby_debug_udp_close_ip_format, n->m_dst_addr.addr_bytes[0], n->m_dst_addr.addr_bytes[1], n->m_dst_addr.addr_bytes[2], n->m_dst_addr.addr_bytes[3]);
                delete n;
                break;
            }
        }
        delete p;
    }
    strncpy(lobby_player_names[client], "", 0x10);
    if (lobby_state == 0xE) {
        lobby_floor_reload_pending = 1;
    }
    if (current_dialog_window != 0) {
        current_dialog_window->close();
        current_dialog_window = 0;
    }
    if (quest_download_active == 0) {
        main_task.resume_layers();
    }
}

TPlyJoinLobbyEntry::~TPlyJoinLobbyEntry() {}
void TLobby::on_lobby_player_add(TPlyJoinLobbyEntry *entries, int leader_id) {
    LobbyPlayerEntry e;
    TObjPlayer *p;
    TObjPlayer *plr;
    copy_join_lobby_entry((u8 *)&e, (u8 *)entries);
    designated_client_id = leader_id;
    if (e.client_id == local_client_id) {
        lobby_debug_printf_stub(lobby_debug_burst_overwrite_format, e.client_id);
        ((TPlyJoinLobbyEntry *)&e)->~TPlyJoinLobbyEntry();
        return;
    }
    p = get_player_by_client_id(e.client_id);
    if (p != NULL) {
        delete p;
        lobby_debug_printf_stub(lobby_debug_delete_player_format, e.client_id);
    }
    strncpy(lobby_player_names[e.client_id], e.name, 0x10);
    plr = create_player_object(e.client_id, 4, reinterpret_cast<TPlyCharData *>(e.char_data));
    plr->guild_card_tag.copy_from((PlayerGuildCardTag *)e.tag);
    plr->reset_motion_fields();
    lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
    ((TPlyJoinLobbyEntry *)&e)->~TPlyJoinLobbyEntry();
}
void TLobby::retire_lobby_player(int idx, int v) {
    TObjPlayer *p;
    designated_client_id = v;
    p = get_player_by_client_id(idx);
    if (p) {
        delete p;
        lobby_debug_printf_stub(lobby_debug_player_exit_format, idx);
    }
    strncpy(lobby_player_names[idx], "", 0x10);
}

void handle_generate_id(void) {  }
void TLobby::open_download_list_window(int count, TMenuList<QuestListEntry, 30, 0> &list) {
    static void *tbl = (void *)lobby_window_title_download;
    s32 i;
    const NJS_POINT2 *w;

    if (list_window != 0) {
        list_window->queue_destruction();
        list_window = 0;
    }
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((const char *)tbl);
    for (i = 0; i < count; i++) {
        switch (list.entries[i].tag.m_tag1) {
        case 0:
            list_window->add_list_entry(0x2C, (const char *)list.entries[i].name, i);
            break;
        case 1:
            list_window->add_list_entry(0x17, (const char *)list.entries[i].name, i);
            break;
        case 2:
            list_window->add_list_entry(0x31, (const char *)list.entries[i].name, i);
            break;
        default:
            list_window->add_list_entry(0x2C, (const char *)list.entries[i].name, i);
            break;
        }
    }
    list_window->calc_content_extent();
    if (download_list_window != 0) {
        download_list_window->queue_destruction();
        download_list_window = 0;
    }
    {
        NJS_POINT2 p = { 224.0f, 188.0f };
        w = get_window_layout_position(0xC7);
        download_list_window = TWindowMessage::create(w, (const f32 *)(&p), 1);
        download_list_window->append_line(list.entries[0].short_description, (int)3);
    }
    card_list_selected_index = 0;
    lobby_state = 0x11;
}

#pragma defer_codegen off

void TLobby::send_logout() {
    if (protocol_instance != NULL) {
        protocol_instance->send_logout();
    }
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

#define CONNECT_TO_LOBBY_SERVER(res, s)                                                                   \
    if (get_video_standard() == 0) {                                                    \
        res = TLobby::protocol_instance->set_server_info("", "", \
                                     TLobby::init_serial_access(), (const char *)get_access_key_input_buffer(), \
                                     s[0].host, s[0].port);                                     \
    } else {                                                                                        \
        res = TLobby::protocol_instance->set_server_info("", "", \
                                     TLobby::init_serial_access(), (const char *)get_access_key_input_buffer(), \
                                     s[1].host, s[1].port);                                     \
    }
void TLobby::run_join_lobby_connect(TObject *parent) {
    DateStamp date;
    void *p;
    TAdDialingMessageWindow *win;
    s32 res;

    if (TLobby::connection_lost == 0) {
        reset_controller_input_state();
        getDateStamp(&date);
        DateToSeconds(&date, (int *)&date_seconds);
        p = TObject::operator new(0x2C);
        if (p != NULL) {
            init_idle_timeout_timer((u8 *)p, parent);
        }
        join_state_flag = 1;
        win = TLobby::create_dialing_message_window((const char *)get_connection_message_text(7), 1);
        switch (lobby_server_choice_stub()) {
        case 0:
        case 1:
            CONNECT_TO_LOBBY_SERVER(res, join_lobby_server_table)
            break;
        case 2:
            CONNECT_TO_LOBBY_SERVER(res, join_lobby_ss702_server_table)
            break;
        case 3:
        default:
            CONNECT_TO_LOBBY_SERVER(res, join_lobby_ddplanet_server_table)
            break;
        }
        if (win != NULL) {
            queue_destruction__7TObjectFv(win);
        }
        switch (res) {
        case 0:
            return;
        case 1:
            TLobby::reset_state(8);
            break;
        case 2:
            TLobby::reset_state(9);
            break;
        default:
            TLobby::reset_state(8);
            break;
        }
    }
}

#pragma pop

TLobby::TLobby(TObject *parent) : TObject(parent) {
    TProtocol *protocol;

    lobby_init_hook();
    m_name = lobby_class_name;
    join_lobby_controller = this;
    card_list_window = 0;
    download_list_window = 0;
    list_window = 0;
    lobby_player_construction_window = 0;
    current_dialog_window = 0;
    join_entry_window_obj = 0;
    TLobby_warp_menu_window = NULL;
    lobby_com_card_window = NULL;
    lobby_make_team_menu_window = NULL;
    lobby_make_team_window = NULL;
    lobby_keyboard_prompt_window = NULL;
    lobby_keyboard_controller = NULL;
    lobby_scroll_text_window = NULL;
    lobby_entered_flag = 0;
    room_change_pending = 0;
    pending_local_client_id = 0;
    pending_member_count = 0;
    deferred_player_setup_state = 0;
    lobby_state = 0;
    join_state_flag = 1;
    date_seconds = 0;
    event_theme_id = 0;
    card_list_selected_index = 0;
    idle_timeout_active = 0;
    block_number = 0;
    lobby_number = 0;
    join_lobby_idle_timer = 0;
    lobby_block_high = 0;
    login_pending_flag = 1;
    TLobby::connection_lost = 0;
    lobby_login_result_flag = 0;
    player_setup_pending = 0;
    local_client_id = 0;
    designated_client_id = 0;
    memset(lobby_room_title, 0, sizeof(lobby_room_title));
    memset(lobby_player_names, 0, 0xC0);
    memset(lobby_player_status_records, 0, sizeof(lobby_player_status_records));
    protocol = new TProtocol(this, 0x36, current_language, TLobby::init_serial_access(), (char *)get_access_key_input_buffer(), (char *)get_password_input_buffer());
    protocol_instance = protocol;
    protocol->m_recv_handlers.handle_unused_login = (recv_packet_handler_handle_unused_login)TLobby::handle_regist_check;
    protocol_instance->m_recv_handlers.handle_03_recv_regist = (recv_packet_handler_handle_03_recv_regist)TLobby::handle_register_name_result;
    protocol_instance->m_recv_handlers.handle_04_recv_login = (recv_packet_handler_handle_04_recv_login)TLobby::handle_login_result;
    protocol_instance->m_recv_handlers.handle_05_recv_logout = TLobby::queue_static_object_destruction;
    protocol_instance->m_recv_handlers.handle_06_recv_chat = NULL;
    protocol_instance->m_recv_handlers.handle_01_recv_error = (recv_packet_handler_handle_01_recv_error)handle_error;
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = TLobby::open_ship_block_select_menu;
    protocol_instance->m_recv_handlers.handle_08_recv_game_list = handle_game_list;
    protocol_instance->m_recv_handlers.handle_11_recv_message = (recv_packet_handler_handle_11_recv_message)handle_server_message;
    protocol_instance->m_recv_handlers.handle_0E_recv_start_game = NULL;
    protocol_instance->m_recv_handlers.unused7 = NULL;
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = (recv_packet_handler_handle_64_recv_start_game3)TLobby::handle_game_join;
    protocol_instance->m_recv_handlers.unused8 = NULL;
    protocol_instance->m_recv_handlers.handle_67_recv_start_lobby2 = (recv_packet_handler_handle_67_recv_start_lobby2)TLobby::handle_lobby_enter;
    protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)TLobby::open_scroll_text_window;
    protocol_instance->m_recv_handlers.handle_80_recv_generate_id = (recv_packet_handler_handle_80_recv_generate_id)handle_generate_id;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = TLobby::on_game_player_add;
    protocol_instance->m_recv_handlers.handle_66_recv_exit_game = (recv_packet_handler_handle_66_recv_exit_game)TLobby::remove_player;
    protocol_instance->m_recv_handlers.handle_68_recv_burst_lobby = TLobby::on_lobby_player_add;
    protocol_instance->m_recv_handlers.handle_69_recv_exit_lobby = TLobby::retire_lobby_player;
    protocol_instance->m_recv_handlers.handle_81_recv_chat_message = receive_short_mail;
    protocol_instance->m_recv_handlers.handle_41_recv_user_ans = handle_user_search_answer;
    protocol_instance->m_recv_handlers.handle_18_90_9A_recv_pso_regist_check = (recv_packet_handler_handle_18_90_9A_recv_pso_regist_check)TLobby::handle_verify_result;
    protocol_instance->m_recv_handlers.handle_92_9C_register_response_packet = (recv_packet_handler_handle_92_9C_register_response_packet)TLobby::handle_register_result;
    protocol_instance->m_recv_handlers.handle_95_request_character_data_packet = TLobby::send_selected_character;
    protocol_instance->m_recv_handlers.send_96_unused = TLobby::send_position_update;
    protocol_instance->m_recv_handlers.handle_97_checksum_reply_packet = (recv_packet_handler_handle_97_checksum_reply_packet)TLobby::handle_state;
    protocol_instance->m_recv_handlers.handle_B1_current_time_packet = TLobby::reset_lobby_state;
    protocol_instance->m_recv_handlers.handle_C0_choice_search_option_packet = TLobby::handle_choice_search_options;
    protocol_instance->m_recv_handlers.handle_C4_choice_search_reply_packet = TLobby::handle_choice_search_results;
    protocol_instance->m_recv_handlers.handle_A2_recv_quest_menu_list = copy_quest_list_data;
    protocol_instance->m_recv_handlers.handle_A3_recv_quest_menu_info = TQuestListOnline::receive_quest_info;
    protocol_instance->m_recv_handlers.handle_44_recv_download_head = TQuestListOnline::begin_file_download;
    protocol_instance->m_recv_handlers.handle_13_recv_download = (recv_packet_handler_handle_13_recv_download)handle_quest_download_chunk__6TLobbyFv;
    protocol_instance->m_recv_handlers.handle_A4_recv_quest_list = (recv_packet_handler_handle_A4_recv_quest_list)TLobby::open_download_list_window;
    protocol_instance->m_recv_handlers.handle_A5_recv_quest_info = show_card_list_message;
    protocol_instance->m_recv_handlers.handle_A6_recv_vm_download_head = TQuestVmDownLoadServer::begin_file_download;
    protocol_instance->m_recv_handlers.handle_A7_recv_vm_download = TQuestVmDownLoadServer::receive_file_chunk;
    protocol_instance->m_recv_handlers.handle_B0_recv_emergency_call = (recv_packet_handler_handle_B0_recv_emergency_call)TLobby::disable_window_flags;
    protocol_instance->m_recv_handlers.handle_1F_recv_text_list = TLobby::open_information_list;
    protocol_instance->m_recv_handlers.handle_88_player_arrow_color_list_packet = apply_arrow_colors;
    protocol_instance->m_recv_handlers.handle_C5_player_challenge_data_packet = TLobby::copy_player_records;
    protocol_instance->m_recv_handlers.handle_D3_execute_trade_packet = handle_trade_received_items;
    protocol_instance->m_recv_handlers.handle_D4_trade_result_packet = (recv_packet_handler_handle_D4_trade_result_packet)TLobby::handle_reset_choice;
    protocol_instance->m_recv_handlers.handle_D1_advance_trade_state_packet = (recv_packet_handler_handle_D1_advance_trade_state_packet)TLobby::apply_trade_items;
    protocol_instance->m_recv_handlers.handle_D8_infoboard_packet = TLobby::handle_info_board;
    protocol_instance->m_recv_handlers.handle_DA_lobby_event_packet = TLobby::set_lobby_event_theme;
    protocol_instance->m_recv_handlers.handle_AB_quest_stats_response_packet = (recv_packet_handler_handle_AB_quest_stats_response_packet)create_quest_stats_thread;
    lobby_challenge_mode = 0;
}
const char *TLobby::get_seq_phase(int id) { return get_online_message_text(id); }
void lobby_init_hook(void) {  }
void lobby_debug_printf_stub(const char *fmt, ...) {}
void TLobby::construct_global_arrays() {
    __construct_array(lobby_join_entries, __ct__18TPlyJoinLobbyEntryFv, __dt__18TPlyJoinLobbyEntryFv, 0x43C, 0xC);
    __register_global_object(0, TLobby::destroy_join_entries, join_entries_dtor_registration);
    __construct_array(game_join_player_records, __ct__17TPlyJoinLobbyDataFv, 0, 0x20, 4);
}



TPlyJoinLobbyData::TPlyJoinLobbyData() {}
void TLobby::destroy_join_entries() {
    __destroy_arr(lobby_join_entries, __dt__18TPlyJoinLobbyEntryFv, 0x43c, 0xc);
}


TPlyJoinLobbyEntry::TPlyJoinLobbyEntry() {}
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

void bswap_and_send_extended_subcommand(void *p, u32 client_id) { bswap_extended_subcommand_header((extended_game_command_header *)p); ((long_game_command_union *)p)->send_to_client(client_id); }

void bswap_extended_subcommand_header(extended_game_command_header *p) { TLobby::bswap_header_fields(p); }
void TLobby::bswap_header_fields(extended_game_command_header *header) {
    bswap_16(&header->header.id);
    bswap_32(&header->size);
}
void TLobby::bswap_and_handle_packet(void *packet, int client_id) {
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
TPlyJoinLobbyEntry *TLobby::copy_member_record(TPlyJoinLobbyEntry *dst, TPlyJoinLobbyEntry *src) {
    *(ByteBlock_8 *)&dst->tag = *(ByteBlock_8 *)&src->tag;
    dst->ip_addr = src->ip_addr;
    dst->client_id = src->client_id;
    *(ByteBlock_10 *)dst->name = *(ByteBlock_10 *)src->name;
    dst->char_data = src->char_data;
    return dst;
}

TPlyCharData &TPlyCharData::operator=(TPlyCharData &src) {
    m_inventory.m_num_items = src.m_inventory.m_num_items;
    m_inventory.m_hp_materials_used = src.m_inventory.m_hp_materials_used;
    m_inventory.m_tp_materials_used = src.m_inventory.m_tp_materials_used;
    m_inventory.m_language = src.m_inventory.m_language;
    *(ByteBlock_348 *)m_inventory.m_items = *(ByteBlock_348 *)src.m_inventory.m_items;
    *(ByteBlock_24 *)&m_stats = *(ByteBlock_24 *)&src.m_stats;
    *(ByteBlock_50 *)&m_disp_part2 = *(ByteBlock_50 *)&src.m_disp_part2;
    copy_disp_config(&m_config, &src.m_config);
    *(ByteBlock_14 *)m_tech_levels = *(ByteBlock_14 *)src.m_tech_levels;
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
    *(ByteBlock_10 *)dst->name = *(ByteBlock_10 *)src->name;
    copy_char_data(&dst->char_data, &src->char_data);
    return to;
}

TPlyCharData *copy_char_data(TPlyCharData *dst, TPlyCharData *src) {
    dst->m_inventory.m_num_items = src->m_inventory.m_num_items;
    dst->m_inventory.m_hp_materials_used = src->m_inventory.m_hp_materials_used;
    dst->m_inventory.m_tp_materials_used = src->m_inventory.m_tp_materials_used;
    dst->m_inventory.m_language = src->m_inventory.m_language;
    *(ByteBlock_348 *)dst->m_inventory.m_items = *(ByteBlock_348 *)src->m_inventory.m_items;
    *(ByteBlock_24 *)&dst->m_stats = *(ByteBlock_24 *)&src->m_stats;
    *(ByteBlock_50 *)&dst->m_disp_part2 = *(ByteBlock_50 *)&src->m_disp_part2;
    dst->m_config.copy_full(&src->m_config);
    *(ByteBlock_14 *)dst->m_tech_levels = *(ByteBlock_14 *)src->m_tech_levels;
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
void set_area_random_seed(int a0) { area_random_seed = a0; }

void set_quest_list_online_state(s32 state) {
    if (quest_list_online_instance != NULL) {
        quest_list_online_instance->set_state(state);
    }
}

void TWindowMenu::set_ready_flag() { menu_flags |= 0x1; }


int TWindowMenuIconLine::is_decided() { return (this->state_flags >> 1) & 0x1; }
int TWindowMenuIconLine::is_cancelled() { return (this->state_flags >> 2) & 0x1; }
int TWindowMakeTeam::test_flag_1d_bit1() { return (flags >> 1) & 1; }
s32 TWindowMakeTeam::get_field_20() { return kind; }
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

saddr get_connection_message_text(s32 id) {
    return (saddr)text_language_group_table[12][id];
}

const char *get_online_message_text(s32 id) {
    return text_language_group_table[14][id];
}

u8 *get_password_input_buffer(void) {
    return ((u8 *)&TAdEnterPasswordGC::input_buffer);
}

void *TProtocol::operator new(size_t size) { return obj_heap->heap_alloc(size); }

__declspec(section ".ctors") static void *const __sinit_TPlyJoinLobbyEntry_cpp_ref = (void *)TLobby::construct_global_arrays;

// Window positions copied by the message/menu openers above, and the lobby log and
// menu strings; defined after their users so each is addressed on its own.



__declspec(section ".rodata") const NJS_POINT2 card_list_message_window_size[1] = { { 332.0f, 200.0f } };
__declspec(section ".rodata") NJS_POINT2 idle_timeout_window_size[1] = { { 342.0f, 144.0f } };
__declspec(section ".rodata") const char lobby_debug_udp_open_format[] = "udp open %d %d.%d.%d.%d";
__declspec(section ".rodata") const char lobby_debug_make_player_format[] = "Make Player %d";
__declspec(section ".rodata") const char lobby_debug_burst_player_format[] = "burst player %d";
__declspec(section ".rodata") const char lobby_debug_duplicate_player_format[] = "Duplicate player %d";
__declspec(section ".rodata") const char lobby_debug_create_player_format[] = "create player %d";
__declspec(section ".rodata") const char lobby_debug_rcv_set_flag_format[] = "RcvSetFlag size %d";
__declspec(section ".rodata") const char lobby_debug_rcv_item_condition_format[] = "RcvItemCondition size %d";
__declspec(section ".rodata") const char lobby_debug_rcv_object_condition_format[] = "RcvObjectCondition size %d";
__declspec(section ".rodata") const char lobby_debug_rcv_enemy_condition_format[] = "RcvEnemyCondition size %d";
__declspec(section ".rodata") const char lobby_window_title_download[] = "Down Load";
__declspec(section ".rodata") const char lobby_debug_player_exit_format[] = "player %d exit";
__declspec(section ".rodata") const char lobby_debug_burst_overwrite_format[] = "OnBurstLobby over write player %d";
__declspec(section ".rodata") const char lobby_debug_delete_player_format[] = "delete player %d";
__declspec(section ".rodata") const char lobby_debug_udp_close_ip_format[] = "udp close %d.%d.%d.%d";
__declspec(section ".rodata") const char lobby_debug_udp_close_player_format[] = "udp close %d %d.%d.%d.%d";
__declspec(section ".rodata") const char lobby_debug_my_player_format[] = "My Player %d";
__declspec(section ".rodata") const char lobby_list_savedata_format[] = "SaveData %d";
__declspec(section ".rodata") const char lobby_list_duplicate_my_player_format[] = "Duplicate My player %d";
__declspec(section ".rodata") const char lobby_list_block_range_format[] = "%s:%02d-%02d";
__declspec(section ".rodata") const char lobby_debug_lobby_start_format[] = "Lobby start %d";
__declspec(section ".rodata") const char lobby_debug_game_start_format[] = "Game start %d";
__declspec(section ".rodata") const char lobby_msg_information_counter[] = "Information Counter";
__declspec(section ".rodata") const char lobby_window_title_information[] = "Information";
__declspec(section ".rodata") const char lobby_window_title_ship_select[] = "Ship Select";
__declspec(section ".rodata") const char lobby_window_title_block_select[] = "Block Select";
__declspec(section ".rodata") const char lobby_list_header_block[] = "BLOCK";

__declspec(section ".rodata") const char lobby_msg_login_success[] = "login success.";
__declspec(section ".rodata") const char lobby_msg_registed[] = "Registed.";
__declspec(section ".rodata") const char lobby_msg_name_taken[] = "already use this name.";
__declspec(section ".rodata") const char lobby_msg_regist_check_ok[] = "Regist check OK";
__declspec(section ".rodata") const char lobby_window_title_block_jump[] = "BlockJump";
__declspec(section ".rodata") const char lobby_window_title_ship_jump[] = "ShipJump";
__declspec(section ".rodata") const char lobby_window_title_taisen_team[] = "TAISEN TEAM";

u32 lbl_8050BEB8[2];
