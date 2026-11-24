#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureEntryCopy.h"
#include "pso/system/memory.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecZarua.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoaReal.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/render/reflection.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/animation/MotionContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/enemy/sinowzoa/SinowZoaData.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/unk/TLobby.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleUnits.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/GinjaView.h"

#include "pso/player/PlayerAttackParams.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/technique/TTecDeband.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/base/TObjBase.h"

// load_resources fills these per kind (0 and 1) from TLobby::register_boss,
// TLobby::dispatch_shared_handler_b, TLobby::register_object and
// TLobby::dispatch_shared_handler_a.
Vec lbl_80542FB0;
player_stats *TObjEneMe3SinowZoa__base_params_by_variant[2];
AttackParams *TObjEneMe3SinowZoa__attack_params_by_variant[2];
ActorParamBlock *TObjEneMe3SinowZoa__resistance_params_by_variant[2];
TObjEneMe3SinowZoaParams *TObjEneMe3SinowZoa__kind_param_tbls[2];
// The model texture list with textures 0-2 swapped for 3-5 (load_resources); init_variant
// installs it for the alternate form (named after the Stelth twin, load_shared_resources).
NJS_TEXLIST TObjEneMe3SinowZoa__alternate_texture_list;
Vec lbl_80542FE4;
u32 *TObjEneMe3SinowZoa__material_color_pointers[4];

BmlResource * TObjEneMe3SinowZoa__bml_resource;
s32 TObjEneMe3SinowZoa__render_node_index;
TBreakUpMdlData * TObjEneMe3SinowZoa__breakup_model;


extern "C" {

void create__9TTecJelinFllll(void *, void *, void *, int);
}



TObjEneMe3SinowZoaMoveParams TObjEneMe3SinowZoa_init_params = { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } };
CollisionBody sinow_zoa_collision_parts = { { 0.0f, 0.0f, 0.0f }, 12.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f };
const char *bm_ene_me3_shinowa_zoa_model_names[] = {
    sinow_zoa_model, NULL,
};
const char *bm_ene_me3_shinowa_zoa_motion_names[] = {
    sinow_zoa_t_wait_motion, sinow_zoa_apper_motion, sinow_zoa_backstep_motion, sinow_zoa_bareta_motion,
    sinow_zoa_damage_motion, sinow_zoa_death_motion, sinow_zoa_f_attack_motion, sinow_zoa_sword_motion,
    sinow_zoa_transform_motion, sinow_zoa_wait_motion, sinow_zoa_walk_motion, NULL,
};
BmlResourceDescriptor bm_ene_me3_shinowa_zoa_resource_descriptor = {
    sinow_zoa_bml, bm_ene_me3_shinowa_zoa_model_names, bm_ene_me3_shinowa_zoa_motion_names, 1, 11,
};
const char *bm_ene_me3_zoa_low_model_names[] = {
    sinow_zoa_low_model, NULL,
};
const char *bm_ene_me3_zoa_low_motion_names[] = {
    sinow_zoa_t_wait_motion, sinow_zoa_apper_motion, sinow_zoa_backstep_motion, sinow_zoa_bareta_motion,
    sinow_zoa_damage_motion, sinow_zoa_death_motion, sinow_zoa_f_attack_motion, sinow_zoa_sword_motion,
    sinow_zoa_transform_motion, sinow_zoa_wait_motion, sinow_zoa_walk_motion, NULL,
};
BmlResourceDescriptor bm_ene_me3_zoa_low_resource_descriptor = {
    sinow_zoa_low_bml, bm_ene_me3_zoa_low_model_names, bm_ene_me3_zoa_low_motion_names, 1, 11,
};
const char *TObjEneMe3SinowZoa__name = sinow_zoa_class_name;
const char *TObjEneMe3SinowZoaReal__name = sinow_zoa_real_class_name;
TObjMotionAction TObjEneMe3SinowZoa__animation_descriptors[13] = {
    { 1, 0, 0, 0.5f, 0x80000000 },
    { 3, 0, 1, 0.7f, 0x80000000 },
    { 1, 0, 9, 0.5f, 0x80000000 },
    { 3, 0, 2, 0.8f, 0x0 },
    { 3, 0, 4, 0.4f, 0x0 },
    { 3, 0, 5, 0.6f, 0x0 },
    { 3, 0, 6, 0.7f, 0x0 },
    { 3, 0, 7, 1.0f, 0x0 },
    { 3, 0, 8, 1.0f, 0x0 },
    { 1, 0, 9, 0.5f, 0x0 },
    { 1, 0, 10, 1.1f, 0x0 },
    { 3, 0, 3, 0.7f, 0x0 },
    { 3, 0, 8, 1.0f, 0x0 },
};

// load_resources (inferred): floor_resource_callbacks pairs it with free_resources.
void TObjEneMe3SinowZoa::load_resources() {
    s32 i;
    const NJS_TEXLIST *src;
    s32 count;
    NJS_OBJECT *model;
    NJS_CNK_MODEL *chunk;
    AnimationMotion *motion;
    TBreakUpMdlData *breakup;
    TObjEneMe3SinowZoaParams *params;

    lbl_80542FB0.x = 0.0f;
    lbl_80542FB0.y = 0.0f;
    lbl_80542FB0.z = 0.0f;
    if (is_split_screen()) {
        TObjEneMe3SinowZoa__bml_resource = load_enemy_bml_resource(&bm_ene_me3_zoa_low_resource_descriptor);
    } else {
        TObjEneMe3SinowZoa__bml_resource = load_enemy_bml_resource(&bm_ene_me3_shinowa_zoa_resource_descriptor);
    }
    src = TObjEneMe3SinowZoa__bml_resource->models->texlist;
    count = src->nbTexture;
    TObjEneMe3SinowZoa__alternate_texture_list.nbTexture = count;
    TObjEneMe3SinowZoa__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(count * sizeof(NJS_TEXNAME));
    for (i = 0; i < count; i++) {
        copy_ginja_texture_entry(&TObjEneMe3SinowZoa__alternate_texture_list.textures[i], &src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3SinowZoa__alternate_texture_list.textures[i].texture = TObjEneMe3SinowZoa__alternate_texture_list.textures[i + 3].texture;
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3SinowZoa__base_params_by_variant[i] = TLobby::register_boss(sinow_zoa_base_param_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3SinowZoa__attack_params_by_variant[i] = TLobby::dispatch_shared_handler_b(sinow_zoa_attack_param_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3SinowZoa__resistance_params_by_variant[i] = TLobby::register_object(sinow_zoa_resistance_param_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3SinowZoa__kind_param_tbls[i] = (TObjEneMe3SinowZoaParams *)TLobby::dispatch_shared_handler_a(sinow_zoa_kind_param_ids[i]);
    }
    params = TObjEneMe3SinowZoa__kind_param_tbls[0];
    set_entry_value_clamped(7, params->sword_motion_speed);
    set_entry_value_clamped(4, params->damage_motion_speed);
    TObjEneMe3SinowZoa__render_node_index = 0;
    lbl_80542FE4.x = 0.0f;
    lbl_80542FE4.y = 0.0f;
    lbl_80542FE4.z = 0.0f;
    model = TObjEneMe3SinowZoa__bml_resource->models->model;
    chunk = static_cast<NJS_CNK_MODEL *>(find_model_node(model, 9)->model);
    if (chunk != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[0] = reinterpret_cast<u32 *>(chunk->polygon_list + 2);
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[0] = NULL;
    }
    chunk = static_cast<NJS_CNK_MODEL *>(find_model_node(model, 13)->model);
    if (chunk != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[1] = reinterpret_cast<u32 *>(chunk->polygon_list + 2);
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[1] = NULL;
    }
    chunk = static_cast<NJS_CNK_MODEL *>(find_model_node(model, 38)->model);
    if (chunk != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[2] = reinterpret_cast<u32 *>(chunk->polygon_list + 2);
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[2] = NULL;
    }
    motion = TObjEneMe3SinowZoa__bml_resource->motions[TObjEneMe3SinowZoa__animation_descriptors[5].motion].motion;
    breakup = new TBreakUpMdlData(TObjEneMe3SinowZoa__bml_resource->models->model, (NJS_MOTION *)motion, motion->frameCount - 1);
    TObjEneMe3SinowZoa__breakup_model = breakup;
    {
        NpcAnimationBinding info = sinow_zoa_attack_binding_desc_a;
        info.motions = TObjEneMe3SinowZoa__bml_resource->motions;
        NpcAnimationBinding info_b = sinow_zoa_attack_binding_desc_b;
        info_b.motions = TObjEneMe3SinowZoa__bml_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x49, TObjEneMe3SinowZoa__bml_resource->models->model, TObjEneMe3SinowZoa__bml_resource->models->texlist, &info, 12.0f, 0.0f);
        TObjNpcEnemy::register_animated_chunk(0x4A, TObjEneMe3SinowZoa__bml_resource->models->model, &TObjEneMe3SinowZoa__alternate_texture_list, &info, 12.0f, 0.0f);
        TObjNpcEnemy::register_animated_chunk(0x4B, TObjEneMe3SinowZoa__bml_resource->models->model, TObjEneMe3SinowZoa__bml_resource->models->texlist, &info_b, 12.0f, 0.0f);
        TObjNpcEnemy::register_animated_chunk(0x4C, TObjEneMe3SinowZoa__bml_resource->models->model, &TObjEneMe3SinowZoa__alternate_texture_list, &info_b, 12.0f, 0.0f);
    }
}

extern "C" {

int TObjEneMe3SinowZoaReal__create(void* p) { return (saddr)TObjEneMe3SinowZoaReal::create_instance(p); }

void TObjEneMe3SinowZoa::free_resources() {
    if (TObjEneMe3SinowZoa__breakup_model != NULL) {
        delete TObjEneMe3SinowZoa__breakup_model;
        TObjEneMe3SinowZoa__breakup_model = NULL;
    }
    if (TObjEneMe3SinowZoa__alternate_texture_list.textures != NULL) {
        mem_free(TObjEneMe3SinowZoa__alternate_texture_list.textures);
        TObjEneMe3SinowZoa__alternate_texture_list.textures = NULL;
    }
    if (TObjEneMe3SinowZoa__bml_resource != 0) {
        delete TObjEneMe3SinowZoa__bml_resource;
        TObjEneMe3SinowZoa__bml_resource = NULL;
    }
}

void TObjEneMe3SinowZoa::set_entry_value_clamped(s32 index, f32 speed) {
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    TObjEneMe3SinowZoa__animation_descriptors[index].speed = speed;
}

}

TObjEneMe3SinowZoa::TObjEneMe3SinowZoa(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3SinowZoa__name;
}

extern "C" {

void TObjEneMe3SinowZoaReal::init_enemy() {
    s32 kind;

    init_position_vectors();
    init_variant();
    model = (void *)TObjEneMe3SinowZoa__bml_resource->models->model;
    init_model(&sinow_zoa_collision_parts, 1);
    motion_flags = 0;
    this->set_action_table(TObjEneMe3SinowZoa__animation_descriptors);
    this->set_motion_list(TObjEneMe3SinowZoa__bml_resource->motions);
    set_animation((this->requested_action));
    kind = this->kind_index;
    reset_hp(TObjEneMe3SinowZoa__base_params_by_variant[kind], TObjEneMe3SinowZoa__attack_params_by_variant[kind], TObjEneMe3SinowZoa__resistance_params_by_variant[kind]);
    this->set_state_flag_4();
    movementParameters = &TObjEneMe3SinowZoa_init_params;
    this->wall_reach = 10.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    this->behavior_flags = 0;
    this->floor_flags = 0;
    VecCopy(&floor_point, &position);
    this->body_y = (this->position.y);
    this->body_offset_y = 0.0f;
    material_color = 0;
    this->attack_count = 0;
    this->saved_evp = (s16) this->evp;
    fade.reset_obstruction_fade();
    this->state_step = 0;
    this->state_timer = 0;
    this->backstep_angle = 0;
    this->move_speed = 0.0f;
    this->state_values[0] = 0.0f;
    this->state_values[1] = 0.0f;
    this->state_values[2] = 0.0f;
    this->state_values[3] = 0.0f;
    owned_objects[0] = NULL;
    owned_objects[1] = NULL;
    if (this->stealthed == 1) {
        set_indexed_flags(0, 0x08000000);
    } else {
        this->clear_player_status_flag(0, 0x08000000);
    }
}

TObjEneMe3SinowZoa::~TObjEneMe3SinowZoa() {
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

void TObjEneMe3SinowZoa::run_task() {
    s32 flags;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->setup_move();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    }
    update_stealth_fade();
    this->copy_pos_with_height_offset();
    this->update_body_colliders();
    flags = this->behavior_flags;
    if (flags & 0x40000) {
        this->behavior_flags = (s32) (flags & 0xFFFBFFFF);
    } else {
        submit_default_cursor_candidate();
    }
    if ((this->stealthed == 0) || (fade.has_partial_opacity() != 0)) {
        this->render_minimap_dot();
    }
    if (this->floor_flags & 0x4000) {
        request_reflection_render();
    }
}

void TObjEneMe3SinowZoa::update_stealth_fade() {
    s32 flags;
    if (actorFlags & 0x24) {
        if ((this->stealthed != 0) || (flags = this->behavior_flags, (((flags & 0x100000) == 0) == 0)) || (flags & 4)) {
            this->behavior_flags |= 4;
            if (fade.advance_toward_max() != 0) {
                this->stealthed = 0;
                this->behavior_flags &= 0xFFEFFFFB;
                this->behavior_flags |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
        if ((s16) this->mode == 0x11) {
            transition_enemy_state(0x12);
        }
    } else {
        flags = this->behavior_flags;
        if (!(flags & 0x100000) && !(flags & 4) && (fade.has_partial_opacity() != 0)) {
            if (this->stealthed != 0) {
                if (fade.decay_value_toward_floor() != 0) {
                    this->behavior_flags |= 0x40000;
                    set_indexed_flags(0, 0x08000000);
                }
            } else if (fade.advance_toward_max() != 0) {
                this->behavior_flags |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
    }
}

void TObjEneMe3SinowZoa::refresh_target() {  }

void TObjEneMe3SinowZoa::run_death_reaction() { if (this->mode != 15) { transition_enemy_state(15); } }

void TObjEneMe3SinowZoa::run_hit_reaction() {
    if (this->behavior_flags & 1) {
        clear_attack_receipts();
        if ((this->stealthed == 1) && (random_ratio() <= this->stealth_off_chance)) {
            transition_enemy_state(0x12);
        }
    } else if ((s16) this->mode != 0xE) {
        transition_enemy_state(0xE);
    }
}

void TObjEneMe3SinowZoa::run_miss_reaction() {  }

void TObjEneMe3SinowZoa::copy_pos_with_height_offset() {
    VecCopy(&body_center, &position);
    this->body_center.y = this->body_center.y + (12.0f + this->body_offset_y);
    VecCopy(&center, &position);
}

void TObjEneMe3SinowZoa::update_body_colliders() {
    bodies->offset.y = this->body_center.y - this->position.y;
}

void TObjEneMe3SinowZoa::set_intangible() { TObjEneDD::set_intangible(); sub_800F5874(38); }

void TObjEneMe3SinowZoa::clear_intangible() { TObjEneDD::clear_intangible(); sub_800F5864(38); }

void TObjEneMe3SinowZoa::setup_move_bounds() {
    if (starts_stealthed() != 0) {
        this->stealthed = 1;
    } else {
        this->stealthed = 0;
    }
    this->fade_in_start = is_outside_visible_range();
    if (this->fade_in_start == 1) {
        this->requested_action = 2;
    } else {
        this->requested_action = 0;
    }
    this->technique_chance = 0.4f + this->parameters[2];
    this->stealth_on_chance = 0.3f + this->parameters[1];
    this->stealth_off_chance = 0.1f + this->parameters[4];
    this->warp_chance = 0.5f + this->parameters[3];
    this->texture_variant = (s32) this->variant;
}

f32 TObjEneMe3SinowZoa::get_node_height() {
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

// Parameter names as in the Stelth twin's test_body_collision: a facing and the distance to test.
s32 TObjEneMe3SinowZoa::check_body_collision_at(s32 angle, f32 distance) {
    CollisionBody *body = bodies;
    u8 res;
    s32 rot = rotation_y;
    u32 flags = body->flags;
    distance *= 0.5f;
    body->offset.x = 0.0f;
    body->offset.z = distance;
    body->radius = distance;
    body->half_width = 12.0f;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = angle;
    check_enemy_body_collisions(this);
    res = (body->flags & 0x380000) != 0;
    copy_collision_body(body, &sinow_zoa_collision_parts);
    body->flags = flags;
    rotation_y = rot;
    return res;
}

#pragma push
#pragma fp_contract on

s32 TObjEneMe3SinowZoa::is_in_sword_range(f32) {
    f32 facing;
    if (fabs_float(current_target->position.y - position.y) >= 20.0f) {
        if (random_ratio() <= warp_chance) {
            transition_enemy_state(0xC);
        } else {
            return 0;
        }
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

void TObjEneMe3SinowZoa::attack_and_unequip() {
    f32 d;
    s32 near;
    TObjChara *pl;
    near = is_passing_frame(23.0f);
    if (is_passing_frame(15.0f) != 0 || near != 0) {
        if (enemy_check_target_valid() != 0) {
            if (current_target->select_melee_contact_body(this, 1.0f) != 0) {
                d = current_target->receive_physical_attack(this, 1.0f);
                current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if (d > 0.0f) {
                    if (is_alternate_variant() != 0) {
                        pl = current_target;
                        TItem *held;
                        if (TObjPlayer::is_locally_controlled(pl) != 0 && (held = (TItem *)TObjPlayer::get_equipped_weapon(pl)) != 0) {
                            TObjPlayer::send_6x26_unequip_item(static_cast<TObjPlayer *>(pl), held->get_item_id());
                            ((TObjPlayer *)pl)->get_hand_joint_position((saddr)&hand_position);
                            spawn_particle_effect(&hand_position, 0x1D0);
                        }
                    } else if (near != 0 && this->random_ratio() <= 0.1666f) {
                        TObjEneDD__sub_800BA438(this, current_target);
                    }
                }
            }
        }
        play_sound_effect(0x4003AA2B, &position, 0, 0);
    }
}

void TObjEneMe3SinowZoa::vfunc_108() {  }

s32 TObjEneMe3SinowZoa::is_target_in_range() {
    f32 distance;
    u8 in_range;

    in_range = 0;
    if (!(this->behavior_flags & 0x10000)) {
        distance = this->destination_distance;
        if ((distance > 50.0f) && (distance < 150.0f) && (this->check_body_collision_at(this->rotation_y, distance - 20.0f) == 0)) {
            in_range = 1;
        }
    }
    return in_range;
}

void TObjEneMe3SinowZoa::select_next_attack_state() {  }

s32 TObjEneMe3SinowZoa::try_run_effect_m6() {
    if (this->behavior_flags & 4) {
        fade.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}

s32 TObjEneMe3SinowZoa::try_run_effect_m7() {
    if (this->behavior_flags & 4) {
        fade.clear_flag_and_notify();
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::on_target_lost() {  }

void TObjEneMe3SinowZoa::vfunc_112() {  }

void TObjEneMe3SinowZoa::update_distance_state() {
    f32 thr = 30.0f;
    if ((this->body_y - this->position.y) > thr) {
        set_colliders_contact_high();
        return;
    }
    set_colliders_contact_low();
}

void TObjEneMe3SinowZoa::check_collisions() {
    update_body_colliders();
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
}

s32 TObjEneMe3SinowZoa::starts_stealthed() {
    return parameters[0] < 2.0f;
}

s32 TObjEneMe3SinowZoa::is_outside_visible_range() {
    u8 r = 0;
    if (parameters[0] < 1.0f ||
        (parameters[0] >= 2.0f && parameters[0] < 3.0f)) r = 1;
    return r;
}

s32 TObjEneMe3SinowZoa::acquire_target(f32 range) { return select_and_apply_target(range); }

s32 TObjEneMe3SinowZoa::is_alternate_variant() {
    u8 r = this->texture_variant >= 1;
    return r;
}

void TObjEneMe3SinowZoa::init_variant() {
    if (is_alternate_variant() != 0) {
        texlist = &TObjEneMe3SinowZoa__alternate_texture_list;
        initialize_enemy_state(0x46);
        this->kind_index = 1;
        return;
    }
    texlist = TObjEneMe3SinowZoa__bml_resource->models->texlist;
    initialize_enemy_state(0x45);
    this->kind_index = 0;
}

void TObjEneMe3SinowZoa::cast_technique() {
    saddr lv;
    lv = TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->support_tech_level);
    if (is_alternate_variant() != 0) {
        if (game_difficulty_selection == 3) {
            TTecSifta::create(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->support_tech_level));
            TTecDeband::create(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->support_tech_level));
        } else {
            TTecZarua::create_instance((saddr)this, &position, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->support_tech_level));
            create__9TTecJelinFllll(this, &position, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->support_tech_level));
        }
    } else {
        TTecResta::create(this, &position, lv);
    }
}

void TObjEneMe3SinowZoa::dispatch_action(u32 state, s32 mode) {
    switch (state) {
    case 0:
        state_reset(mode);
        return;
    case 1:
        state_fade_in(mode);
        return;
    case 3:
        state_ambush(mode);
        return;
    case 2:
        state_chase(mode);
        return;
    case 4:
        state_reveal(mode);
        return;
    case 5:
        state_appear(mode);
        return;
    case 6:
        state_chase_target(mode);
        return;
    case 7:
        state_f_attack(mode);
        return;
    case 8:
        state_sword(mode);
        return;
    case 9:
        state_backstep(mode);
        return;
    case 13:
        state_wait(mode);
        return;
    case 10:
        state_vanish(mode);
        return;
    case 11:
        state_cast_technique(mode);
        return;
    case 14:
        state_knockback(mode);
        return;
    case 15:
        state_death(mode);
        return;
    case 12:
        state_warp(mode);
        return;
    case 16:
        state_cast_barta(mode);
        return;
    case 17:
        state_stealth_on(mode);
        return;
    case 18:
        state_stealth_off(mode);
    default:
        return;
    }
}

void TObjEneMe3SinowZoa::state_reset(s32 mode) {
    switch (mode) {
    case 4:
        if (this->fade_in_start == 1) {
            this->requested_action = 2;
            set_field_378(1);
        } else {
            this->requested_action = 0;
            set_field_378(3);
        }
        set_intangible();
        this->behavior_flags |= 2;
        this->behavior_flags &= 0xFFEFFFFA;
        if (TObjEneDD::check_v2_mode() != 0) {
            this->behavior_flags &= 0xFFFEFFFF;
        }
        this->state_step = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        this->body_y = this->position.y;
        this->material_color = 0;
        this->attack_count = 0;
        return;
    case 3:
        if (this->state_step > 5) {
            if (this->fade_in_start == 1) {
                this->transition_enemy_state(1);
            } else {
                this->transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        this->state_step += 1;
        if (this->state_step == 1) {
            this->body_y = this->position.y;
            update_ground_contact();
            this->body_offset_y = this->body_y - this->position.y;
        }
        break;
    }
}

void TObjEneMe3SinowZoa::state_fade_in(s32 mode) {
    Vec v;
    f32 t;
    switch (mode) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(0);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.start_fade_in();
        VecCopy(&v, &this->position);
        t = this->body_y;
        v.y = t - 20.0f;
        if (this->stealthed == 0) {
            TBoss3Volopt__sub_800D8D88((saddr)&v);
        } else {
            create_timed_particle_emitter(&this->position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            if (this->stealthed == 1) {
                this->transition_enemy_state(2);
            } else {
                this->transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (this->fade.get_color()->a >= -0.75f) {
            this->advance_animation();
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        this->behavior_flags &= ~4;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase(s32 mode) {
    s32 timer;

    switch (mode) {
    case 4:
        this->requested_action = 9;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        this->state_timer = 0;
        this->state_values[0] = 0.0f;
        return;
    case 3:
        if (this->acquire_target(200.0f) != 0) {
            if (this->destination_distance <= 40.0f) {
                this->transition_enemy_state(0xD);
                return;
            }
            timer = this->state_timer - 1;
            this->state_timer = timer;
            if ((timer <= 0) && (this->is_target_in_range() != 0)) {
                this->state_timer = 0x3C;
                if (this->random_ratio() <= 0.01f) {
                    this->transition_enemy_state(7);
                    return;
                }
            }
        } else if (this->state_step >= 0xE10) {
            this->transition_enemy_state(0xD);
            return;
        }
        break;
    case 5:
        break;
    case 0:
        (this->state_step)++;
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->state_values[0] = (this->destination_direction.x * sin_table_lookup(this->rotation_y)) + (this->destination_direction.z * cos_table_lookup(this->rotation_y));
            if (this->state_values[0] < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->update_ground_contact();
            }
        }
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::state_ambush(s32 mode) {
    Vec v;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->behavior_flags |= 7;
        this->fade.start_fade_in();
        VecCopy(&v, &this->position);
        v.y = this->body_y - 10.0f;
        TBoss3Volopt__sub_800D8D88((saddr)&v);
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFB;
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::state_reveal(s32 mode) {
    // inferred: clears the green byte of the ARGB colour material_color
    static const u32 color_mask = 0xFFFF00FF;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        this->state_timer = 0;
        break;
    case 3:
        if (this->state_step > 0x1E) {
            this->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (this->state_step == 0) {
            if (update_linked_position(200.0f) != 0) {
                this->state_step = 1;
                this->material_color = 0x1C00FFFF;
                this->material_color &= color_mask;
                this->state_timer = 0;
            }
        } else {
            (this->state_step)++;
            this->state_timer += 0x10;
            if (this->state_timer > 0xFF) {
                this->state_timer = 0xFF;
            }
            this->material_color = (this->state_timer << 24) | (this->material_color & 0xFFFFFF);
            if (enemy_validate_retained_target(this) == 0) {
                this->state_step = 0;
                this->material_color = 0;
            }
        }
        this->update_ground_contact();
        update_distance_state();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        break;
    case 5:
        this->material_color = 0x1C00FFFF;
        this->body_offset_y = 0.0f;
        break;
    }
}

void TObjEneMe3SinowZoa::state_appear(s32 mode) {
    f32 height;
    f32 node_height;

    switch (mode) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF9;
        this->behavior_flags |= 1;
        this->state_step = 0;
        this->move_speed = 0.0f;
        if (this->enemy_has_live_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        }
        break;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            node_height = this->get_node_height();
            this->advance_animation();
            this->state_values[0] = this->get_node_height();
            this->body_y = this->body_y + (node_height - this->state_values[0]);
            this->state_step = 1;
            this->body_offset_y = this->body_y - this->position.y;
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 29.0f) {
                this->frame = 29.0f;
            }
            this->move_speed -= 0.3f;
            if (this->move_speed < -5.0f) {
                this->move_speed = -5.0f;
            }
            this->body_y = this->body_y + this->move_speed;
            height = this->get_node_height();
            this->body_y = this->body_y - (height - this->state_values[0]);
            this->state_values[0] = height;
            if (this->body_y < this->position.y) {
                this->body_y = this->position.y;
                this->state_step = 2;
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
            }
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->requested_action = 9;
                this->state_step = 3;
                this->body_y = this->position.y;
                this->body_offset_y = 0.0f;
            }
            this->advance_animation();
            break;
        }
        this->update_ground_contact();
        this->update_distance_state();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFE;
        this->body_offset_y = 0.0f;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase_target(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->destination_distance = (f32) 300.0f;
        this->move_speed = (f32) TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->walk_speed;
        this->state_values[0] = 0.0f;
        return;
    case 3:
        if (this->current_target == NULL) {
            this->on_target_lost();
            this->transition_enemy_state(0xD);
            return;
        }
        if (is_in_sword_range(state_values[0]) != 0) {
            this->transition_enemy_state(8);
            return;
        }
        if (this->is_target_in_range() != 0) {
            this->transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            spawn_footstep_effects();
            this->state_values[0] = (this->destination_direction.x * sin_table_lookup(this->rotation_y)) + (this->destination_direction.z * cos_table_lookup(this->rotation_y));
            if (this->state_values[0] < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->update_ground_contact();
            } else {
                enemy_turn_and_move_on_ground(this, 0x500, this->move_speed);
            }
            this->check_collisions();
        }
        break;
    }
}

void TObjEneMe3SinowZoa::state_f_attack(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 6;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->move_speed = 0.0f;
        this->set_active();
        break;
    case 3:
        if (this->state_step == 7 || this->get_flag_b4() != 0) {
            if (this->update_ground_contact() == 0) {
                this->transition_enemy_state(10);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch ((u32)this->state_step) {
        case 0:
            this->advance_animation();
            if (this->motion_flags & 8) {
                this->state_step = 1;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1: {
            s32 target;
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                target = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            } else {
                target = this->rotation_y;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, target, 0x1000);
            if (this->is_passing_frame(10.0f) != 0) {
                this->state_step = 2;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        }
        case 2:
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            if (this->frame + this->play_speed >= 14.0f) {
                if (this->check_body_collision_at(this->rotation_y, this->destination_distance - 20.0f) != 0) {
                    this->state_step = 7;
                } else {
                    Vec v;
                    f32 d = this->destination_distance - 20.0f;
                    VecCopy(&v, &this->position);
                    v.x = this->destination_direction.x * d + v.x;
                    v.y += 20.0f;
                    v.z = this->destination_direction.z * d + v.z;
                    if (csnVecterUnder(&v, 0x15) != 0) {
                        if (this->room == find_section_at_position(&v)) {
                            if (this->stealthed != 0) {
                                this->fade.set_rate(0.05f);
                                this->fade.reset_obstruction_fade();
                                this->behavior_flags |= 0x100000;
                                this->behavior_flags |= 0x40000;
                                this->clear_player_status_flag(0, 0x08000000);
                                this->state_step = 3;
                            } else {
                                this->state_step = 4;
                            }
                            this->state_values[0] = (this->destination_distance - 20.0f) / 12.857143f;
                            this->set_invulnerable();
                            play_sound_effect(0x4003A82C, &this->position, 0, 0);
                        } else {
                            this->state_step = 7;
                        }
                    } else {
                        this->state_step = 7;
                    }
                }
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 3:
            if (this->fade.advance_timer(0.2f) != 0) {
                this->state_step = 4;
            }
        case 4:
            this->advance_animation();
            if (this->frame + this->play_speed >= 23.0f) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 5;
                } else {
                    this->state_step = 6;
                }
                this->clear_invulnerable();
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
            }
            this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, this->state_values[0]);
            break;
        case 5:
            if (this->frame > 15.0f && this->fade.decay_value_toward_floor() != 0) {
                this->behavior_flags &= ~0x100000;
                this->state_step = 6;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
        case 6:
            this->advance_animation();
            if (this->is_passing_frame((f32)25.0f) != 0 && this->enemy_check_target_valid() != 0) {
                if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                    this->current_target->receive_physical_attack(this, 1.0f);
                    this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                }
            }
            this->state_values[0] *= 0.85f;
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->state_values[0]);
            this->check_collisions();
            break;
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

void TObjEneMe3SinowZoa::state_sword(s32 mode) {
    s32 target_angle;
    f32 cur_frame;

    switch (mode) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->behavior_flags |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000);
        if (this->stealthed != 0) {
            this->fade.set_rate(0.05f);
            this->fade.reset_obstruction_fade();
            this->behavior_flags |= 0x100000;
            this->state_step = 0;
        } else {
            this->state_step = 1;
        }
        this->state_timer = 0;
        return;
    case 3:
        if (this->state_step == 4) {
            this->behavior_flags |= 0x80000;
            this->select_next_attack_state();
        }
        return;
    case 0:
        switch (this->state_step) {
        case 0:
            if (this->fade.advance_timer(0.2f) != 0) {
                this->state_step = 1;
            }
        case 1:
            this->advance_animation();
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
            if (cur_frame >= 0.0f && cur_frame <= 5.0f) {
                TObjEneMe3SinowZoaParams *rec = TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index];
                this->move_to_shot_position(this->destination_direction.x, this->destination_direction.z, rec->sword_lunge_speed);
            } else {
                this->update_ground_contact();
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 2;
            }
            break;
        case 2:
            this->state_timer += 1;
            if (this->state_timer >= TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->sword_hold_frames) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 3;
                } else {
                    this->state_step = 4;
                }
            }
            this->update_ground_contact();
            break;
        case 3:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 4;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        this->check_collisions();
        break;
    case 5:
        break;
    }
}


void TObjEneMe3SinowZoa::state_backstep(s32 mode) {
    s32 zero;

    switch (mode) {
    case 4:
        this->requested_action = 3;
        this->set_field_378(6);
        this->clear_intangible();
        zero = 0;
        this->behavior_flags &= 0xFFEFFFF8;
        this->attack_count = zero;
        this->state_step = 3;
        if (this->acquire_target(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->backstep_angle = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            if (this->check_body_collision_at(this->backstep_angle + 0x8000, 80.0f) == 0) {
                this->destination_direction.x *= -1.0f;
                this->destination_direction.z *= -1.0f;
                this->state_step = 0;
                this->move_speed = (f32) 7.111111f;
            }
        }
        this->set_active();
        return;
    case 3:
        if (this->state_step == 3) {
            if ((this->stealthed == 0) && (this->random_ratio() <= this->stealth_on_chance)) {
                this->transition_enemy_state(0x11);
            } else if (this->random_ratio() <= this->technique_chance) {
                if (this->is_alternate_variant() != 0) {
                    if (this->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->support_tech_chance) {
                        this->transition_enemy_state(0x10);
                    } else {
                        this->transition_enemy_state(0xB);
                    }
                } else {
                    this->transition_enemy_state(0x10);
                }
            } else if (this->random_ratio() <= this->warp_chance) {
                this->transition_enemy_state(0xC);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->rotation_y = approach_angle_limited(this->rotation_y, this->backstep_angle, 0x31C7);
            if ((this->frame + this->play_speed) >= 15.0f) {
                this->state_step = 1;
                this->set_invulnerable();
                play_sound_effect(0x4003A829, &this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        case 1:
            if ((this->frame + this->play_speed) >= 24.0f) {
                this->state_step = 2;
                this->clear_invulnerable();
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
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


void TObjEneMe3SinowZoa::state_cast_technique(s32 mode) {
    switch (mode) {
    case 4:
        (this->requested_action) = 8;
        this->set_field_378(0xB);
        this->clear_intangible();
        (this->behavior_flags) &= 0xFFEFFFF8;
        if ((this->stealthed) != 0) {
            this->fade.set_rate(0.05f);
            this->fade.reset_obstruction_fade();
            (this->behavior_flags) |= 0x100000;
            (this->behavior_flags) |= 0x40000;
            this->clear_player_status_flag(0, 0x08000000);
            (this->state_step) = 0;
        } else {
            (this->state_step) = 1;
        }
        (this->state_timer) = 0;
        break;
    case 3:
        if ((this->state_timer) > TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->cast_duration) {
            this->transition_enemy_state(6);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch ((this->state_step)) {
        case 0:
            this->advance_animation();
            if (this->fade.advance_timer(0.2f) != 0) {
                (this->state_step) = 1;
            }
        case 1:
            if (this->get_flag_b4() != 0) {
                cast_technique();
                if (TObjEneDD::check_v2_mode() != 0) {
                    (this->state_step) = 3;
                } else if ((this->behavior_flags) & 0x100000) {
                    (this->state_step) = 4;
                } else {
                    (this->state_step) = 2;
                }
                (this->state_timer) = 0;
            }
            break;
        case 2:
            (this->state_timer)++;
            break;
        case 3:
            (this->state_timer)++;
            if ((this->state_timer) == 5) {
                TTecSifta::create(this, &this->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->support_tech_level));
            } else if ((this->state_timer) == 0xA) {
                TTecDeband::create(this, &this->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->support_tech_level));
                if ((this->behavior_flags) & 0x100000) {
                    (this->state_step) = 4;
                } else {
                    (this->state_step) = 2;
                }
                (this->state_timer) = 0;
            }
            break;
        case 4:
            if (this->fade.decay_value_toward_floor() != 0) {
                (this->state_step) = 2;
                (this->behavior_flags) |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        this->update_ground_contact();
        break;
    }
}

void TObjEneMe3SinowZoa::state_wait(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 9;
        set_field_378(0xD);
        this->behavior_flags &= 0xFFEFFFF8;
        this->set_intangible();
        this->attack_count = 0;
        this->state_step = 0;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(6);
        } else if (this->state_step >= 0x5A) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        (this->state_step)++;
        advance_animation();
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::state_vanish(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(6);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFFC;
        this->behavior_flags |= 4;
        this->fade.set_rate_from_divisor(0x1E);
        this->fade.reset_color();
        this->state_step = 1;
        break;
    case 3:
        if (this->state_step == 2) {
            this->transition_enemy_state(0);
        }
        break;
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
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFB;
        break;
    }
}

void TObjEneMe3SinowZoa::state_knockback(s32 mode) {
    Vec v;
    f32 len;
    switch (mode) {
    case 4:
        this->requested_action = 4;
        this->advance_animation();
        this->set_active();
        play_sound_effect(0x4003A82D, &this->position, 0, 0);
        this->behavior_flags &= 0xFFEFFFF8;
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
        VecCopy(&v, &velocity);
        len = normalize_vector_xz((Vec *)(&v));
        this->move_clamped_on_ground(v.x, v.z, len);
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

void TObjEneMe3SinowZoa::state_death(s32 mode) {
    Vec v;
    Vec p;
    this->stealthed = 0;
    switch (mode) {
    case 3:
    case 5:
        break;
    case 4:
        this->requested_action = 5;
        this->refresh_and_send_entity_flags();
        this->disable_body_collision();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            this->advance_animation();
            if (this->is_passing_frame(18.0f) != 0 || this->is_passing_frame(28.0f) != 0) {
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 1;
                this->state_timer = 0;
                v.x = 0.0f;
                v.y = 10.0f;
                v.z = 20.0f;
                rotate_y_and_translate(&v, &this->position, this->rotation_y);
                spawn_effect_f8(&v, 0x14);
            }
            break;
        case 1:
            this->state_timer += 1;
            if (this->state_timer >= 0x14) {
                this->state_step = 2;
                this->behavior_flags |= 2;
                TBoss3Volopt::create_breakup_mdl(TObjEneMe3SinowZoa__breakup_model, &sinow_zoa_breakup_params,
                                   this->texlist, &this->position, this->rotation_y);
                VecCopy(&p, &this->position);
                p.x += 20.0f * sin_table_lookup(this->rotation_y);
                p.z += 20.0f * cos_table_lookup(this->rotation_y);
                trigger_dell_biter_events(&p);
                play_sound_effect(0x4003AD2E, &this->position, 0, 0);
            }
            this->update_ground_contact();
            break;
        case 2:
            this->queue_destruction();
            break;
        }
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_warp(s32 mode) {
    Vec v;
    Vec pos;
    Vec tmp;
    s32 d[3];
    s32 i;

    switch (mode) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xC);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFF9;
        this->behavior_flags |= 1;
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 2) {
            this->stealthed = 1;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
            if (this->random_ratio() <= this->technique_chance) {
                if (this->is_alternate_variant() != 0) {
                    if (this->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->support_tech_chance) {
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
                play_sound_effect(0x4003AD2F, &this->position, 0, 0);
                this->fade.set_rate_from_divisor(0x1E);
                VecCopy(&v, &this->position);
                v.y = this->body_y - 20.0f;
                this->state_step = 1;
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
                    d[0] = (s32)(3.0f * this->random_ratio()) - 1;
                    d[1] = (s32)(2.0f * this->random_ratio()) - 1;
                    if (d[1] <= d[0]) {
                        d[1]++;
                    }
                    d[2] = -(d[0] + d[1]);
                    for (i = 0; i < 3; i++) {
                        s32 ang;
                        VecCopy(&pos, &this->current_target->position);
                        ang = this->current_target->rotation_y + ((d[i] + 1) << 14);
                        pos.x += 20.0f * cos_table_lookup(ang);
                        pos.z -= 20.0f * sin_table_lookup(ang);
                        pos.y += 5.0f;
                        VecCopy(&tmp, &pos);
                        tmp.x += pos.x - this->current_target->position.x;
                        tmp.z += pos.z - this->current_target->position.z;
                        if (check_move_collision(&tmp) == 0 &&
                            csnVector(&this->current_target->position, &tmp, 0x88E0) == 0 &&
                            csnVectorUnder(&pos, this->ground_candidates.groups, 0x15) != 0 &&
                            this->room == find_section_at_position(&pos)) {
                            VecCopy(&this->position, &pos);
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

void TObjEneMe3SinowZoa::render() {
    s32 mode;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    is_alternate_variant();
    if (this->behavior_flags & 2) {
        mode = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        mode = this->classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (mode != 0) {
        if (this->render_model_if_visible() != 0) {
            return;
        }
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        if (!(this->floor_flags & 0x4000)) {
            this->vfunc_108();
            TObjEneDD::clear_global_flag_400();
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        for (i = 0; i < 3; i++) {
            if (TObjEneMe3SinowZoa__material_color_pointers[i] != NULL) {
                *TObjEneMe3SinowZoa__material_color_pointers[i] = this->material_color;
            }
        }
        draw = 1;
        if (this->try_run_effect_m6() != 0) {
            if (defer_render() != 0) {
                draw = 0;
            } else if (this->stealthed != 0) {
                draw = 0;
            }
        } else if (this->fade.has_partial_opacity() != 0) {
            this->fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw = 0;
            }
        } else if (this->stealthed != 0) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&this->position.x);
            translate_matrix(0, 0.0f, this->body_offset_y, 0.0f);
            rotate_matrix_y(0, this->rotation_y);
            TObjEneMe3SinowZoa__render_node_index = 0;
            if (mode == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            pop_matrix();
        }
        if (this->try_run_effect_m7() == 0 && this->fade.has_partial_opacity() != 0) {
            this->fade.clear_flag_and_notify();
        }
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
    }
    TParticleCtrl::end_effect_render();
}

}

void TObjEneMe3SinowZoa::setup_move() { if (get_target_info() != 0) { setup_move_bounds(); init_variant(); } }

extern "C" {

s32 TObjEneMe3SinowZoa::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&this->floor_point) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            push_matrix();
            post_translate_matrix(&this->position.x);
            translate_matrix(0, 0.0f, this->body_offset_y, 0.0f);
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::render_demo() {
    s32 save[3];
    s32 flag;
    AnimationMotion *motion;
    f32 frame;
    if (get_target_info() != 0) {
        if (starts_stealthed() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), sinow_zoa_debug_stelth_enable);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), sinow_zoa_debug_stelth_disable);
        }
        if (is_outside_visible_range() != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), sinow_zoa_debug_appear_ground);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), sinow_zoa_debug_appear_roof);
        }
        queue_debug_text(pack_debug_text_position(0, 4), (char *)sinow_zoa_debug_tecniq_attack);
        queue_debug_text(pack_debug_text_position(0, 3), (char *)sinow_zoa_debug_stelth_on);
        queue_debug_text(pack_debug_text_position(0, 6), (char *)sinow_zoa_debug_stelth_off);
        queue_debug_text(pack_debug_text_position(0, 5), (char *)sinow_zoa_debug_warp);
        if (is_alternate_variant() != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), sinow_zoa_debug_tex_spigell);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), sinow_zoa_debug_tex_berill);
        }
    }
    flag = is_alternate_variant();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            NJS_TEXNAME *parts = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            s32 i;
            for (i = 0; i < 3; i++) {
                save[i] = parts[i].texaddr;
            }
            for (i = 0; i < 3; i++) {
                parts[i].texaddr = parts[i + 3].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 1.0f, 1.0f, 1.0f);
        {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3SinowZoa__material_color_pointers[i] != NULL) {
                    *TObjEneMe3SinowZoa__material_color_pointers[i] = 0xB000FFB0;
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
            motion = motion_list[action_table[idx].motion].motion;
            frame = parameters[3];
            if (frame < 0.0f) {
                frame = 0.0f;
            } else if (frame > (motion->frameCount - 1)) {
                frame = (motion->frameCount - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion(model, motion, frame);
            clear_motion_packed_rotation();
            current_motion = (NJS_MOTION *)motion;
            this->frame = frame;
            frame = get_node_height();
            print_float_padded(pack_debug_text_position(0, 7), 5, frame);
        } else {
            model_render_flags &= ~0x400;
        }
        pop_matrix();
        if (flag != 0) {
            s32 i;
            NJS_TEXNAME *parts = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            for (i = 0; i < 3; i++) {
                parts[i].texaddr = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneMe3SinowZoa::state_stealth_on(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.set_rate_from_divisor(0x1E);
        play_sound_effect(0x4003AD2F, &this->position, 0, 0);
        this->state_step = 0;
        break;
    case 3:
        if ((this->state_step == 1) && (this->fade.decay_value_toward_floor() != 0)) {
            this->stealthed = 1;
            this->transition_enemy_state(6);
            this->behavior_flags &= ~5;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
            break;
        }
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 1;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::state_stealth_off(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xB;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.set_rate_from_divisor(0x1E);
        this->stealthed = 0;
        this->behavior_flags |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000U);
        this->state_step = 0;
        break;
    case 3:
        if ((this->state_step == 1) && (this->fade.advance_toward_max() != 0)) {
            this->transition_enemy_state(6);
            this->behavior_flags &= ~5;
            break;
        }
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 1;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

inline s32 approach_80316C3C(TObjEneMe3SinowZoa *self) {
    copy_position_if_valid(self, self->body_center);
    self->body_center.y += 5.0f;
    return ((TObjEnemy *)self)->enemy_turn_toward_dest(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn);
}
inline s32 seek_80316C3C(TObjEneMe3SinowZoa *self, Vec *diff) {
    s32 angle;
    if (select_enemy_destination(self, self->destination, 1) != 0) {
        angle = approach_80316C3C(self);
        enemy_set_heading_velocity(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->speed, self, self->rotation_y);
        move_with_wall_slide(self);
    } else {
        VecCopy(diff, &self->destination);
        subtract_vector(diff, &self->body_center);
        angle = self->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn, diff);
    }
    return angle;
}

void TObjEneMe3SinowZoa::state_cast_barta(s32 mode) {
    s32 angle;
    Vec diff;
    Vec out;
    switch (mode) {
    case 5:
        break;
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->enemy_copy_target_destination();
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 5) {
            this->transition_enemy_state(6);
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
        default:
            if (this->current_target == NULL) {
                this->transition_enemy_state(6);
                break;
            }
            angle = seek_80316C3C(this, &diff);
            if (angle < 0x100) {
                if (this->stealthed != 0) {
                    this->fade.set_rate(0.05f);
                    this->fade.reset_obstruction_fade();
                    this->behavior_flags |= 0x100000;
                    this->behavior_flags |= 0x40000;
                    this->clear_player_status_flag(0, 0x08000000);
                    this->state_step = 1;
                } else {
                    this->state_step = 2;
                }
                this->requested_action = 8;
            } else {
                this->requested_action = 0xA;
            }
            break;
        case 1:
            this->advance_animation();
            if (this->fade.advance_timer(0.2f) != 0) {
                this->state_step = 2;
            }
        case 2:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->state_timer = 0;
                this->state_step = 3;
            }
            if (this->is_passing_frame(10.0f) != 0) {
                this->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&this->position.x);
                rotate_matrix_y(0, this->rotation_y);
                set_motion_packed_rotation();
                this->calc_joint_matrices(10.0f);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                Vec offset = sinow_zoa_barta_origin_offset;
                matrix_mult_vec(0, &offset, &out);
                pop_matrix();
                if (this->current_target != NULL) {
                    VecCopy(&diff, &this->destination);
                    subtract_vector(&diff, &this->body_center);
                    angle = this->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)this->movementParameters)->turn, &diff);
                } else {
                    angle = this->attack_params->attack_angle;
                }
                if (angle < this->attack_params->attack_angle / 2 && this->current_target != NULL) {
                    if (game_difficulty_selection == 3) {
                        TTecRaBarta::create((void *)this, (void *)(&out), (void *)(&this->position), TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->attack_tech_level));
                    } else {
                        TTecGiBarta::create_ex(this, &out, this->rotation_y, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->attack_tech_level));
                    }
                } else if (this->behavior_flags & 0x100000) {
                    this->state_step = 4;
                } else {
                    this->state_step = 5;
                }
            }
            break;
        case 3:
            if (++this->state_timer >= 0x28) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 4;
                } else {
                    this->state_step = 5;
                }
            }
            break;
        case 4:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 5;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        break;
    }
    update_collisions();
}

s32 TObjEneMe3SinowZoa::check_move_collision(const Vec *pos) {
    CollisionBody *body;
    u32 r;
    u32 saved;
    Vec saved_position;
    body = this->bodies;
    saved = body->flags;
    body->flags = 0x9D01U;
    VecCopy(&saved_position, &this->position);
    VecCopy(&this->position, pos);
    TObjPlayer::init_all_slots();
    this->check_collisions();
    this->update_enemy_collision_flags();
    if (body->flags & 0x80000) {
        if (get_valid_target_player(this->current_target->get_entity_id()) == 0) {
            VecCopy(&this->position, &saved_position);
            TObjPlayer::init_all_slots();
            return 1;
        }
    }
    if ((body->flags & 0x100000) && get_valid_target_player(this->entity_id) == 0) {
        VecCopy(&this->position, &saved_position);
        TObjPlayer::init_all_slots();
        return 1;
    }
    r = (body->flags & 0x200000) != 0;
    VecCopy(&this->position, &saved_position);
    TObjPlayer::init_all_slots();
    copy_collision_body(body, &sinow_zoa_collision_parts);
    body->flags = saved;
    return r;
}

f32 TObjEneMe3SinowZoa::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    f32 damage = TObjChara::receive_direct_attack(source, payload, collider, -1, -1);
    if (this->stealthed == 1 && random_ratio() <= this->stealth_off_chance) {
        transition_enemy_state(0x12);
    } else if (mode == 2) {
        transition_enemy_state(6);
    }
    return damage;
}

void *TObjEneMe3SinowZoaReal::create_instance(void *set_data) {
    return new TObjEneMe3SinowZoaReal(tl_04, set_data);
}

TObjEneMe3SinowZoaReal::TObjEneMe3SinowZoaReal(TObject *parent, void *set_data) : TObjEneMe3SinowZoa(parent) {
    m_name = TObjEneMe3SinowZoaReal__name;
    invoke_initialization_hook(set_data);
    setup_move_bounds();
    init_enemy();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneMe3SinowZoaReal::~TObjEneMe3SinowZoaReal() {
}

void TObjEneMe3SinowZoaReal::run_death_reaction() { TObjEneMe3SinowZoa::run_death_reaction(); }

void TObjEneMe3SinowZoaReal::run_hit_reaction() { TObjEneMe3SinowZoa::run_hit_reaction(); }

void TObjEneMe3SinowZoaReal::select_next_attack_state() {
    this->attack_count = this->attack_count + 1;
    if ((this->attack_count >= 2) || (this->random_ratio() < 0.5f)) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}

void TObjEneMe3SinowZoaReal::on_target_lost() {  }

void TObjEneMe3SinowZoa::spawn_footstep_effects() {
    if ((this->is_passing_frame(12.0f) != 0) || (this->is_passing_frame(28.0f) != 0)) {
        this->check_floor_contact(&this->position);
    }
}

// dead-stripped; reconstructed from its pooled literals as in the Stelth twin: 23.0f is pooled
// between check_floor_contact's 1.0f and spawn_footstep_effects's 12.0f, before its first live user.
void TObjEneMe3SinowZoa::spawn_ground_effect_on_frame_23() {
    if (is_passing_frame(23.0f) != 0) {
        check_floor_contact(&position);
    }
}

void TObjEneMe3SinowZoa::check_and_notify() {
    s32 x;
    x = check_floor_contact(&position);
    if (x == 0) {
        spawn_particle_effect(&position, 243);
    }
}

s32 TObjEneMe3SinowZoa::check_floor_contact(const Vec *origin) {
    Vec v;
    CsnHit *hit;
    TParticleCtrl *p;
    VecCopy(&v, origin);
    v.y += 15.0f;
    hit = csnVectorUnder(&v, this->ground_candidates.groups, 0x4007);
    if (hit != NULL) {
        this->floor_flags = hit->contact->flags;
        if (this->floor_flags & 0x4000) {
            VecCopy(&this->floor_point, &hit->contact->point);
        } else {
            VecCopy(&this->floor_point, &this->position);
        }
        if (hit->hit_mask & 4) {
            play_ground_contact_sound(&this->position);
            p = spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (p != 0) {
                attach_particle_model(p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
            return 1;
        }
        if (hit->hit_mask & 2) {
            play_ground_contact_sound(&this->position);
            p = spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (p != 0) {
                attach_particle_model(p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[3].point, 0xA4);
            return 1;
        }
    }
    return 0;
}

}
