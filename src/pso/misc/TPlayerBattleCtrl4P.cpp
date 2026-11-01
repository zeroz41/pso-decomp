#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TPlayerBattleCtrl4P_8031012C.h"
#include "pso/misc/TWindowSubComCard_80244774.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowCtrl.h"

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

struct O_8031224C { u8 pad[0x20]; s32 w0; u8 pad2[0x240 - 0x24]; s32 timer; u8 pad3[0x274 - 0x244]; s32 team[4]; u8 pad4[0x294 - 0x284]; Strs_8031224C *strs; };

extern "C" {
s64 OSGetTime(void);
s32 is_battle_decided__19TPlayerBattleCtrl4PFv(void *);
void *get_player_by_client_id(s32 i);
s32 append_line__14TWindowMessageFii(s32, void *, int);
int sprintf(char *, const char *, ...);
char *strncpy(char *, const char *, u32);
extern Cnt_8031224C lbl_80475B68[];
extern char team_matchup_message_buffer[];
void update__19TPlayerBattleCtrl4PFv(void *);
s32 __ct__15TDuelEffectCtrlFP7TObjectUc(void *, void *, s32);
void *__nw__7TObjectFUl(s32);
void set_frames__15ProtectionTimerFl(void *, s32);
s32 update_all_players__19TPlayerBattleCtrl4PFv();
s32 check_all_players_flag__19TPlayerBattleCtrl4PFv(void *);

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
void TPlayerBattleCtrl4P::start_battle() { start_duel(); set_score((s32)((void*)((void*)((void*)1)))); }
void TPlayerBattleCtrl4P::close_intro_and_start_battle() {
    void *temp_r3 = this->intro_window;
    if ((u32) temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        this->intro_window = 0U;
    }
    set_split_screen_battle_phase(2);
}
void TPlayerBattleCtrl4P::wait_for_start_countdown() {
    s32 temp_r0;

    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        set_score((s32)((void*)((void*)(8))));
    }
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

void TPlayerBattleCtrl4P::begin_ready_wait() {
    ready_timer = 0x384;
    set_score((s32)((void*)(6)));
}
void TPlayerBattleCtrl4P::wait_for_team_matchup() {
    s32 temp_r0;

    temp_r0 = frame_timer - 1;
    frame_timer = temp_r0;
    if (temp_r0 <= 0) {
        set_score((s32)((void*)(5)));
    }
}
extern s32 lobby_rule_settings[];

void TPlayerBattleCtrl4P::show_team_matchup() {
    Cnt_8031224C cnt = lbl_80475B68[0];
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
