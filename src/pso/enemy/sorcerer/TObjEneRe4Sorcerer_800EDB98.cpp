#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/system/BmlResource.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/render/TUnk_80490470.h"

extern "C" {

void vfunc_106__18TObjEneRe4SorcererFv(u8 *arg0);
void vfunc_105__18TObjEneRe4SorcererFv(u8 *arg0);
s32 post_translate_matrix(void *);
s32 TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);
s32 scroll_strip_uvs(int, int, int);
s32 translate_matrix(int, f32, f32, f32);
s32 push_matrix();

extern u32 TObjEneRe4Sorcerer__uv_scroll_buffer;
extern s32 model_render_flags;

void TObjEneRe4Sorcerer::vfunc_106() {
    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        draw_ground_shadow(0, 0);
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        translate_matrix(0, 0.0f, 22.0f, 0.0f);
        rotate_matrix_y(0, rotation_y);
        m_3c0 = (s16)(m_3c0 + 5);
        scroll_strip_uvs(TObjEneRe4Sorcerer__uv_scroll_buffer, m_3c0, 0);
        m_3c4 += 0.01f;
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, m_3c4);
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(model);
        TParticleCtrl::end_effect_render();
        model_render_flags &= 0xFFFDFFFF;
        pop_matrix();
    }
}

void TObjEneRe4Sorcerer__sub_800EFE30(void);

void TObjEneRe4Sorcerer::vfunc_105() {
    if (get_target_info() != 0) {
        ((void (*)(void *))TObjEneRe4Sorcerer__sub_800EFE30)(this);
    }
}

}

#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TTecMegid.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecResta.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
f64 atan2_float(f32, f32);
s32 set_field_378__9TObjEneDDFl(void *, s32);
void TObjEneRe4Sorcerer__sub_800EF214(TObjEneRe4Sorcerer *self);
void *find_entity_by_id(u16 id);
extern const f64 TObjEneRe4Sorcerer__data_8043D408;
void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *arg0, s32 arg1);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update__15RenderFadeStateFv(int);
s32 defer_render__7TObjectFv(void *);
extern s32 TObjEneRe4Sorcerer__render_node_index;
extern s32 TObjEneRe4Sorcerer__saved_render_flags;
extern f32 TObjEneRe4Sorcerer__effect_render_scale;
extern s32 re4_sorcerer_render_node_ptr;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__18TObjEneRe4SorcererFv(u8 *arg0);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(TObjBase *object);
s32 *csnLookAt(s32 arg0, s32 arg1);
s32 enemy_bind_or_clear_target(void *, u16);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
int is_target_ranger(void *p);
s32 is_alive__8TObjBaseFv(void *);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
f32 horizontal_distance_squared(void *, void *);
s32 select_attack_target__18TObjEneRe4SorcererFiff(TObjEneRe4Sorcerer *self, f32 farg0, f32 farg1);
void scale_matrix(s32, s32, f32, f32, f32);

struct Params_800F0464 { s32 a, b, c, d; };

void queue_destruction__7TObjectFv(void *arg0);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void free_bin_model_request(void*, int);
s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
s32 TObjPlayer__sub_800A04F0(void *);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
int TObjEneDD__sub_800BA804(u16 arg0);
s32 init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int, int);
u32 vfunc_102__9TObjEneDDFv();
u32 vfunc_101__9TObjEneDDFPUc();
void invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
u32 load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
void TObjEneRe4Bit__sub_800EDAB0(void);
void TObjEneRe4Bit__sub_800EDAB4();
void TObjEneRe4Sorcerer__sub_800EE0F8(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE1CC(TObjEneRe4Sorcerer *self, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEC00(TObjEneRe4Sorcerer *self, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEDE4(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EEFE4(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__vt85(TObjEneRe4Sorcerer *self, u32 state, s32 reason);
void TObjEneRe4Sorcerer__sub_800EF7C8(TObjEneRe4Sorcerer *self);
void TObjEneRe4Sorcerer__sub_800EF844(TObjEneRe4Sorcerer *self);
void set_motion_by_state__18TObjEneRe4SorcererFPv(TObjEneRe4Sorcerer *self);
void TObjEneRe4Sorcerer__sub_800EF95C(TObjEneRe4Sorcerer *self, f32 speed);
void vfunc_102__18TObjEneRe4SorcererFv(u8 *arg0);
void vfunc_101__18TObjEneRe4SorcererFPUc(u8 *arg0);
void vfunc_88__18TObjEneRe4SorcererFv(void *arg0);
void vfunc_61__18TObjEneRe4SorcererFv(void);
void vfunc_62__18TObjEneRe4SorcererFv(u8 *arg0);
void vfunc_63__18TObjEneRe4SorcererFv(void* p);
void vfunc_28__18TObjEneRe4SorcererFv(void);
void run_task__18TObjEneRe4SorcererFv(u8 *arg0);
TObjEneRe4Sorcerer *__dt__18TObjEneRe4SorcererFv(TObjEneRe4Sorcerer *arg0, s16 arg1);
TObjEneRe4Sorcerer *TObjEneRe4Sorcerer__ct(TObjEneRe4Sorcerer *self, void *arg1, void *arg2);
void TBoss3Volopt__sub_800F059C(void);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2);
void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
s32 approach_angle_limited(s32, s32, s32);
s32 free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(void *, void *, int, int);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
s32 create_ex__11TTecGiBartaFPvPvPv(void *, void *, s32, s32);
void __destroy_arr(void *, void *, u32, u32);
void __construct_array(void *, void *, void *, int, int);
void vec3_add_to(void *, void *);
s32 subtract_vector(void *, void *);

extern s32 __dt__15RenderFadeStateFv[];
extern s32 __ct__15RenderFadeStateFv[];
extern Params_800F0464 re4_sorcerer_spawn_descriptor;
extern u8 lbl_8043D418[];
Vec lbl_80501070;
extern void *lbl_805D2AF0;
extern s32 lbl_805D52D0;
extern s32 TObjEneRe4Sorcerer__attack_params;
extern s32 TObjEneRe4Sorcerer__resistance_params;
extern s32 *sorcerer_behavior_params;
extern BmlResource *sorcerer_bml_resource;
extern void *tl_04;

extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFPl();
}
extern "C" {
void vfunc_84__9TObjEneDDFv();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_89__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void vfunc_91__9TObjEneDDFv();
}
extern "C" {
void vfunc_92__9TObjEneDDFv();
}
extern "C" {
void vfunc_93__9TObjEneDDFv();
}
extern "C" {
void vfunc_94__9TObjEneDDFv();
}
extern "C" {
void vfunc_95__9TObjEneDDFv();
}
extern "C" {
void vfunc_96__9TObjEneDDFv();
}
extern "C" {
void vfunc_97__9TObjEneDDFv();
}
extern "C" {
void vfunc_98__9TObjEneDDFv();
}
extern "C" {
void vfunc_99__9TObjEneDDFv();
}
extern "C" {
void vfunc_100__9TObjEneDDFv();
}
extern "C" {
int vfunc_104__12TObjEneDD_STFf(void *p);
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void vfunc_60__9TObjCharaFv();
}
extern "C" {
void vfunc_59__9TObjCharaFv();
}
extern "C" {
void vfunc_58__9TObjCharaFv();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
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
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFf();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
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
extern u8 lbl_8043D2F0[];
}
extern "C" {
extern u8 lbl_8043D308[];
}
extern "C" {
extern u8 lbl_8043D318[];
}
extern "C" {
extern u8 lbl_8043D330[];
}
extern "C" {
extern u8 lbl_8043D348[];
}
extern "C" {
extern u8 lbl_8043D360[];
}
extern "C" {
extern u8 lbl_8043D374[];
}
extern "C" {
extern u8 lbl_8043D38C[];
}
extern "C" {
extern u8 lbl_8043D3A0[];
}
extern "C" {
extern u8 lbl_8043D3B8[];
}
extern "C" {
extern u8 lbl_8043D3CC[];
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
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
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
void update_movement_status__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
extern void *bm_ene_re4_sorcerer_model_names[3];
extern void *bm_ene_re4_sorcerer_motion_names[9];
TObjEneRe4InitParams re4_sorcerer_init_params = {225.0f, 0.0f, 0x600};
void *re4_sorcerer_collision_body_part_table[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm_ene_re4_sorcerer_model_names[3] = {
    (void *)&lbl_8043D2F0, (void *)&lbl_8043D308, (void *)0x0,
};
void *bm_ene_re4_sorcerer_motion_names[9] = {
    (void *)&lbl_8043D318, (void *)&lbl_8043D330, (void *)&lbl_8043D348, (void *)&lbl_8043D360,
    (void *)&lbl_8043D374, (void *)&lbl_8043D38C, (void *)&lbl_8043D3A0, (void *)&lbl_8043D3B8,
    (void *)0x0,
};
void *bm_ene_re4_sorcerer_resource_descriptor[4] = {
    (void *)&lbl_8043D3CC, (void *)&bm_ene_re4_sorcerer_model_names, (void *)&bm_ene_re4_sorcerer_motion_names, (void *)0x20008,
};
void *re4_sorcerer_action_params[32] = {
    (void *)0x10000, (void *)0x7, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20002, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f19999a, (void *)0x80000000,
    (void *)0x30000, (void *)0x1, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x80000000,
};
void *__vt__18TObjEneRe4Sorcerer[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__18TObjEneRe4SorcererFv, (void *)&run_task__18TObjEneRe4SorcererFv,
    (void *)&render__18TObjEneRe4SorcererFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__18TObjEneRe4SorcererFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__18TObjEneRe4SorcererFv, (void *)&vfunc_62__18TObjEneRe4SorcererFv, (void *)&vfunc_63__18TObjEneRe4SorcererFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneRe4Sorcerer__vt85,
    (void *)&vfunc_88__18TObjEneRe4SorcererFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__18TObjEneRe4SorcererFPUc, (void *)&vfunc_102__18TObjEneRe4SorcererFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&vfunc_105__18TObjEneRe4SorcererFv, (void *)&vfunc_106__18TObjEneRe4SorcererFv,
};
#define re4_sorcerer_collision_body_part_table ((f32 *)re4_sorcerer_collision_body_part_table)
#define bm_ene_re4_sorcerer_resource_descriptor ((u8 *)bm_ene_re4_sorcerer_resource_descriptor)
#define __vt__18TObjEneRe4Sorcerer ((s32 *)__vt__18TObjEneRe4Sorcerer)

void TObjEneRe4Sorcerer::render() {
    s32 var_r30;
    s32 temp_r31;
    s32 var_r28;
    s32 var_r27;
    if (TObjPlayer::check_demo_mode() == 1) {
        vfunc_106();
        return;
    }
    var_r30 = 0;
    if (is_split_screen() != 0) {
        var_r30 = get_camera_mode__11TCameraCtrlFv();
    }
    var_r30 = (s32)&fades[var_r30];
    update__15RenderFadeStateFv(var_r30);
    temp_r31 = ((RenderFadeState *)var_r30)->updateFromCamera(&m_2fc);
    if (!(m_3c8 & 2)) {
        var_r28 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r28 = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        var_r28 = 1;
    } else {
        var_r28 = 0;
    }
    if (var_r28 != 0) {
        if (m_3c8 & 0x10) {
            draw_ground_shadow(0, 0);
        }
        update_secondary_light();
        TObjFish::set_global_param(texlist);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        scroll_strip_uvs(TObjEneRe4Sorcerer__uv_scroll_buffer, m_3c0, 0);
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, m_3c4);
        TObjPlayer::toggle_particle_effect();
        var_r27 = 1;
        if (m_3c8 & 4) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render__7TObjectFv(this) != 0) {
                var_r27 = 0;
            }
        } else if (temp_r31 != 0) {
            ((RenderFadeState *)var_r30)->set_flags_and_apply_damage_color();
            if (defer_render__7TObjectFv(this) != 0) {
                var_r27 = 0;
            }
        }
        if (var_r27 != 0) {
            push_matrix();
            post_translate_matrix(&position);
            translate_matrix(0, 0.0f, 22.0f, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneRe4Sorcerer__render_node_index = 0;
            TObjEneRe4Sorcerer__saved_render_flags = 0;
            TObjEneRe4Sorcerer__effect_render_scale = m_3f8;
            re4_sorcerer_render_node_ptr = (s32)bit_anchors;
            set_chunk_model_node_callback((s32)TObjEneRe4Sorcerer::step_effect_sequence);
            model_render_flags |= 0x01000000;
            if (var_r28 == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            model_render_flags &= 0xFEFFFFFF;
            set_chunk_model_node_callback((s32)NULL);
            pop_matrix();
        }
        if (m_3c8 & 4) {
            fade.clear_flag_and_notify();
        } else if (temp_r31 != 0) {
            ((RenderFadeState *)var_r30)->clear_flag_and_notify();
        }
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        TParticleCtrl::end_effect_render();
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneRe4Sorcerer::step_effect_sequence() {
    s32 t;
    switch (TObjEneRe4Sorcerer__render_node_index) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 0x34:
        f32 k = TObjEneRe4Sorcerer__effect_render_scale;
        t = model_render_flags;
        TObjEneRe4Sorcerer__saved_render_flags = t;
        model_render_flags = t & 0xFFFF7FFF;
        scale_matrix(0, t, k, k, k);
        TParticleCtrl::begin_effect_render();
        break;
    case 0x37:
        model_render_flags = TObjEneRe4Sorcerer__saved_render_flags;
        TObjPlayer::toggle_particle_effect();
        break;
    }
    TObjEneRe4Sorcerer__render_node_index += 1;
}
#pragma pop

void TObjEneRe4Sorcerer::handle_death_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 6;
        m_3c8 |= 6;
        refresh_and_send_entity_flags();
        m_4e4 = 0;
        fn_800D911C((Vec *)&m_2fc);
        TObjPlayer__sub_800A04F0(&fade);
        m_3f8 = 0.0f;
        play_sound_effect((void *)remap_sound_for_area(0x4003AD19), &position, 0, 0);
        return;
    case 0:
        advance_animation();
        if (fade.decay_value_toward_floor() != 0) {
            TObjPlayer::apply_effect_variant_b((s32)&position, 0);
            queue_destruction__7TObjectFv(this);
        }
    case 3:
    case 5:
        return;
    }
}

void TObjEneRe4Sorcerer__sub_800EE0F8(TObjEneRe4Sorcerer *self, s32 arg1) {
    Vec v;
    f32 c;
    switch (arg1) {
    case 4:
        self->requested_action = 5;
        self->advance_animation();
        break;
    case 3:
        if (self->get_flag_b4() != 0) {
            self->transition_enemy_state(self->m_378);
        }
        break;
    case 0:
        self->advance_animation();
        VecCopy(&v, (Vec *)&self->x_speed);
        c = normalize_vector_xz(&v);
        self->move_to_wall_clamped_destination(v.x, v.z, c);
        self->x_speed *= 0.8f;
        self->m_310 *= 0.8f;
        TObjEneRe4Sorcerer__sub_800EF214(self);
        break;
    case 5:
        self->clear_attack_receipts();
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE1CC(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 temp_r0;
    s32 var_r3;
    TObjEneRe4Bit *bit;

    bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[1]);
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        set_field_378__9TObjEneDDFl(self, 3);
        self->m_3c8 |= 0xA;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        return;
    case 3:
        if (self->m_4e8 == 5) {
            self->advance_anim_frame();
            self->transition_enemy_state(3);
        }
        return;
    case 0:
        self->advance_animation();
        self->m_4e4 = self->m_4e4 + 1;
        temp_r0 = self->m_4e8;
        switch (temp_r0) {
        case 0:
            if ((bit != NULL) && (bit->sub_800ED498() != 0)) {
                self->m_4e4 = 0;
                if (self->m_390->is_alive() != 0) {
                    if (self->m_390 != self) {
                        self->enemy_copy_target_destination();
                        self->update_velocity();
                        if (self->m_3ac >= 100.0f) {
                            self->m_4e8 = 4;
                        } else {
                            self->m_4e8 = 1;
                            self->requested_action = 1;
                            self->m_3c8 |= 8;
                            self->apply_mylla_effect();
                        }
                        self->rotation_y = (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(self->m_3a0.x, self->m_3a0.z));
                    } else {
                        self->m_4e8 = 1;
                        self->requested_action = 1;
                        self->m_3c8 |= 8;
                        self->apply_mylla_effect();
                    }
                } else {
                    self->m_4e8 = 4;
                }
            } else if ((f32)self->m_4e4 >= 240.0f) {
                self->m_4e8 = 5;
            }
            break;
        case 1:
            if ((bit != NULL) && (bit->sub_800ED498() == 0)) {
                self->m_4e8 = 5;
            } else if ((f32)self->m_4e4 >= 90.0f) {
                self->requested_action = 4;
                self->m_4e8 = 3;
            }
            play_persistent_sound(self->remap_sound_for_area(0x4003A814), (s32)self, (u32)&self->position, 0, 0);
            break;
        case 2:
        case 3:
            if ((self->frame >= 11.0f) && (temp_r0 == 3)) {
                if (bit != NULL) {
                    var_r3 = bit->get_state();
                } else {
                    var_r3 = 3;
                }
                switch (var_r3) {
                case 2:
                    self->m_4e8 = 2;
                    self->cast_resta();
                    break;
                case 3:
                    self->m_4e8 = 2;
                    break;
                }
            }
            if (self->get_flag_b4() != 0) {
                self->m_4e8 = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if ((f32)self->m_4e4 >= 60.0f) {
                self->m_4e8 = 5;
            }
            break;
        case 5:
            break;
        }
        self->vfunc_89();
        self->vfunc_88();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        self->m_3c8 &= 0xFFFFFFF7;
        enemy_clear_target__12TObjEneDD_STFUs(self);
        break;
    }
}

void TObjEneRe4Sorcerer::update_state_machine(s32 reason) {
    f32 *t = &m_4ec;
    s32 mask;
    s32 n;
    s32 i;
    TObjChara *p;
    s32 j;
    switch (reason) {
    case 4:
        set_field_378__9TObjEneDDFl(this, 6);
        vfunc_95();
        m_3c8 &= ~2;
        enemy_clear_target__12TObjEneDD_STFUs(this);
        init_float_params();
        if (vfunc_99() != 0) {
            m_4e4 = 3;
        } else {
            m_4e4 = 0;
        }
        m_4e8 = 0;
        *t = 0.0f;
        break;
    case 3:
        if (m_4e4 == 4) {
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        switch (m_4e4) {
        case 3:
            mask = 0;
            n = TLobby::get_game_mode();
            *t = 0.0f;
            for (i = 0; i < n; i++) {
                p = (TObjChara *)get_player_data__10TObjPlayerFi(i);
                mask |= update_farthest_target((s32)p, t);
            }
            if (mask != 0) {
                m_4e4 = 2;
            } else {
                m_4e4 = 0;
            }
            break;
        case 0:
            if (check_shield(this) != 0) {
                m_390 = this;
                m_4e4 = 2;
            } else {
                m_4e4 = 1;
            }
            break;
        case 1:
            j = TLobby::get_game_mode();
            n = j + TObjEneDD::get_enemy_count();
            *t = 0.0f;
            for (; j < n; j++) {
                p = (TObjChara *)get_player_data__10TObjPlayerFi(j);
                if (p == this) {
                    continue;
                }
                if (p != 0) {
                    s16 a = p->room;
                    if (a != room) {
                        continue;
                    }
                }
                update_farthest_target((s32)p, t);
            }
            m_4e4 = 2;
            break;
        case 2:
            if (m_390 != 0) {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 20.0f);
            } else {
                VecCopy(&m_394, &position);
                TObjEneRe4Sorcerer__sub_800EF95C(this, 160.0f);
            }
            m_4e4 = 4;
            break;
        }
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 temp_r0;
    s32 var_r3;
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[0]);
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        set_field_378__9TObjEneDDFl(self, 3);
        self->m_3c8 |= 0xA;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        return;
    case 3:
        if (self->m_4e8 == 5) {
            self->advance_anim_frame();
            self->m_3ec = self->m_3ec + 1;
            self->transition_enemy_state(3);
        }
        return;
    case 0:
        self->advance_animation();
        self->m_4e4 = self->m_4e4 + 1;
        temp_r0 = self->m_4e8;
        switch (temp_r0) {
        case 0:
            if ((bit != NULL) && (bit->sub_800ED498() != 0)) {
                self->m_4e4 = 0;
                if (self->try_attack(10000.0f, 10000.0f) == 0) {
                    self->m_4e8 = 4;
                } else {
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    if (self->m_3ac >= 100.0f) {
                        self->m_4e8 = 4;
                    } else {
                        self->m_4e8 = 1;
                        self->requested_action = 1;
                        self->m_3c8 |= 8;
                        self->set_photon_state();
                    }
                    self->rotation_y = (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(self->m_3a0.x, self->m_3a0.z));
                }
            } else if (self->m_4e4 >= 0xF0) {
                self->m_4e8 = 5;
            }
            self->turn_to_target();
            self->create_effect();
            break;
        case 1:
            if ((bit != NULL) && (bit->sub_800ED498() == 0)) {
                self->m_4e8 = 5;
            } else if (self->m_4e4 >= 0x5A) {
                self->requested_action = 3;
                self->m_4e8 = 3;
            }
            self->turn_to_target();
            self->create_effect();
            break;
        case 2:
        case 3:
            if ((self->frame >= 11.0f) && (temp_r0 == 3)) {
                if (bit != NULL) {
                    var_r3 = bit->get_state();
                } else {
                    var_r3 = 3;
                }
                switch (var_r3) {
                case 2:
                    self->m_4e8 = 2;
                    self->cast_technique();
                    break;
                case 3:
                    self->m_4e8 = 2;
                    break;
                }
            }
            if (self->get_flag_b4() != 0) {
                self->m_4e8 = 5;
                if (bit != NULL) {
                    bit->set_attack_flag();
                }
            }
            break;
        case 4:
            if (self->m_4e4 >= 0x3C) {
                self->m_4e8 = 5;
            }
            break;
        case 5:
            break;
        }
        self->vfunc_89();
        self->vfunc_88();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        return;
    case 5:
        if (bit != NULL) {
            bit->set_attack_flag();
        }
        self->m_3c8 &= 0xFFFFFFF7;
        break;
    }
}

void TObjEneRe4Sorcerer::state_wait(s32 arg1) {
    switch (arg1) {
    case 4:
        m_4e4 = 0;
        set_field_378__9TObjEneDDFl(this, 4);
        m_3c8 &= 0xFFFFFFFD;
        vfunc_95();
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return;
    case 3:
        if (try_attack(160000.0f, 160000.0f) != 0) {
            if (m_3ec & 1) {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 80.0f);
            } else {
                TObjEneRe4Sorcerer__sub_800EF95C(this, 30.0f);
            }
            transition_enemy_state(2);
            return;
        }
        if (m_4e4 > 0x5A) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        m_4e4 = m_4e4 + 1;
        break;
    }
}

s32 TObjEneRe4Sorcerer__sub_800EEC00(TObjEneRe4Sorcerer *self, s32 arg1) {
    f32 temp_f2;
    s32 i;
    switch (arg1) {
    case 4:
        set_field_378__9TObjEneDDFl(self, 3);
        self->vfunc_96();
        TObjEneRe4Sorcerer__sub_800EF844(self);
        self->m_3c8 |= 2;
        self->m_3c8 &= 0xFFFFFFF7;
        for (i = 0; i < 2; i++) {
            TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
            if (bit != NULL) {
                bit->set_flag_and_notify();
            }
        }
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        self->fade.reset_color();
        ((TBoss3Volopt *)&self->position)->play_area_variant_sound();
        break;
    case 3:
        if (self->m_4e4 >= 0x1E) {
            self->request_death_effect();
        }
        break;
    case 0:
        self->advance_animation();
        switch (self->m_4e8) {
        case 0:
            temp_f2 = self->m_3f8;
            if (temp_f2 > 0.0f) {
                self->m_3f8 = temp_f2 - 0.2f;
                if (self->m_3f8 < 0.0f) {
                    self->m_3f8 = 0.0f;
                    self->m_3c8 |= 4;
                    self->fade.reset_color();
                }
            } else if (self->fade.decay_value_toward_floor() != 0) {
                self->m_4e4 = 0;
                self->m_4e8 = 1;
                self->m_3c8 &= 0xFFFFFFF9;
            }
            TObjEneRe4Sorcerer__sub_800EF214(self);
            break;
        case 1:
            self->m_4e4 = self->m_4e4 + 1;
            break;
        }
        self->vfunc_102();
        break;
    case 5:
        self->m_3c8 &= 0xFFFFFFFB;
        self->m_3f8 = 1.0f;
        break;
    }
}


#pragma push
#pragma opt_common_subs off
s32 TObjEneRe4Sorcerer__sub_800EEDE4(TObjEneRe4Sorcerer *self, s32 arg1) {
    s32 i;
    TObjEneRe4Bit *bit;

    switch (arg1) {
    case 4:
        self->requested_action = 7;
        set_field_378__9TObjEneDDFl(self, 3);
        self->m_3c8 |= 0xE;
        self->vfunc_96();
        TObjEneRe4Sorcerer__sub_800EF844(self);
        self->fade.reset_obstruction_fade();
        for (i = 0; i < 2; i++) {
            if ((bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i])) != NULL) {
                bit->reset_transform();
                bit->clear_state_flag_0x10();
            }
        }
        self->m_3f8 = 0.0f;
        self->m_4e4 = 0;
        self->m_4e8 = 0;
        ((TBoss3Volopt *)&self->position)->play_area_variant_sound();
        break;
    case 3:
        if (self->m_4e4 >= 0x3C) {
            set_motion_by_state__18TObjEneRe4SorcererFPv(self);
        }
        break;
    case 0:
        if (*((f32 * (*)(void *))TBoss3Volopt__sub_800F059C)(&self->fade) >= -0.75f) {
            self->advance_animation();
            self->turn_to_target();
        }
        switch (self->m_4e8) {
        case 0:
            if (self->fade.advance_toward_max() != 0) {
                self->m_4e4 = 0;
                self->m_4e8 = 1;
                self->m_3c8 &= ~4;
                TObjEneRe4Sorcerer__sub_800EF7C8(self);
            }
            break;
        case 1:
            self->m_4e4 += 1;
            if (self->m_3f8 < 1.0f) {
                self->m_3f8 += 0.2f;
            }
            self->vfunc_89();
            break;
        }
        self->vfunc_102();
        TObjEneRe4Sorcerer__sub_800EF214(self);
        break;
    case 5:
        self->m_3f8 = 1.0f;
        self->m_3c8 &= ~4;
        break;
    }
}
#pragma pop

void TObjEneRe4Sorcerer__sub_800EEFE4(TObjEneRe4Sorcerer *self, s32 arg1) {
    switch (arg1) {
    case 4:
        set_field_378__9TObjEneDDFl(self, 1);
        VecCopy(&self->position, &self->home_position);
        VecCopy(&self->prev_position, &self->home_position);
        VecCopy((Vec *)&self->m_2fc, &self->home_position);
        self->vfunc_95();
        return;
    case 3:
        if (self->try_attack(160000.0f, 62500.0f) != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->m_3f0 = (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(-self->m_3a0.x, -self->m_3a0.z));
            TObjEneRe4Sorcerer__sub_800EF95C(self, 50.0f);
            self->transition_enemy_state(2);
        }
    case 5:
        return;
    case 0:
        self->vfunc_88();
        break;
    }
}

s32 TObjEneRe4Sorcerer::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        m_4e4 = 0;
        break;
    case 3:
        if (m_4e4 >= 2) {
            transition_enemy_state(1);
        }
        break;
    case 5:
        break;
    case 0:
        m_4e4 = m_4e4 + 1;
        break;
    }
}

void TObjEneRe4Sorcerer__vt85(TObjEneRe4Sorcerer *self, u32 state, s32 reason) {
    switch (state) {
    case 0:
        self->handle_state(reason);
        return;
    case 1:
        TObjEneRe4Sorcerer__sub_800EEFE4(self, reason);
        return;
    case 2:
        TObjEneRe4Sorcerer__sub_800EEDE4(self, reason);
        return;
    case 3:
        TObjEneRe4Sorcerer__sub_800EEC00(self, reason);
        return;
    case 4:
        self->state_wait(reason);
        return;
    case 5:
        TObjEneRe4Sorcerer__sub_800EE7DC(self, reason);
        return;
    case 6:
        self->update_state_machine(reason);
        return;
    case 7:
        TObjEneRe4Sorcerer__sub_800EE1CC(self, reason);
        return;
    case 8:
        TObjEneRe4Sorcerer__sub_800EE0F8(self, reason);
        return;
    case 9:
        self->handle_death_state(reason);
    default:
        return;
    }
}

void TObjEneRe4Sorcerer__sub_800EF214(TObjEneRe4Sorcerer *self) {
    play_persistent_sound(self->remap_sound_for_area(0x4003A81D), (s32)self, (u32)&self->position, 0, 0);
}

void TObjEneRe4Sorcerer::create_effect() {
    if (m_3e8 == 0) {
        play_persistent_sound(remap_sound_for_area(0x4003A812), (s32)this, (u32)&position, 0, 0);
        return;
    }
    play_persistent_sound(remap_sound_for_area(0x4003AB13), (s32)this, (u32)&position, 0, 0);
}

s32 TObjEneRe4Sorcerer::cast_resta() {
    Vec *var_r31;

    if (m_390->is_alive() != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            var_r31 = bit->get_spell_data();
        } else {
            var_r31 = &position;
        }
        TTecResta::create(this, var_r31, (void *)TObjEneDD::clamp_frame_index(sorcerer_behavior_params[8]));
        return 1;
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::cast_technique() {
    Vec v;
    s32 frame;
    Vec *src;
    if (transform_relative_position__9TObjEneDDFPv(this, m_390) != 0) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            src = bit->get_spell_data();
        } else {
            src = &position;
        }
        if (m_3e8 == 0) {
            fn_80044330(&targets);
            targets.count = 1;
            targets.records[0].id = get_entity_id(m_390);
            targets.records[0].flag = 0;
            if (TObjEneDD::check_v2_mode() != 0) {
                TTecGrants::create(this, src, &targets, (void *)TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else if (TLobby::get_instance() == 1) {
                ((TTecGiZonde *)this)->create(src, &targets, (void *)TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            } else {
                ((TTecRaFoie *)this)->create_ex(src, &targets, (void *)TObjEneDD::clamp_frame_index(sorcerer_behavior_params[6]));
            }
        } else if (TObjEneDD::check_v2_mode() != 0) {
            TTecMegid::create((s32)this, (s32)src, (s32)&m_390->position, TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]));
        } else {
            VecCopy(&v, &m_390->position);
            subtract_vector(&v, src);
            frame = TObjEneDD::clamp_frame_index(sorcerer_behavior_params[7]);
            create_ex__11TTecGiBartaFPvPvPv(this, src, (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(v.x, v.z)), frame);
        }
        return 1;
    }
    return 0;
}

void TObjEneRe4Sorcerer::turn_to_target() {
    enemy_copy_target_destination();
    update_velocity();
    rotation_y = approach_angle_limited(rotation_y, (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(m_3a0.x, m_3a0.z)), 0xA00);
}

void TObjEneRe4Sorcerer::calc_orb_positions() {
    f32 temp_f2;
    f32 temp_f31;

    temp_f31 = 15.0f * cos_table_lookup(rotation_y);
    temp_f2 = 15.0f * -sin_table_lookup(rotation_y);
    bit_anchors[1].x = position.x + temp_f31;
    bit_anchors[1].y = 18.0f + position.y;
    bit_anchors[1].z = position.z + temp_f2;
    bit_anchors[0].x = position.x - temp_f31;
    bit_anchors[0].y = 18.0f + position.y;
    bit_anchors[0].z = position.z - temp_f2;
}

void TObjEneRe4Sorcerer::apply_mylla_effect() {
    TObjEneRe4Bit *bit;
    bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[1]);
    if (bit != NULL) {
        bit->set_state_flag_and_mode(2);
    }
}

void TObjEneRe4Sorcerer::set_photon_state() {
    TObjEneRe4Bit *bit;
    if (m_3e8 == 0) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(0);
        }
    } else {
        bit = (TObjEneRe4Bit *)find_entity_by_id(bit_ids[0]);
        if (bit != NULL) {
            bit->set_state_flag_and_mode(1);
        }
    }
}

s32 TObjEneRe4Sorcerer::update_farthest_target(s32 item_pro_shield, f32 *arg2) {
    f32 temp_f1;
    if (((TObjChara *)item_pro_shield)->is_alive() != 0 && check_shield((TObjChara *)item_pro_shield) != 0) {
        temp_f1 = horizontal_distance_squared(&position, &((TObjChara *)item_pro_shield)->position);
        if ((temp_f1 <= 40000.0f) && (temp_f1 > *arg2)) {
            *arg2 = temp_f1;
            m_38c = get_entity_id((TObjChara *)item_pro_shield);
            m_390 = (TObjChara *)item_pro_shield;
            return 1;
        }
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::check_shield(TObjChara *target) {
    if (TObjEneDD::check_v2_mode() != 0) {
        return target->hp < ((TItemProShield *)target)->get_field_2b8();
    }
    return target->hp < (((TItemProShield *)target)->get_field_2b8() / 4);
}

void TObjEneRe4Sorcerer__sub_800EF7C8(TObjEneRe4Sorcerer *self) {
    s32 i;
    self->vfunc_92();
    self->vfunc_93();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->call_vt_90_91();
        }
    }
}

void TObjEneRe4Sorcerer__sub_800EF844(TObjEneRe4Sorcerer *self) {
    s32 i;
    self->vfunc_91();
    self->vfunc_94();
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit *bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->invoke_state_callbacks();
        }
    }
}

void TObjEneRe4Sorcerer::advance_anim_frame() {
    m_3e8 = m_3e8 + 1;
    if (m_3e8 >= 3) {
        m_3e8 = 0;
    }
}

void TObjEneRe4Sorcerer::request_death_effect() {
    if (m_3e8 != 2) {
        transition_enemy_state(4);
        return;
    }
    transition_enemy_state(6);
}

void set_motion_by_state__18TObjEneRe4SorcererFPv(TObjEneRe4Sorcerer *self) {
    if (self->m_3e8 != 2) {
        self->transition_enemy_state(5);
        return;
    }
    self->transition_enemy_state(7);
}

void TObjEneRe4Sorcerer__sub_800EF95C(TObjEneRe4Sorcerer *self, f32 speed) {
    s32 i;
    Vec out;
    Vec v;
    Vec t;
    TObjEneRe4Bit *bit;
    self->enemy_copy_target_destination();
    self->update_velocity();
    v.x = speed * sin_table_lookup(self->m_3f0);
    v.y = 0.0f;
    v.z = speed * cos_table_lookup(self->m_3f0);
    vec3_add_to(&v, &self->m_394);
    subtract_vector(&v, &self->position);
    speed = normalize_vector_xz(&v);
    calc_wall_clamped_destination(self, &out, v.x, v.z, speed);
    t.x = out.x;
    t.y = 10.0f + out.y;
    t.z = out.z;
    if (csnVectorUnder((s32)&t, (u32 *)&self->m_120, 0xE0) == 0) {
        VecCopy(&self->position, &out);
    }
    self->vfunc_102();
    VecCopy(&self->prev_position, &self->position);
    self->update_collision_center();
    self->rotation_y = self->m_3f0 + 0x8000;
    self->calc_orb_positions();
    self->m_3f0 += 0x2AAA;
    self->transform_part_positions();
    for (i = 0; i < 2; i++) {
        bit = (TObjEneRe4Bit *)find_entity_by_id(self->bit_ids[i]);
        if (bit != NULL) {
            bit->reset_transform();
        }
    }
}

s32 TObjEneRe4Sorcerer::try_attack(f32 farg0, f32 farg1) {
    if (tick_period_counter((s32)this, &m_3b0, 0x1E) != 0) {
        return select_attack_target__18TObjEneRe4SorcererFiff(this, farg0, farg1);
    }
    if (enemy_has_live_target() != 0) {
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs(this);
    return 0;
}

#pragma push
#pragma opt_loop_invariants off
s32 select_attack_target__18TObjEneRe4SorcererFiff(TObjEneRe4Sorcerer *self, f32 farg0, f32 farg1) {
    f32 d;
    f32 best;
    s32 id;
    TObjChara *p;
    s32 n;
    int i;
    void *o1;
    void *o2;
    if (self->vfunc_99() != 0) {
        best = farg1;
        id = 0xFFFF;
        o1 = find_entity_by_id(self->bit_ids[0]);
        o2 = find_entity_by_id(self->bit_ids[1]);
        p = (TObjChara *)TLobby::get_game_mode();
        n = (s32)p + TObjEneDD::get_enemy_count();
        for (i = (s32)p; i < n; i++) {
            p = (TObjChara *)get_player_data__10TObjPlayerFi(i);
            if (p != self && p != o1 && p != o2 && is_alive__8TObjBaseFv(p) != 0) {
                d = horizontal_distance_squared(&self->m_2fc, &p->position);
                if (d < best && csnLookAt((s32)&self->m_2fc, (s32)&p->m_2fc) == 0) {
                    id = ((s32 (*)(void *))get_entity_id)(p);
                    best = d;
                }
            }
        }
        if (((s32 (*)(void *, s32))enemy_bind_or_clear_target)(self, id) != 0) {
            return 1;
        }
    }
    {
    TObjChara *q; s32 tA; s32 tB; s32 j; s32 m; f32 e;
    tA = 0xFFFF;
    tB = tA;
    m = TLobby::get_game_mode();
    for (j = 0; j < m; j++) {
        q = (TObjChara *)get_player_data__10TObjPlayerFi(j);
        if (is_alive__8TObjBaseFv(q) != 0) {
            e = horizontal_distance_squared(&self->m_2fc, &q->m_2fc);
            if (is_target_ranger(q) != 0) {
                if (e < farg0 && transform_relative_position__9TObjEneDDFPv(self, q) != 0) {
                    farg0 = e;
                    tA = ((s32 (*)(void *))get_entity_id)(q);
                }
            } else if (e < farg1 && transform_relative_position__9TObjEneDDFPv(self, q) != 0) {
                farg1 = e;
                tB = ((s32 (*)(void *))get_entity_id)(q);
            }
        }
    }
    if ((u16)tA != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(self, tA);
        return 1;
    }
    if ((u16)tB != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(self, tB);
        return 1;
    }
    }
    enemy_clear_target__12TObjEneDD_STFUs(self);
    return 0;
}
#pragma pop

u8 *TObjEneRe4Sorcerer::vfunc_102() {
    if (vfunc_102__9TObjEneDDFv() == 0U) {
        this->m_3c8 = (s32) (this->m_3c8 & 0xFFFFFFEF);
        return;
    }
    this->m_3c8 = (s32) (this->m_3c8 | 0x10);
}

u8 *TObjEneRe4Sorcerer::vfunc_101(u8 *) {
    if (vfunc_101__9TObjEneDDFPUc() == 0U) {
        this->m_3c8 = (s32) (this->m_3c8 & 0xFFFFFFEF);
        return;
    }
    this->m_3c8 = (s32) (this->m_3c8 | 0x10);
}

void TObjEneRe4Sorcerer__sub_800EFE30(void) {  }

void TObjEneRe4Sorcerer::vfunc_88() {
    bodies->offset.y = 22.0f;
}

void TObjEneRe4Sorcerer::update_collision_center() {
    m_2fc = position.x;
    m_300 = 22.0f + position.y;
    m_304 = position.z;
    VecCopy(&center, (Vec *)&m_2fc);
}

void TObjEneRe4Sorcerer::vfunc_61() {  }

void TObjEneRe4Sorcerer::vfunc_62() {
    if (mode != 8) {
        if (!(m_3c8 & 8)) {
            transition_enemy_state(8);
            return;
        }
        clear_attack_receipts();
    }
}

void TObjEneRe4Sorcerer::vfunc_63() {
    if (mode != 9) {
        transition_enemy_state(9);
    }
}

void TObjEneRe4Sorcerer::vfunc_28() {  }

void TObjEneRe4Sorcerer::run_task() {
    s32 i;
    void *p;
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_105();
        return;
    }
    if (vfunc_83() != 4) {
        if (TObjEneDD__sub_800BA804(m_38c) != 0 && find_entity_by_id(m_38c) == NULL) {
            enemy_clear_target__12TObjEneDD_STFUs(this);
        }
        vfunc_85();
        calc_orb_positions();
        m_3c0 += 5;
        m_3c0 = (u8)m_3c0;
        m_3c4 += 0.01f;
        if (m_3c4 >= 1.0f) {
            m_3c4 -= 1.0f;
        }
    } else {
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(bit_ids[i])) != NULL) {
                ((TObjEneRe4Bit *)p)->set_flag3cc_bit2000();
            }
        }
    }
    update_collision_center();
    submit_default_cursor_candidate();
    vfunc_100();
}

TObjEneRe4Sorcerer *__dt__18TObjEneRe4SorcererFv(TObjEneRe4Sorcerer *arg0, s16 arg1) {
    s32 i;
    void *p;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjEneRe4Sorcerer;
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(arg0->bit_ids[i])) != NULL) {
                queue_destruction__7TObjectFv(p);
            }
            arg0->bit_ids[i] = 0xFFFF;
        }
        free_collision_body_parts(arg0);
        __destroy_arr(arg0->fades, __dt__15RenderFadeStateFv, sizeof(RenderFadeState), 4);
        __dt__13TUnk_80490470Fv(&arg0->fade, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneRe4Sorcerer::init_enemy() {
    s32 i;
    u16 id;
    s32 t;
    s32 n;
    BmlModelEntry *models;

    init_position_vectors();
    model = (void *)sorcerer_bml_resource->models->model;
    models = sorcerer_bml_resource->models;
    texlist = models->m_c;
    init_model__9TObjEneDDFP13CollisionBodyl(this, re4_sorcerer_collision_body_part_table, 1, (int)models);
    set_field_d8((s32)re4_sorcerer_action_params);
    set_field_dc((s32)sorcerer_bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp((u8 *)lbl_805D52D0, (u8 *)TObjEneRe4Sorcerer__attack_params, (u8 *)TObjEneRe4Sorcerer__resistance_params);
    set_state_8();
    movementParameters = &re4_sorcerer_init_params;
    initialize_enemy_state(0x1F);
    m_37c = 15.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    set_active();
    mode = 0;
    dispatch_action(mode, 4);
    m_3c0 = 0;
    m_3c4 = 0.0f;
    m_3c8 = 0;
    m_3c8 &= ~2;
    for (i = 0; i < 2; i++) {
        VecCopy(&bit_anchors[i], &position);
    }
    id = entity_id + 1;
    n = set_index + 1;
    bit_ids[0] = id;
    create_disabled(&bit_anchors[0], id++, n++);
    bit_ids[1] = id;
    create_enabled(&bit_anchors[1], id, n);
    m_3e8 = 0;
    m_3ec = 0;
    m_3f0 = 0;
    m_3f4 = m_2cc;
    m_3f8 = 1.0f;
    fade.reset_obstruction_fade();
    fn_80044330(&targets);
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
    TObjEneRe4Sorcerer__sub_800EF844(this);
}
#pragma pop

TObjEneRe4Sorcerer *TObjEneRe4Sorcerer__ct(TObjEneRe4Sorcerer *self, void *arg1, void *arg2) {
    __ct__12TObjEneDD_STFP7TObject(self);
    *(s32 **)((s8 *)self + 0x18) = __vt__18TObjEneRe4Sorcerer;
    __ct__13TUnk_80490470Fv(&self->fade);
    ((TObjPlayer *)&self->targets)->construct_target_cursor_records();
    __construct_array(self->fades, __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, sizeof(RenderFadeState), 4);
    *(void **)((s8 *)self + 0x0) = lbl_805D2AF0;
    invoke_initialization_hook__9TObjEneDDFPv(self, arg2);
    ((void (*)(void *))TObjEneRe4Sorcerer__sub_800EFE30)(self);
    self->init_enemy();
    return self;
}

void TObjEneRe4Sorcerer::free_bits() {
    if ((u32) TObjEneRe4Sorcerer__uv_scroll_buffer != 0U) {
        destroy_buffer_pair((void *)TObjEneRe4Sorcerer__uv_scroll_buffer, 1);
        TObjEneRe4Sorcerer__uv_scroll_buffer = 0U;
    }
    TObjEneRe4Bit__sub_800EDAB0();
    if ((u32) sorcerer_bml_resource != 0U) {
        free_bin_model_request((void*)sorcerer_bml_resource, 1);
        sorcerer_bml_resource = 0U;
    }
}

TObjEneRe4Sorcerer *TObjEneRe4Sorcerer::create() {
    TObjEneRe4Sorcerer *o = (TObjEneRe4Sorcerer *)__nw__7TObjectFUl(0x4F0);
    if (o != NULL) {
        o = TObjEneRe4Sorcerer__ct(o, tl_04, this);
    }
    return o;
}

void TObjEneRe4Sorcerer::load_resources() {
    u32 r;
    lbl_80501070.x = 0.0f;
    lbl_80501070.y = 0.0f;
    lbl_80501070.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource_named(bm_ene_re4_sorcerer_resource_descriptor, lbl_8043D418);
    } else {
        sorcerer_bml_resource = (BmlResource *)load_enemy_bml_resource(bm_ene_re4_sorcerer_resource_descriptor);
    }
    lbl_805D52D0 = register_boss__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__attack_params = dispatch_shared_handler_b__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__resistance_params = register_object__6TLobbyFl(0xA);
    sorcerer_behavior_params = (s32 *)dispatch_shared_handler_a__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__render_node_index = 0;
    TObjEneRe4Sorcerer__saved_render_flags = 0;
    TObjEneRe4Sorcerer__effect_render_scale = 0.0f;
    re4_sorcerer_render_node_ptr = 0;
    TObjEneRe4Bit__sub_800EDAB4();
    r = (u32) (int)::operator new(0x14);
    if (r != 0) {
        r = (u32) ((TLobby *)r)->alloc_tables(sorcerer_bml_resource->models->model, 2);
    }
    TObjEneRe4Sorcerer__uv_scroll_buffer = r;
    Params_800F0464 p = re4_sorcerer_spawn_descriptor;
    p.a = (s32)sorcerer_bml_resource->motions;
    TLobby::spawn_npc_enemy((s16)0x2A, sorcerer_bml_resource->models->model, (NJS_TEXLIST *)sorcerer_bml_resource->models->m_c, &p, re4_sorcerer_collision_body_part_table[3], 15.0f);
}

void TBoss3Volopt__sub_800F059C(void) {  }
}

extern "C" {
s32 lbl_805D52D0;
s32 TObjEneRe4Sorcerer__attack_params;
s32 TObjEneRe4Sorcerer__resistance_params;
s32 *sorcerer_behavior_params;
BmlResource *sorcerer_bml_resource;
s32 TObjEneRe4Sorcerer__render_node_index;
s32 TObjEneRe4Sorcerer__saved_render_flags;
f32 TObjEneRe4Sorcerer__effect_render_scale;
s32 re4_sorcerer_render_node_ptr;
u32 TObjEneRe4Sorcerer__uv_scroll_buffer;
}
