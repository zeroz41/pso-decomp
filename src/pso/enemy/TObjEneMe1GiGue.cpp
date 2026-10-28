#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/map/CurrentArea.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEneMe1GiGueBarrier.h"
#include "pso/enemy/TObjEneMe1GiGueMissile.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TOKeyMachine01.h"

#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>
#include "types.h"
#include "pso/system/NinjaUtil.h"

struct V_802CAAF0 { s32 x; s32 y; };
struct S_802CAAF0 {
    u8 pad0[0x2FC];
    u8 f2FC[0x8C];
    u32 f388;
};
struct Obj_802CD058;

struct Gi_802CB170;
struct O_802CAC04;
struct Obj_802CB8F0;
struct Obj_802CBCC0;
struct Obj_802CCBAC;
struct Obj_802CD058;
struct S_802CB10C;
struct Tgt_802CB170;
struct Vec_802CAD98;
struct Vec_802CB8F0;

struct IV3_802CB824 { s32 x, y, z; };

extern "C" {
s32 copy_target_state__14TObjEnePanarmsFPv(void *, void *);
void * __nw__7TObjectFUl(int);
void TObjPlayer__sub_802CDEB4(void *, void *, u16, void *, s32, s32, u16);
void TObjEneMe1GiGue__sub_802CB824(void *obj, s32 arg1);
f32 receive_weapon_special_attack__15TObjEneMe1GiGueFPvPv(u8 *arg0);
f32 receive_attack__15TObjEneMe1GiGueFPviii(S_802CAAF0 *arg0, s32 arg1, V_802CAAF0 arg2, s32 arg3);
f32 receive_physical_attack__15TObjEneMe1GiGueFPvf(u8 *arg0);
void TObjEneMe1GiGueBarrier__sub_802CABF4(void* p);
s32 update_action_hold_status__15TObjEneMe1GiGueFv(s32 arg0);
void find_open_direction__15TObjEneMe1GiGueFPvPv(u8 *arg0, Vec_802CAD98 *arg1);
void load_params__15TObjEneMe1GiGueFv(s32 arg0);
void TObjEneMe1GiGue__sub_802CB03C(u8 *arg0);
s32 TObjEneMe1GiGue__sub_802CB10C(S_802CB10C *arg0);
void add_target_in_cone__15TObjEneMe1GiGueFPvPv(Gi_802CB170 *self, Tgt_802CB170 *t);
void init__15TObjEneMe1GiGueFPv(u8 *arg0);
void TObjEneMe1GiGue__sub_802CB378(u8 *arg0);
void sub_802CB6D4__15TObjEneMe1GiGueFv(u8 *arg0);
void move_around_center__15TObjEneMe1GiGueFPvPvf(Obj_802CB8F0 *o, Vec_802CB8F0 *c, f32 r);
void update_rush_attack__15TObjEneMe1GiGueFPv(Obj_802CBCC0 *o);
void action__15TObjEneMe1GiGueFPv(void *arg0);
void TObjEneMe1GiGue__sub_802CC45C(u8 *arg0);
void TObjEneMe1GiGue__sub_802CC614(u8 *arg0);
void TObjEneMe1GiGue__sub_802CC900(u8 *arg0);
void TObjEneMe1GiGue__sub_802CCBAC(Obj_802CCBAC *o);
void vfunc_63__15TObjEneMe1GiGueFv(u8 *arg0);
void vfunc_62__15TObjEneMe1GiGueFv(u8 *arg0);
void sub_802CCF2C__15TObjEneMe1GiGueFv(u8 *arg0);
void TObjEneMe1GiGue__sub_802CD054(void);
void draw_model__15TObjEneMe1GiGueFPv(Obj_802CD058 *self);
void run_task__15TObjEneMe1GiGueFv(u8 *arg0);
void *deleting_dtor__15TObjEneMe1GiGueFPvs(void *, s16);

struct Base_802CD5C0_802CD390 { char pad[0xC]; };

struct VObj_802CD5C0_802CD390 : Base_802CD5C0_802CD390 {
    virtual void m0(int);
};

struct Mdl_802CD62C { u8 pad[8]; s32 a; s32 b; };

struct Obj_802CD62C { u8 pad[0x42C]; Mdl_802CD62C *mdl; s32 v430; };

struct Spawn_802CD62C { s32 w[4]; };

struct Sub_802CD62C { u8 pad[0xC]; f32 f; };

extern "C" {
void get_anim_node_position__15TObjEnemyCustomFlP3Vec();
}
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_58__15TObjEneMe1GiGueFv();
}
extern "C" {
void vfunc_60__15TObjEneMe1GiGueFv();
}
extern "C" {
void vfunc_59__15TObjEneMe1GiGueFv();
}
extern "C" {
void vfunc_61__15TObjEneMe1GiGueFv();
}
extern "C" {
void vfunc_28__15TObjEnemyCustomFv();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void recalc_stats__13TUnk_804806E8Fv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_67__13TUnk_804806E8Ff();
}
extern "C" {
void vfunc_66__13TUnk_804806E8Fv();
}
extern "C" {
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__13TUnk_804806E8Fl();
}
extern "C" {
void apply_action_hold_status__13TUnk_804806E8Ff();
}
extern "C" {
void apply_anti_technique__13TUnk_804806E8Fl();
}
extern "C" {
void apply_attack_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void apply_confusion_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_movement_ailment__13TUnk_804806E8Fl();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void apply_poison_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void vfunc_79__15TObjEnemyCustomFv();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void cure_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void cure_poison_ailment__13TUnk_804806E8Fv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_78__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_77__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_76__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_75__13TUnk_804806E8Ff();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void vfunc_9__13TUnk_804806E8Fv();
}
extern "C" {
void get_actor_level_index__13TUnk_804806E8Fv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void is_actor_cadence_frame__13TUnk_804806E8Fl();
}
extern "C" {
void is_target_in_attack_range__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 lbl_80472118[];
}
extern "C" {
extern u8 lbl_80472128[];
}
extern "C" {
extern u8 lbl_8047213C[];
}
extern "C" {
extern u8 lbl_80472150[];
}
extern "C" {
extern u8 lbl_80472168[];
}
extern "C" {
extern u8 lbl_8047217C[];
}
extern "C" {
extern u8 lbl_80472194[];
}
extern "C" {
extern u8 lbl_804721A8[];
}
extern "C" {
extern u8 lbl_804721BC[];
}
extern "C" {
extern u8 lbl_804721D4[];
}
extern "C" {
extern u8 lbl_804721E8[];
}
extern "C" {
extern u8 lbl_804721FC[];
}
extern "C" {
extern u8 lbl_80472214[];
}
extern "C" {
extern u8 lbl_80472228[];
}
extern "C" {
extern u8 lbl_8047223C[];
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__13TUnk_804806E8Fv();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
}
extern "C" {
void select_melee_contact_body__13TUnk_804806E8FPvf();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *TObjEneMe1GiGue__model_filename_table[4];
extern void *me1_gi_gue_motion_filename_table[10];
extern void *lbl_804E1210[4];
extern void *gi_gue_njm_name_table[10];
void *TObjEneMe1GiGue__model_filename_table[4] = {
    (void *)&lbl_80472118, (void *)&lbl_80472128, (void *)&lbl_8047213C, (void *)0x0,
};
void *me1_gi_gue_motion_filename_table[10] = {
    (void *)&lbl_80472150, (void *)&lbl_80472168, (void *)&lbl_8047217C, (void *)&lbl_80472194,
    (void *)&lbl_804721A8, (void *)&lbl_804721BC, (void *)&lbl_804721D4, (void *)&lbl_804721E8,
    (void *)&lbl_804721FC, (void *)0x0,
};
void *lbl_804E1200[4] = {
    (void *)&lbl_80472214, (void *)&TObjEneMe1GiGue__model_filename_table, (void *)&me1_gi_gue_motion_filename_table, (void *)0x30009,
};
void *lbl_804E1210[4] = {
    (void *)&lbl_80472228, (void *)&lbl_80472128, (void *)&lbl_8047213C, (void *)0x0,
};
void *gi_gue_njm_name_table[10] = {
    (void *)&lbl_80472150, (void *)&lbl_80472168, (void *)&lbl_8047217C, (void *)&lbl_80472194,
    (void *)&lbl_804721A8, (void *)&lbl_804721BC, (void *)&lbl_804721D4, (void *)&lbl_804721E8,
    (void *)&lbl_804721FC, (void *)0x0,
};
void *lbl_804E1248[4] = {
    (void *)&lbl_8047223C, (void *)&lbl_804E1210, (void *)&gi_gue_njm_name_table, (void *)0x30009,
};
void *gigue_enemy_param_table[36] = {
    (void *)0x20000, (void *)0x4, (void *)0x3f333333, (void *)0x0,
    (void *)0x10001, (void *)0x3, (void *)0x3f333333, (void *)0x1,
    (void *)0x20000, (void *)0x2, (void *)0x3f19999a, (void *)0x4,
    (void *)0x20007, (void *)0x1, (void *)0x3f19999a, (void *)0x4,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x8,
    (void *)0x20007, (void *)0x0, (void *)0x3f000000, (void *)0x8,
    (void *)0x20007, (void *)0x3, (void *)0x3f333333, (void *)0x1,
    (void *)0x10007, (void *)0x3, (void *)0x3f333333, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3f333333, (void *)0x1,
};
void *lbl_804E12E8[7] = {
    (void *)0x43160000, (void *)0x3eed097b, (void *)0x300, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_804E1304[22] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8001, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x41400000, (void *)0x0,
    (void *)0x0, (void *)0xa000002, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_804E135C[83] = {
    (void *)0x0, (void *)0x0, (void *)&deleting_dtor__15TObjEneMe1GiGueFPvs, (void *)&run_task__15TObjEneMe1GiGueFv,
    (void *)&draw_model__15TObjEneMe1GiGueFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__15TObjEneMe1GiGueFPvf, (void *)&receive_attack__15TObjEneMe1GiGueFPviii,
    (void *)&receive_weapon_special_attack__15TObjEneMe1GiGueFPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__15TObjEnemyCustomFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__15TObjEneMe1GiGueFv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__15TObjEneMe1GiGueFv, (void *)&vfunc_59__15TObjEneMe1GiGueFv,
    (void *)&vfunc_60__15TObjEneMe1GiGueFv, (void *)&vfunc_61__15TObjEneMe1GiGueFv, (void *)&vfunc_62__15TObjEneMe1GiGueFv, (void *)&vfunc_63__15TObjEneMe1GiGueFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__15TObjEnemyCustomFlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__15TObjEnemyCustomFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};

f32 receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll(void *, s32, V_802CAAF0, s32, s32, s32);
f32 receive_weapon_special_attack__13TUnk_804806E8FPvPv();
f32 receive_physical_attack__13TUnk_804806E8FPvf();

f32 TObjEneMe1GiGue::receive_weapon_special_attack(void *, void *) {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;

    var_f31 = 0.0f;
    if (this->m_388 & 0x80000) {
        ((TUnk_804806E8 *)arg0)->show_miss_popup((const float *)(arg0 + 0x2FC));
        ((TObjEneMe1GiGue *)arg0)->set_state(0xA);
    } else {
        var_f31 = receive_weapon_special_attack__13TUnk_804806E8FPvPv();
    }
    return var_f31;
}

f32 receive_attack__15TObjEneMe1GiGueFPviii(S_802CAAF0 *arg0, s32 arg1, V_802CAAF0 arg2, s32 arg3) {
    f32 r = 0.0f;
    if (arg0->f388 & 0x80000) {
        ((TUnk_804806E8 *)arg0)->show_miss_popup((const float *)(arg0->f2FC));
        ((TObjEneMe1GiGue *)arg0)->set_state(10);
    } else {
        r = receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll(arg0, arg1, arg2, arg3, -1, -1);
    }
    return r;
}

f32 TObjEneMe1GiGue::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;

    var_f31 = 0.0f;
    if (this->m_388 & 0x80000) {
        ((TUnk_804806E8 *)arg0)->show_miss_popup((const float *)(arg0 + 0x2FC));
        ((TObjEneMe1GiGue *)arg0)->set_state(0xA);
    } else {
        var_f31 = receive_physical_attack__13TUnk_804806E8FPvf();
    }
    return var_f31;
}

}

struct O_802CAC04 { u8 pad[0x326]; s16 v; };

void TObjEneMe1GiGueBarrier::clear_flag388_bit80000() { *(u32*)((char*)this + 0x388) &= 0xfff7ffff; }
void TObjEneMe1GiGueBarrier__sub_802CABF4(void* p) { *(u32*)((char*)p + 0x388) |= 0x80000; }

u8 TObjEneMe1GiGueBarrier::is_active_state() {
    s32 r = 0;
    s16 v = ((O_802CAC04 *)this)->v;
    if (v == 9) goto yes;
    if (v == 10) goto yes;
    if (v == 11) goto yes;
    if (v == 4) goto yes;
    if (v != 5) goto done;
yes:
    r = 1;
done:
    return r;
}

s32 TObjEneMe1GiGueBarrier::get_field_44c() { return *(s32*)((char*)this + 0x44c); }
s32 TObjEneMe1GiGueBarrier::get_timer() { return this->rotation_y; }
void*TObjEneMe1GiGueBarrier::update_and_get_pos() { TObjEneMe1GiGue__sub_802CB03C((u8 *)this); return (char*)this + 0x3b4; }

struct RecoveredGlobal_802CB03C_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

typedef struct S_802CB10C { u8 pad0[0x3C0]; s32 f3C0; } S_802CB10C;

struct RecoveredGlobal_802CB03C_lbl_8058D490;
struct Vec_802CAD98 { f32 x, y, z; };

struct Vec_802CB170
{
  f32 x;
  f32 y;
  f32 z;
};

struct Tgt_802CB170
{
  u8 pad[0x30];
  u32 flags;
  u8 pad34[4];
  Vec_802CB170 pos;
};

struct Gi_802CB170
{
  u8 pad[0x38];
  Vec_802CB170 pos;
  u8 pad44[0x60 - 0x44];
  s32 angle;
  u8 pad64[0x3C0 - 0x64];
  s32 count;
  s16 list[12];
  u8 pad3dc[0x434 - 0x3DC];
  s32 fov;
  f32 range;
};

extern "C" {
s32 update_if_active__15TObjEneMe1GiGueFl(void *, s32);
s32 project_actor_to_ground(void *, void *, s32);
}
s32 get_gigue_int_parameter(s32, s32);
f32 get_gigue_float_parameter(s32, s32);
extern f32 lbl_805D6840;
extern f32 lbl_805D6844;
extern f32 lbl_805D6848;
extern f32 lbl_805D684C;
extern s32 lbl_805D6850;
extern s32 lbl_805D6854;
extern "C" {
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 set_global_flag__10TObjPlayerFv();
s32 clear_global_state__10TObjPlayerFv();
extern RecoveredGlobal_802CB03C_lbl_8058D490 identity_matrix;
int get_player_data__10TObjPlayerFi(int a0);
extern s32 lbl_805D586C;
f64 atan2_float(f32, f32);
u8 *csnVector(void *, void *, s32);
void vec3_add_to(void *, void *);
void matrix_mult_vec(int, Vec_802CAD98 *, void *);
extern Vec_802CAD98 lbl_80472280;
extern Vec_802CAD98 lbl_8047228C;
extern const f64 TObjEneMe1GiGue__data_80472298;
s16 get_entity_id(void *);
s32 angle_difference_abs(s32, s32);
void subtract_vector(Vec_802CB170 *, Vec_802CB170 *);
s32 update_action_hold_status__13TUnk_804806E8Fv();
s32 *csnVectorUnder(s32, s32, s32, s32);

    extern u32 TObjEneMe1GiGue__data_805D6838;
int TObjEneMe1GiGue::get_barrier_count() {  return TObjEneMe1GiGue__data_805D6838; }

s32 TObjEneMe1GiGue::check_vector_bit(s32 arg1) {
    s32 arg0 = (s32)this;
    s32 *temp_r3;

    temp_r3 = csnVectorUnder(arg1, arg0 + 0x120, 5, arg0);
    if (temp_r3 == NULL) {
        return 0;
    }
    return (u32)__cntlzw(*temp_r3 & 4) >> 5;
}

#pragma push
#pragma fp_contract on
void TObjEneMe1GiGue::sub_802CACD8() {
    s32 temp_r4;
    u8 *arg0 = (u8 *)this;
    temp_r4 = ((TObjEneMe1GiGue *)arg0)->m_388;
    if (temp_r4 & 0x40000) {
        ((TObjEneMe1GiGue *)arg0)->m_388 = (s32) (temp_r4 & 0xFFFBFFFF);
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        project_actor_to_ground(arg0, (u8 *)&this->position, 0);
        return;
    }
    if ((s32) ((TObjEneMe1GiGue *)arg0)->next_action == 7) {
        ((TObjEneMe1GiGue *)arg0)->m_388 = (s32) (temp_r4 & 0xFFFFFFFE);
        update_if_active__15TObjEneMe1GiGueFl(arg0, 0);
    }
}
#pragma pop

s32 TObjEneMe1GiGue::update_action_hold_status() {
    s32 arg0 = (s32)this;
    if (update_action_hold_status__13TUnk_804806E8Fv() != 0) {
        ((TObjEneMe1GiGue *)arg0)->sub_802CACD8();
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void find_open_direction__15TObjEneMe1GiGueFPvPv(u8 *arg0, Vec_802CAD98 *arg1) {
    f32 best;
    s32 ang;
    s32 bestAng;
    s32 i;
    u8 *hit;
    f32 d;
    ang = (s32) (TObjEneMe1GiGue__data_80472298 * atan2_float(arg1->x, arg1->z));
    best = 0.0f;
    bestAng = ang;
    push_matrix_from(&identity_matrix);
    Vec_802CAD98 v = lbl_80472280;
    rotate_matrix_y(0, ang);
    for (i = 0; i < 3; i++) {
        matrix_mult_vec(0, &v, arg0 + 0x390);
        vec3_add_to(arg0 + 0x390, arg0 + 0x2FC);
        hit = csnVector(arg0 + 0x2FC, arg0 + 0x390, -1);
        if (hit == NULL) {
            pop_matrix();
            return;
        }
        d = vec_xz_distance((Vec *)(arg0 + 0x38), *(Vec **)((s8 *)hit + 4)) - 20.0f;
        if (best < d) {
            best = d;
            bestAng = ang;
        }
        rotate_matrix_y(0, 0x5555);
        ang += 0x5555;
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    Vec_802CAD98 w = lbl_8047228C;
    w.x = best;
    rotate_matrix_y(0, bestAng);
    matrix_mult_vec(0, &w, arg0 + 0x390);
    vec3_add_to(arg0 + 0x390, arg0 + 0x2FC);
    pop_matrix();
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe1GiGue::load_params() {
    s32 arg0 = (s32)this;
    lbl_805D6840 = get_gigue_float_parameter(arg0, 1);
    lbl_805D6844 = get_gigue_float_parameter(arg0, 2);
    lbl_805D6848 = get_gigue_float_parameter(arg0, 3);
    lbl_805D684C = get_gigue_float_parameter(arg0, 4);
    lbl_805D6850 = get_gigue_int_parameter(arg0, 0);
    lbl_805D6854 = get_gigue_int_parameter(arg0, 1);
    *(s32 *)((s8 *)arg0 + 0x44C) = (s32) (30.0f * (f32) get_gigue_int_parameter(arg0, 3));
    *(s32 *)((s8 *)arg0 + 0x450) = get_gigue_int_parameter(arg0, 4);
}
#pragma pop

void TObjEneMe1GiGue::update_direction() {
    *(f32 *)((s8 *)this + 0x438) = ((TObjPlayer *)(this->m_318))->get_pos_x();
    this->m_434 = ((TObjPlayer *)(this->m_318))->get_field_0c();
}
typedef char RecoveredGlobal_802CB03C_lbl_8058D490_size[sizeof(RecoveredGlobal_802CB03C_lbl_8058D490) == 0x30 ? 1 : -1];
void TObjEneMe1GiGue__sub_802CB03C(u8 *enemy) {
    push_matrix_from(&identity_matrix.value);
    translate_matrix(0, (f32) (*(f32 *)((s8 *)enemy + 0x38)), (f32) (*(f32 *)((s8 *)enemy + 0x3EC) + (*(f32 *)((s8 *)enemy + 0x3C) + *(f32 *)((s8 *)enemy + 0x3E8))), (f32) (*(f32 *)((s8 *)enemy + 0x40)));
    rotate_matrix_y(0, (int) (((TObjEnemy *)enemy)->rotation_y));
    set_global_flag__10TObjPlayerFv();
    ((TObjEnemy *)enemy)->render_anim_model(((TObjEnemy *)enemy)->m_c0);
    clear_global_state__10TObjPlayerFv();
    pop_matrix();
    ((TObjEnemy *)(enemy))->get_anim_node_position(0, (Vec *)(enemy + 0x3B4));
    ((TObjEnemy *)(enemy))->get_anim_node_position(0x2A, (Vec *)(enemy + 0x39C));
    ((TObjEnemy *)(enemy))->get_anim_node_position(0x16, (Vec *)(enemy + 0x3A8));
}
s32 TObjEneMe1GiGue__sub_802CB10C(S_802CB10C *arg0) {
    s32 i;
    arg0->f3C0 = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        s32 t = get_player_data__10TObjPlayerFi(i);
        add_target_in_cone__15TObjEneMe1GiGueFPvPv((Gi_802CB170 *)(arg0), (Tgt_802CB170 *)(t));
    }
    return arg0->f3C0;
}
typedef struct Gi_802CB170 Gi_802CB170;
typedef struct Tgt_802CB170 Tgt_802CB170;
typedef struct Vec_802CB170 Vec_802CB170;
void add_target_in_cone__15TObjEneMe1GiGueFPvPv(Gi_802CB170 *self, Tgt_802CB170 *t) {
  int new_var;
  if ((((self->count < 12) && (t != 0)) && (((void *) t) != ((void *) self))) && (!(t->flags & 0x06000800)))
  {
    Vec_802CB170 v = t->pos;
    subtract_vector(&v, &self->pos);
    if (!(((v.x * v.x) + (v.z * v.z)) > (self->range * self->range)))
    {
      new_var = (-((s32) (((const f64 *)&TObjEneMe1GiGue__data_80472298)[0] * atan2_float(v.z, v.x)))) + 0x4000;
      if (angle_difference_abs(new_var, self->angle) <= (self->fov / 2))
      {
        self->list[self->count++] = get_entity_id(t);
      }
    }
  }
}
}

typedef struct { f32 x, y, z; } Vec_802CB378;
extern "C" {
s32 apply_actor_gravity(void *, int, f32);
s32 calc_velocity_toward_destination(void *, void *, void *, f32);
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, s32, s32))update_if_active__15TObjEneMe1GiGueFl)
s32 sub_8004292C__15TObjEnemyCustomFv(void *);
void *spawn_particle_effect(void *pos, s32 id);
s32 advance_animation_playback(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(void *, void *, s32, s32);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
s32 play_area_sound_effect__12TBoss3VoloptFv(void *, s32);

}

struct Base410 { char pad[0x14]; };
struct VObj410 : Base410 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual s32 m5(); virtual void m6();
};

void init__15TObjEneMe1GiGueFPv(u8 *arg0) {
    s32 temp_r4;
    s32 temp_r5;

    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) | 4);
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x30) | 0x04000000;
        *(s32 *)((s8 *)arg0 + 0x30) = temp_r4;
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        play_area_sound_effect__12TBoss3VoloptFv(arg0 + 0x2FC, temp_r4);
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x3FC);
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
    case 1:
        advance_animation_playback(arg0);
        if (((VObj410 *)(arg0 + 0x3FC))->m5() == 1) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
            play_sound_effect((void *)TObjEneMe1GiGue::remap_sound_id((arg0), 0x3A345), arg0 + 0x38, 0, 0);
        }
        ((TObjPlayer *)arg0)->update_collisions();
        return;
    case -1:
        temp_r5 = *(s32 *)((s8 *)arg0 + 0x388);
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (temp_r5 & ~5);
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFBFFFFFF);
        update_if_active__15TObjEneMe1GiGueFl(arg0, 0, temp_r5);
        return;
    }
}
void TObjEneMe1GiGue__sub_802CB378(u8 *arg0) {
    f32 temp_f3;
    s32 temp_r0_2;
    s32 temp_r6;
    u8 *temp_r3;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(arg0 + 0x50));
        ((void (*)(void *, Vec_802CB378, Vec_802CB378, f32))calc_velocity_toward_destination)(arg0, *(Vec_802CB378 *)((s8 *)arg0 + 0x38), *(Vec_802CB378 *)((s8 *)arg0 + 0x390), *(f32 *)((s8 *)arg0 + 0x3E4));
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) & 0xFFFBFFFF);
        sub_8004292C__15TObjEnemyCustomFv(arg0);
        *(f32 *)((s8 *)arg0 + 0x3EC) = (f32) *(f32 *)((s8 *)arg0 + 0x43C);
        *(s16 *)((s8 *)arg0 + 0xB8) = 7;
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
    case 1:
        advance_animation_playback(arg0);
        temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xA4));
        *(s32 *)((s8 *)temp_r3 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x44) | 1);
        *(f32 *)((s8 *)arg0 + 0x3EC) += (-2.3f);
        temp_f3 = *(f32 *)((s8 *)arg0 + 0x3EC);
        if (temp_f3 <= 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x3EC) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) | 0x800000);
            *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFEFFFFFF);
            *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
            if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) != 8) {
                *(s32 *)((s8 *)arg0 + 0x37C) = -1;
                play_sound_effect((void *)TObjEneMe1GiGue::remap_sound_id((arg0), 0x3A345), arg0 + 0x38, 0, 0);
            }
        } else if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == 7) {
            if (temp_f3 <= (2.3f * (40.0f + (1.0f / *(f32 *)((s8 *)arg0 + 0xCC))))) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 8;
            }
        } else {
            temp_r0_2 = (s32) *(f32 *)((s8 *)arg0 + 0xC0);
            if (((temp_r0_2 == 0x14) || (temp_r0_2 == 0x28)) && (((TObjEneMe1GiGue *)arg0)->check_vector_bit((s32)(arg0 + 0x38)) != 0)) {
                spawn_particle_effect((arg0 + 0x38), 0xF0);
            }
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(arg0, 0x3A819)), (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
        ((TObjPlayer *)arg0)->update_collisions();
        break;
    case -1:
        ((void (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 1);
        break;
    }
    apply_actor_gravity(arg0, 0, (f32) (0.0f));
}

#undef update_if_active__15TObjEneMe1GiGueFl

#include <dolphin/mtx.h>

#include <stddef.h>

struct Vec_802CB8F0 { f32 x, y, z; };

struct Sub_802CB8F0 { u8 pad0[8]; s32 f8; };

struct Obj_802CB8F0 {
    u8 pad0[0x38];
    Vec_802CB8F0 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x29C - 0x64];
    Vec_802CB8F0 v29C;
    u8 pad2A8[0x350 - 0x2A8];
    Sub_802CB8F0 *f350;
    u8 pad354[0x390 - 0x354];
    Vec_802CB8F0 v390;
    u8 pad39C[0x3E4 - 0x39C];
    f32 f3E4;
};

struct Obj_802CB8F0;
struct Vec_802CB8F0;

struct Vec_802CBA98 { f32 x, y, z; };

struct Vec_802CCBAC { f32 x, y, z; };

struct Sub_802CCBAC { f32 f0; u8 pad4[4]; s32 f8; };

struct Tgt_802CCBAC { u8 pad0[0x38]; Vec_802CCBAC pos; u8 pad44[0x2FC - 0x44]; Vec_802CCBAC v2FC; };

struct Obj_802CCBAC {
    u8 pad0[0x30]; u32 f30; u8 pad34[4]; Vec_802CCBAC pos; u8 pad44[0x60 - 0x44];
    s32 f60; u8 pad64[0xB8 - 0x64]; s16 fB8; u8 padBA[0x29C - 0xBA];
    Vec_802CCBAC v29C; Tgt_802CCBAC *f2A8; u8 pad2AC[0x350 - 0x2AC];
    Sub_802CCBAC *f350; u8 pad354[0x37C - 0x354]; s32 f37C; u8 pad380[8]; u32 f388;
    u8 pad38C[0x3DC - 0x38C]; s32 f3DC; f32 f3E0; f32 f3E4; u8 pad3E8[0x3F8 - 0x3E8];
    s32 f3F8; u8 pad3FC[0x434 - 0x3FC]; s32 f434; f32 f438; u8 pad43C[0x448 - 0x43C]; s32 f448;
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
extern void *TObjEneMe1GiGue__barrier_obj;
f32 calc_boss4_scale__10TObjPlayerFi(void *);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 enemy_set_heading_velocity(void *, f32, s32);
s32 enemy_turn_toward_dest(void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
u16 find_nearest_visible_player(void *, int, f32);
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
s32 find_target_in_range__15TObjEnemyCustomFf(void *, f32);
#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
s32 create__9TTecJelinFllll(void *, void *, void *, s32);
s32 create_instance__9TTecZaruaFllll(void *, void *, void *, s32);
#define TObjEneMe1GiGue__sub_802CB10C ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CB10C)
s32 update_enemy_collision_flags__10TObjPlayerFv(void *);
s32 check_enemy_body_collisions(void *);
s32 check_object_collisions__10TObjPlayerFv(void *);
s32 check_path_obstructed(void *, Vec_802CBA98 *);
void *find_entity_by_id(u16 id);
s32 enemy_wander_home__9TObjEnemyFlfff(void *, s32, f32, f32, f32);
#define subtract_vector ((void (*)(void *, void *))subtract_vector)
u32 get_player_by_client_id(s32);

s32 TObjEneMe1GiGue::remap_sound_id(void *obj, s32 id) {
    s32 st = get_current_area();
    if (id == 0x3A344) return st == 0x23 ? 0x40039E14 : id;
    if (id == 0x3A345) return st == 0x23 ? 0x40039415 : id;
    return ((s32 (*)(void *, s32))copy_target_state__14TObjEnePanarmsFPv)(obj, id);
}

void TObjEneMe1GiGue::apply_hit_shake(u32 arg1) {
    if ((arg1 == get_player_by_client_id(0)) && ((s32) this->m_3f4 <= 0)) {
        this->m_3f4 = 0x1E;
        TCameraCtrl::set_shake_preset(1);
    }
}

void TObjEneMe1GiGue::init_move() {
    VecCopy((Vec *)(((u8 *)this) + 0x44), (const Vec *)(((u8 *)this) + 0x38));
    this->actorFlags = (s32) (this->actorFlags | 0x01000000);
    update_if_active__15TObjEneMe1GiGueFl(this, 0xE);
    this->m_378 = 1;
    refresh_collision_body_centers();
}

#pragma fp_contract on

void TObjEneMe1GiGue::sub_802CB6D4() {
    switch (this->mode) {
    case 0:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            if (find_nearest_visible_player(this, 0, **(f32 * *)&this->movementParameters) != 0xFFFF) {
                find_target_in_range__15TObjEnemyCustomFf(this, **(f32 * *)&this->movementParameters);
                if (this->m_388 & 0x40000) {
                    init_move();
                } else {
                    update_if_active__15TObjEneMe1GiGueFl(this, 1);
                }
            }
        }
        break;
    case 1:
        if (find_nearest_visible_player(this, 0, 50.0f) != 0xFFFF) {
            if (calc_boss4_scale__10TObjPlayerFi(this) <= this->m_444) {
                update_if_active__15TObjEneMe1GiGueFl(this, 0xB);
            } else {
                update_if_active__15TObjEneMe1GiGueFl(this, 0xD);
                this->m_378 = 1;
            }
        } else if (find_nearest_visible_player(this, 0, 50.0f + **(f32 * *)&this->movementParameters) == 0xFFFF) {
            update_if_active__15TObjEneMe1GiGueFl(this, 0);
        }
        break;
    case 13:
        break;
    }
}

#define arg0 ((u8 *)arg0_)
void TObjEneMe1GiGue__sub_802CB824(void *arg0_, s32 arg1) {
    void *p;
    u8 *slot = arg0 + arg1 * 2;
    if (find_entity_by_id(*(u16 *)(slot + 0x3C4)) != 0) {
        IV3_802CB824 v;
        v.x = 0;
        v.y = *(s32 *)(arg0 + 0x60) + ((arg1 & 1) ? -0x2000 : 0x2000);
        v.z = 0;
        p = __nw__7TObjectFUl(0x10C);
        if (p != 0) {
            f32 lim = get_gigue_float_parameter((s32)((s32)arg0), 5);
            TObjPlayer__sub_802CDEB4(p, arg0 + 0x3A8, *(u16 *)(slot + 0x3C4), &v, arg1 * 3,
                                     calc_boss4_scale__10TObjPlayerFi(arg0) <= lim, *(u16 *)(arg0 + 0x1C));
        }
    }
}
#undef arg0

void move_around_center__15TObjEneMe1GiGueFPvPvf(Obj_802CB8F0 *o, Vec_802CB8F0 *c, f32 r) {
    if (xz_distance_squared((Vec *)&o->pos, (Vec *)&o->v390) < 400.0f) {
        s32 k = (s32)(182.04445f * (360.0f * calc_boss4_scale__10TObjPlayerFi(o)));
        f32 d = 0.4f * (r * (1.0f + calc_boss4_scale__10TObjPlayerFi(o)));
        o->v390.x = d * cos_table_lookup(k) + c->x;
        o->v390.z = d * sin_table_lookup(k) + c->z;
    }
    VecCopy((Vec *)&o->v29C, (const Vec *)&o->v390);
    enemy_turn_toward_dest(o, o->f350->f8);
    enemy_set_heading_velocity(o, o->f3E4, o->f60);
    move_with_wall_slide((u8 *)o);
}

void TObjEneMe1GiGue::break_apart() {
    Vec position;
    VecCopy((Vec *)(&position.x), (const Vec *)(((u8 *)this) + 0x38));
    position.y += 40.0f + this->m_3ec;
    TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe1GiGue__barrier_obj, 0, this->texture_id, (s32)((void *)&position.x), this->rotation_y);
    ((TObjPlayer *)((u8 *)this))->refresh_lobby_state();
    this->send_entity_set_flags();
    spawn_particle_effect((&position.x), 0x205);
    spawn_particle_effect((&position.x), 0x206);
    play_sound_effect((void *) (TObjEneMe1GiGue::remap_sound_id((this), 0x3AF1C)), &position.x, 0, 0);
    queue_destruction__7TObjectFv((this));
}

void TObjEneMe1GiGue::update_hit_reaction() {
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_r5;
    s16 temp_r4;
    s16 var_r3;
    s32 entity;
    s32 var_r30;
    switch (this->state) {
    case 0:
        var_r3 = 4;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        if (this->actorFlags & 0x01000000) {
            var_r3 = 5;
        }
        this->m_b8 = var_r3;
        spawn_particle_effect(((u8 *)this) + 0x2FC, 0xF2);
        this->state = 1;
    case 1:
        advance_animation_playback(this);
        if (!(this->actorFlags & 0x01000000)) {
            Vec_802CBA98 v = *(Vec_802CBA98 *)((s8 *)((u8 *)this) + 0x2FC);
            v.x += *(f32 *)((s8 *)((u8 *)this) + 0x308);
            v.z += this->m_310;
            if (check_path_obstructed(this, &v) == 0) {
                move_with_wall_slide(((u8 *)this));
            } else {
                *(f32 *)((s8 *)((u8 *)this) + 0x308) = this->m_310 = 0.0f;
            }
            *(f32 *)((s8 *)((u8 *)this) + 0x308) *= 0.5f;
            this->m_310 *= 0.5f;
        }
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)((u8 *)this))->update_collisions();
        if ((u32) this->m_b4 != 8U) {
            this->state = -1;
        }
        break;
    case -1:
        var_r30 = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        this->m_388 = (s32) (this->m_388 & 0xFFFFFFFE);
        this->m_378 = 1;
        temp_r4 = this->referenceHp;
        if (((s32) (temp_r4 - this->hp) > (s32) (temp_r4 / 4)) && !(this->actorFlags & 2)) {
            entity = (s32)find_entity_by_id(this->m_2d4);
            if (entity != 0) {
                var_r30 = 1;
                if ((this->actorFlags & 0x01000000) && (xz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)((u8 *)entity + 0x38)) > 400.0f)) {
                    var_r30 = 0;
                }
            }
        }
        if (var_r30 == 1) {
            this->targetId = (u16) this->m_2d4;
            this->next_action = 9;
        } else if (this->actorFlags & 0x01000000) {
            update_if_active__15TObjEneMe1GiGueFl(this, 0xD);
            this->m_378 = (s32) this->m_380;
        } else {
            update_if_active__15TObjEneMe1GiGueFl(this, 0);
        }
        this->referenceHp = (s16) this->hp;
        break;
    }
}
}
#undef play_sound_effect
#undef update_if_active__15TObjEneMe1GiGueFl
#undef apply_actor_gravity
#undef sub_8004292C__15TObjEnemyCustomFv
#undef TObjEneMe1GiGue__sub_802CB10C
#undef subtract_vector

struct Vec_802CBCC0 { f32 x, y, z; };
struct Sub_802CBCC0 { f32 f0; u8 pad4[4]; s32 f8; };
struct A4_802CBCC0 { u8 pad0[0x44]; u32 f44; };

struct Obj_802CBCC0 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[4];
    Vec_802CBCC0 pos;
    Vec_802CBCC0 prev;
    Vec_802CBCC0 v50;
    u8 pad5C[0xA4 - 0x5C];
    A4_802CBCC0 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0xCC - 0xC4];
    f32 fCC;
    u8 padD0[0x2A8 - 0xD0];
    u8 *f2A8;
    u8 pad2AC[0x308 - 0x2AC];
    Vec_802CBCC0 v308;
    u8 pad314[0x350 - 0x314];
    Sub_802CBCC0 *f350;
    u8 pad354[0x374 - 0x354];
    s32 f374;
    u8 pad378[4];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[4];
    Vec_802CBCC0 dest;
    u8 pad39C[0x3E4 - 0x39C];
    f32 f3E4;
    u8 pad3E8[4];
    f32 f3EC;
    u8 pad3F0[0x3F8 - 0x3F0];
    s32 f3F8;
    u8 pad3FC[0x440 - 0x3FC];
    f32 f440;
    u8 pad444[0x454 - 0x444];
    s32 f454;
};

extern "C" {

#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#define calc_velocity_toward_destination ((s32 (*)(void *, f32, Vec_802CBCC0, Vec_802CBCC0))calc_velocity_toward_destination)
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#define csnVector ((u32 (*)(void *, void *, s32))csnVector)
s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0);
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
#define find_open_direction__15TObjEneMe1GiGueFPvPv ((s32 (*)(void *, void *))find_open_direction__15TObjEneMe1GiGueFPvPv)
#define subtract_vector ((void (*)(void *, void *))subtract_vector)

void update_rush_attack__15TObjEneMe1GiGueFPv(Obj_802CBCC0 *o) {
    switch (o->state) {
    case 0:
        o->f30 |= 0x800000;
        o->f30 &= ~0x1000000;
        o->fB8 = o->state = 1;
        o->f3EC = 0.0f;
        o->f454 = 0x3C;
        ((s32 (*)(void *))sub_8004292C__15TObjEnemyCustomFv)(o);
        break;
    case 1:
        o->f30 &= ~0x1000000;
        enemy_wander_home__9TObjEnemyFlfff(o, o->f350->f8, o->f3E4, 100.0f, 50.0f);
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, 0.0f);
        o->f454--;
        if (o->f454 <= 0) {
            o->state = 2;
            play_sound_effect((void *)TObjEneMe1GiGue::remap_sound_id((o), 0x3A818), &o->pos, 0, 0);
            o->f30 |= 0x1000000;
            o->f30 &= ~0x800000;
            ((s32 (*)(void *, Sub_802CBCC0 *, f32))find_target_in_range__15TObjEnemyCustomFf)(o, o->f350, o->f350->f0);
            if (o->f2A8 != NULL) {
                Vec_802CBCC0 d;
                VecCopy((Vec *)&d, (const Vec *)&o->pos);
                subtract_vector(&d, o->f2A8 + 0x38);
                find_open_direction__15TObjEneMe1GiGueFPvPv(o, &d);
                calc_velocity_toward_destination(o, o->f3E4, o->pos, o->dest);
            } else {
                VecCopy((Vec *)&o->dest, (const Vec *)&o->v50);
                calc_velocity_toward_destination(o, o->f3E4, o->pos, o->dest);
            }
        }
        check_object_collisions__10TObjPlayerFv(o);
        check_enemy_body_collisions(o);
        update_enemy_collision_flags__10TObjPlayerFv(o);
        break;
    case 2: {
        s32 ok;
        o->f30 &= ~0x800000;
        advance_animation_playback(o);
        calc_velocity_toward_destination(o, get_gigue_float_parameter((s32)o, 0), o->pos, o->dest);
        ok = 1;
        if (o->fB8 == 6 && o->fC0 < 22.0f) {
            ok = 0;
        }
        if (ok) {
            o->f3EC += 2.2f;
        }
        ((TObjPlayer *)o)->update_collisions();
        if (TObjPlayer__sub_800DC478((u8 *)o, 1, 22.0f) != 0 && ((TObjEneMe1GiGue *)o)->check_vector_bit((s32)&o->pos) != 0) {
            spawn_particle_effect(&o->pos, 0xF0);
        }
        if (o->f3EC >= 50.0f) {
            o->state = 3;
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(o, 0x3A819)), (s32)o, (u32)&o->pos, 0, 0);
        break;
    }
    case 3:
        advance_animation_playback(o);
        calc_velocity_toward_destination(o, get_gigue_float_parameter((s32)o, 0), o->pos, o->dest);
        o->v308.y = 0.0f;
        VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
        vec3_add_to(&o->pos, &o->v308);
        if (csnVector(&o->prev, &o->pos, 0x88E0) != 0) {
            VecCopy((Vec *)&o->pos, (const Vec *)&o->prev);
            o->state = 4;
            o->v308.x = o->v308.z = 0.0f;
        } else {
            if (xz_distance_squared((Vec *)&o->pos, (Vec *)&o->dest) <= (10.0f + o->f3E4) * (10.0f + o->f3E4)) {
                o->state = 4;
                o->v308.x = o->v308.z = 0.0f;
            }
        }
        if (objInBand((GameObj *)o, (f32)(10.0f)) != 0 && ((TObjEneMe1GiGue *)o)->check_vector_bit((s32)&o->pos) != 0) {
            spawn_particle_effect(&o->pos, 0xF0);
        }
        ((TUnk_804AF8A0 *)o)->refresh_collision_body_centers();
        if (o->f3EC > 15.0f) {
            ((TObjPlayer *)o)->update_angle(o->f350->f8 * 2, &o->v308);
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(o, 0x3A819)), (s32)o, (u32)&o->pos, 0, 0);
        project_actor_to_ground(o, &o->pos, 0);
        break;
    case 4:
        o->f30 &= ~0x800000;
        o->fA4->f44 |= 1;
        advance_animation_playback(o);
        o->f3EC += (-2.3f);
        if (o->f3EC <= 0.0f) {
            o->f3EC = 0.0f;
            o->f30 |= 0x800000;
            o->f30 &= ~0x1000000;
            o->v308.y = 0.0f;
            if (o->fB8 != 8) {
                if (!(o->f388 & 0x80000) && calc_boss4_scale__10TObjPlayerFi(o) <= o->f440) {
                    update_if_active__15TObjEneMe1GiGueFl(o, 0xC);
                } else {
                    update_if_active__15TObjEneMe1GiGueFl(o, 0);
                }
            }
        } else if (o->fB8 == 7) {
            if (o->f3EC <= 2.3f * (40.0f + 1.0f / o->fCC)) {
                o->fB8 = 8;
            }
        } else {
            s32 t = (s32)o->fC0;
            if ((t == 0x14 || t == 0x28) && ((TObjEneMe1GiGue *)o)->check_vector_bit((s32)&o->pos) != 0) {
                spawn_particle_effect(&o->pos, 0xF0);
            }
        }
        play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(o, 0x3A819)), (s32)o, (u32)&o->pos, 0, 0);
        check_object_collisions__10TObjPlayerFv(o);
        check_enemy_body_collisions(o);
        update_enemy_collision_flags__10TObjPlayerFv(o);
        apply_actor_gravity(o, 0, 0.0f);
        break;
    case -1:
        if (o->f374 != 4 && o->f374 != 5) {
            o->f3EC = 0.0f;
        }
        o->fA4->f44 &= ~1;
        o->f388 &= ~0x40000;
        o->f3F8 = 0;
        break;
    }
}

#undef calc_velocity_toward_destination
#undef csnVector
#undef find_open_direction__15TObjEneMe1GiGueFPvPv
#undef apply_actor_gravity
#undef update_if_active__15TObjEneMe1GiGueFl
#undef sub_8004292C__15TObjEnemyCustomFv
#undef play_sound_effect
#undef subtract_vector
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#define TObjEneMe1GiGue__sub_802CB10C ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CB10C)
#define subtract_vector ((void (*)(void *, void *))subtract_vector)
void action__15TObjEneMe1GiGueFPv(void *enemy) {

    switch (*(s32 *)((s8 *)enemy + 0x37C)) {
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        *(s32 *)((s8 *)enemy + 0x388) = (s32) (*(s32 *)((s8 *)enemy + 0x388) & 0xFFFBFFFF);
        *(s16 *)((s8 *)enemy + 0xB8) = 1;
        *(s32 *)((s8 *)enemy + 0x37C) = 1;
        return;
    case 1:
        TObjEneMe1GiGueBarrier::create(enemy, enemy);
        *(s32 *)((s8 *)enemy + 0x37C) = 2;
        *(s32 *)((s8 *)enemy + 0x384) = 0x2D;
        advance_animation_playback(enemy);
        apply_actor_gravity(enemy, 0, 0.0f);
        ((TObjPlayer *)enemy)->update_collisions();
        return;
    case 2:
        enemy_wander_home__9TObjEnemyFlfff(enemy, *(s32 *)((s8 *)(*(void **)((s8 *)enemy + 0x350)) + 8), *(f32 *)((s8 *)enemy + 0x3E4), 100.0f, 100.0f);
        advance_animation_playback(enemy);
        apply_actor_gravity(enemy, 0, 0.0f);
        ((TObjPlayer *)enemy)->update_collisions();
        *(s32 *)((s8 *)enemy + 0x384) = (s32) (*(s32 *)((s8 *)enemy + 0x384) - 1);
        if ((s32) *(s32 *)((s8 *)enemy + 0x384) <= 0) {
            update_if_active__15TObjEneMe1GiGueFl(enemy, 0);
        }
    case -1:
        return;
    }
}

void TObjEneMe1GiGue__sub_802CC45C(u8 *arg0) {
    s32 r;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case -1:
        break;
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        r = 0;
        if (!(*(s32 *)((s8 *)arg0 + 0x30) & 0x01000000)) {
            r = TObjEneMe1GiGue__sub_802CB10C(arg0);
        }
        if (r > 0) {
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
            *(s16 *)((s8 *)arg0 + 0xB8) = 3;
        } else if (*(s32 *)((s8 *)arg0 + 0x30) & 0x01000000) {
            update_if_active__15TObjEneMe1GiGueFl(arg0, 0xD);
        } else {
            update_if_active__15TObjEneMe1GiGueFl(arg0, 0);
        }
        *(s32 *)((s8 *)arg0 + 0x388) &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
        case 1:
            if (*(f32 *)((s8 *)arg0 + 0xC0) >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C(arg0);
                spawn_particle_effect(arg0 + 0x3A8, 0x204);
                *(s32 *)((s8 *)arg0 + 0x37C) = 2;
            }
            break;
        case 2:
            play_sound_effect((void *)TObjEneMe1GiGue::remap_sound_id((arg0), 0x3A344), arg0 + 0x38, 0, 0);
            if (*(f32 *)((s8 *)arg0 + 0xC0) >= 10.0f) {
                TObjEneMe1GiGue__sub_802CB03C(arg0);
                *(s32 *)((s8 *)arg0 + 0x37C) = 3;
                create_instance__9TTecZaruaFllll(arg0, arg0 + 0x2FC, arg0 + 0x2FC, get_gigue_int_parameter((s32)arg0, 2));
                create__9TTecJelinFllll(arg0, arg0 + 0x2FC, arg0 + 0x2FC, get_gigue_int_parameter((s32)arg0, 2));
            }
            break;
    }
        advance_animation_playback(arg0);
        apply_actor_gravity(arg0, 0, 0.0f);
        ((TObjPlayer *)arg0)->update_collisions();
        if (*(s16 *)((s8 *)arg0 + 0xB8) != 3) {
            update_if_active__15TObjEneMe1GiGueFl(arg0, 0xD);
        }
        break;
    }
}

#undef play_sound_effect
#undef update_if_active__15TObjEneMe1GiGueFl
#undef apply_actor_gravity
#undef sub_8004292C__15TObjEnemyCustomFv
#undef TObjEneMe1GiGue__sub_802CB10C
#undef subtract_vector
#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#define TObjEneMe1GiGue__sub_802CB10C ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CB10C)

void TObjEneMe1GiGue__sub_802CC614(u8 *enemy) {
    s32 n;
    s32 r;

    switch (*(s32 *)((s8 *)enemy + 0x37C)) {
    case -1:
        break;
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        r = 0;
        if (!(*(s32 *)((s8 *)enemy + 0x30) & 0x01000000)) {
            r = TObjEneMe1GiGue__sub_802CB10C(enemy);
        }
        if (r > 0) {
            *(s16 *)((s8 *)enemy + 0xB8) = 3;
            *(s32 *)((s8 *)enemy + 0x384) = *(s32 *)((s8 *)enemy + 0x450);
            if (*(s32 *)((s8 *)enemy + 0x384) <= 0x14) {
                *(s32 *)((s8 *)enemy + 0x384) = 0x14;
            }
            *(s32 *)((s8 *)enemy + 0x37C) = 1;
        } else if (*(s32 *)((s8 *)enemy + 0x30) & 0x01000000) {
            update_if_active__15TObjEneMe1GiGueFl(enemy, 0xD);
        } else if (!(*(s32 *)((s8 *)enemy + 0x388) & 0x80000) && calc_boss4_scale__10TObjPlayerFi(enemy) <= *(f32 *)((s8 *)enemy + 0x440)) {
            update_if_active__15TObjEneMe1GiGueFl(enemy, 0xC);
        } else {
            update_if_active__15TObjEneMe1GiGueFl(enemy, 0);
        }
        *(s32 *)((s8 *)enemy + 0x388) &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (*(s32 *)((s8 *)enemy + 0x37C)) {
        case 1:
            if (*(f32 *)((s8 *)enemy + 0xC0) >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C(enemy);
                *(s32 *)((s8 *)enemy + 0x37C) = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(enemy, 0x3A820)), (s32)enemy, (u32)(enemy + 0x38), 0, 0);
            if (*(f32 *)((s8 *)enemy + 0xC0) >= 10.0f) {
                TObjEneMe1GiGue__sub_802CB03C(enemy);
                n = *(s32 *)((s8 *)enemy + 0x3C0);
                TObjEneMe1GiGue__sub_802CB824(enemy, (s32)((s32)((f32)n * calc_boss4_scale__10TObjPlayerFi(enemy)) % n));
                *(s32 *)((s8 *)enemy + 0x37C) = 3;
            }
            break;
        }
        advance_animation_playback(enemy);
        apply_actor_gravity(enemy, 0, 0.0f);
        ((TObjPlayer *)enemy)->update_collisions();
        (*(s32 *)((s8 *)enemy + 0x384))--;
        if (*(s32 *)((s8 *)enemy + 0x384) <= 0) {
            (*(s32 *)((s8 *)enemy + 0x448))++;
            if (*(s32 *)((s8 *)enemy + 0x448) >= 3) {
                *(s32 *)((s8 *)enemy + 0x384) = 0x2D;
                *(s16 *)((s8 *)enemy + 0xB8) = 1;
                *(s32 *)((s8 *)enemy + 0x37C) = 4;
            } else {
                *(s32 *)((s8 *)enemy + 0x37C) = 0;
                *(f32 *)((s8 *)enemy + 0xC0) = 0.0f;
            }
        }
        break;
    case 4:
        enemy_wander_home__9TObjEnemyFlfff(enemy, *(s32 *)((s8 *)(*(u8 **)((s8 *)enemy + 0x350)) + 8), *(f32 *)((s8 *)enemy + 0x3E4), 100.0f, 100.0f);
        advance_animation_playback(enemy);
        apply_actor_gravity(enemy, 0, 0.0f);
        ((TObjPlayer *)enemy)->update_collisions();
        (*(s32 *)((s8 *)enemy + 0x384))--;
        if (*(s32 *)((s8 *)enemy + 0x384) <= 0) {
            if (!(*(s32 *)((s8 *)enemy + 0x388) & 0x80000) && calc_boss4_scale__10TObjPlayerFi(enemy) <= *(f32 *)((s8 *)enemy + 0x440)) {
                update_if_active__15TObjEneMe1GiGueFl(enemy, 0xC);
            } else {
                update_if_active__15TObjEneMe1GiGueFl(enemy, 0);
            }
        }
        break;
    }
}

}

#undef TObjEneMe1GiGue__sub_802CB10C
#undef apply_actor_gravity
#undef update_if_active__15TObjEneMe1GiGueFl
#undef sub_8004292C__15TObjEnemyCustomFv
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
#undef play_sound_effect
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#undef update_if_active__15TObjEneMe1GiGueFl
#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#undef apply_actor_gravity
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#undef sub_8004292C__15TObjEnemyCustomFv
#define TObjEneMe1GiGue__sub_802CB10C ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CB10C)
#undef TObjEneMe1GiGue__sub_802CB10C
#define subtract_vector ((void (*)(void *, void *))subtract_vector)
#undef subtract_vector

struct Vec_802CC900 { f32 x, y, z; };

struct Obj_802CC900 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_802CC900 pos;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x29C - 0xC4];
    Vec_802CC900 v29C;
    u8 *f2A8;
    u8 pad2AC[0x378 - 0x2AC];
    s32 f378;
    s32 state;
    u8 pad380[0x384 - 0x380];
    s32 f384;
    u32 f388;
    u8 pad38C[0x39C - 0x38C];
    u8 f39C[0x440 - 0x39C];
    f32 f440;
    u8 pad444[0x450 - 0x444];
    s32 f450;
};

extern "C" {

#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
s32 enemy_turn_half_toward_dest(void *);
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
extern Vec_802CC900 lbl_80472274[];

void TObjEneMe1GiGue__sub_802CC900(u8 *arg0) {
    Obj_802CC900 *o = (Obj_802CC900 *)arg0;
    u32 r;

    switch (o->state) {
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        o->f384 = o->f450;
        if (o->f384 <= 0x28) {
            o->f384 = 0x28;
        }
        if (!(o->f30 & 0x01000000)) {
            o->fB8 = 2;
            goto set1;
        }
        update_if_active__15TObjEneMe1GiGueFl(o, 0xD);
        o->f388 &= ~0x40000;
        break;
    set1:
        o->state = 1;
        advance_animation_playback(o);
        o->f388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        if (o->f2A8 == NULL) {
            o->state = 4;
            break;
        }
        switch (o->state) {
        case 1:
            if (o->fC0 >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C((u8 *)o);
                o->state = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(TObjEneMe1GiGue::remap_sound_id(o, 0x3A81D)), (s32)o, (u32)&o->pos, 0, 0);
            if (o->fC0 >= 20.0f) {
                TObjEneMe1GiGue__sub_802CB03C((u8 *)o);
                if ((r = (u32)spawn_particle_effect(o->f39C, 0x203)) != 0) {
                    Vec_802CC900 v = lbl_80472274[0];
                    ((TBoss4Type2 *)r)->copy_vec3(&v);
                }
                TObjEneMe1GiGueMissile::create((s32)o, (s32)o->f39C, (s32)(o->f2A8 + 0x2FC), (f32)lbl_805D6840, (f32)lbl_805D6850);
                play_sound_effect((void *)TObjEneMe1GiGue::remap_sound_id((o), 0x3A31E), &o->pos, 0, 0);
                o->state = 3;
            }
            break;
        }
        VecCopy((Vec *)&o->v29C, (const Vec *)(o->f2A8 + 0x2FC));
        enemy_turn_half_toward_dest(o);
        advance_animation_playback(o);
        if (!(o->f30 & 0x01000000)) {
            apply_actor_gravity(o, 0, 0.0f);
        }
        ((TObjPlayer *)o)->update_collisions();
        if (--o->f384 <= 0) {
            o->state = 4;
        }
        break;
    case 4:
        if (o->f30 & 0x01000000) {
            o->f378 = 0;
            update_if_active__15TObjEneMe1GiGueFl(o, 0xD);
        } else if (!(o->f388 & 0x80000) && calc_boss4_scale__10TObjPlayerFi(o) <= o->f440) {
            update_if_active__15TObjEneMe1GiGueFl(o, 0xC);
        } else {
            update_if_active__15TObjEneMe1GiGueFl(o, 0);
        }
        break;
    case -1:
        break;
    }
}

#undef play_sound_effect
#undef apply_actor_gravity
#undef update_if_active__15TObjEneMe1GiGueFl
#undef sub_8004292C__15TObjEnemyCustomFv
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
#define update_if_active__15TObjEneMe1GiGueFl ((s32 (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)
#define apply_actor_gravity ((s32 (*)(void *, s32, f32))apply_actor_gravity)
#define sub_8004292C__15TObjEnemyCustomFv ((s32 (*)())sub_8004292C__15TObjEnemyCustomFv)
#define TObjEneMe1GiGue__sub_802CB10C ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CB10C)
#define subtract_vector ((void (*)(void *, void *))subtract_vector)
void TObjEneMe1GiGue__sub_802CCBAC(Obj_802CCBAC *o) {
    o->f30 &= ~0x01000000;
    switch (o->f37C) {
    case 0:
        o->f388 &= ~0x00040000;
        sub_8004292C__15TObjEnemyCustomFv();
        o->fB8 = 1;
        o->f3DC = 0;
        if (o->f2A8 != NULL) {
            VecCopy((Vec *)&o->v29C, (const Vec *)&o->f2A8->v2FC);
        }
        o->f37C = 1;
    case 1:
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, 0.0f);
        if (o->f2A8 != NULL) {
            Vec_802CCBAC d = o->f2A8->pos;
            subtract_vector(&d, &o->pos);
            if (d.x * d.x + d.z * d.z <= o->f438 * o->f438 &&
                angle_difference_abs(-(s32)(TObjEneMe1GiGue__data_80472298 * atan2_float(d.z, d.x)) + 0x4000, o->f60) < o->f434 / 2) {
                s32 st;
                o->f3F8++;
                if (o->f3F8 > 2) {
                    o->f3F8 = 0;
                    st = 0xD;
                } else {
                    o->f448 = 0;
                    st = 9;
                }
                update_if_active__15TObjEneMe1GiGueFl(o, st);
                break;
            }
        }
        o->f60 += o->f350->f8 / 2;
        enemy_set_heading_velocity(o, o->f3E4, o->f60);
        move_with_wall_slide((u8 *)o);
        o->f3DC += o->f350->f8 / 2;
        if (o->f3DC > 0x10000) {
            o->f3E0 = 0.0f;
            o->f37C = 2;
        }
        break;
    case -1:
        break;
    case 2:
        ((s32 (*)(f32, f32, f32, void *, s32))enemy_wander_home__9TObjEnemyFlfff)(o->f3E4, 100.0f, 50.0f, o, o->f350->f8);
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, 0.0f);
        o->f3E0 += o->f3E4;
        if (o->f3E0 > 100.0f) {
            if (find_target_in_range__15TObjEnemyCustomFf(o, o->f350->f0) != 0) {
                o->f3DC = 0;
                o->f37C = 1;
            } else {
                update_if_active__15TObjEneMe1GiGueFl(o, 0);
            }
        }
        check_object_collisions__10TObjPlayerFv(o);
        check_enemy_body_collisions(o);
        update_enemy_collision_flags__10TObjPlayerFv(o);
        break;
    }
}

void TObjEneMe1GiGue::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    ((TObjEneMe1GiGue *)arg0)->set_state(5);
    this->m_380 = (s32) this->m_378;
    this->m_378 = 5;
    this->m_388 = (s32) (this->m_388 | 1);
}
void TObjEneMe1GiGue::vfunc_62() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  temp_r0 = *((s16 *) (((s8 *) arg0) + 0x326));
  if (temp_r0 != 0xC)
  {
    if (temp_r0 < 0xC)
    {
      if (temp_r0 < 0xA)
      {
        arg0++;
        arg0--;
        goto block_6;
      }
      goto block_5;
    }
    if (temp_r0 < 0xE)
    {
      block_5:
      *((s16 *) (((s8 *) arg0) + 0x33E)) = (s16) (*((s16 *) (((s8 *) arg0) + 0x32C)));
      *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) & 0xFFFFFDFF);
      return;
    }
    goto block_6;
  }
  block_6:
  ((TObjEneMe1GiGue *)arg0)->set_state(4);
  *((s32 *) (((s8 *) arg0) + 0x380)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x378)));
  *((s32 *) (((s8 *) arg0) + 0x378)) = 4;
  *((s32 *) (((s8 *) arg0) + 0x388)) = (s32) (((*((s32 *) (((s8 *) arg0) + 0x388))) | 0x10000) | 1);
}
void TObjEneMe1GiGue::sub_802CCF2C() {
    if (this->m_388 & 0x40000) {
        return;
    }
    switch (this->state) {
    case -1:
        break;
    case 0:
        this->m_b8 = 1;
        this->state = 1;
        this->m_384 = 0x96;
        ((void (*)(u8 *)) sub_8004292C__15TObjEnemyCustomFv)(((u8 *)this));
    case 1:
        advance_animation_playback(this);
        move_around_center__15TObjEneMe1GiGueFPvPvf((Obj_802CB8F0 *) this, (Vec_802CB8F0 *) (((u8 *)this) + 0x50), *(f32 *)((s8 *)((u8 *)this) + 0x358));
        this->m_384 -= 1;
        if (this->m_384 <= 0) {
            this->m_b8 = 0;
            this->state = 2;
            this->m_384 = 0x5A;
        }
        check_object_collisions__10TObjPlayerFv(this);
        check_enemy_body_collisions(this);
        update_enemy_collision_flags__10TObjPlayerFv(this);
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation_playback(this);
        check_object_collisions__10TObjPlayerFv(this);
        check_enemy_body_collisions(this);
        update_enemy_collision_flags__10TObjPlayerFv(this);
        this->m_384 -= 1;
        if (this->m_384 <= 0) {
            this->state = 0;
        }
        break;
    }
}

#undef play_sound_effect
#undef update_if_active__15TObjEneMe1GiGueFl
#undef apply_actor_gravity
#undef sub_8004292C__15TObjEnemyCustomFv
#undef TObjEneMe1GiGue__sub_802CB10C
#undef subtract_vector
s32 is_split_screen();
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 TLobby__sub_8001FE7C(s32, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 init_from_model__11TBreakUpMdlFl(s32, s32);
s32 update_obstruction_fade(void *);
s32 find_active_entity_by_id(int);
void * TObjControl__ct(void *, void *);
s32 submit_cursor_candidate(void *, int);
s32 minimap_render_dot(void *, int, int, int);
#define load_params__15TObjEneMe1GiGueFv ((s32 (*)(void *))load_params__15TObjEneMe1GiGueFv)
#define sub_802CB6D4__15TObjEneMe1GiGueFv ((s32 (*)(void *))sub_802CB6D4__15TObjEneMe1GiGueFv)
#define update_rush_attack__15TObjEneMe1GiGueFPv ((s32 (*)(void *))update_rush_attack__15TObjEneMe1GiGueFPv)
#define TObjEneMe1GiGue__sub_802CCBAC ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CCBAC)
#define sub_802CCF2C__15TObjEneMe1GiGueFv ((s32 (*)(void *))sub_802CCF2C__15TObjEneMe1GiGueFv)
u8 *TObjEneMe1GiGue__ct(u8 *, s32, u8 *);
void TObjEneMe1GiGue__sub_802CDAE8();
void TObjEneMe1GiGue__sub_802CE4E8(void);
void TObjEneMe1GiGue__sub_802CE4EC();
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);

extern s32 TObjEneMe1GiGue__param_table;
extern Spawn_802CD62C gigue_spawn_descriptor;
extern s32 ene_me1_gigue_boss_id;
extern s32 lbl_805D682C;
extern s32 lbl_805D6830;
extern void *tl_04;

void TObjEneMe1GiGue__sub_802CD054(void) {  }
}
#undef load_params__15TObjEneMe1GiGueFv
#undef sub_802CB6D4__15TObjEneMe1GiGueFv
#undef update_rush_attack__15TObjEneMe1GiGueFPv
#undef TObjEneMe1GiGue__sub_802CCBAC
#undef sub_802CCF2C__15TObjEneMe1GiGueFv
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Vec_802CD058 { f32 x, y, z; };

struct SubBase_802CD058 { u8 pad[0x14]; };
struct Sub_802CD058 : SubBase_802CD058 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
    u8 pad18[4];
};

struct ObjBase_802CD058 { u8 pad[0x18]; };
struct Obj_802CD058 : ObjBase_802CD058 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
    u8 pad1c[0x24 - 0x1c];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    u32 f30;
    s32 f34;
    Vec_802CD058 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    u8 pad6c[0x2fc - 0x6c];
    u8 f2fc[0x388 - 0x2fc];
    u32 f388;
    u8 pad38c[0x3e8 - 0x38c];
    f32 f3e8;
    f32 f3ec;
    u8 pad3f0[0x3fc - 0x3f0];
    Sub_802CD058 s3fc;
    Sub_802CD058 s418;
};

extern "C" {

void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
#define rotate_matrix_y ((void (*)(s32, s32))rotate_matrix_y)
void push_matrix(void);
void draw_chunk_object(void *child);
#define set_global_flag__10TObjPlayerFv ((void (*)(void))set_global_flag__10TObjPlayerFv)
#define clear_global_state__10TObjPlayerFv ((void (*)(void))clear_global_state__10TObjPlayerFv)
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

#pragma fp_contract on
void draw_model__15TObjEneMe1GiGueFPv(Obj_802CD058 *self) {
    s32 vis;
    s32 ok;

    if (self->f30 & 0x2000000) {
        return;
    }
    if (get_current_area() == 0x23) {
        vis = self->m9(600.0f, 600.0f, 20.0f);
    } else {
        vis = self->m9(150.0f, 400.0f, 20.0f);
    }
    if (vis == 0) {
        return;
    }
    if (TObjPlayer::check_demo_mode() != 1 && (self->f388 & 0x40000)) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (((RenderFadeState *)(&self->s418))->updateFromCamera((const f32*)(self->f2fc)) != 0) {
        self->s418.m6();
        if (defer_render__7TObjectFv(self) != 0) {
            model_render_flags = saved_model_render_flags;
            return;
        }
    }
    TObjFish::set_global_param(self->f24);
    select_actor_lighting((s32)self);
    TObjPlayer::toggle_particle_effect();
    ok = 1;
    push_matrix();
    translate_matrix(0, self->pos.x, self->f3ec + (self->pos.y + self->f3e8), self->pos.z);
    rotate_matrix_y(0, self->f60);
    model_render_flags &= ~0x400;
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object((void *)self->f34);
    } else if (self->f388 & 4) {
        if (self->s3fc.m8() != 0) {
            self->s3fc.m6();
            if (vis == 1) {
                set_global_flag__10TObjPlayerFv();
                ((TObjMotion *)self)->draw();
                clear_global_state__10TObjPlayerFv();
            } else {
                set_global_flag__10TObjPlayerFv();
                ((TObjEnemy *)self)->render_world_model();
                clear_global_state__10TObjPlayerFv();
            }
            self->s3fc.m7();
        } else {
            ok = 0;
        }
    } else {
        if (vis == 1) {
            set_global_flag__10TObjPlayerFv();
            ((TObjMotion *)self)->draw();
            clear_global_state__10TObjPlayerFv();
        } else {
            set_global_flag__10TObjPlayerFv();
            ((TObjEnemy *)self)->render_world_model();
            clear_global_state__10TObjPlayerFv();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    TParticleCtrl::end_effect_render();
    if (!(self->f30 & 0x800) && ok != 0) {
        Vec_802CD058 v;
        v.x = v.y = v.z = (1.0f - 0.01f * self->f3ec) * (5.0f * self->f68);
        ((TObjEnemy *)self)->render_with_position_override((u8 *)&v, 0);
    }
    self->s418.m7();
    model_render_flags = saved_model_render_flags;
}

#undef rotate_matrix_y
#undef set_global_flag__10TObjPlayerFv
#undef clear_global_state__10TObjPlayerFv
#define load_params__15TObjEneMe1GiGueFv ((s32 (*)(void *))load_params__15TObjEneMe1GiGueFv)
#define sub_802CB6D4__15TObjEneMe1GiGueFv ((s32 (*)(void *))sub_802CB6D4__15TObjEneMe1GiGueFv)
#define update_rush_attack__15TObjEneMe1GiGueFPv ((s32 (*)(void *))update_rush_attack__15TObjEneMe1GiGueFPv)
#define TObjEneMe1GiGue__sub_802CCBAC ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CCBAC)
#define sub_802CCF2C__15TObjEneMe1GiGueFv ((s32 (*)(void *))sub_802CCF2C__15TObjEneMe1GiGueFv)
void TObjEneMe1GiGue::dispatch_state() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        sub_802CCF2C__15TObjEneMe1GiGueFv((void *) arg0);
        return;
      case 1:
        TObjEneMe1GiGue__sub_802CCBAC((void *) arg0);
        return;
      case 2:
        TObjEneMe1GiGue__sub_802CDAE8();
        return;
      case 3:
        ((TObjEnemyCustom *)arg0)->update_state_machine();
        return;
      case 4:
        ((TObjEneMe1GiGue *)arg0)->update_hit_reaction();
        return;
      case 5:
        ((TObjEneMe1GiGue *)arg0)->break_apart();
        return;
      case 9:
        TObjEneMe1GiGue__sub_802CC614(arg0);
        return;
      case 10:
        TObjEneMe1GiGue__sub_802CC900(arg0);
        return;
      case 11:
        TObjEneMe1GiGue__sub_802CC45C(arg0);
        return;
      case 12:
        action__15TObjEneMe1GiGueFPv(arg0);
        return;
      case 13:
        update_rush_attack__15TObjEneMe1GiGueFPv((void *) arg0);
        return;
      case 7:
        init__15TObjEneMe1GiGueFPv(arg0);
        return;
      case 14:
        TObjEneMe1GiGue__sub_802CB378(arg0);
        break;
    }
  }
}

void TObjEneMe1GiGue::run_task() {
    s32 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *arg0 = (u8 *)this;

    if (TObjPlayer::check_demo_mode() == 1) {
        load_params__15TObjEneMe1GiGueFv(arg0);
        ((s32 (*)(void *))TObjEneMe1GiGue__sub_802CD054)(arg0);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x2A8) = find_active_entity_by_id((int) (((TObjEneMe1GiGue *)arg0)->targetId));
    ((TObjEnemyCustom *)arg0)->release_destroyed_target();
    sub_802CB6D4__15TObjEneMe1GiGueFv(arg0);
    if ((s16) ((TObjEneMe1GiGue *)arg0)->mode != (s32) ((TObjEneMe1GiGue *)arg0)->next_action) {
        if ((s32) ((TObjEneMe1GiGue *)arg0)->state != -1) {
            ((TObjEneMe1GiGue *)arg0)->state = -1;
            ((TObjEneMe1GiGue *)arg0)->dispatch_state();
        }
        ((TObjEneMe1GiGue *)arg0)->mode = (s16) ((TObjEneMe1GiGue *)arg0)->next_action;
        ((TObjEneMe1GiGue *)arg0)->state = 0;
    }
    ((TObjEneMe1GiGue *)arg0)->dispatch_state();
    if ((s32) ((TObjEneMe1GiGue *)arg0)->state == -1) {
        ((TObjEneMe1GiGue *)arg0)->state = -1;
        ((TObjEneMe1GiGue *)arg0)->dispatch_state();
        ((TObjEneMe1GiGue *)arg0)->mode = (s16) ((TObjEneMe1GiGue *)arg0)->next_action;
        ((TObjEneMe1GiGue *)arg0)->state = 0;
    }
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    ((TObjEneMe1GiGue *)arg0)->m_300 = (f32) (((TObjEneMe1GiGue *)arg0)->m_300 + (15.0f + ((TObjEneMe1GiGue *)arg0)->m_3ec));
    *(f32 *)((s8 *)(((TObjEneMe1GiGue *)arg0)->m_a4) + 4) = (f32) (25.0f + ((TObjEneMe1GiGue *)arg0)->m_3ec);
    if (!(((TObjEneMe1GiGue *)arg0)->m_388 & 0x40000)) {
        submit_cursor_candidate(arg0, -1);
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    }
    temp_r3 = ((TObjEneMe1GiGue *)arg0)->m_3f4;
    if (temp_r3 > 0) {
        ((TObjEneMe1GiGue *)arg0)->m_3f4 = (temp_r3 - 1);
    }
    temp_r3_2 = (unsigned char *) (((TObjEneMe1GiGue *)arg0)->m_a4);
    *(s32 *)((s8 *)temp_r3_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x18) & 0xFFFFFFF9);
    if (((TObjEneMe1GiGue *)arg0)->m_3ec > 5.0f) {
        temp_r3_3 = (unsigned char *) (((TObjEneMe1GiGue *)arg0)->m_a4);
        *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 4);
    } else {
        temp_r3_4 = (unsigned char *) (((TObjEneMe1GiGue *)arg0)->m_a4);
        *(s32 *)((s8 *)temp_r3_4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_4 + 0x18) | 2);
    }
    update_obstruction_fade((u8 *)&this->m_418);
    if (xz_distance_squared((Vec *)&this->position, &this->prev_position) > 2500.0f) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x44));
    }
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
}

void *TObjEneMe1GiGue::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x458);
    if (o2 != NULL) {
        o2 = ((void *(*)(void *, void *, void *))TObjEneMe1GiGue__ct)(o2, o, arg0);
    }
    return o2;
}

void TObjEneMe1GiGue::delete_barrier() {
    TObjEneMe1GiGueBarrier__sub_80325CC0();
    TObjEneMe1GiGue__sub_802CE4E8();
    if (TObjEneMe1GiGue__barrier_obj != NULL) {
        if (TObjEneMe1GiGue__barrier_obj != NULL) {
            ((VObj_802CD5C0_802CD390*)TObjEneMe1GiGue__barrier_obj)->m0(1);
        }
        TObjEneMe1GiGue__barrier_obj = NULL;
    }
    if (TObjEneMe1GiGue__data_805D6838 != 0U) {
        TLobby__sub_8001FE7C(TObjEneMe1GiGue__data_805D6838, 1);
        TObjEneMe1GiGue__data_805D6838 = 0U;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 getf_802CD62C(Sub_802CD62C *q) { return q->f; }
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TObjEneMe1GiGue::load_resources() {
    s32 o;
    Sub_802CD62C *q;

    if (is_split_screen() != 0) {
        o = (int)::operator new(0x440);
        if (o != 0) {
            o = (s32)load_resource_from_descriptor((void *)o, 1, lbl_804E1248, 0, 0, 0);
        }
        TObjEneMe1GiGue__data_805D6838 = o;
    } else {
        o = (int)::operator new(0x440);
        if (o != 0) {
            o = (s32)load_resource_from_descriptor((void *)o, 1, lbl_804E1200, 0, 0, 0);
        }
        TObjEneMe1GiGue__data_805D6838 = o;
    }
    ene_me1_gigue_boss_id = register_boss__6TLobbyFl(0x1A);
    lbl_805D682C = dispatch_shared_handler_b__6TLobbyFl(0x1A);
    lbl_805D6830 = register_object__6TLobbyFl(0x1A);
    TObjEneMe1GiGue__param_table = dispatch_shared_handler_a__6TLobbyFl(0x1A);
    o = (int)::operator new(0x10);
    if (o != 0) {
        o = init_from_model__11TBreakUpMdlFl(o, ((Obj_802CD62C *)TObjEneMe1GiGue__data_805D6838)->mdl->a);
    }
    TObjEneMe1GiGue__barrier_obj = (void *)o;
    TObjEneMe1GiGue__sub_802CE4EC();
    TObjEneMe1GiGueBarrier::init_global();
    q = (Sub_802CD62C *)lbl_804E1304;
    {
    Spawn_802CD62C sp = gigue_spawn_descriptor;
    sp.w[0] = ((Obj_802CD62C *)TObjEneMe1GiGue__data_805D6838)->v430;
    TLobby::spawn_npc_enemy((s16)0x41, (s32)(((Obj_802CD62C *)TObjEneMe1GiGue__data_805D6838)->mdl->a), (s32)(((Obj_802CD62C *)TObjEneMe1GiGue__data_805D6838)->mdl->b), (s32)&sp, (f32)(getf_802CD62C(q)), (f32)15.0f);
    }
}
#pragma pop

}

#undef load_params__15TObjEneMe1GiGueFv
#undef sub_802CB6D4__15TObjEneMe1GiGueFv
#undef update_rush_attack__15TObjEneMe1GiGueFPv
#undef TObjEneMe1GiGue__sub_802CCBAC
#undef sub_802CCF2C__15TObjEneMe1GiGueFv

struct E_802CDAEC { s32 a; s32 b; s32 c; s32 d; };
struct G_802CDAEC { u8 pad[0x42c]; E_802CDAEC *e; };
struct O_802CDAEC { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };
struct G_802CDAC4 { u8 pad[0x18]; s32 v[1]; };

extern "C" {
void free_collision_body_parts(void *);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 obj_setFlags30(void *, int);
s32 __ct__15TObjEnemyCustomFP7TObject(void *, s32);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern s32 lbl_805D3F18;

#define GIGUE_DATA_6838 ((G_802CDAEC *)TObjEneMe1GiGue__data_805D6838)

void *deleting_dtor__15TObjEneMe1GiGueFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = lbl_804E135C;
        free_collision_body_parts(arg0);
        __dt__13TUnk_804949A8Fv((s8 *)arg0 + 0x418, -1);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3FC, -1);
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneMe1GiGue__ct(u8 *arg0, s32 enemy_custom, u8 *arg2) {
    __ct__15TObjEnemyCustomFP7TObject(arg0, enemy_custom);
    *(void **)((s8 *)arg0 + 0x18) = lbl_804E135C;
    ((TUnk_80494938 *)(arg0 + 0x3FC))->init_common();
    ((TObjPlayer *)(arg0 + 0x418))->init_and_activate();
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3F18;
    ((TObjEneMe1GiGue *)arg0)->apply_set_data(arg2);
    VecCopy((Vec *)(arg0 + 0x290), (const Vec *)((void *) VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x38))));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)GIGUE_DATA_6838 + 0x430);
    ((TObjEneMe1GiGue *)arg0)->variant = 0;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(0x11);
    ((TObjEneMe1GiGue *)arg0)->state36C = *(s16 *)((s8 *)arg2 + 0x3E);
    ((TObjEneMe1GiGue *)arg0)->load_params_from_table(((TObjEneMe1GiGue *)arg0)->variant);
    ((TObjEneMe1GiGue *)arg0)->action_table = gigue_enemy_param_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(((TObjEneMe1GiGue *)arg0)->action_table));
    init_collision_body_parts(arg0, lbl_804E1304, 2);
    *(u32 *)((s8 *)(((TObjEneMe1GiGue *)arg0)->m_a4) + 0x44) &= ~1;
    ((TObjEneMe1GiGue *)arg0)->movementParameters = lbl_804E12E8;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)ene_me1_gigue_boss_id, (u8 *)lbl_805D682C, (u8 *)lbl_805D6830);
    ((TObjEneMe1GiGue *)arg0)->update_direction();
    ((void (*)(void *))load_params__15TObjEneMe1GiGueFv)(arg0);
    ((TObjEneMe1GiGue *)arg0)->m_b8 = 0;
    ((TObjMotion *)arg0)->set_animation(((TObjEneMe1GiGue *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TObjEneMe1GiGue *)arg0)->m_b8);
    ((TObjEneMe1GiGue *)arg0)->hp = ((TObjEneMe1GiGue *)arg0)->hpmax;
    ((TObjEneMe1GiGue *)arg0)->tp = ((TObjEneMe1GiGue *)arg0)->tpmax;
    ((TObjEneMe1GiGue *)arg0)->referenceHp = ((TObjEneMe1GiGue *)arg0)->hp;
    ((TObjEnemy *)arg0)->update_prev_position();
    initialize_enemy_photon_effect(arg0);
    ((TObjEneMe1GiGue *)arg0)->m_38c = 0;
    ((TObjEneMe1GiGue *)arg0)->scale.x = 1.0f;
    ((TObjEneMe1GiGue *)arg0)->m_3e4 = *(f32 *)((s8 *)(((TObjEneMe1GiGue *)arg0)->movementParameters) + 4) * ((TObjEneMe1GiGue *)arg0)->scale.x;
    VecCopy((Vec *)(arg0 + 0x50), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x440) = 0.5f + *(f32 *)((s8 *)arg0 + 0x360);
    ((TObjEneMe1GiGue *)arg0)->m_444 = 0.5f + *(f32 *)((s8 *)arg0 + 0x364);
    ((TObjEneMe1GiGue *)arg0)->m_43c = 150.0f + *(f32 *)((s8 *)arg0 + 0x35C);
    if (((TObjEneMe1GiGue *)arg0)->m_43c < 0.0f) {
        ((TObjEneMe1GiGue *)arg0)->m_43c = 0.0f;
    }
    if ((s32) *(f32 *)((s8 *)arg0 + 0x354) >= 1) {
        ((TObjEneMe1GiGue *)arg0)->m_388 |= 0x40000;
        if (*(f32 *)((s8 *)arg0 + 0x358) < 1.0f) {
            *(f32 *)((s8 *)arg0 + 0x358) = 50.0f;
        }
        ((TObjEnemyCustom *)arg0)->set_flags_30();
    }
    ((TObjEneMe1GiGue *)arg0)->m_3f4 = 0;
    ((TObjEneMe1GiGue *)arg0)->m_3f8 = 0;
    ((TObjEnemy *)arg0)->set_param(0x37);
    *(f32 *)((s8 *)arg0 + 0x3E8) = 0.0f;
    ((TObjEneMe1GiGue *)arg0)->m_448 = 0;
    if (((TObjEneMe1GiGue *)arg0)->m_388 & 0x40000) {
        ((TObjEneMe1GiGue *)arg0)->init_move();
    } else {
        ((TObjEnemyCustom *)arg0)->sub_800C7860();
    }
    project_actor_to_ground(arg0, arg0 + 0x38, 0);
    ((TObjEneMe1GiGue *)arg0)->m_3ec = 0.0f;
    ((TObjPlayer *)(arg0 + 0x418))->activate_and_dispatch();
    obj_setFlags30(arg0, 0x01000000);
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
    ((TObjEneMe1GiGue *)arg0)->clear_lobby_object_state();
    return arg0;
}

void TObjEneMe1GiGue::vfunc_58() {  }
void TObjEneMe1GiGue::vfunc_60() {  }
void TObjEneMe1GiGue::vfunc_59() {  }
void TObjEneMe1GiGue::vfunc_61() {  }
}

s32 get_gigue_int_parameter(s32 self, s32 i) {
    return (*(G_802CDAC4 * *)&TObjEneMe1GiGue__param_table)->v[i];
}

f32 get_gigue_float_parameter(s32 arg0, s32 arg1) {
    return *(f32 *)((s8 *)(TObjEneMe1GiGue__param_table + (arg1 * 4)) + 0);
}

void TObjEneMe1GiGue__sub_802CDAE8(void) {  }

void TObjEneMe1GiGue::load_params_from_table(s32 i) {
    O_802CDAEC *self = (O_802CDAEC *)this;
    self->f34 = GIGUE_DATA_6838->e[i].c;
    self->f24 = GIGUE_DATA_6838->e[i].d;
}
#undef GIGUE_DATA_6838
