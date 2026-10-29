#include "pso/enemy/TObjEnemy.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TUnk_8049387C.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe1Gee.h"
#include "pso/map/FloorArea.h"
class TObjEneMe1Gee_NEEDLE;
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/object/obj_band.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"

struct D_800CC950;
struct Data_800C82A4;
struct Ene_800CB3A4;
struct Gee_800C8788;
struct Gee_800C8950;
struct Obj_800C86E0;
struct Obj_800C88D4;
struct Obj_800C8B4C;
extern "C" {
s32 advance_animation_playback(void *, s32);
s32 create_breakup_mdl__12TBoss3VoloptFlllll(s32, s32, s32, void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
int TObjEneMe1Gee__sub_800CB628(void* p);
int TObjEneMe1Gee__vt102(void* p);
int vfunc_89__13TObjEneMe1GeeFv(void* p);
s32 vfunc_116__13TUnk_8049387CFv(Obj_800C86E0 *arg0);
s32 vfunc_108__13TUnk_8049387CFv(Obj_800C88D4 *self);
void *__ct__13TUnk_80494938Fv(void *);
s32 __ct__12TObjEneDD_STFP7TObject(void *);
u8 * TObjEneMe1Gee__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s16 arg4, s16 arg5);
u8 vfunc_109__13TUnk_8049387CFv(u8 *arg0);
u8 TObjEneMe1Gee__sub_800CB5A0(u8 *arg0, s32 arg1);
void * __dt__13TUnk_8049387CFv(void *arg0, s16 arg1);
void * __nw__7TObjectFUl(u32);
void * init__13TObjEneMe1GeeFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void vfunc_110__13TUnk_8049387CFl(u8 *arg0, s32 arg1);
void sub_800C84C8__13TUnk_8049387CFv(u8 *arg0);
void vfunc_117__13TUnk_8049387CFUl(Gee_800C8788 *arg0, u32 arg1);
void vfunc_107__13TUnk_8049387CFv(Gee_800C8950 *self);
void vfunc_105__13TUnk_8049387CFv(Obj_800C8B4C *self);
void vfunc_106__13TUnk_8049387CFv(void* a0);
void TObjEneMe1Gee__sub_800C8BCC(u8 *arg0);
void TObjEneMe1Gee__sub_800CB4DC(u8 *arg0);
void sub_800CB764__13TUnk_8049387CFl(u8 *arg0, s32 arg1);
void sub_800CBE6C__13TObjEneMe1GeeFv(u8 *arg0);
void sub_800CC0C4__13TObjEneMe1GeeFv(u8 *arg0);
void vfunc_114__13TObjEneMe1GeeFv(void* p);
void vfunc_115__13TObjEneMe1GeeFv(u8 *arg0);
void vfunc_62__13TObjEneMe1GeeFv(void* p);
void vfunc_63__13TObjEneMe1GeeFv(u8 *arg0);
void TObjEneMe1Gee__vt85(Ene_800CB3A4 *arg0, u32 arg1, s32 arg2);
void vfunc_88__13TObjEneMe1GeeFv(void *arg0);
void vfunc_101__13TObjEneMe1GeeFPUc(void *arg0);
void vfunc_112__13TUnk_8049387CFl(u8 *arg0, s32 arg1);
void render__13TObjEneMe1GeeFv(u8 *arg0);
void set_flag3c8_bit2__13TObjEneMe1GeeFv(void* p);
extern D_800CC950 * TObjEneMe1Gee__resource_bundle;
extern const Data_800C82A4 TObjEneMe1Gee__data_8043BDB0;
extern s32 lbl_805D2A68;
extern s32 gee_resource_bundle_ptr;
#pragma push
#define vfunc_117__13TUnk_8049387CFUl ((void (*)())vfunc_117__13TUnk_8049387CFUl)
#define vfunc_108__13TUnk_8049387CFv ((void (*)())vfunc_108__13TUnk_8049387CFv)
#define vfunc_107__13TUnk_8049387CFv ((void (*)())vfunc_107__13TUnk_8049387CFv)
#define vfunc_105__13TUnk_8049387CFv ((void (*)())vfunc_105__13TUnk_8049387CFv)
#define vfunc_106__13TUnk_8049387CFv ((void (*)())vfunc_106__13TUnk_8049387CFv)
#define vfunc_114__13TObjEneMe1GeeFv ((void (*)())vfunc_114__13TObjEneMe1GeeFv)
#define vfunc_115__13TObjEneMe1GeeFv ((void (*)())vfunc_115__13TObjEneMe1GeeFv)
#define vfunc_62__13TObjEneMe1GeeFv ((void (*)())vfunc_62__13TObjEneMe1GeeFv)
#define vfunc_63__13TObjEneMe1GeeFv ((void (*)())vfunc_63__13TObjEneMe1GeeFv)
#define TObjEneMe1Gee__vt85 ((void (*)())TObjEneMe1Gee__vt85)
#define vfunc_88__13TObjEneMe1GeeFv ((void (*)())vfunc_88__13TObjEneMe1GeeFv)
#define vfunc_89__13TObjEneMe1GeeFv ((void (*)())vfunc_89__13TObjEneMe1GeeFv)
#define vfunc_101__13TObjEneMe1GeeFPUc ((void (*)())vfunc_101__13TObjEneMe1GeeFPUc)
#define vfunc_110__13TUnk_8049387CFl ((void (*)())vfunc_110__13TUnk_8049387CFl)
#define vfunc_109__13TUnk_8049387CFv ((void (*)())vfunc_109__13TUnk_8049387CFv)
#define vfunc_116__13TUnk_8049387CFv ((void (*)())vfunc_116__13TUnk_8049387CFv)
#define vfunc_112__13TUnk_8049387CFl ((void (*)())vfunc_112__13TUnk_8049387CFl)
extern "C" void vfunc_28__13TObjEneMe1GeeFv();
extern "C" void vfunc_61__13TObjEneMe1GeeFv();

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFPl();
extern "C" void vfunc_84__9TObjEneDDFv();
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
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_111__13TUnk_8049387CFl(u8 *, s32);
extern "C" void vfunc_113__13TUnk_8049387CFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 lbl_8043BD08[];
extern "C" u8 lbl_8043BD14[];
extern "C" u8 lbl_8043BD24[];
extern "C" u8 lbl_8043BD38[];
extern "C" u8 lbl_8043BD4C[];
extern "C" u8 lbl_8043BD60[];
extern "C" u8 lbl_8043BD74[];
extern "C" u8 lbl_8043BD88[];
extern "C" u8 lbl_8043BD98[];
extern "C" u8 lbl_8043BDE0[];
extern "C" u8 lbl_8043BDFC[];
extern "C" u8 lbl_8043BE08[];
extern "C" u8 lbl_8043BE28[];
extern "C" u8 lbl_8043BE38[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *bm_ene_me1_gee_model_names[3];
extern void *bm_ene_me1_gee_motion_names[5];
extern void *bm_ene_me1_gee_low_model_names[3];
extern void *bm_ene_me1_gee_low_motion_names[5];
void *me1_gee_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049379C[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm_ene_me1_gee_model_names[3] = {
    (void *)lbl_8043BD08, (void *)lbl_8043BD14, (void *)0x0,
};
void *bm_ene_me1_gee_motion_names[5] = {
    (void *)lbl_8043BD24, (void *)lbl_8043BD38, (void *)lbl_8043BD4C, (void *)lbl_8043BD60,
    (void *)0x0,
};
void *bm_ene_me1_gee_resource_descriptor[4] = {
    (void *)lbl_8043BD74, (void *)bm_ene_me1_gee_model_names, (void *)bm_ene_me1_gee_motion_names, (void *)0x20004,
};
void *bm_ene_me1_gee_low_model_names[3] = {
    (void *)lbl_8043BD88, (void *)lbl_8043BD14, (void *)0x0,
};
void *bm_ene_me1_gee_low_motion_names[5] = {
    (void *)lbl_8043BD24, (void *)lbl_8043BD38, (void *)lbl_8043BD4C, (void *)lbl_8043BD60,
    (void *)0x0,
};
void *bm_ene_me1_gee_low_resource_descriptor[4] = {
    (void *)lbl_8043BD98, (void *)bm_ene_me1_gee_low_model_names, (void *)bm_ene_me1_gee_low_motion_names, (void *)0x20004,
};
void *TObjEneMe1Gee__motion_parameters[16] = {
    (void *)0x10000, (void *)0x3, (void *)0x3f666666, (void *)0x0,
    (void *)0x20000, (void *)0x2, (void *)0x3f800000, (void *)0x0,
    (void *)0x20000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x20000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x0,
};
void *TObjEneMe1Gee__fade_command_streams[5] = {
    (void *)lbl_8043BDE0, (void *)lbl_8043BDFC, (void *)lbl_8043BE08, (void *)lbl_8043BE28,
    (void *)lbl_8043BE38,
};
void *me1_gee_dispatch_table[118] = {
    (void *)0x0, (void *)0x0, (void *)__dt__13TUnk_8049387CFv, (void *)TObjEneMe1Gee__sub_800C8BCC,
    (void *)render__13TObjEneMe1GeeFv, (void *)render_shadows__9TObjEnemyFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv, (void *)get_center__9TObjCharaFv, (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__14TObjCollidableFl, (void *)add_actor_exp__9TObjCharaFl, (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv, (void *)update_actor_ground_y__9TObjCharaFv, (void *)vfunc_18__9TObjCharaFPUc, (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf, (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)receive_physical_attack__9TObjCharaFPvf, (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv, (void *)apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)try_start_action__9TObjCharaFll, (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__13TObjEneMe1GeeFv, (void *)vfunc_29__9TObjCharaFv, (void *)is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv, (void *)vfunc_37__9TObjCharaFv, (void *)update_flag30_timer__9TObjCharaFv, (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv, (void *)update_attack_stat_status__9TObjCharaFv, (void *)update_defense_stat_status__9TObjCharaFv, (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv, (void *)apply_paralysis__9TObjCharaFv, (void *)apply_slow_status__9TObjCharaFv, (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl, (void *)apply_shock_status__9TObjCharaFv, (void *)clear_harmful_statuses__9TObjCharaFv, (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv, (void *)cure_poison_ailment__9TObjCharaFv, (void *)cure_paralysis__9TObjCharaFv, (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf, (void *)apply_anti_technique__9TObjCharaFl, (void *)vfunc_58__9TObjCharaFv, (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv, (void *)vfunc_61__13TObjEneMe1GeeFv, (void *)vfunc_62__13TObjEneMe1GeeFv, (void *)vfunc_63__13TObjEneMe1GeeFv,
    (void *)reset_pose__9TObjCharaFv, (void *)get_anim_node_position__9TObjCharaFlP3Vec, (void *)vfunc_66__9TObjCharaFv, (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl, (void *)apply_switch_attack__9TObjCharaFv, (void *)enemy_spawn_jellen_effect__9TObjCharaFv, (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv, (void *)recalc_stats__9TObjCharaFv, (void *)vfunc_74__9TObjEnemyFl, (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFv, (void *)vfunc_77__9TObjCharaFv, (void *)vfunc_78__9TObjCharaFl, (void *)vfunc_79__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv, (void *)vfunc_83__12TObjEneDD_STFv,
    (void *)vfunc_84__9TObjEneDDFv, (void *)vfunc_85__9TObjEneDDFv, (void *)vfunc_86__9TObjEneDDFv, (void *)TObjEneMe1Gee__vt85,
    (void *)vfunc_88__13TObjEneMe1GeeFv, (void *)vfunc_89__13TObjEneMe1GeeFv, (void *)vfunc_90__9TObjEneDDFv, (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv, (void *)vfunc_93__9TObjEneDDFv, (void *)vfunc_94__9TObjEneDDFv, (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv, (void *)vfunc_97__9TObjEneDDFv, (void *)vfunc_98__9TObjEneDDFv, (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv, (void *)vfunc_101__13TObjEneMe1GeeFPUc, (void *)vfunc_102__9TObjEneDDFv, (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)TObjEneMe1Gee__vt102, (void *)vfunc_105__13TUnk_8049387CFv, (void *)vfunc_106__13TUnk_8049387CFv, (void *)vfunc_107__13TUnk_8049387CFv,
    (void *)vfunc_108__13TUnk_8049387CFv, (void *)vfunc_109__13TUnk_8049387CFv, (void *)vfunc_110__13TUnk_8049387CFl, (void *)vfunc_111__13TUnk_8049387CFl,
    (void *)vfunc_112__13TUnk_8049387CFl, (void *)vfunc_113__13TUnk_8049387CFv, (void *)vfunc_114__13TObjEneMe1GeeFv, (void *)vfunc_115__13TObjEneMe1GeeFv,
    (void *)vfunc_116__13TUnk_8049387CFv, (void *)vfunc_117__13TUnk_8049387CFUl,
};
static s32 gee_boss_stat_handle_table[3];
static s32 gee_shared_handler_b_table[3];
static s32 gee_object_handle_table[3];
static s32 gee_shared_handler_a_table[3];
static f32 gee_camera_ctrl_vec[4];
#undef vfunc_117__13TUnk_8049387CFUl
#undef vfunc_108__13TUnk_8049387CFv
#undef vfunc_107__13TUnk_8049387CFv
#undef vfunc_105__13TUnk_8049387CFv
#undef vfunc_106__13TUnk_8049387CFv
#undef vfunc_114__13TObjEneMe1GeeFv
#undef vfunc_115__13TObjEneMe1GeeFv
#undef vfunc_62__13TObjEneMe1GeeFv
#undef vfunc_63__13TObjEneMe1GeeFv
#undef TObjEneMe1Gee__vt85
#undef vfunc_88__13TObjEneMe1GeeFv
#undef vfunc_89__13TObjEneMe1GeeFv
#undef vfunc_101__13TObjEneMe1GeeFPUc
#undef vfunc_110__13TUnk_8049387CFl
#undef vfunc_109__13TUnk_8049387CFv
#undef vfunc_116__13TUnk_8049387CFv
#undef vfunc_112__13TUnk_8049387CFl
#pragma pop
#pragma push

extern s32 TObjEneMe1Gee__data_805D51C0;

void TUnk_8049387C::vfunc_112(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        create_breakup_mdl__12TBoss3VoloptFlllll(TObjEneMe1Gee__data_805D51C0, 0, *(s32 *)((s8 *)arg0 + 0x24), arg0 + 0x2FC, *(s32 *)((s8 *)arg0 + 0x60));
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x400000);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        return;
    case 0:
        if (this->vfunc_109() != 0) {
            ((TObjEnemy *)arg0)->send_entity_set_flags();
            queue_destruction__7TObjectFv(arg0);
        }
    case 3:
    case 1:
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF);
        break;
    }
}

#pragma pop
#pragma push
#define set_flag3c8_bit2__13TObjEneMe1GeeFv ((s32 (*)(void *))set_flag3c8_bit2__13TObjEneMe1GeeFv)
#define sub_800CBE6C__13TObjEneMe1GeeFv ((s32 (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)
#define TObjEneMe1Gee__sub_800CB5A0 ((s32 (*)(void *, s32))TObjEneMe1Gee__sub_800CB5A0)
#define sub_800CB764__13TUnk_8049387CFl ((s32 (*)(void *, s32))sub_800CB764__13TUnk_8049387CFl)
struct Vec_800C82A4 { f32 x, y, z; };
struct Data_800C82A4 { f32 a; Vec_800C82A4 v; };
struct Gee_800C82A4 { u8 pad[0x494]; s32 count; void *arr[8]; };
s32 transition_enemy_state__9TObjEneDDFl(void *, s32);
extern const f32 TObjEneMe1Gee__data_805DA0A8;
extern const f32 lbl_805DA0AC;
struct Gee_800C84C8 { u8 pad[0x494]; s32 count; void *arr[8]; };

void TUnk_8049387C::vfunc_111(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        ((TObjEneDD *)arg0)->set_field_378(5);
        this->vfunc_96();
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x3C8) & 4) {
            this->vfunc_105();
        }
        break;
    case 0:
        ((void (*)())advance_animation_playback)();
        ((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        ((TObjEneMe1Gee *)arg0)->update();
        ((TObjEneMe1Gee *)arg0)->update_animation_frame();
        this->vfunc_89();
        break;
    case 5:
        break;
    }
}

void TUnk_8049387C::vfunc_110(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Gee_800C82A4 *self = (Gee_800C82A4 *) arg0;
    s32 k;
    s32 i;
    s32 j;
    s32 m;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(4);
        this->vfunc_96();
        *(f32 *)((s8 *)arg0 + 0x46C) = TObjEneMe1Gee__data_8043BDB0.v.x;
        *(f32 *)((s8 *)arg0 + 0x470) = TObjEneMe1Gee__data_8043BDB0.v.y;
        *(f32 *)((s8 *)arg0 + 0x474) = TObjEneMe1Gee__data_8043BDB0.v.z;
        *(s32 *)((s8 *)arg0 + 0x434) = 0;
        for (k = 2, i = 0; i < self->count; k += 2, i++) {
            ((TObjEneMe1Gee *)(self->arr[i]))->set_state_flag(*(s32 *)((s8 *)arg0 + 0x390), k);
        }
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x3C8) & 2) {
            *(s32 *)((s8 *)arg0 + 0x3C8) &= ~2;
            *(s32 *)((s8 *)arg0 + 0x4B8) = 1;
            transition_enemy_state__9TObjEneDDFl(arg0, 5);
        }
        break;
    case 0:
        ((void (*)())advance_animation_playback)();
        ((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        switch (*(s32 *)((s8 *)arg0 + 0x434)) {
        case 0:
            (*(s32 *)((s8 *)arg0 + 0x404))--;
            if (*(s32 *)((s8 *)arg0 + 0x404) <= 0) {
                *(s32 *)((s8 *)arg0 + 0x47C) = 2;
                *(s32 *)((s8 *)arg0 + 0x434) = 1;
            }
            break;
        case 1:
            if (*(s32 *)((s8 *)arg0 + 0x47C) == 0) {
                *(s32 *)((s8 *)arg0 + 0x3C8) |= 0x8000;
                for (j = 0; j < self->count; j++) {
                    if (TObjEneMe1Gee__sub_800CB628(self->arr[j]) == 0) {
                        break;
                    }
                }
                if (j == self->count) {
                    set_flag3c8_bit2__13TObjEneMe1GeeFv(arg0);
                    for (m = 0; m < self->count; m++) {
                        set_flag3c8_bit2__13TObjEneMe1GeeFv(self->arr[m]);
                    }
                }
            }
            ((TObjEneMe1Gee *)arg0)->update();
            break;
        }
        sub_800CBE6C__13TObjEneMe1GeeFv(arg0, lbl_805DA0AC + *(f32 *)((s8 *)arg0 + 0x3C));
        this->vfunc_89();
        break;
    case 5:
        this->vfunc_92();
        break;
    }
}

void TUnk_8049387C::sub_800C84C8() {
    u8 *arg0 = (u8 *)this;
    Gee_800C84C8 *self = (Gee_800C84C8 *) arg0;
    s32 j;
    s32 i;

    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x10) {
        *(s32 *)((s8 *)arg0 + 0x3C8) &= ~0x10;
        *(u32 *)((s8 *)arg0 + 0x4B8) = 7;
    }
    switch (*(u32 *)((s8 *)arg0 + 0x4B8)) {
    case 1:
        sub_800CB764__13TUnk_8049387CFl(arg0, 0);
        *(u32 *)((s8 *)arg0 + 0x4B8) = 2;
        break;
    case 2:
        if (*(s32 *)((s8 *)arg0 + 0x47C) == 0) {
            *(u32 *)((s8 *)arg0 + 0x4B8) = 3;
            *(s32 *)((s8 *)arg0 + 0x3C8) &= ~8;
            copy_argb((NJS_ARGB *)(arg0 + 0x468), (NJS_ARGB *)((void *)&TObjEneMe1Gee__data_8043BDB0));
            for (i = 0; i < self->count; i++) {
                if (TObjEneMe1Gee__sub_800CB5A0(self->arr[i], 0x200) != 0) {
                    ((TObjEneMe1Gee *)(self->arr[i]))->set_flag3c8_bit4();
                }
            }
        }
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x3C8) & 8) {
            *(u32 *)((s8 *)arg0 + 0x4B8) = 4;
        }
        break;
    case 4:
        sub_800CB764__13TUnk_8049387CFl(arg0, 2);
        *(u32 *)((s8 *)arg0 + 0x4B8) = 5;
        break;
    case 5:
        if (*(s32 *)((s8 *)arg0 + 0x47C) == 0) {
            copy_argb((NJS_ARGB *)(arg0 + 0x468), (NJS_ARGB *)((void *)&TObjEneMe1Gee__data_8043BDB0));
            *(u32 *)((s8 *)arg0 + 0x4B8) = 6;
            for (i = 0; i < self->count; i++) {
                if (TObjEneMe1Gee__sub_800CB5A0(self->arr[i], 0x100) != 0) {
                    ((TObjEneMe1Gee *)(self->arr[i]))->set_flag3c8_bit4();
                }
            }
        }
        break;
    case 7:
        sub_800CB764__13TUnk_8049387CFl(arg0, 4);
        *(u32 *)((s8 *)arg0 + 0x4B8) = 8;
        break;
    case 8:
        if (*(s32 *)((s8 *)arg0 + 0x47C) == 0) {
            *(u32 *)((s8 *)arg0 + 0x4B8) = 9;
            copy_argb((NJS_ARGB *)(arg0 + 0x468), (NJS_ARGB *)((void *)&TObjEneMe1Gee__data_8043BDB0));
            for (j = 0; j < self->count; j++) {
                TObjEneMe1Gee__sub_800CB4DC((u8 *)self->arr[j]);
            }
            TObjEneMe1Gee__sub_800CB4DC(arg0);
        }
        break;
    case 9:
        break;
    }
}

#undef set_flag3c8_bit2__13TObjEneMe1GeeFv
#undef sub_800CBE6C__13TObjEneMe1GeeFv
#undef TObjEneMe1Gee__sub_800CB5A0
#undef sub_800CB764__13TUnk_8049387CFl
#pragma pop
#pragma push
void vfunc_113__13TUnk_8049387CFv(void);

int TUnk_8049387C::vfunc_109() {
    u8 *arg0 = (u8 *)this;
    return (u8) (*(s32 *)((s8 *)arg0 + 0x494) <= 0);
}

void TUnk_8049387C::vfunc_113() {  }

}

#pragma pop
#pragma push

struct Obj_800C86E0 { u8 pad0[0x390]; void *key; u8 pad1[0x100]; s32 count; u8 *items[8]; };

extern "C" {
s32 TObjEneMe1Gee__sub_800CB584(u8 *);

int TUnk_8049387C::vfunc_116() {
    Obj_800C86E0 *arg0 = (Obj_800C86E0 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if ((void *)TObjEneMe1Gee__sub_800CB584(arg0->items[i]) == arg0->key) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode() != 0) {
        return n < 4;
    }
    return n < 2;
}

}

#pragma pop
#pragma push
#define advance_animation_playback ((s32 (*)())advance_animation_playback)
#define TObjEneMe1Gee__data_8043BDB0 ((const u8 *)&TObjEneMe1Gee__data_8043BDB0)
#define copy_argb ((int (*)(void *, void *))copy_argb)
#define sub_800C84C8__13TUnk_8049387CFv ((s32 (*)(void *))sub_800C84C8__13TUnk_8049387CFv)
#define create_breakup_mdl__12TBoss3VoloptFlllll ((void (*)(s32, s32, s32, s32, s32))create_breakup_mdl__12TBoss3VoloptFlllll)
#define TObjEneMe1Gee__fade_command_streams ((char * *)&TObjEneMe1Gee__fade_command_streams)
#define me1_gee_dispatch_table ((s32 *)&me1_gee_dispatch_table)

#include <stddef.h>

struct Vec_800C96B4 { f32 x, y, z; };

struct Data_800C96B4 { u8 pad[0x28]; s32 f28; };

struct VBase_800C96B4 { char pad[0x18]; };

struct Gee_800C96B4 : VBase_800C96B4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94();
    u8 pad1C[0x30 - 0x1C];
    u32 f30;
    u8 pad34[0x3C - 0x34];
    f32 f3C;
    u8 pad40[0xB8 - 0x40];
    s16 fB8;
    u8 padBA[0x308 - 0xBA];
    Vec_800C96B4 vel;
    u8 pad314[0x378 - 0x314];
    s32 f378;
    u8 pad37C[0x3C8 - 0x37C];
    u32 f3C8;
    u8 pad3CC[0x3EC - 0x3CC];
    f32 f3EC;
    u8 pad3F0[0x3F8 - 0x3F0];
    f32 f3F8;
    u8 pad3FC[0x42C - 0x3FC];
    Data_800C96B4 *data;
    u8 pad430[4];
    s32 f434;
    s32 f438;
    u8 pad43C[0x448 - 0x43C];
    f32 f448;
    f32 f44C;
};

struct Par_800C8950 { u8 pad[0x2c]; s32 x2c; };

struct Vec_800C8950 { f32 x, y, z; };

struct Gee_800C8950 {
    u8 pad0[0x1c]; u16 x1c; u8 pad1e[0x2c - 0x1e]; s16 x2c;
    u8 pad2e[0x38 - 0x2e]; Vec_800C8950 pos;
    u8 pad44[0x60 - 0x44]; s32 angle;
    u8 pad64[0x42c - 0x64]; Par_800C8950 *par;
    u8 pad430[0x490 - 0x430];
    s32 maxCount; s32 count; void *children[8];
};

struct Vec_800C96B4;
struct Vec_800C9A94 { f32 x, y, z; };

struct Gee_800C9A94 {
    u8 pad0[0x38];
    Vec_800C9A94 pos38;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    u8 snd[0x394 - 0x2FC];
    Vec_800C9A94 base;
    Vec_800C9A94 vel;
    f32 f3AC;
    u8 pad3B0[0x3C8 - 0x3B0];
    u32 flags;
    u8 pad3CC[0x3E8 - 0x3CC];
    f32 f3E8;
    u8 pad3EC[0x3F4 - 0x3EC];
    f32 f3F4;
    f32 f3F8;
    u8 pad3FC[0x408 - 0x3FC];
    s32 f408;
    u8 pad40C[0x434 - 0x40C];
    s32 mode;
    s32 timer;
    s32 count;
    u8 pad440[4];
    s32 rot;
    f32 f448;
    f32 dist;
    f32 ddist;
    Vec_800C9A94 dir;
};

struct VBase_800CA454 { char pad[0x18]; };

struct VObj_800CA454 : VBase_800CA454 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101(); virtual void m102(); virtual void m103();
    virtual void m104(); virtual void m105(); virtual s32 m106();
};

struct Vec_800CA454 { f32 x, y, z; };

struct Param_800CA454 { u8 pad0[4]; f32 f4; u8 pad8[0x18 - 8]; s32 f18; u8 pad1C[4]; s32 f20; s32 f24; };

struct Gee_800CA454 {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[4];
    Vec_800CA454 pos38;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    u8 snd[0x394 - 0x2FC];
    Vec_800CA454 tgt;
    u8 pad3A0[0x3C8 - 0x3A0];
    u32 flags;
    u8 pad3CC[0x3E8 - 0x3CC];
    f32 f3E8;
    u8 pad3EC[0x3FC - 0x3EC];
    f32 f3FC;
    u8 pad400[0x408 - 0x400];
    s32 f408;
    u8 pad40C[0x42C - 0x40C];
    Param_800CA454 *param;
    u8 pad430[4];
    s32 mode;
    s32 timer;
    u8 pad43C[0x454 - 0x43C];
    Vec_800CA454 dir;
    void *sub460;
    void *sub464;
};

struct VBase_14_559b06 { char pad[0x14]; };

struct VObj_14_559b06 : VBase_14_559b06 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2(void *);
};

struct VBase_18_3bc1aa { char pad[0x18]; };

struct VObj_18_3bc1aa : VBase_18_3bc1aa {
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

struct Vec_800CC430 { f32 x, y, z; };

struct Gee_800CC430 { u8 pad0[0x38]; Vec_800CC430 pos; u8 pad44[0x414 - 0x44]; Vec_800CC430 v[2]; u8 pad42c[0x468 - 0x42C]; f32 f468; };

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
extern const f32 TObjEneMe1Gee__data_805DA0B4;
extern const f32 TObjEneMe1Gee__data_805DA0C8;
extern const f32 TObjEneMe1Gee__data_805DA0D4;
extern const f32 TObjEneMe1Gee__data_805DA0E8;
void TObjEneMe1Gee__sub_800C96B4(Gee_800C96B4 *o, s32 mode);
f32 get_status_value_f32__23TObjEneMe1CanadinLeaderFv(f32);
void *create__13TObjEneMe1GeeFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
f32 sin_table_lookup(s32, f32);
f32 cos_table_lookup(s32);
s32 vec3_add_to(void *, s32);
extern const f32 lbl_805DA0B0;
f64 atan2_float(f32, f32);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void TObjEneMe1Gee__sub_800CBC04(u8 *arg0);
void TObjEneMe1Gee__sub_800CBC1C(u8 *arg0);
s32 play_sound_effect(s32, u32, s16, s32);
f32 subtract_vector(void *, void *);
extern const f64 lbl_8043BF28;
extern const f32 lbl_805DA0F0;
extern const f32 lbl_805DA0F4;
extern const f32 lbl_805DA0F8;
extern const f32 lbl_805DA0FC;
void TObjEneMe1Gee__sub_800C9A94(void *arg0, s32 arg1);
void TObjEneEpsilon__sub_800B92F8(u8 *arg0, s32 arg1, f32 farg0);
void destroy_subobj__13TObjEneMe1GeeFPv(void* p, void * _w1);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u8 *TObjEneMe1Gee_NEEDLE__ct(TObjEneMe1Gee_NEEDLE *arg0, s32 arg1, u8 *from, u8 *to, f32 farg0, f32 farg1);
void matrix_mult_vec(void *, Vec_800CA454 *, Vec_800CA454 *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *src);
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern const u8 TObjEneMe1Gee__data_8043BDC0[];
extern Vec_800CA454 lbl_8043BE7C[];
extern u8 identity_matrix[];
extern u8 *anim_model_matrix_array;
extern const f32 lbl_805DA124;
void TObjEneMe1Gee__sub_800CA454(void *arg0, s32 arg1);
s16 get_entity_id(void *);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 set_part_position__9TObjEneDDFPvPvi(void *, int, int);
s32 init_model__9TObjEneDDFv(void *, void *, int);
s32 rand(f32);
extern const f32 lbl_805DA0B8;
extern const f32 TObjEneMe1Gee__data_805DA0C0;
extern const f32 lbl_805DA148;
extern const f32 lbl_805DA14C;
extern "C" u8 lbl_8043BD08[];
extern "C" u8 lbl_8043BD14[];
extern "C" u8 lbl_8043BD24[];
extern "C" u8 lbl_8043BD38[];
extern "C" u8 lbl_8043BD4C[];
extern "C" u8 lbl_8043BD60[];
extern "C" u8 lbl_8043BD74[];
extern "C" u8 lbl_8043BD88[];
extern "C" u8 lbl_8043BD98[];
}

struct VBase_18_800C8EB4 { char pad[0x18]; };
struct VObj_18_800C8EB4 : VBase_18_800C8EB4 {
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
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual s32 m111();
    virtual void m112();
    virtual s32 m113();
};

struct SubBase_800C8EB4 { char pad[0x14]; };
struct Sub_800C8EB4 : SubBase_800C8EB4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" {

struct Obj_800C88D4 { u8 pad[0x3c8]; u32 f3c8; u8 pad2[0x494 - 0x3cc]; s32 count; void *children[1]; };

struct Obj_800C8B4C { u8 pad[0x430]; s32 f430; };

struct VBase_18 { char pad[0x18]; };

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_800C913C_lbl_80500E68 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_800C913C_lbl_80500E68_size[sizeof(RecoveredGlobal_800C913C_lbl_80500E68) == 0x10 ? 1 : -1];

struct VBase_18_0f49f2 { char pad[0x18]; };

struct VObj_18_0f49f2 : VBase_18_0f49f2 {
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
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual s32 m115(void *);
};

struct Stack_800C9318 {
    s32 sp8;
    f32 spC;
};

struct VBase_18_455f6b { char pad[0x18]; };

struct VObj_18_455f6b : VBase_18_455f6b {
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
    virtual s32 m93();
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
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual s32 m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual s32 m115(void *);
};

struct VBase_14_87d649 { char pad[0x14]; };

struct VObj_14_87d649 : VBase_14_87d649 {
    virtual void m0();
    virtual s32 m1(s32);
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredFields_800C9580_arg0 {
    u8 unknown_0[0x30];
    s32 field_30;
    u8 unknown_34[0x84];
    s16 field_B8;
    u8 unknown_BA[0x306];
    u8 * field_3C0;
    s32 field_3C4;
    s32 field_3C8;
    u8 unknown_3CC[0xC0];
    u16 field_48C;
};

typedef char RecoveredFields_800C9580_arg0_30_offset[offsetof(RecoveredFields_800C9580_arg0, field_30) == 0x30 ? 1 : -1];

typedef char RecoveredFields_800C9580_arg0_B8_offset[offsetof(RecoveredFields_800C9580_arg0, field_B8) == 0xB8 ? 1 : -1];

typedef char RecoveredFields_800C9580_arg0_3C0_offset[offsetof(RecoveredFields_800C9580_arg0, field_3C0) == 0x3C0 ? 1 : -1];

typedef char RecoveredFields_800C9580_arg0_3C4_offset[offsetof(RecoveredFields_800C9580_arg0, field_3C4) == 0x3C4 ? 1 : -1];

typedef char RecoveredFields_800C9580_arg0_3C8_offset[offsetof(RecoveredFields_800C9580_arg0, field_3C8) == 0x3C8 ? 1 : -1];

typedef char RecoveredFields_800C9580_arg0_48C_offset[offsetof(RecoveredFields_800C9580_arg0, field_48C) == 0x48C ? 1 : -1];

struct Stack_800CAFD8 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct VBase_14_948132 { char pad[0x14]; };

struct VObj_14_948132 : VBase_14_948132 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct RecoveredFields_800CAFD8_arg0 {
    u8 unknown_0[0x30];
    s32 field_30;
    u8 unknown_34[0x84];
    s16 field_B8;
    u8 unknown_BA[0x30E];
    s32 field_3C8;
    u8 unknown_3CC[0x2C];
    f32 field_3F8;
    u8 unknown_3FC[0x38];
    s32 field_434;
    u8 unknown_438[0x44];
    s32 field_47C;
};

typedef char RecoveredFields_800CAFD8_arg0_30_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_30) == 0x30 ? 1 : -1];

typedef char RecoveredFields_800CAFD8_arg0_B8_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_B8) == 0xB8 ? 1 : -1];

typedef char RecoveredFields_800CAFD8_arg0_3C8_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_3C8) == 0x3C8 ? 1 : -1];

typedef char RecoveredFields_800CAFD8_arg0_3F8_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_3F8) == 0x3F8 ? 1 : -1];

typedef char RecoveredFields_800CAFD8_arg0_434_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_434) == 0x434 ? 1 : -1];

typedef char RecoveredFields_800CAFD8_arg0_47C_offset[offsetof(RecoveredFields_800CAFD8_arg0, field_47C) == 0x47C ? 1 : -1];

struct Base_Sub { char pad[0x14]; };

struct V_Sub : Base_Sub {
    virtual void pa84(); virtual void pb84(); virtual void pc84(); virtual void pd84();
    virtual void pv85();
    virtual s32 m5();
};

struct Base_800CB3A4 {
    u8 pad[0x18];
};

struct Ene_800CB3A4 : Base_800CB3A4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108(s32);
    virtual void v109(s32);
    virtual void v110(s32);
};

struct RecoveredGlobal_800CB764_lbl_8043BDD0 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_800CB764_lbl_8043BDD0_size[sizeof(RecoveredGlobal_800CB764_lbl_8043BDD0) == 0x10 ? 1 : -1];

struct Base_800CBA98 { char pad[0x18]; };

struct VObj_800CBA98 : Base_800CBA98 {
    virtual void pad_8(); virtual void pad_c(); virtual void pad_10(); virtual void pad_14();
    virtual void pad_18(); virtual void pad_1c(); virtual void pad_20(); virtual void pad_24();
    virtual void pad_28(); virtual void pad_2c(); virtual void pad_30(); virtual void pad_34();
    virtual void pad_38(); virtual void pad_3c(); virtual void pad_40(); virtual void pad_44();
    virtual void pad_48(); virtual void pad_4c(); virtual void pad_50(); virtual void pad_54();
    virtual void pad_58(); virtual void pad_5c(); virtual void pad_60(); virtual void pad_64();
    virtual void pad_68(); virtual void pad_6c(); virtual void pad_70(); virtual void pad_74();
    virtual void pad_78(); virtual void pad_7c(); virtual void pad_80(); virtual void pad_84();
    virtual void pad_88(); virtual void pad_8c(); virtual void pad_90(); virtual void pad_94();
    virtual void pad_98(); virtual void pad_9c(); virtual void pad_a0(); virtual void pad_a4();
    virtual void pad_a8(); virtual void pad_ac(); virtual void pad_b0(); virtual void pad_b4();
    virtual void pad_b8(); virtual void pad_bc(); virtual void pad_c0(); virtual void pad_c4();
    virtual void pad_c8(); virtual void pad_cc(); virtual void pad_d0(); virtual void pad_d4();
    virtual void pad_d8(); virtual void pad_dc(); virtual void pad_e0(); virtual void pad_e4();
    virtual void pad_e8(); virtual void pad_ec(); virtual void pad_f0(); virtual void pad_f4();
    virtual void pad_f8(); virtual void pad_fc(); virtual void pad_100(); virtual void pad_104();
    virtual void pad_108(); virtual void pad_10c(); virtual void pad_110(); virtual void pad_114();
    virtual void pad_118(); virtual void pad_11c(); virtual void pad_120(); virtual void pad_124();
    virtual void pad_128(); virtual void pad_12c(); virtual void pad_130(); virtual void pad_134();
    virtual void pad_138(); virtual void pad_13c(); virtual void pad_140(); virtual void pad_144();
    virtual void pad_148(); virtual void pad_14c(); virtual void pad_150(); virtual void pad_154();
    virtual void pad_158(); virtual void pad_15c(); virtual void pad_160(); virtual void pad_164();
    virtual void pad_168(); virtual void pad_16c(); virtual void pad_170(); virtual void pad_174();
    virtual void pad_178(); virtual void pad_17c(); virtual void pad_180(); virtual void pad_184();
    virtual void pad_188(); virtual void pad_18c(); virtual void pad_190(); virtual void pad_194();
    virtual void pad_198(); virtual void pad_19c(); virtual void pad_1a0(); virtual void pad_1a4();
    virtual void pad_1a8(); virtual void pad_1ac(); virtual void pad_1b0(); virtual void pad_1b4();
    virtual void pad_1b8(); virtual void pad_1bc(); virtual void pad_1c0(); virtual void pad_1c4();
    virtual void pad_1c8(); virtual void pad_1cc();
    virtual s32 m114(s32);
};

struct Base_800CBB34 {
    u8 pad[0x18];
};

struct Obj_800CBB34 : Base_800CBB34 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113();
    virtual s32 v114(void *);
};

typedef struct Rec_800CBB34 {
    u16 id;
    f32 dist;
} Rec_800CBB34;

typedef struct Gee_800CBB34 {
    u8 pad0[0x390];
    void *target;
    u8 pad394[0x3C0 - 0x394];
    Obj_800CBB34 *owner;
    u8 pad3C4[0x48C - 0x3C4];
    u16 ownerIdx;
} Gee_800CBB34;

struct VObj_18_p40 : VBase_18 {
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
    virtual void m97();
    virtual void m98();
    virtual s32 m99(s32 *);
};

struct Stack_800CBDBC {
    s32 sp8;
    f32 spC;
};

struct Stack_800CBE6C {
    s32 sp8;
    f32 spC;
};

struct Obj_800CBEF0 { u8 pad[0x3c8]; u32 f3c8; u8 pad2[0x3f8 - 0x3cc]; f32 f3f8; f32 f3fc; f32 f400; };

struct VBase_800CC190 {
    char pad[0x18];
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
    virtual void m97();
    virtual void m98();
};

struct RecoveredGlobal_800CC6D8___vt__13TObjEneMe1Gee { s32 value; u8 remaining[0x1D4]; };

typedef char RecoveredGlobal_800CC6D8___vt__13TObjEneMe1Gee_size[sizeof(RecoveredGlobal_800CC6D8___vt__13TObjEneMe1Gee) == 0x1D8 ? 1 : -1];

struct Par_800C8788 { u8 pad[0x2c]; s32 x2c; };

struct Gee_800C8788 {
    u8 pad[0x3c0]; s32 x3c0; u8 pad3c4[4]; s32 flags;
    u8 pad3cc[0x42c - 0x3cc]; Par_800C8788 *par;
    u8 pad430[0x48c - 0x430]; u16 x48c; u8 pad48e[2];
    s32 maxCount; s32 count; u32 ids[8]; s32 x4b8;
};

f32 random_ratio__9TObjCharaFv(s32);
f32 newton_sqrtf(f32);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
int copy_position__14TObjEneEpsilonFPv(void *p, void *_w1);
int select_and_apply_target__12TObjEneDD_STFf(void*);
s32 set_target_player__12TObjEneDD_STFPv();
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 update_player_state__9TObjEneDDFv(void *, int, int);
s32 is_main_phase_15__9TObjEneDDFv();
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
int vfunc_89__9TObjEneDDFv(void*);
u32 vfunc_101__9TObjEneDDFPUc();
s32 collect_enemy_target_candidates(void *, Rec_800CBB34 *);
s32 get_target_info__9TObjEneDDFv();
s32 pack_debug_text_position(s32, s32);
void TObjEneMe1Gee__sub_800C9580(u8 *arg0, s32 arg1);
void run_task__13TObjEneMe1GeeFPvi(TObjEneMe1Gee *arg0, s32 arg1);
void TObjEneMe1Gee__sub_800C9DF8(void *, s32);
void TObjEneMe1Gee__sub_800CAFD8(u8 *arg0, s32 arg1);
void TObjEneMe1Gee__sub_800CB560(u8 *arg0);
s32 TObjEneMe1Gee__sub_800CB584(u8 *arg0);
void TObjEneMe1Gee__sub_800CB968(s32 arg0);
s32 TObjEneMe1Gee__sub_800CBA80(u8 *arg0);
s32 find_attack_target__13TObjEneMe1GeeFPvPv(Gee_800CBB34 *arg0, f32 *out);
void TObjEneMe1Gee__sub_800CBDBC(u8 *arg0);
void approach_target_value__13TObjEneMe1GeeFPvf(Obj_800CBEF0 *self, f32 target);
void sub_800CBF58__13TObjEneMe1GeeFf(u8 *arg0, f32 farg0);
void calc_position__13TObjEneMe1GeeFiPv(s32 arg0, void *arg1);
void vfunc_61__13TObjEneMe1GeeFv(void);
void vfunc_28__13TObjEneMe1GeeFv(void);
int TObjEneMe1Gee__sub_800CC2BC(void);
void run_task__13TObjEneMe1GeeFv(u8 *arg0);
void * __dt__13TObjEneMe1GeeFv(void *arg0, s16 arg1);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void TBoss3Volopt__sub_800D8D88(s32);
s32 approach_angle_limited(s32, s32, s32);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(void *);
s32 push_matrix();
void draw_chunk_object(void *child);

extern s32 TObjEneMe1Gee__render_node_index;
extern s32 TObjEneMe1Gee__data_805D51C4;
extern const f32 TObjEneMe1Gee__data_805DA0EC;
extern s32 __vt__13TObjEneMe1Gee[];
extern RecoveredGlobal_800CB764_lbl_8043BDD0 lbl_8043BDD0;
extern s32 lbl_8043BE98[];
extern s32 lbl_8043BEA8[];
extern s32 lbl_8043BEBC[];
extern s32 lbl_8043BEC8[];
extern s32 lbl_8043BED8[];
extern s32 lbl_8043BEEC[];
extern s32 lbl_8043BF0C[];
extern s32 gee_camera_ctrl_step_ptr;
extern const f32 lbl_805DA0BC;
extern const f32 lbl_805DA0C4;
extern const f32 lbl_805DA0CC;
extern const f32 lbl_805DA0D0;
extern const f32 lbl_805DA110;
extern const f32 lbl_805DA128;
extern const f32 lbl_805DA130;
extern const f32 lbl_805DA134;
extern const f32 lbl_805DA138;
extern const f32 lbl_805DA13C;
extern const f32 lbl_805DA140;
extern const f32 lbl_805DA144;

void TUnk_8049387C::vfunc_117(u32 arg1) {
    Gee_800C8788 *arg0 = (Gee_800C8788 *)this;
    s32 i;
    u32 tmp;

    for (i = 0; i < arg0->count; i++) {
        if (arg0->ids[i] == arg1) {
            arg0->count--;
            tmp = arg0->ids[arg0->count];
            arg0->ids[arg0->count] = arg1;
            arg0->ids[i] = tmp;
            break;
        }
    }
    if (arg0->x4b8 == 3) {
        s32 lim = (s32)get_status_value_f32__23TObjEneMe1CanadinLeaderFv((f32)arg0->maxCount / (f32)arg0->par->x2c);
        if (arg0->count <= arg0->maxCount - lim) {
            arg0->x3c0 = (s32)find_entity_by_id(arg0->x48c);
            ((TObjEneMe1Gee *)(arg0->x3c0))->set_flag3c8_bit8();
        }
    }
    if (!(arg0->flags & 0x100000) && arg0->count <= arg0->maxCount / 2) {
        arg0->flags |= 0x10;
    }
    if (arg0->count <= 2) {
        arg0->flags |= 0x40;
    }
}

s32 TUnk_8049387C::vfunc_108() {
    Obj_800C88D4 *self = (Obj_800C88D4 *)this;
    s32 i;
    if (self->f3c8 & 0x40) {
        self->f3c8 &= ~0x40;
        ((void (*)(void *, s16))transition_enemy_state__9TObjEneDDFl)(self, 12);
        for (i = 0; i < self->count; i++) {
            ((TObjEneMe1Gee *)(self->children[i]))->set_flag3c8_bit40();
        }
        return 1;
    }
    return 0;
}

void TUnk_8049387C::vfunc_107() {
    s32 n;
    s32 i;
    s32 j;
    u16 a;
    s32 b;
    s32 angle;
    Vec_800C8950 v;
    Gee_800C8950 *self = (Gee_800C8950 *)this;
    n = (s32)get_status_value_f32__23TObjEneMe1CanadinLeaderFv((f32)self->maxCount / (f32)self->par->x2c);
    if (n < 1) {
        n = 1;
    }
    a = self->x1c + 1;
    angle = self->angle;
    b = self->x2c + 1;
    for (i = 0; i < n; i++) {
        v.x = lbl_805DA0B0 * ((f32 (*)(s32))sin_table_lookup)(angle);
        v.y = TObjEneMe1Gee__data_805DA0B4;
        v.z = lbl_805DA0B0 * cos_table_lookup(angle);
        ((void (*)(void *, void *))vec3_add_to)(&v, &self->pos);
        angle += 0x10000 / self->maxCount;
        self->children[i] = ((void *(*)(void *, void *, u16, s32))create__13TObjEneMe1GeeFPvPvPvPv)(self, &v, a++, b++);
        ((TObjEneMe1Gee *)((u8 *)self->children[i]))->sub_800CB5B8();
        self->count++;
    }
    for (j = n; j < self->maxCount; j++) {
        v.x = lbl_805DA0B0 * ((f32 (*)(s32))sin_table_lookup)(angle);
        v.y = TObjEneMe1Gee__data_805DA0B4;
        v.z = lbl_805DA0B0 * cos_table_lookup(angle);
        ((void (*)(void *, void *))vec3_add_to)(&v, &self->pos);
        angle += 0x10000 / self->maxCount;
        self->children[j] = ((void *(*)(void *, void *, u16, s32))create__13TObjEneMe1GeeFPvPvPvPv)(self, &v, a++, b++);
        ((TObjEneMe1Gee *)((u8 *)self->children[j]))->sub_800CB5D4();
        self->count++;
    }
}

void TUnk_8049387C::vfunc_105() {
    Obj_800C8B4C *self = (Obj_800C8B4C *)this;
    switch (self->f430) {
    case 0:
    case 1:
        self->f430++;
        ((void (*)(void *, s16))transition_enemy_state__9TObjEneDDFl)(self, 7);
        break;
    case 2:
        self->f430 = 0;
        ((void (*)(void *, s16))transition_enemy_state__9TObjEneDDFl)(self, 8);
        break;
    }
}

void TUnk_8049387C::vfunc_106() { *(int*)((char*)this + 0x34) = *(int*)((char*)*(int*)((char*)(*(int *)&TObjEneMe1Gee__resource_bundle) + 0x42c) + 0x8); this->texlist = *(int*)((char*)*(int*)((char*)(*(int *)&TObjEneMe1Gee__resource_bundle) + 0x42c) + 0xc); }

void TObjEneMe1Gee__sub_800C8BCC(u8 *arg0) {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TUnk_8049387C *)(arg0))->vfunc_114();
        return;
    }
    if (((TUnk_8049387C *)(arg0))->vfunc_83() != 4) {
        ((TUnk_8049387C *)(arg0))->vfunc_85();
        ((TObjEneMe1Gee *)arg0)->update_fade_sequence();
        sub_800C84C8__13TUnk_8049387CFv(arg0);
    }
    ((TObjEneMe1Gee *)arg0)->copy_pos();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
    ((TUnk_8049387C *)(arg0))->vfunc_100();
}

void *__dt__13TUnk_8049387CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = me1_gee_dispatch_table;
        ((void (*)(void *, int))__dt__13TObjEneMe1GeeFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneMe1Gee::vfunc_115() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 temp_r3_2;
    if (get_target_info__9TObjEneDDFv() != 0) {
        if ((s32) this->m_3e0 == 0) {
            temp_r3 = *(s32 *)((s8 *)arg0 + 0x3C8);
            if (temp_r3 & 0x100) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), (char *)lbl_8043BE98);
            } else if (temp_r3 & 0x200) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), (char *)lbl_8043BEA8);
            } else {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 2)), (char *)lbl_8043BEBC);
            }
            temp_r3_2 = *(s32 *)((s8 *)arg0 + 0x3C8);
            if (temp_r3_2 & 0x02000000) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), (char *)lbl_8043BEC8);
            } else if (temp_r3_2 & 0x04000000) {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), (char *)lbl_8043BED8);
            } else {
                TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 3)), (char *)lbl_8043BEBC);
            }
        }
        TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 4)), (char *)lbl_8043BEEC);
        TObjEneMe1Gee::queue_debug_text((s32)(pack_debug_text_position(0, 5)), (char *)lbl_8043BF0C);
    }
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DA0BC, TObjEneMe1Gee__data_805DA0C0) != 0) {
        update_player_state__9TObjEneDDFv(arg0, 0, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneMe1Gee::vfunc_114() { if (((int (*)(void*))get_target_info__9TObjEneDDFv)(this) != 0) { ((int (*)(void*))sub_800CC0C4__13TObjEneMe1GeeFv)(this); } }

void render__13TObjEneMe1GeeFv(u8 *ene_me1_gee) {
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r30;
    s32 var_r29;

    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_115();
        return;
    }
    if (*(s32 *)((s8 *)ene_me1_gee + 0x3C8) & 0x400000) {
        var_r30 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r30 = ((VObj_18_800C8EB4 *)(ene_me1_gee))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneMe1Gee__data_805DA0C0);
    } else if (((VObj_18_800C8EB4 *)(ene_me1_gee))->m8(lbl_805DA0BC, TObjEneMe1Gee__data_805DA0C0) != 0) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (var_r30 != 0) {
        if (*(s32 *)((s8 *)ene_me1_gee + 0x3C8) & 0x01000000) {
            update_player_state__9TObjEneDDFv(ene_me1_gee, 0, 0);
        }
        ((TObjEneDD *)ene_me1_gee)->update_secondary_light();
        TObjFish::set_global_param((int) (((TObjEneMe1Gee *)ene_me1_gee)->texlist));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_113();
        push_matrix();
        post_translate_matrix(ene_me1_gee + 0x38);
        translate_matrix(0, TObjEneMe1Gee__data_805DA0B4, (f32) (*(f32 *)((s8 *)ene_me1_gee + 0x3F4)), TObjEneMe1Gee__data_805DA0B4);
        rotate_matrix_y(0, (int) (((TObjEneMe1Gee *)ene_me1_gee)->rotation_y));
        temp_r0 = ((TObjEneMe1Gee *)ene_me1_gee)->mode;
        var_r29 = 1;
        if ((temp_r0 == 1) || (temp_r0 == 0xC)) {
            ((Sub_800C8EB4 *)(ene_me1_gee + 0x3CC))->m6();
            if (defer_render__7TObjectFv(ene_me1_gee) != 0) {
                var_r29 = 0;
            }
        }
        if (var_r29 != 0) {
            if ((s16) ((TObjEneMe1Gee *)ene_me1_gee)->mode != 0xB) {
                TObjEneMe1Gee__render_node_index = 0;
                gee_camera_ctrl_step_ptr = (s32)(ene_me1_gee + 0x414);
                TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneMe1Gee::advance_camera_ctrl_step));
                if (var_r30 == 1) {
                    TObjPlayer::set_global_flag();
                    ((TObjMotion *)ene_me1_gee)->draw();
                    TObjPlayer::clear_global_state();
                } else {
                    TObjPlayer::set_global_flag();
                    ((TObjEnemy *)ene_me1_gee)->draw_motion_model();
                    TObjPlayer::clear_global_state();
                }
                TObjEneRe7Berura::set_global_state((s32)NULL);
            } else {
                rotate_matrix_z(0, (int) (((TObjEneMe1Gee *)ene_me1_gee)->rotation_z));
                TObjEneMe1Gee__render_node_index = -1;
                gee_camera_ctrl_step_ptr = (s32)(ene_me1_gee + 0x414);
                TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneMe1Gee::advance_camera_ctrl_step));
                ((TObjEneDD_ST *)ene_me1_gee)->draw_with_alt_model((int) (*(s32 *)((s8 *)ene_me1_gee + 0x410)));
                TObjEneRe7Berura::set_global_state((s32)NULL);
            }
        }
        temp_r0_2 = ((TObjEneMe1Gee *)ene_me1_gee)->mode;
        if ((temp_r0_2 == 1) || (temp_r0_2 == 0xC)) {
            ((Sub_800C8EB4 *)(ene_me1_gee + 0x3CC))->m7();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        ((TObjEneDD *)ene_me1_gee)->update_primary_light();
        return;
    }
    VecCopy__FP3VecPC3Vec(ene_me1_gee + 0x414, ene_me1_gee + 0x2FC);
    VecCopy__FP3VecPC3Vec(ene_me1_gee + 0x420, ene_me1_gee + 0x2FC);
}

void TObjEneMe1Gee::advance_camera_ctrl_step() {
    s32 pos;
    s32 temp_r4_2;
    switch ((s32) TObjEneMe1Gee__render_node_index) {
    case 4:
        pos = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &(*(RecoveredGlobal_800C913C_lbl_80500E68 *)&gee_camera_ctrl_vec).value, pos);
        break;
    case 7:
        temp_r4_2 = gee_camera_ctrl_step_ptr;
        gee_camera_ctrl_step_ptr = temp_r4_2 + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &(*(RecoveredGlobal_800C913C_lbl_80500E68 *)&gee_camera_ctrl_vec).value, temp_r4_2);
        break;
    }
    TObjEneMe1Gee__render_node_index += 1;
}

void TObjEneMe1Gee::state_orbit(s32 arg1) {
    f32 temp_f1;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0;
        temp_f1 = *(f32 *)((s8 *)this + 0x3C);
        *(f32 *)((s8 *)this + 0x3F8) = (f32) (temp_f1 + *(f32 *)((s8 *)this + 0x3EC));
        *(f32 *)((s8 *)this + 0x448) = sin_table_lookup(*(s32 *)((s8 *)this + 0x60), temp_f1);
        *(f32 *)((s8 *)this + 0x44C) = cos_table_lookup(*(s32 *)((s8 *)this + 0x60));
        return;
    case 0:
        advance_animation_playback();
        *(f32 *)((s8 *)this + 0x3F8) = (f32) (*(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3EC));
        *(f32 *)((s8 *)this + 0x300) = (f32) *(f32 *)((s8 *)this + 0x3F8);
        this->move_with_wall_slide_commit(*(f32 *)((s8 *)this + 0x448), *(f32 *)((s8 *)this + 0x44C), lbl_805DA0C4);
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::handle_event(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        *(s32 *)((s8 *)this + 0x434) = 0;
        return;
    case 0:
        advance_animation_playback();
        *(s32 *)((s8 *)this + 0x434) = (s32) (*(s32 *)((s8 *)this + 0x434) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x434) > 0x5A) {
            *(s32 *)((s8 *)this + 0x434) = 0;
            this->requested_action = (this->requested_action + 1);
            if ((s16) this->requested_action >= 4) {
                this->requested_action = 0;
            }
        }
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TObjEneMe1Gee::vfunc_112(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800C9318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800C9318, spC) == 0x4) ? 1 : -1];
    Stack_800C9318 stack;
    switch (arg1) {
    case 4:
        if ((s32) this->m_3e0 == 1) {
            *(u8 **)((s8 *)arg0 + 0x3C0) = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x48C));
            ((VObj_18_0f49f2 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x3C0))))->m115(arg0);
        }
        create_breakup_mdl__12TBoss3VoloptFlllll(TObjEneMe1Gee__data_805D51C4, 0, this->texlist, (s32)(arg0 + 0x2FC), this->rotation_y);
        play_sound_effect(TObjEneMe1Gee::handle_message((s32) arg0, 0x3A843), (u32)(arg0 + 0x38), 0, 0);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x400000);
        this->actorFlags = (s32) (this->actorFlags | 0x01000000);
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&stack.sp8, (u8 *)&this->m_2fc);
        stack.spC -= TObjEneMe1Gee__data_805DA0C8;
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        return;
    case 0:
        queue_destruction__7TObjectFv(arg0);
    case 3:
    case 5:
        return;
    }
}

void TObjEneMe1Gee::state_return_home(s32 arg1) {

    switch (arg1) {
    case 4:
        set_field_378(0xF);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        *(s32 *)((s8 *)this + 0x434) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x434) == 2) {
            this->vfunc_105();
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        if (this->update_linked_position(TObjEneMe1Gee__data_805DA0A8) != 0) {
            *(s32 *)((s8 *)this + 0x434) = 2;
        }
        switch (*(s32 *)((s8 *)this + 0x434)) {
        case 0:
            *(s32 *)((s8 *)this + 0x438) = (s32) (*(s32 *)((s8 *)this + 0x438) + 1);
            if ((s32) *(s32 *)((s8 *)this + 0x438) >= 0x3C) {
                *(s32 *)((s8 *)this + 0x434) = 1;
            }
            ((s32 (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)(this, *(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3F4));
            break;
        case 1:
            copy_position__14TObjEneEpsilonFPv(this, (u8 *)this + 0x50);
            this->update_velocity();
            update_angle();
            set_move_speed_x();
            if (*(f32 *)((s8 *)this + 0x3AC) > lbl_805DA0CC) {
                this->move_with_wall_slide_commit(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8), lbl_805DA0D0);
            }
            break;
        }
        this->vfunc_89();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee__sub_800C9580(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        ((RecoveredFields_800C9580_arg0 *)ene_dd)->field_B8 = 0;
        ((TObjEneDD *)ene_dd)->set_field_378(0xC);
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        ((RecoveredFields_800C9580_arg0 *)ene_dd)->field_3C8 = (s32) (((RecoveredFields_800C9580_arg0 *)ene_dd)->field_3C8 & 0xFFBFFFFF);
        ((RecoveredFields_800C9580_arg0 *)ene_dd)->field_30 = (s32) (((RecoveredFields_800C9580_arg0 *)ene_dd)->field_30 | 0x800);
        if ((s32) ((RecoveredFields_800C9580_arg0 *)ene_dd)->field_3C4 == 1) {
            ((RecoveredFields_800C9580_arg0 *)ene_dd)->field_3C0 = (u8 *)find_entity_by_id(((RecoveredFields_800C9580_arg0 *)ene_dd)->field_48C);
            ((VObj_18_455f6b *)((u8 *)(((RecoveredFields_800C9580_arg0 *)ene_dd)->field_3C0)))->m115(ene_dd);
        } else {
            ((TObjEnemy *)ene_dd)->send_entity_set_flags();
        }
        ((VObj_14_87d649 *)(ene_dd + (972)))->m1(0x19);
        ((VObj_14_87d649 *)(ene_dd + (972)))->m2();
        return;
    case 3:
        if ((((VObj_14_87d649 *)(ene_dd + (972)))->m4() != 0) && (((VObj_18_455f6b *)(ene_dd))->m107() != 0)) {
            queue_destruction__7TObjectFv(ene_dd);
        }
    case 5:
    case 0:
        return;
    }
}
#pragma pop

void TObjEneMe1Gee__sub_800C96B4(Gee_800C96B4 *o, s32 mode) {
    Vec_800C96B4 v;
    f32 len;
    switch (mode) {
    case 4:
        o->fB8 = 3;
        ((void (*)(void *))advance_animation_playback)(o);
        ((TObjEneMe1Gee *)o)->update_photon_target();
        o->f3C8 &= ~0x400000;
        o->m94();
        o->f30 &= ~0x1000000;
        o->f434 = 0;
        if (o->f3F8 > TObjEneMe1Gee__data_805DA0C8 + (o->f3C + o->f3EC)) {
            o->f438 = 0;
        } else {
            o->f438 = 2;
        }
        o->f448 = TObjEneMe1Gee__data_805DA0B4;
        o->f44C = TObjEneMe1Gee__data_805DA0B4;
        break;
    case 3:
        if (o->f438 == 3) {
            transition_enemy_state__9TObjEneDDFl(o, o->f378);
        }
        break;
    case 0:
        ((void (*)(void *))advance_animation_playback)(o);
        VecCopy__FP3VecPC3Vec(&v, &o->vel);
        len = normalize_vector_xz((Vec *)(&v));
        ((TObjEneDD *)o)->move_with_wall_slide_on_ground(v.x, v.z, len);
        len *= TObjEneMe1Gee__data_805DA0D4;
        o->vel.x = v.x * len;
        o->vel.z = v.z * len;
        switch (o->f438) {
        case 0:
            o->f448 = o->f448 - 0.13f;
            if (o->f448 < -4.0f) {
                o->f448 = -4.0f;
            }
            o->f3F8 += o->f448;
            if (o->f3F8 < 12.0f + (o->f3C + o->f3EC)) {
                o->f438 = 1;
                if (o->f448 > -2.0f) {
                    o->f448 = -2.0f;
                }
                o->f44C = (o->f448 * o->f448) / TObjEneMe1Gee__data_805DA0E8;
            }
            break;
        case 1:
            o->f448 += o->f44C;
            o->f3F8 += o->f448;
            if (o->f448 >= TObjEneMe1Gee__data_805DA0B4) {
                if (o->f3F8 > o->f3C + o->f3EC) {
                    o->f3F8 = o->f3C + o->f3EC;
                    o->f434 = 0;
                    o->f438 = 2;
                }
            }
            break;
        case 2:
            o->f434++;
            if (o->f434 >= o->data->f28) {
                o->f438 = 3;
            }
            break;
        }
        o->m87();
        break;
    case 5:
        ((TObjEneDD *)o)->clear_attack_receipts();
        o->fB8 = 0;
        break;
    }
}

void run_task__13TObjEneMe1GeeFPvi(TObjEneMe1Gee *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        arg0->requested_action = 0;
        ((TObjEneDD *)arg0)->set_field_378(0xA);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        arg0->vfunc_95();
        if ((s32) arg0->m_3e0 == 1) {
            *(s32 *)((s8 *)arg0 + 0x3C0) = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x48C)));
            ((TObjEneMe1Gee *)(*(s32 *)((s8 *)arg0 + 0x3C0)))->set_flag3c8_bit8();
        }
        *(s32 *)((s8 *)arg0 + 0x408) = 0;
        return;
    case 3:
        if ((arg0->vfunc_108() == 0) && (*(f32 *)((s8 *)arg0 + 0x3AC) < TObjEneMe1Gee__data_805DA0EC)) {
            ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(arg0, 6);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        copy_position__14TObjEneEpsilonFPv((arg0), ((u8 *)arg0 + 0x50));
        ((TObjEneDD *)arg0)->update_velocity();
        arg0->update_angle();
        arg0->set_move_speed_x();
        ((TObjEneDD *)arg0)->move_with_wall_slide_commit(arg0->m_3a0, (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), lbl_805DA0D0);
        arg0->vfunc_88();
        break;
    }
}

#pragma push
#pragma fp_contract on
#define o ((Gee_800C9A94 *)arg0)
void TObjEneMe1Gee__sub_800C9A94(void *arg0, s32 arg1) {
    Vec_800C9A94 *dir = &o->dir;
    switch (arg1) {
    case 4:
        o->fB8 = 0;
        ((TObjEneDD *)o)->set_field_378(9);
        o->flags &= 0xFFBFFFFF;
        ((TObjEneMe1Gee *)o)->vfunc_96();
        o->f408 = 0;
        o->mode = 1;
        TObjEneMe1Gee__sub_800CBC1C((u8 *)o);
        o->timer = 0;
        o->count = 0;
        o->rot = 0;
        o->f448 = TObjEneMe1Gee__data_805DA0B4;
        o->dist = TObjEneMe1Gee__data_805DA0B4;
        o->ddist = TObjEneMe1Gee__data_805DA0B4;
        dir->x = TObjEneMe1Gee__data_805DA0B4;
        dir->y = TObjEneMe1Gee__data_805DA0B4;
        dir->z = TObjEneMe1Gee__data_805DA0B4;
        break;
    case 3:
        if (((TObjEneMe1Gee *)o)->vfunc_108() == 0 && ((TObjEneMe1Gee *)o)->check_death_trigger() == 0 && o->count >= 4) {
            ((TObjEneMe1Gee *)o)->vfunc_105();
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Gee__data_805DA0A8) != 0) {
            switch (o->mode) {
            case 1: {
                if (o->timer == 0) {
                    f32 t;
                    ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                    ((TObjEneDD *)o)->update_velocity();
                    t = lbl_805DA0F0 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    if (t >= TObjEneMe1Gee__data_805DA0B4) {
                        t += lbl_805DA0F4;
                    } else {
                        t -= lbl_805DA0F4;
                    }
                    t *= lbl_805DA0F8;
                    o->rot = t;
                    dir->x = -o->vel.x;
                    dir->z = -o->vel.z;
                    o->f448 = lbl_805DA0F8 * (o->f3E8 - o->f3F4);
                    o->ddist = lbl_805DA0F8 * (lbl_805DA0FC - o->f3AC);
                    o->dist = o->f3AC;
                    play_sound_effect(TObjEneMe1Gee::handle_message((s32)o, 0x3AD13), (u32)o->snd, 0, 0);
                }
                o->timer++;
                if (o->timer >= 8) {
                    o->count++;
                    o->mode = 0;
                    TObjEneMe1Gee__sub_800CBC04((u8 *)o);
                }
                o->f3F8 += o->f448;
                rotate_xz_pair_by_angle(&dir->x, &dir->z, o->rot);
                {
                    Vec_800C9A94 v;
                    f32 c;
                    o->dist += o->ddist;
                    v.x = dir->x * o->dist + o->base.x;
                    v.z = dir->z * o->dist + o->base.z;
                    subtract_vector(&v, &o->pos38);
                    c = normalize_vector_xz((Vec *)((Vec_800C96B4 *)&v));
                    ((TObjEneDD *)o)->move_to_wall_clamped_destination(v.x, v.z, c);
                }
                o->angle = (s32)(lbl_8043BF28 * atan2_float(dir->x, dir->z)) + 0x8000;
                break;
            }
            case 0:
                ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                ((TObjEneDD *)o)->update_velocity();
                ((TObjEneMe1Gee *)o)->update_angle();
                ((TObjEneMe1Gee *)o)->update_animation_frame();
                o->timer++;
                if (o->timer > 30) {
                    o->timer = 0;
                    o->mode = 1;
                }
                break;
            }
            ((TObjEneMe1Gee *)o)->vfunc_89();
        }
        break;
    case 5:
        TObjEneMe1Gee__sub_800CBC04((u8 *)o);
        break;
    }
}
#undef o
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
struct VBase_800C9DF8 { char pad[0x18]; };
struct VObj_800C9DF8 : VBase_800C9DF8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual void m20(void *, f32);
    virtual void m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101(); virtual void m102(); virtual void m103();
    virtual void m104(); virtual void m105(); virtual s32 m106(); virtual void m107();
    virtual void m108(); virtual void m109(); virtual void m110(); virtual void m111();
    virtual void m112(); virtual void m113(); virtual s32 m114(void *);
};

struct Pair_800C9DF8 { s32 a, b; };

struct Gee_800C9DF8 : VObj_800C9DF8 {
    u8 pad1C[0x30 - 0x1C];
    u32 f30;
    u8 pad34[0x3C - 0x34];
    f32 f3C;
    u8 pad40[0xB8 - 0x40];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    u8 snd[0x390 - 0x2FC];
    VObj_800C9DF8 *f390;
    u8 pad394[0x3A0 - 0x394];
    f32 f3A0;
    f32 f3A4;
    f32 f3A8;
    f32 f3AC;
    u8 pad3B0[0x3C0 - 0x3B0];
    VObj_800C9DF8 *f3C0;
    u8 pad3C4[4];
    u32 flags;
    u8 pad3CC[0x3EC - 0x3CC];
    f32 f3EC;
    u8 pad3F0[4];
    f32 f3F4;
    f32 f3F8;
    u8 pad3FC[0x408 - 0x3FC];
    s32 f408;
    u8 pad40C[0x42C - 0x40C];
    f32 *f42C;
    u8 pad430[4];
    s32 mode;
    s32 timer;
    s32 toggle;
    u8 pad440[8];
    f32 f448;
    f32 f44C;
    u8 pad450[0x48C - 0x450];
    u16 f48C;
};

extern "C" {
void TObjEneEpsilon__sub_800B92AC(u8 *arg0, s32 arg1, f32 farg0);
extern Pair_800C9DF8 lbl_8043BE88[];
extern const f32 lbl_805DA100;
extern const f32 lbl_805DA104;
extern const f32 lbl_805DA108;
extern const f32 lbl_805DA10C;
extern const f32 lbl_805DA114;
extern const f32 lbl_805DA118;
extern const f32 lbl_805DA11C;
extern const f32 lbl_805DA120;
#pragma push
#pragma fp_contract on
#define o ((Gee_800C9DF8 *)o_)
void TObjEneMe1Gee__sub_800C9DF8(void *o_, s32 arg1) {
    f32 dist;

    switch (arg1) {
    case 4:
        o->fB8 = 0;
        ((TObjEneDD *)o)->set_field_378(8);
        o->flags &= ~0x400000;
        o->m94();
        o->f30 &= ~0x1000000;
        o->flags &= ~0x80000;
        o->mode = 0;
        o->timer = 0x28;
        o->toggle = 0;
        o->f448 = TObjEneMe1Gee__data_805DA0B4;
        o->f44C = TObjEneMe1Gee__data_805DA0B4;
        break;
    case 3:
        if (o->m106() == 0 && ((TObjEneMe1Gee *)o)->check_death_trigger() == 0 && o->mode == 5) {
            transition_enemy_state__9TObjEneDDFl(o, 9);
        }
        break;
    case 0:
        advance_animation_playback();
        if (o->mode == 0) {
            if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Gee__data_805DA0A8) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)o)->update_death_check() == 0) {
            break;
        }
        switch (o->mode) {
        case 0:
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Gee *)o)->update_angle();
            o->timer++;
            if (o->timer > 0x28) {
                o->timer = 0;
                o->mode = 1;
                if (o->flags & 0x40000) {
                    if (o->f3AC < lbl_805DA0B0) {
                        o->mode = 2;
                        ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDC0);
                    }
                } else if (o->f3AC < lbl_805DA100) {
                    o->f3C0 = (VObj_800C9DF8 *)find_entity_by_id(o->f48C);
                    if (o->f3C0->m114(o->f390) != 0) {
                        o->flags |= 0x40000;
                    } else if (((s32 (*)(void *, f32 *, f32))find_attack_target__13TObjEneMe1GeeFPvPv)(o, &dist, lbl_805DA104) != 0) {
                        if (dist < lbl_805DA100) {
                            o->flags |= 0x40000;
                        }
                    } else {
                        o->mode = 5;
                    }
                }
            }
            ((void (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)(o, o->f3C + o->f3F4);
            break;
        case 1:
            if (o->timer == 0) {
                f32 z;
                f32 x;
                f32 c;
                f32 s;
                f32 inv;
                f32 k;
                ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
                ((TObjEneDD *)o)->update_velocity();
                play_sound_effect(TObjEneMe1Gee::handle_message((s32)o, 0x3AD13), (u32)o->snd, 0, 0);
                k = lbl_805DA108;
                inv = TObjEneMe1Gee__data_805DA0EC / newton_sqrtf(k);
                k *= inv;
                c = TObjEneMe1Gee__data_805DA0E8 * inv;
                s = lbl_805DA10C * inv;
                if (o->toggle == 1) {
                    o->toggle = 0;
                    s *= lbl_805DA110;
                } else {
                    o->toggle = 1;
                }
                x = o->f3A0;
                z = o->f3A8 * c - x * s;
                o->f3A0 = x * c + o->f3A8 * s;
                o->f3A8 = z;
                o->f448 = lbl_805DA114 * k;
                o->f44C = lbl_805DA114 * (o->f3EC - o->f3F4);
            }
            TObjEneMe1Gee__sub_800CBC1C((u8 *)o);
            o->timer++;
            if (o->timer >= 4) {
                o->timer = 0;
                o->mode = 0;
                TObjEneMe1Gee__sub_800CBC04((u8 *)o);
            }
            o->f3F8 += o->f44C;
            ((TObjEneDD *)o)->move_to_wall_clamped_destination(o->f3A0, o->f3A8, o->f448);
            break;
        case 2:
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Gee *)o)->update_angle();
            sub_800CBF58__13TObjEneMe1GeeFf((u8 *)o, o->f3C + o->f3EC);
            if (o->f3AC < lbl_805DA118) {
                if (TObjEneMe1Gee__sub_800CBA80((u8 *)o) != 0) {
                    o->timer = 0;
                    o->mode = 3;
                }
            } else {
                if (o->f3AC > lbl_805DA0B0) {
                    o->mode = 1;
                }
                TObjEneEpsilon__sub_800B92AC((u8 *)o, 0x200, *o->f42C);
            }
            break;
        case 3:
            o->fB8 = 1;
            o->mode = 4;
            play_sound_effect(TObjEneMe1Gee::handle_message((s32)o, 0x3AD15), (u32)o->snd, 0, 0);
        case 4:
            ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Gee *)o)->update_angle();
            o->timer++;
            if (o->fB8 == 0) {
                if (o->f408 >= 3) {
                    o->mode = 5;
                } else {
                    o->timer = 0;
                    if (o->f3AC < lbl_805DA11C) {
                        o->mode = 3;
                    } else if (o->f3AC < lbl_805DA0B0) {
                        o->mode = 2;
                    } else {
                        o->mode = 1;
                        ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDB0);
                        if (o->f3AC > lbl_805DA100) {
                            o->flags &= ~0x40000;
                        }
                    }
                }
            } else if (objInBand((GameObj *)o, (f32)lbl_805DA0B8) != 0) {
                o->f408++;
                if (TObjEneMe1Gee__sub_800CBA80((u8 *)o) != 0) {
                    if (o->f390->m18(o, TObjEneMe1Gee__data_805DA0EC) != 0) {
                        o->f390->m20(o, TObjEneMe1Gee__data_805DA0EC);
                        o->f390->m23(o, lbl_805DA120);
                        if (random_ratio__9TObjCharaFv((s32)o) <= lbl_805DA114) {
                            Pair_800C9DF8 p = lbl_8043BE88[0];
                            o->f390->m21(o, &p, 0, -1, -1);
                        }
                    }
                }
            }
            ((TObjEneMe1Gee *)o)->update_hover_height();
            break;
        case 5:
            break;
        }
        o->m87();
        break;
    case 5:
        o->flags &= ~0x40000;
        ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDB0);
        TObjEneMe1Gee__sub_800CBC04((u8 *)o);
        break;
    }
}
#undef o
#pragma pop

}

#define o ((Gee_800CA454 *)arg0)
void TObjEneMe1Gee__sub_800CA454(void *arg0, s32 arg1) {
    Vec_800CA454 *dir = &o->dir;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)o)->set_field_378(7);
        o->flags |= 0x10000;
        o->flags &= ~0x400000;
        ((VObj_800CA454 *)o)->m94();
        o->flags30 |= 0x1000000;
        ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDB0);
        o->mode = 1;
        o->timer = 0;
        o->sub460 = NULL;
        o->sub464 = NULL;
        break;
    case 3:
        if (((VObj_800CA454 *)o)->m106() == 0 && ((TObjEneMe1Gee *)o)->check_death_trigger() == 0 && o->mode == 6) {
            if (o->flags & 0x100000) {
                transition_enemy_state__9TObjEneDDFl(o, 9);
            } else {
                transition_enemy_state__9TObjEneDDFl(o, 10);
            }
        }
        break;
    case 0:
        ((void (*)(void *))advance_animation_playback)(o);
        if (o->mode == 1) {
            if (((TObjEneDD_ST *)o)->update_linked_position(TObjEneMe1Gee__data_805DA0A8) == 0) {
                break;
            }
        } else if (((TObjEneEpsilon *)o)->update_death_check() == 0) {
            break;
        }
        ((TObjEneDD_ST *)o)->enemy_copy_target_destination();
        switch (o->mode) {
        case 1:
            ((TObjEneDD *)o)->update_velocity();
            if (((TObjEneMe1Gee *)o)->check_can_attack() != 0) {
                o->mode = 2;
                o->flags |= 0x40000;
            }
            TObjEneEpsilon__sub_800B92F8((u8 *)o, 0x200, (f32)TObjEneMe1Gee__data_805DA0D4);
            break;
        case 2:
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Gee *)o)->update_angle();
            o->mode = 3;
            ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDC0);
            VecCopy__FP3VecPC3Vec(dir, &o->tgt);
            break;
        case 3: {
            Vec_800CA454 d;
            ((TObjEneDD *)o)->update_velocity();
            ((TObjEneMe1Gee *)o)->update_angle();
            VecCopy__FP3VecPC3Vec(&d, &o->tgt);
            subtract_vector(&d, dir);
            if (normalize_vector_xz((Vec *)((Vec_800C96B4 *)&d)) < lbl_805DA124) {
                VecCopy__FP3VecPC3Vec(dir, &o->tgt);
            } else {
                dir->x = lbl_805DA124 * d.x + dir->x;
                dir->y = lbl_805DA124 * d.y + dir->y;
                dir->z = lbl_805DA124 * d.z + dir->z;
            }
            o->timer++;
            if (o->timer > o->param->f18) {
                o->fB8 = 1;
                o->mode = 4;
                o->timer = 0;
                if (o->sub460 != NULL) {
                    queue_destruction__7TObjectFv(o->sub460);
                    o->sub460 = NULL;
                }
                if (o->sub464 != NULL) {
                    queue_destruction__7TObjectFv(o->sub464);
                    o->sub464 = NULL;
                }
                play_sound_effect(TObjEneMe1Gee::handle_message((s32)o, 0x3AD17), (u32)o->snd, 0, 0);
            } else {
                play_persistent_sound((s32)(TObjEneMe1Gee::handle_message((s32)o, 0x3A914)), (s32)o, (u32)o->snd, 0, 0);
            }
            break;
        }
        case 4:
            o->timer++;
            if (o->timer >= 15) {
                o->mode = 5;
                o->flags &= ~0x40000;
                ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDB0);
                o->f408++;
                ((void (*)(void *))advance_animation_playback)(o);
                push_matrix_from(identity_matrix);
                post_translate_matrix(&o->pos38);
                rotate_matrix_y(0, o->angle);
                TObjPlayer::set_global_flag();
                ((TObjEnemy *)o)->calc_joint_matrices(o->timer);
                TObjPlayer::clear_global_state();
                pop_matrix();
                o->timer = 0;
                push_matrix_from(anim_model_matrix_array + 0x150);
                {
                    Vec_800CA454 out;
                    Vec_800CA454 in = lbl_8043BE7C[0];
                    void *p;
                    matrix_mult_vec(0, &in, &out);
                    pop_matrix();
                    out.y += o->f3E8;
                    p = __nw__7TObjectFUl(0xC4);
                    if (p != NULL) {
                        TObjEneMe1Gee_NEEDLE__ct((TObjEneMe1Gee_NEEDLE *)((u8 *)p), (s32)((s32)o), (u8 *)((u8 *)&out), (u8 *)((u8 *)dir), (f32)((f32)o->f3FC), (f32)((f32)o->param->f4));
                    }
                }
            }
            break;
        case 5:
            o->timer++;
            if (o->timer > o->param->f20) {
                o->timer = 0;
                if (o->f408 >= o->param->f24) {
                    o->mode = 6;
                } else {
                    o->mode = 1;
                }
            }
            break;
        }
        ((TObjEneMe1Gee *)o)->set_move_speed_x();
        ((VObj_800CA454 *)o)->m87();
        break;
    case 5:
        o->flags &= ~0x40000;
        ((void (*)(void *, const void *))destroy_subobj__13TObjEneMe1GeeFPv)(o, TObjEneMe1Gee__data_8043BDB0);
        if (o->sub460 != NULL) {
            queue_destruction__7TObjectFv(o->sub460);
            o->sub460 = NULL;
        }
        if (o->sub464 != NULL) {
            queue_destruction__7TObjectFv(o->sub464);
            o->sub464 = NULL;
        }
        break;
    }
}
#undef o
#pragma pop

void TObjEneMe1Gee::state_attack(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(6);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        this->actorFlags = (s32) (this->actorFlags | 0x01000000);
        *(s32 *)((s8 *)this + 0x434) = 0;
        return;
    case 3:
        if ((this->vfunc_108() == 0) && ((s32) *(s32 *)((s8 *)this + 0x434) == 3)) {
            *(s32 *)((s8 *)this + 0x408) = 0;
            this->vfunc_105();
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation_playback();
        this->update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        switch (*(s32 *)((s8 *)this + 0x434)) {
        case 0:
            temp_r3 = *(s32 *)((s8 *)this + 0x3C8);
            if (temp_r3 & 4) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFB);
                if (((s32 (*)(void *, s32))TObjEneMe1Gee__sub_800CB5A0)(this, 0x200) != 0) {
                    *(s32 *)((s8 *)this + 0x434) = 1;
                    ((s32 (*)(void *, s32))sub_800CB764__13TUnk_8049387CFl)(this, 1);
                } else {
                    *(s32 *)((s8 *)this + 0x434) = 2;
                    ((s32 (*)(void *, s32))sub_800CB764__13TUnk_8049387CFl)(this, 3);
                }
            }
            update();
            this->update_animation_frame();
            break;
        case 1:
            if ((s32) *(s32 *)((s8 *)this + 0x47C) == 0) {
                *(s32 *)((s8 *)this + 0x434) = 3;
            }
            update();
            this->update_animation_frame();
            break;
        case 2:
            update();
            if ((s32) *(s32 *)((s8 *)this + 0x47C) != 0) {
                this->update_animation_frame();
            } else {
                ((s32 (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)(this, *(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3F0));
                if (*(s32 *)((s8 *)this + 0x3C8) & 0x80000) {
                    *(s32 *)((s8 *)this + 0x434) = 3;
                }
            }
            break;
        }
        this->vfunc_89();
        break;
    }
}

void TObjEneMe1Gee::vfunc_111(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        this->actorFlags = (s32) (this->actorFlags | 0x01000000);
        return;
    case 3:
        if (*(s32 *)((s8 *)this + 0x3C8) & 0x80000) {
            *(s32 *)((s8 *)this + 0x408) = 0;
            this->vfunc_105();
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        update();
        update_animation_frame();
        this->vfunc_89();
        break;
    }
}

void TObjEneMe1Gee::vfunc_110(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(4);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFEFFFFFF);
        *(f32 *)((s8 *)arg0 + 0x46C) = ((const f32 *)TObjEneMe1Gee__data_8043BDB0)[1];
        *(f32 *)((s8 *)arg0 + 0x470) = ((const f32 *)TObjEneMe1Gee__data_8043BDB0)[2];
        *(f32 *)((s8 *)arg0 + 0x474) = ((const f32 *)TObjEneMe1Gee__data_8043BDB0)[3];
        ((TObjEneMe1Gee *)arg0)->update_packed_color();
        *(s32 *)((s8 *)arg0 + 0x434) = 0;
        return;
    case 3:
        if (this->vfunc_108() == 0) {
            temp_r3 = *(s32 *)((s8 *)arg0 + 0x3C8);
            if (temp_r3 & 2) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFD);
                if ((s32) *(s32 *)((s8 *)arg0 + 0x3C4) == 1) {
                    transition_enemy_state__9TObjEneDDFl(arg0, 6);
                } else {
                    transition_enemy_state__9TObjEneDDFl(arg0, 5);
                }
            }
        }
        break;
    case 1:
        break;
    case 0:
        ((void (*)())advance_animation_playback)();
        ((TObjEneDD_ST *)arg0)->update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        switch (*(s32 *)((s8 *)arg0 + 0x434)) {
        case 2:
            break;
        case 0:
            *(s32 *)((s8 *)arg0 + 0x404) = (s32) (*(s32 *)((s8 *)arg0 + 0x404) - 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x404) <= 0) {
                *(s32 *)((s8 *)arg0 + 0x47C) = 2;
                *(s32 *)((s8 *)arg0 + 0x434) = 1;
            }
            break;
        case 1:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x47C) == 0) {
                *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x8000);
                switch (*(s32 *)((s8 *)arg0 + 0x3C4)) {
                case 0:
                    set_flag3c8_bit2__13TObjEneMe1GeeFv(arg0);
                case 1:
                    *(s32 *)((s8 *)arg0 + 0x434) = 3;
                    break;
                }
            }
            ((TObjEneMe1Gee *)arg0)->update();
            break;
        case 3:
            ((TObjEneMe1Gee *)arg0)->update();
            break;
        }
        ((TObjEneMe1Gee *)arg0)->update_hover_height();
        this->vfunc_89();
        return;
    case 5:
        this->vfunc_92();
        break;
    }
}

void TObjEneMe1Gee::state_hover(s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_96();
        this->actorFlags = (s32) (this->actorFlags & 0xFEFFFFFF);
        *(s32 *)((s8 *)this + 0x47C) = 1;
        break;
    case 3:
        if (this->vfunc_108() == 0) {
            temp_r3 = *(s32 *)((s8 *)this + 0x3C8);
            if (temp_r3 & 1) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (temp_r3 & 0xFFFFFFFE);
                transition_enemy_state__9TObjEneDDFl(this, 4);
            } else if (this->enemy_has_live_target() != 0) {
                transition_enemy_state__9TObjEneDDFl(this, 4);
            }
        }
        break;
    case 0:
        advance_animation_playback();
        if ((s32) this->m_3e0 != 1) {
            this->update_linked_position(TObjEneMe1Gee__data_805DA0A8);
        }
        if ((s32) this->m_3e0 == 2) {
            ((s32 (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)(this, lbl_805DA0AC + *(f32 *)((s8 *)this + 0x3C));
        } else {
            this->update_hover_height();
        }
        this->vfunc_89();
        break;
    case 5:
        this->actorFlags = (s32) (this->actorFlags & 0xFEFFFFFF);
        break;
    case 1:
        break;
    }
}

void TObjEneMe1Gee__sub_800CAFD8(u8 *ene_me1_gee, s32 arg1) {
    Stack_800CAFD8 stack;
    f32 temp_f0;
    switch (arg1) {
    case 4:
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_B8 = 0;
        ((TObjEneDD *)ene_me1_gee)->set_field_378(3);
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3C8 = (s32) (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3C8 & 0xFFBFFFFF);
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3C8 = (s32) (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3C8 & 0xFFF7FFFF);
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_30 = (s32) (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_30 | 0x01000000);
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_95();
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_47C = 1;
        TObjEneMe3SinowZoa__sub_800D758C(ene_me1_gee + 0x3CC);
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&stack.sp8, ene_me1_gee + 0x38);
        temp_f0 = stack.spC + lbl_805DA128;
        stack.spC = temp_f0;
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3F8 = temp_f0;
        TBoss3Volopt__sub_800D8D88((s32) &stack.sp8);
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_91();
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_434 = 0;
        return;
    case 3:
        if (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_3C8 & 0x80000) {
            ((void (*)(void *, s16))transition_enemy_state__9TObjEneDDFl)(ene_me1_gee, 3);
            ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_92();
        }
        return;
    case 0:
        ((void (*)(void *))advance_animation_playback)(ene_me1_gee);
        switch (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_434) {
        case 0:
            if (((VObj_14_948132 *)(ene_me1_gee + (972)))->m5() != 0) {
                ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_434 = 1;
            }
            break;
        case 1:
            ((TObjEneMe1Gee *)ene_me1_gee)->update_from_float_sum();
            break;
        }
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_88();
        TObjEneMe1Gee__sub_800CB968((s32) ene_me1_gee);
        return;
    case 5:
        ((TObjEneMe1Gee *)(ene_me1_gee))->vfunc_92();
        ((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_30 = (s32) (((RecoveredFields_800CAFD8_arg0 *)ene_me1_gee)->field_30 & 0xFEFFFFFF);
        break;
    }
}

void TObjEneMe1Gee::state_move(s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        *(s32 *)((s8 *)((u8 *)this) + 0x3C8) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C8) & 0xFFBFFFFF);
        this->vfunc_95();
        temp_r4 = this->actorFlags & 0xFEFFFFFF;
        this->actorFlags = temp_r4;
        *(s32 *)((s8 *)((u8 *)this) + 0x47C) = 1;
        ((s32 (*)(void *, s32))TObjEneMe3SinowZoa__sub_800D758C)(((u8 *)this) + 0x3CC, temp_r4);
        ((TBoss3Volopt *)(((u8 *)this) + 0x38))->play_area_sound_effect();
        return;
    case 3:
        if (((V_Sub *) (((u8 *)this) + 0x3CC))->m5() != 0) {
            transition_enemy_state__9TObjEneDDFl(this, 3);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback();
        if ((s32) this->m_3e0 == 2) {
            ((s32 (*)(void *, f32))sub_800CBE6C__13TObjEneMe1GeeFv)(this, lbl_805DA0AC + *(f32 *)((s8 *)((u8 *)this) + 0x3C));
        } else {
            this->update_hover_height();
        }
        this->vfunc_88();
        break;
    }
}

void TObjEneMe1Gee::state_attack_loop(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(3);
        this->vfunc_95();
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x400000);
        *(s32 *)((s8 *)this + 0x47C) = 1;
        *(s32 *)((s8 *)this + 0x434) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x434) >= 4) {
            if ((s32) this->m_3e0 == 0) {
                *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x100000);
            }
            if (*(s32 *)((s8 *)this + 0x3C8) & 0x02000000) {
                transition_enemy_state__9TObjEneDDFl(this, 1);
            } else {
                transition_enemy_state__9TObjEneDDFl(this, 2);
            }
        }
    case 5:
        break;
    case 0:
        *(s32 *)((s8 *)this + 0x434) = (s32) (*(s32 *)((s8 *)this + 0x434) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x434) == 2) {
            this->vfunc_107();
        }
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFEFFFFFF);
        break;
    }
}

void TObjEneMe1Gee__vt85(Ene_800CB3A4 *arg0, u32 arg1, s32 mode) {
    switch (arg1) {
    case 0:
        ((TObjEneMe1Gee *)arg0)->state_attack_loop(mode);
        break;
    case 1:
        ((TObjEneMe1Gee *)arg0)->state_move(mode);
        break;
    case 2:
        ((void (*)(void *, s32))TObjEneMe1Gee__sub_800CAFD8)(arg0, mode);
        break;
    case 3:
        ((TObjEneMe1Gee *)arg0)->state_hover(mode);
        break;
    case 4:
        arg0->v108(mode);
        break;
    case 5:
        arg0->v109(mode);
        break;
    case 6:
        ((TObjEneMe1Gee *)arg0)->state_attack(mode);
        break;
    case 7:
        TObjEneMe1Gee__sub_800CA454(arg0, mode);
        break;
    case 8:
        TObjEneMe1Gee__sub_800C9DF8(arg0, mode);
        break;
    case 9:
        TObjEneMe1Gee__sub_800C9A94(arg0, mode);
        break;
    case 10:
        ((void (*)(void *, s32))run_task__13TObjEneMe1GeeFPvi)(arg0, mode);
        break;
    case 12:
        ((void (*)(void *, s32))TObjEneMe1Gee__sub_800C9580)(arg0, mode);
        break;
    case 13:
        TObjEneMe1Gee__sub_800C96B4((Gee_800C96B4 *)(arg0), mode);
        break;
    case 14:
        arg0->v110(mode);
        break;
    case 15:
        ((TObjEneMe1Gee *)arg0)->state_return_home(mode);
        break;
    case 17:
        ((TObjEneMe1Gee *)arg0)->handle_event(mode);
        break;
    case 18:
        ((TObjEneMe1Gee *)arg0)->state_orbit(mode);
        break;
    }
}

void TObjEneMe1Gee::set_flag3c8_bit40() { *(u32*)((char*)this + 0x3c8) |= 0x40; }

void TObjEneMe1Gee__sub_800CB4DC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x100000 | 4);
}

void TObjEneMe1Gee::set_flag3c8_bit8() { *(u32*)((char*)this + 0x3c8) |= 0x8; }

void TObjEneMe1Gee::set_flag3c8_bit4() { *(u32*)((char*)this + 0x3c8) |= 0x4; }

void TObjEneMe1Gee::set_flag3c8_bit2() { *(u32*)((char*)this + 0x3c8) |= 0x2; }

void TObjEneMe1Gee::set_state_flag(s32 arg1, s32 arg2) {
    set_target_player__12TObjEneDD_STFPv();
    *(s32 *)((s8 *)this + 0x404) = arg2;
    *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 1);
}

void TObjEneMe1Gee__sub_800CB560(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x404) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 1);
}

int TObjEneMe1Gee::vfunc_116() { return 1; }

void TObjEneMe1Gee::vfunc_117(u32) {  }

s32 TObjEneMe1Gee__sub_800CB584(u8 *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x40000) {
        return *(s32 *)((s8 *)arg0 + 0x390);
    }
    return 0;
}

u8 TObjEneMe1Gee__sub_800CB5A0(u8 *arg0, s32 arg1) {
    return (u8) ((*(s32 *)((s8 *)arg0 + 0x3C8) & arg1) != 0);
}

void TObjEneMe1Gee::sub_800CB5B8() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x200);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFEFF);
}

void TObjEneMe1Gee::sub_800CB5D4() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x100);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFDFF);
}

void TObjEneMe1Gee::sub_800CB5F0() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x04000000);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFDFFFFFF);
}

void TObjEneMe1Gee::sub_800CB60C() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x02000000);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFBFFFFFF);
}

int TObjEneMe1Gee__sub_800CB628(void* p) { return (*(u32*)((char*)p + 0x3c8) >> 15) & 0x1; }

void TObjEneMe1Gee::update_photon_target() {
    if ((s16) this->mode == 3) {
        *(s32 *)((s8 *)this + 0x3C0) = (s32)find_entity_by_id(*(u16 *)((s8 *)this + 0x48C));
        TObjEneMe1Gee__sub_800CB560((u8 *)((void*)(*(s32 *)((s8 *)this + 0x3C0))));
    }
}

int TObjEneMe1Gee::vfunc_109() { return 1; }

void TObjEneMe1Gee::vfunc_113() {
    if ((s32 *) (*(s32 **)&gee_resource_bundle_ptr) != NULL) {
        *(*(s32 **)&gee_resource_bundle_ptr) = *(s32 *)((s8 *)this + 0x478);
    }
}

extern "C" {
struct C_800CB69C { u8 pad[0x468]; f32 b, g, r, a; u32 rgba; };
extern const f32 lbl_805DA12C;
#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::update_packed_color() {
    C_800CB69C *o = (C_800CB69C *)this;
    u8 r = (u32)(lbl_805DA12C * o->r);
    u8 a = (u32)(lbl_805DA0D0 * (lbl_805DA12C * o->a));
    u8 g = (u32)(lbl_805DA12C * o->g);
    u8 b = (u32)(lbl_805DA12C * o->b);
    o->rgba = (a << 24) | (r << 16) | (g << 8) | b;
}
#pragma pop
}

void destroy_subobj__13TObjEneMe1GeeFPv(void* p, void * _w1) { copy_argb((void *)((char*)p + 0x468), _w1); ((TObjEneMe1Gee *)p)->update_packed_color(); }

void TUnk_8049387C::sub_800CB764(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(void *, void *))destroy_subobj__13TObjEneMe1GeeFPv)(arg0, &lbl_8043BDD0.value);
    *(s32 *)((s8 *)arg0 + 0x47C) = 3;
    *(s32 *)((s8 *)arg0 + 0x480) = arg1;
    *(s32 *)((s8 *)arg0 + 0x484) = 2;
    *(s32 *)((s8 *)arg0 + 0x488) = 0;
}

void TObjEneMe1Gee::update_fade_sequence() {
    u8 *arg0 = (u8 *)this;
    switch (*(s32 *)((s8 *)arg0 + 0x47C)) {
    case 0:
        break;
    case 1:
        if (*(f32 *)((s8 *)arg0 + 0x468) > TObjEneMe1Gee__data_805DA0B4) {
            *(f32 *)((s8 *)arg0 + 0x468) = *(f32 *)((s8 *)arg0 + 0x468) - lbl_805DA130;
        } else {
            *(f32 *)((s8 *)arg0 + 0x468) = TObjEneMe1Gee__data_805DA0B4;
            *(s32 *)((s8 *)arg0 + 0x47C) = 0;
        }
        ((TObjEneMe1Gee *)arg0)->update_packed_color();
        break;
    case 2:
        if (*(f32 *)((s8 *)arg0 + 0x468) < TObjEneMe1Gee__data_805DA0EC) {
            *(f32 *)((s8 *)arg0 + 0x468) = *(f32 *)((s8 *)arg0 + 0x468) + lbl_805DA130;
        } else {
            *(f32 *)((s8 *)arg0 + 0x468) = TObjEneMe1Gee__data_805DA0EC;
            *(s32 *)((s8 *)arg0 + 0x47C) = 0;
        }
        ((TObjEneMe1Gee *)arg0)->update_packed_color();
        break;
    case 3:
        (*(s32 *)((s8 *)arg0 + 0x484))++;
        if ((f32)*(s32 *)((s8 *)arg0 + 0x484) >= lbl_805DA0CC) {
            *(s32 *)((s8 *)arg0 + 0x484) = 0;
            switch (TObjEneMe1Gee__fade_command_streams[*(s32 *)((s8 *)arg0 + 0x480)][(*(s32 *)((s8 *)arg0 + 0x488))++]) {
            case 'b':
                *(f32 *)((s8 *)arg0 + 0x468) = TObjEneMe1Gee__data_805DA0B4;
                break;
            case 'c':
                *(s32 *)((s8 *)arg0 + 0x47C) = 0;
                ((void (*)(void *, void *))copy_argb)(arg0 + 0x468, (void *)TObjEneMe1Gee__data_8043BDB0);
                break;
            case 'a':
                *(f32 *)((s8 *)arg0 + 0x468) = TObjEneMe1Gee__data_805DA0EC;
                break;
            }
            ((TObjEneMe1Gee *)arg0)->update_packed_color();
        }
        break;
    }
}

int TObjEneMe1Gee__vt102(void* p) { return select_and_apply_target__12TObjEneDD_STFf(p); }

void TObjEneMe1Gee__sub_800CB968(s32 arg0) {
    play_persistent_sound(TObjEneMe1Gee::handle_message(arg0, 0x3BC16), arg0, arg0 + 0x2FC, 0, 0);
}

s32 TObjEneMe1Gee::handle_message(s32 arg0, s32 arg1) {
    s32 var_r3;

    if (arg1 == 0x3A843) {
        var_r3 = 0x3A843;
        if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
            return 0x4003B20D;
        }
        return var_r3;
    }
    var_r3 = ((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(arg1));
    return var_r3;
}

s32 TObjEneMe1Gee::check_death_trigger() {
    if ((u32) this->m_390 == 0U) {
        transition_enemy_state__9TObjEneDDFl(this, 0xF);
        return 1;
    }
    return 0;
}

s32 TObjEneMe1Gee::vfunc_108() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x3C8);
    if (temp_r4 & 0x40) {
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (temp_r4 & 0xFFFFFFBF);
        transition_enemy_state__9TObjEneDDFl(arg0, 0xC);
        return 1;
    }
    return 0;
}

void TObjEneMe1Gee::vfunc_107() {  }

s32 TObjEneMe1Gee__sub_800CBA80(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3F4) < lbl_805DA134;
}

s32 TObjEneMe1Gee::check_can_attack() {
    f32 sp8;
    s32 var_r31;

    var_r31 = 0;
    if (*(f32 *)((s8 *)this + 0x3AC) < lbl_805DA0FC) {
        var_r31 = 1;
        *(void **)((s8 *)this + 0x3C0) = find_entity_by_id(*(u16 *)((s8 *)this + 0x48C));
        if ((((VObj_800CBA98 *)(*(void **)((s8 *)this + 0x3C0)))->m114(this->m_390) == 0) && (((s32 (*)(void *, f32 *, f32))find_attack_target__13TObjEneMe1GeeFPvPv)(this, &sp8, lbl_805DA138) != 0) && (sp8 > lbl_805DA0FC)) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

s32 find_attack_target__13TObjEneMe1GeeFPvPv(Gee_800CBB34 *arg0, f32 *out) {
    Rec_800CBB34 recs[5];
    s32 found;
    s32 n;
    void *p;
    s32 i;
    found = 0;
    *out = lbl_805DA110;
    n = collect_enemy_target_candidates(arg0, recs);
    for (i = 0; i < n; i++) {
        p = get_player_by_client_id(recs[i].id);
        if (p != arg0->target) {
            arg0->owner = (Obj_800CBB34 *)find_entity_by_id(arg0->ownerIdx);
            if (arg0->owner->v114(p) != 0) {
                *out = newton_sqrtf(recs[i].dist);
                found = 1;
                ((void (*)(void *, void *))set_target_player__12TObjEneDD_STFPv)(arg0, p);
                break;
            }
        }
    }
    return found;
}

void TObjEneMe1Gee__sub_800CBC04(u8 *arg0) {
    u8 *temp_r4;
    temp_r4 = *(u8 **)((s8 *)arg0 + 0xA4);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & ~0x28);
}

void TObjEneMe1Gee__sub_800CBC1C(u8 *arg0) {
    u8 *temp_r3;
    temp_r3 = *(u8 **)((s8 *)arg0 + 0xA4);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 0x28);
}

void TObjEneMe1Gee::vfunc_89() { vfunc_89__9TObjEneDDFv(this); }

void TObjEneMe1Gee::vfunc_105() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3C8) & 0x100) {
        ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(arg0, 8);
        return;
    }
    if ((s32) this->m_3e0 == 0) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x430) < 2) {
            ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(arg0, 7);
            *(s32 *)((s8 *)arg0 + 0x430) = (s32) (*(s32 *)((s8 *)arg0 + 0x430) + 1);
            return;
        }
        ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(arg0, 8);
        *(s32 *)((s8 *)arg0 + 0x430) = 0;
        return;
    }
    ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(arg0, 7);
}

void TObjEneMe1Gee::update() { if (this->enemy_has_live_target() != 0) { this->enemy_copy_target_destination(); this->update_velocity(); this->update_angle(); } }

void TObjEneMe1Gee::update_angle() {
    this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (lbl_8043BF28 * atan2_float(this->m_3a0, *(f32 *)((s8 *)this + 0x3A8))), 0x400);
    this->rotation_y = (s32) (s16) this->rotation_y;
}

void TObjEneMe1Gee::update_from_float_sum() {
    ((s32 (*)(f32))TObjEneMe1Gee__sub_800CBDBC)(*(f32 *)((s8 *)this + 0x3EC) + *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneMe1Gee__sub_800CBDBC(u8 *arg0) {
    Stack_800CBDBC stack;
    ((s32 (*)(void))approach_target_value__13TObjEneMe1GeeFPvf)();
    VecCopy__FP3VecPC3Vec(&stack.sp8, arg0 + 0x38);
    stack.spC = *(f32 *)((s8 *)arg0 + 0x3F8);
    ((VObj_18_p40 *)(arg0))->m99(&stack.sp8);
}

void TObjEneMe1Gee::update_animation_frame() {
    ((s32 (*)(f32))sub_800CBE6C__13TObjEneMe1GeeFv)(*(f32 *)((s8 *)this + 0x3E8) + *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneMe1Gee::update_hover_height() {
    ((s32 (*)(f32))sub_800CBE6C__13TObjEneMe1GeeFv)(*(f32 *)((s8 *)this + 0x3EC) + *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneMe1Gee::sub_800CBE6C() {
    u8 *arg0 = (u8 *)this;
    Stack_800CBE6C stack;
    ((s32 (*)(void))sub_800CBF58__13TObjEneMe1GeeFf)();
    VecCopy__FP3VecPC3Vec(&stack.sp8, (u8 *)&this->position);
    stack.spC = *(f32 *)((s8 *)arg0 + 0x3F8);
    this->vfunc_101((u8 *)&stack.sp8);
}

void TObjEneMe1Gee::set_move_speed_x() {
    ((s32 (*)(f32))sub_800CBF58__13TObjEneMe1GeeFf)(*(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x3E8));
}

void approach_target_value__13TObjEneMe1GeeFPvf(Obj_800CBEF0 *self, f32 target) {
    f32 d = target - self->f3f8;
    self->f3c8 &= ~0x80000;
    if (d >= self->f400) {
        self->f3f8 += self->f400;
    } else if (d <= -self->f400) {
        self->f3f8 -= self->f400;
    } else {
        self->f3f8 = target;
        self->f3c8 |= 0x80000;
    }
}

void TObjEneMe1Gee::sub_800CBF58(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f3;
    temp_f3 = farg0 - *(f32 *)((s8 *)arg0 + 0x3F8);
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFF7FFFF);
    if (temp_f3 >= TObjEneMe1Gee__data_805DA0D4) {
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3F8) + TObjEneMe1Gee__data_805DA0D4);
        return;
    }
    if (temp_f3 <= lbl_805DA13C) {
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3F8) - TObjEneMe1Gee__data_805DA0D4);
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x3F8) = farg0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x80000);
}

u8 *TObjEneMe1Gee::vfunc_101(u8 *) {
    if (vfunc_101__9TObjEneDDFPUc() == 0U) {
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFEFFFFFF);
        return;
    }
    *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) | 0x01000000);
}

#pragma push
#pragma fp_contract on
void calc_position__13TObjEneMe1GeeFiPv(s32 actor, void *arg1) {
    f32 temp_f1;
    f32 temp_f31;
    s32 random_scaled;

    random_scaled = TObjEneDD::get_random_scaled();
    f32 fv = random_ratio__9TObjCharaFv(actor);
    temp_f31 = (TObjEneMe1Gee__data_805DA0E8 * fv) + lbl_805DA0B8;
    temp_f1 = temp_f31 * sin_table_lookup(random_scaled, fv);
    *(f32 *)((s8 *)arg1 + 0) = temp_f1;
    *(f32 *)((s8 *)arg1 + 4) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (temp_f31 * ((f32 (*)(s32, f32))cos_table_lookup)(random_scaled, temp_f1));
    vec3_add_to(arg1, actor + 0x38);
}
#pragma pop

void TObjEneMe1Gee::vfunc_106() {
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&(*(int *)&TObjEneMe1Gee__resource_bundle)) + 0x42C)) + 8);
    this->texlist = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&(*(int *)&TObjEneMe1Gee__resource_bundle)) + 0x42C)) + 0xC);
}

#pragma push
#pragma opt_common_subs off
void TObjEneMe1Gee::sub_800CC0C4() {
    u8 *arg0 = (u8 *)this;
    if ((s32) get_random_float__21TObjEneMe3ShinowaRealFv((f32) (*(f32 *)((s8 *)arg0 + 0x354))) == 0) {
        ((TObjEneMe1Gee *)arg0)->sub_800CB5D4();
    } else {
        ((TObjEneMe1Gee *)arg0)->sub_800CB5B8();
    }
    if ((s32) get_random_float__21TObjEneMe3ShinowaRealFv((f32) (*(f32 *)((s8 *)arg0 + 0x358))) == 0) {
        ((TObjEneMe1Gee *)arg0)->sub_800CB60C();
    } else {
        ((TObjEneMe1Gee *)arg0)->sub_800CB5F0();
    }
    *(f32 *)((s8 *)arg0 + 0x3FC) = (f32) (lbl_805DA140 + *(f32 *)((s8 *)arg0 + 0x360));
    if (*(f32 *)((s8 *)arg0 + 0x3FC) < lbl_805DA144) {
        *(f32 *)((s8 *)arg0 + 0x3FC) = (f32) lbl_805DA144;
    }
    *(f32 *)((s8 *)arg0 + 0x400) = (f32) (TObjEneMe1Gee__data_805DA0EC + *(f32 *)((s8 *)arg0 + 0x35C));
    if (*(f32 *)((s8 *)arg0 + 0x400) < TObjEneMe1Gee__data_805DA0EC) {
        *(f32 *)((s8 *)arg0 + 0x400) = (f32) TObjEneMe1Gee__data_805DA0EC;
    }
}
#pragma pop

void TObjEneMe1Gee::vfunc_88() {
    struct VBase_800CC190 *o = (struct VBase_800CC190 *)this;
    *(f32 *)((s8 *)this + 0x3F4) = (f32) (*(f32 *)((s8 *)this + 0x3F8) - *(f32 *)((s8 *)this + 0x3C));
    if (*(f32 *)((s8 *)this + 0x3F4) < TObjEneMe1Gee__data_805DA0E8) {
        o->m96();
    } else {
        o->m95();
    }
    *(f32 *)((s8 *)this->bodies + 4) = (f32) *(f32 *)((s8 *)this + 0x3F4);
}

void TObjEneMe1Gee::copy_pos() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) *(f32 *)((s8 *)arg0 + 0x3F8);
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    ((s32 (*)(void *, void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x74, arg0 + 0x2FC, arg0);
}

void TObjEneMe1Gee::vfunc_61() {  }

void TObjEneMe1Gee::vfunc_62() { if (this->mode != 13) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(this, (void*)13); } }

void TObjEneMe1Gee::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 0xE) && (temp_r0 != 0xC)) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(arg0, (void*)(0xE));
    }
}

void TObjEneMe1Gee::vfunc_28() {  }

int TObjEneMe1Gee__sub_800CC2BC(void) {  return (*(int *)&TObjEneMe1Gee__resource_bundle); }

void run_task__13TObjEneMe1GeeFv(u8 *arg0) {
    u8 *object;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneMe1Gee *)(arg0))->vfunc_114();
        return;
    }
    if (((s32) ((TObjEneMe1Gee *)arg0)->m_3e0 == 1) && ((*(u8 **)((s8 *)arg0 + 0x3C0) = (u8 *)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x48C)), object = *(u8 **)((s8 *)arg0 + 0x3C0), ((object == NULL) != 0)) || (((TObject *)object)->all_parents_unqueued_for_destruction() == 0))) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (((TObjEneMe1Gee *)(arg0))->vfunc_83() != 4) {
        ((TObjEneMe1Gee *)(arg0))->vfunc_85();
        ((TObjEneMe1Gee *)arg0)->update_fade_sequence();
    }
    ((TObjEneMe1Gee *)arg0)->copy_pos();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
    ((TObjEneMe1Gee *)(arg0))->vfunc_100();
}

void *__dt__13TObjEneMe1GeeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjEneMe1Gee;
        if (*(void **)((s8 *)arg0 + 0x464) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x464)); *(s32 *)((s8 *)arg0 + 0x464) = 0; }
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3CC, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
#undef me1_gee_init_params
#define me1_gee_init_params ((s32 *)me1_gee_init_params)
#pragma opt_loop_invariants off
void TObjEneMe1Gee::init_state() {
    s32 temp_r0;
    s32 i;
    s32 var_r30;
    u8 *temp_r4;
    this->init_position_vectors();
    this->vfunc_106();
    init_model__9TObjEneDDFv(this, (void *) lbl_8049379C, 1);
    this->set_field_d8((s32)((void *) TObjEneMe1Gee__motion_parameters));
    this->set_field_dc((int) (*(s32 *)((s8 *)(*(u8 * *)&(*(int *)&TObjEneMe1Gee__resource_bundle)) + 0x430)));
    *(s16 *)((s8 *)((u8 *)this) + 0xB8) = 0;
    set_animation((*(s16 *)((s8 *)((u8 *)this) + 0xB8)));
    this->set_field_b8((int) (*(s16 *)((s8 *)((u8 *)this) + 0xB8)));
    reset_hp__9TObjEneDDFv(this, gee_boss_stat_handle_table[*(s32 *)((s8 *)((u8 *)this) + 0x3C4)], gee_shared_handler_b_table[*(s32 *)((s8 *)((u8 *)this) + 0x3C4)], gee_object_handle_table[*(s32 *)((s8 *)((u8 *)this) + 0x3C4)]);
    this->check_state_flag_1();
    *(s32 **)((s8 *)((u8 *)this) + 0x350) = me1_gee_init_params;
    initialize_enemy_state__9TObjEneDDFv(this, 0x36);
    *(f32 *)((s8 *)((u8 *)this) + 0x37C) = (f32) lbl_805DA0B8;
    this->enemy_init_acquire_period(0x2D);
    this->enemy_init_validate_period(0x2D);
    this->set_active();
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x30) | 0x01000000);
    *(s32 *)((s8 *)((u8 *)this) + 0x42C) = gee_shared_handler_a_table[*(s32 *)((s8 *)((u8 *)this) + 0x3C4)];
    ((VObj_14_559b06 *)(((u8 *)this) + (972)))->m2(gee_shared_handler_a_table);
    *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) lbl_805DA148;
    *(f32 *)((s8 *)((u8 *)this) + 0x3EC) = (f32) TObjEneMe1Gee__data_805DA0C0;
    *(f32 *)((s8 *)((u8 *)this) + 0x3F0) = (f32) ((TObjEneMe1Gee__data_805DA0C8 * (lbl_805DA14C * (f32) rand(lbl_805DA148))) + TObjEneMe1Gee__data_805DA0C0);
    *(f32 *)((s8 *)((u8 *)this) + 0x3F4) = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x3EC);
    *(f32 *)((s8 *)((u8 *)this) + 0x3F8) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3C) + *(f32 *)((s8 *)((u8 *)this) + 0x3F4));
    *(s32 *)((s8 *)((u8 *)this) + 0x404) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x408) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x40C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x410) = 0;
    for (i = 0; i < 2; i++) {
        VecCopy__FP3VecPC3Vec(&((Gee_800CC430 *)((u8 *)this))->v[i], &((Gee_800CC430 *)((u8 *)this))->pos);
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x430) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x434) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x438) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x43C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x440) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x444) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x448) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)((u8 *)this) + 0x44C) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)((u8 *)this) + 0x450) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)((u8 *)this) + 0x454) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)((u8 *)this) + 0x458) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(f32 *)((s8 *)((u8 *)this) + 0x45C) = (f32) TObjEneMe1Gee__data_805DA0B4;
    *(s32 *)((s8 *)((u8 *)this) + 0x460) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x464) = 0;
    copy_argb(((u8 *)this) + 0x468, (void *)((void *) (((u8 *)&TObjEneMe1Gee__data_8043BDC0))));
    ((Gee_800CC430 *)((u8 *)this))->f468 = TObjEneMe1Gee__data_805DA0B4;
    *(s32 *)((s8 *)((u8 *)this) + 0x47C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x478) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x480) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x484) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x488) = 0;
    this->copy_pos();
    set_part_position__9TObjEneDDFPvPvi(this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0xA4)), 0);
    *(s16 *)((s8 *)((u8 *)this) + 0x326) = 0;
    ((VObj_18_3bc1aa *)(this))->m85(*(s16 *)((s8 *)((u8 *)this) + 0x326), 4);
    if (*(void **)((s8 *)((u8 *)this) + 0x3C0) != NULL) {
        *(s16 *)((s8 *)((u8 *)this) + 0x48C) = get_entity_id(*(void **)((s8 *)((u8 *)this) + 0x3C0));
        return;
    }
    *(u16 *)((s8 *)((u8 *)this) + 0x48C) = 0xFFFF;
}
#pragma pop

u8 *TObjEneMe1Gee__ct(u8 *ene_me1_gee, s32 arg1, u8 *arg2, s32 arg3, s16 arg4, s16 arg5) {
    __ct__12TObjEneDD_STFP7TObject(ene_me1_gee);
    *(s32 **)((s8 *)ene_me1_gee + 0x18) = &(*(RecoveredGlobal_800CC6D8___vt__13TObjEneMe1Gee *)&__vt__13TObjEneMe1Gee).value;
    __ct__13TUnk_80494938Fv(ene_me1_gee + 0x3CC);
    *(s32 *)((s8 *)ene_me1_gee + 0) = (s32) lbl_805D2A68;
    *(u8 **)((s8 *)ene_me1_gee + 0x3C0) = arg2;
    ((TObjEneDD *)ene_me1_gee)->init_common_from((u8 *)(*(u8 **)((s8 *)ene_me1_gee + 0x3C0)));
    ((TObjEneMe1Gee *)ene_me1_gee)->entity_id = arg4;
    *(s16 *)((s8 *)ene_me1_gee + 0x2C) = arg5;
    ((s32 (*)(void *, void *))calc_position__13TObjEneMe1GeeFiPv)((void *) (*(u8 **)((s8 *)ene_me1_gee + 0x3C0)), ene_me1_gee + 0x38);
    VecCopy__FP3VecPC3Vec(ene_me1_gee + 0x38, (void *)arg3);
    ((TObjEneMe1Gee *)ene_me1_gee)->rotation_y = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)ene_me1_gee + 0x3C0)) + 0x60);
    *(s32 *)((s8 *)ene_me1_gee + 0x3C8) = 0;
    ((TObjEneMe1Gee *)ene_me1_gee)->m_3e0 = 1;
    ((TObjEneMe1Gee *)ene_me1_gee)->init_state();
    return ene_me1_gee;
}

#undef advance_animation_playback
#undef TObjEneMe1Gee__data_8043BDB0
#undef copy_argb
#undef sub_800C84C8__13TUnk_8049387CFv
#undef create_breakup_mdl__12TBoss3VoloptFlllll
#undef TObjEneMe1Gee__fade_command_streams
#undef me1_gee_dispatch_table
#pragma pop
#pragma push
#define sub_800CC0C4__13TObjEneMe1GeeFv ((void (*)(void *))sub_800CC0C4__13TObjEneMe1GeeFv)
#define __ct__12TObjEneDD_STFP7TObject ((void (*)(void *))__ct__12TObjEneDD_STFP7TObject)
#define __ct__13TUnk_80494938Fv ((void (*)(void *))__ct__13TUnk_80494938Fv)
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);

void *init__13TObjEneMe1GeeFPvPvPvPv(void *ene_me1_gee, void *arg1, void *arg2, void *arg3) {
    __ct__12TObjEneDD_STFP7TObject(ene_me1_gee);
    *(s32 **)((s8 *)ene_me1_gee + 0x18) = __vt__13TObjEneMe1Gee;
    __ct__13TUnk_80494938Fv((void *)((char *)ene_me1_gee + 972));
    *(void * *)&((TObjEneMe1Gee *)ene_me1_gee)->m_name = (*(void **)&lbl_805D2A68);
    invoke_initialization_hook__9TObjEneDDFv(ene_me1_gee, arg2);
    *(u32 *)((s8 *)ene_me1_gee + 0x3C8) = 0;
    sub_800CC0C4__13TObjEneMe1GeeFv(ene_me1_gee);
    *(void **)((s8 *)ene_me1_gee + 0x3C0) = ene_me1_gee;
    *(void **)((s8 *)ene_me1_gee + 0x3C4) = arg3;
    ((TObjEneMe1Gee *)ene_me1_gee)->init_state();
    return ene_me1_gee;
}

}

#undef sub_800CC0C4__13TObjEneMe1GeeFv
#undef __ct__12TObjEneDD_STFP7TObject
#undef __ct__13TUnk_80494938Fv
#pragma pop
#pragma push

struct DelB_800CC808 { char pad[0xC]; };
struct Del_800CC808 : DelB_800CC808 { virtual ~Del_800CC808(); };

extern "C" {
void TLobby__sub_8001FE7C(void *, s32);
void TObjEneMe1Gee__sub_802A4D4C(void);

#define g51C4 (*(Del_800CC808 **)&TObjEneMe1Gee__data_805D51C4)
#define g51C0 (*(Del_800CC808 **)&TObjEneMe1Gee__data_805D51C0)
#define g51B0 (*(void **)&TObjEneMe1Gee__resource_bundle)
void TObjEneMe1Gee::free_globals() {
    if (g51C4 != NULL) {
        delete g51C4;
        g51C4 = NULL;
    }
    if (g51C0 != NULL) {
        delete g51C0;
        g51C0 = NULL;
    }
    if (g51B0 != NULL) {
        TLobby__sub_8001FE7C(g51B0, 1);
        g51B0 = NULL;
    }
    TObjEneMe1Gee__sub_802A4D4C();
}
#undef g51C4
#undef g51C0
#undef g51B0

#pragma pop
#pragma push
#define TObjEneMe1Gee__ct ((void * (*)(void *, void *, void *, void *, void *, void *))TObjEneMe1Gee__ct)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
void * create__13TObjEneMe1GeeFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);

extern void *tl_04;

void * create__13TObjEneMe1GeeFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x490);
    if (o != NULL) {
        o = TObjEneMe1Gee__ct(o, tl_04, arg0, arg1, arg2, arg3);
    }
    return o;
}

#undef TObjEneMe1Gee__ct
#undef __nw__7TObjectFUl
#pragma pop
#pragma push
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)

void *TObjEneMe1Gee::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x490);
    if (o != NULL) {
        o = init__13TObjEneMe1GeeFPvPvPvPv(o, tl_04, arg0, 0);
    }
    return o;
}

}

#undef __nw__7TObjectFUl
#pragma pop
#pragma push
#define bm_ene_me1_gee_resource_descriptor ((u8 *)&bm_ene_me1_gee_resource_descriptor)
#define bm_ene_me1_gee_low_resource_descriptor ((u8 *)&bm_ene_me1_gee_low_resource_descriptor)

#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Vec_800CC950 { f32 x, y, z; };

struct Q_800CC950 { s32 a, b, c, d; };

struct E_800CC950 { u8 pad[0x8]; s32 f8; s32 fc; };

struct D_800CC950 { u8 pad[0x42C]; E_800CC950 *f42c; s32 f430; };

extern "C" {
s32 is_split_screen();
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 init_from_model__11TBreakUpMdlFl(s32, s32);
s32 load_enemy_bml_resource(u8 *arg0);
s32 TObjPlayer__sub_800F0928(s32);
extern s32 lbl_8043BCD8[];
extern s32 lbl_8043BCE4[];
extern s32 lbl_8043BCF0[];
extern s32 lbl_8043BCFC[];
extern Q_800CC950 lbl_8043BE6C;
extern u8 *lbl_805D51B4;
extern const f32 lbl_805DA150;
void TObjEneMe1Gee::load_resources() {
    s32 i;
    s32 p;
    s32 t;
    Vec_800CC950 *v;
    v = (Vec_800CC950 *)gee_camera_ctrl_vec;
    gee_camera_ctrl_vec[0] = TObjEneMe1Gee__data_805DA0B4;
    v->y = TObjEneMe1Gee__data_805DA0B4;
    v->z = TObjEneMe1Gee__data_805DA0B4;
    if (((s32 (*)(void *))is_split_screen)(v) != 0) {
        TObjEneMe1Gee__resource_bundle = (D_800CC950 *)load_enemy_bml_resource(bm_ene_me1_gee_low_resource_descriptor);
    } else {
        TObjEneMe1Gee__resource_bundle = (D_800CC950 *)load_enemy_bml_resource(bm_ene_me1_gee_resource_descriptor);
    }
    TObjEneMe1Gee::cache_result_805D6660();
    lbl_805D51B4 = (u8 *)find_model_node(TObjEneMe1Gee__resource_bundle->f42c->f8, 7);
    for (i = 0; i < 3; i++) {
        gee_boss_stat_handle_table[i] = register_boss__6TLobbyFl(lbl_8043BCD8[i]);
        gee_shared_handler_b_table[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043BCE4[i]);
        gee_object_handle_table[i] = register_object__6TLobbyFl(lbl_8043BCF0[i]);
        gee_shared_handler_a_table[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_8043BCFC[i]);
    }
    TObjEneMe1Gee__render_node_index = 0;
    p = (int)::operator new(0x10);
    if (p != 0) {
        p = init_from_model__11TBreakUpMdlFl(p, TObjEneMe1Gee__resource_bundle->f42c->f8);
    }
    TObjEneMe1Gee__data_805D51C0 = p;
    p = (int)::operator new(0x10);
    if (p != 0) {
        p = init_from_model__11TBreakUpMdlFl(p, TObjEneMe1Gee__resource_bundle->f42c->f8);
    }
    TObjEneMe1Gee__data_805D51C4 = p;
    t = *(s32 *)((s8 *)(*(u8 **)((s8 *)(find_model_node(TObjEneMe1Gee__resource_bundle->f42c->f8, 4)) + 4)) + 4);
    gee_resource_bundle_ptr = t + 4;
    TObjPlayer__sub_800F0928(t);
    {
        Q_800CC950 sp8 = lbl_8043BE6C;
        sp8.a = TObjEneMe1Gee__resource_bundle->f430;
        TLobby::spawn_npc_enemy((s16)0x10, TObjEneMe1Gee__resource_bundle->f42c->f8, TObjEneMe1Gee__resource_bundle->f42c->fc, (s32)&sp8, (f32)lbl_805DA150, (f32)TObjEneMe1Gee__data_805DA0C0);
    }
}

}

#undef bm_ene_me1_gee_resource_descriptor
#undef bm_ene_me1_gee_low_resource_descriptor
#pragma pop
