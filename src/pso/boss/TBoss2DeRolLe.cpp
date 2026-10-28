#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss2DeRolLe.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/misc/TBreakUpMdl.h"
#include "pso/TBoss2Tentacle.h"
#include "pso/TObjEZRopeBase.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss2Fin.h"
#include "pso/boss/TBoss2Joint.h"
#include "pso/boss/TBoss2Mine.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2CeilJunk.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"

#include <stddef.h>
#pragma push
namespace constructor_data {
extern "C" {
extern "C" void render_body__13TBoss2DeRolLeFv(u8 *arg0);
extern "C" void dispatch_action__13TBoss2DeRolLeFiUii(s32 arg0, u32 arg1, s32 arg2);
extern "C" void update_colliders_from_offsets__13TBoss2DeRolLeFi(s32 arg0);
extern "C" void vfunc_61__13TBoss2DeRolLeFv();
extern "C" void apply_damage_taken__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0);
extern "C" void vfunc_63__13TBoss2DeRolLeFv();
extern "C" void vfunc_28__13TBoss2DeRolLeFv();
extern "C" u8 *__dt__13TBoss2DeRolLeFv(u8 *arg0, s16 arg1);
extern "C" void apply_poison_status__13TBoss2DeRolLeFv();
extern "C" void apply_paralysis__13TBoss2DeRolLeFv();
extern "C" void apply_slow_status__13TBoss2DeRolLeFv();
extern "C" void apply_confusion_status__13TBoss2DeRolLeFv();
extern "C" void apply_movement_ailment__13TBoss2DeRolLeFl();
extern "C" void apply_shock_status__13TBoss2DeRolLeFv();
extern "C" void clear_harmful_statuses__13TBoss2DeRolLeFv();
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
extern "C" void vfunc_105__13TBoss2DeRolLeFv();
extern "C" void render__13TBoss2DeRolLeFv(u8 *arg0);
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_804806E8Fv();
extern "C" void vfunc_58__13TUnk_804806E8Fv();
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
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
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
extern "C" u8 lbl_80435710[];
extern "C" u8 lbl_8043572C[];
extern "C" u8 lbl_80435748[];
extern "C" u8 lbl_80435764[];
extern "C" u8 lbl_80435780[];
extern "C" u8 lbl_804357A0[];
extern "C" u8 lbl_804357B8[];
extern "C" u8 lbl_804357D0[];
extern "C" u8 lbl_804357E8[];
extern "C" u8 lbl_80435804[];
extern "C" u8 lbl_8043581C[];
extern "C" u8 lbl_80435834[];
extern "C" u8 lbl_8043584C[];
extern "C" u8 lbl_80435868[];
extern "C" u8 lbl_80435884[];
extern "C" u8 lbl_8043589C[];
extern "C" u8 lbl_804358B4[];
extern "C" u8 lbl_804358CC[];
extern "C" u8 lbl_804358E4[];
extern "C" u8 lbl_80435900[];
extern "C" u8 lbl_80435918[];
extern "C" u8 lbl_80435930[];
extern "C" u8 lbl_80435948[];
extern "C" u8 lbl_80435960[];
extern "C" u8 lbl_8043597C[];
extern "C" u8 lbl_80435998[];
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void run_task__13TBoss2DeRolLeFPv(u8 *arg0);
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_check__13TBoss2DeRolLeFPv(void *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
void *derolle_part_transform_template[12] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x40800000, (void *)0x0, (void *)0x0, (void *)0x41500000,
};
void *derolle_action_mode_sequence_table[44] = {
    (void *)0x1, (void *)0x3, (void *)0x18, (void *)0x6,
    (void *)0x11, (void *)0x9, (void *)0xc, (void *)0x12,
    (void *)0x14, (void *)0x16, (void *)0x3, (void *)0x6,
    (void *)0x11, (void *)0x9, (void *)0xd, (void *)0x19,
    (void *)0x8, (void *)0x10, (void *)0x4, (void *)0x13,
    (void *)0x15, (void *)0x17, (void *)0x9, (void *)0xf,
    (void *)0x21, (void *)0x22, (void *)0x1a, (void *)0x1b,
    (void *)0x1b, (void *)0x1b, (void *)0x1b, (void *)0x1c,
    (void *)0x23, (void *)0x24, (void *)0x25, (void *)0x21,
    (void *)0x22, (void *)0x1a, (void *)0x1b, (void *)0x1b,
    (void *)0x1b, (void *)0x1b, (void *)0x1d, (void *)0x2c,
};
void *derolle_action_sequence_table[50] = {
    (void *)0x1, (void *)0x28, (void *)0x29, (void *)0x2a,
    (void *)0x2b, (void *)0x22, (void *)0xd, (void *)0x25,
    (void *)0x21, (void *)0x28, (void *)0x27, (void *)0x29,
    (void *)0x2a, (void *)0x2b, (void *)0x27, (void *)0x22,
    (void *)0xf, (void *)0x21, (void *)0x28, (void *)0x27,
    (void *)0x28, (void *)0x27, (void *)0x28, (void *)0x22,
    (void *)0x1a, (void *)0x1b, (void *)0x1b, (void *)0x1b,
    (void *)0x1b, (void *)0x1b, (void *)0x1c, (void *)0xd,
    (void *)0x25, (void *)0x21, (void *)0x28, (void *)0x29,
    (void *)0x2a, (void *)0x2b, (void *)0x28, (void *)0x22,
    (void *)0x1a, (void *)0x1b, (void *)0x1b, (void *)0x1b,
    (void *)0x1b, (void *)0x1b, (void *)0x1b, (void *)0x1b,
    (void *)0x1d, (void *)0x2c,
};
void *TBoss2DeRolLe__shared_handler_id_table[3] = {
    (void *)0xf, (void *)0x10, (void *)0x11,
};
void *lbl_8048228C[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804822A8[33] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *bm_boss2_de_rol_le_model_names[8] = {
    (void *)&lbl_80435710, (void *)&lbl_8043572C, (void *)&lbl_80435748, (void *)&lbl_80435764,
    (void *)&lbl_80435780, (void *)&lbl_804357A0, (void *)&lbl_804357B8, (void *)0x0,
};
void *bm_boss2_de_rol_le_motion_names[19] = {
    (void *)&lbl_804357D0, (void *)&lbl_804357E8, (void *)&lbl_80435804, (void *)&lbl_8043581C,
    (void *)&lbl_80435834, (void *)&lbl_8043584C, (void *)&lbl_80435868, (void *)&lbl_80435884,
    (void *)&lbl_8043589C, (void *)&lbl_804358B4, (void *)&lbl_804358CC, (void *)&lbl_804358E4,
    (void *)&lbl_80435900, (void *)&lbl_80435918, (void *)&lbl_80435930, (void *)&lbl_80435948,
    (void *)&lbl_80435960, (void *)&lbl_8043597C, (void *)0x0,
};
void *boss2_derolle_bml_descriptor[4] = {
    (void *)&lbl_80435998, (void *)&bm_boss2_de_rol_le_model_names, (void *)&bm_boss2_de_rol_le_motion_names, (void *)0x70012,
};
void *lbl_804823A8[68] = {
    (void *)0x30000, (void *)0x8, (void *)0x3f4ccccd, (void *)0xc0000000,
    (void *)0x10000, (void *)0xb, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x20001, (void *)0xa, (void *)0x3e99999a, (void *)0x0,
    (void *)0x20001, (void *)0xe, (void *)0x3f000000, (void *)0x0,
    (void *)0x20001, (void *)0xc, (void *)0x3f000000, (void *)0x0,
    (void *)0x20009, (void *)0xf, (void *)0x3e8f5c29, (void *)0x0,
    (void *)0x2000a, (void *)0xd, (void *)0x3e8f5c29, (void *)0x0,
    (void *)0x10000, (void *)0x6, (void *)0x40000000, (void *)0x0,
    (void *)0x10000, (void *)0x5, (void *)0x40000000, (void *)0x0,
    (void *)0x30000, (void *)0x10, (void *)0x3f19999a, (void *)0x0,
    (void *)0x2000f, (void *)0x2, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3e99999a, (void *)0x0,
    (void *)0x20001, (void *)0x4, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x10000, (void *)0x1, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f333333, (void *)0x0,
};
void *boss2_derolle_particle_node_indices[3] = {
    (void *)0x0, (void *)0x5, (void *)0x9,
};
void *boss2_derolle_particle_limits[3] = {
    (void *)0x42000000, (void *)0x41f00000, (void *)0x41f00000,
};
void *__vt__13TBoss2DeRolLe[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TBoss2DeRolLeFv, (void *)&run_task__13TBoss2DeRolLeFPv,
    (void *)&render__13TBoss2DeRolLeFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TBoss2DeRolLeFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TBoss2DeRolLeFv, (void *)&apply_paralysis__13TBoss2DeRolLeFv, (void *)&apply_slow_status__13TBoss2DeRolLeFv, (void *)&apply_confusion_status__13TBoss2DeRolLeFv,
    (void *)&apply_movement_ailment__13TBoss2DeRolLeFl, (void *)&apply_shock_status__13TBoss2DeRolLeFv, (void *)&clear_harmful_statuses__13TBoss2DeRolLeFv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TBoss2DeRolLeFv, (void *)&apply_damage_taken__13TBoss2DeRolLeFPv, (void *)&vfunc_63__13TBoss2DeRolLeFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__13TBoss2DeRolLeFiUii,
    (void *)&update_colliders_from_offsets__13TBoss2DeRolLeFi, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&update_check__13TBoss2DeRolLeFPv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&vfunc_105__13TBoss2DeRolLeFv, (void *)&render_body__13TBoss2DeRolLeFv,
};

}
}
#pragma pop

#include <stddef.h>
#pragma push

typedef struct Vec_8002EA64 {
    f32 x, y, z;
} Vec_8002EA64;

typedef struct Part_8002EA64 {
    Vec_8002EA64 pos;
    Vec_8002EA64 vel;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
    s32 unk28;
} Part_8002EA64;

typedef struct Obj_8002EA64 {
    u8 pad0[0x18];
    s32 *vtbl;
    u8 pad1C[4];
    Part_8002EA64 parts[19];
} Obj_8002EA64;

struct Vec_8002EFE8 { s32 x, y, z; };

struct Motion_8002EFE8 { s32 f0; s32 anim; s32 f8; s32 fC; };

struct Model_8002EFE8 { s32 f0; u32 frames; };

struct Anim_8002EFE8 { s32 f0; Model_8002EFE8 *model; };

struct Self_8002EFE8 {
    u8 pad0[0x24];
    s32 x24;
    u8 pad28[0x34 - 0x28];
    s32 x34;
    u8 pos[0xC];
    u8 pad44[0x5C - 0x44];
    s32 rotX;
    s32 rotY;
    s32 rotZ;
    u8 pad68[0xC0 - 0x68];
    f32 frame;
    u8 padC4[0xD8 - 0xC4];
    Motion_8002EFE8 *motions;
    Anim_8002EFE8 *anims;
    u8 padE0[0x354 - 0xE0];
    f32 motionIdx;
    f32 fixedFrame;
    f32 speed;
    u8 pad360[0x5E0 - 0x360];
    s32 joints[10];
};

extern "C" {
int alloc__23TAdSinglePlyChrSelectGCFv(void *);
extern u8 *lbl_805D4BA4;
void TObjPlayer__sub_8002E7C8(void);
void queue_destruction__7TObjectFv(void *arg0);
s32 create_particle__17TObjBoss2CeilJunkFv(void *, s32);
f32 vec3_add_to(void *, void *);
void scale_matrix(int, f32, f32, f32);
void set_matrix_identity(int);
void push_matrix(void);
s32 pop_matrix(void);
extern const f32 lbl_805D8260;
void VecCopy__FP3VecPC3Vec(void *, void *);
void fn_8002F5AC(u8 *arg0);
void TBoss2Joint__sub_8003688C(u8 *arg0);
s32 TObjLight__sub_801337F8(s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, int);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
void TObjPlayer__sub_8002F61C(void);
extern Vec_8002EFE8 lbl_804359E4;
extern u8 controller_input_state[];
extern s32 current_scene_light;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D8278;
extern const f32 TBoss2DeRolLe__data_805D827C;
void render_body__13TBoss2DeRolLeFv(u8 *arg0);
struct VObj8002EB88_8002eb88_8002E784 {
    char pad[0xC];
    virtual void m0(int);
};

int vfunc_105__13TBoss2DeRolLeFv(void* p);
void TObjPlayer__sub_8002EB88(void);
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

struct VObj8002EB88_8002eb88_8002E784;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on

#pragma pop

#pragma push
#pragma opt_common_subs off
void TBoss2DeRolLe::render_body() {
    Self_8002EFE8 *self = (Self_8002EFE8 *)this;
    s32 i;
    Model_8002EFE8 *model;
    s32 idx;
    f32 frame;
    f32 max;
    this->update_object_view_visibility(lbl_805D8278, lbl_805D8278);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, self->rotX);
    rotate_matrix_z(0, this->rotation_z);
    Vec_8002EFE8 scale = lbl_804359E4;
    TObjEneDD::check_v2_mode();
    scale_current_matrix(&scale);
    for (i = 0; i < 10; i++) {
        TBoss2Joint__sub_8003688C((u8 *)self->joints[i]);
    }
    idx = self->motionIdx;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 0x11) {
        idx = 0x10;
    }
    model = self->anims[self->motions[idx].anim].model;
    if (is_on_current_screen__11TCameraCtrlFv(controller_input_state + 0xC0, 4) != 0) {
        max = model->frames - 1;
        this->m_c0 = this->m_c0 + self->speed;
        while (this->m_c0 < TBoss2DeRolLe__data_805D827C) {
            this->m_c0 = this->m_c0 + max;
        }
        while (this->m_c0 > max) {
            this->m_c0 = this->m_c0 - max;
        }
        frame = this->m_c0;
    } else {
        frame = self->fixedFrame;
        if (frame < TBoss2DeRolLe__data_805D827C) {
            frame = TBoss2DeRolLe__data_805D827C;
        } else if (frame > (model->frames - 1)) {
            frame = model->frames;
        }
    }
    fn_8002F5AC((u8 *)self);
    TObjEneRe7Berura::set_global_state((s32)TObjPlayer__sub_8002F61C);
    TObjFish::set_global_param(this->texture_id);
    draw_model_motion((void *)self->x34, (void *)model, (f32)frame);
    TObjEneRe7Berura::set_global_state((s32)NULL);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
}
#pragma pop

int TBoss2DeRolLe::vfunc_105() { return this->get_target_info(); }

}

#pragma pop

#pragma push

struct VBase_18_3a6650 { char pad[0x18]; };
struct VObj_18_3a6650 : VBase_18_3a6650 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
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
    virtual s32 m104();
};

struct Vec_8002F258 { f32 x, y, z; };
struct Vec4_8002F258 { f32 x, y, z, w; };
struct Light_8002F258 { u8 pad0[0x24]; Vec4_8002F258 col; };
struct Ctx_8002F258 { u8 pad0[0x2C]; void *tex; };
struct Me_8002F258 : VObj_18_3a6650 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    Vec_8002F258 pos;
    u8 pad44[0x5C - 0x44];
    s32 rx;
    s32 ry;
    s32 rz;
    u8 pad68[0x3C0 - 0x68];
    s32 flags;
    u8 pad3c4[0x3D8 - 0x3C4];
    u8 nodes[0x3F8 - 0x3D8];
    Vec_8002F258 pts[20];
    u8 pad4e8[0x540 - 0x4E8];
    Vec_8002F258 mids[10];
    u8 pad5b8[0x5E0 - 0x5B8];
    s32 joints[10];
    u8 pad608[0x6A4 - 0x608];
    f32 height;
};

extern "C" {

void update_pulsing_colors__13TBoss2DeRolLeFPv(u8 *arg0);
s32 TObjLight__sub_801336DC(s32);
s32 TObjLight__sub_8013379C(s32, void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
extern Vec_8002F258 lbl_804359D8[];
extern u8 derolle_segment_texture_slots[];
extern Light_8002F258 TObjLight__scene_light_state;
extern Ctx_8002F258 *derolle_texture_list_handle;
extern void *lbl_805D4BCC;
extern s32 lbl_805D5564;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;

void TBoss2DeRolLe::render() {
    Me_8002F258 *e = (Me_8002F258 *)this;
    Vec4_8002F258 *col;
    s32 i;
    Vec_8002F258 *out;

    if (this->get_target_info() != 0) {
        e->m104();
        return;
    }
    e->m8(1000.0f, 1000.0f);
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    TObjEneDD::clear_global_flag_400();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&e->pos);
    translate_matrix(0, 0.0f, e->height, 0.0f);
    rotate_matrix_y(0, e->ry);
    rotate_matrix_x(0, e->rx);
    rotate_matrix_z(0, e->rz);
    {
        Vec_8002F258 sc = lbl_804359D8[0];
        scale_current_matrix(&sc);
    }
    update_pulsing_colors__13TBoss2DeRolLeFPv(((u8 *)this));
    for (i = 0; i < 10; i++) {
        TBoss2Joint__sub_8003688C((u8 *)e->joints[i]);
    }
    if (e->flags & 0x40) {
        derolle_texture_list_handle->tex = derolle_segment_texture_slots;
    } else {
        derolle_texture_list_handle->tex = lbl_805D4BCC;
    }
    fn_8002F5AC(((u8 *)this));
    TObjFish::set_global_param(e->f24);
    TObjEneRe7Berura::set_global_state((s32)((void *)TObjPlayer__sub_8002F61C));
    {
    Vec4_8002F258 saved;
    col = &TObjLight__scene_light_state.col;
    ((TRaderMapCore *)(&saved))->copy_vec4(col);
    if (TObjBoss2Tunnel::is_active() != 0) {
        TObjLight__scene_light_state.col.y = 0.3f;
        TObjLight__scene_light_state.col.z = 0.4f;
        TObjLight__scene_light_state.col.w = 0.5f;
        TObjLight__sub_8013379C(current_scene_light, &TObjLight__scene_light_state);
        TObjLight__sub_801336DC(lbl_805D5564);
    }
    this->draw();
    ((TRaderMapCore *)col)->copy_vec4(&saved);
    }
    TObjEneRe7Berura::set_global_state((s32)NULL);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    {
    Vec_8002F258 v;
    out = e->mids;
    VecCopy__FP3VecPC3Vec(&v, &e->pts[0]);
    vec3_add_to(&v, &e->pts[9]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy__FP3VecPC3Vec(out, &v);
    VecCopy__FP3VecPC3Vec(&v, &e->pts[9]);
    vec3_add_to(&v, &e->pts[11]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy__FP3VecPC3Vec(out + 1, &v);
    out += 2;
    for (i = 0; i < 8; i++) {
        VecCopy__FP3VecPC3Vec(&v, &e->pts[i + 11]);
        vec3_add_to(&v, &e->pts[i + 12]);
        v.x *= 0.5f;
        v.y *= 0.5f;
        v.z *= 0.5f;
        VecCopy__FP3VecPC3Vec(out, &v);
        out++;
    }
    }
    ((TObject *)(e->nodes))->render_nodes();
}

#pragma pop

#pragma push

void TRaderMapCore::copy_vec4(void* q) { *(f32*)((char*)this + 0x0) = *(f32*)((char*)q + 0x0); *(f32*)((char*)this + 0x4) = *(f32*)((char*)q + 0x4); *(f32*)((char*)this + 0x8) = *(f32*)((char*)q + 0x8); *(f32*)((char*)this + 0xc) = *(f32*)((char*)q + 0xc); }

}

#pragma pop

#pragma push

struct RecoveredGlobal_8002F5AC_lbl_804FE30C {
    s32 value;
    u8 remaining[0xC];
};

extern RecoveredGlobal_8002F5AC_lbl_804FE30C lbl_804FE30C;
extern s32 TBoss2DeRolLe__current_attack_id;
extern s32 TBoss2DeRolLe__sequence_match_index;
extern s32 lbl_805D4BB0;
extern u8 *lbl_805D4BB4;
extern u8 *lbl_805D4BB8;
extern s32 lbl_805D4BBC;
extern s32 lbl_805D4BC0;
typedef char RecoveredGlobal_8002F5AC_lbl_804FE30C_size[sizeof(RecoveredGlobal_8002F5AC_lbl_804FE30C) == 0x10 ? 1 : -1];
void fn_8002F5AC(u8 *arg0) {
    TBoss2DeRolLe__current_attack_id = 0;
    ((TRaderMapCore *)(&lbl_804FE30C.value))->copy_vec4((arg0 + 0x608));
    lbl_805D4BB0 = *(s32 *)((s8 *)arg0 + 0x3C0);
    TBoss2DeRolLe__sequence_match_index = 0;
    lbl_805D4BB4 = arg0 + 0x3F8;
    lbl_805D4BBC = *(s32 *)((s8 *)arg0 + 0x61C);
    lbl_805D4BC0 = *(s32 *)((s8 *)arg0 + 0x618);
    lbl_805D4BB8 = arg0 + 0x4E8;
}

#pragma pop

#pragma push
void get_current_matrix(void *m);
namespace joint_transform_view {

struct RecoveredGlobal_8002F61C_lbl_80435628 {
    s32 value;
    u8 remaining[0x50];
};

struct RecoveredGlobal_8002F61C_lbl_804820D8 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_8002F61C_lbl_804FE31C {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
void update_camera_sequence__9TObjEneDDFv(void);
s32 mult_vec_array__10TObjPlayerFUll(int, void *, void *, int);
s32 subtract_vector(void *, void *);
s32 push_matrix();
s32 pop_matrix();
extern RecoveredGlobal_8002F61C_lbl_80435628 derolle_attack_sequence_id_table;
extern RecoveredGlobal_8002F61C_lbl_804820D8 derolle_part_transform_template;
extern RecoveredGlobal_8002F61C_lbl_804FE31C lbl_804FE31C;
extern s32 TBoss2DeRolLe__current_attack_id;
extern s32 TBoss2DeRolLe__sequence_match_index;
extern s32 lbl_805D4BB0;
extern s32 lbl_805D4BB4;
extern s32 lbl_805D4BB8;
extern s32 lbl_805D4BBC;
extern s32 lbl_805D4BC0;
void TObjPlayer__sub_8002F61C(void);
typedef char RecoveredGlobal_8002F61C_lbl_80435628_size[sizeof(RecoveredGlobal_8002F61C_lbl_80435628) == 0x54 ? 1 : -1];
typedef char RecoveredGlobal_8002F61C_lbl_804820D8_size[sizeof(RecoveredGlobal_8002F61C_lbl_804820D8) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_8002F61C_lbl_804FE31C_size[sizeof(RecoveredGlobal_8002F61C_lbl_804FE31C) == 0xC ? 1 : -1];
void TObjPlayer__sub_8002F61C(void) {
    if ((s32) TBoss2DeRolLe__current_attack_id == (s32) *(s32 *)((s8 *)&derolle_attack_sequence_id_table.value + (TBoss2DeRolLe__sequence_match_index * 4))) {
        get_camera_ctrl__9TObjEneDDFv((s32) &lbl_804FE31C.value, lbl_805D4BB4);
        TBoss2DeRolLe__sequence_match_index += 1;
        lbl_805D4BB4 += 0xC;
    }
    if ((s32) TBoss2DeRolLe__current_attack_id == 0x33) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        mult_vec_array__10TObjPlayerFUll(0, (void *)&derolle_part_transform_template.value, (void *)lbl_805D4BB8, 4);
        pop_matrix();
        subtract_vector((void *)(lbl_805D4BB8 + 0xC), (void *)lbl_805D4BB8);
    }
    if ((lbl_805D4BB0 & 0x80) && ((s32) TBoss2DeRolLe__current_attack_id >= 0x4D) && ((s32) TBoss2DeRolLe__current_attack_id <= 0x58)) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        get_current_matrix((void *)lbl_805D4BC0);
        pop_matrix();
        lbl_805D4BC0 += 0x30;
    }
    if (((s32) TBoss2DeRolLe__current_attack_id >= 0x1D) && ((s32) TBoss2DeRolLe__current_attack_id <= 0x20)) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        get_current_matrix((void *)lbl_805D4BBC);
        pop_matrix();
        lbl_805D4BBC += 0x30;
    }
    TBoss2DeRolLe__current_attack_id += 1;
}

}

}
#pragma pop

#pragma push
namespace behavior_view {

struct Obj_80034034;
struct Obj_800341F0;
struct Vec_800310F8 { f32 x, y, z; };

struct Self_800310F8 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x390 - 0xBA];
    u8 *f390;
    u8 pad394[0x3C0 - 0x394];
    s32 flags;
    u8 pad3C4[0x620 - 0x3C4];
    void *parts[4];
    u8 pad630[0x654 - 0x630];
    s32 dir;
    u8 pad658[0x6E0 - 0x658];
    s32 phase;
    s32 timer;
    s32 idx;
    s32 limit;
    s32 life;
};

struct DR_800327C8 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0x3C0 - 0xBA];
    u32 flags;
    u8 pad3C4[0x654 - 0x3C4];
    s32 mode;
    s32 sub;
    u8 pad65C[0x67C - 0x65C];
    f32 ampX;
    u8 pad680[0x69C - 0x680];
    f32 ampZ;
    u8 pad6A0[0x6E0 - 0x6A0];
    s32 done;
    s32 kind;
    u8 pad6E8[0x6FC - 0x6E8];
    f32 baseX;
    f32 baseZ;
    f32 scaleX;
    f32 scaleZ;
};

struct Obj_80034258;
struct VBase_18_8002F7C4 { char pad[0x18]; };

struct VObj_18_8002F7C4 : VBase_18_8002F7C4 {
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
    virtual void m72(s32);
};

struct Vec_8002F7C4 { f32 x, y, z; };

struct Cam_8002F7C4 { s8 a; s8 b; s16 c; f32 d; f32 e; };

struct Sub_8002F7C4 { u8 pad0[8]; u32 f8; };

struct Rol_8002F7C4 : VObj_18_8002F7C4 {
    u8 pad1C[0x30 - 0x1C];
    u32 flags30;
    u8 pad34[0x38 - 0x34];
    Vec_8002F7C4 pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    u8 pad60[0xB8 - 0x60];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    Sub_8002F7C4 *f3CC;
    u8 pad3D0[0x540 - 0x3D0];
    Vec_8002F7C4 pts[10];
    u8 pad5B8[0x5E0 - 0x5B8];
    s32 slots[10];
    u8 pad608[0x620 - 0x608];
    s32 tent[4];
    u8 pad630[0x654 - 0x630];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[4];
    s32 f6AC;
    u8 pad6B0[0x6E0 - 0x6B0];
    s32 f6E0;
    s32 f6E4;
    u8 pad6E8[0x6F4 - 0x6E8];
    s32 f6F4;
    u8 pad6F8[0x758 - 0x6F8];
    s32 f758;
};

struct Vec_80032E38 { f32 x, y, z; };

struct Cam_80032E38 { s8 a; s8 b; s16 c; f32 d; f32 e; };

struct Play_80032E38 { u16 h0; u16 h2; };

struct Rol_80032E38 {
    u8 pad0[0x38];
    Vec_80032E38 pos;
    u8 pad44[0x64 - 0x44];
    s32 f64;
    u8 pad68[0xB8 - 0x68];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3A0 - 0xC4];
    f32 f3A0;
    u8 pad3A4[0x3A8 - 0x3A4];
    f32 f3A8;
    f32 f3AC;
    u8 pad3B0[0x3C0 - 0x3B0];
    u32 f3C0;
    u8 pad3C4[0x654 - 0x3C4];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    u8 pad6EC[0x6FC - 0x6EC];
    f32 f6FC;
    u8 pad700[0x724 - 0x700];
    Vec_80032E38 f724;
};

struct V_800320B4 { f32 x, y, z; };

struct R_800320B4 { f32 x, y, z; };

struct D_800320B4 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB0 - 0x44];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x3C0 - 0xC4];
    u32 flags;
    u8 pad3C4[0x518 - 0x3C4];
    u8 snd[0x540 - 0x518];
    R_800320B4 recs[10];
    u8 pad5B8[0x654 - 0x5B8];
    s32 mode;
    s32 next_mode;
    u8 pad65C[0x684 - 0x65C];
    u8 mover[0x694 - 0x684];
    f32 f694;
    u8 pad698[0x69C - 0x698];
    f32 f69C;
    u8 pad6A0[0x6A4 - 0x6A0];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 phase;
    s32 f6E4;
    s32 step;
    s32 tick;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 dir;
    f32 f700;
    f32 f704;
    f32 vy;
    f32 vx;
    f32 ay;
};

typedef struct Vec_800344A4 {
    f32 x, y, z;
} Vec_800344A4;
typedef struct DeRolLe_800344A4 {
    u8 pad0[0x3D8];
    u8 unk3D8[0x540 - 0x3D8];
    Vec_800344A4 pts[8];
    u8 pad5A0[0x5E0 - 0x5A0];
    void *joints[8];
    u8 pad600[0x654 - 0x600];
    s32 mode;
} DeRolLe_800344A4;

struct Vec_80033AA4 { f32 x, y, z; };

struct Vec3i_80033AA4 { s32 x, y, z; };

struct Obj_80033AA4 {
    u8 pad0[0x540];
    Vec_80033AA4 pos[42];
    u8 pad738[8];
    void *ctl[6];
    s32 f758;
};

struct Vec_800313F8 { f32 x, y, z; };

struct Sub_800313F8 { u8 pad0[8]; u32 f8; };

struct DR_800313F8 {
    u8 pad0[0x38];
    Vec_800313F8 pos;
    u8 pad44[0x64 - 0x44];
    s32 f64;
    u8 pad68[0xB0 - 0x68];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    Sub_800313F8 *f3CC;
    u8 pad3D0[0x44C - 0x3D0];
    Vec_800313F8 v44C;
    Vec_800313F8 v458;
    u8 pad464[0x4E8 - 0x464];
    Vec_800313F8 v4E8;
    u8 pad4F4[0x518 - 0x4F4];
    u8 snd[0x620 - 0x518];
    s32 tentacles[4];
    u8 pad630[0x654 - 0x630];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    s32 f6EC;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 f6FC;
    f32 f700;
    f32 f704;
    f32 f708;
    f32 f70C;
    f32 f710;
    f32 f714;
    f32 f718;
    u8 pad71C[0x73C - 0x71C];
    void *f73C;
};

struct Vec_8002FE60 { f32 x, y, z; };

struct Inst_8002FE60 { u32 w[5]; };

struct D_8002FE60 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x390 - 0xC4];
    u8 *target;
    u8 pad394[0x3C0 - 0x394];
    u32 flags;
    u8 pad3C4[0x4E8 - 0x3C4];
    Vec_8002FE60 pos;
    Vec_8002FE60 dir;
    u8 pad500[0x518 - 0x500];
    u8 snd[0x654 - 0x518];
    s32 mode;
    u8 pad658[0x6C8 - 0x658];
    s32 f6C8;
    void *laser1;
    void *laser2;
    u8 pad6D4[0x6DC - 0x6D4];
    s32 count;
    s32 phase;
    s32 timer;
    s32 f6E8;
    u8 pad6EC[0x6F4 - 0x6EC];
    s32 f6F4;
    u8 pad6F8[0x6FC - 0x6F8];
    f32 speed;
    f32 f700;
    u8 pad704[0x724 - 0x704];
    Vec_8002FE60 vel;
    Vec_8002FE60 hit;
    void *ptcl;
    u8 pad740[0x758 - 0x740];
    s32 f758;
};

extern "C" {
u8 TBoss2DeRolLe__sub_80034574(u8 *arg0);
void init_wave_params__13TBoss2DeRolLeFPv(u8 *arg0);
u8 update_state__13TBoss2DeRolLeFPv(u8 *arg0);
void init_move_params__13TBoss2DeRolLeFPv(u8 *arg0);
u8 TBoss2DeRolLe__sub_80034800(u8 *arg0);
void init_movement__13TBoss2DeRolLeFPv(u8 *arg0);
u8 update_phase_is_done__13TBoss2DeRolLeFPv(u8 *arg0);
void TBoss2DeRolLe__sub_800344A4(DeRolLe_800344A4 *self, s32 idx, s32 arg2);
s32 VecCopy__FP3VecPC3Vec(int, void *);
f32 fabs_float(f32);
void TBoss2DeRolLe__sub_80033A80(s32 arg0, s32 arg1);
void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4);
extern s32 boss2_derolle_particle_node_indices[];
extern f32 boss2_derolle_particle_limits[];
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 lbl_805D82E0;
extern const f32 TBoss2DeRolLe__data_805D8328;
void update_particle_ctrls__13TBoss2DeRolLeFPv(Obj_80033AA4 *o);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 VecCopy__FP3VecPC3Vec(int, void *);
void queue_destruction__7TObjectFv(void *);
int play_sound(void* p, int a1);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
void TObjBoss2Tunnel__sub_8003C5F8(void);
void TObjBoss2Tunnel__sub_8003C610(void);
void *create_particle_emitter(void *pos, s32 id);
s32 objInBand__FP7GameObjf(void *, f32);
void advance_animation_playback(void *);
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 TBoss2DeRolLe__data_805D829C;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82B4;
extern const f32 TBoss2DeRolLe__data_805D82B8;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 lbl_805D82D0;
extern const f32 TBoss2DeRolLe__data_805D82D8;
extern const f32 TBoss2DeRolLe__data_805D82DC;
extern const f32 TBoss2DeRolLe__data_805D82E4;
extern const f32 lbl_805D8304;
extern const f32 TBoss2DeRolLe__data_805D832C;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 lbl_805D834C;
extern const f32 lbl_805D8350;
extern const f32 lbl_805D8354;
extern const f32 TBoss2DeRolLe__data_805D8358;
extern const f32 lbl_805D835C;
extern const f32 lbl_805D8360;
extern const f32 lbl_805D8364;
extern const f32 lbl_805D8368;
extern const f32 lbl_805D836C;
extern const f32 lbl_805D8370;
void TBoss2DeRolLe__sub_800313F8(DR_800313F8 *o, u32 arg1, s32 arg2);
s32 VecCopy__FP3VecPC3Vec(int, void *);
f32 atan2_float(f32, f32);
void queue_destruction__7TObjectFv(void *);
s32 get_flag_b4__9TObjEneDDFv(void *);
void fill_value_array(s32);
int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2);
int play_sound(void* p, int a1);
void pick_random_target__13TBoss2DeRolLeFi(s32 arg0);
void free_laser__13TBoss2DeRolLeFPv(void *arg0, s32);
void activate_laser_light__13TBoss2DeRolLeFPv(void *arg0);
void calc_offset_position__13TBoss2DeRolLeFPv(u8 *arg0);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
void push_trail_position__13TBoss2DeRolLeFPvPv(void *, void *);
void *__ct__13TUnk_80482C58FP7TObjectll(void *, void *, int, int);
u8 *csnVector(void *, void *, int);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void advance_animation_playback(void *);
void *__nw__7TObjectFUl(u32);
s32 vec3_add_to(int, void *);
void subtract_vector(void *, void *);
extern Inst_8002FE60 lbl_804356FC[];
extern const f64 lbl_80435A10[];
extern u8 *TBoss2DeRolLe__data_805D4BA0;
void TBoss2DeRolLe__sub_8002FE60(void *arg0, u32 arg1);
u32 __cvt_fp2unsigned(f32);
extern u32 *boss2_derolle_primary_color_targets[];
extern u32 *boss2_derolle_segment_color_targets[];
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D8328;
extern const f32 TBoss2DeRolLe__data_805D8334;
extern const f32 lbl_805D842C;
void update_pulsing_colors__13TBoss2DeRolLeFPv(u8 *arg0);
#define TBoss2DeRolLe__sub_80034574 ((s32 (*)(void *))TBoss2DeRolLe__sub_80034574)
#define init_wave_params__13TBoss2DeRolLeFPv ((s32 (*)(void *))init_wave_params__13TBoss2DeRolLeFPv)
#define update_state__13TBoss2DeRolLeFPv ((s32 (*)(void *))update_state__13TBoss2DeRolLeFPv)
#define init_move_params__13TBoss2DeRolLeFPv ((s32 (*)(void *))init_move_params__13TBoss2DeRolLeFPv)
#define TBoss2DeRolLe__sub_80034800 ((s32 (*)(void *))TBoss2DeRolLe__sub_80034800)
#define init_movement__13TBoss2DeRolLeFPv ((s32 (*)(void *))init_movement__13TBoss2DeRolLeFPv)
#define update_phase_is_done__13TBoss2DeRolLeFPv ((s32 (*)(void *))update_phase_is_done__13TBoss2DeRolLeFPv)
#define TBoss2DeRolLe__sub_800344A4 ((s32 (*)(void *, int, int))TBoss2DeRolLe__sub_800344A4)
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 VecCopy__FP3VecPC3Vec(int, void *);
void pick_random_target__13TBoss2DeRolLeFi(s32 arg0);
void advance_animation_playback(void *);
void set_move_direction__13TBoss2DeRolLeFPv(void *, s32);
s32 get_random_scaled__9TObjEneDDFv(void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 TBoss2Tentacle__sub_80039CA0(void *);
void TBoss2Tentacle__sub_80039E68(void *);
extern u8 *TBoss2DeRolLe__data_805D4BA0;
extern const f32 lbl_805D8340;
extern const f32 lbl_805D8344;
void TBoss2DeRolLe__sub_800310F8(void *arg0, void *arg1, int arg2);
void TBoss2DeRolLe__sub_800338BC(void);
s32 init_head_params__13TBoss2DeRolLeFPv(void *);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
void advance_animation_playback(void *);
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D832C;
void TBoss2DeRolLe__sub_800327C8(void *arg0, void *arg1, int arg2, int arg3);
void assign_slots_from_list(void *, s32);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 VecCopy__FP3VecPC3Vec(int, void *);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
void TBoss2Tentacle__sub_80039E54(void *a0);
s32 restore_player_cameras();
s32 activate_camera_mode(int);
void set_scripted_camera_pose(void *, void *, void *);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 objInBand__FP7GameObjf(void *, f32);
void advance_animation_playback(void *);
int play_sound_effect(void*, int, int, int);
void play_cue_stream_file(s32 name);
f32 cos_table_lookup(s32);
extern const char lbl_804359F8[] = "deldeath.adx";
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 lbl_805D828C;
extern const f32 lbl_805D8290;
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 lbl_805D8298;
extern const f32 TBoss2DeRolLe__data_805D829C;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82AC;
extern const f32 lbl_805D82B0;
extern const f32 TBoss2DeRolLe__data_805D82B4;
extern const f32 TBoss2DeRolLe__data_805D82B8;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 lbl_805D82C0;
extern const f32 lbl_805D82C4;
extern const f32 lbl_805D82C8;
void handle_death_state__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
s32 VecCopy__FP3VecPC3Vec(int, void *);
s32 activate_camera_mode(int);
void set_move_target_point__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
s32 vec3_add_to(int, void *);
void advance_animation_playback(void *);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
s32 objInBand__FP7GameObjf(void *, f32);
int play_sound_effect(void*, int, int, int);
s32 get_flag_b4__9TObjEneDDFv(void *);
Play_80032E38 *get_scripted_camera_playback(void);
s32 restore_player_cameras();
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D82D8;
extern const f32 TBoss2DeRolLe__data_805D82DC;
extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 lbl_805D82F4;
extern const f32 lbl_805D8340;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 lbl_805D83E4;
extern const f32 lbl_805D83F0;
extern const f32 lbl_805D8408;
extern const f32 lbl_805D840C;
extern const f32 lbl_805D8410;
extern const f32 lbl_805D8414;
extern const f32 lbl_805D8418;
extern const f32 lbl_805D841C;
extern const f32 lbl_805D8420;
extern const f32 lbl_805D8424;
extern const f32 lbl_805D8428;
void TBoss2DeRolLe__sub_80032E38(void *arg0, void *arg1);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 VecCopy__FP3VecPC3Vec(int, void *);
f32 fabs_float(f32);
int play_sound(void* p, int a1);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
void update_angle__13TBoss2DeRolLeFPv(void *arg0);
f32 calc_node_height__13TBoss2DeRolLeFPv(void *);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
s32 advance_scalar_motion_profile(void *);
void set_move_params__13TBoss2DeRolLeFPvffff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 objInBand__FP7GameObjf(void *, f32);
void advance_animation_playback(void *);
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 TBoss2DeRolLe__data_805D829C;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D82E4;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D832C;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 TBoss2DeRolLe__data_805D8358;
extern const f32 lbl_805D8368;
extern const f32 TBoss2DeRolLe__data_805D83AC;
extern const f32 lbl_805D83B0;
extern const f32 lbl_805D83B4;
extern const f32 lbl_805D83B8;
extern const f32 lbl_805D83BC;
extern const f32 lbl_805D83C0;
extern const f32 lbl_805D83C4;
extern const f32 lbl_805D83C8;
extern const f32 lbl_805D83CC;
extern const f32 lbl_805D83D0;
extern const f32 lbl_805D83D4;
extern const f32 lbl_805D83D8;
extern const f32 TBoss2DeRolLe__data_805D83DC;
extern const f32 lbl_805D83E0;
extern const f32 lbl_805D83E4;
extern const f32 lbl_805D83E8;
extern const f32 lbl_805D83EC;
extern const f32 lbl_805D83F0;
extern const f32 lbl_805D83F4;
extern const f32 lbl_805D83F8;
void TBoss2DeRolLe__sub_800320B4(void *arg0, void *arg1, int arg2, int arg3);
struct Stack_800339BC {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_800339BC_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

struct Obj_80034034 { u8 pad[0x326]; s16 f326; };

struct Obj_800333F4 { u8 pad0[0xB8]; s16 f_B8; };

struct Obj_8002F73C { u8 pad0[0xB8]; s16 fB8; u8 pad1[0x3C0 - 0xBA]; u32 f3C0; };

struct Obj_8002FCE4 {
    u8 pad0[0x5C];
    s32 f5C;
    u8 pad1[0xB8 - 0x60];
    s16 fB8;
    u8 pad2[0x3C0 - 0xBA];
    u32 f3C0;
    u8 pad3[0x6A4 - 0x3C4];
    f32 f6A4;
};

typedef struct DeRolLe_8002FD9C {
    u8 pad0[0xB8];
    s16 state;
    u8 padBA[0x3C0 - 0xBA];
    s32 flags;
    u8 pad3C4[0x654 - 0x3C4];
    s32 mode;
} DeRolLe_8002FD9C;

struct Vec_80030720 { f32 x, y, z; };

struct Obj_80030720 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x390 - 0xBA];
    s32 f390;
    u8 pad394[0x3C0 - 0x394];
    u32 f3C0;
    u8 pad3C4[0x4D0 - 0x3C4];
    u8 f4D0[0x524 - 0x4D0];
    u8 f524[0x630 - 0x524];
    s32 f630[5];
    s32 f644[3];
    u8 pad650[4];
    s32 f654;
};

struct Obj_80034034;

typedef char RecoveredGlobal_800339BC_lbl_804FF5E8_size[sizeof(RecoveredGlobal_800339BC_lbl_804FF5E8) == 0x28 ? 1 : -1];

struct VBase_800341F0 { char pad[0x18]; };

struct V_800341F0 : VBase_800341F0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5();
    virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17();
    virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41();
    virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53();
    virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65();
    virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76(); virtual void m77();
    virtual void m78(); virtual void m79(); virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94();
};

struct Obj_800341F0 : V_800341F0 {
    u8 pad1c[0x5e0 - 0x1c];
    V_800341F0 *parts[10];
};

struct B_80034258 { u8 pad[0x18]; };

struct V_80034258 : B_80034258 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
};

struct Obj_80034258 : V_80034258 {
    u8 pad2[0x5e0 - 0x1c];
    V_80034258 *parts[10];
};

struct Vec_80030588 { f32 x, y, z; };

struct Rec_80030898 { f32 a; f32 b; f32 c; };

struct Obj_80030898 { u8 pad0[0x544]; Rec_80030898 recs[8]; };

f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 VecCopy__FP3VecPC3Vec(int, void *);
int get_player_data__10TObjPlayerFi(int a0);
void queue_destruction__7TObjectFv(void *);
s32 get_flag_b4__9TObjEneDDFv(void *);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
void TBoss2DeRolLe__sub_8002F73C(Obj_8002F73C *self, u32 kind);
void TBoss2DeRolLe__sub_8002FCE4(Obj_8002FCE4 *self, u32 kind);
void TBoss2DeRolLe__sub_8002FD9C(DeRolLe_8002FD9C *self, u32 arg1, s32 arg2);
void state_ceiling_attack__13TBoss2DeRolLeFPvUi(u8 *arg0, u32 arg1);
void TBoss2DeRolLe__sub_80030720(Obj_80030720 *self, u32 arg1, s32 arg2);
void TBoss2DeRolLe__sub_80030898(u8 *arg0, u32 arg1, s32 arg2);
void TBoss2DeRolLe__sub_80030A38(u8 *arg0, u32 arg1);
void TBoss2DeRolLe__sub_80030DFC(void *, void *, int);
void TBoss2DeRolLe__sub_80031AD4(void *, void *);
void handle_debug_pad_input__13TBoss2DeRolLeFPvPv(void *, void *);
void TBoss2DeRolLe__sub_800333F4(Obj_800333F4 *self, u32 arg1);
void dispatch_action__13TBoss2DeRolLeFiUii(s32 arg0, u32 arg1, s32 arg2);
void advance_phase_wrap__13TBoss2DeRolLeFPv(u8 *arg0);
int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2);
int play_sound(void* p, int a1);
void TBoss2DeRolLe__sub_800338BC(void);
void update_projectile_spawns__13TBoss2DeRolLeFPv(u8 *arg0);
void spawn_offset_particle__13TBoss2DeRolLeFiff(s32 arg0, f32 farg0, f32 farg1);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
void TBoss2DeRolLe__sub_80033A80(s32 arg0, s32 arg1);
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void reset_fields_3d0__13TBoss2DeRolLeFPv(void* p);
void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0);
void handle_6x13_de_rol_le_boss_actions(void *arg0);
void TBoss2DeRolLe__sub_80034034(Obj_80034034 *self);
void clear_play_flags__13TBoss2DeRolLeFv(void *arg0);
void set_flags_play_sound__13TBoss2DeRolLeFPv(u8 *arg0);
void apply_hp_damage_with_sound__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
void update_check__13TBoss2DeRolLeFPv(void *arg0);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void TBoss2DeRolLe__sub_80034258(Obj_80034258 *self);
void pick_random_target__13TBoss2DeRolLeFi(s32 arg0);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
void swap_endian__13TBoss2DeRolLeFPv(void *);
void swap_6x13_fields__13TBoss2DeRolLeFPv(void *);
void init_launch__10TBoss2MineFPvPvii(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
s32 create_particle__17TObjBoss2CeilJunkFv(s32, s32);
s32 TObjBoss2Tunnel__sub_8003B1D8(void *);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 enemy_set_target_id(void * a0 = 0, u16 a1 = 0);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 vfunc_93__9TObjEneDDFv();
s32 is_alive__9TObjEneDDFv();
u8 *get_enemy_entity(u16 arg0);
s32 objInBand__FP7GameObjf(void *, f32);
void advance_animation_playback(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
int play_sound_effect(void*, int, int, int);
s32 vec3_add_to(int, void *);

extern Vec_80030720 TBoss2DeRolLe__mine_ground_targets[];
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8280;
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82AC;
extern const f32 TBoss2DeRolLe__data_805D82DC;
extern const f32 TBoss2DeRolLe__data_805D82E4;
extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 TBoss2DeRolLe__data_805D82FC;
extern s32 derolle_action_mode_sequence_table[];
extern s32 derolle_action_sequence_table[];
extern RecoveredGlobal_800339BC_lbl_804FF5E8 lbl_804FF5E8;
extern const f32 lbl_805D82CC;
extern const f32 lbl_805D82EC;
extern const f32 lbl_805D82F4;
extern const f32 lbl_805D82F8;

extern "C" {
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

extern "C" {
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

extern "C" {
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void TBoss2DeRolLe__sub_80034258(Obj_80034258 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

extern "C" {
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_80034258(Obj_80034258 *self);
}

extern "C" {
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

extern "C" {
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

extern "C" {
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
}

void TBoss2DeRolLe__sub_8002F73C(Obj_8002F73C *self, u32 kind) {
    switch (kind) {
    case 4:
        self->fB8 = 0x10;
        ((void (*)(void))TBoss2DeRolLe__sub_80034258)();
        self->f3C0 = self->f3C0 | 4;
        self->f3C0 = self->f3C0 & 0xFFFFFEFF;
        TObjBoss2Tunnel::set_global_flag_200();
        if (TObjBoss2Tunnel::is_active() != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 0:
        queue_destruction__7TObjectFv(self);
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define o ((Rol_8002F7C4 *)arg0)
void handle_death_state__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    Cam_8002F7C4 cam;
    Vec_8002F7C4 v;
    Vec_8002F7C4 w;
    Vec_8002F7C4 save;
    s32 i;
    f32 t;
    switch ((u32)arg1) {
    case 4:
        o->f3C0 &= ~0x100;
        o->f3C0 |= 4;
        TBoss2DeRolLe__sub_80034258((Obj_80034258 *)o);
        o->fB8 = 0x10;
        o->f654 = 3;
        set_position_index__13TBoss2DeRolLeFPvi(o, o->f654);
        o->f5C = 0;
        o->f6A4 = TBoss2DeRolLe__data_805D827C;
        o->f6E0 = 0;
        o->f6E4 = 0;
        o->f6F4 = 0;
        o->f6AC = 0;
        for (i = 0; i < 4; i++) {
            TBoss2Tentacle__sub_80039E54((void *)o->tent[i]);
        }
        TWindowCtrl::init_all_slots();
        cam.b = 0;
        cam.a = 2;
        cam.c = 0;
        cam.d = TBoss2DeRolLe__data_805D827C;
        cam.e = lbl_805D828C;
        ((s32 (*)(int, f32))activate_camera_mode)(5, TBoss2DeRolLe__data_805D827C);
        ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x2AAA);
        set_scripted_camera_pose(&o->pos, &o->pos, &o->f5C);
        break;
    case 2:
        if (o->f3CC->f8 & 0x400) {
            o->flags30 &= ~0x800;
            TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)o);
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)o, 2);
        }
        break;
    case 9:
        if (o->f6E0 == 3) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)o, 0x20);
        }
        break;
    case 0:
        advance_animation_playback(o);
        switch (o->f6E0) {
        case 0:
            if (objInBand__FP7GameObjf(o, lbl_805D8290) != 0) {
                play_cue_stream_file((s32)lbl_804359F8);
            } else if (objInBand__FP7GameObjf(o, TBoss2DeRolLe__data_805D8294) != 0) {
                play_sound_effect((void *)0x4003AD11, 0, 0, 0);
            } else if (objInBand__FP7GameObjf(o, lbl_805D8298) != 0) {
                play_sound_effect((void *)0x4003AD12, 0, 0, 0);
                start_pad_rumble_all(0xC0, 0xF);
            }
            o->f6E4++;
            t = o->fC0;
            if (t >= TBoss2DeRolLe__data_805D8294 && t <= TBoss2DeRolLe__data_805D829C) {
                if ((f32)o->f6E4 >= TBoss2DeRolLe__data_805D82A0) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, &o->pos);
                    for (i = 0; i < 10; i++) {
                        u8 *q = (u8 *)o + i * 12;
                        if (v.y * *(f32 *)(q + 0x544) < TBoss2DeRolLe__data_805D827C) {
                            break;
                        }
                        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, q + 0x540);
                    }
                    v.x += TBoss2DeRolLe__data_805D82A4 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    v.y = TBoss2DeRolLe__data_805D82A8;
                    v.z += TBoss2DeRolLe__data_805D82AC * calc_boss4_scale__10TObjPlayerFi(o);
                    ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &v);
                }
            } else if (t >= lbl_805D8298 && t <= lbl_805D82B0 && (f32)o->f6E4 >= TBoss2DeRolLe__data_805D82A0) {
                o->f6E4 = 0;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&w, &o->pos);
                w.x += TBoss2DeRolLe__data_805D82A4 * calc_elapsed_scaled__9TObjEneDDFv(o) + TBoss2DeRolLe__data_805D8294;
                w.y = TBoss2DeRolLe__data_805D82A8;
                w.z += TBoss2DeRolLe__data_805D82A4 * calc_elapsed_scaled__9TObjEneDDFv(o) + TBoss2DeRolLe__data_805D8294;
                ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &w);
            }
            if (o->fC0 >= TBoss2DeRolLe__data_805D8294) {
                o->f758 = 5;
            }
            if (o->fC0 > TBoss2DeRolLe__data_805D82B4) {
                o->f6E0 = 2;
            }
            break;
        case 1:
            o->f6F4 += 0x400;
            o->f6A4 = TBoss2DeRolLe__data_805D8288 * (TBoss2DeRolLe__data_805D82B8 * (cos_table_lookup(o->f6F4) - TBoss2DeRolLe__data_805D82BC));
            break;
        case 2:
            o->f6A4 -= TBoss2DeRolLe__data_805D82BC;
            if (o->f6A4 < lbl_805D82C0) {
                o->f6E0 = 3;
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 1:
        break;
    case 3:
        break;
    case 5:
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&save, &o->pos);
        o->pos.x = lbl_805D82C4;
        o->pos.y = TBoss2DeRolLe__data_805D82A0;
        o->pos.z = lbl_805D82C8;
        ((TObjEnemy *)o)->update_prev_position();
        for (i = 0; i != 10; i++) {
            assign_slots_from_list(o, o->slots[i]);
        }
        ((TBoss8Dragon *)o)->refresh_and_send_entity_flags();
        TBoss4DarkFalz::dispatch_by_main_phase((u16)((void *)0x20));
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&o->pos, &save);
        ((TObjEnemy *)o)->update_prev_position();
        o->flags30 = 0x12008;
        o->m72(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    }
}
#undef o
#pragma pop

void TBoss2DeRolLe__sub_8002FCE4(Obj_8002FCE4 *self, u32 kind) {
    switch (kind) {
    case 4:
        self->f3C0 = self->f3C0 | 4;
        self->f3C0 = self->f3C0 & 0xFFFFFEFF;
        ((void (*)(void))TBoss2DeRolLe__sub_80034258)();
        self->f5C = 0;
        self->f6A4 = TBoss2DeRolLe__data_805D827C;
        return;
    case 9:
        if (self->fB8 == 1) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)(self));
        }
        break;
    case 8:
        if (self->f6A4 < lbl_805D82CC) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(self), 0x1F);
            return;
        }
        break;
    case 0:
        self->f6A4 = self->f6A4 - TBoss2DeRolLe__data_805D82A0;
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    }
}

void TBoss2DeRolLe__sub_8002FD9C(DeRolLe_8002FD9C *self, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 4:
        self->flags &= ~4;
        self->flags |= 0x100;
        self->state = 0xE;
        ((void (*)(void *))TBoss2DeRolLe__sub_800341F0)(self);
        self->mode = 3;
        set_position_index__13TBoss2DeRolLeFPvi(self, self->mode);
        if (arg2 != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 2:
        if (self->state == 1) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)((struct Obj_80034034 *)self), 2);
        }
        break;
    case 9:
        if (self->state == 1) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)((struct Obj_80034034 *)self));
        }
        break;
    case 0:
        ((s32 (*)(void *))advance_animation_playback)(self);
        break;
    }
}

#define VCOPY(d, s) ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)((d), (s))
#define VADD(d, s) ((void (*)(void *, void *)) vec3_add_to)((d), (s))
#pragma push
#pragma fp_contract on
void TBoss2DeRolLe__sub_8002FE60(void *arg0, u32 arg1) {
    Vec_8002FE60 *vel;
    Vec_8002FE60 *hit;
    D_8002FE60 *self = (D_8002FE60 *) arg0;
    vel = &self->vel;
    switch (arg1) {
    case 4:
        self->flags &= ~4;
        self->flags |= 0x100;
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *) self);
        self->fB8 = 0xF;
        self->mode = 3;
        set_position_index__13TBoss2DeRolLeFPvi(self, self->mode);
        fill_value_array(self->f6C8);
        self->phase = 0;
        self->timer = 0;
        self->f6E8 = 0;
        self->f6F4 = 0;
        self->speed = 0.0f;
        self->f700 = 0.0f;
        vel->x = 0.0f;
        vel->y = 0.0f;
        vel->z = 0.0f;
        self->ptcl = NULL;
        break;
    case 2:
        if (self->phase == 4) {
            if (self->count >= 4) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *) self, 0x1C);
            } else {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *) self, 0x1B);
            }
        }
        break;
    case 9:
        if (self->phase == 4) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *) self);
        }
        break;
    case 0:
        advance_animation_playback(self);
        self->f758 = 6;
        switch (self->phase) {
        case 0:
            self->timer++;
            if (self->timer >= 0x14) {
                self->timer = 0;
                self->phase = 1;
                fill_value_array(self->f6C8);
                self->fB8 = 0xD;
                if (((TObjEneDD_ST *)self)->enemy_check_target_valid() != 0) {
                    VCOPY(vel, self->target + 0x38);
                } else {
                    vel->x = 0.0f;
                    vel->y = 0.0f;
                    vel->z = 0.0f;
                }
                calc_offset_position__13TBoss2DeRolLeFPv((u8 *)self);
                activate_laser_light__13TBoss2DeRolLeFPv(self);
                ((int (*)(int, void *))play_sound)(0x4003A809, self->snd);
            }
            break;
        case 1:
            if (self->count != 0 && TObjEneDD::check_v2_mode() != 0) {
                self->frame = 13.0f;
            }
            if (self->frame <= 12.0f) {
                if (self->ptcl == NULL) {
                    self->ptcl = spawn_continuous_particle_effect_with_flags(&self->pos, 0x122, 0x40);
                    if (self->ptcl != NULL) {
                        ((TParticleCtrl *)(self->ptcl))->enable();
                    }
                } else {
                    Vec_8002FE60 a;
                    VCOPY(&a, &self->pos);
                    a.x += 2.0f * (5.0f * self->dir.x);
                    a.y += 5.0f * self->dir.y;
                    a.z += 5.0f * self->dir.z;
                    ((TNowLoading *)(self->ptcl))->copy_pos(&a);
                }
            } else if (self->ptcl != NULL) {
                queue_destruction__7TObjectFv(self->ptcl);
                self->ptcl = NULL;
            }
            calc_offset_position__13TBoss2DeRolLeFPv((u8 *)self);
            if (self->frame >= 13.0f) {
                self->frame = 13.0f;
                self->phase = 2;
                subtract_vector(vel, &self->pos);
                ((TObjBoss2Tunnel *)vel)->clamp_velocity();
                vel->y = 0.0f;
                self->f6F4 = lbl_80435A10[0] * atan2_float(vel->x, vel->z);
                self->speed = 80.0f;
                spawn_particle_effect_with_flags(&self->pos, 0x126, 0x40);
            }
            break;
        case 2: {
            f32 k;
            f32 dist;
            f32 s;
            u8 *col;
            self->frame = 13.0f;
            self->speed += 30.0f;
            if (self->ptcl == NULL) {
                self->ptcl = spawn_continuous_particle_effect_with_flags(&self->pos, 0x177, 0x40);
                if (self->ptcl != NULL) {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else {
                Vec_8002FE60 b;
                VCOPY(&b, &self->pos);
                b.x += 2.0f * (5.0f * self->dir.x);
                b.y += 5.0f * self->dir.y;
                b.z += 5.0f * self->dir.z;
                ((TNowLoading *)(self->ptcl))->copy_pos(&b);
            }
            {
                Vec_8002FE60 e;
                Vec_8002FE60 c;
                Vec_8002FE60 p;
                Vec_8002FE60 d;
                f32 h;
                f32 dy;
                f32 t;
                hit = &self->hit;
                h = self->pos.y;
                dy = -10.0f - h;
                e.x = vel->x * self->speed;
                e.y = dy;
                e.z = vel->z * self->speed;
                t = (10.0f - h) / dy;
                c.x = e.x * t;
                c.y = dy * t;
                c.z = e.z * t;
                VADD(&c, &self->pos);
                VCOPY(hit, &e);
                VADD(hit, &self->pos);
                self->f700 += 5.0f;
                if (self->f700 >= 20.0f) {
                    self->f700 -= 20.0f;
                }
                s = self->f700;
                VCOPY(&p, &self->pos);
                VCOPY(&d, hit);
                subtract_vector(&d, &p);
                dist = ((TObjBoss2Tunnel *)(&d))->update_scale();
                p.x += d.x * s;
                p.y += d.y * s;
                p.z += d.z * s;
                k = 20.0f;
                d.x *= k;
                d.y *= k;
                d.z *= k;
                for (; dist > s; s += k) {
                    spawn_particle_effect_with_flags(&p, 0x176, 0x40);
                    VADD(&p, &d);
                }
                col = csnVector(&c, hit, 0x16EF);
                if (col != NULL) {
                    VCOPY(hit, *(void **) (col + 4));
                    if (self->laser1 == NULL) {
                        void *o = __nw__7TObjectFUl(0x124);
                        if (o != NULL) {
                            o = __ct__13TUnk_80482C58FP7TObjectll(o, self, 6, 0x124);
                        }
                        self->laser1 = o;
                    } else {
                        push_trail_position__13TBoss2DeRolLeFPvPv(self->laser1, hit);
                    }
                    if (self->laser2 == NULL) {
                        void *o = __nw__7TObjectFUl(0x124);
                        if (o != NULL) {
                            o = __ct__13TUnk_80482C58FP7TObjectll(o, self, 0xF, 0x125);
                        }
                        self->laser2 = o;
                    } else {
                        push_trail_position__13TBoss2DeRolLeFPvPv(self->laser2, hit);
                    }
                }
                {
                    Inst_8002FE60 r = lbl_804356FC[0];
                    *(f32 *) &r.w[1] = *(f32 *) TBoss2DeRolLe__data_805D4BA0;
                    TObjEneDD::setup_instance((s32)self, (s32)hit, (u8 *)&r, self->f6C8);
                }
            }
            ((int (*)(int, void *, void *))spawn_trap__13TBoss2DeRolLeFPvii)(0x4003B00A, self, hit);
            if (self->speed >= 500.0f) {
                self->speed = 500.0f;
                self->phase = 3;
                if (self->ptcl != NULL) {
                    queue_destruction__7TObjectFv(self->ptcl);
                    self->ptcl = NULL;
                }
            }
            break;
        }
        case 3:
            if (TObjEneDD::check_v2_mode() != 0) {
                self->phase = 4;
            }
            if (get_flag_b4__9TObjEneDDFv(self) != 0) {
                self->phase = 4;
            }
            break;
        }
        break;
    case 6:
        pick_random_target__13TBoss2DeRolLeFi((s32) self);
        break;
    case 5:
        free_laser__13TBoss2DeRolLeFPv(self, (s32)(self->count++));
        if (self->ptcl != NULL) {
            queue_destruction__7TObjectFv(self->ptcl);
            self->ptcl = NULL;
        }
        if (self->laser1 != NULL) {
            queue_destruction__7TObjectFv(self->laser1);
            self->laser1 = NULL;
        }
        if (self->laser2 != NULL) {
            queue_destruction__7TObjectFv(self->laser2);
            self->laser2 = NULL;
        }
        break;
    }
}
#pragma pop
#undef VCOPY
#undef VADD

#pragma push
#pragma fp_contract on
void state_ceiling_attack__13TBoss2DeRolLeFPvUi(u8 *arg0, u32 arg1) {
    Vec_80030588 v;
    f32 frame;

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) & ~4;
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) | 0x100;
        ((s32 (*)(void))TBoss2DeRolLe__sub_800341F0)();
        ((TBoss2DeRolLe *)arg0)->m_b8 = 0xC;
        *(s32 *)((s8 *)arg0 + 0x654) = 3;
        ((s32 (*)(void *, int))set_position_index__13TBoss2DeRolLeFPvi)(arg0, *(s32 *)((s8 *)arg0 + 0x654));
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        ((TBoss2DeRolLe *)arg0)->m_6f8 = 0;
        return;
    case 2:
        if (((TBoss2DeRolLe *)arg0)->m_b8 == 0xF) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x1B);
        }
        return;
    case 9:
        if (((TBoss2DeRolLe *)arg0)->m_b8 == 0xF) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)arg0);
            return;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x6E0) = *(s32 *)((s8 *)arg0 + 0x6E0) + 1;
        frame = ((TBoss2DeRolLe *)arg0)->m_c0;
        if (frame >= TBoss2DeRolLe__data_805D82E4 && frame <= lbl_805D82EC && (f32)*(s32 *)((s8 *)arg0 + 0x6E0) >= TBoss2DeRolLe__data_805D82F0) {
            *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
            VecCopy__FP3VecPC3Vec((int)&v, arg0 + 0x38);
            v.x = TBoss2DeRolLe__data_805D82DC * calc_elapsed_scaled__9TObjEneDDFv(arg0) + v.x;
            v.y = TBoss2DeRolLe__data_805D82A8;
            v.z = v.z + TBoss2DeRolLe__data_805D82AC;
            spawn_ceil_junk__13TBoss2DeRolLeFii((s32)arg0, (s32)&v);
        }
        if (objInBand__FP7GameObjf(arg0, TBoss2DeRolLe__data_805D82E4) != 0) {
            ((int (*)(int, void *))play_sound)(0x4003AD12, arg0 + 0x518);
        }
        break;
    default:
        break;
    }
}
extern int fold_flush_0;
#pragma pop

void TBoss2DeRolLe__sub_80030720(Obj_80030720 *self, u32 arg1, s32 arg2) {
    u8 *pos;
    s32 i;
    s32 j;
    switch (arg1) {
    case 4:
        self->f3C0 &= ~4;
        self->f3C0 |= 0x100;
        self->fB8 = 0xB;
        self->f654 = 1;
        set_position_index__13TBoss2DeRolLeFPvi(self, self->f654);
        break;
    case 2:
        if (get_flag_b4__9TObjEneDDFv(self) != 0) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)self, 2);
        }
        break;
    case 9:
        if (get_flag_b4__9TObjEneDDFv(self) != 0) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)self);
        }
        break;
    case 0:
        ((s32 (*)(void *))advance_animation_playback)(self);
        if (objInBand__FP7GameObjf(self, lbl_805D82F4) != 0) {
            pos = self->f4D0;
            if (arg2 == 0x18) {
                for (i = 0; i < 5; i++) {
                    ((TBoss2Mine *)(self->f630[i]))->set_launch_position_velocity((u8 *)pos, (u8 *)&TBoss2DeRolLe__mine_ground_targets[i]);
                }
            } else if (((TObjEneDD_ST *)self)->enemy_has_live_target() != 0) {
                for (j = 0; j < 3; j++) {
                    init_launch__10TBoss2MineFPvPvii((u8 *)self->f644[j], (u8 *)pos, (s32)self->f390, (s32)j);
                }
            }
            ((int (*)(int, void *))play_sound)(0x4003A303, self->f524);
        }
        break;
    case 6:
        if (arg2 == 0x19) {
            ((s32 (*)(void *))pick_random_target__13TBoss2DeRolLeFi)(self);
        }
        break;
    }
}

void TBoss2DeRolLe__sub_80030898(u8 *arg0, u32 arg1, s32 arg2) {
    s32 i;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 3;
        ((s32 (*)(void))TBoss2DeRolLe__sub_800341F0)();
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) & ~4;
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) & ~0x100;
        *(s32 *)((s8 *)arg0 + 0x654) = arg2;
        ((s32 (*)(void *, int))set_position_index__13TBoss2DeRolLeFPvi)(arg0, *(s32 *)((s8 *)arg0 + 0x654));
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
        *(f32 *)((s8 *)arg0 + 0x6FC) = lbl_805D82F8;
        *(s32 *)((s8 *)arg0 + 0x6B4) = *(s32 *)((s8 *)arg0 + 0x6B4) + 1;
        if (*(s32 *)((s8 *)arg0 + 0x6B4) >= 3) {
            *(s32 *)((s8 *)arg0 + 0x6B4) = 0;
        }
        return;
    case 2:
        if (((s32 (*)(void))get_flag_b4__9TObjEneDDFv)() != 0) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 2);
            return;
        }
        break;
    case 9:
        if (((s32 (*)(void))get_flag_b4__9TObjEneDDFv)() != 0) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)arg0);
            return;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6E4)) {
        case 0:
            if (!(*(s32 *)((s8 *)arg0 + 0xB0) & 4)) {
                TBoss2DeRolLe__sub_800344A4(arg0, *(s32 *)((s8 *)arg0 + 0x6E0), *(s32 *)((s8 *)arg0 + 0x6B4));
                *(s32 *)((s8 *)arg0 + 0x6E4) = 1;
                return;
            }
            break;
        case 1:
            i = *(s32 *)((s8 *)arg0 + 0x6E0);
            if (((Obj_80030898 *)arg0)->recs[i].a < ((Obj_80030898 *)arg0)->recs[i + 1].a) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = i + 1;
                if ((f32)*(s32 *)((s8 *)arg0 + 0x6E0) >= TBoss2DeRolLe__data_805D82FC) {
                    *(s32 *)((s8 *)arg0 + 0x6E4) = 2;
                }
                TBoss2DeRolLe__sub_800344A4(arg0, *(s32 *)((s8 *)arg0 + 0x6E0), *(s32 *)((s8 *)arg0 + 0x6B4));
            }
            break;
        }
        break;
    default:
        break;
    }
}

struct Vec_80030A38 { f32 x, y, z; };
extern const f32 TBoss2DeRolLe__data_805D82B4;
extern const f32 TBoss2DeRolLe__data_805D82B8;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 lbl_805D8304;
extern const f32 lbl_805D8308;
extern const f32 lbl_805D830C;
extern const f32 lbl_805D8310;
extern const f32 lbl_805D8314;
extern const f32 lbl_805D8318;
extern const f32 lbl_805D831C;
extern const f32 lbl_805D8320;
extern const f32 lbl_805D8324;
extern const f32 TBoss2DeRolLe__data_805D8328;
#pragma push
#pragma fp_contract on
void TBoss2DeRolLe__sub_80030A38(u8 *arg0, u32 arg1) {
    Vec_80030A38 v;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((s32 (*)(void))TBoss2DeRolLe__sub_800341F0)();
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) | 4;
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) & ~0x100;
        set_position_index__13TBoss2DeRolLeFPvi(arg0, 3);
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E8) = 0x1E;
        *(f32 *)((s8 *)arg0 + 0x6FC) = TBoss2DeRolLe__data_805D827C;
        *(f32 *)((s8 *)arg0 + 0x700) = TBoss2DeRolLe__data_805D82F0;
        return;
    case 2:
        if (*(s32 *)((s8 *)arg0 + 0x6E0) == 6) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 2);
        }
        return;
    case 9:
        if (*(s32 *)((s8 *)arg0 + 0x6E0) == 6) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)arg0);
            return;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6E0)) {
        case 0:
            *(f32 *)((s8 *)arg0 + 0x6FC) = *(f32 *)((s8 *)arg0 + 0x6FC) + TBoss2DeRolLe__data_805D8300;
            *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) - *(f32 *)((s8 *)arg0 + 0x6FC);
            *(f32 *)((s8 *)arg0 + 0x700) = *(f32 *)((s8 *)arg0 + 0x700) + lbl_805D8304;
            *(f32 *)((s8 *)arg0 + 0x6A4) = *(f32 *)((s8 *)arg0 + 0x6A4) + *(f32 *)((s8 *)arg0 + 0x700);
            if (*(f32 *)((s8 *)arg0 + 0x6A4) < lbl_805D8308) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 1;
                *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x6E4) = *(s32 *)((s8 *)arg0 + 0x6E4) + 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E4) >= 0x2D) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 2;
                *(s16 *)((s8 *)arg0 + 0xB8) = 2;
                *(f32 *)((s8 *)arg0 + 0x40) = lbl_805D830C;
                *(s32 *)((s8 *)arg0 + 0x64) = 0x8000;
                *(f32 *)((s8 *)arg0 + 0x6A4) = lbl_805D8310;
            }
            break;
        case 2:
            *(s32 *)((s8 *)arg0 + 0x6E8) = *(s32 *)((s8 *)arg0 + 0x6E8) + 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E8) >= 0x1E) {
                *(s32 *)((s8 *)arg0 + 0x6E8) = 0;
            }
            ((int (*)(int, void *, void *))spawn_trap__13TBoss2DeRolLeFPvii)(0x40039E02, arg0, arg0 + 0x518);
            *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) + TBoss2DeRolLe__data_805D82B8;
            if (*(f32 *)((s8 *)arg0 + 0x40) >= lbl_805D8314) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 3;
                *(f32 *)((s8 *)arg0 + 0x700) = TBoss2DeRolLe__data_805D827C;
            }
            if (calc_boss4_scale__10TObjPlayerFi(arg0) <= *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x10)) {
                VecCopy__FP3VecPC3Vec((int)&v, arg0 + 0x38);
                v.x = *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0xC) * calc_elapsed_scaled__9TObjEneDDFv(arg0) + v.x;
                v.z = v.z - TBoss2DeRolLe__data_805D82B4 * calc_boss4_scale__10TObjPlayerFi(arg0);
                v.y = v.y + (TBoss2DeRolLe__data_805D82E4 + *(f32 *)((s8 *)arg0 + 0x6A4));
                TObjBoss2CeilJunk::create(&v);
            }
            break;
        case 3:
            *(f32 *)((s8 *)arg0 + 0xC8) = *(f32 *)((s8 *)arg0 + 0xC8) - lbl_805D8318;
            if (*(f32 *)((s8 *)arg0 + 0xC8) < 0.0f) {
                *(f32 *)((s8 *)arg0 + 0xC8) = 0.0f;
            }
            if (*(f32 *)((s8 *)arg0 + 0x6A4) > TBoss2DeRolLe__data_805D827C) {
                *(f32 *)((s8 *)arg0 + 0x700) = *(f32 *)((s8 *)arg0 + 0x700) + lbl_805D831C;
                *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) + lbl_805D8320;
            } else {
                *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) + lbl_805D8324;
            }
            *(f32 *)((s8 *)arg0 + 0x6A4) = *(f32 *)((s8 *)arg0 + 0x6A4) + *(f32 *)((s8 *)arg0 + 0x700);
            if (*(f32 *)((s8 *)arg0 + 0x6A4) < lbl_805D8308) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 4;
                *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
                ((int (*)(int, void *))play_sound)(0x4003AD12, arg0 + 0x518);
            }
            break;
        case 4:
            *(s32 *)((s8 *)arg0 + 0x6E4) = *(s32 *)((s8 *)arg0 + 0x6E4) + 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E4) >= 0x2D) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 5;
                *(s16 *)((s8 *)arg0 + 0xB8) = 1;
                *(s32 *)((s8 *)arg0 + 0x654) = 1;
                set_position_index__13TBoss2DeRolLeFPvi(arg0, *(s32 *)((s8 *)arg0 + 0x654));
                *(s32 *)((s8 *)arg0 + 0x64) = 0;
                *(f32 *)((s8 *)arg0 + 0x6A4) = lbl_805D8308;
                TObjBoss2Tunnel::set_global_flag_400();
            }
            break;
        case 5:
            *(f32 *)((s8 *)arg0 + 0x6A4) = *(f32 *)((s8 *)arg0 + 0x6A4) + TBoss2DeRolLe__data_805D8328;
            if (*(f32 *)((s8 *)arg0 + 0x6A4) >= 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x6A4) = 0.0f;
                *(s32 *)((s8 *)arg0 + 0x6E0) = 6;
            }
            break;
        }
        break;
    default:
        break;
    }
}
#pragma pop

extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D832C;
extern const f32 TBoss2DeRolLe__data_805D8330;
extern const f32 TBoss2DeRolLe__data_805D8334;
extern const f32 lbl_805D8308;
extern const f32 lbl_805D8338;
extern const f32 lbl_805D833C;
#pragma push
#pragma fp_contract on
#define arg0 ((u8 *)arg0_)
#define F(t, o) (*(t *)(arg0 + (o)))

void TBoss2DeRolLe__sub_80030DFC(void *arg0_, void *arg1_, int arg2) {
    switch ((u32)arg1_) {
    case 4:
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)arg0);
        F(s32, 0x3C0) |= 4;
        F(s32, 0x3C0) &= ~0x100;
        F(s32, 0x654) = arg2;
        set_move_direction__13TBoss2DeRolLeFPv(arg0, F(s32, 0x654));
        if (F(s32, 0x654) == 0) {
            F(f32, 0x700) = TBoss2DeRolLe__data_805D832C;
            F(s16, 0xB8) = 9;
        } else {
            F(f32, 0x700) = TBoss2DeRolLe__data_805D82BC;
            F(s16, 0xB8) = 10;
        }
        F(s32, 0x6E0) = 0;
        F(s32, 0x6E4) = 0;
        F(f32, 0x6FC) = TBoss2DeRolLe__data_805D827C;
        F(f32, 0x708) = TBoss2DeRolLe__data_805D832C;
        F(f32, 0x704) = TBoss2DeRolLe__data_805D827C;
        F(s32, 0x6F4) = 0x500;
        TObjBoss2Tunnel::clear_global_flag_3000();
        break;
    case 2:
        if (F(s32, 0x6E0) == 2) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 2);
        }
        break;
    case 9:
        if (F(s32, 0x6E0) == 2) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)arg0);
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(s32, 0x6E0)) {
        case 0:
            F(f32, 0x704) += TBoss2DeRolLe__data_805D8300;
            F(f32, 0x40) -= F(f32, 0x704);
            F(f32, 0x6FC) += TBoss2DeRolLe__data_805D8330;
            F(f32, 0x38) += F(f32, 0x6FC) * F(f32, 0x700);
            F(f32, 0x708) += TBoss2DeRolLe__data_805D8334;
            F(f32, 0x6A4) -= F(f32, 0x708);
            F(s32, 0x6F4) = (s32)((f32)F(s32, 0x6F4) + lbl_805D8338);
            if ((f32)F(s32, 0x6F4) >= lbl_805D833C) {
                F(s32, 0x6F4) = 0x4000;
            }
            F(s32, 0x64) = (s32)((f32)F(s32, 0x6F4) * -F(f32, 0x700));
            if (F(s32, 0x6E4) == 0 && F(s32, 0x6F4) >= 0x2200) {
                F(s32, 0x6E4) = 1;
                play_sound((void *)0x4003AD12, (int)(arg0 + 0x518));
            }
            if (F(f32, 0x6A4) < lbl_805D8308) {
                F(s32, 0x6E0) = 1;
                set_position_index__13TBoss2DeRolLeFPvi(arg0, F(s32, 0x654));
                F(f32, 0x6A4) = lbl_805D8308;
                F(s16, 0xB8) = 1;
                F(f32, 0x708) = TBoss2DeRolLe__data_805D827C;
                F(s32, 0x3C0) &= ~4;
                F(s32, 0x3C0) |= 0x100;
            }
            break;
        case 1:
            F(f32, 0x6A4) += 2.0f;
            if (F(f32, 0x6A4) >= 0.0f) {
                F(f32, 0x6A4) = 0.0f;
                F(s32, 0x6E0) = 2;
            }
            break;
        }
        break;
    case 5:
        F(s32, 0x3C0) &= ~4;
        break;
    case 1:
    case 3:
    case 6:
    case 7:
    case 8:
        break;
    }
}

#undef F
#undef arg0
#pragma pop

#define self ((Self_800310F8 *)arg0)
void TBoss2DeRolLe__sub_800310F8(void *arg0, void *arg1, int arg2) {
    Vec_800310F8 v;
    s32 a;
    s32 ok;
    s32 i;
    switch ((u32)arg1) {
    case 4:
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)self);
        self->flags &= ~4;
        self->flags &= ~0x100;
        self->dir = arg2;
        set_move_direction__13TBoss2DeRolLeFPv(self, self->dir);
        if (self->dir == 0) {
            self->fB8 = 9;
        } else {
            self->fB8 = 10;
        }
        self->phase = 0;
        self->timer = 0;
        self->idx = 0;
        if (TObjEneDD::check_v2_mode() != 0) {
            self->limit = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x24);
            self->life = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x28);
        } else {
            self->limit = 0xB4;
            self->life = 0x78;
        }
        break;
    case 2:
        if (self->phase == 3) {
            if (self->dir == 0) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)self, 0x16);
            } else {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)self, 0x17);
            }
        }
        break;
    case 9:
        if (self->phase == 3) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)self);
        }
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->phase) {
        case 0:
            self->timer++;
            if (self->timer > 0x28) {
                self->phase = 1;
                self->timer = 0;
                self->idx = 0;
            }
            break;
        case 1:
            self->timer++;
            if (self->timer >= self->limit) {
                self->timer = 0;
                if (((TObjEneDD_ST *)self)->enemy_has_live_target() != 0) {
                    VecCopy__FP3VecPC3Vec((int)&v, self->f390 + 0x38);
                } else {
                    f32 r = lbl_805D8340 * calc_boss4_scale__10TObjPlayerFi(self);
                    a = get_random_scaled__9TObjEneDDFv(self);
                    v.x = r * sin_table_lookup(a);
                    v.y = lbl_805D8344;
                    v.z = r * cos_table_lookup(a);
                    TObjBoss2Tunnel::adjust_to_ground((s32)&v, &v);
                }
                {
                    Self_800310F8 *o = (Self_800310F8 *)arg0;
                    ((TBoss2Tentacle *)(o->parts[o->idx]))->start_attack_at_target((u8 *)&v, o->life);
                }
                self->idx++;
                if (self->idx >= 4) {
                    self->timer = 0;
                    self->phase = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            self->timer++;
            for (i = 0; i < 4; i++) {
                if (TBoss2Tentacle__sub_80039CA0(self->parts[i]) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || self->timer > 0x258) {
                self->phase = 3;
            }
            break;
        }
        break;
    case 6:
        pick_random_target__13TBoss2DeRolLeFi((s32)self);
        break;
    case 5:
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                TBoss2Tentacle__sub_80039E68(self->parts[j]);
            }
        }
        break;
    }
}
#undef self

#pragma push
#pragma fp_contract on

struct Obj_800341F0;

struct Vec_80031AD4 { f32 x, y, z; };

struct Rol_80031AD4 {
    u8 pad0[0x38];
    Vec_80031AD4 pos;
    u8 pad44[0xB0 - 0x44];
    s32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x518 - 0x3C4];
    u8 f518[0x654 - 0x518];
    s32 f654;
    u8 pad658[0x684 - 0x658];
    u8 f684[0x69C - 0x684];
    f32 f69C;
    u8 pad6A0[0x6A4 - 0x6A0];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    s32 f6EC;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 f6FC;
    f32 f700;
    f32 f704;
    f32 f708;
};

extern "C" {

s32 VecCopy__FP3VecPC3Vec(int, void *);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034034 *self, s32 mode);
void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self);
void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self);
void set_position_index__13TBoss2DeRolLeFPvi(void *, s32);
f32 calc_node_height__13TBoss2DeRolLeFPv(void *);
s32 advance_scalar_motion_profile(void *);
void update_angle__13TBoss2DeRolLeFPv(void *arg0);
void set_move_params__13TBoss2DeRolLeFPvffff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
f32 fabs_float(f32);
void advance_animation_playback(void *);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2);
s32 objInBand__FP7GameObjf(void *, f32);
int play_sound(void* p, int a1);
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82A4;
extern const f32 TBoss2DeRolLe__data_805D82A8;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D82E8;
extern const f32 lbl_805D82EC;
extern const f32 TBoss2DeRolLe__data_805D82FC;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 lbl_805D8364;
extern const f32 lbl_805D836C;
extern const f32 lbl_805D8374;
extern const f32 lbl_805D8378;
extern const f32 lbl_805D837C;
extern const f32 lbl_805D8380;
extern const f32 lbl_805D8384;
extern const f32 lbl_805D8388;
extern const f32 lbl_805D838C;
extern const f32 lbl_805D8390;
extern const f32 lbl_805D8394;
extern const f32 lbl_805D8398;
extern const f32 lbl_805D839C;
extern const f32 lbl_805D83A0;
extern const f32 lbl_805D83A4;
extern const f32 lbl_805D83A8;
extern const f32 TBoss2DeRolLe__data_805D83AC;

#pragma push
#pragma fp_contract on
void TBoss2DeRolLe__sub_800313F8(DR_800313F8 *o, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 4:
        o->fB8 = 1;
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)(o));
        o->f3C0 |= 4;
        o->f3C0 &= ~0x100;
        o->f654 = arg2;
        set_position_index__13TBoss2DeRolLeFPvi(o, o->f654);
        o->f6FC = TBoss2DeRolLe__data_805D827C;
        o->f708 = TBoss2DeRolLe__data_805D827C;
        o->f704 = TBoss2DeRolLe__data_805D827C;
        o->f700 = TBoss2DeRolLe__data_805D827C;
        o->f70C = lbl_805D8304;
        o->f710 = TBoss2DeRolLe__data_805D827C;
        o->f714 = o->pos.z;
        o->f718 = TBoss2DeRolLe__data_805D827C;
        o->f6E4 = 0;
        o->f6E0 = 0;
        o->f6E8 = 0;
        o->f73C = 0;
        o->f6EC = 0;
        break;
    case 2: {
        u32 fl = o->f3CC->f8;
        if (fl & 0x400) {
            if (o->f654 == 0) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(o), 0x14);
            } else {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(o), 0x15);
            }
        } else if (fl & 4) {
            if (o->f654 == 0) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(o), 0x16);
            } else {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(o), 0x17);
            }
        }
        break;
    }
    case 9:
        if (o->fB8 == 0xA || o->fB8 == 9) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)(o));
        }
        break;
    case 0:
        advance_animation_playback(o);
        switch (o->f6E0) {
        case 0:
            o->f6E4++;
            if (o->f6E4 > 0xA) {
                o->f6E4 = 0;
                o->f6E0 = 1;
                if (o->f654 == 0) {
                    o->fB8 = 7;
                    o->f6FC = TBoss2DeRolLe__data_805D832C;
                } else {
                    o->fB8 = 8;
                    o->f6FC = TBoss2DeRolLe__data_805D82BC;
                }
            }
            break;
        case 1:
            if (!(o->fB0 & 4)) {
                o->f6E0 = 2;
            }
            break;
        case 2:
            if (o->fC0 >= TBoss2DeRolLe__data_805D82B8) {
                o->f6E0 = 3;
                o->f708 = TBoss2DeRolLe__data_805D827C;
                o->f700 = o->pos.x;
                o->f704 = (TBoss2DeRolLe__data_805D82B4 * o->f6FC - o->f700) / TBoss2DeRolLe__data_805D8348;
                o->f70C = -(o->f710 / TBoss2DeRolLe__data_805D8348);
                o->f714 = o->pos.z;
                o->f710 = TBoss2DeRolLe__data_805D827C;
            }
            break;
        case 3:
            if (o->fC0 >= lbl_805D82D0) {
                o->f6E0 = 4;
                o->f708 = TBoss2DeRolLe__data_805D827C;
                o->f700 = TBoss2DeRolLe__data_805D82B4 * o->f6FC;
                o->f704 = (lbl_805D834C * o->f6FC - o->f700) / TBoss2DeRolLe__data_805D8348;
                o->f714 = o->pos.z;
                o->f70C = (TBoss2DeRolLe__data_805D82A0 * (TBoss2DeRolLe__data_805D82E4 - o->pos.z)) / lbl_805D8350;
                o->f710 = TBoss2DeRolLe__data_805D827C;
            }
            break;
        case 4:
            if (o->fC0 >= TBoss2DeRolLe__data_805D8294) {
                o->f6E0 = 5;
                o->f708 = TBoss2DeRolLe__data_805D827C;
                o->f700 = lbl_805D834C * o->f6FC;
                o->f704 = (TBoss2DeRolLe__data_805D82B4 * o->f6FC - o->f700) / TBoss2DeRolLe__data_805D82D8;
                o->f718 = (lbl_805D8354 * -o->f6FC) / TBoss2DeRolLe__data_805D82D8;
            }
            break;
        case 5:
            if (o->fC0 >= TBoss2DeRolLe__data_805D8358) {
                s32 i;
                o->f6E0 = 6;
                TCameraCtrl::set_shake_preset(1);
                if (o->f654 == 0) {
                    TObjBoss2Tunnel__sub_8003C610();
                } else {
                    TObjBoss2Tunnel__sub_8003C5F8();
                }
                ((int (*)(s32, void *))play_sound)(0x4003A507, o->snd);
                for (i = 0; i < 4; i++) {
                    ((TBoss2Tentacle *)(o->tentacles[i]))->forward_80039DC8();
                }
            }
            break;
        case 6:
            break;
        }
        o->f6E8++;
        if (o->f6E0 != 0 && o->f6E0 != 1) {
            if (o->fC0 >= lbl_805D835C && o->fC0 <= lbl_805D8360 && o->f6E8 >= 2) {
                Vec_800313F8 v;
                f32 s;
                o->f6E8 = 0;
                VecCopy__FP3VecPC3Vec((int)&v, &o->v4E8);
                s = lbl_805D8364 * calc_boss4_scale__10TObjPlayerFi(o);
                v.x = v.x - o->f6FC * s;
                v.y = TBoss2DeRolLe__data_805D82A8;
                v.z = v.z + TBoss2DeRolLe__data_805D82A4;
                ((void (*)(void *, Vec_800313F8 *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &v);
            }
            if (objInBand__FP7GameObjf(o, lbl_805D835C) != 0) {
                ((int (*)(s32, void *))play_sound)(0x4003AD11, o->snd);
            }
            if (o->f73C == 0) {
                o->f73C = create_particle_emitter(&o->pos, 0x161);
                if (o->f73C != 0) {
                    ((TParticleCtrl *)(o->f73C))->enable();
                }
            } else if (o->fC0 >= lbl_805D8368 && o->fC0 <= TBoss2DeRolLe__data_805D82DC) {
                o->f6EC++;
                if (o->f6EC % 4 == 0) {
                    ((TNowLoading *)(o->f73C))->copy_pos(&o->v44C);
                } else if (o->f6EC % 4 == 2) {
                    ((TNowLoading *)(o->f73C))->copy_pos(&o->v458);
                } else {
                    ((TParticleCtrl *)(o->f73C))->enable();
                }
            } else {
                ((TParticleCtrl *)(o->f73C))->enable();
            }
        }
        switch (o->f6E0) {
        case 0:
        case 1:
        case 2:
            o->f710 += o->f70C;
            if (o->f710 < -7.0f) {
                o->f710 = -7.0f;
            }
            o->pos.z += o->f710;
            break;
        case 3: {
            f32 t = o->fC0 - TBoss2DeRolLe__data_805D82B8;
            o->pos.x = o->f704 * t + o->f700;
            f32 h = TBoss2DeRolLe__data_805D8288 * o->f70C;
            o->pos.z = t * (h * t + lbl_805D836C) + o->f714;
            if (objInBand__FP7GameObjf(o, lbl_805D8370) != 0) {
                ((int (*)(s32, void *))play_sound)(0x4003AD12, o->snd);
            }
            break;
        }
        case 4: {
            f32 t = o->fC0 - lbl_805D82D0;
            o->pos.x = o->f704 * t + o->f700;
            f32 h = TBoss2DeRolLe__data_805D8288 * o->f70C;
            o->pos.z = t * (h * t) + o->f714;
            o->f6A4 = TBoss2DeRolLe__data_805D829C * t;
            if (o->f6A4 > 4.0f) {
                o->f6A4 = 4.0f;
            }
            break;
        }
        case 5: {
            f32 t = o->fC0 - TBoss2DeRolLe__data_805D8294;
            f32 u;
            o->pos.x = o->f704 * t + o->f700;
            u = o->fC0 - lbl_805D82D0;
            {
                f32 h = TBoss2DeRolLe__data_805D8288 * o->f70C;
                f32 w = u * (h * u);
                o->pos.z = o->f714 + w;
            }
            o->f64 = o->f718 * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        o->f3C0 &= ~4;
        if (o->f73C != 0) {
            queue_destruction__7TObjectFv(o->f73C);
            o->f73C = 0;
        }
        break;
    }
}
#pragma pop

#define o ((Rol_80031AD4 *)arg0)

void TBoss2DeRolLe__sub_80031AD4(void *arg0, void *arg1) {
    Vec_80031AD4 va;
    Vec_80031AD4 vb;

    switch ((u32)arg1) {
    case 4:
        o->fB8 = 1;
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)o);
        o->f3C0 |= 4;
        o->f3C0 &= ~0x100;
        o->f654 = 3;
        set_position_index__13TBoss2DeRolLeFPvi(o, o->f654);
        o->f6E0 = 0;
        o->f6E8 = 0;
        o->f6E4 = 0;
        o->f6FC = TBoss2DeRolLe__data_805D827C;
        o->f700 = TBoss2DeRolLe__data_805D827C;
        o->f704 = TBoss2DeRolLe__data_805D827C;
        o->f708 = TBoss2DeRolLe__data_805D827C;
        o->f6EC = 0;
        break;
    case 2:
        if (o->f6E0 == 3) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)o, 2);
        }
        break;
    case 9:
        if (o->f6E0 == 3) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)o);
        }
        break;
    case 0:
        advance_animation_playback(o);
        switch (o->f6E0) {
        case 0:
            o->f6E8++;
            if (o->f6E8 > 0x14) {
                o->fB8 = 4;
                o->f6E0 = 1;
            }
            o->f704 -= 0.2f;
            if (o->f704 < -7.0f) {
                o->f704 = -7.0f;
            }
            o->pos.z += o->f704;
            break;
        case 1:
            if (!(o->fB0 & 4)) {
                o->f6E0 = 2;
            }
            break;
        case 2:
            switch (o->f6E4) {
            case 0:
                if (o->fC0 >= lbl_805D8374) {
                    o->f6E4 = 1;
                    o->f708 = (lbl_805D837C * -o->f704 + (lbl_805D8378 - o->pos.z)) / lbl_805D8380;
                    o->f6EC = 0;
                }
                break;
            case 1:
                if (o->fC0 >= lbl_805D8384) {
                    o->f6E4 = 2;
                    o->f6FC = TBoss2DeRolLe__data_805D82FC * (TBoss2DeRolLe__data_805D82A4 - o->pos.y) / lbl_805D8388;
                    o->f700 = TBoss2DeRolLe__data_805D82A0 * o->f6FC / lbl_805D8388;
                    o->f6EC = 0;
                }
                break;
            case 2:
                if (o->fC0 >= lbl_805D838C) {
                    o->f6E4 = 3;
                    o->f704 *= TBoss2DeRolLe__data_805D8288;
                    o->f708 = TBoss2DeRolLe__data_805D827C;
                }
                break;
            case 3:
                if (o->fC0 >= lbl_805D8390) {
                    o->f6E4 = 4;
                }
                break;
            }
            if (o->fB8 != 1) {
                if (objInBand__FP7GameObjf(o, TBoss2DeRolLe__data_805D82FC) != 0 || objInBand__FP7GameObjf(o, lbl_805D838C) != 0) {
                    play_sound((void *)0x4003AD11, (int)o->f518);
                } else if (objInBand__FP7GameObjf(o, lbl_805D82EC) != 0) {
                    play_sound((void *)0x4003AD12, (int)o->f518);
                }
            }
            switch (o->f6E4) {
            case 1:
                o->f6EC++;
                if (o->fC0 >= lbl_805D8394 && o->f6EC >= 2) {
                    o->f6EC = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&va, &o->pos);
                    va.x += lbl_805D8364 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    va.y = TBoss2DeRolLe__data_805D82A8;
                    va.z += lbl_805D8398;
                    ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &va);
                }
                break;
            case 2:
            case 3:
                o->f6EC++;
                if (o->f6EC >= 2 && o->fC0 >= lbl_805D839C && o->fC0 <= lbl_805D83A0) {
                    o->f6EC = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&vb, &o->pos);
                    vb.x += lbl_805D8364 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    vb.y = TBoss2DeRolLe__data_805D82A8;
                    vb.z += lbl_805D83A4;
                    ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &vb);
                }
                break;
            }
            switch (o->f6E4) {
            case 0:
                o->f704 -= 0.2f;
                if (o->f704 < -7.0f) {
                    o->f704 = -7.0f;
                }
                o->pos.z += o->f704;
                break;
            case 1:
                o->f704 += o->f708;
                o->pos.z += o->f704;
                o->f6FC = calc_node_height__13TBoss2DeRolLeFPv(o);
                break;
            case 2:
                o->pos.z += o->f704;
                o->f6A4 += o->f6FC;
                o->f6FC -= o->f700;
                o->fC0 -= lbl_805D83A8;
                break;
            case 3:
            case 4:
                if (o->f708 <= TBoss2DeRolLe__data_805D827C) {
                    o->f704 -= TBoss2DeRolLe__data_805D8300;
                    if (o->f704 <= TBoss2DeRolLe__data_805D827C) {
                        o->f708 = TBoss2DeRolLe__data_805D82BC;
                        set_move_params__13TBoss2DeRolLeFPvffff(o->f684, TBoss2DeRolLe__data_805D8348, fabs_float(TBoss2DeRolLe__data_805D82E8 - o->pos.z), TBoss2DeRolLe__data_805D8300, TBoss2DeRolLe__data_805D83AC);
                        o->f704 = o->pos.z;
                    } else {
                        o->pos.z += o->f704;
                    }
                } else if (advance_scalar_motion_profile(o->f684) == 3) {
                    o->f6E0 = 3;
                } else {
                    o->pos.z = o->f704 - o->f69C;
                }
                update_angle__13TBoss2DeRolLeFPv(o);
                break;
            }
            break;
        }
        break;
    case 5:
        o->f654 = 1;
        o->f3C0 &= ~4;
        break;
    }
}
#undef o

}
#undef o
#pragma pop

#pragma push
#pragma fp_contract on
#define o ((DR_800327C8 *)arg0)

#pragma push
#pragma fp_contract on
#define self ((D_800320B4 *) arg0)
void TBoss2DeRolLe__sub_800320B4(void *arg0, void *arg1, int arg2, int arg3) {
    switch ((u32) arg1) {
    case 4:
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *) self);
        self->flags |= 4;
        self->flags &= ~0x100;
        self->mode = arg2;
        self->next_mode = arg3;
        set_position_index__13TBoss2DeRolLeFPvi(self, self->mode);
        if (self->mode == 0) {
            self->fB8 = 5;
            self->dir = TBoss2DeRolLe__data_805D832C;
        } else {
            self->fB8 = 6;
            self->dir = TBoss2DeRolLe__data_805D82BC;
        }
        self->phase = 0;
        self->f6E4 = 0;
        self->step = 0;
        self->f700 = TBoss2DeRolLe__data_805D827C;
        self->f704 = TBoss2DeRolLe__data_805D827C;
        self->vx = TBoss2DeRolLe__data_805D827C;
        self->ay = TBoss2DeRolLe__data_805D827C;
        self->vy = TBoss2DeRolLe__data_805D827C;
        self->tick = 0;
        break;
    case 2:
        if (self->phase == 2) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *) self, 2);
        }
        break;
    case 9:
        if (self->phase == 2) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *) self);
        }
        break;
    case 0:
        switch (self->phase) {
        case 0:
            advance_animation_playback(self);
            if (!(self->fB0 & 4)) {
                self->phase = 1;
            }
            break;
        case 1:
            advance_animation_playback(self);
            switch (self->step) {
            case 0:
                if (self->frame >= TBoss2DeRolLe__data_805D82E4) {
                    self->step = 1;
                    self->vx = lbl_805D83B0 * self->dir;
                }
                break;
            case 1:
                if (self->frame >= TBoss2DeRolLe__data_805D8294) {
                    self->step = 2;
                    self->vx = lbl_805D83B4 * self->dir;
                    self->ay = (lbl_805D83BC * -self->vy + (lbl_805D83B8 - self->z)) / lbl_805D83C0;
                }
                break;
            case 2:
                if (self->frame >= TBoss2DeRolLe__data_805D829C) {
                    self->step = 3;
                    self->f700 = (calc_node_height__13TBoss2DeRolLeFPv(self) - self->f700) / lbl_805D83C4;
                    self->f704 = (TBoss2DeRolLe__data_805D82A0 * self->f700) / lbl_805D83C8;
                    self->vx = lbl_805D83CC * self->dir;
                    self->tick = 0;
                }
                break;
            case 3:
                if (self->frame >= lbl_805D83D0) {
                    self->step = 4;
                    self->vx = lbl_805D83D4 * self->dir;
                    set_move_params__13TBoss2DeRolLeFPvffff(self->mover, TBoss2DeRolLe__data_805D8348, fabs_float(TBoss2DeRolLe__data_805D8358 - self->z), TBoss2DeRolLe__data_805D8300, TBoss2DeRolLe__data_805D83AC);
                    self->f694 = -(TBoss2DeRolLe__data_805D8288 * self->vy);
                    self->vy = self->z;
                }
                break;
            case 4:
                if (self->frame >= lbl_805D83D8) {
                    self->step = 5;
                    self->vx = self->dir * ((TBoss2DeRolLe__data_805D83DC - self->x * self->dir) / lbl_805D83E0);
                }
                break;
            case 5:
                if (self->frame >= lbl_805D83E4) {
                    self->step = 6;
                }
                break;
            }
            if (self->fB8 != 1) {
                if (objInBand__FP7GameObjf(self, TBoss2DeRolLe__data_805D82E4) != 0 || objInBand__FP7GameObjf(self, lbl_805D83E8) != 0) {
                    ((int (*)(int, void *))play_sound)(0x4003AD11, self->snd);
                } else if (objInBand__FP7GameObjf(self, TBoss2DeRolLe__data_805D8358) != 0) {
                    ((int (*)(int, void *))play_sound)(0x4003AD12, self->snd);
                }
            }
            self->tick++;
            if (self->step != 6) {
                f32 frame = self->frame;
                if (frame >= lbl_805D8368 && frame <= lbl_805D83EC) {
                    if (self->tick >= 3) {
                        V_800320B4 v;
                        s32 i;
                        self->tick = 0;
                        ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                        for (i = 0; i < 10; i++) {
                            if (v.y * self->recs[i].y < TBoss2DeRolLe__data_805D827C) {
                                break;
                            }
                            ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->recs[i]);
                        }
                        v.x = v.x - self->dir * (TBoss2DeRolLe__data_805D8294 * calc_boss4_scale__10TObjPlayerFi(self) + TBoss2DeRolLe__data_805D82A4);
                        v.y = TBoss2DeRolLe__data_805D82A8;
                        v.z = v.z + (TBoss2DeRolLe__data_805D8294 * calc_elapsed_scaled__9TObjEneDDFv(self) + lbl_805D83F0);
                        ((void (*)(void *, void *)) spawn_ceil_junk__13TBoss2DeRolLeFii)(self, &v);
                    }
                } else if (frame >= lbl_805D83E8 && frame <= lbl_805D83D8 && self->tick >= 3) {
                    V_800320B4 v;
                    self->tick = 0;
                    ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                    v.x = v.x + self->dir * (20.0f * calc_boss4_scale__10TObjPlayerFi(self) + 20.0f);
                    v.y = TBoss2DeRolLe__data_805D82A8;
                    v.z = v.z + (lbl_805D83F4 * calc_elapsed_scaled__9TObjEneDDFv(self) + TBoss2DeRolLe__data_805D82E4);
                    ((void (*)(void *, void *)) spawn_ceil_junk__13TBoss2DeRolLeFii)(self, &v);
                }
            }
            switch (self->step) {
            case 0:
                self->vy = self->vy - TBoss2DeRolLe__data_805D8300;
                self->z = self->z + self->vy;
                break;
            case 1:
                self->x = self->x + self->vx;
                self->z = self->z + self->vy;
                break;
            case 2:
                self->x = self->x + self->vx;
                self->vy = self->vy + self->ay;
                self->z = self->z + self->vy;
                self->f700 = calc_node_height__13TBoss2DeRolLeFPv(self);
                break;
            case 3:
                self->x = self->x + self->vx;
                self->frame = self->frame - lbl_805D83F8;
                self->f6A4 = self->f6A4 + self->f700;
                self->f700 = self->f700 - self->f704;
                self->z = self->z + self->vy;
                break;
            case 4:
                self->x = self->x + self->vx;
                update_angle__13TBoss2DeRolLeFPv(self);
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f69C;
                break;
            case 5:
                self->x = self->x + self->vx;
                update_angle__13TBoss2DeRolLeFPv(self);
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f69C;
                break;
            case 6:
                update_angle__13TBoss2DeRolLeFPv(self);
                if (advance_scalar_motion_profile(self->mover) == 3) {
                    self->phase = 2;
                }
                self->z = self->vy - self->f69C;
                if (self->fB8 == 1) {
                    self->flags |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        self->mode = self->next_mode;
        self->flags &= ~4;
        break;
    }
}
#undef self
#pragma pop

void TBoss2DeRolLe__sub_800327C8(void *arg0, void *arg1, int arg2, int arg3) {
    s32 r;
    switch ((u32)arg1) {
    case 4:
        o->fB8 = 1;
        ((void (*)(void *))TBoss2DeRolLe__sub_800341F0)(o);
        o->flags &= ~4;
        o->flags |= 0x100;
        o->mode = arg2;
        o->sub = arg3;
        set_position_index__13TBoss2DeRolLeFPvi(o, o->mode);
        o->done = 0;
        o->baseX = o->x;
        o->baseZ = o->z;
        switch (o->mode) {
        case 0:
            o->scaleX = TBoss2DeRolLe__data_805D82BC;
            switch (o->sub) {
            case 2:
                break;
            case 1:
                o->kind = 1;
                break;
            case 3:
                o->kind = 3;
                break;
            }
            break;
        case 1:
            o->kind = 2;
            switch (o->sub) {
            case 1:
                break;
            case 2:
                o->scaleX = TBoss2DeRolLe__data_805D82BC;
                break;
            case 0:
                o->scaleX = TBoss2DeRolLe__data_805D832C;
                break;
            }
            break;
        case 2:
            o->scaleX = TBoss2DeRolLe__data_805D832C;
            switch (o->sub) {
            case 2:
                break;
            case 1:
                o->kind = 1;
                break;
            case 3:
                o->kind = 3;
                break;
            }
            break;
        case 3:
            o->kind = 0;
            switch (o->sub) {
            case 1:
                break;
            case 2:
                o->scaleX = TBoss2DeRolLe__data_805D82BC;
                break;
            case 0:
                o->scaleX = TBoss2DeRolLe__data_805D832C;
                break;
            }
            break;
        }
        switch (o->kind) {
        case 0:
            init_wave_params__13TBoss2DeRolLeFPv(o);
            o->scaleZ = TBoss2DeRolLe__data_805D82BC;
            break;
        case 1:
            init_head_params__13TBoss2DeRolLeFPv(o);
            o->scaleZ = TBoss2DeRolLe__data_805D82BC;
            break;
        case 2:
            init_movement__13TBoss2DeRolLeFPv(o);
            o->scaleZ = TBoss2DeRolLe__data_805D832C;
            break;
        case 3:
            init_move_params__13TBoss2DeRolLeFPv(o);
            o->scaleZ = TBoss2DeRolLe__data_805D832C;
            break;
        }
        break;
    case 2:
        if (o->done == 1) {
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)o, 2);
        }
        break;
    case 9:
        if (o->done == 1) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)o);
        }
        break;
    case 0:
        ((void (*)(void))advance_animation_playback)();
        ((void (*)(void *))TBoss2DeRolLe__sub_800338BC)(o);
        r = 0;
        switch (o->kind) {
        case 0:
            r = TBoss2DeRolLe__sub_80034574(o);
            break;
        case 1:
            r = update_phase_is_done__13TBoss2DeRolLeFPv(o);
            o->z = o->baseZ + o->ampZ;
            break;
        case 2:
            r = TBoss2DeRolLe__sub_80034800(o);
            o->z = o->baseZ - o->ampZ;
            break;
        case 3:
            r = update_state__13TBoss2DeRolLeFPv(o);
            o->z = o->baseZ - o->ampZ;
            break;
        }
        if (r != 0) {
            o->done = 1;
        }
        o->x = o->ampX * o->scaleX + o->baseX;
        o->z = o->ampZ * o->scaleZ + o->baseZ;
        break;
    case 5:
        o->mode = o->sub;
        break;
    }
}
#undef o
#pragma pop

struct Pad_80032B28 { u8 pad[8]; u32 buttons; };
extern const f32 lbl_805D83FC;
#define arg0 ((u8 *)arg0_)
void handle_debug_pad_input__13TBoss2DeRolLeFPvPv(void *arg0_, void *arg1_) {
    u32 arg1 = (u32)arg1_;
    u32 b;

    switch (arg1) {
    case 4:
        ((TBoss2DeRolLe *)arg0)->m_b8 = 1;
        TBoss2DeRolLe__sub_800341F0((Obj_800341F0 *)arg0);
        *(s32 *)((s8 *)arg0 + 0x3C0) &= ~4;
        *(s32 *)((s8 *)arg0 + 0x3C0) |= 0x100;
        *(f32 *)((s8 *)arg0 + 0x6A4) = TBoss2DeRolLe__data_805D827C;
        ((TBoss2DeRolLe *)arg0)->rotation_z = 0;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 1;
        *(s32 *)((s8 *)arg0 + 0x6E8) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        break;
    case 2:
        switch (*(s32 *)((s8 *)arg0 + 0x654)) {
        case 0:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x10) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 3);
            } else if (b & 0x40) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 4);
            } else if (b & 0x20) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 5);
            } else if (b & 0x400) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x12);
            } else if (b & 4) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x10);
            } else if (b & 2) {
                *(f32 *)((s8 *)arg0 + 0x40) = lbl_805D83FC;
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 1);
            }
            break;
        case 1:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x40) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 6);
            } else if (b & 0x20) {
            } else if (b & 0x80) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 8);
            } else if (b & 0x400) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x18);
            } else if (b & 4) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x19);
            } else if (b & 2) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x1E);
            }
            break;
        case 2:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x20) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 9);
            } else if (b & 0x80) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xA);
            } else if (b & 0x10) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xB);
            } else if (b & 0x400) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x13);
            } else if (b & 4) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x11);
            } else if (b & 2) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x1E);
            }
            break;
        case 3:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x80) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xC);
            } else if (b & 0x10) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xD);
            } else if (b & 0x40) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xE);
            } else if (b & 0x400) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0xF);
            } else if (b & 4) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x1A);
            } else if (b & 0x200) {
                if (TObjBoss2Tunnel::is_active() != 0) {
                    TObjBoss2Tunnel::set_global_flag_800();
                } else {
                    TObjBoss2Tunnel::set_global_flag_400();
                }
            } else if (b & 2) {
                set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)arg0, 0x1F);
            }
            break;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        if (!(((TBoss2DeRolLe *)arg0)->animationFlags & 4)) {
            ((TBoss2DeRolLe *)arg0)->m_c8 -= 0.03f;
            if (((TBoss2DeRolLe *)arg0)->m_c8 < 0.6f) {
                ((TBoss2DeRolLe *)arg0)->m_c8 = 0.6f;
            }
        }
        break;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}
#undef arg0

#pragma push
#pragma fp_contract on
#define o ((Rol_80032E38 *)arg0)
void TBoss2DeRolLe__sub_80032E38(void *arg0, void *arg1) {
    Vec_80032E38 *p = &o->f724;
    Cam_80032E38 cam;
    Cam_80032E38 cam2;
    Vec_80032E38 v1;
    Vec_80032E38 v2;
    Vec_80032E38 v3;
    f32 t;
    switch ((u32)arg1) {
    case 4:
        o->fB8 = 0;
        TBoss2DeRolLe__sub_80034258((Obj_80034258 *)o);
        o->f3C0 &= ~4;
        o->f3C0 &= ~0x100;
        o->pos.x = lbl_805D83F0;
        o->f6A4 = TBoss2DeRolLe__data_805D827C;
        o->f64 = 0;
        o->f6E0 = 1;
        o->f6E4 = 0;
        o->f6E8 = 0;
        o->f6FC = TBoss2DeRolLe__data_805D827C;
        p->x = TBoss2DeRolLe__data_805D827C;
        p->y = TBoss2DeRolLe__data_805D827C;
        p->z = TBoss2DeRolLe__data_805D827C;
        if (TObjEneDD::check_v2_mode() != 0) {
            cam.b = 1;
            cam.a = 1;
            cam.c = 0;
            cam.d = TBoss2DeRolLe__data_805D827C;
            cam.e = lbl_805D8408;
            ((s32 (*)(int, f32))activate_camera_mode)(5, TBoss2DeRolLe__data_805D827C);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x1C71);
        } else {
            cam2.b = 0;
            cam2.a = 1;
            cam2.c = 0;
            cam2.d = TBoss2DeRolLe__data_805D827C;
            cam2.e = lbl_805D8408;
            ((s32 (*)(int, f32))activate_camera_mode)(5, TBoss2DeRolLe__data_805D827C);
            ((TCameraCtrl *)(&cam2))->cache_target_and_forward(0x1C71);
        }
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)o)->get_target_state_b();
        break;
    case 2:
        if (o->f6E0 == 5) {
            o->f654 = 0;
            set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)o, 2);
        }
        break;
    case 9:
        if (o->f6E0 == 5) {
            o->f654 = 0;
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)o);
        }
        break;
    case 0:
        if (o->f6E0 == 2) {
            o->fB8 = 1;
            ((void (*)(void *, void *))vec3_add_to)(&o->pos, p);
            set_move_target_point__13TBoss2DeRolLeFPvi((u8 *)o, 0);
            o->f6E0 = 3;
        }
        advance_animation_playback(o);
        switch (o->f6E0) {
        case 0:
            o->f6E8++;
            if (o->f6E8 >= 0x37) {
                o->f6E8 = 0;
                o->f6E0 = 1;
                o->pos.x = TBoss2DeRolLe__data_805D827C;
                o->pos.y = TBoss2DeRolLe__data_805D8348;
                o->pos.z = lbl_805D840C;
                o->f6A4 = TBoss2DeRolLe__data_805D827C;
                o->f64 = 0;
            }
            break;
        case 1:
            get_node_world_pos__13TBoss2DeRolLeFPvPv((u8 *)o, (u8 *)p);
            o->f6E4++;
            t = o->fC0;
            if (t >= lbl_805D8410 && t <= lbl_805D8414) {
                if ((f32)o->f6E4 >= TBoss2DeRolLe__data_805D82F0) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v1, &o->pos);
                    ((void (*)(void *, void *))vec3_add_to)(&v1, p);
                    v1.x += TBoss2DeRolLe__data_805D82DC * calc_elapsed_scaled__9TObjEneDDFv(o);
                    v1.y = TBoss2DeRolLe__data_805D82A8;
                    v1.z += lbl_805D83F0;
                    ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &v1);
                }
            } else if (t >= lbl_805D83E4 && t <= lbl_805D8418) {
                if ((f32)o->f6E4 >= TBoss2DeRolLe__data_805D82A0) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v2, &o->pos);
                    ((void (*)(void *, void *))vec3_add_to)(&v2, p);
                    v2.x += TBoss2DeRolLe__data_805D82A4 * calc_elapsed_scaled__9TObjEneDDFv(o);
                    v2.y = TBoss2DeRolLe__data_805D82A8;
                    v2.z += TBoss2DeRolLe__data_805D82A4;
                    ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &v2);
                }
            } else if (t >= lbl_805D841C && t <= lbl_805D8340 && (f32)o->f6E4 >= TBoss2DeRolLe__data_805D82A0) {
                o->f6E4 = 0;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v3, &o->pos);
                ((void (*)(void *, void *))vec3_add_to)(&v3, p);
                v3.x += TBoss2DeRolLe__data_805D82DC * calc_elapsed_scaled__9TObjEneDDFv(o);
                v3.y = TBoss2DeRolLe__data_805D82A8;
                v3.z += lbl_805D83F0;
                ((void (*)(void *, void *))spawn_ceil_junk__13TBoss2DeRolLeFii)(o, &v3);
            }
            if (objInBand__FP7GameObjf(o, lbl_805D8420) != 0 || objInBand__FP7GameObjf(o, lbl_805D8424) != 0) {
                play_sound_effect((void *)0x4003AD11, 0, 0, 0);
            } else if (objInBand__FP7GameObjf(o, lbl_805D8428) != 0) {
                play_sound_effect((void *)0x4003AD12, 0, 0, 0);
            }
            if (o->fC0 >= lbl_805D8410) {
                o->pos.x -= TBoss2DeRolLe__data_805D82BC;
            } else if (o->fC0 >= lbl_805D82F4) {
                o->pos.x -= TBoss2DeRolLe__data_805D82D8;
            }
            if (get_flag_b4__9TObjEneDDFv(o) != 0) {
                o->f6E0 = 2;
                o->f3C0 |= 0x100;
            }
            break;
        case 2:
            break;
        case 3:
            o->pos.x = TBoss2DeRolLe__data_805D82F0 * o->f3A0 + o->pos.x;
            o->pos.z = TBoss2DeRolLe__data_805D82F0 * o->f3A8 + o->pos.z;
            o->f6FC += TBoss2DeRolLe__data_805D82F0;
            if (o->f6FC >= o->f3AC) {
                o->f6E0 = 4;
            }
            break;
        case 4:
            if (get_scripted_camera_playback()->h2 & 1) {
                restore_player_cameras();
                o->f6E0 = 5;
            }
            break;
        }
        break;
    case 5:
        restore_player_cameras();
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)o)->get_target_state_a();
        break;
    }
}
#undef o
#pragma pop

void TBoss2DeRolLe__sub_800333F4(Obj_800333F4 *self, u32 arg1) {
    switch (arg1) {
    case 4: self->f_B8 = 1; return;
    case 2: set_state_and_send__13TBoss2DeRolLeFPvi((Obj_80034034 *)(self), 1); return;
    case 0: ((s32 (*)(void *))advance_animation_playback)(self); return;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void dispatch_action__13TBoss2DeRolLeFiUii(s32 arg0, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        TBoss2DeRolLe__sub_800333F4((Obj_800333F4 *)(arg0), arg2);
        return;
    case 1:
        TBoss2DeRolLe__sub_80032E38((void *)arg0, (void *)arg2);
        return;
    case 2:
        handle_debug_pad_input__13TBoss2DeRolLeFPvPv((void *)arg0, (void *)arg2);
        return;
    case 3:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 0, 1);
        return;
    case 4:
        TBoss2DeRolLe__sub_800320B4((void *)arg0, (void *)arg2, 0, 2);
        return;
    case 5:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 0, 3);
        return;
    case 6:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 1, 2);
        return;
    case 8:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 1, 0);
        return;
    case 9:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 2, 3);
        return;
    case 10:
        TBoss2DeRolLe__sub_800320B4((void *)arg0, (void *)arg2, 2, 0);
        return;
    case 11:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 2, 1);
        return;
    case 12:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 3, 0);
        return;
    case 13:
        TBoss2DeRolLe__sub_80031AD4((void *)arg0, (void *)arg2);
        return;
    case 14:
        TBoss2DeRolLe__sub_800327C8((void *)arg0, (void *)arg2, 3, 2);
        return;
    case 18:
        TBoss2DeRolLe__sub_800313F8((DR_800313F8 *)(arg0), arg2, 0);
        return;
    case 19:
        TBoss2DeRolLe__sub_800313F8((DR_800313F8 *)(arg0), arg2, 2);
        return;
    case 20:
        TBoss2DeRolLe__sub_800310F8((void *)arg0, (void *)arg2, 0);
        return;
    case 21:
        TBoss2DeRolLe__sub_800310F8((void *)arg0, (void *)arg2, 2);
        return;
    case 22:
        TBoss2DeRolLe__sub_80030DFC((void *)arg0, (void *)arg2, 0);
        return;
    case 23:
        TBoss2DeRolLe__sub_80030DFC((void *)arg0, (void *)arg2, 2);
        return;
    case 16:
        ((s32 (*)(void *, void *, int))TBoss2DeRolLe__sub_80030898)((void *)arg0, (void *)arg2, 0);
        return;
    case 17:
        ((s32 (*)(void *, void *, int))TBoss2DeRolLe__sub_80030898)((void *)arg0, (void *)arg2, 2);
        return;
    case 15:
        ((s32 (*)(void *, void *))TBoss2DeRolLe__sub_80030A38)((void *)arg0, (void *)arg2);
        return;
    case 24:
        TBoss2DeRolLe__sub_80030720((Obj_80030720 *)(arg0), arg2, 0x18);
        return;
    case 25:
        TBoss2DeRolLe__sub_80030720((Obj_80030720 *)(arg0), arg2, 0x19);
        return;
    case 26:
        ((s32 (*)(void *, void *))state_ceiling_attack__13TBoss2DeRolLeFPvUi)((void *)arg0, (void *)arg2);
        return;
    case 27:
        TBoss2DeRolLe__sub_8002FE60((void *)arg0, (u32)arg2);
        return;
    case 28:
        TBoss2DeRolLe__sub_8002FD9C((DeRolLe_8002FD9C *)(arg0), arg2, 0);
        return;
    case 29:
        TBoss2DeRolLe__sub_8002FD9C((DeRolLe_8002FD9C *)(arg0), arg2, 1);
        return;
    case 30:
        TBoss2DeRolLe__sub_8002FCE4((Obj_8002FCE4 *)(arg0), arg2);
        return;
    case 31:
        handle_death_state__13TBoss2DeRolLeFPvPv((void *)arg0, (void *)arg2);
        return;
    case 32:
        TBoss2DeRolLe__sub_8002F73C((Obj_8002F73C *)(arg0), arg2);
    default:
        return;
    }
}

#pragma push
#pragma fp_contract on
#pragma dont_inline off
#pragma inline_depth(4)
static inline u32 pack_80033684(u32 a, u32 r, u32 g, u32 b) { u32 c = a << 24; c |= r << 16; c |= g << 8; c |= b; return c; }
static inline u32 swap_80033684(u32 x) {
    u32 t = x >> 16;
    t = __rlwimi(t, x, 16, 0, 7);
    t = __rlwimi(t, x, 16, 8, 15);
    return t;
}
void update_pulsing_colors__13TBoss2DeRolLeFPv(u8 *arg0) {
    s32 i;
    f32 t;
    u8 v;
    u32 c;
    f32 add;
    f32 mul;
    f32 scale;
    f32 half;
    f32 wrap;
    f32 step;
    f32 ph;
    t = *(f32 *)((s8 *)arg0 + 0x6D4);
    if (t > TBoss2DeRolLe__data_805D82BC) {
        t = TBoss2DeRolLe__data_805D82A0 - t;
    }
    v = __cvt_fp2unsigned(lbl_805D842C * (TBoss2DeRolLe__data_805D8328 * t + TBoss2DeRolLe__data_805D8334));
    c = swap_80033684(pack_80033684(0xFF, v, 0, v >> 2));
    *boss2_derolle_primary_color_targets[0] = c;
    *boss2_derolle_primary_color_targets[2] = c;
    *boss2_derolle_primary_color_targets[1] = swap_80033684(pack_80033684(0xFF, v, v, 0));
    step = TBoss2DeRolLe__data_805D8300;
    wrap = TBoss2DeRolLe__data_805D82A0;
    half = TBoss2DeRolLe__data_805D82BC;
    scale = lbl_805D842C;
    mul = TBoss2DeRolLe__data_805D8328;
    ph = *(f32 *)((s8 *)arg0 + 0x6D4);
    add = TBoss2DeRolLe__data_805D8334;
    for (i = 0; i < 10; i++) {
        ph += step;
        if (ph > wrap) {
            ph -= wrap;
        }
        t = ph;
        if (ph > half) {
            t = TBoss2DeRolLe__data_805D82A0 - ph;
        }
        v = __cvt_fp2unsigned(scale * (mul * t + add));
        *boss2_derolle_segment_color_targets[i] = swap_80033684(pack_80033684(0xFF, v, v, 0));
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void advance_phase_wrap__13TBoss2DeRolLeFPv(u8 *arg0) {
    f32 temp_f1;
    *(f32 *)((s8 *)arg0 + 0x6D4) = (f32) (*(f32 *)((s8 *)arg0 + 0x6D4) + *(f32 *)((s8 *)arg0 + 0x6D8));
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x6D4);
    if (temp_f1 >= TBoss2DeRolLe__data_805D82A0) {
        *(f32 *)((s8 *)arg0 + 0x6D4) = (f32) (temp_f1 - TBoss2DeRolLe__data_805D82A0);
    }
}
extern int fold_flush_1;
#pragma pop

int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2) { return play_persistent_sound((s32)p, (a1), (a2), 0, 0); }

int play_sound(void* p, int a1) { return play_sound_effect(p, a1, 0, 0); }

void TBoss2DeRolLe__sub_800338BC(void) {  }

void update_projectile_spawns__13TBoss2DeRolLeFPv(u8 *arg0) {
    u8 *temp_r31;

    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x518), TBoss2DeRolLe__data_805D8280);
    project_sound_origin_from_camera((s32)(arg0 + 0x4D0), (u8 *)(arg0 + 0x524), TBoss2DeRolLe__data_805D8280);
    temp_r31 = arg0 + 0x530;
    VecCopy__FP3VecPC3Vec((int)temp_r31, arg0 + 0x524);
    vec3_add_to((int)temp_r31, arg0 + 0x524);
    *(f32 *)((s8 *)temp_r31 + 0) = (f32) (*(f32 *)((s8 *)temp_r31 + 0) * TBoss2DeRolLe__data_805D8288);
    *(f32 *)((s8 *)temp_r31 + 4) = (f32) (*(f32 *)((s8 *)temp_r31 + 4) * TBoss2DeRolLe__data_805D8288);
    *(f32 *)((s8 *)temp_r31 + 8) = (f32) (*(f32 *)((s8 *)temp_r31 + 8) * TBoss2DeRolLe__data_805D8288);
    if ((*(s32 *)((s8 *)arg0 + 0x3C0) & 0x100) && ((objInBand__FP7GameObjf(arg0, TBoss2DeRolLe__data_805D82F0) != 0) || (objInBand__FP7GameObjf(arg0, TBoss2DeRolLe__data_805D8294) != 0))) {
        *(s32 *)((s8 *)arg0 + 0x53C) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x53C) <= 0x10) {
        play_persistent_sound(0x4003AD00, (s32)arg0, (u32)(arg0 + 0x530), 0, 0);
        *(s32 *)((s8 *)arg0 + 0x53C) = (s32) (*(s32 *)((s8 *)arg0 + 0x53C) + 1);
    }
}

#pragma push
#pragma fp_contract on
void spawn_offset_particle__13TBoss2DeRolLeFiff(s32 arg0, f32 farg0, f32 farg1) {
    typedef char sp8_offset[(offsetof(Stack_800339BC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800339BC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800339BC, sp10) == 0x8) ? 1 : -1];
    Stack_800339BC stack;
    VecCopy__FP3VecPC3Vec((int)((void *)&stack.sp8), (void *)arg0);
    stack.sp8 = -((*(f32 *)((s8 *)&lbl_804FF5E8.value + 0xC) * farg1) - stack.sp8);
    stack.spC -= (*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x10) * farg1) - farg0;
    stack.sp10 = -((*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x14) * farg1) - stack.sp10);
    spawn_particle_effect_with_flags((&stack.sp8), 0x127, 0x40);
}
extern int fold_flush_2;
#pragma pop

void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, s32 arg2) {
    create_particle__17TObjBoss2CeilJunkFv(arg2, 0x121);
}

void TBoss2DeRolLe__sub_80033A80(s32 arg0, s32 arg1) {
    TObjBoss2Tunnel__sub_8003B1D8((void *)arg1);
}

#pragma push
#pragma fp_contract on
void update_particle_ctrls__13TBoss2DeRolLeFPv(Obj_80033AA4 *o) {
    Vec_80033AA4 t;
    Vec3i_80033AA4 ang;
    s32 ok;
    s32 j;
    s32 i;
    s32 k;
    void *p;
    s32 m;
    s32 n;
    ok = 1;
    for (i = 0; i < 6; i++) {
        if (o->ctl[i] == NULL) {
            ang.z = 0;
            ang.y = 0;
            ang.x = 0;
            p = create_particle_controller_with_angles(o->pos, &ang, 0x120, 1, 0x40);
            if (p != NULL) {
                o->ctl[i] = p;
                ((TBoss4Type2 *)(o->ctl[i]))->set_flags(2);
                ((TParticleCtrl *)(o->ctl[i]))->enable();
            } else {
                for (j = 0; j < i; j++) {
                    ((TParticleCtrl *)(o->ctl[j]))->enable();
                }
                ok = 0;
                break;
            }
        }
    }
    if (ok != 0) {
        if (o->f758 == 0) {
            for (k = 0; k < 3; k++) {
                Vec_80033AA4 *v = &o->pos[boss2_derolle_particle_node_indices[k]];
                f32 r = fabs_float(v->y - lbl_805D82E0);
                f32 lim = boss2_derolle_particle_limits[k];
                if (r < TBoss2DeRolLe__data_805D8328 * lim) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&t, v);
                    lim -= r;
                    t.y = TBoss2DeRolLe__data_805D82A8;
                    t.x += lim;
                    ((TNowLoading *)(o->ctl[k * 2]))->copy_pos(&t);
                    t.x -= TBoss2DeRolLe__data_805D82A0 * lim;
                    ((TNowLoading *)(o->ctl[k * 2 + 1]))->copy_pos(&t);
                } else {
                    ((TParticleCtrl *)(o->ctl[k * 2]))->enable();
                    ((TParticleCtrl *)(o->ctl[k * 2 + 1]))->enable();
                }
            }
        } else {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&t, &o->pos[o->f758]);
            t.y = TBoss2DeRolLe__data_805D82A8;
            t.x += TBoss2DeRolLe__data_805D8294;
            ((TNowLoading *)(o->ctl[0]))->copy_pos(&t);
            t.x -= TBoss2DeRolLe__data_805D82A4;
            ((TNowLoading *)(o->ctl[1]))->copy_pos(&t);
            for (m = 2; m < 6; m++) {
                ((TParticleCtrl *)(o->ctl[m]))->enable();
            }
            o->f758 = 0;
        }
        for (n = 0; n < 6; n++) {
            ((void (*)(void *, void *))TBoss2DeRolLe__sub_80033A80)(o, o->ctl[n]);
        }
    }
}
#pragma pop

void advance_action_sequence__13TBoss2DeRolLeFPv(Obj_80034034 *self) {
    s32 retry;
    s32 mode;
    do {
        retry = 0;
        (*(s32 *)((s8 *)self + 0x3D4))++;
        if (TObjEneDD::check_v2_mode() != 0) {
            mode = derolle_action_sequence_table[*(s32 *)((s8 *)self + 0x3D4)];
        } else {
            mode = derolle_action_mode_sequence_table[*(s32 *)((s8 *)self + 0x3D4)];
        }
        switch (mode) {
        case 33:
            if (calc_elapsed_scaled__9TObjEneDDFv(self) > TBoss2DeRolLe__data_805D827C) {
                mode = 8;
            } else {
                mode = 6;
            }
            break;
        case 34:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 5;
            } else {
                mode = 9;
            }
            break;
        case 35:
            if (calc_elapsed_scaled__9TObjEneDDFv(self) > TBoss2DeRolLe__data_805D827C) {
                mode = 0xC;
            } else {
                mode = 0xE;
            }
            break;
        case 36:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 3;
            } else {
                mode = 0xB;
            }
            break;
        case 37:
            if (calc_elapsed_scaled__9TObjEneDDFv(self) > TBoss2DeRolLe__data_805D827C) {
                mode = 0x18;
            } else {
                mode = 0x19;
            }
            break;
        case 39:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 4;
            } else {
                mode = 0xA;
            }
            break;
        case 40:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 0x10;
            } else {
                mode = 0x11;
            }
            break;
        case 41:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 0x12;
            } else {
                mode = 0x13;
            }
            break;
        case 42:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 0x14;
            } else {
                mode = 0x15;
            }
            break;
        case 43:
            if (*(s32 *)((s8 *)self + 0x658) == 0) {
                mode = 0x16;
            } else {
                mode = 0x17;
            }
            break;
        case 44:
            retry = 1;
            *(s32 *)((s8 *)self + 0x3D4) = 5;
            break;
        }
    } while (retry != 0);
    set_state_and_send__13TBoss2DeRolLeFPvi(self, mode);
}

void reset_fields_3d0__13TBoss2DeRolLeFPv(void* p) { *(s32*)((char*)p + 0x3d0) = 0; *(s32*)((char*)p + 0x3d4) = 0; }

void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    enemy_set_target_id(arg0, (u16) *(s32 *)((s8 *)arg1 + 8));
    *(s32 *)((s8 *)arg0 + 0x3D4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)arg0)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg0 + 0x3D4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)arg0)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0) {
    void *x;
    swap_endian__13TBoss2DeRolLeFPv(arg0);
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        set_params__13TBoss2DeRolLeFPvPv(x, arg0);
    }
}

void handle_6x13_de_rol_le_boss_actions(void *arg0) {
    void *x;
    swap_6x13_fields__13TBoss2DeRolLeFPv(arg0);
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        init_from_param__13TBoss2DeRolLeFPvPv(x, arg0);
    }
}

void TBoss2DeRolLe__sub_80034034(Obj_80034034 *self) {
    s16 st = self->f326;
    if (st != 0x1f && st != 0x20) {
        if (st == 0x14 || st == 0x15) {
            advance_action_sequence__13TBoss2DeRolLeFPv((Obj_80034034 *)(self));
        } else if (st == 0x16 || st == 0x17) {
            set_state_and_send__13TBoss2DeRolLeFPvi(self, 0x1f);
        } else {
            set_state_and_send__13TBoss2DeRolLeFPvi(self, 0x1e);
        }
    }
}

u8 is_ready__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0) {
    int var_r4;

    var_r4 = 0;
    if (((s32) arg0->m_6c8 <= 0) && !(*(s32 *)((s8 *)arg0 + 0x3C0) & 4)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}

void TBoss2DeRolLe::clear_play_flags() {
    void *temp_r3;
    void *temp_r4;

    temp_r4 = this->m_a4;
    *(s32 *)((s8 *)temp_r4 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x44) & 0xFFFFFFFE);
    temp_r3 = this->m_a4;
    *(s32 *)((s8 *)temp_r3 + 0x70) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x70) & 0xFFFFFFFE);
}

void set_flags_play_sound__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x88);
    ((s32 (*)(void))clear_play_flags__13TBoss2DeRolLeFv)();
    ((s32 (*)(s32, void *))play_sound)(0x4003AA06, arg0 + 0x38);
}

void apply_hp_damage_with_sound__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x6AC) = (s32) (*(s32 *)((s8 *)arg0 + 0x6AC) - (s32) (TBoss2DeRolLe__data_805D8288 * (f32) arg1));
    ((s32 (*)(s32, void *))play_sound)(0x4003A80F, arg0 + 0x38);
}

void update_check__13TBoss2DeRolLeFPv(void *arg0) {
    vfunc_93__9TObjEneDDFv();
    if ((*(s32 *)((s8 *)arg0 + 0x3C0) & 8) || (TObjEneDD::check_v2_mode() != 0)) {
        ((s32 (*)(void *))clear_play_flags__13TBoss2DeRolLeFv)(arg0);
    }
}

void TBoss2DeRolLe__sub_800341F0(Obj_800341F0 *self) {
    s32 i;
    self->m94();
    for (i = 0; i < 10; i++) {
        self->parts[i]->m94();
    }
}

void TBoss2DeRolLe__sub_80034258(Obj_80034258 *self) {
    s32 i;
    self->m93();
    for (i = 0; i < 10; i++) {
        self->parts[i]->m93();
    }
}

void pick_random_target__13TBoss2DeRolLeFi(s32 actor) {
    s32 n;
    s32 p;
    s32 j;
    s32 i;

    n = TLobby::get_game_mode();
    if (n == 0) {
        enemy_clear_target__12TObjEneDD_STFUs((void *)actor);
        return;
    }
    if (n == 1) {
        p = get_player_data__10TObjPlayerFi(0);
        ((TObjEneDD_ST *)actor)->set_target_player((void *)p);
        return;
    }
    j = (s32) get_random_float__21TObjEneMe3ShinowaRealFv((f32) n * calc_boss4_scale__10TObjPlayerFi((void *)actor));
    enemy_clear_target__12TObjEneDD_STFUs((void *)actor);
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(j);
        if (is_alive__9TObjEneDDFv() != 0) {
            ((TObjEneDD_ST *)actor)->set_target_player((void *)p);
            return;
        }
        if (++j >= n) {
            j = 0;
        }
    }
}

#undef TBoss2DeRolLe__sub_80034574
#undef init_wave_params__13TBoss2DeRolLeFPv
#undef update_state__13TBoss2DeRolLeFPv
#undef init_move_params__13TBoss2DeRolLeFPv
#undef TBoss2DeRolLe__sub_80034800
#undef init_movement__13TBoss2DeRolLeFPv
#undef update_phase_is_done__13TBoss2DeRolLeFPv
#undef TBoss2DeRolLe__sub_800344A4

#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define play_sound_effect ((void (*)(s32, Vec_800344A4 *, s32, s32))play_sound_effect)
s32 advance_scalar_motion_profile(void *);
extern const f32 TBoss2DeRolLe__data_805D8280;
extern const f32 TBoss2DeRolLe__data_805D8328;
extern const f32 TBoss2DeRolLe__data_805D8334;
extern const f32 lbl_805D8438;
extern const f32 lbl_805D843C;
u8 TBoss2DeRolLe__sub_80034800(u8 *arg0);
extern const f32 TBoss2DeRolLe__data_805D82DC;
void calc_offset_position__13TBoss2DeRolLeFPv(u8 *arg0);
s32 advance_scalar_motion_profile(void *);
extern const f32 TBoss2DeRolLe__data_805D8328;
extern const f32 TBoss2DeRolLe__data_805D8334;
extern const f32 lbl_805D8440;
u8 update_phase_is_done__13TBoss2DeRolLeFPv(u8 *arg0);
void *__ct__15TBoss2PhotonPadFv(void *, void *, Vec_800344A4 *, Vec_800344A4 *, s32);
void *__nw__7TObjectFUl(u32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D832C;
void TBoss2DeRolLe__sub_800344A4(DeRolLe_800344A4 *self, s32 idx, s32 arg2);
s32 advance_scalar_motion_profile(void *);
u8 TBoss2DeRolLe__sub_80034574(u8 *arg0);
void activate_laser_light__13TBoss2DeRolLeFPv(void *arg0);
void init_move_params__13TBoss2DeRolLeFPv(u8 *arg0);
void init_movement__13TBoss2DeRolLeFPv(u8 *arg0);
void init_wave_params__13TBoss2DeRolLeFPv(u8 *arg0);
u8 update_state__13TBoss2DeRolLeFPv(u8 *arg0);
s32 advance_scalar_motion_profile(void *);
void TBoss2LaserLight__sub_80037474(void *p);
void TBoss2LaserLight__sub_80037480(void *p);
f32 fabs_float(f32);
void init_params__13TBoss2DeRolLeFPvfff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2);

void free_laser__13TBoss2DeRolLeFPv(void *arg0, s32 _w1) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x6B8) != 0U) {
        TBoss2LaserLight__sub_80037474(*(void **)((s8 *)arg0 + 0x6B8));
    }
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFEF);
}

void activate_laser_light__13TBoss2DeRolLeFPv(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x6B8) != 0U) {
        TBoss2LaserLight__sub_80037480(*(void **)((s8 *)arg0 + 0x6B8));
    }
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x10);
}

extern const f32 TBoss2DeRolLe__data_805D82D8;
extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 TBoss2DeRolLe__data_805D8330;
extern const f32 TBoss2DeRolLe__data_805D8358;
extern const f32 TBoss2DeRolLe__data_805D83DC;

#pragma push
#pragma fp_contract on
void calc_offset_position__13TBoss2DeRolLeFPv(u8 *arg0) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x6BC, arg0 + 0x4E8);
    *(f32 *)((s8 *)arg0 + 0x6BC) = (f32) ((TBoss2DeRolLe__data_805D82DC * *(f32 *)((s8 *)arg0 + 0x4F4)) + *(f32 *)((s8 *)arg0 + 0x6BC));
    *(f32 *)((s8 *)arg0 + 0x6C0) = (f32) ((TBoss2DeRolLe__data_805D82DC * *(f32 *)((s8 *)arg0 + 0x4F8)) + *(f32 *)((s8 *)arg0 + 0x6C0));
    *(f32 *)((s8 *)arg0 + 0x6C4) = (f32) ((TBoss2DeRolLe__data_805D82DC * *(f32 *)((s8 *)arg0 + 0x4FC)) + *(f32 *)((s8 *)arg0 + 0x6C4));
}
#pragma pop

void TBoss2DeRolLe__sub_800344A4(DeRolLe_800344A4 *self, s32 idx, s32 arg2) {
    Vec_800344A4 v;
    s32 ang;
    void *p;
    ang = 0x3800 - idx * 0x33;
    v.x = sin_table_lookup(ang);
    v.y = TBoss2DeRolLe__data_805D827C;
    v.z = cos_table_lookup(ang);
    if (self->mode == 2) {
        v.x *= TBoss2DeRolLe__data_805D832C;
    }
    p = __nw__7TObjectFUl(0x38);
    if (p != NULL) {
        __ct__15TBoss2PhotonPadFv(p, self->unk3D8, &self->pts[idx], &v, arg2);
    }
    play_sound_effect(0x4003B708, &self->pts[idx], 0, 1);
    ((TBoss2Joint *)(self->joints[idx]))->call_36A90_with_1();
}

u8 TBoss2DeRolLe__sub_80034574(u8 *arg0) {
    f32 var_f2;
    advance_scalar_motion_profile(arg0 + 0x664);
    switch (*(s32 *)((s8 *)arg0 + 0x660)) {
    case 2:
        break;
    case 1:
        var_f2 = *(f32 *)((s8 *)arg0 + 0x694) - 0.1f;
        if (var_f2 < -4.0f) {
            var_f2 = -4.0f;
        }
        *(f32 *)((s8 *)arg0 + 0x694) = var_f2;
        *(f32 *)((s8 *)arg0 + 0x69C) = (f32) (*(f32 *)((s8 *)arg0 + 0x69C) + var_f2);
        if (*(f32 *)((s8 *)arg0 + 0x67C) > 30.0f) {
            *(s32 *)((s8 *)arg0 + 0x660) = 3;
        }
        break;
    case 3:
        if (advance_scalar_motion_profile(arg0 + 0x684) == 3) {
            *(s32 *)((s8 *)arg0 + 0x660) = 4;
        }
        break;
    }
    *(f32 *)((s8 *)arg0 + 0xC8) += 0.1f;
    if (*(f32 *)((s8 *)arg0 + 0xC8) > 0.9f) {
        *(f32 *)((s8 *)arg0 + 0xC8) = 0.9f;
    }
    return (u8) (*(s32 *)((s8 *)arg0 + 0x660) == 4);
}

void init_wave_params__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x660) = 1;
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x664, TBoss2DeRolLe__data_805D82F0, fabs_float(TBoss2DeRolLe__data_805D83DC - *(f32 *)((s8 *)arg0 + 0x38)), TBoss2DeRolLe__data_805D8330);
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x684, TBoss2DeRolLe__data_805D82D8, fabs_float(TBoss2DeRolLe__data_805D8358 - *(f32 *)((s8 *)arg0 + 0x40)), TBoss2DeRolLe__data_805D8330);
}

extern const f32 TBoss2DeRolLe__data_805D8280;
extern const f32 TBoss2DeRolLe__data_805D82B4;
extern const f32 TBoss2DeRolLe__data_805D8328;

u8 update_state__13TBoss2DeRolLeFPv(u8 *arg0) {

    advance_scalar_motion_profile(arg0 + 0x684);
    switch (*(s32 *)((s8 *)arg0 + 0x65C)) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0xC8) = (f32) TBoss2DeRolLe__data_805D8280;
        if (*(f32 *)((s8 *)arg0 + 0x69C) > TBoss2DeRolLe__data_805D82B4) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(arg0 + 0x664) == 3) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 2;
        }
        break;
    }
    if (*(f32 *)((s8 *)arg0 + 0x69C) > TBoss2DeRolLe__data_805D82B4) {
        *(f32 *)((s8 *)arg0 + 0xC8) = (f32) TBoss2DeRolLe__data_805D8328;
    }
    return (u8) (*(s32 *)((s8 *)arg0 + 0x65C) == 2);
}

extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D8330;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 TBoss2DeRolLe__data_805D83AC;
extern const f32 lbl_805D8434;

void init_move_params__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x65C) = 0;
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x664, TBoss2DeRolLe__data_805D82F0, fabs_float(-*(f32 *)((s8 *)arg0 + 0x38)), TBoss2DeRolLe__data_805D8330);
    set_move_params__13TBoss2DeRolLeFPvffff(arg0 + 0x684, TBoss2DeRolLe__data_805D8348, fabs_float(lbl_805D8434 - *(f32 *)((s8 *)arg0 + 0x40)), TBoss2DeRolLe__data_805D8300, TBoss2DeRolLe__data_805D83AC);
}

extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 TBoss2DeRolLe__data_805D8300;
extern const f32 TBoss2DeRolLe__data_805D8330;
extern const f32 TBoss2DeRolLe__data_805D8348;
extern const f32 TBoss2DeRolLe__data_805D8358;
extern const f32 TBoss2DeRolLe__data_805D83AC;
extern const f32 TBoss2DeRolLe__data_805D83DC;

u8 TBoss2DeRolLe__sub_80034800(u8 *arg0) {
  const f32 *new_var;
  advance_scalar_motion_profile(arg0 + 0x664);
  switch (*((s32 *) (((s8 *) arg0) + 0x660)))
  {
    case 0:
      if ((*((f32 *) (((s8 *) arg0) + 0x67C))) > lbl_805D8438)
    {
      *((s32 *) (((s8 *) arg0) + 0x660)) = 2;
    }
      break;
    case 2:
      *((f32 *) (((s8 *) arg0) + 0xC8)) = (f32) TBoss2DeRolLe__data_805D8280;
      *((s32 *) (((s8 *) arg0) + 0x660)) = 3;
      break;
    case 3:
      if (advance_scalar_motion_profile(arg0 + 0x684) == 3)
    {
      *((s32 *) (((s8 *) arg0) + 0x660)) = 4;
    }
      if ((*((f32 *) (((s8 *) arg0) + 0x69C))) > lbl_805D843C)
    {
      *((f32 *) (((s8 *) arg0) + 0xC8)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0xC8))) + TBoss2DeRolLe__data_805D8334);
      if ((*((f32 *) (((s8 *) arg0) + 0xC8))) > (*(new_var = &TBoss2DeRolLe__data_805D8328)))
      {
        *((f32 *) (((s8 *) arg0) + 0xC8)) = (f32) (*new_var);
      }
    }
      break;
  }
  return (u8) ((*((s32 *) (((s8 *) arg0) + 0x660))) == 4);
}

void init_movement__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x660) = 0;
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x664, TBoss2DeRolLe__data_805D82F0, fabs_float(TBoss2DeRolLe__data_805D83DC - *(f32 *)((s8 *)arg0 + 0x38)), TBoss2DeRolLe__data_805D8330);
    set_move_params__13TBoss2DeRolLeFPvffff(arg0 + 0x684, TBoss2DeRolLe__data_805D8348, fabs_float(TBoss2DeRolLe__data_805D8358 - *(f32 *)((s8 *)arg0 + 0x40)), TBoss2DeRolLe__data_805D8300, TBoss2DeRolLe__data_805D83AC);
}
#pragma push
#pragma opt_common_subs off
u8 update_phase_is_done__13TBoss2DeRolLeFPv(u8 *arg0) {
    advance_scalar_motion_profile(arg0 + 0x684);
    switch (*(s32 *)((s8 *)arg0 + 0x65C)) {
    case 0:
        if (*(f32 *)((s8 *)arg0 + 0x69C) > lbl_805D8440) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(arg0 + 0x664) == 3) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 2;
        }
        break;
    }
    *(f32 *)((s8 *)arg0 + 0xC8) = (f32) (*(f32 *)((s8 *)arg0 + 0xC8) + TBoss2DeRolLe__data_805D8334);
    if (*(f32 *)((s8 *)arg0 + 0xC8) > TBoss2DeRolLe__data_805D8328) {
        *(f32 *)((s8 *)arg0 + 0xC8) = (f32) TBoss2DeRolLe__data_805D8328;
    }
    return (u8) (*(s32 *)((s8 *)arg0 + 0x65C) == 2);
}
#pragma pop

}

#undef VecCopy__FP3VecPC3Vec
#undef play_sound_effect

}
#pragma pop

#pragma push
namespace joint_state_view {

struct VBase18 { char pad[0x18]; };

struct VObj18 : VBase18 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(void *, f32);
};


struct RecoveredGlobal_80034C90_lbl_8043567C {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80034C2C_lbl_8043567C {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredFields_80034C2C_arg0 {
    u8 unknown_0[0x3AC];
    f32 field_3AC;
};

struct Stack_80034AC8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80034AC8_lbl_804359CC {
    s32 value;
    u8 remaining[0x8];
};

struct Vec3_80034B60 { f32 x, y, z; };

struct Obj_80034B60 { u8 pad0[0x34]; s32 f34; u8 pad1[0xC0 - 0x38]; f32 fC0; u8 pad2[0xF8 - 0xC4]; s32 fF8; };

struct Base_80034E90 { char pad[0x18]; };

struct Obj_80034E90 : Base_80034E90 {
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
    virtual void m85(s32, s32);
    u8 pad1c[0x1C - 0x1C];
};

struct Pkt8_80034E90 { u8 hdr[2]; u16 a; s16 b; s16 c; };

struct Pkt16_80034E90 { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; };

struct Fld_80034E90 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x38C - 0x1E]; u16 f38C; u8 pad2[0x3D4 - 0x38E]; s32 f3D4; };

extern "C" {
f32 TBoss2DeRolLe__sub_80034CEC(void);
f32 TBoss2DeRolLe__sub_80034CF8(void);
extern u8 *TBoss2DeRolLe__instance;
void forward_switch_phase_stats__13TBoss2DeRolLeFi(s32 arg0);
extern f32 TBoss2DeRolLe__data_805D82BC;
void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
s32 update_local_colliders_from_world(s32, Vec *);
void update_colliders_from_offsets__13TBoss2DeRolLeFi(s32 arg0);
int play_sound(void *, int);
void spawn_offset_particle__13TBoss2DeRolLeFiff(s32, f32, f32);
void set_flags_play_sound__13TBoss2DeRolLeFPv(u8 *arg0);
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 lbl_805D8448;
void apply_damage_taken__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
extern RecoveredGlobal_80034C90_lbl_8043567C TBoss2DeRolLe__position_point_table;
extern const f32 TBoss2DeRolLe__data_805D827C;
void set_position_index__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
f32 subtract_vector(void *, void *);
extern RecoveredGlobal_80034C90_lbl_8043567C TBoss2DeRolLe__position_point_table;
void set_move_target_point__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
void bind_motion_context(s32 arg0, f32 farg0);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 set_matrix_identity(int);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(void *);
extern const RecoveredGlobal_80034AC8_lbl_804359CC lbl_804359CC;
extern const f32 TBoss2DeRolLe__data_805D827C;
void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
void bind_motion_context(s32 arg0, f32 farg0);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern u8 identity_matrix[];
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D82A0;
f32 calc_node_height__13TBoss2DeRolLeFPv(Obj_80034B60 *self);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, s32, s32, s32);
extern s32 TBoss2DeRolLe__attack_params_table[];
extern s32 TBoss2DeRolLe__base_params[2];
extern s32 TBoss2DeRolLe__resistance_params[2];
void reload_stats_for_phase__13TBoss2DeRolLeFPvi(void *self, s32 kind);
s32 send_6x13__13TBoss2DeRolLeFPv(void *);
s32 TBoss2DeRolLe__sub_80036358(void *);
s32 update_and_send__13TBoss2DeRolLeFPv(void *);
void TBoss2DeRolLe__sub_800363A0(void *p);
void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034E90 *self, s32 kind);
void vfunc_61__13TBoss2DeRolLeFv(void);
s32 TBoss2Joint_get_shell_max_hp(void);
void backup_pos__13TBoss2DeRolLeFi(s32 arg0);
void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void init_head_params__13TBoss2DeRolLeFPv(u8 *arg0);
void set_move_direction__13TBoss2DeRolLeFPv(void *arg0);
void update_angle__13TBoss2DeRolLeFPv(void *arg0);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
f32 fabs_float(f32);
void init_params__13TBoss2DeRolLeFPvfff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2);

extern const f32 TBoss2DeRolLe__data_805D82D8;
extern const f32 TBoss2DeRolLe__data_805D82E8;
extern const f32 TBoss2DeRolLe__data_805D82F0;
extern const f32 TBoss2DeRolLe__data_805D8330;

void init_head_params__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x65C) = 0;
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x664, TBoss2DeRolLe__data_805D82F0, fabs_float(-*(f32 *)((s8 *)arg0 + 0x38)), TBoss2DeRolLe__data_805D8330);
    init_params__13TBoss2DeRolLeFPvfff(arg0 + 0x684, TBoss2DeRolLe__data_805D82D8, fabs_float(TBoss2DeRolLe__data_805D82E8 - *(f32 *)((s8 *)arg0 + 0x40)), TBoss2DeRolLe__data_805D8330);
}

extern const f32 TBoss2DeRolLe__data_805D827C;
extern f32 lbl_805D8284;
extern f32 lbl_805D8444;

void update_angle__13TBoss2DeRolLeFPv(void *arg0) {
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x6A4);
    if (temp_f2 > lbl_805D8284) {
        *(f32 *)((s8 *)arg0 + 0x6A4) = (f32) (temp_f2 - lbl_805D8284);
        return;
    }
    if (temp_f2 < lbl_805D8444) {
        *(f32 *)((s8 *)arg0 + 0x6A4) = (f32) (temp_f2 + lbl_805D8284);
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x6A4) = (f32) TBoss2DeRolLe__data_805D827C;
}

extern const f32 TBoss2DeRolLe__data_805D82B4;
extern const f32 lbl_805D82C0;
extern const f32 TBoss2DeRolLe__data_805D82E4;
extern const f32 TBoss2DeRolLe__data_805D82FC;

typedef char RecoveredGlobal_80034AC8_lbl_804359CC_size[sizeof(RecoveredGlobal_80034AC8_lbl_804359CC) == 0xC ? 1 : -1];
void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_80034AC8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80034AC8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80034AC8, sp10) == 0x8) ? 1 : -1];
    Stack_80034AC8 stack;
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(const f32 *)&TBoss2DeRolLe__data_805D827C);
    *(f32 *)((s8 *)arg1 + 4) = (f32) (*(const f32 *)&TBoss2DeRolLe__data_805D827C);
    *(f32 *)((s8 *)arg1 + 8) = (f32) (*(const f32 *)&TBoss2DeRolLe__data_805D827C);
    push_matrix();
    set_matrix_identity(0);
    stack.sp8 = *(s32 *)((s8 *)&lbl_804359CC.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804359CC.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804359CC.value + 8);
    scale_current_matrix((void *)&stack.sp8);
    bind_motion_context((*(s32 *)((s8 *)arg0 + 0xF8)), (f32) (*(f32 *)((s8 *)arg0 + 0xC0)));
    compose_motion_node_matrix((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
    matrix_mult_vec(0, arg1, arg1);
    pop_matrix();
}

f32 calc_node_height__13TBoss2DeRolLeFPv(Obj_80034B60 *self) {
    Vec3_80034B60 v;
    v.x = TBoss2DeRolLe__data_805D827C;
    v.y = TBoss2DeRolLe__data_805D827C;
    v.z = TBoss2DeRolLe__data_805D827C;
    push_matrix_from(identity_matrix);
    scale_matrix(0, TBoss2DeRolLe__data_805D82A0, TBoss2DeRolLe__data_805D82A0, TBoss2DeRolLe__data_805D82A0);
    bind_motion_context(self->fF8, self->fC0);
    compose_motion_node_matrix((void *)self->f34);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

void set_move_direction__13TBoss2DeRolLeFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x654) == 0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805D82C0;
        *(s32 *)((s8 *)arg0 + 0x64) = 0x500;
    } else {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) TBoss2DeRolLe__data_805D82B4;
        *(s32 *)((s8 *)arg0 + 0x64) = -0x500;
    }
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) TBoss2DeRolLe__data_805D82E4;
    *(f32 *)((s8 *)arg0 + 0x6A4) = (f32) TBoss2DeRolLe__data_805D82FC;
}

extern u8 *TBoss2DeRolLe__data_805D4BA0;

typedef char RecoveredGlobal_80034C90_lbl_8043567C_size[sizeof(RecoveredGlobal_80034C90_lbl_8043567C) == 0x30 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80034C2C_lbl_8043567C_size[sizeof(RecoveredGlobal_80034C2C_lbl_8043567C) == 0x30 ? 1 : -1];
typedef char RecoveredFields_80034C2C_arg0_3AC_offset[offsetof(RecoveredFields_80034C2C_arg0, field_3AC) == 0x3AC ? 1 : -1];
void set_move_target_point__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1) {
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x394), (s32)((void *) ((u8 *)&(*(RecoveredGlobal_80034C2C_lbl_8043567C *)&TBoss2DeRolLe__position_point_table).value + (arg1 * 0xC))));
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x3A0), (s32)(arg0 + 0x394));
    subtract_vector(arg0 + 0x3A0, arg0 + 0x38);
    ((RecoveredFields_80034C2C_arg0 *)arg0)->field_3AC = ((TObjBoss2Tunnel *)(arg0 + 0x3A0))->clamp_velocity();
}
#pragma pop

void set_position_index__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1) {
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x38), (s32)((u8 *)&TBoss2DeRolLe__position_point_table.value + (arg1 * 0xC)));
    *(f32 *)((s8 *)arg0 + 0x6A4) = (f32) (*(const f32 *)&TBoss2DeRolLe__data_805D827C);
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
}

s32 TBoss2Joint_get_shell_max_hp(void) {
    return *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x1C);
}

extern s32 derolle_effect_params[];

f32 TBoss2DeRolLe__sub_80034CEC(void) {
    return *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 8);
}

f32 TBoss2DeRolLe__sub_80034CF8(void) {
    return *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 4);
}

void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    reload_stats_for_phase__13TBoss2DeRolLeFPvi(arg0, 2);
    TObjEneDD::emit_effect((void*)arg0, (int)arg1, (int)derolle_effect_params);
    ((void (*)(void *, void *))reload_stats_for_phase__13TBoss2DeRolLeFPvi)(arg0, *(void **)((s8 *)arg0 + 0x3C4));
}

void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;
    temp_r5 = *(u8 **)((s8 *)arg1 + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 0x04000000);
        reload_stats_for_phase__13TBoss2DeRolLeFPvi((void *)((void *)arg0), 1);
        ((VObj18 *)arg1)->m20(arg0, TBoss2DeRolLe__data_805D82BC);
        reload_stats_for_phase__13TBoss2DeRolLeFPvi(arg0, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x3C4))));
    }
}

void forward_switch_phase_stats__13TBoss2DeRolLeFi(s32 arg0) {
    if ((void *) TBoss2DeRolLe__instance != NULL) {
        switch_phase_stats__13TBoss2DeRolLeFPvPv((u8 *)TBoss2DeRolLe__instance, (u8 *)arg0);
    }
}

void reload_stats_for_phase__13TBoss2DeRolLeFPvi(void *self, s32 kind) {
    s32 a;
    s32 i;
    s32 b;
    switch (kind) {
    case 0:
    default:
        a = 0;
        i = 0;
        b = 0;
        break;
    case 1:
        a = 0;
        i = 1;
        b = 0;
        break;
    case 2:
        a = 0;
        i = 2;
        b = 0;
        break;
    }
    reload_stats_keep_hp_tp__9TObjEneDDFv(self, TBoss2DeRolLe__base_params[a], TBoss2DeRolLe__attack_params_table[i], TBoss2DeRolLe__resistance_params[b]);
}

void set_state_and_send__13TBoss2DeRolLeFPvi(Obj_80034E90 *self, s32 kind) {
    Pkt16_80034E90 p16;
    Pkt8_80034E90 p8;
    Fld_80034E90 *f = (Fld_80034E90 *)self;
    self->m85(kind, 6);
    if (kind == 0x19 || (kind - 0x14) <= 1U || kind == 0x1B) {
        TBoss2DeRolLe__sub_800363A0(&p16);
        p16.a = f->f1C;
        p16.b = kind;
        p16.c = f->f3D4;
        p16.d = f->f38C;
        update_and_send__13TBoss2DeRolLeFPv(&p16);
        return;
    }
    TBoss2DeRolLe__sub_80036358(&p8);
    p8.a = f->f1C;
    p8.b = kind;
    p8.c = f->f3D4;
    send_6x13__13TBoss2DeRolLeFPv(&p8);
}

#pragma push
#pragma fp_contract on
void update_colliders_from_offsets__13TBoss2DeRolLeFi(s32 arg0) {
    Vec sp20;
    Vec sp14;
    Vec sp8;
    VecCopy__FP3VecPC3Vec((s32)&sp8, arg0 + 0x440);
    VecCopy__FP3VecPC3Vec((s32)&sp14, arg0 + 0x500);
    VecCopy__FP3VecPC3Vec((s32)&sp20, arg0 + 0x50C);
    update_local_colliders_from_world(arg0, &sp8);
}
#pragma pop

void backup_pos__13TBoss2DeRolLeFi(s32 arg0) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC);
}
void TBoss2DeRolLe::vfunc_61() {  }
void apply_damage_taken__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0) {
    s32 temp_r4;
    temp_r4 = arg0->hpmax - arg0->hp;
    if (*(s32 *)((s8 *)arg0 + 0x3C0) & 8) {
        arg0->m_6c8 = (s32) (arg0->m_6c8 - temp_r4);
        spawn_offset_particle__13TBoss2DeRolLeFiff(*(s32 *)((s8 *)arg0 + 0xA4) + 0x1C, TBoss2DeRolLe__data_805D82A0, lbl_805D8448);
        play_sound((void *)0x4003A80F, (s32)((u8 *)arg0 + 0x518));
    } else {
        arg0->m_6cc = (s32) (arg0->m_6cc - temp_r4);
        if ((s32) arg0->m_6cc < 0) {
            arg0->m_6cc = 0;
            set_flags_play_sound__13TBoss2DeRolLeFPv((u8 *)arg0);
        }
    }
    arg0->hp = (s16) arg0->hpmax;
    ((TObjEneDD *)arg0)->clear_attack_receipts();
}

}

}
#pragma pop

#pragma push
namespace lifecycle_view {

struct VBase_8003508C_80035084 {
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
    virtual void m85(s16, int);
};

struct VBase_18_bd2ad6
{
  char pad[0x18];
};

struct VObj_18_bd2ad6 : VBase_18_bd2ad6 {
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
    virtual s32 m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual s32 m39();
    virtual s32 m40();
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
    virtual s32 m60();
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
    virtual s32 m103();
};

struct Stack_800365C8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_800365C8_lbl_80435A44 {
    s32 value;
    u8 remaining[0x8];
};

struct Self_80035420 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1C[0x5E0 - 0x1C];
    void *a5E0[10];
    s32 x608[4];
    s32 x618;
    s32 x61C;
    void *a620[4];
    void *a630[5];
    void *a644[3];
    void *x650;
    u8 pad654[0x6B8 - 0x654];
    void *x6B8;
    u8 pad6BC[0x6C8 - 0x6BC];
    void *x6C8;
    void *x6CC;
    void *x6D0;
    u8 pad6D4[0x73C - 0x6D4];
    void *x73C;
    void *a740[6];
};

struct Vec_800363B4 { f32 x, y, z; };

struct Seg_800363B4 { s8 n; u8 pad1[0xF]; void *model1; void *model2; };

typedef struct Slot_80035D24 {
    s32 kind;
    s32 f04;
    f32 f08[3];
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 f20[3];
    struct Slot_80035D24 *next;
    s32 f30;
    s32 f34;
} Slot_80035D24;

typedef struct Node_80035D24 {
    u8 pad0[4];
    struct { u8 pad[4]; s32 v; } *h;
    u8 pad8[0x2C - 8];
    struct Node_80035D24 *sub;
    struct Node_80035D24 *next;
} Node_80035D24;

extern "C" {
void init_float_block__13TBoss2DeRolLeFPv(u8 *arg0);
void VecCopy__FP3VecPC3Vec(void *, void *);
extern const f32 lbl_805D8458;
f32 newton_sqrtf(f32);
extern const f32 TBoss2DeRolLe__data_805D8288;
extern const f32 TBoss2DeRolLe__data_805D82A0;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 lbl_805D844C;
void TBoss2DeRolLe__sub_800360A8(void *arg0);
s32 advance_action_sequence__13TBoss2DeRolLeFPv(void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 construct_piece_controller__10TObjPlayerFPvii(int, void *, int);
void advance_phase_wrap__13TBoss2DeRolLeFPv(u8 *arg0);
void update_projectile_spawns__13TBoss2DeRolLeFPv(u8 *arg0);
s32 update_particle_ctrls__13TBoss2DeRolLeFPv(void *);
s32 TBoss2DeRolLe__sub_80034034(void *);
s32 is_ready__13TBoss2DeRolLeFPv(void *);
void backup_pos__13TBoss2DeRolLeFi(s32 arg0);
void TBoss2DeRolLe__sub_8003508C(void *arg0);
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 add_radar_scaled_marker(void *, int, int, int, f32);
void *__nw__7TObjectFUl(int);
extern const f32 TBoss2DeRolLe__data_805D82A0;
void run_task__13TBoss2DeRolLeFPv(u8 *arg0);
extern RecoveredGlobal_800365C8_lbl_80435A44 lbl_80435A44;
s32 __dt__7TObjectFv(void *, int);
void queue_destruction__7TObjectFv(void *arg0);
s32 free_if_positive__13TBoss2DeRolLeFis(s32 arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
void mem_free(void *p);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
extern u8 __vt__13TBoss2DeRolLe[];
extern s32 TBoss2DeRolLe__instance;
u8 *__dt__13TBoss2DeRolLeFv(u8 *arg0, s16 arg1);
void VecCopy__FP3VecPC3Vec(void *, void *);
f32 fabs_float(f32);
f32 atan2_float(f32, f32);
s32 TObjLight__sub_801337F8(s32);
s32 scale_matrix(int, f32, f32, f32);
f32 vector_length(void *);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 subtract_vector(void *, void *);
s32 rotate_matrix_x(int, int);
s32 normalize_vector(void *);
s32 push_matrix();
s32 pop_matrix();
void draw_chunk_object(void *child);
extern const f64 lbl_80435A50[];
extern u32 lbl_805D4BA4;
extern s32 current_scene_light;
extern const f32 lbl_805D8260;
extern const f32 TBoss2Fin__data_805D8450;
extern const f32 lbl_805D8454;
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void TObjPlayer__sub_8002E7C8(void);
void TBoss2Mine__sub_80038D88(void);
void TBoss2Tentacle__sub_8003A0AC(void);
u8 *load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
extern u8 lbl_804356C0[];
extern u8 lbl_80435A18[];
extern s32 TBoss2DeRolLe__shared_handler_id_table[];
extern u8 boss2_derolle_bml_descriptor[];
extern s32 de_rol_le_base_param_ids[1];
extern s32 de_rol_le_resistance_param_ids[1];
extern s32 lbl_805D26B0[1];
extern s32 TBoss2DeRolLe__base_params[1];
extern s32 TBoss2DeRolLe__resistance_params[1];
extern s32 TBoss2DeRolLe__data_805D4BA0[1];
extern u32 lbl_805D4BA4;
extern s32 TBoss2DeRolLe__current_attack_id;
extern s32 TBoss2DeRolLe__sequence_match_index;
extern s32 lbl_805D4BB0;
extern s32 lbl_805D4BB4;
extern s32 lbl_805D4BB8;
extern s32 lbl_805D4BBC;
extern s32 lbl_805D4BC0;
extern s32 TBoss2DeRolLe__instance;
extern u8 *derolle_texture_list_handle;
extern s32 lbl_805D4BCC;
extern const f32 TBoss2DeRolLe__data_805D827C;
void load_resources__13TBoss2DeRolLeFv(void);
s32 advance_scalar_motion_profile(void *arg0);
void vfunc_63__13TBoss2DeRolLeFv(void);
void vfunc_28__13TBoss2DeRolLeFv(void);
void TBoss2DeRolLe__sub_8003508C(void *arg0);
void apply_poison_status__13TBoss2DeRolLeFv(void);
void apply_paralysis__13TBoss2DeRolLeFv(void);
void apply_slow_status__13TBoss2DeRolLeFv(void);
void apply_confusion_status__13TBoss2DeRolLeFv(void);
void apply_movement_ailment__13TBoss2DeRolLeFl(void);
void apply_shock_status__13TBoss2DeRolLeFv(void);
void clear_harmful_statuses__13TBoss2DeRolLeFv(void);
void TBoss2DeRolLe__sub_80036358(void* p);
void TBoss2DeRolLe__sub_800363A0(void* p);
void *create__13TBoss2DeRolLeFPv(void *arg0);
s32 free_if_positive__13TBoss2DeRolLeFis(s32 arg0, s16 arg1);
s32 get_instance__13TBoss2DeRolLeFv(void);
void init_params__13TBoss2DeRolLeFPvfff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2);
s32 init_resources__13TBoss2DeRolLeFi(s32 arg0);
void reset_parts__13TBoss2DeRolLeFv(void);
void send_6x13__13TBoss2DeRolLeFPv(void* p);
void set_move_params__13TBoss2DeRolLeFPvffff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
void swap_6x13_fields__13TBoss2DeRolLeFPv(void* p);
void swap_endian__13TBoss2DeRolLeFPv(void* p);
void update_and_send__13TBoss2DeRolLeFPv(void* p);
void *TBoss2DeRolLe__ct(void *, void *, void *);
s32 TBoss2DeRolLe__sub_80034034(void *);
void TBoss2Fin__sub_800367C0(void);
void TBoss2Mine__sub_80038D84(void);
void TBoss2Tentacle__sub_8003A0A8(void);
int TLobby__send_and_handle_60(void*);
void TLobby__sub_8001FE7C(void*, int);
void TObjPlayer__sub_8002EB88(void);
void __dl__FPv(void);
void *__nw__7TObjectFUl(int);
int bswap_16__FPUs(void*);
int bswap_32__FPUl(void*);

void TBoss2DeRolLe::vfunc_63() {  }
void TBoss2DeRolLe::vfunc_28() {  }

void TBoss2DeRolLe__sub_8003508C(void *arg0) {
    struct VBase_8003508C_80035084 *o = (struct VBase_8003508C_80035084 *)arg0;
    if (is_ready__13TBoss2DeRolLeFPv(arg0) != 0) {
        TBoss2DeRolLe__sub_80034034(arg0);
        return;
    }
    o->m85(((TBoss2DeRolLe *)arg0)->mode, 9);
}

extern u32 lbl_805D4BA4;

typedef struct VBase_18_bd2ad6 VBase_18_bd2ad6;
typedef struct VObj_18_bd2ad6 VObj_18_bd2ad6;
void run_task__13TBoss2DeRolLeFPv(u8 *arg0) {
  s16 temp_r0_2;
  s32 temp_r0_3;
  s32 temp_r30;
  s32 temp_r3;
  u32 temp_r3_2;
  if (((TObjEneDD *)arg0)->get_target_info() != 0)
  {
    (((VObj_18_bd2ad6 *)(arg0))->m103());
    return;
  }
  temp_r3 = *((s32 *) (((s8 *) arg0) + 0x3C0));
  if (temp_r3 & 0x8000)
  {
    ((TObjEnemy *)arg0)->send_entity_set_flags();
    queue_destruction__7TObjectFv(arg0);
    return;
  }
  if (temp_r3 & 0x80)
  {
    *((s32 *) (((s8 *) arg0) + 0x3C0)) = (s32) (temp_r3 & 0xFFFFFF7F);
    *((s32 *) (((s8 *) arg0) + 0x3C0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x3C0))) | 0x40);
    temp_r3_2 = ((u32)__nw__7TObjectFUl(0x500));
    if (temp_r3_2 != 0U)
    {
      construct_piece_controller__10TObjPlayerFPvii((int) temp_r3_2, (void *) arg0, (int) (*((s32 *) (((s8 *) arg0) + 0x618))));
    }
  }
  if ((is_main_phase_15__9TObjEneDDFv() != 0) && (((s32) (*((s32 *) (((s8 *) arg0) + 0x3C8)))) == 0))
  {
    if (((TObjEneDD *)arg0)->update_lobby_state() != 0)
    {
      *((s32 *) (((s8 *) arg0) + 0x3F4)) = 0;
    }
    else
    {
      *((s32 *) (((s8 *) arg0) + 0x3F4)) = 1;
    }
  }
  if ((((s32) (*((s32 *) (((s8 *) arg0) + 0x3C8)))) != 0) && ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x3CC)))) + 8))) & 0x10000))
  {
    switch (*((s32 *) (((s8 *) arg0) + 0x3F4)))
    {
      case 1:
        *((s32 *) (((s8 *) arg0) + 0x3F4)) = 0;
        advance_action_sequence__13TBoss2DeRolLeFPv((void *) arg0);
        break;
      case 0:
        *((s32 *) (((s8 *) arg0) + 0x3F4)) = 2;
        break;
      case 2:
        *((s32 *) (((s8 *) arg0) + 0x3F4)) = 1;
        break;
    }
  }
  temp_r30 = query_teammate_state__9TObjEneDDFv();
  (((TBoss2DeRolLe *)(arg0))->update_attack_stat_status());
  (((TBoss2DeRolLe *)(arg0))->update_defense_stat_status());
  if (temp_r30 == 0)
  {
    temp_r0_2 = ((TBoss2DeRolLe *)arg0)->mode;
    temp_r3 = temp_r0_2;
    if (((temp_r0_2 == 0x1F) || (temp_r3 == 0x20)) || (temp_r0_2 == 0x1E))
    {
      ((TBoss2DeRolLe *)arg0)->actorFlags = (s32) ((((TBoss2DeRolLe *)arg0)->actorFlags) | 0x800);
    }
    else
    {
      ((TBoss2DeRolLe *)arg0)->actorFlags = (s32) ((((TBoss2DeRolLe *)arg0)->actorFlags) & 0xFFFFF7FF);
    }
    temp_r0_3 = *((s32 *) (((s8 *) arg0) + 0x3F4));
    if (temp_r0_3 != 1)
    {
      if (temp_r0_3 == 2)
      {
        if (is_ready__13TBoss2DeRolLeFPv((void *)((void *) arg0)) != 0)
        {
          TBoss2DeRolLe__sub_80034034((void *) arg0);
        }
        else
        {
          (((VObj_18_bd2ad6 *)(arg0))->m85((((TBoss2DeRolLe *)arg0)->mode), 2));
        }
      }
      else
      {
        TBoss2DeRolLe__sub_8003508C((void *) arg0);
      }
      if ((((TBoss2DeRolLe *)(arg0))->test_flag30_512()) != 0)
      {
        (((TBoss2DeRolLe *)(arg0))->vfunc_62());
      }
      (((VObj_18_bd2ad6 *)(arg0))->m85((((TBoss2DeRolLe *)arg0)->mode), 8));
      (((VObj_18_bd2ad6 *)(arg0))->m85((((TBoss2DeRolLe *)arg0)->mode), 0));
    }
    else
    {
      if ((((TBoss2DeRolLe *)(arg0))->test_flag30_512()) != 0)
      {
        (((TBoss2DeRolLe *)(arg0))->vfunc_62());
      }
      (((VObj_18_bd2ad6 *)(arg0))->m85((((TBoss2DeRolLe *)arg0)->mode), 0));
    }
    advance_phase_wrap__13TBoss2DeRolLeFPv(arg0);
    update_projectile_spawns__13TBoss2DeRolLeFPv(arg0);
  }
  ((TObjEneDD *)arg0)->sub_800BBA0C();
  (((VObj_18_bd2ad6 *)(arg0))->m86());
  backup_pos__13TBoss2DeRolLeFi((s32)arg0);
  ((TBoss8Dragon *)arg0)->set_player_state_default();
  add_radar_scaled_marker(arg0 + 0x38, -0x5DB4, 1, 1, (f32) TBoss2DeRolLe__data_805D82A0);
  update_particle_ctrls__13TBoss2DeRolLeFPv((void *) arg0);
  if (temp_r30 == 0)
  {
    ((TObject *)(arg0 + 0x3D8))->run_tasks();
  }
}

#define self ((Self_80035420 *)arg0)
u8 *__dt__13TBoss2DeRolLeFv(u8 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        self->vtable = __vt__13TBoss2DeRolLe;
        if (self->x73C != NULL) {
            queue_destruction__7TObjectFv(self->x73C);
            self->x73C = NULL;
        }
        for (i = 0; i < 6; i++) {
            if (self->a740[i] != NULL) {
                queue_destruction__7TObjectFv(self->a740[i]);
                self->a740[i] = NULL;
            }
        }
        mem_free((void *)self->x618);
        self->x618 = 0;
        if (self->x6CC != NULL) {
            queue_destruction__7TObjectFv(self->x6CC);
            self->x6CC = NULL;
        }
        if (self->x6D0 != NULL) {
            queue_destruction__7TObjectFv(self->x6D0);
            self->x6D0 = NULL;
        }
        if (self->x6C8 != NULL) {
            delete_buffer__12TBoss8DragonFis((s32)self->x6C8, 1);
            self->x6C8 = NULL;
        }
        if (self->x6B8 != NULL) {
            queue_destruction__7TObjectFv(self->x6B8);
            self->x6B8 = NULL;
        }
        if (self->x650 != NULL) {
            queue_destruction__7TObjectFv(self->x650);
            self->x650 = NULL;
        }
        for (i = 2; i >= 0; i--) {
            queue_destruction__7TObjectFv(self->a644[i]);
            self->a644[i] = NULL;
        }
        for (i = 4; i >= 0; i--) {
            queue_destruction__7TObjectFv(self->a630[i]);
            self->a630[i] = NULL;
        }
        for (i = 9; i >= 0; i--) {
            queue_destruction__7TObjectFv(self->a5E0[i]);
            self->a5E0[i] = NULL;
        }
        for (i = 3; i >= 0; i--) {
            queue_destruction__7TObjectFv(self->a620[i]);
            self->a620[i] = NULL;
        }
        mem_free((void *)self->x61C);
        free_collision_body_parts(self);
        if ((u32)TBoss2DeRolLe__instance == (u32)arg0) {
            TBoss2DeRolLe__instance = 0;
        }
        free_if_positive__13TBoss2DeRolLeFis((s32)(arg0 + 0x684), -1);
        free_if_positive__13TBoss2DeRolLeFis((s32)(arg0 + 0x664), -1);
        __dt__7TObjectFv(arg0 + 0x3D8, -1);
        __dt__12TObjEneDD_STFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return arg0;
}
#undef self

}
}
#pragma push
namespace constructor_view {

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {

struct Vec_8003563C { f32 x, y, z; };
struct Buf_8003563C { u8 b[0x30]; };
struct VBase_18_bd2ad6 { char pad[0x18]; };
struct VObj_18_bd2ad6 : VBase_18_bd2ad6 {
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
void VecCopy__FP3VecPC3Vec(void *, void *);
s32 fill_value_array(void *);
void reset_fields_3d0__13TBoss2DeRolLeFPv(void *p);
void init_float_block__13TBoss2DeRolLeFPv(u8 *arg0);
s32 init_resources__13TBoss2DeRolLeFi(s32 arg0);
void *__ct__9TBoss2FinFv(void *, void *, void *, void *);
void *TBoss2Joint__ct(void *, void *, u16, int, void *, s32, s32);
void *TBoss2LaserLight__ct(void *, void *, void *);
void *create__13TUnk_80482D04Fiii(void *, void *, u16, int);
void *TBoss2Mine__sub_800381B8(void *, void *, u16, int);
void *__ct__14TBoss2TentacleFP7TObjectll(void *, void *, void *, s32);
void *alloc__23TAdSinglePlyChrSelectGCFv(int);
s32 init_object__12TObjEneDD_STFv(void *, void *);
s32 is_main_phase_15__9TObjEneDDFv();
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 init_model__9TObjEneDDFv(void *, void *, int, void *);
s32 invoke_initialization_hook__9TObjEneDDFv(void *, void *);
u8 *TBoss8Dragon__sub_800BC5EC(u8 *arg0, s32 arg1);
Buf_8003563C *mem_alloc(int);
void *__nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 set_matrix_identity(void *);
struct W3_8003563C;
extern W3_8003563C lbl_804359C0[];
extern u8 controller_input_state[];
extern s32 boss2_de_rol_le_class_name;
extern s32 TBoss2DeRolLe__base_params;
extern s32 TBoss2DeRolLe__resistance_params;
extern u8 *TBoss2DeRolLe__data_805D4BA0;
extern u32 lbl_805D4BA4;
extern s32 TBoss2DeRolLe__instance;
extern const f32 TBoss2DeRolLe__data_805D827C;
extern const f32 TBoss2DeRolLe__data_805D8294;
extern const f32 TBoss2DeRolLe__data_805D82BC;
extern const f32 TBoss2DeRolLe__data_805D8334;

extern "C" void render_body__13TBoss2DeRolLeFv(u8 *arg0);
extern "C" void dispatch_action__13TBoss2DeRolLeFiUii(s32 arg0, u32 arg1, s32 arg2);
extern "C" void update_colliders_from_offsets__13TBoss2DeRolLeFi(s32 arg0);
extern "C" void vfunc_61__13TBoss2DeRolLeFv();
extern "C" void apply_damage_taken__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0);
extern "C" void vfunc_63__13TBoss2DeRolLeFv();
extern "C" void vfunc_28__13TBoss2DeRolLeFv();
extern "C" u8 *__dt__13TBoss2DeRolLeFv(u8 *arg0, s16 arg1);
extern "C" void apply_poison_status__13TBoss2DeRolLeFv();
extern "C" void apply_paralysis__13TBoss2DeRolLeFv();
extern "C" void apply_slow_status__13TBoss2DeRolLeFv();
extern "C" void apply_confusion_status__13TBoss2DeRolLeFv();
extern "C" void apply_movement_ailment__13TBoss2DeRolLeFl();
extern "C" void apply_shock_status__13TBoss2DeRolLeFv();
extern "C" void clear_harmful_statuses__13TBoss2DeRolLeFv();
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
extern "C" void vfunc_105__13TBoss2DeRolLeFv();
extern "C" void render__13TBoss2DeRolLeFv(u8 *arg0);
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_804806E8Fv();
extern "C" void vfunc_58__13TUnk_804806E8Fv();
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
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
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
extern "C" u8 lbl_80435710[];
extern "C" u8 lbl_8043572C[];
extern "C" u8 lbl_80435748[];
extern "C" u8 lbl_80435764[];
extern "C" u8 lbl_80435780[];
extern "C" u8 lbl_804357A0[];
extern "C" u8 lbl_804357B8[];
extern "C" u8 lbl_804357D0[];
extern "C" u8 lbl_804357E8[];
extern "C" u8 lbl_80435804[];
extern "C" u8 lbl_8043581C[];
extern "C" u8 lbl_80435834[];
extern "C" u8 lbl_8043584C[];
extern "C" u8 lbl_80435868[];
extern "C" u8 lbl_80435884[];
extern "C" u8 lbl_8043589C[];
extern "C" u8 lbl_804358B4[];
extern "C" u8 lbl_804358CC[];
extern "C" u8 lbl_804358E4[];
extern "C" u8 lbl_80435900[];
extern "C" u8 lbl_80435918[];
extern "C" u8 lbl_80435930[];
extern "C" u8 lbl_80435948[];
extern "C" u8 lbl_80435960[];
extern "C" u8 lbl_8043597C[];
extern "C" u8 lbl_80435998[];
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void run_task__13TBoss2DeRolLeFPv(u8 *arg0);
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_check__13TBoss2DeRolLeFPv(void *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
using constructor_data::derolle_part_transform_template;
using constructor_data::derolle_action_mode_sequence_table;
using constructor_data::derolle_action_sequence_table;
using constructor_data::TBoss2DeRolLe__shared_handler_id_table;
using constructor_data::lbl_8048228C;
using constructor_data::lbl_804822A8;
using constructor_data::bm_boss2_de_rol_le_model_names;
using constructor_data::bm_boss2_de_rol_le_motion_names;
using constructor_data::boss2_derolle_bml_descriptor;
using constructor_data::lbl_804823A8;
using constructor_data::boss2_derolle_particle_node_indices;
using constructor_data::boss2_derolle_particle_limits;
using constructor_data::__vt__13TBoss2DeRolLe;
u32 TBoss2DeRolLe__mine_ground_targets[15];
u32 boss2_derolle_primary_color_targets[3];
u32 derolle_segment_joint_node_offsets[10];
u32 boss2_derolle_segment_color_targets[10];
u32 TBoss2DeRolLe__attack_params_table[3];

struct Self_8003563C {
    s32 f0;
    u8 pad4[0x20];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_8003563C pos;
    u8 pad44[0x3C0 - 0x44];
    s32 f3C0;
    s32 f3C4;
    s32 f3C8;
    void *f3CC;
    s32 f3D0;
    s32 f3D4;
    u8 obj3D8[0x3F4 - 0x3D8];
    s32 f3F4;
    Vec_8003563C v3F8[20];
    Vec_8003563C v4E8[4];
    Vec_8003563C v518[3];
    s32 f53C;
    Vec_8003563C v540[10];
    s32 f5B8[10];
    void *f5E0[10];
    f32 f608, f60C, f610, f614;
    Buf_8003563C *f618;
    Buf_8003563C *f61C;
    void *f620[4];
    void *f630[5];
    void *f644[3];
    void *f650;
    s32 f654, f658, f65C, f660;
    u8 r664[0x20];
    u8 r684[0x20];
    f32 f6A4;
    s32 f6A8, f6AC, f6B0, f6B4;
    void *f6B8;
    f32 f6BC, f6C0, f6C4;
    void *f6C8;
    s32 f6CC, f6D0;
    f32 f6D4, f6D8;
    s32 f6DC, f6E0, f6E4, f6E8, f6EC, f6F0, f6F4, f6F8;
    f32 f6FC[16];
    s32 f73C;
    s32 f740[6];
    s32 f758;
};

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct W3_8003563C { u32 a, b, c; };
#define self ((Self_8003563C *)arg0)
void *TBoss2DeRolLe__ct(void *arg0, void *arg1, void *arg2) {
    u16 a;
    void *p;
    s32 b;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    struct { W3_8003563C v; u32 flags; } locals;

    init_object__12TObjEneDD_STFv(arg0, arg1);
    *(u8 **)((s8 *)self + 0x18) = (u8 *)__vt__13TBoss2DeRolLe;
    __ct__7TObjectFP7TObject(self->obj3D8, 0);
    init_resources__13TBoss2DeRolLeFi((s32)self->r664);
    init_resources__13TBoss2DeRolLeFi((s32)self->r684);
    self->f0 = boss2_de_rol_le_class_name;
    if ((u32)TBoss2DeRolLe__instance == 0) {
        TBoss2DeRolLe__instance = (s32)self;
    }
    invoke_initialization_hook__9TObjEneDDFv(self, arg2);
    self->f3C0 = 0;
    {

        if (((TObjEnemy *)self)->exchange_object_state((s32)&locals.flags, (s16)1) != 0 && (locals.flags & 0x12008) == 0x12008) {
            self->f3C0 |= 0x8000;
        }
    }
    ((TObjEneDD *)self)->init_position_vectors();
    {
        u8 *q;
        q = *(u8 **)((s8 *)lbl_805D4BA4 + 0x42C);
        self->f34 = *(s32 *)((s8 *)q + 0x28);
        q = *(u8 **)((s8 *)lbl_805D4BA4 + 0x42C);
        self->f24 = *(s32 *)((s8 *)q + 0x2C);
        init_model__9TObjEneDDFv(self, (u8 *)lbl_804822A8, 3, q);
    }
    ((TBoss2DeRolLe *)self)->animationFlags = 0;
    ((TObjMotion *)self)->set_field_d8((s32)((u8 *)lbl_804823A8));
    ((TObjMotion *)self)->set_field_dc(*(s32 *)((s8 *)lbl_805D4BA4 + 0x430));
    ((TBoss2DeRolLe *)self)->m_b8 = 0;
    ((TObjMotion *)self)->set_animation(((TBoss2DeRolLe *)self)->m_b8);
    ((TObjMotion *)self)->set_field_b8(((TBoss2DeRolLe *)self)->m_b8);
    reset_hp__9TObjEneDDFv(self, TBoss2DeRolLe__base_params, ((s32 *)TBoss2DeRolLe__attack_params_table)[0], TBoss2DeRolLe__resistance_params);
    ((TObjEneDD *)self)->check_state_flag_2();
    ((TBoss2DeRolLe *)self)->movementParameters = (u8 *)lbl_8048228C;
    initialize_enemy_state__9TObjEneDDFv(self, 0x2D);
    ((TBoss2DeRolLe *)self)->m_37c = TBoss2DeRolLe__data_805D8294;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(0x1E);
    self->f3C4 = 0;
    self->f3D0 = 0;
    self->f3D4 = 0;
    for (i = 0; i < 20; i++) {
        self->v3F8[i].x = TBoss2DeRolLe__data_805D827C;
        self->v3F8[i].y = TBoss2DeRolLe__data_805D827C;
        self->v3F8[i].z = TBoss2DeRolLe__data_805D827C;
    }
    for (i = 0; i < 4; i++) {
        self->v4E8[i].x = TBoss2DeRolLe__data_805D827C;
        self->v4E8[i].y = TBoss2DeRolLe__data_805D827C;
        self->v4E8[i].z = TBoss2DeRolLe__data_805D827C;
    }
    self->f61C = mem_alloc(0xC0);
    for (i = 0; i < 4; i++) {
        set_matrix_identity(&self->f61C[i]);
        p = __nw__7TObjectFUl(0x158);
        if (p != NULL) {
            p = __ct__14TBoss2TentacleFP7TObjectll(p, self->obj3D8, &self->f61C[i], i);
        }
        self->f620[i] = p;
    }
    {
        locals.v = lbl_804359C0[0];
        a = ((TBoss2DeRolLe *)self)->m_1c + 1;
        b = *(s16 *)((s8 *)self + 0x2C) + 1;
        for (j = 0; j < 10; j++) {
            VecCopy__FP3VecPC3Vec(&self->v540[j], &locals.v);
            self->f5B8[j] = -1;
            p = __nw__7TObjectFUl(0x3BC);
            if (p != NULL) {
                p = TBoss2Joint__ct(p, self, a++, b++, &self->v540[j], ((s32 *)derolle_segment_joint_node_offsets)[j], ((s32 *)boss2_derolle_segment_color_targets)[j]);
            }
            self->f5E0[j] = p;
        }
    }
    for (i = 0; i < 5; i++) {
        p = __nw__7TObjectFUl(0x3F0);
        if (p != NULL) {
            p = TBoss2Mine__sub_800381B8(p, self->obj3D8, a++, b++);
        }
        self->f630[i] = p;
    }
    for (i = 0; i < 3; i++) {
        p = __nw__7TObjectFUl(0x410);
        if (p != NULL) {
            p = create__13TUnk_80482D04Fiii(p, self->obj3D8, a++, b++);
        }
        self->f644[i] = p;
    }
    p = __nw__7TObjectFUl(0x88);
    if (p != NULL) {
        p = __ct__9TBoss2FinFv(p, self->obj3D8, (u8 *)self + 0x404, (u8 *)self + 0x470);
    }
    self->f650 = p;
    self->f654 = 0;
    self->f658 = 0;
    self->f65C = 0;
    self->f660 = 0;
    init_float_block__13TBoss2DeRolLeFPv(self->r664);
    init_float_block__13TBoss2DeRolLeFPv(self->r684);
    self->f6A4 = TBoss2DeRolLe__data_805D827C;
    self->f6A8 = self->f6AC = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x18);
    self->f6B0 = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x20);
    ((TBoss2DeRolLe *)self)->hpmax = ((TBoss2DeRolLe *)self)->hp = 0x4E20;
    self->f6B4 = 0;
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = TBoss2LaserLight__ct(p, self->obj3D8, &self->f6BC);
    }
    self->f6B8 = p;
    self->f6BC = TBoss2DeRolLe__data_805D827C;
    self->f6C0 = TBoss2DeRolLe__data_805D827C;
    self->f6C4 = TBoss2DeRolLe__data_805D827C;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x10);
    if (p != NULL) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 4);
    }
    self->f6C8 = p;
    fill_value_array(self->f6C8);
    self->f6CC = 0;
    self->f6D0 = 0;
    self->f6D4 = TBoss2DeRolLe__data_805D82BC;
    self->f6D8 = TBoss2DeRolLe__data_805D8334;
    for (k = 0; k < 3; k++) {
        VecCopy__FP3VecPC3Vec(&self->v518[k], &self->pos);
    }
    self->f53C = 0;
    self->f608 = TBoss2DeRolLe__data_805D82BC;
    self->f60C = TBoss2DeRolLe__data_805D82BC;
    self->f610 = TBoss2DeRolLe__data_805D82BC;
    self->f614 = TBoss2DeRolLe__data_805D82BC;
    self->f618 = mem_alloc(0x240);
    for (i = 0; i < 12; i++) {
        set_matrix_identity(&self->f618[i]);
    }
    for (m = 0; m < 6; m++) {
        self->f740[m] = 0;
    }
    self->f758 = 0;
    self->f6DC = 0;
    self->f6E0 = 0;
    self->f6E4 = 0;
    self->f6E8 = 0;
    self->f6EC = 0;
    self->f6F0 = 0;
    self->f6F4 = 0;
    self->f6F8 = 0;
    self->f6FC[0] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[1] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[2] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[3] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[4] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[5] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[6] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[7] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[8] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[9] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[10] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[11] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[12] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[13] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[14] = TBoss2DeRolLe__data_805D827C;
    self->f6FC[15] = TBoss2DeRolLe__data_805D827C;
    self->f73C = 0;
    self->f3C8 = 0;
    self->f3CC = controller_input_state + 0x70;
    if (((s32 (*)(void *))is_main_phase_15__9TObjEneDDFv)(controller_input_state) != 0) {
        if (((TObjEneDD *)self)->update_lobby_state() != 0) {
            self->f3F4 = 0;
        } else {
            self->f3F4 = 1;
        }
    } else {
        self->f3F4 = 0;
    }
    reset_fields_3d0__13TBoss2DeRolLeFPv(self);
    if (!(self->f3C0 & 0x8000)) {
        ((TBoss2DeRolLe *)self)->mode = 1;
        ((VObj_18_bd2ad6 *)self)->m85(((TBoss2DeRolLe *)self)->mode, 4);
    }
    return self;
}
#undef self
#pragma pop
}
}
#pragma pop
namespace lifecycle_view {
extern "C" {
void reset_parts__13TBoss2DeRolLeFv(void) {
    TObjPlayer::clear_target_ref();
    TObjPlayer__sub_8002EB88();
    TBoss2Fin__sub_800367C0();
    TBoss2Mine__sub_80038D84();
    TBoss2Tentacle__sub_8003A0A8();
    if ((u32) lbl_805D4BA4 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D4BA4, 1);
        lbl_805D4BA4 = 0U;
    }
}

extern void *tl_04;

void *create__13TBoss2DeRolLeFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x75C);
    if (o != NULL) {
        o = TBoss2DeRolLe__ct(o, tl_04, arg0);
    }
    return o;
}

extern const f32 TBoss2DeRolLe__data_805D827C;

using constructor_view::TBoss2DeRolLe__mine_ground_targets;
using constructor_view::boss2_derolle_primary_color_targets;
using constructor_view::derolle_segment_joint_node_offsets;
using constructor_view::boss2_derolle_segment_color_targets;
using constructor_view::TBoss2DeRolLe__attack_params_table;
u32 lbl_804FE30C[4];
u32 lbl_804FE31C[3];
Slot_80035D24 derolle_segment_texture_slots[11];
void load_resources__13TBoss2DeRolLeFv(void) {
    s32 k;
    s32 m2;
    s32 m3;
    u8 *res;
    s32 i;
    Node_80035D24 *n;
    Node_80035D24 *m;
    Slot_80035D24 *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        res = load_enemy_bml_resource_named(boss2_derolle_bml_descriptor, lbl_80435A18);
    } else {
        res = (u8 *)load_enemy_bml_resource(boss2_derolle_bml_descriptor);
    }
    (*(u8 * *)&lbl_805D4BA4) = res;
    TBoss2DeRolLe__current_attack_id = 0;
    TBoss2DeRolLe__sequence_match_index = 0;
    lbl_805D4BB0 = 0;
    ((f32 *)lbl_804FE30C)[0] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE30C)[1] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE30C)[2] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE30C)[3] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE31C)[0] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE31C)[1] = TBoss2DeRolLe__data_805D827C;
    ((f32 *)lbl_804FE31C)[2] = TBoss2DeRolLe__data_805D827C;
    lbl_805D4BB4 = 0;
    lbl_805D4BB8 = 0;
    lbl_805D4BBC = 0;
    lbl_805D4BC0 = 0;
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__base_params[i] = register_boss__6TLobbyFl(de_rol_le_base_param_ids[i]);
    }
    for (i = 0; i < 3; i++) {
        ((s32 *)TBoss2DeRolLe__attack_params_table)[i] = dispatch_shared_handler_b__6TLobbyFl(TBoss2DeRolLe__shared_handler_id_table[i]);
    }
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__resistance_params[i] = register_object__6TLobbyFl(de_rol_le_resistance_param_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__data_805D4BA0[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_805D26B0[i]);
    }
    TBoss2DeRolLe__instance = 0;
    TBoss2Tentacle__sub_8003A0AC();
    TBoss2Mine__sub_80038D88();
    for (k = 0; k < 5; k++) {
        TObjBoss2Tunnel::adjust_to_ground((s32)(lbl_804356C0 + k * 0xC), (u8 *)TBoss2DeRolLe__mine_ground_targets + k * 0xC);
    }
    TBoss2Fin::init_effect_table();
    res = (*(u8 * *)&lbl_805D4BA4);
    n = *(Node_80035D24 **)(*(u8 **)(*(u8 **)(res + 0x42C) + 0x28) + 0x2C);
    for (i = 0; i < 10; i++) {
        ((s32 *)derolle_segment_joint_node_offsets)[i] = n->h->v + 8;
        ((s32 *)boss2_derolle_segment_color_targets)[i] = n->sub->h->v + 8;
        n = n->next;
    }
    ((s32 *)boss2_derolle_primary_color_targets)[0] = n->h->v + 8;
    m = n->next;
    ((s32 *)boss2_derolle_primary_color_targets)[1] = m->h->v + 8;
    ((s32 *)boss2_derolle_primary_color_targets)[2] = m->next->h->v + 8;
    derolle_texture_list_handle = (u8 *)find_model_node(*(s32 *)(*(u8 **)(res + 0x42C) + 0x28), 0x4D);
    lbl_805D4BCC = *(s32 *)(derolle_texture_list_handle + 0x2C);
    for (m2 = 0; m2 < 11; m2++) {
        p = &derolle_segment_texture_slots[m2];
        p->kind = 0xF;
        p->f04 = 0;
        p->f08[0] = TBoss2DeRolLe__data_805D827C;
        p->f08[1] = TBoss2DeRolLe__data_805D827C;
        p->f08[2] = TBoss2DeRolLe__data_805D827C;
        p->f14 = 0;
        p->f18 = 0;
        p->f1C = 0;
        p->f20[0] = TBoss2DeRolLe__data_805D827C;
        p->f20[1] = TBoss2DeRolLe__data_805D827C;
        p->f20[2] = TBoss2DeRolLe__data_805D827C;
        p->next = 0;
        p->f30 = 0;
    }
    for (m3 = 0; m3 < 10; m3++) {
        derolle_segment_texture_slots[m3].next = &derolle_segment_texture_slots[m3 + 1];
    }
    p = &derolle_segment_texture_slots[10];
    p->kind = 0x1F;
    p->next = 0;
    TObjPlayer::create_breakup_model();
    TObjPlayer__sub_8002E7C8();
    TWindowCtrl::init_all_slots();
}

s32 advance_scalar_motion_profile(void *arg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    switch (*(s32 *)((s8 *)arg0 + 0)) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) + *(f32 *)((s8 *)arg0 + 4));
        if (*(f32 *)((s8 *)arg0 + 0x10) > *(f32 *)((s8 *)arg0 + 0xC)) {
            *(f32 *)((s8 *)arg0 + 0x10) = *(f32 *)((s8 *)arg0 + 0xC);
            *(s32 *)((s8 *)arg0 + 0) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)arg0 + 0x18) > *(f32 *)((s8 *)arg0 + 0x1C)) {
            *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - *(f32 *)((s8 *)arg0 + 8));
            *(s32 *)((s8 *)arg0 + 0) = 2;
        }
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - *(f32 *)((s8 *)arg0 + 8));
        if (*(f32 *)((s8 *)arg0 + 0x10) < 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x10) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0) = 3;
        }
        break;
    }
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) (*(f32 *)((s8 *)arg0 + 0x18) + *(f32 *)((s8 *)arg0 + 0x10));
    if (*(f32 *)((s8 *)arg0 + 0x18) > *(f32 *)((s8 *)arg0 + 0x14)) {
        *(f32 *)((s8 *)arg0 + 0x18) = *(f32 *)((s8 *)arg0 + 0x14);
    }
    return *(s32 *)((s8 *)arg0 + 0);
}

void TBoss2DeRolLe__sub_800360A8(void *arg0) {
  s8 *new_var;
  s8 *new_var2;
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f31;
  f32 temp_f3;
  f32 temp_f4;
  f32 temp_f5;
  new_var = ((s8 *) arg0) + 0xC;
  temp_f4 = *((f32 *) (((s8 *) arg0) + 0x10));
  temp_f31 = -(*((f32 *) (((s8 *) arg0) + 8)));
  temp_f5 = temp_f4 * temp_f4;
  temp_f3 = (TBoss2DeRolLe__data_805D82BC / (*((f32 *) (((s8 *) arg0) + 4)))) - (TBoss2DeRolLe__data_805D82BC / temp_f31);
  new_var2 = ((s8 *) arg0) + 0x1C;
  temp_f1 = (*((f32 *) (((s8 *) arg0) + 0x14))) + (temp_f5 / (lbl_805D844C * temp_f31));
  if ((((TBoss2DeRolLe__data_805D82BC / (*((f32 *) (((s8 *) arg0) + 4)))) - (TBoss2DeRolLe__data_805D82BC / temp_f31)) * (TBoss2DeRolLe__data_805D8288 * temp_f5)) > temp_f1)
  {
    *((f32 *) new_var) = newton_sqrtf((TBoss2DeRolLe__data_805D82A0 * temp_f1) / temp_f3);
    temp_f3 = (TBoss2DeRolLe__data_805D82BC / (*((f32 *) (((s8 *) arg0) + 4)))) - (TBoss2DeRolLe__data_805D82BC / temp_f31);
  }
  temp_f0 = *((f32 *) new_var);
  *((f32 *) new_var2) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x14))) + ((TBoss2DeRolLe__data_805D8288 * (temp_f0 * temp_f0)) / temp_f31));
}

void set_move_params__13TBoss2DeRolLeFPvffff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(f32 *)((s8 *)arg0 + 4) = farg2;
    *(f32 *)((s8 *)arg0 + 8) = farg3;
    *(f32 *)((s8 *)arg0 + 0xC) = farg0;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x14) = farg1;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TBoss2DeRolLe__data_805D827C;
    TBoss2DeRolLe__sub_800360A8(arg0);
}

extern const f32 TBoss2DeRolLe__data_805D827C;

void init_params__13TBoss2DeRolLeFPvfff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(f32 *)((s8 *)arg0 + 4) = farg2;
    *(f32 *)((s8 *)arg0 + 8) = farg2;
    *(f32 *)((s8 *)arg0 + 0xC) = farg0;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x14) = farg1;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TBoss2DeRolLe__data_805D827C;
    TBoss2DeRolLe__sub_800360A8(arg0);
}

void init_float_block__13TBoss2DeRolLeFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(f32 *)((s8 *)arg0 + 4) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 8) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x14) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TBoss2DeRolLe__data_805D827C;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) TBoss2DeRolLe__data_805D827C;
}

s32 free_if_positive__13TBoss2DeRolLeFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

s32 init_resources__13TBoss2DeRolLeFi(s32 arg0) {
    init_float_block__13TBoss2DeRolLeFPv((u8 *)arg0);
    return arg0;
}

extern s32 TBoss2DeRolLe__instance;

s32 get_instance__13TBoss2DeRolLeFv(void) {
    return TBoss2DeRolLe__instance;
}

void TBoss2DeRolLe::apply_poison_status() {  }
void TBoss2DeRolLe::apply_paralysis() {  }
void TBoss2DeRolLe::apply_slow_status() {  }
void TBoss2DeRolLe::apply_confusion_status() {  }
void TBoss2DeRolLe::apply_movement_ailment(s32) {  }
void TBoss2DeRolLe::apply_shock_status() {  }
void TBoss2DeRolLe::clear_harmful_statuses() {  }
void swap_endian__13TBoss2DeRolLeFPv(void* p) { ((TObjPlayer *)p)->read_be16_field2(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); bswap_32__FPUl((char*)p + 0x8); }
void swap_6x13_fields__13TBoss2DeRolLeFPv(void* p) { ((TObjPlayer *)p)->read_be16_field2(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); }
void send_6x13__13TBoss2DeRolLeFPv(void* p) { swap_6x13_fields__13TBoss2DeRolLeFPv(p); TLobby__send_and_handle_60(p); }
void TBoss2DeRolLe__sub_80036358(void* p) { *(u8*)((char*)p + 0x0) = 19; *(u8*)((char*)p + 0x1) = 2; }
void update_and_send__13TBoss2DeRolLeFPv(void* p) { swap_endian__13TBoss2DeRolLeFPv(p); TLobby__send_and_handle_60(p); }
void TBoss2DeRolLe__sub_800363A0(void* p) { *(u8*)((char*)p + 0x0) = 20; *(u8*)((char*)p + 0x1) = 3; }

typedef char RecoveredGlobal_800365C8_lbl_80435A44_size[sizeof(RecoveredGlobal_800365C8_lbl_80435A44) == 0xC ? 1 : -1];

}

}
#pragma pop
