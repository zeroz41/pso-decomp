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

extern "C" {
void send_6x70_player_data__6TLobbyFi(saddr arg0);
void send_6x6E_sync_game_state__6TLobbyFi(saddr arg0);
char * get_seq_phase__6TLobbyFPv(int);
void lobby_debug_printf_stub(const char *fmt, ...);
saddr get_player_by_client_id(void *);
u8 * create_player_object(s32, s32, void *);
s32 __dt__18TPlyJoinLobbyEntryFv(saddr arg0, s16 arg1);
void TLobby__sub_8013AA64(void *, void *);
void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *, void *);
void show_dialog_value_line(char *);
void copy_member_record__6TLobbyFPvPv(void *, void *);
void init_6x72_resume_packet(void *);
void send_packet_60__6TLobbyFi(void *);
extern const char TLobby__data_8043EF38[];
extern const char lobby_debug_burst_player_format[];
extern const char lobby_debug_udp_close_player_format[];
extern s32 TLobby__designated_client_id;
extern saddr local_client_id;
void on_game_player_add__6TLobbyFiii(saddr arg0, s32 arg1, s32 arg2);
s32 queue_destruction__7TObjectFv(void *);
void set_menu_mode_2__6TLobbyFv();
extern const char lobby_window_title_information[];
void open_information_list__6TLobbyFiPv(s32 arg0, Ent_80136FA0 *arg1);
s32 TLobby__sub_8013F810(void *, void *, s32, void *);
void bswap_6x6E_sync_game_state__6TLobbyFPv(void *p);
void import_sync_records__6TLobbyFPs(void *, u16);
void activate_triggered_floor_events(void);
void handle_6x6E_sync_game_state(Pkt_8013566C *arg0);
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

void mark_area_change_pending();
u16 get_entity_id(void *);
void * get_current_floor();
void TLobby__sub_800703D0(void *, void *);
void TLobby__sub_80077798(void *, void *);
void update_idle_timeout__6TLobbyFPv(u8 *arg0);
u8 * init_idle_timeout_timer(u8 *arg0, saddr arg1);
void handle_6x70_sync_player_disp_and_inventory(Pkt_801354AC *arg0);
void handle_6x6D_sync_game_state(Pkt_8013574C *arg0);
void handle_6x6C_sync_game_state(Pkt_801357F8 *arg0);
void handle_6x6B_sync_game_state(Pkt_801358B4 *arg0);
void TLobby__sub_80135FFC(void);
void retire_lobby_player__6TLobbyFii(saddr idx, s32 v);
void on_lobby_player_add__6TLobbyFii(saddr arg0, s32 arg1);
void remove_player__6TLobbyFUiii(uaddr arg0, s32 arg1, s32 arg2);
void handle_lobby_enter__6TLobbyFPviiiiiii(Ent_801368B0 *ents, s32 n, s32 client_id, s32 leader, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void handle_game_join__6TLobbyFPv(Pkt_80136C94 *pkt);
void add_lobby_members__6TLobbyFPvisi(Ent_801368B0 *, s32, s32, s32);
void destroy_all_objects__6TLobbyFv();
void set_menu_mode_1__6TLobbyFv(void);
void set_menu_mode_0__6TLobbyFv(void);
s32 open_hard_keyboard__6TLobbyFPv(void *);
void bswap_player_data__6TLobbyFi(void *);
void set_player_count__6TLobbyFi(s32);
s32 bswap_and_send_extended_subcommand(int, void *);
s32 bswap_and_handle_packet__6TLobbyFii(void *, void *);
s32 TLobby__sub_8013A578(void *);
void fn_8013ACE4(s32);
s32 mem_free(int);
u8 * mem_alloc(s32);
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
void * get_window_layout_position(int);

extern u8 TLobby__data_805011D8[];
extern s32 TLobby__data_805D4E30;
u8 *TLobby__protocol_instance;
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
u32 TLobby_warp_menu_window;
u32 lobby_com_card_window;
s32 lobby_make_team_menu_window;
u32 lobby_make_team_window;
u32 lobby_keyboard_prompt_window;
u32 lobby_keyboard_controller;
u32 lobby_scroll_text_window;
s32 TLobby__player_setup_pending;
s32 lobby_selected_game_list_index;
s32 TLobby__join_lobby_controller;
s32 TLobby__idle_timeout_object;
extern u32 *quest_object_entries;
extern S12_801358B4 *TLobby__data_805D6144;
extern u32 TLobby__data_805D6148;
extern u32 TLobby__data_805D614C;
extern const char TLobby__data_805DB0B0[4];
extern u8 TLobby__sub_801371B0[];
extern const Pair_80135E7C lbl_8043EE18[];
extern const Pair_80135E7C lbl_8043EE20[];
extern const char lobby_msg_information_counter[];
void fn_80338D58(void *list, s32 flag, const char *name, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 index);
extern NJS_POINT2 lbl_8043EE28[];
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
extern RecoveredGlobal_80135198_lbl_804A7008 lbl_804A7008;
extern char lobby_idle_timeout_text_buffer[];
extern RecoveredGlobal_80135974_lbl_805127F8 quest_story_flags_by_difficulty;
extern s32 game_difficulty_selection;
extern Mgr_801361E8 *game_protocol_instance;
extern s32 quest_download_active;
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

extern const char lobby_debug_duplicate_player_format[];
namespace PD_data {
extern "C" {
typedef struct Server_801399B8 {
    const char *host;
    s32 port;
} Server_801399B8;
void __dt__13TUnk_804A7008Fv();
void update_idle_timeout__6TLobbyFPv();
void TLobby__sub_8013A2DC();
void render_shadows__7TObjectFv();
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
void *lbl_804A7008[6] = { 0, 0, (void *)__dt__13TUnk_804A7008Fv, (void *)update_idle_timeout__6TLobbyFPv, (void *)TLobby__sub_8013A2DC, (void *)render_shadows__7TObjectFv };
}
}
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
    a.kb = open_hard_keyboard__6TLobbyFPv((void *)local_client_id) != 0 ? 1 : 0;
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
    TLobby__sub_800703D0(d.b, card + 0x21C4);
    d.h[0] = *(u16 *)(card + 0x21A8);
    d.h[1] = *(u16 *)(card + 0x21AA);
    d.h[2] = *(u16 *)(card + 0x21AC);
    d.h[3] = *(u16 *)(card + 0x21AE);
    d.h[4] = *(u16 *)(card + 0x21B0);
    d.h[5] = *(u16 *)(card + 0x21B2);
    d.h[6] = *(u16 *)(card + 0x21B4);
    d.w0 = *(u32 *)(card + 0x21B8);
    d.w1 = *(u32 *)(card + 0x21BC);
    send_player_data_98__9TProtocolFPvPvPvPvPvPvPv((*(void * *)&TLobby__protocol_instance), (void *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF), &d, &a, b, e, c);
}

void update_idle_timeout__6TLobbyFPv(u8 *object) {
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
                sprintf(lobby_idle_timeout_text_buffer, get_seq_phase__6TLobbyFPv(0x1F), t->limit - elapsed);
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
            sprintf(lobby_idle_timeout_text_buffer, get_seq_phase__6TLobbyFPv(0x1F), limit - elapsed);
        }
        break;
    }
}

u8 *init_idle_timeout_timer(u8 *arg0, saddr arg1) {
    s32 sp8;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A7008.value;
    getDateStamp((DateStamp *)(&sp8));
    DateToSeconds((DateStamp *)(&sp8), (int *)(arg0 + 0x1C));
    ((TUnk_804A7008 *)arg0)->m_20 = (s32) *(s32 *)((s8 *)arg0 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x24) = ((TLobby *)local_client_id)->get_table_entry_by_index();
    ((TUnk_804A7008 *)arg0)->m_28 = 0;
    TLobby__idle_timeout_object = 0;
    return arg0;
}
}
void activate_keyboard();
void TLobby::open_udp_socket_for_player() {
    saddr arg0 = (saddr)this;
    TPacket *o = new TPacket((TObject *)game_protocol_instance);
    if (o != NULL) {
        o->m_id = arg0;
        o->set_ip_address(game_join_player_records[arg0].ip);
        o->m_dst_port = local_client_id + 0xFA0;
        o->m_src_port = arg0 + 0xFA0;
        s32 v = o->open();
        lobby_debug_printf_stub(lobby_debug_udp_open_format, v, o->m_dst_addr.addr_bytes[0], o->m_dst_addr.addr_bytes[1], o->m_dst_addr.addr_bytes[2], o->m_dst_addr.addr_bytes[3]);
    }
}
void send_6x6F_quest_flags(saddr arg0);
void restore_switch_table(saddr arg0, s32 arg1);
extern const char lobby_debug_rcv_set_flag_format[];
extern s16 TLobby__data_805D5CE8;
void set_world_section_id(void *, s32);
void handle_6x6F_set_quest_flags_v2(saddr arg0);
void handle_6x72_done_loading_into_game(void);
void bswap_object_source_record(void *);
void set_area_random_seed(int a0);
void *create_remote_player_object(void *arg0);
void set_floor_map_variant(s32 arg0, s32 arg1);
s32 request_story_select_state(s32 arg0);
u32 copy_switch_table(void *destination);
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
                if (((void *(*)(s32))get_player_by_client_id)(i) == NULL) {
                    e = (LEntry_801352C0 *)TLobby__data_80506A6C;
                    e += i;
                    p = create_player_object(i, 4, e->body);
                    ((TLobby *)(p + 0xDAC))->copy_header_struct(e);
                    ((VObj_18_9029aa *)p)->m6();
                    ((TLobby *)i)->open_udp_socket_for_player();
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
        bswap_player_data__6TLobbyFi(disp);
        if (disp->id != local_client_id) {
            p = (Obj_801354AC *)get_player_by_client_id((void *)disp->id);
            if (p != NULL) {
                delete p;
            }
            plr = (Plr_801354AC *)create_remote_player_object(disp);
            strncpy(TLobby__player_names[get_entity_id(plr)], plr->m10(), 0x10);
            ((TLobby *)(disp->id))->open_udp_socket_for_player();
            lobby_debug_printf_stub(lobby_debug_create_player_format, get_entity_id(plr));
        }
    }
}

void send_6x70_player_data__6TLobbyFi(saddr arg0) {
    Stack_80135598 stack;
    u8 *temp_r3;
    init_player_join_record(&stack.sp8);
    temp_r3 = (u8 *)(mem_alloc(0x494));
    if (temp_r3 != NULL) {
        TObjPlayer::fill_player_record((void *) (get_player_by_client_id((void *)local_client_id)), temp_r3 + 8);
        *(s8 *)((s8 *)temp_r3 + 0) = 0x70;
        *(s8 *)((s8 *)temp_r3 + 1) = 0;
        *(s16 *)((s8 *)temp_r3 + 2) = (s16) local_client_id;
        *(s32 *)((s8 *)temp_r3 + 4) = 0x494;
        bswap_and_send_extended_subcommand((saddr)temp_r3, (void *)arg0);
        mem_free((saddr)temp_r3);
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

typedef struct Pkt_8013566C Pkt_8013566C;

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
        bswap_6x6E_sync_game_state__6TLobbyFPv(buf);
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
        buf = mem_alloc(0x8000);
        if (buf != NULL) {
            tmp = ::operator new(0x7230);
            if (tmp != NULL) {
                TLobby__sub_8013F810(tmp, arg0->data + 0, len, buf);
                ::operator delete(tmp);
            }
            ((TLobby *)buf)->apply_sync_item_state();
            mem_free((saddr)buf);
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
    bswap_and_handle_packet__6TLobbyFii(&stack.sp8, (void *)arg0);
}
extern "C" {

void send_6x6E_sync_game_state__6TLobbyFi(saddr arg0) {
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
            bswap_6x6E_sync_game_state__6TLobbyFPv(hdr);
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
        bswap_and_send_extended_subcommand((saddr)buf, (void *)arg0);
        mem_free((saddr)buf);
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
        src = mem_alloc(0x8000);
        if (src != NULL) {
            memset(src, 0, 0x8000);
            n = ((TLobby *)src)->write_sync_item_state();
            tmp = ::operator new(0x7230);
            if (tmp != NULL) {
                len = ((TLobby *)tmp)->lz_compress_packet((void *)src, (s32)n, (s32 *)buf->data);
                ::operator delete(tmp);
            }
            mem_free((saddr)src);
        }
        buf->cmd = 0x6D;
        buf->flag = 0;
        buf->f2 = 0;
        buf->len = ((len + 3) & ~3) + 8;
        bswap_and_send_extended_subcommand((saddr)buf, (void *)arg0);
        mem_free((saddr)buf);
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
            mem_free((saddr)p);
            ::operator delete(tmp);
            buf->cmd = 0x6C;
            buf->flag = 0;
            buf->f2 = 0;
            buf->len = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand((saddr)buf, (void *)arg0);
        }
        mem_free((saddr)buf);
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
            mem_free((saddr)p);
            ::operator delete(tmp);
            buf->cmd = 0x6B;
            buf->flag = 0;
            buf->f2 = 0;
            buf->len = ((len + 3) & ~3) + 8;
            bswap_and_send_extended_subcommand((saddr)buf, (void *)arg0);
        }
        mem_free((saddr)buf);
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
}
extern "C" {

struct Rec_801378AC;
extern const char lobby_debug_my_player_format[];
extern const char lobby_list_savedata_format[];
extern const char lobby_list_duplicate_my_player_format[];
extern const char lobby_list_block_range_format[];
void close_all_windows__6TLobbyFv(void);
void *__ct__11TWindowRoomFPc(void *self, char *title);
void handle_chat_message__11TWindowCtrlFPc(char *);

#pragma push
#pragma opt_propagation off
#pragma pop
}

#pragma push
namespace P1_80137188 {

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
extern const NJS_POINT2 lbl_8043EE10[];
s32 get_window_layout_position(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
void TLobby__sub_801371B0(s32 arg0);
extern uaddr TLobby__download_list_window;
extern const NJS_POINT2 lbl_8043EE08[];
s32 get_window_layout_position(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
void TLobby__sub_80137228(s32 arg0);
void disable_window_flags__6TLobbyFPv(void* a0);
void handle_state__6TLobbyFi(s32 arg0);
s32 TLobby__sub_80146740();
s32 close_and_set_state_13__6TLobbyFv(s32);
s32 reset_state__6TLobbyFv(s32);

    extern int local_client_id;

extern saddr TLobby__protocol_instance;

}
}
#pragma pop

#pragma push
namespace P2_8013731C {

extern "C" {

void send_position_update__6TLobbyFv(void);
s32 increment_frame__23TAdSinglePlyChrSelectGCFv();
s32 get_player_count__23TAdSinglePlyChrSelectGCFv();

extern saddr TLobby__protocol_instance;

}
}
#pragma pop

#pragma push
void send_register_9c(u8 *arg0);
void buffer_reset(void);
namespace P3_80137360 {
extern "C" {
void reset_state__6TLobbyFv(void);
void TLobby__sub_801384E4(void);
s32 __ct__13GameListEntryFv(s32 arg0);
void show_join_entry_message(s32 arg0);
void show_seq_phase_message__6TLobbyFi(s32 arg0);
}

struct Rec_801378AC { u8 b[0x43c]; };

extern "C" {
extern void *TLobby__protocol_instance;
extern const char lobby_msg_registed[];
extern const char lobby_msg_name_taken[];
void lobby_debug_printf_stub(const char *fmt, ...);
void handle_register_name_result__6TLobbyFi(s32 ok);
extern void *TLobby__protocol_instance;
extern const char lobby_msg_regist_check_ok[];
void lobby_debug_printf_stub(const char *fmt, ...);
void handle_regist_check__6TLobbyFi(s32 ok);
extern Rec_801378AC TLobby__data_80506A6C[];
extern s32 TLobby__deferred_player_setup_state;
extern s16 TLobby__data_805D558C;
extern s16 TLobby__pending_member_count;
extern s32 TLobby__designated_client_id;
void copy_member_record__6TLobbyFPvPv(Rec_801378AC *dst, Rec_801378AC *src);
void add_lobby_members__6TLobbyFPvisi(Rec_801378AC *src, s32 n, s16 v, s32 w);
void lobby_debug_printf_stub(const char *fmt, ...);
s32 increment_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 get_player_count__23TAdSinglePlyChrSelectGCFv(void);
extern const char lobby_msg_login_success[];
extern void *TLobby__protocol_instance;
extern s32 TLobby__login_pending_flag;
extern s32 lobby_login_result_flag;
void handle_login_result__6TLobbyFUi(u32 arg0);
u8 *get_character_save_record(u32);
s32 open_hard_keyboard__6TLobbyFPv(void *);
void TLobby__sub_80077798(void *, void *);
s32 get_flag_bit0__6TLobbyFv(void);
char *get_card_window_area__6TLobbyFv(void);
void TLobby__sub_800703D0(void *, void *);
void send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(void *, void *, void *, void *, void *, void *, void *);
extern saddr local_client_id;
extern void *TLobby__protocol_instance;
void send_selected_character__6TLobbyFv(void);
void lobby_debug_printf_stub(const char *fmt, ...);
s32 send_login_9e_extended__6TLobbyFPvPvi(int, void *, int);
extern const char lobby_msg_regist_check_ok[];
extern void *TLobby__protocol_instance;
void handle_verify_result__6TLobbyFUi(u32 arg0);
void lobby_debug_printf_stub(const char *fmt, ...);
void *get_player_by_client_id(s32);
s32 send_login_9e_extended__6TLobbyFPvPvi(int, void *, int);
extern const char lobby_msg_registed[];
extern const char lobby_msg_name_taken[];
extern saddr local_client_id;
extern void *TLobby__protocol_instance;
void handle_register_result__6TLobbyFi(s32 arg0);
void construct_lobby_players(Rec_801378AC *, s32, int, s32);
extern Rec_801378AC TLobby__data_80506A6C[];
extern s32 TLobby__designated_client_id;
extern void *TLobby__protocol_instance;
extern s16 TLobby__data_805D558C;
extern s16 TLobby__pending_member_count;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__player_setup_pending;
void process_deferred_player_setup__6TLobbyFv(void);
void queue_static_object_destruction__6TLobbyFv(void);
void reset_state_flags__6TLobbyFv(void);
s32 queue_destruction__7TObjectFv(s32);

extern saddr TLobby__join_lobby_controller;

extern void *TLobby__protocol_instance;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__data_805D5594;
extern saddr TLobby__current_dialog_window;
extern s32 TLobby__player_setup_pending;

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

}

struct RecoveredGlobal_80137B50___vt__6TLobby {
    s32 value;
    u8 remaining[0x14];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
s32 __dt__7TObjectFv(void *, int);
void destroy_all_objects__6TLobbyFv(void);
extern RecoveredGlobal_80137B50___vt__6TLobby __vt__6TLobby;
extern s32 TLobby__data_805D4E30;
extern s32 TLobby__lobby_entered_flag;
extern s32 TLobby__data_805D5588;
extern s16 TLobby__data_805D558C;
extern s16 TLobby__pending_member_count;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__data_805D5594;
extern s32 TLobby__join_state_flag;
extern s32 TLobby__date_seconds;
extern s32 TLobby__event_theme_id;
extern s32 TLobby__card_list_selected_index;
extern s32 TLobby__idle_timeout_active;
extern s32 TLobby__data_805D55AC;
extern s32 TLobby__lobby_number;
extern s32 TLobby__join_lobby_idle_timer;
extern s32 TLobby__data_805D55B8;
extern s32 TLobby__login_pending_flag;
extern s32 lbl_805D55C0;
extern s32 TLobby__player_setup_pending;
extern s32 lobby_selected_game_list_index;
extern saddr TLobby__join_lobby_controller;
u8 *__dt__6TLobbyFv(u8 *arg0, s16 arg1);
extern uaddr TLobby__download_list_window;
extern s32 TLobby__data_805D5594;
extern const NJS_POINT2 lbl_8043EE00[];
saddr get_window_layout_position(s32);
void TQuestListOnline__sub_8013ACF4(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
void TLobby__sub_80137C10(s32 arg0);
void destroy_all_objects__6TLobbyFv(void);
void init_player_window_effect__6TLobbyFv(void);
void update_com_card_window__6TLobbyFv(void);
void update_player_window__6TLobbyFv(void);
s32 clear_lobby_flag__10TObjPlayerFPv();
void close_all_windows__6TLobbyFv(void);
s32 send_lobby_arrow__9TProtocolFUc(s32, s32);

extern uaddr TLobby__card_list_window;
extern uaddr TLobby__download_list_window;
extern uaddr TLobby__list_window;
extern uaddr lobby_player_construction_window;
extern uaddr TLobby__join_entry_window_obj;
extern uaddr TLobby_warp_menu_window;
extern uaddr lobby_com_card_window;
extern uaddr lobby_make_team_window;
extern uaddr lobby_keyboard_prompt_window;
extern uaddr lobby_keyboard_controller;
extern uaddr lobby_scroll_text_window;

extern saddr local_client_id;

LAYOUT_ASSERT(RecoveredGlobal_80137B50___vt__6TLobby_size, sizeof(RecoveredGlobal_80137B50___vt__6TLobby) == 0x18);

extern saddr local_client_id;

extern uaddr lobby_com_card_window;

void open_city_warp_menu__6TLobbyFv(void);
saddr get_seq_phase__6TLobbyFPv(s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 get_window_layout_position(s32);

extern s32 TLobby__data_805D5594;

void close_and_set_state_12__6TLobbyFv(void);
void open_keyboard_window__6TLobbyFv(void);
void send_room_change__6TLobbyFi(s32 arg0);
saddr get_window_layout_position(s32);
void close_all_windows__6TLobbyFv(void);

extern s32 TLobby__data_805D5588;
extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;

extern saddr local_client_id;
extern s32 TLobby__data_805D5594;
extern uaddr lobby_keyboard_prompt_window;
extern saddr TLobby__join_lobby_controller;
extern s32 lbl_805DB0B4;

void close_and_send_text_list__6TLobbyFv(void);
void close_all_windows__6TLobbyFv(void);

void close_menu_windows__6TLobbyFv(void);
extern void open_ship_block_select_menu__6TLobbyFiPvPv(void);

extern void *TLobby__protocol_instance;
extern s32 TLobby__data_805D5594;

void return_to_main_menu__6TLobbyFv(void);
void open_ship_block_select_menu__6TLobbyFiPvPv();

extern void *TLobby__protocol_instance;
extern s32 TLobby__data_805D5594;
extern uaddr TLobby__card_list_window;
extern uaddr TLobby__download_list_window;
extern uaddr TLobby__list_window;
extern uaddr TLobby_warp_menu_window;
extern uaddr lobby_com_card_window;

int close_all_windows__6TLobbyFPv(void* p);
void open_warp_menu__6TLobbyFv(void);
s32 get_window_layout_position(s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
saddr get_seq_phase__6TLobbyFPv(s32);

extern s32 TLobby__data_805D5594;

void open_make_team_window__6TLobbyFi(s32 arg0);
s32 TWindowMakeTeam__ct(s32, s32, s32);

extern s32 TLobby__data_805D5594;
extern saddr TLobby__join_lobby_controller;

void open_menu_window__6TLobbyFv(void);
saddr get_seq_phase__6TLobbyFPv(s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 get_window_layout_position(s32);

extern s32 TLobby__data_805D5594;
extern uaddr lobby_com_card_window;
extern saddr lobby_make_team_menu_window;

void request_game_list__6TLobbyFv(void);

extern s32 TLobby__data_805D5594;

void show_dialog_value_line(saddr arg0);
saddr get_seq_phase__6TLobbyFPv(s32);
extern char lbl_80509D3C[];
extern char lobby_join_message_buffer[];
extern void *TLobby__protocol_instance;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__data_805D5594;
extern s32 TLobby__join_lobby_idle_timer;
extern s32 lbl_805D55C0;
extern saddr TLobby__current_dialog_window;
extern s32 TLobby__player_setup_pending;
void close_and_set_state_13__6TLobbyFv(void);
void create_warp_menu__6TLobbyFv(void);
void open_lobby_warp_menu__6TLobbyFv(void);
void update_state__6TLobbyFv(void);
s32 get_window_layout_position(s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
saddr get_seq_phase__6TLobbyFPv(s32);

extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;
extern s32 TLobby__join_lobby_idle_timer;
extern s32 lbl_805D55C0;

extern void *TLobby__protocol_instance;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__data_805D5594;
extern s32 TLobby__join_lobby_idle_timer;
extern s32 lbl_805D55C0;
extern saddr TLobby__current_dialog_window;
extern s32 TLobby__player_setup_pending;

extern s32 TLobby__data_805D5594;
extern s32 TLobby__lobby_number;

void destroy_lobby_ui__6TLobbyFv(void);
void set_menu_mode_0__6TLobbyFv(void);
void set_menu_mode_1__6TLobbyFv(void);
void set_menu_mode_2__6TLobbyFv(void);

extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;

extern s32 TLobby__data_805D5594;
extern uaddr TLobby__card_list_window;
extern uaddr TLobby__download_list_window;
extern uaddr TLobby__list_window;
extern uaddr TLobby__join_entry_window_obj;
extern uaddr TLobby_warp_menu_window;
extern uaddr lobby_com_card_window;
extern uaddr lobby_make_team_window;
extern uaddr lobby_keyboard_prompt_window;
extern uaddr lobby_scroll_text_window;

extern s32 TLobby__data_805D5594;
extern uaddr TLobby__card_list_window;
extern uaddr TLobby__download_list_window;
extern uaddr TLobby__list_window;
extern uaddr TLobby__join_entry_window_obj;
extern uaddr TLobby_warp_menu_window;
extern uaddr lobby_com_card_window;
extern uaddr lobby_make_team_window;
extern uaddr lobby_keyboard_prompt_window;
extern uaddr lobby_keyboard_controller;
extern uaddr lobby_scroll_text_window;

}

struct Entry_80138B7C { u8 b[0x1C]; };

struct Card_80138B7C { u8 b[0x98]; };

struct Lobby_80138B7C { u8 pad[0x2C68]; Card_80138B7C cards[1]; };

extern "C" {
void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *, void *);
void return_to_main_menu__6TLobbyFv(void);
void close_all_windows__6TLobbyFv(void);
extern s8 controller_input_state[];
extern s32 TLobby__card_list_selected_index;
extern uaddr TLobby__card_list_window;
extern uaddr TLobby__download_list_window;
extern uaddr TLobby__list_window;
void update_card_list_window__6TLobbyFv(void);
void update_scroll_close__6TLobbyFv(void);
void handle_short_list_input__6TLobbyFv(void);
void update_short_list__6TLobbyFv(void);
void close_all_windows__6TLobbyFv(void);
s32 reset_controller_input_state();

extern s8 controller_input_state[];
extern uaddr lobby_scroll_text_window;

extern s8 controller_input_state[];
extern uaddr TLobby__join_entry_window_obj;

extern s8 controller_input_state[];
extern uaddr TLobby__download_list_window;

}

struct GLE_80138D3C_80137188 { char pad[0x1c]; };
struct GBig_80138D3C_80137188 { char pad[0x1da8]; GLE_80138D3C_80137188 arr[1]; };

extern "C" {
void open_make_team_window__6TLobbyFi(s32);
void close_all_windows__6TLobbyFv(void);
void close_com_card_window__6TLobbyFv(void);
void update_make_team_menu__6TLobbyFv(void);
void handle_comcard_window__6TLobbyFv(void);
s32 __ct__16TPlyGuildCardTagFv();
void close_all_windows__6TLobbyFv(void);
s32 mem_free(s32);

extern uaddr lobby_keyboard_controller;
extern s32 lobby_selected_game_list_index;

}

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

extern "C" {
extern s8 controller_input_state[];
extern s32 TLobby__join_lobby_idle_timer;
void set_queued_main_phase(s32);
void request_main_phase(s32);
void queue_join_entry_exit_on_input(void *self);
void close_and_set_state_12__6TLobbyFv();
extern const char lobby_window_title_block_jump[];
extern s8 controller_input_state[];
extern uaddr TLobby__list_window;
void update_block_jump_list__6TLobbyFv(void);
void close_and_set_state_12__6TLobbyFv();
extern const char lobby_window_title_ship_jump[];
extern s8 controller_input_state[];
extern uaddr TLobby__list_window;
void update_ship_select_window__6TLobbyFv(void);
void close_all_windows__6TLobbyFv(void);
extern s8 controller_input_state[];
extern uaddr TLobby__list_window;
extern s32 lobby_selected_game_list_index;
void update_game_list_menu__6TLobbyFv(void);
void handle_com_card__6TLobbyFv(void);
void handle_create_game_window__6TLobbyFv(void);
void update__6TLobbyFv(void);
s32 reset_controller_input_state();
s32 TLobby__sub_8013AD50(u32);
u8 TLobby__sub_8013AD5C(u32);
s8 TLobby__sub_8013AD6C(u32);
s32 TLobby__sub_8013AD74(u32);
s32 TWindowMakeTeam__sub_80264B24(u32);
s32 TWindowMakeTeam__sub_80264B38(u32);
void close_all_windows__6TLobbyFv(void);


extern uaddr lobby_make_team_window;

extern s8 controller_input_state[];
extern uaddr TLobby__join_entry_window_obj;

extern uaddr lobby_com_card_window;

}

struct GameListEntry_80139538_80137188 { char pad[0x1C]; };
struct Root_80139538_80137188 { char pad[0x1DA8]; struct GameListEntry_80139538_80137188 entries[1]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Pad_801395D8 { u8 pad[0x10]; u32 flags; };

struct Ent_801395D8 { u8 b[0x1C]; };

struct Lst_801395D8 { u8 pad[0x1DA8]; Ent_801395D8 e[1]; };

struct Flag_80139690 { u8 pad[0x2A]; s8 flag; };

extern "C" {
extern uaddr TLobby__join_entry_window_obj;
extern const NJS_POINT2 lbl_8043EDF8[];
s32 get_window_layout_position(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
s32 get_seq_phase__6TLobbyFPv(s32);
extern const NJS_POINT2 lbl_8043EDF0[];
extern const f32 lbl_805DB0B8;
s32 get_window_layout_position(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
void show_dialog_value_line(s32 arg0);
extern const NJS_POINT2 lbl_8043EDE8[];
extern const f32 lbl_805DB0B8;
s32 get_window_layout_position(s32);
u32 create_message_window_for_size(s32 arg0, void *arg1);
s32 get_seq_phase__6TLobbyFPv(s32);
extern const char lobby_window_title_taisen_team[];
extern s8 controller_input_state[];
extern uaddr TLobby__list_window;
void handle_team_select__6TLobbyFv(void);
void func_80019A68__Fv(void);
void update_com_card_window__6TLobbyFv(void);
void update_state__6TLobbyFv(void);
void update_scroll_close__6TLobbyFv(void);
void handle_short_list_input__6TLobbyFv(void);
void update_short_list__6TLobbyFv(void);
void update_card_list_window__6TLobbyFv(void);
void handle_comcard_window__6TLobbyFv(void);
void update_make_team_menu__6TLobbyFv(void);
void handle_create_game_window__6TLobbyFv(void);
void update__6TLobbyFv(void);
void update_block_jump_list__6TLobbyFv(void);
void update_ship_select_window__6TLobbyFv(void);
void handle_com_card__6TLobbyFv(void);
void update_game_list_menu__6TLobbyFv(void);
void update_menu_window__6TLobbyFv(void);
void handle_warp_menu_input__6TLobbyFv(void);
void handle_game_list_select__6TLobbyFv(void);
void handle_team_select__6TLobbyFv(void);
s32 get_link_status__Fv(void);
s32 poll_memcard_result(saddr);
extern s32 quest_download_active;
void run_task__6TLobbyFv(void *self);
void close_com_card_window__6TLobbyFv(void);
void handle_game_list_select__6TLobbyFv(void);
void handle_warp_menu_input__6TLobbyFv(void);
void update_menu_window__6TLobbyFv(void);
void close_all_windows__6TLobbyFv(void);

extern uaddr lobby_com_card_window;

extern uaddr TLobby_warp_menu_window;

extern uaddr TLobby__list_window;

struct Root_80139538_80137188;
#define CALL_80139690(f) ((void (*)(void *))f)(self)

}
}
#pragma pop

#pragma defer_codegen on
namespace P3_80137360 {

void show_seq_phase_message__6TLobbyFi(s32 arg0) {
    if ((*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) == 0) {
        NJS_POINT2 tmp = lbl_8043EDE8[0];
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = create_message_window_for_size(get_window_layout_position(0xc1), &tmp);
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->set_depth(lbl_805DB0B8);
    }
    ((TWindowMessage *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->append_line((int)(get_seq_phase__6TLobbyFPv(arg0)), (int)1);
}

void show_dialog_value_line(saddr arg0) {
    if ((*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) == 0) {
        NJS_POINT2 tmp = lbl_8043EDF0[0];
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = create_message_window_for_size(get_window_layout_position(0xc1), &tmp);
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->set_depth(lbl_805DB0B8);
    }
    ((TWindowMessage *)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))))->append_line((int)arg0, (int)1);
}

void close_com_card_window__6TLobbyFv(void) {
    if ((u32) (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) != 0U) {
        ((TWindowBase *)((void*)(*(uaddr *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window)))))->close();
        (*(u32 *)&(*(u32 *)&(*(u32 *)&TLobby__current_dialog_window))) = 0U;
    }
}

void show_join_entry_message(s32 arg0) {
    if (TLobby__join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EDF8[0];
        TLobby__join_entry_window_obj = create_message_window_for_size(get_window_layout_position(0xc2), &tmp);
    }
    ((TWindowMessage *)TLobby__join_entry_window_obj)->append_line((int)(get_seq_phase__6TLobbyFPv(arg0)), (int)1);
}

void run_task__6TLobbyFv(void *self) {
    s32 r;
    switch ((*(u32 *)&TLobby__data_805D5594)) {
    case 1:
        CALL_80139690(handle_team_select__6TLobbyFv);
        break;
    case 2:
        CALL_80139690(handle_team_select__6TLobbyFv);
        break;
    case 3:
        CALL_80139690(handle_warp_menu_input__6TLobbyFv);
        break;
    case 4:
        CALL_80139690(update_menu_window__6TLobbyFv);
        break;
    case 6:
        CALL_80139690(update_game_list_menu__6TLobbyFv);
        break;
    case 9:
        CALL_80139690(handle_comcard_window__6TLobbyFv);
        break;
    case 10:
        CALL_80139690(handle_create_game_window__6TLobbyFv);
        break;
    case 5:
        CALL_80139690(handle_com_card__6TLobbyFv);
        break;
    case 7:
        CALL_80139690(update_ship_select_window__6TLobbyFv);
        break;
    case 8:
        CALL_80139690(update_block_jump_list__6TLobbyFv);
        break;
    case 12:
        CALL_80139690(queue_join_entry_exit_on_input);
        return;
    case 13:
        CALL_80139690(update__6TLobbyFv);
        break;
    case 17:
        CALL_80139690(update_card_list_window__6TLobbyFv);
        break;
    case 20:
        CALL_80139690(update_short_list__6TLobbyFv);
        break;
    case 22:
        CALL_80139690(handle_short_list_input__6TLobbyFv);
        break;
    case 21:
        CALL_80139690(handle_game_list_select__6TLobbyFv);
        break;
    case 24:
        CALL_80139690(update_make_team_menu__6TLobbyFv);
        break;
    case 26:
        CALL_80139690(update_scroll_close__6TLobbyFv);
        break;
    case 25:
        CALL_80139690(update_com_card_window__6TLobbyFv);
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

void handle_team_select__6TLobbyFv(void) {
    s32 idx;
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((void *)((*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))))))->send_action(*(GameListEntry *)((void *)(&(*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))->e[idx])), (char *)((s32 *)lobby_window_title_taisen_team), (char *)((s32 *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0)))));
            ((s32 (*)())close_and_set_state_12__6TLobbyFv)();
            return;
        }
        if ((*(Pad_801395D8 **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801395D8 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance))))->e[idx]));
        }
    }
}

void handle_game_list_select__6TLobbyFv(void) {
    s32 temp_r31;

    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            temp_r31 = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))))->send_action(*(GameListEntry *)(&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&(*(struct Root_80139538_80137188 * *)&TLobby__protocol_instance)))->entries[temp_r31]), (char *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0))), (char *)(&(*(s32 *)&(*(s32 *)&TLobby__data_805DB0B0))));
            ((s32 (*)())close_and_set_state_12__6TLobbyFv)();
            return;
        }
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_cancelled() != 0) {
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            TLobby::close_all_windows();
        }
    }
}

void handle_warp_menu_input__6TLobbyFv(void) {
    s32 selected_menu_value;

    if ((u32) TLobby_warp_menu_window != 0U) {
        if (((TWindowMenu *)TLobby_warp_menu_window)->is_decided() != 0) {
            selected_menu_value = ((TWindowMenu *)TLobby_warp_menu_window)->get_selected_value();
            switch (selected_menu_value) {
            case 0:
                ((s32 (*)())create_warp_menu__6TLobbyFv)();
                return;
            case 1:
                ((s32 (*)())open_warp_menu__6TLobbyFv)();
                return;
            case 2:
                ((s32 (*)())close_and_send_text_list__6TLobbyFv)();
                return;
            case 3:
                ((s32 (*)())open_city_warp_menu__6TLobbyFv)();
                return;
            }
        } else if (((TWindowMenu *)TLobby_warp_menu_window)->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}

void update_menu_window__6TLobbyFv(void) {
    s32 selected_menu_value;

    if ((u32) lobby_com_card_window != 0U) {
        selected_menu_value = ((TWindowMenu *)((void*)lobby_com_card_window))->get_selected_value();
        if (((TWindowMenu *)lobby_com_card_window)->is_decided() != 0) {
            switch (selected_menu_value) {
            case 0:
                ((s32 (*)())request_game_list__6TLobbyFv)();
                return;
            case 1:
                ((s32 (*)())open_menu_window__6TLobbyFv)();
                return;
            case 2:
                ((s32 (*)())close_all_windows__6TLobbyFPv)();
                return;
            }
        } else if (((TWindowMenu *)lobby_com_card_window)->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}

void update_game_list_menu__6TLobbyFv(void) {
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            lobby_selected_game_list_index = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            if ((*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[lobby_selected_game_list_index].flags & 2) {
                ((s32 (*)())open_keyboard_window__6TLobbyFv)();
                return;
            }
            ((TProtocol *)((*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_action(*(GameListEntry *)(&(*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[lobby_selected_game_list_index]), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            ((s32 (*)())destroy_lobby_ui__6TLobbyFv)();
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
            if (lobby_selected_game_list_index < (*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->count) {
                ((TProtocol *)((*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801392F8 **)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[lobby_selected_game_list_index]));
            }
        }
    }
}

void handle_com_card__6TLobbyFv(void) {
    s32 temp_r3;

    if ((u32) lobby_com_card_window != 0U) {
        if (((TWindowMenu *)lobby_com_card_window)->is_decided() != 0) {
            ((s32 (*)())close_com_card_window__6TLobbyFv)();
            temp_r3 = ((TWindowMenu *)lobby_com_card_window)->get_selected_value();
            switch (temp_r3) {
            case 0:
                ((s32 (*)())return_to_main_menu__6TLobbyFv)();
                return;
            case 1:
                ((s32 (*)())close_menu_windows__6TLobbyFv)();
                return;
            }
        } else if (((TWindowMenu *)lobby_com_card_window)->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}

void update_ship_select_window__6TLobbyFv(void) {
    s32 idx;
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(Lst_801391BC * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_action(*(GameListEntry *)(&(*(Lst_801391BC * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[idx]), (char *)(lobby_window_title_ship_jump), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            close_and_set_state_12__6TLobbyFv();
            return;
        }
        if ((*(Pad_801391BC **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_801391BC * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_801391BC * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[idx]));
        }
    }
}

void update_block_jump_list__6TLobbyFv(void) {
    s32 idx;
    if (TLobby__list_window != 0U) {
        if (((TWindowMenuIconLine *)TLobby__list_window)->is_decided() != 0) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TWindowBase *)TLobby__list_window)->close();
            TLobby__list_window = 0U;
            ((TProtocol *)((*(Lst_80139104 * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_action(*(GameListEntry *)(&(*(Lst_80139104 * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[idx]), (char *)(lobby_window_title_block_jump), (char *)(&(*(char *)&(*(char *)&(*(char *)&TLobby__data_805DB0B0)))));
            close_and_set_state_12__6TLobbyFv();
            return;
        }
        if ((*(Pad_80139104 **)controller_input_state)->flags & 0x400) {
            idx = ((TWindowMenuIconLine *)TLobby__list_window)->get_cursor_value();
            ((TProtocol *)((*(Lst_80139104 * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))))->send_info(*(TPlyGuildCardTag *)(&(*(Lst_80139104 * *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))))->e[idx]));
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

void update__6TLobbyFv(void) {
    if ((u32) TLobby__join_entry_window_obj != 0U) {
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 8) != 0) {
            if (((TWindowMessagePage *)TLobby__join_entry_window_obj)->is_message_window_ready() == 0) {
                ((TWindowMessage *)TLobby__join_entry_window_obj)->complete_reveal();
            } else {
                ((TWindowBase *)TLobby__join_entry_window_obj)->close();
                TLobby__join_entry_window_obj = 0U;
                close_all_windows__6TLobbyFv();
                ((TProtocol *)((*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance)))))))->send_server_time_accepted();
            }
        }
    } else {
        TLobby::close_all_windows();
    }
    reset_controller_input_state();
}

void handle_create_game_window__6TLobbyFv(void) {
    s32 temp_r3;
    s32 temp_r30;
    u8 temp_r29;
    u8 temp_r28;
    u8 temp_r27;
    u8 temp_r0;

    if ((u32) lobby_make_team_window != 0U) {
        if (TLobby__sub_8013AD74(lobby_make_team_window) != 0) {
            temp_r3 = TWindowMakeTeam__sub_80264B38(lobby_make_team_window);
            if (temp_r3 != 0) {
                temp_r30 = TWindowMakeTeam__sub_80264B24(lobby_make_team_window);
                temp_r29 = TLobby__sub_8013AD6C(lobby_make_team_window) == 2;
                temp_r28 = ((TWindowMakeTeam *)lobby_make_team_window)->is_enabled();
                temp_r27 = (s8)((TLobby *)lobby_make_team_window)->get_mode() == 1;
                temp_r0 = TLobby__sub_8013AD5C(lobby_make_team_window);
                ((TProtocol *)(*(s32 *)&(*(s32 *)&(*(s32 *)&(*(s32 *)&TLobby__protocol_instance)))))->send_create_game((char *)temp_r3, (char *)temp_r30, temp_r28, temp_r29, temp_r27, temp_r0);
                ((s32 (*)())destroy_lobby_ui__6TLobbyFv)();
                return;
            }
            TLobby::close_all_windows();
            return;
        }
        if (TLobby__sub_8013AD50(lobby_make_team_window) != 0) {
            TLobby::close_all_windows();
        }
    }
}

void update_make_team_menu__6TLobbyFv(void) {
    s32 selected_menu_value;
    static s32 last_selection = 0;
    if ((void *) (*(u8 * *)&lobby_make_team_menu_window) != NULL) {
        selected_menu_value = ((TWindowMenu *)(*(u8 * *)&lobby_make_team_menu_window))->get_selected_value();
        if (last_selection != selected_menu_value) {
            last_selection = selected_menu_value;
            switch (selected_menu_value) {
            case 0:
                ((void (*)(s32))show_seq_phase_message__6TLobbyFi)(0x11);
                break;
            case 1:
                ((void (*)(s32))show_seq_phase_message__6TLobbyFi)(0x12);
                break;
            }
        }
        if (((TWindowMenu *)(*(u8 * *)&lobby_make_team_menu_window))->is_decided() != 0) {
            ((TWindowBase *)(*(u8 * *)&lobby_make_team_menu_window))->close();
            (*(u8 * *)&lobby_make_team_menu_window) = NULL;
            TLobby::close_com_card_window();
            if ((void *) (*(u8 * *)&TLobby_warp_menu_window) != NULL) {
                ((TWindowBase *)(*(u8 * *)&TLobby_warp_menu_window))->close();
                (*(u8 * *)&TLobby_warp_menu_window) = NULL;
            }
            if ((void *) (*(u8 * *)&lobby_com_card_window) != NULL) {
                ((TWindowBase *)(*(u8 * *)&lobby_com_card_window))->close();
                (*(u8 * *)&lobby_com_card_window) = NULL;
            }
            switch (selected_menu_value) {
            case 0:
                TLobby::open_make_team_window(1);
                return;
            case 1:
                TLobby::open_make_team_window(2);
                return;
            }
        } else if (((TWindowMenu *)(*(u8 * *)&lobby_make_team_menu_window))->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    }
}

void handle_comcard_window__6TLobbyFv(void) {
    saddr temp_r3;

    if ((u32) lobby_keyboard_controller != 0U) {
        if (((TKeyBoardControl *)lobby_keyboard_controller)->is_cancelled() != 0) {
            ((s32 (*)(u32))queue_destruction__7TObjectFv)(lobby_keyboard_controller);
            lobby_keyboard_controller = 0U;
            TLobby::close_all_windows();
            return;
        }
        if (((TKeyBoardControl *)lobby_keyboard_controller)->is_confirmed() != 0) {
            temp_r3 = (saddr)((TKeyBoardControl *)lobby_keyboard_controller)->realloc_buffer();
            ((TProtocol *)((*(GBig_80138D3C_80137188 * *)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)(&(*(GBig_80138D3C_80137188 * *)&TLobby__protocol_instance)->arr[lobby_selected_game_list_index]), (char *)(&(*(s32 *)&TLobby__data_805DB0B0)), (char *)(temp_r3));
            mem_free(temp_r3);
            ((s32 (*)(u32))queue_destruction__7TObjectFv)(lobby_keyboard_controller);
            lobby_keyboard_controller = 0U;
            ((TWindowBase *)(*(saddr *)&lobby_keyboard_prompt_window))->close();
            (*(s32 *)&lobby_keyboard_prompt_window) = 0;
            ((s32 (*)())destroy_lobby_ui__6TLobbyFv)();
        }
    }
}

s32 __ct__13GameListEntryFv(s32 arg0) {
    __ct__16TPlyGuildCardTagFv();
    return arg0;
}

void update_card_list_window__6TLobbyFv(void) {
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
        ((void (*)(void *))__ct__13GameListEntryFv)(&e);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e, &((Lobby_80138B7C *)(*(saddr *)&(*(s32 *)&TLobby__protocol_instance)))->cards[sel]);
        ((TProtocol *)(*(s32 *)&(*(s32 *)&TLobby__protocol_instance)))->send_action(*(GameListEntry *)&e, (char *)TLobby__data_805DB0B0, (char *)TLobby__data_805DB0B0);
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
            ((TWindowMessage *)TLobby__download_list_window)->append_line((saddr)(&((Lobby_80138B7C *)(*(saddr *)&(*(s32 *)&TLobby__protocol_instance)))->cards[sel].b[0x28]), (int)3);
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
        ((void (*)(void *))__ct__13GameListEntryFv)(&e2);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&e2, &((Lobby_80138B7C *)(*(saddr *)&(*(s32 *)&TLobby__protocol_instance)))->cards[sel]);
        ((TProtocol *)(*(s32 *)&(*(s32 *)&TLobby__protocol_instance)))->send_info(*(TPlyGuildCardTag *)&e2);
    } else if (btn & 2) {
        if (TLobby__card_list_window != 0) {
            ((TWindowBase *)TLobby__card_list_window)->close();
            TLobby__card_list_window = 0;
        } else {
            TLobby::return_to_main_menu();
        }
    }
}

void update_short_list__6TLobbyFv(void) {
    void *context;

    if ((u32) TLobby__download_list_window != 0U) {
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

void handle_short_list_input__6TLobbyFv(void) {
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

void update_scroll_close__6TLobbyFv(void) {
    if ((u32) lobby_scroll_text_window != 0U) {
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 0xE) != 0) {
            ((TAdScrollWinGC *)lobby_scroll_text_window)->close();
            lobby_scroll_text_window = 0U;
            ((s32 (*)())destroy_lobby_ui__6TLobbyFv)();
            reset_controller_input_state();
            ((TProtocol *)((*(s32 *)&(*(s32 *)&TLobby__protocol_instance))))->send_message_box_closed();
        }
    } else {
        TLobby::close_all_windows();
    }
}

void close_all_windows__6TLobbyFv(void) {
    if ((u32) TLobby__card_list_window != 0U) {
        ((TWindowBase *)TLobby__card_list_window)->close();
        TLobby__card_list_window = 0U;
    }
    if ((u32) TLobby__download_list_window != 0U) {
        ((TWindowBase *)TLobby__download_list_window)->close();
        TLobby__download_list_window = 0U;
    }
    if ((u32) TLobby__list_window != 0U) {
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
    if ((u32) TLobby_warp_menu_window != 0U) {
        ((TWindowBase *)TLobby_warp_menu_window)->close();
        TLobby_warp_menu_window = 0U;
    }
    if ((u32) lobby_com_card_window != 0U) {
        ((TWindowBase *)lobby_com_card_window)->close();
        lobby_com_card_window = 0U;
    }
    if ((u32) (*(u32 *)&(*(u32 *)&lobby_make_team_menu_window)) != 0U) {
        ((TWindowBase *)(*(uaddr *)&(*(u32 *)&lobby_make_team_menu_window)))->close();
        (*(u32 *)&(*(u32 *)&lobby_make_team_menu_window)) = 0U;
    }
    if ((u32) lobby_make_team_window != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)((void *)lobby_make_team_window);
        lobby_make_team_window = 0U;
    }
    if ((u32) lobby_keyboard_prompt_window != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)((void *)lobby_keyboard_prompt_window);
        lobby_keyboard_prompt_window = 0U;
    }
    if ((u32) lobby_keyboard_controller != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)((void *)lobby_keyboard_controller);
        lobby_keyboard_controller = 0U;
    }
    if ((u32) lobby_scroll_text_window != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)((void *)lobby_scroll_text_window);
        lobby_scroll_text_window = 0U;
    }
    ((s32 (*)())update_player_window__6TLobbyFv)();
    TLobby__data_805D5594 = 0;
}

void destroy_lobby_ui__6TLobbyFv(void) {
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
    temp = (void*)(uaddr)TLobby_warp_menu_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        TLobby_warp_menu_window = 0U;
    }
    temp = (void*)(uaddr)lobby_com_card_window;
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        lobby_com_card_window = 0U;
    }
    temp = (void*)(uaddr)(*(uaddr *)&lobby_make_team_menu_window);
    if (temp != 0) {
        ((TWindowBase *)temp)->close();
        (*(u32 *)&lobby_make_team_menu_window) = 0U;
    }
    temp = (void*)(uaddr)lobby_make_team_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
        lobby_make_team_window = 0U;
    }
    temp = (void*)(uaddr)lobby_keyboard_prompt_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
        lobby_keyboard_prompt_window = 0U;
    }
    temp = (void*)(uaddr)lobby_scroll_text_window;
    if (temp != 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(temp);
        lobby_scroll_text_window = 0U;
    }
    TLobby__data_805D5594 = 0xE;
}

void set_menu_mode_0__6TLobbyFv(void) {
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(0);
    TLobby__data_805D5594 = 1;
}

void set_menu_mode_1__6TLobbyFv(void) {
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(1);
    TLobby__data_805D5594 = 1;
}

void set_menu_mode_2__6TLobbyFv(void) {
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(2);
    TLobby__data_805D5594 = 0x15;
}

void open_lobby_warp_menu__6TLobbyFv(void) {
    s32 window_layout_position;
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(3);
    window_layout_position = get_window_layout_position(0xB4);
    if ((s32) TLobby__lobby_number < 0xD) {
        (*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)) = create_window_menu_default(window_layout_position, 2);
        forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)), get_seq_phase__6TLobbyFPv(0x35), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)), get_seq_phase__6TLobbyFPv(0x36), 6, 1);
    } else {
        (*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)) = create_window_menu_default(window_layout_position, 3);
        forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)), get_seq_phase__6TLobbyFPv(0x35), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)), get_seq_phase__6TLobbyFPv(0x36), 6, 1);
        forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&(*(s32 *)&TLobby_warp_menu_window)), get_seq_phase__6TLobbyFPv(0x47), 6, 3);
    }
    ((TWindowMenu *)(*(saddr *)&(*(s32 *)&TLobby_warp_menu_window)))->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>((*(saddr *)&(*(s32 *)&TLobby_warp_menu_window))));
    ((TWindowMenu *)(*(saddr *)&(*(s32 *)&TLobby_warp_menu_window)))->set_ready_flag();
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    TLobby__data_805D5594 = 3;
}

void TLobby__sub_801384E4(void) {
    if ((u32) (*(u32 *)&(*(u32 *)&TLobby__join_lobby_controller)) != 0U) {
        if ((s32) TLobby__player_setup_pending == 0) {
            if ((s32) TLobby__data_805D5594 != 0xC) {
                sprintf(lobby_join_message_buffer, (const char *)get_seq_phase__6TLobbyFPv(7), lbl_80509D3C);
                show_dialog_value_line((saddr)lobby_join_message_buffer);
                reinterpret_cast<TWindowBase *>(TLobby__current_dialog_window)->reparent_to_main_ctrl();
                ((s32 (*)())init_player_window_effect__6TLobbyFv)();
                TLobby__join_lobby_idle_timer = 0;
                TLobby__data_805D5594 = 0xC;
                if ((void *) TLobby__protocol_instance != NULL) {
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

void update_state__6TLobbyFv(void) {
    if ((u32) (*(u32 *)&(*(u32 *)&TLobby__join_lobby_controller)) != 0U) {
        if ((s32) TLobby__player_setup_pending == 0) {
            if ((s32) TLobby__data_805D5594 != 0xC) {
                ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(0x21);
                reinterpret_cast<TWindowBase *>(TLobby__current_dialog_window)->reparent_to_main_ctrl();
                ((s32 (*)())init_player_window_effect__6TLobbyFv)();
                TLobby__join_lobby_idle_timer = 0;
                TLobby__data_805D5594 = 0xC;
                if ((void *) TLobby__protocol_instance != NULL) {
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

void reset_state__6TLobbyFv(void) {
    ((s32 (*)())show_join_entry_message)();
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    TLobby__join_lobby_idle_timer = 0;
    TLobby__data_805D5594 = 0xC;
    lbl_805D55C0 = 1;
}

void close_and_set_state_13__6TLobbyFv(void) {
    ((s32 (*)())show_join_entry_message)();
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    TLobby__data_805D5594 = 0xD;
}

void create_warp_menu__6TLobbyFv(void) {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)(*(saddr *)&TLobby_warp_menu_window))->open();
    window_layout_position = get_window_layout_position(0xB5);
    (*(s32 *)&lobby_com_card_window) = create_window_menu_default(window_layout_position, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x39), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x3A), 6, 1);
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>((*(saddr *)&lobby_com_card_window)));
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->set_ready_flag();
    TLobby__data_805D5594 = 4;
}

void request_game_list__6TLobbyFv(void) {
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(4);
    if ((void *) (*(void * *)&TLobby_warp_menu_window) != 0) {
        ((TWindowBase *)(*(void * *)&TLobby_warp_menu_window))->close();
        (*(void * *)&TLobby_warp_menu_window) = 0;
    }
    if ((void *) (*(void * *)&lobby_com_card_window) != 0) {
        ((TWindowBase *)(*(void * *)&lobby_com_card_window))->close();
        (*(void * *)&lobby_com_card_window) = 0;
    }
    ((TProtocol *)((*(s32 *)&TLobby__protocol_instance)))->send_game_list();
    TLobby__data_805D5594 = 6;
}

void open_menu_window__6TLobbyFv(void) {
    uaddr tmp_e4 = lobby_com_card_window;
    if (tmp_e4 != 0U) {
        ((TWindowOptionCtrl *)tmp_e4)->open();
    }
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(0x11);
    lobby_make_team_menu_window = create_window_menu_default(get_window_layout_position(0xB6), 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii(lobby_make_team_menu_window, get_seq_phase__6TLobbyFPv(0x45), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii(lobby_make_team_menu_window, get_seq_phase__6TLobbyFPv(0x46), 6, 1);
    ((TWindowMenu *)lobby_make_team_menu_window)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(lobby_make_team_menu_window));
    ((TWindowMenu *)lobby_make_team_menu_window)->set_ready_flag();
    ((TWindowSubComCardList *)lobby_make_team_menu_window)->set_selected_index(0);
    TLobby__data_805D5594 = 0x18;
}

void open_make_team_window__6TLobbyFi(s32 arg0) {
    s32 var_r4;

    var_r4 = (saddr)TObject::operator new(0x38);
    if (var_r4 != 0) {
        var_r4 = TWindowMakeTeam__ct(var_r4, TLobby__join_lobby_controller, arg0);
    }
    (*(s32 *)&lobby_make_team_window) = var_r4;
    TLobby__data_805D5594 = 0xA;
}

int close_all_windows__6TLobbyFPv(void* p) { return ((int (*)(void*))close_all_windows__6TLobbyFv)(p); }

void open_warp_menu__6TLobbyFv(void) {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)(*(saddr *)&TLobby_warp_menu_window))->open();
    window_layout_position = get_window_layout_position(0xB5);
    (*(s32 *)&lobby_com_card_window) = create_window_menu_default(window_layout_position, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x3E), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x3F), 6, 1);
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>((*(saddr *)&lobby_com_card_window)));
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->set_ready_flag();
    TLobby__data_805D5594 = 5;
}

void return_to_main_menu__6TLobbyFv(void) {
    uaddr t;

    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(6);
    t = TLobby_warp_menu_window;
    if (t != 0U) {
        ((TWindowBase *)t)->close();
        TLobby_warp_menu_window = 0U;
    }
    t = lobby_com_card_window;
    if (t != 0U) {
        ((TWindowBase *)t)->close();
        lobby_com_card_window = 0U;
    }
    t = TLobby__download_list_window;
    if (t != 0U) {
        ((TWindowBase *)t)->close();
        TLobby__download_list_window = 0U;
    }
    t = TLobby__card_list_window;
    if (t != 0U) {
        ((TWindowBase *)t)->close();
        TLobby__card_list_window = 0U;
    }
    t = TLobby__list_window;
    if (t != 0U) {
        ((TWindowBase *)t)->close();
        TLobby__list_window = 0U;
    }
    *(void **)((s8 *)TLobby__protocol_instance + 0xBBE4) = (void *)&open_ship_block_select_menu__6TLobbyFiPvPv;
    ((TProtocol *)(TLobby__protocol_instance))->send_ship_list_request();
    TLobby__data_805D5594 = 7;
}

void close_menu_windows__6TLobbyFv(void) {
    ((s32 (*)(s32))show_seq_phase_message__6TLobbyFi)(6);
    ((TWindowBase *)(*(saddr *)&TLobby_warp_menu_window))->close();
    (*(s32 *)&TLobby_warp_menu_window) = 0;
    ((TWindowBase *)(*(saddr *)&lobby_com_card_window))->close();
    (*(s32 *)&lobby_com_card_window) = 0;
    *(void **)((s8 *)TLobby__protocol_instance + 0xBBE4) = (void *)open_ship_block_select_menu__6TLobbyFiPvPv;
    ((TProtocol *)(TLobby__protocol_instance))->send_block_list_request();
    TLobby__data_805D5594 = 8;
}

void close_and_send_text_list__6TLobbyFv(void) {
    TLobby::close_all_windows();
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    ((TProtocol *)((*(s32 *)&TLobby__protocol_instance)))->send_text_list();
}

void open_keyboard_window__6TLobbyFv(void) {
    saddr var_r0;
    s32 tmp_r3;

    if ((u32) (*(u32 *)&TLobby__current_dialog_window) != 0U) {
        ((TWindowBase *)(*(uaddr *)&TLobby__current_dialog_window))->close();
        (*(u32 *)&TLobby__current_dialog_window) = 0U;
    }
    if ((u32) lobby_keyboard_prompt_window == 0U) {
        static s32 *blank_entry = &lbl_805DB0B4;
        tmp_r3 = get_window_layout_position(0xC3);
        lobby_keyboard_prompt_window = ((u32 (*)(s32, s32))create_window_menu_default)(tmp_r3, 2);
        ((s32 (*)(u32, s32 *, s32, s32))forward_trade_action_default__16TObjCityMainWarpFPviii)(lobby_keyboard_prompt_window, ((s32 * (*)(s32))get_seq_phase__6TLobbyFPv)(0x44), 2, 0);
        ((s32 (*)(u32, s32 *, s32, s32))forward_trade_action_default__16TObjCityMainWarpFPviii)(lobby_keyboard_prompt_window, blank_entry, 2, 1);
        ((TWindowMenu *)lobby_keyboard_prompt_window)->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(lobby_keyboard_prompt_window));
        ((TAdChrSelASlotGC *)lobby_keyboard_prompt_window)->set_flag_40();
    }
    var_r0 = (saddr)new TKeyBoardControl((TObject *)TLobby__join_lobby_controller, 0x10, 0, 0, local_client_id);
    (*(s32 *)&lobby_keyboard_controller) = var_r0;
    ((TKeyBoardControl *)(*(saddr *)&lobby_keyboard_controller))->set_sub_position((u8 *)(get_window_layout_position(0xC4)));
    ((TKeyBoardControl *)(*(saddr *)&lobby_keyboard_controller))->set_hard_position((u8 *)get_window_layout_position(0xC5));
    TLobby__data_805D5594 = 9;
}

void close_and_set_state_12__6TLobbyFv(void) {
    TLobby::close_all_windows();
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    TLobby__data_805D5594 = 0x12;
}

void send_room_change__6TLobbyFi(s32 arg0) {
    TLobby__data_805D5588 = 1;
    ((s32 (*)())init_player_window_effect__6TLobbyFv)();
    ((TProtocol *)((*(s32 *)&TLobby__protocol_instance)))->send_room_change(arg0);
    TLobby__data_805D5594 = 0x13;
}

void open_city_warp_menu__6TLobbyFv(void) {
    s32 window_layout_position;
    ((TWindowOptionCtrl *)(*(saddr *)&TLobby_warp_menu_window))->open();
    window_layout_position = get_window_layout_position(0xB5);
    (*(s32 *)&lobby_com_card_window) = create_window_menu_default(window_layout_position, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x4C), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x48), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x49), 6, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x4A), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((*(s32 *)&lobby_com_card_window), get_seq_phase__6TLobbyFPv(0x4B), 6, 4);
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>((*(saddr *)&lobby_com_card_window)));
    ((TWindowMenu *)(*(saddr *)&lobby_com_card_window))->set_ready_flag();
    TLobby__data_805D5594 = 0x19;
}

void update_com_card_window__6TLobbyFv(void) {
    s32 selected_menu_value;

    if ((u32) lobby_com_card_window != 0U) {
        selected_menu_value = ((TWindowMenu *)lobby_com_card_window)->get_selected_value();
        if (((TWindowMenu *)lobby_com_card_window)->is_decided() != 0) {
            send_lobby_arrow__9TProtocolFUc((*(s32 *)&(*(s32 *)&TLobby__protocol_instance)), selected_menu_value);
            TLobby::close_all_windows();
            return;
        }
        if (((TWindowMenu *)lobby_com_card_window)->is_cancelled() != 0) {
            TLobby::close_all_windows();
        }
    } else {
        TLobby::close_all_windows();
    }
}

void init_player_window_effect__6TLobbyFv(void) {
    TObjPlayer *player = (TObjPlayer *)((u32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (player != 0) {
        player->init_effect_5f0();
    }
    TWindowCtrl::suppress_slot(local_client_id);
}

void update_player_window__6TLobbyFv(void) {
    if (((u32 (*)(s32))get_player_by_client_id)(local_client_id) != 0U) {
        clear_lobby_flag__10TObjPlayerFPv();
    }
    TWindowCtrl::unsuppress_slot(local_client_id);
}

void TLobby__sub_80137C10(s32 arg0) {
    if (TLobby__download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE00[0];
        TLobby__download_list_window = create_message_window_for_size(get_window_layout_position(0xc6), &tmp);
    }
    ((TWindowMessage *)TLobby__download_list_window)->append_line((int)arg0, (int)3);
    TLobby__data_805D5594 = 0x14;
    TQuestListOnline__sub_8013ACF4(0xb);
}

u8 *__dt__6TLobbyFv(u8 *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = &__vt__6TLobby.value;
        TLobby::destroy_all_objects();
        (*(s32 *)&TLobby__protocol_instance) = 0;
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
        TLobby__join_lobby_controller = 0;
        TLobby__data_805D4E30 = 0;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

void destroy_all_objects__6TLobbyFv(void) {
    if ((u32) TLobby__card_list_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__card_list_window);
        TLobby__card_list_window = 0U;
    }
    if ((u32) TLobby__download_list_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__download_list_window);
        TLobby__download_list_window = 0U;
    }
    if ((u32) TLobby__list_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby__list_window);
        TLobby__list_window = 0U;
    }
    if ((u32) lobby_player_construction_window != 0U) {
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
    if ((u32) TLobby_warp_menu_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)TLobby_warp_menu_window);
        TLobby_warp_menu_window = 0U;
    }
    if ((u32) lobby_com_card_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_com_card_window);
        lobby_com_card_window = 0U;
    }
    if ((u32) lobby_make_team_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_make_team_window);
        lobby_make_team_window = 0U;
    }
    if ((u32) lobby_keyboard_prompt_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_keyboard_prompt_window);
        lobby_keyboard_prompt_window = 0U;
    }
    if ((u32) lobby_keyboard_controller != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_keyboard_controller);
        lobby_keyboard_controller = 0U;
    }
    if ((u32) lobby_scroll_text_window != 0U) {
        ((void (*)(void*))queue_destruction__7TObjectFv)((void*)lobby_scroll_text_window);
        lobby_scroll_text_window = 0U;
    }
}

void reset_state_flags__6TLobbyFv(void) {
    buffer_reset();
    *(s32 *)((s8 *)TLobby__protocol_instance + 0x191C) = 1;
    TLobby__player_setup_pending = 1;
    if ((s32) TLobby__data_805D5594 == 0xC) {
        TLobby__deferred_player_setup_state = 5;
        TLobby__data_805D5594 = 0x17;
    }
    TLobby__current_dialog_window = 0;
}

void process_deferred_player_setup__6TLobbyFv(void) {
    TLobby__player_setup_pending = 0;
    switch (TLobby__deferred_player_setup_state) {
    case 1:
    case 2:
        construct_lobby_players(TLobby__data_80506A6C, TLobby__pending_member_count, TLobby__data_805D558C, TLobby__designated_client_id);
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

void add_lobby_members__6TLobbyFPvisi(Rec_801378AC *src, s32 n, s16 v, s32 w) {
    s32 i;
    TLobby__deferred_player_setup_state = 2;
    TLobby__data_805D558C = v;
    for (i = TLobby__pending_member_count; i < TLobby__pending_member_count + n; i++) {
        TLobby::copy_member_record(&TLobby__data_80506A6C[i], &src[i]);
    }
    TLobby__pending_member_count += n;
    TLobby__designated_client_id = w;
}

void handle_regist_check__6TLobbyFi(s32 ok) {
    if (ok) {
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        ((TProtocol *)(TLobby__protocol_instance))->send_login2(TLobby::get_option_state());
    } else {
        ((TProtocol *)(TLobby__protocol_instance))->send_regist();
    }
}

void handle_verify_result__6TLobbyFUi(u32 arg0) {
    s32 option_state;
    switch (arg0) {
    case 0:
    case 2:
        lobby_debug_printf_stub(lobby_msg_regist_check_ok);
        TLobby::dispatch_by_index(1);
        option_state = TLobby::get_option_state();
        send_login_9e_extended__6TLobbyFPvPvi((saddr)TLobby__protocol_instance, (void *) (((saddr)(void *)TAdSinglePlyChrSelectGC::get_char_index((u32)(0xFFFF))) + 0x370), (int)option_state);
        return;
    case 1:
        send_register_9c((u8 *)TLobby__protocol_instance);
        return;
    case 3:
        TLobby::dispatch_by_index(0);
        ((void (*)(s32))reset_state__6TLobbyFv)(0x4E);
        return;
    case 4:
        TLobby::dispatch_by_index(0);
        ((void (*)(s32))reset_state__6TLobbyFv)(0x4F);
        return;
    case 7:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1B);
        return;
    case 8:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1A);
        return;
    case 11:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x16);
        return;
    case 12:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x17);
        return;
    case 13:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x18);
        return;
    case 14:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x19);
        return;
    case 15:
    case 16:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x15);
        return;
    case 17:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1A);
        return;
    case 18:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1B);
        return;
    case 19:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1C);
        return;
    case 26:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1D);
        return;
    case 27:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1E);
        return;
    default:
        ((void (*)(s32))reset_state__6TLobbyFv)(0x1D);
        return;
    }
}

void handle_register_name_result__6TLobbyFi(s32 ok) {
    if (ok) {
        lobby_debug_printf_stub(lobby_msg_registed);
        ((TProtocol *)(TLobby__protocol_instance))->send_login2(TLobby::get_option_state());
    } else {
        lobby_debug_printf_stub(lobby_msg_name_taken);
        TLobby::dispatch_by_index(2);
        ((void (*)(s32))reset_state__6TLobbyFv)(0xd);
    }
}

void handle_register_result__6TLobbyFi(s32 arg0) {
    s32 opt;
    if (arg0 != 0) {
        lobby_debug_printf_stub(lobby_msg_registed);
        get_player_by_client_id(local_client_id);
        opt = TLobby::get_option_state();
        send_login_9e_extended__6TLobbyFPvPvi((saddr)TLobby__protocol_instance, (u8 *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF) + 0x370, opt);
        TLobby::dispatch_by_index(1);
        return;
    }
    lobby_debug_printf_stub(lobby_msg_name_taken);
    TLobby::dispatch_by_index(2);
    ((void (*)(s32))reset_state__6TLobbyFv)(0x50);
}

void handle_login_result__6TLobbyFUi(u32 arg0) {
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
        ((void (*)(s32))reset_state__6TLobbyFv)(0xA);
        break;
    case 2:
        TLobby::dispatch_by_index(0);
        ((void (*)(s32))reset_state__6TLobbyFv)(0xB);
        break;
    case 3:
        TLobby::dispatch_by_index(2);
        ((void (*)(s32))reset_state__6TLobbyFv)(0xD);
        break;
    case 4:
        TLobby::dispatch_by_index(0);
        ((void (*)(s32))reset_state__6TLobbyFv)(0xE);
        break;
    case 5:
        TLobby::dispatch_by_index(0);
        ((void (*)(s32))reset_state__6TLobbyFv)(0xF);
        break;
    case 6:
        lobby_login_result_flag = 1;
        TLobby::dispatch_by_index(2);
        ((void (*)(s32))reset_state__6TLobbyFv)(0x50);
        break;
    default:
        ((void (*)(s32))reset_state__6TLobbyFv)(8);
        break;
    }
}

void send_selected_character__6TLobbyFv(void) {
    A_80137384 a;
    u8 b[0x7C];
    char c[0xAC];
    D_80137384 d;
    u8 e[0x204];
    u8 *card;
    card = get_character_save_record(0xFFFF);
    memset(&a, 0, sizeof(a));
    a.kb = open_hard_keyboard__6TLobbyFPv((void *)local_client_id) != 0 ? 1 : 0;
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
    TLobby__sub_800703D0(d.b, card + 0x21C4);
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

void queue_static_object_destruction__6TLobbyFv(void) {
    ((TObject *)TLobby__join_lobby_controller)->queue_destruction();
}
}
namespace P2_8013731C {

void send_position_update__6TLobbyFv(void) {
    s32 temp_r31;
    s32 temp_r4;

    temp_r31 = increment_frame__23TAdSinglePlyChrSelectGCFv();
    temp_r4 = get_player_count__23TAdSinglePlyChrSelectGCFv();
    ((TProtocol *)(TLobby__protocol_instance))->send_character_save_info(temp_r4, temp_r31);
}
}
namespace P1_80137188 {

void handle_state__6TLobbyFi(s32 arg0) {
    s32 temp_r3;

    if (arg0 != 0) {
        TAdSinglePlyChrSelectGC::save_online_character();
        temp_r3 = TLobby__sub_80146740();
        switch (temp_r3) {
        case 0:
            ((TProtocol *)(TLobby__protocol_instance))->send_server_time_request();
            return;
        case 1:
            close_and_set_state_13__6TLobbyFv(0x13);
            return;
        case 2:
            close_and_set_state_13__6TLobbyFv(0x14);
            return;
        }
    } else {
        reset_state__6TLobbyFv(0x20);
        TAdSinglePlyChrSelectGC::reset_character_data();
        TAdSinglePlyChrSelectGC::save_online_character();
    }
}

void TLobby__sub_80137228(s32 arg0) {
    if (TLobby__download_list_window == 0) {
        NJS_POINT2 tmp = lbl_8043EE08[0];
        TLobby__download_list_window = create_message_window_for_size(get_window_layout_position(0xc7), &tmp);
    }
    ((TWindowMessage *)TLobby__download_list_window)->append_line((int)arg0, (int)3);
}

void TLobby__sub_801371B0(s32 arg0) {
    if (TLobby__join_entry_window_obj == 0) {
        NJS_POINT2 tmp = lbl_8043EE10[0];
        TLobby__join_entry_window_obj = create_message_window_for_size(get_window_layout_position(0xc8), &tmp);
    }
    ((TWindowMessage *)TLobby__join_entry_window_obj)->append_line((int)arg0, (int)3);
    TLobby__data_805D5594 = 0x16;
}

void disable_window_flags__6TLobbyFPv(void* a0) { TWindowCtrl::set_window_flags_off(local_client_id, (saddr)a0); }
}

extern "C" {
void open_ship_block_select_menu__6TLobbyFiPvPv(s32 arg0, Ent_8013703C *arg1, Ent_8013703C *arg2) {
    static void *tblA = (void *)lobby_window_title_ship_select;
    static void *tblB = (void *)lobby_window_title_block_select;
    void *tbl;
    s32 cmp;
    s32 i;

    cmp = strncmp(arg1->name, lobby_list_header_block, 5);
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
    for (i = 0; i < arg0; i++) {
        ((TLobby *)TLobby__list_window)->add_status_disp_entry((saddr)arg1[i].name, (s32)i);
    }
    ((TWindowMenuIconLine *)TLobby__list_window)->calc_content_extent();
    if (cmp == 0) {
        TLobby::set_menu_mode_1();
    } else {
        TLobby::set_menu_mode_0();
    }
    if (strncmp(arg2->name, lobby_list_header_block, 5) != 0) {
        memset(TLobby__data_8050AAAC, 0, 0x11);
        strncpy(TLobby__data_8050AAAC, arg2->name, 0x10);
    }
}
}

void open_information_list__6TLobbyFiPv(s32 arg0, Ent_80136FA0 *arg1) {
    void *w = (void *)lobby_window_title_information;
    s32 i;
    void *old = TLobby__list_window;
    if (old != 0) {
        ((TObject *)old)->queue_destruction();
        TLobby__list_window = 0;
    }
    TLobby__list_window = TShopJudgmentItemWindow::open_default((saddr)w);
    for (i = 0; i < arg0; i++) {
        ((TLobby *)TLobby__list_window)->add_status_disp_entry((saddr)arg1[i].name, (s32)i);
    }
    ((TWindowMenuIconLine *)TLobby__list_window)->calc_content_extent();
    TLobby::set_menu_mode_2();
}

extern "C" {
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
}

void handle_game_join__6TLobbyFPv(Pkt_80136C94 *pkt) {
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
        p = (Obj_80136C94 *)get_player_by_client_id((void *)i);
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
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct((u8 *)(*(void * *)&TLobby__protocol_instance) + 0x1900);
        p->m6();
        strncpy(TLobby__player_names[local_client_id], p->m10(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        ((TLobby *)(*(void * *)&TLobby__protocol_instance))->send_6F_burst_done();
        TLobby__data_805D5594 = 0xF;
        p = (Ply_80136A8C *)create_player_object(1 - local_client_id, 4, (void *)TAdSinglePlyChrSelectGC::get_char_index(0));
        if (p != NULL) {
            init_player_join_record(&hdr);
            TObjPlayer::fill_player_record(p, &hdr);
            bswap_player_data__6TLobbyFi(&hdr);
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
        ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct((u8 *)(*(void * *)&TLobby__protocol_instance) + 0x1900);
        p->m6();
        strncpy(TLobby__player_names[local_client_id], p->m10(), 0x10);
        lobby_debug_printf_stub(lobby_debug_make_player_format, local_client_id);
        ((TLobby *)(*(void * *)&TLobby__protocol_instance))->send_6F_burst_done();
        TLobby__data_805D5594 = 0xF;
    }
}

#pragma push
#pragma opt_propagation off

void handle_lobby_enter__6TLobbyFPviiiiiii(Ent_801368B0 *ents, s32 n, s32 client_id, s32 leader, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
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
        strncpy(TLobby__player_names[ents[i].id], ents[i].name, 0x10);
    }
    for (i = 0; i < 12; i++) {
        p = (Obj_801368B0 *)get_player_by_client_id((void *)i);
        if (p != NULL) {
            delete p;
            lobby_debug_printf_stub(TLobby__data_8043EF38, i);
        }
    }
    add_lobby_members__6TLobbyFPvisi(ents, n, client_id, leader);
    set_floor_map_variant((saddr)(get_current_floor()), v4);
    TLobby__event_theme_id = arg7;
    activate_keyboard();
    *(u8 **)(TLobby__protocol_instance + 0xBBF8) = TLobby__sub_801371B0;
}
#pragma pop

extern "C" {
void construct_lobby_players(Rec_801378AC *records, s32 count, int self_id, s32 unused) {
    s32 j;
    s32 i;
    u8 *plr;
    void *room;

    for (i = 0; i < count; i++) {
        if (self_id == ((Entry_8013634C *)records)[i].client_id) {
            if (((void *(*)(s32))get_player_by_client_id)(self_id) == NULL) {
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
            if (((void *(*)(s32))get_player_by_client_id)(((Entry_8013634C *)records)[j].client_id) == NULL) {
                plr = create_player_object(((Entry_8013634C *)records)[j].client_id, 4, ((Entry_8013634C *)records)[j].char_data);
                ((TLobby *)(plr + 0xDAC))->copy_header_struct(&((Entry_8013634C *)records)[j]);
                ((Plr_80136080 *)plr)->m6();
                lobby_debug_printf_stub(lobby_debug_create_player_format, ((Entry_8013634C *)records)[j].client_id);
            } else {
                lobby_debug_printf_stub(lobby_debug_duplicate_player_format, ((Entry_8013634C *)records)[j].client_id);
            }
        }
    }
    *(void **)(TLobby__protocol_instance + 0xBBF0) = (void *)handle_chat_message__11TWindowCtrlFPc;
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
}

void on_game_player_add__6TLobbyFiii(saddr arg0, s32 arg1, s32 arg2) {
    Entry_8013634C e;
    s32 pkt;
    Obj_801361E8 *p;
    Node_801361E8 *n;
    u8 *plr;
    if (TLobby__data_805D5594 != 0xE && TLobby__data_805D5594 != 0xF) {
        return;
    }
    TLobby__sub_8013AA64(&e, (void *)arg0);
    if (e.client_id == local_client_id) {
        ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
        return;
    }
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&game_join_player_records[e.client_id], &e);
    game_join_player_records[e.client_id].ip_addr = e.ip_addr;
    game_join_player_records[e.client_id].client_id = e.client_id;
    strncpy(game_join_player_records[e.client_id].name, e.name, 0x10);
    TLobby__join_state_flag = arg2;
    sprintf(player_joined_message, get_seq_phase__6TLobbyFPv(0x10), e.name);
    show_dialog_value_line(player_joined_message);
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
    TLobby__designated_client_id = arg1;
    p = ((Obj_801361E8 *(*)(void *))get_player_by_client_id)((void *)e.client_id);
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
    if (((u8 *(*)(void *))get_player_by_client_id)((void *)local_client_id) != NULL) {
        TLobby::send_6x70_player_data(e.client_id);
        if (((u8 *(*)(void *))get_player_by_client_id)((void *)e.client_id) == NULL) {
            plr = create_player_object(e.client_id, 4, e.char_data);
            ((TLobby *)(plr + 0xDAC))->copy_header_struct(&e);
            ((Plr_80136080 *)plr)->m6();
            ((TLobby *)(e.client_id))->open_udp_socket_for_player();
            lobby_debug_printf_stub(lobby_debug_burst_player_format, e.client_id);
        }
    } else {
        game_join_pending_clients[e.client_id] = 1;
        TLobby::copy_member_record(&((Entry_8013634C *)TLobby__data_80506A6C)[e.client_id], &e);
    }
    if (local_client_id == TLobby__designated_client_id) {
        init_6x72_resume_packet(&pkt);
        send_packet_60__6TLobbyFi(&pkt);
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

void remove_player__6TLobbyFUiii(uaddr arg0, s32 arg1, s32 arg2) {
    Obj_801361E8 *p;
    Node_801361E8 *n;
    TLobby__designated_client_id = arg1;
    TLobby__join_state_flag = arg2;
    p = (Obj_801361E8 *)get_player_by_client_id((void *)arg0);
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

void on_lobby_player_add__6TLobbyFii(saddr arg0, s32 arg1) {
    Entry_80136080 e;
    Obj_80136080 *p;
    u8 *plr;
    TLobby__sub_8013AA64(&e, (void *)arg0);
    TLobby__designated_client_id = arg1;
    if (e.client_id == local_client_id) {
        lobby_debug_printf_stub(lobby_debug_burst_overwrite_format, e.client_id);
        ((void (*)(void *, s32))__dt__18TPlyJoinLobbyEntryFv)(&e, -1);
        return;
    }
    p = (Obj_80136080 *)get_player_by_client_id((void *)e.client_id);
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

void retire_lobby_player__6TLobbyFii(saddr idx, s32 v) {
    Obj_80136000 *p;
    TLobby__designated_client_id = v;
    p = (Obj_80136000 *)get_player_by_client_id((void *)idx);
    if (p) {
        delete p;
        lobby_debug_printf_stub(lobby_debug_player_exit_format, idx);
    }
    strncpy(TLobby__player_names[idx], TLobby__data_805DB0B0, 0x10);
}

void TLobby__sub_80135FFC(void) {  }

extern "C" {
void open_download_list_window__6TLobbyFiPv(s32 arg0, Ent_80135E7C *arg1) {
    static void *tbl = (void *)lobby_window_title_download;
    s32 i;
    Ent_80135E7C *e;
    void *w;

    if (TLobby__list_window != 0) {
        queue_destruction__7TObjectFv(TLobby__list_window);
        TLobby__list_window = 0;
    }
    TLobby__list_window = TShopJudgmentItemWindow::open_default((saddr)tbl);
    for (i = 0; i < arg0; i++) {
        e = &arg1[i];
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
        TLobby__download_list_window = TWindowMessage::create((const NJS_POINT2 *)w, (const f32 *)(&p), 1);
        ((TWindowMessage *)TLobby__download_list_window)->append_line((saddr)((char *)arg1 + 0x2C), (int)3);
    }
    TLobby__card_list_selected_index = 0;
    TLobby__data_805D5594 = 0x11;
}
}
#pragma defer_codegen off


#pragma push
namespace P4_80137188 {
using namespace PD_data;

extern "C" {

void send_logout__6TLobbyFv(void);
void TLobby__sub_8013A16C(void);
void lobby_debug_printf_stub(s32 arg0, ...);
int get_seq_phase__6TLobbyFPv(void* p);
int get_online_message_text(void*);

extern uaddr TLobby__protocol_instance;

void send_logout__6TLobbyFv(void) {
    if ((u32) TLobby__protocol_instance != 0U) {
        ((TProtocol *)((void*)TLobby__protocol_instance))->send_logout();
    }
}

extern "C" {

typedef struct Date_801399B8 {
    u16 y;
    u8 b[0x16];
} Date_801399B8;

s32 TKeyBoardControl__sub_8000F828(void);
void queue_destruction__7TObjectFv(void *);
void init_idle_timeout_timer(void *, saddr);
void reset_state__6TLobbyFv(int);
s32 get_access_key_input_buffer(void);
saddr get_connection_message_text(int);
void reset_controller_input_state(void);
s32 socket_set_server_info(u32, const void *, const void *, saddr, saddr, saddr, u16);
s8 TAdSinglePlyChrSelectGC__sub_8033605C(void);
extern uaddr TLobby__protocol_instance;
extern s32 TLobby__join_state_flag;
extern s32 TLobby__date_seconds;
extern s32 lbl_805D55C0;
extern const char TLobby__data_805DB0B0[4];

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

#define CONNECT_801399B8(res, s)                                                                   \
    if (TKeyBoardControl__sub_8000F828() == 0) {                                                    \
        res = socket_set_server_info(TLobby__protocol_instance, TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
                                     (saddr)TLobby::init_serial_access(), get_access_key_input_buffer(), \
                                     (saddr)s[0].host, s[0].port);                                     \
    } else {                                                                                        \
        res = socket_set_server_info(TLobby__protocol_instance, TLobby__data_805DB0B0, TLobby__data_805DB0B0, \
                                     (saddr)TLobby::init_serial_access(), get_access_key_input_buffer(), \
                                     (saddr)s[1].host, s[1].port);                                     \
    }

void run_join_lobby_connect__6TLobbyFi(s32 arg0) {
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
            init_idle_timeout_timer(p, arg0);
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
            reset_state__6TLobbyFv(8);
            break;
        case 2:
            reset_state__6TLobbyFv(9);
            break;
        default:
            reset_state__6TLobbyFv(8);
            break;
        }
    }
}

#pragma pop

}

extern "C" {
void __dt__6TLobbyFv();
void run_task__6TLobbyFv();
void render__6TLobbyFv();
void render_shadows__7TObjectFv();
void *__vt__6TLobby[6] = { 0, 0, (void *)__dt__6TLobbyFv, (void *)run_task__6TLobbyFv, (void *)render__6TLobbyFv, (void *)render_shadows__7TObjectFv };
}
namespace C_80139C44 {

extern "C" {

u8 *__ct__9TProtocolFP7TObjectUsiPcPcPc(void *, void *, s32, s32, s32, s32, s32);
s32 get_access_key_input_buffer();
s32 TAdEnterPasswordGC__sub_8013ADE4();
s32 __ct__7TObjectFP7TObject(void *, void *);
void TLobby__sub_80134A20();
void copy_player_records__6TLobbyFl();
void apply_lobby_markers__6TLobbyFv();
void set_lobby_event_theme();
void init_once__6TLobbyFPv();
void TLobby__sub_80134DC8();
void TLobby__sub_80134DE8();
void show_card_list_message();
void open_download_list_window__6TLobbyFiPv();
void TLobby__sub_80135FFC();
void retire_lobby_player__6TLobbyFii();
void on_lobby_player_add__6TLobbyFii();
void remove_player__6TLobbyFUiii();
void on_game_player_add__6TLobbyFiii();
void handle_lobby_enter__6TLobbyFPviiiiiii();
void handle_game_join__6TLobbyFPv();
void TLobby__sub_80136E68();
void open_information_list__6TLobbyFiPv();
void open_ship_block_select_menu__6TLobbyFiPvPv();
void disable_window_flags__6TLobbyFPv();
void TLobby__sub_80137228();
void handle_state__6TLobbyFi();
void send_position_update__6TLobbyFv();
void queue_static_object_destruction__6TLobbyFv();
void send_selected_character__6TLobbyFv();
void handle_login_result__6TLobbyFUi();
void handle_register_result__6TLobbyFi();
void handle_register_name_result__6TLobbyFi();
void handle_verify_result__6TLobbyFUi();
void handle_regist_check__6TLobbyFi();
void TLobby__sub_80137C10();
void receive_file_chunk__22TQuestVmDownLoadServerFv();
void begin_file_download__22TQuestVmDownLoadServerFv();
void handle_quest_download_chunk__6TLobbyFv();
void try_close__6TLobbyFPv();
void forward_8024273C__6TLobbyFPv();
void handle_trade_received_items();
extern u8 __vt__6TLobby[];
extern s32 lobby_class_name;
extern s32 TLobby__data_805D4E30;
extern saddr local_client_id;
extern s32 TLobby__designated_client_id;
extern u8 *TLobby__protocol_instance;
extern s32 TLobby__lobby_entered_flag;
extern s32 TLobby__data_805D5588;
extern s16 TLobby__data_805D558C;
extern s16 TLobby__pending_member_count;
extern s32 TLobby__deferred_player_setup_state;
extern s32 TLobby__data_805D5594;
extern s32 TLobby__join_state_flag;
extern s32 TLobby__date_seconds;
extern s32 TLobby__event_theme_id;
extern s32 TLobby__card_list_selected_index;
extern s32 TLobby__idle_timeout_active;
extern s32 TLobby__data_805D55AC;
extern s32 TLobby__lobby_number;
extern s32 TLobby__join_lobby_idle_timer;
extern s32 TLobby__data_805D55B8;
extern s32 TLobby__login_pending_flag;
extern s32 lbl_805D55C0;
extern s32 lobby_login_result_flag;
extern s32 TLobby__card_list_window;
extern saddr TLobby__download_list_window;
extern s32 TLobby__list_window;
extern saddr lobby_player_construction_window;
extern s32 TLobby__current_dialog_window;
extern s32 TLobby__join_entry_window_obj;
extern s32 TLobby_warp_menu_window;
extern s32 lobby_com_card_window;
extern s32 lobby_make_team_menu_window;
extern s32 lobby_make_team_window;
extern s32 lobby_keyboard_prompt_window;
extern s32 lobby_keyboard_controller;
extern s32 lobby_scroll_text_window;
extern s32 TLobby__player_setup_pending;
extern u8 *TLobby__join_lobby_controller;

u8 *TLobby__ct(u8 *object, void *arg1) {
    s32 access_key_input_buffer;
    s32 temp_r26;
    u8 *var_r27;

    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__6TLobby;
    TLobby__sub_8013A16C();
    *(s32 *)((s8 *)object + 0) = (s32) lobby_class_name;
    TLobby__join_lobby_controller = object;
    TLobby__card_list_window = 0;
    TLobby__download_list_window = 0;
    TLobby__list_window = 0;
    lobby_player_construction_window = 0;
    TLobby__current_dialog_window = 0;
    TLobby__join_entry_window_obj = 0;
    TLobby_warp_menu_window = 0;
    lobby_com_card_window = 0;
    lobby_make_team_menu_window = 0;
    lobby_make_team_window = 0;
    lobby_keyboard_prompt_window = 0;
    lobby_keyboard_controller = 0;
    lobby_scroll_text_window = 0;
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
    var_r27 = (u8 *)(alloc_from_obj_heap(0xBCA4));
    if (var_r27 != NULL) {
        temp_r26 = TAdEnterPasswordGC__sub_8013ADE4();
        access_key_input_buffer = get_access_key_input_buffer();
        var_r27 = (u8 *)(__ct__9TProtocolFP7TObjectUsiPcPcPc(var_r27, object, 0x36, current_language, (saddr)TLobby::init_serial_access(), access_key_input_buffer, temp_r26));
    }
    TLobby__protocol_instance = var_r27;
    *(s32 **)((s8 *)var_r27 + 0xBBD4) = (s32 *)&handle_regist_check__6TLobbyFi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBD8) = (s32 *)&handle_register_name_result__6TLobbyFi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBDC) = (s32 *)&handle_login_result__6TLobbyFUi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBE0) = (s32 *)&queue_static_object_destruction__6TLobbyFv;
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBBF0) = 0;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBEC) = (s32 *)&TLobby__sub_80137C10;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBE4) = (s32 *)&open_ship_block_select_menu__6TLobbyFiPvPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBE8) = (s32 *)&TLobby__sub_80136E68;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBF4) = (s32 *)&TLobby__sub_80137228;
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBBFC) = 0;
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBC00) = 0;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC04) = (s32 *)&handle_game_join__6TLobbyFPv;
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBC08) = 0;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC0C) = (s32 *)&handle_lobby_enter__6TLobbyFPviiiiiii;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBBF8) = (s32 *)&TLobby::open_scroll_text_window;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC10) = (s32 *)&TLobby__sub_80135FFC;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC18) = (s32 *)&on_game_player_add__6TLobbyFiii;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC1C) = (s32 *)&remove_player__6TLobbyFUiii;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC20) = (s32 *)&on_lobby_player_add__6TLobbyFii;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC24) = (s32 *)&retire_lobby_player__6TLobbyFii;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC38) = (s32 *)&try_close__6TLobbyFPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC3C) = (s32 *)&forward_8024273C__6TLobbyFPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC28) = (s32 *)&handle_verify_result__6TLobbyFUi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC2C) = (s32 *)&handle_register_result__6TLobbyFi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC34) = (s32 *)&send_selected_character__6TLobbyFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC40) = (s32 *)&send_position_update__6TLobbyFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC44) = (s32 *)&handle_state__6TLobbyFi;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC48) = (s32 *)&TLobby::reset_lobby_state;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC4C) = (s32 *)&TLobby__sub_80134DE8;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC50) = (s32 *)&TLobby__sub_80134DC8;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC58) = (s32 *)&copy_quest_list_data__16TQuestListOnlineFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC5C) = (s32 *)&TQuestListOnline::receive_quest_info;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC60) = (s32 *)&TQuestListOnline::begin_file_download;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC64) = (s32 *)&handle_quest_download_chunk__6TLobbyFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC68) = (s32 *)&open_download_list_window__6TLobbyFiPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC6C) = (s32 *)&show_card_list_message;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC70) = (s32 *)&begin_file_download__22TQuestVmDownLoadServerFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC74) = (s32 *)&receive_file_chunk__22TQuestVmDownLoadServerFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC80) = (s32 *)&disable_window_flags__6TLobbyFPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC7C) = (s32 *)&open_information_list__6TLobbyFiPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC84) = (s32 *)&apply_lobby_markers__6TLobbyFv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC8C) = (s32 *)&copy_player_records__6TLobbyFl;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC98) = (s32 *)&handle_trade_received_items;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC9C) = (s32 *)&TLobby::handle_reset_choice;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBCA0) = (s32 *)&TLobby::apply_trade_items;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC54) = (s32 *)&init_once__6TLobbyFPv;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC90) = (s32 *)&set_lobby_event_theme;
    *(s32 **)((s8 *)TLobby__protocol_instance + 0xBC94) = (s32 *)&TLobby__sub_80134A20;
    TLobby__data_805D4E30 = 0;
    return object;
}

}

}

int get_seq_phase__6TLobbyFPv(void* p) { return get_online_message_text(p); }
void TLobby__sub_8013A16C(void) {  }
void lobby_debug_printf_stub(s32 arg0, ...) {}

}
namespace C_8013A1C0 {
extern "C" {
void __register_global_object(int, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __dt__18TPlyJoinLobbyEntryFv();
void TLobby__sub_8013A23C();
void destroy_join_entries__6TLobbyFv();
void init_char_data__6TLobbyFPv();
void construct_global_arrays__6TLobbyFv(void) {
    __construct_array(TLobby__data_80506A6C, (void *)init_char_data__6TLobbyFPv, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43C, 0xC);
    __register_global_object(0, (void *)destroy_join_entries__6TLobbyFv, TLobby__join_entries_dtor_registration);
    __construct_array(game_join_player_records, (void *)TLobby__sub_8013A23C, 0, 0x20, 4);
}
}

}
}
#pragma pop

#pragma push
namespace P5_8013A23C {

extern "C" {
extern u8 TLobby__data_80506A6C[];
void __dt__18TPlyJoinLobbyEntryFv(void *self, s16 flag);
void __destroy_arr(void *arr, void *dtor, u32 size, u32 count);
void destroy_join_entries__6TLobbyFv(void);
s32 TLobby__sub_8013A23C(s32 arg0);
s32 __ct__16TPlyGuildCardTagFv();

s32 TLobby__sub_8013A23C(s32 arg0) {
    __ct__16TPlyGuildCardTagFv();
    return arg0;
}
void destroy_join_entries__6TLobbyFv(void) {
    __destroy_arr(TLobby__data_80506A6C, (void *)__dt__18TPlyJoinLobbyEntryFv, 0x43c, 0xc);
}

}
}
#pragma pop

#pragma push
void bswap_telepipe_record(void *);
namespace P6_8013A2A4 {

struct H_8013A348 { u8 b[12]; };

struct S_8013A348 { u8 pad[0x28]; struct H_8013A348 h[5]; };

extern "C" {
void bswap__12player_statsFv(void *);
void bswap_inventory__6TLobbyFPv(void* p);
void bswap__15disp_data_part2Fv(void *);
void TLobby__sub_8013A9C0(void *);
void bswap_player_data__6TLobbyFi(saddr arg0);
void TLobby__sub_8013A2DC(void);
void bswap_6x6E_sync_game_state__6TLobbyFPv(void* p);
void bswap_inventory__6TLobbyFPv(void* p);
void* init_char_data__6TLobbyFPv(void* p);
void open_hard_keyboard__6TLobbyFPv(void* p);
void set_player_count__6TLobbyFi(int a0);
int __ct__12TPlyCharDataFv(void*);
int __ct__16TPlyGuildCardTagFv(void*);

void* init_char_data__6TLobbyFPv(void* p) { __ct__16TPlyGuildCardTagFv(p); __ct__12TPlyCharDataFv((char*)p + 0x20); return p; }
void TLobby__sub_8013A2DC(void) {  }
void bswap_6x6E_sync_game_state__6TLobbyFPv(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); }
void open_hard_keyboard__6TLobbyFPv(void* p) { TWindowKeyBoardHard::test_card_flag((saddr)p, (saddr)((void*)262144)); }

void bswap_player_data__6TLobbyFi(saddr arg0) {
    s32 i;
    bswap_16((u16 *)arg0);
    bswap_16((u16 *)(arg0 + 2));
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
    bswap_32((u32 *)(arg0 + 0x18));
    bswap_32((u32 *)(arg0 + 0x1C));
    bswap_16((u16 *)(arg0 + 0x20));
    bswap_16((u16 *)(arg0 + 0x22));
    bswap_16((u16 *)(arg0 + 0x24));
    bswap_16((u16 *)(arg0 + 0x26));
    for (i = 0; i < 5; i++) {
        ((TLobby *)(&((struct S_8013A348 *)arg0)->h[i]))->bswap_header_3words();
    }
    bswap_32((u32 *)(arg0 + 0x64));
    ((TLobby *)(arg0 + 0x68))->bswap_fields();
    TLobby__sub_8013A9C0((void *)(arg0 + 0x70));
    bswap_telepipe_record((void *)(arg0 + 0x78));
    bswap_32((u32 *)(arg0 + 0x94));
    bswap_32((u32 *)(arg0 + 0xAC));
    bswap_32((u32 *)(arg0 + 0x488));
    bswap_32((u32 *)(arg0 + 0xB0));
    bswap__15disp_data_part2Fv((void *)(arg0 + 0xC8));
    bswap__12player_statsFv((void *)(arg0 + 0x118));
    TLobby::bswap_inventory((void*)(arg0 + 0x13C));
}

void bswap_inventory__6TLobbyFPv(void* p) { bswap_32((u32 *)p); { int i; for (i = 0; i < 30; i++) { ((TPlyInventoryItem *)((char*)p + 0x4 + i * 28))->bswap(); } } }

    extern int lobby_player_count;
void set_player_count__6TLobbyFi(int a0) { lobby_player_count = a0; }

}
}
#pragma pop

#pragma push
namespace P7_8013A4A8 {

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_10 { u8 bytes[0x10]; };

struct ByteBlock_20 { u8 bytes[0x20]; };

struct ByteBlock_50 { u8 bytes[0x50]; };

struct ByteBlock_348 { u8 bytes[0x348]; };

struct ByteBlock_24 { u8 bytes[0x24]; };

struct ByteBlock_14 { u8 bytes[0x14]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct P8_8013A5D4 { u32 w[2]; };

struct Rec_8013A5D4 { P8_8013A5D4 f0; u32 f8; u32 fc; P8_8013A5D4 f10; P8_8013A5D4 f18; u8 f20[0x41c]; };

extern "C" {
void TObjPlayer__sub_8013A820(void *arg0, void *arg1);
    extern int item_drop_server_seed;
    extern int area_random_seed;
void TObjPlayer__sub_8013A820(void *arg0, void *arg1);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
void* TObjPlayer__sub_8013A788(void* p, void* a1);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1);
u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1);
Rec_8013A5D4 *copy_member_record__6TLobbyFPvPv(Rec_8013A5D4 *dst, Rec_8013A5D4 *src);
void bswap_and_send_extended_subcommand(void* p, void* a1);
void bswap_extended_subcommand_header(void* p);
void TLobby__sub_8013A578(void* p);
void init_6x72_resume_packet(void* p);
void bswap_and_handle_packet__6TLobbyFii(saddr arg0, s32 arg1);
void bswap_header_fields__6TLobbyFi(saddr arg0);
void send_packet_60__6TLobbyFi(saddr arg0);

void bswap_and_send_extended_subcommand(void* p, void* a1) { bswap_extended_subcommand_header(p); ((TLobby *)p)->send_command((uaddr)a1); }

void bswap_extended_subcommand_header(void* p) { TLobby::bswap_header_fields((saddr)p); }

void bswap_header_fields__6TLobbyFi(saddr arg0) {
    bswap_16((u16 *)(arg0 + 2));
    bswap_32((u32 *)(arg0 + 4));
}
void bswap_and_handle_packet__6TLobbyFii(saddr arg0, s32 arg1) {
    bswap_client_id_header((G_ClientIDHeader *)arg0);
    ((TLobby *)arg0)->send_subcommand_to_client((u32)arg1);
}
void TLobby__sub_8013A578(void* p) { *(u8*)((char*)p + 0x0) = 111; *(u8*)((char*)p + 0x1) = 129; }
void send_packet_60__6TLobbyFi(saddr cmd) {
    bswap_client_id_header((G_ClientIDHeader *)cmd);
    send_subcommand((void *)cmd);
}
void init_6x72_resume_packet(void* p) { *(u8*)((char*)p + 0x0) = 114; *(u8*)((char*)p + 0x1) = 1; }

Rec_8013A5D4 *copy_member_record__6TLobbyFPvPv(Rec_8013A5D4 *dst, Rec_8013A5D4 *src) {
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

}
}
#pragma pop

__declspec(section ".ctors") static void *const __sinit_TPlyJoinLobbyEntry_cpp_ref = (void *)P4_80137188::C_8013A1C0::construct_global_arrays__6TLobbyFv;

// Window positions copied by the message/menu openers above, and the lobby log and
// menu strings; defined after their users so each is addressed on its own.
namespace P3_80137360 {
extern "C" {
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDE8[1] = { { 342.0f, 144.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDF0[1] = { { 342.0f, 144.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EDF8[1] = { { 558.0f, 224.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE00[1] = { { 224.0f, 188.0f } };
}
}
namespace P1_80137188 {
extern "C" {
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE08[1] = { { 224.0f, 188.0f } };
__declspec(section ".rodata") const NJS_POINT2 lbl_8043EE10[1] = { { 558.0f, 224.0f } };
}
}
extern "C" {
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
}
namespace P3_80137360 {
extern "C" {
__declspec(section ".rodata") const char lobby_msg_login_success[] = "login success.";
__declspec(section ".rodata") const char lobby_msg_registed[] = "Registed.";
__declspec(section ".rodata") const char lobby_msg_name_taken[] = "already use this name.";
__declspec(section ".rodata") const char lobby_msg_regist_check_ok[] = "Regist check OK";
__declspec(section ".rodata") const char lobby_window_title_block_jump[] = "BlockJump";
__declspec(section ".rodata") const char lobby_window_title_ship_jump[] = "ShipJump";
__declspec(section ".rodata") const char lobby_window_title_taisen_team[] = "TAISEN TEAM";
}
}

u32 lbl_8050BEB8[2];
