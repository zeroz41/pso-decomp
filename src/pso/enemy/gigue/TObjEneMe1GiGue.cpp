#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/PlayerAttackParams.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueBarrier.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"

s32 get_gigue_int_parameter(TObjEneMe1GiGue *, s32);
f32 get_gigue_float_parameter(TObjEneMe1GiGue *, s32);
extern f32 lbl_805D6840;
extern f32 lbl_805D6844;
extern f32 lbl_805D6848;
extern f32 lbl_805D684C;
extern s32 lbl_805D6850;
extern s32 lbl_805D6854;
void move_with_wall_slide(u8 *arg0);
int initialize_enemy_photon_effect(void *p);

extern "C" {

void __ct__15RenderFadeStateFv(void *);
void TObjEneMe1GiGue__sub_802CB824(TObjEneMe1GiGue *gigue, s32 index);
void find_open_direction__15TObjEneMe1GiGueFPvPv(TObjEneMe1GiGue *gigue, Vec *dir);
void TObjEneMe1GiGue__sub_802CB03C(TObjEneMe1GiGue *gigue);
s32 TObjEneMe1GiGue__sub_802CB10C(TObjEneMe1GiGue *gigue);
void add_target_in_cone__15TObjEneMe1GiGueFPvPv(TObjEneMe1GiGue *gigue, TObjChara *target);
void init__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CB378(TObjEneMe1GiGue *gigue);
void move_around_center__15TObjEneMe1GiGueFPvPvf(TObjEneMe1GiGue *gigue, Vec *center, f32 radius);
void update_rush_attack__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue);
void action__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CC45C(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CC614(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CC900(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CCBAC(TObjEneMe1GiGue *gigue);
void TObjEneMe1GiGue__sub_802CD054(TObjEneMe1GiGue *gigue);
TObjEneMe1GiGue *deleting_dtor__15TObjEneMe1GiGueFPvs(TObjEneMe1GiGue *self, s16 del);
s32 project_actor_to_ground(void *, void *, s32);
int get_player_data__10TObjPlayerFi(int a0);
extern s32 registered_player_count;
f64 atan2_float(f32, f32);
s16 get_entity_id(void *);
extern BmlResource *TObjEneMe1GiGue__data_805D6838;
s32 apply_actor_gravity(void *, int, f32);
s32 calc_velocity_toward_destination(void *, Vec, Vec, f32);
s32 play_persistent_sound(s32 id, void *source, Vec *pos, s32 a3, s32 flags);
s32 play_sound_effect(s32, void *, s32, s32);
extern TUnk_8048FA00 *TObjEneMe1GiGue__barrier_obj;
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 enemy_turn_toward_dest(void *, s32);
u16 find_nearest_visible_player(void *, int, f32);
s32 create__9TTecJelinFllll(void *, void *, void *, s32);
s32 create_instance__9TTecZaruaFllll(void *, void *, void *, s32);
s32 check_enemy_body_collisions(void *);
s32 check_path_obstructed(void *, Vec *);
void *find_entity_by_id(u16 id);
s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0);
s32 enemy_turn_half_toward_dest(void *);
s32 is_split_screen();
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 init_from_model__11TBreakUpMdlFl(s32, s32);
s32 find_active_entity_by_id(int);
void * __ct__11TObjControlFP7TObject(void *, void *);
s32 minimap_render_dot(void *, int, int, int);
TObjEneMe1GiGue *TObjEneMe1GiGue__ct(TObjEneMe1GiGue *self, TObject *parent, void *set_data);
void TObjEneMe1GiGue__sub_802CDAE8();
void TObjEneMe1GiGue__sub_802CE4E8(void);
void TObjEneMe1GiGue__sub_802CE4EC();
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);
extern GiGueParameters *TObjEneMe1GiGue__param_table;
extern s32 ene_me1_gigue_boss_id;
extern s32 lbl_805D682C;
extern s32 lbl_805D6830;
extern void *tl_04;
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void free_collision_body_parts(void *);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 obj_setFlags30(void *, int);
s32 __ct__15TObjEnemyCustomFP7TObject(void *, TObject *);
s32 init_collision_body_parts(void *, void *, int);

// The vtable entries, by their linker names.
void receive_weapon_special_attack__15TObjEneMe1GiGueFPvPv();
void receive_physical_attack__15TObjEneMe1GiGueFPvf();
void receive_direct_attack__15TObjEneMe1GiGueFPv19DirectAttackPayloadPvll();
void render__15TObjEneMe1GiGueFv();
void update_action_hold_status__15TObjEneMe1GiGueFv();
void vfunc_63__15TObjEneMe1GiGueFv();
void vfunc_62__15TObjEneMe1GiGueFv();
void run_task__15TObjEneMe1GiGueFv();
void get_anim_node_position__15TObjEnemyCustomFlP3Vec();
void vfunc_6__8TObjBaseFPsl();
void vfunc_58__15TObjEneMe1GiGueFv();
void vfunc_60__15TObjEneMe1GiGueFv();
void vfunc_59__15TObjEneMe1GiGueFv();
void vfunc_61__15TObjEneMe1GiGueFv();
void vfunc_28__15TObjEnemyCustomFv();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void vfunc_79__15TObjEnemyCustomFPl();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void apply_defense_stat_status__9TObjCharaFPv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFf();
void vfunc_75__9TObjCharaFf();
void clear_lobby_object_state__9TObjEnemyFv();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void render_shadows__9TObjEnemyFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv();
void try_start_action__9TObjCharaFll();
void vfunc_37__9TObjCharaFv();
void update_actor_ground_y__9TObjCharaFv();
void update_attack_stat_status__9TObjCharaFv();
void update_defense_stat_status__9TObjCharaFv();
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
void has_flag_0x800__9TObjCharaFv();
void test_flag30_512__9TObjCharaFv();
void test_flag_1000__9TObjCharaFv();
void test_flag_256__9TObjCharaFv();

// What movementParameters points at: EnemyMoveParams and four more words.
struct GiGueMoveParams {
    EnemyMoveParams move;
    s32 unk_c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
};

const char *TObjEneMe1GiGue__model_filename_table[4] = {
    "gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *me1_gi_gue_motion_filename_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor lbl_804E1200 = {
    "bm_ene_gi_gue.bml", TObjEneMe1GiGue__model_filename_table, me1_gi_gue_motion_filename_table, 3, 9,
};

const char *lbl_804E1210[4] = {
    "lo_gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *gi_gue_njm_name_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor lbl_804E1248 = {
    "bm_ene_gi_gue_low.bml", lbl_804E1210, gi_gue_njm_name_table, 3, 9,
};

TObjMotionAction gigue_enemy_param_table[9] = {
    {2, 0, 4, 0.7f, 0},
    {1, 1, 3, 0.7f, 1},
    {2, 0, 2, 0.6f, 4},
    {2, 7, 1, 0.6f, 4},
    {2, 0, 0, 0.5f, 8},
    {2, 7, 0, 0.5f, 8},
    {2, 7, 3, 0.7f, 1},
    {1, 7, 3, 0.7f, 1},
    {2, 0, 3, 0.7f, 1},
};

GiGueMoveParams lbl_804E12E8 = {
    {150.0f, 0.46296296f, 0x300}, 0x1E0000, 0, 1, 0,
};

CollisionBody lbl_804E1304[2] = {
    {{0.0f, 15.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 12.0f, 0.0f, 0, 0xA000002, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneMe1GiGue__name = "TObjEneMe1GiGue";
void *lbl_804E135C[83] = {
    (void *)0x0, (void *)0x0, (void *)&deleting_dtor__15TObjEneMe1GiGueFPvs, (void *)&run_task__15TObjEneMe1GiGueFv,
    (void *)&render__15TObjEneMe1GiGueFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__15TObjEneMe1GiGueFPvf, (void *)&receive_direct_attack__15TObjEneMe1GiGueFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__15TObjEneMe1GiGueFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__15TObjEnemyCustomFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__15TObjEneMe1GiGueFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__15TObjEneMe1GiGueFv, (void *)&vfunc_59__15TObjEneMe1GiGueFv,
    (void *)&vfunc_60__15TObjEneMe1GiGueFv, (void *)&vfunc_61__15TObjEneMe1GiGueFv, (void *)&vfunc_62__15TObjEneMe1GiGueFv, (void *)&vfunc_63__15TObjEneMe1GiGueFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__15TObjEnemyCustomFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__15TObjEnemyCustomFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};

}

void TObjEneMe1GiGue::load_params_from_table(s32 i) {
    model = (void *)TObjEneMe1GiGue__data_805D6838->models[i].model;
    texlist = TObjEneMe1GiGue__data_805D6838->models[i].m_c;
}

void TObjEneMe1GiGue__sub_802CDAE8(void) {  }

f32 get_gigue_float_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->floats[i];
}

s32 get_gigue_int_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->ints[i];
}

extern "C" {

void TObjEneMe1GiGue::vfunc_61() {  }

void TObjEneMe1GiGue::vfunc_59() {  }

void TObjEneMe1GiGue::vfunc_60() {  }

void TObjEneMe1GiGue::vfunc_58() {  }

TObjEneMe1GiGue *TObjEneMe1GiGue__ct(TObjEneMe1GiGue *self, TObject *parent, void *set_data) {
    __ct__15TObjEnemyCustomFP7TObject(self, parent);
    *(void **)((s8 *)self + 0x18) = lbl_804E135C;
    __ct__13TUnk_80494938Fv(&self->m_3fc);
    __ct__15RenderFadeStateFv(&self->m_418);
    self->m_name = TObjEneMe1GiGue__name;
    self->apply_set_data(set_data);
    VecCopy((Vec *)&self->m_290, VecCopy((Vec *)&self->m_29c, &self->position));
    self->motion_list = TObjEneMe1GiGue__data_805D6838->motions;
    self->variant = 0;
    self->add_flags_2e4(0x11);
    self->state36C = *(s16 *)((s8 *)set_data + 0x3E);
    self->load_params_from_table(self->variant);
    self->action_table = gigue_enemy_param_table;
    self->set_field_d8((s32)self->action_table);
    init_collision_body_parts(self, lbl_804E1304, 2);
    self->bodies[1].flags &= ~1;
    self->movementParameters = &lbl_804E12E8;
    self->bind_enemy_combat_stats((u8 *)ene_me1_gigue_boss_id, (u8 *)lbl_805D682C, (u8 *)lbl_805D6830);
    self->update_direction();
    self->load_params();
    self->requested_action = 0;
    self->set_animation(self->requested_action);
    self->set_field_b8(self->requested_action);
    self->hp = self->hpmax;
    self->tp = self->tpmax;
    self->referenceHp = self->hp;
    self->update_prev_position();
    initialize_enemy_photon_effect(self);
    self->m_38c = 0;
    self->scale.x = 1.0f;
    self->m_3e4 = ((EnemyMoveParams *)self->movementParameters)->min_distance * self->scale.x;
    VecCopy(&self->home_position, &self->position);
    VecCopy(&self->m_390, &self->position);
    self->m_440 = 0.5f + self->parameters[3];
    self->m_444 = 0.5f + self->parameters[4];
    self->m_43c = 150.0f + self->parameters[2];
    if (self->m_43c < 0.0f) {
        self->m_43c = 0.0f;
    }
    if ((s32)self->parameters[0] >= 1) {
        self->m_388 |= 0x40000;
        if (self->parameters[1] < 1.0f) {
            self->parameters[1] = 50.0f;
        }
        self->set_flags_30();
    }
    self->m_3f4 = 0;
    self->m_3f8 = 0;
    self->set_param(0x37);
    self->m_3e8 = 0.0f;
    self->m_448 = 0;
    if (self->m_388 & 0x40000) {
        self->init_move();
    } else {
        self->sub_800C7860();
    }
    project_actor_to_ground(self, &self->position, 0);
    self->m_3ec = 0.0f;
    self->m_418.activate_and_dispatch();
    obj_setFlags30(self, 0x01000000);
    VecCopy(&self->prev_position, &self->position);
    self->clear_lobby_object_state();
    return self;
}

TObjEneMe1GiGue *deleting_dtor__15TObjEneMe1GiGueFPvs(TObjEneMe1GiGue *self, s16 del) {
    if (self != NULL) {
        *(void **)((s8 *)self + 0x18) = lbl_804E135C;
        free_collision_body_parts(self);
        __dt__15RenderFadeStateFv(&self->m_418, -1);
        __dt__13TUnk_80494938Fv(&self->m_3fc, -1);
        __dt__15TObjEnemyCustomFv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void TObjEneMe1GiGue::load_resources() {
    void *o;

    if (is_split_screen() != 0) {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &lbl_804E1248, 0, 0, 0);
        }
        TObjEneMe1GiGue__data_805D6838 = (BmlResource *)o;
    } else {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &lbl_804E1200, 0, 0, 0);
        }
        TObjEneMe1GiGue__data_805D6838 = (BmlResource *)o;
    }
    ene_me1_gigue_boss_id = register_boss__6TLobbyFl(0x1A);
    lbl_805D682C = dispatch_shared_handler_b__6TLobbyFl(0x1A);
    lbl_805D6830 = register_object__6TLobbyFl(0x1A);
    TObjEneMe1GiGue__param_table = (GiGueParameters *)dispatch_shared_handler_a__6TLobbyFl(0x1A);
    o = ::operator new(0x10);
    if (o != NULL) {
        o = (void *)init_from_model__11TBreakUpMdlFl((s32)o, TObjEneMe1GiGue__data_805D6838->models->model);
    }
    TObjEneMe1GiGue__barrier_obj = (TUnk_8048FA00 *)o;
    TObjEneMe1GiGue__sub_802CE4EC();
    TObjEneMe1GiGueBarrier::init_global();
    {
    DelDepthAnimationBinding binding = {TObjEneMe1GiGue__data_805D6838->motions, gigue_enemy_param_table, 1, 9, 0};
    TLobby::spawn_npc_enemy(0x41, TObjEneMe1GiGue__data_805D6838->models->model, (NJS_TEXLIST *)TObjEneMe1GiGue__data_805D6838->models->m_c, &binding, lbl_804E1304[0].radius, 15.0f);
    }
}

void TObjEneMe1GiGue::delete_barrier() {
    TObjEneMe1GiGueBarrier__sub_80325CC0();
    TObjEneMe1GiGue__sub_802CE4E8();
    if (TObjEneMe1GiGue__barrier_obj != NULL) {
        delete TObjEneMe1GiGue__barrier_obj;
        TObjEneMe1GiGue__barrier_obj = NULL;
    }
    if (TObjEneMe1GiGue__data_805D6838 != NULL) {
        free_bin_model_request(TObjEneMe1GiGue__data_805D6838, 1);
        TObjEneMe1GiGue__data_805D6838 = NULL;
    }
}

void *TObjEneMe1GiGue::create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x458);
    if (o2 != NULL) {
        o2 = TObjEneMe1GiGue__ct((TObjEneMe1GiGue *)o2, (TObject *)o, arg0);
    }
    return o2;
}

void TObjEneMe1GiGue::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        TObjEneMe1GiGue__sub_802CD054(this);
        return;
    }
    target = (u8 *)find_active_entity_by_id(targetId);
    release_destroyed_target();
    sub_802CB6D4();
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            dispatch_state();
        }
        mode = next_action;
        state = 0;
    }
    dispatch_state();
    if ((s32)state == -1) {
        state = -1;
        dispatch_state();
        mode = next_action;
        state = 0;
    }
    VecCopy((Vec *)&m_2fc, &position);
    m_300 += 15.0f + m_3ec;
    bodies[0].offset.y = 25.0f + m_3ec;
    if (!(m_388 & 0x40000)) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
    if (m_3f4 > 0) {
        m_3f4--;
    }
    bodies[0].flags &= ~6;
    if (m_3ec > 5.0f) {
        bodies[0].flags |= 4;
    } else {
        bodies[0].flags |= 2;
    }
    m_418.update();
    if (xz_distance_squared(&position, &prev_position) > 2500.0f) {
        VecCopy(&position, &prev_position);
    }
    VecCopy(&prev_position, &position);
}

void TObjEneMe1GiGue::dispatch_state() {
    switch (mode) {
    case 0:
        sub_802CCF2C();
        return;
    case 1:
        TObjEneMe1GiGue__sub_802CCBAC(this);
        return;
    case 2:
        TObjEneMe1GiGue__sub_802CDAE8();
        return;
    case 3:
        update_state_machine();
        return;
    case 4:
        update_hit_reaction();
        return;
    case 5:
        break_apart();
        return;
    case 9:
        TObjEneMe1GiGue__sub_802CC614(this);
        return;
    case 10:
        TObjEneMe1GiGue__sub_802CC900(this);
        return;
    case 11:
        TObjEneMe1GiGue__sub_802CC45C(this);
        return;
    case 12:
        action__15TObjEneMe1GiGueFPv(this);
        return;
    case 13:
        update_rush_attack__15TObjEneMe1GiGueFPv(this);
        return;
    case 7:
        init__15TObjEneMe1GiGueFPv(this);
        return;
    case 14:
        TObjEneMe1GiGue__sub_802CB378(this);
        break;
    }
}

void TObjEneMe1GiGue::render() {
    s32 vis;
    s32 ok;

    if (actorFlags & 0x2000000) {
        return;
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = classify_actor_view_detail(600.0f, 600.0f, 20.0f);
    } else {
        vis = classify_actor_view_detail(150.0f, 400.0f, 20.0f);
    }
    if (vis == 0) {
        return;
    }
    if (TObjPlayer::check_demo_mode() != 1 && (m_388 & 0x40000)) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (m_418.updateFromCamera(&m_2fc) != 0) {
        ((MaterialColorFade *)&m_418)->set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            model_render_flags = saved_model_render_flags;
            return;
        }
    }
    TObjFish::set_global_param(texlist);
    select_actor_lighting((s32)this);
    TObjPlayer::toggle_particle_effect();
    ok = 1;
    push_matrix();
    translate_matrix(0, position.x, m_3ec + (position.y + m_3e8), position.z);
    rotate_matrix_y(NULL, rotation_y);
    model_render_flags &= ~0x400;
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else if (m_388 & 4) {
        if (((MaterialColorFade *)&m_3fc)->has_visible_opacity() != 0) {
            ((MaterialColorFade *)&m_3fc)->set_flags_and_apply_damage_color();
            if (vis == 1) {
                set_motion_packed_rotation();
                draw();
                clear_motion_packed_rotation();
            } else {
                set_motion_packed_rotation();
                draw_motion_model();
                clear_motion_packed_rotation();
            }
            ((MaterialColorFade *)&m_3fc)->clear_flag_and_notify();
        } else {
            ok = 0;
        }
    } else {
        if (vis == 1) {
            set_motion_packed_rotation();
            draw();
            clear_motion_packed_rotation();
        } else {
            set_motion_packed_rotation();
            draw_motion_model();
            clear_motion_packed_rotation();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    TParticleCtrl::end_effect_render();
    if (!(actorFlags & 0x800) && ok != 0) {
        Vec v;
        v.x = v.y = v.z = (1.0f - 0.01f * m_3ec) * (5.0f * scale.x);
        draw_ground_shadow(&v, 0);
    }
    ((MaterialColorFade *)&m_418)->clear_flag_and_notify();
    model_render_flags = saved_model_render_flags;
}

void TObjEneMe1GiGue__sub_802CD054(TObjEneMe1GiGue *gigue) {  }

void TObjEneMe1GiGue::sub_802CCF2C() {
    if (m_388 & 0x40000) {
        return;
    }
    switch (state) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        state = 1;
        m_384 = 150;
        sub_8004292C();
    case 1:
        advance_animation();
        move_around_center__15TObjEneMe1GiGueFPvPvf(this, &home_position, parameters[1]);
        m_384 -= 1;
        if (m_384 <= 0) {
            requested_action = 0;
            state = 2;
            m_384 = 90;
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation();
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        m_384 -= 1;
        if (m_384 <= 0) {
            state = 0;
        }
        break;
    }
}

void TObjEneMe1GiGue::vfunc_62() {
    switch (mode) {
    case 10:
    case 11:
    case 13:
        referenceHp = hp;
        actorFlags &= ~0x200;
        return;
    }
    set_state(4);
    m_380 = m_378;
    m_378 = 4;
    m_388 |= 0x10000 | 1;
}

void TObjEneMe1GiGue::vfunc_63() {
    set_state(5);
    m_380 = m_378;
    m_378 = 5;
    m_388 |= 1;
}

void TObjEneMe1GiGue__sub_802CCBAC(TObjEneMe1GiGue *gigue) {
    gigue->actorFlags &= ~0x01000000;
    switch (gigue->state) {
    case 0:
        gigue->m_388 &= ~0x00040000;
        gigue->sub_8004292C();
        gigue->requested_action = 1;
        gigue->m_3dc = 0;
        if (gigue->target != NULL) {
            VecCopy((Vec *)&gigue->m_29c, (Vec *)&((TObjChara *)gigue->target)->m_2fc);
        }
        gigue->state = 1;
    case 1:
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        if (gigue->target != NULL) {
            Vec d = ((TObjBase *)gigue->target)->position;
            subtract_vector(&d, &gigue->position);
            if (d.x * d.x + d.z * d.z <= gigue->m_438 * gigue->m_438 &&
                angle_difference_abs(-(s32)(10430.38043493439 * atan2_float(d.z, d.x)) + 0x4000, gigue->rotation_y) < gigue->m_434 / 2) {
                s32 next;
                gigue->m_3f8++;
                if (gigue->m_3f8 > 2) {
                    gigue->m_3f8 = 0;
                    next = 13;
                } else {
                    gigue->m_448 = 0;
                    next = 9;
                }
                gigue->update_if_active(next);
                break;
            }
        }
        gigue->rotation_y += ((EnemyMoveParams *)gigue->movementParameters)->turn_speed / 2;
        enemy_set_heading_velocity(gigue->m_3e4, gigue, gigue->rotation_y);
        move_with_wall_slide((u8 *)gigue);
        gigue->m_3dc += ((EnemyMoveParams *)gigue->movementParameters)->turn_speed / 2;
        if (gigue->m_3dc > 0x10000) {
            gigue->m_3e0 = 0.0f;
            gigue->state = 2;
        }
        break;
    case -1:
        break;
    case 2:
        gigue->enemy_wander_home(gigue->m_3e4, 100.0f, 50.0f, ((EnemyMoveParams *)gigue->movementParameters)->turn_speed);
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        gigue->m_3e0 += gigue->m_3e4;
        if (gigue->m_3e0 > 100.0f) {
            if (gigue->find_target_in_range(((EnemyMoveParams *)gigue->movementParameters)->max_distance) != 0) {
                gigue->m_3dc = 0;
                gigue->state = 1;
            } else {
                gigue->update_if_active(0);
            }
        }
        gigue->check_object_collisions();
        check_enemy_body_collisions(gigue);
        gigue->update_enemy_collision_flags();
        break;
    }
}

void TObjEneMe1GiGue__sub_802CC900(TObjEneMe1GiGue *gigue) {
    TParticleCtrl *particle;

    switch (gigue->state) {
    case 0:
        gigue->sub_8004292C();
        gigue->m_384 = gigue->m_450;
        if (gigue->m_384 <= 40) {
            gigue->m_384 = 40;
        }
        if (!(gigue->actorFlags & 0x01000000)) {
            gigue->requested_action = 2;
            goto start;
        }
        gigue->update_if_active(13);
        gigue->m_388 &= ~0x40000;
        break;
    start:
        gigue->state = 1;
        gigue->advance_animation();
        gigue->m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        if (gigue->target == NULL) {
            gigue->state = 4;
            break;
        }
        switch (gigue->state) {
        case 1:
            if (gigue->frame >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                gigue->state = 2;
            }
            break;
        case 2:
            play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A81D), gigue, &gigue->position, 0, 0);
            if (gigue->frame >= 20.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                if ((particle = (TParticleCtrl *)spawn_particle_effect(&gigue->m_39c, 0x203)) != NULL) {
                    GiGueShotAngles dir = {0x4000, 0, 0};
                    particle->set_direction(&dir);
                }
                TObjEneMe1GiGueMissile::create((s32)gigue, (s32)&gigue->m_39c, (s32)&((TObjChara *)gigue->target)->m_2fc, lbl_805D6840, (f32)lbl_805D6850);
                play_sound_effect(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A31E), &gigue->position, 0, 0);
                gigue->state = 3;
            }
            break;
        }
        VecCopy((Vec *)&gigue->m_29c, (Vec *)&((TObjChara *)gigue->target)->m_2fc);
        enemy_turn_half_toward_dest(gigue);
        gigue->advance_animation();
        if (!(gigue->actorFlags & 0x01000000)) {
            apply_actor_gravity(gigue, 0, 0.0f);
        }
        ((TObjPlayer *)gigue)->update_collisions();
        if (--gigue->m_384 <= 0) {
            gigue->state = 4;
        }
        break;
    case 4:
        if (gigue->actorFlags & 0x01000000) {
            gigue->m_378 = 0;
            gigue->update_if_active(13);
        } else if (!(gigue->m_388 & 0x80000) && gigue->random_ratio() <= gigue->m_440) {
            gigue->update_if_active(12);
        } else {
            gigue->update_if_active(0);
        }
        break;
    case -1:
        break;
    }
}

void TObjEneMe1GiGue__sub_802CC614(TObjEneMe1GiGue *gigue) {
    s32 n;
    s32 count;

    switch (gigue->state) {
    case -1:
        break;
    case 0:
        gigue->sub_8004292C();
        count = 0;
        if (!(gigue->actorFlags & 0x01000000)) {
            count = TObjEneMe1GiGue__sub_802CB10C(gigue);
        }
        if (count > 0) {
            gigue->requested_action = 3;
            gigue->m_384 = gigue->m_450;
            if (gigue->m_384 <= 20) {
                gigue->m_384 = 20;
            }
            gigue->state = 1;
        } else if (gigue->actorFlags & 0x01000000) {
            gigue->update_if_active(13);
        } else if (!(gigue->m_388 & 0x80000) && gigue->random_ratio() <= gigue->m_440) {
            gigue->update_if_active(12);
        } else {
            gigue->update_if_active(0);
        }
        gigue->m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (gigue->state) {
        case 1:
            if (gigue->frame >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                gigue->state = 2;
            }
            break;
        case 2:
            play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A820), gigue, &gigue->position, 0, 0);
            if (gigue->frame >= 10.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                n = gigue->m_3c0;
                TObjEneMe1GiGue__sub_802CB824(gigue, (s32)((f32)n * gigue->random_ratio()) % n);
                gigue->state = 3;
            }
            break;
        }
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        ((TObjPlayer *)gigue)->update_collisions();
        gigue->m_384--;
        if (gigue->m_384 <= 0) {
            gigue->m_448++;
            if (gigue->m_448 >= 3) {
                gigue->m_384 = 45;
                gigue->requested_action = 1;
                gigue->state = 4;
            } else {
                gigue->state = 0;
                gigue->frame = 0.0f;
            }
        }
        break;
    case 4:
        gigue->enemy_wander_home(gigue->m_3e4, 100.0f, 100.0f, ((EnemyMoveParams *)gigue->movementParameters)->turn_speed);
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        ((TObjPlayer *)gigue)->update_collisions();
        gigue->m_384--;
        if (gigue->m_384 <= 0) {
            if (!(gigue->m_388 & 0x80000) && gigue->random_ratio() <= gigue->m_440) {
                gigue->update_if_active(12);
            } else {
                gigue->update_if_active(0);
            }
        }
        break;
    }
}

void TObjEneMe1GiGue__sub_802CC45C(TObjEneMe1GiGue *gigue) {
    s32 count;
    switch (gigue->state) {
    case -1:
        break;
    case 0:
        gigue->sub_8004292C();
        count = 0;
        if (!(gigue->actorFlags & 0x01000000)) {
            count = TObjEneMe1GiGue__sub_802CB10C(gigue);
        }
        if (count > 0) {
            gigue->state = 1;
            gigue->requested_action = 3;
        } else if (gigue->actorFlags & 0x01000000) {
            gigue->update_if_active(13);
        } else {
            gigue->update_if_active(0);
        }
        gigue->m_388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (gigue->state) {
        case 1:
            if (gigue->frame >= 5.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                spawn_particle_effect(&gigue->m_3a8, 0x204);
                gigue->state = 2;
            }
            break;
        case 2:
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A344), &gigue->position, 0, 0);
            if (gigue->frame >= 10.0f) {
                TObjEneMe1GiGue__sub_802CB03C(gigue);
                gigue->state = 3;
                create_instance__9TTecZaruaFllll(gigue, &gigue->m_2fc, &gigue->m_2fc, get_gigue_int_parameter(gigue, 2));
                create__9TTecJelinFllll(gigue, &gigue->m_2fc, &gigue->m_2fc, get_gigue_int_parameter(gigue, 2));
            }
            break;
        }
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        ((TObjPlayer *)gigue)->update_collisions();
        if (gigue->requested_action != 3) {
            gigue->update_if_active(13);
        }
        break;
    }
}

void action__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue) {
    switch (gigue->state) {
    case 0:
        gigue->sub_8004292C();
        gigue->m_388 &= ~0x40000;
        gigue->requested_action = 1;
        gigue->state = 1;
        return;
    case 1:
        TObjEneMe1GiGueBarrier::create(gigue, gigue);
        gigue->state = 2;
        gigue->m_384 = 45;
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        ((TObjPlayer *)gigue)->update_collisions();
        return;
    case 2:
        gigue->enemy_wander_home(gigue->m_3e4, 100.0f, 100.0f, ((EnemyMoveParams *)gigue->movementParameters)->turn_speed);
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        ((TObjPlayer *)gigue)->update_collisions();
        gigue->m_384 = gigue->m_384 - 1;
        if (gigue->m_384 <= 0) {
            gigue->update_if_active(0);
        }
    case -1:
        return;
    }
}

void update_rush_attack__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue) {
    switch (gigue->state) {
    case 0:
        gigue->actorFlags |= 0x800000;
        gigue->actorFlags &= ~0x1000000;
        gigue->requested_action = gigue->state = 1;
        gigue->m_3ec = 0.0f;
        gigue->m_454 = 60;
        gigue->sub_8004292C();
        break;
    case 1:
        gigue->actorFlags &= ~0x1000000;
        gigue->enemy_wander_home(gigue->m_3e4, 100.0f, 50.0f, ((EnemyMoveParams *)gigue->movementParameters)->turn_speed);
        gigue->advance_animation();
        apply_actor_gravity(gigue, 0, 0.0f);
        gigue->m_454--;
        if (gigue->m_454 <= 0) {
            gigue->state = 2;
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A818), &gigue->position, 0, 0);
            gigue->actorFlags |= 0x1000000;
            gigue->actorFlags &= ~0x800000;
            gigue->find_target_in_range(((EnemyMoveParams *)gigue->movementParameters)->max_distance);
            if (gigue->target != NULL) {
                Vec d;
                VecCopy(&d, &gigue->position);
                subtract_vector(&d, &((TObjBase *)gigue->target)->position);
                find_open_direction__15TObjEneMe1GiGueFPvPv(gigue, &d);
                calc_velocity_toward_destination(gigue, gigue->position, gigue->m_390, gigue->m_3e4);
            } else {
                VecCopy(&gigue->m_390, &gigue->home_position);
                calc_velocity_toward_destination(gigue, gigue->position, gigue->m_390, gigue->m_3e4);
            }
        }
        gigue->check_object_collisions();
        check_enemy_body_collisions(gigue);
        gigue->update_enemy_collision_flags();
        break;
    case 2: {
        s32 rising;
        gigue->actorFlags &= ~0x800000;
        gigue->advance_animation();
        calc_velocity_toward_destination(gigue, gigue->position, gigue->m_390, get_gigue_float_parameter(gigue, 0));
        rising = 1;
        if (gigue->requested_action == 6 && gigue->frame < 22.0f) {
            rising = 0;
        }
        if (rising) {
            gigue->m_3ec += 2.2f;
        }
        ((TObjPlayer *)gigue)->update_collisions();
        if (TObjPlayer__sub_800DC478((u8 *)gigue, 1, 22.0f) != 0 && gigue->check_vector_bit(&gigue->position) != 0) {
            spawn_particle_effect(&gigue->position, 0xF0);
        }
        if (gigue->m_3ec >= 50.0f) {
            gigue->state = 3;
        }
        play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A819), gigue, &gigue->position, 0, 0);
        break;
    }
    case 3:
        gigue->advance_animation();
        calc_velocity_toward_destination(gigue, gigue->position, gigue->m_390, get_gigue_float_parameter(gigue, 0));
        gigue->y_speed = 0.0f;
        VecCopy(&gigue->prev_position, &gigue->position);
        vec3_add_to(&gigue->position, (Vec *)&gigue->x_speed);
        if (csnVector(&gigue->prev_position, &gigue->position, 0x88E0) != 0) {
            VecCopy(&gigue->position, &gigue->prev_position);
            gigue->state = 4;
            gigue->x_speed = gigue->m_310 = 0.0f;
        } else {
            if (xz_distance_squared(&gigue->position, &gigue->m_390) <= (10.0f + gigue->m_3e4) * (10.0f + gigue->m_3e4)) {
                gigue->state = 4;
                gigue->x_speed = gigue->m_310 = 0.0f;
            }
        }
        if (gigue->is_passing_frame(10.0f) != 0 && gigue->check_vector_bit(&gigue->position) != 0) {
            spawn_particle_effect(&gigue->position, 0xF0);
        }
        gigue->refresh_collision_body_centers();
        if (gigue->m_3ec > 15.0f) {
            gigue->turn_toward_direction(((EnemyMoveParams *)gigue->movementParameters)->turn_speed * 2, (Vec *)&gigue->x_speed);
        }
        play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A819), gigue, &gigue->position, 0, 0);
        project_actor_to_ground(gigue, &gigue->position, 0);
        break;
    case 4:
        gigue->actorFlags &= ~0x800000;
        gigue->bodies[1].flags |= 1;
        gigue->advance_animation();
        gigue->m_3ec += -2.3f;
        if (gigue->m_3ec <= 0.0f) {
            gigue->m_3ec = 0.0f;
            gigue->actorFlags |= 0x800000;
            gigue->actorFlags &= ~0x1000000;
            gigue->y_speed = 0.0f;
            if (gigue->requested_action != 8) {
                if (!(gigue->m_388 & 0x80000) && gigue->random_ratio() <= gigue->m_440) {
                    gigue->update_if_active(12);
                } else {
                    gigue->update_if_active(0);
                }
            }
        } else if (gigue->requested_action == 7) {
            if (gigue->m_3ec <= 2.3f * (40.0f + 1.0f / gigue->blend_speed)) {
                gigue->requested_action = 8;
            }
        } else {
            s32 frame = (s32)gigue->frame;
            if ((frame == 0x14 || frame == 0x28) && gigue->check_vector_bit(&gigue->position) != 0) {
                spawn_particle_effect(&gigue->position, 0xF0);
            }
        }
        play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A819), gigue, &gigue->position, 0, 0);
        gigue->check_object_collisions();
        check_enemy_body_collisions(gigue);
        gigue->update_enemy_collision_flags();
        apply_actor_gravity(gigue, 0, 0.0f);
        break;
    case -1:
        if ((s32)gigue->next_action != 4 && (s32)gigue->next_action != 5) {
            gigue->m_3ec = 0.0f;
        }
        gigue->bodies[1].flags &= ~1;
        gigue->m_388 &= ~0x40000;
        gigue->m_3f8 = 0;
        break;
    }
}

void TObjEneMe1GiGue::update_hit_reaction() {
    s16 action;
    s16 ref_hp;
    s32 entity;
    s32 retaliate;
    switch (state) {
    case 0:
        action = 4;
        actorFlags &= ~0x200000;
        if (actorFlags & 0x01000000) {
            action = 5;
        }
        requested_action = action;
        spawn_particle_effect(&m_2fc, 0xF2);
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            Vec v = *(Vec *)&m_2fc;
            v.x += x_speed;
            v.z += m_310;
            if (check_path_obstructed(this, &v) == 0) {
                move_with_wall_slide((u8 *)this);
            } else {
                x_speed = m_310 = 0.0f;
            }
            x_speed *= 0.5f;
            m_310 *= 0.5f;
        }
        apply_actor_gravity(this, 0, 0.0f);
        ((TObjPlayer *)this)->update_collisions();
        if (action_flags != 8) {
            state = -1;
        }
        break;
    case -1:
        retaliate = 0;
        actorFlags &= ~0x200;
        m_388 &= ~1;
        m_378 = 1;
        ref_hp = referenceHp;
        if (ref_hp - hp > ref_hp / 4 && !(actorFlags & 2)) {
            entity = (s32)find_entity_by_id(m_2d4);
            if (entity != 0) {
                retaliate = 1;
                if ((actorFlags & 0x01000000) && xz_distance_squared(&position, &((TObjBase *)entity)->position) > 400.0f) {
                    retaliate = 0;
                }
            }
        }
        if (retaliate == 1) {
            targetId = m_2d4;
            next_action = 9;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
            m_378 = m_380;
        } else {
            update_if_active(0);
        }
        referenceHp = hp;
        break;
    }
}

void TObjEneMe1GiGue::break_apart() {
    Vec pos;
    VecCopy(&pos, &position);
    pos.y += 40.0f + m_3ec;
    TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe1GiGue__barrier_obj, 0, texlist, (s32)&pos, rotation_y);
    ((TObjPlayer *)this)->refresh_lobby_state();
    send_entity_set_flags();
    spawn_particle_effect(&pos, 0x205);
    spawn_particle_effect(&pos, 0x206);
    play_sound_effect(remap_sound_id(this, 0x3AF1C), &pos, 0, 0);
    queue_destruction();
}

void move_around_center__15TObjEneMe1GiGueFPvPvf(TObjEneMe1GiGue *gigue, Vec *center, f32 radius) {
    if (xz_distance_squared(&gigue->position, &gigue->m_390) < 400.0f) {
        s32 angle = (s32)(182.04445f * (360.0f * gigue->random_ratio()));
        f32 d = 0.4f * (radius * (1.0f + gigue->random_ratio()));
        gigue->m_390.x = d * cos_table_lookup(angle) + center->x;
        gigue->m_390.z = d * sin_table_lookup(angle) + center->z;
    }
    VecCopy((Vec *)&gigue->m_29c, &gigue->m_390);
    enemy_turn_toward_dest(gigue, ((EnemyMoveParams *)gigue->movementParameters)->turn_speed);
    enemy_set_heading_velocity(gigue->m_3e4, gigue, gigue->rotation_y);
    move_with_wall_slide((u8 *)gigue);
}

void TObjEneMe1GiGue__sub_802CB824(TObjEneMe1GiGue *gigue, s32 index) {
    if (find_entity_by_id(gigue->m_3c4[index]) != 0) {
        GiGueShotAngles angles;
        angles.x = 0;
        angles.y = gigue->rotation_y + ((index & 1) ? -0x2000 : 0x2000);
        angles.z = 0;
        new TUnk_804E14E8(&gigue->m_3a8, gigue->m_3c4[index], &angles, index * 3,
                          gigue->random_ratio() <= get_gigue_float_parameter(gigue, 5),
                          gigue->entity_id);
    }
}

void TObjEneMe1GiGue::sub_802CB6D4() {
    switch (mode) {
    case 0:
        if (is_actor_cadence_frame(30) != 0) {
            if (find_nearest_visible_player(this, 0, ((EnemyMoveParams *)movementParameters)->max_distance) != 0xFFFF) {
                find_target_in_range(((EnemyMoveParams *)movementParameters)->max_distance);
                if (m_388 & 0x40000) {
                    init_move();
                } else {
                    update_if_active(1);
                }
            }
        }
        break;
    case 1:
        if (find_nearest_visible_player(this, 0, 50.0f) != 0xFFFF) {
            if (random_ratio() <= m_444) {
                update_if_active(11);
            } else {
                update_if_active(13);
                m_378 = 1;
            }
        } else if (find_nearest_visible_player(this, 0, 50.0f + ((EnemyMoveParams *)movementParameters)->max_distance) == 0xFFFF) {
            update_if_active(0);
        }
        break;
    case 13:
        break;
    }
}

void TObjEneMe1GiGue::init_move() {
    VecCopy(&prev_position, &position);
    actorFlags |= 0x01000000;
    update_if_active(14);
    m_378 = 1;
    refresh_collision_body_centers();
}

void TObjEneMe1GiGue::apply_hit_shake(TObjChara *player) {
    if (player == get_player_by_client_id(0) && m_3f4 <= 0) {
        m_3f4 = 30;
        TCameraCtrl::set_shake_preset(1);
    }
}

s32 TObjEneMe1GiGue::remap_sound_id(void *obj, s32 id) {
    s32 area = get_current_floor_area();
    if (id == 0x3A344) return area == AREA_TOWER ? 0x40039E14 : id;
    if (id == 0x3A345) return area == AREA_TOWER ? 0x40039415 : id;
    return ((TObjEnemy *)obj)->remap_sound_for_area(id);
}

}

void TObjEneMe1GiGue__sub_802CB378(TObjEneMe1GiGue *gigue) {
    f32 height;
    s32 frame;
    switch (gigue->state) {
    case 0:
        VecCopy(&gigue->m_390, &gigue->home_position);
        calc_velocity_toward_destination(gigue, gigue->position, gigue->m_390, gigue->m_3e4);
        gigue->m_388 &= ~0x40000;
        gigue->sub_8004292C();
        gigue->m_3ec = gigue->m_43c;
        gigue->requested_action = 7;
        gigue->state = 1;
    case 1:
        gigue->advance_animation();
        gigue->bodies[1].flags |= 1;
        gigue->m_3ec += -2.3f;
        height = gigue->m_3ec;
        if (height <= 0.0f) {
            gigue->m_3ec = 0.0f;
            gigue->actorFlags |= 0x800000;
            gigue->actorFlags &= ~0x1000000;
            gigue->y_speed = 0.0f;
            if (gigue->requested_action != 8) {
                gigue->state = -1;
                play_sound_effect(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A345), &gigue->position, 0, 0);
            }
        } else if (gigue->requested_action == 7) {
            if (height <= 2.3f * (40.0f + 1.0f / gigue->blend_speed)) {
                gigue->requested_action = 8;
            }
        } else {
            frame = (s32)gigue->frame;
            if ((frame == 0x14 || frame == 0x28) && gigue->check_vector_bit(&gigue->position) != 0) {
                spawn_particle_effect(&gigue->position, 0xF0);
            }
        }
        play_persistent_sound(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A819), gigue, &gigue->position, 0, 0);
        ((TObjPlayer *)gigue)->update_collisions();
        break;
    case -1:
        gigue->update_if_active(1);
        break;
    }
    apply_actor_gravity(gigue, 0, 0.0f);
}

void init__15TObjEneMe1GiGueFPv(TObjEneMe1GiGue *gigue) {
    u32 flags;

    switch (gigue->state) {
    case 0:
        gigue->m_388 |= 4;
        flags = gigue->actorFlags | 0x04000000;
        gigue->actorFlags = flags;
        gigue->requested_action = 0;
        ((TBoss3Volopt *)&gigue->m_2fc)->play_area_sound_effect();
        gigue->m_3fc.start_fade_in();
        gigue->state = 1;
    case 1:
        gigue->advance_animation();
        if (((TUnk_80494938 *)&gigue->m_3fc)->advance_toward_max() == 1) {
            gigue->state = -1;
            play_sound_effect(TObjEneMe1GiGue::remap_sound_id(gigue, 0x3A345), &gigue->position, 0, 0);
        }
        ((TObjPlayer *)gigue)->update_collisions();
        return;
    case -1:
        flags = gigue->m_388;
        gigue->m_388 = flags & ~5;
        gigue->actorFlags &= ~0x04000000;
        gigue->update_if_active(0);
        return;
    }
}

extern "C" {

void add_target_in_cone__15TObjEneMe1GiGueFPvPv(TObjEneMe1GiGue *gigue, TObjChara *target) {
    int angle;
    if (gigue->m_3c0 < 12 && target != NULL && (void *)target != (void *)gigue && !(target->actorFlags & 0x06000800)) {
        Vec v = target->position;
        subtract_vector(&v, &gigue->position);
        if (!(v.x * v.x + v.z * v.z > gigue->m_438 * gigue->m_438)) {
            angle = -(s32)(10430.38043493439 * atan2_float(v.z, v.x)) + 0x4000;
            if (angle_difference_abs(angle, gigue->rotation_y) <= gigue->m_434 / 2) {
                gigue->m_3c4[gigue->m_3c0++] = get_entity_id(target);
            }
        }
    }
}

s32 TObjEneMe1GiGue__sub_802CB10C(TObjEneMe1GiGue *gigue) {
    s32 i;
    gigue->m_3c0 = 0;
    for (i = 0; i < registered_player_count; i++) {
        TObjChara *player = (TObjChara *)get_player_data__10TObjPlayerFi(i);
        add_target_in_cone__15TObjEneMe1GiGueFPvPv(gigue, player);
    }
    return gigue->m_3c0;
}

void TObjEneMe1GiGue__sub_802CB03C(TObjEneMe1GiGue *gigue) {
    push_matrix_from(&identity_matrix);
    translate_matrix(0, gigue->position.x, gigue->m_3ec + (gigue->position.y + gigue->m_3e8), gigue->position.z);
    rotate_matrix_y(0, gigue->rotation_y);
    set_motion_packed_rotation();
    gigue->calc_joint_matrices(gigue->frame);
    clear_motion_packed_rotation();
    pop_matrix();
    gigue->get_anim_node_position(0, &gigue->m_3b4);
    gigue->get_anim_node_position(0x2A, &gigue->m_39c);
    gigue->get_anim_node_position(0x16, &gigue->m_3a8);
}

void TObjEneMe1GiGue::update_direction() {
    m_438 = ((AttackParams *)m_318)->get_attack_range();
    m_434 = ((AttackParams *)m_318)->get_attack_angle();
}

void TObjEneMe1GiGue::load_params() {
    lbl_805D6840 = get_gigue_float_parameter(this, 1);
    lbl_805D6844 = get_gigue_float_parameter(this, 2);
    lbl_805D6848 = get_gigue_float_parameter(this, 3);
    lbl_805D684C = get_gigue_float_parameter(this, 4);
    lbl_805D6850 = get_gigue_int_parameter(this, 0);
    lbl_805D6854 = get_gigue_int_parameter(this, 1);
    m_44c = (s32)(30.0f * (f32)get_gigue_int_parameter(this, 3));
    m_450 = get_gigue_int_parameter(this, 4);
}

#pragma pool_data off
void find_open_direction__15TObjEneMe1GiGueFPvPv(TObjEneMe1GiGue *gigue, Vec *dir) {
    f32 best;
    s32 ang;
    s32 best_ang;
    s32 i;
    CsnHit *hit;
    f32 d;
    ang = (s32)(10430.38043493439 * atan2_float(dir->x, dir->z));
    best = 0.0f;
    best_ang = ang;
    push_matrix_from(&identity_matrix);
    Vec v = {200.0f, 0.0f, 0.0f};
    rotate_matrix_y(0, ang);
    for (i = 0; i < 3; i++) {
        matrix_mult_vec(0, &v, &gigue->m_390);
        vec3_add_to(&gigue->m_390, (Vec *)&gigue->m_2fc);
        hit = csnVector((Vec *)&gigue->m_2fc, &gigue->m_390, -1);
        if (hit == NULL) {
            pop_matrix();
            return;
        }
        d = vec_xz_distance(&gigue->position, &hit->contact->point) - 20.0f;
        if (best < d) {
            best = d;
            best_ang = ang;
        }
        rotate_matrix_y(0, 0x5555);
        ang += 0x5555;
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    Vec w = {0.0f, 0.0f, 0.0f};
    w.x = best;
    rotate_matrix_y(0, best_ang);
    matrix_mult_vec(0, &w, &gigue->m_390);
    vec3_add_to(&gigue->m_390, (Vec *)&gigue->m_2fc);
    pop_matrix();
}
#pragma pool_data reset

s32 TObjEneMe1GiGue::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        sub_802CACD8();
        return 1;
    }
    return 0;
}

void TObjEneMe1GiGue::sub_802CACD8() {
    s32 flags = m_388;
    if (flags & 0x40000) {
        m_388 = flags & ~0x40000;
        VecCopy(&position, &home_position);
        project_actor_to_ground(this, &position, 0);
        return;
    }
    if ((s32)next_action == 7) {
        m_388 = flags & ~1;
        update_if_active(0);
    }
}

s32 TObjEneMe1GiGue::check_vector_bit(Vec *pos) {
    s32 *csnVectorUnder(Vec *, u32 *, s32, TObjEneMe1GiGue *);
    s32 *hit = csnVectorUnder(pos, (u32 *)&m_120, 5, this);
    if (hit == NULL) {
        return 0;
    }
    return (u32)__cntlzw(*hit & 4) >> 5;
}

BmlResource *TObjEneMe1GiGue::sub_802CAC80() { return TObjEneMe1GiGue__data_805D6838; }

}

Vec *TObjEneMe1GiGue::update_and_get_pos() {
    TObjEneMe1GiGue__sub_802CB03C(this);
    return &m_3b4;
}

s32 TObjEneMe1GiGue::sub_802CAC48() { return rotation_y; }

s32 TObjEneMe1GiGue::get_field_44c() { return m_44c; }

s32 TObjEneMe1GiGue::is_active_state() {
    s32 r = 0;
    s16 v = mode;
    if (v == 9) goto yes;
    if (v == 10) goto yes;
    if (v == 11) goto yes;
    if (v == 4) goto yes;
    if (v != 5) goto done;
yes:
    r = 1;
done:
    return (u8)r;
}

void TObjEneMe1GiGue::sub_802CABF4() { m_388 |= 0x80000; }

void TObjEneMe1GiGue::clear_flag388_bit80000() { m_388 &= ~0x80000; }

extern "C" {

f32 TObjEneMe1GiGue::receive_physical_attack(void *attacker, f32 power) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&m_2fc);
        set_state(10);
    } else {
        damage = TObjChara::receive_physical_attack(attacker, power);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_direct_attack(void *attacker, DirectAttackPayload hit, void *source, s32, s32) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&m_2fc);
        set_state(10);
    } else {
        damage = TObjChara::receive_direct_attack(attacker, hit, source, -1, -1);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_weapon_special_attack(void *attacker, void *weapon) {
    f32 damage = 0.0f;
    if (m_388 & 0x80000) {
        show_miss_popup(&m_2fc);
        set_state(10);
    } else {
        damage = TObjChara::receive_weapon_special_attack(attacker, weapon);
    }
    return damage;
}

}
