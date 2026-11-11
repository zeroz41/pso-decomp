#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_8032E708.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"

struct O_80337054 { u8 pad[0x3CC]; s32 f3cc; u8 pad2[0x410 - 0x3D0]; s32 f410; };

extern "C" {
s32 set_action__9TBoss6MagFl(void * a0, s32 a1);
void spawn_mag_mines__11TBoss6Type2Fv();
int play_sound_effect(void*, void*, void*, void*);
s32 turn_toward_target__11TBoss6Type2Fv();
s32 fly_toward_target__11TBoss6Type2Fv();
s32 TBoss6Type2__sub_8032FB84();
s32 set_action__9TBoss6MagFl(void * a0 = 0, s32 a1 = 0);

void TBoss6Type2::update_recover_timer() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x400) += -1.0f / 30.0f;
    if (*(f32 *)((s8 *)arg0 + 0x400) < 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x400) = 0.0f;
    }
    this->m_3cc = (this->m_3cc + 1);
    if ((s32) this->m_3cc >= 0x5A) {
        TBoss6Type2__sub_8032F5C4(arg0);
        if ((s32) this->m_40c != 0) {
            set_action__9TBoss6MagFl(arg0, 1);
            return;
        }
        set_action__9TBoss6MagFl(arg0, 2);
    }
}

void TBoss6Type2::sub_80336F00() { m_3cc = 0; play_sound_effect((void*)438292, &position, (void*)0, (void*)0); destroy_part_object((s32)((void*)((void*)0))); }

void TBoss6Type2::update_ramp_timer() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x400) += 1.0f / 30.0f;
    if (*(f32 *)((s8 *)arg0 + 0x400) > 1.0f) {
        *(f32 *)((s8 *)arg0 + 0x400) = 1.0f;
    }
    this->m_3cc = (this->m_3cc + 1);
    if ((s32) this->m_3cc >= (s32) this->m_3c0) {
        set_action__9TBoss6MagFl(arg0, 5);
    }
}

void TBoss6Type2::sub_80336FB8() { m_3cc = 0; ensure_particle_emitter((s32)((void*)0)); }
void TBoss6Type2::tick_attack_timer() {
    this->m_3cc = (this->m_3cc - 1);
    if ((s32) this->m_3cc < 0) {
        destroy_part_object((s32)((void*)(3)));
        if ((s32) this->m_40c != 0) {
            set_action__9TBoss6MagFl(this, 1);
            return;
        }
        set_action__9TBoss6MagFl(this, 2);
    }
}

void TBoss6Type2::start_mag_mines_state() {
    O_80337054 *arg0 = (O_80337054 *)this;
    this->m_3cc = 0x25;
    switch (arg0->f410) {
    case 0:
        spawn_mag_mines__11TBoss6Type2Fv();
        break;
    default:
        break;
    }
    ((TBoss6Type2 *)arg0)->ensure_particle_emitter((s32)((void*)((void *)3)));
}

void TBoss6Type2::update_effect_subsystems() {
    turn_toward_target__11TBoss6Type2Fv();
    apply_random_drift();
    push_out_from_target();
    push_out_from_points();
    enforce_min_distance();
    if ((s32) this->m_40c != 0) {
        set_action__9TBoss6MagFl(this, 1);
    }
}
void TBoss6Type2::sub_80337108() {  }
void TBoss6Type2::update_attack_state() {
    fly_toward_target__11TBoss6Type2Fv();
    push_out_from_target();
    enforce_min_distance();
    if ((s32) this->m_40c == 0) {
        set_action__9TBoss6MagFl(this, 2);
    }
}
void TBoss6Type2::sub_80337160() {  }
void TBoss6Type2::advance_phase_counter() {
    TBoss6Type2__sub_8032FB84();
    this->m_3cc = (this->m_3cc + 1);
    if ((s32) this->m_3cc >= 4) {
        set_action__9TBoss6MagFl(this, 1);
    }
}
void TBoss6Type2::sub_803371B4() { *(s32 *)((char *)this + 0x3cc) = 0; }

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
