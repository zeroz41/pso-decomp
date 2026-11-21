#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_8032E708.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"

extern "C" {
int play_sound_effect(void*, void*, void*, void*);
s32 TBoss6Type2__sub_8032FB84();

void TBoss6Type2::update_recover_timer() {
    TBoss6Mag *mag = (TBoss6Mag *)this;
    mag->m_400 += -1.0f / 30.0f;
    if (mag->m_400 < 0.0f) {
        mag->m_400 = 0.0f;
    }
    mag->m_3cc = (mag->m_3cc + 1);
    if (mag->m_3cc >= 0x5A) {
        TBoss6Type2__sub_8032F5C4(mag);
        if (mag->m_40c != 0) {
            mag->set_action(1);
            return;
        }
        mag->set_action(2);
    }
}

void TBoss6Type2::sub_80336F00() { ((TBoss6Mag *)this)->m_3cc = 0; play_sound_effect((void*)438292, &position, (void*)0, (void*)0); destroy_part_object((s32)((void*)((void*)0))); }

void TBoss6Type2::update_ramp_timer() {
    TBoss6Mag *mag = (TBoss6Mag *)this;
    mag->m_400 += 1.0f / 30.0f;
    if (mag->m_400 > 1.0f) {
        mag->m_400 = 1.0f;
    }
    mag->m_3cc = (mag->m_3cc + 1);
    if (mag->m_3cc >= mag->m_3c0) {
        mag->set_action(5);
    }
}

void TBoss6Type2::sub_80336FB8() { ((TBoss6Mag *)this)->m_3cc = 0; ensure_particle_emitter((s32)((void*)0)); }
void TBoss6Type2::tick_attack_timer() {
    ((TBoss6Mag *)this)->m_3cc = (((TBoss6Mag *)this)->m_3cc - 1);
    if (((TBoss6Mag *)this)->m_3cc < 0) {
        destroy_part_object((s32)((void*)(3)));
        if (((TBoss6Mag *)this)->m_40c != 0) {
            ((TBoss6Mag *)this)->set_action(1);
            return;
        }
        ((TBoss6Mag *)this)->set_action(2);
    }
}

void TBoss6Type2::start_mag_mines_state() {
    TBoss6Mag *mag = (TBoss6Mag *)this;
    mag->m_3cc = 0x25;
    switch (mag->m_410) {
    case 0:
        spawn_mag_mines();
        break;
    default:
        break;
    }
    ((TBoss6Type2 *)mag)->ensure_particle_emitter((s32)((void*)((void *)3)));
}

void TBoss6Type2::update_effect_subsystems() {
    turn_toward_target();
    apply_random_drift();
    push_out_from_target();
    push_out_from_points();
    enforce_min_distance();
    if (((TBoss6Mag *)this)->m_40c != 0) {
        ((TBoss6Mag *)this)->set_action(1);
    }
}
void TBoss6Type2::sub_80337108() {  }
void TBoss6Type2::update_attack_state() {
    fly_toward_target();
    push_out_from_target();
    enforce_min_distance();
    if (((TBoss6Mag *)this)->m_40c == 0) {
        ((TBoss6Mag *)this)->set_action(2);
    }
}
void TBoss6Type2::sub_80337160() {  }
void TBoss6Type2::advance_phase_counter() {
    TBoss6Type2__sub_8032FB84();
    ((TBoss6Mag *)this)->m_3cc = (((TBoss6Mag *)this)->m_3cc + 1);
    if (((TBoss6Mag *)this)->m_3cc >= 4) {
        ((TBoss6Mag *)this)->set_action(1);
    }
}
void TBoss6Type2::sub_803371B4() { ((TBoss6Mag *)this)->m_3cc = 0; }

}

typedef void (TBoss6Type2::*TBoss6Type2ActionHandler)();

struct TBoss6Type2Action {
    const char *name;
    s32 motion;
    s32 param;
    TBoss6Type2ActionHandler enter;
    TBoss6Type2ActionHandler update;
};

TBoss6Type2Action boss6_type2_action_table[6] = {
    {"START", 0, 1, &TBoss6Type2::sub_803371B4, &TBoss6Type2::advance_phase_counter},
    {"SET_SHOLDER", 0, 0, &TBoss6Type2::sub_80337160, &TBoss6Type2::update_attack_state},
    {"CHASE_PL", 0, 1, &TBoss6Type2::sub_80337108, &TBoss6Type2::update_effect_subsystems},
    {"SHOOT", 1, 1, &TBoss6Type2::start_mag_mines_state, &TBoss6Type2::tick_attack_timer},
    {"DEAD", 2, 0, &TBoss6Type2::sub_80336FB8, &TBoss6Type2::update_ramp_timer},
    {"REVIVAL", 4, 0, &TBoss6Type2::sub_80336F00, &TBoss6Type2::update_recover_timer},
};
