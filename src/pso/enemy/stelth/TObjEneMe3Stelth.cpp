#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/GroundContactSound.h"
#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/stelth/StelthData.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/stelth/TObjEneMe3StelthReal.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/player/TObjPlayer.h"
#include "pso/animation/MotionContext.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResource.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/unk/TLobby.h"
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/npc/TObjNpcEnemy_803D8090.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth_803DC82C.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/enemy/dd/TObjEneDD_800B9A34.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa_800D72A4.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/technique/TTecDeband.h"
#include "pso/ui/TLevelSelect.h"

#pragma readonly_strings on

// Class names the two constructors store in m_name (.sdata).
const char *TObjEneMe3Stelth__class_name = stelth_class_name;
const char *TObjEneMe3StelthReal__class_name = stelth_real_class_name;


extern "C" {
s32 is_split_screen();
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 select_enemy_destination(void *, Vec *, int);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
extern StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[];
u16 get_entity_id(void *);
extern CollisionBody TObjEneMe3Stelth__collision_body_template;
BmlResource *TObjEneMe3Stelth__bml_resource;
s32 TObjEneMe3Stelth__render_node_index;
TUnk_8048FA00 *TObjEneMe3Stelth__breakup_model;
SampledMotionPoints *TObjEneMe3Stelth__trail_buffer;
s32 stelth_projection_texture_handle;
f32 lbl_805010E0[3];
__declspec(section ".data") saddr TObjEneMe3Stelth__base_params_by_variant[2];
__declspec(section ".data") saddr TObjEneMe3Stelth__attack_params_by_variant[2];
__declspec(section ".data") saddr TObjEneMe3Stelth__resistance_params_by_variant[2];
__declspec(section ".data") StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[2];
__declspec(section ".data") NJS_TEXLIST TObjEneMe3Stelth__alternate_texture_list;
f32 lbl_80501114[3];
u32 *TObjEneMe3Stelth__material_color_pointers[4];


s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(void *);
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;


void action__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 reason);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
f32 *TBoss3Volopt__sub_800F059C(void *);
f32 atan2_float(f32 y, f32 x);


f32 fabs_float(f32);


extern void *lbl_80497710[2];
extern void *lbl_80497718[12];
extern void *stelth_bml_resource_desc[4];
extern void *lbl_80497758[2];
extern void *lbl_80497760[12];
extern void *me3_stelth_bml_resource_desc[4];
void *TObjEneMe3Stelth__shared_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody TObjEneMe3Stelth__collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};
__declspec(section ".data") void *lbl_80497710[2] = {
    (void *)stelth_model, (void *)0x0,
};
void *lbl_80497718[12] = {
    (void *)stelth_t_wait_motion, (void *)stelth_apper_motion, (void *)stelth_backstep_motion, (void *)stelth_bareta_motion,
    (void *)stelth_damage_motion, (void *)stelth_death_motion, (void *)stelth_f_attack_motion, (void *)stelth_sword_motion,
    (void *)stelth_transform_motion, (void *)stelth_wait_motion, (void *)stelth_walk_motion, (void *)0x0,
};
void *stelth_bml_resource_desc[4] = {
    (void *)stelth_bml, (void *)&lbl_80497710, (void *)&lbl_80497718, (void *)0x1000b,
};
__declspec(section ".data") void *lbl_80497758[2] = {
    (void *)stelth_low_model, (void *)0x0,
};
void *lbl_80497760[12] = {
    (void *)stelth_t_wait_motion, (void *)stelth_apper_motion, (void *)stelth_backstep_motion, (void *)stelth_bareta_motion,
    (void *)stelth_damage_motion, (void *)stelth_death_motion, (void *)stelth_f_attack_motion, (void *)stelth_sword_motion,
    (void *)stelth_transform_motion, (void *)stelth_wait_motion, (void *)stelth_walk_motion, (void *)0x0,
};
void *me3_stelth_bml_resource_desc[4] = {
    (void *)stelth_low_bml, (void *)&lbl_80497758, (void *)&lbl_80497760, (void *)0x1000b,
};
TObjMotionAction TObjEneMe3Stelth__animation_descriptors[13] = {
    {MOTION_MODE_LOOP, 0, 0, 0.5f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_ONCE, 0, 1, 0.7f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_LOOP, 0, 9, 0.5f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_ONCE, 0, 2, 0.8f, 0},
    {MOTION_MODE_ONCE, 0, 4, 0.4f, 0},
    {MOTION_MODE_ONCE, 0, 5, 0.6f, 0},
    {MOTION_MODE_ONCE, 0, 6, 0.7f, 0},
    {MOTION_MODE_ONCE, 0, 7, 1.0f, 0},
    {MOTION_MODE_ONCE, 0, 8, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 9, 0.5f, 0},
    {MOTION_MODE_LOOP, 0, 10, 1.1f, 0},
    {MOTION_MODE_ONCE, 0, 3, 0.7f, 0},
    {MOTION_MODE_ONCE, 0, 8, 1.0f, 0},
};





void draw_model__16TObjEneMe3StelthFPv(TObjEneMe3Stelth *stelth) {
    stelth->draw_ginja_motion_model();
}
void TObjEneDD_ST::sub_800F5874(s32 arg1) {
    this->m_11c = (s16) (this->m_11c | arg1);
}
void TObjEneDD_ST::sub_800F5864(s32 arg1) {
    this->m_11c = (s16) (this->m_11c & ~arg1);
}
void TObjEneMe3Stelth::load_shared_resources() {
    s32 i;
    NJS_TEXLIST *src;
    s32 n;
    StelthBehaviorParams *d;
    u32 m;
    NJS_CNK_MODEL *q;
    AnimationMotion *motion;
    void *p;

    lbl_805010E0[0] = 0.0f;
    lbl_805010E0[1] = 0.0f;
    lbl_805010E0[2] = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneMe3Stelth__bml_resource = load_enemy_bml_resource((BmlResourceDescriptor *)me3_stelth_bml_resource_desc);
    } else {
        TObjEneMe3Stelth__bml_resource = load_enemy_bml_resource((BmlResourceDescriptor *)stelth_bml_resource_desc);
    }
    src = (NJS_TEXLIST *)TObjEneMe3Stelth__bml_resource->models->m_c;
    n = src->nbTexture;
    TObjEneMe3Stelth__alternate_texture_list.nbTexture = n;
    TObjEneMe3Stelth__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        ((TObjPlayer *)&TObjEneMe3Stelth__alternate_texture_list.textures[i])->copy_vec3(&src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3Stelth__alternate_texture_list.textures[i].texaddr = TObjEneMe3Stelth__alternate_texture_list.textures[i + 3].texaddr;
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__base_params_by_variant[i] = (saddr)TLobby::register_boss(lbl_8043D47C[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__attack_params_by_variant[i] = (saddr)TLobby::dispatch_shared_handler_b(lbl_8043D484[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__resistance_params_by_variant[i] = (saddr)TLobby::register_object(lbl_8043D48C[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__behavior_params_by_variant[i] = (StelthBehaviorParams *)TLobby::dispatch_shared_handler_a(lbl_8043D494[i]);
    }
    d = TObjEneMe3Stelth__behavior_params_by_variant[0];
    TObjEneMe3Stelth::set_slot_min_clamped_value(7, d->m_0c);
    TObjEneMe3Stelth::set_slot_min_clamped_value(4, d->m_10);
    TObjEneMe3Stelth__render_node_index = 0;
    lbl_80501114[0] = 0.0f;
    lbl_80501114[1] = 0.0f;
    lbl_80501114[2] = 0.0f;
    m = (saddr)TObjEneMe3Stelth__bml_resource->models->model;
    q = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(m, 9))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[0] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[0] = 0;
    }
    q = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(m, 0xD))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[1] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[1] = 0;
    }
    q = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(m, 0x26))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[2] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[2] = 0;
    }
    motion = TObjEneMe3Stelth__bml_resource->motions[TObjEneMe3Stelth__animation_descriptors[5].motion].motion;
    if (is_split_screen() != 0) {
        p = new TUnk_8048FA00(TObjEneMe3Stelth__bml_resource->models->model, (NJS_MOTION *)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        TObjEneMe3Stelth__breakup_model = (TUnk_8048FA00 *)p;
    } else {
        p = new TUnk_8048FA00((long)(saddr)TObjEneMe3Stelth__bml_resource->models->model, (long)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        TObjEneMe3Stelth__breakup_model = (TUnk_8048FA00 *)p;
    }
    {
        Vec va;
        Vec vb;
        saddr mdl;
        AnimationMotion *trail_motion;
        BmlResource *r = TObjEneMe3Stelth__bml_resource;
        s32 idx = TObjEneMe3Stelth__animation_descriptors[6].motion;
        mdl = (saddr)r->models->model;
        va.x = 0.0f;
        va.y = 0.0f;
        va.z = 0.0f;
        vb.x = -10.0f;
        vb.y = 0.0f;
        vb.z = 0.0f;
        trail_motion = r->motions[idx].motion;
        TObjEneMe3Stelth__trail_buffer = new SampledMotionPoints(2, 16.0f, 26.0f, 0.7f);
        TObjEneMe3Stelth__trail_buffer->sample_node_offsets((NJS_OBJECT *)mdl, (NJS_MOTION *)trail_motion, 0x22, &va, &vb);
    }
    {
        NpcAnimationBinding a = stelth_attack_binding_desc_a;
        a.motions = TObjEneMe3Stelth__bml_resource->motions;
        NpcAnimationBinding b = stelth_attack_binding_desc_b;
        b.motions = TObjEneMe3Stelth__bml_resource->motions;
        NpcModelRegistry::register_animated_ginja(0x2B, reinterpret_cast<NJS_OBJECT *>(TObjEneMe3Stelth__bml_resource->models->model),
                                                  reinterpret_cast<GinjaTextureList *>(TObjEneMe3Stelth__bml_resource->models->m_c), &a, 8.0f, 0.0f);
        NpcModelRegistry::register_animated_ginja(0x2D, reinterpret_cast<NJS_OBJECT *>(TObjEneMe3Stelth__bml_resource->models->model),
                                                  reinterpret_cast<GinjaTextureList *>(TObjEneMe3Stelth__bml_resource->models->m_c), &b, 8.0f, 0.0f);
    }
}
void *TObjEneMe3Stelth::create_real() { return TObjEneMe3StelthReal::create(this); }
void TObjEneMe3Stelth::free_shared_resources() {
    if (TObjEneMe3Stelth__trail_buffer != NULL) {
        delete TObjEneMe3Stelth__trail_buffer;
        TObjEneMe3Stelth__trail_buffer = NULL;
    }
    if (TObjEneMe3Stelth__breakup_model != NULL) {
        delete TObjEneMe3Stelth__breakup_model;
        TObjEneMe3Stelth__breakup_model = NULL;
    }
    if (TObjEneMe3Stelth__alternate_texture_list.textures != NULL) {
        mem_free(TObjEneMe3Stelth__alternate_texture_list.textures);
        TObjEneMe3Stelth__alternate_texture_list.textures = NULL;
    }
    if (TObjEneMe3Stelth__bml_resource != NULL) {
        delete TObjEneMe3Stelth__bml_resource;
        TObjEneMe3Stelth__bml_resource = NULL;
    }
}
void TObjEneMe3Stelth::set_slot_min_clamped_value(s32 arg0, f32 farg0) {
    f32 speed = farg0;
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    TObjEneMe3Stelth__animation_descriptors[arg0].speed = speed;
}
TObjEneMe3Stelth::TObjEneMe3Stelth(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3Stelth__class_name;
}
#pragma push
#pragma opt_propagation off
void TObjEneMe3StelthReal::init_common() {
    BmlModelEntry *entry;
    f32 y;
    s32 v;

    init_position_vectors();
    sub_800F4758();
    entry = TObjEneMe3Stelth__bml_resource->models;
    model = (void *)entry->model;
    init_model(&TObjEneMe3Stelth__collision_body_template, 1);
    motion_flags = 0;
    set_field_d8((saddr)TObjEneMe3Stelth__animation_descriptors);
    set_field_dc((saddr)TObjEneMe3Stelth__bml_resource->motions);
    set_animation(requested_action);
    v = m_3c8;
    reset_hp((u8 *)TObjEneMe3Stelth__base_params_by_variant[v], (u8 *)TObjEneMe3Stelth__attack_params_by_variant[v], (u8 *)TObjEneMe3Stelth__resistance_params_by_variant[v]);
    set_state_flag_4();
    movementParameters = TObjEneMe3Stelth__shared_params;
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    m_3cc = 0;
    y = position.y;
    m_3d0 = y;
    m_3d4 = 0.0f;
    m_3e8 = 0;
    m_3ec = 0;
    m_3f4 = m_2cc;
    m_404.reset_obstruction_fade();
    m_424 = 0;
    m_428 = 0;
    m_42c = 0;
    m_430 = 0.0f;
    m_434 = 0.0f;
    m_438 = 0.0f;
    m_43c = 0.0f;
    m_440 = 0.0f;
    m_444 = NULL;
    m_448 = NULL;
    m_420 = 0;
    if (m_3c0 == 1) {
        set_indexed_flags(0, 0x08000000);
        return;
    }
    clear_player_status_flag(0, 0x08000000);
}
#pragma pop
TObjEneMe3Stelth::~TObjEneMe3Stelth() {
    if (m_444 != NULL) {
        m_444->queue_destruction();
        m_444 = NULL;
    }
    if (m_448 != NULL) {
        m_448->queue_destruction();
        m_448 = NULL;
    }
    free_collision_body_parts(this);
}
void TObjEneMe3Stelth::run_task() {
    s32 flags;
    if (TObjPlayer::check_demo_mode() != 0) {
        setup_move();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
    }
    copy_pos_with_height_offset();
    update_body_colliders();
    flags = m_3cc;
    if (flags & 0x40000) {
        m_3cc = flags & ~0x40000;
        return;
    }
    submit_default_cursor_candidate();
}
void TObjEneMe3Stelth::refresh_target() {  }
void TObjEneMe3Stelth::run_death_reaction() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
}
void TObjEneMe3Stelth::run_hit_reaction() {
    if (m_3cc & 1) {
        clear_attack_receipts();
        if (m_3c0 == 1 && random_ratio() <= m_3e0) {
            transition_enemy_state(0x12);
        }
    } else if (mode != 0xE) {
        transition_enemy_state(0xE);
    }
}
void TObjEneMe3Stelth::run_miss_reaction() {  }
void TObjEneMe3Stelth::copy_pos_with_height_offset() {
    VecCopy(&body_center, &position);
    body_center.y += 12.0f + m_3d4;
    VecCopy(&center, &body_center);
}
void TObjEneMe3Stelth::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}
void TObjEneMe3Stelth::setup_move_bounds() {
    if (sub_800F4850() != 0) {
        m_3c0 = 1;
    } else {
        m_3c0 = 0;
    }
    m_3c4 = is_angle_in_range();
    if (m_3c4 == 1) {
        requested_action = 2;
    } else {
        requested_action = 0;
    }
    m_3d8 = 0.4f + parameters[2];
    m_3dc = 0.3f + parameters[1];
    m_3e0 = 0.1f + parameters[4];
    m_3e4 = 0.5f + parameters[3];
    m_3f0 = variant;
}
f32 TObjEneMe3Stelth::get_node_world_y() {
    Vec v;
    NJS_OBJECT *node;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    bind_motion_context(current_motion, frame);
    node = (NJS_OBJECT *)model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}
// inferred parameter names: the callers pass a facing (rotation_y, m_42c + 0x8000) and the
// distance to test, which becomes a body of radius half that distance, centred half that far ahead.
s32 TObjEneMe3Stelth::test_body_collision(s32 angle, f32 distance) {
    CollisionBody *s = bodies;
    u8 res;
    s32 a = rotation_y;
    s32 b = s->flags;
    distance *= 0.5f;
    s->offset.x = 0.0f;
    s->offset.z = distance;
    s->radius = distance;
    s->half_width = 8.0f;
    s->shape = 1;
    s->flags = 0x9D01;
    rotation_y = angle;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(this, angle, 0.0f, distance);
    res = (s->flags & 0x380000) != 0;
    copy_collision_body(s, &TObjEneMe3Stelth__collision_body_template);
    s->flags = b;
    rotation_y = a;
    return res;
}
#pragma push
#pragma fp_contract on
s32 TObjEneMe3Stelth::sub_800F4C10(f32) {
    f32 facing;
    if (fabs_float(current_target->position.y - position.y) >= 20.0f) {
        return 0;
    }
    if (destination_distance > 25.0f) {
        return 0;
    }
    facing = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
    if (facing < cos_table_lookup(0x1E00)) {
        return 0;
    }
    return 1;
}
#pragma pop
void TObjEneMe3Stelth::attack_and_unequip() {
    s32 near = is_passing_frame(23.0f);
    if (is_passing_frame(15.0f) == 0 && near == 0) {
        return;
    }
    if (enemy_check_target_valid() != 0 && current_target->select_melee_contact_body(this, 1.0f) != 0) {
        f32 d = current_target->receive_physical_attack(this, 1.0f);
        current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
        if (d > 0.0f) {
            if (sub_800F47D4() != 0) {
                TObjChara *t = current_target;
                TItem *held;
                if (TObjPlayer::is_locally_controlled(t) != 0 && (held = (TItem *)TObjPlayer::get_item_field_6(t)) != 0) {
                    TObjPlayer::send_6x26_unequip_item((void *)t, held->get_item_id());
                    ((TObjPlayer *)t)->get_hand_joint_position((saddr)&m_3f8);
                    spawn_particle_effect(&m_3f8, 0x1D0);
                }
            } else if (near != 0 && random_ratio() <= 0.1666f) {
                TObjEneDD__sub_800BA438(this, current_target);
            }
        }
    }
    play_sound_effect(0x3AA37, (u8 *)&position, 0, 0);
}
void TObjEneMe3Stelth::vfunc_108() {  }
s32 TObjEneMe3Stelth::check_target_in_range() {
    f32 temp_f1;
    s32 var_r31;

    var_r31 = 0;
    if (!(m_3cc & 0x10000)) {
        temp_f1 = destination_distance;
        if ((temp_f1 > 100.0f) && (temp_f1 < 150.0f) && (test_body_collision(rotation_y, temp_f1 - 20.0f) == 0)) {
            var_r31 = 1;
        }
    }
    return (u8)var_r31;
}
void TObjEneMe3Stelth::select_next_attack_state() {  }
s32 TObjEneMe3Stelth::check_active_flag() {
    if (m_3cc & 4) {
        m_404.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}
s32 TObjEneMe3Stelth::check_flag() {
    if (m_3cc & 4) {
        m_404.clear_flag_and_notify();
        return 1;
    }
    return 0;
}
void TObjEneMe3Stelth::on_target_lost() {  }
void TObjEneMe3Stelth::set_intangible() { TObjEneDD::set_intangible(); sub_800F5874(38); }
void TObjEneMe3Stelth::clear_intangible() { TObjEneDD::clear_intangible(); sub_800F5864(38); }
void TObjEneMe3Stelth::vfunc_112() {  }
void TObjEneMe3Stelth::update_distance_state() {
    if (m_3d0 - position.y > 30.0f) {
        set_colliders_contact_high();
        return;
    }
    set_colliders_contact_low();
}
void TObjEneMe3Stelth::check_collisions() {
    update_body_colliders();
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
}
s32 TObjEneMe3Stelth::sub_800F4850() {
    return parameters[0] < 2.0f;
}
s32 TObjEneMe3Stelth::is_angle_in_range() {
    return parameters[0] < 1.0f ||
           (parameters[0] >= 2.0f && parameters[0] < 3.0f);
}
s32 TObjEneMe3Stelth::acquire_target(f32 f) { return select_and_apply_target(f); }
s32 TObjEneMe3Stelth::sub_800F47D4() {
    return m_3f0 >= 1;
}
void TObjEneMe3Stelth::sub_800F4758() {
    if (sub_800F47D4() != 0) {
        texlist = (saddr)&TObjEneMe3Stelth__alternate_texture_list;
        initialize_enemy_state(0x3F);
        m_3c8 = 1;
        return;
    }
    texlist = (saddr)TObjEneMe3Stelth__bml_resource->models->m_c;
    initialize_enemy_state(0x3E);
    m_3c8 = 0;
}
void TObjEneMe3Stelth::create_resta_effect() {
    saddr f = TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->support_tech_level);
    TTecResta::create((void *)this, (u8 *)&this->position, f);
}
void TObjEneMe3Stelth::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        vfunc_113(reason);
        break;
    case 1:
        sub_800F42B8(reason);
        break;
    case 3:
        sub_800F3FE4(reason);
        break;
    case 2:
        state_chase(reason);
        break;
    case 4:
        update_state_fade_in(reason);
        break;
    case 5:
        update_state_drop(reason);
        break;
    case 6:
        state_chase_target(reason);
        break;
    case 7:
        sub_800F348C(reason);
        break;
    case 8:
        sub_800F3214(reason);
        break;
    case 9:
        run_walk_state(reason);
        break;
    case 13:
        handle_message(reason);
        break;
    case 10:
        action__16TObjEneMe3StelthFPvi(this, reason);
        break;
    case 11:
        update_state_resta_cast(reason);
        break;
    case 14:
        sub_800F290C(reason);
        break;
    case 15:
        handle_breakup_state(reason);
        break;
    case 12:
        sub_800F2270(reason);
        break;
    case 16:
        sub_800F1098(reason);
        break;
    case 17:
        exec(reason);
        break;
    case 18:
        sub_800F1440(reason);
        break;
    }
    if (m_3c0 != 1 || ((s32)state != 1 && (s32)state != 2)) {
        render_minimap_dot();
    }
}
void TObjEneMe3Stelth::vfunc_113(s32 reason) {
    switch (reason) {
    case 4:
        if (m_3c4 == 1) {
            requested_action = 2;
            set_field_378(1);
        } else {
            requested_action = 0;
            set_field_378(3);
        }
        set_intangible();
        m_3cc |= 2;
        m_3cc &= ~1;
        if (TObjEneDD::check_v2_mode() != 0) {
            m_3cc &= ~0x10000;
        }
        m_424 = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        m_3d0 = position.y;
        m_3e8 = 0;
        m_3ec = 0;
        return;
    case 3:
        if (m_424 > 5) {
            if (m_3c4 == 1) {
                transition_enemy_state(1);
            } else {
                transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        m_424++;
        if (m_424 == 1) {
            m_3d0 = position.y;
            update_ground_contact();
            m_3d4 = m_3d0 - position.y;
        }
        break;
    }
}
void TObjEneMe3Stelth::sub_800F42B8(s32 reason) {
    Vec v;
    f32 t;
    switch (reason) {
    case 4:
        requested_action = 2;
        set_field_378(0);
        set_intangible();
        m_3cc &= ~2;
        m_3cc |= 5;
        m_404.start_fade_in();
        VecCopy(&v, &position);
        t = m_3d0;
        v.y = t - 20.0f;
        if (m_3c0 == 0) {
            TBoss3Volopt__sub_800D8D88(&v, t);
        } else {
            create_timed_particle_emitter((u8 *)&position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (m_404.advance_toward_max() != 0) {
            if (m_3c0 == 1) {
                transition_enemy_state(2);
            } else {
                transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (*TBoss3Volopt__sub_800F059C(&m_404) >= -0.75f) {
            advance_animation();
        }
        update_ground_contact();
        break;
    case 5:
        m_3cc &= ~4;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase(s32 arg1) {
    s32 temp_r0;
    switch (arg1) {
    case 4:
        requested_action = 9;
        set_field_378(0xD);
        clear_intangible();
        m_3cc &= ~7;
        m_424 = 0;
        m_428 = 0;
        m_434 = 0.0f;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            if (destination_distance <= 40.0f) {
                transition_enemy_state(0xD);
                break;
            }
            temp_r0 = m_428 - 1;
            m_428 = temp_r0;
            if ((temp_r0 <= 0) && (check_target_in_range() != 0)) {
                m_428 = 0x3C;
                if (random_ratio() <= 0.01f) {
                    transition_enemy_state(7);
                    break;
                }
            }
        } else {
            if (m_424 >= 0xE10) {
                transition_enemy_state(0xD);
                break;
            }
        case 5:
            break;
        }
        break;
    case 0:
        m_424++;
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            m_434 = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
            if (m_434 < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                update_ground_contact();
            }
        }
        check_collisions();
        break;
    }
}
#pragma pop
void TObjEneMe3Stelth::sub_800F3FE4(s32 reason) {
    Vec pos;
    f32 temp_f1;
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->m_3cc |= 7;
        this->m_404.start_fade_in();
        VecCopy(&pos, &this->position);
        temp_f1 = this->m_3d0;
        pos.y = temp_f1 - 10.0f;
        TBoss3Volopt__sub_800D8D88(&pos, temp_f1);
        break;
    case 3:
        if (this->m_404.advance_toward_max() != 0) {
            this->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        this->m_3cc &= ~4;
        break;
    }
}
void TObjEneMe3Stelth::update_state_fade_in(s32 reason) {
    s32 t;
    switch (reason) {
    case 4:
        requested_action = 0;
        set_field_378(5);
        set_intangible();
        m_3cc &= ~7;
        m_424 = 0;
        m_428 = 0;
        break;
    case 3:
        if (m_424 > 0x1E) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (m_424 == 0) {
            if (update_linked_position(200.0f) != 0) {
                m_424 = 1;
                static const u32 color_mask = 0xFFFF00FF;
                m_3e8 = 0x1C00FFFF;
                m_3e8 &= color_mask;
                m_428 = 0;
            }
        } else {
            m_424 += 1;
            m_428 += 0x10;
            if (m_428 > 0xFF) {
                m_428 = 0xFF;
            }
            t = m_428;
            m_3e8 = (t << 24) | (m_3e8 & 0x00FFFFFF);
            if (enemy_validate_retained_target(this) == 0) {
                m_424 = 0;
                m_3e8 = 0;
            }
        }
        update_ground_contact();
        update_distance_state();
        check_collisions();
        m_3d4 = m_3d0 - position.y;
        break;
    case 5:
        m_3e8 = 0x1C00FFFF;
        m_3d4 = 0.0f;
        break;
    }
}
void TObjEneMe3Stelth::update_state_drop(s32 reason) {
    f32 node_world_y;
    f32 temp_f31;

    switch (reason) {
    case 4:
        requested_action = 1;
        set_field_378(0xD);
        clear_intangible();
        m_3cc &= ~6;
        m_3cc |= 1;
        m_424 = 0;
        m_430 = 0.0f;
        if (enemy_has_live_target() != 0) {
            enemy_copy_target_destination();
            update_velocity();
        }
        break;
    case 3:
        if (m_424 == 3) {
            transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (m_424) {
        case 0:
            temp_f31 = get_node_world_y();
            advance_animation();
            m_434 = get_node_world_y();
            m_3d0 = m_3d0 + (temp_f31 - m_434);
            m_424 = 1;
            m_3d4 = m_3d0 - position.y;
            break;
        case 1:
            advance_animation();
            if (frame > 29.0f) {
                frame = 29.0f;
            }
            m_430 -= 0.3f;
            if (m_430 < -5.0f) {
                m_430 = -5.0f;
            }
            m_3d0 = m_3d0 + m_430;
            node_world_y = get_node_world_y();
            m_3d0 = m_3d0 - (node_world_y - m_434);
            m_434 = node_world_y;
            if (m_3d0 < position.y) {
                m_3d0 = position.y;
                m_424 = 2;
                play_hit_effect();
            }
            break;
        case 2:
            if (get_flag_b4() != 0) {
                requested_action = 9;
                m_424 = 3;
                m_3d0 = position.y;
                m_3d4 = 0.0f;
            }
            advance_animation();
            break;
        }
        update_ground_contact();
        update_distance_state();
        check_collisions();
        m_3d4 = m_3d0 - position.y;
        break;
    case 5:
        m_3cc &= ~1;
        m_3d4 = 0.0f;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase_target(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0xA;
        set_field_378(6);
        clear_intangible();
        m_3cc &= ~7;
        destination_distance = 300.0f;
        m_430 = TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->m_00;
        m_434 = 0.0f;
        return;
    case 3:
        if (current_target == NULL) {
            on_target_lost();
            transition_enemy_state(0xD);
            return;
        }
        if (sub_800F4C10(m_434) != 0) {
            transition_enemy_state(8);
            return;
        }
        if (check_target_in_range() != 0) {
            transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            sub_800F0C90();
            m_434 = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
            if (m_434 < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                update_ground_contact();
            } else {
                enemy_turn_and_move_on_ground(this, 0x500, m_430);
            }
            check_collisions();
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::sub_800F348C(s32 reason) {
    Vec v;
    Vec points[2];
    f32 t;
    s32 ang;
    Vec *entry;
    switch (reason) {
    case 4:
        this->requested_action = 6;
        this->set_field_378(6);
        this->clear_intangible();
        this->m_3cc &= ~7;
        this->m_3cc |= 0x10000;
        this->m_424 = 0;
        this->m_430 = 0.0f;
        this->set_active();
        break;
    case 3:
        if (this->m_424 == 5 || this->get_flag_b4() != 0) {
            if (this->update_ground_contact() == 0) {
                this->transition_enemy_state(0xA);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch (this->m_424) {
        case 0:
            this->advance_animation();
            if (this->motion_flags & 8) {
                this->m_424 = 1;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1:
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                ang = (s32)(10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
            } else {
                ang = this->rotation_y;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, ang, 0x1000);
            if (this->is_passing_frame(10.0f) != 0) {
                this->m_424 = 2;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 2:
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            if (this->frame + this->play_speed >= 14.0f) {
                if (this->test_body_collision(this->rotation_y, this->destination_distance - 20.0f) != 0) {
                    this->m_424 = 5;
                } else {
                    t = this->destination_distance - 20.0f;
                    VecCopy(&v, &this->position);
                    v.x += this->destination_direction.x * t;
                    v.y += 20.0f;
                    v.z += this->destination_direction.z * t;
                    if (csnVecterUnder(&v, 0x15) != 0) {
                        if (this->room == ((TScene *)(&v))->find_section_at_position()) {
                            this->m_424 = 3;
                            this->m_434 = (this->destination_distance - 20.0f) / 12.857143f;
                            this->set_invulnerable();
                            play_sound_effect(0x3A835, (u8 *)&this->position, 0, 0);
                        } else {
                            this->m_424 = 5;
                        }
                    } else {
                        this->m_424 = 5;
                    }
                }
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 3:
            this->advance_animation();
            if (this->frame + this->play_speed >= 23.0f) {
                this->m_424 = 4;
                this->clear_invulnerable();
                this->play_hit_effect();
            }
            this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, this->m_434);
            this->check_collisions();
            break;
        case 4:
            this->advance_animation();
            if (this->is_passing_frame(25.0f) != 0) {
                if (this->enemy_check_target_valid() != 0) {
                    if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                        this->current_target->receive_physical_attack(this, 1.0f);
                        this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                    }
                }
                play_sound_effect(0x3A838, (u8 *)&this->position, 0, 0);
            }
            this->m_434 *= 0.85f;
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->m_434);
            this->check_collisions();
            break;
        }
        if (this->m_424 != 0) {
            entry = TObjEneMe3Stelth__trail_buffer->lookup(this->frame);
            if (entry != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix((f32 *)&this->position);
                rotate_matrix_y(0, this->rotation_y);
                matrix_mult_vec_array(NULL, entry, (Vec *)points, 2);
                pop_matrix();
            }
        }
        break;
    case 5:
        this->m_3d0 = this->position.y;
        this->m_3d4 = 0.0f;
        this->clear_invulnerable();
        this->clear_field_388();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::sub_800F3214(s32 reason) {
    f32 temp_f1;
    s32 var_r4;
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->m_3cc &= ~7;
        this->m_3cc |= 0x10000;
        this->m_424 = 0;
        this->m_428 = 0;
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        switch (this->m_424) {
        case 0:
            this->attack_and_unequip();
            if (this->frame < 20.0f) {
                if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    var_r4 = (s32) (10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
                } else {
                    var_r4 = this->rotation_y;
                }
                this->rotation_y = approach_angle_limited(this->rotation_y, var_r4, 0x300);
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            this->vfunc_112();
            sub_800F0C90();
            temp_f1 = this->frame;
            if ((temp_f1 >= 0.0f) && (temp_f1 <= 5.0f)) {
                ((TObjEneDD *)this)->move_to_shot_position(this->destination_direction.x, this->destination_direction.z, TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->m_08);
            } else {
                this->update_ground_contact();
            }
            if (this->frame >= 25.0f) {
                this->frame = 25.0f;
                this->m_424 = 1;
            }
            break;
        case 1:
            this->m_428++;
            if (this->m_428 <= TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->m_20) {
                this->frame = 25.0f;
            }
            this->update_ground_contact();
            break;
        }
        this->check_collisions();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::run_walk_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 3;
        this->set_field_378(6);
        this->clear_intangible();
        this->m_3cc &= ~7;
        this->m_3ec = 0;
        this->m_424 = 3;
        if (this->acquire_target(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->m_42c = (s32) (10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
            if (this->test_body_collision(this->m_42c + 0x8000, 80.0f) == 0) {
                this->destination_direction.x *= -1.0f;
                this->destination_direction.z *= -1.0f;
                this->m_424 = 0;
                this->m_430 = 7.111111f;
            }
        }
        this->set_active();
        return;
    case 3:
        if (this->m_424 == 3) {
            if ((this->m_3c0 == 0) && (this->random_ratio() <= this->m_3dc)) {
                this->transition_enemy_state(0x11);
                return;
            }
            if (this->random_ratio() <= this->m_3d8) {
                if (this->sub_800F47D4() != 0) {
                    if (this->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->m_14) {
                        this->transition_enemy_state(0x10);
                        return;
                    }
                    this->transition_enemy_state(0xB);
                    return;
                }
                this->transition_enemy_state(0x10);
                return;
            }
            if (this->random_ratio() <= this->m_3e4) {
                this->transition_enemy_state(0xC);
                return;
            }
            this->transition_enemy_state(6);
        }
        return;
    case 0:
        this->advance_animation();
        switch (this->m_424) {
        case 0:
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x31C7);
            if ((this->frame + this->play_speed) >= 15.0f) {
                this->m_424 = 1;
                this->set_invulnerable();
                play_sound_effect(0x3A835, (u8 *)&this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        case 1:
            if ((this->frame + this->play_speed) >= 24.0f) {
                this->m_424 = 2;
                this->clear_invulnerable();
                this->play_hit_effect();
            }
            this->move_clamped_on_ground(this->destination_direction.x, this->destination_direction.z, this->m_430);
            return;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->m_424 = 3;
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        }
        break;
    case 5:
        this->clear_invulnerable();
        this->clear_field_388();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::update_state_resta_cast(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 8;
        set_field_378(0xB);
        clear_intangible();
        m_3cc &= ~6;
        m_3cc |= 1;
        m_424 = 0;
        m_428 = 0;
        return;
    case 3:
        if (m_428 > TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->m_1c) {
            transition_enemy_state(6);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (m_424) {
        case 0:
            if (get_flag_b4() != 0) {
                create_resta_effect();
                if (TObjEneDD::check_v2_mode() != 0) {
                    m_424 = 2;
                } else {
                    m_424 = 1;
                }
                m_428 = 0;
            }
            break;
        case 1:
            m_428++;
            break;
        case 2:
            m_428++;
            if (m_428 == 5) {
                TTecSifta::create((void *)this, (u8 *)&position, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->support_tech_level));
            } else if (m_428 == 0xA) {
                TTecDeband::create(this, (u8 *)&position, (s32)(TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->support_tech_level)));
                m_424 = 1;
                m_428 = 0;
            }
            break;
        }
        update_ground_contact();
        break;
    }
}
#pragma pop
}

void TObjEneMe3Stelth::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 9;
        this->set_field_378(0xD);
        this->m_3cc &= ~7;
        this->set_intangible();
        this->m_3ec = 0;
        this->m_424 = 0;
        break;
    case 3:
        if (this->update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(6);
        } else if (this->m_424 >= 0x5A) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        this->m_424++;
        this->advance_animation();
        this->update_ground_contact();
        this->check_collisions();
        break;
    }

}


void action__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 reason) {

    switch (reason) {
    case 4:
        stelth->requested_action = 8;
        stelth->set_field_378(6);
        stelth->set_intangible();
        stelth->m_3cc &= ~3;
        stelth->m_3cc |= 4;
        stelth->m_404.reset_color();
        stelth->m_424 = 1;
        return;
    case 3:
        if (stelth->m_424 == 2) {
            stelth->transition_enemy_state(0);
        }
        return;
    case 0:
        stelth->advance_animation();
        switch (stelth->m_424) {
        case 0:
            if (stelth->get_flag_b4() != 0) {
                stelth->m_424 = 1;
            }
            break;
        case 1:
            if (stelth->m_404.decay_value_toward_floor() != 0) {
                stelth->m_424 = 2;
            }
            break;
        }
        stelth->update_ground_contact();
        return;
    case 5:
        stelth->m_3cc &= ~4;
        break;
    }
}
void TObjEneMe3Stelth::sub_800F290C(s32 reason) {
    Vec v;
    f32 c;
    switch (reason) {
    case 4:
        this->requested_action = 4;
        this->advance_animation();
        this->set_active();
        play_sound_effect(0x3A839, (u8 *)&this->position, 0, 0);
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (this->m_3c0 == 1 && this->random_ratio() <= this->m_3e0) {
                this->transition_enemy_state(0x12);
            } else {
                this->transition_enemy_state(this->next_mode);
            }
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, (Vec *)&this->x_speed);
        c = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, c);
        this->x_speed *= 0.8f;
        this->m_310 *= 0.8f;
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::handle_breakup_state(s32 reason) {
    Vec ofs;
    Vec v;
    switch (reason) {
    case 4:
        requested_action = 5;
        refresh_and_send_entity_flags();
        disable_body_collision();
        m_3cc &= ~0xF;
        m_424 = 0;
        break;
    case 3:
        break;
    case 0:
        switch (m_424) {
        case 0:
            advance_animation();
            if (is_passing_frame(18.0f) != 0 || is_passing_frame(28.0f) != 0) {
                play_sound_effect(0x3A836, (u8 *)&position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                m_424 = 1;
                m_428 = 0;
                ofs.x = 0.0f;
                ofs.y = 10.0f;
                ofs.z = 20.0f;
                rotate_y_and_translate(&ofs, &position, rotation_y);
                TObjPlayer::spawn_effect_f8((saddr)&ofs, 0x14);
            } else if (is_passing_frame(2.0f) != 0) {
                m_3cc |= 8;
            } else if (is_passing_frame(6.0f) != 0) {
                m_3cc &= ~8;
                m_3c0 = 0;
            }
            break;
        case 1:
            m_428++;
            if (m_428 >= 0x14) {
                m_424 = 2;
                m_3cc |= 2;
                TBoss3Volopt::create_breakup_mdl((saddr)TObjEneMe3Stelth__breakup_model, (saddr)&me3_stelth_breakup_params, (s32)texlist, (saddr)&position, (s32)rotation_y);
                VecCopy((Vec *)&v, (const Vec *)&position);
                v.x += 20.0f * sin_table_lookup(rotation_y);
                v.z += 20.0f * cos_table_lookup(rotation_y);
                ((TObjPlayer *)(&v))->trigger_dell_biter_events();
                play_sound_effect(0x3AD3A, (u8 *)&position, 0, 0);
            }
            update_ground_contact();
            break;
        case 2:
            queue_destruction();
            break;
        }
        break;
    case 5:
        m_3cc &= ~8;
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjEneMe3Stelth::sub_800F2270(s32 reason) {
    Vec v;
    Vec p;
    Vec q;
    s32 arr[3];
    s32 i;
    s32 ang;
    switch (reason) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xC);
        this->set_intangible();
        this->m_3cc &= ~6;
        this->m_3cc |= 1;
        this->m_424 = 0;
        break;
    case 3:
        if (this->m_424 == 2) {
            this->m_3c0 = 1;
            this->m_3cc |= 0x40000;
            this->set_indexed_flags(0, 0x8000000);
            if (this->random_ratio() <= this->m_3d8) {
                if (this->sub_800F47D4() != 0) {
                    if (this->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->m_14) {
                        this->transition_enemy_state(0x10);
                    } else {
                        this->transition_enemy_state(0xB);
                    }
                } else {
                    this->transition_enemy_state(0x10);
                }
            } else {
                this->transition_enemy_state(1);
            }
        }
        break;
    case 0:
        switch (this->m_424) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->m_3cc |= 4;
                this->m_404.reset_color();
                VecCopy(&v, &this->position);
                v.y = this->m_3d0 - 20.0f;
                this->m_424 = 1;
                play_sound_effect(0x3B23B, &this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1:
            if (this->m_404.decay_value_toward_floor() != 0) {
                this->m_3cc |= 2;
                if (this->update_linked_position(200.0f) != 0) {
                    if (this->current_target == NULL) {
                        break;
                    }
                    arr[0] = (s32)(3.0f * this->random_ratio()) - 1;
                    arr[1] = (s32)(2.0f * this->random_ratio()) - 1;
                    if (arr[1] <= arr[0]) {
                        arr[1]++;
                    }
                    arr[2] = -(arr[0] + arr[1]);
                    for (i = 0; i < 3; i++) {
                        VecCopy(&p, &this->current_target->position);
                        ang = this->current_target->rotation_y + ((arr[i] + 1) << 14);
                        p.x = 20.0f * cos_table_lookup(ang) + p.x;
                        p.z = p.z - 20.0f * sin_table_lookup(ang);
                        p.y += 5.0f;
                        VecCopy(&q, &p);
                        q.x += p.x - this->current_target->position.x;
                        q.z += p.z - this->current_target->position.z;
                        if (sub_800F0F84(&q) == 0 &&
                            csnVector(&this->current_target->position, &q, 0x88E0) == 0 &&
                            csnVectorUnder(&p, (CsnGroup **)&this->m_120, 0x15) != 0 &&
                            ((TScene *)(&p))->find_section_at_position() == this->room) {
                            VecCopy(&this->position, &p);
                            this->rotation_y = ang + 0xC000;
                            break;
                        }
                    }
                }
                this->m_424 = 2;
            }
            break;
        }
        break;
    case 5:
        this->m_3cc &= ~4;
        break;
    }
}
#pragma pop
void TObjEneMe3Stelth::add_instance(NJS_OBJECT *node) {
    load_projection_tex_matrix(stelth_projection_texture_handle);
    TObjEneMe3Stelth__render_node_index = TObjEneMe3Stelth__render_node_index + 1;
}
void TObjEneMe3Stelth::render() {
    s32 mode;
    s32 draw;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_with_debug_info();
        return;
    }
    sub_800F47D4();
    if (m_3cc & 2) {
        mode = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        mode = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (m_3c0 != 0 && is_split_screen() == 0 && dispatch_input_to_instance__18TAdEnterPasswordGCFi(this) != 0) {
        return;
    }
    if (mode != 0) {
        vfunc_108();
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        if (is_split_screen() != 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != 0) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = m_3e8;
                }
            }
            draw = 1;
            if (m_3c0 != 0) {
                if (m_3cc & 8) {
                    m_404.set_flags_and_apply_damage_color();
                } else {
                    model_render_flags |= 0x820;
                    NJS_ARGB c = stelth_render_color_a;
                    set_constant_material(&c);
                    set_chunk_material_override_pair(0xFF00, 0x800);
                }
                if (defer_render() != 0) {
                    draw = 0;
                }
            } else if (check_active_flag() != 0) {
                if (defer_render() != 0) {
                    draw = 0;
                }
            } else {
                model_render_flags |= 0x820;
                NJS_ARGB c = stelth_render_color_b;
                set_constant_material(&c);
                set_chunk_material_override_pair(0xFF00, 0x800);
            }
            if (draw != 0) {
                TObjFish::set_global_param(texlist);
                push_matrix();
                post_translate_matrix(&position.x);
                translate_matrix(0, 0.0f, m_3d4, 0.0f);
                rotate_matrix_y(0, rotation_y);
                TObjEneMe3Stelth__render_node_index = 0;
                if (mode == 1) {
                    TObjMotion::draw();
                } else {
                    draw_motion_model();
                }
                pop_matrix();
            }
            if (m_3c0 != 0) {
                if (m_3cc & 8) {
                    m_404.clear_flag_and_notify();
                }
            } else {
                check_flag();
            }
        } else {
            s32 i;
            if (m_3c0 != 0) {
                TParticleCtrl::begin_effect_render();
                if (m_3cc & 8) {
                    TObjPlayer::setup_tev_stage();
                    model_render_flags |= 0x8021;
                    NJS_ARGB c = me3_stelth_render_color;
                    set_constant_material(&c);
                    set_color_blend_mode(1, 4, 5, 0);
                } else {
                    setup_particle_tev(0);
                }
            } else {
                model_render_flags |= 0x8021;
                NJS_ARGB c = me3_stelth_secondary_render_color;
                set_constant_material(&c);
                set_color_blend_mode(1, 4, 5, 0);
            }
            TObjFish::set_global_param(texlist);
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != 0) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = m_3e8;
                }
            }
            check_active_flag();
            push_matrix();
            post_translate_matrix(&position.x);
            translate_matrix(0, 0.0f, m_3d4, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneMe3Stelth__render_node_index = 0;
            m_420 += 0x222;
            stelth_projection_texture_handle = m_420;
            set_model_node_callback(TObjEneMe3Stelth::add_instance);
            if (m_3c0 != 0) {
                set_ginja_draw_list_mask(3);
            }
            if (mode == 1) {
                draw_ginja_motion_model();
            } else {
                draw_model__16TObjEneMe3StelthFPv(this);
            }
            if (m_3c0 != 0) {
                set_ginja_draw_list_mask(2);
            }
            set_model_node_callback(0);
            pop_matrix();
            check_flag();
            if (m_3c0 != 0) {
                reset_particle_tev();
            }
        }
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
    }
    TParticleCtrl::end_effect_render();
}
void TObjEneMe3Stelth::setup_move() {
    if (get_target_info() != 0) {
        setup_move_bounds();
        sub_800F4758();
    }
}
void TObjEneMe3Stelth::draw_with_debug_info() {
    s32 save[3];
    s32 flag;
    NJS_MOTION *motion;
    f32 frame;
    if (get_target_info() != 0) {
        if (sub_800F4850() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_enable);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_disable);
        }
        if (is_angle_in_range() != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_ground);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_roof);
        }
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 4), (char *)stelth_debug_tecniq_attack);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 3), (char *)stelth_debug_stelth_on);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 6), (char *)stelth_debug_stelth_off);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 5), (char *)stelth_debug_warp);
        if (sub_800F47D4() != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_spigell);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_berill);
        }
    }
    flag = sub_800F47D4();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(texlist);
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            NJS_TEXNAME *textures = ((NJS_TEXLIST *)texlist)->textures;
            s32 i;
            for (i = 0; i < 3; i++) {
                save[i] = textures[i].texaddr;
            }
            for (i = 0; i < 3; i++) {
                textures[i].texaddr = textures[i + 3].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix((f32 *)&position);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 1.0f, 1.0f, 1.0f);
        {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != NULL) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = 0xB000FFB0;
                }
            }
        }
        if (mode == 0) {
            s32 idx = requested_action;
            if (idx < 0) {
                idx = 0;
            } else if (idx >= 0xD) {
                idx = 0xC;
            }
            motion = (NJS_MOTION *)motion_list[action_table[idx].motion].motion;
            frame = parameters[3];
            if (frame < 0.0f) {
                frame = 0.0f;
            } else if (frame > (motion->nbFrame - 1)) {
                frame = (motion->nbFrame - 1);
            }
            set_ginja_draw_list_mask(3);
            set_motion_packed_rotation();
            draw_ginja_model_with_motion(model, motion, frame);
            clear_motion_packed_rotation();
            set_ginja_draw_list_mask(1);
            current_motion = motion;
            this->frame = frame;
            frame = get_node_world_y();
            print_float_padded(pack_debug_text_position(0, 7), 5, frame);
        } else {
            model_render_flags &= ~0x400;
        }
        pop_matrix();
        if (flag != 0) {
            s32 i;
            NJS_TEXNAME *textures = ((NJS_TEXLIST *)texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i].texaddr = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
void TObjEneMe3Stelth::exec(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(6);
        this->clear_intangible();
        this->m_3cc &= 0xFFFFFFF1;
        this->m_3cc |= 1;
        this->m_424 = 0;
        play_sound_effect(0x3B23B, &this->position, 0, 0);
        return;
    case 3:
        if (this->m_424 == 3) {
            this->transition_enemy_state(6);
            this->m_3cc &= ~1;
            this->m_3cc |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
        }
        return;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->m_424 = 3;
        } else if (is_split_screen() != 0) {
            switch (this->m_424) {
            case 0:
                if (this->is_passing_frame(4.0f) != 0) {
                    this->m_3cc |= 8;
                    this->m_404.reset_obstruction_fade();
                    this->m_424 = 1;
                }
                break;
            case 1:
                if (((TObjEneMe3SinowZoa *)&this->m_404)->advance_timer(0.2f) != 0) {
                    this->m_3cc &= ~8;
                    this->m_3c0 = 0;
                    this->m_424 = 2;
                }
                break;
            }
        } else if (this->is_passing_frame(25.0f) != 0) {
            this->m_3cc |= 8;
            this->m_3c0 = 1;
        } else if (this->is_passing_frame(29.0f) != 0) {
            this->m_3cc &= ~8;
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        this->m_3cc &= ~8;
        break;
    }
}
void TObjEneMe3Stelth::sub_800F1440(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0xB;
        this->set_field_378(6);
        this->clear_intangible();
        this->m_3cc &= 0xFFFFFFF1;
        this->m_3cc |= 1;
        this->m_3cc |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000);
        this->m_424 = 0;
        play_sound_effect(0x3B23B, &this->position, 0, 0);
        break;
    case 3:
        if (this->m_424 == 3) {
            this->transition_enemy_state(6);
            this->m_3cc &= ~1;
        }
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->m_424 = 3;
        } else if (is_split_screen() != 0) {
            switch (this->m_424) {
            case 0:
                if (this->is_passing_frame(4.0f) != 0) {
                    this->m_3cc |= 8;
                    NJS_ARGB q = me3_stelth_offset_vec;
                    ((TObjEneMe3SinowZoa *)&this->m_404)->copy_position_vector(&q);
                    this->m_424 = 1;
                }
                break;
            case 1:
                if (this->m_404.decay_value_toward_floor() != 0) {
                    this->m_3cc &= ~8;
                    this->m_3c0 = 0;
                    this->m_424 = 2;
                }
                break;
            }
        } else if (this->is_passing_frame(4.0f) != 0) {
            this->m_3cc |= 8;
        } else if (this->is_passing_frame(6.0f) != 0) {
            this->m_3cc &= ~8;
            this->m_3c0 = 0;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        this->m_3cc &= ~8;
        this->m_3c0 = 0;
        break;
    }
}
void TObjEneMe3Stelth::sub_800F1098(s32 reason) {
    Vec d;
    Vec out;
    s32 c[3];
    s32 r;
    switch (reason) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->m_3cc &= 0xFFFFFFF8;
        this->m_3cc |= 0x10000;
        this->enemy_copy_target_destination();
        this->m_424 = 0;
        break;
    case 3:
        if (this->m_424 == 3) {
            this->transition_enemy_state(6);
        }
        break;
    case 0:
        this->update_prev_position();
        switch (this->m_424) {
        case 0:
        default:
            if (this->current_target == NULL) {
                this->transition_enemy_state(6);
                break;
            }
            {
                Vec dest = this->destination;
                if (select_enemy_destination(this, &dest, 1) != 0) {
                    Vec pos = this->body_center;
                    copy_position_if_valid__10TObjPlayerFii((saddr)this, (saddr)&pos);
                    this->body_center.y += 5.0f;
                    r = ((TObjEnemy *)this)->enemy_turn_toward_dest(((StelthMovementParams *)this->movementParameters)->turn);
                    enemy_set_heading_velocity(((StelthMovementParams *)this->movementParameters)->speed, this, this->rotation_y);
                    move_with_wall_slide((u8 *)this);
                } else {
                    VecCopy(&d, &this->destination);
                    subtract_vector(&d, &this->body_center);
                    r = this->turn_toward_direction(((StelthMovementParams *)this->movementParameters)->turn, &d);
                }
            }
            if (r < 0x100) {
                this->m_424 = 1;
                this->requested_action = 8;
            } else {
                this->requested_action = 0xA;
            }
            break;
        case 1:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->m_428 = 0;
                this->m_424 = 2;
            }
            if (this->is_passing_frame(10.0f) != 0) {
                this->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix((f32 *)&this->position);
                rotate_matrix_y(0, this->rotation_y);
                set_motion_packed_rotation();
                this->calc_joint_matrices(10.0f);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                c[0] = lbl_8043D680[0];
                c[1] = lbl_8043D680[1];
                c[2] = lbl_8043D680[2];
                matrix_mult_vec(0, (Vec *)c, &out);
                pop_matrix();
                if (this->current_target != NULL) {
                    VecCopy(&d, &this->destination);
                    subtract_vector(&d, &this->body_center);
                    r = this->turn_toward_direction(((StelthMovementParams *)this->movementParameters)->turn, &d);
                } else {
                    r = ((s32 *)this->m_318)[3];
                }
                if (r < ((s32 *)this->m_318)[3] / 2 && this->current_target != NULL) {
                    if (game_difficulty_selection == 3) {
                        ((TTecRaFoie *)this)->create(&out, (u8 *)&this->destination, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->attack_tech_level));
                    } else {
                        TTecGiFoie::create(this, &out, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->m_3c8]->attack_tech_level));
                    }
                } else {
                    this->m_424 = 3;
                }
            }
            break;
        case 2:
            if (++this->m_428 >= 0x3C) {
                this->m_424 = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
    ((TObjPlayer *)this)->update_collisions();
}
s32 TObjEneMe3Stelth::sub_800F0F84(Vec *pos) {
    CollisionBody *body;
    s32 result;
    u32 saved;
    Vec sp;
    u8 unused[12];
    body = this->bodies;
    saved = body->flags;
    body->flags = 0x9D01;
    VecCopy(&sp, &this->position);
    VecCopy(&this->position, pos);
    TObjPlayer::init_all_slots();
    this->check_collisions();
    if ((body->flags & 0x80000) && get_valid_target_player(get_entity_id(this->current_target)) == 0) {
        VecCopy(&this->position, &sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    if ((body->flags & 0x100000) && get_valid_target_player(this->entity_id) == 0) {
        VecCopy(&this->position, &sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    result = (body->flags & 0x200000) != 0;
    VecCopy(&this->position, &sp);
    TObjPlayer::init_all_slots();
    copy_collision_body(body, &TObjEneMe3Stelth__collision_body_template);
    body->flags = saved;
    return result;
}
f32 TObjEneMe3Stelth::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    if (m_3c0 == 1 && get_entity_id(source) < 0x1000 && random_ratio() <= m_3e0) {
        transition_enemy_state(0x12);
    } else if (mode == 2) {
        transition_enemy_state(6);
    }
    return TObjChara::receive_direct_attack(source, payload, collider, -1, -1);
}
void *TObjEneMe3StelthReal::create(void *set_data) {
    return new TObjEneMe3StelthReal(tl_04, set_data);
}
TObjEneMe3StelthReal::TObjEneMe3StelthReal(TObject *parent, void *set_data) : TObjEneMe3Stelth(parent) {
    m_name = TObjEneMe3StelthReal__class_name;
    invoke_initialization_hook(set_data);
    setup_move_bounds();
    init_common();
    mode = 0;
    dispatch_action(mode, 4);
}
TObjEneMe3StelthReal::~TObjEneMe3StelthReal() {}
void TObjEneMe3StelthReal::run_death_reaction() { TObjEneMe3Stelth::run_death_reaction(); }
void TObjEneMe3StelthReal::run_hit_reaction() { TObjEneMe3Stelth::run_hit_reaction(); }
void TObjEneMe3StelthReal::select_next_attack_state() {
    m_3ec = m_3ec + 1;
    if (m_3ec >= 2 || random_ratio() < 0.5f) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}
void TObjEneMe3StelthReal::on_target_lost() {  }

void TObjEneMe3Stelth::sub_800F0C90() {
    if (this->is_passing_frame(12.0f) != 0 || this->is_passing_frame(28.0f) != 0) {
        this->try_spawn_ground_effect(&this->position);
    }
}

// dead-stripped; reconstructed from its pooled literals: 23.0f (.sdata2 0x805DA810) is pooled
// between try_spawn_ground_effect's 1.0f and sub_800F0C90's 12.0f, before its first live user.
// Body after its sibling sub_800F0C90 (a ground effect on a motion frame); name inferred.
void TObjEneMe3Stelth::spawn_ground_effect_on_frame_23() {
    if (is_passing_frame(23.0f) != 0) {
        try_spawn_ground_effect(&position);
    }
}

void TObjEneMe3Stelth::play_hit_effect() {
    if (try_spawn_ground_effect(&position) != 0) {
        play_sound_effect(0x3A836, &position, 0, 0);
        return;
    }
    spawn_particle_effect(&position, 0xF3);
    play_sound_effect(0x3A836, &position, 0, 0);
}

s32 TObjEneMe3Stelth::try_spawn_ground_effect(const Vec *origin) {
    Vec pos;
    void *effect;
    CsnHit *hit;
    VecCopy(&pos, origin);
    pos.y += 15.0f;
    hit = csnVectorUnder(&pos, (CsnGroup **)&m_120, 0x15);
    if (hit != NULL && (hit->hit_mask & 4)) {
        effect = spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (effect != NULL) {
            attach_particle_model((u8 *)effect, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
        }
        spawn_particle_effect(&hit->contact[2].point, 0xA4);
        TObjEneGibbles__sub_800D8988(&position);
        return 1;
    }
    return 0;
}
