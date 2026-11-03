#include "types.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/Boss6Type1Appearance.h"
#include "pso/boss/Boss6Type2Appearance.h"
#include "pso/boss/Boss6Type2Death.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss6Thanks.h"
#include "pso/boss/TBoss6EmptyWarp.h"
#include "pso/object/TObjOnlineEnding.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/misc/TLobby.h"
#include "pso/system/SoundEffect.h"

// The Falz plot script: one {name, enter, idle, update, advance} entry per
// plot state, run by TBoss6PlotFalz::run_phase_action. Built with deferred
// code generation, so the actions below are written in table order and come
// out in reverse.

extern "C" {
void end_cutscene_camera__14TBoss6PlotFalzFPv(void);
void refresh_players_equipment__14TBoss6PlotFalzFPv(void);
int is_ready__14TBoss6PlotFalzFv(void *);
s32 is_ending_or_split_screen__14TBoss6PlotFalzFv(void *);
s32 destroy_static_instance__14TBoss6PlotFalzFv(void *);
s32 queue_instance_destruction__14TBoss6PlotFalzFv(void *);
s32 obj_setArrS16_FC(void *, int, void *);
s32 alloc__8TObjFishFPv(void *);
}

extern u32 TBoss6PlotFalz__type2_instance;

// --- FALL_ELEV ---
void TBoss6PlotFalz::sub_802B0A34() { *(s32*)((char*)this + 0x3d0) = 0; *(s32*)((char*)this + 0x3cc) = 0; }
void TBoss6PlotFalz::advance_if_ready() { if (is_ready__14TBoss6PlotFalzFv(this) != 0) { send_6xA3_action((s8)((void*)2)); } }
void TBoss6PlotFalz::advance_intro_timer() {
    if ((s32) *(s32 *)((s8 *)this + 0x3CC) == 0x69) {
        play_sound_effect(0x40030F00, 0, 0, 0);
    }
    *(s32 *)((s8 *)this + 0x3CC) = (s32) (*(s32 *)((s8 *)this + 0x3CC) + 1);
    if ((s32) *(s32 *)((s8 *)this + 0x3CC) > 0x12C) {
        set_state(1);
    }
}

// --- DEMO_START ---
void TBoss6PlotFalz::init_proto1_adx() {
    play_area_music("proto1.adx");
    TBoss6PlotFalz::freeze_all_players();
    *(s32 *)((s8 *)this + 0x3D0) = 0;
    *(s32 *)((s8 *)this + 0x3CC) = 0;
    TBoss4DarkFalz::dispatch_by_main_phase(0x56);
    TBoss6Demo10_TYPE1_APPEAR__create(this);
}
void TBoss6PlotFalz::sub_802B08F0() { if (is_ready__14TBoss6PlotFalzFv(this) != 0) { send_6xA3_action((s8)((void*)2)); } }
void TBoss6PlotFalz::tick_timeout() {
    s32 temp_r0;

    refresh_players_equipment__14TBoss6PlotFalzFPv();
    temp_r0 = *(s32 *)((s8 *)this + 0x3CC) + 1;
    *(s32 *)((s8 *)this + 0x3CC) = temp_r0;
    if (temp_r0 > 0x1F4) {
        set_state(2);
    }
}

// --- VS_TYPE1 ---
void TBoss6PlotFalz::enter_active_state() { end_cutscene_camera__14TBoss6PlotFalzFPv(); refresh_players_equipment__14TBoss6PlotFalzFPv(); *(int*)((char*)this + 0x3d0) = 1; *(int*)((char*)this + 0x3cc) = 0; spawn_type1(); }
void TBoss6PlotFalz::update_phase() {
    if ((TBoss6PlotFalz__sub_802ABADC() == 0) || (is_ready__14TBoss6PlotFalzFv(this) != 0)) {
        send_6xA3_action((s8)((void*)(3)));
    }
}
void TBoss6PlotFalz::sub_802B0808() {  }

// --- DEMO_DED_T1 ---
void TBoss6PlotFalz::reset_and_recreate() {
    s32 sp8;
    TBoss6PlotFalz::get_target_pos_b((s32)this, (s32)((void *)&sp8));
    queue_instance_destruction__14TBoss6PlotFalzFv(this);
    TLobby::stop_audio_streams();
    TBoss6PlotFalz::freeze_all_players();
    *(s32 *)((s8 *)this + 0x3D0) = 0;
    *(s32 *)((s8 *)this + 0x3CC) = 0;
    TBoss6PlotFalz::create(this, &sp8);
}
void TBoss6PlotFalz::set_state4_if_ready() { if (is_ready__14TBoss6PlotFalzFv(this) != 0) { send_6xA3_action((s8)((void*)4)); } }
void TBoss6PlotFalz::sub_802B06D0() {
    f32 f;
    refresh_players_equipment__14TBoss6PlotFalzFPv();
    if (*(s32 *)((s8 *)this + 0x3CC) > 0xF7) {
        f = (f32)(*(s32 *)((s8 *)this + 0x3CC) - 0xF7) / 8.0f;
        if (f > 1.0f) {
            f = 1.0f;
        }
        apply_fade_alpha(0, f);
    }
    if (++*(s32 *)((s8 *)this + 0x3CC) > 0x101) {
        set_state(4);
    }
}

// --- DEMO_WAIT_T2 ---
void TBoss6PlotFalz::init_hall_boss_scene() {
    TBoss6EmptyWarp::init_warp();
    release_object();
    play_area_music("HALL.adx");
    refresh_players_equipment__14TBoss6PlotFalzFPv();
    *(s32 *)((s8 *)this + 0x3CC) = 0;
    *(s32 *)((s8 *)this + 0x3DC) = alloc__8TObjFishFPv(this);
}
void TBoss6PlotFalz::check_and_advance_state() {
    void *player = *(void **)((s8 *)this + 0x3DC);
    if ((player != NULL) && ((((TObjPlayer *)player)->get_plot_state() != 0) || (is_ready__14TBoss6PlotFalzFv(this) != 0))) {
        send_6xA3_action((s8)((void *)5));
    }
}
void TBoss6PlotFalz::update_cutscene_fade() {
    s32 t = *(s32 *)((s8 *)this + 0x3CC);
    if (t <= 0x2D) {
        apply_fade_alpha(0, 1.0f);
    } else if (t > 0x2D && t < 0x10E) {
        apply_fade_alpha(0, (f32)(0x10E - t) / 225.0f);
    }
    if (*(s32 *)((s8 *)this + 0x3CC) == 0x2D) {
        end_cutscene_camera__14TBoss6PlotFalzFPv();
    }
    *(s32 *)((s8 *)this + 0x3CC) = *(s32 *)((s8 *)this + 0x3CC) + 1;
}

// --- DEMO_APP_T2 ---
void TBoss6PlotFalz::stop_adx_audio() {
    if ((u32) *(u32 *)((s8 *)this + 0x3DC) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3DC));
    }
    *(u32 *)((s8 *)this + 0x3DC) = 0U;
    TBoss6PlotFalz::freeze_all_players();
    TLobby::stop_audio_streams();
    play_area_music("proto2.adx");
    *(s32 *)((s8 *)this + 0x3CC) = 0;
    create_boss6_type2_appearance(this);
}
void TBoss6PlotFalz::advance_phase_if_ready() { if (is_ready__14TBoss6PlotFalzFv(this) != 0) { this->send_6xA3_action((s8)((void*)6)); } }
void TBoss6PlotFalz::advance_timer() {
    s32 temp_r0;

    refresh_players_equipment__14TBoss6PlotFalzFPv();
    temp_r0 = *(s32 *)((s8 *)this + 0x3CC) + 1;
    *(s32 *)((s8 *)this + 0x3CC) = temp_r0;
    if (temp_r0 > 0x198) {
        this->set_state(6);
    }
}

// --- VS_TYPE2 ---
void TBoss6PlotFalz::sub_802B0448() { end_cutscene_camera__14TBoss6PlotFalzFPv(); refresh_players_equipment__14TBoss6PlotFalzFPv(); *(int*)((char*)this + 0x3d0) = 0; *(int*)((char*)this + 0x3cc) = 0; spawn_type2(); }
void TBoss6PlotFalz::check_action_7() {
    if ((TBoss6PlotFalz::is_boss_active() == 0) || (is_ready__14TBoss6PlotFalzFv(this) != 0)) {
        send_6xA3_action((s8)((void*)(7)));
    }
}
void TBoss6PlotFalz::sub_802B03F4() {  }

// --- DEMO_END ---
void TBoss6PlotFalz::finish_and_dispatch_next_phase() {
    s32 sp10[2];
    u16 out[4];
    s32 i;

    if ((u32) TBoss6PlotFalz__type2_instance != 0U) {
        ((TBoss6Type2 *)TBoss6PlotFalz__type2_instance)->get_phase_values((u16 *)(((u8 *)this) + 0x2D6), (u16 *)(((u8 *)this) + 0x2D4), (u16 *)out);
        i = 0;
        do {
            obj_setArrS16_FC(this, (int)i, (void *)out[i]);
            i += 1;
        } while (i < 4);
    }
    TBoss6PlotFalz::get_target_pos_a((s32)this, (s32)sp10);
    destroy_static_instance__14TBoss6PlotFalzFv(this);
    TLobby::stop_audio_streams();
    TBoss6PlotFalz::freeze_all_players();
    *(s32 *)((s8 *)((u8 *)this) + 0x3D0) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = 0;
    TBoss4DarkFalz::dispatch_by_main_phase(0x57);
    TBoss6Thanks::try_dispatch_darkfalz_phase();
    create_boss6_type2_death((this), (sp10));
}
void TBoss6PlotFalz::update_plot_timer() {
    s32 temp_r0;

    refresh_players_equipment__14TBoss6PlotFalzFPv();
    if (((s32) *(s32 *)((s8 *)this + 0x3CC) > 1) && (is_ready__14TBoss6PlotFalzFv(this) != 0)) {
        *(s32 *)((s8 *)this + 0x3CC) = 0x2CA;
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x3CC) + 1;
    *(s32 *)((s8 *)this + 0x3CC) = temp_r0;
    if (temp_r0 > 0x2CA) {
        if (is_ending_or_split_screen__14TBoss6PlotFalzFv(this) != 0) {
            set_state(8);
            return;
        }
        end_cutscene_camera__14TBoss6PlotFalzFPv();
        award_exp_and_destroy();
    }
}

// --- OL_ENDING ---
void TBoss6PlotFalz::reset_ending_state() { TBoss6PlotFalz::freeze_all_players(); *(int*)((char*)this + 0x3d0) = 0; *(int*)((char*)this + 0x3cc) = 0; TObjOnlineEnding::create(this); }
void TBoss6PlotFalz::sub_802B0228() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x3CC) + 1;
    *(s32 *)((s8 *)this + 0x3CC) = temp_r0;
    if (temp_r0 > 0x1C6) {
        end_cutscene_camera__14TBoss6PlotFalzFPv();
        award_exp_and_destroy();
    }
}

typedef void (TBoss6PlotFalz::*TBoss6PlotFalzAction)();

struct TBoss6PlotFalzScriptState {
    const char* name;
    TBoss6PlotFalzAction action_enter;
    TBoss6PlotFalzAction action_idle;
    TBoss6PlotFalzAction action_update;
    TBoss6PlotFalzAction action_advance;
};

TBoss6PlotFalzScriptState TBoss6PlotFalz__data_804DE66C[9] = {
    { "FALL_ELEV", &TBoss6PlotFalz::sub_802B0A34, 0,
      &TBoss6PlotFalz::advance_if_ready, &TBoss6PlotFalz::advance_intro_timer },
    { "DEMO_START", &TBoss6PlotFalz::init_proto1_adx, 0,
      &TBoss6PlotFalz::sub_802B08F0, &TBoss6PlotFalz::tick_timeout },
    { "VS_TYPE1", &TBoss6PlotFalz::enter_active_state, 0,
      &TBoss6PlotFalz::update_phase, &TBoss6PlotFalz::sub_802B0808 },
    { "DEMO_DED_T1", &TBoss6PlotFalz::reset_and_recreate, 0,
      &TBoss6PlotFalz::set_state4_if_ready, &TBoss6PlotFalz::sub_802B06D0 },
    { "DEMO_WAIT_T2", &TBoss6PlotFalz::init_hall_boss_scene, 0,
      &TBoss6PlotFalz::check_and_advance_state, &TBoss6PlotFalz::update_cutscene_fade },
    { "DEMO_APP_T2", &TBoss6PlotFalz::stop_adx_audio, 0,
      &TBoss6PlotFalz::advance_phase_if_ready, &TBoss6PlotFalz::advance_timer },
    { "VS_TYPE2", &TBoss6PlotFalz::sub_802B0448, 0,
      &TBoss6PlotFalz::check_action_7, &TBoss6PlotFalz::sub_802B03F4 },
    { "DEMO_END", &TBoss6PlotFalz::finish_and_dispatch_next_phase, 0, 0,
      &TBoss6PlotFalz::update_plot_timer },
    { "OL_ENDING", &TBoss6PlotFalz::reset_ending_state, 0, 0,
      &TBoss6PlotFalz::sub_802B0228 },
};
