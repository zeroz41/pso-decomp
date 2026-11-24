#include "pso/enemy/EnemyStateRecord.h"
#include "pso/network/TUserAns.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/unk/TUnk_804A7008.h"
#include "pso/system/date.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
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
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8020BFC4.h"
#include "pso/unk/text_8020B5CC.h"
#include "pso/unk/text_800C7FEC.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMakeTeam_8026534C.h"
#include "pso/unk/text_8013ADE4.h"
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
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/player/TPlyInventory.h"
#include <stdio.h>
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby_8013A874.h"
#include "pso/unk/text_8013AAD4.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/unk/TLobby_8013AD38.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_8013ADD0.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/map/TSetManager.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/network/client_id.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/warp/TObjLaboMapWarp_80185248.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_801461EC.h"
#include "pso/unk/TTitleScene.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TObjPlayer_801BDD8C.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"

struct Entry_8013634C {
    u8 tag[8];
    u32 ip_addr;
    saddr client_id;
    char name[16];
    u8 char_data[0x41C];
};
struct Ent_80136FA0 { u8 pad[0xA]; char name[0x12]; };
struct Pkt_8013566C
{
  u8 pad[4];
  s32 len;
  u8 data[1];
};
struct GameStateSyncScratch {
    u16 total_size;
    u16 floor_flags_size;
    u16 sync_records_size;
    u16 switch_table_size;
    u8 payload[sizeof(FloorSetFlagsPayload)];
};
LAYOUT_ASSERT(GameStateSyncScratchSize, sizeof(GameStateSyncScratch) == 0x4008);
LAYOUT_ASSERT(GameStateSyncPayloadOffset, offsetof(GameStateSyncScratch, payload) == 8);
struct Stack_80135598 {
    s32 sp8;
    u8 trailing_storage[0x488];
};
struct RecoveredGlobal_80135198_lbl_804A7008 { s32 value; u8 remaining[0x14]; };
LAYOUT_ASSERT(RecoveredGlobal_80135198_lbl_804A7008_size, sizeof(RecoveredGlobal_80135198_lbl_804A7008) == 0x18);
struct Stack_80135974 {
    s32 sp8;
    s32 spC;
    u8 trailing_storage[0x1FC];
};
struct RecoveredGlobal_80135974_lbl_805127F8 { s32 value; u8 remaining[0x1FC]; };
LAYOUT_ASSERT(RecoveredGlobal_80135974_lbl_805127F8_size, sizeof(RecoveredGlobal_80135974_lbl_805127F8) == 0x200);
struct RecoveredGlobal_8013561C_lbl_805127F8 {
    s32 value;
    u8 remaining[0x1FC];
};
struct Row_80135208 { u8 pad[8]; union { u32 ip; u32 ip_addr; }; s32 client_id; char name[16]; };
struct Pkt_8013574C { u8 pad[4]; s32 len; u8 data[1]; };
struct Pkt_801357F8 { u8 pad[4]; s32 len; u8 data[1]; };
struct Pkt_801358B4 { u8 pad[4]; s32 len; u8 data[1]; };
struct Disp_801354AC { u16 id; };
struct Pkt_801354AC { u8 pad[8]; Disp_801354AC disp; };
struct Pkt_801359C4 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135AE0 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135BD0 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135CD8 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Entry_80136080 {
    u8 tag[8];
    u32 ip_addr;
    saddr client_id;
    char name[16];
    u8 char_data[0x420];
};
struct DateStamp_80134F9C { s32 v[3]; };
struct Timer_80134F9C {
    u8 pad[0x1C];
    s32 now;
    s32 start;
    u32 limit;
    u8 state;
};
typedef char LobbyPlayerName[16];
typedef struct { f32 x; f32 y; } Pair_80135E7C;
struct Ent_80136E68 {
    u8 pad0[8];
    s8 b8;
    u8 b9;
    char name[0x11];
    s8 flags;
};
typedef struct { u8 pad0[5]; u8 kind; u8 pad6[6]; u8 name[0x8C]; } Ent_80135E7C;
typedef struct {
    u32 kb;
    u8 pad[0x14];
} A_80134E30;
typedef struct {
    u8 pad[0x4];
    ChallengeRecord b;
    u16 h[7];
    u32 w0;
    u32 w1;
} D_80134E30;
LAYOUT_ASSERT(RecoveredGlobal_8013561C_lbl_805127F8_size, sizeof(RecoveredGlobal_8013561C_lbl_805127F8) == 0x200);
struct Ent_801368B0 { u8 hdr[0xC]; s32 id; char name[0x10]; u8 rest[0x43C - 0x20]; };
struct Hdr_80136A8C {
    u8 pad0[0xAC];
    s32 fAC;
    u8 padB0[0x488 - 0xB0];
    s32 f488;
    u8 pad48C[4];
};
struct Row_80136C94 { u8 pad[8]; u32 ip; u8 pad2[20]; };
struct Hdr_80136C94 { u8 data[0x10]; };
struct Pkt_80136C94 {
    u8 pad0[0x84];
    Row_80136C94 rows[4];
    s8 client_id;
    s8 leader_id;
    s8 b106;
    s8 b107;
    s8 count;
    s8 b109;
    s8 b10a;
    s8 b10b;
    s32 w10c;
    u8 b110;
};
typedef struct { u8 pad0[0xA]; char name[0x12]; } Ent_8013703C;
struct LEntry_801352C0 { u8 hdr[0x20]; u8 body[0x41C]; };
typedef struct Server_801399B8 {
    const char *host;
    s32 port;
} Server_801399B8;
typedef struct Pkt_8013566C Pkt_8013566C;
struct Rec_801378AC;
struct Rec_801378AC { u8 b[0x43c]; };
typedef struct {
    u32 kb;
    u8 pad[0x14];
} A_80137384;
typedef struct {
    u8 pad[0x4];
    ChallengeRecord b;
    u16 h[7];
    u32 w0;
    u32 w1;
} D_80137384;
typedef struct Date_801399B8 {
    u16 y;
    u8 b[0x16];
} Date_801399B8;
struct H_8013A348 { u8 b[12]; };
struct S_8013A348 { u8 pad[0x28]; struct H_8013A348 h[5]; };
struct ByteBlock_10 { u8 bytes[0x10]; };
struct ByteBlock_20 { u8 bytes[0x20]; };
struct ByteBlock_50 { u8 bytes[0x50]; };
struct ByteBlock_348 { u8 bytes[0x348]; };
struct ByteBlock_24 { u8 bytes[0x24]; };
struct ByteBlock_14 { u8 bytes[0x14]; };
struct P8_8013A5D4 { u32 w[2]; };
struct Rec_8013A5D4 { P8_8013A5D4 f0; u32 f8; u32 fc; P8_8013A5D4 f10; P8_8013A5D4 f18; u8 f20[0x41c]; };

extern "C" {
void handle_quest_download_chunk__6TLobbyFv();
void apply_lobby_markers__6TLobbyFv();
void lobby_debug_printf_stub(const char *fmt, ...);
extern const char lobby_debug_delete_player_format[];
extern const char lobby_debug_burst_player_format[];
extern const char lobby_debug_udp_close_player_format[];
extern const char lobby_window_title_information[];
s32 TLobby__sub_8013F810(void *, void *, s32, void *);
void handle_6x6E_sync_game_state(Pkt_8013566C *arg0);
void * get_current_floor();
void TLobby__sub_80077798(void *, void *);
void handle_6x70_sync_player_disp_and_inventory(Pkt_801354AC *arg0);
void handle_6x6D_sync_game_state(Pkt_8013574C *arg0);
void handle_6x6C_sync_game_state(Pkt_801357F8 *arg0);
void handle_6x6B_sync_game_state(Pkt_801358B4 *arg0);
void import_sync_records__6TLobbyFPs(void *, u16);
s32 TLobby__sub_801A3E8C();
s32 init_player_join_record(void *);
void send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(void *, void *, void *, void *, void *, void *, void *);
u8 * get_character_save_record(u32);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 TLobby__data_805D4E30;
extern const char TLobby__data_805DB0B0[4];
extern const Pair_80135E7C lbl_8043EE18[1];
extern const Pair_80135E7C lbl_8043EE20[1];
extern const char lobby_msg_information_counter[];
void fn_80338D58(void *list, s32 flag, const char *name, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 index);
extern NJS_POINT2 lbl_8043EE28[1];
extern const char lobby_debug_udp_open_format[];
extern const char lobby_debug_make_player_format[];
extern const char lobby_debug_create_player_format[];
extern const char lobby_debug_rcv_item_condition_format[];
extern const char lobby_debug_rcv_object_condition_format[];
extern const char lobby_debug_rcv_enemy_condition_format[];
extern const char lobby_window_title_download[];
extern const char lobby_debug_player_exit_format[];
extern const char lobby_debug_burst_overwrite_format[];
extern const char lobby_debug_udp_close_ip_format[];
extern const char lobby_debug_lobby_start_format[];
extern const char lobby_debug_game_start_format[];
extern const char lobby_window_title_ship_select[];
extern const char lobby_window_title_block_select[];
extern const char lobby_list_header_block[];
extern RecoveredGlobal_80135974_lbl_805127F8 quest_story_flags_by_difficulty;
extern s32 game_difficulty_selection;
extern s32 quest_download_active;
extern const char lobby_debug_duplicate_player_format[];
void render_shadows__7TObjectFv();
extern const char lobby_debug_rcv_set_flag_format[];
extern s16 TLobby__data_805D5CE8;
extern const char lobby_debug_my_player_format[];
extern const char lobby_list_savedata_format[];
extern const char lobby_list_duplicate_my_player_format[];
extern const char lobby_list_block_range_format[];
void *__ct__11TWindowRoomFPc(void *self, char *title);
void handle_chat_message__11TWindowCtrlFPc(char *);
extern const NJS_POINT2 lbl_8043EE10[1];
extern const NJS_POINT2 lbl_8043EE08[1];
extern const char lobby_msg_registed[];
extern const char lobby_msg_name_taken[];
extern const char lobby_msg_regist_check_ok[];
extern const char lobby_msg_login_success[];
void send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(void *, void *, void *, void *, void *, void *, void *);
void construct_lobby_players(Rec_801378AC *records, s32 count, int self_id, s32 unused);
extern const NJS_POINT2 lbl_8043EE00[1];
s32 clear_lobby_flag__10TObjPlayerFPv();
extern s32 lbl_805DB0B4;
extern const char lobby_window_title_block_jump[];
extern const char lobby_window_title_ship_jump[];
const char *TWindowMakeTeam__sub_80264B24(TWindowMakeTeam *window);
const char *TWindowMakeTeam__sub_80264B38(TWindowMakeTeam *window);
extern const NJS_POINT2 lbl_8043EDF8[1];
extern const NJS_POINT2 lbl_8043EDF0[1];
extern const f32 lbl_805DB0B8;
extern const NJS_POINT2 lbl_8043EDE8[1];
extern const char lobby_window_title_taisen_team[];
s32 get_link_status__Fv(void);
void show_card_list_message(void *msg);
void TLobby__sub_80136E68(s32 count, Ent_80136E68 *entries, Ent_80136E68 *selected);
void receive_file_chunk__22TQuestVmDownLoadServerFv();
void begin_file_download__22TQuestVmDownLoadServerFv();
void handle_trade_received_items(TTradeList *trade_list);
void __register_global_object(int, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __destroy_arr(void *arr, void *dtor, u32 size, u32 count);
extern int lobby_player_count;
extern int item_drop_server_seed;
extern int area_random_seed;
}
void bswap_object_source_record(void *);
void set_area_random_seed(int a0);
void buffer_reset(void);
void bswap_telepipe_record(void *);


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
s32 TLobby::data_805D55B8;
s32 TLobby::login_pending_flag;
s32 lbl_805D55C0;
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
TWindowMessage *TLobby__idle_timeout_object;

#pragma push
#pragma readonly_strings on
const char *lobby_class_name = "TLobby";
#pragma pop
// Lobby server host names (each listed twice in its table).
const char join_lobby_game04_server_host[] = "game04.st-pso.games.sega.net";
const char join_lobby_ss702_server_host[] = "ss702.sonicteam.com";
const char join_lobby_ddplanet_server_host[] = "ddplanet.sega.co.jp";
Server_801399B8 join_lobby_server_table[2] = { { join_lobby_game04_server_host, 0x238F }, { join_lobby_game04_server_host, 0x238F } };
Server_801399B8 lbl_804A6FE8[2] = { { join_lobby_ss702_server_host, 0x238C }, { join_lobby_ss702_server_host, 0x238C } };
Server_801399B8 lbl_804A6FF8[2] = { { join_lobby_ddplanet_server_host, 0x2329 }, { join_lobby_ddplanet_server_host, 0x2329 } };
void *lbl_804A7008[6] = { 0, 0, (void *)__dt__13TUnk_804A7008Fv, (void *)TLobby::update_idle_timeout, (void *)TLobby__sub_8013A2DC, (void *)render_shadows__7TObjectFv };

u32 TLobby::join_entries_dtor_registration[3];
u32 TLobby::join_entries[3252];
u32 lbl_80509D3C[8];
u32 lobby_player_status_records[852];
char lobby_ship_name[0x28];
u32 lbl_8050AAD4[5];
LobbyPlayerName lobby_player_names[12];
s32 game_join_pending_clients[4];
Row_80135208 game_join_player_records[4];
u32 lobby_join_message_buffer[64];
char player_joined_message[0x80];
char lobby_idle_timeout_text_buffer[0x100];
u8 lobby_scroll_text_buffer[0x1000];

void TLobby::send_game_character() {
    A_80134E30 a;
    u8 b[0x7C];
    char c[0xAC];
    D_80134E30 d;
    u8 e[0x204];
    u8 *card;
    TAdSinglePlyChrSelectGC::init();
    card = get_character_save_record(0xFFFF);
    memset(&a, 0, sizeof(a));
    a.kb = TLobby::open_hard_keyboard((void *)(saddr)local_client_id) != 0 ? 1 : 0;
    TLobby__sub_80077798(card + 0x22EC, &a);
    memset(c, 0, sizeof(c));
    strncpy(c, (char *)TLobby::get_card_window_field(), 0xAC);
    memset(b, 0, sizeof(b));
    ((TLobby *)b)->collect_active_card_ids();
    memset(e, 0, sizeof(e));
    if (TLobby::get_flag_bit0() != 0) {
        e[1] = 1;
        strncpy((char *)e + 4, (char *)TLobby::get_card_window_area(), 0x200);
    }
    memset(&d, 0, sizeof(d));
    d.b = *(ChallengeRecord *)(card + 0x21C4);
    d.h[0] = *(u16 *)(card + 0x21A8);
    d.h[1] = *(u16 *)(card + 0x21AA);
    d.h[2] = *(u16 *)(card + 0x21AC);
    d.h[3] = *(u16 *)(card + 0x21AE);
    d.h[4] = *(u16 *)(card + 0x21B0);
    d.h[5] = *(u16 *)(card + 0x21B2);
    d.h[6] = *(u16 *)(card + 0x21B4);
    d.w0 = *(u32 *)(card + 0x21B8);
    d.w1 = *(u32 *)(card + 0x21BC);
    send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(protocol_instance, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), &d, &a, b, e, c);
}
void TLobby::update_idle_timeout(void *object) {
    Timer_80134F9C *t = (Timer_80134F9C *)object;
    NJS_POINT2 tmp = lbl_8043EE28[0];
    DateStamp_80134F9C ds;
    u32 limit;
    u32 elapsed;
    getDateStamp((DateStamp *)&ds);
    DateToSeconds((DateStamp *)&ds, (int *)&t->now);
    if (has_window_task_root() == 0) {
        TLobby__idle_timeout_object = 0;
    }
    if (hardware_keyboard_state.has_any_key_pressed() != 0 || TKeyBoardControl::any_pad_input_active() != 0) {
        t->start = t->now;
        t->state = 0;
        if (TLobby__idle_timeout_object != 0) {
            delete TLobby__idle_timeout_object;
            TLobby__idle_timeout_object = 0;
        }
    }
    t->limit = ((TLobby *)(saddr)local_client_id)->get_table_entry_by_index();
    elapsed = t->now - t->start;
    switch (t->state) {
    case 0:
        if (t->limit != 0 && elapsed + 0x1E > t->limit) {
            t->state = 1;
            if (TLobby__idle_timeout_object == 0 && has_window_task_root() != 0) {
                sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), t->limit - elapsed);
                TLobby__idle_timeout_object = (TWindowMessage *)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xCA)), (const f32 *)(&tmp), 1);
                TLobby__idle_timeout_object->append_line((saddr)lobby_idle_timeout_text_buffer, (int)0x80);
                TLobby__idle_timeout_object->set_depth(30000.0f);
                TLobby__idle_timeout_object->complete_reveal();
            }
        }
        break;
    case 1:
        limit = t->limit;
        if (elapsed > limit) {
            delete TLobby__idle_timeout_object;
            TLobby__idle_timeout_object = 0;
            idle_timeout_active = 1;
            queue_destruction__7TObjectFv(object);
        } else {
            sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), limit - elapsed);
        }
        break;
    }
}

u8 *init_idle_timeout_timer(u8 *arg0, saddr parent) {
    s32 date;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)parent);
    *(void ***)((s8 *)arg0 + 0x18) = lbl_804A7008;
    getDateStamp((DateStamp *)(&date));
    DateToSeconds((DateStamp *)(&date), (int *)(arg0 + 0x1C));
    ((TUnk_804A7008 *)arg0)->m_20 = (s32) *(s32 *)((s8 *)arg0 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x24) = ((TLobby *)(saddr)local_client_id)->get_table_entry_by_index();
    ((TUnk_804A7008 *)arg0)->m_28 = 0;
    TLobby__idle_timeout_object = 0;
    return arg0;
}

void TLobby::open_udp_socket_for_player(s32 client) {
    TPacket *o = new TPacket((TObject *)game_protocol_instance);
    if (o != NULL) {
        o->m_id = client;
        o->set_ip_address(game_join_player_records[client].ip);
        o->m_dst_port = local_client_id + 0xFA0;
        o->m_src_port = client + 0xFA0;
        s32 v = o->open();
        lobby_debug_printf_stub(lobby_debug_udp_open_format, v, o->m_dst_addr.addr_bytes[0], o->m_dst_addr.addr_bytes[1], o->m_dst_addr.addr_bytes[2], o->m_dst_addr.addr_bytes[3]);
    }
}

void handle_6x71_unblock_game_join(void) {
    LEntry_801352C0 *e;
    s32 *pend;
    u8 *p;
    saddr i;

    if (TLobby__data_805D5CE8 == 0) {
        p = reinterpret_cast<u8 *>(create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)));
        ((TLobby *)(p + 0xDAC))->copy_header_struct(&TLobby::protocol_instance->m_guildcard_tag);
        ((TObjPlayer *)p)->reset_motion_fields();
        {
            saddr nm = (saddr)lobby_player_names;
            strncpy((char *)(nm + local_client_id * 16), ((TObjPlayer *)p)->get_name(), 0x10);
        }
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        pend = (s32 *)game_join_pending_clients;
        for (i = 0; i < 4; i++) {
            if (pend[i] != 0) {
                TLobby::send_6x70_player_data(i);
                if (get_player_by_client_id(i) == NULL) {
                    e = (LEntry_801352C0 *)TLobby::join_entries;
                    e += i;
                    p = reinterpret_cast<u8 *>(create_player_object(i, 4, reinterpret_cast<TPlyCharData *>(e->body)));
                    ((TLobby *)(p + 0xDAC))->copy_header_struct(e);
                    ((TObjPlayer *)p)->reset_motion_fields();
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

void TLobby::send_6x71_to_player() {
    saddr client_id = (saddr)this;
    G_ClientIDHeader packet;
    packet.subcommand = 0x71;
    packet.size = 1;
    packet.client_id = 0;
    bswap_client_id_header(&packet);
    ((game_command *)&packet)->send_to_client(client_id);
}

void handle_6x70_sync_player_disp_and_inventory(Pkt_801354AC *arg0) {
    TObjPlayer *plr;
    Disp_801354AC *disp;
    TObjPlayer *p;
    if (TLobby__data_805D5CE8 == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        disp = &arg0->disp;
        TLobby::bswap_player_data(disp);
        if (disp->id != local_client_id) {
            p = get_player_by_client_id(disp->id);
            if (p != NULL) {
                delete p;
            }
            plr = (TObjPlayer *)create_remote_player_object(disp);
            strncpy(lobby_player_names[plr->get_entity_id()], plr->get_name(), 0x10);
            TLobby::open_udp_socket_for_player(disp->id);
            lobby_debug_printf_stub(lobby_debug_create_player_format, plr->get_entity_id());
        }
    }
}
void TLobby::send_6x70_player_data(int size) {
    Stack_80135598 stack;
    u8 *temp_r3;
    init_player_join_record(&stack.sp8);
    temp_r3 = (u8 *)(mem_alloc(0x494));
    if (temp_r3 != NULL) {
        TObjPlayer::fill_player_record((void *) (get_player_by_client_id(local_client_id)), temp_r3 + 8);
        *(s8 *)((s8 *)temp_r3 + 0) = 0x70;
        *(s8 *)((s8 *)temp_r3 + 1) = 0;
        *(s16 *)((s8 *)temp_r3 + 2) = (s16) local_client_id;
        *(s32 *)((s8 *)temp_r3 + 4) = 0x494;
        bswap_and_send_extended_subcommand(temp_r3, size);
        mem_free(temp_r3);
    }
}

#pragma push
#pragma peephole off
void handle_6x6F_set_quest_flags_v2(saddr arg0) {
    if (((s16) TLobby__data_805D5CE8 == 0) && (((s32) TLobby::lobby_state == 0xE) || ((s32) TLobby::lobby_state == 0xF))) {
        memcpy((void *) (&(*(RecoveredGlobal_8013561C_lbl_805127F8 *)&quest_story_flags_by_difficulty).value), (void *)(arg0 + 4), 0x200);
    }
}
#pragma pop

void handle_6x6E_sync_game_state(Pkt_8013566C *arg0) {
  u8 *new_var;
  u8 *new_var2;
  void *tmp;
  GameStateSyncScratch *buf;
  s32 n;
  if ((TLobby__data_805D5CE8 == 0) && ((TLobby::lobby_state == 0xE) || (TLobby::lobby_state == 0xF)))
  {
    lobby_debug_printf_stub(lobby_debug_rcv_set_flag_format, arg0->len);
    buf = static_cast<GameStateSyncScratch *>(::operator new(sizeof(GameStateSyncScratch)));
    if (buf != 0)
    {
      tmp = ::operator new(0x7230);
      if (tmp != 0)
      {
        new_var2 = buf->payload;
        new_var = new_var2;
        TLobby__sub_8013F810(tmp, arg0->data, arg0->len, buf);
        ::operator delete(tmp);
        TLobby::bswap_6x6E_sync_game_state(buf);
        apply_floor_set_flags_packet(reinterpret_cast<FloorSetFlagsHeader *>(new_var), buf->floor_flags_size);
        n = buf->floor_flags_size;
        import_sync_records__6TLobbyFPs(&buf->payload[n], buf->sync_records_size);

        if ((buf->sync_records_size && buf->sync_records_size) && buf->sync_records_size)
        {
        }
        n += buf->sync_records_size;
        restore_switch_table((saddr)(&buf->payload[n]), buf->switch_table_size);
        activate_triggered_floor_events();
      }
      ::operator delete((0, buf));
    }
  }
}

void handle_6x6D_sync_game_state(Pkt_8013574C *arg0) {
    s32 len;
    u8 *buf;
    void *tmp;
    if (TLobby__data_805D5CE8 == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        len = arg0->len - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_item_condition_format, arg0->len);
        buf = (u8 *)mem_alloc(0x8000);
        if (buf != NULL) {
            tmp = ::operator new(0x7230);
            if (tmp != NULL) {
                TLobby__sub_8013F810(tmp, arg0->data + 0, len, buf);
                ::operator delete(tmp);
            }
            ((TLobby *)buf)->apply_sync_item_state();
            mem_free(buf);
        }
    }
}

void handle_6x6C_sync_game_state(Pkt_801357F8 *arg0) {
    u32 r;
    QuestObjectEntry *p;
    s32 n;
    s32 i;
    if (TLobby__data_805D5CE8 == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        n = arg0->len - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_object_condition_format, arg0->len);
        p = (QuestObjectEntry *)::operator new(0x7230);
        if (p != NULL) {
            r = ((u32)TLobby__sub_8013F810(p, arg0->data, n, quest_object_entries));
            ::operator delete(p);
            n = r >> 2;
            p = quest_object_entries;
            object_condition_count = n;
            for (i = 0; i < n; i++) {
                bswap_object_source_record(&p[i]);
            }
        }
    }
}

void handle_6x6B_sync_game_state(Pkt_801358B4 *arg0) {
    u32 r;
    EnemyStateRecord *p;
    s32 n;
    s32 i;
    if (TLobby__data_805D5CE8 == 0 && (TLobby::lobby_state == 0xE || TLobby::lobby_state == 0xF)) {
        n = arg0->len - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_enemy_condition_format, arg0->len);
        p = (EnemyStateRecord *)::operator new(0x7230);
        if (p != NULL) {
            r = ((u32)TLobby__sub_8013F810(p, arg0->data, n, TLobby__data_805D6144));
            ::operator delete(p);
            n = r / sizeof(EnemyStateRecord);
            p = TLobby__data_805D6144;
            enemy_condition_count = n;
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
        }
    }
}

void send_6x6F_quest_flags(saddr size) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80135974, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80135974, spC) == 0x4);
    Stack_80135974 stack;
    TLobby__sub_8013A578(&stack.sp8);
    memcpy(&stack.spC, &quest_story_flags_by_difficulty.value, 0x200);
    TLobby::bswap_and_handle_packet(&stack.sp8, size);
}
void TLobby::send_6x6E_sync_game_state(int size) {
    s32 n;
    s32 len;
    Pkt_801359C4 *buf;
    GameStateSyncScratch *hdr;
    void *tmp;
    buf = (Pkt_801359C4 *)mem_alloc(0x4000);
    if (buf != NULL) {
        memset(buf, 0, 0x4000);
        hdr = static_cast<GameStateSyncScratch *>(::operator new(sizeof(GameStateSyncScratch)));
        if (hdr != NULL) {
            memset(hdr, 0, sizeof(*hdr));
            hdr->floor_flags_size = serialize_area_set_flags(reinterpret_cast<FloorSetFlagsPayload *>(hdr->payload));
            n = hdr->floor_flags_size;
            hdr->sync_records_size = TLobby::export_sync_records(reinterpret_cast<s16 *>(&hdr->payload[n]));
            n += hdr->sync_records_size;
            hdr->switch_table_size = copy_switch_table(&hdr->payload[n]);
            n += hdr->switch_table_size;
            hdr->total_size = n;
            TLobby::bswap_6x6E_sync_game_state(hdr);
            tmp = ::operator new(0x7230);
            if (tmp != NULL) {
                len = ((TLobby *)tmp)->lz_compress_packet((void *)hdr, (s32)n, (s32 *)buf->data);
                ::operator delete(tmp);
            }
            ::operator delete(hdr);
        }
        buf->cmd = 0x6E;
        buf->flag = 0;
        buf->f2 = 0;
        buf->len = ((len + 3) & ~3) + 8;
        bswap_and_send_extended_subcommand(buf, size);
        mem_free(buf);
    }
}

void TLobby::send_6x6D_item_state() {
    saddr arg0 = (saddr)this;
    s32 n;
    s32 len;
    Pkt_80135AE0 *buf;
    u8 *src;
    void *tmp;
    buf = (Pkt_80135AE0 *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        src = (u8 *)mem_alloc(0x8000);
        if (src != NULL) {
            memset(src, 0, 0x8000);
            n = ((TLobby *)src)->write_sync_item_state();
            tmp = ::operator new(0x7230);
            if (tmp != NULL) {
                len = ((TLobby *)tmp)->lz_compress_packet((void *)src, (s32)n, (s32 *)buf->data);
                ::operator delete(tmp);
            }
            mem_free(src);
        }
        buf->cmd = 0x6D;
        buf->flag = 0;
        buf->f2 = 0;
        buf->len = ((len + 3) & ~3) + 8;
        bswap_and_send_extended_subcommand(buf, arg0);
        mem_free(buf);
    }
}

void TLobby::send_compressed_packet_6c() {
    QuestObjectEntry *src;
    s32 len;
    u32 size;
    Pkt_80135BD0 *buf;
    void *tmp;
    u32 n;
    u32 *p;
    u32 i;
    saddr arg0 = (saddr)this;
    buf = (Pkt_80135BD0 *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        tmp = ::operator new(0x7230);
        if (tmp != NULL) {
            src = quest_object_entries;
            size = object_condition_count * 4;
            n = size / 4;
            p = (u32 *)mem_alloc(size);
            memcpy(p, src, size);
            for (i = 0; i < n; i++) {
                bswap_object_source_record(&p[i]);
            }
            len = ((TLobby *)tmp)->lz_compress_packet((void *)p, (s32)size, (s32 *)buf->data);
            mem_free(p);
            ::operator delete(tmp);
            buf->cmd = 0x6C;
            buf->flag = 0;
            buf->f2 = 0;
            buf->len = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand(buf, arg0);
        }
        mem_free(buf);
    }
}

void TLobby::send_cmd_6B() {
    EnemyStateRecord *src;
    s32 len;
    u32 size;
    Pkt_80135CD8 *buf;
    void *tmp;
    u32 n;
    EnemyStateRecord *p;
    u32 i;
    saddr arg0 = (saddr)this;
    buf = (Pkt_80135CD8 *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        tmp = ::operator new(0x7230);
        if (tmp != NULL) {
            src = TLobby__data_805D6144;
            size = enemy_condition_count * sizeof(EnemyStateRecord);
            n = size / sizeof(EnemyStateRecord);
            p = (EnemyStateRecord *)mem_alloc((s32)(n * sizeof(EnemyStateRecord)));
            memcpy(p, src, size);
            for (i = 0; i < n; i++) {
                p[i].bswap();
            }
            len = ((TLobby *)tmp)->lz_compress_packet((void *)p, (s32)size, (s32 *)buf->data);
            mem_free(p);
            ::operator delete(tmp);
            buf->cmd = 0x6B;
            buf->flag = 0;
            buf->f2 = 0;
            buf->len = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand(buf, arg0);
        }
        mem_free(buf);
    }
}

void show_card_list_message(void *msg) {
    if (TLobby::card_list_window != 0) {
        TLobby::card_list_window->close();
        TLobby::card_list_window = 0;
    }
    if (TLobby::lobby_state == 0x11) {
        Pair_80135E7C p = lbl_8043EE20[0];
        TLobby::card_list_window = (TWindowMessage *)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xC9)), (const f32 *)(&p), 1);
        TLobby::card_list_window->append_line((saddr)((char *)msg + 4), (int)3);
        TLobby::card_list_window->set_depth(37000.0f);
    }
}

#pragma defer_codegen on
void TLobby::show_seq_phase_message(int id) {
    if (current_dialog_window == 0) {
        NJS_POINT2 tmp = lbl_8043EDE8[0];
        current_dialog_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        current_dialog_window->set_depth(lbl_805DB0B8);
    }
    current_dialog_window->append_line((int)(TLobby::get_seq_phase(id)), (int)1);
}

void show_dialog_value_line(saddr arg0) {
    if (TLobby::current_dialog_window == 0) {
        NJS_POINT2 tmp = lbl_8043EDF0[0];
        TLobby::current_dialog_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        TLobby::current_dialog_window->set_depth(lbl_805DB0B8);
    }
    TLobby::current_dialog_window->append_line((int)arg0, (int)1);
}
void TLobby::close_com_card_window() {
    if (current_dialog_window != 0U) {
        current_dialog_window->close();
        current_dialog_window = 0U;
    }
}

void show_join_entry_message(s32 id) {
    if (TLobby::join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EDF8[0];
        TLobby::join_entry_window_obj = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc2), &tmp);
    }
    TLobby::join_entry_window_obj->append_line((int)(TLobby::get_seq_phase(id)), (int)1);
}

void TLobby::run_task() {
    s32 r;
    switch ((*(u32 *)&lobby_state)) {
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
        func_80019A68__Fv();
    }
    r = TLobby::query_task_active();
    if (protocol_instance->m_is_invalid_packet != 0 || get_link_status__Fv() == 0 || r < 0) {
        protocol_instance->m_is_invalid_packet = 0;
        TQuestListOnline::close_windows_and_reset();
        if (r < 0) {
            TLobby::update_state();
            return;
        }
        while (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) == -1) {
        }
        TLobby__sub_801384E4();
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
                (char *)lobby_window_title_taisen_team, (char *)TLobby__data_805DB0B0);
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
                (char *)TLobby__data_805DB0B0, (char *)TLobby__data_805DB0B0);
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
                // 0x801381D0 is called with no argument here; the (void *) in its symbol is a guess
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
                (char *)TLobby__data_805DB0B0, (char *)TLobby__data_805DB0B0);
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
                (char *)lobby_window_title_ship_jump, (char *)TLobby__data_805DB0B0);
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
                (char *)lobby_window_title_block_jump, (char *)TLobby__data_805DB0B0);
            TLobby::close_and_set_state_12();
            return;
        }
        if (controller_input_state.sources[0]->pressed & 0x400) {
            idx = list_window->get_cursor_value();
            protocol_instance->send_info(protocol_instance->m_game_entries[idx].tag);
        }
    }
}

void queue_join_entry_exit_on_input(void *self) {
    if ((controller_input_state.sources[0]->pressed & 8) || TLobby::join_lobby_idle_timer++ > 0xe10) {
        TAdSinglePlyChrSelectGC::init();
        set_queued_main_phase(2);
        request_main_phase(0x12);
        ((void (*)(void *))queue_destruction__7TObjectFv)(self);
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
            name = TWindowMakeTeam__sub_80264B38(lobby_make_team_window);
            if (name != NULL) {
                password = TWindowMakeTeam__sub_80264B24(lobby_make_team_window);
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
                (char *)TLobby__data_805DB0B0, text);
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
        protocol_instance->send_action(e, (char *)TLobby__data_805DB0B0, (char *)TLobby__data_805DB0B0);
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
            download_list_window->append_line((saddr)protocol_instance->m_quest_entries[sel].short_description, (int)3);
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
    void *temp;
    temp = card_list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        card_list_window = 0U;
    }
    temp = download_list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        download_list_window = 0U;
    }
    temp = list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        list_window = 0U;
    }
    temp = current_dialog_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        current_dialog_window = 0U;
    }
    temp = join_entry_window_obj;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        join_entry_window_obj = 0U;
    }
    temp = TLobby_warp_menu_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby_warp_menu_window = NULL;
    }
    temp = lobby_com_card_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        lobby_com_card_window = NULL;
    }
    temp = lobby_make_team_menu_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        lobby_make_team_menu_window = NULL;
    }
    temp = lobby_make_team_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
        lobby_make_team_window = NULL;
    }
    temp = lobby_keyboard_prompt_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
        lobby_keyboard_prompt_window = NULL;
    }
    temp = lobby_scroll_text_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
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
    s32 window_layout_position;
    TLobby::show_seq_phase_message(3);
    window_layout_position = (saddr)get_window_layout_position(0xB4);
    if ((s32) lobby_number < 0xD) {
        TLobby_warp_menu_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x35), 6, 0);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x36), 6, 1);
    } else {
        TLobby_warp_menu_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 3);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x35), 6, 0);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x36), 6, 1);
        TLobby_warp_menu_window->add_text_entry(TLobby::get_seq_phase(0x47), 6, 3);
    }
    TLobby_warp_menu_window->calc_window_size();
    align_menu_entry_positions(TLobby_warp_menu_window);
    TLobby_warp_menu_window->set_ready_flag();
    TLobby::init_player_window_effect();
    lobby_state = 3;
}

void TLobby__sub_801384E4(void) {
    if (TLobby::join_lobby_controller != NULL) {
        if ((s32) TLobby::player_setup_pending == 0) {
            if ((s32) TLobby::lobby_state != 0xC) {
                sprintf((char *)lobby_join_message_buffer, (const char *)TLobby::get_seq_phase(7), lbl_80509D3C);
                show_dialog_value_line((saddr)lobby_join_message_buffer);
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
        lbl_805D55C0 = 1;
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
        lbl_805D55C0 = 1;
    }
}
void TLobby::reset_state(int msg) {
    show_join_entry_message(msg);
    TLobby::init_player_window_effect();
    join_lobby_idle_timer = 0;
    lobby_state = 0xC;
    lbl_805D55C0 = 1;
}
void TLobby::close_and_set_state_13(int msg) {
    show_join_entry_message(msg);
    TLobby::init_player_window_effect();
    lobby_state = 0xD;
}
void TLobby::create_warp_menu() {
    s32 window_layout_position;
    ((TWindowMenu *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x39), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3A), 6, 1);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
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
        ((TWindowMenu *)menu)->open();
    }
    TLobby::show_seq_phase_message(0x11);
    lobby_make_team_menu_window = (TWindowMenu *)create_window_menu_default((saddr)get_window_layout_position(0xB6), 2);
    lobby_make_team_menu_window->add_text_entry(TLobby::get_seq_phase(0x45), 6, 0);
    lobby_make_team_menu_window->add_text_entry(TLobby::get_seq_phase(0x46), 6, 1);
    lobby_make_team_menu_window->calc_window_size();
    align_menu_entry_positions(lobby_make_team_menu_window);
    lobby_make_team_menu_window->set_ready_flag();
    ((TWindowSubComCardList *)lobby_make_team_menu_window)->set_selected_index(0);
    lobby_state = 0x18;
}
void TLobby::open_make_team_window(int mode) {
    lobby_make_team_window = new TWindowMakeTeam((TObject *)join_lobby_controller, mode);
    lobby_state = 0xA;
}
void TLobby::close_all_windows(void *) { TLobby::close_all_windows(); }
void TLobby::open_warp_menu() {
    s32 window_layout_position;
    ((TWindowMenu *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3E), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x3F), 6, 1);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
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
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    protocol_instance->send_ship_list_request();
    lobby_state = 7;
}
void TLobby::close_menu_windows() {
    TLobby::show_seq_phase_message(6);
    TLobby_warp_menu_window->close();
    TLobby_warp_menu_window = NULL;
    lobby_com_card_window->close();
    lobby_com_card_window = NULL;
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    protocol_instance->send_block_list_request();
    lobby_state = 8;
}
void TLobby::close_and_send_text_list() {
    TLobby::close_all_windows();
    TLobby::init_player_window_effect();
    protocol_instance->send_text_list();
}
void TLobby::open_keyboard_window() {
    saddr var_r0;
    s32 tmp_r3;

    if (current_dialog_window != 0U) {
        current_dialog_window->close();
        current_dialog_window = 0U;
    }
    if (lobby_keyboard_prompt_window == NULL) {
        static s32 *blank_entry = &lbl_805DB0B4;
        tmp_r3 = (saddr)get_window_layout_position(0xC3);
        lobby_keyboard_prompt_window = (TWindowMenu *)create_window_menu_default(tmp_r3, 2);
        lobby_keyboard_prompt_window->add_text_entry(TLobby::get_seq_phase(0x44), 2, 0);
        lobby_keyboard_prompt_window->add_text_entry((saddr)blank_entry, 2, 1);
        lobby_keyboard_prompt_window->calc_window_size();
        align_menu_entry_positions(lobby_keyboard_prompt_window);
        lobby_keyboard_prompt_window->set_flag_40();
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
    s32 window_layout_position;
    ((TWindowMenu *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 5);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4C), 6, 0);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x48), 6, 1);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x49), 6, 2);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4A), 6, 3);
    lobby_com_card_window->add_text_entry(TLobby::get_seq_phase(0x4B), 6, 4);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
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
    if (get_player_by_client_id(local_client_id) != NULL) {
        clear_lobby_flag__10TObjPlayerFPv();
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
}

void TLobby__sub_80137C10(s32 arg0) {
    if (TLobby::download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE00[0];
        TLobby::download_list_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc6), &tmp);
    }
    TLobby::download_list_window->append_line((int)arg0, (int)3);
    TLobby::lobby_state = 0x14;
    TQuestListOnline__sub_8013ACF4(0xb);
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
    data_805D55B8 = 0;
    login_pending_flag = 1;
    lbl_805D55C0 = 0;
    player_setup_pending = 0;
    lobby_selected_game_list_index = 0;
    join_lobby_controller = NULL;
    TLobby__data_805D4E30 = 0;
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
        construct_lobby_players((Rec_801378AC *)join_entries, pending_member_count, pending_local_client_id, designated_client_id);
        break;
    case 3:
    case 4:
        TLobby::make_players();
        break;
    case 5:
        TLobby__sub_801384E4();
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
        TLobby::copy_member_record(&((TPlyJoinLobbyEntry *)join_entries)[i], &src[i]);
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
void TLobby::handle_verify_result(unsigned int arg0) {
    s32 option_state;
    switch (arg0) {
    case 0:
    case 2:
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        TLobby::dispatch_by_index(1);
        option_state = TLobby::get_option_state();
        protocol_instance->send_login_9e_extended((void *) (((saddr)(void *)TAdSinglePlyChrSelectGC::get_char_index((u32)(0xFFFF))) + 0x370), (int)option_state);
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
void TLobby::handle_register_result(int arg0) {
    s32 opt;
    if (arg0 != 0) {
        lobby_debug_printf_stub(lobby_msg_registed);
        get_player_by_client_id(local_client_id);
        opt = TLobby::get_option_state();
        protocol_instance->send_login_9e_extended((u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) + 0x370, opt);
        TLobby::dispatch_by_index(1);
        return;
    }
    lobby_debug_printf_stub(lobby_msg_name_taken);
    TLobby::dispatch_by_index(2);
    TLobby::reset_state(0x50);
}
void TLobby::handle_login_result(unsigned int arg0) {
    s32 event_counter;
    switch (arg0) {
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
    A_80137384 a;
    u8 b[0x7C];
    char c[0xAC];
    D_80137384 d;
    u8 e[0x204];
    u8 *card;
    card = get_character_save_record(0xFFFF);
    memset(&a, 0, sizeof(a));
    a.kb = TLobby::open_hard_keyboard((void *)(saddr)local_client_id) != 0 ? 1 : 0;
    TLobby__sub_80077798(card + 0x22EC, &a);
    memset(c, 0, sizeof(c));
    strncpy(c, (char *)TLobby::get_card_window_field(), 0xAC);
    memset(b, 0, sizeof(b));
    ((TLobby *)b)->collect_active_card_ids();
    memset(e, 0, sizeof(e));
    if (TLobby::get_flag_bit0() != 0) {
        e[1] = 1;
        strncpy((char *)e + 4, (char *)TLobby::get_card_window_area(), 0x200);
    }
    memset(&d, 0, sizeof(d));
    d.b = *(ChallengeRecord *)(card + 0x21C4);
    d.h[0] = *(u16 *)(card + 0x21A8);
    d.h[1] = *(u16 *)(card + 0x21AA);
    d.h[2] = *(u16 *)(card + 0x21AC);
    d.h[3] = *(u16 *)(card + 0x21AE);
    d.h[4] = *(u16 *)(card + 0x21B0);
    d.h[5] = *(u16 *)(card + 0x21B2);
    d.h[6] = *(u16 *)(card + 0x21B4);
    d.w0 = *(u32 *)(card + 0x21B8);
    d.w1 = *(u32 *)(card + 0x21BC);
    send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(protocol_instance, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), &d, &a, b, e, c);
}
void TLobby::queue_static_object_destruction() {
    join_lobby_controller->queue_destruction();
}
void TLobby::send_position_update() {
    s32 event_counter;
    s32 temp_r4;

    event_counter = TAdSinglePlyChrSelectGC::increment_frame();
    temp_r4 = TAdSinglePlyChrSelectGC::get_player_count();
    protocol_instance->send_character_save_info(temp_r4, event_counter);
}
void TLobby::handle_state(int arg0) {
    s32 temp_r3;

    if (arg0 != 0) {
        TAdSinglePlyChrSelectGC::save_online_character();
        temp_r3 = TLobby__sub_80146740();
        switch (temp_r3) {
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

void TLobby__sub_80137228(s32 arg0) {
    if (TLobby::download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE08[0];
        TLobby::download_list_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc7), &tmp);
    }
    TLobby::download_list_window->append_line((int)arg0, (int)3);
}

void TLobby__sub_801371B0(s32 arg0) {
    if (TLobby::join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EE10[0];
        TLobby::join_entry_window_obj = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc8), &tmp);
    }
    TLobby::join_entry_window_obj->append_line((int)arg0, (int)3);
    TLobby::lobby_state = 0x16;
}
void TLobby::disable_window_flags(void*flags) { TWindowCtrl::set_window_flags_off(local_client_id, (saddr)flags); }
void TLobby::open_ship_block_select_menu(int count, void *entries, void *selected) {
    static void *tblA = (void *)lobby_window_title_ship_select;
    static void *tblB = (void *)lobby_window_title_block_select;
    Ent_8013703C *list = (Ent_8013703C *)entries;
    Ent_8013703C *entry = (Ent_8013703C *)selected;
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
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((saddr)tbl);
    for (i = 0; i < count; i++) {
        ((TLobby *)list_window)->add_status_disp_entry((saddr)list[i].name, (s32)i);
    }
    list_window->calc_content_extent();
    if (cmp == 0) {
        TLobby::set_menu_mode_1();
    } else {
        TLobby::set_menu_mode_0();
    }
    if (strncmp(entry->name, lobby_list_header_block, 5) != 0) {
        memset(lobby_ship_name, 0, 0x11);
        strncpy(lobby_ship_name, entry->name, 0x10);
    }
}
void TLobby::open_information_list(int count, void *entries) {
    Ent_80136FA0 *list = (Ent_80136FA0 *)entries;
    void *w = (void *)lobby_window_title_information;
    s32 i;
    void *old = list_window;
    if (old != 0) {
        ((TObject *)old)->queue_destruction();
        list_window = 0;
    }
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((saddr)w);
    for (i = 0; i < count; i++) {
        ((TLobby *)list_window)->add_status_disp_entry((saddr)list[i].name, (s32)i);
    }
    list_window->calc_content_extent();
    TLobby::set_menu_mode_2();
}

void TLobby__sub_80136E68(s32 count, Ent_80136E68 *entries, Ent_80136E68 *selected) {
    static void *tbl = (void *)lobby_msg_information_counter;
    void *w;
    s32 i;

    if (TLobby::list_window != 0) {
        TLobby::list_window->queue_destruction();
        TLobby::list_window = 0;
    }
    w = TLobby::create_object(tbl);
    for (i = 0; i < count; i++) {
        Ent_80136E68 *e = &entries[i];
        s32 flags = e->flags;
        s8 mark = 0;
        s32 level;
        if (flags & 0x10) {
            mark = 2;
        }
        if (flags & 0x20) {
            mark = 1;
        }
        level = 0;
        if (flags & 0x40) {
            level = 1;
        }
        if (flags & 0x80) {
            level = 2;
        }
        fn_80338D58(w, flags & 2, e->name, (s8)e->b9, 4, (s8)(e->b8 - 0x22), mark, level, i);
    }
    ((TWindowMenuIconLine *)w)->calc_content_extent();
    TLobby::list_window = (TWindowMenuIconLine *)w;
    memset(lbl_8050AAD4, 0, 0x11);
    strncpy((char *)lbl_8050AAD4, selected->name, 0x11);
}
void TLobby::handle_game_join(void *data) {
    Pkt_80136C94 *pkt = (Pkt_80136C94 *)data;
    Hdr_80136C94 hdr;
    TObjPlayer *p;
    saddr i;
    s32 j;
    ((TObjPlayer *)(&hdr))->clear_header_struct();
    ((void * (*)(void *, const void *, u32))memcpy)(((Row_80136C94 *)&game_join_player_records), pkt->rows, 0x80);
    bswap_32(&((Row_80136C94 *)&game_join_player_records)[0].ip);
    bswap_32(&((Row_80136C94 *)&game_join_player_records)[1].ip);
    bswap_32(&((Row_80136C94 *)&game_join_player_records)[2].ip);
    bswap_32(&((Row_80136C94 *)&game_join_player_records)[3].ip);
    TLobby::destroy_all_objects();
    lobby_debug_printf_stub(lobby_debug_game_start_format, pkt->client_id);
    local_client_id = pkt->client_id;
    designated_client_id = pkt->leader_id;
    join_state_flag = pkt->b106;
    TLobby::set_player_count(pkt->count);
    TLobby__data_805D4E30 = pkt->b10b;
    game_difficulty_selection = pkt->b107;
    event_theme_id = pkt->b109;
    set_area_random_seed(pkt->w10c);
    leader_selection.set_section_id(pkt->b10a);
    if ((s32)pkt->b110 == 2) {
        request_story_select_state(1);
    } else {
        request_story_select_state(0);
    }
    fn_8013ACE4(pkt->w10c);
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
    Hdr_80136A8C hdr;
    TObjPlayer *q;
    if (TLobby__sub_801A3E8C() != 0) {
        p = create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct(&protocol_instance->m_guildcard_tag);
        p->reset_motion_fields();
        strncpy(lobby_player_names[local_client_id], p->get_name(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        protocol_instance->send_6F_burst_done();
        lobby_state = 0xF;
        p = create_player_object(1 - local_client_id, 4, TAdSinglePlyChrSelectGC::get_char_index(0));
        if (p != NULL) {
            init_player_join_record(&hdr);
            TObjPlayer::fill_player_record(p, &hdr);
            TLobby::bswap_player_data(&hdr);
            hdr.fAC = 0;
            hdr.f488 = 0;
            delete p;
            q = (TObjPlayer *)create_remote_player_object(&hdr);
            if (q != NULL) {
                q->reset_motion_fields();
            }
        }
    } else if (local_client_id == designated_client_id) {
        p = create_player_object(local_client_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct(&protocol_instance->m_guildcard_tag);
        p->reset_motion_fields();
        strncpy(lobby_player_names[local_client_id], p->get_name(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        protocol_instance->send_6F_burst_done();
        lobby_state = 0xF;
    }
}

#pragma push
#pragma opt_propagation off
void TLobby::handle_lobby_enter(TPlyJoinLobbyEntry *ents, int n, int client_id, int leader, int arg4, int arg5, int arg6, int arg7) {
    s32 v4;
    TObjPlayer *p;
    saddr i;
    s32 j;
    TPacket *node;
    TLobby::destroy_all_objects();
    lobby_debug_printf_stub(lobby_debug_lobby_start_format, client_id);
    local_client_id = client_id;
    v4 = arg4;
    lobby_entered_flag = 1;
    join_state_flag = 1;
    lobby_number = arg4;
    block_number = arg5;
    data_805D55B8 = arg6;
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
    set_floor_map_variant((saddr)(get_current_floor()), v4);
    event_theme_id = arg7;
    activate_keyboard();
    protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)TLobby__sub_801371B0;
}
#pragma pop

void construct_lobby_players(Rec_801378AC *records, s32 count, int self_id, s32 unused) {
    s32 j;
    s32 i;
    u8 *plr;
    void *room;

    for (i = 0; i < count; i++) {
        if (self_id == ((Entry_8013634C *)records)[i].client_id) {
            if (get_player_by_client_id(self_id) == NULL) {
                plr = reinterpret_cast<u8 *>(create_player_object(self_id, 0, TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)));
                ((TLobby *)(plr + 0xDAC))->copy_header_struct(&((Entry_8013634C *)records)[i]);
                ((TObjPlayer *)plr)->reset_motion_fields();
                lobby_debug_printf_stub(lobby_debug_my_player_format, self_id);
                lobby_debug_printf_stub(lobby_list_savedata_format, sizeof(((Entry_8013634C *)records)->char_data));
            } else {
                lobby_debug_printf_stub(lobby_list_duplicate_my_player_format, i);
            }
        }
    }
    for (j = 0; j < count; j++) {
        if (self_id != ((Entry_8013634C *)records)[j].client_id) {
            if (get_player_by_client_id(((Entry_8013634C *)records)[j].client_id) == NULL) {
                plr = reinterpret_cast<u8 *>(create_player_object(((Entry_8013634C *)records)[j].client_id, 4, reinterpret_cast<TPlyCharData *>(((Entry_8013634C *)records)[j].char_data)));
                ((TLobby *)(plr + 0xDAC))->copy_header_struct(&((Entry_8013634C *)records)[j]);
                ((TObjPlayer *)plr)->reset_motion_fields();
                lobby_debug_printf_stub(lobby_debug_create_player_format, ((Entry_8013634C *)records)[j].client_id);
            } else {
                lobby_debug_printf_stub(lobby_debug_duplicate_player_format, ((Entry_8013634C *)records)[j].client_id);
            }
        }
    }
    TLobby::protocol_instance->m_recv_handlers.handle_06_recv_chat = (recv_packet_handler_handle_06_recv_chat)handle_chat_message__11TWindowCtrlFPc;
    if (lobby_player_construction_window != NULL) {
        lobby_player_construction_window->queue_destruction();
        lobby_player_construction_window = NULL;
    }
    sprintf((char *)lbl_80509D3C, lobby_list_block_range_format, lobby_ship_name, TLobby::block_number, TLobby::lobby_number + 1);
    room = TObject::operator new(sizeof(TWindowRoom));
    if (room != NULL) {
        room = __ct__11TWindowRoomFPc(room, (char *)lbl_80509D3C);
    }
    lobby_player_construction_window = (TObject *)room;
    TLobby::close_all_windows();
}
void TLobby::on_game_player_add(TPlyJoinLobbyEntry *entries, int leader_id, int disable_udp) {
    Entry_8013634C e;
    s32 pkt;
    TObjPlayer *p;
    TPacket *n;
    u8 *plr;
    if (lobby_state != 0xE && lobby_state != 0xF) {
        return;
    }
    TLobby__sub_8013AA64((u8 *)&e, (u8 *)entries);
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
    show_dialog_value_line((saddr)player_joined_message);
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
        ((TLobby *)(e.client_id))->send_6x6D_item_state();
        ((TLobby *)(e.client_id))->send_cmd_6B();
        ((TLobby *)(e.client_id))->send_compressed_packet_6c();
        TLobby::send_6x6E_sync_game_state(e.client_id);
        send_6x6F_quest_flags(e.client_id);
        ((TLobby *)(e.client_id))->send_6x71_to_player();
    }
    if (get_player_by_client_id(local_client_id) != NULL) {
        TLobby::send_6x70_player_data(e.client_id);
        if (get_player_by_client_id(e.client_id) == NULL) {
            plr = reinterpret_cast<u8 *>(create_player_object(e.client_id, 4, reinterpret_cast<TPlyCharData *>(e.char_data)));
            ((TLobby *)(plr + 0xDAC))->copy_header_struct(&e);
            ((TObjPlayer *)plr)->reset_motion_fields();
            TLobby::open_udp_socket_for_player(e.client_id);
            lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
        }
    } else {
        game_join_pending_clients[e.client_id] = 1;
        TLobby::copy_member_record(&((Entry_8013634C *)join_entries)[e.client_id], &e);
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
void TLobby::remove_player(unsigned int client, int arg1, int arg2) {
    TObjPlayer *p;
    TPacket *n;
    designated_client_id = arg1;
    join_state_flag = arg2;
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
    strncpy(lobby_player_names[client], TLobby__data_805DB0B0, 0x10);
    if (lobby_state == 0xE) {
        TLobby__data_805D5CE8 = 1;
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
    Entry_80136080 e;
    TObjPlayer *p;
    u8 *plr;
    TLobby__sub_8013AA64((u8 *)&e, (u8 *)entries);
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
    plr = reinterpret_cast<u8 *>(create_player_object(e.client_id, 4, reinterpret_cast<TPlyCharData *>(e.char_data)));
    ((TLobby *)(plr + 0xDAC))->copy_header_struct(&e);
    ((TObjPlayer *)plr)->reset_motion_fields();
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
    strncpy(lobby_player_names[idx], TLobby__data_805DB0B0, 0x10);
}

void TLobby__sub_80135FFC(void) {  }
void TLobby::open_download_list_window(int count, void *entries) {
    static void *tbl = (void *)lobby_window_title_download;
    Ent_80135E7C *list = (Ent_80135E7C *)entries;
    s32 i;
    Ent_80135E7C *e;
    const NJS_POINT2 *w;

    if (list_window != 0) {
        queue_destruction__7TObjectFv(list_window);
        list_window = 0;
    }
    list_window = (TWindowMenuIconLine *)TShopJudgmentItemWindow::open_default((saddr)tbl);
    for (i = 0; i < count; i++) {
        e = &list[i];
        switch (e->kind) {
        case 0:
            list_window->add_list_entry(0x2C, (saddr)e->name, (s32)i);
            break;
        case 1:
            list_window->add_list_entry(0x17, (saddr)e->name, (s32)i);
            break;
        case 2:
            list_window->add_list_entry(0x31, (saddr)e->name, (s32)i);
            break;
        default:
            list_window->add_list_entry(0x2C, (saddr)e->name, (s32)i);
            break;
        }
    }
    list_window->calc_content_extent();
    if (download_list_window != 0) {
        queue_destruction__7TObjectFv(download_list_window);
        download_list_window = 0;
    }
    {
        Pair_80135E7C p = lbl_8043EE18[0];
        w = get_window_layout_position(0xC7);
        download_list_window = (TWindowMessage *)TWindowMessage::create(w, (const f32 *)(&p), 1);
        download_list_window->append_line((saddr)((char *)list + 0x2C), (int)3);
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

#define CONNECT_801399B8(res, s)                                                                   \
    if (TKeyBoardControl__sub_8000F828() == 0) {                                                    \
        res = TLobby::protocol_instance->set_server_info(TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
                                     TLobby::init_serial_access(), (const char *)get_access_key_input_buffer(), \
                                     s[0].host, s[0].port);                                     \
    } else {                                                                                        \
        res = TLobby::protocol_instance->set_server_info(TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
                                     TLobby::init_serial_access(), (const char *)get_access_key_input_buffer(), \
                                     s[1].host, s[1].port);                                     \
    }
void TLobby::run_join_lobby_connect(int arg0) {
    Date_801399B8 date;
    void *p;
    void *win;
    s32 res;

    if (lbl_805D55C0 == 0) {
        reset_controller_input_state();
        getDateStamp((DateStamp *)&date);
        DateToSeconds((DateStamp *)&date, (int *)&date_seconds);
        p = TObject::operator new(0x2C);
        if (p != NULL) {
            init_idle_timeout_timer((u8 *)p, arg0);
        }
        join_state_flag = 1;
        win = TLobby::create_dialing_message_window((void *)(get_connection_message_text(7)), (void *)1);
        switch (TAdSinglePlyChrSelectGC__sub_8033605C()) {
        case 0:
        case 1:
            CONNECT_801399B8(res, join_lobby_server_table)
            break;
        case 2:
            CONNECT_801399B8(res, lbl_804A6FE8)
            break;
        case 3:
        default:
            CONNECT_801399B8(res, lbl_804A6FF8)
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

    TLobby__sub_8013A16C();
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
    data_805D55B8 = 0;
    login_pending_flag = 1;
    lbl_805D55C0 = 0;
    lobby_login_result_flag = 0;
    player_setup_pending = 0;
    local_client_id = 0;
    designated_client_id = 0;
    memset(lbl_80509D3C, 0, 0x20);
    memset(lobby_player_names, 0, 0xC0);
    memset(lobby_player_status_records, 0, 0xD50);
    protocol = new TProtocol(this, 0x36, current_language, TLobby::init_serial_access(), (char *)get_access_key_input_buffer(), (char *)TAdEnterPasswordGC__sub_8013ADE4());
    protocol_instance = protocol;
    protocol->m_recv_handlers.handle_unused_login = (recv_packet_handler_handle_unused_login)TLobby::handle_regist_check;
    protocol_instance->m_recv_handlers.handle_03_recv_regist = (recv_packet_handler_handle_03_recv_regist)TLobby::handle_register_name_result;
    protocol_instance->m_recv_handlers.handle_04_recv_login = (recv_packet_handler_handle_04_recv_login)TLobby::handle_login_result;
    protocol_instance->m_recv_handlers.handle_05_recv_logout = TLobby::queue_static_object_destruction;
    protocol_instance->m_recv_handlers.handle_06_recv_chat = NULL;
    protocol_instance->m_recv_handlers.handle_01_recv_error = (recv_packet_handler_handle_01_recv_error)TLobby__sub_80137C10;
    protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    protocol_instance->m_recv_handlers.handle_08_recv_game_list = (recv_packet_handler_handle_08_recv_game_list)TLobby__sub_80136E68;
    protocol_instance->m_recv_handlers.handle_11_recv_message = (recv_packet_handler_handle_11_recv_message)TLobby__sub_80137228;
    protocol_instance->m_recv_handlers.handle_0E_recv_start_game = NULL;
    protocol_instance->m_recv_handlers.unused7 = NULL;
    protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = (recv_packet_handler_handle_64_recv_start_game3)TLobby::handle_game_join;
    protocol_instance->m_recv_handlers.unused8 = NULL;
    protocol_instance->m_recv_handlers.handle_67_recv_start_lobby2 = (recv_packet_handler_handle_67_recv_start_lobby2)TLobby::handle_lobby_enter;
    protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)TLobby::open_scroll_text_window;
    protocol_instance->m_recv_handlers.handle_80_recv_generate_id = (recv_packet_handler_handle_80_recv_generate_id)TLobby__sub_80135FFC;
    protocol_instance->m_recv_handlers.handle_65_recv_burst_game = TLobby::on_game_player_add;
    protocol_instance->m_recv_handlers.handle_66_recv_exit_game = (recv_packet_handler_handle_66_recv_exit_game)TLobby::remove_player;
    protocol_instance->m_recv_handlers.handle_68_recv_burst_lobby = TLobby::on_lobby_player_add;
    protocol_instance->m_recv_handlers.handle_69_recv_exit_lobby = TLobby::retire_lobby_player;
    protocol_instance->m_recv_handlers.handle_81_recv_chat_message = (recv_packet_handler_handle_81_recv_chat_message)try_close__6TLobbyFPv;
    protocol_instance->m_recv_handlers.handle_41_recv_user_ans = TLobby::handle_user_search_answer;
    protocol_instance->m_recv_handlers.handle_18_90_9A_recv_pso_regist_check = (recv_packet_handler_handle_18_90_9A_recv_pso_regist_check)TLobby::handle_verify_result;
    protocol_instance->m_recv_handlers.handle_92_9C_register_response_packet = (recv_packet_handler_handle_92_9C_register_response_packet)TLobby::handle_register_result;
    protocol_instance->m_recv_handlers.handle_95_request_character_data_packet = TLobby::send_selected_character;
    protocol_instance->m_recv_handlers.send_96_unused = TLobby::send_position_update;
    protocol_instance->m_recv_handlers.handle_97_checksum_reply_packet = (recv_packet_handler_handle_97_checksum_reply_packet)TLobby::handle_state;
    protocol_instance->m_recv_handlers.handle_B1_current_time_packet = TLobby::reset_lobby_state;
    protocol_instance->m_recv_handlers.handle_C0_choice_search_option_packet = TLobby::handle_choice_search_options;
    protocol_instance->m_recv_handlers.handle_C4_choice_search_reply_packet = TLobby::handle_choice_search_results;
    protocol_instance->m_recv_handlers.handle_A2_recv_quest_menu_list = copy_quest_list_data__16TQuestListOnlineFv;
    protocol_instance->m_recv_handlers.handle_A3_recv_quest_menu_info = TQuestListOnline::receive_quest_info;
    protocol_instance->m_recv_handlers.handle_44_recv_download_head = TQuestListOnline::begin_file_download;
    protocol_instance->m_recv_handlers.handle_13_recv_download = (recv_packet_handler_handle_13_recv_download)handle_quest_download_chunk__6TLobbyFv;
    protocol_instance->m_recv_handlers.handle_A4_recv_quest_list = (recv_packet_handler_handle_A4_recv_quest_list)TLobby::open_download_list_window;
    protocol_instance->m_recv_handlers.handle_A5_recv_quest_info = (recv_packet_handler_handle_A5_recv_quest_info)show_card_list_message;
    protocol_instance->m_recv_handlers.handle_A6_recv_vm_download_head = (recv_packet_handler_handle_A6_recv_vm_download_head)begin_file_download__22TQuestVmDownLoadServerFv;
    protocol_instance->m_recv_handlers.handle_A7_recv_vm_download = (recv_packet_handler_handle_A7_recv_vm_download)receive_file_chunk__22TQuestVmDownLoadServerFv;
    protocol_instance->m_recv_handlers.handle_B0_recv_emergency_call = (recv_packet_handler_handle_B0_recv_emergency_call)TLobby::disable_window_flags;
    protocol_instance->m_recv_handlers.handle_1F_recv_text_list = (recv_packet_handler_handle_1F_recv_text_list)TLobby::open_information_list;
    protocol_instance->m_recv_handlers.handle_88_player_arrow_color_list_packet = apply_lobby_markers__6TLobbyFv;
    protocol_instance->m_recv_handlers.handle_C5_player_challenge_data_packet = TLobby::copy_player_records;
    protocol_instance->m_recv_handlers.handle_D3_execute_trade_packet = handle_trade_received_items;
    protocol_instance->m_recv_handlers.handle_D4_trade_result_packet = (recv_packet_handler_handle_D4_trade_result_packet)TLobby::handle_reset_choice;
    protocol_instance->m_recv_handlers.handle_D1_advance_trade_state_packet = (recv_packet_handler_handle_D1_advance_trade_state_packet)TLobby::apply_trade_items;
    protocol_instance->m_recv_handlers.handle_D8_infoboard_packet = TLobby::handle_info_board;
    protocol_instance->m_recv_handlers.handle_DA_lobby_event_packet = TLobby::set_lobby_event_theme;
    protocol_instance->m_recv_handlers.handle_AB_quest_stats_response_packet = (recv_packet_handler_handle_AB_quest_stats_response_packet)TLobby__sub_80134A20;
    TLobby__data_805D4E30 = 0;
}
saddr TLobby::get_seq_phase(int id) { return get_online_message_text(id); }
void TLobby__sub_8013A16C(void) {  }
void lobby_debug_printf_stub(const char *fmt, ...) {}
void TLobby::construct_global_arrays() {
    __construct_array(join_entries, (void *)__ct__18TPlyJoinLobbyEntryFv, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43C, 0xC);
    __register_global_object(0, (void *)TLobby::destroy_join_entries, join_entries_dtor_registration);
    __construct_array(game_join_player_records, (void *)__ct__17TPlyJoinLobbyDataFv, 0, 0x20, 4);
}



TPlyJoinLobbyData::TPlyJoinLobbyData() {}
void TLobby::destroy_join_entries() {
    __destroy_arr(join_entries, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43c, 0xc);
}


TPlyJoinLobbyEntry::TPlyJoinLobbyEntry() {}
void TLobby__sub_8013A2DC(void) {  }
void TLobby::bswap_6x6E_sync_game_state(void*p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); }
s32 TLobby::open_hard_keyboard(void *p) { return TWindowKeyBoardHard::test_card_flag((saddr)p, 0x40000); }
void TLobby::bswap_player_data(void *data) {
    u8 *p = (u8 *)data;
    s32 i;
    bswap_16((u16 *)p);
    bswap_16((u16 *)(p + 2));
    bswap_32((u32 *)(p + 4));
    bswap_32((u32 *)(p + 8));
    bswap_32((u32 *)(p + 0xC));
    bswap_32((u32 *)(p + 0x10));
    bswap_32((u32 *)(p + 0x14));
    bswap_32((u32 *)(p + 0x18));
    bswap_32((u32 *)(p + 0x1C));
    bswap_16((u16 *)(p + 0x20));
    bswap_16((u16 *)(p + 0x22));
    bswap_16((u16 *)(p + 0x24));
    bswap_16((u16 *)(p + 0x26));
    for (i = 0; i < 5; i++) {
        ((TLobby *)(&((struct S_8013A348 *)p)->h[i]))->bswap_header_3words();
    }
    bswap_32((u32 *)(p + 0x64));
    ((TLobby *)(p + 0x68))->bswap_fields();
    TLobby__sub_8013A9C0((void *)(p + 0x70));
    bswap_telepipe_record((void *)(p + 0x78));
    bswap_32((u32 *)(p + 0x94));
    bswap_32((u32 *)(p + 0xAC));
    bswap_32((u32 *)(p + 0x488));
    bswap_32((u32 *)(p + 0xB0));
    bswap__15disp_data_part2Fv((saddr)(p + 0xC8));
    bswap__12player_statsFv((void *)(p + 0x118));
    TLobby::bswap_inventory((void*)(p + 0x13C));
}
void TLobby::bswap_inventory(void*p) { bswap_32((u32 *)p); { int i; for (i = 0; i < 30; i++) { ((TPlyInventoryItem *)((char*)p + 0x4 + i * 28))->bswap(); } } }
void TLobby::set_player_count(int a0) { lobby_player_count = a0; }


#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void bswap_and_send_extended_subcommand(void *p, u32 client_id) { bswap_extended_subcommand_header(p); ((long_game_command_union *)p)->send_to_client(client_id); }

void bswap_extended_subcommand_header(void* p) { TLobby::bswap_header_fields(p); }
void TLobby::bswap_header_fields(void *header) {
    bswap_16((u16 *)((u8 *)header + 2));
    bswap_32((u32 *)((u8 *)header + 4));
}
void TLobby::bswap_and_handle_packet(void *packet, int client_id) {
    bswap_client_id_header((G_ClientIDHeader *)packet);
    ((game_command *)packet)->send_to_client(client_id);
}
void TLobby__sub_8013A578(void* p) { *(u8*)((char*)p + 0x0) = 111; *(u8*)((char*)p + 0x1) = 129; }
void TLobby::send_packet_60(void *packet) {
    bswap_client_id_header((G_ClientIDHeader *)packet);
    send_subcommand(packet);
}
void init_6x72_resume_packet(void* p) { *(u8*)((char*)p + 0x0) = 114; *(u8*)((char*)p + 0x1) = 1; }
void *TLobby::copy_member_record(void *to, void *from) {
    Rec_8013A5D4 *dst = (Rec_8013A5D4 *)to;
    Rec_8013A5D4 *src = (Rec_8013A5D4 *)from;
    dst->f0 = src->f0;
    dst->f8 = src->f8;
    dst->fc = src->fc;
    dst->f10 = src->f10;
    dst->f18 = src->f18;
    copy_player_data__9TProtocolFPvPv(dst->f20, src->f20);
    return dst;
}

u8 *copy_player_data__9TProtocolFPvPv(u8 *dst, u8 *src) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r5;
    u8 *temp_r6;
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(u8 *)((s8 *)dst + 2) = (u8) *(u8 *)((s8 *)src + 2);
    *(u8 *)((s8 *)dst + 3) = (u8) *(u8 *)((s8 *)src + 3);
    *(ByteBlock_348 *)((saddr) dst + 4) = *(const ByteBlock_348 *)((saddr) src + 4);
    temp_r6 = (dst + 0x348);
    temp_r4 = (src + 0x348);
    *(ByteBlock_24 *)((saddr) temp_r6 + 4) = *(const ByteBlock_24 *)((saddr) temp_r4 + 4);
    *(ByteBlock_50 *)((dst + 0x36C) + 4) = *(const ByteBlock_50 *)((src + 0x36C) + 4);
    TObjPlayer__sub_8013A748(dst + 0x3C0, src + 0x3C0);
    temp_r5 = (dst + 0x404);
    temp_r4_2 = (src + 0x404);
    *(ByteBlock_14 *)((saddr) temp_r5 + 4) = *(const ByteBlock_14 *)((saddr) temp_r4_2 + 4);
    return dst;
}

void *TObjPlayer__sub_8013A748(void *dst, void *src) {
    TObjPlayer__sub_8013A788(dst, src);
    ((void (*)(void *, void *))TObjPlayer__sub_8013A788)((void *)((char *)dst + 36), (void *)((char *)src + 36));
    return dst;
}

void* TObjPlayer__sub_8013A788(void* p, void* a1) { *(void**)(p) = *(void**)((char*)a1 + 0x0); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x4)), (void *)((void*)((char*)a1 + 0x4))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x8)), (void *)((void*)((char*)a1 + 0x8))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0xc)), (void *)((void*)((char*)a1 + 0xc))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x10)), (void *)((void*)((char*)a1 + 0x10))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x14)), (void *)((void*)((char*)a1 + 0x14))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x18)), (void *)((void*)((char*)a1 + 0x18))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x1c)), (void *)((void*)((char*)a1 + 0x1c))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x20)), (void *)((void*)((char*)a1 + 0x20))); return p; }
void TObjPlayer__sub_8013A820(void *dst, void *src) {
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(s16 *)((s8 *)dst + 2) = (s16) *(s16 *)((s8 *)src + 2);
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

void TLobby::bswap_fields() { bswap_16((u16 *)((char*)this + 0x2)); bswap_32((u32 *)((char*)this + 0x4)); }

void TLobby::bswap_header_3words() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void bswap__15disp_data_part2Fv(saddr part2) {
    s32 off;
    s32 i;

    bswap_32((u32 *)(part2 + 0x18));
    bswap_32((u32 *)(part2 + 0x2C));
    bswap_32((u32 *)(part2 + 0x34));
    for (i = 0, off = 0; i < 8; i++, off += 2) {
        bswap_16((u16 *)((char *)part2 + off + 0x38));
    }
    bswap_32((u32 *)(part2 + 0x48));
    bswap_32((u32 *)(part2 + 0x4C));
}
}

void bswap_telepipe_record(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); bswap_32((u32 *)((char*)p + 0x10)); bswap_32((u32 *)((char*)p + 0x14)); bswap_32((u32 *)((char*)p + 0x18)); }

void TLobby__sub_8013A9C0(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); }

void bswap_object_source_record(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); }

void EnemyStateRecord::bswap() {
    bswap_32(reinterpret_cast<u32 *>(&flags));
    bswap_16(&drop_id);
    bswap_16(reinterpret_cast<u16 *>(&damage));
}
u8 *TLobby__sub_8013AA64(u8 *dst, u8 *src) {
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(dst, src);
    *(s32 *)((s8 *)dst + 8) = (s32) *(s32 *)((s8 *)src + 8);
    *(s32 *)((s8 *)dst + 0xC) = (s32) *(s32 *)((s8 *)src + 0xC);
    *(ByteBlock_10 *)((saddr) dst + 0x10) = *(const ByteBlock_10 *)((saddr) src + 0x10);
    fn_8013AAD4((dst + 0x20), (src + 0x20));
    return dst;
}

u8 *fn_8013AAD4(u8 *dst, u8 *src) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r5;
    u8 *temp_r6;
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(u8 *)((s8 *)dst + 2) = (u8) *(u8 *)((s8 *)src + 2);
    *(u8 *)((s8 *)dst + 3) = (u8) *(u8 *)((s8 *)src + 3);
    *(ByteBlock_348 *)((saddr) dst + 4) = *(const ByteBlock_348 *)((saddr) src + 4);
    temp_r6 = (dst + 0x348);
    temp_r4 = (src + 0x348);
    *(ByteBlock_24 *)((saddr) temp_r6 + 4) = *(const ByteBlock_24 *)((saddr) temp_r4 + 4);
    *(ByteBlock_50 *)((dst + 0x36C) + 4) = *(const ByteBlock_50 *)((src + 0x36C) + 4);
    ((TPlyGuildCardTag *)(dst + 0x3C0))->copy_full(src + 0x3C0);
    temp_r5 = (dst + 0x404);
    temp_r4_2 = (src + 0x404);
    *(ByteBlock_14 *)((saddr) temp_r5 + 4) = *(const ByteBlock_14 *)((saddr) temp_r4_2 + 4);
    return dst;
}

#pragma pop


void *TPlyGuildCardTag::copy_full(void *source) {
    copy(source);
    ((TPlyGuildCardTag *)((char *)this + 36))->copy((void *)((char *)source + 36));
    return this;
}
void*TPlyGuildCardTag::copy(void* a1) { *(void**)(this) = *(void**)((char*)a1 + 0x0); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x4), (void *)((char*)a1 + 0x4)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x8), (void *)((char*)a1 + 0x8)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0xc), (void *)((char*)a1 + 0xc)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x10), (void *)((char*)a1 + 0x10)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x14), (void *)((char*)a1 + 0x14)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x18), (void *)((char*)a1 + 0x18)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x1c), (void *)((char*)a1 + 0x1c)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x20), (void *)((char*)a1 + 0x20)); return this; }
void TPlyGuildCardTag__sub_8013ACA4(void *dst, void *src) {
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(s16 *)((s8 *)dst + 2) = (s16) *(s16 *)((s8 *)src + 2);
}
void __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *dst, void *src) {
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(u16 *)((s8 *)dst + 2) = (u16) *(u16 *)((s8 *)src + 2);
    *(s32 *)((s8 *)dst + 4) = (s32) *(s32 *)((s8 *)src + 4);
}
void fn_8013ACE4(int a0) { item_drop_server_seed = a0; }
void set_area_random_seed(int a0) { area_random_seed = a0; }

void TQuestListOnline__sub_8013ACF4(s32 arg0) {
    if (TQuestListOnline__instance != NULL) {
        TQuestListOnline__instance->set_state(arg0);
    }
}

void TWindowMenu::set_ready_flag() { m_70 |= 0x1; }

extern "C" {
extern u8 *text_language_group_table;

int TWindowMenuIconLine::is_decided() { return (this->state_flags >> 1) & 0x1; }
int TWindowMenuIconLine::is_cancelled() { return (this->state_flags >> 2) & 0x1; }
int TWindowMakeTeam::test_flag_1d_bit1() { return (m_1d >> 1) & 1; }
s32 TWindowMakeTeam::get_field_20() { return m_20; }
u8 TWindowMakeTeam::get_mode() { return m_1e; }
u8 TWindowMakeTeam::read_mode() { return m_1e; }
int TWindowMakeTeam::test_flag_1d_bit0() { return m_1d & 1; }

s32 *get_access_key_input_buffer(void) {
    return (s32 *)TAdEnterSerialAccessGC::access_key_input_buffer;
}

char *TLobby::init_serial_access() { return TAdEnterSerialAccessGC::hex_to_decimal_string((const char *)get_raw_serial_input_buffer()); }

s32 *get_raw_serial_input_buffer(void) {
    return (s32 *)TAdEnterSerialAccessGC::raw_serial_buffer;
}

saddr get_connection_message_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x30)) + (arg0 * 4));
}

}

extern u8 *text_language_group_table;
s32 get_online_message_text(s32 id) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x38)) + (id * 4));
}

s32 *TAdEnterPasswordGC__sub_8013ADE4(void) {
    return ((s32 *)&TAdEnterPasswordGC__input_buffer);
}

void *TProtocol::operator new(size_t size) { return obj_heap->heap_alloc(size); }

__declspec(section ".ctors") static void *const __sinit_TPlyJoinLobbyEntry_cpp_ref = (void *)TLobby::construct_global_arrays;

// Window positions copied by the message/menu openers above, and the lobby log and
// menu strings; defined after their users so each is addressed on its own.

__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDE8[1] = { { 342.0f, 144.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDF0[1] = { { 342.0f, 144.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDF8[1] = { { 558.0f, 224.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE00[1] = { { 224.0f, 188.0f } };

__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE08[1] = { { 224.0f, 188.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE10[1] = { { 558.0f, 224.0f } };

__declspec(section ".rodata") const Pair_80135E7C lbl_8043EE18[1] = { { 224.0f, 188.0f } };
__declspec(section ".rodata") const Pair_80135E7C lbl_8043EE20[1] = { { 332.0f, 200.0f } };
__declspec(section ".rodata") NJS_POINT2 lbl_8043EE28[1] = { { 342.0f, 144.0f } };
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
