#include "pso/system/TSetEvtDestroy.h"
#include "pso/item/TItem.h"
#include "types.h"
#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

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

struct RecoveredGlobal_80310300_TPlayerBattleCtrl4P__data_80542E90 {
    s32 value;
    u8 remaining[0x1C];
};

struct T_803102A4 { u8 pad[0x28]; s32 arr[4]; };

struct T_803102C8 { u8 pad[0x298]; s32 mode; };

struct Ctl_803101D4 { u8 pad[0x28]; void *win[4]; };

struct Ctl_80310230 { u8 pad[0x28]; void *win[4]; };

struct Ctl_8031012C { u8 pad[0x28]; void *win[4]; };

struct MapEnt_8031012C { u8 pad[0x20]; u8 sub[0x30]; };

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

extern RecoveredGlobal_80310300_TPlayerBattleCtrl4P__data_80542E90 split_screen_battle_rankings;
extern "C" {
s32 *get_split_screen_battle_rankings(void);
void clear_split_screen_battle_window_slots(T_803102A4 *self);
extern void *TPlayerBattleCtrl4P__instance;
void TWindow__close(u8 *arg0);
void *get_player_by_client_id(s32);
void *__nw__7TObjectFUl(u32);
void *TWindowDuelResult__ct(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 get_map_id__13TRaderMapCoreFv();
extern MapEnt_8031012C controller_input_state[];
u8 TLobby__sub_801D7100(void *);
extern u8 lobby_rule_settings[];
int sprintf(char *, const char *, ...);
s32 TLobby__sub_801C19D0(void *);
extern P_803109D4 lbl_80475B80[];
s32 are_split_screen_battle_players_tied(void);
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C();
void *get_character_save_record(u16);
void record_split_screen_battle_results(void);

int obj_getPtr2B0_20(u8 *p);
f32 fn_801C19A4(void *);
s32 TWindowDuelResult__sub_801C19AC(void *);

s32 calc_battle_score__19TPlayerBattleCtrl4PFPvPv(void *self, u8 *arg1);
void set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl(u8 *arg0, s32 arg1);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, int);
void queue_destruction__7TObjectFv(void *);
extern s32 lbl_805D2A98;
void destroy_matching_children__19TPlayerBattleCtrl4PFPvPv(void *self, Par_80311304 *p);
void TObjPlayer__send_selected_spawn_position(void *self, u16 id);
extern s32 tl_05;
s32 obj_set_flag_20000();
u64 OSGetTime();
void obj_clear_flag30_20000(void *arg0);
s32 init_with_name__6TLobbyFPvPvPvPv(void *, void *, void *, int);
s32 TObjEneRe4Sorcerer__sub_801E3F14(int);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
void send_code_45_to_window__19TPlayerBattleCtrl4PFPvii(void *arg0, s32 arg1, s32 arg2);
extern char lbl_80475BAC[];
extern char lbl_80475BB8[];
extern s32 TLobby__battle_ctrl_default_value;
s32 rand();
extern const f32 lbl_805DF240;
extern const f32 lbl_805DF244;

s32 fn_801C19D8(void *, int);
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
extern Team_801C343C lbl_80475B78[];
s32 calculate_split_screen_battle_rankings(void *);
void TLobby__sub_801B09A4(void);
void play_cue_stream_file(s32 name);
void show_duel_result_window(s32 arg0, s32 arg1);

void TLobby__sub_8020BB18(void);
void TLobby__sub_8020BCE4(void);
void end_player_keyboard_hold(s32 arg0);
void clear_trap_counts(s8 *arg0);
s32 destroy_children_with_tag(s32);

void begin_player_keyboard_hold(s32 arg0);
s32 obj_testFlags30__14TObjCollidableFUl(u32, s32);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 release_attached_resource__10TObjPlayerFv();
void request_active_window_close(void);
s32 send_code_45_1__10TObjPlayerFl();

typedef char RecoveredGlobal_80310300_TPlayerBattleCtrl4P__data_80542E90_size[sizeof(RecoveredGlobal_80310300_TPlayerBattleCtrl4P__data_80542E90) == 0x20 ? 1 : -1];

s32 TPlayerBattleCtrl4P::close_windows_on_button() {
    Ctl_8031012C *self = (Ctl_8031012C *)this;
    s32 r = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            if (self->win[i] != NULL) {
                if (TWindowShortListCtrl__check_controller_button(controller_input_state[get_map_id__13TRaderMapCoreFv()].sub, 2) != 0) {
                    TWindow__close((u8 *)self->win[i]);
                    self->win[i] = 0;
                } else {
                    r = 0;
                }
            }
        }
    }
    return r;
}

void TPlayerBattleCtrl4P::close_player_windows() {
    Ctl_803101D4 *o = (Ctl_803101D4 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (o->win[i] != 0) {
            TWindow__close((u8 *)o->win[i]);
            o->win[i] = 0;
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

void clear_split_screen_battle_window_slots(T_803102A4 *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

u8 TPlayerBattleCtrl4P::is_battle_mode_active() {
    T_803102C8 *p = (*(T_803102C8 * *)&TPlayerBattleCtrl4P__instance);
    if (p != 0) {
        return p->mode == 1 || p->mode == 2;
    }
    return 0;
}

s32 *get_split_screen_battle_rankings(void) {
    return &split_screen_battle_rankings.value;
}

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
}
extern char lbl_80475B90[];
extern char lbl_80475B98[];
extern char lbl_80475BA0[];
extern char *TPlayerBattleCtrl4P_player_name_formats[];
void request_split_screen_battle_event(void* p);
extern s16 battle_event_second_table[];
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
s32 get_split_screen_battle_timer_limit(u8 *arg0);
void reset_cameras_to_actor(void *actor, s32 arg1);
void refresh_split_screen_battle_alive_flags(void* p);
void refresh_split_screen_battle_alive_flags(void* p) { ((TPlayerBattleCtrl4P *)p)->update_player_alive_flags(); }

void TPlayerBattleCtrl4P::reset_ctrl_to_default() {
    void *temp_r3;
    temp_r3 = TPlayerBattleCtrl4P__instance;
    if (temp_r3 != NULL) {
        TPlayerBattleCtrl4P::init_ctrl_default(temp_r3);
    }
}

extern s32 TPlayerBattleCtrl4P__init_flag;

void TPlayerBattleCtrl4P::init() {
    TLobby__sub_801B09A4();
    advance_item_system_generation();
    TPlayerBattleCtrl4P__init_flag = 1;
}

int TPlayerBattleCtrl4P::init_ctrl_default(void* p) { return ((int (*)(void*, int))set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl)(p, 0); }
void TPlayerBattleCtrl4P::notify_lobby(void* p, void* a1, void* a2) { play_cue_stream_file((s32)a1); show_duel_result_window((s32)((void*)-50), (s32)a2); }
void TPlayerBattleCtrl4P::reset_score_counters() { this->timed_event_state = 0; *(s32 *)&this->unknown_290 = 0; }

void record_split_screen_battle_results(void) {
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

s32 TPlayerBattleCtrl4P::set_state() {
    this->timed_event_state = 2;
    return 1;
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

void request_split_screen_battle_event(void* p) { *(s32*)((char*)p + 0x260) = 1; }

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
u8 TPlayerBattleCtrl4P::is_battle_decided() {
    O_803109D4 *o = (O_803109D4 *)this;
    s32 count = 0;
    s32 i = 0;
    s32 ok;
    s32 team;
    u8 *p;
    P_803109D4 seen = lbl_80475B80[0];
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

#define get_player_by_client_id ((u32 (*)(s32))get_player_by_client_id)
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

#define TBL_801C343C ((Rank_801C343C *)&split_screen_battle_rankings)
#define PLAYER_801C343C(k) ((u32 (*)(s32))get_player_by_client_id)(k)
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
        Team_801C343C team = lbl_80475B78[0];
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

#pragma push
#pragma opt_lifetimes off
typedef struct Ctl_80310F10 Ctl_80310F10;
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
          fn_801C19D8((void *)(p + 0x828), o->team[(((((((((((j & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu]);
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

s32 get_split_screen_battle_timer_limit(u8 *arg0) {
    return *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x1C)) + 0x24) * 0x3C;
}

void TPlayerBattleCtrl4P::set_score(s32 v) { this->phase_state = v; }

void TPlayerBattleCtrl4P::set_split_screen_battle_phase(s32 arg1) {
    this->phase = arg1;
    this->phase_state = 0;
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

extern s32 tl_00;
extern s32 tl_01;

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
        a = (s32)(lbl_805DF240 * (lbl_805DF244 * (f32)rand()));
        b = (s32)(lbl_805DF240 * (lbl_805DF244 * (f32)rand()));
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
        TWindow__close((u8 *)this->intro_window);
        this->intro_window = NULL;
    }
    if (this->menu_window != NULL) {
        TWindow__close((u8 *)this->menu_window);
        this->menu_window = NULL;
    }
    close_player_windows();
    set_split_screen_battle_phase__19TPlayerBattleCtrl4PFl((u8 *)o, 5);
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
    queue_destroy_event_descendants((TObject*)tl_01);
    destroy_children_with_tag(tl_00);
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
    name = get_current_area() == 0x10 ? lbl_80475BAC : lbl_80475BB8;
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

#undef get_player_by_client_id
