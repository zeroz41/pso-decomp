#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/BmlResource.h"

struct NJS_OBJECT;
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/FloatRounding.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gibon/TObjEneBm5GibonU.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"
#include "pso/technique/TTecZonde.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecMegid.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/TPlyDispData.h"

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as GeeAnimationBinding).

extern "C" {
s32 pack_debug_text_position(s32, s32);
s32 debug_draw_line(void *, void *, u32, u32);
s32 scale_matrix(s32, f32, f32, f32);
s32 translate_matrix(saddr, f32, f32, f32);
s32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
void render_debug__16TObjEneBm5GibonUFv(u8 *arg0);
s32 enemy_validate_retained_target(u8 *ene_dd_st);
void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1);
s32 TObjEneBm5GibonU__sub_800D0968(TObjEneBm5GibonU *self, int);
s32 approach_angle_limited(s32, s32, s32);
extern const s32 lbl_8043BF30[];
extern const s32 lbl_8043BF38[];
extern const s32 lbl_8043BF40[];
extern const s32 lbl_8043BF48[];
TObjEneBm5GibonU *TObjEneBm5GibonU__sub_800D13B8(TObjEneBm5GibonU *self, s16 arg1);
void rotate_xz_pair_by_angle(f32 *, f32 *, s32);
f32 atan2_float(f32 y, f32 x);
s32 get_entity_id(int);
void update_shock_clock__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void TObjEneBm5GibonU__sub_800D0738(TObjEneBm5GibonU *self, u32 arg1, s32 arg2);
void TObjEneBm5GibonU__sub_800D0AE8(TObjEneBm5GibonU *self, Vec *dir);
void update_body_colliders__16TObjEneBm5GibonUFv(u8 *arg0);
void run_death_reaction__16TObjEneBm5GibonUFv(void *arg0);
void run_hit_reaction__16TObjEneBm5GibonUFv(void* p);
void run_demo_task__16TObjEneBm5GibonUFv(void *arg0);
BmlResource * TObjEneBm5GibonU__model_archive;
#pragma push
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void run_miss_reaction__16TObjEneBm5GibonUFv();
}
extern "C" {
void refresh_target__16TObjEneBm5GibonUFv();
}
extern "C" {
void snap_to_ground_at__9TObjEneDDFPUc();
}
extern "C" {
void apply_enemy_state__9TObjEneDDFPl();
}
extern "C" {
void update_immobilizing_statuses__9TObjEneDDFv();
}
extern "C" {
void update_action_state__9TObjEneDDFv();
}
extern "C" {
void has_action_state_changed__9TObjEneDDFv();
}
extern "C" {
void check_collisions__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void set_invulnerable__9TObjEneDDFv();
}
extern "C" {
void clear_invulnerable__9TObjEneDDFv();
}
extern "C" {
void enable_body_collision__9TObjEneDDFv();
}
extern "C" {
void disable_body_collision__9TObjEneDDFv();
}
extern "C" {
void set_intangible__9TObjEneDDFv();
}
extern "C" {
void clear_intangible__9TObjEneDDFv();
}
extern "C" {
void set_colliders_contact_high__9TObjEneDDFv();
}
extern "C" {
void set_colliders_contact_low__9TObjEneDDFv();
}
extern "C" {
void is_confused__9TObjEneDDFv();
}
extern "C" {
void render_minimap_dot__9TObjEneDDFv();
}
extern "C" {
void move_xz_on_ground__9TObjEneDDFPUc();
}
extern "C" {
void update_ground_contact__9TObjEneDDFv();
}
extern "C" {
int acquire_target__12TObjEneDD_STFf(void *p);
}
extern "C" {
void update_status_effects__12TObjEneDD_STFv();
}
extern "C" {
void has_no_target__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void deliver_attack_hits__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void run_attack_action__9TObjCharaFv();
}
extern "C" {
void run_move_action__9TObjCharaFv();
}
extern "C" {
void run_idle_action__9TObjCharaFv();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_confusion_status__9TObjCharaFv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUcf();
}
extern "C" {
void apply_movement_ailment__9TObjCharaFl();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_paralysis__9TObjCharaFv();
}
extern "C" {
void apply_poison_status__9TObjCharaFv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__9TObjCharaFv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void clear_harmful_statuses__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void gain_photon_blast_chain_charge__9TObjCharaFv();
}
extern "C" {
void spend_photon_blast_charge__9TObjCharaFf();
}
extern "C" {
void gain_photon_blast_charge__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__9TObjCharaFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
void is_target_in_attack_range__9TObjCharaFv();
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void update_action_hold_status__9TObjCharaFv();
}
extern "C" {
s32 update_slow_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
TObjEneBm5GibonUMovementParameters TObjEneBm5GibonU__movement_parameters = {
    225.0f, 0.0f, 0x600, { 0, 0, 0, 0 },
};
CollisionBody gibon_collision_body_templates[4] = {
    { { 0.0f, 10.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 16.0f, 0.0f }, 12.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 6.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *lbl_80493D6C[3] = {
    "gibon.nj", "gibonb_gibon.nj", NULL,
};
const char *gibon_u_animation_name_table[10] = {
    "attack_gibon.njm", "back_gibon.njm", "damage_gibon.njm", "dead_gibon.njm", "fire_gibon.njm",
    "hoe_gibon.njm", "run_gibon.njm", "wait_gibon.njm", "walk_gibon.njm", NULL,
};
BmlResourceDescriptor lbl_80493DA0 = {
    "bm_ene_bm5_gibon_u.bml", lbl_80493D6C, gibon_u_animation_name_table, 2, 9,
};
const char *lbl_80493DB0[3] = {
    "lo_gibon.nj", "lo_gibonb_gibon.nj", NULL,
};
const char *gibon_u_animation_file_table[10] = {
    "attack_gibon.njm", "back_gibon.njm", "damage_gibon.njm", "dead_gibon.njm", "fire_gibon.njm",
    "hoe_gibon.njm", "run_gibon.njm", "wait_gibon.njm", "walk_gibon.njm", NULL,
};
BmlResourceDescriptor lbl_80493DE4 = {
    "bm_ene_bm5_gibon_u_low.bml", lbl_80493DB0, gibon_u_animation_file_table, 2, 9,
};
TObjMotionAction gibon_u_action_table[17] = {
    { MOTION_MODE_LOOP, 0, 7, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 8, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 6, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 6, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 7, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 2, 1.0f, 0 },
    { MOTION_MODE_CHAIN, 8, 2, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 9, 5, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 0, 1.2f, 0 },
    { MOTION_MODE_ONCE, 0, 3, 1.3f, 0 },
    { MOTION_MODE_ONCE, 0, 1, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 4, 1.0f, 0 },
    { MOTION_MODE_CHAIN, 9, 7, 0.5f, 0 },
    { MOTION_MODE_ONCE, 0, 0, 1.0f, 0 },
    { MOTION_MODE_ONCE, 0, 6, 1.0f, 0 },
};
const char *TObjEneBm5GibonU__class_name = "TObjEneBm5GibonU";
const NpcAnimationBinding TObjEneBm5GibonU__spawn_params = { NULL, reinterpret_cast<TObjMotionAction *>(gibon_u_action_table), 0, 1, 17 };
void *lbl_80493F04[107] = {
    (void *)0x0, (void *)0x0, (void *)TObjEneBm5GibonU__sub_800D13B8, (void *)run_task__16TObjEneBm5GibonUFv,
    (void *)render__16TObjEneBm5GibonUFv, (void *)render_shadows__9TObjEnemyFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv, (void *)get_center__9TObjCharaFv, (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__14TObjCollidableFl, (void *)add_actor_exp__9TObjCharaFl, (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv, (void *)update_actor_ground_y__9TObjCharaFv, (void *)vfunc_18__9TObjCharaFPUc, (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf, (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)receive_physical_attack__9TObjCharaFPvf, (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv, (void *)apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)try_start_action__9TObjCharaFll, (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)refresh_target__16TObjEneBm5GibonUFv, (void *)has_no_target__9TObjCharaFv, (void *)is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv, (void *)update_slow_status__9TObjCharaFv, (void *)update_flag30_timer__9TObjCharaFv, (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv, (void *)update_attack_stat_status__9TObjCharaFv, (void *)update_defense_stat_status__9TObjCharaFv, (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv, (void *)apply_paralysis__9TObjCharaFv, (void *)apply_slow_status__9TObjCharaFv, (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl, (void *)apply_shock_status__9TObjCharaFv, (void *)clear_harmful_statuses__9TObjCharaFv, (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv, (void *)cure_poison_ailment__9TObjCharaFv, (void *)cure_paralysis__9TObjCharaFv, (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf, (void *)apply_anti_technique__9TObjCharaFl, (void *)run_idle_action__9TObjCharaFv, (void *)run_move_action__9TObjCharaFv,
    (void *)run_attack_action__9TObjCharaFv, (void *)run_miss_reaction__16TObjEneBm5GibonUFv, (void *)run_hit_reaction__16TObjEneBm5GibonUFv, (void *)run_death_reaction__16TObjEneBm5GibonUFv,
    (void *)reset_pose__9TObjCharaFv, (void *)get_anim_node_position__9TObjCharaFlP3Vec, (void *)vfunc_66__9TObjCharaFv, (void *)deliver_attack_hits__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl, (void *)apply_switch_attack__9TObjCharaFv, (void *)enemy_spawn_jellen_effect__9TObjCharaFv, (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv, (void *)recalc_stats__9TObjCharaFv, (void *)vfunc_74__9TObjEnemyFl, (void *)gain_photon_blast_charge__9TObjCharaFf,
    (void *)spend_photon_blast_charge__9TObjCharaFf, (void *)gain_photon_blast_chain_charge__9TObjCharaFv, (void *)vfunc_78__9TObjCharaFl, (void *)apply_enemy_state__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv, (void *)update_status_effects__12TObjEneDD_STFv,
    (void *)update_immobilizing_statuses__9TObjEneDDFv, (void *)update_action_state__9TObjEneDDFv, (void *)has_action_state_changed__9TObjEneDDFv, (void *)TObjEneBm5GibonU__sub_800D0738,
    (void *)update_body_colliders__16TObjEneBm5GibonUFv, (void *)check_collisions__9TObjEneDDFv, (void *)vfunc_90__9TObjEneDDFv, (void *)set_invulnerable__9TObjEneDDFv,
    (void *)clear_invulnerable__9TObjEneDDFv, (void *)enable_body_collision__9TObjEneDDFv, (void *)disable_body_collision__9TObjEneDDFv, (void *)set_intangible__9TObjEneDDFv,
    (void *)clear_intangible__9TObjEneDDFv, (void *)set_colliders_contact_high__9TObjEneDDFv, (void *)set_colliders_contact_low__9TObjEneDDFv, (void *)is_confused__9TObjEneDDFv,
    (void *)render_minimap_dot__9TObjEneDDFv, (void *)move_xz_on_ground__9TObjEneDDFPUc, (void *)update_ground_contact__9TObjEneDDFv, (void *)snap_to_ground_at__9TObjEneDDFPUc,
    (void *)acquire_target__12TObjEneDD_STFf, (void *)run_demo_task__16TObjEneBm5GibonUFv, (void *)render_debug__16TObjEneBm5GibonUFv,
};
__declspec(section ".data") u8 *TObjEneBm5GibonU__data_80500E78[2];
__declspec(section ".data") u8 *lbl_80500E80[2];
__declspec(section ".data") u8 *lbl_80500E88[2];
__declspec(section ".data") u8 *lbl_80500E90[2];
__declspec(section ".data") f32 lbl_80500E98[3];
__declspec(section ".data") u32 lbl_80500EA4[3];
__declspec(section ".data") u32 TObjEneBm5GibonU__node_list[5];
__declspec(section ".data") u32 TObjEneBm5GibonU__enemy_list[3];
}

#pragma pop
#pragma push


extern "C" {
extern s32 game_difficulty_selection;
s32 fn_800D88E4(void *);
void TObjEneBm5GibonU__sub_800D02F8(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CFE30(TObjEneBm5GibonU *self, s32 arg1);
void TObjEneBm5GibonU__sub_800CFA48(TObjEneBm5GibonU *self, s32 arg1);
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
s32 is_split_screen();
s32 draw_blob_shadow(s32);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 TObjEneBm5GibonU__render_node_index;
s32 TObjEneBm5GibonU__render_joint_y_rotation;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
s32 is_vec_xz_cross_negative(void *, void *);
void spawn_dead_spot_scale15(s32 point, s32 delay);
s32 vec3_add_to(void *, void *);
s32 obj_is_hit_receivable(u8 *arg0);
void TObjEneBm5GibonU__sub_800CDB98(TObjEneBm5GibonU *self, s32 arg1);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 select_enemy_destination(void *, Vec, s32);
void copy_position_if_valid__10TObjPlayerFii(void *, Vec);
f32 newton_sqrtf(f32);
void *spawn_directional_particle(void *pos, void *dir, s32 id);
void rotate_vector_by_matrix(saddr, void *, void *);
void subtract_vector(void *, void *);
extern u8 identity_matrix[];
extern saddr tl_07;

s32 TObjEneBm5GibonU::get_clamped_level() {
    player_stats *p = (player_stats *)m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

s32 TObjEneBm5GibonU::check_hit_sphere(int angle, f32 scale) {
    CollisionBody *body;
    u8 hit;
    s32 saved_rotation;
    u32 saved_flags;
    scale *= 0.5f;
    body = bodies;
    saved_rotation = rotation_y;
    saved_flags = body->flags;
    body->offset.x = 0.0f;
    body->offset.z = scale;
    body->radius = scale;
    body->half_width = 8.0f;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = angle;
    check_collisions();
    update_enemy_collision_flags();
    hit = (body->flags & 0x380000) != 0;
    if (m_464 == 1) {
        copy_collision_body(body, &gibon_collision_body_templates[1]);
    } else {
        copy_collision_body(body, &gibon_collision_body_templates[0]);
    }
    body->flags = saved_flags;
    rotation_y = saved_rotation;
    return hit;
}

int TObjEneBm5GibonU::get_attack_state(void *pos) { return spawn_landing_effect((Vec *)pos); }

int TObjEneBm5GibonU::spawn_landing_effect(Vec *pos) {
    Vec v;
    CsnHit *hit;
    void *p;
    VecCopy(&v, pos);
    v.y += 15.0f;
    hit = csnVectorUnder(&v, (CsnGroup **)&m_120, 5);
    if (hit != NULL && (hit->hit_mask & 4)) {
        p = spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (p != NULL) {
            attach_particle_model((u8 *)p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            if (m_464 == 1) {
                ((TParticleCtrl *)p)->set_scale(1.5f, 1.0f);
            }
        }
        p = spawn_particle_effect(&hit->contact[2].point, 0xA4);
        if (p != NULL && m_464 == 1) {
            ((TParticleCtrl *)p)->set_scale(1.5f, 1.0f);
        }
        return fn_800D88E4(&position);
    }
    return play_sound_effect(remap_sound_for_area(0x3BC21), &position, 0, 0);
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CCD8C(TObjEneBm5GibonU *self) {
    if ((self->is_passing_frame(7.0f) != 0) || (self->is_passing_frame(28.0f) != 0)) {
        self->spawn_landing_effect(&self->position);
    }
}
#pragma pop

void TObjEneBm5GibonU__sub_800CCDE4(TObjEneBm5GibonU *self) {
    if (self->is_passing_frame(10.0f) != 0) {
        self->get_attack_state(&self->position);
    }
}

void TObjEneBm5GibonU__sub_800CCE28(TObjEneBm5GibonU *self) {
    if ((self->is_passing_frame(12.0f) != 0) || (self->is_passing_frame(28.0f) != 0)) {
        self->get_attack_state(&self->position);
    }
}

#pragma pool_data off
void TObjEneBm5GibonU::render_debug() {
    Vec v;
    s32 idx;
    f32 frame;
    AnimationMotion *motion;
    TObjEneBm5GibonU *other;
    if (this->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), "GROUP:%2d", m_46c);
        if (m_470 == 1) {
            debug_printf_at(pack_debug_text_position(0, 3), "SPOT APPEAR");
        } else {
            debug_printf_at(pack_debug_text_position(0, 3), "JUMP APPEAR");
        }
        if (m_464 != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), "L/M:LEADER");
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), "L/M:MEMBER");
        }
        debug_printf_at(pack_debug_text_position(0, 4), "BACKJUMP(+0.4f)");
        debug_printf_at(pack_debug_text_position(0, 5), "RUN_FOIE(+0.3f)");
        debug_printf_at(pack_debug_text_position(0, 6), "BACK_FOIE(+0.3f)");
    }
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        if (m_464 == 1) {
            scale_matrix(0, 1.5f, 1.5f, 1.5f);
        } else {
            scale_matrix(0, 2.0f, 2.0f, 2.0f);
        }
        idx = (s32)parameters[3];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x11) {
            idx = 0x10;
        }
        motion = motion_list[action_table[idx].motion].motion;
        frame = parameters[4];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (motion->frameCount - 1)) {
            frame = (f32)motion->frameCount;
        }
        translate_matrix(0, 0.0f, 0.0f, -10.0f);
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(model, motion, frame);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    other = TObjEneBm5GibonU::find_enemy_by_id(m_46c);
    if (other != 0) {
        debug_draw_line(&body_center, &other->body_center, 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    VecCopy(&v, &body_center);
    v.y += 50.0f;
    debug_draw_line(&body_center, &v, 0xFFC0C0C0, 0xFF6060FF);
}
#pragma pool_data reset

void TObjEneBm5GibonU::run_demo_task() {
    s32 temp_r31;

    if (this->get_target_info() != 0) {
        temp_r31 = m_464;
        sub_800D10A0();
        if (temp_r31 != m_464) {
            if (temp_r31 != 0) {
                forward_hit_to_enemy_list();
            } else {
                init_child_from_list();
            }
        }
        update_center_position();
    }
}

void TObjEneBm5GibonU::render() {
    s32 rot[3];
    s32 cam;
    s32 vis;
    s32 fade;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_debug();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (!(m_4ac & 2) && this->mode != 0x12) {
        fade = 0;
        if (m_464 != 0) {
            m_3f4[cam].update();
            fade = m_3f4[cam].updateFromCamera(&body_center.x);
        }
        if (TObjEneDD::is_main_phase_15() != 0) {
            vis = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 20.0f);
        } else if (update_object_view_visibility(400.0f, 20.0f) != 0) {
            vis = 1;
        } else {
            vis = 0;
        }
        if (vis != 0) {
            if (this->mode != 0x11) {
                direction_to_rotation_xz((u8 *)&ground_normal, &rot[0], &rot[2]);
                push_matrix();
                post_translate_matrix(&position);
                translate_matrix(0, 0.0f, 0.3f, 0.0f);
                rotate_matrix_z(0, rot[2]);
                rotate_matrix_x(0, rot[0]);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, 0.0f, 0.0f, -3.0f);
                scale_matrix(0, 2.0f, 1.0f, 3.0f);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            if (this->mode == 1 || this->mode == 2) {
                m_3d8.set_flags_and_apply_damage_color();
            } else if (fade != 0) {
                m_3f4[cam].set_flags_and_apply_damage_color();
            }
            post_translate_matrix(&position);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, 0.0f, 0.0f, -10.0f);
            if (m_464 == 1) {
                scale_matrix(0, 1.5f, 1.5f, 1.5f);
            } else {
                scale_matrix(0, 2.0f, 2.0f, 2.0f);
            }
            TObjEneBm5GibonU__render_node_index = 0;
            TObjEneBm5GibonU__render_joint_y_rotation = -(m_478 / 2);
            set_chunk_model_node_callback(TObjEneBm5GibonU::advance_anim_frame);
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (fade != 0) {
                if (defer_render() == 0) {
                    if (vis == 1) {
                        this->draw();
                    } else {
                        this->draw_motion_model();
                    }
                }
            } else if (vis == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            if (this->mode == 1 || this->mode == 2) {
                m_3d8.clear_flag_and_notify();
            } else if (fade != 0) {
                m_3f4[cam].clear_flag_and_notify();
            }
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5GibonU::advance_anim_frame(NJS_OBJECT *) {
    if (((s32) TObjEneBm5GibonU__render_node_index >= 0x30) && ((s32) TObjEneBm5GibonU__render_node_index < 0x32)) {
        rotate_matrix_y(0, TObjEneBm5GibonU__render_joint_y_rotation);
    }
    TObjEneBm5GibonU__render_node_index += 1;
}

void TObjEneBm5GibonU::handle_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneBm5GibonU::state_cast_technique(s32 arg1) {
    Vec v;
    Vec p;
    s32 ang[3];
    s32 r;
    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(14);
        clear_intangible();
        m_4ac &= ~2;
        enemy_copy_target_destination();
        m_518 = 0;
        break;
    case 3:
        if (m_518 == 2) {
            transition_enemy_state(8);
        }
        break;
    case 0:
        update_prev_position();
        if (m_518 != 1) {
            if (current_target == 0) {
                transition_enemy_state(8);
            } else {
                if (select_enemy_destination(this, destination, 1) != 0) {
                    copy_position_if_valid__10TObjPlayerFii(this, body_center);
                    r = enemy_turn_toward_dest(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn);
                    enemy_set_heading_velocity(((TObjEneBm5GibonUMovementParameters *)movementParameters)->speed, this, rotation_y);
                    move_with_wall_slide((u8 *)this);
                } else {
                    VecCopy(&v, &destination);
                    subtract_vector(&v, &body_center);
                    r = turn_toward_direction(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn, &v);
                }
                if (r < 0x100) {
                    m_518 = 1;
                    requested_action = 13;
                } else {
                    requested_action = 1;
                }
            }
        } else {
            advance_animation();
            if (get_flag_b4() != 0) {
                m_518 = 2;
            }
            if (is_passing_frame(15.0f) != 0) {
                p.x = 0.0f;
                p.y = 15.0f;
                p.z = 12.0f;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, rotation_y);
                rotate_vector_by_matrix(0, &p, &p);
                pop_matrices(1);
                vec3_add_to(&p, &body_center);
                if (current_target != 0) {
                    VecCopy(&v, &destination);
                    subtract_vector(&v, &body_center);
                    r = turn_toward_direction(((TObjEneBm5GibonUMovementParameters *)movementParameters)->turn, &v);
                } else {
                    r = ((AttackParams *)m_318)->get_attack_angle();
                }
                if (game_difficulty_selection == 3) {
                    switch (m_468) {
                    case 1:
                        if (r < ((AttackParams *)m_318)->get_attack_angle() / 2 && current_target != 0) {
                            TTecMegid::create((saddr)this, (saddr)&p, (saddr)&destination, (s32)(get_clamped_level()));
                        } else {
                            TTecMegid::create_ex((saddr)this, (saddr)&p, rotation_y, (s32)(get_clamped_level()));
                        }
                        play_sound_effect(0x4002A60B, &p, 0, 0);
                        break;
                    default:
                        if (r < ((AttackParams *)m_318)->get_attack_angle() / 2 && current_target != 0) {
                            clear_target_cursor_list((TargetCursorList *)&m_4b0);
                            m_4b0 = 1;
                            m_4b4 = get_entity_id((saddr)current_target);
                            m_4b6 = 0;
                            TTecGiZonde::create(this, &p, &m_4b0, get_clamped_level());
                        } else {
                            void *e;
                            spawn_particle_effect(&p, 0xB9);
                            spawn_particle_effect(&p, 0xBA);
                            v.x = 0.0f;
                            v.y = 0.0f;
                            v.z = 1.0f;
                            push_matrix_from(identity_matrix);
                            rotate_matrix_y(0, rotation_y);
                            rotate_vector_by_matrix(0, &v, &v);
                            pop_matrix();
                            e = TObject::operator new(0x260);
                            if (e != 0) {
                                ((TTecZonde *)e)->construct_bolt_effect((u8 *)tl_07, (u8 *)&p, (u8 *)&v, 0x14000000, 20, (f32)(((AttackParams *)m_318)->get_attack_range()), 1.8f);
                            }
                        }
                        play_sound_effect(0x4002A408, &p, 0, 0);
                        break;
                    }
                } else {
                    switch (m_468) {
                    case 1:
                        TTecGiBarta::create_ex(this, &p, rotation_y, get_clamped_level());
                        break;
                    default:
                        if (r < ((AttackParams *)m_318)->get_attack_angle() / 2 && current_target != 0) {
                            TTecFoie::create_ex(this, &p, &current_target->body_center, get_clamped_level());
                        } else {
                            TTecFoie::create(this, &p, rotation_y, get_clamped_level());
                        }
                        break;
                    }
                    v.x = 0.0f;
                    v.y = 0.0f;
                    v.z = 0.0f;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, rotation_y);
                    rotate_vector_by_matrix(0, &v, &v);
                    pop_matrices(1);
                    if (m_468 != 1) {
                        ang[0] = (s32)(10430.38043493439 * atan2_float(v.z, newton_sqrtf(v.x * v.x + v.y * v.y)));
                        ang[1] = 0;
                        ang[2] = -(s32)(10430.38043493439 * atan2_float(v.x, v.y));
                        spawn_directional_particle(&p, ang, 0xCC);
                    }
                }
            }
        }
        break;
    case 5:
        break;
    }
    ((TObjPlayer *)this)->update_collisions();
}

void TObjEneBm5GibonU__sub_800CDB98(TObjEneBm5GibonU *self, s32 arg1) {
    s32 offs[3];
    switch (arg1) {
    case 4:
        self->requested_action = 0xC;
        self->set_field_378(0xE);
        self->clear_intangible();
        self->m_4ac &= ~2;
        self->m_518 = 0;
        self->m_52c = 0;
        offs[0] = (s32)(3.0f * self->random_ratio()) - 1;
        offs[1] = (s32)(2.0f * self->random_ratio()) - 1;
        if (offs[1] <= offs[0]) {
            offs[1]++;
        }
        self->destination_direction.x = 0.0f;
        self->destination_direction.y = 0.0f;
        self->destination_direction.z = 0.0f;
        offs[2] = -(offs[0] + offs[1]);
        self->destination_distance = 0.0f;
        if (((TObjEneBm5GibonU *)self)->update_target() != 0) {
            s32 d;
            int ang;
            s32 i;
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->m_528 = (s32)(10430.38043493439 * atan2_float(self->destination_direction.x, self->destination_direction.z));
            for (i = 0; i < 3; i++) {
                d = offs[i] * 0x1FFF;
                ang = self->m_528 + 0x10000 + d - 0x8000;
                if (self->check_hit_sphere(ang, 160.0f) == 0) {
                    f32 dx = 2.0f * (60.0f * sin_table_lookup(ang));
                    f32 dz = 2.0f * (60.0f * cos_table_lookup(ang));
                    if ((u32)((TObjEneDD *)self)->enemy_probe_wall_ahead(dx, dz, 1.0f) == 0) {
                        Vec v;
                        VecCopy(&v, (const Vec *)&self->body_center);
                        v.x += dx;
                        v.z += dz;
                        if (csnVectorUnder(&v, (CsnGroup **)&self->m_120, 0x15) != 0) {
                            self->destination_direction.x = sin_table_lookup(ang);
                            self->destination_direction.y = 0.0f;
                            self->destination_direction.z = cos_table_lookup(ang);
                            self->destination_distance = 60.0f;
                            self->m_528 += d / 2;
                            break;
                        }
                    }
                }
            }
        }
        self->m_498 = self->m_494 = self->destination_distance / 33.0f;
        self->m_518 = 0;
        self->set_invulnerable();
        break;
    case 3:
        if (self->m_518 == 1) {
            if (self->random_ratio() < self->m_4a8) {
                self->transition_enemy_state(0x14);
            } else {
                self->transition_enemy_state(8);
            }
        }
        break;
    case 0:
        switch (self->m_518) {
        case 0:
            self->advance_animation();
            if (self->get_flag_b4() != 0) {
                self->m_518 = 1;
            }
            TObjEneBm5GibonU__sub_800CCD8C(self);
            if (self->is_passing_frame(8.0f) != 0) {
                play_sound_effect(self->remap_sound_for_area(0x3B22A), &self->position, 0, 0);
            }
            if (self->is_passing_frame(33.0f) != 0) {
                self->clear_invulnerable();
                TObjPlayer::init_all_slots();
                self->check_object_collisions();
                if (self->m_50c->bodies->flags & 0x80000) {
                    s32 i;
                    for (i = 0; i < 16; i++) {
                        TObjPlayer *p = (TObjPlayer *)TObjPlayer::get_battle_param(i);
                        if (p == 0) {
                            break;
                        }
                        if (obj_is_hit_receivable((u8 *)p) != 0 && p->select_melee_contact_body(self, 1.0f) != 0) {
                            p->apply_knockback_from_attacker((u8 *)self, 1.0f);
                            p->receive_physical_attack(self, 1.0f);
                        }
                    }
                }
            }
            self->approach_target(0.1f);
            self->rotation_y = approach_angle_limited(self->rotation_y, self->m_528, 0x1000);
            self->rotation_y = (s16)self->rotation_y;
            ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->rotation_y);
            if (self->frame <= 33.0f) {
                self->move_with_wall_slide_on_ground(self->destination_direction.x, self->destination_direction.z, self->m_498);
            }
            break;
        }
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    case 5:
        self->play_sound_variant();
        self->clear_invulnerable();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CE060(TObjEneBm5GibonU *self, s32 arg1) {
    Vec sp14;
    Vec sp8;
    f32 k;
    TObjEneBm5GibonUNode *n;
    u8 *o;
    switch (arg1) {
    case 4:
        self->clear_intangible();
        self->refresh_and_send_entity_flags();
        play_sound_effect(self->remap_sound_for_area(0x3A826), &self->position, 0, 0);
        self->requested_action = 0xB;
        TBoss8Dragon__sub_800BB7D4(self, 0xF1);
        self->m_518 = 0;
        self->m_530 = ((TObjEneBm5GibonU *)self)->calc_anim_speed(self->action_table[7].speed);
        self->m_538 = 0.0f;
        self->wall_reach = 0.0f;
        if (self->m_464 != 0) {
            k = 50.0f;
            for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__node_list)->head; n != NULL; n = n->next) {
                o = (u8 *)((TObjEneBm5GibonU *)n)->update_photon_mylla();
                if (o != NULL && ((TObjEneBm5GibonU *)o)->m_46c == self->m_46c) {
                    ((void (*)(void *, s32, u16))TObjEneBm5GibonU__sub_800D095C)(o, (s32)(k * self->random_ratio()) + 0x14, self->attacker_id);
                }
            }
        }
        self->set_active();
        return;
    case 3:
        if (self->m_518 == 2) {
            self->transition_enemy_state(0x12);
        }
    case 1:
        return;
    case 0:
        switch (self->m_518) {
        case 0:
            self->advance_animation();
            if (self->get_flag_b4() != 0) {
                self->m_518 = 1;
                sp14.x = 0.0f;
                sp14.y = 0.0f;
                sp14.z = -10.0f;
                rotate_xz_pair_by_angle(&sp14.x, &sp14.z, self->rotation_y);
                vec3_add_to(&sp14, &self->position);
                if (self->m_464 == 1) {
                    spawn_dead_spot_scale15((saddr)&sp14, 0x32);
                } else {
                    TObjPlayer::spawn_dead_spot_type2((saddr)&sp14, 0x32);
                }
                ((TObjPlayer *)(&sp14))->spawn_effect_at_ground(0x46);
            }
            self->rotation_y = approach_angle_limited(self->rotation_y, self->m_528, 0x300);
            self->rotation_y = (s16)self->rotation_y;
            if (self->wall_reach < 28.0f) {
                self->wall_reach += self->m_530;
            }
            VecCopy(&sp8, (const Vec *)&self->x_speed);
            {
                f32 v = normalize_vector_xz(&sp8);
                self->move_clamped_on_ground(sp8.x, sp8.z, v);
            }
            if (self->is_passing_frame(26.0f) != 0) {
                TObjEneBm5GibonU__sub_800D0AE8(self, &sp8);
            }
            self->x_speed *= 0.8f;
            self->m_310 *= 0.8f;
            ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->rotation_y);
            self->update_body_colliders();
            break;
        case 1:
            self->position.y -= 0.1f;
            self->m_538 += 0.1f;
            if (self->m_538 > 20.0f) {
                self->m_518 = 2;
            }
            break;
        }
        break;
    case 5:
        self->clear_field_388();
        return;
    }
}

void TObjEneBm5GibonU__sub_800CE370(TObjEneBm5GibonU *self, s32 arg1) {
    Vec sp8;
    switch (arg1) {
    case 4:
        self->clear_intangible();
        TBoss8Dragon__sub_800BB7D4(self, 0xF1);
        self->m_51c = 0;
        self->m_528 = 0;
        self->requested_action = 6;
        self->m_518 = 0;
        if (self->referenceHp - self->hp < 0x14) {
            play_sound_effect(self->remap_sound_for_area(0x3A824), &self->position, 0, 0);
        }
        self->set_active();
        break;
    case 3:
        if (self->motion_flags & 0x10) {
            switch (self->next_mode) {
            case 12:
                self->transition_enemy_state(0xE);
                break;
            case 3:
                self->transition_enemy_state(8);
                break;
            default:
                self->transition_enemy_state(self->next_mode);
                break;
            }
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&sp8, (const Vec *)&self->x_speed);
        {
            f32 v = normalize_vector_xz(&sp8);
            self->move_with_wall_slide_on_ground(sp8.x, sp8.z, v);
        }
        if (self->m_518 == 0) {
            self->x_speed *= 0.5f;
            self->m_310 *= 0.5f;
        } else {
            self->x_speed *= 0.9f;
            self->m_310 *= 0.9f;
            self->rotation_y = approach_angle_limited(self->rotation_y, self->m_528, 0x300);
            self->rotation_y = (s16) self->rotation_y;
            if (self->is_passing_frame(26.0f) != 0) {
                TObjEneBm5GibonU__sub_800D0AE8(self, &sp8);
            }
        }
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    case 5:
        self->clear_attack_receipts();
        self->clear_field_388();
        break;
    }
}

void action__16TObjEneBm5GibonUFPvi(TObjEneBm5GibonU *self, s32 arg1) {
    s32 temp_r0;

    switch (arg1) {
    case 4:
        self->clear_intangible();
        self->set_field_378(8);
        self->requested_action = 9;
        self->m_518 = 0;
        TObjEneBm5GibonU::find_enemy_by_id(self->m_46c);
        return;
    case 3:
        if (self->get_flag_b4() != 0) {
            self->transition_enemy_state(8);
        }
    case 5:
        return;
    case 0:
        self->advance_animation();
        ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->rotation_y);
        if (self->is_passing_frame(10.0f) != 0) {
            play_sound_effect(self->remap_sound_for_area(0x3AA22), &self->position, 0, 0);
        }
        self->m_518++;
        temp_r0 = self->m_518;
        if (temp_r0 == 0x1E) {
            self->damage_linked_entity_type10();
        } else if (temp_r0 == 0x28) {
            self->damage_linked_entity();
        }
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CE694(TObjEneBm5GibonU *self, s32 arg1) {
    Vec v;
    f32 dx;
    f32 dz;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(0xE);
        self->clear_intangible();
        self->m_518 = 0;
        self->m_528 = 0;
        self->m_51c = 0;
        break;
    case 3:
        if (self->m_518 == 2) {
            if (self->current_target != NULL) {
                self->transition_enemy_state(0xB);
            } else {
                self->transition_enemy_state(8);
            }
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        switch (self->m_518) {
        case 0:
            self->m_528 = ((self->m_51c >> 1) << 0xC) + 0x1800;
            if (self->m_51c & 1) {
                self->m_528 = -self->m_528;
            }
            if (((TObjEneBm5GibonU *)self)->is_active() == 0) {
                self->m_528 = -self->m_528;
            }
            self->m_528 += self->rotation_y;
            (self->m_51c)++;
            if (self->m_51c > 8) {
                self->m_518 = 2;
            }
            dx = 16.0f * sin_table_lookup(self->m_528);
            dz = 16.0f * cos_table_lookup(self->m_528);
            self->m_50c->position.x = self->position.x + dx;
            self->m_50c->position.y = self->position.y;
            self->m_50c->position.z = self->position.z + dz;
            ((TObjPlayer *)self->m_50c)->update_collisions();
            if (!(self->m_50c->bodies->flags & 0x380000)) {
                dx *= 2.0f;
                dz *= 2.0f;
                if (((TObjEneDD *)self)->enemy_probe_wall_ahead(dx, dz, 1.0f) == 0U) {
                    VecCopy(&v, &self->body_center);
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, (CsnGroup **)&self->m_120, 0x15) != NULL) {
                        self->m_518 = 1;
                        self->requested_action = 0x10;
                        self->destination_direction.x = sin_table_lookup(self->m_528);
                        self->destination_direction.y = 0.0f;
                        self->destination_direction.z = cos_table_lookup(self->m_528);
                    }
                }
            }
            break;
        case 1:
            if (self->get_flag_b4() != 0) {
                ((TObjEneBm5GibonU *)self)->update_target();
                self->m_518 = 2;
            }
            TObjEneBm5GibonU__sub_800CCDE4(self);
            self->move_with_wall_slide_on_ground(self->destination_direction.x, self->destination_direction.z, 1.8f);
            self->rotation_y = approach_angle_limited(self->rotation_y, self->m_528, 0xF00);
            ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->m_528);
            self->check_collisions();
            self->update_enemy_collision_flags();
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CE978(TObjEneBm5GibonU *self, s32 arg1) {
    Vec dir;
    Vec diff;
    Vec *home = &self->m_54c;
    f32 range = self->m_530;
    u8 *tgt;
    switch (arg1) {
    case 4:
        self->requested_action = 1;
        self->set_field_378(0xD);
        self->clear_intangible();
        self->m_494 = 1.6f;
        self->m_518 = 0;
        VecCopy(home, &self->position);
        TObjBoss2Tunnel::calc_scaled_value(0x200, 1.6f);
        self->m_52c = self->rotation_y;
        if (self->enemy_has_live_target() != 0) {
            dir.x = sin_table_lookup(self->rotation_y);
            dir.z = cos_table_lookup(self->rotation_y);
            tgt = (u8 *)self->current_target;
            diff.x = ((TObjEneBm5GibonU *)tgt)->position.x - self->position.x;
            diff.z = ((TObjEneBm5GibonU *)tgt)->position.z - self->position.z;
            if (is_vec_xz_cross_negative(&dir, &diff) != 0) {
                self->m_528 = 0x5000;
            } else {
                self->m_528 = -0x5000;
            }
        } else if (self->random_ratio() < 0.5f) {
            self->m_528 = 0x5000;
        } else {
            self->m_528 = -0x5000;
        }
        self->m_528 += self->m_52c;
        return;
    case 3:
        if (self->current_target == NULL || self->m_518 > 0x96) {
            self->transition_enemy_state(8);
            return;
        }
        if (self->destination_distance < range) {
            self->transition_enemy_state(0xB);
        }
    case 5:
        return;
    case 0:
        (self->m_518)++;
        self->advance_animation();
        if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
            TObjEneBm5GibonU__sub_800CCE28(self);
            self->m_528 = approach_angle_limited(self->m_528, self->m_52c, 0x100);
            self->destination.x = 90.0f * sin_table_lookup(self->m_528) + home->x;
            self->destination.z = 90.0f * cos_table_lookup(self->m_528) + home->z;
            self->update_velocity();
            self->approach_target(0.2f);
            self->play_speed = 1.05f * self->m_498;
            enemy_turn_and_move_on_ground((u8 *)self, 0x500, self->m_498);
            self->face_target();
            self->check_collisions();
            self->update_enemy_collision_flags();
        }
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU__sub_800CEBD8(TObjEneBm5GibonU *self, s32 arg1) {
    f32 temp_f0;
    s32 temp_r4;
    switch (arg1) {
    case 4:
        self->requested_action = 0xA;
        self->set_field_378(0xE);
        self->clear_intangible();
        temp_r4 = self->m_4ac & 0xFFFFFFFD;
        self->m_4ac = temp_r4;
        self->m_518 = 0;
        self->m_51c = 0;
        self->m_528 = TObjEneBm5GibonU__sub_800D0968(self, temp_r4);
        self->m_52c = 0;
        {
            f32 lim = 40.0f;
            if (self->destination_distance > lim) {
                self->destination_distance = lim;
            }
        }
        temp_f0 = self->destination_distance / 14.666667f;
        self->m_494 = temp_f0;
        self->m_498 = temp_f0;
        self->m_564 = 0;
        return;
    case 3:
        if ((s32) self->m_518 == 1) {
            self->transition_enemy_state(0xE);
        }
        break;
    case 5:
        break;
    case 0:
        switch (self->m_518) {
        case 0:
            (self->advance_animation());
            if (self->get_flag_b4() != 0) {
                self->m_518 = 1;
            }
            TObjEneBm5GibonU__sub_800CCD8C(self);
            if (self->is_passing_frame(8.0f) != 0) {
                play_sound_effect(self->remap_sound_for_area(0x3A828), &self->position, 0, 0);
            }
            if (self->is_passing_frame(22.0f) != 0) {
                play_sound_effect(self->remap_sound_for_area(0x3A529), &self->position, 0, 0);
            }
            if (self->is_passing_frame(22.0f) != 0) {
                self->m_564 = 0;
                if (enemy_validate_retained_target((u8 *)self) != 0) {
                    if (self->current_target->select_melee_contact_body(self, 1.0f) != 0) {
                        self->current_target->receive_physical_attack(self, 1.0f);
                        self->current_target->apply_knockback_from_attacker((u8 *)self, 7.0f);
                        self->m_564 = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (self->random_ratio() <= 0.1f)) {
                            if ((s32) self->m_464 != 0) {
                                TObjEneDD__sub_800BA378((saddr)self, (u8 *)self->current_target);
                            } else {
                                TObjEneDD::send_damage_message((saddr)self, (u8 *)self->current_target);
                            }
                        }
                    }
                }
            }
            self->approach_target(0.1f);
            self->rotation_y = approach_angle_limited((s32)(self->rotation_y), (s32)(self->m_528), 0x1000);
            self->rotation_y = (s32) (s16) self->rotation_y;
            ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->rotation_y);
            if (self->frame <= 28.0f) {
                self->move_with_wall_slide_on_ground(self->destination_direction.x, self->destination_direction.z, self->m_498);
            } else if ((s32) self->m_564 == 0) {
                self->m_498 *= 0.8f;
                self->move_with_wall_slide_on_ground(self->destination_direction.x, self->destination_direction.z, self->m_498);
            }
            break;
        }
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    }
}
extern "C" {
f32 calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(TObjEneBm5GibonU *self, Vec *target, Vec *dir);
#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::run_idle_state(s32 arg1) {
  s32 ang;
  Vec *a = &((TObjEneBm5GibonU *)this)->m_540;
  Vec *b = &m_54c;
  f32 fx;
  f32 fz;
  switch (arg1)
  {
    case 4:
      requested_action = 1;
      set_field_378(0xB);
      clear_intangible();
      m_494 = 0.7f;
      m_518 = 0;
      m_51c = 0;
      m_520 = 0 & 0xFFFF;
      m_524 = 0;
      m_528 = 0;
      m_530 = 0.0f;
      m_534 = 0.0f;
      a->x = 0.0f;
      a->y = 0.0f;
      a->z = 0.0f;
      b->x = 0.0f;
      b->y = 0.0f;
      b->z = 0.0f;
      set_active();
      break;

    case 3:
      if (current_target == 0)
    {
      transition_enemy_state(8);
      break;
    }
      if (m_518 > 0x1C2)
    {
      m_518 = 0;
      if (random_ratio() < 0.5f)
      {
        if (random_ratio() < m_4a0)
        {
          transition_enemy_state(0x13);
        }
        else
        {
          transition_enemy_state(0xC);
        }
      }
    }
    else
      if (m_518 > 0x2D)
    {
      f32 dz = position.z - current_target->position.z;
      f32 dx = position.x - current_target->position.x;
      f32 d = (dx * dx) + (dz * dz);
      if (d >= 10000.0f)
      {
        select_attack_by_range();
      }
      else
        if (d < 900.0f)
      {
        if (random_ratio() < m_4a0)
        {
          transition_enemy_state(0x13);
        }
        else
        {
          transition_enemy_state(0xC);
        }
      }
      else
      {
        fx = sin_table_lookup(current_target->rotation_y);
        fz = cos_table_lookup(current_target->rotation_y);
        fz = (fx * b->x) + (fz * b->z);
        if (fz < cos_table_lookup(0x6AAA))
        {
          if (random_ratio() < m_4a0)
          {
            transition_enemy_state(0x13);
          }
          else
          {
            transition_enemy_state(0xC);
          }
        }
      }
    }
      break;

    case 0:
      advance_animation();
      if (((TObjEneEpsilon *)this)->update_death_check() != 0)
    {
      if (m_520 == 0)
      {
        Vec fwd;
        Vec to;
        m_520 = 1;
        VecCopy(a, &current_target->position);
        m_530 = calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(this, a, b);
        m_534 = rand_range(50.0f, 80.0f);
        fwd.x = sin_table_lookup(rotation_y);
        fwd.y = 0.0f;
        fwd.z = cos_table_lookup(rotation_y);
        to.x = current_target->position.x - position.x;
        to.y = 0.0f;
        to.z = current_target->position.z - position.z;
        if (is_vec_xz_cross_negative(&fwd, &to) != 0)
        {
          m_528 = -1;
        }
        else
        {
          m_528 = 1;
        }
      }
      m_518++;
      TObjEneBm5GibonU__sub_800CCE28(this);
      if (m_524 > 0)
      {
        m_524--;
        if (m_528 > 0)
        {
          m_530 -= 0.5f;
        }
        else
        {
          m_530 += 0.5f;
        }
      }
      else
      {
        f32 cur = m_530;
        f32 tgt = m_534;
        f32 diff = cur - tgt;
        if (diff > 0.2f)
        {
          m_530 = cur - 0.2f;
        }
        else
          if (diff < -0.2f)
        {
          m_530 += 0.2f;
        }
        else
        {
          m_530 = tgt;
        }
      }
      switch (m_520)
      {
        case 1:
        {
          m_494 = 0.7f;
          approach_target(0.12f);
          calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(this, &((TObjEneBm5GibonU *)this)->m_540, b);
          if (m_528 >= 0)
          {
            fx = b->z;
            fz = -b->x;
          }
          else
          {
            fz = b->x;
            fx = -b->z;
          }
          if (has_move_failures(1) != 0)
          {
            set_active();
          }
          else
          {
            clear_field_388();
          }
          move_with_wall_slide_on_ground(fx, fz, m_498);
          if (has_move_failures(10) != 0)
          {
            m_51c = 0;
            m_520 = 2;
          }
          break;
        }

        case 2:
        {
          m_494 = 0.5f;
          approach_target(0.12f);
          m_51c++;
          if (m_51c >= 0x28)
          {
            ang = rotation_y;
          }
          else
          {
            ang = rotation_y + (m_528 << 11);
          }
          fz = sin_table_lookup(ang);
          fx = cos_table_lookup(ang);
          if (has_move_failures(2) != 0)
          {
            m_51c = 0;
            set_active();
          }
          else
          {
            clear_field_388();
          }
          move_with_wall_slide_on_ground(fz, fx, m_498);
          if (m_51c >= 0x50)
          {
            m_520 = 0;
          }
          break;
        }

      }

      rotation_y = approach_angle_limited(rotation_y, (s32) (10430.38043493439 * atan2_float(position.x - prev_position.x, position.z - prev_position.z)), 0x200);
      rotation_y = (s16) rotation_y;
      play_speed = 1.05f * m_498;
      face_target();
      check_collisions();
      update_enemy_collision_flags();
      if (bodies->flags & 0x380000)
      {
        m_524 = 0x14;
      }
    }
      break;

    case 5:
      clear_field_388();
      break;

  }

}
#pragma pop
}
void TObjEneBm5GibonU__sub_800CF4BC(TObjEneBm5GibonU *self, s32 arg1) {
    s32 *rot = &self->m_528;
    Vec *vel = &self->m_540;
    Vec *dir = &self->m_54c;
    f32 t;
    switch (arg1) {
    case 4:
        self->requested_action = 3;
        self->set_field_378(0xA);
        self->clear_intangible();
        self->m_494 = 2.0f;
        self->m_518 = 0;
        self->m_51c = 0;
        calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(self, 0x1C71, dir, rot);
        VecCopy(vel, dir);
        self->m_52c = *rot;
        return;
    case 3:
        if (self->current_target == NULL) {
            self->transition_enemy_state(8);
            return;
        }
        if (self->m_518 == 1) {
            self->transition_enemy_state(0x14);
            return;
        }
        if (self->is_passing_frame(self->frame_count - 1.0001f) != 0 &&
            self->destination_distance < 90.0f) {
            self->transition_enemy_state(0xB);
        }
    case 5:
    case 1:
        return;
    case 0:
        self->advance_animation();
        if (((TObjEneEpsilon *)self)->update_death_check() == 0) {
            return;
        }
        if (self->is_passing_frame(13.0f) != 0) {
            self->spawn_landing_effect(&self->position);
        }
        TObjEneBm5GibonU__sub_800CCDE4(self);
        if (self->is_passing_frame(10.0f) != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
            if (self->m_51c == 0) {
                self->m_51c = 1;
                calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(self, -0x1C71, dir, rot);
            } else {
                self->m_51c = 0;
                calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(self, 0x1C71, dir, rot);
            }
        }
        if (self->is_passing_frame(self->frame_count - 1.0001f) != 0) {
            VecCopy(vel, dir);
            self->m_52c = *rot;
        }
        self->rotation_y = approach_angle_limited(self->rotation_y, self->m_52c, 0x800);
        self->rotation_y = (s16)self->rotation_y;
        if (self->is_passing_frame(18.0f) != 0) {
            self->m_498 = 6.0f;
        }
        t = self->frame;
        if (t >= 10.0f && t <= 18.0f) {
            self->move_with_wall_slide_on_ground(vel->x, vel->z, 1.0f);
        } else {
            self->m_498 *= 0.9f;
            self->move_with_wall_slide_on_ground(vel->x, vel->z, self->m_498);
        }
        self->m_49c += self->m_498;
        if (self->m_49c >= 50.0f) {
            self->m_49c -= 50.0f;
            if (self->random_ratio() < self->m_4a4) {
                self->m_518 = 1;
            }
        }
        self->face_target();
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CF7CC(TObjEneBm5GibonU *self, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    switch (arg1) {
    case 4:
        self->requested_action = 2;
        self->set_field_378(9);
        self->clear_intangible();
        self->m_494 = 1.6f;
        self->m_518 = 0;
        return;
    case 3:
        if (self->current_target == NULL) {
            self->transition_enemy_state(8);
        } else if (self->has_move_failures(0xA) != 0) {
            self->transition_enemy_state(0xA);
        } else if ((s32) self->m_518 == 1) {
            self->transition_enemy_state(0x14);
        } else if ((self->is_passing_frame((f32) (self->frame_count - 1.0001f)) != 0) && (self->destination_distance < 90.0f)) {
            self->transition_enemy_state(0xB);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        self->advance_animation();
        if (self->is_passing_frame(13.0f) != 0) {
            self->spawn_landing_effect(&self->position);
        }
        if ((s16) self->requested_action == 2) {
            TObjEneBm5GibonU__sub_800CCDE4(self);
        }
        if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
            if (self->is_passing_frame(18.0f) != 0) {
                self->m_498 = 4.0f;
            }
            temp_f1 = self->frame;
            if ((temp_f1 >= 10.0f) && (temp_f1 <= 18.0f)) {
                enemy_turn_and_move_on_ground((u8 *)self, (768.0f * self->m_498), 1.0f);
            } else {
                self->m_498 *= 0.9f;
                temp_f1_2 = self->m_498;
                enemy_turn_and_move_on_ground((u8 *)self, (768.0f * temp_f1_2), temp_f1_2);
            }
            self->m_49c += self->m_498;
            if (self->m_49c >= 50.0f) {
                self->m_49c -= 50.0f;
                if (self->random_ratio() < self->m_4a4) {
                    self->m_518 = 1;
                }
            }
            self->face_target();
            self->check_collisions();
            self->update_enemy_collision_flags();
        }
        break;
    }
}
}
s32 actor_rand_int(saddr actor, s32 range);
extern "C" {

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CFA48(TObjEneBm5GibonU *self, s32 arg1) {
    s32 angle;
    f32 radius;
    TObjChara *target;
    f32 dx;
    f32 dz;

    switch (arg1) {
    case 4:
        self->requested_action = 1;
        self->set_field_378(8);
        self->clear_intangible();
        self->m_51c = 0;
        self->m_518 = 0;
        self->m_520 = actor_rand_int((saddr)self, 0x14);
        self->m_564 = 0;
        angle = (s32)(65536.0f * self->random_ratio());
        radius = 120.0f * self->random_ratio();
        self->destination.x = radius * sin_table_lookup(angle) + self->m_488.x;
        self->destination.z = radius * cos_table_lookup(angle) + self->m_488.z;
        self->m_494 = 0.7f * self->random_ratio() + 0.3f;
        self->m_498 = 0.0f;
        self->m_530 = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
        self->update_velocity();
        break;
    case 3:
        if (self->m_564 != 0) {
            self->select_attack_by_range();
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        if (self->play_sound_variant() != 0) {
            f32 dist;
            target = self->current_target;
            dx = target->position.x - self->position.x;
            dz = target->position.z - self->position.z;
            dist = dx * dx;
            dist += dz * dz;
            if (dist < 22500.0f) {
                self->m_564 = 1;
            }
            self->face_target();
        } else {
            ((TObjEneBm5GibonU *)self)->turn_toward_angle(self->rotation_y);
        }
        switch (self->m_518) {
        case 0:
            TObjEneBm5GibonU__sub_800CCE28(self);
            self->update_velocity();
            self->approach_target(0.05f);
            self->m_51c += 1;
            if (self->destination_distance < self->m_530 || self->m_51c > 100) {
                self->m_518 = 1;
                self->m_494 = 0.0f;
            } else if (self->has_move_failures(0x14) != 0) {
                self->m_51c = 0;
                ((TObjEneBm5GibonU *)self)->pick_wander_destination();
                self->m_494 = self->rand_range(0.3f, 1.0f);
                self->m_530 = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
            }
            self->play_speed = 1.05f * self->m_498;
            enemy_turn_and_move_on_ground((u8 *)self, 512.0f * self->m_498, self->m_498);
            break;
        case 1:
            TObjEneBm5GibonU__sub_800CCE28(self);
            self->update_velocity();
            self->approach_target(0.020000001f);
            if (self->m_498 <= 0.1f) {
                self->m_518 = 2;
                self->m_51c = self->rand_range(240.0f, 360.0f);
                self->requested_action = 0;
            }
            self->play_speed = 1.05f * self->m_498;
            enemy_turn_and_move_on_ground((u8 *)self, 512.0f * self->m_498, self->m_498);
            break;
        case 2:
            self->requested_action = 0;
            self->m_51c -= 1;
            if (self->m_51c <= 0) {
                ((TObjEneBm5GibonU *)self)->pick_wander_destination();
                self->m_494 = self->rand_range(0.3f, 1.0f);
                self->m_498 = 0.0f;
                self->m_530 = 2.0f + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
                self->m_518 = 0;
                self->requested_action = 1;
            }
            self->update_ground_contact();
            break;
        }
        self->check_collisions();
        self->update_enemy_collision_flags();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU__sub_800CFE30(TObjEneBm5GibonU *self, s32 _w1) {  }

void TObjEneBm5GibonU__sub_800CFE34(TObjEneBm5GibonU *self, s32 arg1) {
    TObjEneBm5GibonUNode *n;
    TObjEneBm5GibonU *o;
    switch (arg1) {
    case 4:
        self->requested_action = 0xE;
        self->set_field_378(8);
        self->set_intangible();
        self->m_518 = 0;
        break;
    case 3:
        if (self->get_flag_b4() != 0) {
            self->transition_enemy_state(8);
        }
        break;
    case 5:
        break;
    case 0:
        (self->m_518)++;
        self->advance_animation();
        if (self->is_passing_frame(20.0f) != 0) {
            play_sound_effect(self->remap_sound_for_area(0x3A523), &self->position, 0, 0);
        }
        if (self->m_518 == 0x3C) {
            for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__enemy_list)->head; n != NULL; n = n->next) {
                o = (TObjEneBm5GibonU *)((TObjEneBm5GibonU *)n)->update_photon_mylla();
                if (self->m_46c == TObjEneBm5GibonU__sub_800D1D70(o)) {
                    o->set_flag();
                }
            }
        }
        if (enemy_validate_retained_target((u8 *)self) != 0) {
            if (self->requested_action == 0xE) {
                self->face_target();
            } else {
                self->m_478 = 0;
            }
        } else {
            self->play_sound_variant();
        }
        self->update_ground_contact();
        self->update_body_colliders();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CFFBC(TObjEneBm5GibonU *self, s32 arg1) {
  switch (arg1)
  {
    case 4:
      self->requested_action = 5;
      self->set_field_378(8);
      (self->set_intangible());
      self->m_518 = 0;
      return;
    case 3:
      if ((self->m_518) > 0x3C)
    {
      self->transition_enemy_state(8);
    }
    case 5:
      return;
      return;
    case 0:
      self->m_518 = (s32) ((self->m_518) + 1);
      self->advance_animation();
      if (self->is_passing_frame(20.0f) != 0)
    {
      play_sound_effect(self->remap_sound_for_area(0x3A523), &self->position, 0, 0);
    }
      if (enemy_validate_retained_target((u8 *)self) != 0)
    {
      self->enemy_copy_target_destination();
      self->update_velocity();
      self->face_target();
    }
    else
    {
      self->play_sound_variant();
    }
      (self->update_ground_contact());
      (self->update_body_colliders());
      break;
  }
}

void TObjEneBm5GibonU__sub_800D00F0(TObjEneBm5GibonU *self, s32 arg1) {
  switch (arg1)
  {
    case 4:
      *((s16 *) (((s8 *) self) - -0xB8)) = 4;
      self->set_field_378(5);
      (self->set_intangible());
      self->m_518 = (s32) (((s32) (60.0f * self->random_ratio())) + 0xA);
      return;
      return;
      self->m_518 = (s32) (((s32) (60.0f * self->random_ratio())) + 0xA);
    case 3:
      if ((self->m_518) <= 0)
    {
      self->set_anim_by_state();
    }
    case 5:
      return;
    case 0:
      self->m_518 = (s32) ((self->m_518) - 1);
      self->play_sound_variant();
      self->advance_animation();
      (self->update_ground_contact());
      (self->update_body_colliders());
      break;
  }
}

void TObjEneBm5GibonU__sub_800D01DC(TObjEneBm5GibonU *self, s32 arg1) {
  u8 *entity;
  switch (arg1)
  {
    case 4:
      self->requested_action = 4;
      self->set_field_378(3);
      (self->clear_intangible());
      ((TObjEneDD_ST *)(self))->enemy_clear_target();
      self->m_478 = 0;
      self->m_4ac = (s32) ((self->m_4ac) & 0xFFFFFFFE);
      return;
    case 3:
      if ((self->m_4ac) & 1)
    {
      self->transition_enemy_state(5);
      return;
    }
      if ((self->current_target) != 0U)
    {
      self->enemy_copy_target_destination();
      self->set_anim_by_state();
      entity = (u8 *) find_entity_by_id(self->m_474);
      if (entity != 0)
      {
        ((TObjEneBm5GibonU *)entity)->set_flag();
      }
    }
      return;
    case 0:
      self->play_sound_variant();
      self->advance_animation();
      (self->update_ground_contact());
      (self->update_body_colliders());
      return;
      return;
    case 5:
      self->m_4ac = (s32) ((self->m_4ac) & 0xFFFFFFFE);
      break;
  }
}

void TObjEneBm5GibonU__sub_800D02F8(TObjEneBm5GibonU *self, s32 arg1) {
    Vec *home = &self->m_540;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(8);
        self->set_intangible();
        self->m_4ac &= ~3;
        ((TObjEneDD_ST *)(self))->enemy_clear_target();
        self->m_478 = 0;
        VecCopy(home, &self->position);
        self->m_3d8.start_fade_in();
        play_area_sound_effect(&self->position);
        break;
    case 3:
        if (self->m_3d8.advance_toward_max() != 0) {
            if (((TObjEneBm5GibonU *)self)->update_target() != 0) {
                self->transition_enemy_state(8);
            } else {
                self->transition_enemy_state(3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        self->update_ground_contact();
        self->update_body_colliders();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800D0420(TObjEneBm5GibonU *self, s32 arg1) {
    Vec *home = &self->m_540;
    switch (arg1) {
    case 4:
        self->requested_action = 0xF;
        self->set_field_378(8);
        self->set_intangible();
        self->m_4ac = (s32) (self->m_4ac & 0xFFFFFFFC);
        ((TObjEneDD_ST *)(self))->enemy_clear_target();
        self->m_478 = 0;
        VecCopy(home, &self->position);
        self->position.x -= 100.0f * sin_table_lookup(self->rotation_y);
        self->position.z -= 100.0f * cos_table_lookup(self->rotation_y);
        self->m_530 = 3.5714285f;
        break;
    case 3:
        if (self->get_flag_b4() != 0) {
            if (((TObjEneBm5GibonU *)self)->update_target() != 0) {
                self->transition_enemy_state(8);
            } else {
                self->transition_enemy_state(3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        if (!(self->motion_flags & 4)) {
            TObjEneBm5GibonU__sub_800CCD8C(self);
            if (self->is_passing_frame(8.0f) != 0) {
                play_sound_effect(self->remap_sound_for_area(0x3A828), &self->position, 0, 0);
            }
            if (self->is_passing_frame(22.0f) != 0) {
                play_sound_effect(self->remap_sound_for_area(0x3A529), &self->position, 0, 0);
            }
            if (self->frame > 28.0f) {
                self->m_530 *= 0.8f;
            }
            self->position.x += self->m_530 * sin_table_lookup(self->rotation_y);
            self->position.z += self->m_530 * cos_table_lookup(self->rotation_y);
        }
        self->update_ground_contact();
        self->update_body_colliders();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU::handle_state(s32 arg1) {
  TObjEneBm5GibonU *other;
  switch (arg1)
  {
    case 4:
      m_51c = 0;
      set_field_378(0);
      set_intangible();
      m_4ac |= 2;
      return;
    case 3:
      if (m_51c > 0)
    {
      if (m_470 < 1)
      {
        transition_enemy_state(1);
        return;
      }
      transition_enemy_state(2);
    }
    case 5:
      return;
    case 0:
      other = TObjEneBm5GibonU::find_enemy_by_id(m_46c);
      if (other)
    {
      m_474 = get_entity_id((saddr) other);
    }
      if (m_464 != 0 || other == NULL)
    {
      VecCopy(&m_488, &m_47c);
    }
    else
    {
      VecCopy(&m_488, TObjEneBm5GibonU__sub_800D1D78(other));
    }
      m_51c++;
      break;
  }
}

void TObjEneBm5GibonU__sub_800D0738(TObjEneBm5GibonU *self, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        self->handle_state(msg);
        break;
    case 1:
        TObjEneBm5GibonU__sub_800D0420(self, msg);
        break;
    case 2:
        TObjEneBm5GibonU__sub_800D02F8(self, msg);
        break;
    case 3:
        TObjEneBm5GibonU__sub_800D01DC(self, msg);
        break;
    case 4:
        TObjEneBm5GibonU__sub_800CFE30(self, msg);
        break;
    case 5:
        TObjEneBm5GibonU__sub_800D00F0(self, msg);
        break;
    case 6:
        TObjEneBm5GibonU__sub_800CFFBC(self, msg);
        break;
    case 7:
        TObjEneBm5GibonU__sub_800CFE34(self, msg);
        break;
    case 8:
        TObjEneBm5GibonU__sub_800CFA48(self, msg);
        break;
    case 9:
        TObjEneBm5GibonU__sub_800CF7CC(self, msg);
        break;
    case 10:
        TObjEneBm5GibonU__sub_800CF4BC(self, msg);
        break;
    case 11:
        self->run_idle_state(msg);
        break;
    case 12:
        TObjEneBm5GibonU__sub_800CEBD8(self, msg);
        break;
    case 13:
        TObjEneBm5GibonU__sub_800CE978(self, msg);
        break;
    case 14:
        TObjEneBm5GibonU__sub_800CE694(self, msg);
        break;
    case 15:
        action__16TObjEneBm5GibonUFPvi(self, msg);
        break;
    case 16:
        TObjEneBm5GibonU__sub_800CE370(self, msg);
        break;
    case 17:
        TObjEneBm5GibonU__sub_800CE060(self, msg);
        break;
    case 18:
        self->handle_message(msg);
        break;
    case 19:
        TObjEneBm5GibonU__sub_800CDB98(self, msg);
        break;
    case 20:
        self->state_cast_technique(msg);
        break;
    }
}

void TObjEneBm5GibonU::damage_linked_entity() {
    u8 *r = (u8 *)find_entity_by_id(m_474);
    if (r != 0) {
        DirectAttackPayload d;
        d.kind = 9;
        d.power = 1.5f;
        receive_direct_attack(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU::damage_linked_entity_type10() {
    u8 *r = (u8 *)find_entity_by_id(m_474);
    if (r != 0) {
        DirectAttackPayload d;
        d.kind = 10;
        d.power = 1.5f;
        receive_direct_attack(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU__sub_800D095C(TObjEneBm5GibonU *self, s32 arg1, s16 arg2) {
    self->m_510 = arg1;
    self->m_514 = arg2;
}
#pragma push
#pragma fp_contract on
s32 TObjEneBm5GibonU__sub_800D0968(TObjEneBm5GibonU *self, int _w1) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    if (is_target_unobstructed_from((TObjEneDD *)self, (TObjChara *)self->current_target) != 0) {
        self->enemy_copy_target_destination();
        self->update_velocity();
        if (((TObjEneBm5GibonU *)self)->is_active() != 0) {
            var_f0 = 7.0f;
        } else {
            var_f0 = -7.0f;
        }
        temp_f5 = self->destination_direction.z;
        temp_f4 = self->destination_direction.x;
        self->destination.x = (f32) (self->destination.x + ((2.0f * temp_f4) + (temp_f5 * var_f0)));
        self->destination.z = (f32) (self->destination.z + ((2.0f * temp_f5) - (temp_f4 * var_f0)));
        self->update_velocity();
        return (s32) (10430.38043493439 * atan2_float((f64) self->destination_direction.x, (f64) self->destination_direction.z));
    }
    self->destination_direction.x = sin_table_lookup(self->rotation_y);
    self->destination_direction.y = (f32) 0.0f;
    self->destination_direction.z = cos_table_lookup(self->rotation_y);
    VecCopy(&self->destination, &self->position);
    self->destination.x = (f32) ((30.0f * self->destination_direction.x) + self->destination.x);
    self->destination.z = (f32) ((30.0f * self->destination_direction.z) + self->destination.z);
    self->destination_distance = 30.0f;
    return self->rotation_y;
}
#pragma pop

#pragma pop
#pragma push
int TObjEneBm5GibonU::is_active() { return this->entity_id & 0x1; }

f32 TObjEneBm5GibonU::calc_anim_speed(f32 speed) {
    return 28.0f / ((this->motion_list[this->action_table[7].motion].motion->frameCount - 1) / speed);
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800D0AE8(TObjEneBm5GibonU *self, Vec *dir) {
    Vec v;
    VecCopy(&v, &self->position);
    v.x = 5.0f * dir->x + v.x;
    v.z = 5.0f * dir->z + v.z;
    self->spawn_landing_effect(&v);
}
#pragma pop

s32 TObjEneBm5GibonU::play_sound_variant() {
    if ((s32) m_464 != 0) {
        return this->update_linked_position(350.0f);
    }
    return this->update_linked_position(250.0f);
}

s32 TObjEneBm5GibonU::update_target() {
    if (this->m_464 != 0) {
        return this->select_and_apply_target(350.0f);
    }
    return this->select_and_apply_target(250.0f);
}

void TObjEneBm5GibonU::set_flag() { m_4ac |= 0x1; }

#pragma push
#pragma fp_contract on
f32 calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(TObjEneBm5GibonU *self, Vec *target, Vec *dir) {
    f32 dx;
    f32 dz;
    dx = self->position.x - target->x;
    dz = self->position.z - target->z;
    f32 d = dx * dx + dz * dz;
    f32 inv = 1.0f / newton_sqrtf(d);
    dir->x = dx * inv;
    dir->y = 0.0f;
    dir->z = dz * inv;
    return d * inv;
}
#pragma pop

void TObjEneBm5GibonU::set_anim_by_state() {
    if ((s32) m_464 != 0) {
        transition_enemy_state(7);
        return;
    }
    transition_enemy_state(6);
}

#pragma pop
#pragma push

void TObjEneBm5GibonU::select_attack_by_range() {
    m_49c = 0.0f;
    if (random_ratio() < 0.5f) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(0xA);
}

#pragma pop
#pragma push

#pragma fp_contract on

void calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(TObjEneBm5GibonU *self, s32 angle, Vec *out, s32 *rotation) {
    f32 c;
    f32 s;

    s = sin_table_lookup(angle);
    c = cos_table_lookup(angle);
    out->z = c * self->destination_direction.z - s * self->destination_direction.x;
    out->x = s * self->destination_direction.z + c * self->destination_direction.x;
    *rotation = (s32)(10430.38043493439 * atan2_float(out->x, out->z));
}

}

#pragma pop
#pragma push

typedef struct Hit_800D0E14 {
    u32 flags;
    Vec *pos;
} Hit_800D0E14;

extern "C" {
Hit_800D0E14 *csnVector(void *, void *, s32);
s32 angle_diff_s16(s32, s32);
void TObjEneBm5GibonU::approach_target(f32 step) {
    f32 target;
    f32 speed;

    speed = m_498;
    target = m_494;
    if (speed != target) {
        if (speed > target) {
            m_498 = speed - step;
            if (m_498 < m_494) {
                m_498 = m_494;
            }
        } else {
            m_498 = speed + step;
            if (m_498 > m_494) {
                m_498 = m_494;
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::pick_wander_destination() {
    Vec v;
    f32 d;
    Hit_800D0E14 *hit;
    v.x = this->position.x - this->m_488.x;
    v.y = 0.0f;
    v.z = this->position.z - this->m_488.z;
    normalize_vector_xz(&v);
    rotate_xz_pair_by_angle(&v.x, &v.z, (s32)(32768.0f * this->random_ratio()) + 0x4000);
    d = 120.0f * this->rand_range(0.3f, 1.0f);
    this->destination.x = v.x * d + this->m_488.x;
    this->destination.z = v.z * d + this->m_488.z;
    hit = csnVector(&this->body_center, &this->destination, 0x88E0);
    if (hit != NULL) {
        v.x = hit->pos->x - this->position.x;
        v.z = hit->pos->z - this->position.z;
        d = normalize_vector_xz(&v) - 25.0f;
        this->destination.x = v.x * d + this->position.x;
        this->destination.z = v.z * d + this->position.z;
    }
}
#pragma pop

void TObjEneBm5GibonU::face_target() {
    Vec off;
    Vec q;
    off.x = sin_table_lookup(rotation_y) * 0.0f;
    q.x = position.x + off.x;
    off.z = cos_table_lookup(rotation_y) * 0.0f;
    q.z = position.z + off.z;
    q.x = current_target->position.x - q.x;
    q.z = current_target->position.z - q.z;
    turn_toward_angle((s32)(10430.38043493439 * atan2_float(q.x, q.z)));
}

void TObjEneBm5GibonU::turn_toward_angle(s32 angle) {
    s32 d;
    d = angle_diff_s16(this->rotation_y, angle);
    if (d > 0x3000) {
        d = 0x3000;
    } else if (d < -0x3000) {
        d = -0x3000;
    }
    if (this->m_478 * d >= 0) {
        this->m_478 = approach_angle_limited(this->m_478, d, 0x400);
    } else if (this->m_478 * angle_diff_s16(this->m_478, d) >= 0) {
        if (this->m_478 >= 0) {
            this->m_478 -= 0x400;
        } else {
            this->m_478 += 0x400;
        }
    } else {
        this->m_478 = approach_angle_limited(this->m_478, d, 0x400);
    }
    this->m_478 = (s16)this->m_478;
}

void TObjEneBm5GibonU::sub_800D10A0() {
    m_46c = (s32)floor_to_float(parameters[0]);
    if (parameters[1] >= 1.0f) {
        m_470 = 0;
    } else {
        m_470 = 1;
    }
    if (variant >= 1) {
        m_464 = 1;
        m_468 = 1;
        model = (void *)TObjEneBm5GibonU__model_archive->models[1].model;
        texlist = (saddr)TObjEneBm5GibonU__model_archive->models[1].m_c;
    } else {
        m_464 = 0;
        m_468 = 0;
        model = (void *)TObjEneBm5GibonU__model_archive->models[0].model;
        texlist = (saddr)TObjEneBm5GibonU__model_archive->models[0].m_c;
    }
    m_4a0 = 0.4f + parameters[2];
    m_4a4 = 0.3f + parameters[3];
    m_4a8 = 0.3f + parameters[4];
}

}

#pragma pop
#pragma push

#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"

// The Gibbon's static data from TObjEneBm5GibonU__data_80500E78 on: the parameter tables, then
// the two lists, each after the destructor-chain record __register_global_object fills in.
struct TObjEneBm5GibonUStaticData {
    u8 tables[0x2c];
    u8 node_list_chain[0xc];
    TObjEneBm5GibonUList node_list;
    u8 enemy_list_chain[0xc];
    TObjEneBm5GibonUList enemy_list;
};

extern "C" {
void TObjEneBm5GibonU__sub_800D1CF8(TObjEneBm5GibonUNode *self);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, u32, u32);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
void __ct__12TObjEneDD_STFP7TObject(void *, s32, s32);
void init_collision_body_parts(TObjCollidable *, const CollisionBody *, s32);
void *__ct__14TObjCollidableFP7TObject(void *, s32);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv();
void run_miss_reaction__16TObjEneBm5GibonUFv(void);
void refresh_target__16TObjEneBm5GibonUFv(void);
void __dl__FPv(void);

void TObjEneBm5GibonU::update_body_colliders() {
    *(f32 *)((s8 *)this->bodies + 4) = 10.0f;
}

void TObjEneBm5GibonU::update_center_position() {
    body_center.x = position.x;
    body_center.y = 10.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}

void TObjEneBm5GibonU::run_miss_reaction() {  }
void TObjEneBm5GibonU::run_hit_reaction() { if (this->mode != 16) { transition_enemy_state(16); } }
void TObjEneBm5GibonU::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0x11) && (temp_r0 != 0x12)) {
        transition_enemy_state(0x11);
    }
}
void TObjEneBm5GibonU::refresh_target() {  }

void TObjEneBm5GibonU::run_task() {
    s16 temp_r0;
    s16 temp_r3_2;
    s32 temp_r3;
    TObject *partner;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    partner = (TObject *)find_entity_by_id(m_474);
    if (partner != NULL) {
        partner->all_parents_unqueued_for_destruction();
    }
    if (this->update_status_effects() != 4) {
        temp_r3 = this->m_510;
        if (temp_r3 != 0) {
            this->m_510 = (temp_r3 - 1);
            if ((s32) this->m_510 == 0) {
                temp_r0 = this->mode;
                if ((temp_r0 != 0x11) && (temp_r0 != 0x12)) {
                    transition_enemy_state(0xF);
                }
            }
        }
        this->update_action_state();
    } else {
        temp_r3_2 = this->mode;
        if (temp_r3_2 == 0) {
            this->update_action_state();
        } else if (temp_r3_2 == 1) {
            VecCopy(&position, &home_position);
            transition_enemy_state(8);
            this->update_action_state();
        }
    }
    update_center_position();
    submit_default_cursor_candidate();
    this->render_minimap_dot();
}

TObjEneBm5GibonU *TObjEneBm5GibonU__sub_800D13B8(TObjEneBm5GibonU *self, s16 arg1) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = lbl_80493F04;
        if (self->m_50c != NULL) {
            free_collision_body_parts(self->m_50c);
            delete self->m_50c;
            self->m_50c = NULL;
        }
        self->forward_hit_to_node_list();
        if (self->m_464 != 0) {
            self->forward_hit_to_enemy_list();
        }
        free_collision_body_parts(self);
        __destroy_arr(self->m_3f4, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80494938Fv(&self->m_3d8, -1);
        TObjEneBm5GibonU::destroy((saddr)&self->m_3cc, -1);
        TObjEneBm5GibonU::destroy((saddr)&self->m_3c0, -1);
        __dt__12TObjEneDD_STFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

TObjEneBm5GibonU *TObjEneBm5GibonU__ct(TObjEneBm5GibonU *self, s32 arg1, saddr set_data) {
    void *p;
    s32 i;
    s32 b;
    __ct__12TObjEneDD_STFP7TObject(self, arg1, set_data);
    *(void **)((u8 *)self + 0x18) = lbl_80493F04;
    TObjEneBm5GibonU__sub_800D1CF8(&self->m_3c0);
    TObjEneBm5GibonU__sub_800D1CF8(&self->m_3cc);
    __ct__13TUnk_80494938Fv(&self->m_3d8);
    __construct_array(self->m_3f4, (void *)&__ct__15RenderFadeStateFv, (void *)&__dt__15RenderFadeStateFv, 0x1C, 4);
    __ct__16TargetCursorListFv(&self->m_4b0);
    self->m_name = TObjEneBm5GibonU__class_name;
    ((TObjEneDD *)self)->invoke_initialization_hook((void *)set_data);
    self->sub_800D10A0();
    self->init_position_vectors();
    if (self->m_464 == 1) {
        ((TObjEneDD *)self)->init_model(&gibon_collision_body_templates[1], 1);
    } else {
        ((TObjEneDD *)self)->init_model(&gibon_collision_body_templates[0], 1);
    }
    self->set_field_d8((saddr)gibon_u_action_table);
    self->set_field_dc((saddr)TObjEneBm5GibonU__model_archive->motions);
    self->requested_action = 0;
    self->set_animation(self->requested_action);
    self->set_field_b8(self->requested_action);
    b = self->m_464 ? 1 : 0;
    ((TObjEneDD *)self)->reset_hp(TObjEneBm5GibonU__data_80500E78[b], lbl_80500E80[b], lbl_80500E88[b]);
    self->set_state_flag_1();
    self->movementParameters = &TObjEneBm5GibonU__movement_parameters;
    if (self->m_464 != 0) {
        ((TObjEneDD *)self)->initialize_enemy_state(0x3C);
    } else {
        ((TObjEneDD *)self)->initialize_enemy_state(0x3B);
    }
    self->wall_reach = 15.0f;
    self->enemy_init_acquire_period(0x14);
    self->enemy_init_validate_period(0x14);
    ((TObjEneBm5GibonU *)&self->m_3c0)->set_field8_from_obj((saddr)self);
    self->init_child_node();
    if (self->m_464 != 0) {
        ((TObjEneBm5GibonU *)&self->m_3cc)->set_field8_from_obj((saddr)self);
        self->init_child_from_list();
    }
    self->m_474 = 0xFFFF;
    self->m_478 = 0;
    VecCopy(&self->m_47c, &self->position);
    VecCopy(&self->m_488, &self->position);
    self->m_494 = 0.0f;
    self->m_498 = 0.0f;
    self->m_4ac = 0;
    p = TObject::operator new(0xAC);
    if (p != NULL) {
        p = __ct__14TObjCollidableFP7TObject(p, 0);
    }
    self->m_50c = (TObjCollidable *)p;
    init_collision_body_parts(self->m_50c, &gibon_collision_body_templates[2], 1);
    self->m_510 = 0;
    self->m_514 = 0xFFFF;
    self->set_colliders_contact_low();
    self->m_518 = 0;
    self->m_51c = 0;
    self->m_520 = 0;
    self->m_524 = 0;
    self->m_528 = 0;
    self->m_52c = 0;
    self->m_530 = 0.0f;
    self->m_534 = 0.0f;
    self->m_538 = 0.0f;
    self->m_53c = 0.0f;
    self->m_540.x = 0.0f;
    self->m_540.y = 0.0f;
    self->m_540.z = 0.0f;
    self->m_54c.x = 0.0f;
    self->m_54c.y = 0.0f;
    self->m_54c.z = 0.0f;
    self->m_558 = 0.0f;
    self->m_55c = 0.0f;
    self->m_560 = 0.0f;
    self->m_564 = 0;
    self->update_center_position();
    self->update_body_colliders();
    self->transform_part_positions();
    self->mode = 0;
    self->dispatch_action(self->mode, 4);
    for (i = 0; i < 4; i++) {
        self->m_3f4[i].activate_and_dispatch();
    }
    return self;
}

TObjEneBm5GibonU *TObjEneBm5GibonU::find_enemy_by_id(s32 id) {
    TObjEneBm5GibonUNode *n;
    for (n = ((TObjEneBm5GibonUList *)TObjEneBm5GibonU__enemy_list)->head; n != 0; n = n->next) {
        TObjEneBm5GibonU *e = (TObjEneBm5GibonU *)((TObjEneBm5GibonU *)n)->update_photon_mylla();
        if (e != 0 && e->m_46c == id) {
            return e;
        }
    }
    return 0;
}

void TObjEneBm5GibonU::forward_hit_to_enemy_list() {
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__enemy_list)->forward_hit(&m_3cc);
}

void TObjEneBm5GibonU::init_child_from_list() {
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__enemy_list)->init_child(&m_3cc);
}

void TObjEneBm5GibonU::forward_hit_to_node_list() {
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__node_list)->forward_hit(&m_3c0);
}

void TObjEneBm5GibonU::init_child_node() {
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__node_list)->init_child(&m_3c0);
}

void TObjEneBm5GibonU::release_static_resource() {
    if (TObjEneBm5GibonU__model_archive != NULL) {
        delete TObjEneBm5GibonU__model_archive;
        TObjEneBm5GibonU__model_archive = NULL;
    }
}

extern void *tl_04;

void *TObjEneBm5GibonU::create(void *arg0) {
    void *o = TObject::operator new(0x568);
    if (o != NULL) {
        o = TObjEneBm5GibonU__ct((TObjEneBm5GibonU *)o, (saddr)tl_04, (saddr)arg0);
    }
    return o;
}

void TObjEneBm5GibonU::load_resources() {
    s32 i;
    BmlResource *m;
    f32 *v;
    if (is_split_screen() != 0) {
        m = load_enemy_bml_resource(&lbl_80493DE4);
    } else {
        m = load_enemy_bml_resource(&lbl_80493DA0);
    }
    TObjEneBm5GibonU__model_archive = m;
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__node_list)->reset_fields();
    ((TObjEneBm5GibonU *)TObjEneBm5GibonU__enemy_list)->reset_fields();
    TObjEneBm5GibonU__render_node_index = 0;
    TObjEneBm5GibonU__render_joint_y_rotation = 0;
    v = lbl_80500E98;
    lbl_80500E98[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    for (i = 0; i < 2; i++) {
        TObjEneBm5GibonU__data_80500E78[i] = (u8 *)TLobby::register_boss(lbl_8043BF30[i]);
        lbl_80500E80[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_8043BF38[i]);
        lbl_80500E88[i] = (u8 *)TLobby::register_object(lbl_8043BF40[i]);
        lbl_80500E90[i] = (u8 *)TLobby::dispatch_shared_handler_a(lbl_8043BF48[i]);
    }
    NpcAnimationBinding sp = TObjEneBm5GibonU__spawn_params;
    m = TObjEneBm5GibonU__model_archive;
    sp.motions = reinterpret_cast<BmlMotionEntry *>(m->motions);
    NpcModelRegistry::register_animated_chunk(0xE, reinterpret_cast<void *>(m->models[0].model), reinterpret_cast<void *>(m->models[0].m_c), &sp, gibon_collision_body_templates[0].radius, 0.0f);
    NpcModelRegistry::register_animated_chunk(0xF, reinterpret_cast<void *>(TObjEneBm5GibonU__model_archive->models[1].model), reinterpret_cast<void *>(TObjEneBm5GibonU__model_archive->models[1].m_c), &sp, gibon_collision_body_templates[1].radius, 0.0f);
}

void TObjEneBm5GibonU::forward_hit(void* a1) {
    TObjEneBm5GibonUList *list = (TObjEneBm5GibonUList *)this;
    ((TObjEneBm5GibonU *)a1)->unlink_list_node((void ***)&list->head, (void **)&list->tail);
}
void TObjEneBm5GibonU::init_child(void* a1) {
    TObjEneBm5GibonUList *list = (TObjEneBm5GibonUList *)this;
    ((TObjEneBm5GibonU *)a1)->push_list_node((void **)&list->head, (void **)&list->tail);
}
void TObjEneBm5GibonU::reset_fields() {
    TObjEneBm5GibonUList *list = (TObjEneBm5GibonUList *)this;
    list->head = NULL;
    list->tail = NULL;
}
s32 __dt__16TObjEneBm5GibonUFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void*TObjEneBm5GibonU::reset() { reset_fields(); return this; }
void *TObjEneBm5GibonU::update_photon_mylla() {
    return find_entity_by_id(((TObjEneBm5GibonUNode *)this)->entity_id);
}
void TObjEneBm5GibonU::set_field8_from_obj(s32 arg1) {
    ((TObjEneBm5GibonUNode *)this)->entity_id = get_entity_id(arg1);
}

void TObjEneBm5GibonU::push_list_node(void **head, void **tail) {
    TObjEneBm5GibonUNode *node = (TObjEneBm5GibonUNode *)this;
    TObjEneBm5GibonUNode *last;
    last = (TObjEneBm5GibonUNode *)*tail;
    if (last != NULL) {
        node->prev = last;
        ((TObjEneBm5GibonUNode *)*tail)->next = node;
    } else {
        node->prev = NULL;
        *head = node;
    }
    *tail = node;
    node->next = NULL;
}

void TObjEneBm5GibonU::unlink_list_node(void ***head, void **tail) {
    TObjEneBm5GibonUNode *node = (TObjEneBm5GibonUNode *)this;
    TObjEneBm5GibonUNode *next;
    TObjEneBm5GibonUNode *prev;
    prev = node->prev;
    if (prev != NULL) {
        prev->next = node->next;
    } else {
        *head = (void **)node->next;
    }
    next = node->next;
    if (next != NULL) {
        next->prev = node->prev;
        return;
    }
    *tail = node->prev;
}

s32 TObjEneBm5GibonU::destroy(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TObjEneBm5GibonU__sub_800D1CF8(TObjEneBm5GibonUNode *self) {
    self->prev = NULL;
    self->next = NULL;
    self->entity_id = 0xFFFF;
}

#pragma push
#pragma opt_propagation off
void TObjEneBm5GibonU::register_global_objects() {
    TObjEneBm5GibonUStaticData *data = (TObjEneBm5GibonUStaticData *)TObjEneBm5GibonU__data_80500E78;
    __register_global_object(((TObjEneBm5GibonU *)&data->node_list)->reset(), (void *)__dt__16TObjEneBm5GibonUFis, data->node_list_chain);
    __register_global_object(((TObjEneBm5GibonU *)&data->enemy_list)->reset(), (void *)__dt__16TObjEneBm5GibonUFis, data->enemy_list_chain);
}
#pragma pop

s32 TObjEneBm5GibonU__sub_800D1D70(TObjEneBm5GibonU *self) { return self->m_46c; }
Vec *TObjEneBm5GibonU__sub_800D1D78(TObjEneBm5GibonU *self) { return &self->m_47c; }

void TObjEneBm5GibonU::clear_flag_and_update() {
    if (previous_mode == 7) {
        active_flags &= ~1;
        ((TObjEnemyCustom *)this)->update_if_active(0);
    }
}

s32 TObjEneBm5GibonU::check_and_update() {
    if (TObjChara::update_movement_status() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}
s32 TObjEneBm5GibonU::try_activate() {
    if (TObjChara::update_shock_clock() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

}

#pragma pop

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5GibonU_cpp_ref = (void *)TObjEneBm5GibonU::register_global_objects;
