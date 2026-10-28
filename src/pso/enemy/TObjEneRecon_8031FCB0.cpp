#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneRecobox.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/boss/TBoss8Dragon.h"

#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"

extern "C" {

struct Obj_8031FE14 { u8 pad[0x18]; void *vt; };

struct VBase_18_b2458f { char pad[0x18]; };

struct VObj_18_b2458f : VBase_18_b2458f {
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
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
    virtual s32 m86();
};

struct Sub_8031FE98 { u8 b[0x1C]; };

struct Self_8031FE98 { u8 pad[0x3FC]; s32 f3fc[4]; u8 pad40c[0x418 - 0x40C]; u16 f418[6]; u16 f424[30]; Sub_8031FE98 subs[4]; };

void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void init_object__12TObjEneDD_STFv(void *, s32, void *);
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, int);
void init_model__9TObjEneDDFv(void *, void *, int);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
void init_and_activate__10TObjPlayerFv();
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void TObjEneRecon__sub_8031F408(void *arg0, s32 arg1);
void TObjEneRecon__sub_8031F600(void *arg0, s32 arg1);
void dispatch_state__12TObjEneReconFiUii(s32 arg0, u32 arg1, s32 arg2);
void run_task__14TObjEneRecoboxFv(u8 *arg0);
Obj_8031FE14 * fn_8031FE14(Obj_8031FE14 *arg0, s16 arg1);
void __destroy_arr(void *, void *, int, int);
void __construct_array(void *, void *, void *, int, int);

extern u8 *TObjEneRecobox__static_instance;
extern s32 TObjEneRecobox_name_ref;
extern s32 recobox_boss_register_id;
extern s32 lbl_805D6B14;
extern s32 TObjEneRecobox__shared_object_handle;
extern const f32 lbl_805DF464;
extern const f32 lbl_805DF468;
extern const f32 lbl_805DF46C;

extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFv();
extern "C" void TObjEneDD__vt82();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int TObjEneEpsilon__vt101(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void draw_with_debug_info__14TObjEneRecoboxFv();
extern "C" void render__14TObjEneRecoboxFv(u8 *arg0);
extern "C" void TObjEneRecon__sub_8031FB6C(u8 *arg0);
extern "C" void vfunc_61__14TObjEneRecoboxFv();
extern "C" void vfunc_62__14TObjEneRecoboxFv();
extern "C" void vfunc_28__14TObjEneRecoboxFv();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void recalc_stats__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_804806E8Fv();
extern "C" void vfunc_58__13TUnk_804806E8Fv();
extern "C" void apply_slow_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void interact__13TUnk_804AF8A0Fl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__13TUnk_804806E8Fl();
extern "C" void apply_action_hold_status__13TUnk_804806E8Ff();
extern "C" void apply_anti_technique__13TUnk_804806E8Fl();
extern "C" void apply_attack_stat_status__13TUnk_804806E8FPv();
extern "C" void apply_confusion_status__13TUnk_804806E8Fv();
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_movement_ailment__13TUnk_804806E8Fl();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_paralysis__13TUnk_804806E8Fv();
extern "C" void apply_poison_status__13TUnk_804806E8Fv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__13TUnk_804806E8Fv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void clear_harmful_statuses__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void vfunc_9__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();
extern "C" u8 lbl_80476118[];
extern "C" u8 lbl_80476124[];
extern "C" u8 lbl_80476134[];
extern "C" u8 lbl_80476144[];
extern "C" u8 lbl_8047615C[];
extern "C" u8 lbl_80476174[];
extern "C" u8 lbl_8047618C[];
extern "C" u8 lbl_804761A4[];
extern "C" u8 lbl_804761C0[];
extern "C" u8 lbl_804761D8[];
extern "C" u8 lbl_804761F4[];
extern "C" u8 lbl_80476208[];
extern "C" u8 lbl_80476220[];
extern "C" u8 lbl_80476234[];
extern "C" u8 lbl_8047624C[];
extern "C" u8 lbl_80476260[];
extern "C" u8 lbl_80476274[];
extern "C" u8 lbl_80476288[];
extern "C" u8 lbl_80476298[];
extern "C" u8 lbl_804762AC[];
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void vfunc_63__14TObjEneRecoboxFv();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_if_800BB858__14TObjEneRecoboxFv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
extern void *lbl_804EC6B0[7];
extern void *recobox_motion_name_table[11];
extern void *lbl_804EC708[7];
extern void *TObjEneRecobox__resource_bundle[11];
void *TObjEneRecobox__attack_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EC684[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EC6B0[7] = {
    (void *)&lbl_80476118, (void *)&lbl_80476124, (void *)&lbl_80476134, (void *)&lbl_80476144,
    (void *)&lbl_8047615C, (void *)&lbl_80476174, (void *)0x0,
};
void *recobox_motion_name_table[11] = {
    (void *)&lbl_8047618C, (void *)&lbl_804761A4, (void *)&lbl_804761C0, (void *)&lbl_804761D8,
    (void *)&lbl_804761F4, (void *)&lbl_80476208, (void *)&lbl_80476220, (void *)&lbl_80476234,
    (void *)&lbl_8047624C, (void *)&lbl_80476260, (void *)0x0,
};
void *lbl_804EC6F8[4] = {
    (void *)&lbl_80476274, (void *)&lbl_804EC6B0, (void *)&recobox_motion_name_table, (void *)0x6000a,
};
void *lbl_804EC708[7] = {
    (void *)&lbl_80476288, (void *)&lbl_80476298, (void *)&lbl_80476134, (void *)&lbl_80476144,
    (void *)&lbl_8047615C, (void *)&lbl_80476174, (void *)0x0,
};
void *TObjEneRecobox__resource_bundle[11] = {
    (void *)&lbl_8047618C, (void *)&lbl_804761A4, (void *)&lbl_804761C0, (void *)&lbl_804761D8,
    (void *)&lbl_804761F4, (void *)&lbl_80476208, (void *)&lbl_80476220, (void *)&lbl_80476234,
    (void *)&lbl_8047624C, (void *)&lbl_80476260, (void *)0x0,
};
void *lbl_804EC750[4] = {
    (void *)&lbl_804762AC, (void *)&lbl_804EC708, (void *)&TObjEneRecobox__resource_bundle, (void *)0x6000a,
};
void *TObjEneRecobox__animation_entries[16] = {
    (void *)0x10000, (void *)0x1, (void *)0x3dcccccd, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x3, (void *)0x3dcccccd, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f19999a, (void *)0x0,
};
void *TObjEneRecobox__vtable[107] = {
    (void *)0x0, (void *)0x0, (void *)&fn_8031FE14, (void *)&run_task__14TObjEneRecoboxFv,
    (void *)&render__14TObjEneRecoboxFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__14TObjEneRecoboxFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__14TObjEneRecoboxFv, (void *)&vfunc_62__14TObjEneRecoboxFv, (void *)&vfunc_63__14TObjEneRecoboxFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state__12TObjEneReconFiUii,
    (void *)&TObjEneRecon__sub_8031FB6C, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&update_if_800BB858__14TObjEneRecoboxFv, (void *)&draw_with_debug_info__14TObjEneRecoboxFv,
};
#define TObjEneRecobox__attack_params ((u8 *)TObjEneRecobox__attack_params)
#define lbl_804EC684 ((u8 *)lbl_804EC684)
#define TObjEneRecobox__animation_entries ((u8 *)TObjEneRecobox__animation_entries)
#define TObjEneRecobox__vtable ((u8 *)TObjEneRecobox__vtable)

void dispatch_state__12TObjEneReconFiUii(s32 ene_dd, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        ((TObjEneRecobox *)ene_dd)->sub_8031F6C0(arg2);
        return;
    case 1:
        ((TObjEneRecon *)ene_dd)->handle_state(arg2);
        return;
    case 2:
        TObjEneRecon__sub_8031F600((void *)ene_dd, (arg2));
        return;
    case 3:
        ((TObjEneRecon *)ene_dd)->update_state(arg2);
        return;
    case 4:
        ((TObjEneRecon *)ene_dd)->handle_action_state(arg2);
        return;
    case 5:
        TObjEneRecon__sub_8031F408((void *)ene_dd, (arg2));
        return;
    case 6:
        ((TObjEneRecon *)ene_dd)->handle_death_state(arg2);
    default:
        return;
    }
}

void TObjEneRecobox::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_if_800BB858();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else if ((s16) this->mode == 1) {
        transition_enemy_state(0);
    }
    this->vfunc_88();
    ((TObjEneRecon *)((u8 *)this))->restore_position();
    ((TBoss8Dragon *)((u8 *)this))->set_player_state_default();
    this->vfunc_100();
    this->update_floor_probe();
}

Obj_8031FE14 *fn_8031FE14(Obj_8031FE14 *arg0, s16 arg1) {
    if (arg0 != 0) {
        arg0->vt = TObjEneRecobox__vtable;
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x460, ((u8 *)__dt__13TUnk_804949A8Fv), 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3C0, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneRecobox__ct(u8 *ene_recobox, s32 arg1, u8 *arg2) {
    Self_8031FE98 *S = (Self_8031FE98 *)ene_recobox;
    s32 i;
    s32 n;
    init_object__12TObjEneDD_STFv(ene_recobox, arg1, arg2);
    *(u8 **)((s8 *)ene_recobox + 0x18) = TObjEneRecobox__vtable;
    ((TUnk_80494938 *)(ene_recobox + 0x3C0))->init_common();
    __construct_array(ene_recobox + 0x460, (void *)&init_and_activate__10TObjPlayerFv, (void *)&__dt__13TUnk_804949A8Fv, 0x1C, 4);
    *(s32 *)((s8 *)ene_recobox + 0) = TObjEneRecobox_name_ref;
    invoke_initialization_hook__9TObjEneDDFv(ene_recobox, arg2);
    ((TObjEneDD *)ene_recobox)->init_position_vectors();
    *(s32 *)((s8 *)ene_recobox + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x18);
    ((TObjEneRecobox *)ene_recobox)->texture_id = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecobox__static_instance + 0x42C)) + 0x1C);
    init_model__9TObjEneDDFv(ene_recobox, lbl_804EC684, 1);
    ((TObjEneRecobox *)ene_recobox)->m_300 = lbl_805DF464 + *(f32 *)((s8 *)ene_recobox + 0x3C);
    ((TObjEneRecobox *)ene_recobox)->vfunc_88();
    ((TObjMotion *)ene_recobox)->set_field_d8((s32)TObjEneRecobox__animation_entries);
    ((TObjMotion *)ene_recobox)->set_field_dc(*(s32 *)((s8 *)TObjEneRecobox__static_instance + 0x430));
    ((TObjEneRecobox *)ene_recobox)->m_b8 = 0;
    ((TObjMotion *)ene_recobox)->set_animation(((TObjEneRecobox *)ene_recobox)->m_b8);
    ((TObjMotion *)ene_recobox)->set_field_b8(((TObjEneRecobox *)ene_recobox)->m_b8);
    reset_hp__9TObjEneDDFv(ene_recobox, recobox_boss_register_id, lbl_805D6B14, TObjEneRecobox__shared_object_handle);
    ((TObjEneDD *)ene_recobox)->check_state_flag_4();
    *(u8 * *)&((TObjEneRecobox *)ene_recobox)->movementParameters = TObjEneRecobox__attack_params;
    initialize_enemy_state__9TObjEneDDFv(ene_recobox, 0x43);
    ((TObjEneRecobox *)ene_recobox)->m_37c = lbl_805DF468;
    ((TObjEneRecobox *)ene_recobox)->sub_8031F800();
    n = *(s16 *)((s8 *)arg2 + 2);
    if (n <= 1) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 = 0;
    } else if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 >= n) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410 = n - 1;
    }
    if (*(s32 *)&((TObjEneRecobox *)ene_recobox)->m_414 > *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410) {
        *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_414 = *(s32 *)&((TObjEneRecobox *)ene_recobox)->m_410;
    }
    for (i = 0; i < 4; i++) {
        S->f3fc[i] = 0;
    }
    *(s32 *)((s8 *)ene_recobox + 0x40C) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x40C) |= 1;
    TObjEneMe3SinowZoa__sub_800D758C(ene_recobox + 0x3C0);
    *(s32 *)((s8 *)ene_recobox + 0x410) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x414) = 0;
    for (i = 0; i < 30; i++) {
        S->f424[i] = 0xFFFF;
    }
    for (i = 0; i < 6; i++) {
        S->f418[i] = 0xFFFF;
    }
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&S->subs[i]))->activate_and_dispatch();
    }
    *(s32 *)((s8 *)ene_recobox + 0x4D8) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4DC) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x3E0) = 0;
    VecCopy((Vec *)(ene_recobox + 0x3E4), (const Vec *)(ene_recobox + 0x38));
    *(s32 *)((s8 *)ene_recobox + 0x4E0) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4E4) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4E8) = 0;
    *(s32 *)((s8 *)ene_recobox + 0x4EC) = 0;
    ((TObjEneRecobox *)ene_recobox)->m_4f0 = lbl_805DF46C;
    ((TObjEneRecobox *)ene_recobox)->mode = 0;
    ((VObj_18_b2458f *)ene_recobox)->m85(((TObjEneRecobox *)ene_recobox)->mode, 4);
    return ene_recobox;
}

int TObjEneRecobox__sub_803201D0(void);

u32 TObjEneRecobox::remap_area_sound_id(u32 arg0) {
    u32 ret;
    if (((s32)(arg0 & 0xBFFF00FF) >> 16 << 16) != 0x30000) {
        return arg0;
    }
    ret = TOKeyMachine01::get_global_state();
    switch (ret) {
    case 0x22:
        ret = arg0 - 0x40010000 + 0x4E19;
        break;
    case 0x23:
        ret = arg0 - 0x40010000 + 0x4E28;
        break;
    default:
        return arg0;
    }
    ret |= arg0 & 0x8FFFFF00;
    return ret;
}

int TObjEneRecobox__sub_803201D0(void) {  return (*(int *)&TObjEneRecobox__static_instance); }

void *TObjEneRecobox__create(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void *__nw__7TObjectFUl(int);

void TObjEneRecobox::release_static_instance() {
    TObjEneRecon::release_static_instance();
    if ((u32) (*(u32 *)&TObjEneRecobox__static_instance) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TObjEneRecobox__static_instance), 1);
        (*(u32 *)&TObjEneRecobox__static_instance) = 0U;
    }
}

extern void *tl_04;

void *TObjEneRecobox__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4F4);
    if (o != NULL) {
        o = TObjEneRecobox__ct((u8 *)o, (s32)tl_04, (u8 *)arg0);
    }
    return o;
}

extern "C" {
struct V3_80320260 { f32 x, y, z; };
struct Spawn_80320260 { s32 a, b, c, d; };
struct Inner_80320260 { u8 pad[0x18]; s32 f18; s32 f1C; };
struct Box_80320260 { u8 pad[0x42C]; Inner_80320260 *f42C; s32 f430; };
struct Sub_80320260 { u8 pad[0xC]; f32 f0C; };

s32 is_split_screen(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 load_enemy_bml_resource(u8 *arg0);
extern Spawn_80320260 recobox_resource_binding_desc;
extern "C" u8 lbl_80476118[];
extern "C" u8 lbl_80476124[];
extern "C" u8 lbl_80476134[];
extern "C" u8 lbl_80476144[];
extern "C" u8 lbl_8047615C[];
extern "C" u8 lbl_80476174[];
extern "C" u8 lbl_8047618C[];
extern "C" u8 lbl_804761A4[];
extern "C" u8 lbl_804761C0[];
extern "C" u8 lbl_804761D8[];
extern "C" u8 lbl_804761F4[];
extern "C" u8 lbl_80476208[];
extern "C" u8 lbl_80476220[];
extern "C" u8 lbl_80476234[];
extern "C" u8 lbl_8047624C[];
extern "C" u8 lbl_80476260[];
extern "C" u8 lbl_80476274[];
extern "C" u8 lbl_80476288[];
extern "C" u8 lbl_80476298[];
extern "C" u8 lbl_804762AC[];
#undef lbl_804EC684
#define lbl_804EC684 (*(Sub_80320260 *)lbl_804EC684)
extern V3_80320260 lbl_80543000;
extern s32 lbl_805D6B1C;

#pragma dont_inline off
#pragma inline_depth(4)
static inline f32 getf_80320260(Sub_80320260 *p) { return p->f0C; }
void TObjEneRecobox::load_resources() {
    Box_80320260 *box;

    lbl_80543000.x = lbl_805DF46C;
    lbl_80543000.y = lbl_805DF46C;
    lbl_80543000.z = lbl_805DF46C;
    {
        u32 res;
        if (is_split_screen(&lbl_80543000) != 0) {
            res = load_enemy_bml_resource((u8 *)lbl_804EC750);
        } else {
            res = load_enemy_bml_resource((u8 *)lbl_804EC6F8);
        }
        (*(u32 *)&TObjEneRecobox__static_instance) = res;
    }
    recobox_boss_register_id = register_boss__6TLobbyFl(0x41);
    lbl_805D6B14 = dispatch_shared_handler_b__6TLobbyFl(0x41);
    TObjEneRecobox__shared_object_handle = register_object__6TLobbyFl(0x41);
    lbl_805D6B1C = dispatch_shared_handler_a__6TLobbyFl(0x41);
    TObjEneRecon::load_resources();
    {
        Sub_80320260 *sp = &lbl_804EC684;
        Spawn_80320260 s = recobox_resource_binding_desc;
        box = (Box_80320260 *)(*(u32 *)&TObjEneRecobox__static_instance);
        s.a = box->f430;
        TLobby::spawn_npc_enemy((s16)0xD, box->f42C->f18, box->f42C->f1C, (s32)&s, (f32)(getf_80320260(sp)), (f32)lbl_805DF46C);
    }
}

}
}
