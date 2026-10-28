#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void TObjNpcBase__ct(void *, void *);
void init_collision_body_parts(void *, void *, s32);
extern u8 npc_default_battle_stats[];
extern u8 npc_movement_parameters[];
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_88__14TObjNpcBringerFv();
extern "C" void *__dt__14TObjNpcBringerFv(void *arg0, s16 arg1);
extern "C" void draw_debug_info__11TObjNpcBaseFv();
extern "C" void is_target_in_attack_range__11TObjNpcBaseFv();
extern "C" void vfunc_92__11TObjNpcBaseFv();
extern "C" void vfunc_91__11TObjNpcBaseFv();
extern "C" void debug_draw_talk__11TObjNpcBaseFv();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void recalc_stats__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_63__13TUnk_804806E8Fv();
extern "C" void vfunc_62__13TUnk_804806E8Fv();
extern "C" void vfunc_61__13TUnk_804806E8Fv();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void apply_slow_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void vfunc_83__11TObjNpcBaseFv();
extern "C" void vfunc_58__11TObjNpcBaseFv();
extern "C" void vfunc_59__11TObjNpcBaseFv();
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
extern "C" void apply_set_params__11TObjNpcBaseFll();
extern "C" void apply_shock_status__13TUnk_804806E8Fv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void clear_harmful_statuses__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void draw_model__10TObjPlayerFv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void handle_message_event__17TObjNpcFemaleBaseFUs();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void play_voice__11TObjNpcBaseFv();
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void run_task__11TObjNpcBaseFv(u8 *arg0);
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void vfunc_28__11TObjNpcBaseFv();
extern "C" void update_conversation__11TObjNpcBaseFv();
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
extern "C" void update_standing__11TObjNpcBaseFv();
extern "C" void update_wandering__11TObjNpcBaseFv();
extern s32 TObjNpcBringer__name;
extern u8 *TObjEneDf2Bringer__resource_bundle;
u8 *TObjNpcBringer__ct(u8 *self, void *parent, s32 arg2);
void *npc_bringer_animation_table[8] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x10000, (void *)0xa, (void *)0x3f800000, (void *)0x1,
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
    (void *)&draw_model__10TObjPlayerFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&get_center__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&handle_message_event__17TObjNpcFemaleBaseFUs, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__11TObjNpcBaseFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__11TObjNpcBaseFv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__11TObjNpcBaseFv, (void *)&vfunc_59__11TObjNpcBaseFv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TUnk_804806E8Fv, (void *)&vfunc_62__13TUnk_804806E8Fv, (void *)&vfunc_63__13TUnk_804806E8Fv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
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
    ((TObjPlayer *)self)->init_npc_animation((void*)npc_bringer_animation_table, (void*)(*(s32 *)(TObjEneDf2Bringer__resource_bundle + 0x430)), (void*)(*(s16 *)(self + 0xB8)));
    *(u8 **)(self + 0x350) = npc_movement_parameters;
    ((TUnk_804806E8 *)self)->set_motion_params(npc_default_battle_stats);
    init_collision_body_parts(self, lbl_804A7EC0, 2);
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    return self;
}

}
