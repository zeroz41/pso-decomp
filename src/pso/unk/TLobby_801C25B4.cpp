#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TDuelEffectCtrl.h"
#include "pso/network/client_id.h"
#include "pso/system/memory.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include <stdio.h>
#include <stdlib.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TQuestManager.h"
#include "pso/map/TSetEvtDestroy.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TDelayedAreaMusic.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/network/TLobby.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/unk/text_801C23A8.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/text_800C7FEC.h"
#include <string.h>
#include "pso/ui/Language.h"

#include "pso/object/base/TObjMotion.h"



#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/player/PlayerTrapCounts.h"
#include <dolphin/os/OSTime.h>
#include "pso/unk/TLobby_801A3C48.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
// The placement ordinals show_score_results prints; their strings open the unit's .sdata2.
#pragma push
char *lobby_rank_ordinal_text_table[] = {"1st", "2nd", "3rd", "4th"};


TPlayerBattleCtrl *battle_mode_data_ptr;
s32 lbl_805D5D9C;
s32 battle_config_ptr;
s32 lbl_805D5DA4;
s32 lbl_805D5DA8;
s32 lbl_805D5DAC;
s32 lbl_805D5DB0;
s32 lbl_805D5DB4;
void *lobby_char_slot_array;
u8 battle_player_ready_flags[4];
s32 battle_ctrl_default_value;
f32 battle_enemy_take_damage_score;
f32 battle_meseta_score;

typedef struct UpdateBattleSyncLobby {
    u8 pad0[0x268];
    s8 pending[8];
    s32 state;
} UpdateBattleSyncLobby;


void play_duel_result_stream(const char *file, saddr duration);
extern "C" {
u8 is_battle_mode_running(void);
s32 TLobby__sub_801C2678(void);
extern s16 battle_event_second_table[];
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
s32 is_duel_ranking_empty(void);
extern u8 player_battle_ctrl_text_japanese[];
extern u8 player_battle_ctrl_text_english[];
struct SendBattleModeDataS801C295C { s32 f0; s8 f4; s8 pad[0x13]; };

void build_6x7D_set_battle_mode_data(void *p);

// "TPlayerBattleCtrl" opens the unit's .rodata, ahead of the pairs below.
f32 battle_player_give_damage_score = 0.05f;
f32 battle_player_take_damage_score = 0.02f;
f32 battle_player_kill_score = 10.0f;
f32 battle_player_death_score = 7.0f;
f32 battle_enemy_give_damage_score = 0.01f;
f32 battle_enemy_kill_score = 3.0f;
f32 battle_enemy_death_score = 7.0f;
const char *player_battle_ctrl_name = "TPlayerBattleCtrl";
extern "C" {
__declspec(section ".rodata") u32 lbl_80446F94[2] = { 0x43A40000, 0x43260000 };
__declspec(section ".rodata") u32 lbl_80446F9C[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FA4[2] = { 0x43580000, 0x42A80000 };
__declspec(section ".rodata") u32 lbl_80446FAC[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FB4[2] = { 0x436E0000, 0x433C0000 };
__declspec(section ".rodata") u32 lbl_80446FBC[2] = { 0, 0 };
}
#define lbl_80446F94 ((UpdateBattleIntroPair *)lbl_80446F94)
#define lbl_80446F9C ((UpdateBattleIntroCnt *)lbl_80446F9C)
#define lbl_80446FAC ((CheckTeamBalanceCount *)lbl_80446FAC)
#define lbl_80446FB4 ((TLobbyPair *)lbl_80446FB4)
#define lbl_80446FBC ((CalcPlayerRankingsTeam *)lbl_80446FBC)

}

typedef struct SendBattleModeStateMsg {
    u8 pad0[4];
    u8 kind;
    u8 pad5[2];
    u8 enabled;
    u32 id;
    s32 player;
    u8 pad10[0x10];
} SendBattleModeStateMsg;

typedef struct SendBattleModeStatePlayer {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x754 - 0x34];
    u8 ctrl[4];
} SendBattleModeStatePlayer;


extern "C" {

void build_6x7D_set_battle_mode_data(void *);

struct UpdateTimedWaitLobby;
s32 calc_player_rankings__6TLobbyFPv(UpdateTimedWaitLobby *);

}

struct TLobbyStack {
    s32 sp8;
    s8 spC;
    u8 pad_D[0x3];
    s32 sp10;
};

typedef struct StartDuelBattleLobby {
    u8 pad0[0x30];
    u64 time;
    u8 pad38[0x64 - 0x38];
    s32 f64;
    u8 pad68[0x268 - 0x68];
    s8 pending[8];
} StartDuelBattleLobby;

typedef struct Send6x7DSetBattleModeDataMsg {
    s32 hdr;
    s8 sub;
    u8 pad5[3];
    s32 order[4];
} Send6x7DSetBattleModeDataMsg;

extern "C" {
void TLobby__sub_801C2C34(void *);
}
void clear_battle_player_ready_flags(void);
extern "C" {
void obj_clear_flag30_20000(void *);
void TObjEneRe4Sorcerer__sub_801E3F14(s32);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
extern const char *dead_spot_class_name;

extern u16 battle_mode_data_table[];
void send_6x7D_set_battle_mode_data(void *);
s32 obj_set_flag_20000();
s32 get_battle_time_limit_frames();
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void TLobby__sub_8020BB18(void);
void TLobby__sub_8020BCE4(void);
}

struct SendBattleModeParamsStack {
    s32 sp8;
    s8 spC;
    s8 spD;
    u8 pad_E[0x2];
    s32 sp10;
    s32 sp14;
};

typedef struct TLobbyPair { u32 a; u32 b; } TLobbyPair;


typedef struct UpdatePlayerBattleCtrlStateLobby {
    u8 pad0[0x20];
    s32 state;
    s32 next;
    u8 pad28[0x40 - 0x28];
    s32 *msgs;
    u8 pad44[0x4C - 0x44];
    void *window;
    u8 pad50[0x58 - 0x50];
    s32 f58;
} UpdatePlayerBattleCtrlStateLobby;

struct Handle6x7DSetBattleModeDataPacket {
    u8 pad0[4];
    s8 type;
    s8 mode;
    u8 pad6;
    s8 team;
    s32 v[4];
};

struct Handle6x7DSetBattleModeDataLobby {
    u8 pad0[0x24];
    s32 mode;
    u8 pad28[0x30];
    s32 a;
    s32 b;
};

struct UpdateTimedWaitLobby {
    u8 pad0[0x20];
    s32 state;
    s32 result;
    u8 pad28[8];
    s64 start;
    s32 remain;
    s32 limit;
    u8 pad40[8];
    s32 timer48;
    u8 pad4c[0x14];
    s32 timer60;
};

struct Cfg_801C3D50 {
    u8 b[0xC];
    s8 c;
    u8 arr[4];
    u8 d11;
    s8 lvl;
    u8 d13;
    u8 pad14[4];
    s32 vol;
    s32 v1c;
    s32 v20;
    s32 v24;
    s16 v28;
};

struct UpdateBattleIntroPair { s32 a, b; };

struct UpdateBattleIntroName { char s[16]; };

struct UpdateBattleIntroLobby {
    u8 pad0[0x20];
    s32 state;
    s32 next;
    u8 pad28[4];
    s32 timer;
    u8 pad30[0x10];
    u8 *cfg;
    s32 timer2;
    u8 pad48[4];
    void *window;
    u8 pad50[0x18];
    u8 msg[0x80];
};

struct UpdateBattleIntroCnt { s32 v[2]; };


struct CalcPlayerRankingsTeam { s32 v[2]; };

typedef struct CheckTeamBalanceCount { s32 v[2]; } CheckTeamBalanceCount;

extern "C" {
void handle_6x7E(void);
void TLobby__sub_801C38A4(void);
void TLobby__sub_801B09A4(void);


void request_active_window_close(void);
s32 get_battle_time_limit_frames(void);
void __destroy_new_array(void *, void *);
void free_char_slots(void);
int TKeyBoardControl__sub_8000F828(void);
void TAdSinglePlyChrSelectGC__sub_801C5120(void);
void TAdSinglePlyChrSelectGC__sub_801C5158(void);
void *__construct_new_array(void *, void *, void *, s32, s32);
void *__dt__19PlayerCharDataEntryFv(void *entry, s16 mode);
void construct__19PlayerCharDataEntryFv(void);

void TLobby__sub_801C3AF4(UpdatePlayerBattleCtrlStateLobby *self);


void handle_6x7D_set_battle_mode_data(Handle6x7DSetBattleModeDataPacket *pkt);
}

extern "C" {
s32 fn_801D6D8C(void *, int, int);
s32 fn_801D726C(void *, int);
s32 fn_801D72B0(void *, int);
extern u32 player_slot_table[];

extern s32 battle_intro_value_table[];
void obj_clear_flag30_20000(void *actor);
}

void record_local_battle_placement(void *);
extern "C" {


void update_duel_result__6TLobbyFPv(TPlayerBattleCtrl *ctrl);



extern char battle_intro_message_buffer[];


void reset_map(void);
void TLobby__sub_8020BC50(void);
void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl);


s32 check_team_balance__6TLobbyFPvi(UpdateTimedWaitLobby *self, s32 arg1);
void TKeyBoardControl__sub_8000F950(void);
extern s32 evt2_random_enemies_mode;
void TAdSinglePlyChrSelectGC__sub_801C50C0(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50CC();
void TAdSinglePlyChrSelectGC__sub_801C50D8(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50E4();
void TAdSinglePlyChrSelectGC__sub_801C50F0(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50FC();
void TAdSinglePlyChrSelectGC__sub_801C5108(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C5114();
void handle_6x7F_battle_scores(saddr command);
void play_area_music(char *name);
}

void record_local_battle_placement(void *arg0);


#define CFG (*(Cfg_801C3D50 **)&battle_config_ptr)


void update_player_battle_ctrl_state(void *player_battle_ctrl);
extern "C" {

void fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl);
}

extern s32 lbl_805D55C0;

BattleRanking duel_result_table[4];
s32 battle_team_table[4];
s16 battle_event_second_table[8];
u16 battle_mode_data_table[4];
s32 battle_intro_value_table[4];
char battle_intro_message_buffer[0x100];

TPlayerBattleCtrl::TPlayerBattleCtrl(TObject *parent) : TObject(parent) {
    TObjPlayer *player;
    m_name = player_battle_ctrl_name;
    unk_28 = 0;
    state_24 = 0;
    state_20 = 0;
    state_1c = 0;
    window_4c = NULL;
    window_50 = NULL;
    window_54 = NULL;
    text = (current_language == LANGUAGE_JAPANESE) ? player_battle_ctrl_text_japanese : player_battle_ctrl_text_english;
    player = get_local_player();
    if (player != NULL) {
        player->export_character_data(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    }
    TLobby::stop_audio_streams();
    pad_64 = 0;
}

TPlayerBattleCtrl::~TPlayerBattleCtrl() {
    if (state_20 != -1) {
        state_20 = -1;
        update_player_battle_ctrl_state(this);
    }
    if (window_4c != NULL) ((TWindowBase *)window_4c)->close();
    if (window_50 != NULL) ((TWindowBase *)window_50)->close();
    if (window_54 != NULL) ((TWindowBase *)window_54)->close();
    battle_mode_data_ptr = 0;
}

void TPlayerBattleCtrl::run_task() {
    if (lbl_805D55C0 == 0) {
        if (state_1c != state_24) {
            if (state_20 != -1) {
                state_20 = -1;
                update_player_battle_ctrl_state(this);
            }
            state_1c = state_24;
            state_20 = 0;
        }
        update_player_battle_ctrl_state(this);
    }
}

void update_player_battle_ctrl_state(void *player_battle_ctrl) {
    switch (((TPlayerBattleCtrl *)player_battle_ctrl)->state_1c) {
    case 0:
        fn_801C4CE0((TPlayerBattleCtrl *)player_battle_ctrl);
        return;
    case 1:
        ((TLobby *)player_battle_ctrl)->update_battle_intro();
        return;
    case 2:
        ((TLobby *)player_battle_ctrl)->update_timed_wait();
        return;
    case 3:
        TLobby::update_duel_result((u8 *)player_battle_ctrl);
        return;
    case 4:
        ((TLobby *)player_battle_ctrl)->end_battle_mode_cleanup();
        return;
    case 5:
        TLobby__sub_801C3AF4((UpdatePlayerBattleCtrlStateLobby *)player_battle_ctrl);
        return;
    case 6:
        update_battle_exit_sequence((TPlayerBattleCtrl *)player_battle_ctrl);
    default:
        return;
    }
}

void fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl) {
    switch (player_battle_ctrl->state_20) {
    case -1:
        break;
    case 0:
        (player_battle_ctrl)->init_battle_round();
        player_battle_ctrl->state_24 = 1;
        break;
    }
}

void TLobby::update_battle_intro() {
    switch (((UpdateBattleIntroLobby *)this)->state) {
    case 0:
        if (((UpdateBattleIntroLobby *)this)->window == NULL) {
            UpdateBattleIntroPair p = lbl_80446F94[0];
            ((UpdateBattleIntroLobby *)this)->window = TWindowMessage::create(get_window_layout_position(0x52), (const f32 *)(&p), 1);
        }
        lbl_805D5DA4 = 0;
        ((UpdateBattleIntroLobby *)this)->state = 1;
        break;
    case 1:
        ((TWindowMessage *)(((UpdateBattleIntroLobby *)this)->window))->append_line((saddr)((UpdateBattleIntroLobby *)this)->msg, 0x80);
        ((UpdateBattleIntroLobby *)this)->timer = 0xF0;
        ((UpdateBattleIntroLobby *)this)->state = 2;
        break;
    case 2:
        if (--((UpdateBattleIntroLobby *)this)->timer <= 0) {
            if (((TLobby *)((u8 *)&lobby_rule_settings))->get_rule_field_a() == 1) {
                ((UpdateBattleIntroLobby *)this)->state = 3;
            } else {
                ((UpdateBattleIntroLobby *)this)->state = 5;
            }
        }
        break;
    case 3: {
        UpdateBattleIntroCnt cnt = lbl_80446F9C[0];
        UpdateBattleIntroName names[4];
        s32 i;
        for (i = 0; i < 4; i++) {
            names[i].s[0] = 0;
        }
        for (i = 0; i < 4; i++) {
            TObjPlayer *pl = get_player_by_client_id(i);
            if (pl != NULL) {
                s32 team = battle_intro_value_table[i] != 1 ? 1 : 0;
                if (cnt.v[team] < 2) {
                    strncpy(names[team * 2 + cnt.v[team]].s, pl->get_name(), 0x10);
                    cnt.v[team]++;
                }
            }
        }
        sprintf(battle_intro_message_buffer, *(char **)(((UpdateBattleIntroLobby *)this)->cfg + 0x18), names[0].s, names[1].s, names[2].s, names[3].s);
        ((TWindowMessage *)(((UpdateBattleIntroLobby *)this)->window))->append_line((saddr)battle_intro_message_buffer, 0x80);
        ((UpdateBattleIntroLobby *)this)->timer = 0xF0;
        ((UpdateBattleIntroLobby *)this)->state = 4;
        break;
    }
    case 4:
        if (--((UpdateBattleIntroLobby *)this)->timer <= 0) {
            ((UpdateBattleIntroLobby *)this)->state = 5;
        }
        break;
    case 5:
        ((UpdateBattleIntroLobby *)this)->timer2 = 0x384;
        ((UpdateBattleIntroLobby *)this)->state = 6;
    case 6:
        ((UpdateBattleIntroLobby *)this)->timer2--;
        if (TLobby::check_all_battle_flags(((UpdateBattleIntroLobby *)this)) != 0 || ((UpdateBattleIntroLobby *)this)->timer2 <= 0) {
            ((TWindowBase *)((UpdateBattleIntroLobby *)this)->window)->close();
            ((UpdateBattleIntroLobby *)this)->window = NULL;
            TLobby__sub_801C2C34(((UpdateBattleIntroLobby *)this));
            ((UpdateBattleIntroLobby *)this)->timer2 = 0x1C2;
            ((UpdateBattleIntroLobby *)this)->state = 7;
        }
        break;
    case 7:
        ((UpdateBattleIntroLobby *)this)->timer2--;
        if (TLobby::check_all_players_ready(((UpdateBattleIntroLobby *)this)) != 0 || ((UpdateBattleIntroLobby *)this)->timer2 <= 0) {
            new TDuelEffectCtrl(this, 0);
            ((UpdateBattleIntroLobby *)this)->timer = 0x96;
            ((UpdateBattleIntroLobby *)this)->state = 8;
        }
        break;
    case 8:
        if (--((UpdateBattleIntroLobby *)this)->timer <= 0) {
            ((UpdateBattleIntroLobby *)this)->next = 2;
        }
        break;
    case -1:
        if (((UpdateBattleIntroLobby *)this)->window != NULL) {
            ((TWindowBase *)((UpdateBattleIntroLobby *)this)->window)->close();
            ((UpdateBattleIntroLobby *)this)->window = NULL;
        }
        clear_battle_player_ready_flags();
        break;
    }
}

void TLobby::update_timed_wait() {
    s32 secs;
    s32 rem;
    switch (((UpdateTimedWaitLobby *)this)->state) {
    case 0:
        ((TLobby *)((UpdateTimedWaitLobby *)this))->start_duel_battle();
        ((UpdateTimedWaitLobby *)this)->state = 1;
    case 1:
        if (TLobby::check_team_balance((UpdateTimedWaitLobby *)(((UpdateTimedWaitLobby *)this)), 1) != 0) {
            TLobby::send_battle_mode_params(5, 0, 0);
            return;
        }
        secs = (OSGetTime() - ((UpdateTimedWaitLobby *)this)->start) / (*(u32 *)0x800000F8 / 4);
        rem = ((UpdateTimedWaitLobby *)this)->limit - secs;
        ((UpdateTimedWaitLobby *)this)->remain = rem > 0 ? rem : 0;
        TWindowCtrl::set_timer_window_time(((UpdateTimedWaitLobby *)this)->remain);
        if (((UpdateTimedWaitLobby *)this)->remain == 0) {
            ((UpdateTimedWaitLobby *)this)->result = 3;
            TLobby::send_battle_mode_params(3, 0, 0);
            return;
        }
        if (TLobby::check_battle_end(((UpdateTimedWaitLobby *)this)) != 0) {
            if (--((UpdateTimedWaitLobby *)this)->timer48 <= 0) {
                ((UpdateTimedWaitLobby *)this)->result = 3;
                TLobby::send_battle_mode_params(3, 0, 0);
            }
        } else {
            ((UpdateTimedWaitLobby *)this)->timer48 = 300;
        }
        ((TLobby *)((UpdateTimedWaitLobby *)this))->update_battle_sync(secs);
        if (--((UpdateTimedWaitLobby *)this)->timer60 <= 0) {
            send_battle_mode_state();
            ((UpdateTimedWaitLobby *)this)->timer60 = 90;
        }
        TLobby::calc_player_rankings((UpdateTimedWaitLobby *)(((UpdateTimedWaitLobby *)this)));
        break;
    case -1:
        break;
    }
}

void update_duel_result__6TLobbyFPv(TPlayerBattleCtrl *ctrl) {
    void *p;
    void *q;
    switch (ctrl->state_20) {
    case 0:
        TLobby::init(ctrl);
        lbl_805D5DA8 = 0;
        lbl_805D5DAC = 0;
        new TDuelEffectCtrl((TObject *)ctrl, 1);
        ctrl->timer = 0x78;
        TWindowCtrl::close_timer_window();
        TWindowCtrl::suppress_slot(local_client_id);
        ctrl->state_20 = 1;
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        break;
    case 1:
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (--ctrl->timer <= 0) {
            ((TLobby *)ctrl)->send_battle_mode_state();
            ctrl->timer = 0x5A;
            ctrl->state_20 = 2;
        }
        break;
    case 2:
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (--ctrl->timer <= 0) {
            ctrl->timeout = 0x1C2;
            ctrl->state_20 = 3;
        }
        break;
    case 3:
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (((TLobby *)ctrl)->check_timeout((ctrl->timeout)--) != 0 || ctrl->timeout <= 0) {
            TLobby::clear_counter(ctrl);
            TLobby::calc_player_rankings((UpdateTimedWaitLobby *)ctrl);
            record_local_battle_placement(ctrl);
            if (duel_result_table[0].client_id == local_client_id) {
                play_duel_result_stream("win.adx", 0x96);
            } else {
                play_duel_result_stream("lose.adx", 0x96);
            }
            ctrl->state_20 = 4;
        }
        break;
    case 4:
        if (ctrl->window_54 != NULL) {
            ((TWindowBase *)(ctrl->window_54))->close();
        }
        ctrl->window_54 = new TWindowDuelResult(local_client_id);
        q = (void *)(saddr)get_local_player();
        if (q != NULL) {
            if (((TObjPlayer *)q)->check_player_flag1() == 0) {
                TLobby::close_and_play_effect((u16)local_client_id, 1);
            }
            ((TObjPlayer *)q)->release_attached_resource();
        }
        ctrl->state_20 = 5;
        break;
    case 5:
        if (controller_input_state.controllers[0].pressed_buttons & 2) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
            ((TWindowBase *)(ctrl->window_54))->close();
            ctrl->window_54 = NULL;
            ctrl->state_20 = 6;
            p = (void *)(saddr)get_local_player();
            if (p != NULL && (static_cast<TObjPlayer *>(p)->actorFlags & 0x800)) {
                static_cast<TObjPlayer *>(p)->reset_pose();
            }
        }
        break;
    case 6:
        if (TLobby::check_team_balance((UpdateTimedWaitLobby *)((UpdateTimedWaitLobby *)ctrl), 0) != 0) {
            TLobby::send_battle_mode_params(5, 1, 0);
        } else {
            q = (void *)(saddr)get_local_player();
            if (local_client_id == designated_client_id && TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
                if (ctrl->window_4c == NULL) {
                    ctrl->window_4c = TWindowMessage::create(get_window_layout_position(0x53), (const f32 *)lbl_80446FA4, 1);
                    if (ctrl->window_4c != NULL) {
                        ((TWindowMessage *)(ctrl->window_4c))->append_line(((s32 *)ctrl->text)[0], 0x80);
                    }
                }
                if (ctrl->window_50 == NULL) {
                    ctrl->window_50 = create_window_menu_default(get_window_layout_position(0x54), 3);
                    ((TWindowMenu *)(ctrl->window_50))->add_text_entry(((s32 *)ctrl->text)[1], 6, 1);
                    ((TWindowMenu *)(ctrl->window_50))->add_text_entry(((s32 *)ctrl->text)[2], 6, 2);
                    ((TWindowMenu *)(ctrl->window_50))->add_text_entry(((s32 *)ctrl->text)[3], 6, 3);
                    ((TWindowMenu *)(ctrl->window_50))->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(ctrl->window_50));
                    ((TWindowMenu *)(ctrl->window_50))->set_ready_flag();
                }
                if (ctrl->window_50 != NULL) {
                    if (((TWindowMenu *)(ctrl->window_50))->is_decided() != 0) {
                        switch (((TWindowMenu *)(ctrl->window_50))->get_selected_value()) {
                        case 1:
                            send_6x7D_set_battle_mode_data(ctrl);
                            ctrl->state_20 = 9;
                            break;
                        case 2:
                            ctrl->state_20 = 7;
                            break;
                        case 3:
                            TLobby::send_battle_mode_params(4, 0, 0);
                            ctrl->state_20 = 9;
                            break;
                        }
                    } else if (((TWindowMenu *)(ctrl->window_50))->is_cancelled() != 0) {
                        ctrl->state_20 = 7;
                    }
                }
                if (q != NULL && ((TObjPlayer *)q)->check_player_flag1() == 0) {
                    TLobby::close_and_play_effect((u16)local_client_id, 1);
                }
            } else if (q != NULL && ((TObjPlayer *)q)->check_player_flag1() != 0) {
                TLobby::handle_battle_result((u16)local_client_id, 1);
            }
        }
        break;
    case 7:
        if (ctrl->window_4c != NULL) {
            ((TWindowBase *)(ctrl->window_4c))->close();
            ctrl->window_4c = NULL;
        }
        if (ctrl->window_50 != NULL) {
            ((TWindowBase *)(ctrl->window_50))->close();
            ctrl->window_50 = NULL;
        }
        p = (void *)(saddr)get_local_player();
        if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() != 0) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
        }
        ctrl->state_20 = 8;
    case 8:
        if (TLobby::check_team_balance((UpdateTimedWaitLobby *)((UpdateTimedWaitLobby *)ctrl), 0) != 0) {
            TLobby::send_battle_mode_params(5, 1, 0);
        } else {
            p = (void *)get_player_by_client_id(local_client_id);
            if (p != NULL && ((TObjPlayer *)p)->is_controls_locked() == 0 && (controller_input_state.controllers[0].pressed_buttons & 6)) {
                ctrl->state_20 = 6;
            }
        }
        break;
    case -1:
        if (ctrl->window_4c != NULL) {
            ((TWindowBase *)(ctrl->window_4c))->close();
            ctrl->window_4c = NULL;
        }
        if (ctrl->window_50 != NULL) {
            ((TWindowBase *)(ctrl->window_50))->close();
            ctrl->window_50 = NULL;
        }
        if (ctrl->window_54 != NULL) {
            ((TWindowBase *)(ctrl->window_54))->close();
            ctrl->window_54 = NULL;
        }
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            obj_clear_flag30_20000(p);
        }
        TWindowCtrl::close_timer_window();
        TWindowCtrl::suppress_slot(local_client_id);
        break;
    case 9:
        break;
    }
    if (ctrl->state_20 == 6 || ctrl->state_20 == 8) {
        p = (void *)(saddr)get_local_player();
        if (p != NULL && ((TObjPlayer *)p)->is_controls_locked() == 0 && TWindowCtrl::has_player_active_menu(local_client_id) == 0 && (controller_input_state.controllers[0].pressed_buttons & 0x400)) {
            if (ctrl->window_4c != NULL) {
                ((TWindowBase *)(ctrl->window_4c))->close();
                ctrl->window_4c = NULL;
            }
            if (ctrl->window_50 != NULL) {
                ((TWindowBase *)(ctrl->window_50))->close();
                ctrl->window_50 = NULL;
            }
            ctrl->state_20 = 4;
        }
    }
}

void TLobby::end_battle_mode_cleanup() {
    switch (((TPlayerBattleCtrl *)this)->state_20) {
    case 0:
        if (lobby_idle_timeout_window != NULL) {
            delete lobby_idle_timeout_window;
            lobby_idle_timeout_window = NULL;
        }
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F950();
        lobby_floor_reload_pending = 1;
        ((TObject *)this)->queue_destruction();
        break;
    case -1:
        break;
    }
}

s32 get_battle_time_limit_frames(void) {
    return *(s32 *)((s8 *)(*(void * *)&battle_config_ptr) + 0x24) * 0x3C;
}

void TLobby::close_and_play_effect(int client, s32 local) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        send_impose_hold(player, -1);
    }
    if (local != 0) {
        TWindowCtrl::begin_client_keyboard_hold(local_client_id);
        request_active_window_close();
        TWindowCtrl::suppress_slot(local_client_id);
    }
}

void TLobby::handle_battle_result(int client, s32 local) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id((u16)client)) != NULL) {
        send_release_hold(player);
    }
    if (local != 0) {
        TWindowCtrl::end_client_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
    }
}

void TLobby::apply_game_settings(s32 owner, s32 use_config) {
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    if (use_config != 0) {
        s32 flag;
        TLobby::set_validated_field_0x1(lobby_rule_settings, CFG->b[0]);
        TLobby::set_field_2(lobby_rule_settings, CFG->b[1]);
        TLobby::set_field_3(lobby_rule_settings, CFG->b[2]);
        TLobby::set_clamped_field_4(lobby_rule_settings, CFG->b[3]);
        TLobby::set_field_5(lobby_rule_settings, CFG->b[4]);
        TLobby::set_field_0x6(lobby_rule_settings, CFG->b[5]);
        TLobby::set_field7_clamped(lobby_rule_settings, CFG->b[6]);
        TLobby::set_difficulty(lobby_rule_settings, CFG->b[7]);
        TLobby::set_byte9_clamped(lobby_rule_settings, CFG->b[8]);
        TLobby::set_field_b(lobby_rule_settings, CFG->b[0xA]);
        TLobby::set_clamped_field_c(lobby_rule_settings, CFG->b[0xB]);
        fn_801D72B0(lobby_rule_settings, CFG->c);
        for (s32 i = 0; i < 4; i++) {
            fn_801D6D8C(lobby_rule_settings, CFG->b[i + 0xD], i);
        }
        TLobby::set_field_d(lobby_rule_settings, CFG->d11);
        ((TObjPlayer *)lobby_rule_settings)->set_level(CFG->lvl);
        TLobby::set_field_0xE(lobby_rule_settings, CFG->d13);
        ((TLobby *)lobby_rule_settings)->set_volume((u8) CFG->vol);
        ((TLobby *)lobby_rule_settings)->set_max_tech_level((u8) CFG->v1c);
        ((TLobby *)lobby_rule_settings)->set_clamped_index((s16) CFG->v20);
        ((TLobby *)lobby_rule_settings)->set_clamped_value_1c(CFG->v24);
        fn_801D726C(lobby_rule_settings, (u8) CFG->v28);
        flag = 0;
        if ((s32) CFG->b[9] == 1 && TLobby::get_game_mode() == 4) {
            s32 toggle = 1;
            for (s32 i = 0; i < 4; i++) {
                uaddr p = (uaddr)get_player_by_client_id(i);
                if (p != 0U) {
                    toggle = 1 - toggle;
                    s32 v = 2;
                    if (toggle != 0) {
                        v = 1;
                    }
                    battle_intro_value_table[i] = v;
                    ((PlayerPkState *)(p + 0x828))->set_team(battle_intro_value_table[i]);
                } else {
                    battle_intro_value_table[i] = -1;
                }
            }
            flag = 1;
        }
        TLobby::set_field_a(lobby_rule_settings, (u8) (flag != 0));
        for (s32 i = 0; i < 4; i++) {
            uaddr p = player_slot_table[i];
            if (p != 0U) {
                ((DamageStatSlot *)(p + 0x78C))->set_bonus_weight(battle_player_give_damage_score);
                ((DamageStatSlot *)(p + 0x78C))->set_normal_weight(battle_enemy_give_damage_score);
                ((DamageStatSlot *)(p + 0x77C))->set_bonus_weight(battle_player_take_damage_score);
                ((DamageStatSlot *)(p + 0x77C))->set_normal_weight(battle_enemy_take_damage_score);
                ((DamageStatSlot *)(p + 0x75C))->set_bonus_weight(battle_player_kill_score);
                ((DamageStatSlot *)(p + 0x75C))->set_normal_weight(battle_enemy_kill_score);
                ((DamageStatSlot *)(p + 0x76C))->set_bonus_weight(battle_player_death_score);
                ((DamageStatSlot *)(p + 0x76C))->set_normal_weight(battle_enemy_death_score);
                ((DamageStatSlot *)(p + 0x79C))->set_bonus_weight(battle_meseta_score);
                ((DamageStatSlot *)(p + 0x79C))->set_normal_weight(battle_meseta_score);
            }
        }
        TLobby::set_section_id(lobby_rule_settings, 1);
    }
    if (((u32 (*)(void))get_local_player)() != 0U) {
        TLobby::apply_battle_rules_to_players();
    }
}

void TLobby::send_battle_mode_params(s8 command, s32 value, s32 extra) {
    SendBattleModeParamsStack stack;
    build_6x7D_set_battle_mode_data(&stack.sp8);
    stack.spD = command;
    stack.spC = 0;
    stack.sp10 = value;
    stack.sp14 = extra;
    ((TLobby *)(&stack.sp8))->send_set_battle_mode_data();
}

s32 check_team_balance__6TLobbyFPvi(UpdateTimedWaitLobby *self, s32 arg1) {
    s32 i;
    s32 t;
    uaddr pl;
    if (TLobby::get_game_mode() <= 1) {
        return 1;
    }
    if (arg1 != 0 && ((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
        CheckTeamBalanceCount cnt = lbl_80446FAC[0];
        i = 0;
        do {
            pl = (uaddr)get_player_by_client_id(i);
            if (pl != 0) {
                t = ((PlayerPkState *)(pl + 0x828))->get_team() - 1;
                if (t >= 0 && t < 2) {
                    cnt.v[t] = 1;
                }
            }
            i++;
        } while (i < 4);
        if (cnt.v[0] == 0 || cnt.v[1] == 0) {
            return 1;
        }
    }
    return 0;
}

void TLobby__sub_801C3AF4(UpdatePlayerBattleCtrlStateLobby *self) {
    s32 idx;
    s32 s;
    switch (self->state) {
    case 0: {
        TLobby::close_and_play_effect((u16)local_client_id, 1);
        if (self->window != NULL) {
            ((TWindowBase *)self->window)->close();
            self->window = NULL;
        }
        if (self->f58 != 0) {
            idx = 5;
        } else {
            idx = 4;
            s = TAdSinglePlyChrSelectGC::get_char_select_slot() - 1;
            TAdSinglePlyChrSelectGC::set_slot((u16)(s > 0 ? s : 0));
        }
        TLobbyPair p = lbl_80446FB4[0];
        self->window = TWindowMessage::create(get_window_layout_position(0xB3), (const f32 *)(&p), 1);
        if (self->window != NULL) {
            ((TWindowMessage *)(self->window))->append_line(self->msgs[idx], 0x80);
        }
        self->state = 1;
        break;
    }
    case 1:
        if (controller_input_state.sources[0]->pressed & 8) {
            self->next = 4;
        }
        break;
    case -1:
        break;
    }
}

void TLobby::init_char_slots() {
    battle_mode_data_ptr = 0;
    lbl_805D5D9C = TKeyBoardControl__sub_8000F828() == 1 ? 0x19 : 0x1E;
    lobby_char_slot_array = __construct_new_array(mem_alloc(0x3220), (void *)construct__19PlayerCharDataEntryFv, (void *)__dt__19PlayerCharDataEntryFv, 0x42C, 0xC);
    TAdSinglePlyChrSelectGC__sub_801C5158();
    clear_battle_player_ready_flags();
    battle_ctrl_default_value = 1;
    TAdSinglePlyChrSelectGC__sub_801C5120();
}

void free_char_slots(void) {
    if (lobby_char_slot_array != 0) {
        __destroy_new_array(lobby_char_slot_array, (void *)__dt__19PlayerCharDataEntryFv);
        lobby_char_slot_array = 0;
    }
}

void TLobby::init_battle_ctrl(s32 config, saddr src) {
    uaddr player_battle_ctrl;
    if ((u32) (*(u32 *)&battle_mode_data_ptr) == 0U) {
        player_battle_ctrl = (uaddr)new TPlayerBattleCtrl(tl_00);
        (*(u32 *)&battle_mode_data_ptr) = player_battle_ctrl;
    }
    if ((u32) (*(u32 *)&battle_mode_data_ptr) != 0U) {
        strncpy((char *)((*(uaddr *)&battle_mode_data_ptr) + 0x68), (const char *)src, 0x200);
        battle_config_ptr = config;
    }
}

void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl) {
    TObjPlayer *player;
    switch (ctrl->state_20) {
    case 0:
        player = get_local_player();
        if (player != NULL) {
            send_impose_hold(player, -1);
        }
        ctrl->timer = 0xF;
        ctrl->state_20 = 1;
    case 1:
        if (--ctrl->timer <= 0) {
            TLobby__sub_8020BC50();
            reset_map();
            if (quest_mission_manager != NULL) {
                TQuestThread::clear_buffer(quest_mission_manager);
            }
            TLobby::stop_audio_streams();
            lbl_805D5DB4 = 0;
            TLobby::init_fadeout_state(TLobby::init_and_set_flag);
            ctrl->state_20 = 2;
        }
        break;
    case 2:
        if (lbl_805D5DB4 != 0) {
            TLobby::finish_chr_select_scene_init();
            TLobby::set_fade_params(TLobby__sub_801C38A4);
            ctrl->state_20 = 3;
        }
        break;
    case 3:
    default:
        break;
    }
}

void TLobby::init_and_set_flag() { TLobby__sub_801B09A4(); advance_item_system_generation(); lbl_805D5DB4 = 1; }

void TLobby__sub_801C38A4(void) {
    if ((void *) battle_mode_data_ptr != NULL) {
        battle_mode_data_ptr->state_24 = 0;
    }
}

void handle_6x7D_set_battle_mode_data(Handle6x7DSetBattleModeDataPacket *pkt) {
    uaddr p;
    s32 i;
    ((TLobby *)pkt)->bswap_set_battle_mode_data();
    switch (pkt->type) {
    case 0:
        if (battle_mode_data_ptr != NULL) {
            ((Handle6x7DSetBattleModeDataLobby *)battle_mode_data_ptr)->mode = pkt->mode;
            ((Handle6x7DSetBattleModeDataLobby *)battle_mode_data_ptr)->a = pkt->v[0];
            ((Handle6x7DSetBattleModeDataLobby *)battle_mode_data_ptr)->b = pkt->v[1];
        }
        break;
    case 2:
        lbl_805D5DA4 = 1;
        break;
    case 3:
        p = (uaddr)get_player_by_client_id(pkt->v[0]);
        if (p != 0) {
            if (pkt->v[0] != local_client_id) {
                ((PlayerSubObjectSlots *)(p + 0x7AC))->set_score(pkt->v[1]);
            }
            battle_team_table[pkt->v[0]] = pkt->team;
        }
        lbl_805D5DB0++;
        break;
    case 4:
        battle_player_ready_flags[pkt->v[0]] = 1;
        break;
    case 5:
        if (battle_mode_data_ptr != NULL) {
            ((TLobby *)battle_mode_data_ptr)->set_flag_270();
        }
        break;
    case 6:
        if (battle_mode_data_ptr != NULL) {
            ((Handle6x7DSetBattleModeDataLobby *)battle_mode_data_ptr)->mode = 6;
            for (i = 0; i < 4; i++) {
                battle_mode_data_table[i] = pkt->v[i];
            }
        }
        break;
    }
}

void handle_6x7E(void) {  }

void handle_6x7F_battle_scores(saddr command) {
    bswap_client_id_header((G_ClientIDHeader *)command);
    memcpy(duel_result_table, (void *)(command + 4), 0x20);
    lbl_805D5DAC = 1;
}

void copy_battle_ranking(BattleRanking *dst, BattleRanking *src) {
    dst->client_id = src->client_id;
    dst->place = src->place;
    dst->score = src->score;
}

s32 calc_player_rankings__6TLobbyFPv(UpdateTimedWaitLobby *) {
    s32 n;
    s32 i;
    s32 j;
    uaddr p;
    s32 rank;
    s32 m;
    s32 k;
    for (k = 0; k < 4; k++) {
        duel_result_table[k].client_id = 0xFFFF;
        duel_result_table[k].place = 0;
        duel_result_table[k].score = 0;
    }
    n = 0;
    if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
        CalcPlayerRankingsTeam team = lbl_80446FBC[0];
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                s32 t = ((PlayerPkState *)(p + 0x828))->get_team() != 1 ? 1 : 0;
                team.v[t] += ((PlayerSubObjectSlots *)(p + 0x7AC))->get_score();
            }
        }
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                duel_result_table[n].client_id = ((TObjBase *)p)->get_entity_id();
                duel_result_table[n].score = team.v[((PlayerPkState *)(p + 0x828))->get_team() != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                duel_result_table[n].client_id = ((TObjBase *)p)->get_entity_id();
                duel_result_table[n].score = ((PlayerSubObjectSlots *)(p + 0x7AC))->get_score();
                n++;
            }
        }
        if (n <= 1) {
            return 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        if (duel_result_table[i].client_id != 0xFFFF) {
            for (j = i + 1; j < n; j++) {
                if (duel_result_table[j].client_id != 0xFFFF && duel_result_table[i].score < duel_result_table[j].score) {
                    BattleRanking tmp = duel_result_table[i];
                    copy_battle_ranking(&duel_result_table[i], &duel_result_table[j]);
                    copy_battle_ranking(&duel_result_table[j], &tmp);
                }
            }
        }
    }
    rank = 0;
    for (m = 0; m < n; m++) {
        duel_result_table[m].place = rank;
        if (m < n - 1 && duel_result_table[m].score != duel_result_table[m + 1].score) {
            rank = m + 1;
        }
    }
    return 1;
}

void record_local_battle_placement(void *arg0) {
    s32 slot;
    s32 i;
    s32 n;
    s32 s;
    s32 r;
    uaddr pl;

    slot = -1;
    for (i = 0; i < 4; i++) {
        pl = (uaddr)get_player_by_client_id(duel_result_table[i].client_id);
        if (pl != 0 && local_client_id == (u16)((TObjBase *)pl)->get_entity_id()) {
            slot = duel_result_table[i].place;
            break;
        }
    }
    if (is_duel_ranking_empty() == 0) {
        switch (slot) {
        case 0:
            {
                u16 c = TAdSinglePlyChrSelectGC__sub_801C5114();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                TAdSinglePlyChrSelectGC__sub_801C5108(m);
            }
            break;
        case 1:
            {
                u16 c = TAdSinglePlyChrSelectGC__sub_801C50FC();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                TAdSinglePlyChrSelectGC__sub_801C50F0(m);
            }
            break;
        case 2:
            {
                u16 c = TAdSinglePlyChrSelectGC__sub_801C50E4();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                TAdSinglePlyChrSelectGC__sub_801C50D8(m);
            }
            break;
        case 3:
            {
                u16 c = TAdSinglePlyChrSelectGC__sub_801C50CC();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                TAdSinglePlyChrSelectGC__sub_801C50C0(m);
            }
            break;
        }
    }
    s = TAdSinglePlyChrSelectGC::get_char_select_slot() - 1;
    TAdSinglePlyChrSelectGC::set_slot((u16)(s > 0 ? s : 0));
    TAdSinglePlyChrSelectGC__sub_801FCE6C();
}

void play_duel_result_stream(const char *file, saddr duration) {
    play_cue_stream_file(file);
    show_duel_result_window(-50, duration);
}

s32 TLobby::assign_player_id(void *) {
    s32 score;
    saddr player;

    player = (saddr)get_local_player();
    if (player == 0) {
        return 0;
    }
    score = ((TObjPlayer *)player)->calc_battle_score();
    ((PlayerSubObjectSlots *)(player + 0x7AC))->set_score(score);
    return score;
}

TDelayedAreaMusic::TDelayedAreaMusic(TObject *parent, const char *name, s32 delay) : TObject(parent) {
    delay_frames = delay;
    strncpy(music_name, name, 32);
}

TDelayedAreaMusic::~TDelayedAreaMusic() {}

void TDelayedAreaMusic::run_task() {
    if (--delay_frames <= 0) {
        play_area_music(music_name);
        queue_destruction();
    }
}

void TPlayerBattleCtrl::init_battle_round() {
  s32 char_select_slot;
  saddr temp_r3;
  s32 var_ctr;
  s32 var_r3;
  s32 i;
  this->m_3c = get_battle_time_limit_frames();
  TWindowCtrl::create_alt_timer();
  TWindowCtrl::set_timer_window_time(this->m_3c);
  TOMineTrap::destroy_matching_traps();
  char_select_slot = TAdSinglePlyChrSelectGC::get_char_select_slot();
  char_select_slot = char_select_slot + 1;
  var_r3 = 0xFFFF;
  if (char_select_slot < var_r3)
  {
    var_r3 = char_select_slot;
  }
  TAdSinglePlyChrSelectGC::set_slot((u16) var_r3);
  TAdSinglePlyChrSelectGC__sub_801FCE6C();
  TLobby::apply_game_settings((saddr)this, 1);
  TLobby::close_and_play_effect((u16) local_client_id, 1);
  temp_r3 = (saddr)get_local_player();
  if (temp_r3 != 0)
  {
    obj_set_flag_20000();
    ((DamageStatSlot *)(temp_r3 + 0x78C))->reset();
    ((DamageStatSlot *)(temp_r3 + 0x77C))->reset();
    ((DamageStatSlot *)(temp_r3 + 0x75C))->reset();
    ((DamageStatSlot *)(temp_r3 + 0x76C))->reset();
    ((DamageStatSlot *)(temp_r3 + 0x79C))->reset();
    ((PlayerSubObjectSlots *)(temp_r3 + 0x7AC))->set_score(0);
  }
  *((s32 *) (((s8 *) this) + 0x60)) = 0x5A;
  TLobby::calc_player_rankings((UpdateTimedWaitLobby *)this);
  for (i = 0; i < 4; i++)
  {
    battle_team_table[i] = 1;
  }
}

void TLobby::start_duel_battle() {
    const char *name;
    uaddr p;
    s32 area;
    s32 i;
    TObjEneRe4Sorcerer__sub_801E3F14(4);
    TObjEneRe4Sorcerer__sub_801E3F18();
    ((StartDuelBattleLobby *)this)->time = OSGetTime();
    TLobby::handle_battle_result((u16)local_client_id, 1);
    if ((p = (saddr)get_local_player()) != 0) {
        obj_clear_flag30_20000((void *)p);
    }
    TLobby::clear_counter(this);
    area = get_current_floor_area();
    name = (area == AREA_BATTLE1) ? "duel1.adx" : "duel2.adx";
    new TDelayedAreaMusic(this, name, 0x2D);
    for (i = 0; i < 8; i++) {
        ((StartDuelBattleLobby *)this)->pending[i] = 1;
        if (battle_event_second_table[i] == 0) {
            ((StartDuelBattleLobby *)this)->pending[i] = 0;
        }
    }
    ((StartDuelBattleLobby *)this)->f64 = battle_ctrl_default_value;
}

void TLobby::init(void *arg0) {
    saddr temp_r3;
    s32 i;
    TObjPlayer *player;

    ((TLobby *)arg0)->set_flag_270();
    TLobby::close_and_play_effect((u16) local_client_id, 1);
    temp_r3 = (saddr)get_local_player();
    if (temp_r3 != 0) {
        obj_set_flag_20000();
        ((ProtectionTimer *)(temp_r3 + 0x644))->set_frames(0xE10);
    }
    TOMineTrap::destroy_matching_traps();
    queue_destroy_event_descendants(tl_01);
    TQuestThread::destroy_all_in(tl_00);
    TLobby__sub_8020BCE4();
    TAdSinglePlyChrSelectGC::destroy();
    TLobby__sub_8020BB18();
    i = 0;
    ((TPlayerBattleCtrl *)arg0)->pad_64 = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            player->trap_counts.clear();
        }
        i += 1;
    } while (i < 4);
}

void send_6x7D_set_battle_mode_data(void *) {
    Send6x7DSetBattleModeDataMsg msg;
    s32 i;
    s32 a;
    s32 b;
    s32 t;
    build_6x7D_set_battle_mode_data(&msg);
    msg.sub = 6;
    for (i = 0; i < 4; i++) {
        msg.order[i] = i;
    }
    for (i = 0; i < 0x1E; i++) {
        a = (s32) (4.0f * (3.0517578125e-05f * (f32) rand()));
        b = (s32) (4.0f * (3.0517578125e-05f * (f32) rand()));
        if (a != b) {
            t = msg.order[a];
            msg.order[a] = msg.order[b];
            msg.order[b] = t;
        }
    }
    ((TLobby *)(&msg))->send_6x7D_set_battle_mode_data();
    ((game_command *)&msg)->send();
}

void TLobby::finish_chr_select_scene_init() {
    TLobby::init_scene_objects();
    TObjPlayer *player = get_local_player();
    if (player != NULL) {
        player->send_selected_spawn_position(battle_mode_data_table[(u16)player->get_entity_id()]);
        reset_cameras_to_actor(player, 0);
    }
    ((TLobby *)tl_05)->destroy_matching_children();
    TAdSinglePlyChrSelectGC::destroy();
}

void TLobby::destroy_matching_children() {
    TObject *down;
    down = this->m_down;
    while (down != NULL) {
        if (down->check_value_equals(dead_spot_class_name) != 0) {
            down->queue_destruction();
        }
        ((TLobby *)down)->destroy_matching_children();
        down = down->m_next;
    }
}

void clear_battle_player_ready_flags(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        battle_player_ready_flags[i] = 0;
    }
}

void TLobby__sub_801C2C34(void *) {
    TLobbyStack stack;
    build_6x7D_set_battle_mode_data((&stack.sp8));
    stack.spC = 4;
    stack.sp10 = local_client_id;
    ((TLobby *)(&stack.sp8))->send_set_battle_mode_data();
}

s32 TLobby::check_all_players_ready(void *) {
    u8 *var_r31;
    s32 var_r30;
    s32 var_r29;

    var_r31 = battle_player_ready_flags;
    var_r30 = 1;
    var_r29 = 0;
loop_1:
    if ((get_player_by_client_id(var_r29) != NULL) && ((s8) *var_r31 == 0)) {
        var_r30 = 0;
    } else {
        var_r29 += 1;
        var_r31 += 1;
        if (var_r29 < 4) {
            goto loop_1;
        }
    }
    return var_r30;
}

void TLobby::show_score_results() {
    char buf[0x48];
    BattleRanking *e;
    s32 i;
    TObjPlayer *p;
    TLobby::clear_counter(this);
    TLobby::calc_player_rankings((UpdateTimedWaitLobby *)this);
    TWindowCtrl::append_message_all("SCORE");
    for (i = 0; i < 4; i++) {
        e = &duel_result_table[i];
        p = get_player_by_client_id(e->client_id);
        if (p != NULL) {
            sprintf(buf, "%s %s", lobby_rank_ordinal_text_table[e->place], p->get_name());
            TWindowCtrl::append_message_all(buf);
        }
    }
    play_duel_result_stream("start.adx", 0x3C);
}

void TLobby::set_flag_270() {
    send_battle_mode_state();
    *(s32 *)((s8 *)this + 0x270) = 1;
}

void TLobby::send_battle_mode_state() {
    SendBattleModeStateMsg m;
    SendBattleModeStatePlayer *p;
    s32 id;
    s32 on;
    p = (SendBattleModeStatePlayer *)(saddr)get_local_player();
    if (p != NULL) {
        id = TLobby::assign_player_id(this);
        build_6x7D_set_battle_mode_data(&m);
        m.kind = 3;
        m.id = ((TObjBase *)p)->get_entity_id();
        m.player = id;
        on = 1;
        if (p->flags & 0x800) {
            if (TLobby__sub_801D7100(lobby_rule_settings) == 1) {
                on = 0;
            } else if (TLobby__sub_801D7100(lobby_rule_settings) == 2 &&
                       ((PlayerBattleScore *)(p->ctrl))->get_timer() == 0) {
                on = 0;
            }
        }
        m.enabled = on;
        battle_team_table[local_client_id] = on;
        ((TLobby *)(&m))->send_set_battle_mode_data();
    }
}

s32 TLobby::check_timeout(s32 timer) {
    if (lbl_805D5DB0 >= TLobby::get_game_mode()) {
        *(s32 *)((s8 *)this + 0x270) = 2;
    }
    return *(s32 *)((s8 *)this + 0x270) == 2;
}

void TLobby::clear_counter(void* a0) { *(int*)((char*)a0 + 0x270) = 0; lbl_805D5DB0 = 0; }

void TLobby::send_battle_mode_data(void * _w0) {
    struct SendBattleModeDataS801C295C sp8;

    build_6x7D_set_battle_mode_data(&sp8);
    sp8.f4 = 5;
    ((TLobby *)(&sp8))->send_set_battle_mode_data();
}

void TLobby::update_battle_sync(s32 t) {
    s32 i;
    switch (((UpdateBattleSyncLobby *)this)->state) {
    case 0:
        if (local_client_id == designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (((UpdateBattleSyncLobby *)this)->pending[i] != 0 && t / 60 == battle_event_second_table[i]) {
                    ((UpdateBattleSyncLobby *)this)->pending[i] = 0;
                    TLobby::send_battle_mode_data(this);
                }
            }
        }
        break;
    case 1:
        check_timeout(t);
        break;
    case 2:
        show_score_results();
        break;
    }
}

s32 TLobby::check_battle_end(void *) {
    u8 *p;
    s32 cnt;
    s32 i;
    s32 ok;
    s32 idx;
    s32 seen[2] = {0, 0};
    cnt = 0;
    for (i = 0; i < 4; i++) {
        p = (u8 *)get_player_by_client_id(i);
        if (p != NULL) {
            ok = 1;
            if (battle_team_table[i] == 0) {
                ok = 0;
            } else if (*(s32 *)(p + 0x30) & 0x800) {
                if (TLobby__sub_801D7100(lobby_rule_settings) == 1) {
                    ok = 0;
                } else if (TLobby__sub_801D7100(lobby_rule_settings) == 2 &&
                           ((PlayerBattleScore *)(p + 0x754))->get_timer() == 0) {
                    ok = 0;
                }
            }
            if (ok != 0) {
                cnt++;
                if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
                    idx = ((TObjPlayer *)p)->pk_state.get_team() - 1;
                    if (idx >= 0 && idx < 2) {
                        seen[idx] = 1;
                    }
                }
            }
        }
    }
    if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1 && (seen[0] == 0 || seen[1] == 0)) {
        return 1;
    }
    return cnt <= 1;
}

s32 is_duel_ranking_empty(void) {
    BattleRanking *e;
    s32 result = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &duel_result_table[i];
        if (get_player_by_client_id(e->client_id) != NULL && e->place != 0) {
            result = 0;
            break;
        }
    }
    return result;
}

s32 TLobby__sub_801C2678(void) {
    if (is_duel_ranking_empty() != 0) {
        return 0;
    }
    return battle_ctrl_default_value;
}

u8 is_battle_mode_running(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return TPlayerBattleCtrl4P::is_battle_mode_active();
    }
    if (battle_mode_data_ptr != NULL) {
        return battle_mode_data_ptr->state_1c == 1 || battle_mode_data_ptr->state_1c == 2;
    }
    return 0;
}

s32 TLobby::check_all_battle_flags(void *) {
    uaddr player;
    s32 var_r31;

    var_r31 = 0;
loop_1:
    player = (uaddr)get_player_by_client_id(var_r31);
    if ((player != 0U) && (((TObjCollidable *)player)->test_actor_flags(0x02000000) != 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 1;
    }
    goto loop_1;
}
