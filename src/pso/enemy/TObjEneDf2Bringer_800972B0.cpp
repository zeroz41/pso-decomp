#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneDf2Bringer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/enemy/TUnk_8048FE7C.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type3.h"

#include "pso/enemy/TUnk_8048FE08.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TUnk_80490470.h"

struct Bringer_80097714;
struct Bringer_800993E8;
struct Obj_80098EFC;
struct Obj_80098FF4;
struct VBase_800996EC { char pad[0x18]; };

struct VObj_800996EC : VBase_800996EC {
    virtual void m0(s32);
};

extern "C" {
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
s32 __destroy_arr(void *, void *, int, int);
extern s32 __dt__13TUnk_804949A8Fv[];
u8 *__dt__17TObjEneDf2BringerFv(u8 *arg0, s16 arg1);
void render__17TObjEneDf2BringerFv(u8 *arg0);
void TObjEneDf2Bringer__sub_80097620(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_80097714(Bringer_80097714 *obj, s32 mode);
void TObjEneDf2Bringer__sub_80097820(u8 *arg0, s32 arg1);
void action__17TObjEneDf2BringerFPvi(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_80097E9C(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_8009813C(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_8009859C(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_800987E8(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__sub_80098BAC(u8 *arg0, s32 arg1);
void TObjEneDf2Bringer__vt85(s32 arg0, u32 arg1, s32 arg2);
void sub_80098DEC__17TObjEneDf2BringerFv(u8 *arg0);
void TObjEneDf2Bringer__vt102(void *arg0, f32 farg0);
void TObjEneDf2Bringer__sub_80098EB4(s32 arg0);
s32 attack_visible_players__17TObjEneDf2BringerFPv(Obj_80098EFC *self);
s32 TObjEneDf2Bringer__sub_80098FF4(Obj_80098FF4 *self);
void update_flag_0x3C0__17TObjEneDf2BringerFPv(void *arg0);
void update_if_in_band__17TObjEneDf2BringerFi(s32 arg0);
void spawn_particle_if_in_band__17TObjEneDf2BringerFPv(u8 *arg0);
void spawn_offset_particle__17TObjEneDf2BringerFPv(u8 *arg0);
void update_attack_child__17TObjEneDf2BringerFPv(Bringer_800993E8 *obj);
void TObjEneDf2Bringer__sub_800994F8(void);
void vfunc_88__17TObjEneDf2BringerFv(void);
void set_effect_pos_above_self__17TObjEneDf2BringerFv(u8 *arg0);
void vfunc_61__17TObjEneDf2BringerFv(void);
void vfunc_62__17TObjEneDf2BringerFv(u8 *arg0);
void vfunc_63__17TObjEneDf2BringerFv(void* p);
void vfunc_28__17TObjEneDf2BringerFv(void);
void run_task__17TObjEneDf2BringerFv(u8 *arg0);
void * TObjEneDf2Bringer__ct(void *arg0, void *arg1, void *arg2);
}
void bringer_render_node_callback(void);
struct RecoveredGlobal_8031B170_lbl_804E8880
{
  s32 value;
  u8 remaining[0xCC];
};
extern "C" {
extern "C" u8 lbl_80439F70[];
extern "C" u8 lbl_80439F84[];
extern "C" u8 lbl_80439F9C[];
extern "C" u8 lbl_80439FB4[];
extern "C" u8 lbl_80439FD0[];
extern "C" u8 lbl_80439FE8[];
extern "C" u8 lbl_8043A000[];
extern "C" u8 lbl_8043A018[];
extern "C" u8 lbl_8043A030[];
extern "C" u8 lbl_8043A048[];
extern "C" u8 lbl_8043A060[];
extern "C" u8 lbl_8043A078[];
extern "C" u8 lbl_8043A090[];
extern void *bm_ene_df2_bringer_model_names[2];
extern void *bm_ene_df2_bringer_motion_names[12];
void *bringer_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048FA2C[33] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x41000000, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x40400000, (void *)0x0,
    (void *)0x0, (void *)0x9d03, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x40400000, (void *)0x0, (void *)0x0,
    (void *)0x9d03, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
__declspec(section ".data") void *bm_ene_df2_bringer_model_names[2] = {
    (void *)&lbl_80439F70, (void *)0x0,
};
void *bm_ene_df2_bringer_motion_names[12] = {
    (void *)&lbl_80439F84, (void *)&lbl_80439F9C, (void *)&lbl_80439FB4, (void *)&lbl_80439FD0,
    (void *)&lbl_80439FE8, (void *)&lbl_8043A000, (void *)&lbl_8043A018, (void *)&lbl_8043A030,
    (void *)&lbl_8043A048, (void *)&lbl_8043A060, (void *)&lbl_8043A078, (void *)0x0,
};
void *bm_ene_df2_bringer_resource_descriptor[4] = {
    (void *)&lbl_8043A090, (void *)&bm_ene_df2_bringer_model_names, (void *)&bm_ene_df2_bringer_motion_names, (void *)0x1000b,
};
void *lbl_8048FAF8[44] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0xa, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x1, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f19999a, (void *)0x0,
};
#define lbl_8048FAF8 (*(RecoveredGlobal_8031B170_lbl_804E8880 *)lbl_8048FAF8)
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
extern "C" void vfunc_83__17TObjEneDf2BringerFv();
extern "C" void vfunc_105__17TObjEneDf2BringerFv();
extern "C" void vfunc_83__12TObjEneDD_STFv();
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
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
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
void *__vt__17TObjEneDf2Bringer[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__17TObjEneDf2BringerFv, (void *)&run_task__17TObjEneDf2BringerFv,
    (void *)&render__17TObjEneDf2BringerFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__17TObjEneDf2BringerFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__17TObjEneDf2BringerFv, (void *)&vfunc_62__17TObjEneDf2BringerFv, (void *)&vfunc_63__17TObjEneDf2BringerFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneDf2Bringer__vt85,
    (void *)&vfunc_88__17TObjEneDf2BringerFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneDf2Bringer__vt102, (void *)&vfunc_83__17TObjEneDf2BringerFv, (void *)&vfunc_105__17TObjEneDf2BringerFv,
};
#define __vt__17TObjEneDf2Bringer ((s32 *)__vt__17TObjEneDf2Bringer)

}

struct VBase_18_beae68 { char pad[0x18]; };

struct VObj_18_beae68 : VBase_18_beae68 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual s32 m92();
};

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredGlobal_800975A8_lbl_805008A8 {
    s32 value;
    u8 remaining[0xC];
};

struct Vec_80097714 { f32 x, y, z; };

struct BringerBase_80097714 { char pad[0x18]; };

struct Bringer_80097714 : BringerBase_80097714 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
};

struct Fields_80097714 {
    u8 pad0[0xB8];
    s16 fieldB8;
    u8 padBA[0x308 - 0xBA];
    Vec_80097714 vel;
    u8 pad314[0x378 - 0x314];
    s32 field378;
    u8 pad37C[0x484 - 0x37C];
    s32 timer;
};

struct VB2_800987E8 { u8 pad0[0x14]; };

struct V2_800987E8 : VB2_800987E8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct VBase_14_aa9368 { char pad[0x14]; };

struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};

struct VBase_18_1fdb47 { char pad[0x18]; };

struct VObj_18_1fdb47 : VBase_18_1fdb47 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
};

struct Vec_800972B0 { f32 x, y, z; };

struct Ent_800972B0 { s32 a, b, c; };

struct Fade_800972B0 { u8 pad[0x1C]; };

struct Fields_800972B0 {
    u8 pad0[0x24];
    Ent_800972B0 **f24;
    u8 pad28[0x2FC - 0x28];
    Vec_800972B0 pos;
    u8 pad308[0x3E0 - 0x308];
    Fade_800972B0 fades[4];
    Vec_800972B0 pts[4];
    s32 f480;
};

struct VBase_18_313dd8 { char pad[0x18]; };

struct VObj_18_313dd8 : VBase_18_313dd8 {
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
};

struct Vec_8009813C { f32 x, y, z; };

struct Sub_8009813C { u8 pad[0x18]; s32 flags; };

struct Prm_8009813C { f32 speed; u8 pad4[0x18]; s32 i1C; s32 i20; };

struct Vec_80097820 { f32 x, y, z; };

#include <stddef.h>
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItem.h"

u8 *construct_bringer_rush_effect(u8 *, s32, u8 *, s32, f32);
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
struct VBase_18_d3b6b2 { char pad[0x18]; };

struct VObj_18_d3b6b2 : VBase_18_d3b6b2 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32 *, s32 *);
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct Stack_80097E9C {
    f32 sp8[3];
    f32 sp14[3];
};

extern "C" {
s32 queue_destruction__7TObjectFv(void *);
s32 TObjPlayer__sub_800A04F0(void *);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 advance_animation_playback(void *);
s32 play_effect_if_v2__10TObjPlayerFl(int);
s32 play_sound_effect(void *, void *, int, int);
s32 get_camera_ctrl__9TObjEneDDFv(void *, int);
s32 rotate_matrix_x(int, int);
extern RecoveredGlobal_800975A8_lbl_805008A8 bringer_camera_ctrl_target_vec;
extern s32 TObjEneDf2Bringer__render_node_index;
extern s32 TObjEneDf2Bringer__render_rotation_x;
extern s32 TObjEneDf2Bringer__render_point_cursor;
void clear_attack_receipts__9TObjEneDDFv(void *);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
extern const f32 lbl_805D97E4;
s32 update_linked_position__12TObjEneDD_STFf(void *, f32);
s32 set_field_378__9TObjEneDDFl(void *, s32);
extern f32 TObjEneDf2Bringer__data_805D9820;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 update_obstruction_fade(void *);
s32 scroll_strip_uvs(int, int, int);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern Vec_800972B0 lbl_8043A0D4[];
extern s32 TObjEneDf2Bringer__uv_scroll_buffer;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D97D8;
extern const f32 lbl_805D97DC;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
f64 atan2_float(f32, f32);
void fill_value_array(s32);
s32 turn_toward_angle_limited__15TObjBoss2TunnelFlllll(s32, s32, s32, s32, s32);
#define update_if_in_band__17TObjEneDf2BringerFi ((void (*)(void *))update_if_in_band__17TObjEneDf2BringerFi)
#define spawn_particle_if_in_band__17TObjEneDf2BringerFPv ((void (*)(void *))spawn_particle_if_in_band__17TObjEneDf2BringerFPv)
#define spawn_offset_particle__17TObjEneDf2BringerFPv ((void (*)(void *))spawn_offset_particle__17TObjEneDf2BringerFPv)
s32 TObjEneDf2Bringer__sub_80099248(void *);
s32 enemy_validate_retained_target(void *);
u32 enemy_probe_wall_ahead__13TBoss5GryphonFfff(void *, f32, f32, f32);
s32 approach_angle_limited(s32, s32, s32);
s32 play_persistent_sound(s32, void *, void *, s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 subtract_vector(void *, void *);
extern const f64 TObjEneDf2Bringer__data_8043A0F8;
extern Prm_8009813C *TObjEneDf2Bringer__data_805D4FB4;
extern const f32 TObjEneDf2Bringer__data_805D97E0;
extern const f32 TObjEneDf2Bringer__data_805D97F4;
extern const f32 lbl_805D9810;
extern const f32 lbl_805D9814;
extern const f32 lbl_805D9818;
extern const f32 lbl_805D981C;
u32 create_particle_emitter(void *, s32);
#define TObjEneDf2Bringer__sub_80098EB4 ((s32 (*)(void *))TObjEneDf2Bringer__sub_80098EB4)
#define attack_visible_players__17TObjEneDf2BringerFPv ((s32 (*)(void *))attack_visible_players__17TObjEneDf2BringerFPv)
#define TObjEneDf2Bringer__sub_80098FF4 ((s32 (*)(void *))TObjEneDf2Bringer__sub_80098FF4)
void *__nw__7TObjectFUl(u32);
extern const f32 lbl_805D97E8;
extern const f32 lbl_805D97EC;
extern const f32 lbl_805D97F0;
extern const f32 lbl_805D97F8;
extern const f32 lbl_805D97FC;
extern const f32 lbl_805D9800;
extern const f32 lbl_805D9804;
extern const f32 TObjEneDf2Bringer__data_805D9808;
#define update_attack_child__17TObjEneDf2BringerFPv ((s32 (*)(void *))update_attack_child__17TObjEneDf2BringerFPv)
s32 lookup_entry_by_value__10TObjPlayerFPvf(int, f32);
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
extern s32 TObjEneDf2Bringer__trail_buffer;
extern const f32 lbl_805D980C;
#define update_flag_0x3C0__17TObjEneDf2BringerFPv ((s32 (*)(void *))update_flag_0x3C0__17TObjEneDf2BringerFPv)

typedef char RecoveredGlobal_800975A8_lbl_805008A8_size[sizeof(RecoveredGlobal_800975A8_lbl_805008A8) == 0x10 ? 1 : -1];

#define S ((Fields_800972B0 *)arg0)
#pragma push
#pragma opt_loop_invariants off
void render__17TObjEneDf2BringerFv(u8 *arg0) {
    s32 var_r31;
    s32 temp_r29;
    Fade_800972B0 *temp_r28;
    s32 var_r27;
    s32 temp_r27;
    s32 mode;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneDf2Bringer *)(arg0))->vfunc_105();
        return;
    }
    mode = 0;
    if (is_split_screen() != 0) {
        mode = get_camera_mode__11TCameraCtrlFv();
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C0) & 1) {
        var_r31 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r31 = ((VObj_18_1fdb47 *)(arg0))->m9(lbl_805D9E88, lbl_805D9E84, lbl_805D97DC);
    } else if (((VObj_18_1fdb47 *)(arg0))->m8(lbl_805D97D8, lbl_805D97DC) != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        {
            Vec_800972B0 v = lbl_8043A0D4[0];
            update_player_state__9TObjEneDDFv(arg0, &v, 0);
        }
        ((TObjEneDD *)arg0)->update_secondary_light();
        TObjEneDf2Bringer__render_node_index = 0;
        TObjEneDf2Bringer__render_rotation_x = S->f480;
        TObjEneDf2Bringer__render_point_cursor = (s32) S->pts;
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        temp_r28 = &S->fades[mode];
        var_r27 = 1;
        update_obstruction_fade(temp_r28);
        temp_r29 = ((RenderFadeState *)temp_r28)->updateFromCamera((const f32*)(arg0 + 0x2FC));
        if (*(s32 *)((s8 *)arg0 + 0x3C0) & 2) {
            ((VObj_14_aa9368 *)(arg0 + (964)))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                var_r27 = 0;
            }
        } else if (temp_r29 != 0) {
            ((VObj_14_aa9368 *)(temp_r28))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                var_r27 = 0;
            }
        }
        scroll_strip_uvs(TObjEneDf2Bringer__uv_scroll_buffer, (s16) *(s32 *)((s8 *)arg0 + 0x4A8), 0);
        TObjFish::set_global_param((s32)S->f24);
        {
            Ent_800972B0 *e = *S->f24;
            temp_r27 = *(s32 *)((s8 *)e + 0x14);
            *(s32 *)((s8 *)e + 0x14) = e[*(s32 *)((s8 *)arg0 + 0x488)].c;
        }
        if (var_r27 != 0) {
            push_matrix();
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
            TObjEneRe7Berura::set_global_state((s32)&bringer_render_node_callback);
            TObjPlayer::set_global_flag();
            if (var_r31 == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->render_world_model();
            }
            TObjPlayer::clear_global_state();
            TObjEneRe7Berura::set_global_state(NULL);
            pop_matrix();
        }
        if (*(s32 *)((s8 *)arg0 + 0x3C0) & 2) {
            ((VObj_14_aa9368 *)(arg0 + (964)))->m7();
        } else if (temp_r29 != 0) {
            ((VObj_14_aa9368 *)(temp_r28))->m7();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        ((TObjEneDD *)arg0)->update_primary_light();
        *(s32 *)((s8 *)(*S->f24) + 0x14) = temp_r27;
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy((Vec *)&S->pts[i], (const Vec *)&S->pos);
    }
}
}
#pragma pop

void bringer_render_node_callback(void) {
    s32 pos;
    switch (TObjEneDf2Bringer__render_node_index) {
    case 8:
        rotate_matrix_x(0, TObjEneDf2Bringer__render_rotation_x);
        break;
    case 11:
    case 16:
    case 26:
    case 41:
        pos = TObjEneDf2Bringer__render_point_cursor;
        TObjEneDf2Bringer__render_point_cursor = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv(&bringer_camera_ctrl_target_vec.value, pos);
        break;
    }
    TObjEneDf2Bringer__render_node_index += 1;
}

void TObjEneDf2Bringer__sub_80097620(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xA;
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 2);
        ((VObj_18_beae68 *)(arg0))->m92();
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        ((TObjPlayer *)(arg0 + 0x2FC))->request_two_effects();
        TObjPlayer__sub_800A04F0(arg0 + 0x3C4);
        play_sound_effect((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A511))), arg0 + 0x38, 0, 0);
        play_effect_if_v2__10TObjPlayerFl(-0x200);
        return;
    case 0:
        ((s32)advance_animation_playback(arg0));
        if (((VObj_14_c1c33b *)(arg0 + (964)))->m4() != 0) {
            TObjPlayer::apply_effect_variant_b((s32)(arg0 + 0x38), 0);
            queue_destruction__7TObjectFv(arg0);
        }
    case 3:
    case 5:
        return;
    }
}

void TObjEneDf2Bringer__sub_80097714(Bringer_80097714 *obj, s32 mode) {
    Fields_80097714 *self = (Fields_80097714 *)obj;
    Vec_80097714 v;
    f32 speed;
    switch (mode) {
    case 4:
        self->fieldB8 = 6;
        advance_animation_playback(self);
        ((TObjEneDD_ST *)self)->set_active();
        break;
    case 3:
        if (((TObjEneDD *)self)->get_flag_b4() != 0 &&
            ((TObjEneDf2Bringer *)self)->check_stage_advance() == 0) {
            transition_enemy_state__9TObjEneDDFs(self, self->field378);
        }
        break;
    case 0:
        ((s32)advance_animation_playback(self));
        self->timer--;
        VecCopy((Vec *)&v, (const Vec *)&self->vel);
        speed = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)self)->move_clamped_on_ground(v.x, v.z, speed);
        self->vel.x *= lbl_805D97E4;
        self->vel.z *= lbl_805D97E4;
        obj->m87();
        break;
    case 5:
        clear_attack_receipts__9TObjEneDDFv(self);
        ((TObjEneDD *)self)->clear_field_388();
        break;
    }
}

#define F_8009(off, T) (*(T *)(arg0 + (off)))
#define atan2_float ((f32 (*)(f32, f32))atan2_float)
void TObjEneDf2Bringer__sub_80097820(u8 *arg0, s32 arg1) {
    void *e;
    switch (arg1) {
    case 4:
        F_8009(0xB8, s16) = 9;
        set_field_378__9TObjEneDDFl(arg0, 4);
        F_8009(0x3C0, s32) &= ~3;
        F_8009(0x3C0, s32) |= 4;
        F_8009(0x4AC, s32) = 0;
        F_8009(0x4B0, s32) = 0;
        F_8009(0x4B4, s32) = 0;
        F_8009(0x4B8, s32) = 0;
        F_8009(0x4C4, u32) = 0;
        break;
    case 3:
        if (F_8009(0x4AC, s32) == 4) {
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F_8009(0x4AC, s32)) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                if (TObjEneDf2Bringer__sub_80098FF4(arg0) != 0) {
                    ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                    ((TObjEneDD *)arg0)->update_velocity();
                    F_8009(0x4B8, s32) = (u16)(s32)(((const f64 *)&TObjEneDf2Bringer__data_8043A0F8)[0] * ((f32)atan2_float(F_8009(0x3A0, f32), F_8009(0x3A8, f32))));
                    F_8009(0x4AC, s32) = 1;
                    F_8009(0xB8, s16) = 1;
                } else {
                    F_8009(0x4AC, s32) = 4;
                }
            } else {
                if (objInBand((GameObj *)arg0, (f32)lbl_805D97E8) != 0) {
                    Vec_80097820 v = *(Vec_80097820 *)((s8 *)arg0 + 0x38);
                    void *o;
                    v.y += lbl_805D97E8;
                    o = new TUnk_8048FE7C((TObject *)arg0, (u8 *)&v, lbl_805D97EC);
                }
                if (objInBand((GameObj *)arg0, (f32)lbl_805D97F0) != 0) {
                    F_8009(0x4B4, s32) = attack_visible_players__17TObjEneDf2BringerFPv(arg0);
                    play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B20B), arg0 + 0x38, 0, 0);
                }
                if ((e = F_8009(0x4C4, void *)) == 0) {
                    F_8009(0x4C4, u32) = create_particle_emitter(arg0 + 0x474, 0xEB);
                    if (F_8009(0x4C4, u32) != 0) {
                        ((TParticleCtrl *)(F_8009(0x4C4, void *)))->enable();
                    }
                } else if (F_8009(0xC0, f32) < TObjEneDf2Bringer__data_805D97F4 || F_8009(0xC0, f32) > lbl_805D97F8) {
                    ((TParticleCtrl *)e)->enable();
                } else {
                    ((TNowLoading *)e)->copy_pos(arg0 + 0x474);
                }
            }
            break;
        case 1:
            F_8009(0x60, s32) = approach_angle_limited((s32)(F_8009(0x60, s32)), (s32)(F_8009(0x4B8, s32)), 0x300);
            if ((u16)F_8009(0x60, s32) == F_8009(0x4B8, s32)) {
                F_8009(0x4AC, s32) = 2;
                F_8009(0xB8, s16) = 5;
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A80A), arg0 + 0x38, 0, 0);
            }
            if (F_8009(0x4C4, u32) != 0) {
                queue_destruction__7TObjectFv(F_8009(0x4C4, void *));
                F_8009(0x4C4, u32) = 0;
            }
            TObjEneDf2Bringer__sub_80098EB4(arg0);
            break;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    F_8009(0x4B0, s32)++;
                    if (F_8009(0x4B0, s32) < 3) {
                        if (TObjEneDf2Bringer__sub_80098FF4(arg0) != 0) {
                            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                            ((TObjEneDD *)arg0)->update_velocity();
                            F_8009(0x4B8, s32) = (u16)(s32)(((const f64 *)&TObjEneDf2Bringer__data_8043A0F8)[0] * ((f32)atan2_float(F_8009(0x3A0, f32), F_8009(0x3A8, f32))));
                            F_8009(0x4AC, s32) = 1;
                            F_8009(0xB8, s16) = 1;
                        } else {
                            F_8009(0x4AC, s32) = 4;
                        }
                    } else {
                        F_8009(0x4B0, s32) = 0;
                        F_8009(0x4AC, s32) = 3;
                        F_8009(0x494, s32) = 0;
                        F_8009(0x488, s32) = 1;
                        F_8009(0x3C0, s32) &= ~8;
                    }
                } else {
                    F_8009(0x4AC, s32) = 3;
                    F_8009(0x494, s32) = 0;
                    F_8009(0x488, s32) = 1;
                    F_8009(0x3C0, s32) &= ~8;
                }
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D97FC) != 0) {
                f32 spd = (f32)*(s32 *)((s8 *)(*(u8 * *)&TObjEneDf2Bringer__data_805D4FB4) + 0x24);
                if (F_8009(0x4B4, s32) > 150) {
                    spd *= lbl_805D9800;
                } else if (F_8009(0x4B4, s32) > 70) {
                    spd *= lbl_805D9804;
                }
                ((TObjEneDf2Bringer *)(F_8009(0x4A0, void *)))->setup_dir_shot(arg0 + 0x468, F_8009(0x4B8, s32), spd);
            }
            if ((e = F_8009(0x4C4, void *)) == 0) {
                F_8009(0x4C4, u32) = create_particle_emitter(arg0 + 0x38, 0xED);
                if (F_8009(0x4C4, u32) != 0) {
                    s32 ang[3];
                    ang[0] = 0;
                    ang[1] = F_8009(0x4B8, s32) - 0x4000;
                    ang[2] = -0x4000;
                    ((TBoss4Type2 *)(F_8009(0x4C4, void *)))->set_flags(2);
                    ((TBoss4Type2 *)(F_8009(0x4C4, void *)))->copy_vec3(ang);
                    ((TParticleCtrl *)(F_8009(0x4C4, void *)))->enable();
                }
            } else if (F_8009(0xC0, f32) < TObjEneDf2Bringer__data_805D9808 || F_8009(0xC0, f32) > lbl_805D97FC) {
                ((TParticleCtrl *)e)->enable();
            } else {
                ((TNowLoading *)e)->copy_pos(arg0 + 0x468);
            }
            break;
        case 3:
            F_8009(0x4B0, s32)++;
            if (F_8009(0x4B0, s32) >= 60) {
                F_8009(0x4AC, s32) = 4;
            }
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        break;
    case 5:
        F_8009(0x3C0, s32) &= ~8;
        F_8009(0x494, s32) = 0;
        if (F_8009(0x4C4, u32) != 0) {
            queue_destruction__7TObjectFv(F_8009(0x4C4, void *));
            F_8009(0x4C4, u32) = 0;
        }
        break;
    }
}
#undef atan2_float

void action__17TObjEneDf2BringerFPvi(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 8;
        set_field_378__9TObjEneDDFl(arg0, 7);
        *(u32 *)((s8 *)arg0 + 0x4C4) = 0U;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x484) <= 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        }
        return;
    case 0:
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x484) = (s32) (*(s32 *)((s8 *)arg0 + 0x484) - 1);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x4C4) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x4C4) = create_particle_emitter(arg0 + 0x450, 0x100);
            if ((u32) *(u32 *)((s8 *)arg0 + 0x4C4) != 0U) {
                ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x4C4)))->enable();
            }
        } else if (*(s32 *)((s8 *)arg0 + 0x484) & 1) {
            ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x4C4)))->copy_pos(arg0 + 0x450);
        } else {
            ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x4C4)))->copy_pos(arg0 + 0x45C);
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        play_persistent_sound(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD0F), arg0, arg0 + 0x38, 0, 0);
        return;
    case 5:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x4C4) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4C4));
            *(u32 *)((s8 *)arg0 + 0x4C4) = 0U;
        }
        break;
    }
}

void TObjEneDf2Bringer__sub_80097E9C(u8 *arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_80097E9C, sp8) == 0x0) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80097E9C, sp14) == 0xC) ? 1 : -1];
    Stack_80097E9C stack;
    s32 temp_r3;
    s32 entry;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        set_field_378__9TObjEneDDFl(arg0, 4);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        fill_value_array((s32)((int) (*(s32 *)((s8 *)arg0 + 0x49C))));
        ((TBoss4Type3 *)(*(u8 **)((s8 *)arg0 + 0x4A4)))->reset_timer();
        *(s32 *)((s8 *)arg0 + 0x4AC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
        *(s32 *)((s8 *)arg0 + 0x490) = 0;
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4B0) == 2) {
            *(s32 *)((s8 *)arg0 + 0x48C) = (s32) (*(s32 *)((s8 *)arg0 + 0x48C) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x48C) >= 2) {
                *(s32 *)((s8 *)arg0 + 0x48C) = 0;
                *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF7);
            }
            if (((TObjEneDf2Bringer *)arg0)->check_stage_advance() == 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 4);
            }
        }
        break;
    case 0:
        ((s32 (*)())advance_animation_playback)();
        temp_r3 = *(s32 *)((s8 *)arg0 + 0x60);
        *(s32 *)((s8 *)arg0 + 0x480) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(temp_r3, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x480))), temp_r3, 0x200, 0x2000);
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if (objInBand((GameObj *)(arg0), TObjEneDf2Bringer__data_805D97F4) != 0) {
                spawn_offset_particle__17TObjEneDf2BringerFPv(arg0);
            }
            entry = lookup_entry_by_value__10TObjPlayerFPvf(TObjEneDf2Bringer__trail_buffer, (f32) (*(f32 *)((s8 *)arg0 + 0xC0)));
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x60)));
                matrix_mult_vec(0, (void *)(entry + 0x18), (void *)&stack.sp8);
                matrix_mult_vec(0, (void *)entry, &stack.sp14);
                pop_matrix();
                ((VObj_18_d3b6b2 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x4A4))))->m4((s32 *)stack.sp8, (s32 *)stack.sp14);
            }
            update_attack_child__17TObjEneDf2BringerFPv(arg0);
            if (objInBand((GameObj *)(arg0), lbl_805D980C) != 0) {
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A30C), arg0 + 0x38, 0, 0);
                play_effect_if_v2__10TObjPlayerFl(-0x200);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 0;
                *(s32 *)((s8 *)arg0 + 0x4B0) = 1;
                *(s32 *)((s8 *)arg0 + 0x4AC) = 0;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x4AC) = (s32) (*(s32 *)((s8 *)arg0 + 0x4AC) + 1);
            if ((f32) *(s32 *)((s8 *)arg0 + 0x4AC) >= *(f32 *)((s8 *)(*(u8 * *)&TObjEneDf2Bringer__data_805D4FB4) + 0x14)) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 2;
            }
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    case 5:
        break;
    }
}

#pragma push
#pragma fp_contract on
#define F(t, o) (*(t *)(arg0 + (o)))
#define PRM TObjEneDf2Bringer__data_805D4FB4
#define VO ((VObj_18_313dd8 *)(arg0))
void TObjEneDf2Bringer__sub_8009813C(u8 *arg0, s32 arg1) {
    Vec_8009813C d;
    s32 hit;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 7;
        set_field_378__9TObjEneDDFl(arg0, 4);
        F(s32, 0x3C0) &= ~7;
        F(s32, 0x4AC) = 0;
        F(s32, 0x4B0) = 0;
        F(f32, 0x4BC) = PRM->speed;
        fill_value_array(F(s32, 0x49C));
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (F(s32, 0x4AC) == 3) {
            F(s32, 0x48C) = 0;
            F(s32, 0x490)++;
            F(s32, 0x3C0) &= ~8;
            if (((TObjEneDf2Bringer *)arg0)->check_stage_advance() == 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 7);
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(s32, 0x4AC)) {
        case 0:
            if (objInBand((GameObj *)arg0, (f32)TObjEneDf2Bringer__data_805D97F4) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D9810)) != 0) {
                spawn_offset_particle__17TObjEneDf2BringerFPv(arg0);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s16, 0xB8) = 2;
                F(s32, 0x4AC) = 1;
                F(s32, 0x3C0) |= 4;
                F(Sub_8009813C *, 0xA4)->flags |= 0x700;
            }
            if (enemy_validate_retained_target(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            F(s32, 0x60) = approach_angle_limited(F(s32, 0x60), (s32)(TObjEneDf2Bringer__data_8043A0F8 * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8))), 0x280);
            F(s32, 0x480) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(F(s32, 0x60), F(s32, 0x480), F(s32, 0x60), 0x200, 0x2000);
            VO->m87();
            break;
        case 1:
            spawn_particle_if_in_band__17TObjEneDf2BringerFPv(arg0);
            hit = 0;
            if (enemy_probe_wall_ahead__13TBoss5GryphonFfff(arg0, F(f32, 0x3A0), F(f32, 0x3A8), lbl_805D9814 * PRM->speed) != 0) {
                hit = 1;
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground(F(f32, 0x3A0), F(f32, 0x3A8), PRM->speed);
            if (((TObjEneDD *)arg0)->has_move_failures(1) != 0) {
                hit = 1;
            }
            ((TObjPlayer *)arg0)->update_enemy_collision_flags();
            if (F(Sub_8009813C *, 0xA4)->flags & 0x200000) {
                hit = 1;
            }
            if (TObjEneDf2Bringer__sub_80099248(arg0) != 0) {
                hit = 1;
            }
            if (enemy_validate_retained_target(arg0) != 0) {
                VecCopy((Vec *)&d, (const Vec *)(F(u8 *, 0x390) + 0x38));
                subtract_vector(&d, arg0 + 0x38);
                if (((TObjBoss2Tunnel *)(&d))->clamp_velocity() >= lbl_805D9814) {
                    if (d.x * sin_table_lookup(F(s32, 0x60)) + d.z * cos_table_lookup(F(s32, 0x60)) < TObjEneDf2Bringer__data_805D97E0) {
                        hit = 1;
                    }
                }
            }
            if (hit != 0) {
                F(s32, 0x4AC) = 2;
                F(s32, 0x4B0) = 0;
                F(s32, 0x484) = PRM->i1C;
                F(s32, 0x3C0) &= ~4;
                set_field_378__9TObjEneDDFl(arg0, 7);
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B40E), arg0 + 0x38, 0, 0);
                play_effect_if_v2__10TObjPlayerFl(-0x200);
            }
            play_persistent_sound(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD09), arg0, arg0 + 0x38, 0, 0);
            break;
        case 2:
            F(s32, 0x4B0)++;
            if (F(s32, 0x4B0) >= 10) {
                F(s16, 0xB8) = 3;
                update_if_in_band__17TObjEneDf2BringerFi(arg0);
                if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                    F(s32, 0x4AC) = 3;
                }
                F(f32, 0x4BC) *= lbl_805D9818;
            }
            if (F(f32, 0x4BC) >= lbl_805D981C) {
                TObjEneDf2Bringer__sub_80099248(arg0);
            } else {
                VO->m87();
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x4BC));
            break;
        }
        break;
    case 5:
        F(s32, 0x3C0) &= ~4;
        F(Sub_8009813C *, 0xA4)->flags &= ~0x700;
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneDf2Bringer__sub_8009859C(u8 *ene_df2_bringer, s32 arg1) {
    f32 t;
    s32 temp_r30;
    u8 *temp_r30_2;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_df2_bringer + 0xB8) = 1;
        set_field_378__9TObjEneDDFl(ene_df2_bringer, 4);
        ((TObjEneDD *)(ene_df2_bringer))->vfunc_96();
        *(s32 *)((s8 *)ene_df2_bringer + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_df2_bringer + 0x3C0) & 0xFFFFFFF8);
        *(s32 *)((s8 *)ene_df2_bringer + 0x4AC) = 0;
        break;
    case 3:
        if (*(u32 *)((s8 *)ene_df2_bringer + 0x390) == 0U) {
            transition_enemy_state__9TObjEneDDFs(ene_df2_bringer, 3);
        } else if ((*(f32 *)((s8 *)ene_df2_bringer + 0x3AC) >= (f32) *(s32 *)((s8 *)(*(u8 * *)&TObjEneDf2Bringer__data_805D4FB4) + 0x2C)) && (*(s32 *)((s8 *)ene_df2_bringer + 0x490) < 2)) {
            transition_enemy_state__9TObjEneDDFs(ene_df2_bringer, 5);
        } else if (*(s32 *)((s8 *)ene_df2_bringer + 0x4AC) == 1) {
            transition_enemy_state__9TObjEneDDFs(ene_df2_bringer, 6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_df2_bringer);
        if (update_flag_0x3C0__17TObjEneDf2BringerFPv(ene_df2_bringer) != 0) {
            ((TObjEneDD_ST *)ene_df2_bringer)->enemy_copy_target_destination();
            ((TObjEneDD *)ene_df2_bringer)->update_velocity();
        }
        {
        s32 ang;
        *(s32 *)((s8 *)ene_df2_bringer + 0x60) = approach_angle_limited((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60)), (s32)(ang = (s32) (TObjEneDf2Bringer__data_8043A0F8 * atan2_float(*(f32 *)((s8 *)ene_df2_bringer + 0x3A0), *(f32 *)((s8 *)ene_df2_bringer + 0x3A8)))), 0x300);
        *(s32 *)((s8 *)ene_df2_bringer + 0x480) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60)), (s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x480)), ang, 0x200, 0x2000);
        }
        temp_r30_2 = (*(u8 * *)&TObjEneDf2Bringer__data_805D4FB4);
        if (*(f32 *)((s8 *)ene_df2_bringer + 0x3AC) <= (f32) *(s32 *)((s8 *)temp_r30_2 + 0x28)) {
            t = *(f32 *)((s8 *)ene_df2_bringer + 0x3A8) * cos_table_lookup((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60)));
            t = (*(f32 *)((s8 *)ene_df2_bringer + 0x3A0) * sin_table_lookup((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60)))) + t;
            if (t >= cos_table_lookup(0x1800)) {
                *(s32 *)((s8 *)ene_df2_bringer + 0x4AC) = 1;
            }
        } else {
            t = cos_table_lookup((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60)));
            ((TObjEneDD *)ene_df2_bringer)->move_clamped_on_ground(sin_table_lookup((s32)(*(s32 *)((s8 *)ene_df2_bringer + 0x60))), t, *(f32 *)((s8 *)temp_r30_2 + 4));
        }
        ((TObjEneDD *)(ene_df2_bringer))->vfunc_89();
        TObjEneDf2Bringer__sub_80098EB4(ene_df2_bringer);
        break;
    }
}
#pragma pop

void TObjEneDf2Bringer__sub_800987E8(u8 *ene_dd_st, s32 arg1) {
    s32 temp_r0;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd_st + 0xB8) = 0;
        set_field_378__9TObjEneDDFl(ene_dd_st, 3);
        *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)(ene_dd_st))->vfunc_95();
        *(s32 *)((s8 *)ene_dd_st + 0x4AC) = 0;
        *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 0;
        return;
    case 3:
        if (*(s32 *)((s8 *)ene_dd_st + 0x4AC) == 2) {
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, 4);
        } else if (*(s32 *)((s8 *)ene_dd_st + 0x4AC) == 3) {
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, 1);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_dd_st);
        switch (*(s32 *)((s8 *)ene_dd_st + 0x4AC)) {
        case 0:
            if (update_linked_position__12TObjEneDD_STFf(ene_dd_st, TObjEneDf2Bringer__data_805D9820) != 0) {
                *(s32 *)((s8 *)ene_dd_st + 0x4AC) = 2;
            } else {
                *(s32 *)((s8 *)ene_dd_st + 0x4B0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x4B0) + 1);
                if ((s32) *(s32 *)((s8 *)ene_dd_st + 0x4B0) >= 0x3C) {
                    *(s32 *)((s8 *)ene_dd_st + 0x4AC) = 1;
                    ((V2_800987E8 *)(ene_dd_st + 0x3C4))->m2();
                    *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) | 2);
                }
            }
            break;
        case 1:
            if (((V2_800987E8 *)(ene_dd_st + 0x3C4))->m4() != 0) {
                *(s32 *)((s8 *)ene_dd_st + 0x4AC) = 3;
            }
            break;
        }
        ((TObjEneDD *)(ene_dd_st))->vfunc_102();
        ((TObjEneDD *)(ene_dd_st))->vfunc_89();
        break;
    }
}

#undef S
#undef F
#undef PRM
#undef VO
#undef F_8009
#undef update_flag_0x3C0__17TObjEneDf2BringerFPv
#undef update_attack_child__17TObjEneDf2BringerFPv
#undef TObjEneDf2Bringer__sub_80098FF4
#undef attack_visible_players__17TObjEneDf2BringerFPv
#undef TObjEneDf2Bringer__sub_80098EB4
#undef spawn_offset_particle__17TObjEneDf2BringerFPv
#undef spawn_particle_if_in_band__17TObjEneDf2BringerFPv
#undef update_if_in_band__17TObjEneDf2BringerFi
#define atan2_float ((f32 (*)(f64, f64))atan2_float)
#define TObjEneDf2Bringer__data_805D9820 (*(const f32 *)&TObjEneDf2Bringer__data_805D9820)
#define TObjEneDf2Bringer__sub_80097714 ((s32 (*)(void *, void *))TObjEneDf2Bringer__sub_80097714)
#define TObjEneDf2Bringer__sub_80097820 ((s32 (*)(void *, void *))TObjEneDf2Bringer__sub_80097820)
#define TObjEneDf2Bringer__sub_8009813C ((s32 (*)(void *, void *))TObjEneDf2Bringer__sub_8009813C)
#define TObjEneDf2Bringer__sub_8009859C ((s32 (*)(void *, void *))TObjEneDf2Bringer__sub_8009859C)
struct SubBase_80098970 { char pad[0x14]; };
struct SubObj_80098970 : SubBase_80098970 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual void v4();
    virtual s32 v5();
};

#define advance_animation_playback ((s32 (*)())advance_animation_playback)
#define play_sound_effect ((s32 (*)(s32, void *, s32, s32))play_sound_effect)
#define TObjEneDf2Bringer__sub_80098EB4 ((s32 (*)(void *))TObjEneDf2Bringer__sub_80098EB4)
#define update_if_in_band__17TObjEneDf2BringerFi ((s32 (*)(void *))update_if_in_band__17TObjEneDf2BringerFi)
#define spawn_particle_if_in_band__17TObjEneDf2BringerFPv ((s32 (*)(void *))spawn_particle_if_in_band__17TObjEneDf2BringerFPv)
#define play_effect_if_v2__10TObjPlayerFl ((s32 (*)(s32))play_effect_if_v2__10TObjPlayerFl)

#define TObjEneDf2Bringer__data_805D9820 (*(const f32 *)&TObjEneDf2Bringer__data_805D9820)
extern const f32 lbl_805D9824;

void TObjEneDf2Bringer::exec(s32 arg1) {
    u8 *arg0 = (u8 *)this;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        set_field_378__9TObjEneDDFl(arg0, 4);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFE);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 2);
        this->vfunc_95();
        ((SubObj_80098970 *)(arg0 + 0x3C4))->v3();
        *(s32 *)((s8 *)arg0 + 0x4AC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3640D), arg0 + 0x38, 0, 0);
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
        *(s32 *)((s8 *)arg0 + 0x494) = 0;
        *(s32 *)((s8 *)arg0 + 0x48C) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4B0) == 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        }
        return;
    case 0:
        advance_animation_playback();
        update_linked_position__12TObjEneDD_STFf(arg0, TObjEneDf2Bringer__data_805D9820);
        *(s32 *)((s8 *)arg0 + 0x4AC) = (s32) (*(s32 *)((s8 *)arg0 + 0x4AC) + 1);
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4AC) > 0x14) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 1;
                *(s16 *)((s8 *)arg0 + 0xB8) = 3;
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B40E), arg0 + 0x38, 0, 0);
                play_effect_if_v2__10TObjPlayerFl(-0x200);
            }
            spawn_particle_if_in_band__17TObjEneDf2BringerFPv(arg0);
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), lbl_805D9824);
            TObjEneDf2Bringer__sub_80098EB4(arg0);
            break;
        case 1:
            update_if_in_band__17TObjEneDf2BringerFi(arg0);
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 2;
            }
            break;
        }
        if (((SubObj_80098970 *)(arg0 + 0x3C4))->v5() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFD);
            this->vfunc_96();
            this->vfunc_89();
            return;
        }
        break;
    case 5:
        this->vfunc_96();
        break;
    }
}

void TObjEneDf2Bringer__sub_80098BAC(u8 *ene_dd_st, s32 arg1) {
    switch (arg1) {
    case 4:
        ((s32)set_field_378__9TObjEneDDFl(ene_dd_st, 1));
        *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) | 1);
        ((TObjEneDD_ST *)(ene_dd_st))->vfunc_95();
        return;
    case 3:
        if (((s32)update_linked_position__12TObjEneDD_STFf(ene_dd_st, TObjEneDf2Bringer__data_805D9820)) != 0) {
            ((TObjEneDD_ST *)ene_dd_st)->enemy_copy_target_destination();
            ((TObjEneDD *)ene_dd_st)->update_velocity();
            *(s32 *)((s8 *)ene_dd_st + 0x60) = (s32) (TObjEneDf2Bringer__data_8043A0F8 * atan2_float((f64) *(f32 *)((s8 *)ene_dd_st + 0x3A0), (f64) *(f32 *)((s8 *)ene_dd_st + 0x3A8)));
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, 2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneDf2Bringer::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        set_field_378__9TObjEneDDFl(this, 0);
        *(s32 *)((s8 *)this + 0x4AC) = 0;
        return;
    case 3:
        transition_enemy_state__9TObjEneDDFs(this, 1);
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x4AC) = (s32) (*(s32 *)((s8 *)this + 0x4AC) + 1);
    case 5:
        return;
    }
}
void TObjEneDf2Bringer__vt85(s32 ene_dd_st, u32 arg1, s32 mode) {
    switch (arg1) {
    case 0:
        ((TObjEneDf2Bringer *)ene_dd_st)->handle_state(mode);
        return;
    case 1:
        TObjEneDf2Bringer__sub_80098BAC((u8 *)ene_dd_st, (s32)mode);
        return;
    case 2:
        ((TObjEneDf2Bringer *)ene_dd_st)->exec(mode);
        return;
    case 3:
        TObjEneDf2Bringer__sub_800987E8((u8 *)ene_dd_st, (mode));
        return;
    case 4:
        TObjEneDf2Bringer__sub_8009859C((void *)ene_dd_st, (void *)mode);
        return;
    case 5:
        TObjEneDf2Bringer__sub_8009813C((void *)ene_dd_st, (void *)mode);
        return;
    case 6:
        TObjEneDf2Bringer__sub_80097E9C((u8 *)ene_dd_st, (mode));
        return;
    case 7:
        action__17TObjEneDf2BringerFPvi((u8 *)ene_dd_st, (mode));
        return;
    case 8:
        TObjEneDf2Bringer__sub_80097820((void *)ene_dd_st, (void *)mode);
        return;
    case 9:
        TObjEneDf2Bringer__sub_80097714((void *)ene_dd_st, (void *)mode);
        return;
    case 10:
        TObjEneDf2Bringer__sub_80097620((u8 *)ene_dd_st, (mode));
    default:
        return;
    }
}
#undef TObjEneDf2Bringer__data_805D9820
#undef play_effect_if_v2__10TObjPlayerFl
#undef spawn_particle_if_in_band__17TObjEneDf2BringerFPv
#undef update_if_in_band__17TObjEneDf2BringerFi
#undef play_sound_effect
#undef advance_animation_playback
#undef TObjEneDf2Bringer__sub_8009859C
#undef TObjEneDf2Bringer__sub_8009813C
#undef TObjEneDf2Bringer__sub_80097820
#undef TObjEneDf2Bringer__sub_80097714
#undef TObjEneDf2Bringer__data_805D9820
#undef atan2_float
#undef TObjEneDf2Bringer__sub_80098EB4

struct Stack_800991E0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Obj_80098FF4 {
    u8 pad0[0x38];
    u8 pos[0x2FC - 0x38];
    u8 field2FC[4];
};

struct Pair_800993E8 { s32 a; u32 flags; };

struct ChildBase_800993E8 { char pad[0x18]; };

struct Child_800993E8 : ChildBase_800993E8 {
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
    virtual void m15(Pair_800993E8 *, s32);
};

struct BringerBase_800993E8 { char pad[0x18]; };

struct Bringer_800993E8 : BringerBase_800993E8 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual s32 m97();
};

struct Vec_800993E8 { f32 x, y, z; };

struct Entry_800993E8 { u8 pad0[0xC]; Vec_800993E8 a; u8 pad18[0x24 - 0x18]; Vec_800993E8 b; };

struct Model_800993E8 { u8 pad0[0x2C]; Vec_800993E8 b; };

struct ChildFields_800993E8 {
    u8 pad0[0x38];
    Vec_800993E8 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Model_800993E8 *model;
};

struct Fields_800993E8 {
    u8 pad0[0x38];
    Vec_800993E8 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xC0 - 0x64];
    f32 frame;
    u8 padC4[0x498 - 0xC4];
    Child_800993E8 *child;
    s32 field49C;
};

struct Obj_80098EFC {
    u8 pad0[0x38];
    u8 pos[0x2FC - 0x38];
    u8 field2FC[0x474 - 0x2FC];
    u8 field474[4];
};

extern "C" {
void *get_player_by_client_id(s32 i);
s32 rotate_xz_pair_by_angle(f32 *, f32 *, s32, f32, f32);
void *spawn_particle_effect(void *pos, s32 id);
s32 vec3_add_to(f32 *, void *);
extern const f32 lbl_805D9830;
#define copy_target_state__14TObjEnePanarmsFPv ((s32 (*)(void *, int))copy_target_state__14TObjEnePanarmsFPv)
#define play_persistent_sound ((s32 (*)(void *, void *, void *, int, int))play_persistent_sound)
Obj_80098FF4 *get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);
u32 csnLookAt(void *, void *);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
s32 is_alive__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805D982C;
#define lookup_entry_by_value__10TObjPlayerFPvf ((Entry_800993E8 * (*)(void *, f32))lookup_entry_by_value__10TObjPlayerFPvf)
extern Pair_800993E8 lbl_8043A0CC[];
#define TObjEneDf2Bringer__trail_buffer (*(void * *)&TObjEneDf2Bringer__trail_buffer)
extern const f32 lbl_805D9838;
extern const f32 lbl_805D983C;
void check_can_act__10TObjPlayerFii(void *, s16);
s16 obj_getS16_32E(u8 *p);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
u8 *fn_8009A398(void *, void *, void *, void *);
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
extern const f32 lbl_805D9828;
struct Base_80098E4C_80098DB0 { char pad[0x18]; };
struct VObj_80098E4C_80098DB0 : Base_80098E4C_80098DB0 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual int m97();
};

#define enemy_validate_retained_target ((s32 (*)())enemy_validate_retained_target)
s32 spawn_part__14TObjEneEpsilonFi(void *, f32);
#define update_linked_position__12TObjEneDD_STFf ((s32 (*)(f32))update_linked_position__12TObjEneDD_STFf)

s32 TObjEneDf2Bringer::check_stage_advance() {
    if ((s32) *(s32 *)((s8 *)this + 0x494) >= 5) {
        transition_enemy_state__9TObjEneDDFs(this, 8);
        return 1;
    }
    return 0;
}

void TObjEneDf2Bringer::sub_80098DEC() {
    u8 *arg0 = (u8 *)this;
    s32 player;
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)arg0 + 0x2D4);
    if (temp_r3 < 0x1000U) {
        player = (s32)get_player_by_client_id(temp_r3);
        if (player != 0) {
            ((TObjEneDD_ST *)arg0)->set_target_player((void *)player);
        }
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 8);
    }
    *(s32 *)((s8 *)arg0 + 0x494) = (s32) (*(s32 *)((s8 *)arg0 + 0x494) + 1);
}

void TObjEneDf2Bringer__vt102(void *ene_epsilon, f32 farg0) {
    if (((VObj_80098E4C_80098DB0 *)ene_epsilon)->m97() != 0) {
        ((TObjEneDD_ST *)ene_epsilon)->select_and_apply_target(farg0);
        return;
    }
    spawn_part__14TObjEneEpsilonFi(ene_epsilon, farg0);
}

void TObjEneDf2Bringer__sub_80098EB4(s32 arg0) {
    play_persistent_sound((void *) (copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003B708)), (void *)arg0, (void *)(arg0 + 0x38), 0, 0);
}

s32 attack_visible_players__17TObjEneDf2BringerFPv(Obj_80098EFC *self) {
    s32 count;
    Obj_80098EFC *player;
    s32 total;
    s32 i;
    s32 dmg;
    void *o;
    count = TLobby::get_game_mode();
    total = 0;
    for (i = 0; i < count; i++) {
        player = ((Obj_80098EFC *)get_player_data__10TObjPlayerFi(i));
        if (is_alive__9TObjEneDDFv(player) != 0) {
            horizontal_distance_squared(self->field2FC, player->pos);
            if (csnLookAt(self->field2FC, player->field2FC) == 0) {
                dmg = get_random_float__21TObjEneMe3ShinowaRealFv(lbl_805D9828 * (f32)obj_getS16_32E((u8 *)player));
                check_can_act__10TObjPlayerFii(player, dmg);
                total += dmg;
                o = __nw__7TObjectFUl(0x54);
                if (o != 0) {
                    fn_8009A398(o, self, player->field2FC, self->field474);
                }
            }
        }
    }
    return total;
}

s32 TObjEneDf2Bringer__sub_80098FF4(Obj_80098FF4 *self) {
    s32 count;
    Obj_80098FF4 *player;
    u16 id;
    s32 i;
    f32 dist;
    f32 best;
    best = TObjEneDf2Bringer__data_805D97E0;
    id = 0xFFFF;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = get_player_data__10TObjPlayerFi(i);
        if (is_alive__9TObjEneDDFv(player) != 0) {
            dist = horizontal_distance_squared(self->field2FC, player->pos);
            if (dist < lbl_805D982C && dist > best &&
                csnLookAt(self->field2FC, player->field2FC) == 0) {
                id = get_entity_id(player);
                best = dist;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(self, id);
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs(self);
    return 0;
}

void update_flag_0x3C0__17TObjEneDf2BringerFPv(void *arg0) {
    if (!(*(s32 *)((s8 *)arg0 + 0x3C0) & 8)) {
        update_linked_position__12TObjEneDD_STFf(TObjEneDf2Bringer__data_805D9820);
        return;
    }
    if (enemy_validate_retained_target() == 0) {
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF7);
    }
}

void update_if_in_band__17TObjEneDf2BringerFi(s32 arg0) {
    if (objInBand((GameObj *)arg0, lbl_805D9810) != 0) {
        spawn_offset_particle__17TObjEneDf2BringerFPv((u8 *)arg0);
    }
}

void spawn_particle_if_in_band__17TObjEneDf2BringerFPv(u8 *arg0) {
    if ((objInBand((GameObj *)arg0, (f32)TObjEneDf2Bringer__data_805D97E0) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D97E8)) != 0)) {
        spawn_particle_effect(arg0 + 0x38, 0xF0);
    }
}

void spawn_offset_particle__17TObjEneDf2BringerFPv(u8 *arg0) {
    Stack_800991E0 stack;
    stack.sp8 = lbl_805D9830;
    stack.spC = TObjEneDf2Bringer__data_805D97E0;
    stack.sp10 = TObjEneDf2Bringer__data_805D9808;
    rotate_xz_pair_by_angle(&stack.sp8, &stack.sp10, *(s32 *)((s8 *)arg0 + 0x60), TObjEneDf2Bringer__data_805D97E0, lbl_805D9830);
    vec3_add_to(&stack.sp8, arg0 + 0x38);
    spawn_particle_effect(&stack.sp8, 0xF3);
}
s32 check_enemy_body_collisions(void *);
s32 obj_is_hit_receivable(void);
s32 attack_target_history_add(s32, TObjPlayer *);
s32 is_player_entity_id(u16);
s32 is_locally_controlled__10TObjPlayerFPv(TObjPlayer *);
TItem *get_item_field_6__10TObjPlayerFPv(TObjPlayer *);
void send_6x26_unequip_item__10TObjPlayerFPvPv(TObjPlayer *, s32);
void TObjEneDD__sub_800BA438(void *, TObjPlayer *);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
extern const f32 lbl_805D9834;

s32 TObjEneDf2Bringer__sub_80099248(void *bringer) {
    s32 hit;
    TObjPlayer *player;
    s32 i;
    u8 *eff;
    hit = 0;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)bringer)->check_object_collisions();
    check_enemy_body_collisions(bringer);
    if (*(s32 *)((s8 *)(*(u8 **)((s8 *)bringer + 0xA4)) + 0x18) & 0x180000) {
        hit = 1;
        for (i = 0; i < 0x10; i++) {
            player = (TObjPlayer *)TObjPlayer::get_battle_param(i);
            if (player == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && attack_target_history_add(*(s32 *)((s8 *)bringer + 0x49C), player) != 0) {
                DirectAttackPayload h;
                h.kind = 0;
                h.power = TObjEneDf2Bringer__data_805D4FB4->i20;
                player->receive_direct_attack(bringer, h, 0, -1, -1);
                if (is_player_entity_id(get_entity_id(player)) != 0) {
                    if (TObjEneDD::check_v2_mode() != 0) {
                        if (is_locally_controlled__10TObjPlayerFPv(player) != 0) {
                            TItem *item = get_item_field_6__10TObjPlayerFPv(player);
                            if (item != NULL) {
                                send_6x26_unequip_item__10TObjPlayerFPvPv(player, item->get_item_id());
                            }
                        }
                    } else if (calc_boss4_scale__10TObjPlayerFi(bringer) <= lbl_805D9834) {
                        TObjEneDD__sub_800BA438(bringer, player);
                    }
                }
                eff = (u8 *)__nw__7TObjectFUl(0x34);
                if (eff != NULL) {
                    construct_bringer_rush_effect(eff, (s32)bringer, (u8 *)bringer, (s32)player, lbl_805D97F0);
                }
            }
        }
    }
    return hit;
}

void update_attack_child__17TObjEneDf2BringerFPv(Bringer_800993E8 *obj) {
    Fields_800993E8 *self = (Fields_800993E8 *)obj;
    Entry_800993E8 *entry;
    f32 start;
    if (TObjEneDD::check_v2_mode() != 0) {
        start = lbl_805D9838;
    } else {
        start = lbl_805D980C;
    }
    if (self->frame >= start && self->frame <= lbl_805D983C) {
        entry = lookup_entry_by_value__10TObjPlayerFPvf(TObjEneDf2Bringer__trail_buffer, self->frame);
        VecCopy((Vec *)(&((ChildFields_800993E8 *)self->child)->pos), (const Vec *)&self->pos);
        ((ChildFields_800993E8 *)self->child)->angle = self->angle;
        VecCopy((Vec *)(((ChildFields_800993E8 *)self->child)->model), (const Vec *)&entry->a);
        VecCopy((Vec *)(&((ChildFields_800993E8 *)self->child)->model->b), (const Vec *)&entry->b);
        ((TUnk_804AF8A0 *)(self->child))->refresh_collision_body_centers();
        Pair_800993E8 pair = lbl_8043A0CC[0];
        if (obj->m97() != 0) {
            pair.flags |= 2;
        }
        self->child->m15(&pair, self->field49C);
    }
}

#undef lookup_entry_by_value__10TObjPlayerFPvf
#undef play_persistent_sound
#undef copy_target_state__14TObjEnePanarmsFPv
#undef update_linked_position__12TObjEneDD_STFf
#undef enemy_validate_retained_target
#undef __nw__7TObjectFUl
#undef TObjEneDf2Bringer__trail_buffer
#define sub_80098DEC__17TObjEneDf2BringerFv ((s32 (*)())sub_80098DEC__17TObjEneDf2BringerFv)
#define clear_attack_receipts__9TObjEneDDFv ((s32 (*)(void *))clear_attack_receipts__9TObjEneDDFv)
#define transition_enemy_state__9TObjEneDDFs ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)
extern const f32 lbl_805D9840;

void TObjEneDf2Bringer__sub_800994F8(void) {  }
void TObjEneDf2Bringer::vfunc_88() {  }

void TObjEneDf2Bringer::set_effect_pos_above_self() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + lbl_805D9840);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneDf2Bringer::vfunc_61() {  }

void TObjEneDf2Bringer::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)arg0 + 0x326);
    if ((temp_r0 != 9) && (temp_r0 != 8)) {
        sub_80098DEC__17TObjEneDf2BringerFv();
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C0) & 4) {
        clear_attack_receipts__9TObjEneDDFv(arg0);
        return;
    }
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 9) {
        transition_enemy_state__9TObjEneDDFs(arg0, (void*)(9));
    }
}

}
#undef transition_enemy_state__9TObjEneDDFs
#undef clear_attack_receipts__9TObjEneDDFv
#undef sub_80098DEC__17TObjEneDf2BringerFv

struct VBase_18_p5 { char pad[0x18]; };
struct VObj_18_p5 : VBase_18_p5 {
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct VBase_14_fa0828 { char pad[0x14]; };
struct VObj_14_fa0828 : VBase_14_fa0828 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
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

#define set_effect_pos_above_self__17TObjEneDf2BringerFv ((s32 (*)(void *))set_effect_pos_above_self__17TObjEneDf2BringerFv)
extern const f32 lbl_805D9844;
extern "C" {
void *TObjEneDf2Bringer__ct(void *arg0, void *arg1, void *arg2);
void TLobby__sub_8001FE7C(void*, int);
}
#define transition_enemy_state__9TObjEneDDFs ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)
#define TObjEneDf2Bringer__sub_800994F8 ((void (*)(void *))TObjEneDf2Bringer__sub_800994F8)
void bringer_effect_cleanup_noop(void);
extern "C" {
void __construct_array(void *, void *, void *, int, int);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
}
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);

void TObjEneDf2Bringer::vfunc_63() { if (*(short*)((char*)this + 0x326) != 10) { transition_enemy_state__9TObjEneDDFs(this, (void*)10); } }
void TObjEneDf2Bringer::vfunc_28() {  }

extern s32 init_and_activate__10TObjPlayerFv[];
extern void *lbl_805D29A0;

void run_task__17TObjEneDf2BringerFv(u8 *arg0) {
    s32 temp_r0;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneDf2Bringer *)(arg0))->vfunc_83();
        return;
    }
    if (((VObj_18_p5 *)(arg0))->m81() != 4) {
        ((TObjEneDf2Bringer *)(arg0))->vfunc_85();
        *(s32 *)((s8 *)arg0 + 0x4A8) = (s32) (*(s32 *)((s8 *)arg0 + 0x4A8) + 0xC);
        *(s32 *)((s8 *)arg0 + 0x4A8) = (s32) (u8) *(s32 *)((s8 *)arg0 + 0x4A8);
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x494);
        if (temp_r0 <= 2) {
            *(s32 *)((s8 *)arg0 + 0x488) = 1;
        } else if (temp_r0 <= 4) {
            *(s32 *)((s8 *)arg0 + 0x488) = 5;
        } else if (temp_r0 <= 5) {
            *(s32 *)((s8 *)arg0 + 0x488) = 6;
        }
    }
    set_effect_pos_above_self__17TObjEneDf2BringerFv(arg0);
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    ((TObjEneDf2Bringer *)(arg0))->vfunc_100();
}

struct Vec_80099800 { f32 x, y, z; };
struct Slot_80099800 { u8 pad[0x1C]; };

void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
u8 *TBoss8Dragon__sub_800BC5EC(u8 *arg0, s32 arg1);
s32 create__12TObjEneSaverFPvPv(s32, s32);
extern s32 bringer_boss_stats_handle;
extern s32 bringer_boss_stats_ptr_b;
extern s32 bringer_object_handle;
extern u32 TObjEneDf2Bringer__resource_bundle;
struct Arr_80099800 { u8 pad[0x3E0]; Slot_80099800 slot[4]; Vec_80099800 v[4]; };

u8 *__dt__17TObjEneDf2BringerFv(u8 *arg0, s16 arg1) {
    VObj_800996EC *o;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjEneDf2Bringer;
        if (*(void **)((s8 *)arg0 + 0x4C4) != NULL) {
            queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x4C4)));
            *(void **)((s8 *)arg0 + 0x4C4) = NULL;
        }
        queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x4A4)));
        *(s32 *)((s8 *)arg0 + 0x4A4) = 0;
        o = *(VObj_800996EC **)((s8 *)arg0 + 0x4A0);
        if (o != NULL) {
            o->m0(1);
        }
        *(void **)((s8 *)arg0 + 0x4A0) = NULL;
        delete_buffer__12TBoss8DragonFis(*(s32 *)((s8 *)arg0 + 0x49C), 1);
        *(s32 *)((s8 *)arg0 + 0x49C) = 0;
        o = *(VObj_800996EC **)((s8 *)arg0 + 0x498);
        if (o != NULL) {
            o->m0(1);
        }
        *(void **)((s8 *)arg0 + 0x498) = NULL;
        free_collision_body_parts(arg0);
        __destroy_arr(arg0 + 0x3E0, __dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80490470Fv(arg0 + 0x3C4, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneDf2Bringer::init_enemy() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    void *p;

    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneDf2Bringer__resource_bundle + 0x42C)) + 8);
    *(s32 *)((s8 *)arg0 + 0x24) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneDf2Bringer__resource_bundle + 0x42C)) + 0xC);
    init_model__9TObjEneDDFv(arg0, lbl_8048FA2C, 1);
    ((TObjMotion *)arg0)->set_field_d8((s32)&lbl_8048FAF8);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)TObjEneDf2Bringer__resource_bundle + 0x430));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    reset_hp__9TObjEneDDFv(arg0, bringer_boss_stats_handle, bringer_boss_stats_ptr_b, bringer_object_handle);
    ((TObjEneDD *)arg0)->set_state_8();
    *(void **)((s8 *)arg0 + 0x350) = bringer_init_params;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x24);
    *(f32 *)((s8 *)arg0 + 0x37C) = lbl_805D9840;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0x1E);
    *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C0) |= 1;
    ((VObj_14_fa0828 *)(arg0 + 0x3C4))->m3();
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((Arr_80099800 *)arg0)->slot[i]))->activate_and_dispatch();
    }
    for (i = 0; i < 4; i++) {
        VecCopy((Vec *)(&((Arr_80099800 *)arg0)->v[i]), (const Vec *)(arg0 + 0x38));
    }
    *(s32 *)((s8 *)arg0 + 0x480) = 0;
    *(s32 *)((s8 *)arg0 + 0x484) = 0;
    *(s32 *)((s8 *)arg0 + 0x488) = 1;
    *(s32 *)((s8 *)arg0 + 0x494) = 0;
    *(s32 *)((s8 *)arg0 + 0x48C) = 0;
    *(s32 *)((s8 *)arg0 + 0x490) = 0;
    p = __nw__7TObjectFUl(0xB0);
    if (p != NULL) {
        p = ((TUnk_804928CC *)p)->init_instance(arg0, arg0, (u8 *)lbl_8048FA2C + 0x2C, (void *)2);
    }
    *(void **)((s8 *)arg0 + 0x498) = p;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x10);
    if (p != NULL) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 8);
    }
    *(void **)((s8 *)arg0 + 0x49C) = p;
    p = __nw__7TObjectFUl(0xD4);
    if (p != NULL) {
        p = ((TUnk_8048FE08 *)p)->init((int)arg0, (int)arg0, *(s32 *)((s8 *)arg0 + 0x49C));
    }
    *(void **)((s8 *)arg0 + 0x4A0) = p;
    *(s32 *)((s8 *)arg0 + 0x4A4) = create__12TObjEneSaverFPvPv(0xFF5050FF, 0x80000080);
    *(s32 *)((s8 *)arg0 + 0x4A8) = 0;
    *(s32 *)((s8 *)arg0 + 0x4AC) = 0;
    *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
    *(s32 *)((s8 *)arg0 + 0x4B4) = 0;
    *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
    *(f32 *)((s8 *)arg0 + 0x4BC) = TObjEneDf2Bringer__data_805D97E0;
    *(f32 *)((s8 *)arg0 + 0x4C0) = TObjEneDf2Bringer__data_805D97E0;
    *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
    *(s16 *)((s8 *)arg0 + 0x326) = 1;
    ((VObj_18_be4a70 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
}

void *TObjEneDf2Bringer__ct(void *ene_df2_bringer, void *arg1, void *arg2) {
    ((TObjEneDD_ST *)ene_df2_bringer)->init_object();
    *(s32 **)((s8 *)ene_df2_bringer + 0x18) = __vt__17TObjEneDf2Bringer;
    ((TUnk_80490470 *)((char *)ene_df2_bringer + 964))->init_vtable_and_field18();
    __construct_array((void *)((char *)ene_df2_bringer + 992), init_and_activate__10TObjPlayerFv, __dt__13TUnk_804949A8Fv, 28, 4);
    *(void **)((s8 *)ene_df2_bringer + 0x0) = lbl_805D29A0;
    invoke_initialization_hook__9TObjEneDDFv(ene_df2_bringer, arg2);
    TObjEneDf2Bringer__sub_800994F8(ene_df2_bringer);
    ((TObjEneDf2Bringer *)ene_df2_bringer)->init_enemy();
    return ene_df2_bringer;
}

#define TObjEneDf2Bringer__trail_buffer (*(u32 *)&TObjEneDf2Bringer__trail_buffer)
#define TObjEneDf2Bringer__uv_scroll_buffer (*(u32 *)&TObjEneDf2Bringer__uv_scroll_buffer)

typedef struct RecoveredGlobal_8031B170_lbl_804E8880 RecoveredGlobal_8031B170_lbl_804E8880;
typedef char RecoveredGlobal_8031B170_lbl_804E8880_size[((sizeof(RecoveredGlobal_8031B170_lbl_804E8880)) == 0xD0) ? (1) : (-1)];
void TObjEneDf2Bringer::set_entry_value_clamped(s32 arg0, f32 farg0) {
  u8 *new_var;
  f32 var_f1;
  var_f1 = farg0;
  if (var_f1 < lbl_805D9844)
  {
    var_f1 = lbl_805D9844;
  }
  new_var = (u8 *)&lbl_8048FAF8.value;
  new_var = new_var + (arg0 * 0x10);
  *((f32 *) (((s8 *) new_var) + 8)) = var_f1;
}

void TObjEneDf2Bringer::free_resources() {
    bringer_effect_cleanup_noop();
    if ((u32) TObjEneDf2Bringer__uv_scroll_buffer != 0U) {
        destroy_buffer_pair((void *)TObjEneDf2Bringer__uv_scroll_buffer, 1);
        TObjEneDf2Bringer__uv_scroll_buffer = 0U;
    }
    if ((u32) TObjEneDf2Bringer__trail_buffer != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)TObjEneDf2Bringer__trail_buffer, 1);
        TObjEneDf2Bringer__trail_buffer = 0U;
    }
    if ((u32) TObjEneDf2Bringer__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDf2Bringer__resource_bundle, 1);
        TObjEneDf2Bringer__resource_bundle = 0U;
    }
}

extern void *tl_04;

void *TObjEneDf2Bringer::create() {
    void *o = __nw__7TObjectFUl(0x4C8);
    if (o != NULL) {
        o = TObjEneDf2Bringer__ct(o, tl_04, this);
    }
    return o;
}

typedef struct Ent_80099BD4 Ent_80099BD4;
typedef struct Path_80099BD4 Path_80099BD4;
typedef struct Seg_80099BD4 Seg_80099BD4;
typedef struct Sp_80099BD4 Sp_80099BD4;
typedef struct Vec_80099BD4 Vec_80099BD4;
struct Vec_80099BD4
{
  f32 x;
  f32 y;
  f32 z;
};
struct Ent_80099BD4
{
  s32 k;
  s32 v;
};
struct Sp_80099BD4
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
};
struct Seg_80099BD4
{
  Vec_80099BD4 p0;
  Vec_80099BD4 p1;
  Vec_80099BD4 p2;
  Vec_80099BD4 p3;
};
struct Path_80099BD4
{
  Seg_80099BD4 *segs;
  s32 pad;
  s32 n;
};
u8 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
}
void init_bringer_effect_tables(void);
extern "C" {
u32 load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
void *init_trail_buffer__11TBoss4Type3FPvifff(void *, s32, f32, f32, f32);
extern Sp_80099BD4 lbl_8043A0BC[];
extern u8 lbl_8043A108[];
extern const f32 lbl_805D9848;
extern const f32 lbl_805D984C;
#define bringer_camera_ctrl_target_vec (*(Vec_80099BD4 *)&bringer_camera_ctrl_target_vec)
#define TObjEneDf2Bringer__data_805D4FB4 (*(u8 **)&TObjEneDf2Bringer__data_805D4FB4)
#pragma push
#pragma fp_contract on
void TObjEneDf2Bringer::load_resources() {
  Vec_80099BD4 offs[4];
  s32 ids[4];
  Vec_80099BD4 a;
  Vec_80099BD4 d;
  void *o;
  Vec_80099BD4 *p3;
  s32 n;
  Seg_80099BD4 *seg;
  Vec_80099BD4 *p1;
  s32 i;
  f32 k1;
  f32 len;
  f32 s2;
  f32 k2;
  f32 s1;
  s32 j;
  bringer_camera_ctrl_target_vec.x = TObjEneDf2Bringer__data_805D97E0;
  bringer_camera_ctrl_target_vec.y = TObjEneDf2Bringer__data_805D97E0;
  bringer_camera_ctrl_target_vec.z = TObjEneDf2Bringer__data_805D97E0;
  if (TObjEneDD::check_v2_mode() != 0)
  {
    TObjEneDf2Bringer__resource_bundle = load_enemy_bml_resource_named(bm_ene_df2_bringer_resource_descriptor, lbl_8043A108);
  }
  else
  {
    TObjEneDf2Bringer__resource_bundle = load_enemy_bml_resource((u8 *)bm_ene_df2_bringer_resource_descriptor);
  }
  bringer_boss_stats_handle = register_boss__6TLobbyFl(0xD);
  bringer_boss_stats_ptr_b = dispatch_shared_handler_b__6TLobbyFl(0xD);
  bringer_object_handle = register_object__6TLobbyFl(0xD);
  TObjEneDf2Bringer__data_805D4FB4 = dispatch_shared_handler_a__6TLobbyFl(0xD);
  TObjEneDf2Bringer__render_node_index = 0;
  TObjEneDf2Bringer__render_rotation_x = 0;
  TObjEneDf2Bringer__render_point_cursor = 0;
  TObjEneDf2Bringer::set_entry_value_clamped(4, *((f32 *)(TObjEneDf2Bringer__data_805D4FB4 + 8)));
  TObjEneDf2Bringer::set_entry_value_clamped(5, *((f32 *)(TObjEneDf2Bringer__data_805D4FB4 + 0xC)));
  o = alloc__23TAdSinglePlyChrSelectGCFv(0x18);
  if (o != 0)
  {
    o = init_trail_buffer__11TBoss4Type3FPvifff(o, 4, TObjEneDf2Bringer__data_805D9808, lbl_805D97FC, *((f32 *) (((u8 *)&lbl_8048FAF8) + 0x48)));
  }
  TObjEneDf2Bringer__trail_buffer = (u32) o;
  {
    ids[0] = 0x1A;
    ids[1] = 0x1A;
    ids[2] = 0x1E;
    ids[3] = 0x1E;
    for (i = 0; i < 4; i++)
    {
      offs[i].x = TObjEneDf2Bringer__data_805D97E0;
      offs[i].y = TObjEneDf2Bringer__data_805D97E0;
      offs[i].z = TObjEneDf2Bringer__data_805D97E0;
    }

    ((TBoss4Type3 *)o)->draw_motion_trail((s32)(*((s32 *) ((*((u8 **) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x42C))) + 8))), (s32)((*((Ent_80099BD4 **) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x430)))[*((s32 *) (((u8 *)&lbl_8048FAF8) + 0x44))].v), (s32)ids, (s32)offs);
  }
  k1 = lbl_805D9848;
  n = ((Path_80099BD4 *) TObjEneDf2Bringer__trail_buffer)->n;
  seg = ((Path_80099BD4 *) TObjEneDf2Bringer__trail_buffer)->segs;
  k2 = lbl_805D984C;
  for (j = 0; j < n; seg++, j++)
  {
    VecCopy((Vec *)&a, (const Vec *)&seg->p0);
    VecCopy((Vec *)&d, (const Vec *)&seg->p2);
    subtract_vector(&d, &a);
    len = ((TObjBoss2Tunnel *)(&d))->update_scale();
    p1 = &seg->p1;
    s1 = k1 * len;
    VecCopy((Vec *)p1, (const Vec *)&a);
    p3 = &seg->p3;
    s2 = k2 * len;
    p1->x = (d.x * s1) + p1->x;
    p1->y = (d.y * s1) + p1->y;
    p1->z = (d.z * s1) + p1->z;
    VecCopy((Vec *)p3, (const Vec *)&a);
    p3->x = (d.x * s2) + p3->x;
    p3->y = (d.y * s2) + p3->y;
    p3->z = (d.z * s2) + p3->z;
  }

  o = alloc__23TAdSinglePlyChrSelectGCFv(0x14);
  if (o != 0)
  {
    o = ((TLobby *)o)->alloc_tables(*((s32 *) ((*((u8 **) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x42C))) + 8)), 1);
  }
  TObjEneDf2Bringer__uv_scroll_buffer = (u32) o;
  init_bringer_effect_tables();
  {
    Sp_80099BD4 sp = lbl_8043A0BC[0];
    sp.a = *((s32 *) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x430));
    TLobby::spawn_npc_enemy((s16)0x16, (s32)(*((s32 *) ((*((u8 **) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x42C))) + 8))), (s32)(*((s32 *) ((*((u8 **) (((u8 *) TObjEneDf2Bringer__resource_bundle) + 0x42C))) + 0xC))), (s32)&sp, (f32)TObjEneDf2Bringer__data_805D9808, (f32)TObjEneDf2Bringer__data_805D97E0);
  }
}
}
#pragma pop
#undef bringer_camera_ctrl_target_vec
#undef TObjEneDf2Bringer__data_805D4FB4

#undef TObjEneDf2Bringer__uv_scroll_buffer
#undef TObjEneDf2Bringer__trail_buffer
#undef TObjEneDf2Bringer__sub_800994F8
#undef set_effect_pos_above_self__17TObjEneDf2BringerFv
#undef __nw__7TObjectFUl
#undef transition_enemy_state__9TObjEneDDFs
