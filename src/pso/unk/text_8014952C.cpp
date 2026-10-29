#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void TObjNpcBase__ct(void *, void *);
void init_collision_body_parts(void *, void *, s32);
extern u8 npc_default_battle_stats[];
extern u8 npc_movement_parameters[];
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_88__14TObjNpcBringerFv();
extern "C" void *__dt__14TObjNpcBringerFv(void *arg0, s16 arg1);
extern "C" void draw_debug_info__11TObjNpcBaseFv();
extern "C" void is_target_in_attack_range__11TObjNpcBaseFv();
extern "C" void vfunc_92__11TObjNpcBaseFv();
extern "C" void vfunc_91__11TObjNpcBaseFv();
extern "C" void debug_draw_talk__11TObjNpcBaseFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_63__9TObjCharaFv();
extern "C" void vfunc_62__9TObjCharaFv();
extern "C" void vfunc_61__9TObjCharaFv();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void vfunc_83__11TObjNpcBaseFv();
extern "C" void vfunc_58__11TObjNpcBaseFv();
extern "C" void vfunc_59__11TObjNpcBaseFv();
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
extern "C" void apply_set_params__11TObjNpcBaseFll();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void draw_model__10TObjPlayerFv();
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
extern "C" void handle_message_event__17TObjNpcFemaleBaseFUs();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void play_voice__11TObjNpcBaseFv();
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void run_task__11TObjNpcBaseFv(u8 *arg0);
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void vfunc_28__11TObjNpcBaseFv();
extern "C" void update_conversation__11TObjNpcBaseFv();
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern "C" void update_standing__11TObjNpcBaseFv();
extern "C" void update_wandering__11TObjNpcBaseFv();
extern s32 TObjNpcBringer__name;
extern u8 *TObjEneDf2Bringer__resource_bundle;
u8 *TObjNpcBringer__ct(u8 *self, void *parent, s32 arg2);
TObjMotionAction npc_bringer_animation_table[2] = {
    {1, 0, 9, 0.8f, 1},
    {1, 0, 10, 1.0f, 1},
};
void *lbl_804A7EC0[22] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x40a00000, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0xc0a00000, (void *)0x40e00000, (void *)0x0,
    (void *)0x0, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *__vt__14TObjNpcBringer[94] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TObjNpcBringerFv, (void *)&run_task__11TObjNpcBaseFv,
    (void *)&draw_model__10TObjPlayerFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&handle_message_event__17TObjNpcFemaleBaseFUs, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__11TObjNpcBaseFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__11TObjNpcBaseFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__11TObjNpcBaseFv, (void *)&vfunc_59__11TObjNpcBaseFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__9TObjCharaFv, (void *)&vfunc_62__9TObjCharaFv, (void *)&vfunc_63__9TObjCharaFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__11TObjNpcBaseFv,
    (void *)&update_standing__11TObjNpcBaseFv, (void *)&update_wandering__11TObjNpcBaseFv, (void *)&update_conversation__11TObjNpcBaseFv, (void *)&apply_set_params__11TObjNpcBaseFll,
    (void *)&vfunc_88__14TObjNpcBringerFv, (void *)&debug_draw_talk__11TObjNpcBaseFv, (void *)&play_voice__11TObjNpcBaseFv, (void *)&vfunc_91__11TObjNpcBaseFv,
    (void *)&vfunc_92__11TObjNpcBaseFv, (void *)&draw_debug_info__11TObjNpcBaseFv,
};
u8 *TObjNpcBringer__ct(u8 *self, void *parent, s32 arg2) {
    TObjNpcBase__ct(self, parent);
    *(u8 **)(self + 0x18) = (u8 *)__vt__14TObjNpcBringer;
    *(s32 *)(self + 0) = TObjNpcBringer__name;
    ((TObjNpcBringer *)self)->apply_set_data((void *)arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    ((TObjNpcBringer *)self)->apply_set_params(0, 1);
    *(s32 *)(self + 0x34) = get_bml_model(TObjEneDf2Bringer__resource_bundle, 0);
    *(s32 *)(self + 0x24) = TObjFish__sub_8001EDB0(TObjEneDf2Bringer__resource_bundle, 0);
    ((TObjMotion *)self)->init_motion(npc_bringer_animation_table, (BmlMotionEntry *)*(s32 *)(TObjEneDf2Bringer__resource_bundle + 0x430), *(s16 *)(self + 0xB8));
    *(u8 **)(self + 0x350) = npc_movement_parameters;
    ((TObjChara *)self)->set_motion_params(npc_default_battle_stats);
    init_collision_body_parts(self, lbl_804A7EC0, 2);
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    return self;
}

}
