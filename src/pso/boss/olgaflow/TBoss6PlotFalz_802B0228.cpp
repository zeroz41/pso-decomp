#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/olgaflow/TBoss6Demo10_TYPE1_APPEAR.h"
#include "pso/boss/olgaflow/TBoss6Demo11_TYPE1_DEAD.h"
#include "pso/boss/olgaflow/TBoss6Demo20_TYPE2_APPEAR.h"
#include "pso/boss/olgaflow/TBoss6Demo21_TYPE2_DEAD.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6PlotFalzState.h"
#include "pso/boss/olgaflow/Boss6Type2Appearance.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/olgaflow/TBoss6Thanks.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"

// The Falz plot script: one {name, enter, idle, update, advance} entry per
// plot state, run by TBoss6PlotFalz::run_phase_action. Built with deferred
// code generation, so the actions below are written in table order and come
// out in reverse.



// --- FALL_ELEV ---
void TBoss6PlotFalz::enter_fall_elev() { shake_active = 0; state_timer = 0; }
void TBoss6PlotFalz::advance_if_ready() { if (is_ready() != 0) { send_6xA3_action(2); } }
void TBoss6PlotFalz::advance_intro_timer() {
    if (state_timer == 0x69) {
        play_sound_effect(0x40030F00, 0, 0, 0);
    }
    state_timer = state_timer + 1;
    if (state_timer > 0x12C) {
        set_state(1);
    }
}

// --- DEMO_START ---
void TBoss6PlotFalz::init_proto1_adx() {
    play_area_music("proto1.adx");
    TBoss6PlotFalz::freeze_all_players();
    shake_active = 0;
    state_timer = 0;
    set_story_flag_or_send_quest_flag(0x56);
    TBoss6Demo10_TYPE1_APPEAR::create(this);
}
void TBoss6PlotFalz::tick_demo_start() { if (is_ready() != 0) { send_6xA3_action(2); } }
void TBoss6PlotFalz::tick_timeout() {
    TBoss6PlotFalz::refresh_players_equipment();
    if (++state_timer > 0x1F4) {
        set_state(2);
    }
}

// --- VS_TYPE1 ---
void TBoss6PlotFalz::enter_active_state() {
    TBoss6PlotFalz::end_cutscene_camera();
    TBoss6PlotFalz::refresh_players_equipment();
    shake_active = 1;
    state_timer = 0;
    spawn_type1();
}
void TBoss6PlotFalz::update_phase() {
    if ((TBoss6PlotFalz::is_type1_active() == 0) || (is_ready() != 0)) {
        send_6xA3_action(3);
    }
}
void TBoss6PlotFalz::update_vs_type1() {  }

// --- DEMO_DED_T1 ---
void TBoss6PlotFalz::reset_and_recreate() {
    Vec target;
    get_target_pos_b(&target);
    TBoss6PlotFalz::queue_instance_destruction();
    TLobby::stop_audio_streams();
    TBoss6PlotFalz::freeze_all_players();
    shake_active = 0;
    state_timer = 0;
    TBoss6Demo11_TYPE1_DEAD::create(this, &target);
}
void TBoss6PlotFalz::set_state4_if_ready() { if (is_ready() != 0) { send_6xA3_action(4); } }
void TBoss6PlotFalz::update_demo_ded_t1() {
    f32 f;
    TBoss6PlotFalz::refresh_players_equipment();
    if (state_timer > 0xF7) {
        f = (f32)(state_timer - 0xF7) / 8.0f;
        if (f > 1.0f) {
            f = 1.0f;
        }
        apply_fade_alpha(0, f);
    }
    if (++state_timer > 0x101) {
        set_state(4);
    }
}

// --- DEMO_WAIT_T2 ---
void TBoss6PlotFalz::init_hall_boss_scene() {
    TBoss6EmptyWarp::init_warp();
    release_object();
    play_area_music("HALL.adx");
    refresh_players_equipment();
    state_timer = 0;
    wait_demo = TBoss6Demo15_TYPE2_WAIT::alloc(this);
}
void TBoss6PlotFalz::check_and_advance_state() {
    TBoss6Demo15_TYPE2_WAIT *wait = wait_demo;
    if ((wait != NULL) && ((wait->get_plot_state() != 0) || (is_ready() != 0))) {
        send_6xA3_action(5);
    }
}
void TBoss6PlotFalz::update_cutscene_fade() {
    s32 t = state_timer;
    if (t <= 0x2D) {
        apply_fade_alpha(0, 1.0f);
    } else if (t > 0x2D && t < 0x10E) {
        apply_fade_alpha(0, (f32)(0x10E - t) / 225.0f);
    }
    if (state_timer == 0x2D) {
        TBoss6PlotFalz::end_cutscene_camera();
    }
    state_timer = state_timer + 1;
}

// --- DEMO_APP_T2 ---
void TBoss6PlotFalz::stop_adx_audio() {
    if (wait_demo != NULL) {
        wait_demo->queue_destruction();
    }
    wait_demo = NULL;
    TBoss6PlotFalz::freeze_all_players();
    TLobby::stop_audio_streams();
    play_area_music("proto2.adx");
    state_timer = 0;
    TBoss6Demo20_TYPE2_APPEAR::create(this);
}
void TBoss6PlotFalz::advance_phase_if_ready() { if (is_ready() != 0) { this->send_6xA3_action(6); } }
void TBoss6PlotFalz::advance_timer() {
    TBoss6PlotFalz::refresh_players_equipment();
    if (++state_timer > 0x198) {
        this->set_state(6);
    }
}

// --- VS_TYPE2 ---
void TBoss6PlotFalz::enter_vs_type2() {
    TBoss6PlotFalz::end_cutscene_camera();
    TBoss6PlotFalz::refresh_players_equipment();
    shake_active = 0;
    state_timer = 0;
    spawn_type2();
}
void TBoss6PlotFalz::check_action_7() {
    if ((TBoss6PlotFalz::is_boss_active() == 0) || (is_ready() != 0)) {
        send_6xA3_action(7);
    }
}
void TBoss6PlotFalz::update_vs_type2() {  }

// --- DEMO_END ---
void TBoss6PlotFalz::finish_and_dispatch_next_phase() {
    Vec target;
    u16 out[4];
    s32 i;

    if (TBoss6PlotFalz__type2_instance != NULL) {
        TBoss6PlotFalz__type2_instance->get_phase_values(&local_attacker_id, &attacker_id, out);
        i = 0;
        do {
            obj_setArrS16_FC(this, i, out[i]);
            i += 1;
        } while (i < 4);
    }
    get_target_pos_a(&target);
    TBoss6PlotFalz::destroy_static_instance();
    TLobby::stop_audio_streams();
    TBoss6PlotFalz::freeze_all_players();
    shake_active = 0;
    state_timer = 0;
    set_story_flag_or_send_quest_flag(0x57);
    TBoss6Thanks::try_dispatch_darkfalz_phase();
    TBoss6Demo21_TYPE2_DEAD::create(this, &target);
}
void TBoss6PlotFalz::update_plot_timer() {
    refresh_players_equipment();
    if ((state_timer > 1) && (is_ready() != 0)) {
        state_timer = 0x2CA;
    }
    if (++state_timer > 0x2CA) {
        if (is_ending_or_split_screen() != 0) {
            set_state(8);
            return;
        }
        TBoss6PlotFalz::end_cutscene_camera();
        award_exp_and_destroy();
    }
}

// --- OL_ENDING ---
void TBoss6PlotFalz::reset_ending_state() {
    TBoss6PlotFalz::freeze_all_players();
    shake_active = 0;
    state_timer = 0;
    TObjOnlineEnding::create(this);
}
void TBoss6PlotFalz::update_ol_ending() {
    if (++state_timer > 0x1C6) {
        TBoss6PlotFalz::end_cutscene_camera();
        award_exp_and_destroy();
    }
}

TBoss6PlotFalzScriptState boss6_plot_falz_script_states[9] = {
    { "FALL_ELEV", &TBoss6PlotFalz::enter_fall_elev, 0,
      &TBoss6PlotFalz::advance_if_ready, &TBoss6PlotFalz::advance_intro_timer },
    { "DEMO_START", &TBoss6PlotFalz::init_proto1_adx, 0,
      &TBoss6PlotFalz::tick_demo_start, &TBoss6PlotFalz::tick_timeout },
    { "VS_TYPE1", &TBoss6PlotFalz::enter_active_state, 0,
      &TBoss6PlotFalz::update_phase, &TBoss6PlotFalz::update_vs_type1 },
    { "DEMO_DED_T1", &TBoss6PlotFalz::reset_and_recreate, 0,
      &TBoss6PlotFalz::set_state4_if_ready, &TBoss6PlotFalz::update_demo_ded_t1 },
    { "DEMO_WAIT_T2", &TBoss6PlotFalz::init_hall_boss_scene, 0,
      &TBoss6PlotFalz::check_and_advance_state, &TBoss6PlotFalz::update_cutscene_fade },
    { "DEMO_APP_T2", &TBoss6PlotFalz::stop_adx_audio, 0,
      &TBoss6PlotFalz::advance_phase_if_ready, &TBoss6PlotFalz::advance_timer },
    { "VS_TYPE2", &TBoss6PlotFalz::enter_vs_type2, 0,
      &TBoss6PlotFalz::check_action_7, &TBoss6PlotFalz::update_vs_type2 },
    { "DEMO_END", &TBoss6PlotFalz::finish_and_dispatch_next_phase, 0, 0,
      &TBoss6PlotFalz::update_plot_timer },
    { "OL_ENDING", &TBoss6PlotFalz::reset_ending_state, 0, 0,
      &TBoss6PlotFalz::update_ol_ending },
};
