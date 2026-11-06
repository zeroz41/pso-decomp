#pragma readonly_strings on
#include "types.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/boss/TBoss6Type1_802B20C0.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6Type1.h"
#include "pso/boss/TBoss6PlotFalz.h"

struct TBoss6Type1Action {
    const char *name;
    s32 anim;
    s32 param;
    void (TBoss6Type1::*act)();
    void (TBoss6Type1::*idle)();
    void (TBoss6Type1::*update)();
};

TBoss6Type1Action boss6_type1_action_table[41] = {
    { "APPEAR", 2, 1, &TBoss6Type1::init_effect_slot_1, 0, &TBoss6Type1::sub_802B3B94 },
    { "RND_FLOAT", 2, 1, &TBoss6Type1::init_attack_timers, &TBoss6Type1::choose_next_action, &TBoss6Type1::tick_countdown },
    { "RND_MOVE", 2, 1, &TBoss6Type1::start_attack, 0, &TBoss6Type1::update_attack_countdown_reset },
    { "KAKUSAN", 11, 1, &TBoss6Type1::init_state_90, 0, &TBoss6Type1::sub_802B381C },
    { "KAKUSAN_MV", 11, 1, &TBoss6Type1::init_hp_state, 0, &TBoss6Type1::update_action_timer },
    { "SWORD", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD2", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD3", 13, 1, &TBoss6Type1::set_phase_timer_3E, 0, &TBoss6Type1::update_timer_state },
    { "SWORD_MV", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::sub_802B3564 },
    { "SWORD_MV2", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::sub_802B3564 },
    { "SWORD_MV3", 13, 1, &TBoss6Type1::init_attack_timer, 0, &TBoss6Type1::sub_802B3564 },
    { "SWORD_U", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_U2", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_U3", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_U4", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_U5", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_D", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_D2", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_D3", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_D4", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "SWORD_D5", 12, 0, &TBoss6Type1::init_action_timer, 0, &TBoss6Type1::sub_802B343C },
    { "TAILATK_MV", 14, 1, &TBoss6Type1::init_dice_state, 0, &TBoss6Type1::update_attack_timer2 },
    { "FLLSR_MV", 15, 1, &TBoss6Type1::sub_802B3320, 0, &TBoss6Type1::sub_802B31E4 },
    { "SCREAM", 20, 0, &TBoss6Type1::sub_802B3178, 0, &TBoss6Type1::update_timer },
    { "CHAL_UD", 0, 1, &TBoss6Type1::set_phase_90, &TBoss6Type1::start_action_if_idle, &TBoss6Type1::update_charge },
    { "CHAL_FLOAT", 0, 1, &TBoss6Type1::init_hp_and_state, &TBoss6Type1::sub_802B2F00, &TBoss6Type1::tick_trap_countdown },
    { "GOTO_CENTOP", 3, 0, &TBoss6Type1::init_state, 0, &TBoss6Type1::update_timer_transition },
    { "CENTOP_D", 0, 0, &TBoss6Type1::sub_802B2D68, 0, &TBoss6Type1::tick_flee_countdown },
    { "CENTOP_U", 0, 0, &TBoss6Type1::sub_802B2CB4, &TBoss6Type1::trigger_falz_phase, &TBoss6Type1::update_phase },
    { "DOWN_CENTOP", 5, 0, &TBoss6Type1::init_params, 0, &TBoss6Type1::sub_802B2A94 },
    { "LAND_CENTOP", 8, 2, &TBoss6Type1::advance_plot_to_state2, &TBoss6Type1::update_attack_state, &TBoss6Type1::update_hit_timer },
    { "BOMB_CENTOP", 8, 2, &TBoss6Type1::init_move_attack, 0, &TBoss6Type1::tick_state_410_timer },
    { "TKOF_CENTOP", 9, 0, &TBoss6Type1::enter_release_state, &TBoss6Type1::update_if_idle, &TBoss6Type1::sub_802B2724 },
    { "RET_RND_UD", 2, 0, &TBoss6Type1::init_charge, 0, &TBoss6Type1::tick_attack_sequence },
    { "GOTO_CENBTM", 2, 0, &TBoss6Type1::init_work, 0, &TBoss6Type1::update_attack_timer },
    { "CENBTM_D", 2, 0, &TBoss6Type1::sub_802B24B4, 0, &TBoss6Type1::sub_802B245C },
    { "CENBTM_U", 2, 0, &TBoss6Type1::reset_effects, &TBoss6Type1::update_state, &TBoss6Type1::update_countdown },
    { "PUT_MINE", 2, 0, &TBoss6Type1::set_phase_555, &TBoss6Type1::update_if_ready, &TBoss6Type1::update_countdown_state },
    { "RET_RND_DU", 2, 0, &TBoss6Type1::init_charge_attack, 0, &TBoss6Type1::update_attack_countdown },
    { "WAITNEXT", -1, 0, 0, &TBoss6Type1::enter_flag800_state, 0 },
    { "DEAD", -1, 0, 0, 0, 0 },
};

static const Vec centop_pos = {0.0f, 275.0f, 0.0f};
static const Vec centop_down_pos = {0.0f, 225.0f, 0.0f};
static const Vec down_centop_pos = {0.0f, 144.0f, 0.0f};
static const Vec down_centop_land_pos = {0.0f, 64.0f, 0.0f};
static const Vec cenbtm_pos = {0.0f, -145.0f, 0.0f};
static const Vec cenbtm_down_pos = {0.0f, -180.0f, 0.0f};
static Vec tkof_centop_low_pos = {0.0f, 114.0f, 0.0f};
static Vec tkof_centop_high_pos = {0.0f, 264.0f, 0.0f};

extern "C" {















struct RecoveredGlobal_802B3BEC_lbl_80470CE0 {
    s32 value;
    u8 remaining[0x8];
};





typedef char RecoveredGlobal_802B3BEC_lbl_80470CE0_size[sizeof(RecoveredGlobal_802B3BEC_lbl_80470CE0) == 0xC ? 1 : -1];

s32 play_sound_effect(s32, void *, s32, s32);
s32 is_normal_difficulty();
s32 TBoss6Type1__sub_802B4A9C(void *);
void TBoss6Type1__sub_802B4B04(u8 *arg0);
void TBoss6Type1__sub_802B5140(s32 arg0, s32 arg1, s32 arg2);
int clamp_to_arena_radius__11TBoss6Type1FPvPvf(void*, void*);
void TBoss6Type1__sub_802B5598(void *arg0, void *arg1);
s32 calc_grid_cell_position__11TBoss6Type1FPvPv(void *, void *);
s32 is_timer_expired__11TBoss6Type1Fv();
s32 is_field4b0_delta_reached__11TBoss6Type1Fv();
s32 TBoss6Type1__sub_802B6060(u8 *arg0);
int TBoss6Type1__sub_802B6504(void*);
s32 TBoss6Type1__sub_802B6944(void *);
s32 damage_players_in_range__11TBoss6Type1Fv();
s32 TBoss6Type1__sub_802B6C30(void *);
s32 TBoss6Type1__sub_802B73AC();
s32 update_beam_attack__11TBoss6Type1Fv();
s32 TBoss6Type1__sub_802B8A70(void *);
void TBoss6Type1__sub_802B8BB4(u8 *arg0);
int TBoss6Type1__sub_802B8E1C(void*);
int send_flow_action_if_idle__11TBoss6Type1FPvc(void*, void*);
s32 rand(void);

extern RecoveredGlobal_802B3BEC_lbl_80470CE0 lbl_80470CE0;

void TBoss6Type1::enter_flag800_state() {
    if (this->actorFlags & 0x800) {
        send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)(0x28));
        return;
    }
    send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)(1));
}

void TBoss6Type1::update_attack_countdown() {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 temp_r3b;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    ease_toward_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r3 = this->m_40c - 2;
    temp_r0 = *(s32 *)((s8 *)this + 0x410);
    temp_r3b = temp_r3 - 0xA;
    if (temp_r0 == temp_r3) {
        set_motion_set(6);
    } else if (temp_r0 == temp_r3b) {
        this->m_438 = 1;
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        latch_phase_counter();
        this->m_414 = 0;
        set_action_state(1);
    }
}

void TBoss6Type1::init_charge_attack() {
    this->m_40c = 0x3C;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0x3C;
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x4003A811), (void*)(((u8 *)this) + 0x38), (void*)(0), (void*)(1));
    this->release_effect_slot((s32)((void*)(0)));
    this->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::update_countdown_state() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x410) == (s32) ((f32) *(s32 *)((s8 *)arg0 + 0x40C) - 30.0f)) {
        ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(3)));
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x410) - 1;
    *(s32 *)((s8 *)arg0 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss6Type1 *)arg0)->set_action_state(0x27);
    }
}

void TBoss6Type1::update_if_ready() {
    if (((s32) *(s32 *)((s8 *)this + 0x410) == 0) || (is_timer_expired__11TBoss6Type1Fv() != 0)) {
        TBoss6Type1__sub_802B8E1C(this);
    }
}

void TBoss6Type1::set_phase_555() { this->m_40c = 555; *(int*)((char*)this + 0x410) = 555; TBoss6Type1__sub_802B6504(this); release_effect_slot((s32)((void*)((void*)0))); release_effect_slot((s32)((void*)((void*)1))); spawn_effect_slot((s32)((void*)((void*)3))); }

void TBoss6Type1::update_countdown() {
    s32 temp_r0;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::update_state() {
    if ((s32) *(s32 *)((s8 *)this + 0x410) == 0) {
        if (is_normal_difficulty() != 0) {
            TBoss6Type1__sub_802B8E1C(this);
            return;
        }
        if (is_field3F8_over_0x20() != 0) {
            send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)(0x25));
            return;
        }
        TBoss6Type1__sub_802B8E1C(this);
    }
}

void TBoss6Type1::reset_effects() {
    this->m_40c = 0x1E;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0x1E;
    VecCopy((Vec *)(((u8 *)this) + 0x420), &cenbtm_pos);
    this->release_effect_slot((s32)((void*)(0)));
    this->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::sub_802B245C() {
    TBoss6Type1 *boss6_type1 = this;
    s32 temp_r0;

    boss6_type1->interpolate_pos_to_target(*(s32 *)((s8 *)boss6_type1 + 0x410), boss6_type1->m_40c);
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        boss6_type1->set_action_state((int)(0x14 - (boss6_type1->m_41c & 1)));
    }
}

void TBoss6Type1::sub_802B24B4() {
    TBoss6Type1 *boss6_type1 = this;
    boss6_type1->m_40c = 0x1E;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = 0x1E;
    VecCopy((Vec *)((u8 *)boss6_type1 + 0x420), &cenbtm_down_pos);
    boss6_type1->release_effect_slot((s32)((void*)(0)));
    boss6_type1->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::update_attack_timer() {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 temp_r3b;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    ease_toward_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r3 = this->m_40c - 2;
    temp_r0 = *(s32 *)((s8 *)this + 0x410);
    temp_r3b = temp_r3 - 0xA;
    if (temp_r0 == temp_r3) {
        set_motion_set(6);
    } else if (temp_r0 == temp_r3b) {
        this->m_438 = 0;
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        set_action_state(0x23);
    }
}

void TBoss6Type1::init_work() {
    this->m_40c = 0x3C;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0x3C;
    VecCopy((Vec *)(((u8 *)this) + 0x420), &cenbtm_pos);
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x39403), ((u8 *)this) + 0x584, (void*)(0), (void*)(1));
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x4003A811), ((u8 *)this) + 0x38, (void*)(0), (void*)(1));
    this->release_effect_slot((s32)((void*)(0)));
    this->spawn_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::tick_attack_sequence() {
    s32 temp_r0;
    s32 temp_r0_2;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410);
    if (temp_r0 == 0x23) {
        set_motion_set(6);
    } else if (temp_r0 == 0x19) {
        this->m_438 = 1;
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        latch_phase_counter();
        this->m_414 = 0;
        set_action_state(1);
    }
}

void TBoss6Type1::init_charge() {
    this->m_40c = 0x3C;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0x3C;
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x4003A811), (void*)((void *)(((u8 *)this) + 0x38)), (void*)(0), (void*)(1));
    this->release_effect_slot((s32)((void*)(0)));
    this->spawn_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::sub_802B2724() {
    TBoss6Type1 *boss6_type1 = this;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r4;
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410);
    if (temp_r0 == 0x4A) {
        VecCopy((Vec *)((u8 *)boss6_type1 + 0x420), &tkof_centop_low_pos);
    } else if (temp_r0 == 0x3B) {
        VecCopy((Vec *)((u8 *)boss6_type1 + 0x420), &tkof_centop_high_pos);
    }
    temp_r4 = *(s32 *)((s8 *)boss6_type1 + 0x410);
    if (temp_r4 <= 0x4A) {
        if (temp_r4 > 0x3B) {
            boss6_type1->interpolate_pos_to_target(temp_r4 - 0x3B, 0xF);
        } else {
            boss6_type1->interpolate_pos_to_target(temp_r4, boss6_type1->m_40c);
        }
    }
    temp_r0_2 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        boss6_type1->set_action_state(0x27);
    }
}

void TBoss6Type1::update_if_idle() { if (*(int*)((char*)this + 0x410) == 0) { TBoss6Type1__sub_802B8E1C(this); } }

void TBoss6Type1::enter_release_state() {
    u8 *arg0 = (u8 *)this;
    this->m_40c = 0x5A;
    *(s32 *)((s8 *)arg0 + 0x410) = 0x5A;
    ((s32 (*)(void))release_object__11TBoss6Type1FPv)();
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x4003B515), (u8 *)&this->position, (void*)(0), (void*)(0));
    ((TBoss6Type1 *)arg0)->spawn_effect_slot((s32)((void*)(0)));
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(1)));
    ((TBoss6PlotFalz *)(this->m_3f8))->activate_warp();
    ((TBoss6PlotFalz *)(this->m_3f8))->reset_state();
    if (((TBoss6Type1 *)arg0)->count_matches(0x1F, 4) == 0) {
        ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x68A24), (u8 *)&this->position, (void*)(0), (void*)(1));
    }
}

void TBoss6Type1::tick_state_410_timer() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state(0x20);
    }
}

void TBoss6Type1::init_move_attack() {
    u8 *arg0 = (u8 *)this;
    this->m_40c = 0x1E;
    *(s32 *)((s8 *)arg0 + 0x410) = 0x1E;
    damage_players_in_range__11TBoss6Type1Fv();
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x40039C19), (u8 *)&this->position, (void*)(0), (void*)(0));
}

void TBoss6Type1::update_hit_timer() {
    s32 temp_r3;

    play_persistent_sound(0x40032614, (s32)this, 0, 0, 0);
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x410) == 0x3C) {
        ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x39403), (void*)(((u8 *)this) + 0x38), (void*)(0), (void*)(1));
    }
    temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x410);
    if (temp_r3 > 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x410) = (temp_r3 - 1);
        return;
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0;
}

void TBoss6Type1::update_attack_state() {
    if ((s32) *(s32 *)((s8 *)this + 0x410) == 0) {
        if (is_field4b0_delta_reached__11TBoss6Type1Fv() != 0) {
            send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)(0x20));
            return;
        }
        send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)(0x1F));
    }
}

void TBoss6Type1::advance_plot_to_state2() {
    u8 *arg0 = (u8 *)this;
    this->m_40c = 0x12C;
    *(s32 *)((s8 *)arg0 + 0x410) = 0x12C;
    ((TBoss6PlotFalz *)(this->m_3f8))->free_child();
    ((TBoss6PlotFalz *)(this->m_3f8))->set_state_2();
    spawn_map_csn();
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x40039C13), (u8 *)&this->position, (void*)(0), (void*)(0));
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(0)));
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(1)));
    ((TBoss6Type1 *)arg0)->latch_phase_counter();
}

void TBoss6Type1::sub_802B2A94() {
    TBoss6Type1 *arg0 = this;
    f32 temp_f1;
    s32 temp_r0;
    s32 temp_r0_2;
    arg0->interpolate_pos_to_target(*(s32 *)((s8 *)arg0 + 0x410), arg0->m_40c);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x410) == (s32) ((f32) arg0->m_40c - 10.0f)) {
        arg0->m_438 = 0;
    }
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x3C);
    if ((temp_f1 <= 230.0f) && (temp_f1 > 228.0f)) {
        arg0->set_motion_set(1);
    } else {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x410);
        if (temp_r0 == 0x46) {
            arg0->set_motion_set(7);
        } else if (temp_r0 == 0xF) {
            VecCopy((Vec *)((u8 *)arg0 + 0x420), &down_centop_land_pos);
        }
    }
    play_persistent_sound(0x4003B012, ((s32) arg0), ((u32)((u8 *)arg0 + 0x38)), 0, 0);
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x410) - 1;
    *(s32 *)((s8 *)arg0 + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        arg0->set_action_state(0x1E);
    }
}

void TBoss6Type1::init_params() {
    spawn_grav_ball();
    this->m_40c = 300;
    *(u32 *)((s8 *)this + 0x410) = 300;
    VecCopy((Vec *)((void *)((char *)this + 1056)), &down_centop_pos);
    spawn_effect_slot((s32)((void*)(0)));
    release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::update_phase() {
    s32 temp_r0;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if ((temp_r0 < 0) && (is_normal_difficulty() == 0)) {
        set_action_state(0x1D);
    }
}

void TBoss6Type1::trigger_falz_phase() {
    if (((s32) *(s32 *)((s8 *)this + 0x410) == 0) && (is_normal_difficulty() != 0)) {
        TBoss6Type1__sub_802B8E1C(this);
    }
}

void TBoss6Type1::sub_802B2CB4() {
    TBoss6Type1 *boss6_type1 = this;
    boss6_type1->m_40c = 0x1E;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = 0x1E;
    VecCopy((Vec *)((u8 *)boss6_type1 + 0x420), &centop_pos);
    boss6_type1->spawn_effect_slot((s32)((void*)(0)));
    boss6_type1->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::tick_flee_countdown() {
    s32 temp_r0;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((int)(0xF - (this->m_41c & 1)));
    }
}

void TBoss6Type1::sub_802B2D68() {
    TBoss6Type1 *boss6_type1 = this;
    boss6_type1->m_40c = 0x1E;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = 0x1E;
    VecCopy((Vec *)((u8 *)boss6_type1 + 0x420), &centop_down_pos);
    boss6_type1->spawn_effect_slot((s32)((void*)(0)));
    boss6_type1->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::update_timer_transition() {
    s32 temp_r0;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state(0x1B);
    }
}

void TBoss6Type1::init_state() {
    this->m_40c = 0x3C;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0x3C;
    VecCopy((Vec *)(((u8 *)this) + 0x420), &centop_pos);
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x39403), (void*)(((u8 *)this) + 0x584), (void*)(0), (void*)(1));
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x4003A811), (void*)(((u8 *)this) + 0x38), (void*)(0), (void*)(1));
    this->release_effect_slot((s32)((void*)(0)));
    this->spawn_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::tick_trap_countdown() {
    s32 temp_r0;

    play_persistent_sound(0x40038F0F, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x410) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        this->set_action_state(0x27);
    }
}

void TBoss6Type1::sub_802B2F00() {
    u8 *boss6_type1 = (u8 *)this;
    if ((((f32) *(s32 *)((s8 *)boss6_type1 + 0x410) / (f32) ((TBoss6Type1 *)boss6_type1)->m_40c) < 0.5f) && (((TBoss6Type1 *)boss6_type1)->check_field4b0_threshold() != 0)) {
        ((TBoss6Type1 *)boss6_type1)->do_attack();
        return;
    }
    if ((s32) *(s32 *)((s8 *)boss6_type1 + 0x410) == 0) {
        if (TBoss6Type1__sub_802B6060(boss6_type1) != 0) {
            send_flow_action_if_idle__11TBoss6Type1FPvc(boss6_type1, (void*)(0x1A));
            return;
        }
        send_flow_action_if_idle__11TBoss6Type1FPvc(boss6_type1, (void*)(0x22));
    }
}

void TBoss6Type1::init_hp_and_state() { this->m_40c = 300; *(int*)((char*)this + 0x410) = 300; spawn_effect_slot((s32)((void*)((void*)0))); release_effect_slot((s32)((void*)((void*)1))); }

void TBoss6Type1::update_charge() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    ((TBoss6Type1 *)arg0)->interpolate_pos_to_target((s32)(*(s32 *)((s8 *)arg0 + 0x410)), (s32)(*(s32 *)((s8 *)arg0 + 0x40C)));
    play_persistent_sound(0x40038F0F, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x410) - 1;
    *(s32 *)((s8 *)arg0 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss6Type1 *)arg0)->set_action_state(0x27);
    }
}

void TBoss6Type1::start_action_if_idle() { if (*(int*)((char*)this + 0x410) == 0) { send_flow_action_if_idle__11TBoss6Type1FPvc(this, (void*)((void*)25)); } }

void TBoss6Type1::set_phase_90() { this->m_40c = 90; *(int*)((char*)this + 0x410) = 90; latch_phase_counter(); spawn_effect_slot((s32)((void*)((void*)0))); release_effect_slot((s32)((void*)((void*)1))); }

void TBoss6Type1::update_timer() {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r4;

    temp_r0 = *(s32 *)((s8 *)this + 0x410);
    temp_r4 = this->m_40c - 0xF;
    if (temp_r0 >= temp_r4) {
        interpolate_pos_to_target((s32)(temp_r0 - temp_r4), 0xF);
    }
    set_flag_on_threshold();
    temp_r0_2 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        latch_phase_counter();
        this->m_414 = 1;
        set_action_state(1);
    }
}

void TBoss6Type1::sub_802B3178() {
    void*p = (void*)this; ((TBoss6Type1 *)p)->m_40c = 123; *(int*)((char*)p + 0x410) = 123; clamp_to_arena_radius__11TBoss6Type1FPvPvf(p, (char*)p + 0x420); ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)((void*)231170), (void*)((void*)0), (void*)((void*)0), (void*)((void*)0)); ((TBoss6Type1 *)p)->spawn_effect_slot((s32)((void*)((void*)0))); ((TBoss6Type1 *)p)->release_effect_slot((s32)((void*)((void*)1))); }

void TBoss6Type1::sub_802B31E4() {
    TBoss6Type1 *arg0 = this;
    s32 var_r3;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x4A0);
    temp_r4 = arg0->m_49c;
    temp_r6 = *(s32 *)((s8 *)arg0 + 0x410);
    temp_r0 = temp_r5 + 0x1E;
    temp_r0 = temp_r4 + temp_r0;
    temp_r0 -= temp_r4;
    temp_r3 = temp_r0 - temp_r5;
    if (temp_r6 == temp_r0) {
        arg0->set_motion_set(0x11);
    } else if (temp_r6 == temp_r3) {
        arg0->release_effect_slot((s32)((void *) (2)));
        arg0->set_motion_set(0x13);
    }
    arg0->rotate_around_center((int) (*(s32 *)((s8 *)arg0 + 0x410)), arg0->m_40c);
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x410);
    if ((temp_r3 <= (s32) *(s32 *)((s8 *)arg0 + 0x4A0)) && (temp_r3 >= 0x1E)) {
        arg0->increase_field_clamped_max();
        TBoss6Type1__sub_802B6C30(arg0);
    } else {
        arg0->decrease_field_clamped_min();
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x410) >= 0x1E) {
        var_r3 = 0x4003B50C;
        if (*(f32 *)((s8 *)arg0 + 0x4DC) > 0.0f) {
            var_r3 = 0x4003AD0D;
        }
        play_persistent_sound((s32)var_r3, (s32)arg0, (u32)&arg0->sound_pos, 0, 1);
    }
    if (*(f32 *)((s8 *)arg0 + 0x4DC) > 0.0f) {
        TBoss6Type1__sub_802B4B04(((u8 *)arg0));
    } else {
        TBoss6Type1__sub_802B4A9C(arg0);
    }
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x410) - 1;
    *(s32 *)((s8 *)arg0 + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        arg0->reset_param();
        arg0->set_action_state(1);
    }
}

void TBoss6Type1::sub_802B3320() {
    action_timer = m_40c = m_49c + laser_fire_time + 30;
    play_sound_effect(0x4003A608, &sound_pos, 0, 0);
    release_effect_slot(0);
    spawn_effect_slot(1);
    spawn_effect_slot(2);
}

void TBoss6Type1::update_attack_timer2() {
    TBoss6Type1__sub_802B715C(this);
    interpolate_pos_to_target(action_timer, m_40c);
    if (--action_timer < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_dice_state() { this->m_40c = 62; *(int*)((char*)this + 0x410) = 62; release_effect_slot((s32)((void*)((void*)0))); spawn_effect_slot((s32)((void*)((void*)1))); }

void TBoss6Type1::sub_802B343C() {
    TBoss6Type1 *boss6_type1 = this;
    s32 temp_r0;
    s32 temp_r4;

    TBoss6Type1__sub_802B73AC();
    boss6_type1->interpolate_pos_to_target(*(s32 *)((s8 *)boss6_type1 + 0x410), boss6_type1->m_40c);
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        temp_r4 = boss6_type1->m_374;
        switch (temp_r4) {
        case 11:
            boss6_type1->set_action_state(0x1C);
            return;
        case 16:
            boss6_type1->set_action_state(0x24);
            return;
        default:
            boss6_type1->set_action_state(temp_r4 - 1);
            break;
        }
    }
}

void TBoss6Type1::init_action_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    *(s32 *)((s8 *)arg0 + 0x40C) = 0x3E;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x374);
    if ((temp_r0 == 0xB) || (temp_r0 == 0x10)) {
        *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (*(s32 *)((s8 *)arg0 + 0x40C) + 0x1E);
    }
    *(s32 *)((s8 *)arg0 + 0x410) = (s32) *(s32 *)((s8 *)arg0 + 0x40C);
    calc_grid_cell_position__11TBoss6Type1FPvPv(arg0, arg0 + 0x420);
    ((int (*)(void*, void*, void*, void*))play_sound_effect)((void*)(0x40039C21), arg0 + 0x5E4, (void*)(0), (void*)(0));
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(0)));
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::sub_802B3564() {
    TBoss6Type1 *boss6_type1 = this;
    s32 temp_r0;
    s32 temp_r4;

    update_beam_attack__11TBoss6Type1Fv();
    boss6_type1->interpolate_pos_to_target(*(s32 *)((s8 *)boss6_type1 + 0x410), boss6_type1->m_40c);
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        temp_r4 = boss6_type1->m_374;
        if (temp_r4 == 8) {
            boss6_type1->set_action_state(1);
            return;
        }
        boss6_type1->set_action_state(temp_r4 - 1);
    }
}

void TBoss6Type1::init_attack_timer() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x40C) = 0x3E;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x374) == 8) {
        *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (*(s32 *)((s8 *)arg0 + 0x40C) + 0x1E);
    }
    *(s32 *)((s8 *)arg0 + 0x410) = (s32) *(s32 *)((s8 *)arg0 + 0x40C);
    TBoss6Type1__sub_802B5598(arg0, arg0 + 0x420);
    play_sound_effect(0x4003BF07, arg0 + 0x5E4, 0, 0);
    ((TBoss6Type1 *)arg0)->release_effect_slot(0);
    ((TBoss6Type1 *)arg0)->spawn_effect_slot(1);
}

void TBoss6Type1::update_timer_state() {
    s32 temp_r0;
    s32 temp_r4;

    update_beam_attack__11TBoss6Type1Fv();
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        temp_r4 = this->m_374;
        if (temp_r4 == 5) {
            set_action_state(1);
            return;
        }
        set_action_state(temp_r4 - 1);
    }
}

void TBoss6Type1::set_phase_timer_3E() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x40C) = 0x3E;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x374) == 5) {
        *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (*(s32 *)((s8 *)arg0 + 0x40C) + 0x1E);
    }
    *(s32 *)((s8 *)arg0 + 0x410) = (s32) *(s32 *)((s8 *)arg0 + 0x40C);
    *(s32 *)((s8 *)arg0 + 0x40C) = 0x3E;
    *(s32 *)((s8 *)arg0 + 0x410) = 0x3E;
    play_sound_effect(0x4003BF07, arg0 + 0x5E4, 0, 0);
    ((TBoss6Type1 *)arg0)->spawn_effect_slot(0);
    ((TBoss6Type1 *)arg0)->release_effect_slot(1);
}

void TBoss6Type1::update_action_timer() {
    s32 temp_r0_2;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    switch (*(s32 *)((s8 *)this + 0x410)) {
    case 0x48:
    case 0x3E:
    case 0x52:
        TBoss6Type1__sub_802B6944(this);
        break;
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    if (temp_r0_2 < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::init_hp_state() { this->m_40c = 90; *(int*)((char*)this + 0x410) = 90; release_effect_slot((s32)((void*)0)); spawn_effect_slot((s32)((void*)1)); }

void TBoss6Type1::sub_802B381C() {
    TBoss6Type1 *boss6_type1 = this;
    s32 temp_r0;

    if ((s32) *(s32 *)((s8 *)boss6_type1 + 0x410) == 0x3E) {
        ((s32 (*)(void))TBoss6Type1__sub_802B6944)();
    }
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        boss6_type1->set_action_state(1);
    }
}

void TBoss6Type1::init_state_90() { this->m_40c = 90; *(int*)((char*)this + 0x410) = 90; spawn_effect_slot((s32)((void*)((void*)0))); release_effect_slot((s32)((void*)((void*)1))); }

void TBoss6Type1::update_attack_countdown_reset() {
    s32 temp_r0;

    interpolate_pos_to_target(*(s32 *)((s8 *)this + 0x410), this->m_40c);
    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state(1);
    }
}

void TBoss6Type1::start_attack() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_414 == 0) {
        this->m_40c = 0x1E;
        *(s32 *)((s8 *)arg0 + 0x410) = 0x1E;
    } else {
        this->m_40c = 0x1E;
        *(s32 *)((s8 *)arg0 + 0x410) = 0x1E;
    }
    play_sound_effect(0x40039706, (u8 *)&this->position, 0, 0);
    ((TBoss6Type1 *)arg0)->release_effect_slot((s32)((void*)(0)));
    ((TBoss6Type1 *)arg0)->spawn_effect_slot((s32)((void*)(1)));
    if (((TBoss6Type1 *)arg0)->count_matches(0x19, 4) > 0) {
        ((TBoss6Type1 *)arg0)->latch_phase_counter();
        play_sound_effect(0x68A24, (u8 *)&this->position, 0, 1);
    }
}

void TBoss6Type1::tick_countdown() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x410) - 1;
    *(s32 *)((s8 *)this + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state(0x27);
    }
}

void TBoss6Type1::choose_next_action() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x410) == 0) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x414) == 0) {
            if (((TBoss6Type1 *)arg0)->is_ready() != 0) {
                ((s32 (*)(void *, int))send_flow_action_if_idle__11TBoss6Type1FPvc)(arg0, 0x17);
                return;
            }
            if (((TBoss6Type1 *)arg0)->count_matches(2, 0x10) == 0) {
                ((TBoss6Type1 *)arg0)->do_attack();
                return;
            }
            if (((((TBoss6Type1 *)arg0)->count_matches(3, 0xA) + ((TBoss6Type1 *)arg0)->count_matches(5, 0xA)) == 0) || (((1.0f / 32768.0f) * (f32) rand()) < 0.4f)) {
                TBoss6Type1__sub_802B8BB4((arg0));
                return;
            }
            ((TBoss6Type1 *)arg0)->do_attack();
            return;
        }
        if (((TBoss6Type1 *)arg0)->is_time_up() != 0) {
            TBoss6Type1__sub_802B8A70(arg0);
            return;
        }
        TBoss6Type1__sub_802B8BB4((arg0));
    }
}

void TBoss6Type1::init_attack_timers() {
    s32 temp_r0;
    s32 temp_r0_2;

    if ((s32) this->m_414 == 0) {
        this->m_40c = 0x5A;
        *(s32 *)((s8 *)this + 0x410) = 0x5A;
    } else if ((s32) this->m_4ac != 0) {
        temp_r0 = *(s32 *)((s8 *)this + 0x4A8);
        this->m_40c = temp_r0;
        *(s32 *)((s8 *)this + 0x410) = temp_r0;
    } else {
        temp_r0_2 = this->m_4a4;
        this->m_40c = temp_r0_2;
        *(s32 *)((s8 *)this + 0x410) = temp_r0_2;
    }
    spawn_effect_slot((s32)((void*)(0)));
    release_effect_slot((s32)((void*)(1)));
}

void TBoss6Type1::sub_802B3B94() {
    void *boss6_type1 = (void *)this;
    s32 temp_r0;

    if ((s32) *(s32 *)((s8 *)boss6_type1 + 0x410) < 0x1E) {
        TBoss6Type1__sub_802B5140((s32)boss6_type1, *(s32 *)((s8 *)boss6_type1 + 0x410), 0x1E);
    }
    temp_r0 = *(s32 *)((s8 *)boss6_type1 + 0x410) - 1;
    *(s32 *)((s8 *)boss6_type1 + 0x410) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss6Type1 *)boss6_type1)->set_action_state(1);
    }
}

void TBoss6Type1::init_effect_slot_1() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x420), (const Vec *)&lbl_80470CE0.value);
    *(s32 *)((s8 *)arg0 + 0x40C) = 0x5A;
    *(s32 *)((s8 *)arg0 + 0x410) = 0x5A;
    ((TBoss6Type1 *)arg0)->spawn_effect_slot((s32)((void*)(1)));
}


}
