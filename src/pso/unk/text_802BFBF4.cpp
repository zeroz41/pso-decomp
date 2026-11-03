// TBoss6Type2 state-action table: 36 rows of {name, s32, s32, enter / idle / update
// handler}. The handlers are pointers to members, so CodeWarrior builds the table in
// __sinit from a per-handler template (the 97 0xC objects at 0x804DFC50).
#include "types.h"
#include "pso/boss/TBoss6Type2.h"

extern "C" {
extern u8 lbl_804713D0[];
extern u8 lbl_804713D8[];
extern u8 lbl_804713E4[];
extern u8 lbl_804713EC[];
extern u8 lbl_804713F4[];
extern u8 lbl_80471400[];
extern u8 lbl_8047140C[];
extern u8 lbl_80471418[];
extern u8 lbl_80471424[];
extern u8 lbl_80471430[];
extern u8 lbl_8047143C[];
extern u8 lbl_80471448[];
extern u8 lbl_80471454[];
extern u8 lbl_8047145C[];
extern u8 lbl_80471464[];
extern u8 lbl_8047146C[];
extern u8 lbl_80471474[];
extern u8 lbl_8047147C[];
extern u8 lbl_80471484[];
extern u8 lbl_8047148C[];
extern u8 lbl_80471494[];
extern u8 lbl_8047149C[];
extern u8 lbl_804714A4[];
extern u8 lbl_804714AC[];
extern u8 lbl_804714B8[];
extern u8 lbl_804714C4[];
extern u8 lbl_804714D0[];
extern u8 lbl_804714D8[];
extern u8 lbl_804714E4[];
extern u8 lbl_804714F0[];
extern u8 lbl_804714FC[];
extern u8 lbl_80471508[];
extern u8 lbl_80471514[];
extern u8 lbl_80471520[];
extern u8 lbl_8047152C[];
extern u8 lbl_805DE4D8[];
}

typedef void (TBoss6Type2::*Handler)();

struct TBoss6Type2Action {
    u8 *code;
    s32 field4;
    s32 field8;
    Handler h[3];
};

TBoss6Type2Action lbl_804E00DC[36] = {
    { lbl_804713D0, 0, 1, { &TBoss6Type2::sub_802BFBE4, &TBoss6Type2::select_attack_state, &TBoss6Type2::tick_timer_460 } },
    { lbl_804713D8, 4, 1, { &TBoss6Type2::reset_state_timers, 0, &TBoss6Type2::sub_802BFA1C } },
    { lbl_804713E4, 1, 1, { &TBoss6Type2::init_timer_and_play_sound, &TBoss6Type2::pick_next_zako, &TBoss6Type2::tick_action_timer } },
    { lbl_804713EC, 0, 1, { &TBoss6Type2::sub_802BF904, &TBoss6Type2::check_state_0x460_eq0, &TBoss6Type2::sub_802BF834 } },
    { lbl_804713F4, 2, 1, { &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase } },
    { lbl_80471400, 3, 1, { &TBoss6Type2::init_attack_params, 0, &TBoss6Type2::update_zako_phase } },
    { lbl_8047140C, 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_80471418, 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_80471424, 2, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_80471430, 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_8047143C, 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_80471448, 3, 1, { &TBoss6Type2::reset_timers_and_spawn_particle, &TBoss6Type2::send_state_action, &TBoss6Type2::update_zako_spawn_timer } },
    { lbl_80471454, 4, 1, { &TBoss6Type2::start_death_sequence, &TBoss6Type2::update_when_timer_zero, &TBoss6Type2::update_timer } },
    { lbl_8047145C, 6, 1, { &TBoss6Type2::init_timers_and_copy_pos, &TBoss6Type2::sub_802BF3F4, &TBoss6Type2::update_death_sequence } },
    { lbl_805DE4D8, 7, 0, { &TBoss6Type2::init_attack_timers, &TBoss6Type2::update_state_34, &TBoss6Type2::update_attack_sequence } },
    { lbl_80471464, 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_8047146C, 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_80471474, 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_8047147C, 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_80471484, 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_8047148C, 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_80471494, 9, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_8047149C, 8, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_804714A4, 10, 1, { &TBoss6Type2::init_timer, &TBoss6Type2::check_state_0x460_eq4, &TBoss6Type2::sub_802BEE38 } },
    { lbl_804714AC, 11, 0, { &TBoss6Type2::spawn_death_soul, 0, &TBoss6Type2::sub_802BEC28 } },
    { lbl_804714B8, 11, 0, { &TBoss6Type2::sub_802BEB78, 0, &TBoss6Type2::update_attack_timer } },
    { lbl_804714C4, 12, 0, { &TBoss6Type2::start_flow_soul_effect, 0, &TBoss6Type2::update_charge_timer } },
    { lbl_804714D0, 13, 1, { &TBoss6Type2::init_speed_from_ratio, &TBoss6Type2::select_next_state, &TBoss6Type2::tick_timer_0x460 } },
    { lbl_804714D8, 13, 1, { &TBoss6Type2::sub_802BE738, &TBoss6Type2::update_rock_spawn_state, &TBoss6Type2::tick_timer_0x460 } },
    { lbl_804714E4, 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { lbl_804714F0, 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { lbl_804714FC, 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { lbl_80471508, 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { lbl_80471514, 14, 1, { &TBoss6Type2::sub_802BE6A0, &TBoss6Type2::sub_802BE648, &TBoss6Type2::update_zako_timer } },
    { lbl_80471520, -1, 0, { 0, &TBoss6Type2::select_action, 0 } },
    { lbl_8047152C, -1, 0, { 0, 0, 0 } },
};
