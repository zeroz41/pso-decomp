#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/vector.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest_CarryFly.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/enemy/fly/TObjEneBm3FlyNest.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"

extern "C" {

void has_flag_0x800__9TObjCharaFv();
void test_flag30_512__9TObjCharaFv();
void test_flag_1000__9TObjCharaFv();
void test_flag_256__9TObjCharaFv();

struct VBase_18 { char pad[0x18]; };

struct VObj_18_p5 : VBase_18 {
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual s32 m102();
};

void free_bin_model_request(void*, int);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void render_with_state_debug__17TObjEneBm3FlyNestFv(u8 *arg0);
void init__17TObjEneBm3FlyNestFPv(void *);
void vfunc_88__17TObjEneBm3FlyNestFv(void* p);
void vfunc_61__17TObjEneBm3FlyNestFv(void);
void vfunc_62__17TObjEneBm3FlyNestFv(void *arg0);
void vfunc_63__17TObjEneBm3FlyNestFv(void *arg0);
void vfunc_28__17TObjEneBm3FlyNestFv(void);
TObjEneBm3FlyNest *TObjEneBm3FlyNest__sub_800B3E40(TObjEneBm3FlyNest *nest, s16 flag);
s32 is_main_phase_15__9TObjEneDDFv();
void get_camera_ctrl__9TObjEneDDFv(const Vec *origin, Vec *out);
s32 get_random_scaled__9TObjEneDDFv(void *);
s32 noop__12TBoss8DragonFv(void *);
s32 TBoss8Dragon__sub_800BB7D4(void *, s32);
s32 pack_debug_text_position(s32, s32);
BmlResource *load_enemy_bml_resource_named(BmlResourceDescriptor *descriptor, const char *filename);
BmlResource *load_enemy_bml_resource(BmlResourceDescriptor *descriptor);
void *__dt__9TObjEneDDFv(void *arg0, s16 arg1);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
s32 set_field_e4__10TObjPlayerFll(void *, int, f32);
void spawn_dead_spot_scale15(s32 point, s32 delay);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __destroy_arr(void *, void *, u32, u32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void set_global_param__8TObjFishFl(s32);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

void vfunc_6__8TObjBaseFPsl();
void vfunc_103__9TObjEneDDFPUc();
void vfunc_79__9TObjEneDDFPl();
void vfunc_83__9TObjEneDDFv();
void vfunc_84__9TObjEneDDFv();
void vfunc_85__9TObjEneDDFv();
void vfunc_86__9TObjEneDDFv();
void vfunc_89__9TObjEneDDFv();
void vfunc_90__9TObjEneDDFv();
void vfunc_91__9TObjEneDDFv();
void vfunc_92__9TObjEneDDFv();
void vfunc_93__9TObjEneDDFv();
void vfunc_94__9TObjEneDDFv();
void vfunc_95__9TObjEneDDFv();
void vfunc_96__9TObjEneDDFv();
void vfunc_97__9TObjEneDDFv();
void vfunc_98__9TObjEneDDFv();
void vfunc_99__9TObjEneDDFv();
void vfunc_100__9TObjEneDDFv();
void vfunc_101__9TObjEneDDFPUc();
void vfunc_102__9TObjEneDDFv();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
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
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
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
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render_shadows__17TObjEneBm3FlyNestFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
void update_actor_ground_y__9TObjCharaFv();
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
extern const char lbl_8043B120[];
extern const char lbl_8043B130[];
extern const char lbl_8043B140[];
extern const char lbl_8043B158[];
extern const char lbl_8043B170[];
extern const char lbl_8043B184[];
extern const char lbl_8043B19C[];
extern const char lbl_8043B1B0[];
extern const char lbl_8043B1C4[];
extern const char lbl_8043B1DC[];
extern const char lbl_8043B1F4[];
extern const char lbl_8043B20C[];
extern const char lbl_8043B220[];
extern const char lbl_8043B238[];
extern const char lbl_8043B24C[];
extern const char lbl_8043B264[];
extern const char lbl_8043B27C[];
extern const char lbl_8043B290[];
Bm3FlyMovementParameters bm3_fly_nest_params = {
    225.0f, 0.0f, 0x600, { 0, 0, 0, 0 },
};
CollisionBody bm3_flynest_collider_params[1] = {
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003},
};
const char *bm_ene_bm3_fly_model_names[3] = { lbl_8043B120, lbl_8043B130, NULL };
const char *bm_ene_bm3_fly_motion_names[16] = { lbl_8043B140, lbl_8043B158, lbl_8043B170, lbl_8043B184, lbl_8043B19C, lbl_8043B1B0, lbl_8043B1C4, lbl_8043B1DC, lbl_8043B1F4, lbl_8043B20C, lbl_8043B220, lbl_8043B238, lbl_8043B24C, lbl_8043B264, lbl_8043B27C, NULL };
BmlResourceDescriptor bm3_fly_nest_resource_desc = { lbl_8043B290, bm_ene_bm3_fly_model_names, bm_ene_bm3_fly_motion_names, 2, 15 };
TObjMotionAction bm3_flynest_hit_action_table[10] = {
    { 1, 0, 0xE, 0.3f, 0x0 },
    { 3, 0, 0x9, 0.7f, 0x0 },
    { 3, 0, 0x2, 1.0f, 0x0 },
    { 3, 0, 0x5, 0.5f, 0x0 },
    { 1, 0, 0x8, 0.3f, 0x0 },
    { 3, 0, 0x7, 0.7f, 0x0 },
    { 3, 0, 0x6, 1.0f, 0x0 },
    { 3, 0, 0x4, 0.3f, 0x0 },
    { 1, 0, 0xD, 0.3f, 0x0 },
    { 3, 0, 0xB, 0.2f, 0x0 },
};
void *lbl_80491EE4[106] = {
    0, 0, (void *)TObjEneBm3FlyNest__sub_800B3E40, (void *)run_task__17TObjEneBm3FlyNestFv,
    (void *)render__17TObjEneBm3FlyNestFv, (void *)render_shadows__17TObjEneBm3FlyNestFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv, (void *)get_center__9TObjCharaFv, (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__14TObjCollidableFl, (void *)add_actor_exp__9TObjCharaFl, (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv, (void *)update_actor_ground_y__9TObjCharaFv, (void *)vfunc_18__9TObjCharaFPUc, (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf, (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)receive_physical_attack__9TObjCharaFPvf, (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv, (void *)apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)try_start_action__9TObjCharaFll, (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__17TObjEneBm3FlyNestFv, (void *)vfunc_29__9TObjCharaFv, (void *)is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv, (void *)vfunc_37__9TObjCharaFv, (void *)update_flag30_timer__9TObjCharaFv, (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv, (void *)update_attack_stat_status__9TObjCharaFv, (void *)update_defense_stat_status__9TObjCharaFv, (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv, (void *)apply_paralysis__9TObjCharaFv, (void *)apply_slow_status__9TObjCharaFv, (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl, (void *)apply_shock_status__9TObjCharaFv, (void *)clear_harmful_statuses__9TObjCharaFv, (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv, (void *)cure_poison_ailment__9TObjCharaFv, (void *)cure_paralysis__9TObjCharaFv, (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf, (void *)apply_anti_technique__9TObjCharaFl, (void *)vfunc_58__9TObjCharaFv, (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv, (void *)vfunc_61__17TObjEneBm3FlyNestFv, (void *)vfunc_62__17TObjEneBm3FlyNestFv, (void *)vfunc_63__17TObjEneBm3FlyNestFv,
    (void *)reset_pose__9TObjCharaFv, (void *)get_anim_node_position__9TObjCharaFlP3Vec, (void *)vfunc_66__9TObjCharaFv, (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl, (void *)apply_switch_attack__9TObjCharaFv, (void *)enemy_spawn_jellen_effect__9TObjCharaFv, (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv, (void *)recalc_stats__9TObjCharaFv, (void *)vfunc_74__9TObjEnemyFl, (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf, (void *)vfunc_77__9TObjCharaFv, (void *)vfunc_78__9TObjCharaFl, (void *)vfunc_79__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv, (void *)vfunc_83__9TObjEneDDFv,
    (void *)vfunc_84__9TObjEneDDFv, (void *)vfunc_85__9TObjEneDDFv, (void *)vfunc_86__9TObjEneDDFv, (void *)dispatch_state__17TObjEneBm3FlyNestFiUii,
    (void *)vfunc_88__17TObjEneBm3FlyNestFv, (void *)vfunc_89__9TObjEneDDFv, (void *)vfunc_90__9TObjEneDDFv, (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv, (void *)vfunc_93__9TObjEneDDFv, (void *)vfunc_94__9TObjEneDDFv, (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv, (void *)vfunc_97__9TObjEneDDFv, (void *)vfunc_98__9TObjEneDDFv, (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv, (void *)vfunc_101__9TObjEneDDFPUc, (void *)vfunc_102__9TObjEneDDFv, (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)init__17TObjEneBm3FlyNestFPv, (void *)render_with_state_debug__17TObjEneBm3FlyNestFv,
};
extern const s32 bm3_fly_nest_attachment_sample_table[8];
extern const Bm3FlyAnimationBinding bm3_flynest_anim_binding;
extern Vec lbl_8043B304[];
extern Vec lbl_8043B310;
extern const Vec lbl_8043B31C;
extern const char lbl_8043B328[];
extern const char lbl_8043B338[];
extern const char lbl_8043B348[];
extern const char lbl_8043B358[];
extern const char lbl_8043B368[];
extern const f64 lbl_8043B398[];
typedef struct Ctl_800B47C4 {
    f32 *pv;
    s32 *pc;
    s32 d;
    s32 e;
    s32 f;
} Ctl_800B47C4;
Vec TObjEneBm3FlyNest__attachment_sample_origin;
f32 fly_nest_vertex_table[6];
__declspec(section ".data") s32 lbl_80500B24[2];
Ctl_800B47C4 lbl_80500B2C;
extern s32 debug_chunk_object;
extern const char *TObjEneBm3FlyNest_CarryFly__name;
u8 *lbl_805D50F8;
u8 *lbl_805D50FC;
u8 *lbl_805D5100;
void *lbl_805D5104;
BmlResource *lbl_805D5108;
s32 lbl_805D510C;
Vec *TObjEneBm3FlyNest_attachment_point_ptr;
Vec *lbl_805D5114;
s32 bm3_fly_nest_attachment_index;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern s32 model_render_flags;
extern void *tl_04;

void TObjEneBm3FlyNest::render_with_state_debug() {
    f32 var_f31;
    AnimationMotion *var_r30;
    if (this->get_target_info() != 0) {
        switch (this->m_38c) {
        default:
        case 2:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B328);
            break;
        case 9:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B338);
            break;
        case 5:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B348);
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B358, this->m_390);
        debug_printf_at(pack_debug_text_position(0, 2), lbl_8043B368, this->m_394);
    }
    switch (this->m_38c) {
    default:
    case 2:
        var_f31 = 0.0f;
        var_r30 = this->motion_list[this->action_table[0].motion].motion;
        break;
    case 9:
        var_r30 = this->motion_list[this->action_table[7].motion].motion;
        var_f31 = var_r30->frameCount - 1;
        break;
    case 5:
        var_r30 = this->motion_list[this->action_table[3].motion].motion;
        var_f31 = var_r30->frameCount - 1;
        break;
    }
    if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
        Vec v = lbl_8043B31C;
        this->draw_ground_shadow(&v, 1);
        set_global_param__8TObjFishFl(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position);
        translate_matrix(0, 0.0f, -5.0f, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_motion_packed_rotation();
        draw_model_motion(this->model, var_r30, var_f31);
        clear_motion_packed_rotation();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    push_matrix();
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    translate_matrix(0, this->parameters[2], this->parameters[3], this->parameters[4]);
    draw_chunk_object((void *)debug_chunk_object);
    pop_matrix();
}

__declspec(section ".rodata") extern const char bm_ene_bm3_fly_a_bml_filename[] = "bm_ene_bm3_fly_a.bml";
__declspec(section ".rodata") extern const f64 lbl_8043B398[1] = { 10430.38043493439 };

void TObjEneBm3FlyNest::render() {
    RenderFadeState *cm;
    s32 cam;
    s32 res;
    s32 draw;
    f32 t;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_with_state_debug();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    this->m_3ac = 0;
    if (this->mode != 9) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            res = this->classify_actor_view_detail(25.0f + lbl_805D9E88, 50.0f + lbl_805D9E84, 120.0f);
        } else if (this->update_object_view_visibility(500.0f, 120.0f) != 0) {
            res = 1;
        } else {
            res = 0;
        }
        if (res != 0) {
            draw = 1;
            this->m_3ac = 1;
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            cm = &this->m_440[cam];
            cm->update();
            if (cm->updateFromCamera(&this->m_2fc) != 0) {
                cm->set_flags_and_apply_damage_color();
                if (this->defer_render() != 0) {
                    draw = 0;
                }
            }
            if (this->mode != 9) {
                Vec v = lbl_8043B310;
                if (this->mode == 0) {
                    t = 10.0f / (this->m_4b0 - 2.0f);
                    if (t < 1.0f && t > 0.0f) {
                        v.x = v.z = 5.0f * t;
                    }
                }
                TObjEneDD::draw_ground_shadow(&v, 1);
            }
            if (draw != 0) {
                this->update_secondary_light();
                set_global_param__8TObjFishFl(this->texlist);
                push_matrix();
                lbl_805D510C = 0;
                TObjEneBm3FlyNest_attachment_point_ptr = this->m_3c8;
                post_translate_matrix(&this->position);
                translate_matrix(0, 0.0f, this->m_4b0, 0.0f);
                if (this->mode == 0) {
                    bm3_fly_nest_attachment_index = 0;
                    lbl_805D5114 = this->m_3e0;
                    set_chunk_model_node_callback((s32)((void *)handle_attachment_sample__17TObjEneBm3FlyNestFi));
                } else {
                    set_chunk_model_node_callback((s32)((void *)TObjEneBm3FlyNest::capture_attachment));
                }
                rotate_matrix_y(0, this->rotation_y);
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (res == 1) {
                    this->draw();
                } else {
                    this->draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                set_chunk_model_node_callback((s32)NULL);
                pop_matrix();
            }
            this->update_primary_light();
            if (cm->updateFromCamera(&this->m_2fc) != 0) {
                cm->clear_flag_and_notify();
            }
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        }
    }
    VecCopy((Vec *)&this->m_2fc, this->m_3c8);
}

void handle_attachment_sample__17TObjEneBm3FlyNestFi(s32 arg0) {
    Vec *pos;
    if (lbl_805D510C == bm3_fly_nest_attachment_sample_table[bm3_fly_nest_attachment_index]) {
        pos = lbl_805D5114;
        bm3_fly_nest_attachment_index += 1;
        lbl_805D5114 = pos + 1;
        get_camera_ctrl__9TObjEneDDFv(&TObjEneBm3FlyNest__attachment_sample_origin, pos);
    }
    TObjEneBm3FlyNest::capture_attachment((void *)arg0);
}

void TObjEneBm3FlyNest::capture_attachment(void * _w0) {
    switch (lbl_805D510C) {
    case 36: case 45:
        get_camera_ctrl__9TObjEneDDFv(&TObjEneBm3FlyNest__attachment_sample_origin, TObjEneBm3FlyNest_attachment_point_ptr++);
        break;
    }
    ++lbl_805D510C;
}

void TObjEneBm3FlyNest::init(void *) { init_params(); }

s32 copy_target_state__17TObjEneBm3FlyNestFPv(TObjEneBm3FlyNest *nest, s32 sound_id) { return nest->remap_sound_for_area(sound_id); }

Vec *TObjEneBm3FlyNest__sub_800B2A54(TObjEneBm3FlyNest *nest) { return &nest->m_3c8[1]; }

void TObjEneBm3FlyNest::remove_child(u8 *child) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(this->m_3b8[i]) == child) {
            this->m_3b0--;
            this->m_3b8[i] = this->m_3b8[this->m_3b0];
            this->m_3b8[this->m_3b0] = 0xFFFF;
            return;
        }
    }
}

s32 TObjEneBm3FlyNest::has_free_attack_slot(u16 id) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < this->m_3b0; i++) {
        TObjEneBm3Fly *fly = (TObjEneBm3Fly *)find_entity_by_id(this->m_3b8[i]);
        if (fly != 0 && id == fly->get_active_id()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode()) {
        return n < 4;
    }
    return n < 2;
}

void handle_state__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->vfunc_95();
        return;
    case 3:
        if (nest->m_3b0 == 0) {
            nest->send_entity_set_flags();
            nest->queue_destruction();
        }
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma fp_contract on
void state_dying__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    Vec v;
    Vec p;
    f32 r;
    s32 a;
    switch (arg1) {
    case 4:
        nest->requested_action = 7;
        nest->vfunc_96();
        nest->m_4b0 = 0.0f;
        ((TObjPlayer *)nest)->refresh_lobby_state();
        nest->m_4c8 = 4;
        nest->m_4cc = 0x14;
        nest->m_4d0 = 0;
        nest->m_4d8 = 0.0f;
        break;
    case 3:
        if (nest->m_4d8 >= 20.0f) {
            nest->transition_enemy_state(9);
        }
        break;
    case 5:
        break;
    case 0:
        switch (nest->m_4d0) {
        case 0:
            nest->advance_animation();
            if (nest->get_flag_b4() != 0) {
                nest->m_4d0 = 1;
                v.x = (-10.0f);
                v.y = 0.0f;
                v.z = (-8.0f);
                rotate_xz_pair_by_angle(&v.x, &v.z, nest->rotation_y);
                vec3_add_to(&v, &nest->position);
                spawn_dead_spot_scale15((s32)&v, 0x32);
                set_field_e4__10TObjPlayerFll(&v, 0x46, 10.0f);
            }
            if (nest->frame < 25.0f) {
                nest->m_4c8 += 1;
                if (nest->m_4c8 >= 4) {
                    r = nest->rand_range(5.0f, 10.0f);
                    a = get_random_scaled__9TObjEneDDFv(nest);
                    VecCopy(&p, (Vec *)&nest->m_2fc);
                    p.x = r * sin_table_lookup(a) + p.x;
                    p.y += 5.0f;
                    p.z = r * cos_table_lookup(a) + p.z;
                    spawn_particle_effect(&p, 0xF1);
                    nest->m_4c8 = 0;
                }
                nest->m_4cc += 1;
                if (nest->m_4cc >= 0x14) {
                    play_sound_effect(nest->remap_sound_for_area(0x4003AD2B), &nest->position, 0, 0);
                    nest->m_4cc = 0;
                }
            }
            nest->vfunc_102();
            break;
        case 1:
            nest->m_4d8 += 0.1f;
            nest->position.y -= 0.1f;
            break;
        }
        break;
    }
}
#pragma pop

void handle_motion_event__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->vfunc_96();
        noop__12TBoss8DragonFv(nest);
        TBoss8Dragon__sub_800BB7D4(nest, 0xF1);
        play_sound_effect(nest->remap_sound_for_area(0x4003A829), &nest->position, 0, 0);
        if (nest->m_3a8 != 0) {
            nest->requested_action = 6;
            nest->m_4b0 = 0.0f;
            return;
        }
        nest->requested_action = 2;
        nest->m_4b0 = -5.0f;
        return;
    case 3:
        if (nest->get_flag_b4() != 0) {
            if (nest->m_3a8 != 0) {
                nest->transition_enemy_state(5);
                return;
            }
            if (nest->hp <= nest->hpmax / 2) {
                nest->transition_enemy_state(4);
                return;
            }
            nest->transition_enemy_state(nest->m_378);
            return;
        }
        break;
    case 0:
        nest->advance_animation();
        nest->vfunc_102();
        return;
    case 5:
        nest->clear_attack_receipts();
        break;
    }
}

void state_spawn__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->requested_action = 5;
        nest->vfunc_96();
        nest->set_field_378(5);
        nest->m_4b0 = 0.0f;
        return;
    case 3:
        if (nest->motion_flags & 0x10) {
            nest->transition_enemy_state(5);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        if (nest->is_passing_frame(15.0f) != 0) {
            nest->spawn_child();
            nest->m_4b8 = nest->m_4b8 - 1;
        }
        nest->advance_animation();
        nest->vfunc_102();
        break;
    }
}

void update_state__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->requested_action = 4;
        nest->vfunc_96();
        nest->set_field_378(5);
        nest->m_4b0 = 0.0f;
        if (nest->m_3a8 == 0) {
            nest->m_3a8 = 1;
            nest->m_4c0 = 2;
            nest->m_4c4 = 0x78;
        }
        break;
    case 5:
        break;
    case 3:
        if (TObjEneBm3FlyNest__sub_800B3AC8(nest) != 0) {
            nest->transition_enemy_state(6);
            return;
        }
        break;
    case 0:
        nest->advance_animation();
        nest->update_replenish();
        nest->vfunc_102();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest__sub_800B318C(TObjEneBm3FlyNest *nest, s32 arg1) {
    Vec pos;
    s32 angle;
    switch (arg1) {
    case 4:
        nest->vfunc_91();
        nest->requested_action = 3;
        nest->vfunc_96();
        nest->set_field_378(5);
        nest->m_4b0 = -5.0f;
        break;
    case 3:
        if (nest->motion_flags & 0x10) {
            nest->transition_enemy_state(5);
            break;
        }
        break;
    case 0:
        nest->advance_animation();
        if ((nest->is_passing_frame(10.0f) != 0) || (nest->is_passing_frame(28.0f) != 0)) {
            play_sound_effect(nest->remap_sound_for_area(0x4003B72A), &nest->position, 0, 0);
        }
        if (nest->is_passing_frame(9.0f) != 0) {
            spawn_particle_effect(&nest->position, 0xF0);
        } else if (nest->is_passing_frame(27.0f) != 0) {
            angle = nest->rotation_y - 0x4000;
            VecCopy(&pos, &nest->position);
            pos.x += 16.0f * sin_table_lookup(angle);
            pos.z += 16.0f * cos_table_lookup(angle);
            spawn_particle_effect(&pos, 0xF0);
        }
        nest->m_4b0 += 0.1f;
        if (nest->m_4b0 > 0.0f) {
            nest->m_4b0 = 0.0f;
        }
        nest->vfunc_102();
        break;
    case 5:
        nest->vfunc_92();
        break;
    }
}
#pragma pop

void handle_event__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->requested_action = 1;
        nest->vfunc_96();
        nest->set_field_378(2);
        nest->m_4b0 = -5.0f;
        return;
    case 3:
        if (nest->motion_flags & 0x10) {
            nest->transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        nest->advance_animation();
        if (nest->is_passing_frame(15.0f) != 0) {
            nest->spawn_child();
            nest->m_4b8 = nest->m_4b8 - 1;
        }
        nest->vfunc_102();
        break;
    }
}

void state_wait__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    switch (arg1) {
    case 4:
        nest->requested_action = 0;
        nest->vfunc_96();
        nest->set_field_378(2);
        nest->m_4b0 = -5.0f;
        nest->m_4c0 = 1;
        nest->m_4c4 = 0x96;
        return;
    case 3:
        if (TObjEneBm3FlyNest__sub_800B3AC8(nest) != 0) {
            nest->transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        nest->advance_animation();
        nest->update_replenish();
        nest->vfunc_102();
        break;
    }
}

void TObjEneBm3FlyNest::state_initial_emit(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->vfunc_95();
        this->set_field_378(2);
        this->m_4b0 = -5.0f;
        this->m_4c8 = 0;
        this->m_4cc = 0;
        this->m_4d0 = 0;
        break;
    case 3:
        this->advance_animation();
        if (this->m_4d0 == 3) {
            switch (this->m_38c) {
            case 2:
                this->transition_enemy_state(this->m_38c);
                break;
            case 5:
                this->transition_enemy_state(this->m_38c);
                break;
            case 9:
                this->requested_action = 7;
                this->advance_animation();
                this->frame = 2.0f;
                this->advance_animation();
                this->frame = this->frame_count - 1.0f;
                this->actorFlags |= 0x800;
                this->m_3a8 = 1;
                this->transition_enemy_state(this->m_38c);
                break;
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        this->m_4c8 += 1;
        switch (this->m_4d0) {
        case 0:
            if (this->m_4c8 > 0x3C) {
                this->m_4d0 = 2;
                this->requested_action = 1;
            }
            break;
        case 1:
            if (this->is_passing_frame(15.0f) != 0) {
                this->m_4d0 = 2;
            }
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0;
            }
            if ((this->m_4c8 % 10) == 0) {
                if (this->m_4cc < this->m_390) {
                    this->spawn_child();
                    this->m_4cc += 1;
                } else {
                    this->m_4d0 = 3;
                }
            }
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void handle_appear__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1) {
    s32 *cnt = &nest->m_4cc;
    s32 i;
    void *o;

    switch (arg1) {
    case 4:
        nest->requested_action = 8;
        nest->vfunc_95();
        nest->set_field_378(2);
        nest->m_4b0 = 100.0f;
        nest->m_4c8 = 0;
        nest->m_4d0 = 0;
        nest->m_4d4 = 0;
        break;
    case 3:
        if (nest->m_4d0 == 2 && nest->get_flag_b4() != 0) {
            nest->transition_enemy_state(1);
        }
        break;
    case 0:
        nest->advance_animation();
        switch (nest->m_4d0) {
        case 0:
            nest->m_4c8 += 1;
            if (nest->m_4c8 == 1) {
                *cnt = 0;
                for (i = 0; i < 6; i++) {
                    o = __nw__7TObjectFUl(0x68);
                    if (o != 0) {
                        ((s32 (*)(void *, void *, void *, void *, void *, void *, s32))__ct__26TObjEneBm3FlyNest_CarryFlyFP7TObjectlllll)(o, nest, &nest->m_3e0[i], &nest->m_3c8[1], &nest->position, cnt, i + 1);
                    }
                }
            }
            nest->m_4b0 = nest->m_4b0 - ((0.3f * (1.0f + sin_table_lookup(nest->m_4d4))) + 0.2f);
            nest->m_4d4 += 0x700;
            if (nest->m_4b0 < 18.0f && nest->requested_action != 9) {
                nest->requested_action = 9;
            }
            if (nest->m_4b0 < -5.0f) {
                nest->m_4b0 = -5.0f;
                nest->m_4d0 = 1;
                nest->m_4c8 = 0;
                spawn_particle_effect(&nest->position, 0xF0);
                play_sound_effect(nest->remap_sound_for_area(0x4003B72A), &nest->position, 0, 0);
            }
            break;
        case 1:
            nest->m_4c8 += 1;
            if (nest->m_4c8 > 3) {
                nest->m_4c8 = 0;
                *cnt += 1;
                if (*cnt >= 6) {
                    nest->m_4d0 = 2;
                }
            }
            break;
        }
        nest->vfunc_102();
        break;
    case 5:
        *cnt = 6;
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest::init_params() {
    s32 temp_r0;
    s32 temp_r0_2;

    this->m_38c = 2;
    this->m_390 = (s32)this->parameters[1];
    temp_r0 = this->m_390;
    if (temp_r0 < 0) {
        this->m_390 = 0;
    } else if (temp_r0 > 6) {
        this->m_390 = 6;
    }
    this->m_394 = (s32)this->parameters[2];
    temp_r0_2 = this->m_394;
    if (temp_r0_2 < 0) {
        this->m_394 = 0;
        return;
    }
    if (temp_r0_2 > 0x1E) {
        this->m_394 = 0x1E;
    }
}

void TObjEneBm3FlyNest::spawn_child() {
    Vec velocity = lbl_8043B304[0];
    Vec position;
    s32 n;
    if (this->m_3b0 <= 6) {
        n = (this->set_index + 1) + this->m_3b4;
        VecCopy(&position, TObjEneBm3FlyNest__sub_800B2A54(this));
        if (((TObjEneBm3Fly *)this)->create((void *)this->m_3c4, (void *)n, &position, &velocity) != 0) {
            this->m_3b8[this->m_3b0++] = this->m_3c4;
            this->m_3c4++;
            this->m_3b4++;
            spawn_particle_effect(&this->m_3c8[1], 0xC8);
            play_sound_effect(this->remap_sound_for_area(0x4003AB27), &this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
    }
}

s32 TObjEneBm3FlyNest__sub_800B3AC8(TObjEneBm3FlyNest *nest) {
    return nest->m_4b8 > 0;
}

void TObjEneBm3FlyNest::update_replenish() {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 var_r5;
    switch (this->m_4b4) {
    case 0:
        if ((this->m_3b0 <= this->m_390 / 2) || (this->m_3a8 != 0)) {
            this->m_4b4 = 1;
            this->m_4bc = 0;
        }
        return;
    case 1:
        if (this->m_4c0 > 0) {
            this->m_4bc = this->m_4bc + 1;
            if (this->m_4bc > this->m_4c4) {
                this->m_4bc = 0;
                var_r5 = this->m_4c0;
                temp_r0_2 = 6 - this->m_3b0;
                if (temp_r0_2 < var_r5) {
                    var_r5 = temp_r0_2;
                }
                temp_r0_3 = this->m_394 - this->m_3b4;
                if (temp_r0_3 < var_r5) {
                    var_r5 = temp_r0_3;
                }
                this->m_4b8 = var_r5;
                return;
            }
        }
        break;
    }
}

void TObjEneBm3FlyNest::vfunc_88() { set_part_local_pos(&this->m_2fc, 0); }

void TObjEneBm3FlyNest::copy_pos() { VecCopy(&this->center, (Vec *)&this->m_2fc); }

void TObjEneBm3FlyNest::vfunc_61() {  }

void TObjEneBm3FlyNest::vfunc_62() {
    s16 temp_r0;

    if (((s16) this->mode == 3) && (TObjEneDD::check_v2_mode() != 0)) {
        this->clear_attack_receipts();
        return;
    }
    temp_r0 = this->mode;
    if (temp_r0 == 4) {
        this->clear_attack_receipts();
        return;
    }
    if (temp_r0 != 7) {
        this->transition_enemy_state(7);
    }
}

void TObjEneBm3FlyNest::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 9) && (temp_r0 != 8) && (temp_r0 != 4)) {
        if (this->m_3a8 == 0) {
            this->transition_enemy_state(4);
            return;
        }
        this->transition_enemy_state(8);
    }
}

void TObjEneBm3FlyNest::vfunc_28() {  }

void dispatch_state__17TObjEneBm3FlyNestFiUii(TObjEneBm3FlyNest *nest, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 1:
        nest->state_initial_emit(arg2);
        return;
    case 0:
        handle_appear__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 2:
        state_wait__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 3:
        handle_event__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 4:
        TObjEneBm3FlyNest__sub_800B318C(nest, arg2);
        return;
    case 5:
        update_state__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 6:
        state_spawn__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 7:
        handle_motion_event__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 8:
        state_dying__17TObjEneBm3FlyNestFPvi(nest, arg2);
        return;
    case 9:
        handle_state__17TObjEneBm3FlyNestFPvi(nest, arg2);
    default:
        return;
    }
}

void TObjEneBm3FlyNest::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18_p5 *)(this))->m102();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else if (this->mode == 0) {
        this->transition_enemy_state(1);
    }
    this->vfunc_88();
    this->copy_pos();
    this->submit_default_cursor_candidate();
    this->vfunc_100();
}

TObjEneBm3FlyNest *TObjEneBm3FlyNest__sub_800B3E40(TObjEneBm3FlyNest *nest, s16 flag) {
    if (nest != 0) {
        *(void ***)((u8 *)nest + 0x18) = lbl_80491EE4;
        free_collision_body_parts(nest);
        __destroy_arr(nest->m_440, (void *)__dt__15RenderFadeStateFv, 0x1c, 4);
        __dt__9TObjEneDDFv(nest, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(nest);
        }
    }
    return nest;
}

extern const char *bm3_fly_nest_class_name;

void *__ct__9TObjEneDDFP7TObject(void *, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void *);

TObjEneBm3FlyNest *TObjEneBm3FlyNest__ct(TObjEneBm3FlyNest *nest, TObject *parent, void *set_data) {
    s32 i;

    __ct__9TObjEneDDFP7TObject(nest, parent, set_data);
    *(void ***)((u8 *)nest + 0x18) = lbl_80491EE4;
    __construct_array(nest->m_440, __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    nest->m_name = bm3_fly_nest_class_name;
    nest->invoke_initialization_hook(set_data);
    nest->init_position_vectors();
    nest->model = (void *)lbl_805D5108->models[1].model;
    nest->texlist = lbl_805D5108->models[0].m_c;
    nest->init_model(bm3_flynest_collider_params, 1);
    nest->m_300 = 20.0f + nest->position.y;
    nest->vfunc_88();
    nest->set_field_d8((s32)bm3_flynest_hit_action_table);
    nest->set_field_dc((s32)lbl_805D5108->motions);
    nest->requested_action = 0;
    nest->set_animation(nest->requested_action);
    nest->set_field_b8(nest->requested_action);
    nest->reset_hp(lbl_805D50F8, lbl_805D50FC, lbl_805D5100);
    nest->check_state_flag_1();
    nest->movementParameters = &bm3_fly_nest_params;
    nest->initialize_enemy_state(4);
    nest->m_37c = 10.0f;
    nest->init_params();
    if (nest->m_394 > *(s16 *)((u8 *)set_data + 2)) {
        nest->m_394 = *(s16 *)((u8 *)set_data + 2);
    }
    for (i = 0; i < 4; i++) {
        nest->m_398[i] = 0;
    }
    nest->m_3a8 = 0;
    nest->m_3ac = 0;
    nest->m_3b0 = 0;
    nest->m_3b4 = 0;
    nest->m_3c4 = nest->entity_id + 1;
    for (i = 0; i < 6; i++) {
        nest->m_3b8[i] = 0xFFFF;
    }
    for (i = 0; i < 2; i++) {
        VecCopy(&nest->m_3c8[i], &nest->position);
    }
    nest->m_3c8[1].y += 25.0f;
    for (i = 0; i < 8; i++) {
        VecCopy(&nest->m_3e0[i], &nest->position);
    }
    for (i = 0; i < 4; i++) {
        nest->m_440[i].activate_and_dispatch();
    }
    nest->m_4b0 = 0.0f;
    nest->m_4b4 = 0;
    nest->m_4b8 = 0;
    nest->m_4bc = 0;
    nest->m_4c0 = 0;
    nest->m_4c4 = 0;
    nest->m_4c8 = 0;
    nest->m_4cc = 0;
    nest->m_4d0 = 0;
    nest->m_4d4 = 0;
    nest->m_4d8 = 0.0f;
    nest->mode = 0;
    nest->dispatch_action(nest->mode, 4);
    return nest;
}

BmlResource *TObjEneBm3FlyNest__sub_800B4158(void) { return lbl_805D5108; }

void TObjEneBm3FlyNest::free_fly() {
    TObjEneBm3Fly::release_shared_data();
    if (lbl_805D5108 != NULL) {
        free_bin_model_request(lbl_805D5108, 1);
        lbl_805D5108 = NULL;
    }
}

void *TObjEneBm3FlyNest::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4DC);
    if (o != NULL) {
        o = TObjEneBm3FlyNest__ct((TObjEneBm3FlyNest *)o, (TObject *)tl_04, arg0);
    }
    return o;
}

void TObjEneBm3FlyNest::load_resources() {
    BmlModelEntry *models;
    TObjEneBm3FlyNest__attachment_sample_origin.x = 0.0f;
    TObjEneBm3FlyNest__attachment_sample_origin.y = 0.0f;
    TObjEneBm3FlyNest__attachment_sample_origin.z = 0.0f;
    lbl_805D510C = 0;
    TObjEneBm3FlyNest_attachment_point_ptr = NULL;
    lbl_805D5114 = NULL;
    bm3_fly_nest_attachment_index = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5108 = load_enemy_bml_resource_named(&bm3_fly_nest_resource_desc, bm_ene_bm3_fly_a_bml_filename);
    } else {
        lbl_805D5108 = load_enemy_bml_resource(&bm3_fly_nest_resource_desc);
    }
    lbl_805D50F8 = (u8 *)TLobby::register_boss(1);
    lbl_805D50FC = (u8 *)TLobby::dispatch_shared_handler_b(1);
    lbl_805D5100 = (u8 *)TLobby::register_object(1);
    lbl_805D5104 = TLobby::dispatch_shared_handler_a(1);
    TObjEneBm3Fly::load_resources();
    TObjEneBm3FlyNest::init_vertex_table();
    {
        Bm3FlyAnimationBinding anim = bm3_flynest_anim_binding;
        anim.motions = lbl_805D5108->motions;
        models = lbl_805D5108->models;
        TLobby::spawn_npc_enemy(8, models[1].model, (NJS_TEXLIST *)models[0].m_c, &anim, bm3_flynest_collider_params[0].radius, 0.0f);
    }
}

void TObjEneBm3FlyNest_CarryFly::render() {
    ((s32 (*)(s32, void *))set_global_param__8TObjFishFl)(lbl_805D5108->models[0].m_c, lbl_805D5108);
    push_matrix();
    if (state == 0) {
        post_translate_matrix(origin);
    } else {
        post_translate_matrix(target);
    }
    post_translate_matrix(&offset);
    rotate_matrix_y(0, angle);
    set_motion_packed_rotation();
    draw_model_motion((void *)lbl_805D5108->models[0].model, motion, frame);
    clear_motion_packed_rotation();
    pop_matrix();
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest_CarryFly::run_task() {
    f32 lim;
    f32 v;
    f32 spd;

    lim = (f32)(motion->frameCount - 1);
    frame += 0.8f;
    if (frame > lim) {
        frame -= lim;
    }
    switch (state) {
    case 0:
        if (*arrived == index) {
            Vec tmp;
            state = 1;
            VecCopy(&tmp, &offset);
            vec3_add_to(&tmp, origin);
            VecCopy(&velocity, &tmp);
            subtract_vector(&velocity, target);
            velocity.y -= 5.0f;
            VecCopy(&offset, &velocity);
            distance = normalize_vector_xz(&velocity);
            if (distance <= 0.01f) {
                queue_destruction();
                break;
            }
            arc = (-120.0f) / (distance * distance);
            height = 30.0f;
        }
        play_persistent_sound(copy_target_state__17TObjEneBm3FlyNestFPv((TObjEneBm3FlyNest *)m_up, 0x4003A828), (s32)this, (u32)origin, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 1:
        offset.y += 1.0f;
        if (offset.y > 0.0f) {
            state = 2;
            velocity.y = 0.5f * distance;
        }
        play_persistent_sound(copy_target_state__17TObjEneBm3FlyNestFPv((TObjEneBm3FlyNest *)m_up, 0x4003A828), (s32)this, (u32)origin, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 2:
        spd = distance;
        v = velocity.y;
        v = v - 0.05f * spd;
        if (v < 0.5f * -spd) {
            spawn_particle_effect(target, 0xC8);
            play_sound_effect(copy_target_state__17TObjEneBm3FlyNestFPv((TObjEneBm3FlyNest *)m_up, 0x4003AB27), target, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
            queue_destruction();
            break;
        }
        offset.y = arc * (v * v) + height;
        velocity.y = v;
        v += 0.5f * distance;
        offset.x = velocity.x * v;
        offset.z = velocity.z * v;
        play_persistent_sound(copy_target_state__17TObjEneBm3FlyNestFPv((TObjEneBm3FlyNest *)m_up, 0x4003A828), (s32)this, (u32)target, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    }
}
#pragma pop

TObjEneBm3FlyNest_CarryFly::~TObjEneBm3FlyNest_CarryFly() {}

}
TObjEneBm3FlyNest_CarryFly::TObjEneBm3FlyNest_CarryFly(TObject *parent, s32 a, s32 b, s32 unused, s32 c, s32 d) : TObject(parent) {
    Vec v;
    m_name = TObjEneBm3FlyNest_CarryFly__name;
    origin = (Vec *)a;
    target = (Vec *)b;
    arrived = (s32 *)c;
    index = d;
    VecCopy(&v, origin);
    subtract_vector(&v, target);
    ((TObjBoss2Tunnel *)(&v))->update_scale();
    angle = (s32) (lbl_8043B398[0] * atan2_float(v.x, v.z));
    offset.x = 6.0f * v.x;
    offset.y = 6.0f;
    offset.z = 6.0f * v.z;
    motion = lbl_805D5108->motions[10].motion;
    frame = (f32) (index * 2);
    unk_3C = 1.0f;
    unk_44 = 0;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    distance = 0.0f;
    height = 0.0f;
    arc = 0.0f;
    state = 0;
}

void TObjEneBm3FlyNest::init_vertex_table() {
    f32 *v = fly_nest_vertex_table;
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    v[5] = v[4] = 6.0f;
    lbl_80500B24[0] = -1;
    lbl_80500B24[1] = -1;
    lbl_80500B2C.pv = fly_nest_vertex_table;
    lbl_80500B2C.pc = lbl_80500B24;
    lbl_80500B2C.d = 0;
    lbl_80500B2C.e = 2;
}

