#include "pso/system/memory.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureEntryCopy.h"
#include "pso/effect/GroundContactSound.h"
#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/unk/TUnk_804EDAC0.h"
#include "pso/item/TItem.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/math/AngleUnits.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcEnemy.h"
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
#include "pso/player/TObjPlayer_800D8FDC.h"
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
#include "pso/enemy/stelth/TObjEneMe3Stelth_803DC82C.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/enemy/dd/TObjEneDD_800B9A34.h"
#include "pso/render/GinjaView.h"
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
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/unk/TUnk_804EDAC0.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"

#pragma readonly_strings on

// Class names the two constructors store in m_name (.sdata).
const char *TObjEneMe3Stelth__class_name = stelth_class_name;
const char *TObjEneMe3StelthReal__class_name = stelth_real_class_name;


extern "C" {
extern StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[];
extern CollisionBody TObjEneMe3Stelth__collision_body_template;
BmlResource *TObjEneMe3Stelth__bml_resource;
s32 TObjEneMe3Stelth__render_node_index;
TBreakUpMdlData *TObjEneMe3Stelth__breakup_model;
SampledMotionPoints *TObjEneMe3Stelth__trail_buffer;
s32 stelth_projection_texture_handle;
f32 lbl_805010E0[3];
__declspec(section ".data") player_stats *TObjEneMe3Stelth__base_params_by_variant[2];
__declspec(section ".data") AttackParams *TObjEneMe3Stelth__attack_params_by_variant[2];
__declspec(section ".data") ActorParamBlock *TObjEneMe3Stelth__resistance_params_by_variant[2];
__declspec(section ".data") StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[2];
__declspec(section ".data") NJS_TEXLIST TObjEneMe3Stelth__alternate_texture_list;
f32 lbl_80501114[3];
u32 *TObjEneMe3Stelth__material_color_pointers[4];




}

extern "C" {




StelthMovementParams TObjEneMe3Stelth__shared_params = { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } };
CollisionBody TObjEneMe3Stelth__collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};
__declspec(section ".data") const char *stelth_model_names[2] = {
    stelth_model, NULL,
};
const char *stelth_motion_names[12] = {
    stelth_t_wait_motion, stelth_apper_motion, stelth_backstep_motion, stelth_bareta_motion,
    stelth_damage_motion, stelth_death_motion, stelth_f_attack_motion, stelth_sword_motion,
    stelth_transform_motion, stelth_wait_motion, stelth_walk_motion, NULL,
};
BmlResourceDescriptor stelth_bml_resource_desc = {
    stelth_bml, stelth_model_names, stelth_motion_names, 1, 11,
};
__declspec(section ".data") const char *stelth_low_model_names[2] = {
    stelth_low_model, NULL,
};
const char *stelth_low_motion_names[12] = {
    stelth_t_wait_motion, stelth_apper_motion, stelth_backstep_motion, stelth_bareta_motion,
    stelth_damage_motion, stelth_death_motion, stelth_f_attack_motion, stelth_sword_motion,
    stelth_transform_motion, stelth_wait_motion, stelth_walk_motion, NULL,
};
BmlResourceDescriptor me3_stelth_bml_resource_desc = {
    stelth_low_bml, stelth_low_model_names, stelth_low_motion_names, 1, 11,
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





void TObjEneMe3Stelth::draw_model() {
    this->draw_ginja_motion_model();
}
void TObjEneDD_ST::sub_800F5874(s32 mask) {
    this->immunity_flags = (s16) (this->immunity_flags | mask);
}
void TObjEneDD_ST::sub_800F5864(s32 mask) {
    this->immunity_flags = (s16) (this->immunity_flags & ~mask);
}
void TObjEneMe3Stelth::load_shared_resources() {
    s32 i;
    const NJS_TEXLIST *src;
    s32 n;
    StelthBehaviorParams *d;
    NJS_OBJECT *m;
    NJS_CNK_MODEL *q;
    AnimationMotion *motion;
    void *p;

    lbl_805010E0[0] = 0.0f;
    lbl_805010E0[1] = 0.0f;
    lbl_805010E0[2] = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneMe3Stelth__bml_resource = load_enemy_bml_resource(&me3_stelth_bml_resource_desc);
    } else {
        TObjEneMe3Stelth__bml_resource = load_enemy_bml_resource(&stelth_bml_resource_desc);
    }
    src = TObjEneMe3Stelth__bml_resource->models->texlist;
    n = src->nbTexture;
    TObjEneMe3Stelth__alternate_texture_list.nbTexture = n;
    TObjEneMe3Stelth__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        copy_ginja_texture_entry(&TObjEneMe3Stelth__alternate_texture_list.textures[i], &src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3Stelth__alternate_texture_list.textures[i].texture = TObjEneMe3Stelth__alternate_texture_list.textures[i + 3].texture;
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__base_params_by_variant[i] = TLobby::register_boss(stelth_base_stat_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__attack_params_by_variant[i] = TLobby::dispatch_shared_handler_b(stelth_attack_stat_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__resistance_params_by_variant[i] = TLobby::register_object(stelth_resist_stat_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__behavior_params_by_variant[i] = (StelthBehaviorParams *)TLobby::dispatch_shared_handler_a(stelth_param_ids[i]);
    }
    d = TObjEneMe3Stelth__behavior_params_by_variant[0];
    TObjEneMe3Stelth::set_slot_min_clamped_value(7, d->sword_motion_speed);
    TObjEneMe3Stelth::set_slot_min_clamped_value(4, d->damage_motion_speed);
    TObjEneMe3Stelth__render_node_index = 0;
    lbl_80501114[0] = 0.0f;
    lbl_80501114[1] = 0.0f;
    lbl_80501114[2] = 0.0f;
    m = TObjEneMe3Stelth__bml_resource->models->model;
    q = (NJS_CNK_MODEL *)find_model_node(m, 9)->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[0] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[0] = 0;
    }
    q = (NJS_CNK_MODEL *)find_model_node(m, 0xD)->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[1] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[1] = 0;
    }
    q = (NJS_CNK_MODEL *)find_model_node(m, 0x26)->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[2] = (u32 *)(q->polygon_list + 2);
    } else {
        TObjEneMe3Stelth__material_color_pointers[2] = 0;
    }
    motion = TObjEneMe3Stelth__bml_resource->motions[TObjEneMe3Stelth__animation_descriptors[5].motion].motion;
    if (is_split_screen() != 0) {
        p = new TBreakUpMdlData(TObjEneMe3Stelth__bml_resource->models->model, (NJS_MOTION *)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        TObjEneMe3Stelth__breakup_model = (TBreakUpMdlData *)p;
    } else {
        p = new TBreakUpMdlData((long)(saddr)TObjEneMe3Stelth__bml_resource->models->model, (long)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        TObjEneMe3Stelth__breakup_model = (TBreakUpMdlData *)p;
    }
    {
        Vec va;
        Vec vb;
        NJS_OBJECT *mdl;
        AnimationMotion *trail_motion;
        BmlResource *r = TObjEneMe3Stelth__bml_resource;
        s32 idx = TObjEneMe3Stelth__animation_descriptors[6].motion;
        mdl = r->models->model;
        va.x = 0.0f;
        va.y = 0.0f;
        va.z = 0.0f;
        vb.x = -10.0f;
        vb.y = 0.0f;
        vb.z = 0.0f;
        trail_motion = r->motions[idx].motion;
        TObjEneMe3Stelth__trail_buffer = new SampledMotionPoints(2, 16.0f, 26.0f, 0.7f);
        TObjEneMe3Stelth__trail_buffer->sample_node_offsets(mdl, (NJS_MOTION *)trail_motion, 0x22, &va, &vb);
    }
    {
        NpcAnimationBinding a = stelth_attack_binding_desc_a;
        a.motions = TObjEneMe3Stelth__bml_resource->motions;
        NpcAnimationBinding b = stelth_attack_binding_desc_b;
        b.motions = TObjEneMe3Stelth__bml_resource->motions;
        TObjNpcEnemy::register_animated_ginja(0x2B, reinterpret_cast<NJS_OBJECT *>(TObjEneMe3Stelth__bml_resource->models->model),
                                                  reinterpret_cast<NJS_TEXLIST *>(TObjEneMe3Stelth__bml_resource->models->texlist), &a, 8.0f, 0.0f);
        TObjNpcEnemy::register_animated_ginja(0x2D, reinterpret_cast<NJS_OBJECT *>(TObjEneMe3Stelth__bml_resource->models->model),
                                                  reinterpret_cast<NJS_TEXLIST *>(TObjEneMe3Stelth__bml_resource->models->texlist), &b, 8.0f, 0.0f);
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
void TObjEneMe3Stelth::set_slot_min_clamped_value(s32 index, f32 speed) {
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    TObjEneMe3Stelth__animation_descriptors[index].speed = speed;
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
    init_variant();
    entry = TObjEneMe3Stelth__bml_resource->models;
    model = (void *)entry->model;
    init_model(&TObjEneMe3Stelth__collision_body_template, 1);
    motion_flags = 0;
    set_action_table(TObjEneMe3Stelth__animation_descriptors);
    set_motion_list(TObjEneMe3Stelth__bml_resource->motions);
    set_animation(requested_action);
    v = variant_index;
    reset_hp(TObjEneMe3Stelth__base_params_by_variant[v], TObjEneMe3Stelth__attack_params_by_variant[v], TObjEneMe3Stelth__resistance_params_by_variant[v]);
    set_state_flag_4();
    movementParameters = &TObjEneMe3Stelth__shared_params;
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    behavior_flags = 0;
    y = position.y;
    body_y = y;
    body_offset_y = 0.0f;
    material_color = 0;
    attack_count = 0;
    saved_evp = evp;
    fade.reset_obstruction_fade();
    state_step = 0;
    state_timer = 0;
    backstep_angle = 0;
    move_speed = 0.0f;
    state_values[0] = 0.0f;
    state_values[1] = 0.0f;
    state_values[2] = 0.0f;
    state_values[3] = 0.0f;
    owned_objects[0] = NULL;
    owned_objects[1] = NULL;
    projection_scroll = 0;
    if (stealthed == 1) {
        set_indexed_flags(0, 0x08000000);
        return;
    }
    clear_player_status_flag(0, 0x08000000);
}
#pragma pop
TObjEneMe3Stelth::~TObjEneMe3Stelth() {
    if (owned_objects[0] != NULL) {
        owned_objects[0]->queue_destruction();
        owned_objects[0] = NULL;
    }
    if (owned_objects[1] != NULL) {
        owned_objects[1]->queue_destruction();
        owned_objects[1] = NULL;
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
    flags = behavior_flags;
    if (flags & 0x40000) {
        behavior_flags = flags & ~0x40000;
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
    if (behavior_flags & 1) {
        clear_attack_receipts();
        if (stealthed == 1 && random_ratio() <= stealth_off_chance) {
            transition_enemy_state(0x12);
        }
    } else if (mode != 0xE) {
        transition_enemy_state(0xE);
    }
}
void TObjEneMe3Stelth::run_miss_reaction() {  }
void TObjEneMe3Stelth::copy_pos_with_height_offset() {
    VecCopy(&body_center, &position);
    body_center.y += 12.0f + body_offset_y;
    VecCopy(&center, &body_center);
}
void TObjEneMe3Stelth::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}
void TObjEneMe3Stelth::setup_move_bounds() {
    if (starts_stealthed() != 0) {
        stealthed = 1;
    } else {
        stealthed = 0;
    }
    fade_in_start = is_angle_in_range();
    if (fade_in_start == 1) {
        requested_action = 2;
    } else {
        requested_action = 0;
    }
    technique_chance = 0.4f + parameters[2];
    stealth_on_chance = 0.3f + parameters[1];
    stealth_off_chance = 0.1f + parameters[4];
    warp_chance = 0.5f + parameters[3];
    texture_variant = variant;
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
// inferred parameter names: the callers pass a facing (rotation_y, backstep_angle + 0x8000) and the
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
    check_enemy_body_collisions(this);
    res = (s->flags & 0x380000) != 0;
    copy_collision_body(s, &TObjEneMe3Stelth__collision_body_template);
    s->flags = b;
    rotation_y = a;
    return res;
}
#pragma push
#pragma fp_contract on
s32 TObjEneMe3Stelth::is_in_sword_range(f32) {
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
            if (is_alternate_variant() != 0) {
                TObjChara *t = current_target;
                TItem *held;
                if (TObjPlayer::is_locally_controlled(t) != 0 && (held = (TItem *)TObjPlayer::get_equipped_weapon(t)) != 0) {
                    TObjPlayer::send_6x26_unequip_item((TObjPlayer *)t, held->get_item_id());
                    ((TObjPlayer *)t)->get_hand_joint_position((saddr)&hand_position);
                    spawn_particle_effect(&hand_position, 0x1D0);
                }
            } else if (near != 0 && random_ratio() <= 0.1666f) {
                TObjEneDD__sub_800BA438(this, current_target);
            }
        }
    }
    play_sound_effect(0x3AA37, reinterpret_cast<const Vec *>((u8 *)&position), 0, 0);
}
void TObjEneMe3Stelth::vfunc_108() {  }
s32 TObjEneMe3Stelth::check_target_in_range() {
    f32 distance;
    u8 in_range;

    in_range = 0;
    if (!(behavior_flags & 0x10000)) {
        distance = destination_distance;
        if ((distance > 100.0f) && (distance < 150.0f) && (test_body_collision(rotation_y, distance - 20.0f) == 0)) {
            in_range = 1;
        }
    }
    return in_range;
}
void TObjEneMe3Stelth::select_next_attack_state() {  }
s32 TObjEneMe3Stelth::check_active_flag() {
    if (behavior_flags & 4) {
        fade.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}
s32 TObjEneMe3Stelth::check_flag() {
    if (behavior_flags & 4) {
        fade.clear_flag_and_notify();
        return 1;
    }
    return 0;
}
void TObjEneMe3Stelth::on_target_lost() {  }
void TObjEneMe3Stelth::set_intangible() { TObjEneDD::set_intangible(); sub_800F5874(38); }
void TObjEneMe3Stelth::clear_intangible() { TObjEneDD::clear_intangible(); sub_800F5864(38); }
void TObjEneMe3Stelth::vfunc_112() {  }
void TObjEneMe3Stelth::update_distance_state() {
    if (body_y - position.y > 30.0f) {
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
s32 TObjEneMe3Stelth::starts_stealthed() {
    return parameters[0] < 2.0f;
}
s32 TObjEneMe3Stelth::is_angle_in_range() {
    return parameters[0] < 1.0f ||
           (parameters[0] >= 2.0f && parameters[0] < 3.0f);
}
s32 TObjEneMe3Stelth::acquire_target(f32 f) { return select_and_apply_target(f); }
s32 TObjEneMe3Stelth::is_alternate_variant() {
    return texture_variant >= 1;
}
void TObjEneMe3Stelth::init_variant() {
    if (is_alternate_variant() != 0) {
        texlist = &TObjEneMe3Stelth__alternate_texture_list;
        initialize_enemy_state(0x3F);
        variant_index = 1;
        return;
    }
    texlist = TObjEneMe3Stelth__bml_resource->models->texlist;
    initialize_enemy_state(0x3E);
    variant_index = 0;
}
void TObjEneMe3Stelth::create_resta_effect() {
    saddr f = TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->support_tech_level);
    TTecResta::create((void *)this, (u8 *)&this->position, f);
}
void TObjEneMe3Stelth::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        state_reset(reason);
        break;
    case 1:
        state_fade_in(reason);
        break;
    case 3:
        state_ambush(reason);
        break;
    case 2:
        state_chase(reason);
        break;
    case 4:
        state_reveal(reason);
        break;
    case 5:
        state_appear(reason);
        break;
    case 6:
        state_chase_target(reason);
        break;
    case 7:
        state_f_attack(reason);
        break;
    case 8:
        state_sword(reason);
        break;
    case 9:
        state_backstep(reason);
        break;
    case 13:
        state_wait(reason);
        break;
    case 10:
        state_vanish(reason);
        break;
    case 11:
        state_cast_technique(reason);
        break;
    case 14:
        state_knockback(reason);
        break;
    case 15:
        state_death(reason);
        break;
    case 12:
        state_warp(reason);
        break;
    case 16:
        state_cast_barta(reason);
        break;
    case 17:
        state_stealth_on(reason);
        break;
    case 18:
        state_stealth_off(reason);
        break;
    }
    if (stealthed != 1 || ((s32)state != 1 && (s32)state != 2)) {
        render_minimap_dot();
    }
}
void TObjEneMe3Stelth::state_reset(s32 reason) {
    switch (reason) {
    case 4:
        if (fade_in_start == 1) {
            requested_action = 2;
            set_field_378(1);
        } else {
            requested_action = 0;
            set_field_378(3);
        }
        set_intangible();
        behavior_flags |= 2;
        behavior_flags &= ~1;
        if (TObjEneDD::check_v2_mode() != 0) {
            behavior_flags &= ~0x10000;
        }
        state_step = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        body_y = position.y;
        material_color = 0;
        attack_count = 0;
        return;
    case 3:
        if (state_step > 5) {
            if (fade_in_start == 1) {
                transition_enemy_state(1);
            } else {
                transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        state_step++;
        if (state_step == 1) {
            body_y = position.y;
            update_ground_contact();
            body_offset_y = body_y - position.y;
        }
        break;
    }
}
void TObjEneMe3Stelth::state_fade_in(s32 reason) {
    Vec v;
    switch (reason) {
    case 4:
        requested_action = 2;
        set_field_378(0);
        set_intangible();
        behavior_flags &= ~2;
        behavior_flags |= 5;
        fade.start_fade_in();
        VecCopy(&v, &position);
        v.y = body_y - 20.0f;
        if (stealthed == 0) {
            TBoss3Volopt__sub_800D8D88((saddr)&v);
        } else {
            create_timed_particle_emitter((u8 *)&position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (fade.advance_toward_max() != 0) {
            if (stealthed == 1) {
                transition_enemy_state(2);
            } else {
                transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (fade.get_color()->a >= -0.75f) {
            advance_animation();
        }
        update_ground_contact();
        break;
    case 5:
        behavior_flags &= ~4;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase(s32 mode) {
    s32 timer;
    switch (mode) {
    case 4:
        requested_action = 9;
        set_field_378(0xD);
        clear_intangible();
        behavior_flags &= ~7;
        state_step = 0;
        state_timer = 0;
        state_values[0] = 0.0f;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            if (destination_distance <= 40.0f) {
                transition_enemy_state(0xD);
                break;
            }
            timer = state_timer - 1;
            state_timer = timer;
            if ((timer <= 0) && (check_target_in_range() != 0)) {
                state_timer = 0x3C;
                if (random_ratio() <= 0.01f) {
                    transition_enemy_state(7);
                    break;
                }
            }
        } else {
            if (state_step >= 0xE10) {
                transition_enemy_state(0xD);
                break;
            }
        case 5:
            break;
        }
        break;
    case 0:
        state_step++;
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            state_values[0] = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
            if (state_values[0] < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                update_ground_contact();
            }
        }
        check_collisions();
        break;
    }
}
#pragma pop
void TObjEneMe3Stelth::state_ambush(s32 reason) {
    Vec pos;
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->behavior_flags |= 7;
        this->fade.start_fade_in();
        VecCopy(&pos, &this->position);
        pos.y = this->body_y - 10.0f;
        TBoss3Volopt__sub_800D8D88((saddr)&pos);
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        this->behavior_flags &= ~4;
        break;
    }
}
void TObjEneMe3Stelth::state_reveal(s32 reason) {
    s32 t;
    switch (reason) {
    case 4:
        requested_action = 0;
        set_field_378(5);
        set_intangible();
        behavior_flags &= ~7;
        state_step = 0;
        state_timer = 0;
        break;
    case 3:
        if (state_step > 0x1E) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (state_step == 0) {
            if (update_linked_position(200.0f) != 0) {
                state_step = 1;
                static const u32 color_mask = 0xFFFF00FF;
                material_color = 0x1C00FFFF;
                material_color &= color_mask;
                state_timer = 0;
            }
        } else {
            state_step += 1;
            state_timer += 0x10;
            if (state_timer > 0xFF) {
                state_timer = 0xFF;
            }
            t = state_timer;
            material_color = (t << 24) | (material_color & 0x00FFFFFF);
            if (enemy_validate_retained_target(this) == 0) {
                state_step = 0;
                material_color = 0;
            }
        }
        update_ground_contact();
        update_distance_state();
        check_collisions();
        body_offset_y = body_y - position.y;
        break;
    case 5:
        material_color = 0x1C00FFFF;
        body_offset_y = 0.0f;
        break;
    }
}
void TObjEneMe3Stelth::state_appear(s32 reason) {
    f32 node_world_y;
    f32 node_height;

    switch (reason) {
    case 4:
        requested_action = 1;
        set_field_378(0xD);
        clear_intangible();
        behavior_flags &= ~6;
        behavior_flags |= 1;
        state_step = 0;
        move_speed = 0.0f;
        if (enemy_has_live_target() != 0) {
            enemy_copy_target_destination();
            update_velocity();
        }
        break;
    case 3:
        if (state_step == 3) {
            transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (state_step) {
        case 0:
            node_height = get_node_world_y();
            advance_animation();
            state_values[0] = get_node_world_y();
            body_y = body_y + (node_height - state_values[0]);
            state_step = 1;
            body_offset_y = body_y - position.y;
            break;
        case 1:
            advance_animation();
            if (frame > 29.0f) {
                frame = 29.0f;
            }
            move_speed -= 0.3f;
            if (move_speed < -5.0f) {
                move_speed = -5.0f;
            }
            body_y = body_y + move_speed;
            node_world_y = get_node_world_y();
            body_y = body_y - (node_world_y - state_values[0]);
            state_values[0] = node_world_y;
            if (body_y < position.y) {
                body_y = position.y;
                state_step = 2;
                play_hit_effect();
            }
            break;
        case 2:
            if (get_flag_b4() != 0) {
                requested_action = 9;
                state_step = 3;
                body_y = position.y;
                body_offset_y = 0.0f;
            }
            advance_animation();
            break;
        }
        update_ground_contact();
        update_distance_state();
        check_collisions();
        body_offset_y = body_y - position.y;
        break;
    case 5:
        behavior_flags &= ~1;
        body_offset_y = 0.0f;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase_target(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 0xA;
        set_field_378(6);
        clear_intangible();
        behavior_flags &= ~7;
        destination_distance = 300.0f;
        move_speed = TObjEneMe3Stelth__behavior_params_by_variant[variant_index]->walk_speed;
        state_values[0] = 0.0f;
        return;
    case 3:
        if (current_target == NULL) {
            on_target_lost();
            transition_enemy_state(0xD);
            return;
        }
        if (is_in_sword_range(state_values[0]) != 0) {
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
            spawn_footstep_effects();
            state_values[0] = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
            if (state_values[0] < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                update_ground_contact();
            } else {
                enemy_turn_and_move_on_ground(this, 0x500, move_speed);
            }
            check_collisions();
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_f_attack(s32 reason) {
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
        this->behavior_flags &= ~7;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->move_speed = 0.0f;
        this->set_active();
        break;
    case 3:
        if (this->state_step == 5 || this->get_flag_b4() != 0) {
            if (this->update_ground_contact() == 0) {
                this->transition_enemy_state(0xA);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            this->advance_animation();
            if (this->motion_flags & 8) {
                this->state_step = 1;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1:
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                ang = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            } else {
                ang = this->rotation_y;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, ang, 0x1000);
            if (this->is_passing_frame(10.0f) != 0) {
                this->state_step = 2;
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
                    this->state_step = 5;
                } else {
                    t = this->destination_distance - 20.0f;
                    VecCopy(&v, &this->position);
                    v.x += this->destination_direction.x * t;
                    v.y += 20.0f;
                    v.z += this->destination_direction.z * t;
                    if (csnVecterUnder(&v, 0x15) != 0) {
                        if (this->room == find_section_at_position(&v)) {
                            this->state_step = 3;
                            this->state_values[0] = (this->destination_distance - 20.0f) / 12.857143f;
                            this->set_invulnerable();
                            play_sound_effect(0x3A835, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
                        } else {
                            this->state_step = 5;
                        }
                    } else {
                        this->state_step = 5;
                    }
                }
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 3:
            this->advance_animation();
            if (this->frame + this->play_speed >= 23.0f) {
                this->state_step = 4;
                this->clear_invulnerable();
                this->play_hit_effect();
            }
            this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, this->state_values[0]);
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
                play_sound_effect(0x3A838, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
            }
            this->state_values[0] *= 0.85f;
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->state_values[0]);
            this->check_collisions();
            break;
        }
        if (this->state_step != 0) {
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
        this->body_y = this->position.y;
        this->body_offset_y = 0.0f;
        this->clear_invulnerable();
        this->clear_field_388();
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_sword(s32 reason) {
    s32 target_angle;
    f32 cur_frame;
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->behavior_flags &= ~7;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->state_timer = 0;
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->select_next_attack_state();
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->attack_and_unequip();
            if (this->frame < 20.0f) {
                if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    target_angle = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
                } else {
                    target_angle = this->rotation_y;
                }
                this->rotation_y = approach_angle_limited(this->rotation_y, target_angle, 0x300);
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            this->vfunc_112();
            spawn_footstep_effects();
            cur_frame = this->frame;
            if ((cur_frame >= 0.0f) && (cur_frame <= 5.0f)) {
                ((TObjEneDD *)this)->move_to_shot_position(this->destination_direction.x, this->destination_direction.z, TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->sword_lunge_speed);
            } else {
                this->update_ground_contact();
            }
            if (this->frame >= 25.0f) {
                this->frame = 25.0f;
                this->state_step = 1;
            }
            break;
        case 1:
            this->state_timer++;
            if (this->state_timer <= TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->sword_hold_frames) {
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
void TObjEneMe3Stelth::state_backstep(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 3;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= ~7;
        this->attack_count = 0;
        this->state_step = 3;
        if (this->acquire_target(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->backstep_angle = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            if (this->test_body_collision(this->backstep_angle + 0x8000, 80.0f) == 0) {
                this->destination_direction.x *= -1.0f;
                this->destination_direction.z *= -1.0f;
                this->state_step = 0;
                this->move_speed = 7.111111f;
            }
        }
        this->set_active();
        return;
    case 3:
        if (this->state_step == 3) {
            if ((this->stealthed == 0) && (this->random_ratio() <= this->stealth_on_chance)) {
                this->transition_enemy_state(0x11);
                return;
            }
            if (this->random_ratio() <= this->technique_chance) {
                if (this->is_alternate_variant() != 0) {
                    if (this->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->support_tech_chance) {
                        this->transition_enemy_state(0x10);
                        return;
                    }
                    this->transition_enemy_state(0xB);
                    return;
                }
                this->transition_enemy_state(0x10);
                return;
            }
            if (this->random_ratio() <= this->warp_chance) {
                this->transition_enemy_state(0xC);
                return;
            }
            this->transition_enemy_state(6);
        }
        return;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->rotation_y = approach_angle_limited(this->rotation_y, this->backstep_angle, 0x31C7);
            if ((this->frame + this->play_speed) >= 15.0f) {
                this->state_step = 1;
                this->set_invulnerable();
                play_sound_effect(0x3A835, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        case 1:
            if ((this->frame + this->play_speed) >= 24.0f) {
                this->state_step = 2;
                this->clear_invulnerable();
                this->play_hit_effect();
            }
            this->move_clamped_on_ground(this->destination_direction.x, this->destination_direction.z, this->move_speed);
            return;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->state_step = 3;
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
void TObjEneMe3Stelth::state_cast_technique(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 8;
        set_field_378(0xB);
        clear_intangible();
        behavior_flags &= ~6;
        behavior_flags |= 1;
        state_step = 0;
        state_timer = 0;
        return;
    case 3:
        if (state_timer > TObjEneMe3Stelth__behavior_params_by_variant[variant_index]->cast_duration) {
            transition_enemy_state(6);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            if (get_flag_b4() != 0) {
                create_resta_effect();
                if (TObjEneDD::check_v2_mode() != 0) {
                    state_step = 2;
                } else {
                    state_step = 1;
                }
                state_timer = 0;
            }
            break;
        case 1:
            state_timer++;
            break;
        case 2:
            state_timer++;
            if (state_timer == 5) {
                TTecSifta::create((void *)this, (u8 *)&position, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[variant_index]->support_tech_level));
            } else if (state_timer == 0xA) {
                TTecDeband::create(this, (u8 *)&position, (s32)(TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[variant_index]->support_tech_level)));
                state_step = 1;
                state_timer = 0;
            }
            break;
        }
        update_ground_contact();
        break;
    }
}
#pragma pop
}

void TObjEneMe3Stelth::state_wait(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 9;
        this->set_field_378(0xD);
        this->behavior_flags &= ~7;
        this->set_intangible();
        this->attack_count = 0;
        this->state_step = 0;
        break;
    case 3:
        if (this->update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(6);
        } else if (this->state_step >= 0x5A) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        this->state_step++;
        this->advance_animation();
        this->update_ground_contact();
        this->check_collisions();
        break;
    }

}


void TObjEneMe3Stelth::state_vanish(s32 reason) {

    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(6);
        this->set_intangible();
        this->behavior_flags &= ~3;
        this->behavior_flags |= 4;
        this->fade.reset_color();
        this->state_step = 1;
        return;
    case 3:
        if (this->state_step == 2) {
            this->transition_enemy_state(0);
        }
        return;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            if (this->get_flag_b4() != 0) {
                this->state_step = 1;
            }
            break;
        case 1:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 2;
            }
            break;
        }
        this->update_ground_contact();
        return;
    case 5:
        this->behavior_flags &= ~4;
        break;
    }
}
void TObjEneMe3Stelth::state_knockback(s32 reason) {
    Vec v;
    f32 c;
    switch (reason) {
    case 4:
        this->requested_action = 4;
        this->advance_animation();
        this->set_active();
        play_sound_effect(0x3A839, reinterpret_cast<const Vec *>((u8 *)&this->position), 0, 0);
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (this->stealthed == 1 && this->random_ratio() <= this->stealth_off_chance) {
                this->transition_enemy_state(0x12);
            } else {
                this->transition_enemy_state(this->next_mode);
            }
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, &this->velocity);
        c = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, c);
        this->velocity.x *= 0.8f;
        this->velocity.z *= 0.8f;
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
void TObjEneMe3Stelth::state_death(s32 reason) {
    Vec ofs;
    Vec v;
    switch (reason) {
    case 4:
        requested_action = 5;
        refresh_and_send_entity_flags();
        disable_body_collision();
        behavior_flags &= ~0xF;
        state_step = 0;
        break;
    case 3:
        break;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (is_passing_frame(18.0f) != 0 || is_passing_frame(28.0f) != 0) {
                play_sound_effect(0x3A836, reinterpret_cast<const Vec *>((u8 *)&position), 0, 0);
            }
            if (get_flag_b4() != 0) {
                state_step = 1;
                state_timer = 0;
                ofs.x = 0.0f;
                ofs.y = 10.0f;
                ofs.z = 20.0f;
                rotate_y_and_translate(&ofs, &position, rotation_y);
                spawn_effect_f8(&ofs, 0x14);
            } else if (is_passing_frame(2.0f) != 0) {
                behavior_flags |= 8;
            } else if (is_passing_frame(6.0f) != 0) {
                behavior_flags &= ~8;
                stealthed = 0;
            }
            break;
        case 1:
            state_timer++;
            if (state_timer >= 0x14) {
                state_step = 2;
                behavior_flags |= 2;
                TBoss3Volopt::create_breakup_mdl(TObjEneMe3Stelth__breakup_model, &me3_stelth_breakup_params,
                                   texlist, &position, rotation_y);
                VecCopy((Vec *)&v, (const Vec *)&position);
                v.x += 20.0f * sin_table_lookup(rotation_y);
                v.z += 20.0f * cos_table_lookup(rotation_y);
                trigger_dell_biter_events(&v);
                play_sound_effect(0x3AD3A, reinterpret_cast<const Vec *>((u8 *)&position), 0, 0);
            }
            update_ground_contact();
            break;
        case 2:
            queue_destruction();
            break;
        }
        break;
    case 5:
        behavior_flags &= ~8;
        break;
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjEneMe3Stelth::state_warp(s32 reason) {
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
        this->behavior_flags &= ~6;
        this->behavior_flags |= 1;
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 2) {
            this->stealthed = 1;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x8000000);
            if (this->random_ratio() <= this->technique_chance) {
                if (this->is_alternate_variant() != 0) {
                    if (this->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->support_tech_chance) {
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
        switch (this->state_step) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->behavior_flags |= 4;
                this->fade.reset_color();
                VecCopy(&v, &this->position);
                v.y = this->body_y - 20.0f;
                this->state_step = 1;
                play_sound_effect(0x3B23B, &this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->behavior_flags |= 2;
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
                        if (check_move_collision(&q) == 0 &&
                            csnVector(&this->current_target->position, &q, 0x88E0) == 0 &&
                            csnVectorUnder(&p, this->ground_candidates.groups, 0x15) != 0 &&
                            find_section_at_position(&p) == this->room) {
                            VecCopy(&this->position, &p);
                            this->rotation_y = ang + 0xC000;
                            break;
                        }
                    }
                }
                this->state_step = 2;
            }
            break;
        }
        break;
    case 5:
        this->behavior_flags &= ~4;
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
    is_alternate_variant();
    if (behavior_flags & 2) {
        mode = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        mode = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (stealthed != 0 && is_split_screen() == 0 && TUnk_804EDAC0::dispatch_input_to_instance(this) != 0) {
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
                    *TObjEneMe3Stelth__material_color_pointers[i] = material_color;
                }
            }
            draw = 1;
            if (stealthed != 0) {
                if (behavior_flags & 8) {
                    fade.set_flags_and_apply_damage_color();
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
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
                push_matrix();
                post_translate_matrix(&position.x);
                translate_matrix(0, 0.0f, body_offset_y, 0.0f);
                rotate_matrix_y(0, rotation_y);
                TObjEneMe3Stelth__render_node_index = 0;
                if (mode == 1) {
                    TObjMotion::draw();
                } else {
                    draw_motion_model();
                }
                pop_matrix();
            }
            if (stealthed != 0) {
                if (behavior_flags & 8) {
                    fade.clear_flag_and_notify();
                }
            } else {
                check_flag();
            }
        } else {
            s32 i;
            if (stealthed != 0) {
                TParticleCtrl::begin_effect_render();
                if (behavior_flags & 8) {
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
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != 0) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = material_color;
                }
            }
            check_active_flag();
            push_matrix();
            post_translate_matrix(&position.x);
            translate_matrix(0, 0.0f, body_offset_y, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneMe3Stelth__render_node_index = 0;
            projection_scroll += 0x222;
            stelth_projection_texture_handle = projection_scroll;
            set_model_node_callback(TObjEneMe3Stelth::add_instance);
            if (stealthed != 0) {
                set_ginja_draw_list_mask(3);
            }
            if (mode == 1) {
                draw_ginja_motion_model();
            } else {
                draw_model();
            }
            if (stealthed != 0) {
                set_ginja_draw_list_mask(2);
            }
            set_model_node_callback(0);
            pop_matrix();
            check_flag();
            if (stealthed != 0) {
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
        init_variant();
    }
}
void TObjEneMe3Stelth::draw_with_debug_info() {
    s32 save[3];
    s32 flag;
    NJS_MOTION *motion;
    f32 frame;
    if (get_target_info() != 0) {
        if (starts_stealthed() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_enable);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_disable);
        }
        if (is_angle_in_range() != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_ground);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_roof);
        }
        queue_debug_text(pack_debug_text_position(0, 4), (char *)stelth_debug_tecniq_attack);
        queue_debug_text(pack_debug_text_position(0, 3), (char *)stelth_debug_stelth_on);
        queue_debug_text(pack_debug_text_position(0, 6), (char *)stelth_debug_stelth_off);
        queue_debug_text(pack_debug_text_position(0, 5), (char *)stelth_debug_warp);
        if (is_alternate_variant() != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_spigell);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_berill);
        }
    }
    flag = is_alternate_variant();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            NJS_TEXNAME *textures = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
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
            NJS_TEXNAME *textures = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i].texaddr = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
void TObjEneMe3Stelth::state_stealth_on(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFFFFFF1;
        this->behavior_flags |= 1;
        this->state_step = 0;
        play_sound_effect(0x3B23B, &this->position, 0, 0);
        return;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(6);
            this->behavior_flags &= ~1;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
        }
        return;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 3;
        } else if (is_split_screen() != 0) {
            switch (this->state_step) {
            case 0:
                if (this->is_passing_frame(4.0f) != 0) {
                    this->behavior_flags |= 8;
                    this->fade.reset_obstruction_fade();
                    this->state_step = 1;
                }
                break;
            case 1:
                if (this->fade.advance_timer(0.2f) != 0) {
                    this->behavior_flags &= ~8;
                    this->stealthed = 0;
                    this->state_step = 2;
                }
                break;
            }
        } else if (this->is_passing_frame(25.0f) != 0) {
            this->behavior_flags |= 8;
            this->stealthed = 1;
        } else if (this->is_passing_frame(29.0f) != 0) {
            this->behavior_flags &= ~8;
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        this->behavior_flags &= ~8;
        break;
    }
}
void TObjEneMe3Stelth::state_stealth_off(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0xB;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFFFFFF1;
        this->behavior_flags |= 1;
        this->behavior_flags |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000);
        this->state_step = 0;
        play_sound_effect(0x3B23B, &this->position, 0, 0);
        break;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(6);
            this->behavior_flags &= ~1;
        }
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 3;
        } else if (is_split_screen() != 0) {
            switch (this->state_step) {
            case 0:
                if (this->is_passing_frame(4.0f) != 0) {
                    this->behavior_flags |= 8;
                    NJS_ARGB q = me3_stelth_offset_vec;
                    this->fade.copy_color(&q);
                    this->state_step = 1;
                }
                break;
            case 1:
                if (this->fade.decay_value_toward_floor() != 0) {
                    this->behavior_flags &= ~8;
                    this->stealthed = 0;
                    this->state_step = 2;
                }
                break;
            }
        } else if (this->is_passing_frame(4.0f) != 0) {
            this->behavior_flags |= 8;
        } else if (this->is_passing_frame(6.0f) != 0) {
            this->behavior_flags &= ~8;
            this->stealthed = 0;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        this->behavior_flags &= ~8;
        this->stealthed = 0;
        break;
    }
}
void TObjEneMe3Stelth::state_cast_barta(s32 reason) {
    Vec d;
    Vec out;
    s32 r;
    switch (reason) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFFFFFF8;
        this->behavior_flags |= 0x10000;
        this->enemy_copy_target_destination();
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(6);
        }
        break;
    case 0:
        this->update_prev_position();
        switch (this->state_step) {
        case 0:
        default:
            if (this->current_target == NULL) {
                this->transition_enemy_state(6);
                break;
            }
            {
                if (select_enemy_destination(this, this->destination, 1) != 0) {
                    copy_position_if_valid(this, this->body_center);
                    this->body_center.y += 5.0f;
                    r = ((TObjEnemy *)this)->enemy_turn_toward_dest(((StelthMovementParams *)this->movementParameters)->turn);
                    enemy_set_heading_velocity(((StelthMovementParams *)this->movementParameters)->speed, this, this->rotation_y);
                    move_with_wall_slide(this);
                } else {
                    VecCopy(&d, &this->destination);
                    subtract_vector(&d, &this->body_center);
                    r = this->turn_toward_direction(((StelthMovementParams *)this->movementParameters)->turn, &d);
                }
            }
            if (r < 0x100) {
                this->state_step = 1;
                this->requested_action = 8;
            } else {
                this->requested_action = 0xA;
            }
            break;
        case 1:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->state_timer = 0;
                this->state_step = 2;
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
                Vec offset = stelth_foie_origin_offset;
                matrix_mult_vec(0, &offset, &out);
                pop_matrix();
                if (this->current_target != NULL) {
                    VecCopy(&d, &this->destination);
                    subtract_vector(&d, &this->body_center);
                    r = this->turn_toward_direction(((StelthMovementParams *)this->movementParameters)->turn, &d);
                } else {
                    r = this->attack_params->attack_angle;
                }
                if (r < this->attack_params->attack_angle / 2 && this->current_target != NULL) {
                    if (game_difficulty_selection == 3) {
        TTecRaFoie::create(this, &out, &this->destination,
                           TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->attack_tech_level));
                    } else {
                        TTecGiFoie::create(this, &out, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[this->variant_index]->attack_tech_level));
                    }
                } else {
                    this->state_step = 3;
                }
            }
            break;
        case 2:
            if (++this->state_timer >= 0x3C) {
                this->state_step = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
    update_collisions();
}
s32 TObjEneMe3Stelth::check_move_collision(Vec *pos) {
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
    if ((body->flags & 0x80000) && get_valid_target_player(this->current_target->get_entity_id()) == 0) {
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
    if (stealthed == 1 && ((TObjBase *)source)->get_entity_id() < 0x1000 && random_ratio() <= stealth_off_chance) {
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
    attack_count = attack_count + 1;
    if (attack_count >= 2 || random_ratio() < 0.5f) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}
void TObjEneMe3StelthReal::on_target_lost() {  }

void TObjEneMe3Stelth::spawn_footstep_effects() {
    if (this->is_passing_frame(12.0f) != 0 || this->is_passing_frame(28.0f) != 0) {
        this->try_spawn_ground_effect(&this->position);
    }
}

// dead-stripped; reconstructed from its pooled literals: 23.0f (.sdata2 0x805DA810) is pooled
// between try_spawn_ground_effect's 1.0f and spawn_footstep_effects's 12.0f, before its first live user.
// Body after its sibling spawn_footstep_effects (a ground effect on a motion frame); name inferred.
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
    TParticleCtrl *effect;
    CsnHit *hit;
    VecCopy(&pos, origin);
    pos.y += 15.0f;
    hit = csnVectorUnder(&pos, ground_candidates.groups, 0x15);
    if (hit != NULL && (hit->hit_mask & 4)) {
        effect = spawn_particle_effect(&hit->contact[2].point, 0x49);
        if (effect != NULL) {
            attach_particle_model(effect, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
        }
        spawn_particle_effect(&hit->contact[2].point, 0xA4);
        play_ground_contact_sound(&position);
        return 1;
    }
    return 0;
}
