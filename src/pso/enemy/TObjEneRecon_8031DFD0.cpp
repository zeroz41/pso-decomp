#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"

#include "pso/boss/TBoss8Dragon.h"

#include "pso/enemy/TObjEnePanarms.h"

extern "C" {

struct VBase_14_2f517b { char pad[0x14]; };

struct VObj_14_2f517b : VBase_14_2f517b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
};

struct VBase_18_be4a70 { char pad[0x18]; };

struct VObj_18_be4a70 : VBase_18_be4a70 {
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
};

void obj_setFlags30(void *, u32);
void queue_destruction__7TObjectFv(void *);
void *create_particle_emitter(void *pos, s32 id);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 reset_hp__9TObjEneDDFv(void *, void *, int, void *);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 init_model__9TObjEneDDFv(void *, void *, int, int);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void TObjEneRecon__sub_8031C364(u8 *arg0, s32 arg1);
void TObjEneRecon__sub_8031C624(u8 *arg0, s32 arg1);
void run_task__12TObjEneReconFPvi(u8 *arg0, s32 arg1);
void TObjEneRecon__sub_8031C920(u8 *arg0, s32 arg1);
void TObjEneRecon__sub_8031CCFC(u8 *arg0, s32 arg1);
void TObjEneRecon__sub_8031CF30(u8 *arg0, s32 arg1);
void TObjEneRecon__sub_8031D380(u8 *arg0, s32 arg1);
void TObjEneRecon__vt85(s32 arg0, u32 arg1, s32 arg2);
void run_task__12TObjEneReconFv(TObjEneRecon *arg0);
void * __dt__12TObjEneReconFv(void *arg0, s16 arg1);
s32 is_anim_6__12TObjEneReconFv(int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);

extern s32 TObjEneRecon__attack_params;
extern u8 *TObjEneRecon__recobox_static_instance;
extern const f32 TObjEneRecon__data_805DF3C0;
extern const f32 TObjEneRecon__data_805DF3C4;
extern const f32 TObjEneRecon__data_805DF3D4;
extern s32 lbl_805D6AF0;
extern s32 TObjEneRecon__resistance_params;
extern const f32 lbl_805DF400;
extern const f32 lbl_805DF424;
extern const f32 lbl_805DF428;
extern const f32 lbl_805DF42C;
extern const f32 lbl_805DF430;
extern const f32 lbl_805DF434;

extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFv();
extern "C" void TObjEneDD__vt82();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
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
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void TObjEneRecon__vt102(void *arg0, f32 farg0);
extern "C" void vfunc_83__12TObjEneReconFv();
extern "C" void vfunc_106__12TObjEneReconFv();
extern "C" void vfunc_28__12TObjEneReconFv();
extern "C" void vfunc_61__12TObjEneReconFv();
extern "C" void vfunc_62__12TObjEneReconFv();
extern "C" void vfunc_63__12TObjEneReconFv();
extern "C" void vfunc_88__12TObjEneReconFv();
extern "C" void vfunc_89__12TObjEneReconFv();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
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
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render__12TObjEneReconFv(u8 *arg0);
extern "C" void render_shadows__12TObjEneReconFv();
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
void *TObjEneRecon__ai_parameters[7] = {
    (void *)0x43610000, (void *)0x3f6d097b, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TObjEneRecon__collision_body_template[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TObjEneRecon__animation_entries[24] = {
    (void *)0x10000, (void *)0x8, (void *)0x3f333333, (void *)0x0,
    (void *)0x10001, (void *)0x9, (void *)0x3f333333, (void *)0x0,
    (void *)0x30002, (void *)0x4, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30003, (void *)0x5, (void *)0x3f333333, (void *)0x0,
    (void *)0x30004, (void *)0x6, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10005, (void *)0x7, (void *)0x3f333333, (void *)0x0,
};
void *__vt__12TObjEneRecon[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TObjEneReconFv, (void *)&run_task__12TObjEneReconFv,
    (void *)&render__12TObjEneReconFv, (void *)&render_shadows__12TObjEneReconFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__12TObjEneReconFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__12TObjEneReconFv, (void *)&vfunc_62__12TObjEneReconFv, (void *)&vfunc_63__12TObjEneReconFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneRecon__vt85,
    (void *)&vfunc_88__12TObjEneReconFv, (void *)&vfunc_89__12TObjEneReconFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneRecon__vt102, (void *)&vfunc_83__12TObjEneReconFv, (void *)&vfunc_106__12TObjEneReconFv,
};
#define __vt__12TObjEneRecon ((s32 *)__vt__12TObjEneRecon)

void TObjEneRecon__vt85(s32 arg0, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        ((TObjEneRecon *)arg0)->sub_8031D4B0(msg);
        return;
    case 1:
        TObjEneRecon__sub_8031D380((u8 *)arg0, (msg));
        return;
    case 2:
        TObjEneRecon__sub_8031CF30((u8 *)arg0, (msg));
        return;
    case 3:
        TObjEneRecon__sub_8031CCFC((u8 *)arg0, (msg));
        return;
    case 4:
        TObjEneRecon__sub_8031C920((u8 *)arg0, (msg));
        return;
    case 6:
        TObjEneRecon__sub_8031C624((u8 *)arg0, (msg));
        return;
    case 7:
        TObjEneRecon__sub_8031C364((u8 *)arg0, (msg));
        return;
    case 5:
        run_task__12TObjEneReconFPvi((u8 *)arg0, (msg));
        return;
    case 8:
        ((TObjEneRecon *)arg0)->handle_message(msg);
    default:
        return;
    }
}

void run_task__12TObjEneReconFv(TObjEneRecon *ene_recon) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f30;
    s16 temp_r0;
    s16 temp_r0_2;
    s32 entity;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecon *)(ene_recon))->vfunc_106();
        return;
    }
    entity = (s32)find_entity_by_id((*(u16 *)((s8 *)ene_recon + 0x434)));
    if ((entity == 0) || (all_parents_unqueued_for_destruction__7TObjectFv() == 0)) {
        queue_destruction__7TObjectFv(ene_recon);
        return;
    }
    temp_r0 = ene_recon->mode;
    if ((temp_r0 != 8) && (temp_r0 != 7) && (is_anim_6__12TObjEneReconFv(entity) == 1)) {
        ene_recon->m_2dc = (s32) (ene_recon->m_2dc | 4);
        ((TObjPlayer *)ene_recon)->set_hp_clamped(0);
        obj_setFlags30(ene_recon, 0xA00U);
        ((TObjEneRecon *)(ene_recon))->vfunc_74(0);
    }
    if (((TObjEneRecon *)(ene_recon))->vfunc_83() != 4) {
        ((TObjEneRecon *)(ene_recon))->vfunc_85();
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_2 == NULL) {
            *(u8 **)((s8 *)ene_recon + 0x478) = (u8 *)create_particle_emitter((u8 *)ene_recon + 0x2FC, 0x217);
            temp_r3_3 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
            if (temp_r3_3 != NULL) {
                ((TParticleCtrl *)temp_r3_3)->enable();
            }
        } else {
            temp_r0_2 = ene_recon->mode;
            if ((temp_r0_2 == 8) || (temp_r0_2 == 7)) {
                ((TParticleCtrl *)temp_r3_2)->enable();
            } else {
                if ((s32) *(s32 *)((s8 *)ene_recon + 0x47C) == 0) {
                    var_f30 = lbl_805DF400;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 1;
                } else {
                    var_f30 = lbl_805DF428;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 0;
                }
                if (TObjEneDD::check_v2_mode() != 0) {
                    var_f30 *= lbl_805DF400;
                }
                temp_f31 = var_f30 * cos_table_lookup(ene_recon->rotation_y);
                temp_f2 = var_f30 * -sin_table_lookup(ene_recon->rotation_y);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x60) = (f32) (ene_recon->m_2fc + temp_f31);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x64) = (f32) (lbl_805DF424 + ene_recon->m_300);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x68) = (f32) (ene_recon->m_304 + temp_f2);
            }
        }
    } else {
        temp_r3_4 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_4 != NULL) {
            ((TParticleCtrl *)temp_r3_4)->enable();
        }
    }
    ene_recon->update_position_from_offsets();
    ((TBoss8Dragon *)ene_recon)->set_player_state_default();
    ((TObjEneRecon *)(ene_recon))->vfunc_100();
    ene_recon->update_ground_probe();
}

void *__dt__12TObjEneReconFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjEneRecon;
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        free_collision_body_parts(arg0);
        if (*(void **)((s8 *)arg0 + 0x478) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x478)); ((TObjEneRecon *)arg0)->m_494 = 0; }
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x480, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
void TObjEneRecon::init_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;

    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C)) + 8);
    temp_r6 = (u8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)temp_r6 + 0xC);
    init_model__9TObjEneDDFv((void *)arg0, (void *) TObjEneRecon__collision_body_template, 1, (int)temp_r6);
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *) TObjEneRecon__animation_entries));
    ((TObjMotion *)arg0)->set_field_dc((int) (*(s32 *)((s8 *)TObjEneRecon__recobox_static_instance + 0x430)));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation((*(s16 *)((s8 *)arg0 + 0xB8)));
    ((TObjMotion *)arg0)->set_field_b8((int) (*(s16 *)((s8 *)arg0 + 0xB8)));
    reset_hp__9TObjEneDDFv((void *)arg0, (void *)lbl_805D6AF0, (int)TObjEneRecon__attack_params, (void *)TObjEneRecon__resistance_params);
    ((TObjEneDD *)arg0)->check_state_flag_4();
    *(void **)((s8 *)arg0 + 0x350) = (void *) TObjEneRecon__ai_parameters;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x44);
    *(f32 *)((s8 *)arg0 + 0x37C) = (f32) TObjEneRecon__data_805DF3D4;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0xA);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0xA);
    ((TObjEneDD_ST *)arg0)->set_active();
    *(s32 *)((s8 *)arg0 + 0x30) = (*(s32 *)((s8 *)arg0 + 0x30) | 0x01000000);
    *(s32 *)((s8 *)arg0 + 0x444) = 2;
    *(f32 *)((s8 *)arg0 + 0x448) = (*(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x44C) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x450) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x454) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x458) = (f32) TObjEneRecon__data_805DF3C4;
    *(s32 *)((s8 *)arg0 + 0x45C) = 0;
    *(f32 *)((s8 *)arg0 + 0x460) = (f32) ((lbl_805DF430 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + lbl_805DF42C);
    *(f32 *)((s8 *)arg0 + 0x464) = (f32) ((lbl_805DF430 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + TObjEneRecon__data_805DF3C0);
    *(f32 *)((s8 *)arg0 + 0x468) = (f32) ((TObjEneRecon__data_805DF3D4 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + lbl_805DF434);
    *(s32 *)((s8 *)arg0 + 0x474) = 0;
    *(s32 *)((s8 *)arg0 + 0x478) = 0;
    *(s32 *)((s8 *)arg0 + 0x47C) = 0;
    *(s32 *)((s8 *)arg0 + 0x418) = 0;
    VecCopy((Vec *)(arg0 + 0x41C), (const Vec *)(arg0 + 0x38));
    ((VObj_14_2f517b *)(arg0 + (1152)))->m2();
    *(s32 *)((s8 *)arg0 + 0x46C) = 0;
    *(s32 *)((s8 *)arg0 + 0x470) = 0;
    VecCopy((Vec *)(arg0 + 0x40C), (const Vec *)(arg0 + 0x38));
    *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3DC) = 0;
    *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3EC) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F0) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F4) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3FC) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x400) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x404) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x408) = (f32) TObjEneRecon__data_805DF3C4;
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_18_be4a70 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
}
#pragma pop

}
