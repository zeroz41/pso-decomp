#include "pso/camera/TCameraCtrl.h"
#include "pso/network/client_id.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include <stdio.h>
#include <stdlib.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804C8678.h"
#include "pso/map/TSetEvtDestroy.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TUnk_804C3E88.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
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
#include "pso/player/TObjPlayer_801BDF5C.h"

#include "types.h"
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
f32 lbl_805D5DC4;
f32 lbl_805D5DC8;

typedef struct Lobby_801C2898 {
    u8 pad0[0x268];
    s8 pending[8];
    s32 state;
} Lobby_801C2898;

struct Ent_801C26A8 { u16 id; s16 active; u8 pad[4]; };

void play_duel_result_stream(const char *file, saddr duration);
extern "C" {
u8 TLobby__sub_801C2614(void);
s32 TLobby__sub_801C2678(void);
extern s16 battle_event_second_table[];
s32 TLobby__sub_801C19D0(void *);
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
s32 TLobby__sub_801C26A8(void);
extern u8 player_battle_ctrl_text_japanese[];
extern u8 player_battle_ctrl_text_english[];
struct S801C295C_801C25B4 { s32 f0; s8 f4; s8 pad[0x13]; };

void build_6x7D_set_battle_mode_data(void *p);

// "TPlayerBattleCtrl" opens the unit's .rodata, ahead of the pairs below.
f32 lbl_805D3538 = 0.05f;
f32 lbl_805D353C = 0.02f;
f32 lbl_805D3540 = 10.0f;
f32 lbl_805D3544 = 7.0f;
f32 lbl_805D3548 = 0.01f;
f32 lbl_805D354C = 3.0f;
f32 lbl_805D3550 = 7.0f;
const char *TPlayerBattleCtrl__name = "TPlayerBattleCtrl";
extern "C" {
__declspec(section ".rodata") u32 lbl_80446F94[2] = { 0x43A40000, 0x43260000 };
__declspec(section ".rodata") u32 lbl_80446F9C[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FA4[2] = { 0x43580000, 0x42A80000 };
__declspec(section ".rodata") u32 lbl_80446FAC[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FB4[2] = { 0x436E0000, 0x433C0000 };
__declspec(section ".rodata") u32 lbl_80446FBC[2] = { 0, 0 };
}
#define lbl_80446F94 ((Pair_801C49B8 *)lbl_80446F94)
#define lbl_80446F9C ((Cnt_801C49B8 *)lbl_80446F9C)
#define lbl_80446FAC ((Cnt_801C3C1C *)lbl_80446FAC)
#define lbl_80446FB4 ((Pair_801C3AF4 *)lbl_80446FB4)
#define lbl_80446FBC ((Team_801C343C *)lbl_80446FBC)

}

typedef struct Msg_801C29F0 {
    u8 pad0[4];
    u8 kind;
    u8 pad5[2];
    u8 enabled;
    u32 id;
    s32 player;
    u8 pad10[0x10];
} Msg_801C29F0;

typedef struct Player_801C29F0 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x754 - 0x34];
    u8 ctrl[4];
} Player_801C29F0;

typedef struct Entry_801C2B04 {
    u16 id;
    s16 name;
    u8 pad4[4];
} Entry_801C2B04;

extern "C" {

void build_6x7D_set_battle_mode_data(void *);

struct Lobby_801C484C;
s32 calc_player_rankings__6TLobbyFPv(Lobby_801C484C *);

}

struct Stack_801C2C34 {
    s32 sp8;
    s8 spC;
    u8 pad_D[0x3];
    s32 sp10;
};

typedef struct Lobby_801C2F40 {
    u8 pad0[0x30];
    u64 time;
    u8 pad38[0x64 - 0x38];
    s32 f64;
    u8 pad68[0x268 - 0x68];
    s8 pending[8];
} Lobby_801C2F40;

typedef struct Msg_801C2D54 {
    s32 hdr;
    s8 sub;
    u8 pad5[3];
    s32 order[4];
} Msg_801C2D54;

extern "C" {
void TLobby__sub_801C2C34(void *);
void clear_battle_player_ready_flags(void);
s64 OSGetTime(void);
void obj_clear_flag30_20000(void *);
void TObjEneRe4Sorcerer__sub_801E3F14(s32);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
extern const char *TDeadSpot__class_name;

extern u16 battle_mode_data_table[];
extern saddr tl_05;
void send_6x7D_set_battle_mode_data(void *);
s32 obj_set_flag_20000();
s32 TLobby__sub_801C417C();
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void init__6TLobbyFPv(void *arg0);
void TLobby__sub_8020BB18(void);
void TLobby__sub_8020BCE4(void);
void clear_trap_counts(s8 *arg0);

extern saddr tl_00;
extern saddr tl_01;
}
struct Stack_801C3CFC {
    s32 sp8;
    s8 spC;
    s8 spD;
    u8 pad_E[0x2];
    s32 sp10;
    s32 sp14;
};

typedef struct Pair_801C3AF4 { u32 a; u32 b; } Pair_801C3AF4;


typedef struct Lobby_801C3AF4 {
    u8 pad0[0x20];
    s32 state;
    s32 next;
    u8 pad28[0x40 - 0x28];
    s32 *msgs;
    u8 pad44[0x4C - 0x44];
    void *window;
    u8 pad50[0x58 - 0x50];
    s32 f58;
} Lobby_801C3AF4;

struct Pkt_801C374C {
    u8 pad0[4];
    s8 type;
    s8 mode;
    u8 pad6;
    s8 team;
    s32 v[4];
};

struct Lobby_801C374C {
    u8 pad0[0x24];
    s32 mode;
    u8 pad28[0x30];
    s32 a;
    s32 b;
};

struct Lobby_801C484C {
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

struct Pair_801C49B8 { s32 a, b; };

struct Name_801C49B8 { char s[16]; };

struct Lobby_801C49B8 {
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

struct Cnt_801C49B8 { s32 v[2]; };

struct Rank_801C343C { u16 id; s16 rank; s32 score; };

struct Team_801C343C { s32 v[2]; };

typedef struct Cnt_801C3C1C { s32 v[2]; } Cnt_801C3C1C;

extern "C" {
void handle_6x7E(void);
void TLobby__sub_801C38A4(void);
void TLobby__sub_801B09A4(void);


void end_player_keyboard_hold(saddr client_id);

void begin_player_keyboard_hold(saddr client_id);
void request_active_window_close(void);
s32 TLobby__sub_801C417C(void);
void __destroy_new_array(void *, void *);
void TLobby__sub_801C3A40(void);
int TKeyBoardControl__sub_8000F828(void);
void TAdSinglePlyChrSelectGC__sub_801C5120(void);
void TAdSinglePlyChrSelectGC__sub_801C5158(void);
void *__construct_new_array(void *, void *, void *, s32, s32);
s32 destroy_char_data__10TObjPlayerFis(saddr arg0, s16 arg1);
void init_char_data__10TObjPlayerFv(void);

void *get_window_layout_position(s32);
void TLobby__sub_801C3AF4(Lobby_801C3AF4 *self);


void handle_6x7D_set_battle_mode_data(Pkt_801C374C *pkt);
s64 OSGetTime();

s32 set_player_team_id(void *, int);
s32 fn_801D6D8C(void *, int, int);
s32 fn_801D726C(void *, int);
s32 fn_801D72B0(void *, int);
extern u32 player_slot_table[];

extern s32 battle_intro_value_table[];
void obj_clear_flag30_20000(void *actor);
s32 __ct__15TDuelEffectCtrlFP7TObjectUc(void *, void *, int);

void record_local_battle_placement(void *);

void *create_window_menu_default(void *, int);

void update_duel_result__6TLobbyFPv(u8 *arg0);


extern char battle_intro_message_buffer[];

void TLobby__sub_801C36E4(void *arg0, void *arg1);
s32 TLobby__sub_801C4FC4(void *p);

void TLobby__sub_801036CC(void);
void TLobby__sub_8020BC50(void);
void TLobby__sub_801C38E8(void *arg0);


s32 check_team_balance__6TLobbyFPvi(Lobby_801C484C *self, s32 arg1);
void TKeyBoardControl__sub_8000F950(void);
extern s16 TLobby__data_805D5CE8;
extern s32 evt2_random_enemies_mode;
typedef struct Ent_801C32B4 { u16 id; s16 slot; u32 pad; } Ent_801C32B4;
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
s32 TObjPlayer__sub_801AFFD0();

#define TBL_801C32B4 ((Ent_801C32B4 *)duel_result_table)
void record_local_battle_placement(void *arg0);

#define TBL_801C343C ((Rank_801C343C *)duel_result_table)

#define CFG (*(Cfg_801C3D50 **)&battle_config_ptr)


void update_player_battle_ctrl_state(void *player_battle_ctrl);

void fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl);

}

extern s32 lbl_805D55C0;

Ent_801C26A8 duel_result_table[4];
s32 battle_team_table[4];
s16 battle_event_second_table[8];
u16 battle_mode_data_table[4];
s32 battle_intro_value_table[4];
char battle_intro_message_buffer[0x100];

TPlayerBattleCtrl::TPlayerBattleCtrl(TObject *parent) : TObject(parent) {
    TObjPlayer *player;
    m_name = TPlayerBattleCtrl__name;
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
        TLobby__sub_801C3AF4((Lobby_801C3AF4 *)player_battle_ctrl);
        return;
    case 6:
        TLobby__sub_801C38E8((player_battle_ctrl));
    default:
        return;
    }
}

void fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl) {
    switch (player_battle_ctrl->state_20) {
    case -1:
        break;
    case 0:
        ((TPlayerBattleCtrl *)player_battle_ctrl)->init_battle_round();
        player_battle_ctrl->state_24 = 1;
        break;
    }
}

void TLobby::update_battle_intro() {
    switch (((Lobby_801C49B8 *)this)->state) {
    case 0:
        if (((Lobby_801C49B8 *)this)->window == NULL) {
            Pair_801C49B8 p = lbl_80446F94[0];
            ((Lobby_801C49B8 *)this)->window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x52)), (const f32 *)(&p), 1);
        }
        lbl_805D5DA4 = 0;
        ((Lobby_801C49B8 *)this)->state = 1;
        break;
    case 1:
        ((TWindowMessage *)(((Lobby_801C49B8 *)this)->window))->append_line((saddr)((Lobby_801C49B8 *)this)->msg, 0x80);
        ((Lobby_801C49B8 *)this)->timer = 0xF0;
        ((Lobby_801C49B8 *)this)->state = 2;
        break;
    case 2:
        if (--((Lobby_801C49B8 *)this)->timer <= 0) {
            if (((TLobby *)((u8 *)&lobby_rule_settings))->get_rule_field_a() == 1) {
                ((Lobby_801C49B8 *)this)->state = 3;
            } else {
                ((Lobby_801C49B8 *)this)->state = 5;
            }
        }
        break;
    case 3: {
        Cnt_801C49B8 cnt = lbl_80446F9C[0];
        Name_801C49B8 names[4];
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
        sprintf(battle_intro_message_buffer, *(char **)(((Lobby_801C49B8 *)this)->cfg + 0x18), names[0].s, names[1].s, names[2].s, names[3].s);
        ((TWindowMessage *)(((Lobby_801C49B8 *)this)->window))->append_line((saddr)battle_intro_message_buffer, 0x80);
        ((Lobby_801C49B8 *)this)->timer = 0xF0;
        ((Lobby_801C49B8 *)this)->state = 4;
        break;
    }
    case 4:
        if (--((Lobby_801C49B8 *)this)->timer <= 0) {
            ((Lobby_801C49B8 *)this)->state = 5;
        }
        break;
    case 5:
        ((Lobby_801C49B8 *)this)->timer2 = 0x384;
        ((Lobby_801C49B8 *)this)->state = 6;
    case 6:
        ((Lobby_801C49B8 *)this)->timer2--;
        if (TLobby::check_all_battle_flags(((Lobby_801C49B8 *)this)) != 0 || ((Lobby_801C49B8 *)this)->timer2 <= 0) {
            ((TWindowBase *)((Lobby_801C49B8 *)this)->window)->close();
            ((Lobby_801C49B8 *)this)->window = NULL;
            TLobby__sub_801C2C34(((Lobby_801C49B8 *)this));
            ((Lobby_801C49B8 *)this)->timer2 = 0x1C2;
            ((Lobby_801C49B8 *)this)->state = 7;
        }
        break;
    case 7:
        ((Lobby_801C49B8 *)this)->timer2--;
        if (TLobby::check_all_players_ready(((Lobby_801C49B8 *)this)) != 0 || ((Lobby_801C49B8 *)this)->timer2 <= 0) {
            void *o = (void *)TObject::operator new(0x28);
            if (o != NULL) {
                __ct__15TDuelEffectCtrlFP7TObjectUc(o, ((Lobby_801C49B8 *)this), 0);
            }
            ((Lobby_801C49B8 *)this)->timer = 0x96;
            ((Lobby_801C49B8 *)this)->state = 8;
        }
        break;
    case 8:
        if (--((Lobby_801C49B8 *)this)->timer <= 0) {
            ((Lobby_801C49B8 *)this)->next = 2;
        }
        break;
    case -1:
        if (((Lobby_801C49B8 *)this)->window != NULL) {
            ((TWindowBase *)((Lobby_801C49B8 *)this)->window)->close();
            ((Lobby_801C49B8 *)this)->window = NULL;
        }
        clear_battle_player_ready_flags();
        break;
    }
}

void TLobby::update_timed_wait() {
    s32 secs;
    s32 rem;
    switch (((Lobby_801C484C *)this)->state) {
    case 0:
        ((TLobby *)((Lobby_801C484C *)this))->start_duel_battle();
        ((Lobby_801C484C *)this)->state = 1;
    case 1:
        if (TLobby::check_team_balance((Lobby_801C484C *)(((Lobby_801C484C *)this)), 1) != 0) {
            TLobby::send_battle_mode_params(5, 0, 0);
            return;
        }
        secs = (OSGetTime() - ((Lobby_801C484C *)this)->start) / (*(u32 *)0x800000F8 / 4);
        rem = ((Lobby_801C484C *)this)->limit - secs;
        ((Lobby_801C484C *)this)->remain = rem > 0 ? rem : 0;
        TWindowCtrl::set_timer_window_time(((Lobby_801C484C *)this)->remain);
        if (((Lobby_801C484C *)this)->remain == 0) {
            ((Lobby_801C484C *)this)->result = 3;
            TLobby::send_battle_mode_params(3, 0, 0);
            return;
        }
        if (TLobby::check_battle_end(((Lobby_801C484C *)this)) != 0) {
            if (--((Lobby_801C484C *)this)->timer48 <= 0) {
                ((Lobby_801C484C *)this)->result = 3;
                TLobby::send_battle_mode_params(3, 0, 0);
            }
        } else {
            ((Lobby_801C484C *)this)->timer48 = 300;
        }
        ((TLobby *)((Lobby_801C484C *)this))->update_battle_sync(secs);
        if (--((Lobby_801C484C *)this)->timer60 <= 0) {
            send_battle_mode_state();
            ((Lobby_801C484C *)this)->timer60 = 90;
        }
        TLobby::calc_player_rankings((Lobby_801C484C *)(((Lobby_801C484C *)this)));
        break;
    case -1:
        break;
    }
}

void update_duel_result__6TLobbyFPv(u8 *arg0) {
    void *p;
    void *q;
    switch (*(s32 *)((s8 *)arg0 + 0x20)) {
    case 0:
        TLobby::init(arg0);
        lbl_805D5DA8 = 0;
        lbl_805D5DAC = 0;
        p = (void *)TObject::operator new(0x28);
        if (p != NULL) {
            __ct__15TDuelEffectCtrlFP7TObjectUc(p, arg0, 1);
        }
        *(s32 *)((s8 *)arg0 + 0x2C) = 0x78;
        TWindowCtrl::close_timer_window();
        TWindowCtrl::suppress_slot(local_client_id);
        *(s32 *)((s8 *)arg0 + 0x20) = 1;
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
        if (--*(s32 *)((s8 *)arg0 + 0x2C) <= 0) {
            ((TLobby *)arg0)->send_battle_mode_state();
            *(s32 *)((s8 *)arg0 + 0x2C) = 0x5A;
            *(s32 *)((s8 *)arg0 + 0x20) = 2;
        }
        break;
    case 2:
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (--*(s32 *)((s8 *)arg0 + 0x2C) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x44) = 0x1C2;
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
        }
        break;
    case 3:
        p = (void *)(saddr)get_local_player();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (((TLobby *)arg0)->check_timeout((*(s32 *)((s8 *)arg0 + 0x44))--) != 0 || *(s32 *)((s8 *)arg0 + 0x44) <= 0) {
            TLobby::clear_counter(arg0);
            TLobby::calc_player_rankings((Lobby_801C484C *)arg0);
            record_local_battle_placement(arg0);
            if (((u16 *)duel_result_table)[0] == local_client_id) {
                play_duel_result_stream("win.adx", 0x96);
            } else {
                play_duel_result_stream("lose.adx", 0x96);
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 4;
        }
        break;
    case 4:
        if (*(void **)((s8 *)arg0 + 0x54) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x54)))->close();
        }
        *reinterpret_cast<TWindowDuelResult **>(arg0 + 0x54) = new TWindowDuelResult(local_client_id);
        q = (void *)(saddr)get_local_player();
        if (q != NULL) {
            if (((TObjPlayer *)q)->check_player_flag1() == 0) {
                TLobby::close_and_play_effect((u16)local_client_id, 1);
            }
            ((TObjPlayer *)q)->release_attached_resource();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 5;
        break;
    case 5:
        if (controller_input_state.controllers[0].pressed_buttons & 2) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x54)))->close();
            *(void **)((s8 *)arg0 + 0x54) = NULL;
            *(s32 *)((s8 *)arg0 + 0x20) = 6;
            p = (void *)(saddr)get_local_player();
            if (p != NULL && (static_cast<TObjPlayer *>(p)->actorFlags & 0x800)) {
                static_cast<TObjPlayer *>(p)->reset_pose();
            }
        }
        break;
    case 6:
        if (TLobby::check_team_balance((Lobby_801C484C *)((Lobby_801C484C *)arg0), 0) != 0) {
            TLobby::send_battle_mode_params(5, 1, 0);
        } else {
            q = (void *)(saddr)get_local_player();
            if (local_client_id == designated_client_id && TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
                if (*(void **)((s8 *)arg0 + 0x4C) == NULL) {
                    *(void **)((s8 *)arg0 + 0x4C) = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x53)), (const f32 *)lbl_80446FA4, 1);
                    if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
                        ((TWindowMessage *)(*(void **)((s8 *)arg0 + 0x4C)))->append_line(*(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 0), 0x80);
                    }
                }
                if (*(void **)((s8 *)arg0 + 0x50) == NULL) {
                    *(void **)((s8 *)arg0 + 0x50) = create_window_menu_default(get_window_layout_position(0x54), 3);
                    ((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->add_text_entry(*(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 4), 6, 1);
                    ((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->add_text_entry(*(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 8), 6, 2);
                    ((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->add_text_entry(*(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 0xC), 6, 3);
                    ((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(*(void **)((s8 *)arg0 + 0x50)));
                    ((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->set_ready_flag();
                }
                if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
                    if (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->is_decided() != 0) {
                        switch (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->get_selected_value()) {
                        case 1:
                            send_6x7D_set_battle_mode_data(arg0);
                            *(s32 *)((s8 *)arg0 + 0x20) = 9;
                            break;
                        case 2:
                            *(s32 *)((s8 *)arg0 + 0x20) = 7;
                            break;
                        case 3:
                            TLobby::send_battle_mode_params(4, 0, 0);
                            *(s32 *)((s8 *)arg0 + 0x20) = 9;
                            break;
                        }
                    } else if (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->is_cancelled() != 0) {
                        *(s32 *)((s8 *)arg0 + 0x20) = 7;
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
        if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
            *(void **)((s8 *)arg0 + 0x4C) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x50)))->close();
            *(void **)((s8 *)arg0 + 0x50) = NULL;
        }
        p = (void *)(saddr)get_local_player();
        if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() != 0) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 8;
    case 8:
        if (TLobby::check_team_balance((Lobby_801C484C *)((Lobby_801C484C *)arg0), 0) != 0) {
            TLobby::send_battle_mode_params(5, 1, 0);
        } else {
            p = (void *)get_player_by_client_id(local_client_id);
            if (p != NULL && ((TObjPlayer *)p)->is_controls_locked() == 0 && (controller_input_state.controllers[0].pressed_buttons & 6)) {
                *(s32 *)((s8 *)arg0 + 0x20) = 6;
            }
        }
        break;
    case -1:
        if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
            *(void **)((s8 *)arg0 + 0x4C) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x50)))->close();
            *(void **)((s8 *)arg0 + 0x50) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x54) != NULL) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x54)))->close();
            *(void **)((s8 *)arg0 + 0x54) = NULL;
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
    if (*(s32 *)((s8 *)arg0 + 0x20) == 6 || *(s32 *)((s8 *)arg0 + 0x20) == 8) {
        p = (void *)(saddr)get_local_player();
        if (p != NULL && ((TObjPlayer *)p)->is_controls_locked() == 0 && TWindowCtrl::has_player_active_menu(local_client_id) == 0 && (controller_input_state.controllers[0].pressed_buttons & 0x400)) {
            if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
                *(void **)((s8 *)arg0 + 0x4C) = NULL;
            }
            if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x50)))->close();
                *(void **)((s8 *)arg0 + 0x50) = NULL;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 4;
        }
    }
}

void TLobby::end_battle_mode_cleanup() {
    switch (*(s32 *)((u8 *)this + 0x20)) {
    case 0:
        if (TLobby__idle_timeout_object != NULL) {
            delete TLobby__idle_timeout_object;
            TLobby__idle_timeout_object = NULL;
        }
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F950();
        TLobby__data_805D5CE8 = 1;
        ((TObject *)this)->queue_destruction();
        break;
    case -1:
        break;
    }
}

s32 TLobby__sub_801C417C(void) {
    return *(s32 *)((s8 *)(*(void * *)&battle_config_ptr) + 0x24) * 0x3C;
}

void TLobby::close_and_play_effect(int client, s32 arg1) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        send_impose_hold(player, -1);
    }
    if (arg1 != 0) {
        begin_player_keyboard_hold(local_client_id);
        request_active_window_close();
        TWindowCtrl::suppress_slot(local_client_id);
    }
}

void TLobby::handle_battle_result(int client, s32 arg1) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id((u16)client)) != NULL) {
        send_release_hold(player);
    }
    if (arg1 != 0) {
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
    }
}

void TLobby::apply_game_settings(s32 arg0, s32 arg1) {
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    if (arg1 != 0) {
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
        ((TLobby *)lobby_rule_settings)->set_validated_field_0x11((u8) CFG->v1c);
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
                    set_player_team_id((void *)(p + 0x828), battle_intro_value_table[i]);
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
        TLobby::set_section_id(lobby_rule_settings, 1);
    }
    if (((u32 (*)(void))get_local_player)() != 0U) {
        TLobby::apply_battle_rules_to_players();
    }
}

void TLobby::send_battle_mode_params(s8 arg0, s32 arg1, s32 arg2) {
    Stack_801C3CFC stack;
    build_6x7D_set_battle_mode_data(&stack.sp8);
    stack.spD = arg0;
    stack.spC = 0;
    stack.sp10 = arg1;
    stack.sp14 = arg2;
    ((TLobby *)(&stack.sp8))->send_set_battle_mode_data();
}

s32 check_team_balance__6TLobbyFPvi(Lobby_801C484C *self, s32 arg1) {
    s32 i;
    s32 t;
    uaddr pl;
    if (TLobby::get_game_mode() <= 1) {
        return 1;
    }
    if (arg1 != 0 && ((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
        Cnt_801C3C1C cnt = lbl_80446FAC[0];
        i = 0;
        do {
            pl = (uaddr)get_player_by_client_id(i);
            if (pl != 0) {
                t = TLobby__sub_801C19D0((void *)(pl + 0x828)) - 1;
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

void TLobby__sub_801C3AF4(Lobby_801C3AF4 *self) {
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
        Pair_801C3AF4 p = lbl_80446FB4[0];
        self->window = TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0xB3)), (const f32 *)(&p), 1);
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
    lobby_char_slot_array = __construct_new_array(mem_alloc(0x3220), (void *)init_char_data__10TObjPlayerFv, (void *)destroy_char_data__10TObjPlayerFis, 0x42C, 0xC);
    TAdSinglePlyChrSelectGC__sub_801C5158();
    clear_battle_player_ready_flags();
    battle_ctrl_default_value = 1;
    TAdSinglePlyChrSelectGC__sub_801C5120();
}

void TLobby__sub_801C3A40(void) {
    if (lobby_char_slot_array != 0) {
        __destroy_new_array(lobby_char_slot_array, (void *)destroy_char_data__10TObjPlayerFis);
        lobby_char_slot_array = 0;
    }
}

void TLobby::init_battle_ctrl(s32 arg0, saddr src) {
    uaddr player_battle_ctrl;
    if ((u32) (*(u32 *)&battle_mode_data_ptr) == 0U) {
        player_battle_ctrl = (uaddr)new TPlayerBattleCtrl((TObject *)tl_00);
        (*(u32 *)&battle_mode_data_ptr) = player_battle_ctrl;
    }
    if ((u32) (*(u32 *)&battle_mode_data_ptr) != 0U) {
        strncpy((char *)((*(uaddr *)&battle_mode_data_ptr) + 0x68), (const char *)src, 0x200);
        battle_config_ptr = arg0;
    }
}

void TLobby__sub_801C38E8(void *arg0) {
    TObjPlayer *player;
    switch (*(s32 *)((u8 *)arg0 + 0x20)) {
    case 0:
        player = get_local_player();
        if (player != NULL) {
            send_impose_hold(player, -1);
        }
        *(s32 *)((u8 *)arg0 + 0x2C) = 0xF;
        *(s32 *)((u8 *)arg0 + 0x20) = 1;
    case 1:
        if (--*(s32 *)((u8 *)arg0 + 0x2C) <= 0) {
            TLobby__sub_8020BC50();
            TLobby__sub_801036CC();
            if (quest_mission_manager != NULL) {
                TQuestThread::clear_buffer(quest_mission_manager);
            }
            TLobby::stop_audio_streams();
            lbl_805D5DB4 = 0;
            TLobby::init_fadeout_state(TLobby::init_and_set_flag);
            *(s32 *)((u8 *)arg0 + 0x20) = 2;
        }
        break;
    case 2:
        if (lbl_805D5DB4 != 0) {
            TLobby::finish_chr_select_scene_init();
            TLobby::set_fade_params(TLobby__sub_801C38A4);
            *(s32 *)((u8 *)arg0 + 0x20) = 3;
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

void handle_6x7D_set_battle_mode_data(Pkt_801C374C *pkt) {
    uaddr p;
    s32 i;
    ((TLobby *)pkt)->bswap_set_battle_mode_data();
    switch (pkt->type) {
    case 0:
        if (battle_mode_data_ptr != NULL) {
            ((Lobby_801C374C *)battle_mode_data_ptr)->mode = pkt->mode;
            ((Lobby_801C374C *)battle_mode_data_ptr)->a = pkt->v[0];
            ((Lobby_801C374C *)battle_mode_data_ptr)->b = pkt->v[1];
        }
        break;
    case 2:
        lbl_805D5DA4 = 1;
        break;
    case 3:
        p = (uaddr)get_player_by_client_id(pkt->v[0]);
        if (p != 0) {
            if (pkt->v[0] != local_client_id) {
                ((TPlayerBattleCtrl4P *)(p + 0x7AC))->set_battle_mode(pkt->v[1]);
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
            ((Lobby_801C374C *)battle_mode_data_ptr)->mode = 6;
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

void TLobby__sub_801C36E4(void *arg0, void *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}

s32 calc_player_rankings__6TLobbyFPv(Lobby_801C484C *) {
    s32 n;
    s32 i;
    s32 j;
    uaddr p;
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
        Team_801C343C team = lbl_80446FBC[0];
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                s32 t = TLobby__sub_801C19D0((void *)(p + 0x828)) != 1 ? 1 : 0;
                team.v[t] += TLobby__sub_801C4FC4((void *)(p + 0x7AC));
            }
        }
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                TBL_801C343C[n].id = ((TObjBase *)p)->get_entity_id();
                TBL_801C343C[n].score = team.v[TLobby__sub_801C19D0((void *)(p + 0x828)) != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = (uaddr)get_player_by_client_id(k);
            if (p != 0) {
                TBL_801C343C[n].id = ((TObjBase *)p)->get_entity_id();
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

void record_local_battle_placement(void *arg0) {
    s32 slot;
    s32 i;
    s32 n;
    s32 s;
    s32 r;
    uaddr pl;

    slot = -1;
    for (i = 0; i < 4; i++) {
        pl = (uaddr)get_player_by_client_id(duel_result_table[i].id);
        if (pl != 0 && local_client_id == (u16)((TObjBase *)pl)->get_entity_id()) {
            slot = TBL_801C32B4[i].slot;
            break;
        }
    }
    if (TLobby__sub_801C26A8() == 0) {
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
    s32 temp_r3;
    saddr temp_r3_2;

    temp_r3_2 = (saddr)get_local_player();
    if (temp_r3_2 == 0) {
        return 0;
    }
    temp_r3 = TObjPlayer__sub_801AFFD0();
    ((TPlayerBattleCtrl4P *)(temp_r3_2 + 0x7AC))->set_battle_mode(temp_r3);
    return temp_r3;
}

TUnk_804C3E88::TUnk_804C3E88(TObject *parent, const char *name, s32 delay) : TObject(parent) {
    delay_frames = delay;
    strncpy(music_name, name, 32);
}

TUnk_804C3E88::~TUnk_804C3E88() {}

void TUnk_804C3E88::run_task() {
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
  this->m_3c = TLobby__sub_801C417C();
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
    ((TLobby *)(temp_r3 + 0x78C))->update_child_player();
    ((TLobby *)(temp_r3 + 0x77C))->update_child_player();
    ((TLobby *)(temp_r3 + 0x75C))->update_child_player();
    ((TLobby *)(temp_r3 + 0x76C))->update_child_player();
    ((TLobby *)(temp_r3 + 0x79C))->update_child_player();
    ((TPlayerBattleCtrl4P *)(temp_r3 + 0x7AC))->set_battle_mode(0);
  }
  *((s32 *) (((s8 *) this) + 0x60)) = 0x5A;
  TLobby::calc_player_rankings((Lobby_801C484C *)this);
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
    ((Lobby_801C2F40 *)this)->time = OSGetTime();
    TLobby::handle_battle_result((u16)local_client_id, 1);
    if ((p = (saddr)get_local_player()) != 0) {
        obj_clear_flag30_20000((void *)p);
    }
    TLobby::clear_counter(this);
    area = get_current_floor_area();
    name = (area == AREA_BATTLE1) ? "duel1.adx" : "duel2.adx";
    new TUnk_804C3E88(this, name, 0x2D);
    for (i = 0; i < 8; i++) {
        ((Lobby_801C2F40 *)this)->pending[i] = 1;
        if (battle_event_second_table[i] == 0) {
            ((Lobby_801C2F40 *)this)->pending[i] = 0;
        }
    }
    ((Lobby_801C2F40 *)this)->f64 = battle_ctrl_default_value;
}

void init__6TLobbyFPv(void *arg0) {
    saddr temp_r3;
    s32 i;
    uaddr player;

    ((TLobby *)arg0)->set_flag_270();
    TLobby::close_and_play_effect((u16) local_client_id, 1);
    temp_r3 = (saddr)get_local_player();
    if (temp_r3 != 0) {
        obj_set_flag_20000();
        ((ProtectionTimer *)(temp_r3 + 0x644))->set_frames(0xE10);
    }
    TOMineTrap::destroy_matching_traps();
    queue_destroy_event_descendants((TObject*)tl_01);
    TQuestThread::destroy_all_in((TObject *)tl_00);
    TLobby__sub_8020BCE4();
    TAdSinglePlyChrSelectGC::destroy();
    TLobby__sub_8020BB18();
    i = 0;
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
    do {
        player = (uaddr)get_player_by_client_id(i);
        if (player != 0U) {
            clear_trap_counts((s8 *)(player + 0x7C4));
        }
        i += 1;
    } while (i < 4);
}

void send_6x7D_set_battle_mode_data(void *) {
    Msg_801C2D54 msg;
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
        if (down->check_value_equals(TDeadSpot__class_name) != 0) {
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
    Stack_801C2C34 stack;
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
    Entry_801C2B04 *e;
    s32 i;
    TObjPlayer *p;
    TLobby::clear_counter(this);
    TLobby::calc_player_rankings((Lobby_801C484C *)this);
    ((TWindowCtrl *)"SCORE")->init_all_default();
    for (i = 0; i < 4; i++) {
        e = (Entry_801C2B04 *)&duel_result_table[i];
        p = get_player_by_client_id(e->id);
        if (p != NULL) {
            sprintf(buf, "%s %s", lobby_rank_ordinal_text_table[e->name], p->get_name());
            ((TWindowCtrl *)buf)->init_all_default();
        }
    }
    play_duel_result_stream("start.adx", 0x3C);
}

void TLobby::set_flag_270() {
    send_battle_mode_state();
    *(s32 *)((s8 *)this + 0x270) = 1;
}

void TLobby::send_battle_mode_state() {
    Msg_801C29F0 m;
    Player_801C29F0 *p;
    s32 id;
    s32 on;
    p = (Player_801C29F0 *)(saddr)get_local_player();
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
                       ((TPlayerBattleCtrl4P *)(p->ctrl))->get_state() == 0) {
                on = 0;
            }
        }
        m.enabled = on;
        battle_team_table[local_client_id] = on;
        ((TLobby *)(&m))->send_set_battle_mode_data();
    }
}

s32 TLobby::check_timeout(s32 timer) {
    if ((s32) lbl_805D5DB0 >= TLobby::get_game_mode()) {
        *(s32 *)((s8 *)this + 0x270) = 2;
    }
    return *(s32 *)((s8 *)this + 0x270) == 2;
}

void TLobby::clear_counter(void* a0) { *(int*)((char*)a0 + 0x270) = 0; lbl_805D5DB0 = 0; }

void TLobby::send_battle_mode_data(void * _w0) {
    struct S801C295C_801C25B4 sp8;

    build_6x7D_set_battle_mode_data(&sp8);
    sp8.f4 = 5;
    ((TLobby *)(&sp8))->send_set_battle_mode_data();
}

void TLobby::update_battle_sync(s32 t) {
    s32 i;
    switch (((Lobby_801C2898 *)this)->state) {
    case 0:
        if (local_client_id == designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (((Lobby_801C2898 *)this)->pending[i] != 0 && t / 60 == battle_event_second_table[i]) {
                    ((Lobby_801C2898 *)this)->pending[i] = 0;
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
                           ((TPlayerBattleCtrl4P *)(p + 0x754))->get_state() == 0) {
                    ok = 0;
                }
            }
            if (ok != 0) {
                cnt++;
                if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
                    idx = TLobby__sub_801C19D0(p + 0x828) - 1;
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

s32 TLobby__sub_801C26A8(void) {
    Ent_801C26A8 *e;
    s32 result = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &duel_result_table[i];
        if (get_player_by_client_id(e->id) != NULL && e->active != 0) {
            result = 0;
            break;
        }
    }
    return result;
}

s32 TLobby__sub_801C2678(void) {
    if (TLobby__sub_801C26A8() != 0) {
        return 0;
    }
    return battle_ctrl_default_value;
}

u8 TLobby__sub_801C2614(void) {
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
