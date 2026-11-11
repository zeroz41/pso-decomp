#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"

// TBoss6Type2 state handlers and their state-action table (one TU: the table's
// strings and "DPB" lead this TU's .rodata and .sdata2, its __sinit ends the .text).
// Built with -inline off,deferred, so the functions are written last-to-first: the
// function-local statics' .sbss slots run backwards against the code, which only the
// deferred build of a reversed source gives.
//
// 36 rows of {name, s32, s32, enter / idle / update handler}. The handlers are pointers
// to members, so CodeWarrior builds the table in __sinit from a per-handler template
// (the 97 0xC objects at 0x804DFC50).
typedef void (TBoss6Type2::*Handler)();

struct TBoss6Type2Action {
    const char *name;
    s32 field4;
    s32 field8;
    Handler h[3];
};

TBoss6Type2Action lbl_804E00DC[36] = {
    { "WAIT", 0, 1, { &TBoss6Type2::sub_802BFBE4, &TBoss6Type2::select_attack_state, &TBoss6Type2::tick_timer_460 } },
    { "INFO_STAT", 4, 1, { &TBoss6Type2::reset_state_timers, 0, &TBoss6Type2::sub_802BFA1C } },
    { "SEARCH", 1, 1, { &TBoss6Type2::init_timer_and_play_sound, &TBoss6Type2::pick_next_zako, &TBoss6Type2::tick_action_timer } },
    { "NIRAMU", 0, 1, { &TBoss6Type2::sub_802BF904, &TBoss6Type2::check_state_0x460_eq0, &TBoss6Type2::sub_802BF834 } },
    { "WALK_CMN", 2, 1, { &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase } },
    { "WALK_DEF", 3, 1, { &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase } },
    { "WALK_CMNx1", 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "WALK_CMNx2", 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "WALK_CMNx3", 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "WALK_DEFx1", 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "WALK_DEFx2", 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "WALK_DEFx3", 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { "KAMAE", 4, 1, { &TBoss6Type2::start_death_sequence, &TBoss6Type2::update_when_timer_zero, &TBoss6Type2::update_timer } },
    { "BKJUMP", 6, 1, { &TBoss6Type2::init_timers_and_copy_pos, &TBoss6Type2::sub_802BF3F4, &TBoss6Type2::update_death_sequence } },
    { "DPB", 7, 0, { &TBoss6Type2::init_attack_timers, &TBoss6Type2::update_state_34, &TBoss6Type2::update_attack_sequence } },
    { "IAI_L", 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_R", 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_F", 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_L2", 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_R2", 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_F2", 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_L3", 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_R3", 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "IAI_F3", 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { "CHG_TO_BSK", 11, 0, { &TBoss6Type2::spawn_death_soul, 0, &TBoss6Type2::sub_802BEC28 } },
    { "BSK_AGAIN", 11, 0, { &TBoss6Type2::sub_802BEB78, 0, &TBoss6Type2::update_attack_timer } },
    { "CHG_TO_CMN", 12, 0, { &TBoss6Type2::start_flow_soul_effect, 0, &TBoss6Type2::update_charge_timer } },
    { "B_WAIT", 13, 1, { &TBoss6Type2::init_speed_from_ratio, &TBoss6Type2::select_next_state, &TBoss6Type2::tick_timer_0x460 } },
    { "B_BJ_WAIT", 13, 1, { &TBoss6Type2::sub_802BE738, &TBoss6Type2::update_rock_spawn_state, &TBoss6Type2::tick_timer_0x460 } },
    { "B_WALKx1", 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { "B_WALKx2", 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { "B_WALKx3", 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { "B_WALKx4", 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { "B_WALKx5", 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { "WAITNEXT", -1, 0, { 0, &TBoss6Type2::select_action, 0 } },
    { "DEAD", -1, 0, { 0, 0, 0 } },
};

struct T2_802BE6D4 { u8 pad0[0x45C]; s32 f45C; s32 f460; };

struct Vec_802BE9AC { f32 x, y, z; };

struct Obj_802BE9AC {
    u8 pad0[0x38];
    Vec_802BE9AC pos;
    u8 pad44[0x45C - 0x44];
    s32 t45C;
    s32 t460;
    u8 pad464[0x55C - 0x464];
    u16 client;
};

typedef struct S_802BF6CC {
    u8 pad0[0x374];
    s32 f374;
    u8 pad378[0x45C - 0x378];
    s32 f45C;
    s32 f460;
    u8 pad464[0x504 - 0x464];
    s32 f504;
} S_802BF6CC;

extern "C" {
s32 choose_random_motion__11TBoss6Type2Fv();
int send_action_packet__11TBoss6Type2FSc(void*, void*);
s32 TBoss6Type2__sub_802BB768(void *);
s32 VecCopy__FP3VecPC3Vec(void *, void *);
extern const f32 lbl_805DE3F8;
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 spawn_flow_soul__11TBoss6Type2Fiii(s32 arg0, s32 arg1, s32 arg2);
extern const f32 lbl_805DE404;
extern const f32 lbl_805DE400;
s32 TBoss6Type2__sub_802BA598(void *, s32, s32);
s32 TBoss6Type2__sub_802BA944(void *);
s32 TBoss6Type2__sub_802BA9E4(void *);
void TBoss6Type2__sub_802BAD04(s32 arg0);
s32 TBoss6Type2__sub_802BB7C0(void *);
s32 get_phase__11TBoss6Type2Fv();
u16 is_falz_ready__11TBoss6Type2Fv(void *);
extern f32 lbl_805DE408;
extern f32 lbl_805DE3FC;
void TBoss6Type2__sub_802BBC74(TBoss6Type2 *boss);
extern const f32 lbl_805DE3F4;
int TBoss6Type2__sub_802BB694(void);
}

void TBoss6Type2::sub_802BFBE4() { state_duration = 90; state_timer = 90; }

void TBoss6Type2::select_attack_state() {
    if ((s32) this->state_timer == 0) {
        if (TBoss6Type2__sub_802BA9E4(this) != 0) {
            send_action_packet((s8)((void*)(0xD)));
            return;
        }
        if ((get_phase() == 0xD) && (is_ready_to_attack() != 0)) {
            this->m_464 = is_falz_ready();
            send_action_packet((s8)((void*)(0x18)));
            return;
        }
        if (TBoss6Type2__sub_802BA944(this) != 0) {
            send_action_packet((s8)((void*)(0xE)));
            return;
        }
        if (get_phase() == 0xD) {
            this->m_428 = pick_random_other_index();
            this->m_430 = choose_next_index();
            send_action_packet((s8)((void*)(1)));
            return;
        }
        send_action_packet((s8)((void*)(2)));
    }
}

void TBoss6Type2::tick_timer_460() {
    s32 temp_r0;

    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::reset_state_timers() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x4EC);
    this->state_duration = temp_r0;
    this->state_timer = temp_r0;
    TBoss6Type2__sub_802BB768(this);
}

void TBoss6Type2::sub_802BFA1C() {
    s32 temp_r0;

    play_persistent_sound(0x4006A612, (s32)this, (u32)&position, 0, 1);
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 < 0) {
        play_sound_effect(0x40069E13, &position, 0, 1);
        set_action_state((void *)2);
    }
}

void TBoss6Type2::init_timer_and_play_sound() {
    u8 *arg0 = (u8 *)this;
    static s32 dur = (s32)(30.0f / lbl_805DE3F4);
  *((s32 *) (((s8 *) arg0) + 0x460)) = (*((s32 *) (((s8 *) arg0) + 0x45C)) = dur);
  play_sound_effect(0x69126, arg0 + 0x38, 0, 1);
}

void TBoss6Type2::pick_next_zako() {
    if ((s32) this->state_timer == 0) {
        this->m_466 = TBoss6Type2__sub_802BB694();
        if (this->m_466 == 0xFFFF) {
            update_action_state();
            return;
        }
        send_action_packet((s8)((void*)((void*)(3))));
    }
}

void TBoss6Type2::tick_action_timer() {
    s32 temp_r0;

    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::sub_802BF904() { state_duration = 45; state_timer = 45; }

void TBoss6Type2::check_state_0x460_eq0() { if (this->state_timer == 0) { send_state_action_packet(); } }

void TBoss6Type2::sub_802BF834() {
    s32 temp_r0;
    if ((state_timer == state_duration - 0x1E) && (m_466 != 0xFFFF)) {
        play_sound_effect(0x4006A10A, &position, 0, 1);
        play_sound_effect(0x69E27, &position, 0, 1);
        spawn_particle_effect_with_flags((u8 *)this + 0x62C, 0x223, 0x40);
    }
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::init_attack_params() {

    this->state_duration = 0x4B;
    this->state_timer = 0x4B;
    *(s32 *)&this->unk_504 = 0;
    switch (this->m_374) {
    case 4:
        this->m_46c = 0;
        break;
    case 5:
        this->m_46c = 1;
        break;
    default:
        this->m_46c = 0;
        break;
    }
    TBoss6Type2__sub_802BB7C0(this);
    switch ((s32) this->m_374) {
    case 5:
        spawn_particle_slot(0xD);
        break;
    }
}

void TBoss6Type2::update_zako_phase() {
    s32 temp_r0;

    if (((s32) *(s32 *)&this->unk_504 == 0) && (this->turn_toward_target_position() == 0)) {
        *(s32 *)&this->unk_504 = 1;
    }
    update_zako();
    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0xC);
    }
}

void TBoss6Type2::reset_timers_and_spawn_particle() {
    S_802BF6CC *arg0 = (S_802BF6CC *)this;
    arg0->f45C = 0x4B;
    this->state_timer = 0x4B;
    arg0->f504 = 0;
    TBoss6Type2__sub_802BB7C0(arg0);
    switch (this->m_374) {
    case 9:
    case 10:
    case 11:
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(0xD);
        break;
    }
}

void TBoss6Type2::send_state_action() {
    if ((s32) this->state_timer == 0) {
        switch (this->m_374) {
        case 6:
            this->m_46c = 0;
            send_action_packet((s8)((void*)(0xC)));
            return;
        case 9:
            this->m_46c = 1;
            send_action_packet((s8)((void*)(0xC)));
            return;
        default:
            send_state_action_packet();
            break;
        }
    }
}

void TBoss6Type2::update_zako_spawn_timer() {
    s32 temp_r0;

    if (((s32) *(s32 *)&this->unk_504 == 0) && (this->turn_toward_target_position() == 0)) {
        *(s32 *)&this->unk_504 = 1;
    }
    update_zako();
    temp_r0 = this->state_timer - 1;
    this->state_timer = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::start_death_sequence() {
    s32 sound;
    s32 duration = *(s32 *)((s8 *)this + 0x4C8);
    state_duration = duration;
    state_timer = duration;
    switch (m_47c) {
    case 15:
        sound = 0x68522;
        break;
    case 16:
        sound = 0x68521;
        break;
    case 17:
        sound = 0x68523;
        break;
    }
    play_sound_effect(sound, &position, 0, 1);
    destroy_part(0xD);
}

void TBoss6Type2::update_when_timer_zero() { if (*(int*)((char*)this + 0x460) == 0) { send_action_packet__11TBoss6Type2FSc(this, (void*)(*(void**)((char*)this + 0x47c))); } }

void TBoss6Type2::update_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x460) == (s32) (*(s32 *)((s8 *)arg0 + 0x45C) - 7)) {
        play_sound_effect(0x4006A604, arg0 + 0x38, 0, 0);
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x460) - 1;
    *(s32 *)((s8 *)arg0 + 0x460) = temp_r0;
    if (temp_r0 < 0) {
        ((TBoss6Type2 *)arg0)->set_action_state((void *)0x22);
    }
}

void TBoss6Type2::init_timers_and_copy_pos() {
    u8 *arg0 = (u8 *)this;
    static s32 dur = (s32)(15.0f + (30.0f / lbl_805DE3F8));
  *((s32 *) (((s8 *) arg0) + 0x460)) = (*((s32 *) (((s8 *) arg0) + 0x45C)) = (s32) dur);
  VecCopy__FP3VecPC3Vec(arg0 + 0x50C, arg0 + 0x38);
  *((s32 *) (((s8 *) arg0) + 0x470)) = 0;
  if (((s32) (*((s32 *) (((s8 *) arg0) + 0x418)))) == 0)
  {
    TBoss6Type2__sub_802BB768(arg0);
  }
}

void TBoss6Type2::sub_802BF3F4() { if (state_timer == 45) { drop_random_rocks((s32)this, (s32)((void*)0)); } }

void TBoss6Type2::update_death_sequence() {
    s32 d;
    s32 t;
    TBoss6Type2__sub_802BA598(this, state_timer, state_duration);
    d = state_duration;
    s32 d16 = d - 0x16;
    if (state_timer == d - 7) {
        play_sound_effect(0x4006A601, &position, 0, 0);
    }
    if (state_timer == d16) {
        play_sound_effect(0x40069E03, &position, 0, 1);
    }
    trigger_screen_pos();
    switch (state_timer) {
    case 0x2D:
    case 0x37:
    case 0x41:
        spawn_particle_effect_with_flags(&position, 0x221, 0x40);
        spawn_particle_effect_with_flags(&position, 0x22F, 0x40);
        break;
    }
    if (state_timer == 0x41) {
        TCameraCtrl::set_shake_preset(1);
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        if ((s32) m_418 != 0) {
            set_action_state((void *)0x1C);
        } else {
            set_action_state((void *)0);
        }
    }
}

void TBoss6Type2::init_attack_timers() {
    *(s32 *)((s8 *)((u8 *)this) + 0x45C) = 0xB4;
    *(s32 *)((s8 *)((u8 *)this) + 0x460) = 0xB4;
    play_sound_effect(0x4006970E, (void *)(((u8 *)this) + 0x38), 0, 1);
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x418) == 0) {
        TBoss6Type2__sub_802BB7C0(this);
        return;
    }
    TBoss6Type2__sub_802BB768(this);
}

void TBoss6Type2::update_state_34() { if (*(int*)((char*)this + 0x460) == 34) { TBoss6Type2::drop_random_rocks((s32)this, (s32)((void*)0)); } }

void TBoss6Type2::update_attack_sequence() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;

    if ((s32) *(s32 *)((s8 *)arg0 + 0x460) == (s32) (*(s32 *)((s8 *)arg0 + 0x45C) - 0x3C)) {
        play_sound_effect(0x69C0F, arg0 + 0x38, 0, 1);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x460) == (s32) (*(s32 *)((s8 *)arg0 + 0x45C) - 0x78)) {
        TBoss6Type2__sub_802BAD04((s32)arg0);
    }
    switch (*(s32 *)((s8 *)arg0 + 0x460)) {
    case 0xA0:
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(8);
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(9);
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(0xA);
        break;
    case 0x50:
        ((TBoss6Type2 *)arg0)->destroy_part(8);
        ((TBoss6Type2 *)arg0)->destroy_part(9);
        ((TBoss6Type2 *)arg0)->destroy_part(0xA);
        break;
    case 0x82:
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(0xB);
        ((TBoss6Type2 *)arg0)->spawn_particle_slot(0xC);
        break;
    case 0x49:
        ((TBoss6Type2 *)arg0)->destroy_part(0xB);
        ((TBoss6Type2 *)arg0)->destroy_part(0xC);
        break;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x460) == 0x36) {
        TCameraCtrl::set_shake_preset(1);
    }
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x460) - 1;
    *(s32 *)((s8 *)arg0 + 0x460) = temp_r0_2;
    if (temp_r0_2 < 0) {
        ((TBoss6Type2 *)arg0)->reset_attack_counter();
        if ((s32) *(s32 *)((s8 *)arg0 + 0x418) != 0) {
            ((TBoss6Type2 *)arg0)->set_action_state((void *)0x1B);
            return;
        }
        ((TBoss6Type2 *)arg0)->set_action_state((void *)0);
    }
}

void TBoss6Type2::init_timer() {
    static s32 dur = (s32)(30.0f / lbl_805DE3FC);
    s32 temp_r0;
    temp_r0 = dur;
    state_duration = temp_r0;
    *(s32 *)((s8 *)this + 0x460) = temp_r0;
    *(s32 *)((s8 *)this + 0x470) = (s32) (*(s32 *)((s8 *)this + 0x470) + 1);
}

void TBoss6Type2::check_state_0x460_eq4() { if (*(int*)((char*)this + 0x460) == 4) { TBoss6Type2::drop_random_rocks((s32)this, (s32)((void*)0)); } }

void TBoss6Type2::sub_802BEE38() {
    s32 sound;
    s32 n;
    s32 idx;
    s32 grp;
    static s32 swing_sound_time = (s32)(10.0f / lbl_805DE3FC - 10.0f);
    if (state_timer == state_duration - swing_sound_time) {
        sound = 0x40069C05;
        switch ((s32) m_374) {
        case 17:
        case 20:
        case 23:
            sound = 0x40069C06;
            break;
        }
        play_sound_effect(sound, &position, 0, 0);
    }
    static s32 hit_time = (s32)(10.0f / lbl_805DE3FC);
    if (state_timer == state_duration - hit_time) {
        switch ((s32) m_374) {
        case 17:
        case 20:
        case 23:
            play_sound_effect(0x40069C07, &position, 0, 0);
            break;
        }
        TBoss6Type2__sub_802BBC74(this);
    }
    if (state_timer == 24) {
        TCameraCtrl::set_shake_preset(1);
    }
    if (--state_timer < 0) {
        switch ((s32) m_374) {
        case 15:
        case 16:
        case 17:
            if ((s32) m_418 != 0) {
                set_action_state((void *)27);
            } else {
                set_action_state((void *)0);
            }
            break;
        default:
            n = (s32) m_374 - 15;
            grp = n / 3;
            idx = n % 3;
            idx = ((m_478 & 1) + idx);
            idx = (idx + 1) % 3;
            set_action_state((void *)(idx + ((grp - 1) * 3) + 15));
            break;
        }
    }
}

void TBoss6Type2::spawn_death_soul() {
    u8 *arg0 = (u8 *)this;
    static s32 dur = (s32)(60.0f / lbl_805DE400);
    s32 temp_r0;
    temp_r0 = dur;
    *(s32 *)((s8 *)arg0 + 0x45C) = temp_r0;
    *(s32 *)((s8 *)arg0 + 0x460) = temp_r0;
    *(s32 *)((s8 *)arg0 + 0x420) = 0;
    play_sound_effect(0x68A25, arg0 + 0x38, 0, 1);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(6);
    TBoss6Type2__sub_802BB768(arg0);
    if (*(u16 *)((s8 *)arg0 + 0x464) != 0xFFFF) {
        TBoss6Type2::create_flow_soul((void *)arg0, arg0 + 0x620, (void *)(*(u16 *)((s8 *)arg0 + 0x464)), (void *)(*(s32 *)((s8 *)arg0 + 0x45C)));
        ((TBoss6EffHyoui *)(*(u16 *)((s8 *)arg0 + 0x464)))->create((void *)0, (void *)(*(s32 *)((s8 *)arg0 + 0x45C)));
    }
}

void TBoss6Type2::sub_802BEC28() {
    f32 ratio;
    u32 player;
    state_progress = (f32) (1.0f - ((f32) state_timer / (f32) state_duration));
    ratio = state_progress;
    if (ratio < 0.0f) {
        state_progress = 0.0f;
    } else if (ratio > 1.0f) {
        state_progress = 1.0f;
    }
    play_persistent_sound(0x4006A30B, (s32)this, (u32)&position, 0, 1);
    if (--state_timer < 0) {
        m_418 = 1;
        state_progress = 1.0f;
        if (check_target() != 0) {
            if (is_target_valid() == 0) {
                play_sound_effect(0x40069E13, &position, 0, 1);
            }
            player = (u32)get_player_by_client_id(*(u16 *)((s8 *)this + 0x55C));
            if (player != 0U) {
                spawn_particle_effect((void *)(player + 0x38), 0x36);
            }
        }
        copy_anim_state();
        destroy_part(6);
        set_action_state((void *)0x1B);
    }
}

void TBoss6Type2::sub_802BEB78() {
    static s32 dur = (s32)(60.0f / lbl_805DE400);
    s32 duration;
    duration = dur;
    state_duration = duration;
    state_timer = duration;
    play_sound_effect(0x68A25, &position, 0, 1);
    TBoss6Type2__sub_802BB768(this);
    if (m_464 != 0xFFFF) {
        create_flow_soul(this, (u8 *)this + 0x620, (void *)m_464, (void *)(state_duration));
        ((TBoss6EffHyoui *)m_464)->create((void *)0, (void *)(state_duration));
    }
}

void TBoss6Type2::update_attack_timer() {
    u32 player;

    play_persistent_sound(0x4006A30B, (s32)this, (u32)&position, 0, 1);
    if (--state_timer < 0) {
        if (check_target() != 0) {
            if (is_target_valid() == 0) {
                play_sound_effect(0x40069E13, &position, 0, 1);
            }
            player = (u32)get_player_by_client_id(*(u16 *)((s8 *)this + 0x55C));
            if (player != 0U) {
                spawn_particle_effect((void *)(player + 0x38), 0x36);
            }
        }
        set_action_state((void *)0x1B);
    }
}

void TBoss6Type2::start_flow_soul_effect() {
    Obj_802BE9AC *arg0 = (Obj_802BE9AC *)this;
    static s32 dur = (s32)(60.0f / lbl_805DE404);
    Vec_802BE9AC v;
    u32 pl;
    s32 d = dur;
    arg0->t45C = d;
    arg0->t460 = d;
    play_sound_effect(0x68A25, &arg0->pos, 0, 1);
    ((TBoss6Type2 *)arg0)->spawn_particle_slot(7);
    TBoss6Type2__sub_802BB768(arg0);
    if (arg0->client != 0xFFFF) {
        pl = (u32)get_player_by_client_id(arg0->client);
        if (pl != 0) {
            VecCopy__FP3VecPC3Vec(&v, (void *)(pl + 0x38));
            v.y += 10.0f;
            spawn_flow_soul__11TBoss6Type2Fiii((s32)arg0, (s32)&v, (s32)arg0->t45C);
            spawn_particle_effect((void *)(pl + 0x38), 0x36);
        }
        ((TBoss6EffHyoui *)(arg0->client))->create((void *)1, (void *)arg0->t45C);
        if (((TBoss6Type2 *)arg0)->is_target_valid() == 0) {
            play_sound_effect(0x40069E13, &arg0->pos, 0, 1);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type2::update_charge_timer() {
    f32 temp_f1;
    s32 temp_r0;
    *(f32 *)((s8 *)((u8 *)this) + 0x41C) = (f32) ((f32) *(s32 *)((s8 *)((u8 *)this) + 0x460) / (f32) *(s32 *)((s8 *)((u8 *)this) + 0x45C));
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x41C);
    if (temp_f1 < 0.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x41C) = 0.0f;
    } else if (temp_f1 > 1.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x41C) = 1.0f;
    }
    play_persistent_sound(0x4006A30B, ((s32) this), (0U), 0, 0);
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x460) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x460) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x418) = 0;
        *(f32 *)((s8 *)((u8 *)this) + 0x41C) = 0.0f;
        this->copy_anim_state();
        this->destroy_part(7);
        this->set_action_state((void *)0);
    }
}
#pragma pop

void TBoss6Type2::init_speed_from_ratio() {
    static s32 speed_from_ratio = (s32)(30.0f / lbl_805DE408);
    s32 temp_r0;
    temp_r0 = speed_from_ratio;
    state_duration = temp_r0;
    *(s32 *)((s8 *)this + 0x460) = temp_r0;
    *(s32 *)((s8 *)this + 0x420) = (s32) (*(s32 *)((s8 *)this + 0x420) + 1);
}

void TBoss6Type2::select_next_state() {
    u16 temp_r3;

    if ((s32) *(s32 *)((s8 *)this + 0x460) == 0) {
        if (get_phase__11TBoss6Type2Fv() == 0xD) {
            if (is_phase_complete() != 0) {
                send_action_packet__11TBoss6Type2FSc(this, (void*)(0x1A));
                return;
            }
            if (*(u16 *)((s8 *)this + 0x55C) == 0xFFFF) {
                temp_r3 = is_falz_ready__11TBoss6Type2Fv(this);
                if (temp_r3 != 0xFFFF) {
                    *(u16 *)((s8 *)this + 0x464) = temp_r3;
                    send_action_packet__11TBoss6Type2FSc(this, (void*)(0x19));
                    return;
                }
            }
            goto block_7;
        }
block_7:
        if (TBoss6Type2__sub_802BA9E4(this) != 0) {
            send_action_packet__11TBoss6Type2FSc(this, (void*)(0xD));
            return;
        }
        if (TBoss6Type2__sub_802BA944(this) != 0) {
            send_action_packet__11TBoss6Type2FSc(this, (void*)(0xE));
            return;
        }
        update_attack_target();
    }
}

void TBoss6Type2::tick_timer_0x460() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x460) - 1;
    *(s32 *)((s8 *)this + 0x460) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::sub_802BE738() {
    s32 duration = *(s32 *)((s8 *)this + 0x4D4);
    state_duration = duration;
    state_timer = duration;
    m_420++;
}

void TBoss6Type2::update_rock_spawn_state() {
    T2_802BE6D4 *arg0 = (T2_802BE6D4 *)this;
    s32 d = arg0->f45C - arg0->f460;
    if (arg0->f460 >= 0x1E && d % 30 == 0) {
        ((TBoss6Type2 *)arg0)->spawn_rocks_around_players();
        TCameraCtrl::set_shake_preset(1);
    }
    select_next_state();
}

void TBoss6Type2::sub_802BE6A0() {
    state_duration = 0x4B;
    state_timer = 0x4B;
    *(s32 *)((s8 *)this + 0x504) = 0;
    TBoss6Type2__sub_802BB768(this);
}

void TBoss6Type2::sub_802BE648() {
    if (state_timer == 0) {
        if ((s32) m_374 == 0x1D) {
            send_action_packet__11TBoss6Type2FSc(this, (void *)choose_random_motion__11TBoss6Type2Fv());
            return;
        }
        update_attack_target();
    }
}

void TBoss6Type2::update_zako_timer() {
    s32 temp_r0;

    if (((s32) *(s32 *)((s8 *)this + 0x504) == 0) && (this->turn_toward_target_position() == 0)) {
        *(s32 *)((s8 *)this + 0x504) = 1;
    }
    update_zako();
    temp_r0 = *(s32 *)((s8 *)this + 0x460) - 1;
    *(s32 *)((s8 *)this + 0x460) = temp_r0;
    if (temp_r0 < 0) {
        set_action_state((void *)0x22);
    }
}

void TBoss6Type2::select_action() {
    if (*(s32 *)((s8 *)this + 0x30) & 0x800) {
        send_action_packet__11TBoss6Type2FSc(this, (void*)(0x23));
        return;
    }
    if ((s32) *(s32 *)((s8 *)this + 0x418) != 0) {
        send_action_packet__11TBoss6Type2FSc(this, (void*)(0x1B));
        return;
    }
    send_action_packet__11TBoss6Type2FSc(this, (void*)(0));
}
