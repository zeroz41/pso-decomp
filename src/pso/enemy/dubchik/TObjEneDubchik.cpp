#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/effect/TUnk_80494968.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TUnk_80491478.h"
#include "pso/player/TUnk_80491460.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D853C.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
extern "C" {
// Mode 8 (walks back to home_position). It keeps its u8 * parameter: with TObjEneDubchik * the compiler
// keeps actor + 0x290 in r30 (TObjChara's 0x290 and 0x29C vectors are not typed as Vecs yet).
void TObjPlayer__sub_800A8C4C(u8 *actor);
}


struct Node_800AA82C { u32 flags; u8 pad[0x30 - 4]; s32 f30; };


void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 check_path_obstructed(void *, void *);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {

extern saddr lbl_80500AF0[];
extern saddr lbl_80500AF8[];
Res_800AA82C *dubchik_resource;
NJS_TEXLIST *dubchik_texlist;
NJS_TEXLIST *dubchik_variant_texlist;

AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
}
u8 *load_gvm_texture_file(saddr name);
Node_800AA82C *lbl_805D509C;
Node_800AA82C *lbl_805D50A0;
void *breakup_model_ptr;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_800A8C4C { s32 x, y, z; };



extern "C" {
void obj_setFlags30(void *, u32);
s32 minimap_render_dot(void *, s32, s32, s32);
extern void *tl_04;
f32 fabs_float(f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec_800A8C4C, Vec_800A8C4C, f32);
s32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s32 update_enemy_wander_move(void *, Vec *, s32, f32);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);

struct Ids_800AA82C { s16 v[2]; };
__declspec(section ".data") saddr lbl_805009A0[2];
__declspec(section ".data") saddr lbl_805009A8[2];
__declspec(section ".data") saddr lbl_805009B0[2];
saddr lbl_805009B8[20];
u8 lbl_80500A08[0x10];
u8 lbl_80500A18[0x30];
u8 lbl_80500A48[0xA8];
__declspec(section ".data") saddr lbl_80500AF0[2];
__declspec(section ".data") saddr lbl_80500AF8[2];

#define lbl_805009A0 ((u8 *)lbl_805009A0)


const char *bm_ene_dubchik_model_names[] = {
    "me2_y_me2.nj",
    "me2_y_me2_2.nj",
    NULL,
};

const char *bm_ene_dubchik_motion_names[] = {
    "damage_b_me2_y_me2.njm",
    "damage_f_me2_y_me2.njm",
    "kamae01_me2_y_me2.njm",
    "kamae02_me2_y_me2.njm",
    "revival_b_me2_y_me2.njm",
    "revival_f_me2_y_me2.njm",
    "scratch01_me2_me2.njm",
    "scratch02_me2_y_me2.njm",
    "shoot01_me2_y_me2.njm",
    "shoot02_me2_me2.njm",
    "starting_me2_y_me2.njm",
    "wait01_me2_y_me2.njm",
    "wait02_me2_y_me2.njm",
    "walk01_me2_y_me2.njm",
    "walk02_me2_y_me2.njm",
    NULL,
};

BmlResourceDescriptor bm_ene_dubchik_resource_descriptor = {
    "bm_ene_dubchik.bml", bm_ene_dubchik_model_names, bm_ene_dubchik_motion_names, 2, 15,
};

}
const char *TObjEneDubchik__class_name = "TObjEneDubchik";
extern "C" {

__declspec(section ".data") f32 lbl_804910E4[2] = { 0.37037036f, 0.5703704f };
__declspec(section ".data") s32 lbl_804910EC[2] = { 1, 19 };

// Installed as TObjMotion::action_table by the constructor.
TObjMotionAction lbl_804910F4[20] = {
    { 1, 0, 11, 0.5f, 0 },
    { 1, 1, 13, 0.7f, 1 },
    { 2, 0, 6, 0.7f, 4 },
    { 2, 14, 1, 0.7f, 8 },
    { 2, 14, 1, 0.7f, 16 },
    { 2, 0, 10, 0.5f, 0 },
    { 1, 6, 12, 0.5f, 0 },
    { 1, 7, 14, 1.2f, 1 },
    { 2, 10, 2, 0.6f, 4 },
    { 2, 11, 3, 0.4f, 4 },
    { 1, 10, 8, 0.5f, 4 },
    { 1, 11, 9, 0.4f, 4 },
    { 2, 0, 7, 0.8f, 4 },
    { 5, 15, 0, 0.6f, 8 },
    { 2, 0, 5, 0.7f, 8 },
    { 2, 0, 4, 0.7f, 8 },
    { 1, 16, 11, 0.5f, 8 },
    { 2, 0, 8, 0.5f, 4 },
    { 2, 6, 9, 0.4f, 4 },
    { 1, 19, 13, 1.0f, 1 },
};

CollisionBody dubchik_collision_body[1] = {
    { { 0.0f, 9.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

TBoss3VoloptBreakupParams lbl_80491260 = { 0x14, { 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f } };

TBoss3VoloptP01Movement dubchik_movement = { 150.0f, 0.37037036f, 0x400, 0x1E0000, 0, 1, 0 };

__declspec(section ".data") s16 lbl_80491298[3] = { 0x14, 0x15, -1 };
s16 lbl_804912A0[6] = { 0x2B, 0x31, 0x32, 0x33, 0x34, -1 };
s16 lbl_804912AC[9] = { 0x17, 0x1A, 0x1D, 0x1F, 0x20, 0x21, 0x23, 0x24, -1 };
__declspec(section ".data") s16 player_model_node_index_pair[3] = { 0x14, 0x2B, 0x17 };





}


struct T_800AAF98 { u8 pad[0x18]; s32 arr[1]; };


s32 TObjEneDubchik::sub_800AB068() {
    if (fabs_float(position.x - prev_position.x) + fabs_float(position.z - prev_position.z) > 50.0f) {
        VecCopy(&position, &prev_position);
        return 1;
    }
    return 0;
}

void TObjEneDubchik::set_invuln_flags() {
    bodies->flags |= 0x0A000000;
    obj_setFlags30(this, 0x04000000U);
}

void TObjEneDubchik::clear_flag_04000000() {
    bodies->flags &= 0xF5FFFFFF;
    obj_clearFlags30(0x04000000U);
}

void AttackParams::set_attack_range(f32 range) { attack_range = range; }

void TObjEneDubchik::init_level_stats(s32 arg1) {
    s32 var_r0;

    *(s32 *)&this->model = dubchik_resource->mdl->f8;
    if (arg1 == 0) {
        var_r0 = dubchik_resource->mdl->fC;
    } else {
        var_r0 = (saddr)dubchik_variant_texlist;
    }
    this->texlist = var_r0;
}

s32 TObjEneDubchik::sub_800AAF98(s32 i) {
    return ((T_800AAF98 **)lbl_805009B8)[variant]->arr[i];
}

f32 TObjEneDubchik::sub_800AAF78(s32 arg1) {
    return ((f32 *)lbl_805009B8[variant])[arg1];
}

void TObjEneDubchik::run_move_action() {  }

void TObjEneDubchik::run_idle_action() {  }

TObjEneDubchik::TObjEneDubchik(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    s32 i;
    m_name = TObjEneDubchik__class_name;
    apply_set_data(set_data);
    VecCopy(&move_origin, VecCopy(&move_destination, VecCopy(&prev_position, &position)));
    motion_list = dubchik_resource->motions;
    variant = *(s16 *)((u8 *)set_data + 0x3C) ? 1 : 0;
    state36C = *(s16 *)((u8 *)set_data + 0x3E);
    init_level_stats(variant);
    action_table = (TObjMotionAction *)&lbl_804910F4;
    set_field_d8((saddr)action_table);
    init_collision_body_parts(this, dubchik_collision_body, 1);
    movementParameters = &dubchik_movement;
    bind_enemy_combat_stats((u8 *)((saddr *)lbl_805009A0)[variant], (u8 *)lbl_805009A8[variant], (u8 *)lbl_805009B0[variant]);
    sub_800A8B8C();
    requested_action = 5;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    collapsed = 0;
    for (i = 0; i < 3; i++) {
        parts[i] = NULL;
    }
    update_prev_position();
    initialize_enemy_photon_effect(this);
    add_flags_2e4(4);
    attack_count = 0;
    chase_distance = 0.0f;
    if (variant != 0) {
        set_param(50);
    } else {
        set_param(24);
    }
    saver = TUnk_80494968::create(0x00FFFFFF, 0xA0707070);
    if (*(s16 *)((u8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
    effect = NULL;
    reassemble_count = 0;
    search_range = ((s32)parameters[0] & 1) ? 220.0f : 170.0f;
    clear_lobby_object_state();
}

TObjEneDubchik::~TObjEneDubchik() {
    s32 i;
    if (effect != NULL) {
        effect->queue_destruction();
    }
    free_collision_body_parts(this);
    for (i = 0; i < 3; i++) {
        if (parts[i] != NULL) {
            parts[i]->queue_destruction();
        }
    }
    delete saver;
}

// The model and texture files the loader opens (defined at the end of the file).
inline const char *dubchik_bml_filename();
inline const char *dubchik_v2_gvm_filename();
inline const char *dubchik_gvm_filename();

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneDubchik::load_resources() {
    saddr *t;
    Node_800AA82C *nodes[3];
    void *p;
    s32 m;
    s32 i;
    u32 mdl;
    Node_800AA82C *n;
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_resource = (Res_800AA82C *)load_enemy_bml_resource_named(&bm_ene_dubchik_resource_descriptor, (const char *)dubchik_bml_filename());
    } else {
        p = new BmlResource(5, &bm_ene_dubchik_resource_descriptor, 0, 0, NULL);
        dubchik_resource = (Res_800AA82C *)p;
    }
    dubchik_texlist = *(NJS_TEXLIST **)((u8 *)dubchik_resource->mdl + 0x1C);
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_variant_texlist = (NJS_TEXLIST *)load_gvm_texture_file((saddr)dubchik_v2_gvm_filename());
    } else {
        dubchik_variant_texlist = (NJS_TEXLIST *)load_gvm_texture_file((saddr)dubchik_gvm_filename());
    }
    n = (Node_800AA82C *)find_model_node(*(s32 *)((u8 *)dubchik_resource->mdl + 0x18), 0x17);
    n->f30 = 0;
    TObjPlayer__sub_800A4294();
    lbl_805D509C = (Node_800AA82C *)find_model_node(dubchik_resource->mdl->f8, 0x15);
    lbl_805D50A0 = (Node_800AA82C *)find_model_node(dubchik_resource->mdl->f8, 0x2A);
    ((NJS_OBJECT *)find_model_node(*(s32 *)((u8 *)dubchik_resource->mdl + 0x18), 0x15))->evalflags |= 8;
    p = new TUnk_8048FA00(dubchik_resource->mdl->f8);
    breakup_model_ptr = p;
    p = new SampledMotionPoints(2, 28.0f, 35.0f, 1.0f);
    lbl_80500AF0[0] = (saddr)p;
    ((SampledMotionPoints *)lbl_80500AF0[0])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion((BmlResource *)dubchik_resource, 6), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 36.0f, 40.0f, 1.0f);
    lbl_80500AF8[0] = (saddr)p;
    ((SampledMotionPoints *)lbl_80500AF8[0])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion((BmlResource *)dubchik_resource, 6), 0x2E, 0x32);
    p = new SampledMotionPoints(2, 30.0f, 38.0f, 1.0f);
    t = lbl_80500AF0;
    t[1] = (saddr)p;
    ((SampledMotionPoints *)t[1])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion((BmlResource *)dubchik_resource, 7), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 50.0f, 58.0f, 1.0f);
    t = lbl_80500AF8;
    t[1] = (saddr)p;
    ((SampledMotionPoints *)t[1])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion((BmlResource *)dubchik_resource, 7), 0x2E, 0x32);
    for (i = 0; i < 2; i++) {
        ((saddr *)lbl_805009A0)[i] = (saddr)TLobby::register_boss(i + 0x1B);
        lbl_805009A8[i] = (saddr)TLobby::dispatch_shared_handler_b(i + 0x1B);
        lbl_805009B0[i] = (saddr)TLobby::register_object(i + 0x1B);
        lbl_805009B8[i] = (saddr)TLobby::dispatch_shared_handler_a(i + 0x1B);
    }
    mdl = dubchik_resource->mdl->f8;
    for (i = 0; i < 3; i++) {
        nodes[i] = (Node_800AA82C *)find_model_node(mdl, player_model_node_index_pair[i]);
    }
    collect_visible_nodes((NJS_OBJECT *)nodes[0], (NJS_OBJECT **)lbl_80500A08);
    collect_visible_nodes((NJS_OBJECT *)nodes[1], (NJS_OBJECT **)lbl_80500A18);
    collect_visible_nodes((NJS_OBJECT *)nodes[2], (NJS_OBJECT **)lbl_80500A48);
    {
        Ids_800AA82C ids = {{0x1E, 0x1F}};
        NpcAnimationBinding d = { NULL, reinterpret_cast<TObjMotionAction *>(&lbl_804910F4), 0, 1, 20 };
        s32 j;
        d.motions = dubchik_resource->motions;
        for (j = 0; j < 2; j++) {
            Mdl_800AA82C *e = &dubchik_resource->mdl[j];
            NpcModelRegistry::register_animated_chunk(ids.v[j], reinterpret_cast<void *>(e->f8), reinterpret_cast<void *>(e->fC), &d, 5.0f, 0.0f);
        }
    }
}
#pragma pop

void TObjEneDubchik::free_resources() {
    if (breakup_model_ptr != NULL) {
        delete (TUnk_8048FA00 *)breakup_model_ptr;
        breakup_model_ptr = NULL;
    }
    if (dubchik_resource != NULL) {
        delete (BmlResource *)dubchik_resource;
        dubchik_resource = NULL;
    }
    dubchik_texlist = NULL;
    if (dubchik_variant_texlist != NULL) {
        TObjPlayer::free_if_valid((saddr)dubchik_variant_texlist);
        dubchik_variant_texlist = NULL;
    }
    TObjPlayer::reset_effect_count();
    if ((void *)lbl_80500AF0[0] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF0[0];
        lbl_80500AF0[0] = 0;
    }
    if ((void *)lbl_80500AF8[0] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF8[0];
        lbl_80500AF8[0] = 0;
    }
    if ((void *)lbl_80500AF0[1] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF0[1];
        lbl_80500AF0[1] = 0;
    }
    if ((void *)lbl_80500AF8[1] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF8[1];
        lbl_80500AF8[1] = 0;
    }
}

void *TObjEneDubchik::create(void *set_data) {
    void *o;
    void *o2;
    o = new TObjControl((TObject *)tl_04);
    o2 = new TObjEneDubchik((TObject *)o, set_data);
    return o2;
}

void TObjEneDubchik::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_800AA330();
        return;
    }
    sub_800A8B8C();
    target = (u8 *)find_active_entity_by_id(targetId);
    release_destroyed_target();
    sub_800AA10C();
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            run_synced_state_handler();
        }
        mode = next_action;
        state = 0;
    }
    run_synced_state_handler();
    sub_800AB068();
    update_prev_position();
    VecCopy(&center, &body_center);
    if (obj_testFlags30(0x04000000) == 0) {
        submit_cursor_candidate(this, -1);
    }
    minimap_render_dot((u8 *)&position, -0x5DB4, 1, 0);
}

void TObjEneDubchik::run_synced_state_handler() {
    switch (mode) {
    case 0: update_timed_state(); return;
    case 1: update_chase(); return;
    case 2: update_scratch(); return;
    case 9: update_shoot(); return;
    case 4: update_knockback(); return;
    case 5: update_fall_apart(); return;
    case 7: update_appear(); return;
    case 8: TObjPlayer__sub_800A8C4C((u8 *)this); break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneDubchik::render() {
    s32 detail;
    s32 drew;
    s32 visible;
    if (!(actorFlags & 0x02000000)) {
        detail = classify_actor_view_detail(120.0f, 400.0f, 20.0f);
        if (detail != 0) {
            select_actor_lighting((saddr)this);
            TObjPlayer::toggle_particle_effect();
            if (collapsed != 0) {
                TObjFish::set_global_param((saddr)dubchik_texlist);
            } else {
                TObjFish::set_global_param(texlist);
            }
            drew = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            sub_800A8A7C();
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, 1.3f, 1.3f, 1.3f);
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object(model);
            } else if (m_388 & 4) {
                if (fade.has_visible_opacity() != 0) {
                    fade.set_flags_and_apply_damage_color();
                    visible = 1;
                    if (defer_render() != 0) {
                        visible = 0;
                    }
                    if (visible != 0) {
                        if (detail == 1) {
                            draw();
                        } else {
                            draw_motion_model();
                        }
                    }
                    fade.clear_flag_and_notify();
                } else {
                    drew = 0;
                }
            } else if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(actorFlags & 0x800) && (drew != 0)) {
                Vec v = {1.5f, 1.5f, 1.5f};
                draw_ground_shadow(&v, 0);
            }
        }
    }
}
#pragma pop

void TObjEneDubchik::sub_800AA330() {}

void TObjEneDubchik::sub_800AA10C() {
    f32 temp_f31;
    u8 *current_target;
    switch (this->mode) {
    case 8:
    case 0:
        if ((this->is_actor_cadence_frame(0x1E) != 0) && (find_target_in_range(this->search_range) != 0)) {
            this->update_if_active(1);
        }
        break;
    case 1:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range((f32) (50.0f + this->search_range));
        }
        current_target = target;
        if (current_target == NULL) {
            this->update_if_active(8);
            return;
        }
        if (this->chase_distance >= 80.0f) {
            this->chase_distance = 0.0f;
            if ((parameters[0] >= 0.0f) && (this->random_ratio() < 0.35f)) {
                this->targetId = pick_random_nearby_player(150.0f);
                if (this->targetId != 0xFFFF) {
                    target = (u8 *)find_active_entity_by_id(this->targetId);
                    this->update_if_active(9);
                    return;
                }
                find_target_in_range((f32) (50.0f + this->search_range));
                return;
            }
        } else if (current_target != NULL) {
            if (xz_distance_squared(&position, &((TObjChara *)target)->position) < (((AttackParams *)(this->m_318))->get_attack_range() * ((AttackParams *)(this->m_318))->get_attack_range())) {
                this->attack_count = (this->attack_count + 1);
                if ((s16) this->attack_count > 3) {
                    this->attack_count = 0;
                    this->target_nearest_player(40.0f);
                }
                this->update_if_active(2);
                return;
            }
        } else if (this->is_actor_cadence_frame(0x1E) != 0) {
            this->find_target_in_range((f32) (50.0f + this->search_range));
        }
        break;
    }
}

void TObjEneDubchik::update_chase() {
    f32 speed;
    s32 action;
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        m_388 |= 0x01800000;
        sub_8004292C();
        if ((s32)m_380 != 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (collapsed != 0) {
                    action = 7;
                } else {
                    action = lbl_804910EC[variant];
                }
                requested_action = action;
            } else {
                requested_action = 0;
            }
            state = 2;
        } else {
            play_sound_effect(remap_sound_for_area(0x4003B205), &position, 0, 0);
            state = 1;
        }
        if (target != NULL) {
            VecCopy(destination(), &((TObjChara *)target)->body_center);
        }
        break;
    case 1:
        advance_animation();
        if (requested_action == 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (collapsed != 0) {
                    action = 7;
                } else {
                    action = lbl_804910EC[variant];
                }
                requested_action = action;
            }
            state = 2;
        }
        break;
    case 2:
        advance_animation();
        if (collapsed != 0) {
            action = remap_sound_for_area(0x4003A801);
        } else {
            action = remap_sound_for_area(0x4003B200);
        }
        play_persistent_sound(action, (saddr)this, (uaddr)&position, 0, 0);
        if (target != NULL) {
            if (collapsed != 0) {
                speed = sub_800AAF78(2);
            } else {
                speed = lbl_804910E4[variant];
            }
            {
                Vec v = ((TObjChara *)target)->body_center;
                update_enemy_wander_move(this, &v, 1, speed);
            }
            chase_distance += speed;
            turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, velocity());
        } else {
            update_if_active(0);
        }
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        break;
    }
}

void TObjEneDubchik::update_knockback() {
    switch ((s32)state) {
    case 0:
        if (TObjEneDD::check_v2_mode() != 0 && random_ratio() > 0.2f) {
            state = -1;
        } else {
            requested_action = 3;
            enemy_set_heading_velocity(-7.0f, this, rotation_y);
            state = 1;
            play_sound_effect(remap_sound_for_area(0x4003A806), &position, 0, 0);
            knockback_timer = sub_800AAF98(2);
        }
        actorFlags &= ~0x200000;
        break;
    case 1:
        advance_animation();
        if (--knockback_timer <= 0) {
            set_invuln_flags();
        }
        {
        Vec pos = body_center;
        pos.x += velocity()->x;
        pos.z += velocity()->z;
        if (check_path_obstructed(this, &pos) == 0) {
            move_with_wall_slide((u8 *)this);
        } else {
            velocity()->x = velocity()->z = 0.0f;
        }
        }
        velocity()->x *= 0.75f;
        velocity()->z *= 0.75f;
        if (requested_action == 0xE) {
            velocity()->x = velocity()->z = 0.0f;
            state = 3;
            set_invuln_flags();
        }
        break;
    case 2:
        break;
    case 3:
        advance_animation();
        if (frame >= 25.0f) {
            clear_flag_04000000();
        }
        if (action_flags != 8) {
            state = -1;
        }
        break;
    case 4:
        m_384--;
        if (m_384 <= 0) {
            state = -1;
        }
        break;
    case -1:
        clear_flag_04000000();
        obj_clearFlags30(0x200);
        m_388 &= ~1;
        referenceHp = hp;
        update_if_active(1);
        return;
    }
    apply_actor_gravity(this, NULL, 0.0f);
    check_object_collisions();
    check_enemy_body_collisions(this);
}

void TObjEneDubchik::update_fall_apart() {
    s32 i;

    if (m_388 & 0x02000000) {
        update_dying();
        return;
    }
    switch ((s32)state) {
    case 0:
        actorFlags &= ~0x200000;
        m_388 &= ~0x800000;
        set_invuln_flags();
        requested_action = 4;
        enemy_set_heading_velocity(-7.0f, this, rotation_y);
        render_model_and_set_attach_points();
        for (i = 0; i < 3; i++) {
            if (parts[i] == NULL && random_ratio() >= 0.5f) {
                parts[i] = new TUnk_80491478(i, this, (s32)variant != 0 ? dubchik_variant_texlist : dubchik_texlist, &part_offsets[i]);
                m_388 |= 0x20000 << i;
            }
        }
        play_sound_effect(remap_sound_for_area(0x4003A806), &position, 0, 0);
        set_invuln_flags();
        reassemble_count++;
        state = 1;
    case 1: {
        advance_animation();
        Vec pos = body_center;
        pos.x += velocity()->x;
        pos.z += velocity()->z;
        if (check_path_obstructed(this, &pos) == 0) {
            move_with_wall_slide((u8 *)this);
        } else {
            velocity()->x = velocity()->z = 0.0f;
        }
        velocity()->x *= 0.75f;
        velocity()->z *= 0.75f;
        if (requested_action == 0xE) {
            if ((s32)variant != 0 || reassemble_count >= 5) {
                start_dying();
            } else {
                velocity()->x = velocity()->z = 0.0f;
                collapsed = 1;
                m_384 = sub_800AAF98(0);
                state = 2;
            }
        }
        break;
    }
    case 2:
        m_384--;
        if (m_384 <= 0) {
            s32 j;
            for (j = 0; j < 3; j++) {
                if (parts[j] != NULL) {
                    if (random_ratio() >= 0.5f) {
                        part_hit[j] = 1;
                        parts[j]->cancel_action();
                    } else {
                        part_hit[j] = 0;
                    }
                }
            }
            if (parts[1] != NULL && parts[2] != NULL && part_hit[1] + part_hit[2] == 0) {
                s32 k;
                f32 dist = xz_distance_squared(&body_center, &parts[1]->pos);
                if (dist < xz_distance_squared(&body_center, &parts[2]->pos)) {
                    k = 1;
                } else {
                    k = 2;
                }
                part_hit[k] = 1;
                parts[k]->cancel_action();
            }
            m_388 |= 0x800000;
            state = 3;
        }
        break;
    case 3: {
        s32 all_done;
        render_model_and_set_attach_points();
        play_persistent_sound(remap_sound_for_area(0x4003AD07), (saddr)this, (uaddr)&position, 0, 0);
        all_done = 1;
        for (i = 0; i < 3; i++) {
            if (part_hit[i] != 0 && parts[i] != NULL) {
                if (parts[i]->get_action_priority() != 0) {
                    parts[i]->queue_destruction();
                    parts[i] = NULL;
                    m_388 &= ~(0x20000 << i);
                } else {
                    all_done = 0;
                }
            }
        }
        if (all_done != 0) {
            play_sound_effect(remap_sound_for_area(0x4003A808), &position, 0, 0);
            state = 4;
        }
        break;
    }
    case 4:
        advance_animation();
        if (obj_testFlags30(0x800) == 0 && frame >= 25.0f) {
            clear_flag_04000000();
        }
        if (action_flags != 8) {
            obj_clearFlags30(0xA00);
            hp = referenceHp = hpmax;
            clear_harmful_statuses();
            m_388 &= ~1;
            update_if_active(1);
            clear_flag_04000000();
        }
        break;
    case -1:
        obj_clearFlags30(0x200);
        break;
    }
    apply_actor_gravity(this, NULL, 0.0f);
    check_object_collisions();
    check_enemy_body_collisions(this);
}

extern "C" const f32 player_band_threshold_table[6] = { 20.0f, 34.0f, 28.0f, 54.0f, 0.7f, 0.8f };

void TObjEneDubchik::update_scratch() {
    s32 act;
    Vec *h0;
    Vec *h1;
    Vec b2;
    Vec a2;
    Vec b1;
    Vec a1;

    switch ((s32)state) {
    case 0: {
        s16 a = 2;
        if (collapsed != 0) {
            a = 12;
        }
        requested_action = a;
        actorFlags |= 0x200000;
        saver->clear_segments();
        state = 1;
    }
    case 1:
        if (target != NULL) {
            VecCopy(destination(), &((TObjChara *)target)->body_center);
            enemy_turn_toward_dest(((EnemyMoveParams *)movementParameters)->turn_speed);
        }
        advance_animation();
        act = -1;
        if (is_passing_frame((f32)player_band_threshold_table[collapsed]) != 0) {
            if (parts[2] == NULL) {
                act = 4;
            }
        } else if (is_passing_frame((f32)player_band_threshold_table[collapsed + 2]) != 0 && parts[1] == NULL) {
            act = 3;
        }
        if (act >= 0) {
            play_sound_effect(remap_sound_for_area(0x4003AD03), &position, 0, 0);
            if (target != NULL && ((TObjChara *)target)->select_melee_contact_body(this, 1.0f) != 0) {
                ((TObjChara *)target)->receive_physical_attack(this, 1.0f);
                ((TObjChara *)target)->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if (variant != 0 && random_ratio() <= 0.16666667f) {
                    DirectAttackPayload p = {0x11, 0};
                    ((TObjChara *)target)->receive_direct_attack(this, p, 0, -1, -1);
                }
            }
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        h0 = ((SampledMotionPoints *)((void *)lbl_80500AF0[collapsed]))->lookup((f32)frame);
        h1 = ((SampledMotionPoints *)((void *)lbl_80500AF8[collapsed]))->lookup((f32)frame);
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        if (h0 != 0) {
            matrix_mult_vec_array(NULL, h0, &a1, 2);
            saver->vfunc_6(&a1, &b1);
        }
        if (h1 != 0) {
            saddr start = (saddr)&a2;
            matrix_mult_vec_array(NULL, h1, (Vec *)start, 2);
            saver->vfunc_6((Vec *)start, &b2);
        }
        pop_matrix();
        if (action_flags != 4) {
            update_if_active(1);
            state = -1;
        }
        break;
    case -1:
        actorFlags &= ~0x200000;
        break;
    }
}

void TObjEneDubchik::update_shoot() {
    s32 fire;
    switch ((s32)state) {
    case 0:
        if (parts[2] != NULL) {
            update_if_active(1);
            state = -1;
            break;
        }
        shot_count = (s16)parameters[0];
        if (shot_count == 0) {
            shot_count = 2;
        }
        {
            s16 v = 8;
            if (collapsed != 0) {
                v = 9;
            }
            requested_action = v;
        }
    case 1:
        if (shot_count == 1) {
            s16 v = 0x11;
            if (collapsed != 0) {
                v = 0x12;
            }
            requested_action = v;
        }
        state = 2;
    case 2:
        if (target != NULL) {
            VecCopy(destination(), &((TObjChara *)target)->body_center);
            enemy_turn_toward_dest(((EnemyMoveParams *)movementParameters)->turn_speed);
        }
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        fire = 0;
        if (collapsed != 0) {
            if (requested_action != 9) {
                fire = is_passing_frame(2.0f);
            }
        } else if (requested_action != 8) {
            fire = is_passing_frame(2.0f);
        }
        if (fire != 0) {
            render_anim_model_at_pos();
            get_anim_node_position(0x22, &muzzle_position);
            effect = create_particle_emitter(&muzzle_position, 0x119);
            timer = sub_800AAF98(1);
            state = 3;
        }
        break;
    case 3:
        if (target != NULL) {
            VecCopy(destination(), &((TObjChara *)target)->body_center);
            enemy_turn_toward_dest(((EnemyMoveParams *)movementParameters)->turn_speed);
        }
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        render_anim_model_at_pos();
        get_anim_node_position(0x22, &muzzle_position);
        if (effect != NULL) {
            effect->set_position(&muzzle_position);
        }
        if (--timer <= 0) {
            shot_count--;
            new TUnk_80491460(&muzzle_position, rotation_y, (saddr)this, sub_800AAF98(3));
            state = 4;
            if (effect != NULL) {
                effect->queue_destruction();
                effect = NULL;
            }
            play_sound_effect(remap_sound_for_area(0x4003AD04), &position, 0, 0);
        }
        break;
    case 4:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        if (shot_count > 0) {
            if (collapsed != 0) {
                fire = is_passing_frame(6.0f);
            } else {
                fire = is_passing_frame(7.0f);
            }
            if (fire != 0) {
                timer = 0xF;
                state = 5;
            }
        } else if (action_flags != 4U) {
            timer = 0x1E;
            state = 6;
        }
        break;
    case 5:
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        timer = timer - 1;
        if (timer <= 0) {
            state = 1;
        }
        break;
    case 6:
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        timer = timer - 1;
        if (timer <= 0) {
            if (shot_count > 0) {
                state = 1;
            } else {
                update_if_active(1);
                state = -1;
            }
        }
        break;
    case -1:
        if (effect != NULL) {
            effect->queue_destruction();
            effect = NULL;
        }
        break;
    }
}

void TObjEneDubchik::update_timed_state() {
    s16 t;
    switch ((s32)state) {
    case 0:
        requested_action = (m_388 & 0x1000000) ? 0 : 5;
        m_388 |= 0x800000;
        state = 1;
    case 1:
        if (!(actorFlags & 0x800000)) {
            apply_actor_gravity(this, NULL, 0.0f);
        }
        if (actorFlags & 0x40000) {
            t = timer;
            timer = t - 1;
            if (t < 0) {
                state = -1;
            }
        }
        break;
    case -1:
        actorFlags &= 0xFFFBFFFF;
        timer = resetTimer;
        break;
    }
}

void TObjEneDubchik::update_appear() {
    switch (state) {
    case 0:
        m_388 |= 4;
        actorFlags |= 0x04000000;
        requested_action = 5;
        advance_animation();
        TBoss3Volopt__sub_800D8D88((saddr)&body_center);
        fade.start_fade_in();
        state = 1;
    case 1:
        if (fade.advance_toward_max() == 1) {
            state = -1;
        }
        return;
    case -1:
        m_388 &= ~5;
        actorFlags &= 0xFBFFFFFF;
        update_if_active(0);
        break;
    }
}

extern "C" void TObjPlayer__sub_800A8C4C(u8 *actor) {
    f32 var_f31;
    s32 var_r0;
    switch (*(s32 *)((s8 *)actor + 0x37C)) {
    case -1:
        break;
    case 0:
        if (TObjEneDD::check_v2_mode() == 0) {
            if (*(s16 *)((s8 *)actor + 0x392) != 0) {
                var_r0 = 7;
            } else {
                var_r0 = *(s32 *)((s8 *)((u8 *)lbl_804910EC + (*(s32 *)((s8 *)actor + 0x368) * 4)) + 0);
            }
            *(s16 *)((s8 *)actor + 0xB8) = (s16) var_r0;
        } else {
            *(s16 *)((s8 *)actor + 0xB8) = 0;
        }
        VecCopy((Vec *)((u8 *)actor + 0x29C), (const Vec *)((u8 *)actor + 0x50));
        *(s32 *)((s8 *)actor + 0x37C) = 1;
        return;
    case 1:
        ((TObjMotion *)actor)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)((void *)actor)), (s32 *)(0), 0.0f);
        ((TObjPlayer *)actor)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)actor);
        if (*(s16 *)((s8 *)actor + 0x392) != 0) {
            var_f31 = ((TObjEneDubchik *)actor)->sub_800AAF78(2);
        } else {
            var_f31 = *(f32 *)((s8 *)((u8 *)lbl_804910E4 + (*(s32 *)((s8 *)actor + 0x368) * 4)) + 0);
        }
        VecCopy((Vec *)((u8 *)actor + 0x290), (const Vec *)((u8 *)actor + 0x2FC));
        calc_velocity_toward_destination((void *)actor, *(Vec_800A8C4C *)(actor + 0x290), *(Vec_800A8C4C *)(actor + 0x29C), var_f31);
        ((TObjEnemy *)actor)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)actor)->movementParameters + 8), (Vec *)((u8 *)actor + 0x308));
        move_with_wall_slide((actor));
        if (xz_distance_squared((Vec *)((u8 *)actor + 0x38), (Vec *)((u8 *)actor + 0x50)) < 100.0f) {
            *(s16 *)((s8 *)actor + 0xB8) = 5;
            ((TObjMotion *)actor)->advance_animation();
            *(s32 *)((s8 *)actor + 0x388) = (s32) (*(s32 *)((s8 *)actor + 0x388) & 0xFE7FFFFF);
            ((TObjEnemyCustom *)actor)->update_if_active(0);
        }
        return;
    }
}

void TObjEneDubchik::start_dying() {
    m_388 |= 0x02000000;
    obj_setFlags30(this, 0x800U);
}

void TObjEneDubchik::sub_800A8B8C() {
    lbl_804910F4[2].speed = sub_800AAF78(0);
    lbl_804910F4[7].speed = sub_800AAF78(3);
    lbl_804910F4[12].speed = sub_800AAF78(4);
    ((AttackParams *)m_318)->set_attack_range(sub_800AAF78(collapsed ? 5 : 1));
}

void TObjEneDubchik::render_model_and_set_attach_points() {
    render_anim_model_at_pos();
    get_anim_node_position(0x13, &part_offsets[0]);
    get_anim_node_position(0x28, &part_offsets[1]);
    get_anim_node_position(0x29, &part_offsets[2]);
}

void TObjEneDubchik::sub_800A8A7C() {
    u8 *g = lbl_805009A0;
    if (m_388 & 0x20000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x68));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x68));
    }
    if (m_388 & 0x40000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x78));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x78));
    }
    if (m_388 & 0x80000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0xA8));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0xA8));
    }
}

s32 TObjEneDubchik::update_shock_clock() {
    if (TObjChara::update_shock_clock() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

s32 TObjEneDubchik::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

void TObjEneDubchik::clear_state7_flag() {
    if ((s32)next_action == 7) {
        m_388 &= 0xFFFFFFFE;
        update_if_active(0);
    }
}

void TObjEneDubchik::set_flag_start_effect() {
    u32 flags = m_388;
    if (!(flags & 0x04000000)) {
        m_388 = flags | 0x04000000;
        m_388 |= 1;
        m_388 &= 0xFF7FFFFF;
        timer = 0x1E;
        TObjPlayer::create_dead_spot((saddr)&body_center, timer, 2.0f);
    }
}

void TObjEneDubchik::update_dying() {
    set_flag_start_effect();
    if (--timer <= 0) {
        if (TLobby::get_instance() != 0) {
            play_sound_effect(0x4003AD10, &position, 0, 0);
        } else {
            play_sound_effect(remap_sound_for_area(0x4003AD16), &position, 0, 0);
        }
        TBoss3Volopt::create_breakup_mdl((saddr)breakup_model_ptr, (saddr)&lbl_80491260, texlist, (saddr)&body_center, rotation_y);
        ((TObjPlayer *)this)->refresh_lobby_state();
        send_entity_set_flags();
        ((TObjPlayer *)&body_center)->trigger_dell_biter_events();
        obj_setFlags30(this, 0x800);
        queue_destruction();
    }
}

// The loader's file names are local statics of inline accessors, so the loader addresses each by its own
// symbol (not through the unit's .rodata base). They follow the unit's other .rodata, so they are defined last.
inline const char *dubchik_bml_filename() {
    static const char bm_ene_dubchik_a_bml_filename[] = "bm_ene_dubchik_a.bml";
    return bm_ene_dubchik_a_bml_filename;
}
inline const char *dubchik_v2_gvm_filename() {
    static const char me2_y_me2_z_a_gvm_filename[] = "me2_y_me2_z_a.gvm";
    return me2_y_me2_z_a_gvm_filename;
}
inline const char *dubchik_gvm_filename() {
    static const char me2_y_me2_z_gvm_filename[] = "me2_y_me2_z.gvm";
    return me2_y_me2_z_gvm_filename;
}
