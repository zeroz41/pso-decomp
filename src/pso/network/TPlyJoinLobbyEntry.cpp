#include "pso/unk/TLobby_800FD78C.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/player/TPlyInventory.h"
#include <stdio.h>
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/TPlyMeetUserExtension_801DAC6C.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_8013ADD0.h"
#include "pso/unk/TLobby_8001D6A0.h"

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
struct Stack_80135458 {
    s8 sp8;
    s8 sp9;
    s16 spA;
};
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
struct Base_80136000 { u8 pad[0x18]; };
struct Obj_80136000 : Base_80136000 { virtual ~Obj_80136000(); };
struct Row_80135208 { u8 pad[8]; union { u32 ip; u32 ip_addr; }; s32 client_id; char name[16]; };
struct Pkt_8013574C { u8 pad[4]; s32 len; u8 data[1]; };
struct Pkt_801357F8 { u8 pad[4]; s32 len; u8 data[1]; };
struct Pkt_801358B4 { u8 pad[4]; s32 len; u8 data[1]; };
struct S12_801358B4 { u32 a[3]; };
struct Base_801354AC { u8 pad[0x18]; };
struct Obj_801354AC : Base_801354AC { virtual ~Obj_801354AC(); };
struct Plr_801354AC : Base_801354AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual char *m10();
};
struct Disp_801354AC { u16 id; };
struct Pkt_801354AC { u8 pad[8]; Disp_801354AC disp; };
struct Pkt_801359C4 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135AE0 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135BD0 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Pkt_80135CD8 { u8 cmd; u8 flag; u16 f2; s32 len; u8 data[1]; };
struct Base_80136080 { u8 pad[0x18]; };
struct Obj_80136080 : Base_80136080 { virtual ~Obj_80136080(); };
struct Plr_80136080 : Base_80136080 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};
struct Entry_80136080 {
    u8 tag[8];
    u32 ip_addr;
    saddr client_id;
    char name[16];
    u8 char_data[0x420];
};
struct Base_80134F9C { u8 pad[0x18]; };
struct Obj_80134F9C : Base_80134F9C { virtual ~Obj_80134F9C(); };
struct DateStamp_80134F9C { s32 v[3]; };
struct Timer_80134F9C {
    u8 pad[0x1C];
    s32 now;
    s32 start;
    u32 limit;
    u8 state;
};
typedef char Row_TLobby__data_8050AAE8[16];
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
    u8 b[0x100];
    u16 h[7];
    u32 w0;
    u32 w1;
} D_80134E30;
LAYOUT_ASSERT(RecoveredGlobal_8013561C_lbl_805127F8_size, sizeof(RecoveredGlobal_8013561C_lbl_805127F8) == 0x200);
struct Base_801361E8 { u8 pad[0x18]; };
struct Obj_801361E8 : Base_801361E8 { virtual ~Obj_801361E8(); };
struct Node_801361E8 {
    u8 pad0[6];
    u16 id;
    u8 pad8[4];
    Node_801361E8 *next;
    u8 pad10[8];
    void *vt;
    u8 b1c, b1d, b1e, b1f;
};
struct Mgr_801361E8 { u8 pad[0x14]; Node_801361E8 *head; };
struct NodeB_801368B0;
struct Base_801368B0 { u8 pad[0x18]; };
struct Obj_801368B0 : Base_801368B0 { virtual ~Obj_801368B0(); };
struct Ent_801368B0 { u8 hdr[0xC]; s32 id; char name[0x10]; u8 rest[0x43C - 0x20]; };
struct Base_80136A8C { u8 pad[0x18]; };
struct Ply_80136A8C : Base_80136A8C {
    virtual ~Ply_80136A8C();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void m6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual char *m10();
};
struct Hdr_80136A8C {
    u8 pad0[0xAC];
    s32 fAC;
    u8 padB0[0x488 - 0xB0];
    s32 f488;
    u8 pad48C[4];
};
struct Base_80136C94 { u8 pad[0x18]; };
struct Obj_80136C94 : Base_80136C94 { virtual ~Obj_80136C94(); };
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
struct VBase_18_9029aa { char pad[0x18]; };
struct VObj_18_9029aa : VBase_18_9029aa {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual saddr m10();
};
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
    u8 b[0x100];
    u16 h[7];
    u32 w0;
    u32 w1;
} D_80137384;
struct RecoveredGlobal_80137B50___vt__6TLobby {
    s32 value;
    u8 remaining[0x14];
};
LAYOUT_ASSERT(RecoveredGlobal_80137B50___vt__6TLobby_size, sizeof(RecoveredGlobal_80137B50___vt__6TLobby) == 0x18);
struct Entry_80138B7C { u8 b[0x1C]; };
struct Card_80138B7C { u8 b[0x98]; };
struct Lobby_80138B7C { u8 pad[0x2C68]; Card_80138B7C cards[1]; };
struct GLE_80138D3C_80137188 { char pad[0x1c]; };
struct GBig_80138D3C_80137188 { char pad[0x1da8]; GLE_80138D3C_80137188 arr[1]; };
struct Pad_80139094 { u8 pad[0x10]; u32 flags; };
struct Pad_80139104 { u8 pad[0x10]; u32 flags; };
struct Ent_80139104 { u8 b[0x1C]; };
struct Lst_80139104 { u8 pad[0x1DA8]; Ent_80139104 e[1]; };
struct Pad_801391BC { u8 pad[0x10]; u32 flags; };
struct Ent_801391BC { u8 b[0x1C]; };
struct Lst_801391BC { u8 pad[0x1DA8]; Ent_801391BC e[1]; };
struct Ent_801392F8 { u8 b[0x1B]; u8 flags; };
struct Lst_801392F8 { u8 pad[0x1920]; s32 count; u8 pad2[0x1DA8 - 0x1924]; Ent_801392F8 e[1]; };
struct Pad_801392F8 { u8 pad[0x10]; u32 flags; };
struct GameListEntry_80139538_80137188 { char pad[0x1C]; };
struct Root_80139538_80137188 { char pad[0x1DA8]; struct GameListEntry_80139538_80137188 entries[1]; };
struct Pad_801395D8 { u8 pad[0x10]; u32 flags; };
struct Ent_801395D8 { u8 b[0x1C]; };
struct Lst_801395D8 { u8 pad[0x1DA8]; Ent_801395D8 e[1]; };
struct Flag_80139690 { u8 pad[0x2A]; s8 flag; };
struct Root_80139538_80137188;
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
void try_close__6TLobbyFPv();
void handle_quest_download_chunk__6TLobbyFv();
void apply_lobby_markers__6TLobbyFv();
void copy_player_records__6TLobbyFl();
void init_once__6TLobbyFPv();
void lobby_debug_printf_stub(const char *fmt, ...);
u8 * create_player_object(s32, s32, void *);
void TLobby__sub_8013AA64(void *, void *);
extern const char TLobby__data_8043EF38[];
extern const char lobby_debug_burst_player_format[];
extern const char lobby_debug_udp_close_player_format[];
extern s32 TLobby__designated_client_id;
extern saddr local_client_id;
s32 queue_destruction__7TObjectFv(void *);
extern const char lobby_window_title_information[];
s32 TLobby__sub_8013F810(void *, void *, s32, void *);
void handle_6x6E_sync_game_state(Pkt_8013566C *arg0);
void mark_area_change_pending();
u16 get_entity_id(void *);
void * get_current_floor();
void copy_challenge_info(void *, void *);
void TLobby__sub_80077798(void *, void *);
void handle_6x70_sync_player_disp_and_inventory(Pkt_801354AC *arg0);
void handle_6x6D_sync_game_state(Pkt_8013574C *arg0);
void handle_6x6C_sync_game_state(Pkt_801357F8 *arg0);
void handle_6x6B_sync_game_state(Pkt_801358B4 *arg0);
void fn_8013ACE4(s32);
void *mem_alloc(u32 size);
void import_sync_records__6TLobbyFPs(void *, u16);
void clear_enabled_main_warps();
s32 TLobby__sub_801A3E8C();
s32 fill_player_record__10TObjPlayerFPvPv(void *, void *);
s32 init_player_join_record(void *);
void send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(void *, void *, void *, void *, void *, void *, void *);
u8 * get_character_save_record(u32);
void * get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);
void * __nw__7TObjectFUl(u32);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 has_window_task_root();
extern u8 TLobby__data_805011D8[];
extern s32 TLobby__data_805D4E30;
extern u32 *quest_object_entries;
extern S12_801358B4 *TLobby__data_805D6144;
extern u32 TLobby__data_805D6148;
extern u32 TLobby__data_805D614C;
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
extern Mgr_801361E8 *game_protocol_instance;
extern s32 quest_download_active;
extern const char lobby_debug_duplicate_player_format[];
void __dt__13TUnk_804A7008Fv();
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
s32 TLobby__sub_80146740();
s32 increment_frame__23TAdSinglePlyChrSelectGCFv();
s32 get_player_count__23TAdSinglePlyChrSelectGCFv();
extern const char lobby_msg_registed[];
extern const char lobby_msg_name_taken[];
extern const char lobby_msg_regist_check_ok[];
extern const char lobby_msg_login_success[];
void send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(void *, void *, void *, void *, void *, void *, void *);
void construct_lobby_players(Rec_801378AC *records, s32 count, int self_id, s32 unused);
s32 __dt__7TObjectFv(void *, int);
extern void *__vt__6TLobby[6];
extern const NJS_POINT2 lbl_8043EE00[1];
void TQuestListOnline__sub_8013ACF4(s32);
s32 send_lobby_arrow__9TProtocolFUc(TProtocol *, s32);
s32 clear_lobby_flag__10TObjPlayerFPv();
extern s32 lbl_805DB0B4;
extern s8 controller_input_state[];
s32 reset_controller_input_state();
void *__ct__16TPlyGuildCardTagFv(void *self);
void set_queued_main_phase(s32);
void request_main_phase(s32);
extern const char lobby_window_title_block_jump[];
extern const char lobby_window_title_ship_jump[];
s32 *get_access_key_input_buffer(void);
saddr get_connection_message_text(int);
const char *TWindowMakeTeam__sub_80264B24(TWindowMakeTeam *window);
const char *TWindowMakeTeam__sub_80264B38(TWindowMakeTeam *window);
extern const NJS_POINT2 lbl_8043EDF8[1];
extern const NJS_POINT2 lbl_8043EDF0[1];
extern const f32 lbl_805DB0B8;
extern const NJS_POINT2 lbl_8043EDE8[1];
extern const char lobby_window_title_taisen_team[];
void func_80019A68__Fv(void);
s32 get_link_status__Fv(void);
s32 poll_memcard_result(saddr);
s32 TKeyBoardControl__sub_8000F828(void);
s8 TAdSinglePlyChrSelectGC__sub_8033605C(void);
void render__6TLobbyFv();
TProtocol *__ct__9TProtocolFP7TObjectUsiPcPcPc(TProtocol *, void *, s32, s32, char *, char *, char *);
void TLobby__sub_80134A20();
void set_lobby_event_theme();
void TLobby__sub_80134DC8();
void TLobby__sub_80134DE8();
void show_card_list_message(void *msg);
void TLobby__sub_80136E68(s32 count, Ent_80136E68 *entries, Ent_80136E68 *selected);
void receive_file_chunk__22TQuestVmDownLoadServerFv();
void begin_file_download__22TQuestVmDownLoadServerFv();
void handle_trade_received_items();
void __register_global_object(int, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __destroy_arr(void *arr, void *dtor, u32 size, u32 count);
void bswap__15disp_data_part2Fv(void *);
void TLobby__sub_8013A9C0(void *);
int __ct__12TPlyCharDataFv(void*);
extern int lobby_player_count;
extern int item_drop_server_seed;
extern int area_random_seed;
}
void activate_keyboard();
void restore_switch_table(saddr arg0, s32 arg1);
void set_world_section_id(void *, s32);
void bswap_object_source_record(void *);
void set_area_random_seed(int a0);
void *create_remote_player_object(void *arg0);
void set_floor_map_variant(s32 arg0, s32 arg1);
s32 request_story_select_state(s32 arg0);
u32 copy_switch_table(void *destination);
void send_register_9c(u8 *arg0);
void buffer_reset(void);
void bswap_telepipe_record(void *);


TProtocol *TLobby__protocol_instance;
s32 TLobby__lobby_entered_flag;
s32 TLobby__data_805D5588;
s16 TLobby__data_805D558C;
s16 TLobby__pending_member_count;
s32 TLobby__deferred_player_setup_state;
s32 TLobby__data_805D5594;
s32 TLobby__join_state_flag;
s32 TLobby__date_seconds;
s32 TLobby__event_theme_id;
s32 TLobby__card_list_selected_index;
s32 TLobby__idle_timeout_active;
s32 TLobby__data_805D55AC;
s32 TLobby__lobby_number;
s32 TLobby__join_lobby_idle_timer;
s32 TLobby__data_805D55B8;
s32 TLobby__login_pending_flag;
s32 lbl_805D55C0;
s32 lobby_login_result_flag;
void *TLobby__card_list_window;
void *TLobby__download_list_window;
void *TLobby__list_window;
TObject *lobby_player_construction_window;
uaddr TLobby__current_dialog_window;
uaddr TLobby__join_entry_window_obj;
TWindowMenu *TLobby_warp_menu_window;
TWindowMenu *lobby_com_card_window;
TWindowMenu *lobby_make_team_menu_window;
TWindowMakeTeam *lobby_make_team_window;
TWindowMenu *lobby_keyboard_prompt_window;
TKeyBoardControl *lobby_keyboard_controller;
TAdScrollWinGC *lobby_scroll_text_window;
s32 TLobby__player_setup_pending;
s32 lobby_selected_game_list_index;
TLobby *TLobby__join_lobby_controller;
s32 TLobby__idle_timeout_object;

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

u32 TLobby__join_entries_dtor_registration[3];
u32 TLobby__data_80506A6C[3252];
u32 lbl_80509D3C[8];
u32 lobby_player_status_records[852];
char TLobby__data_8050AAAC[0x28];
u32 lbl_8050AAD4[5];
Row_TLobby__data_8050AAE8 TLobby__player_names[12];
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
    a.kb = TLobby::open_hard_keyboard((void *)local_client_id) != 0 ? 1 : 0;
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
    copy_challenge_info(d.b, card + 0x21C4);
    d.h[0] = *(u16 *)(card + 0x21A8);
    d.h[1] = *(u16 *)(card + 0x21AA);
    d.h[2] = *(u16 *)(card + 0x21AC);
    d.h[3] = *(u16 *)(card + 0x21AE);
    d.h[4] = *(u16 *)(card + 0x21B0);
    d.h[5] = *(u16 *)(card + 0x21B2);
    d.h[6] = *(u16 *)(card + 0x21B4);
    d.w0 = *(u32 *)(card + 0x21B8);
    d.w1 = *(u32 *)(card + 0x21BC);
    send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(TLobby__protocol_instance, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), &d, &a, b, e, c);
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
        (*(Obj_80134F9C * *)&TLobby__idle_timeout_object) = 0;
    }
    if (hardware_keyboard_state.has_any_key_pressed() != 0 || TKeyBoardControl::any_pad_input_active() != 0) {
        t->start = t->now;
        t->state = 0;
        if ((*(Obj_80134F9C * *)&TLobby__idle_timeout_object) != 0) {
            delete (*(Obj_80134F9C * *)&TLobby__idle_timeout_object);
            (*(Obj_80134F9C * *)&TLobby__idle_timeout_object) = 0;
        }
    }
    t->limit = ((TLobby *)local_client_id)->get_table_entry_by_index();
    elapsed = t->now - t->start;
    switch (t->state) {
    case 0:
        if (t->limit != 0 && elapsed + 0x1E > t->limit) {
            t->state = 1;
            if ((*(Obj_80134F9C * *)&TLobby__idle_timeout_object) == 0 && has_window_task_root() != 0) {
                sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), t->limit - elapsed);
                (*(Obj_80134F9C * *)&TLobby__idle_timeout_object) = (Obj_80134F9C *)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xCA)), (const f32 *)(&tmp), 1);
                ((TWindowMessage *)(*(Obj_80134F9C * *)&TLobby__idle_timeout_object))->append_line((saddr)lobby_idle_timeout_text_buffer, (int)0x80);
                ((TWindowBase *)(*(Obj_80134F9C * *)&TLobby__idle_timeout_object))->set_depth(30000.0f);
                ((TWindowMessage *)(*(Obj_80134F9C * *)&TLobby__idle_timeout_object))->complete_reveal();
            }
        }
        break;
    case 1:
        limit = t->limit;
        if (elapsed > limit) {
            delete (*(Obj_80134F9C * *)&TLobby__idle_timeout_object);
            (*(Obj_80134F9C * *)&TLobby__idle_timeout_object) = 0;
            TLobby__idle_timeout_active = 1;
            queue_destruction__7TObjectFv(object);
        } else {
            sprintf(lobby_idle_timeout_text_buffer, (const char *)TLobby::get_seq_phase(0x1F), limit - elapsed);
        }
        break;
    }
}

u8 *init_idle_timeout_timer(u8 *arg0, saddr parent) {
    s32 sp8;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)parent);
    *(void ***)((s8 *)arg0 + 0x18) = lbl_804A7008;
    getDateStamp((DateStamp *)(&sp8));
    DateToSeconds((DateStamp *)(&sp8), (int *)(arg0 + 0x1C));
    ((TUnk_804A7008 *)arg0)->m_20 = (s32) *(s32 *)((s8 *)arg0 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x24) = ((TLobby *)local_client_id)->get_table_entry_by_index();
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
        p = create_player_object(local_client_id, 0, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        ((TLobby *)(p + 0xDAC))->copy_header_struct((u8 *)TLobby__protocol_instance + 0x1900);
        ((VObj_18_9029aa *)p)->m6();
        {
            saddr nm = (saddr)TLobby__player_names;
            strncpy((char *)(nm + local_client_id * 16), (const char *)((VObj_18_9029aa *)p)->m10(), 0x10);
        }
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        pend = (s32 *)game_join_pending_clients;
        for (i = 0; i < 4; i++) {
            if (pend[i] != 0) {
                TLobby::send_6x70_player_data(i);
                if (get_player_by_client_id(i) == NULL) {
                    e = (LEntry_801352C0 *)TLobby__data_80506A6C;
                    e += i;
                    p = create_player_object(i, 4, e->body);
                    ((TLobby *)(p + 0xDAC))->copy_header_struct(e);
                    ((VObj_18_9029aa *)p)->m6();
                    TLobby::open_udp_socket_for_player(i);
                    lobby_debug_printf_stub(lobby_debug_burst_player_format, i);
                } else {
                    lobby_debug_printf_stub(lobby_debug_duplicate_player_format, i);
                }
            }
            pend[i] = 0;
        }
        ((TLobby *)TLobby__protocol_instance)->send_6F_burst_done();
        TAdSinglePlyChrSelectGC::load_character_from_card(0);
        TLobby__data_805D5594 = 0xF;
    }
}

void TLobby::send_6x71_to_player() {
    saddr arg0 = (saddr)this;
    Stack_80135458 stack;
    stack.sp8 = 0x71;
    stack.sp9 = 1;
    stack.spA = 0;
    bswap_client_id_header((G_ClientIDHeader *)&stack.sp8);
    ((TLobby *)(&stack.sp8))->send_subcommand_to_client(arg0);
}

void handle_6x70_sync_player_disp_and_inventory(Pkt_801354AC *arg0) {
    Plr_801354AC *plr;
    Disp_801354AC *disp;
    Obj_801354AC *p;
    if (TLobby__data_805D5CE8 == 0 && (TLobby__data_805D5594 == 0xE || TLobby__data_805D5594 == 0xF)) {
        disp = &arg0->disp;
        TLobby::bswap_player_data(disp);
        if (disp->id != local_client_id) {
            p = (Obj_801354AC *)get_player_by_client_id(disp->id);
            if (p != NULL) {
                delete p;
            }
            plr = (Plr_801354AC *)create_remote_player_object(disp);
            strncpy(TLobby__player_names[get_entity_id(plr)], plr->m10(), 0x10);
            TLobby::open_udp_socket_for_player(disp->id);
            lobby_debug_printf_stub(lobby_debug_create_player_format, get_entity_id(plr));
        }
    }
}
void TLobby::send_6x70_player_data(int arg0) {
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
        bswap_and_send_extended_subcommand(temp_r3, arg0);
        mem_free(temp_r3);
    }
}

#pragma push
#pragma peephole off
void handle_6x6F_set_quest_flags_v2(saddr arg0) {
    if (((s16) TLobby__data_805D5CE8 == 0) && (((s32) TLobby__data_805D5594 == 0xE) || ((s32) TLobby__data_805D5594 == 0xF))) {
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
  if ((TLobby__data_805D5CE8 == 0) && ((TLobby__data_805D5594 == 0xE) || (TLobby__data_805D5594 == 0xF)))
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
    if (TLobby__data_805D5CE8 == 0 && (TLobby__data_805D5594 == 0xE || TLobby__data_805D5594 == 0xF)) {
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
    u32 *p;
    s32 n;
    s32 i;
    if (TLobby__data_805D5CE8 == 0 && (TLobby__data_805D5594 == 0xE || TLobby__data_805D5594 == 0xF)) {
        n = arg0->len - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_object_condition_format, arg0->len);
        p = (u32 *)::operator new(0x7230);
        if (p != NULL) {
            r = ((u32)TLobby__sub_8013F810(p, arg0->data, n, quest_object_entries));
            ::operator delete(p);
            n = r >> 2;
            p = quest_object_entries;
            TLobby__data_805D6148 = n;
            for (i = 0; i < n; i++) {
                bswap_object_source_record(&p[i]);
            }
        }
    }
}

void handle_6x6B_sync_game_state(Pkt_801358B4 *arg0) {
    u32 r;
    S12_801358B4 *p;
    s32 n;
    s32 i;
    if (TLobby__data_805D5CE8 == 0 && (TLobby__data_805D5594 == 0xE || TLobby__data_805D5594 == 0xF)) {
        n = arg0->len - 8;
        lobby_debug_printf_stub(lobby_debug_rcv_enemy_condition_format, arg0->len);
        p = (S12_801358B4 *)::operator new(0x7230);
        if (p != NULL) {
            r = ((u32)TLobby__sub_8013F810(p, arg0->data, n, TLobby__data_805D6144));
            ::operator delete(p);
            n = r / 12;
            p = TLobby__data_805D6144;
            TLobby__data_805D614C = n;
            for (i = 0; i < n; i++) {
                ((TLobby *)(&p[i]))->bswap_6x6B();
            }
        }
    }
}

void send_6x6F_quest_flags(saddr arg0) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80135974, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80135974, spC) == 0x4);
    Stack_80135974 stack;
    TLobby__sub_8013A578(&stack.sp8);
    memcpy(&stack.spC, &quest_story_flags_by_difficulty.value, 0x200);
    TLobby::bswap_and_handle_packet(&stack.sp8, arg0);
}
void TLobby::send_6x6E_sync_game_state(int arg0) {
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
        bswap_and_send_extended_subcommand(buf, arg0);
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
    u32 *src;
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
            size = TLobby__data_805D6148 * 4;
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
    S12_801358B4 *src;
    s32 len;
    u32 size;
    Pkt_80135CD8 *buf;
    void *tmp;
    u32 n;
    S12_801358B4 *p;
    u32 i;
    saddr arg0 = (saddr)this;
    buf = (Pkt_80135CD8 *)mem_alloc(0x8000);
    if (buf != NULL) {
        memset(buf, 0, 0x8000);
        tmp = ::operator new(0x7230);
        if (tmp != NULL) {
            src = TLobby__data_805D6144;
            size = TLobby__data_805D614C * sizeof(S12_801358B4);
            n = size / sizeof(S12_801358B4);
            p = (S12_801358B4 *)mem_alloc((s32)(n * sizeof(S12_801358B4)));
            memcpy(p, src, size);
            for (i = 0; i < n; i++) {
                ((TLobby *)(&p[i]))->bswap_6x6B();
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
    if (TLobby__card_list_window != 0) {
        ((TWindowBase *)TLobby__card_list_window)->close();
        TLobby__card_list_window = 0;
    }
    if (TLobby__data_805D5594 == 0x11) {
        Pair_80135E7C p = lbl_8043EE20[0];
        TLobby__card_list_window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xC9)), (const f32 *)(&p), 1);
        ((TWindowMessage *)TLobby__card_list_window)->append_line((saddr)((char *)msg + 4), (int)3);
        ((TWindowBase *)TLobby__card_list_window)->set_depth(37000.0f);
    }
}

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma pop

#pragma push

#pragma pop

#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#define CALL_80139690(f) ((void (*)(void *))f)(self)

#pragma pop

#pragma defer_codegen on
void TLobby::show_seq_phase_message(int id) {
    if ((*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) == 0) {
        NJS_POINT2 tmp = lbl_8043EDE8[0];
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = (uaddr)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->set_depth(lbl_805DB0B8);
    }
    ((TWindowMessage *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->append_line((int)(TLobby::get_seq_phase(id)), (int)1);
}

void show_dialog_value_line(saddr arg0) {
    if ((*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) == 0) {
        NJS_POINT2 tmp = lbl_8043EDF0[0];
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = (uaddr)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc1), &tmp);
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->set_depth(lbl_805DB0B8);
    }
    ((TWindowMessage *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->append_line((int)arg0, (int)1);
}
void TLobby::close_com_card_window() {
    if ((u32) (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) != 0U) {
        ((TWindowBase *)((void*)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window)))))->close();
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = 0U;
    }
}

void show_join_entry_message(s32 arg0) {
    if (TLobby__join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EDF8[0];
        TLobby__join_entry_window_obj = (uaddr)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc2), &tmp);
    }
    ((TWindowMessage *)TLobby__join_entry_window_obj)->append_line((int)(TLobby::get_seq_phase(arg0)), (int)1);
}

void run_task__6TLobbyFv(void *self) {
    s32 r;
    switch ((*(u32 *)&TLobby__data_805D5594)) {
    case 1:
        CALL_80139690(TLobby::handle_team_select);
        break;
    case 2:
        CALL_80139690(TLobby::handle_team_select);
        break;
    case 3:
        CALL_80139690(TLobby::handle_warp_menu_input);
        break;
    case 4:
        CALL_80139690(TLobby::update_menu_window);
        break;
    case 6:
        CALL_80139690(TLobby::update_game_list_menu);
        break;
    case 9:
        CALL_80139690(TLobby::handle_comcard_window);
        break;
    case 10:
        CALL_80139690(TLobby::handle_create_game_window);
        break;
    case 5:
        CALL_80139690(TLobby::handle_com_card);
        break;
    case 7:
        CALL_80139690(TLobby::update_ship_select_window);
        break;
    case 8:
        CALL_80139690(TLobby::update_block_jump_list);
        break;
    case 12:
        CALL_80139690(queue_join_entry_exit_on_input);
        return;
    case 13:
        CALL_80139690((void (*)())TLobby::update);
        break;
    case 17:
        CALL_80139690(TLobby::update_card_list_window);
        break;
    case 20:
        CALL_80139690(TLobby::update_short_list);
        break;
    case 22:
        CALL_80139690(TLobby::handle_short_list_input);
        break;
    case 21:
        CALL_80139690(TLobby::handle_game_list_select);
        break;
    case 24:
        CALL_80139690(TLobby::update_make_team_menu);
        break;
    case 26:
        CALL_80139690(TLobby::update_scroll_close);
        break;
    case 25:
        CALL_80139690(TLobby::update_com_card_window);
        break;
    case 23:
        return;
    }
    if (quest_download_active != 0) {
        func_80019A68__Fv();
    }
    r = TLobby::query_task_active();
    if (((Flag_80139690 *)(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))->flag != 0 || get_link_status__Fv() == 0 || r < 0) {
        Flag_80139690 *d = (Flag_80139690 *)(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)));
        d->flag = 0;
        TQuestListOnline::close_windows_and_reset();
        if (r < 0) {
            TLobby::update_state();
            return;
        }
        while (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) == -1) {
        }
        ((void (*)(void))TLobby__sub_801384E4)();
    }
}
void TLobby::handle_team_select() {
    s32 idx;
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((void *)((*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))))))->send_action(*(GameListEntry *)((void *)(&(*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))->e[idx])), (char *)((s32 *)lobby_window_title_taisen_team), (char *)((s32 *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0)))));
            ((s32 (*)())TLobby::close_and_set_state_12)();
            return;
        }
        if ((*(Pad_801395D8 **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))->e[idx]));
        }
    }
}
void TLobby::handle_game_list_select() {
    s32 temp_r31;

    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            temp_r31 = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))))->send_action(*(GameListEntry *)(&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))->entries[temp_r31]), (char *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0))), (char *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0))));
            ((s32 (*)())TLobby::close_and_set_state_12)();
            return;
        }
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_cancelled() != 0) {
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
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
                ((s32 (*)())TLobby::create_warp_menu)();
                return;
            case 1:
                ((s32 (*)())TLobby::open_warp_menu)();
                return;
            case 2:
                ((s32 (*)())TLobby::close_and_send_text_list)();
                return;
            case 3:
                ((s32 (*)())TLobby::open_city_warp_menu)();
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
                ((s32 (*)())TLobby::request_game_list)();
                return;
            case 1:
                ((s32 (*)())TLobby::open_menu_window)();
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
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            lobby_selected_game_list_index = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            if ((*(Lst_801392F8 **)&TLobby__protocol_instance)->e[lobby_selected_game_list_index].flags & 2) {
                ((s32 (*)())TLobby::open_keyboard_window)();
                return;
            }
            ((TProtocol *)((*(Lst_801392F8 **)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)(&(*(Lst_801392F8 **)&TLobby__protocol_instance)->e[lobby_selected_game_list_index]), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            ((s32 (*)())TLobby::destroy_lobby_ui)();
            return;
        }
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_cancelled() != 0) {
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            TLobby::close_all_windows();
            return;
        }
        if ((*(Pad_801392F8 **)controller_input_state)->flags & 0x400) {
            lobby_selected_game_list_index = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            if (lobby_selected_game_list_index < (*(Lst_801392F8 **)&TLobby__protocol_instance)->count) {
                ((TProtocol *)((*(Lst_801392F8 **)&TLobby__protocol_instance)))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801392F8 **)&TLobby__protocol_instance)->e[lobby_selected_game_list_index]));
            }
        }
    }
}
void TLobby::handle_com_card() {
    s32 temp_r3;

    if (lobby_com_card_window != NULL) {
        if (lobby_com_card_window->is_decided() != 0) {
            ((s32 (*)())TLobby::close_com_card_window)();
            temp_r3 = lobby_com_card_window->get_selected_value();
            switch (temp_r3) {
            case 0:
                ((s32 (*)())TLobby::return_to_main_menu)();
                return;
            case 1:
                ((s32 (*)())TLobby::close_menu_windows)();
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
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(Lst_801391BC * *)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)(&(*(Lst_801391BC * *)&TLobby__protocol_instance)->e[idx]), (char *)(lobby_window_title_ship_jump), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            TLobby::close_and_set_state_12();
            return;
        }
        if ((*(Pad_801391BC **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_801391BC * *)&TLobby__protocol_instance)))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801391BC * *)&TLobby__protocol_instance)->e[idx]));
        }
    }
}
void TLobby::update_block_jump_list() {
    s32 idx;
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(Lst_80139104 * *)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)(&(*(Lst_80139104 * *)&TLobby__protocol_instance)->e[idx]), (char *)(lobby_window_title_block_jump), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            TLobby::close_and_set_state_12();
            return;
        }
        if ((*(Pad_80139104 **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_80139104 * *)&TLobby__protocol_instance)))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_80139104 * *)&TLobby__protocol_instance)->e[idx]));
        }
    }
}

void queue_join_entry_exit_on_input(void *self) {
    if (((*(Pad_80139094 **)controller_input_state)->flags & 8) || TLobby__join_lobby_idle_timer++ > 0xe10) {
        TAdSinglePlyChrSelectGC::init();
        set_queued_main_phase(2);
        request_main_phase(0x12);
        ((void (*)(void *))queue_destruction__7TObjectFv)(self);
    }
}
void TLobby::update() {
    if ((u32) TLobby__join_entry_window_obj != 0U) {
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 8) != 0) {
            if (((TWindowMessagePage *)TLobby__join_entry_window_obj)->is_message_window_ready() == 0) {
                ((TWindowMessage *)TLobby__join_entry_window_obj)->complete_reveal();
            } else {
                ((TWindowBase *)TLobby__join_entry_window_obj)->close();
                TLobby__join_entry_window_obj = 0U;
                TLobby::close_all_windows();
                ((TProtocol *)(TLobby__protocol_instance))->send_server_time_accepted();
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
    u8 temp_r29;
    u8 temp_r28;
    u8 temp_r27;
    u8 temp_r0;

    if (lobby_make_team_window != NULL) {
        if (lobby_make_team_window->test_flag_1d_bit0() != 0) {
            name = TWindowMakeTeam__sub_80264B38(lobby_make_team_window);
            if (name != NULL) {
                password = TWindowMakeTeam__sub_80264B24(lobby_make_team_window);
                temp_r29 = (s8)lobby_make_team_window->read_mode() == 2;
                temp_r28 = lobby_make_team_window->is_enabled();
                temp_r27 = (s8)lobby_make_team_window->get_mode() == 1;
                temp_r0 = get_field_20__15TWindowMakeTeamFv(lobby_make_team_window);
                TLobby__protocol_instance->send_create_game((char *)name, (char *)password, temp_r28, temp_r29, temp_r27, temp_r0);
                ((s32 (*)())TLobby::destroy_lobby_ui)();
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
                ((void (*)(s32))TLobby::show_seq_phase_message)(0x11);
                break;
            case 1:
                ((void (*)(s32))TLobby::show_seq_phase_message)(0x12);
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
            ((TProtocol *)((*(GBig_80138D3C_80137188 * *)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)(&(*(GBig_80138D3C_80137188 * *)&TLobby__protocol_instance)->arr[lobby_selected_game_list_index]), (char *)(&(*(s32 *)&TLobby__data_805DB0B0)), text);
            mem_free(text);
            lobby_keyboard_controller->queue_destruction();
            lobby_keyboard_controller = NULL;
            lobby_keyboard_prompt_window->close();
            lobby_keyboard_prompt_window = NULL;
            ((s32 (*)())TLobby::destroy_lobby_ui)();
        }
    }
}

void *__ct__13GameListEntryFv(void *entry) {
    __ct__16TPlyGuildCardTagFv(entry);
    return entry;
}
void TLobby::update_card_list_window() {
    s32 sel;
    u32 btn;
    if (TLobby__list_window == 0) {
        return;
    }
    if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
        Entry_80138B7C e;
        sel = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
        ((TWindowBase *)TLobby__list_window)->close();
        TLobby__list_window = 0;
        __ct__13GameListEntryFv(&e);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e, &((Lobby_80138B7C *)TLobby__protocol_instance)->cards[sel]);
        TLobby__protocol_instance->send_action(*(GameListEntry *)&e, (char *)TLobby__data_805DB0B0, (char *)TLobby__data_805DB0B0);
        if (TLobby__card_list_window != 0) {
            ((TWindowBase *)TLobby__card_list_window)->close();
            TLobby__card_list_window = 0;
        }
        TLobby::close_all_windows();
        return;
    }
    if (TLobby__download_list_window != 0) {
        sel = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
        if (sel != TLobby__card_list_selected_index) {
            ((TWindowMessage *)TLobby__download_list_window)->append_line((saddr)(&((Lobby_80138B7C *)TLobby__protocol_instance)->cards[sel].b[0x28]), (int)3);
            ((TWindowMessage *)TLobby__download_list_window)->complete_reveal();
            if (TLobby__card_list_window != 0) {
                ((TWindowBase *)TLobby__card_list_window)->close();
                TLobby__card_list_window = 0;
            }
            TLobby__card_list_selected_index = sel;
            return;
        }
    }
    btn = (*(u32 **)controller_input_state)[4];
    if (btn & 0x400) {
        Entry_80138B7C e2;
        sel = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
        __ct__13GameListEntryFv(&e2);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e2, &((Lobby_80138B7C *)TLobby__protocol_instance)->cards[sel]);
        TLobby__protocol_instance->send_info(*(TPlyGuildCardTag *)&e2);
    } else if (btn & 2) {
        if (TLobby__card_list_window != 0) {
            ((TWindowBase *)TLobby__card_list_window)->close();
            TLobby__card_list_window = 0;
        } else {
            TLobby::return_to_main_menu();
        }
    }
}
void TLobby::update_short_list() {
    void *context;

    if (TLobby__download_list_window != NULL) {
        context = controller_input_state + 0x20;
        if (TWindowShortListCtrl__check_controller_button(context, 4) != 0) {
            if (((TWindowMessagePage *)TLobby__download_list_window)->is_message_window_ready() == 0) {
                ((TWindowMessage *)TLobby__download_list_window)->complete_reveal();
            } else {
                ((TWindowBase *)TLobby__download_list_window)->close();
                TLobby__download_list_window = 0U;
                TLobby::close_all_windows();
            }
        } else if (TWindowShortListCtrl__check_controller_button(context, 2) != 0) {
            ((TWindowBase *)TLobby__download_list_window)->close();
            TLobby__download_list_window = 0U;
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}
void TLobby::handle_short_list_input() {
    void *context;

    if ((u32) TLobby__join_entry_window_obj != 0U) {
        context = controller_input_state + 0x20;
        if (TWindowShortListCtrl__check_controller_button(context, 4) != 0) {
            if (((TWindowMessagePage *)TLobby__join_entry_window_obj)->is_message_window_ready() == 0) {
                ((TWindowMessage *)TLobby__join_entry_window_obj)->complete_reveal();
            } else {
                ((TWindowBase *)TLobby__join_entry_window_obj)->close();
                TLobby__join_entry_window_obj = 0U;
                TLobby::close_all_windows();
            }
        } else if (TWindowShortListCtrl__check_controller_button(context, 2) != 0) {
            ((TWindowBase *)TLobby__join_entry_window_obj)->close();
            TLobby__join_entry_window_obj = 0U;
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}
void TLobby::update_scroll_close() {
    if (lobby_scroll_text_window != NULL) {
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 0xE) != 0) {
            lobby_scroll_text_window->close();
            lobby_scroll_text_window = NULL;
            ((s32 (*)())TLobby::destroy_lobby_ui)();
            reset_controller_input_state();
            ((TProtocol *)(TLobby__protocol_instance))->send_message_box_closed();
        }
    } else {
        TLobby::close_all_windows();
    }
}
void TLobby::close_all_windows() {
    if (TLobby__card_list_window != NULL) {
        ((TWindowBase *)TLobby__card_list_window)->close();
        TLobby__card_list_window = 0U;
    }
    if (TLobby__download_list_window != NULL) {
        ((TWindowBase *)TLobby__download_list_window)->close();
        TLobby__download_list_window = 0U;
    }
    if (TLobby__list_window != NULL) {
        ((TWindowBase *)TLobby__list_window)->close();
        TLobby__list_window = 0U;
    }
    if ((u32) (*(u32 *)&(*(u32 *)&TLobby__current_dialog_window)) != 0U) {
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&TLobby__current_dialog_window)))->close();
        (*(u32 *)&(*(u32 *)&TLobby__current_dialog_window)) = 0U;
    }
    if ((u32) TLobby__join_entry_window_obj != 0U) {
        ((TWindowBase *)TLobby__join_entry_window_obj)->close();
        TLobby__join_entry_window_obj = 0U;
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
    ((s32 (*)())TLobby::update_player_window)();
    TLobby__data_805D5594 = 0;
}
void TLobby::destroy_lobby_ui() {
    void *temp;
    temp = (void*)(uaddr)TLobby__card_list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby__card_list_window = 0U;
    }
    temp = (void*)(uaddr)TLobby__download_list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby__download_list_window = 0U;
    }
    temp = (void*)(uaddr)TLobby__list_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby__list_window = 0U;
    }
    temp = (void*)(uaddr)(*(uaddr *)&TLobby__current_dialog_window);
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        (*(u32 *)&TLobby__current_dialog_window) = 0U;
    }
    temp = (void*)(uaddr)TLobby__join_entry_window_obj;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby__join_entry_window_obj = 0U;
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
    TLobby__data_805D5594 = 0xE;
}
void TLobby::set_menu_mode_0() {
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(0);
    TLobby__data_805D5594 = 1;
}
void TLobby::set_menu_mode_1() {
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(1);
    TLobby__data_805D5594 = 1;
}
void TLobby::set_menu_mode_2() {
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(2);
    TLobby__data_805D5594 = 0x15;
}
void TLobby::open_lobby_warp_menu() {
    s32 window_layout_position;
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(3);
    window_layout_position = (saddr)get_window_layout_position(0xB4);
    if ((s32) TLobby__lobby_number < 0xD) {
        TLobby_warp_menu_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
        TObjCityMainWarp::forward_trade_action_default(TLobby_warp_menu_window, TLobby::get_seq_phase(0x35), 6, 0);
        TObjCityMainWarp::forward_trade_action_default(TLobby_warp_menu_window, TLobby::get_seq_phase(0x36), 6, 1);
    } else {
        TLobby_warp_menu_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 3);
        TObjCityMainWarp::forward_trade_action_default(TLobby_warp_menu_window, TLobby::get_seq_phase(0x35), 6, 0);
        TObjCityMainWarp::forward_trade_action_default(TLobby_warp_menu_window, TLobby::get_seq_phase(0x36), 6, 1);
        TObjCityMainWarp::forward_trade_action_default(TLobby_warp_menu_window, TLobby::get_seq_phase(0x47), 6, 3);
    }
    TLobby_warp_menu_window->calc_window_size();
    align_menu_entry_positions(TLobby_warp_menu_window);
    TLobby_warp_menu_window->set_ready_flag();
    ((s32 (*)())TLobby::init_player_window_effect)();
    TLobby__data_805D5594 = 3;
}

void TLobby__sub_801384E4(void) {
    if (TLobby__join_lobby_controller != NULL) {
        if ((s32) TLobby__player_setup_pending == 0) {
            if ((s32) TLobby__data_805D5594 != 0xC) {
                sprintf((char *)lobby_join_message_buffer, (const char *)TLobby::get_seq_phase(7), lbl_80509D3C);
                show_dialog_value_line((saddr)lobby_join_message_buffer);
                reinterpret_cast<TWindowBase *>(TLobby__current_dialog_window)->reparent_to_main_ctrl();
                ((s32 (*)())TLobby::init_player_window_effect)();
                TLobby__join_lobby_idle_timer = 0;
                TLobby__data_805D5594 = 0xC;
                if (TLobby__protocol_instance != NULL) {
                    *(u8 *)((s8 *)TLobby__protocol_instance + 0x2A) = (u8) (*(u8 *)((s8 *)TLobby__protocol_instance + 0x2A) | 1);
                }
            }
        } else {
            TLobby__deferred_player_setup_state = 5;
            TLobby__data_805D5594 = 0x17;
        }
        lbl_805D55C0 = 1;
    }
}
void TLobby::update_state() {
    if (TLobby__join_lobby_controller != NULL) {
        if ((s32) TLobby__player_setup_pending == 0) {
            if ((s32) TLobby__data_805D5594 != 0xC) {
                ((s32 (*)(s32))TLobby::show_seq_phase_message)(0x21);
                reinterpret_cast<TWindowBase *>(TLobby__current_dialog_window)->reparent_to_main_ctrl();
                ((s32 (*)())TLobby::init_player_window_effect)();
                TLobby__join_lobby_idle_timer = 0;
                TLobby__data_805D5594 = 0xC;
                if (TLobby__protocol_instance != NULL) {
                    *(u8 *)((s8 *)TLobby__protocol_instance + 0x2A) = (u8) (*(u8 *)((s8 *)TLobby__protocol_instance + 0x2A) | 1);
                }
            }
        } else {
            TLobby__deferred_player_setup_state = 5;
            TLobby__data_805D5594 = 0x17;
        }
        lbl_805D55C0 = 1;
    }
}
void TLobby::reset_state(int msg) {
    show_join_entry_message(msg);
    ((s32 (*)())TLobby::init_player_window_effect)();
    TLobby__join_lobby_idle_timer = 0;
    TLobby__data_805D5594 = 0xC;
    lbl_805D55C0 = 1;
}
void TLobby::close_and_set_state_13(int msg) {
    show_join_entry_message(msg);
    ((s32 (*)())TLobby::init_player_window_effect)();
    TLobby__data_805D5594 = 0xD;
}
void TLobby::create_warp_menu() {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x39), 6, 0);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x3A), 6, 1);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
    lobby_com_card_window->set_ready_flag();
    TLobby__data_805D5594 = 4;
}
void TLobby::request_game_list() {
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(4);
    if (TLobby_warp_menu_window != NULL) {
        TLobby_warp_menu_window->close();
        TLobby_warp_menu_window = NULL;
    }
    if (lobby_com_card_window != NULL) {
        lobby_com_card_window->close();
        lobby_com_card_window = NULL;
    }
    ((TProtocol *)(TLobby__protocol_instance))->send_game_list();
    TLobby__data_805D5594 = 6;
}
void TLobby::open_menu_window() {
    TWindowMenu *menu = lobby_com_card_window;
    if (menu != NULL) {
        ((TWindowOptionCtrl *)menu)->open();
    }
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(0x11);
    lobby_make_team_menu_window = (TWindowMenu *)create_window_menu_default((saddr)get_window_layout_position(0xB6), 2);
    TObjCityMainWarp::forward_trade_action_default(lobby_make_team_menu_window, TLobby::get_seq_phase(0x45), 6, 0);
    TObjCityMainWarp::forward_trade_action_default(lobby_make_team_menu_window, TLobby::get_seq_phase(0x46), 6, 1);
    lobby_make_team_menu_window->calc_window_size();
    align_menu_entry_positions(lobby_make_team_menu_window);
    lobby_make_team_menu_window->set_ready_flag();
    ((TWindowSubComCardList *)lobby_make_team_menu_window)->set_selected_index(0);
    TLobby__data_805D5594 = 0x18;
}
void TLobby::open_make_team_window(int arg0) {
    lobby_make_team_window = new TWindowMakeTeam((TObject *)TLobby__join_lobby_controller, arg0);
    TLobby__data_805D5594 = 0xA;
}
void TLobby::close_all_windows(void *) { TLobby::close_all_windows(); }
void TLobby::open_warp_menu() {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 2);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x3E), 6, 0);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x3F), 6, 1);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
    lobby_com_card_window->set_ready_flag();
    TLobby__data_805D5594 = 5;
}
void TLobby::return_to_main_menu() {
    TWindowBase *t;

    ((s32 (*)(s32))TLobby::show_seq_phase_message)(6);
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
    t = (TWindowBase *)TLobby__download_list_window;
    if (t != NULL) {
        t->close();
        TLobby__download_list_window = 0U;
    }
    t = (TWindowBase *)TLobby__card_list_window;
    if (t != NULL) {
        t->close();
        TLobby__card_list_window = 0U;
    }
    t = (TWindowBase *)TLobby__list_window;
    if (t != NULL) {
        t->close();
        TLobby__list_window = 0U;
    }
    TLobby__protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    ((TProtocol *)(TLobby__protocol_instance))->send_ship_list_request();
    TLobby__data_805D5594 = 7;
}
void TLobby::close_menu_windows() {
    ((s32 (*)(s32))TLobby::show_seq_phase_message)(6);
    TLobby_warp_menu_window->close();
    TLobby_warp_menu_window = NULL;
    lobby_com_card_window->close();
    lobby_com_card_window = NULL;
    TLobby__protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    ((TProtocol *)(TLobby__protocol_instance))->send_block_list_request();
    TLobby__data_805D5594 = 8;
}
void TLobby::close_and_send_text_list() {
    TLobby::close_all_windows();
    ((s32 (*)())TLobby::init_player_window_effect)();
    ((TProtocol *)(TLobby__protocol_instance))->send_text_list();
}
void TLobby::open_keyboard_window() {
    saddr var_r0;
    s32 tmp_r3;

    if ((u32) (*(u32 *)&TLobby__current_dialog_window) != 0U) {
        ((TWindowBase *)(*(uaddr *)&TLobby__current_dialog_window))->close();
        (*(u32 *)&TLobby__current_dialog_window) = 0U;
    }
    if (lobby_keyboard_prompt_window == NULL) {
        static s32 *blank_entry = &lbl_805DB0B4;
        tmp_r3 = (saddr)get_window_layout_position(0xC3);
        lobby_keyboard_prompt_window = (TWindowMenu *)create_window_menu_default(tmp_r3, 2);
        TObjCityMainWarp::forward_trade_action_default(lobby_keyboard_prompt_window, TLobby::get_seq_phase(0x44), 2, 0);
        TObjCityMainWarp::forward_trade_action_default(lobby_keyboard_prompt_window, (saddr)blank_entry, 2, 1);
        lobby_keyboard_prompt_window->calc_window_size();
        align_menu_entry_positions(lobby_keyboard_prompt_window);
        ((TAdChrSelASlotGC *)lobby_keyboard_prompt_window)->set_flag_40();
    }
    lobby_keyboard_controller = new TKeyBoardControl(TLobby__join_lobby_controller, 0x10, 0, 0, local_client_id);
    lobby_keyboard_controller->set_sub_position((u8 *)(get_window_layout_position(0xC4)));
    lobby_keyboard_controller->set_hard_position((u8 *)get_window_layout_position(0xC5));
    TLobby__data_805D5594 = 9;
}
void TLobby::close_and_set_state_12() {
    TLobby::close_all_windows();
    ((s32 (*)())TLobby::init_player_window_effect)();
    TLobby__data_805D5594 = 0x12;
}
void TLobby::send_room_change(int idx) {
    TLobby__data_805D5588 = 1;
    ((s32 (*)())TLobby::init_player_window_effect)();
    ((TProtocol *)(TLobby__protocol_instance))->send_room_change(idx);
    TLobby__data_805D5594 = 0x13;
}
void TLobby::open_city_warp_menu() {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)TLobby_warp_menu_window)->open();
    window_layout_position = (saddr)get_window_layout_position(0xB5);
    lobby_com_card_window = (TWindowMenu *)create_window_menu_default(window_layout_position, 5);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x4C), 6, 0);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x48), 6, 1);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x49), 6, 2);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x4A), 6, 3);
    TObjCityMainWarp::forward_trade_action_default(lobby_com_card_window, TLobby::get_seq_phase(0x4B), 6, 4);
    lobby_com_card_window->calc_window_size();
    align_menu_entry_positions(lobby_com_card_window);
    lobby_com_card_window->set_ready_flag();
    TLobby__data_805D5594 = 0x19;
}
void TLobby::update_com_card_window() {
    s32 selected_menu_value;

    if (lobby_com_card_window != NULL) {
        selected_menu_value = lobby_com_card_window->get_selected_value();
        if (lobby_com_card_window->is_decided() != 0) {
            send_lobby_arrow__9TProtocolFUc(TLobby__protocol_instance, selected_menu_value);
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
    if (TLobby__download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE00[0];
        TLobby__download_list_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc6), &tmp);
    }
    ((TWindowMessage *)TLobby__download_list_window)->append_line((int)arg0, (int)3);
    TLobby__data_805D5594 = 0x14;
    TQuestListOnline__sub_8013ACF4(0xb);
}

u8 *__dt__6TLobbyFv(u8 *object, s16 arg1) {
    if (object != NULL) {
        *(void ***)((s8 *)object + 0x18) = __vt__6TLobby;
        TLobby::destroy_all_objects();
        TLobby__protocol_instance = NULL;
        TLobby__lobby_entered_flag = 0;
        TLobby__data_805D5588 = 0;
        TLobby__data_805D558C = 0;
        TLobby__pending_member_count = 0;
        TLobby__deferred_player_setup_state = 0;
        TLobby__data_805D5594 = 0;
        TLobby__join_state_flag = 1;
        TLobby__date_seconds = 0;
        TLobby__event_theme_id = 0;
        TLobby__card_list_selected_index = 0;
        TLobby__idle_timeout_active = 0;
        TLobby__data_805D55AC = 0;
        TLobby__lobby_number = 0;
        TLobby__join_lobby_idle_timer = 0;
        TLobby__data_805D55B8 = 0;
        TLobby__login_pending_flag = 1;
        lbl_805D55C0 = 0;
        TLobby__player_setup_pending = 0;
        lobby_selected_game_list_index = 0;
        TLobby__join_lobby_controller = NULL;
        TLobby__data_805D4E30 = 0;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
void TLobby::destroy_all_objects() {
    if (TLobby__card_list_window != NULL) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__card_list_window);
        TLobby__card_list_window = 0U;
    }
    if (TLobby__download_list_window != NULL) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__download_list_window);
        TLobby__download_list_window = 0U;
    }
    if (TLobby__list_window != NULL) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__list_window);
        TLobby__list_window = 0U;
    }
    if (lobby_player_construction_window != NULL) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_player_construction_window);
        lobby_player_construction_window = 0U;
    }
    if ((u32) (*(u32 *)&TLobby__current_dialog_window) != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)(*(uaddr *)&TLobby__current_dialog_window));
        (*(u32 *)&TLobby__current_dialog_window) = 0U;
    }
    if ((u32) TLobby__join_entry_window_obj != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__join_entry_window_obj);
        TLobby__join_entry_window_obj = 0U;
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
    *(s32 *)((s8 *)TLobby__protocol_instance + 0x191C) = 1;
    TLobby__player_setup_pending = 1;
    if ((s32) TLobby__data_805D5594 == 0xC) {
        TLobby__deferred_player_setup_state = 5;
        TLobby__data_805D5594 = 0x17;
    }
    TLobby__current_dialog_window = 0;
}
void TLobby::process_deferred_player_setup() {
    TLobby__player_setup_pending = 0;
    switch (TLobby__deferred_player_setup_state) {
    case 1:
    case 2:
        construct_lobby_players((Rec_801378AC *)TLobby__data_80506A6C, TLobby__pending_member_count, TLobby__data_805D558C, TLobby__designated_client_id);
        break;
    case 3:
    case 4:
        TLobby::make_players();
        break;
    case 5:
        ((s32 (*)())TLobby__sub_801384E4)();
        break;
    }
    if (TLobby__protocol_instance != NULL) {
        *(s32 *)((s8 *)TLobby__protocol_instance + 0x191C) = 0;
        TLobby::drain_deferred_packets();
    }
    TLobby__deferred_player_setup_state = 0;
    TLobby__pending_member_count = 0;
    TLobby__data_805D558C = 0;
}
void TLobby::add_lobby_members(TPlyJoinLobbyEntry *src, int n, int client_id, int leader) {
    s32 i;
    TLobby__deferred_player_setup_state = 2;
    TLobby__data_805D558C = client_id;
    for (i = TLobby__pending_member_count; i < TLobby__pending_member_count + n; i++) {
        TLobby::copy_member_record(&((TPlyJoinLobbyEntry *)TLobby__data_80506A6C)[i], &src[i]);
    }
    TLobby__pending_member_count += n;
    TLobby__designated_client_id = leader;
}
void TLobby::handle_regist_check(int ok) {
    if (ok) {
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        ((TProtocol *)(TLobby__protocol_instance))->send_login2(TLobby::get_option_state());
    } else {
        ((TProtocol *)(TLobby__protocol_instance))->send_regist();
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
        TLobby::send_login_9e_extended(TLobby__protocol_instance, (void *) (((saddr)(void *)TAdSinglePlyChrSelectGC::get_char_index((u32)(0xFFFF))) + 0x370), (int)option_state);
        return;
    case 1:
        send_register_9c((u8 *)TLobby__protocol_instance);
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
        ((TProtocol *)(TLobby__protocol_instance))->send_login2(TLobby::get_option_state());
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
        TLobby::send_login_9e_extended(TLobby__protocol_instance, (u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) + 0x370, opt);
        TLobby::dispatch_by_index(1);
        return;
    }
    lobby_debug_printf_stub(lobby_msg_name_taken);
    TLobby::dispatch_by_index(2);
    TLobby::reset_state(0x50);
}
void TLobby::handle_login_result(unsigned int arg0) {
    s32 temp_r31;
    switch (arg0) {
    case 0:
        lobby_debug_printf_stub(lobby_msg_login_success);
        TAdEnterSerialAccessGC::store_serial_access_key((saddr)((char *)TLobby__protocol_instance + 0x3F8A), (saddr)((char *)TLobby__protocol_instance + 0x3F9B), (saddr)((char *)TLobby__protocol_instance + 0x3F3A));
        if (TLobby__login_pending_flag != 0) {
            temp_r31 = increment_frame__23TAdSinglePlyChrSelectGCFv();
            ((TProtocol *)(TLobby__protocol_instance))->send_character_save_info(get_player_count__23TAdSinglePlyChrSelectGCFv(), temp_r31);
            TLobby__login_pending_flag = 0;
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
    a.kb = TLobby::open_hard_keyboard((void *)local_client_id) != 0 ? 1 : 0;
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
    copy_challenge_info(d.b, card + 0x21C4);
    d.h[0] = *(u16 *)(card + 0x21A8);
    d.h[1] = *(u16 *)(card + 0x21AA);
    d.h[2] = *(u16 *)(card + 0x21AC);
    d.h[3] = *(u16 *)(card + 0x21AE);
    d.h[4] = *(u16 *)(card + 0x21B0);
    d.h[5] = *(u16 *)(card + 0x21B2);
    d.h[6] = *(u16 *)(card + 0x21B4);
    d.w0 = *(u32 *)(card + 0x21B8);
    d.w1 = *(u32 *)(card + 0x21BC);
    send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(TLobby__protocol_instance, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), &d, &a, b, e, c);
}
void TLobby::queue_static_object_destruction() {
    TLobby__join_lobby_controller->queue_destruction();
}
void TLobby::send_position_update() {
    s32 temp_r31;
    s32 temp_r4;

    temp_r31 = increment_frame__23TAdSinglePlyChrSelectGCFv();
    temp_r4 = get_player_count__23TAdSinglePlyChrSelectGCFv();
    ((TProtocol *)(TLobby__protocol_instance))->send_character_save_info(temp_r4, temp_r31);
}
void TLobby::handle_state(int arg0) {
    s32 temp_r3;

    if (arg0 != 0) {
        TAdSinglePlyChrSelectGC::save_online_character();
        temp_r3 = TLobby__sub_80146740();
        switch (temp_r3) {
        case 0:
            ((TProtocol *)(TLobby__protocol_instance))->send_server_time_request();
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
    if (TLobby__download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE08[0];
        TLobby__download_list_window = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc7), &tmp);
    }
    ((TWindowMessage *)TLobby__download_list_window)->append_line((int)arg0, (int)3);
}

void TLobby__sub_801371B0(s32 arg0) {
    if (TLobby__join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EE10[0];
        TLobby__join_entry_window_obj = (uaddr)create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0xc8), &tmp);
    }
    ((TWindowMessage *)TLobby__join_entry_window_obj)->append_line((int)arg0, (int)3);
    TLobby__data_805D5594 = 0x16;
}
void TLobby::disable_window_flags(void*a0) { TWindowCtrl::set_window_flags_off(local_client_id, (saddr)a0); }
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
    if (TLobby__list_window != 0) {
        ((void (*)(void *))queue_destruction__7TObjectFv)(TLobby__list_window);
        TLobby__list_window = 0;
    }
    TLobby__list_window = TShopJudgmentItemWindow::open_default((saddr)tbl);
    for (i = 0; i < count; i++) {
        ((TLobby *)TLobby__list_window)->add_status_disp_entry((saddr)list[i].name, (s32)i);
    }
    ((TWindowMenuIconLine *)TLobby__list_window)->calc_content_extent();
    if (cmp == 0) {
        TLobby::set_menu_mode_1();
    } else {
        TLobby::set_menu_mode_0();
    }
    if (strncmp(entry->name, lobby_list_header_block, 5) != 0) {
        memset(TLobby__data_8050AAAC, 0, 0x11);
        strncpy(TLobby__data_8050AAAC, entry->name, 0x10);
    }
}
void TLobby::open_information_list(int count, void *entries) {
    Ent_80136FA0 *list = (Ent_80136FA0 *)entries;
    void *w = (void *)lobby_window_title_information;
    s32 i;
    void *old = TLobby__list_window;
    if (old != 0) {
        ((TObject *)old)->queue_destruction();
        TLobby__list_window = 0;
    }
    TLobby__list_window = TShopJudgmentItemWindow::open_default((saddr)w);
    for (i = 0; i < count; i++) {
        ((TLobby *)TLobby__list_window)->add_status_disp_entry((saddr)list[i].name, (s32)i);
    }
    ((TWindowMenuIconLine *)TLobby__list_window)->calc_content_extent();
    TLobby::set_menu_mode_2();
}

void TLobby__sub_80136E68(s32 count, Ent_80136E68 *entries, Ent_80136E68 *selected) {
    static void *tbl = (void *)lobby_msg_information_counter;
    void *w;
    s32 i;

    if (TLobby__list_window != 0) {
        ((TObject *)TLobby__list_window)->queue_destruction();
        TLobby__list_window = 0;
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
    TLobby__list_window = w;
    memset(lbl_8050AAD4, 0, 0x11);
    strncpy((char *)lbl_8050AAD4, selected->name, 0x11);
}
void TLobby::handle_game_join(void *data) {
    Pkt_80136C94 *pkt = (Pkt_80136C94 *)data;
    Hdr_80136C94 hdr;
    Obj_80136C94 *p;
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
    TLobby__designated_client_id = pkt->leader_id;
    TLobby__join_state_flag = pkt->b106;
    TLobby::set_player_count(pkt->count);
    TLobby__data_805D4E30 = pkt->b10b;
    game_difficulty_selection = pkt->b107;
    TLobby__event_theme_id = pkt->b109;
    set_area_random_seed(pkt->w10c);
    set_world_section_id(TLobby__data_805011D8, pkt->b10a);
    if ((s32)pkt->b110 == 2) {
        request_story_select_state(1);
    } else {
        request_story_select_state(0);
    }
    fn_8013ACE4(pkt->w10c);
    for (i = 0; i < 0xC; i++) {
        p = (Obj_80136C94 *)get_player_by_client_id(i);
        if (p != NULL) {
            delete p;
            lobby_debug_printf_stub(TLobby__data_8043EF38, i);
        }
    }
    for (j = 0; j < 4; j++) {
        game_join_pending_clients[j] = 0;
    }
    clear_enabled_main_warps();
    TLobby__deferred_player_setup_state = 4;
    floor_transition_state.set_next_floor(0, 0);
    TLobby::set_flag_and_update();
    mark_area_change_pending();
}

void TLobby::make_players() {
    Ply_80136A8C *p;
    Hdr_80136A8C hdr;
    Ply_80136A8C *q;
    if (TLobby__sub_801A3E8C() != 0) {
        p = (Ply_80136A8C *)create_player_object(local_client_id, 0, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct((u8 *)TLobby__protocol_instance + 0x1900);
        p->m6();
        strncpy(TLobby__player_names[local_client_id], p->m10(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        ((TLobby *)TLobby__protocol_instance)->send_6F_burst_done();
        TLobby__data_805D5594 = 0xF;
        p = (Ply_80136A8C *)create_player_object(1 - local_client_id, 4, (void *)TAdSinglePlyChrSelectGC::get_char_index(0));
        if (p != NULL) {
            init_player_join_record(&hdr);
            TObjPlayer::fill_player_record(p, &hdr);
            TLobby::bswap_player_data(&hdr);
            hdr.fAC = 0;
            hdr.f488 = 0;
            delete p;
            q = (Ply_80136A8C *)create_remote_player_object(&hdr);
            if (q != NULL) {
                q->m6();
            }
        }
    } else if (local_client_id == TLobby__designated_client_id) {
        p = (Ply_80136A8C *)create_player_object(local_client_id, 0, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct((u8 *)TLobby__protocol_instance + 0x1900);
        p->m6();
        strncpy(TLobby__player_names[local_client_id], p->m10(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        ((TLobby *)TLobby__protocol_instance)->send_6F_burst_done();
        TLobby__data_805D5594 = 0xF;
    }
}

#pragma push
#pragma opt_propagation off
void TLobby::handle_lobby_enter(TPlyJoinLobbyEntry *ents, int n, int client_id, int leader, int arg4, int arg5, int arg6, int arg7) {
    s32 v4;
    Obj_801368B0 *p;
    saddr i;
    s32 j;
    Node_801361E8 *node;
    TLobby::destroy_all_objects();
    lobby_debug_printf_stub(lobby_debug_lobby_start_format, client_id);
    local_client_id = client_id;
    v4 = arg4;
    TLobby__lobby_entered_flag = 1;
    TLobby__join_state_flag = 1;
    TLobby__lobby_number = arg4;
    TLobby__data_805D55AC = arg5;
    TLobby__data_805D55B8 = arg6;
    TLobby::set_player_count(0);
    TLobby__data_805D5588 = 0;
    TLobby__designated_client_id = leader;
    for (node = game_protocol_instance->head; node != NULL; node = node->next) {
        lobby_debug_printf_stub(lobby_debug_udp_close_ip_format, node->b1c, node->b1d, node->b1e, node->b1f);
        delete (Obj_801368B0 *)node;
    }
    for (j = 0; j < 12; j++) {
        TLobby__player_names[j][0] = 0;
    }
    for (i = 0; i < n; i++) {
        strncpy(TLobby__player_names[ents[i].lobby_data.client_id], ents[i].lobby_data.name, 0x10);
    }
    for (i = 0; i < 12; i++) {
        p = (Obj_801368B0 *)get_player_by_client_id(i);
        if (p != NULL) {
            delete p;
            lobby_debug_printf_stub(TLobby__data_8043EF38, i);
        }
    }
    TLobby::add_lobby_members(ents, n, client_id, leader);
    set_floor_map_variant((saddr)(get_current_floor()), v4);
    TLobby__event_theme_id = arg7;
    activate_keyboard();
    TLobby__protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)TLobby__sub_801371B0;
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
                plr = create_player_object(self_id, 0, (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
                ((TLobby *)(plr + 0xDAC))->copy_header_struct(&((Entry_8013634C *)records)[i]);
                ((Plr_80136080 *)plr)->m6();
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
                plr = create_player_object(((Entry_8013634C *)records)[j].client_id, 4, ((Entry_8013634C *)records)[j].char_data);
                ((TLobby *)(plr + 0xDAC))->copy_header_struct(&((Entry_8013634C *)records)[j]);
                ((Plr_80136080 *)plr)->m6();
                lobby_debug_printf_stub(lobby_debug_create_player_format, ((Entry_8013634C *)records)[j].client_id);
            } else {
                lobby_debug_printf_stub(lobby_debug_duplicate_player_format, ((Entry_8013634C *)records)[j].client_id);
            }
        }
    }
    TLobby__protocol_instance->m_recv_handlers.handle_06_recv_chat = (recv_packet_handler_handle_06_recv_chat)handle_chat_message__11TWindowCtrlFPc;
    if (lobby_player_construction_window != NULL) {
        lobby_player_construction_window->queue_destruction();
        lobby_player_construction_window = NULL;
    }
    sprintf((char *)lbl_80509D3C, lobby_list_block_range_format, TLobby__data_8050AAAC, TLobby__data_805D55AC, TLobby__lobby_number + 1);
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
    Obj_801361E8 *p;
    Node_801361E8 *n;
    u8 *plr;
    if (TLobby__data_805D5594 != 0xE && TLobby__data_805D5594 != 0xF) {
        return;
    }
    TLobby__sub_8013AA64(&e, entries);
    if (e.client_id == local_client_id) {
        ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
        return;
    }
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&game_join_player_records[e.client_id], &e);
    game_join_player_records[e.client_id].ip_addr = e.ip_addr;
    game_join_player_records[e.client_id].client_id = e.client_id;
    strncpy(game_join_player_records[e.client_id].name, e.name, 0x10);
    TLobby__join_state_flag = disable_udp;
    sprintf(player_joined_message, (const char *)TLobby::get_seq_phase(0x10), e.name);
    show_dialog_value_line((saddr)player_joined_message);
    ((TWindowMessage *)TLobby__current_dialog_window)->complete_reveal();
    reinterpret_cast<TWindowBase *>(TLobby__current_dialog_window)->reparent_to_main_ctrl();
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
    TLobby__designated_client_id = leader_id;
    p = (Obj_801361E8 *)get_player_by_client_id(e.client_id);
    if (p != NULL) {
        for (n = game_protocol_instance->head; n != NULL; n = n->next) {
            if (n->id == e.client_id) {
                lobby_debug_printf_stub(lobby_debug_udp_close_player_format, e.client_id, n->b1c, n->b1d, n->b1e, n->b1f);
                delete (Obj_801361E8 *)n;
                break;
            }
        }
        delete p;
        lobby_debug_printf_stub(TLobby__data_8043EF38, e.client_id);
    }
    if (local_client_id == TLobby__designated_client_id) {
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
            plr = create_player_object(e.client_id, 4, e.char_data);
            ((TLobby *)(plr + 0xDAC))->copy_header_struct(&e);
            ((Plr_80136080 *)plr)->m6();
            TLobby::open_udp_socket_for_player(e.client_id);
            lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
        }
    } else {
        game_join_pending_clients[e.client_id] = 1;
        TLobby::copy_member_record(&((Entry_8013634C *)TLobby__data_80506A6C)[e.client_id], &e);
    }
    if (local_client_id == TLobby__designated_client_id) {
        init_6x72_resume_packet(&pkt);
        TLobby::send_packet_60(&pkt);
    }
    ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
}

void handle_6x72_done_loading_into_game(void) {
    if ((u32) TLobby__current_dialog_window != 0U) {
        ((TWindowBase *)TLobby__current_dialog_window)->close();
        TLobby__current_dialog_window = 0U;
    }
    main_task.resume_layers();
}
void TLobby::remove_player(unsigned int arg0, int arg1, int arg2) {
    Obj_801361E8 *p;
    Node_801361E8 *n;
    TLobby__designated_client_id = arg1;
    TLobby__join_state_flag = arg2;
    p = (Obj_801361E8 *)get_player_by_client_id(arg0);
    if (p != NULL) {
        for (n = game_protocol_instance->head; n != NULL; n = n->next) {
            if (n->id == arg0) {
                lobby_debug_printf_stub(lobby_debug_udp_close_ip_format, n->b1c, n->b1d, n->b1e, n->b1f);
                delete (Obj_801361E8 *)n;
                break;
            }
        }
        delete p;
    }
    strncpy(TLobby__player_names[arg0], TLobby__data_805DB0B0, 0x10);
    if (TLobby__data_805D5594 == 0xE) {
        TLobby__data_805D5CE8 = 1;
    }
    if (TLobby__current_dialog_window != 0) {
        ((TWindowBase *)TLobby__current_dialog_window)->close();
        TLobby__current_dialog_window = 0;
    }
    if (quest_download_active == 0) {
        main_task.resume_layers();
    }
}

s32 __dt__18TPlyJoinLobbyEntryFv(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        ((TPlyJoinLobbyEntry *)arg0)->char_data.~TPlyCharData();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}
void TLobby::on_lobby_player_add(TPlyJoinLobbyEntry *entries, int leader_id) {
    Entry_80136080 e;
    Obj_80136080 *p;
    u8 *plr;
    TLobby__sub_8013AA64(&e, entries);
    TLobby__designated_client_id = leader_id;
    if (e.client_id == local_client_id) {
        lobby_debug_printf_stub(lobby_debug_burst_overwrite_format, e.client_id);
        ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
        return;
    }
    p = (Obj_80136080 *)get_player_by_client_id(e.client_id);
    if (p != NULL) {
        delete p;
        lobby_debug_printf_stub(TLobby__data_8043EF38, e.client_id);
    }
    strncpy(TLobby__player_names[e.client_id], e.name, 0x10);
    plr = create_player_object(e.client_id, 4, e.char_data);
    ((TLobby *)(plr + 0xDAC))->copy_header_struct(&e);
    ((Plr_80136080 *)plr)->m6();
    lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
    ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
}
void TLobby::retire_lobby_player(int idx, int v) {
    Obj_80136000 *p;
    TLobby__designated_client_id = v;
    p = (Obj_80136000 *)get_player_by_client_id(idx);
    if (p) {
        delete p;
        lobby_debug_printf_stub(lobby_debug_player_exit_format, idx);
    }
    strncpy(TLobby__player_names[idx], TLobby__data_805DB0B0, 0x10);
}

void TLobby__sub_80135FFC(void) {  }
void TLobby::open_download_list_window(int count, void *entries) {
    static void *tbl = (void *)lobby_window_title_download;
    Ent_80135E7C *list = (Ent_80135E7C *)entries;
    s32 i;
    Ent_80135E7C *e;
    const NJS_POINT2 *w;

    if (TLobby__list_window != 0) {
        queue_destruction__7TObjectFv(TLobby__list_window);
        TLobby__list_window = 0;
    }
    TLobby__list_window = TShopJudgmentItemWindow::open_default((saddr)tbl);
    for (i = 0; i < count; i++) {
        e = &list[i];
        switch (e->kind) {
        case 0:
            ((TWindowMenuIconLine *)TLobby__list_window)->add_list_entry(0x2C, (saddr)e->name, (s32)i);
            break;
        case 1:
            ((TWindowMenuIconLine *)TLobby__list_window)->add_list_entry(0x17, (saddr)e->name, (s32)i);
            break;
        case 2:
            ((TWindowMenuIconLine *)TLobby__list_window)->add_list_entry(0x31, (saddr)e->name, (s32)i);
            break;
        default:
            ((TWindowMenuIconLine *)TLobby__list_window)->add_list_entry(0x2C, (saddr)e->name, (s32)i);
            break;
        }
    }
    ((TWindowMenuIconLine *)TLobby__list_window)->calc_content_extent();
    if (TLobby__download_list_window != 0) {
        queue_destruction__7TObjectFv(TLobby__download_list_window);
        TLobby__download_list_window = 0;
    }
    {
        Pair_80135E7C p = lbl_8043EE18[0];
        w = get_window_layout_position(0xC7);
        TLobby__download_list_window = TWindowMessage::create(w, (const f32 *)(&p), 1);
        ((TWindowMessage *)TLobby__download_list_window)->append_line((saddr)((char *)list + 0x2C), (int)3);
    }
    TLobby__card_list_selected_index = 0;
    TLobby__data_805D5594 = 0x11;
}

#pragma defer_codegen off

#pragma push
void TLobby::send_logout() {
    if (TLobby__protocol_instance != NULL) {
        TLobby__protocol_instance->send_logout();
    }
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

#define CONNECT_801399B8(res, s)                                                                   \
    if (TKeyBoardControl__sub_8000F828() == 0) {                                                    \
        res = socket_set_server_info(TLobby__protocol_instance, TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
                                     TLobby::init_serial_access(), (const char *)get_access_key_input_buffer(), \
                                     s[0].host, s[0].port);                                     \
    } else {                                                                                        \
        res = socket_set_server_info(TLobby__protocol_instance, TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
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
        DateToSeconds((DateStamp *)&date, (int *)&TLobby__date_seconds);
        p = TObject::operator new(0x2C);
        if (p != NULL) {
            init_idle_timeout_timer((u8 *)p, arg0);
        }
        TLobby__join_state_flag = 1;
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

void *__vt__6TLobby[6] = { 0, 0, (void *)__dt__6TLobbyFv, (void *)run_task__6TLobbyFv, (void *)render__6TLobbyFv, (void *)render_shadows__7TObjectFv };

u8 *TLobby__ct(u8 *object, void *parent) {
    s32 *access_key;
    s32 *password;
    TProtocol *protocol;

    __ct__7TObjectFP7TObject(object, parent);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__6TLobby;
    TLobby__sub_8013A16C();
    ((TObject *)object)->m_name = lobby_class_name;
    TLobby__join_lobby_controller = (TLobby *)object;
    TLobby__card_list_window = 0;
    TLobby__download_list_window = 0;
    TLobby__list_window = 0;
    lobby_player_construction_window = 0;
    TLobby__current_dialog_window = 0;
    TLobby__join_entry_window_obj = 0;
    TLobby_warp_menu_window = NULL;
    lobby_com_card_window = NULL;
    lobby_make_team_menu_window = NULL;
    lobby_make_team_window = NULL;
    lobby_keyboard_prompt_window = NULL;
    lobby_keyboard_controller = NULL;
    lobby_scroll_text_window = NULL;
    TLobby__lobby_entered_flag = 0;
    TLobby__data_805D5588 = 0;
    TLobby__data_805D558C = 0;
    TLobby__pending_member_count = 0;
    TLobby__deferred_player_setup_state = 0;
    TLobby__data_805D5594 = 0;
    TLobby__join_state_flag = 1;
    TLobby__date_seconds = 0;
    TLobby__event_theme_id = 0;
    TLobby__card_list_selected_index = 0;
    TLobby__idle_timeout_active = 0;
    TLobby__data_805D55AC = 0;
    TLobby__lobby_number = 0;
    TLobby__join_lobby_idle_timer = 0;
    TLobby__data_805D55B8 = 0;
    TLobby__login_pending_flag = 1;
    lbl_805D55C0 = 0;
    lobby_login_result_flag = 0;
    TLobby__player_setup_pending = 0;
    local_client_id = 0;
    TLobby__designated_client_id = 0;
    memset(lbl_80509D3C, 0, 0x20);
    memset(TLobby__player_names, 0, 0xC0);
    memset(lobby_player_status_records, 0, 0xD50);
    protocol = (TProtocol *)alloc_from_obj_heap(0xBCA4);
    if (protocol != NULL) {
        password = TAdEnterPasswordGC__sub_8013ADE4();
        access_key = get_access_key_input_buffer();
        protocol = __ct__9TProtocolFP7TObjectUsiPcPcPc(protocol, object, 0x36, current_language, TLobby::init_serial_access(), (char *)access_key, (char *)password);
    }
    TLobby__protocol_instance = protocol;
    protocol->m_recv_handlers.handle_unused_login = (recv_packet_handler_handle_unused_login)TLobby::handle_regist_check;
    TLobby__protocol_instance->m_recv_handlers.handle_03_recv_regist = (recv_packet_handler_handle_03_recv_regist)TLobby::handle_register_name_result;
    TLobby__protocol_instance->m_recv_handlers.handle_04_recv_login = (recv_packet_handler_handle_04_recv_login)TLobby::handle_login_result;
    TLobby__protocol_instance->m_recv_handlers.handle_05_recv_logout = TLobby::queue_static_object_destruction;
    TLobby__protocol_instance->m_recv_handlers.handle_06_recv_chat = NULL;
    TLobby__protocol_instance->m_recv_handlers.handle_01_recv_error = (recv_packet_handler_handle_01_recv_error)TLobby__sub_80137C10;
    TLobby__protocol_instance->m_recv_handlers.handle_07_A0_A1_recv_dir_list = (recv_packet_handler_handle_07_A0_A1_recv_dir_list)TLobby::open_ship_block_select_menu;
    TLobby__protocol_instance->m_recv_handlers.handle_08_recv_game_list = (recv_packet_handler_handle_08_recv_game_list)TLobby__sub_80136E68;
    TLobby__protocol_instance->m_recv_handlers.handle_11_recv_message = (recv_packet_handler_handle_11_recv_message)TLobby__sub_80137228;
    TLobby__protocol_instance->m_recv_handlers.handle_0E_recv_start_game = NULL;
    TLobby__protocol_instance->m_recv_handlers.unused7 = NULL;
    TLobby__protocol_instance->m_recv_handlers.handle_64_recv_start_game3 = (recv_packet_handler_handle_64_recv_start_game3)TLobby::handle_game_join;
    TLobby__protocol_instance->m_recv_handlers.unused8 = NULL;
    TLobby__protocol_instance->m_recv_handlers.handle_67_recv_start_lobby2 = (recv_packet_handler_handle_67_recv_start_lobby2)TLobby::handle_lobby_enter;
    TLobby__protocol_instance->m_recv_handlers.handle_1A_D5_recv_text = (recv_packet_handler_handle_1A_D5_recv_text)TLobby::open_scroll_text_window;
    TLobby__protocol_instance->m_recv_handlers.handle_80_recv_generate_id = (recv_packet_handler_handle_80_recv_generate_id)TLobby__sub_80135FFC;
    TLobby__protocol_instance->m_recv_handlers.handle_65_recv_burst_game = TLobby::on_game_player_add;
    TLobby__protocol_instance->m_recv_handlers.handle_66_recv_exit_game = (recv_packet_handler_handle_66_recv_exit_game)TLobby::remove_player;
    TLobby__protocol_instance->m_recv_handlers.handle_68_recv_burst_lobby = TLobby::on_lobby_player_add;
    TLobby__protocol_instance->m_recv_handlers.handle_69_recv_exit_lobby = TLobby::retire_lobby_player;
    TLobby__protocol_instance->m_recv_handlers.handle_81_recv_chat_message = (recv_packet_handler_handle_81_recv_chat_message)try_close__6TLobbyFPv;
    TLobby__protocol_instance->m_recv_handlers.handle_41_recv_user_ans = (recv_packet_handler_handle_41_recv_user_ans)TLobby::forward_8024273C;
    TLobby__protocol_instance->m_recv_handlers.handle_18_90_9A_recv_pso_regist_check = (recv_packet_handler_handle_18_90_9A_recv_pso_regist_check)TLobby::handle_verify_result;
    TLobby__protocol_instance->m_recv_handlers.handle_92_9C_register_response_packet = (recv_packet_handler_handle_92_9C_register_response_packet)TLobby::handle_register_result;
    TLobby__protocol_instance->m_recv_handlers.handle_95_request_character_data_packet = TLobby::send_selected_character;
    TLobby__protocol_instance->m_recv_handlers.send_96_unused = TLobby::send_position_update;
    TLobby__protocol_instance->m_recv_handlers.handle_97_checksum_reply_packet = (recv_packet_handler_handle_97_checksum_reply_packet)TLobby::handle_state;
    TLobby__protocol_instance->m_recv_handlers.handle_B1_current_time_packet = TLobby::reset_lobby_state;
    TLobby__protocol_instance->m_recv_handlers.handle_C0_choice_search_option_packet = TLobby__sub_80134DE8;
    TLobby__protocol_instance->m_recv_handlers.handle_C4_choice_search_reply_packet = TLobby__sub_80134DC8;
    TLobby__protocol_instance->m_recv_handlers.handle_A2_recv_quest_menu_list = copy_quest_list_data__16TQuestListOnlineFv;
    TLobby__protocol_instance->m_recv_handlers.handle_A3_recv_quest_menu_info = TQuestListOnline::receive_quest_info;
    TLobby__protocol_instance->m_recv_handlers.handle_44_recv_download_head = TQuestListOnline::begin_file_download;
    TLobby__protocol_instance->m_recv_handlers.handle_13_recv_download = (recv_packet_handler_handle_13_recv_download)handle_quest_download_chunk__6TLobbyFv;
    TLobby__protocol_instance->m_recv_handlers.handle_A4_recv_quest_list = (recv_packet_handler_handle_A4_recv_quest_list)TLobby::open_download_list_window;
    TLobby__protocol_instance->m_recv_handlers.handle_A5_recv_quest_info = (recv_packet_handler_handle_A5_recv_quest_info)show_card_list_message;
    TLobby__protocol_instance->m_recv_handlers.handle_A6_recv_vm_download_head = (recv_packet_handler_handle_A6_recv_vm_download_head)begin_file_download__22TQuestVmDownLoadServerFv;
    TLobby__protocol_instance->m_recv_handlers.handle_A7_recv_vm_download = (recv_packet_handler_handle_A7_recv_vm_download)receive_file_chunk__22TQuestVmDownLoadServerFv;
    TLobby__protocol_instance->m_recv_handlers.handle_B0_recv_emergency_call = (recv_packet_handler_handle_B0_recv_emergency_call)TLobby::disable_window_flags;
    TLobby__protocol_instance->m_recv_handlers.handle_1F_recv_text_list = (recv_packet_handler_handle_1F_recv_text_list)TLobby::open_information_list;
    TLobby__protocol_instance->m_recv_handlers.handle_88_player_arrow_color_list_packet = apply_lobby_markers__6TLobbyFv;
    TLobby__protocol_instance->m_recv_handlers.handle_C5_player_challenge_data_packet = copy_player_records__6TLobbyFl;
    TLobby__protocol_instance->m_recv_handlers.handle_D3_execute_trade_packet = handle_trade_received_items;
    TLobby__protocol_instance->m_recv_handlers.handle_D4_trade_result_packet = (recv_packet_handler_handle_D4_trade_result_packet)TLobby::handle_reset_choice;
    TLobby__protocol_instance->m_recv_handlers.handle_D1_advance_trade_state_packet = (recv_packet_handler_handle_D1_advance_trade_state_packet)TLobby::apply_trade_items;
    TLobby__protocol_instance->m_recv_handlers.handle_D8_infoboard_packet = init_once__6TLobbyFPv;
    TLobby__protocol_instance->m_recv_handlers.handle_DA_lobby_event_packet = set_lobby_event_theme;
    TLobby__protocol_instance->m_recv_handlers.handle_AB_quest_stats_response_packet = TLobby__sub_80134A20;
    TLobby__data_805D4E30 = 0;
    return object;
}
saddr TLobby::get_seq_phase(int id) { return get_online_message_text(id); }
void TLobby__sub_8013A16C(void) {  }
void lobby_debug_printf_stub(const char *fmt, ...) {}
void TLobby::construct_global_arrays() {
    __construct_array(TLobby__data_80506A6C, (void *)TLobby::init_char_data, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43C, 0xC);
    __register_global_object(0, (void *)TLobby::destroy_join_entries, TLobby__join_entries_dtor_registration);
    __construct_array(game_join_player_records, (void *)TLobby__sub_8013A23C, 0, 0x20, 4);
}

#pragma pop

#pragma push

void *TLobby__sub_8013A23C(void *record) {
    __ct__16TPlyGuildCardTagFv(record);
    return record;
}
void TLobby::destroy_join_entries() {
    __destroy_arr(TLobby__data_80506A6C, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43c, 0xc);
}

#pragma pop

#pragma push
void * TLobby::init_char_data(void*p) { __ct__16TPlyGuildCardTagFv(p); __ct__12TPlyCharDataFv((char*)p + 0x20); return p; }
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
    bswap__15disp_data_part2Fv((void *)(p + 0xC8));
    bswap__12player_statsFv((void *)(p + 0x118));
    TLobby::bswap_inventory((void*)(p + 0x13C));
}
void TLobby::bswap_inventory(void*p) { bswap_32((u32 *)p); { int i; for (i = 0; i < 30; i++) { ((TPlyInventoryItem *)((char*)p + 0x4 + i * 28))->bswap(); } } }
void TLobby::set_player_count(int a0) { lobby_player_count = a0; }

#pragma pop

#pragma push

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void bswap_and_send_extended_subcommand(void *p, u32 size) { bswap_extended_subcommand_header(p); ((TLobby *)p)->send_command(size); }

void bswap_extended_subcommand_header(void* p) { TLobby::bswap_header_fields(p); }
void TLobby::bswap_header_fields(void *header) {
    bswap_16((u16 *)((u8 *)header + 2));
    bswap_32((u32 *)((u8 *)header + 4));
}
void TLobby::bswap_and_handle_packet(void *packet, int size) {
    bswap_client_id_header((G_ClientIDHeader *)packet);
    ((TLobby *)packet)->send_subcommand_to_client((u32)size);
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

u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r5;
    u8 *temp_r6;
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u8 *)((s8 *)arg0 + 2) = (u8) *(u8 *)((s8 *)arg1 + 2);
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg1 + 3);
    *(ByteBlock_348 *)((saddr) arg0 + 4) = *(const ByteBlock_348 *)((saddr) arg1 + 4);
    temp_r6 = (arg0 + 0x348);
    temp_r4 = (arg1 + 0x348);
    *(ByteBlock_24 *)((saddr) temp_r6 + 4) = *(const ByteBlock_24 *)((saddr) temp_r4 + 4);
    *(ByteBlock_50 *)((arg0 + 0x36C) + 4) = *(const ByteBlock_50 *)((arg1 + 0x36C) + 4);
    TObjPlayer__sub_8013A748(arg0 + 0x3C0, arg1 + 0x3C0);
    temp_r5 = (arg0 + 0x404);
    temp_r4_2 = (arg1 + 0x404);
    *(ByteBlock_14 *)((saddr) temp_r5 + 4) = *(const ByteBlock_14 *)((saddr) temp_r4_2 + 4);
    return arg0;
}

void *TObjPlayer__sub_8013A748(void *arg0, void *arg1) {
    TObjPlayer__sub_8013A788(arg0, arg1);
    ((void (*)(void *, void *))TObjPlayer__sub_8013A788)((void *)((char *)arg0 + 36), (void *)((char *)arg1 + 36));
    return arg0;
}

void* TObjPlayer__sub_8013A788(void* p, void* a1) { *(void**)(p) = *(void**)((char*)a1 + 0x0); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x4)), (void *)((void*)((char*)a1 + 0x4))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x8)), (void *)((void*)((char*)a1 + 0x8))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0xc)), (void *)((void*)((char*)a1 + 0xc))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x10)), (void *)((void*)((char*)a1 + 0x10))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x14)), (void *)((void*)((char*)a1 + 0x14))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x18)), (void *)((void*)((char*)a1 + 0x18))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x1c)), (void *)((void*)((char*)a1 + 0x1c))); TObjPlayer__sub_8013A820((void *)((void*)((char*)p + 0x20)), (void *)((void*)((char*)a1 + 0x20))); return p; }
void TObjPlayer__sub_8013A820(void *arg0, void *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

#pragma pop

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
__declspec(section ".rodata") const char TLobby__data_8043EF38[] = "delete player %d";
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
