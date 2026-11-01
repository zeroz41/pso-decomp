#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCard_80244774.h"

#include "types.h"
#include "pso/ui/Language.h"

typedef void (TPlayerBattleCtrl4P::*BattleAction)();

struct BattleIntroWindowState {
    u8 pad[0x20];
    void *intro_window;
};

struct BattleIntroWindowSize { f32 x, y; };

extern "C" {
void *get_window_layout_position(s32);
void *create__14TWindowMessageFPvll(void *, void *, s32);
extern const BattleIntroWindowSize lbl_80475B60;
s32 lbl_805D6AB0;
void append_line__14TWindowMessageFii(void *, void *, int);
void *destroy__19TPlayerBattleCtrl4PFs(void *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
void run_task__19TPlayerBattleCtrl4PFv(TPlayerBattleCtrl4P *self);
extern s32 TPlayerBattleCtrl4P__instance;
extern u8 lbl_80475930[];
extern u8 lbl_8047595C[];
extern u8 lbl_80475964[];
extern u8 lbl_8047596C[];
extern u8 lbl_80475978[];
extern u8 lbl_804759E0[];
extern u8 lbl_80475A34[];
extern u8 lbl_80475A70[];
extern u8 lbl_80475A98[];
extern u8 lbl_80475AA0[];
extern u8 lbl_80475B18[];
extern u8 lbl_805DF228[];
extern u8 lbl_805DF22C[];
extern u8 lbl_805DF230[];
extern u8 lbl_805DF234[];
extern u8 lbl_805DF238[];
extern u8 lbl_805DF23C[];
void render__7TObjectFv();
void render_shadows__7TObjectFv();

void *TPlayerBattleCtrl4P__message_table_language0[7] = {
    (void *)&lbl_80475930, (void *)&lbl_8047595C, (void *)&lbl_80475964, (void *)&lbl_8047596C,
    (void *)&lbl_80475978, (void *)&lbl_804759E0, (void *)&lbl_80475A34,
};
void *lbl_804E7D4C[7] = {
    (void *)&lbl_80475A70, (void *)&lbl_805DF228, (void *)&lbl_805DF22C, (void *)&lbl_80475A98,
    (void *)&lbl_80475AA0, (void *)&lbl_80475AA0, (void *)&lbl_80475B18,
};

}
void TPlayerBattleCtrl4P::show_intro_text() {
    if (this->intro_window != NULL) {
        append_line__14TWindowMessageFii(this->intro_window, (void *)((char *)((void *)this) + 56), 128);
    }
    this->frame_timer = 240;
    set_score(2);
}

void TPlayerBattleCtrl4P::open_intro_window() {
    if (((BattleIntroWindowState *)this)->intro_window == NULL) {
        BattleIntroWindowSize size = lbl_80475B60;
        ((BattleIntroWindowState *)this)->intro_window = create__14TWindowMessageFPvll(
            get_window_layout_position(0x52), &size, 1);
    }
    lbl_805D6AB0 = 0;
    set_score(1);
}

#pragma defer_codegen on

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

#pragma defer_codegen off

void *TPlayerBattleCtrl4P_player_name_formats[4] = {
    (void *)&lbl_805DF230, (void *)&lbl_805DF234, (void *)&lbl_805DF238, (void *)&lbl_805DF23C,
};
void *__vt__19TPlayerBattleCtrl4P[6] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__19TPlayerBattleCtrl4PFs, (void *)&run_task__19TPlayerBattleCtrl4PFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};
#define __vt__19TPlayerBattleCtrl4P ((s32 *)__vt__19TPlayerBattleCtrl4P)
TPlayerBattleCtrl4P* TPlayerBattleCtrl4P::destroy(s16 should_free) {
    if (((void *)this) != NULL) {
        *(s32 **)((s8 *)((void *)this) + 0x18) = __vt__19TPlayerBattleCtrl4P;
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
extern "C" {

void *get_player_by_client_id(s32 i);
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 __ct__7TObjectFP7TObject(void *, void *);
void export_character_data__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
s32 clear_split_screen_battle_window_slots(void *);
extern s32 TPlayerBattleCtrl4P__name;

}
TPlayerBattleCtrl4P* TPlayerBattleCtrl4P::construct(TObject* parent) {
    s32 i;
    void **p;

    __ct__7TObjectFP7TObject(((void *)this), parent);
    *(void **)((s8 *)((void *)this) + 0x18) = __vt__19TPlayerBattleCtrl4P;
    *(s32 *)&this->m_name = TPlayerBattleCtrl4P__name;
    set_split_screen_battle_phase(0);
    this->intro_window = 0;
    this->menu_window = 0;
    clear_split_screen_battle_window_slots(((void *)this));
    p = lbl_804E7D4C;
    if (current_language == LANGUAGE_JAPANESE) {
        p = TPlayerBattleCtrl4P__message_table_language0;
    }
    *(void ** *)&this->message_table = p;
    for (i = 0; i < 4; i++) {
        s32 pl = (s32)get_player_by_client_id(i);
        if (pl != 0) {
            export_character_data__10TObjPlayerFPvPv((u8 *)pl, (u8 *)(get_char_index__23TAdSinglePlyChrSelectGCFUi((u32)i)));
        }
    }
    TPlayerBattleCtrl4P__instance = (s32)((void *)this);
    this->rule_data = 0;
    return this;
}
