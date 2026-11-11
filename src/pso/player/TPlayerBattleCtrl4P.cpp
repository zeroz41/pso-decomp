#include "pso/map/TSetEvtDestroy.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItem.h"
#include "types.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/unk/TLobby.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TPlayerBattleCtrl4P_8031012C.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/Language.h"
struct Base_803107D0_8031058C { char pad[0x18]; };
struct VObj_803107D0_8031058C : Base_803107D0_8031058C {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)VV(34)VV(35)VV(36)VV(37)VV(38)VV(39)VV(40)
VV(41)VV(42)VV(43)VV(44)VV(45)VV(46)VV(47)VV(48)VV(49)VV(50)
VV(51)VV(52)VV(53)VV(54)VV(55)VV(56)VV(57)VV(58)VV(59)VV(60)
VV(61)
#undef VV
    virtual void v64();
};
struct T_803102A4 { u8 pad[0x28]; s32 arr[4]; };
struct T_803102C8 { u8 pad[0x298]; s32 mode; };
struct Ctl_803101D4 { u8 pad[0x28]; void *win[4]; };
struct Ctl_80310230 { u8 pad[0x28]; void *win[4]; };
struct Ctl_8031012C { u8 pad[0x28]; void *win[4]; };
struct Ent_803104CC { u8 pad0[0x30]; u32 flags; u8 pad1[0x754 - 0x34]; u8 sub[4]; };
struct Ctl_803104CC { u8 pad[0x264]; s32 ok[4]; };
struct VBase_80310830 { char pad[0x18]; };
struct VObj_80310830 : VBase_80310830 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual char *v10();
};
struct Ent_80310830 { u16 id; s16 idx; u32 pad; };
struct Ctl_80310910 {
    u8 pad0[0x238];
    s8 flags[8];
    u8 pad240[0x260 - 0x240];
    s32 state;
};
struct P_803109D4 { s32 v[2]; };
// Window size {width, height} passed to TWindowMessage::create (inferred from use).
struct BattleIntroWindowSize { f32 x, y; };
struct O_803109D4 { u8 pad[0x264]; s32 active[4]; };
struct Ent_8031030C { u16 id; s16 idx; u32 pad; };
struct Node_80311304 { u8 pad0[0xC]; Node_80311304 *next; };
struct Par_80311304 { u8 pad0[0x14]; Node_80311304 *head; };
struct Ctl_80311380 { u8 pad[0x288]; u16 tbl[1]; };
struct Ctl_8031171C {
    u8 pad0[0x244];
    s32 f244;
    s32 f248;
    u8 pad24C[0x264 - 0x24C];
    s32 ok[4];
};
struct O_80311618 { u8 pad[0x238]; u8 flags[8]; u8 pad2[0x250 - 0x240]; u64 time; u8 pad3[0x284 - 0x258]; s32 v; };
struct O_80311400 { u8 pad[0x20]; void *w0; void *w1; u8 pad2[0x288 - 0x28]; s16 order[4]; };
struct Ctl_80310F10
{
  u8 pad[0x1C];
  u8 *cfg;
  u8 pad20[0x274 - 0x20];
  s32 team[4];
};
struct Rank_801C343C { u16 id; s16 rank; s32 score; };
struct Team_801C343C { s32 v[2]; };
extern Rank_801C343C split_screen_battle_rankings[4];
extern "C" {
void clear_split_screen_battle_window_slots(T_803102A4 *self);
extern TPlayerBattleCtrl4P *TPlayerBattleCtrl4P__instance;
void *__nw__7TObjectFUl(u32);
void *TWindowDuelResult__ct(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 get_map_id__13TRaderMapCoreFv();
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
int sprintf(char *, const char *, ...);
s32 TLobby__sub_801C19D0(void *);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void *get_character_save_record(u16);
int obj_getPtr2B0_20(u8 *p);
f32 fn_801C19A4(void *);
s32 TWindowDuelResult__sub_801C19AC(void *);
void set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl(u8 *arg0, s32 arg1);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, int);
void queue_destruction__7TObjectFv(void *);
extern s32 lbl_805D2A98;
void destroy_matching_children__19TPlayerBattleCtrl4PFPvPv(void *self, Par_80311304 *p);
void TObjPlayer__send_selected_spawn_position(void *self, u16 id);
s32 obj_set_flag_20000();
s64 OSGetTime(void);
void obj_clear_flag30_20000(void *arg0);
s32 init_with_name__6TLobbyFPvPvPvPv(void *, void *, void *, int);
s32 TObjEneRe4Sorcerer__sub_801E3F14(int);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
extern s32 TLobby__battle_ctrl_default_value;
s32 rand();
s32 set_player_team_id(void *, int);
s32 fn_801D6D8C(void *, u8, int);
s32 fn_801D726C(void *, void *);
s32 fn_801D72B0(void *, s32);
s32 set_field_0xE__6TLobbyFPvUc(void *, void *);
s32 set_field_d__6TLobbyFPvUc(void *, void *);
s32 set_clamped_field_c__6TLobbyFPvUc(void *, void *);
s32 set_field_b__6TLobbyFPvUc(void *, void *);
s32 set_field_a__6TLobbyFPvUc(void *, int);
s32 set_byte9_clamped__6TLobbyFPvUc(void *, void *);
s32 set_difficulty__6TLobbyFPvUc(void *, void *);
s32 set_field7_clamped__6TLobbyFPvUc(void *, void *);
s32 set_field_0x6__6TLobbyFPvUc(void *, void *);
s32 set_field_5__6TLobbyFPvUc(void *, void *);
s32 set_clamped_field_4__6TLobbyFPvUc(void *, void *);
s32 set_field_3__6TLobbyFPvUc(void *, void *);
s32 set_field_2__6TLobbyFPvUc(void *, void *);
s32 set_validated_field_0x1__6TLobbyFPvUc(void *, void *);
s32 set_section_id__6TLobbyFPvUc(void *, int);
extern const f32 lbl_805D3538;
extern const f32 lbl_805D353C;
extern const f32 lbl_805D3540;
extern const f32 lbl_805D3544;
extern const f32 lbl_805D3548;
extern const f32 lbl_805D354C;
extern const f32 lbl_805D3550;
extern const f32 lbl_805D5DC4;
extern const f32 lbl_805D5DC8;
u16 get_entity_id(void *);
void TLobby__sub_801C36E4(void *arg0, void *arg1);
s32 TLobby__sub_801C4FC4(void *p);
void TLobby__sub_801B09A4(void);
void play_cue_stream_file(s32 name);
void show_duel_result_window(s32 arg0, s32 arg1);
void TLobby__sub_8020BB18(void);
void TLobby__sub_8020BCE4(void);
void end_player_keyboard_hold(s32 arg0);
void clear_trap_counts(s8 *arg0);
void begin_player_keyboard_hold(s32 arg0);
s32 obj_testFlags30__14TObjCollidableFUl(u32, s32);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 release_attached_resource__10TObjPlayerFv();
void request_active_window_close(void);
s32 send_code_45_1__10TObjPlayerFl();
}
extern const char *TPlayerBattleCtrl4P_player_name_formats[];
// Code strings of start_match/start_duel/record_battle_results_after_delay ("SCORE", "%s %s",
// "start.adx", "duel1.adx", "duel2.adx", "win.adx", "lose.adx"): kept as the split's symbols. As
// literals CW addresses all three of start_match through one hoisted .rodata base, the original
// loads each by its own lis/addi.
extern char lbl_80475B90[];
extern char lbl_80475B98[];
extern char lbl_80475BA0[];
extern char lbl_80475BAC[];
extern char lbl_80475BB8[];
extern s32 lbl_80475BC4[];
extern s32 lbl_80475BCC[];
extern void *__vt__19TPlayerBattleCtrl4P[6];
extern s16 battle_event_second_table[];
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
void reset_cameras_to_actor(void *actor, s32 arg1);
extern s32 TPlayerBattleCtrl4P__init_flag;
typedef struct Ctl_80310F10 Ctl_80310F10;
Rank_801C343C split_screen_battle_rankings[4];
struct Ids_80311C2C { s32 a; s32 b; s32 c; s32 d; };
struct O_80311C2C { u8 pad[0x20]; void *w0; void *w1; u8 pad2[0x294 - 0x28]; Ids_80311C2C *ids; };
extern "C" {
s32 check_player_flag1__6TLobbyFv();
s32 set_state__19TPlayerBattleCtrl4PFv(void *, int);
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
void *create__14TWindowMessageFPvll(void *, void *, int);
void *get_window_layout_position(int);
void TLobby__sub_801036CC();
void TLobby__sub_8020BC50();
extern void *quest_mission_manager;
void TKeyBoardControl__sub_8000F950(void);
s32 reset_players__19TPlayerBattleCtrl4PFv();
s32 check_flag_100__10TObjPlayerFPv();
int update_players__19TPlayerBattleCtrl4PFv(void*);
}
    extern int evt2_random_enemies_mode;
extern s32 reset_ctrl_to_default__19TPlayerBattleCtrl4PFv[];
extern "C" {
char team_matchup_message_buffer[256];
}
struct VBase_18_26c590 { char pad[0x18]; };
struct VObj_18_26c590 : VBase_18_26c590 {
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
struct Cnt_8031224C { s32 n[2]; };
struct Strs_8031224C { u8 pad[0x18]; char *fmt; };
struct O_8031224C { u8 pad[0x20]; void *w0; u8 pad2[0x240 - 0x24]; s32 timer; u8 pad3[0x274 - 0x244]; s32 team[4]; u8 pad4[0x294 - 0x284]; Strs_8031224C *strs; };
extern "C" {
s32 is_battle_decided__19TPlayerBattleCtrl4PFv(void *);
void append_line__14TWindowMessageFii(void *, void *, int);
char *strncpy(char *, const char *, u32);
void update__19TPlayerBattleCtrl4PFv(void *);
s32 __ct__15TDuelEffectCtrlFP7TObjectUc(void *, void *, s32);
void set_frames__15ProtectionTimerFl(void *, s32);
s32 update_all_players__19TPlayerBattleCtrl4PFv();
s32 check_all_players_flag__19TPlayerBattleCtrl4PFv(void *);
}
typedef void (TPlayerBattleCtrl4P::*BattleAction)();
struct BattleIntroWindowState {
    u8 pad[0x20];
    void *intro_window;
};
extern "C" {
s32 lbl_805D6AB0;
void *destroy__19TPlayerBattleCtrl4PFs(void *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
void run_task__19TPlayerBattleCtrl4PFv(TPlayerBattleCtrl4P *self);
void render__7TObjectFv();
void render_shadows__7TObjectFv();
// Japanese text (shift-JIS)
}
extern "C" {
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 __ct__7TObjectFP7TObject(void *, void *);
void export_character_data__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
}

extern "C" {
const char *TPlayerBattleCtrl4P__message_table_language0[7] = {
    "\x82\xE0\x82\xA4\x88\xEA\x93\x78\x81\x41\x93\xAF\x82\xB6\x83\x8B\x81\x5B\x83\x8B\x82\xC5\n\x8C\x88\x93\xAC\x82\xF0\x8D\x73\x82\xA2\x82\xDC\x82\xB7\x82\xA9\x81\x48", // もう一度、同じルールで 決闘を行いますか？
    "\x82\xCD\x82\xA2", // はい
    "\x82\xA2\x82\xA2\x82\xA6", // いいえ
    "\x8F\x49\x97\xB9\x82\xB7\x82\xE9", // 終了する
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\x8E\x8E\x8D\x87\x8C\x8B\x89\xCA\x82\xCD\x96\xB3\x8C\xF8\x82\xC6\x82\xB5\x82\xDC\x82\xB7\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました 試合結果は無効とします  ビジュアルロビーへ 転送します。 Press start button.
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました  ビジュアルロビーへ 転送します。 Press start button.
    "\x8D\xA1\x89\xF1\x82\xCD\x83\x60\x81\x5B\x83\x80\x90\xED\x82\xC5\x82\xB7\x81\x42\n\x82\x60\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n\x82\x61\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n", // 今回はチーム戦です。 Ａチーム   %s   %s Ｂチーム   %s   %s
};
}

extern "C" {
const char *lbl_804E7D4C[7] = {
    "Do you want to \nfight the same\nrules?",
    "Yes",
    "No",
    "Exit",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "Team battle ok.\nA-TEAM\n  %s\n  %s\nB-TEAM\n  %s\n  %s\n",
};
}

const char *TPlayerBattleCtrl4P__name = "TPlayerBattleCtrl4P";

void TPlayerBattleCtrl4P::init_instance_with_text(s32 arg0, s32 arg1) {
    if (TPlayerBattleCtrl4P__instance == NULL) {
        void *mem = __nw__7TObjectFUl(0x2A0);
        if (mem != NULL) {
            ((TPlayerBattleCtrl4P *)mem)->construct(tl_00);
        }
    }
    if (TPlayerBattleCtrl4P__instance != NULL) {
        strncpy(TPlayerBattleCtrl4P__instance->intro_text, (const char *)arg1, 0x200);
        TPlayerBattleCtrl4P__instance->rule_data = (u8 *)arg0;
    }
}

TPlayerBattleCtrl4P* TPlayerBattleCtrl4P::construct(TObject* parent) {
    s32 i;
    const char **p;

    __ct__7TObjectFP7TObject(((void *)this), parent);
    *(void **)((s8 *)((void *)this) + 0x18) = __vt__19TPlayerBattleCtrl4P;
    m_name = TPlayerBattleCtrl4P__name;
    set_split_screen_battle_phase(0);
    this->intro_window = 0;
    this->menu_window = 0;
    clear_split_screen_battle_window_slots((T_803102A4 *)this);
    p = lbl_804E7D4C;
    if (current_language == LANGUAGE_JAPANESE) {
        p = TPlayerBattleCtrl4P__message_table_language0;
    }
    this->message_table = p;
    for (i = 0; i < 4; i++) {
        s32 pl = (s32)get_player_by_client_id(i);
        if (pl != 0) {
            export_character_data__10TObjPlayerFPvPv((u8 *)pl, (u8 *)(get_char_index__23TAdSinglePlyChrSelectGCFUi((u32)i)));
        }
    }
    TPlayerBattleCtrl4P__instance = this;
    this->rule_data = 0;
    return this;
}

TPlayerBattleCtrl4P* TPlayerBattleCtrl4P::destroy(s16 should_free) {
    if (((void *)this) != NULL) {
        *(void ***)((s8 *)((void *)this) + 0x18) = __vt__19TPlayerBattleCtrl4P;
        if ((u32) this->intro_window != 0U) {
            ((TWindowBase *)this->intro_window)->close();
            this->intro_window = 0U;
        }
        if ((u32) this->menu_window != 0U) {
            ((TWindowBase *)this->menu_window)->close();
            this->menu_window = 0U;
        }
        close_player_windows();
        TPlayerBattleCtrl4P__instance = 0;
        __dt__7TObjectFv(((void *)this), 0);
        if (should_free > 0) {
            __dl__7TObjectFPv(((void *)this));
        }
    }
    return this;
}

void TPlayerBattleCtrl4P::run_task() {
    static BattleAction tbl[6] = { &TPlayerBattleCtrl4P::initialize_battle, &TPlayerBattleCtrl4P::update_intro_phase, &TPlayerBattleCtrl4P::update_battle_phase, &TPlayerBattleCtrl4P::update_results_phase, &TPlayerBattleCtrl4P::update_return_phase, &TPlayerBattleCtrl4P::update_reload_phase };
    (this->*tbl[phase])();
}

void TPlayerBattleCtrl4P::initialize_battle() { init_battle(); set_split_screen_battle_phase((s32)((void*)1)); }

void TPlayerBattleCtrl4P::update_intro_phase() {
    static BattleAction tbl[9] = { &TPlayerBattleCtrl4P::open_intro_window, &TPlayerBattleCtrl4P::show_intro_text, &TPlayerBattleCtrl4P::wait_for_intro_text, &TPlayerBattleCtrl4P::show_team_matchup, &TPlayerBattleCtrl4P::wait_for_team_matchup, &TPlayerBattleCtrl4P::begin_ready_wait, &TPlayerBattleCtrl4P::update_ready_wait, &TPlayerBattleCtrl4P::wait_for_start_countdown, &TPlayerBattleCtrl4P::close_intro_and_start_battle };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_battle_phase() {
    static BattleAction tbl[2] = { &TPlayerBattleCtrl4P::start_battle, &TPlayerBattleCtrl4P::update_battle_time_and_rankings };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_results_phase() {
    static BattleAction tbl[10] = { &TPlayerBattleCtrl4P::begin_battle_results, &TPlayerBattleCtrl4P::wait_after_battle_end, &TPlayerBattleCtrl4P::wait_before_recording_results, &TPlayerBattleCtrl4P::open_result_windows, &TPlayerBattleCtrl4P::wait_for_result_window_close, &TPlayerBattleCtrl4P::update_rematch_menu, &TPlayerBattleCtrl4P::close_rematch_menu, &TPlayerBattleCtrl4P::wait_for_rematch_menu_button, &TPlayerBattleCtrl4P::record_battle_results_after_delay, &TPlayerBattleCtrl4P::close_battle_results };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_return_phase() {
    static BattleAction tbl[3] = { &TPlayerBattleCtrl4P::return_to_hunters_guild, &TPlayerBattleCtrl4P::sub_80311804, &TPlayerBattleCtrl4P::sub_80311800 };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_reload_phase() {
    static BattleAction tbl[4] = { &TPlayerBattleCtrl4P::begin_battle_reload, &TPlayerBattleCtrl4P::begin_battle_reload_fade, &TPlayerBattleCtrl4P::finish_battle_reload, &TPlayerBattleCtrl4P::sub_80311890 };
    (this->*tbl[phase_state])();
}

const char *TPlayerBattleCtrl4P_player_name_formats[4] = {
    "1st", "2nd", "3rd", "4th",
};

void *__vt__19TPlayerBattleCtrl4P[6] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__19TPlayerBattleCtrl4PFs, (void *)&run_task__19TPlayerBattleCtrl4PFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};

void TPlayerBattleCtrl4P::open_intro_window() {
    if (((BattleIntroWindowState *)this)->intro_window == NULL) {
        BattleIntroWindowSize size = {328.0f, 166.0f};
        ((BattleIntroWindowState *)this)->intro_window = create__14TWindowMessageFPvll(
            get_window_layout_position(0x52), &size, 1);
    }
    lbl_805D6AB0 = 0;
    set_score(1);
}

void TPlayerBattleCtrl4P::show_intro_text() {
    if (this->intro_window != NULL) {
        append_line__14TWindowMessageFii(this->intro_window, (void *)((char *)((void *)this) + 56), 128);
    }
    this->frame_timer = 240;
    set_score(2);
}

void TPlayerBattleCtrl4P::wait_for_intro_text() {
    s32 temp_r0;

    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
            set_score((s32)((void*)(3)));
            return;
        }
        set_score((s32)((void*)(5)));
    }
}

void TPlayerBattleCtrl4P::show_team_matchup() {
    Cnt_8031224C cnt = {0, 0};
    char names[4][16];
    s32 i;
    s32 team;
    VObj_18_26c590 *p;
    for (i = 0; i < 4; i++) {
        names[i][0] = 0;
    }
    for (i = 0; i < 4; i++) {
        p = (VObj_18_26c590 *)get_player_by_client_id(i);
        if (p != NULL) {
            team = ((O_8031224C *)this)->team[i] != 1 ? 1 : 0;
            if (cnt.n[team] < 2) {
                strncpy(names[team * 2 + cnt.n[team]], p->m10(), 16);
                cnt.n[team]++;
            }
        }
    }
    sprintf(team_matchup_message_buffer, ((O_8031224C *)this)->strs->fmt, names[0], names[1], names[2], names[3]);
    append_line__14TWindowMessageFii(((O_8031224C *)this)->w0, team_matchup_message_buffer, 0x80);
    ((O_8031224C *)this)->timer = 0xF0;
    set_score((s32)((void *)4));
}

void TPlayerBattleCtrl4P::wait_for_team_matchup() {
    s32 temp_r0;

    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        set_score((s32)((void*)(5)));
    }
}

void TPlayerBattleCtrl4P::begin_ready_wait() {
    ready_timer = 0x384;
    set_score((s32)((void*)(6)));
}

void TPlayerBattleCtrl4P::update_ready_wait() {
    ready_timer = (ready_timer - 1);
    if ((check_all_players_flag__19TPlayerBattleCtrl4PFv(this) != 0) || ((s32) ready_timer >= 0)) {
        if (this->intro_window != (void *) 0) {
        ((TWindowBase *)this->intro_window)->close();
        this->intro_window = 0U;
        {
            void *temp = __nw__7TObjectFUl(0x28);
            if (temp != 0) {
                __ct__15TDuelEffectCtrlFP7TObjectUc(temp, this, 0);
            }
        }
        frame_timer = 0x96;
        set_score((s32)((void*)((void*)(7))));
        }
    }
}

void TPlayerBattleCtrl4P::wait_for_start_countdown() {
    s32 temp_r0;

    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        set_score((s32)((void*)((void*)(8))));
    }
}

void TPlayerBattleCtrl4P::close_intro_and_start_battle() {
    void *temp_r3 = this->intro_window;
    if ((u32) temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        this->intro_window = 0U;
    }
    set_split_screen_battle_phase(2);
}

void TPlayerBattleCtrl4P::start_battle() { start_duel(); set_score((s32)((void*)((void*)((void*)1)))); }

void TPlayerBattleCtrl4P::update_battle_time_and_rankings() {
    s32 secs;
    s32 r;
    secs = (OSGetTime() - battle_start_ticks) / (*(u32 *)0x800000F8 / 4);
    r = battle_duration - secs;
    remaining_seconds = r > 0 ? r : 0;
    ((TWindowCtrl *)remaining_seconds)->set_timer_window_time();
    if (remaining_seconds == 0) {
        set_split_screen_battle_phase(3);
        return;
    }
    if (is_battle_decided__19TPlayerBattleCtrl4PFv(this) != 0) {
        if (--result_confirm_timer <= 0) {
            set_split_screen_battle_phase(3);
        }
    } else {
        result_confirm_timer = 300;
    }
    update_timed_events(secs);
    if (--player_refresh_timer <= 0) {
        update_player_alive_flags();
        player_refresh_timer = 0x5A;
    }
    calculate_split_screen_battle_rankings(this);
}

void TPlayerBattleCtrl4P::begin_battle_results() {
    s32 i;
    VObj_18_26c590 *p;
    update__19TPlayerBattleCtrl4PFv(this);
    {
        void *temp = __nw__7TObjectFUl(0x28);
        if (temp != 0) {
            __ct__15TDuelEffectCtrlFP7TObjectUc(temp, this, 1);
        }
    }
    frame_timer = 0x1E;
    TWindowCtrl::close_timer_window();
    for (i = 0; i < 4; i++) {
        TPlayerBattleCtrl4P::remove_player(this, i, 1);
    }
    for (i = 0; i < 4; i++) {
        p = (VObj_18_26c590 *)get_player_by_client_id(i);
        if (p != 0) {
            set_frames__15ProtectionTimerFl((u8 *)p + 0x644, 0xE10);
        }
    }
    ((s32 (*)(void *))update_all_players__19TPlayerBattleCtrl4PFv)(this);
    set_score((s32)((void *)1));
}

void TPlayerBattleCtrl4P::wait_after_battle_end() {
    s32 temp_r0;

    update_all_players__19TPlayerBattleCtrl4PFv();
    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        frame_timer = 0x5A;
        set_score((s32)((void*)(2)));
    }
}

void TPlayerBattleCtrl4P::wait_before_recording_results() {
    s32 temp_r0;

    update_all_players__19TPlayerBattleCtrl4PFv();
    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        ready_timer = 0x1E;
        set_score((s32)((void*)(8)));
    }
}

#define get_player_by_client_id ((u32 (*)(s32))get_player_by_client_id)

#define TBL_801C343C ((Rank_801C343C *)&split_screen_battle_rankings)

#define PLAYER_801C343C(k) ((u32 (*)(s32))get_player_by_client_id)(k)

#pragma push

#pragma scheduling off

#pragma optimization_level 1

void TPlayerBattleCtrl4P::open_result_windows() {
  u32 var_r31;
  s32 player;
  if (!((s32)this))
  {
  }
  close_player_windows();
  create_result_windows();
  var_r31 = 0;
  do
  {
    player = ((s32)get_player_by_client_id(var_r31));
    if (player != 0)
    {
      if (check_player_flag1__6TLobbyFv() == 0)
      {
        TPlayerBattleCtrl4P::remove_player((void *) ((s32)this), (int) ((u16) var_r31), 1);
      }
      ((TObjPlayer *)player)->release_attached_resource();
    }
    var_r31 += 1;
  }
  while (((s32) var_r31) < 4);
  set_score((s32)((void*)(4)));
}

#pragma pop

void TPlayerBattleCtrl4P::wait_for_result_window_close() { if (close_windows_on_button() != 0) { close_player_windows(); update_players__19TPlayerBattleCtrl4PFv(this); set_score((s32)((void*)((void*)5))); } }

void TPlayerBattleCtrl4P::update_rematch_menu() {
    static const BattleIntroWindowSize size = {216.0f, 84.0f};
    if (has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) {
        if (((O_80311C2C *)this)->w0 == NULL) {
            ((O_80311C2C *)this)->w0 = create__14TWindowMessageFPvll(get_window_layout_position(0x53), (void *)&size, 1);
            if (((O_80311C2C *)this)->w0 != NULL) {
                ((TWindowMessage *)(((O_80311C2C *)this)->w0))->append_line(((O_80311C2C *)this)->ids->a, 0x80);
            }
        }
        if (((O_80311C2C *)this)->w1 == NULL) {
            ((O_80311C2C *)this)->w1 = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x54), 2);
            forward_trade_action_default__16TObjCityMainWarpFPviii(((O_80311C2C *)this)->w1, ((O_80311C2C *)this)->ids->b, 6, 1);
            forward_trade_action_default__16TObjCityMainWarpFPviii(((O_80311C2C *)this)->w1, ((O_80311C2C *)this)->ids->d, 6, 3);
            ((TWindowSubComCard *)(((O_80311C2C *)this)->w1))->calc_window_size();
            align_menu_entry_positions(((O_80311C2C *)this)->w1);
            ((TCheckRoomSequence *)(((O_80311C2C *)this)->w1))->set_ready_flag();
        }
        if (((O_80311C2C *)this)->w1 != NULL) {
            if (((TWindowMenu *)(((O_80311C2C *)this)->w1))->is_decided() != 0) {
                switch (((TWindowMenu *)(((O_80311C2C *)this)->w1))->get_selected_value()) {
                case 1:
                    shuffle_order();
                    break;
                case 2:
                    break;
                case 3:
                    set_split_screen_battle_phase(4);
                    break;
                }
            } else {
                ((TWindowMenu *)(((O_80311C2C *)this)->w1))->is_cancelled();
            }
        }
    }
}

#pragma push

#pragma scheduling off

void TPlayerBattleCtrl4P::close_rematch_menu() {
    u32 var_r31;
    if ((u32) this->intro_window != 0U) {
        ((TWindowBase *)this->intro_window)->close();
        this->intro_window = 0U;
    }
    if ((u32) this->menu_window != 0U) {
        ((TWindowBase *)this->menu_window)->close();
        this->menu_window = 0U;
    }
    var_r31 = 0;
    do {
        if ((((s32)get_player_by_client_id(var_r31)) != 0U) && (check_player_flag1__6TLobbyFv() != 0)) {
            send_code_45_to_window__19TPlayerBattleCtrl4PFPvii((this), ((u16) var_r31), 1);
        }
        var_r31 += 1;
    } while ((s32) var_r31 < 4);
    set_score((s32)((void*)(7)));
}

#pragma pop

void TPlayerBattleCtrl4P::wait_for_rematch_menu_button() {
    if ((get_player_by_client_id(local_client_id) != 0U) && (check_flag_100__10TObjPlayerFPv() == 0) && (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 6) != 0)) {
        set_score((s32)((void*)(5)));
    }
}

void TPlayerBattleCtrl4P::record_battle_results_after_delay() {
    s32 temp_r4;
    TPlayerBattleCtrl4P::update_all_players();
    temp_r4 = ready_timer;
    ready_timer = (temp_r4 - 1);
    if ((set_state__19TPlayerBattleCtrl4PFv(this, temp_r4) != 0) || ((s32) ready_timer <= 0)) {
        reset_score_counters();
        calculate_split_screen_battle_rankings(this);
        record_split_screen_battle_results(this);
        if ((s32) split_screen_battle_rankings[0].id == (s32) local_client_id) {
            TPlayerBattleCtrl4P::notify_lobby((void*)this, (void*)lbl_80475BC4, (void*)0x96);
        } else {
            TPlayerBattleCtrl4P::notify_lobby((void*)this, (void*)lbl_80475BCC, (void*)0x96);
        }
        set_score((s32)((void*)(3)));
    }
}

void TPlayerBattleCtrl4P::close_battle_results() {
    s32 i;
    u32 p;
    if (intro_window != NULL) {
        ((TWindowBase *)intro_window)->close();
        intro_window = NULL;
    }
    if (menu_window != NULL) {
        ((TWindowBase *)menu_window)->close();
        menu_window = NULL;
    }
    close_player_windows();
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0) {
            obj_clear_flag30_20000((void *)p);
        }
    }
    TWindowCtrl::close_timer_window();
    for (i = 0; i < 4; i++) {
        TPlayerBattleCtrl4P::remove_player(this, i, 1);
    }
}

void TPlayerBattleCtrl4P::begin_battle_reload() {
    s32 var_r31;
    u32 ret;

    var_r31 = 0;
    do {
        ret = get_player_by_client_id(var_r31);
        if (ret != 0U) {
            play_effect_default__10TObjPlayerFii(ret, -1);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
    frame_timer = 0xF;
    set_score((s32)((void*)(1)));
}

void TPlayerBattleCtrl4P::begin_battle_reload_fade() {
    if (--this->frame_timer <= 0) {
        TLobby__sub_8020BC50();
        TLobby__sub_801036CC();
        if (quest_mission_manager != NULL) {
            TQuestThread::clear_buffer(quest_mission_manager);
        }
        TLobby::stop_audio_streams();
        TPlayerBattleCtrl4P__init_flag = 0;
        TLobby::init_fadeout_state((s32)(TPlayerBattleCtrl4P::init));
        set_score((s32)((void*)((void *)2)));
    }
}

void TPlayerBattleCtrl4P::finish_battle_reload() {
    if ((s32) TPlayerBattleCtrl4P__init_flag != 0) {
        reset_players__19TPlayerBattleCtrl4PFv();
        TLobby::set_fade_params((s32)reset_ctrl_to_default__19TPlayerBattleCtrl4PFv);
        set_score((s32)((void*)(3)));
    }
}

void TPlayerBattleCtrl4P::sub_80311890() {  }

void TPlayerBattleCtrl4P::return_to_hunters_guild() {
    void *o;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        ((THunterGuildSeqOffline *)o)->init(tl_00, (s32 *)TPlayerBattleCtrl4P::reset_random_enemies_mode);
    }
    queue_destruction__7TObjectFv(this);
}

void TPlayerBattleCtrl4P::reset_random_enemies_mode() { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); }

void TPlayerBattleCtrl4P::sub_80311804() {  }

void TPlayerBattleCtrl4P::sub_80311800() {  }

void TPlayerBattleCtrl4P::init_battle() {
    s32 j;
    s32 i;
    u8 *p;
    ((Ctl_8031171C *)this)->f244 = get_split_screen_battle_timer_limit((u8 *)((Ctl_8031171C *)this));
    TWindowCtrl::create_alt_timer();
    ((TWindowCtrl *)(((Ctl_8031171C *)this)->f244))->set_timer_window_time();
    TOMineTrap::destroy_matching_traps();
    this->apply_rule_configuration(1);
    for (i = 0; i < 4; i++) {
        TPlayerBattleCtrl4P::remove_player(this, i, 1);
        p = (u8 *)get_player_by_client_id(i);
        if (p != 0) {
            obj_set_flag_20000();
            ((TLobby *)(p + 0x78C))->update_child_player();
            ((TLobby *)(p + 0x77C))->update_child_player();
            ((TLobby *)(p + 0x75C))->update_child_player();
            ((TLobby *)(p + 0x76C))->update_child_player();
            ((TLobby *)(p + 0x79C))->update_child_player();
            ((TPlayerBattleCtrl4P *)(p + 0x7AC))->set_battle_mode(0);
        }
    }
    ((Ctl_8031171C *)this)->f248 = 0x5A;
    calculate_split_screen_battle_rankings(this);
    for (j = 0; j < 4; j++) {
        ((Ctl_8031171C *)this)->ok[j] = 1;
    }
}

void TPlayerBattleCtrl4P::start_duel() {
    s32 i;
    s32 j;
    u32 p;
    char *name;
    void *w;
    s32 st;
    TObjEneRe4Sorcerer__sub_801E3F14(4);
    TObjEneRe4Sorcerer__sub_801E3F18();
    ((O_80311618 *)this)->time = OSGetTime();
    for (i = 0; i < 4; i++) {
        ((void (*)(void *, u16, s32))send_code_45_to_window__19TPlayerBattleCtrl4PFPvii)(this, i, 1);
        p = get_player_by_client_id(i);
        if (p != 0) {
            obj_clear_flag30_20000((void *)p);
        }
    }
    this->reset_score_counters();
    name = get_current_floor_area() == AREA_BATTLE1 ? lbl_80475BAC : lbl_80475BB8;
    w = __nw__7TObjectFUl(0x40);
    if (w != NULL) {
        init_with_name__6TLobbyFPvPvPvPv(w, this, name, 0x2D);
    }
    for (j = 0; j < 8; j++) {
        ((O_80311618 *)this)->flags[j] = 1;
        if (battle_event_second_table[j] == 0) {
            ((O_80311618 *)this)->flags[j] = 0;
        }
    }
    ((O_80311618 *)this)->v = TLobby__battle_ctrl_default_value;
}

void TPlayerBattleCtrl4P::update() {
    s32 var_r31;
    s32 var_r31_2;
    u32 player;

    ((s32 (*)())refresh_split_screen_battle_alive_flags)();
    var_r31 = 0;
    do {
        if (get_player_by_client_id(var_r31) != 0U) {
            obj_set_flag_20000();
        }
        var_r31 += 1;
    } while (var_r31 < 4);
    queue_destroy_event_descendants(tl_01);
    TQuestThread::destroy_all_in(tl_00);
    TLobby__sub_8020BCE4();
    TLobby__sub_8020BB18();
    var_r31_2 = 0;
    do {
        player = get_player_by_client_id(var_r31_2);
        if (player != 0U) {
            clear_trap_counts((s8 *)(player + 0x7C4));
        }
        var_r31_2 += 1;
    } while (var_r31_2 < 4);
}

void TPlayerBattleCtrl4P::shuffle_order() {
    O_80311400 *o = (O_80311400 *)this;
    s32 order[4];
    s32 i;
    s32 a;
    s32 b;
    s32 t;
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    for (i = 0; i < 30; i++) {
        a = (s32)(4.0f * (3.0517578e-05f * (f32)rand()));
        b = (s32)(4.0f * (3.0517578e-05f * (f32)rand()));
        if (a != b) {
            t = order[a];
            order[a] = order[b];
            order[b] = t;
        }
    }
    for (i = 0; i < 4; i++) {
        o->order[i] = order[i];
    }
    if (this->intro_window != NULL) {
        ((TWindowBase *)this->intro_window)->close();
        this->intro_window = NULL;
    }
    if (this->menu_window != NULL) {
        ((TWindowBase *)this->menu_window)->close();
        this->menu_window = NULL;
    }
    close_player_windows();
    set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl((u8 *)o, 5);
}

void TPlayerBattleCtrl4P::reset_players() {
    s32 i;
    void *p;
    TLobby::init_scene_objects();
    for (i = 0; i < 4; i++) {
        p = (void *)get_player_by_client_id(i);
        if (p != 0) {
            TObjPlayer__send_selected_spawn_position(p, ((Ctl_80311380 *)this)->tbl[get_entity_id(p)]);
            reset_cameras_to_actor(p, 0);
        }
    }
    destroy_matching_children__19TPlayerBattleCtrl4PFPvPv(this, (Par_80311304 *)(tl_05));
    TAdSinglePlyChrSelectGC::destroy();
}

void destroy_matching_children__19TPlayerBattleCtrl4PFPvPv(void *self, Par_80311304 *p) {
    Node_80311304 *n = p->head;
    Node_80311304 *cur;
    while (p->head != 0 && n != 0) {
        cur = n;
        n = cur->next;
        if (check_value_equals__13TUnk_804B6C24Fl(cur, lbl_805D2A98) != 0) {
            queue_destruction__7TObjectFv(cur);
        } else {
            destroy_matching_children__19TPlayerBattleCtrl4PFPvPv(self, (Par_80311304 *)cur);
        }
    }
}

void TPlayerBattleCtrl4P::update_all_players() {
    s32 var_r31;

    var_r31 = 0;
    do {
        if (get_player_by_client_id(var_r31) != 0U) {
            release_attached_resource__10TObjPlayerFv();
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TPlayerBattleCtrl4P::set_split_screen_battle_phase(s32 arg1) {
    this->phase = arg1;
    this->phase_state = 0;
}

void TPlayerBattleCtrl4P::set_score(s32 v) { this->phase_state = v; }

s32 get_split_screen_battle_timer_limit(u8 *arg0) {
    return *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x1C)) + 0x24) * 0x3C;
}

#pragma push

#pragma opt_lifetimes off

void TPlayerBattleCtrl4P::apply_rule_configuration(s32 arg1) {
    Ctl_80310F10 *o = (Ctl_80310F10 *)this;
  s32 w;
  s32 i;
  s32 flag;
  s32 t;
  s32 j;
  u32 p;
  s32 v;
  ((TLobby *)((s32 *)&lobby_rule_settings))->reset_settings_to_default();
  if (arg1 != 0)
  {
    set_validated_field_0x1__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[0]);
    set_field_2__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[1]);
    set_field_3__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[2]);
    set_clamped_field_4__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[3]);
    set_field_5__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[4]);
    set_field_0x6__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[5]);
    set_field7_clamped__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[6]);
    set_difficulty__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[7]);
    set_byte9_clamped__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[8]);
    set_field_b__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[0xA]);
    set_clamped_field_c__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[0xB]);
    fn_801D72B0(((s32 *)&lobby_rule_settings), ((s8 *) o->cfg)[0xC]);
    for (i = 0; i < 4; i++)
    {
      fn_801D6D8C(((s32 *)&lobby_rule_settings), o->cfg[i + 0xD], i);
    }
    set_field_d__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[0x11]);
    ((TObjPlayer *)((s32 *)&lobby_rule_settings))->set_level(((s8 *) o->cfg)[0x12]);
    set_field_0xE__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (void *) o->cfg[0x13]);
    ((TLobby *)((s32 *)&lobby_rule_settings))->set_volume((u8)((void *) ((u8) (*((s32 *) (((s8 *) o->cfg) + 0x18))))));
    ((TLobby *)((s32 *)&lobby_rule_settings))->set_validated_field_0x11((u8)((void *) ((u8) (*((s32 *) (((s8 *) o->cfg) + 0x1C))))));
    ((TLobby *)((s32 *)&lobby_rule_settings))->set_clamped_index((s16)((void *) ((s16) (*((s32 *) (((s8 *) o->cfg) + 0x20))))));
    ((TLobby *)((s32 *)&lobby_rule_settings))->set_clamped_value_1c((s32)((void *) (*((s32 *) (((s8 *) o->cfg) + 0x24)))));
    fn_801D726C(((s32 *)&lobby_rule_settings), (void *) ((u8) (*((s16 *) (((s8 *) o->cfg) + 0x28)))));
    flag = 0;
    if ((((s32) o->cfg[9]) == 1) && (TLobby::get_game_mode() == 4))
    {
      t = 1;
      for (j = 0; j < 4; j++)
      {
        p = ((u32)get_player_by_client_id(j));
        if (p != 0)
        {
          t = 1 - t;
          w = 2;
          if (t != 0)
          {
            w = 1;
          }
          o->team[j] = w;
          set_player_team_id((void *)(p + 0x828), o->team[(((((((((((j & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu]);
        }
        else
        {
          o->team[j] = -1;
        }
      }
      flag = 1;
    }
    set_field_a__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), (u8) (flag != 0));
    for (j = 0; j < 4; j++)
    {
      p = ((u32)get_player_by_client_id(j));
      if (p != 0)
      {
        ((TLobby *)(p + 0x78C))->set_scale(lbl_805D3538);
        ((TLobby *)(p + 0x78C))->set_pos_z(lbl_805D3548);
        ((TLobby *)(p + 0x77C))->set_scale(lbl_805D353C);
        ((TLobby *)(p + 0x77C))->set_pos_z(lbl_805D5DC4);
        ((TLobby *)(p + 0x75C))->set_scale(lbl_805D3540);
        ((TLobby *)(p + 0x75C))->set_pos_z(lbl_805D354C);
        ((TLobby *)(p + 0x76C))->set_scale(lbl_805D3544);
        ((TLobby *)(p + 0x76C))->set_pos_z(lbl_805D3550);
        ((TLobby *)(p + 0x79C))->set_scale(lbl_805D5DC8);
        ((TLobby *)(p + 0x79C))->set_pos_z(lbl_805D5DC8);
      }
    }
    set_section_id__6TLobbyFPvUc(((s32 *)&lobby_rule_settings), 1);
  }
  for (j = 0; j < 4; j++)
  {
    if (((u32)get_player_by_client_id(j)) != 0)
    {
      TLobby::apply_battle_rules_to_players();
    }
  }
}

#pragma pop

void TPlayerBattleCtrl4P::remove_player(void *arg0, u16 arg1, s32 arg2) {
    u32 id;
    u32 temp;

    id = arg1;
    temp = get_player_by_client_id(id);
    if (temp != 0U) {
        play_effect_default__10TObjPlayerFii(temp, -1);
    }
    if (arg2 != 0) {
        begin_player_keyboard_hold(id);
        request_active_window_close();
        ((TWindowCtrl *)id)->suppress_slot();
    }
}

s32 calculate_split_screen_battle_rankings(void *) {
    s32 n;
    s32 i;
    s32 j;
    u32 p;
    s32 rank;
    s32 m;
    s32 k;
    for (k = 0; k < 4; k++) {
        TBL_801C343C[k].id = 0xFFFF;
        TBL_801C343C[k].rank = 0;
        TBL_801C343C[k].score = 0;
    }
    n = 0;
    if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
        Team_801C343C team = {0, 0};
        for (k = 0; k < 4; k++) {
            p = PLAYER_801C343C(k);
            if (p != 0) {
                s32 t = TLobby__sub_801C19D0((void *)(p + 0x828)) != 1 ? 1 : 0;
                team.v[t] += TLobby__sub_801C4FC4((void *)(p + 0x7AC));
            }
        }
        for (k = 0; k < 4; k++) {
            p = PLAYER_801C343C(k);
            if (p != 0) {
                TBL_801C343C[n].id = get_entity_id((void *)p);
                TBL_801C343C[n].score = team.v[TLobby__sub_801C19D0((void *)(p + 0x828)) != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = PLAYER_801C343C(k);
            if (p != 0) {
                TBL_801C343C[n].id = get_entity_id((void *)p);
                TBL_801C343C[n].score = TLobby__sub_801C4FC4((void *)(p + 0x7AC));
                n++;
            }
        }
        if (n <= 1) {
            return 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        if (TBL_801C343C[i].id != 0xFFFF) {
            for (j = i + 1; j < n; j++) {
                if (TBL_801C343C[j].id != 0xFFFF && TBL_801C343C[i].score < TBL_801C343C[j].score) {
                    Rank_801C343C tmp = TBL_801C343C[i];
                    TLobby__sub_801C36E4(&TBL_801C343C[i], &TBL_801C343C[j]);
                    TLobby__sub_801C36E4(&TBL_801C343C[j], &tmp);
                }
            }
        }
    }
    rank = 0;
    for (m = 0; m < n; m++) {
        TBL_801C343C[m].rank = rank;
        if (m < n - 1 && TBL_801C343C[m].score != TBL_801C343C[m + 1].score) {
            rank = m + 1;
        }
    }
    return 1;
}

s32 TPlayerBattleCtrl4P::check_all_players_flag() {
    s32 var_r31;
    u32 var_r3;

    var_r31 = 0;
loop_1:
    var_r3 = get_player_by_client_id(var_r31);
    if ((var_r3 != 0U) && (obj_testFlags30__14TObjCollidableFUl(var_r3, 0x02000000) != 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 1;
    }
    goto loop_1;
}

void send_code_45_to_window__19TPlayerBattleCtrl4PFPvii(void *arg0, s32 arg1, s32 arg2) {
    u16 temp_r31;
    s32 temp_r30;

    temp_r31 = (u16)arg1;
    temp_r30 = arg2;
    if (get_player_by_client_id(temp_r31) != 0U) {
        send_code_45_1__10TObjPlayerFl();
    }
    if (temp_r30 != 0) {
        end_player_keyboard_hold(temp_r31);
        TWindowCtrl::clear_flag();
        ((TWindowCtrl *)temp_r31)->unsuppress_slot();
    }
}

#undef get_player_by_client_id

u8 TPlayerBattleCtrl4P::is_battle_decided() {
    O_803109D4 *o = (O_803109D4 *)this;
    s32 count = 0;
    s32 i = 0;
    s32 ok;
    s32 team;
    u8 *p;
    P_803109D4 seen = {0, 0};
    do {
        p = (u8 *)get_player_by_client_id(i);
        if (p != NULL) {
            ok = 1;
            if (o->active[i] == 0) {
                ok = 0;
            } else if (*(s32 *)((s8 *)p + 0x30) & 0x800) {
                if (TLobby__sub_801D7100(lobby_rule_settings) == 1) {
                    ok = 0;
                } else if (TLobby__sub_801D7100(lobby_rule_settings) == 2 && ((TPlayerBattleCtrl4P *)(p + 0x754))->get_state() == 0) {
                    ok = 0;
                }
            }
            if (ok != 0) {
                count++;
                if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
                    team = TLobby__sub_801C19D0(p + 0x828) - 1;
                    if (team >= 0 && team < 2) {
                        seen.v[team] = 1;
                    }
                }
            }
        }
        i++;
    } while (i < 4);
    if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1 && (seen.v[0] == 0 || seen.v[1] == 0)) {
        return 1;
    }
    return count <= 1;
}

void TPlayerBattleCtrl4P::update_timed_events(s32 frames) {
    s32 i;
    switch (((Ctl_80310910 *)this)->state) {
    case 0:
        if (local_client_id == TLobby__designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (((Ctl_80310910 *)this)->flags[i] != 0 && frames / 60 == battle_event_second_table[i]) {
                    ((Ctl_80310910 *)this)->flags[i] = 0;
                    request_split_screen_battle_event(this);
                }
            }
        }
        break;
    case 1:
        ((TPlayerBattleCtrl4P *)((Ctl_80310910 *)this))->set_state();
        break;
    case 2:
        ((TPlayerBattleCtrl4P *)((Ctl_80310910 *)this))->start_match();
        break;
    }
}

void request_split_screen_battle_event(void* p) { *(s32*)((char*)p + 0x260) = 1; }

void TPlayerBattleCtrl4P::start_match() {
    char buf[0x40];
    Ent_80310830 *e;
    s32 i;
    VObj_80310830 *p;
    reset_score_counters();
    calculate_split_screen_battle_rankings(this);
    TWindowCtrl::init_all((void*)lbl_80475B90, (void*)0x200);
    for (i = 0; i < 4; i++) {
        e = &((Ent_80310830 *)&split_screen_battle_rankings)[i];
        p = (VObj_80310830 *)get_player_by_client_id(e->id);
        if (p != 0) {
            sprintf(buf, lbl_80475B98, TPlayerBattleCtrl4P_player_name_formats[e->idx], p->v10());
            TWindowCtrl::init_all((void*)buf, (void*)0x200);
        }
    }
    TPlayerBattleCtrl4P::notify_lobby(this, lbl_80475BA0, (void *)0x3C);
}

void TPlayerBattleCtrl4P::update_players() {
    s32 var_r31;
    void *player;

    var_r31 = 0;
    do {
        player = get_player_by_client_id(var_r31);
        if ((player != NULL) && (*(s32 *)((s8 *)player + 0x30) & 0x800)) {
            ((VObj_803107D0_8031058C *)player)->v64();
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

s32 TPlayerBattleCtrl4P::set_state() {
    this->timed_event_state = 2;
    return 1;
}

void record_split_screen_battle_results(void *) {
    void *obj;
    s8 *base;
    s32 outer;
    s32 off;
    s8 *entry;
    outer = 0;
    base = (s8 *)&split_screen_battle_rankings;
    off = 0;
    do {
        entry = base + off;
        if (get_player_by_client_id(*(u16 *)((s8 *)entry + 0)) != NULL) {
            obj = get_character_save_record(*(u16 *)((s8 *)entry + 0));
            if (obj != NULL) {
                s16 field2 = *(s16 *)((s8 *)entry + 2);
                if (are_split_screen_battle_players_tied() == 0) {
                    switch (field2) {
                    case 0:
                        {
                            s32 inc = (s32)(u16)*(u16 *)((s8 *)obj + 0x2354) + 1;
                            s32 lim = 0xFFFF;
                            if (inc < lim) lim = inc;
                            *(u16 *)((s8 *)obj + 0x2354) = lim;
                        }
                        break;
                    case 1:
                        {
                            s32 inc = (s32)(u16)*(u16 *)((s8 *)obj + 0x2356) + 1;
                            s32 lim = 0xFFFF;
                            if (inc < lim) lim = inc;
                            *(u16 *)((s8 *)obj + 0x2356) = lim;
                        }
                        break;
                    case 2:
                        {
                            s32 inc = (s32)(u16)*(u16 *)((s8 *)obj + 0x2358) + 1;
                            s32 lim = 0xFFFF;
                            if (inc < lim) lim = inc;
                            *(u16 *)((s8 *)obj + 0x2358) = lim;
                        }
                        break;
                    case 3:
                        {
                            s32 inc = (s32)(u16)*(u16 *)((s8 *)obj + 0x235A) + 1;
                            s32 lim = 0xFFFF;
                            if (inc < lim) lim = inc;
                            *(u16 *)((s8 *)obj + 0x235A) = lim;
                        }
                        break;
                    }
                }
                {
                    s32 v = *(u16 *)((s8 *)obj + 0x235C) - 1;
                    *(u16 *)((s8 *)obj + 0x235C) = (u16) (v & ((s32) (-v & ~v) >> 0x1F));
                }
            }
        }
        outer += 1;
        off += 8;
    } while (outer < 4);
    TAdSinglePlyChrSelectGC__sub_801FCE6C();
}

void TPlayerBattleCtrl4P::reset_score_counters() { this->timed_event_state = 0; *(s32 *)&this->unknown_290 = 0; }

void TPlayerBattleCtrl4P::notify_lobby(void* p, void* a1, void* a2) { play_cue_stream_file((s32)a1); show_duel_result_window((s32)((void*)-50), (s32)a2); }

int TPlayerBattleCtrl4P::init_ctrl_default(void* p) { return ((int (*)(void*, int))set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl)(p, 0); }

void TPlayerBattleCtrl4P::init() {
    TLobby__sub_801B09A4();
    advance_item_system_generation();
    TPlayerBattleCtrl4P__init_flag = 1;
}

void TPlayerBattleCtrl4P::reset_ctrl_to_default() {
    void *temp_r3;
    temp_r3 = TPlayerBattleCtrl4P__instance;
    if (temp_r3 != NULL) {
        TPlayerBattleCtrl4P::init_ctrl_default(temp_r3);
    }
}

void refresh_split_screen_battle_alive_flags(void* p) { ((TPlayerBattleCtrl4P *)p)->update_player_alive_flags(); }

void TPlayerBattleCtrl4P::update_player_alive_flags() {
    s32 i;
    Ent_803104CC *e;
    s32 v;
    for (i = 0; i < 4; i++) {
        e = (Ent_803104CC *)get_player_by_client_id(i);
        if (e != NULL) {
            ((s32 (*)(void *, void *))calc_battle_score__19TPlayerBattleCtrl4PFPvPv)(this, e);
            v = 1;
            if (e->flags & 0x800) {
                if (TLobby__sub_801D7100(lobby_rule_settings) == 1) {
                    v = 0;
                } else if (TLobby__sub_801D7100(lobby_rule_settings) == 2 && ((TPlayerBattleCtrl4P *)(e->sub))->get_state() == 0) {
                    v = 0;
                }
            }
            ((Ctl_803104CC *)this)->ok[i] = v;
        }
    }
}

extern "C" {
s32 calc_battle_score__19TPlayerBattleCtrl4PFPvPv(void *self, u8 *arg1) {
    f32 score;
    s32 mode;

    score = (f32)TWindowDuelResult__sub_801C19AC(arg1 + 0x78C);
    score -= (f32)TWindowDuelResult__sub_801C19AC(arg1 + 0x77C);
    score += (f32)TWindowDuelResult__sub_801C19AC(arg1 + 0x75C);
    score -= (f32)TWindowDuelResult__sub_801C19AC(arg1 + 0x76C);
    score += (f32)obj_getPtr2B0_20(arg1) * fn_801C19A4(arg1 + 0x79C);
    mode = (s32)score;
    ((TPlayerBattleCtrl4P *)(arg1 + 0x7AC))->set_battle_mode(mode);
    return mode;
}
}

extern "C" {
s32 are_split_screen_battle_players_tied(void) {
    Ent_8031030C *e;
    s32 result;
    s32 i;
    result = 1;
    for (i = 0; i < 4; i++) {
        e = &((Ent_8031030C *)&split_screen_battle_rankings)[i];
        if (get_player_by_client_id(e->id) != NULL && e->idx != 0) {
            result = 0;
            break;
        }
    }
    return result;
}
}

extern "C" {
s32 *get_split_screen_battle_rankings(void) {
    return (s32 *)split_screen_battle_rankings;
}
}

u8 TPlayerBattleCtrl4P::is_battle_mode_active() {
    T_803102C8 *p = (*(T_803102C8 * *)&TPlayerBattleCtrl4P__instance);
    if (p != 0) {
        return p->mode == 1 || p->mode == 2;
    }
    return 0;
}

extern "C" {
void clear_split_screen_battle_window_slots(T_803102A4 *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}
}

void TPlayerBattleCtrl4P::create_result_windows() {
    Ctl_80310230 *o = (Ctl_80310230 *)this;
    s32 i;
    void *w;
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            w = __nw__7TObjectFUl(0x6C);
            if (w != 0) {
                w = TWindowDuelResult__ct(w, i);
            }
            o->win[i] = w;
        }
    }
}

void TPlayerBattleCtrl4P::close_player_windows() {
    Ctl_803101D4 *o = (Ctl_803101D4 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (o->win[i] != 0) {
            ((TWindowBase *)(o->win[i]))->close();
            o->win[i] = 0;
        }
    }
}

s32 TPlayerBattleCtrl4P::close_windows_on_button() {
    Ctl_8031012C *self = (Ctl_8031012C *)this;
    s32 r = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            if (self->win[i] != NULL) {
                if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[get_map_id__13TRaderMapCoreFv()], 2) != 0) {
                    ((TWindowBase *)(self->win[i]))->close();
                    self->win[i] = 0;
                } else {
                    r = 0;
                }
            }
        }
    }
    return r;
}
