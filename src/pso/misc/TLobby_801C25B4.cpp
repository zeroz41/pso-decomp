#include "pso/system/TSetEvtDestroy.h"
#include "pso/item/TItem.h"
#include "pso/TObject.h"
#include "pso/misc/TUnk_804C3E88.h"
#include "pso/TPlayerBattleCtrl.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#include "types.h"
#include "pso/ui/Language.h"
#include "pso/map/CurrentArea.h"

typedef struct Lobby_801C2898 {
    u8 pad0[0x268];
    s8 pending[8];
    s32 state;
} Lobby_801C2898;

struct Ent_801C26A8 { u16 id; s16 active; u8 pad[4]; };

extern "C" {
extern u8 *TLobby__battle_mode_data_ptr;
u8 TLobby__sub_801C2614(void);
extern s32 TLobby__battle_ctrl_default_value;
s32 TLobby__sub_801C2678(void);
u8 check_timeout__6TLobbyFPv(void *arg0);
void show_score_results__6TLobbyFPv(void *);
extern s16 battle_event_second_table[];
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
u32 get_player_by_client_id(s32);
s32 TLobby__sub_801C19D0(void *);
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
extern s32 TLobby__battle_team_table[];
u8 check_battle_end__6TLobbyFv(void);
extern Ent_801C26A8 TLobby__duel_result_table[];
s32 TLobby__sub_801C26A8(void);
s32 update_battle_controller__10TObjPlayerFv();
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(s32);
void __ct__7TObjectFP7TObject(void *);
s32 export_character_data__10TObjPlayerFPvPv(s32, s32);
extern u8 __vt__17TPlayerBattleCtrl[];
extern u8 player_battle_ctrl_text_japanese[];
extern u8 player_battle_ctrl_text_english[];
extern s32 TPlayerBattleCtrl__name;
void *TPlayerBattleCtrl__ct(void *arg0, s32 _w1);
struct S801C295C_801C25B4 { s32 f0; s8 f4; s8 pad[0x13]; };

s32 check_all_battle_flags__6TLobbyFv(void);
void clear_counter__6TLobbyFPv(void* a0);
void build_6x7D_set_battle_mode_data(void *p);
s32 obj_testFlags30__14TObjCollidableFUl(u32, s32);

extern "C" {
__declspec(section ".rodata") char lbl_80446F80[] = "TPlayerBattleCtrl";
__declspec(section ".rodata") u32 lbl_80446F94[2] = { 0x43A40000, 0x43260000 };
__declspec(section ".rodata") u32 lbl_80446F9C[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FA4[2] = { 0x43580000, 0x42A80000 };
__declspec(section ".rodata") u32 lbl_80446FAC[2] = { 0, 0 };
__declspec(section ".rodata") u32 lbl_80446FB4[2] = { 0x436E0000, 0x433C0000 };
__declspec(section ".rodata") u32 lbl_80446FBC[2] = { 0, 0 };
}
#define lbl_80446F94 ((Pair_801C49B8 *)lbl_80446F94)
#define lbl_80446F9C ((Cnt_801C49B8 *)lbl_80446F9C)
#define lbl_80446FA4 ((u8 *)lbl_80446FA4)
#define lbl_80446FAC ((Cnt_801C3C1C *)lbl_80446FAC)
#define lbl_80446FB4 ((Pair_801C3AF4 *)lbl_80446FB4)
#define lbl_80446FBC ((Team_801C343C *)lbl_80446FBC)

s32 check_all_battle_flags__6TLobbyFv(void) {
    u32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
loop_1:
    temp_r3 = get_player_by_client_id(var_r31);
    if ((temp_r3 != 0U) && (obj_testFlags30__14TObjCollidableFUl(temp_r3, 0x02000000) != 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 1;
    }
    goto loop_1;
}

u8 TLobby__sub_801C2614(void) {
  u8 var_r0;
  u8 *var_r3;
  if (TRaderMapCore::is_not_split_screen() == 1)
  {
    var_r0 = TPlayerBattleCtrl4P::is_battle_mode_active();
    return var_r0;
  }
  var_r3 = (u8 *) TLobby__battle_mode_data_ptr;
  if (var_r3 != 0)
  {
    var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r3) + 0x1C)));
    var_r0 = 0;
    if ((((s32) var_r3) == 1) || (((s32) var_r3) == 2))
    {
      var_r0 = 1;
    }
    var_r3 = (u8 *) ((void *) var_r0);
    return (u8) var_r3;
  }
  var_r3 = (u8 *) 0;
  return 0U;
}

s32 TLobby__sub_801C2678(void) {
    if (TLobby__sub_801C26A8() != 0) {
        return 0;
    }
    return TLobby__battle_ctrl_default_value;
}

s32 TLobby__sub_801C26A8(void) {
    Ent_801C26A8 *e;
    s32 result = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &TLobby__duel_result_table[i];
        if (get_player_by_client_id(e->id) != 0 && e->active != 0) {
            result = 0;
            break;
        }
    }
    return result;
}

u8 check_battle_end__6TLobbyFv(void) {
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
            if (TLobby__battle_team_table[i] == 0) {
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

void TLobby::update_battle_sync(s32 t) {
    s32 i;
    switch (((Lobby_801C2898 *)this)->state) {
    case 0:
        if (local_client_id == TLobby__designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (((Lobby_801C2898 *)this)->pending[i] != 0 && t / 60 == battle_event_second_table[i]) {
                    ((Lobby_801C2898 *)this)->pending[i] = 0;
                    TLobby::send_battle_mode_data(this);
                }
            }
        }
        break;
    case 1:
        check_timeout__6TLobbyFPv(((Lobby_801C2898 *)this));
        break;
    case 2:
        show_score_results__6TLobbyFPv(((Lobby_801C2898 *)this));
        break;
    }
}

void TLobby::send_battle_mode_data(void * _w0) {
    struct S801C295C_801C25B4 sp8;

    build_6x7D_set_battle_mode_data(&sp8);
    sp8.f4 = 5;
    ((TLobby *)(&sp8))->send_set_battle_mode_data();
}

    extern int lbl_805D5DB0;
void clear_counter__6TLobbyFPv(void* a0) { *(int*)((char*)a0 + 0x270) = 0; lbl_805D5DB0 = 0; }

}

#pragma push
namespace P1_801C29A0 {

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

struct VBase_801C2B04 { char pad[0x18]; };

struct VObj_801C2B04 : VBase_801C2B04 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9();
    virtual char *m10();
};

typedef struct Entry_801C2B04 {
    u16 id;
    s16 name;
    u8 pad4[4];
} Entry_801C2B04;

extern "C" {
u16 get_entity_id(void *);
Player_801C29F0 *update_battle_controller__10TObjPlayerFv(void);
s32 assign_player_id__6TLobbyFv(void *);
void build_6x7D_set_battle_mode_data(void *);
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
extern s32 TLobby__battle_team_table[];
extern s32 local_client_id;
void send_battle_mode_state__6TLobbyFPv(void *self);
VObj_801C2B04 *get_player_by_client_id(s32);
void clear_counter__6TLobbyFPv(void *a0);
void send_neg50__6TLobbyFPvPv(void *p, s32 a1);
void calc_player_rankings__6TLobbyFPv(void *);
int sprintf(char *, const char *, ...);
extern char lbl_80446FCC[];
extern char lbl_80446FD4[];
extern char lbl_80446FDC[];
extern char *lobby_rank_ordinal_text_table[];
extern Entry_801C2B04 TLobby__duel_result_table[];
void show_score_results__6TLobbyFPv(void *self);
u8 check_timeout__6TLobbyFPv(void *arg0);
void set_flag_270__6TLobbyFPv(void *arg0);

extern s32 lbl_805D5DB0;

u8 check_timeout__6TLobbyFPv(void *arg0) {
    if ((s32) lbl_805D5DB0 >= TLobby::get_game_mode()) {
        *(s32 *)((s8 *)arg0 + 0x270) = 2;
    }
    return (u8) (*(s32 *)((s8 *)arg0 + 0x270) == 2);
}

void send_battle_mode_state__6TLobbyFPv(void *self) {
    Msg_801C29F0 m;
    Player_801C29F0 *p;
    s32 id;
    s32 on;
    p = update_battle_controller__10TObjPlayerFv();
    if (p != NULL) {
        id = assign_player_id__6TLobbyFv(self);
        build_6x7D_set_battle_mode_data(&m);
        m.kind = 3;
        m.id = get_entity_id(p);
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
        TLobby__battle_team_table[local_client_id] = on;
        ((TLobby *)(&m))->send_set_battle_mode_data();
    }
}

void set_flag_270__6TLobbyFPv(void *arg0) {
    send_battle_mode_state__6TLobbyFPv(arg0);
    *(s32 *)((s8 *)arg0 + 0x270) = 1;
}
void show_score_results__6TLobbyFPv(void *self) {
    char buf[0x48];
    Entry_801C2B04 *e;
    s32 i;
    VObj_801C2B04 *p;
    clear_counter__6TLobbyFPv(self);
    calc_player_rankings__6TLobbyFPv(self);
    ((TWindowCtrl *)lbl_80446FCC)->init_all_default();
    for (i = 0; i < 4; i++) {
        e = &TLobby__duel_result_table[i];
        p = get_player_by_client_id(e->id);
        if (p != NULL) {
            sprintf(buf, lbl_80446FD4, lobby_rank_ordinal_text_table[e->name], p->m10());
            ((TWindowCtrl *)buf)->init_all_default();
        }
    }
    send_neg50__6TLobbyFPvPv(lbl_80446FDC, 0x3C);
}
__declspec(section ".rodata") char lbl_80446FCC[] = "SCORE";
__declspec(section ".rodata") char lbl_80446FD4[] = "%s %s";
__declspec(section ".rodata") char lbl_80446FDC[] = "start.adx";

}
}
#pragma pop

#pragma push

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
void TLobby__sub_801C2C34(void);
extern u8 TLobby__battle_player_ready_flags;
void clear_battle_player_ready_flags(void);
u64 OSGetTime(void);
void obj_clear_flag30_20000(void *);
void clear_counter__6TLobbyFPv(void *a0);
void init_with_name__6TLobbyFPvPvPvPv(void *, void *, void *, s32);
void handle_battle_result__6TLobbyFii(u16, s32);
void TObjEneRe4Sorcerer__sub_801E3F14(s32);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
void *__nw__7TObjectFUl(u32);
extern char lbl_80446FF0[];
extern char lbl_80446FFC[];
void queue_destruction__7TObjectFv(void *arg0);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern s32 lbl_805D2A98;
s32 get_entity_id();
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
s32 TObjPlayer__send_selected_spawn_position(s32, u16);
extern u16 battle_mode_data_table[];
extern s32 tl_05;
s32 rand();
void send_6x7D_set_battle_mode_data(void);
s32 obj_set_flag_20000();
s32 calc_player_rankings__6TLobbyFPv(void *);
s32 apply_game_settings__6TLobbyFii(void *, s32);
s32 close_and_play_effect__6TLobbyFii(u16, s32);
s32 TLobby__sub_801C417C();
s32 set_slot__23TAdSinglePlyChrSelectGCFi(u16);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void init_battle_round__17TPlayerBattleCtrlFv(void *arg0);
s32 check_all_players_ready__6TLobbyFv(void);
void init__6TLobbyFPv(void *arg0);
void TLobby__sub_8020BB18(void);
void TLobby__sub_8020BCE4(void);
void clear_trap_counts(s8 *arg0);
s32 destroy_children_with_tag(s32);

s32 set_flag_270__6TLobbyFPv();
s32 set_type__10TObjPlayerFl(s32, s32);

s32 check_all_players_ready__6TLobbyFv(void) {
    u8 *var_r31;
    s32 var_r30;
    s32 var_r29;

    var_r31 = &TLobby__battle_player_ready_flags;
    var_r30 = 1;
    var_r29 = 0;
loop_1:
    if ((get_player_by_client_id(var_r29) != 0U) && ((s8) *var_r31 == 0)) {
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

extern s32 tl_00;
extern s32 tl_01;

void TLobby__sub_801C2C34(void) {
    Stack_801C2C34 stack;
    build_6x7D_set_battle_mode_data((&stack.sp8));
    stack.spC = 4;
    stack.sp10 = local_client_id;
    ((TLobby *)(&stack.sp8))->send_set_battle_mode_data();
}

void clear_battle_player_ready_flags(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        (&TLobby__battle_player_ready_flags)[i] = 0;
    }
}

void TLobby::destroy_matching_children() {
    void *down;
    down = this->m_down;
while (down != NULL) {
        if (check_value_equals__13TUnk_804B6C24Fl(down, lbl_805D2A98) != 0) {
            queue_destruction__7TObjectFv(down);
        }
        ((TLobby *)down)->destroy_matching_children();
        down = *(void **)((s8 *)down + 0xC);
    }
}

void TLobby::finish_chr_select_scene_init() {
    s32 temp_r3;
    TLobby::init_scene_objects();
    temp_r3 = update_battle_controller__10TObjPlayerFv();
    if (temp_r3 != 0) {
        TObjPlayer__send_selected_spawn_position(temp_r3, battle_mode_data_table[(u16)get_entity_id()]);
        reset_cameras_to_actor((void *)temp_r3, 0);
    }
    ((TLobby *)tl_05)->destroy_matching_children();
    TAdSinglePlyChrSelectGC::destroy();
}

void send_6x7D_set_battle_mode_data(void) {
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
    ((TLobby *)(&msg))->send_60_sized();
}

void init__6TLobbyFPv(void *arg0) {
    s32 temp_r3;
    s32 var_r31;
    u32 player;

    set_flag_270__6TLobbyFPv();
    close_and_play_effect__6TLobbyFii((u16) local_client_id, 1);
    temp_r3 = update_battle_controller__10TObjPlayerFv();
    if (temp_r3 != 0) {
        obj_set_flag_20000();
        set_type__10TObjPlayerFl(temp_r3 + 0x644, 0xE10);
    }
    TOMineTrap::destroy_matching_traps();
    queue_destroy_event_descendants((TObject*)tl_01);
    destroy_children_with_tag(tl_00);
    TLobby__sub_8020BCE4();
    TAdSinglePlyChrSelectGC::destroy();
    TLobby__sub_8020BB18();
    var_r31 = 0;
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
    do {
        player = get_player_by_client_id(var_r31);
        if (player != 0U) {
            clear_trap_counts((s8 *)(player + 0x7C4));
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}
void TLobby::start_duel_battle() {
    char *name;
    void *obj;
    u32 p;
    s32 st;
    s32 i;
    TObjEneRe4Sorcerer__sub_801E3F14(4);
    TObjEneRe4Sorcerer__sub_801E3F18();
    ((Lobby_801C2F40 *)this)->time = OSGetTime();
    handle_battle_result__6TLobbyFii(local_client_id, 1);
    if ((p = update_battle_controller__10TObjPlayerFv()) != 0) {
        obj_clear_flag30_20000((void *)p);
    }
    clear_counter__6TLobbyFPv(this);
    st = get_current_area();
    name = (st == 0x10) ? lbl_80446FF0 : lbl_80446FFC;
    obj = __nw__7TObjectFUl(0x40);
    if (obj != NULL) {
        init_with_name__6TLobbyFPvPvPvPv(obj, this, name, 0x2D);
    }
    for (i = 0; i < 8; i++) {
        ((Lobby_801C2F40 *)this)->pending[i] = 1;
        if (battle_event_second_table[i] == 0) {
            ((Lobby_801C2F40 *)this)->pending[i] = 0;
        }
    }
    ((Lobby_801C2F40 *)this)->f64 = TLobby__battle_ctrl_default_value;
}
__declspec(section ".rodata") char lbl_80446FF0[] = "duel1.adx";
__declspec(section ".rodata") char lbl_80446FFC[] = "duel2.adx";
void TPlayerBattleCtrl::init_battle_round() {
  s32 char_select_slot;
  s32 temp_r3;
  s32 var_ctr;
  s32 var_r3;
  s32 i;
  this->m_3c = TLobby__sub_801C417C();
  TWindowCtrl::create_alt_timer();
  ((TWindowCtrl *)(this->m_3c))->set_timer_window_time();
  TOMineTrap::destroy_matching_traps();
  char_select_slot = TAdSinglePlyChrSelectGC::get_char_select_slot();
  char_select_slot = char_select_slot + 1;
  var_r3 = 0xFFFF;
  if (char_select_slot < var_r3)
  {
    var_r3 = char_select_slot;
  }
  set_slot__23TAdSinglePlyChrSelectGCFi((u16) var_r3);
  TAdSinglePlyChrSelectGC__sub_801FCE6C();
  apply_game_settings__6TLobbyFii(this, 1);
  close_and_play_effect__6TLobbyFii((u16) local_client_id, 1);
  temp_r3 = update_battle_controller__10TObjPlayerFv();
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
  calc_player_rankings__6TLobbyFPv(this);
  for (i = 0; i < 4; i++)
  {
    TLobby__battle_team_table[i] = 1;
  }
}
}

#pragma pop

#pragma push
namespace P3_801C25B4 {

struct Stack_801C3CFC {
    s32 sp8;
    s8 spC;
    s8 spD;
    u8 pad_E[0x2];
    s32 sp10;
    s32 sp14;
};

typedef struct Pair_801C3AF4 { u32 a; u32 b; } Pair_801C3AF4;

typedef struct Flags_801C3AF4 {
    u8 pad0[0x10];
    u32 flags;
} Flags_801C3AF4;

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

struct VBase_801C4214 { char pad[0x18]; };

struct VObj_801C4214 : VBase_801C4214 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61();
    virtual void m62();
};

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
    virtual s32 m10();
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

struct Lobby_801C484C;
typedef struct Cnt_801C3C1C { s32 v[2]; } Cnt_801C3C1C;

struct Base_801C418C { u8 pad[0x18]; };

struct V_801C418C : Base_801C418C {
    virtual ~V_801C418C();
};

extern "C" {
void handle_6x7E(void);
extern void *TLobby__battle_mode_data_ptr;
void TLobby__sub_801C38A4(void);
void TLobby__sub_801B09A4(void);
    extern int lbl_805D5DB4;
void init_and_set_flag__6TLobbyFv(void);
u32 __nw__7TObjectFUl(s32);
void strncpy(void *, void *, int);
extern void *TLobby__battle_mode_data_ptr;
extern s32 TLobby__battle_config_ptr;
extern s32 tl_00;
void init_battle_ctrl__6TLobbyFii(s32 arg0, s32 arg1);
void build_6x7D_set_battle_mode_data(void *p);
void send_battle_mode_params__6TLobbyFcii(s8 arg0, s32 arg1, s32 arg2);
u32 get_player_by_client_id(u16);
void end_player_keyboard_hold(s32 arg0);
s32 send_code_45_1__10TObjPlayerFl();
extern s32 local_client_id;
void handle_battle_result__6TLobbyFii(int arg0, s32 arg1);
u32 get_player_by_client_id(u16);
void begin_player_keyboard_hold(s32 arg0);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
extern s32 local_client_id;
void request_active_window_close(void);
void close_and_play_effect__6TLobbyFii(int arg0, s32 arg1);
extern s32 TLobby__battle_config_ptr;
s32 TLobby__sub_801C417C(void);
extern void *lobby_char_slot_array;
void __destroy_new_array(void *, void *);
void TLobby__sub_801C3A40(void);
int TKeyBoardControl__sub_8000F828(void);
void *mem_alloc(u32 size);
void clear_battle_player_ready_flags(void);
void TAdSinglePlyChrSelectGC__sub_801C5120(void);
void TAdSinglePlyChrSelectGC__sub_801C5158(void);
void *__construct_new_array(void *, void *, void *, s32, s32);
s32 destroy_char_data__10TObjPlayerFis(s32 arg0, s16 arg1);
void init_char_data__10TObjPlayerFv(void);
extern void *TLobby__battle_mode_data_ptr;
extern s32 lbl_805D5D9C;
extern void *lobby_char_slot_array;
extern s32 TLobby__battle_ctrl_default_value;
void init_char_slots__6TLobbyFv(void);
void close_and_play_effect__6TLobbyFii(int arg0, s32 arg1);
void set_slot__23TAdSinglePlyChrSelectGCFi(u16);
void TWindow__close(void *);
void *set_window_mode_4__6TLobbyFPvll(void *, void *, s32);
void *get_window_layout_position(s32);
extern Flags_801C3AF4 *controller_input_state[];
extern s32 local_client_id;
void TLobby__sub_801C3AF4(Lobby_801C3AF4 *self);
u32 get_player_by_client_id(u16);
void set_flag_270__6TLobbyFPv(void *);
extern s32 TLobby__battle_team_table[];
extern s16 battle_mode_data_table[];
extern s32 local_client_id;
extern void *TLobby__battle_mode_data_ptr;
extern s32 lbl_805D5DA4;
extern s32 lbl_805D5DB0;
extern u8 TLobby__battle_player_ready_flags[4];
void handle_6x7D_set_battle_mode_data(Pkt_801C374C *pkt);
void send_battle_mode_params__6TLobbyFcii(s8 arg0, s32 arg1, s32 arg2);
s64 OSGetTime();
s32 check_battle_end__6TLobbyFv(Lobby_801C484C *);
void send_battle_mode_state__6TLobbyFPv(Lobby_801C484C *);
void update_timed_wait__6TLobbyFPv(Lobby_801C484C *self);
u32 get_player_by_client_id(u16);
s32 update_battle_controller__10TObjPlayerFv();
s32 fn_801C19D8(void *, int);
s32 fn_801D6D8C(void *, int, int);
s32 fn_801D726C(void *, int);
s32 fn_801D72B0(void *, int);
s32 set_field_0xE__6TLobbyFPvUc(void *, int);
s32 set_field_d__6TLobbyFPvUc(void *, int);
s32 set_clamped_field_c__6TLobbyFPvUc(void *, int);
s32 set_field_b__6TLobbyFPvUc(void *, int);
s32 set_field_a__6TLobbyFPvUc(void *, int);
s32 set_byte9_clamped__6TLobbyFPvUc(void *, int);
s32 set_difficulty__6TLobbyFPvUc(void *, int);
s32 set_field7_clamped__6TLobbyFPvUc(void *, int);
s32 set_field_0x6__6TLobbyFPvUc(void *, int);
s32 set_field_5__6TLobbyFPvUc(void *, int);
s32 set_clamped_field_4__6TLobbyFPvUc(void *, int);
s32 set_field_3__6TLobbyFPvUc(void *, int);
s32 set_field_2__6TLobbyFPvUc(void *, int);
s32 set_validated_field_0x1__6TLobbyFPvUc(void *, int);
s32 set_section_id__6TLobbyFPvUc(void *, int);
extern u32 player_slot_table[];
extern s32 lobby_rule_settings[];
extern s32 battle_intro_value_table[];
extern const f32 lbl_805D3538;
extern const f32 lbl_805D353C;
extern const f32 lbl_805D3540;
extern const f32 lbl_805D3544;
extern const f32 lbl_805D3548;
extern const f32 lbl_805D354C;
extern const f32 lbl_805D3550;
extern s32 TLobby__battle_config_ptr;
extern const f32 lbl_805D5DC4;
extern const f32 lbl_805D5DC8;
void apply_game_settings__6TLobbyFii(s32 arg0, s32 arg1);
void obj_clear_flag30_20000(void *arg0);
s32 __ct__15TDuelEffectCtrlFP7TObjectUc(void *, void *, int);
s32 check_flag_100__10TObjPlayerFPv(void *);
u32 get_player_by_client_id(u16);
s32 update_battle_controller__10TObjPlayerFv();
s32 clear_counter__6TLobbyFPv(void *);
s32 check_timeout__6TLobbyFPv(void *, int);
void send_battle_mode_state__6TLobbyFPv(Lobby_801C484C *);
s32 send_6x7D_set_battle_mode_data(void *);
s32 init__6TLobbyFPv();
void send_neg50__6TLobbyFPvPv(void* p, void* a1);
s32 record_local_battle_placement(void *);
void send_battle_mode_params__6TLobbyFcii(s8 arg0, s32 arg1, s32 arg2);
void handle_battle_result__6TLobbyFii(int arg0, s32 arg1);
void close_and_play_effect__6TLobbyFii(int arg0, s32 arg1);
u32 __nw__7TObjectFUl(s32);
void TWindow__close(void *);
s32 has_player_active_menu__11TWindowCtrlFv(s32);
u32 TWindowDuelResult__ct(void *, s32);
s32 get_selected_menu_value(void *);
s32 align_menu_entry_positions(void *);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(void *, s32, int, int);
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
void *set_window_mode_4__6TLobbyFPvll(void *, void *, s32);
void *get_window_layout_position(s32);
extern u8 lbl_80447008[];
extern u8 lbl_80447010[];
extern Flags_801C3AF4 *controller_input_state[];
extern s32 TLobby__duel_result_table[];
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
extern s32 lbl_805D5DA8;
extern s32 lbl_805D5DAC;
void update_duel_result__6TLobbyFPv(u8 *arg0);
s32 __ct__15TDuelEffectCtrlFP7TObjectUc(void *, void *, int);
u32 get_player_by_client_id(u16);
s32 check_all_battle_flags__6TLobbyFv(void *);
s32 check_all_players_ready__6TLobbyFv(void *);
void TLobby__sub_801C2C34(void *);
void clear_battle_player_ready_flags(void);
u32 __nw__7TObjectFUl(s32);
void TWindow__close(void *);
void *set_window_mode_4__6TLobbyFPvll(void *, void *, s32);
void *get_window_layout_position(s32);
int sprintf(char *str, const char *format, ...);
void strncpy(void *, void *, int);
extern s32 lobby_rule_settings[];
extern s32 battle_intro_value_table[];
extern char battle_intro_message_buffer[];
extern s32 lbl_805D5DA4;
void update_battle_intro__6TLobbyFPv(Lobby_801C49B8 *self);
u32 get_player_by_client_id(u16);
s16 get_entity_id(u32);
s32 TLobby__sub_801C19D0(void *);
void TLobby__sub_801C36E4(void *arg0, void *arg1);
s32 TLobby__sub_801C4FC4(void *p);
extern s32 lobby_rule_settings[];
extern s32 TLobby__duel_result_table[];
s32 calc_player_rankings__6TLobbyFPv(Lobby_801C484C *);
void TLobby__sub_801036CC(void);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 update_battle_controller__10TObjPlayerFv();
s32 clear_buffer__12TQuestThreadFPv(u32);
void TLobby__sub_8020BC50(void);
void TLobby__sub_801C38A4(void);
void init_and_set_flag__6TLobbyFv(void);
extern int lbl_805D5DB4;
extern u32 quest_mission_manager;
void TLobby__sub_801C38E8(void *arg0);
u32 get_player_by_client_id(u16);
s32 TLobby__sub_801C19D0(void *);
extern s32 lobby_rule_settings[];
s32 check_team_balance__6TLobbyFPvi(Lobby_801C484C *self, s32 arg1);
void TKeyBoardControl__sub_8000F950(void);
void queue_destruction__7TObjectFv(void *arg0);
extern void *TLobby__idle_timeout_object;
extern s16 TLobby__data_805D5CE8;
extern s32 evt2_random_enemies_mode;
void end_battle_mode_cleanup__6TLobbyFPv(void *arg0);
typedef struct Ent_801C32B4 { u16 id; s16 slot; u32 pad; } Ent_801C32B4;
void TAdSinglePlyChrSelectGC__sub_801C50C0(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50CC();
void TAdSinglePlyChrSelectGC__sub_801C50D8(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50E4();
void TAdSinglePlyChrSelectGC__sub_801C50F0(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C50FC();
void TAdSinglePlyChrSelectGC__sub_801C5108(u16);
u16 TAdSinglePlyChrSelectGC__sub_801C5114();
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void TLobby__sub_801C36E4(void *arg0, void *arg1);
s32 assign_player_id__6TLobbyFv(void);
void *__dt__13TUnk_804C3E88Fv(void *arg0, s16 arg1);
void handle_6x7F_battle_scores(s32 arg0);
void *init_with_name__6TLobbyFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void release_ref__6TLobbyFPv(u8 *arg0);
void send_neg50__6TLobbyFPvPv(void* p, void* a1);
int play_cue_stream_file(void*);
void play_area_music(char *name);
s32 TObjPlayer__sub_801AFFD0();
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 bswap_packet_header__6TLobbyFv();
int show_duel_result_window(void*, void*);
s32 memcpy(s32 *, s32, s32);
void queue_destruction__7TObjectFv(void *arg0);
void strncpy(void *, void *, int);
s32 update_battle_controller__10TObjPlayerFv();

void release_ref__6TLobbyFPv(u8 *object) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)object + 0x1C) - 1;
    *(s32 *)((s8 *)object + 0x1C) = temp_r0;
    if (temp_r0 <= 0) {
        play_area_music((char *)(object + 0x20));
        queue_destruction__7TObjectFv(object);
    }
}

extern s32 lbl_804C3E88[];

void *__dt__13TUnk_804C3E88Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804C3E88;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804C3E88[];

void *init_with_name__6TLobbyFPvPvPvPv(void *object, void *arg1, void *arg2, void *arg3) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = lbl_804C3E88;
    *(void **)((s8 *)object + 0x1C) = arg3;
    strncpy((void *)((char *)object + 32), arg2, 32);
    return object;
}

s32 assign_player_id__6TLobbyFv(void) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3_2 = update_battle_controller__10TObjPlayerFv();
    if (temp_r3_2 == 0) {
        return 0;
    }
    temp_r3 = TObjPlayer__sub_801AFFD0();
    ((TPlayerBattleCtrl4P *)(temp_r3_2 + 0x7AC))->set_battle_mode(temp_r3);
    return temp_r3;
}

void send_neg50__6TLobbyFPvPv(void* p, void* a1) { play_cue_stream_file(p); show_duel_result_window((void*)-50, a1); }

#define TBL_801C32B4 ((Ent_801C32B4 *)TLobby__duel_result_table)
s32 record_local_battle_placement(void *arg0) {
    s32 slot;
    s32 i;
    s32 n;
    s32 s;
    s32 r;
    u32 pl;

    slot = -1;
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(*(u16 *)&TLobby__duel_result_table[i * 2]);
        if (pl != 0 && local_client_id == (u16)get_entity_id(pl)) {
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
    set_slot__23TAdSinglePlyChrSelectGCFi(s > 0 ? s : 0);
    TAdSinglePlyChrSelectGC__sub_801FCE6C();
}

#define TBL_801C343C ((Rank_801C343C *)TLobby__duel_result_table)
#define PLAYER_801C343C(k) ((u32 (*)(s32))get_player_by_client_id)(k)
s32 calc_player_rankings__6TLobbyFPv(Lobby_801C484C *) {
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
        Team_801C343C team = lbl_80446FBC[0];
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
                TBL_801C343C[n].id = get_entity_id(p);
                TBL_801C343C[n].score = team.v[TLobby__sub_801C19D0((void *)(p + 0x828)) != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = PLAYER_801C343C(k);
            if (p != 0) {
                TBL_801C343C[n].id = get_entity_id(p);
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

void TLobby__sub_801C36E4(void *arg0, void *arg1) {
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}

extern s32 TLobby__duel_result_table[];
extern s32 lbl_805D5DAC;

void handle_6x7F_battle_scores(s32 arg0) {
    bswap_packet_header__6TLobbyFv();
    memcpy(TLobby__duel_result_table, arg0 + 4, 0x20);
    lbl_805D5DAC = 1;
}
void handle_6x7E(void) {  }

void handle_6x7D_set_battle_mode_data(Pkt_801C374C *pkt) {
    u32 p;
    s32 i;
    ((TLobby *)pkt)->bswap_set_battle_mode_data();
    switch (pkt->type) {
    case 0:
        if (TLobby__battle_mode_data_ptr != NULL) {
            ((Lobby_801C374C *)TLobby__battle_mode_data_ptr)->mode = pkt->mode;
            ((Lobby_801C374C *)TLobby__battle_mode_data_ptr)->a = pkt->v[0];
            ((Lobby_801C374C *)TLobby__battle_mode_data_ptr)->b = pkt->v[1];
        }
        break;
    case 2:
        lbl_805D5DA4 = 1;
        break;
    case 3:
        p = ((u32 (*)(s32))get_player_by_client_id)(pkt->v[0]);
        if (p != 0) {
            if (pkt->v[0] != local_client_id) {
                ((TPlayerBattleCtrl4P *)(p + 0x7AC))->set_battle_mode(pkt->v[1]);
            }
            TLobby__battle_team_table[pkt->v[0]] = pkt->team;
        }
        lbl_805D5DB0++;
        break;
    case 4:
        TLobby__battle_player_ready_flags[pkt->v[0]] = 1;
        break;
    case 5:
        if (TLobby__battle_mode_data_ptr != NULL) {
            set_flag_270__6TLobbyFPv(TLobby__battle_mode_data_ptr);
        }
        break;
    case 6:
        if (TLobby__battle_mode_data_ptr != NULL) {
            ((Lobby_801C374C *)TLobby__battle_mode_data_ptr)->mode = 6;
            for (i = 0; i < 4; i++) {
                battle_mode_data_table[i] = pkt->v[i];
            }
        }
        break;
    }
}

void TLobby__sub_801C38A4(void) {
    if ((void *) TLobby__battle_mode_data_ptr != NULL) {
        *(s32 *)((s8 *)TLobby__battle_mode_data_ptr + 0x24) = 0;
    }
}
void init_and_set_flag__6TLobbyFv(void) { TLobby__sub_801B09A4(); advance_item_system_generation(); lbl_805D5DB4 = 1; }

void TLobby__sub_801C38E8(void *arg0) {
    u32 t;
    switch (*(s32 *)((u8 *)arg0 + 0x20)) {
    case 0:
        t = update_battle_controller__10TObjPlayerFv();
        if (t != 0) {
            play_effect_default__10TObjPlayerFii(t, -1);
        }
        *(s32 *)((u8 *)arg0 + 0x2C) = 0xF;
        *(s32 *)((u8 *)arg0 + 0x20) = 1;
    case 1:
        if (--*(s32 *)((u8 *)arg0 + 0x2C) <= 0) {
            TLobby__sub_8020BC50();
            TLobby__sub_801036CC();
            if (quest_mission_manager != 0) {
                clear_buffer__12TQuestThreadFPv(quest_mission_manager);
            }
            TLobby::stop_audio_streams();
            lbl_805D5DB4 = 0;
            TLobby::init_fadeout_state((s32)((void *)init_and_set_flag__6TLobbyFv));
            *(s32 *)((u8 *)arg0 + 0x20) = 2;
        }
        break;
    case 2:
        if (lbl_805D5DB4 != 0) {
            TLobby::finish_chr_select_scene_init();
            TLobby::set_fade_params((s32)((void *)TLobby__sub_801C38A4));
            *(s32 *)((u8 *)arg0 + 0x20) = 3;
        }
        break;
    case 3:
    default:
        break;
    }
}

void init_battle_ctrl__6TLobbyFii(s32 arg0, s32 arg1) {
    u32 player_battle_ctrl;
    if ((u32) (*(u32 *)&TLobby__battle_mode_data_ptr) == 0U) {
        player_battle_ctrl = __nw__7TObjectFUl(0x278);
        if (player_battle_ctrl != 0U) {
            player_battle_ctrl = ((u32)TPlayerBattleCtrl__ct((void *)player_battle_ctrl, (s32)tl_00));
        }
        (*(u32 *)&TLobby__battle_mode_data_ptr) = player_battle_ctrl;
    }
    if ((u32) (*(u32 *)&TLobby__battle_mode_data_ptr) != 0U) {
        strncpy((void *)((*(u32 *)&TLobby__battle_mode_data_ptr) + 0x68), (void *)arg1, 0x200);
        TLobby__battle_config_ptr = arg0;
    }
}

void TLobby__sub_801C3A40(void) {
    if (lobby_char_slot_array != 0) {
        __destroy_new_array(lobby_char_slot_array, (void *)destroy_char_data__10TObjPlayerFis);
        lobby_char_slot_array = 0;
    }
}

void init_char_slots__6TLobbyFv(void) {
    TLobby__battle_mode_data_ptr = 0;
    lbl_805D5D9C = TKeyBoardControl__sub_8000F828() == 1 ? 0x19 : 0x1E;
    lobby_char_slot_array = __construct_new_array(mem_alloc(0x3220), (void *)init_char_data__10TObjPlayerFv, (void *)destroy_char_data__10TObjPlayerFis, 0x42C, 0xC);
    TAdSinglePlyChrSelectGC__sub_801C5158();
    clear_battle_player_ready_flags();
    TLobby__battle_ctrl_default_value = 1;
    TAdSinglePlyChrSelectGC__sub_801C5120();
}

void TLobby__sub_801C3AF4(Lobby_801C3AF4 *self) {
    s32 idx;
    s32 s;
    switch (self->state) {
    case 0: {
        close_and_play_effect__6TLobbyFii((u16)local_client_id, 1);
        if (self->window != NULL) {
            TWindow__close(self->window);
            self->window = NULL;
        }
        if (self->f58 != 0) {
            idx = 5;
        } else {
            idx = 4;
            s = TAdSinglePlyChrSelectGC::get_char_select_slot() - 1;
            set_slot__23TAdSinglePlyChrSelectGCFi(s > 0 ? s : 0);
        }
        Pair_801C3AF4 p = lbl_80446FB4[0];
        self->window = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0xB3), &p, 1);
        if (self->window != NULL) {
            ((TLobby *)(self->window))->send_and_handle(self->msgs[idx], 0x80);
        }
        self->state = 1;
        break;
    }
    case 1:
        if (controller_input_state[0]->flags & 8) {
            self->next = 4;
        }
        break;
    case -1:
        break;
    }
}

s32 check_team_balance__6TLobbyFPvi(Lobby_801C484C *self, s32 arg1) {
    s32 i;
    s32 t;
    u32 pl;
    if (TLobby::get_game_mode() <= 1) {
        return 1;
    }
    if (arg1 != 0 && ((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
        Cnt_801C3C1C cnt = lbl_80446FAC[0];
        i = 0;
        do {
            pl = ((u32 (*)(s32))get_player_by_client_id)(i);
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

void send_battle_mode_params__6TLobbyFcii(s8 arg0, s32 arg1, s32 arg2) {
    Stack_801C3CFC stack;
    build_6x7D_set_battle_mode_data(&stack.sp8);
    stack.spD = arg0;
    stack.spC = 0;
    stack.sp10 = arg1;
    stack.sp14 = arg2;
    ((TLobby *)(&stack.sp8))->send_set_battle_mode_data();
}

#define CFG (*(Cfg_801C3D50 **)&TLobby__battle_config_ptr)
void apply_game_settings__6TLobbyFii(s32 arg0, s32 arg1) {
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    if (arg1 != 0) {
        s32 flag;
        set_validated_field_0x1__6TLobbyFPvUc(lobby_rule_settings, CFG->b[0]);
        set_field_2__6TLobbyFPvUc(lobby_rule_settings, CFG->b[1]);
        set_field_3__6TLobbyFPvUc(lobby_rule_settings, CFG->b[2]);
        set_clamped_field_4__6TLobbyFPvUc(lobby_rule_settings, CFG->b[3]);
        set_field_5__6TLobbyFPvUc(lobby_rule_settings, CFG->b[4]);
        set_field_0x6__6TLobbyFPvUc(lobby_rule_settings, CFG->b[5]);
        set_field7_clamped__6TLobbyFPvUc(lobby_rule_settings, CFG->b[6]);
        set_difficulty__6TLobbyFPvUc(lobby_rule_settings, CFG->b[7]);
        set_byte9_clamped__6TLobbyFPvUc(lobby_rule_settings, CFG->b[8]);
        set_field_b__6TLobbyFPvUc(lobby_rule_settings, CFG->b[0xA]);
        set_clamped_field_c__6TLobbyFPvUc(lobby_rule_settings, CFG->b[0xB]);
        fn_801D72B0(lobby_rule_settings, CFG->c);
        for (s32 i = 0; i < 4; i++) {
            fn_801D6D8C(lobby_rule_settings, CFG->b[i + 0xD], i);
        }
        set_field_d__6TLobbyFPvUc(lobby_rule_settings, CFG->d11);
        ((TObjPlayer *)lobby_rule_settings)->set_level(CFG->lvl);
        set_field_0xE__6TLobbyFPvUc(lobby_rule_settings, CFG->d13);
        ((TLobby *)lobby_rule_settings)->set_volume((u8) CFG->vol);
        ((TLobby *)lobby_rule_settings)->set_validated_field_0x11((u8) CFG->v1c);
        ((TLobby *)lobby_rule_settings)->set_clamped_index((s16) CFG->v20);
        ((TLobby *)lobby_rule_settings)->set_clamped_value_1c(CFG->v24);
        fn_801D726C(lobby_rule_settings, (u8) CFG->v28);
        flag = 0;
        if ((s32) CFG->b[9] == 1 && TLobby::get_game_mode() == 4) {
            s32 toggle = 1;
            for (s32 i = 0; i < 4; i++) {
                u32 p = ((u32 (*)(s32))get_player_by_client_id)(i);
                if (p != 0U) {
                    toggle = 1 - toggle;
                    s32 v = 2;
                    if (toggle != 0) {
                        v = 1;
                    }
                    battle_intro_value_table[i] = v;
                    fn_801C19D8((void *)(p + 0x828), battle_intro_value_table[i]);
                } else {
                    battle_intro_value_table[i] = -1;
                }
            }
            flag = 1;
        }
        set_field_a__6TLobbyFPvUc(lobby_rule_settings, (u8) (flag != 0));
        for (s32 i = 0; i < 4; i++) {
            u32 p = player_slot_table[i];
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
        set_section_id__6TLobbyFPvUc(lobby_rule_settings, 1);
    }
    if (((u32 (*)(void))update_battle_controller__10TObjPlayerFv)() != 0U) {
        TLobby::apply_battle_rules_to_players();
    }
}

void handle_battle_result__6TLobbyFii(int arg0, s32 arg1) {
    if (get_player_by_client_id(arg0) != 0U) {
        send_code_45_1__10TObjPlayerFl();
    }
    if (arg1 != 0) {
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        ((TWindowCtrl *)local_client_id)->unsuppress_slot();
    }
}
void close_and_play_effect__6TLobbyFii(int arg0, s32 arg1) {
    u32 temp = get_player_by_client_id(arg0);
    if (temp != 0U) {
        play_effect_default__10TObjPlayerFii(temp, -1);
    }
    if (arg1 != 0) {
        begin_player_keyboard_hold(local_client_id);
        request_active_window_close();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
    }
}
s32 TLobby__sub_801C417C(void) {
    return *(s32 *)((s8 *)(*(void * *)&TLobby__battle_config_ptr) + 0x24) * 0x3C;
}

struct Lobby_801C484C;
struct Flags_801C3AF4;
#define G28 (((u32 *)controller_input_state)[10])

void end_battle_mode_cleanup__6TLobbyFPv(void *object) {
    switch (*(s32 *)((u8 *)object + 0x20)) {
    case 0:
        if (TLobby__idle_timeout_object != NULL) {
            delete (V_801C418C *)TLobby__idle_timeout_object;
            TLobby__idle_timeout_object = NULL;
        }
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        TKeyBoardControl__sub_8000F950();
        TLobby__data_805D5CE8 = 1;
        queue_destruction__7TObjectFv(object);
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
        init__6TLobbyFPv();
        lbl_805D5DA8 = 0;
        lbl_805D5DAC = 0;
        p = (void *)__nw__7TObjectFUl(0x28);
        if (p != NULL) {
            __ct__15TDuelEffectCtrlFP7TObjectUc(p, arg0, 1);
        }
        *(s32 *)((s8 *)arg0 + 0x2C) = 0x78;
        TWindowCtrl::close_timer_window();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
        *(s32 *)((s8 *)arg0 + 0x20) = 1;
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        break;
    case 1:
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (--*(s32 *)((s8 *)arg0 + 0x2C) <= 0) {
            send_battle_mode_state__6TLobbyFPv((Lobby_801C484C *)arg0);
            *(s32 *)((s8 *)arg0 + 0x2C) = 0x5A;
            *(s32 *)((s8 *)arg0 + 0x20) = 2;
        }
        break;
    case 2:
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (--*(s32 *)((s8 *)arg0 + 0x2C) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x44) = 0x1C2;
            *(s32 *)((s8 *)arg0 + 0x20) = 3;
        }
        break;
    case 3:
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        if (check_timeout__6TLobbyFPv(arg0, (*(s32 *)((s8 *)arg0 + 0x44))--) != 0 || *(s32 *)((s8 *)arg0 + 0x44) <= 0) {
            clear_counter__6TLobbyFPv(arg0);
            calc_player_rankings__6TLobbyFPv((Lobby_801C484C *)((Lobby_801C484C *)arg0));
            record_local_battle_placement(arg0);
            if (((u16 *)TLobby__duel_result_table)[0] == local_client_id) {
                send_neg50__6TLobbyFPvPv(lbl_80447008, (void *)0x96);
            } else {
                send_neg50__6TLobbyFPvPv(lbl_80447010, (void *)0x96);
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 4;
        }
        break;
    case 4:
        if (*(void **)((s8 *)arg0 + 0x54) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x54));
        }
        p = (void *)__nw__7TObjectFUl(0x6C);
        if (p != NULL) {
            p = (void *)TWindowDuelResult__ct(p, local_client_id);
        }
        *(void **)((s8 *)arg0 + 0x54) = p;
        q = (void *)update_battle_controller__10TObjPlayerFv();
        if (q != NULL) {
            if (((TLobby *)q)->check_player_flag1() == 0) {
                close_and_play_effect__6TLobbyFii((u16)local_client_id, 1);
            }
            ((TObjPlayer *)q)->release_attached_resource();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 5;
        break;
    case 5:
        if (G28 & 2) {
            handle_battle_result__6TLobbyFii((u16)local_client_id, 1);
            TWindow__close(*(void **)((s8 *)arg0 + 0x54));
            *(void **)((s8 *)arg0 + 0x54) = NULL;
            *(s32 *)((s8 *)arg0 + 0x20) = 6;
            p = (void *)update_battle_controller__10TObjPlayerFv();
            if (p != NULL && (*(s32 *)((s8 *)p + 0x30) & 0x800)) {
                ((VObj_801C4214 *)p)->m62();
            }
        }
        break;
    case 6:
        if (check_team_balance__6TLobbyFPvi((Lobby_801C484C *)((Lobby_801C484C *)arg0), 0) != 0) {
            send_battle_mode_params__6TLobbyFcii(5, 1, 0);
        } else {
            q = (void *)update_battle_controller__10TObjPlayerFv();
            if (local_client_id == TLobby__designated_client_id && has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) {
                if (*(void **)((s8 *)arg0 + 0x4C) == NULL) {
                    *(void **)((s8 *)arg0 + 0x4C) = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x53), lbl_80446FA4, 1);
                    if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
                        ((TLobby *)(*(void **)((s8 *)arg0 + 0x4C)))->send_and_handle(*(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 0), 0x80);
                    }
                }
                if (*(void **)((s8 *)arg0 + 0x50) == NULL) {
                    *(void **)((s8 *)arg0 + 0x50) = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x54), 3);
                    forward_trade_action_default__16TObjCityMainWarpFPviii(*(void **)((s8 *)arg0 + 0x50), *(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 4), 6, 1);
                    forward_trade_action_default__16TObjCityMainWarpFPviii(*(void **)((s8 *)arg0 + 0x50), *(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 8), 6, 2);
                    forward_trade_action_default__16TObjCityMainWarpFPviii(*(void **)((s8 *)arg0 + 0x50), *(s32 *)((s8 *)(*(s32 **)((s8 *)arg0 + 0x40)) + 0xC), 6, 3);
                    ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x50)))->calc_window_size();
                    align_menu_entry_positions(*(void **)((s8 *)arg0 + 0x50));
                    ((TCheckRoomSequence *)(*(void **)((s8 *)arg0 + 0x50)))->set_ready_flag();
                }
                if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
                    if (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x50)))->is_visible() != 0) {
                        switch (get_selected_menu_value(*(void **)((s8 *)arg0 + 0x50))) {
                        case 1:
                            send_6x7D_set_battle_mode_data(arg0);
                            *(s32 *)((s8 *)arg0 + 0x20) = 9;
                            break;
                        case 2:
                            *(s32 *)((s8 *)arg0 + 0x20) = 7;
                            break;
                        case 3:
                            send_battle_mode_params__6TLobbyFcii(4, 0, 0);
                            *(s32 *)((s8 *)arg0 + 0x20) = 9;
                            break;
                        }
                    } else if (((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x50)))->get_status_flag() != 0) {
                        *(s32 *)((s8 *)arg0 + 0x20) = 7;
                    }
                }
                if (q != NULL && ((TLobby *)q)->check_player_flag1() == 0) {
                    close_and_play_effect__6TLobbyFii((u16)local_client_id, 1);
                }
            } else if (q != NULL && ((TLobby *)q)->check_player_flag1() != 0) {
                handle_battle_result__6TLobbyFii((u16)local_client_id, 1);
            }
        }
        break;
    case 7:
        if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x4C));
            *(void **)((s8 *)arg0 + 0x4C) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x50));
            *(void **)((s8 *)arg0 + 0x50) = NULL;
        }
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL && ((TLobby *)p)->check_player_flag1() != 0) {
            handle_battle_result__6TLobbyFii((u16)local_client_id, 1);
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 8;
    case 8:
        if (check_team_balance__6TLobbyFPvi((Lobby_801C484C *)((Lobby_801C484C *)arg0), 0) != 0) {
            send_battle_mode_params__6TLobbyFcii(5, 1, 0);
        } else {
            p = (void *)((u32 (*)(s32))get_player_by_client_id)(local_client_id);
            if (p != NULL && check_flag_100__10TObjPlayerFPv(p) == 0 && (G28 & 6)) {
                *(s32 *)((s8 *)arg0 + 0x20) = 6;
            }
        }
        break;
    case -1:
        if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x4C));
            *(void **)((s8 *)arg0 + 0x4C) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x50));
            *(void **)((s8 *)arg0 + 0x50) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x54) != NULL) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x54));
            *(void **)((s8 *)arg0 + 0x54) = NULL;
        }
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL) {
            obj_clear_flag30_20000(p);
        }
        TWindowCtrl::close_timer_window();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
        break;
    case 9:
        break;
    }
    if (*(s32 *)((s8 *)arg0 + 0x20) == 6 || *(s32 *)((s8 *)arg0 + 0x20) == 8) {
        p = (void *)update_battle_controller__10TObjPlayerFv();
        if (p != NULL && check_flag_100__10TObjPlayerFPv(p) == 0 && has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0 && (G28 & 0x400)) {
            if (*(void **)((s8 *)arg0 + 0x4C) != NULL) {
                TWindow__close(*(void **)((s8 *)arg0 + 0x4C));
                *(void **)((s8 *)arg0 + 0x4C) = NULL;
            }
            if (*(void **)((s8 *)arg0 + 0x50) != NULL) {
                TWindow__close(*(void **)((s8 *)arg0 + 0x50));
                *(void **)((s8 *)arg0 + 0x50) = NULL;
            }
            *(s32 *)((s8 *)arg0 + 0x20) = 4;
        }
    }
}
__declspec(section ".rodata") u8 lbl_80447008[] = "win.adx";
__declspec(section ".rodata") u8 lbl_80447010[] = "lose.adx";

void update_timed_wait__6TLobbyFPv(Lobby_801C484C *self) {
    s32 secs;
    s32 rem;
    switch (self->state) {
    case 0:
        ((TLobby *)self)->start_duel_battle();
        self->state = 1;
    case 1:
        if (check_team_balance__6TLobbyFPvi((Lobby_801C484C *)(self), 1) != 0) {
            send_battle_mode_params__6TLobbyFcii(5, 0, 0);
            return;
        }
        secs = (OSGetTime() - self->start) / (*(u32 *)0x800000F8 / 4);
        rem = self->limit - secs;
        self->remain = rem > 0 ? rem : 0;
        ((TWindowCtrl *)(self->remain))->set_timer_window_time();
        if (self->remain == 0) {
            self->result = 3;
            send_battle_mode_params__6TLobbyFcii(3, 0, 0);
            return;
        }
        if (check_battle_end__6TLobbyFv(self) != 0) {
            if (--self->timer48 <= 0) {
                self->result = 3;
                send_battle_mode_params__6TLobbyFcii(3, 0, 0);
            }
        } else {
            self->timer48 = 300;
        }
        ((TLobby *)self)->update_battle_sync(secs);
        if (--self->timer60 <= 0) {
            send_battle_mode_state__6TLobbyFPv(self);
            self->timer60 = 90;
        }
        calc_player_rankings__6TLobbyFPv((Lobby_801C484C *)(self));
        break;
    case -1:
        break;
    }
}
void update_battle_intro__6TLobbyFPv(Lobby_801C49B8 *self) {
    switch (self->state) {
    case 0:
        if (self->window == NULL) {
            Pair_801C49B8 p = lbl_80446F94[0];
            self->window = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x52), &p, 1);
        }
        lbl_805D5DA4 = 0;
        self->state = 1;
        break;
    case 1:
        ((TLobby *)(self->window))->send_and_handle((s32)self->msg, 0x80);
        self->timer = 0xF0;
        self->state = 2;
        break;
    case 2:
        if (--self->timer <= 0) {
            if (((TLobby *)((u8 *)&lobby_rule_settings))->get_rule_field_a() == 1) {
                self->state = 3;
            } else {
                self->state = 5;
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
            u8 *pl = (u8 *)((u32 (*)(s32))get_player_by_client_id)(i);
            if (pl != NULL) {
                s32 team = battle_intro_value_table[i] != 1 ? 1 : 0;
                if (cnt.v[team] < 2) {
                    strncpy(names[team * 2 + cnt.v[team]].s, (void *)((VObj_18_26c590 *)pl)->m10(), 0x10);
                    cnt.v[team]++;
                }
            }
        }
        sprintf(battle_intro_message_buffer, *(char **)(self->cfg + 0x18), names[0].s, names[1].s, names[2].s, names[3].s);
        ((TLobby *)(self->window))->send_and_handle((s32)battle_intro_message_buffer, 0x80);
        self->timer = 0xF0;
        self->state = 4;
        break;
    }
    case 4:
        if (--self->timer <= 0) {
            self->state = 5;
        }
        break;
    case 5:
        self->timer2 = 0x384;
        self->state = 6;
    case 6:
        self->timer2--;
        if (check_all_battle_flags__6TLobbyFv(self) != 0 || self->timer2 <= 0) {
            TWindow__close(self->window);
            self->window = NULL;
            TLobby__sub_801C2C34(self);
            self->timer2 = 0x1C2;
            self->state = 7;
        }
        break;
    case 7:
        self->timer2--;
        if (check_all_players_ready__6TLobbyFv(self) != 0 || self->timer2 <= 0) {
            void *o = (void *)__nw__7TObjectFUl(0x28);
            if (o != NULL) {
                __ct__15TDuelEffectCtrlFP7TObjectUc(o, self, 0);
            }
            self->timer = 0x96;
            self->state = 8;
        }
        break;
    case 8:
        if (--self->timer <= 0) {
            self->next = 2;
        }
        break;
    case -1:
        if (self->window != NULL) {
            TWindow__close(self->window);
            self->window = NULL;
        }
        clear_battle_player_ready_flags();
        break;
    }
}

}
}
#pragma pop

#pragma push
namespace P4_801C4CE0 {

extern "C" {
void TLobby__sub_801C38E8(void *arg0);
s32 TLobby__sub_801C3AF4(void *);
void end_battle_mode_cleanup__6TLobbyFPv(void *arg0);
s32 update_duel_result__6TLobbyFPv(void *);
s32 update_timed_wait__6TLobbyFPv(void *);
s32 update_battle_intro__6TLobbyFPv(void *);
void update_player_battle_ctrl_state(void *arg0);
s32 init_battle_round__17TPlayerBattleCtrlFv();
s32 fn_801C4CE0(TPlayerBattleCtrl *arg0);

s32 fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl) {
    switch (player_battle_ctrl->state_20) {
    case -1:
        break;
    case 0:
        init_battle_round__17TPlayerBattleCtrlFv();
        player_battle_ctrl->state_24 = 1;
        break;
    }
}

void update_player_battle_ctrl_state(void *arg0) {
    switch (((TPlayerBattleCtrl *)arg0)->state_1c) {
    case 0:
        fn_801C4CE0((TPlayerBattleCtrl *)arg0);
        return;
    case 1:
        update_battle_intro__6TLobbyFPv(arg0);
        return;
    case 2:
        update_timed_wait__6TLobbyFPv(arg0);
        return;
    case 3:
        update_duel_result__6TLobbyFPv(arg0);
        return;
    case 4:
        end_battle_mode_cleanup__6TLobbyFPv((arg0));
        return;
    case 5:
        TLobby__sub_801C3AF4(arg0);
        return;
    case 6:
        TLobby__sub_801C38E8((arg0));
    default:
        return;
    }
}

}

}
#pragma pop

extern "C" {
void update_player_battle_ctrl_state(void *arg0);
void TWindow__close(void *);
extern s32 lbl_805D55C0;
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

TPlayerBattleCtrl::~TPlayerBattleCtrl() {
    if (state_20 != -1) {
        state_20 = -1;
        update_player_battle_ctrl_state(this);
    }
    if (window_4c != NULL) TWindow__close(window_4c);
    if (window_50 != NULL) TWindow__close(window_50);
    if (window_54 != NULL) TWindow__close(window_54);
    TLobby__battle_mode_data_ptr = 0;
}
void *TPlayerBattleCtrl__ct(void *player_battle_ctrl, s32 _w1) {
    s32 temp_r3;
    __ct__7TObjectFP7TObject(player_battle_ctrl);
    *(u8 **)((s8 *)player_battle_ctrl + 0x18) = __vt__17TPlayerBattleCtrl;
    *(s32 *)((s8 *)player_battle_ctrl + 0) = (s32) TPlayerBattleCtrl__name;
    *(s32 *)((s8 *)player_battle_ctrl + 0x28) = 0;
    ((TPlayerBattleCtrl *)player_battle_ctrl)->state_24 = 0;
    ((TPlayerBattleCtrl *)player_battle_ctrl)->state_20 = 0;
    ((TPlayerBattleCtrl *)player_battle_ctrl)->state_1c = 0;
    *(s32 *)((s8 *)player_battle_ctrl + 0x4C) = 0;
    *(s32 *)((s8 *)player_battle_ctrl + 0x50) = 0;
    *(s32 *)((s8 *)player_battle_ctrl + 0x54) = 0;
    *(u8 **)((s8 *)player_battle_ctrl + 0x40) = (current_language == LANGUAGE_JAPANESE) ? player_battle_ctrl_text_japanese : player_battle_ctrl_text_english;
    temp_r3 = update_battle_controller__10TObjPlayerFv();
    if (temp_r3 != 0) {
        export_character_data__10TObjPlayerFPvPv(temp_r3, get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF));
    }
    TLobby::stop_audio_streams();
    *(s32 *)((s8 *)player_battle_ctrl + 0x64) = 0;
    return player_battle_ctrl;
}
