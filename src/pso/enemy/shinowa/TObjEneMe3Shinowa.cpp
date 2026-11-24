#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaTextureEntryCopy.h"
#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/animation/MotionContext.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"
#include "pso/enemy/shinowa/ShinowaData.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResource.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/technique/TTecDeband.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"

#pragma defer_codegen on
extern "C" {
BmlResource * TObjEneMe3ShinowaMirage__bml_resource;
s32 TObjEneMe3ShinowaMirage__render_node_index;
TBreakUpMdlData * TObjEneMe3ShinowaMirage__breakup_model;
SampledMotionPoints * TObjEneMe3ShinowaMirage__sword_trail_a;
SampledMotionPoints * TObjEneMe3ShinowaMirage__sword_trail_b;
SampledMotionPoints * TObjEneMe3ShinowaMirage__attack_trail;
}

struct ShinowaBattleTables {
    Vec node_origin;
    player_stats *base[2];
    AttackParams *attack[2];
    ActorParamBlock *resistance[2];
};
LAYOUT_ASSERT(ShinowaBattleBaseOffset, offsetof(ShinowaBattleTables, base) == 0xC);
LAYOUT_ASSERT(ShinowaBattleAttackOffset, offsetof(ShinowaBattleTables, attack) == 0x14);
LAYOUT_ASSERT(ShinowaBattleResistanceOffset, offsetof(ShinowaBattleTables, resistance) == 0x1C);

extern "C" {

// Per-variant parameter tables fetched from TLobby (TObjEneMe3Stelth names the same four
// base/attack/resistance/behavior_params_by_variant).
Vec TObjEneMe3ShinowaMirage__node_origin;
__declspec(section ".data") player_stats *TObjEneMe3ShinowaMirage__base_params_by_variant[2];
__declspec(section ".data") AttackParams *TObjEneMe3ShinowaMirage__attack_params_by_variant[2];
__declspec(section ".data") ActorParamBlock *TObjEneMe3ShinowaMirage__resistance_params_by_variant[2];
__declspec(section ".data") TObjEneMe3ShinowaParams *TObjEneMe3ShinowaMirage__mirage_info_table[2];

// Copy of the model's texture list (the mirage swaps the first three texture addresses).
__declspec(section ".data") NJS_TEXLIST TObjEneMe3ShinowaMirage__alternate_texture_list;
Vec TObjEneMe3ShinowaMirage__body_node_position;
s32 *TObjEneMe3ShinowaMirage__material_color_pointers[4];

TObjEneMe3ShinowaMoveParams TObjEneMe3ShinowaMirage__init_params = {
    225.0f, 0.0f, 0x600,
};

CollisionBody shinowa_mirage_model_init_data[1] = {
    {{0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

__declspec(section ".data") const char *bm_ene_me3_shinowa_model_names[2] = {
    shinowa_model, NULL,
};

const char *bm_ene_me3_shinowa_motion_names[11] = {
    shinowa_apper_motion, shinowa_backstep_motion, shinowa_damage_motion, shinowa_death_motion,
    shinowa_f_attack_motion, shinowa_sword_motion, shinowa_transform_motion, shinowa_t_wait_motion,
    shinowa_wait_motion, shinowa_walk_motion, NULL,
};

BmlResourceDescriptor shinowa_mirage_resource_descriptor = {
    shinowa_bml, bm_ene_me3_shinowa_model_names, bm_ene_me3_shinowa_motion_names, 1, 10,
};

TObjMotionAction shinowa_mirage_motion_param_table[11] = {
    {1, 0, 7, 0.5f, ACTION_NO_BLEND_IN},
    {3, 0, 0, 1.5f, ACTION_NO_BLEND_IN},
    {3, 0, 1, 0.8f, 0},
    {3, 0, 2, 0.6f, 0},
    {3, 0, 3, 0.6f, 0},
    {3, 0, 4, 0.7f, 0},
    {3, 0, 5, 1.0f, 0},
    {3, 0, 6, 0.7f, 0},
    {1, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.5f, 0},
    {3, 0, 6, 0.7f, ACTION_NO_BLEND_IN},
};

const char *TObjEneMe3Shinowa__name = "TObjEneMe3Shinowa";
const char *TObjEneMe3ShinowaReal_class_name = "TObjEneMe3ShinowaReal";
// inferred: TObjEneMe3ShinowaMirage__class_name (was lbl_805D2AD0; the mirage ctor stores it to m_name)
const char *TObjEneMe3ShinowaMirage__class_name = "TObjEneMe3ShinowaMirage";
// inferred: motion binding load_shinowa_mirage_resources hands to TLobby::spawn_npc_enemy
const NpcAnimationBinding shinowa_mirage_spawn_binding = { NULL, shinowa_mirage_motion_param_table, 8, 9, 11 };
// inferred: shadow scale handed to draw_ground_shadow by update_player_state_default
const Vec shinowa_shadow_scale = { 2.5f, 1.0f, 1.5f };


// Floor resource callback (inferred: load_shared_resources, the TObjEneMe3SinowZoa::load_resources twin):
// loads the shared Shinowa BML, a texture-list copy for the mirage, the per-variant parameter tables,
// the breakup model and the sampled claw-trail points.
void load_shinowa_mirage_resources() {
    const NJS_TEXLIST *src;
    s32 n;
    s32 i;
    TObjEneMe3ShinowaParams *info;
    NJS_OBJECT *root;
    NJS_CNK_MODEL *cnk;
    AnimationMotion *motion;
    NJS_OBJECT *model;
    f32 step;
    NJS_MOTION *trail;

    TObjEneMe3ShinowaMirage__node_origin.x = 0.0f;
    TObjEneMe3ShinowaMirage__node_origin.y = 0.0f;
    TObjEneMe3ShinowaMirage__node_origin.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneMe3ShinowaMirage__bml_resource = load_enemy_bml_resource_named(&shinowa_mirage_resource_descriptor, "bm_ene_me3_shinowa_a.bml");
    } else {
        TObjEneMe3ShinowaMirage__bml_resource = load_enemy_bml_resource(&shinowa_mirage_resource_descriptor);
    }
    src = TObjEneMe3ShinowaMirage__bml_resource->models->texlist;
    n = src->nbTexture;
    TObjEneMe3ShinowaMirage__alternate_texture_list.nbTexture = n;
    TObjEneMe3ShinowaMirage__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        copy_ginja_texture_entry(&TObjEneMe3ShinowaMirage__alternate_texture_list.textures[i], &src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3ShinowaMirage__alternate_texture_list.textures[i + 3].texture = TObjEneMe3ShinowaMirage__alternate_texture_list.textures[i].texture;
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__base_params_by_variant[j] = TLobby::register_boss(shinowa_mirage_base_param_ids[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__attack_params_by_variant[j] = TLobby::dispatch_shared_handler_b(shinowa_mirage_attack_param_ids[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__resistance_params_by_variant[j] = TLobby::register_object(shinowa_mirage_resistance_param_ids[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__mirage_info_table[j] = (TObjEneMe3ShinowaParams *)TLobby::dispatch_shared_handler_a(shinowa_mirage_behavior_param_ids[j]);
    }
    info = TObjEneMe3ShinowaMirage__mirage_info_table[0];
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(6, info->sword_motion_speed);
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(3, info->m_10);
    TObjEneMe3ShinowaMirage__render_node_index = 0;
    TObjEneMe3ShinowaMirage__body_node_position.x = 0.0f;
    TObjEneMe3ShinowaMirage__body_node_position.y = 0.0f;
    TObjEneMe3ShinowaMirage__body_node_position.z = 0.0f;
    root = TObjEneMe3ShinowaMirage__bml_resource->models->model;
    cnk = (NJS_CNK_MODEL *)find_model_node(root, 9)->model;
    if (cnk != NULL) {
        TObjEneMe3ShinowaMirage__material_color_pointers[0] = (s32 *)(cnk->polygon_list + 2);
    } else {
        TObjEneMe3ShinowaMirage__material_color_pointers[0] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)find_model_node(root, 13)->model;
    if (cnk != NULL) {
        TObjEneMe3ShinowaMirage__material_color_pointers[1] = (s32 *)(cnk->polygon_list + 2);
    } else {
        TObjEneMe3ShinowaMirage__material_color_pointers[1] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)find_model_node(root, 38)->model;
    if (cnk != NULL) {
        TObjEneMe3ShinowaMirage__material_color_pointers[2] = (s32 *)(cnk->polygon_list + 2);
    } else {
        TObjEneMe3ShinowaMirage__material_color_pointers[2] = NULL;
    }
    motion = TObjEneMe3ShinowaMirage__bml_resource->motions[shinowa_mirage_motion_param_table[4].motion].motion;
    TBreakUpMdlData *breakup = new TBreakUpMdlData(TObjEneMe3ShinowaMirage__bml_resource->models->model, (NJS_MOTION *)motion, motion->frameCount - 1);
    TObjEneMe3ShinowaMirage__breakup_model = breakup;
    {
        Vec first;
        Vec second;
        BmlResource *res = TObjEneMe3ShinowaMirage__bml_resource;
        s32 idx = shinowa_mirage_motion_param_table[5].motion;
        model = (NJS_OBJECT *)res->models->model;
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        trail = (NJS_MOTION *)res->motions[idx].motion;
        TObjEneMe3ShinowaMirage__attack_trail = new SampledMotionPoints(2, 16.0f, 26.0f, 0.7f);
        TObjEneMe3ShinowaMirage__attack_trail->sample_node_offsets(model, trail, 0x22, &first, &second);
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        trail = (NJS_MOTION *)TObjEneMe3ShinowaMirage__bml_resource->motions[shinowa_mirage_motion_param_table[6].motion].motion;
        step = TObjEneMe3ShinowaMirage__mirage_info_table[0]->sword_motion_speed;
        if (step < 0.1f) {
            step = 0.1f;
        }
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__sword_trail_a = new SampledMotionPoints(2, 6.0f, 14.0f, step);
        TObjEneMe3ShinowaMirage__sword_trail_a->sample_node_offsets(model, trail, 0x22, &first, &second);
        second.x = 10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__sword_trail_b = new SampledMotionPoints(2, 17.0f, 23.0f, step);
        TObjEneMe3ShinowaMirage__sword_trail_b->sample_node_offsets(model, trail, 0x15, &first, &second);
    }
    {
        NpcAnimationBinding binding = shinowa_mirage_spawn_binding;
        binding.motions = TObjEneMe3ShinowaMirage__bml_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x26, TObjEneMe3ShinowaMirage__bml_resource->models->model, TObjEneMe3ShinowaMirage__bml_resource->models->texlist, &binding, 8.0f, 0.0f);
        TObjNpcEnemy::register_animated_chunk(0x27, TObjEneMe3ShinowaMirage__bml_resource->models->model, &TObjEneMe3ShinowaMirage__alternate_texture_list, &binding, 8.0f, 0.0f);
    }
}

void *TObjEneMe3ShinowaMirage__sub_800E7B74(void *p) { return ((TObjEneMe3ShinowaReal *)p)->create(); }

void TObjEneMe3ShinowaMirage::free_shared_resources() {
    if (TObjEneMe3ShinowaMirage__sword_trail_b != 0) {
        delete TObjEneMe3ShinowaMirage__sword_trail_b;
        TObjEneMe3ShinowaMirage__sword_trail_b = 0;
    }
    if (TObjEneMe3ShinowaMirage__sword_trail_a != 0) {
        delete TObjEneMe3ShinowaMirage__sword_trail_a;
        TObjEneMe3ShinowaMirage__sword_trail_a = 0;
    }
    if (TObjEneMe3ShinowaMirage__attack_trail != 0) {
        delete TObjEneMe3ShinowaMirage__attack_trail;
        TObjEneMe3ShinowaMirage__attack_trail = 0;
    }
    if (TObjEneMe3ShinowaMirage__breakup_model != 0) {
        delete TObjEneMe3ShinowaMirage__breakup_model;
        TObjEneMe3ShinowaMirage__breakup_model = 0;
    }
    if (TObjEneMe3ShinowaMirage__alternate_texture_list.textures != 0) {
        mem_free(TObjEneMe3ShinowaMirage__alternate_texture_list.textures);
        TObjEneMe3ShinowaMirage__alternate_texture_list.textures = 0;
    }
    if (TObjEneMe3ShinowaMirage__bml_resource != 0) {
        delete TObjEneMe3ShinowaMirage__bml_resource;
        TObjEneMe3ShinowaMirage__bml_resource = 0;
    }
}

void TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(s32 slot, f32 speed) {
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    shinowa_mirage_motion_param_table[slot].speed = speed;
}

TObjEneMe3Shinowa::TObjEneMe3Shinowa(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3Shinowa__name;
}
#pragma push
#pragma opt_propagation off
void TObjEneMe3Shinowa::init_enemy() {
    ShinowaBattleTables *tables = reinterpret_cast<ShinowaBattleTables *>(&TObjEneMe3ShinowaMirage__node_origin);
    init_position_vectors();
    select_gold_or_normal_variant();
    model = (void *)TObjEneMe3ShinowaMirage__bml_resource->models->model;
    init_model(shinowa_mirage_model_init_data, 1);
    motion_flags = 0;
    set_action_table(shinowa_mirage_motion_param_table);
    set_motion_list(TObjEneMe3ShinowaMirage__bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    {
        player_stats **base = tables->base;
        AttackParams **attack = tables->attack;
        ActorParamBlock **resistance = tables->resistance;
        s32 i = kind_index;
        reset_hp(base[i], attack[i], resistance[i]);
    }
    set_state_flag_4();
    movementParameters = &TObjEneMe3ShinowaMirage__init_params;
    wall_reach = 10.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    behavior_flags = 0;
    body_y = position.y;
    body_offset_y = 0.0f;
    material_color = 0;
    attack_count = 0;
    mirage_index = 0;
    m_3dc = evp;
    attack_traces[0] = TAttackTraceStrip::create((u32)0xFF0000FF, (u32)0xA08000A0);
    attack_traces[1] = TAttackTraceStrip::create((u32)0xFF0000FF, (u32)0xA08000A0);
    fade.reset_obstruction_fade();
    state_step = 0;
    state_timer = 0;
    target_angle = 0;
    move_speed = 0.0f;
    m_414 = 0.0f;
    start_position.x = 0.0f;
    start_position.y = 0.0f;
    start_position.z = 0.0f;
    particle_emitters[0] = NULL;
    particle_emitters[1] = NULL;
}
#pragma pop
TObjEneMe3Shinowa::~TObjEneMe3Shinowa() {
    attack_traces[1]->queue_destruction();
    attack_traces[1] = NULL;
    attack_traces[0]->queue_destruction();
    attack_traces[0] = NULL;
    if (particle_emitters[0] != NULL) { particle_emitters[0]->queue_destruction(); particle_emitters[0] = NULL; }
    if (particle_emitters[1] != NULL) { particle_emitters[1]->queue_destruction(); particle_emitters[1] = NULL; }
    free_collision_body_parts(this);
}

void TObjEneMe3Shinowa::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_mirage();
        return;
    }
    if (update_status_effects() != 4) {
        update_action_state();
    }
    copy_position_vector();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneMe3Shinowa::refresh_target() {  }

void TObjEneMe3Shinowa::run_death_reaction() { if (mode != 13) { transition_enemy_state(13); } }

void TObjEneMe3Shinowa::run_hit_reaction() {
    if (TObjEneDD::check_v2_mode() != 0) {
        clear_attack_receipts();
        return;
    }
    if (behavior_flags & 1) {
        clear_attack_receipts();
        return;
    }
    if ((s16) mode != 0xC) {
        transition_enemy_state(0xC);
    }
}

void TObjEneMe3Shinowa::run_miss_reaction() {  }

void TObjEneMe3Shinowa::copy_position_vector() { VecCopy(&center, &body_center); }

void TObjEneMe3Shinowa::update_body_colliders() {
    bodies->offset.y = body_offset_y + (body_center.y - position.y);
}

void TObjEneMe3Shinowa::fn_800E762C() {  }

f32 TObjEneMe3Shinowa::get_node_world_y() {
    TObjEneMe3Shinowa *self = this;
    Vec v;
    NJS_OBJECT *node;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    bind_motion_context((NJS_MOTION *)self->current_motion, self->frame);
    node = (NJS_OBJECT *)self->model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

s32 TObjEneMe3Shinowa::check_body_collision_at(s32 angle, f32 length) {
    length *= 0.5f;
    CollisionBody *body = bodies;
    s32 res;
    s32 a = rotation_y;
    s32 b = body->flags;
    body->offset.x = 0.0f;
    body->offset.z = length;
    body->radius = length;
    body->half_width = 8.0f;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = angle;
    check_enemy_body_collisions(this);
    res = (body->flags & 0x380000) != 0;
    copy_collision_body(body, shinowa_mirage_model_init_data);
    body->flags = b;
    rotation_y = a;
    return res;
}
#pragma push
#pragma fp_contract on
s32 TObjEneMe3Shinowa::check_in_range(f32) {
    f32 facing;

    if (destination_distance > 25.0f) {
        return 0;
    }
    facing = destination_direction.z * cos_table_lookup(rotation_y);
    facing += destination_direction.x * sin_table_lookup(rotation_y);
    if (facing < cos_table_lookup(0x1E00)) {
        return 0;
    }
    return 1;
}
#pragma pop
void TObjEneMe3Shinowa::apply_sword_hits() {
    s32 late_hit;
    late_hit = is_passing_frame(19.0f);
    if ((is_passing_frame(9.0f) != 0) || (late_hit != 0)) {
        if (enemy_check_target_valid() != 0) {
            if (current_target->select_melee_contact_body(this, 1.0f) != 0) {
                current_target->receive_physical_attack(this, 1.0f);
                current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if ((late_hit != 0) && (random_ratio() <= 0.1666f)) {
                    TObjEneDD__sub_800BA438(this, current_target);
                }
            }
        }
        play_sound_effect(remap_sound_for_area(0x4003AD13), &position, 0, 0);
    }
}

void TObjEneMe3Shinowa::update_player_state_default() {
    if (!(behavior_flags & 0x80000)) {
        Vec stack = shinowa_shadow_scale;
        draw_ground_shadow(&stack, 0);
    }
}

s32 TObjEneMe3Shinowa::can_hit_same_target() {
    s16 mine;
    u8 ret;
    s16 theirs;
    ret = 0;
    if (!(behavior_flags & 0x10000)) {
        if (destination_distance > 100.0f && destination_distance < 150.0f) {
            mine = (s32)((TObjBase *)this)->get_room();
            theirs = current_target->get_room();
            if (theirs == mine && check_body_collision_at(rotation_y, destination_distance - 20.0f) == 0) {
                ret = 1;
            }
        }
    }
    return ret;
}

void TObjEneMe3Shinowa::select_next_attack_state() {  }

void TObjEneMe3Shinowa::sub_800E7268() {
    this->behavior_flags |= 0x10;
    this->evp = (s16) ((s16) this->m_3dc / 2);
}

void TObjEneMe3ShinowaReal::consume_spawn_request() {
    behavior_flags &= 0xFFFFFFEF;
    evp = (s16) m_3dc;
}

s32 TObjEneMe3Shinowa::update_effect() {
    s16 cur_mode;

    cur_mode = mode;
    if ((cur_mode == 1) || (cur_mode == 9) || (behavior_flags & 0x80000)) {
        fade.set_flags_and_apply_damage_color();
    }
    return 0;
}

void TObjEneMe3Shinowa::dispatch_if_active() {
    s16 cur_mode;

    cur_mode = mode;
    if ((cur_mode == 1) || (cur_mode == 9) || (behavior_flags & 0x80000)) {
        fade.clear_flag_and_notify();
    }
}

void TObjEneMe3Shinowa::on_target_lost() {  }

void TObjEneMe3Shinowa::apply_effect_pair() {
    Vec edge[2];
    Vec *entry;
    Vec *src;

    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    entry = TObjEneMe3ShinowaMirage__sword_trail_a->lookup(frame);
    if (entry != NULL) {
        matrix_mult_vec_array(NULL, entry, edge, 2);
        attack_traces[0]->add_segment(&edge[0], &edge[1]);
    }
    src = TObjEneMe3ShinowaMirage__sword_trail_b->lookup(frame);
    if (src != NULL) {
        matrix_mult_vec_array(NULL, src, edge, 2);
        attack_traces[1]->add_segment(&edge[0], &edge[1]);
    }
    pop_matrix();
}

void TObjEneMe3Shinowa::update_by_distance() {
    f32 lim = 30.0f;
    if ((body_y - position.y) > lim) {
        set_colliders_contact_high();
        return;
    }
    set_colliders_contact_low();
}

void TObjEneMe3Shinowa::check_collisions() {
    update_body_colliders();
    check_object_collisions();
    check_enemy_body_collisions(this);
}

s32 TObjEneMe3Shinowa::is_mirage_enabled() {
    return parameters[0] < 1.0f;
}

s32 TObjEneMe3Shinowa::acquire_target(f32 range) { return select_and_apply_target(range); }

s32 TObjEneMe3Shinowa::is_gold_enabled() {
    return parameters[1] >= 1.0f;
}

void TObjEneMe3Shinowa::select_gold_or_normal_variant() {
    if (is_gold_enabled() != 0) {
        texlist = &TObjEneMe3ShinowaMirage__alternate_texture_list;
        initialize_enemy_state(0x1b);
        kind_index = 1;
        return;
    }
    texlist = TObjEneMe3ShinowaMirage__bml_resource->models->texlist;
    initialize_enemy_state(0x1a);
    kind_index = 0;
}

void TObjEneMe3Shinowa::cast_resta() {
    saddr f = TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[this->kind_index]->support_tech_level);
    TTecResta::create(this, &this->position, f);
}

void TObjEneMe3Shinowa::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        action(reason);
        return;
    case 1:
        state_fade_appear(reason);
        return;
    case 2:
        state_t_wait((s32)reason);
        return;
    case 3:
        state_drop_appear(reason);
        return;
    case 4:
        state_chase_target(reason);
        return;
    case 5:
        state_f_attack((s32)reason);
        return;
    case 6:
        state_sword_attack((s32)reason);
        return;
    case 7:
        state_backstep((s32)reason);
        return;
    case 8:
        state_scatter(reason);
        return;
    case 11:
        state_wait(reason);
        return;
    case 9:
        sub_800E50D8(reason);
        return;
    case 10:
        state_cast_support(reason);
        return;
    case 12:
        state_damage(reason);
        return;
    case 13:
        state_break_apart(reason);
        return;
    case 14:
        state_split_mirages(reason);
        return;
    case 15:
        state_fade_out(reason);
        return;
    case 16:
        state_toggle_cloak(reason);
    default:
        return;
    }
}

void TObjEneMe3Shinowa::action(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 1;
        set_field_378(1);
        set_intangible();
        behavior_flags |= 2;
        behavior_flags &= 0xFFFFFFFE;
        if (TObjEneDD::check_v2_mode() != 0) {
            behavior_flags &= 0xFFFCFFFF;
        }
        state_step = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        body_y = position.y;
        if (!(behavior_flags & 0x1000)) {
            material_color = 0;
        }
        attack_count = 0;
        return;
    case 3:
        if (state_step > 5) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        state_step += 1;
        if (state_step == 1) {
            body_y = position.y;
            update_ground_contact();
            body_offset_y = body_y - position.y;
        }
        break;
    }
}

void TObjEneMe3Shinowa::state_fade_appear(s32 reason) {
    Vec pos;
    f32 y;
    switch (reason) {
    case 4:
        requested_action = 1;
        set_field_378(0);
        set_intangible();
        behavior_flags &= 0xFFFFFFFC;
        fade.start_fade_in();
        VecCopy(&pos, &position);
        y = body_y;
        pos.y = y - 20.0f;
        TBoss3Volopt__sub_800D8D88((saddr)&pos);
        return;
    case 3:
        if (fade.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMe3Shinowa::state_t_wait(s32 reason) {
    s32 step;
    s32 ene_dd_st;
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(3);
        this->set_intangible();
        this->behavior_flags &= 0xFFFFFFFC;
        this->state_step = 0;
        this->state_timer = 0;
        return;
    case 3:
        if (this->state_step > 0x1E) {
            this->transition_enemy_state(3);
        }
        return;
    case 0:
        this->advance_animation();
        step = this->state_step;
        if (step == 0) {
            if (this->update_linked_position(200.0f) != 0) {
                static const u32 color_mask = 0xFFFF00FF;
                this->state_step = 1;
                if (!(this->behavior_flags & 0x1000)) {
                    this->material_color = 0x1C00FFFF;
                }
                this->material_color &= color_mask;
                this->state_timer = 0;
            }
        } else {
            this->state_step = (step + 1);
            this->state_timer += 0x10;
            if (this->state_timer > 0xFF) {
                this->state_timer = 0xFF;
            }
            ene_dd_st = this->state_timer;
            this->material_color = (ene_dd_st << 24) | (this->material_color & 0x00FFFFFF);
            if (enemy_validate_retained_target(this) == 0) {
                this->state_step = 0;
                if (!(this->behavior_flags & 0x1000)) {
                    this->material_color = 0;
                }
            }
        }
        this->update_ground_contact();
        update_by_distance();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        return;
    case 5:
        if (!(this->behavior_flags & 0x1000)) {
            this->material_color = 0x1C00FFFF;
        }
        this->body_offset_y = 0.0f;
        break;
    }
}

void TObjEneMe3Shinowa::state_drop_appear(s32 reason) {
    f32 new_node_y;
    f32 node_world_y;

    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xB);
        this->clear_intangible();
        this->behavior_flags &= 0xFFFFFFFD;
        this->behavior_flags |= 1;
        this->state_step = 0;
        this->move_speed = 0.0f;
        if (this->enemy_has_live_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->target_angle = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            return;
        }
        this->target_angle = (s32) this->rotation_y;
        return;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(0xB);
        }
        return;
    case 0:
        switch (this->state_step) {
        case 0:
            node_world_y = this->get_node_world_y();
            this->advance_animation();
            this->m_414 = this->get_node_world_y();
            this->body_y = this->body_y + (node_world_y - this->m_414);
            this->rotation_y += 0x8000;
            this->state_step = 1;
            this->body_offset_y = this->body_y - this->position.y;
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 29.0f) {
                this->frame = 29.0f;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_angle, 0x800);
            this->move_speed = (f32) (this->move_speed - 0.3f);
            if (this->move_speed < -5.0f) {
                this->move_speed = -5.0f;
            }
            this->body_y = this->body_y + this->move_speed;
            new_node_y = this->get_node_world_y();
            this->body_y = this->body_y - (new_node_y - this->m_414);
            this->m_414 = new_node_y;
            if (this->body_y < this->position.y) {
                this->body_y = this->position.y;
                this->state_step = 2;
                play_sound_effect(this->remap_sound_for_area(0x4003AD12), &this->position, 0, 0);
                spawn_particle_effect(&this->position, 0xF3);
            }
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->requested_action = 8;
                this->state_step = 3;
                this->body_y = this->position.y;
                this->body_offset_y = 0.0f;
            }
            this->advance_animation();
            break;
        }
        this->update_ground_contact();
        update_by_distance();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        return;
    case 5:
        this->behavior_flags &= 0xFFFFFFFE;
        this->body_offset_y = 0.0f;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3Shinowa::state_chase_target(s32 mode) {
    switch (mode) {
    case 4:
        requested_action = 9;
        set_field_378(4);
        clear_intangible();
        behavior_flags &= 0xFFFFFFFC;
        destination_distance = 300.0f;
        if (behavior_flags & 0x10) {
            move_speed = (f32) TObjEneMe3ShinowaMirage__mirage_info_table[kind_index]->m_4;
        } else {
            move_speed = (f32) TObjEneMe3ShinowaMirage__mirage_info_table[kind_index]->m_0;
        }
        m_414 = 0.0f;
        return;
    case 3:
        if ((uaddr) current_target == 0U) {
            on_target_lost();
            transition_enemy_state(0xB);
        } else if (check_in_range(m_414) != 0) {
            transition_enemy_state(6);
        } else if (can_hit_same_target() != 0) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            m_414 = (f32) ((destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y)));
            if (m_414 < cos_table_lookup(0x1000)) {
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

void TObjEneMe3Shinowa::state_f_attack(s32 reason) {
    Vec edge_b;
    Vec sp14;
    Vec v;
    f32 d;
    s32 angle;
    Vec *entry;
    switch (reason) {
    case 4:
        this->requested_action = 5;
        this->set_field_378(4);
        this->clear_intangible();
        this->behavior_flags &= ~3;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->move_speed = 0.0f;
        this->attack_traces[0]->clear_segments();
        this->set_active();
        break;
    case 3:
        if (this->state_step == 5 || ((int)this->get_flag_b4()) != 0) {
            if (this->update_ground_contact() == 0U) {
                this->transition_enemy_state(9);
            } else {
                this->transition_enemy_state(4);
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
                angle = (s32)(10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
            } else {
                angle = this->rotation_y;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, angle, 0x1000);
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
                if (this->check_body_collision_at(this->rotation_y, this->destination_distance - 20.0f) != 0) {
                    this->state_step = 5;
                } else {
                    d = this->destination_distance - 20.0f;
                    VecCopy(&v, &this->position);
                    v.x += this->destination_direction.x * d;
                    v.y += 20.0f;
                    v.z += this->destination_direction.z * d;
                    if (csnVecterUnder(&v, 0x15) != 0U) {
                        this->state_step = 3;
                        this->m_414 = (this->destination_distance - 20.0f) / 12.857143f;
                        this->set_invulnerable();
                        play_sound_effect(this->remap_sound_for_area(0x4003AD11), &this->position, 0, 0);
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
                play_sound_effect(this->remap_sound_for_area(0x4003AD12), &this->position, 0, 0);
                spawn_particle_effect(&this->position, 0xF3);
            }
            this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, this->m_414);
            this->update_body_colliders();
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
                play_sound_effect(this->remap_sound_for_area(0x4003AD13), &this->position, 0, 0);
            }
            this->m_414 *= 0.85f;
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->m_414);
            this->check_collisions();
            break;
        }
        if (this->state_step != 0) {
            entry = TObjEneMe3ShinowaMirage__attack_trail->lookup(this->frame);
            if (entry != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&this->position.x);
                rotate_matrix_y(0, this->rotation_y);
                matrix_mult_vec_array(NULL, entry, (Vec *)&sp14, 2);
                pop_matrix();
                this->attack_traces[0]->add_segment(&sp14, &edge_b);
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
void TObjEneMe3Shinowa::state_sword_attack(s32 reason) {
    s32 angle;
    TObjEneMe3ShinowaParams *info;
    switch (reason) {
    case 4:
        this->requested_action = 6;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= ~3;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->state_timer = 0;
        this->attack_traces[0]->clear_segments();
        this->attack_traces[1]->clear_segments();
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->select_next_attack_state();
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->apply_sword_hits();
            if (this->frame < 20.0f) {
                if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    angle = (s32)(10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
                } else {
                    angle = this->rotation_y;
                }
                this->rotation_y = approach_angle_limited(this->rotation_y, angle, 0x300);
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            this->apply_effect_pair();
            if (this->frame >= 0.0f && this->frame <= 5.0f) {
                info = TObjEneMe3ShinowaMirage__mirage_info_table[this->kind_index];
                ((TObjEneDD *)this)->move_to_shot_position(this->destination_direction.x, this->destination_direction.z, info->dist);
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
            if (this->state_timer <= TObjEneMe3ShinowaMirage__mirage_info_table[this->kind_index]->m_20) {
                this->frame = 25.0f;
            }
            this->update_ground_contact();
            break;
        }
        this->check_collisions();
        break;
    }
}

void TObjEneMe3Shinowa::state_backstep(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(7);
        this->clear_intangible();
        this->behavior_flags &= ~3;
        this->attack_count = 0;
        this->state_step = 3;
        if (this->acquire_target(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->target_angle = (s32)(10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
            if (this->check_body_collision_at(this->target_angle + 0x8000, 80.0f) == 0) {
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
            if (this->is_gold_enabled() != 0) {
                this->transition_enemy_state(0xA);
            } else if ((this->behavior_flags & 0x20000) || (this->is_mirage_enabled() == 0)) {
                this->behavior_flags &= ~0x30000;
                if ((TObjEneDD::check_v2_mode() != 0) && (this->is_mirage_enabled() == 0)) {
                    this->transition_enemy_state(0x10);
                } else {
                    this->transition_enemy_state(4);
                }
            } else {
                this->behavior_flags |= 0x20000;
                this->transition_enemy_state(0xE);
            }
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->rotation_y = approach_angle_limited(this->rotation_y, this->target_angle, 0x31C7);
            if (this->frame + this->play_speed >= 15.0f) {
                this->state_step = 1;
                this->set_invulnerable();
                play_sound_effect(this->remap_sound_for_area(0x4003AD11), &this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        case 1:
            if (this->frame + this->play_speed >= 24.0f) {
                this->state_step = 2;
                this->clear_invulnerable();
                play_sound_effect(this->remap_sound_for_area(0x4003AD12), &this->position, 0, 0);
                spawn_particle_effect(&this->position, 0xF3);
            }
            this->move_clamped_on_ground(this->destination_direction.x, this->destination_direction.z, this->move_speed);
            this->update_body_colliders();
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

void TObjEneMe3Shinowa::state_scatter(s32 reason) {
    Vec save_pos;
    Vec save_center;
    Vec dest;
    s32 rot[3];
    f32 v;
    Vec *home = &this->start_position;

    switch (reason) {
    case 4: {
        this->behavior_flags &= ~3;
        this->clear_intangible();
        this->disable_body_collision();
        this->state_step = 0;
        this->state_timer = 0;
        this->move_speed = 1.0f;
        this->wall_reach = 30.0f;
        this->target_angle = ((this->mirage_index - (s32)floor_to_float(2.5f)) * 0x3333) / 40;
        VecCopy(home, &this->position);
        this->particle_emitters[0] = NULL;
        this->particle_emitters[1] = NULL;
        this->set_active();
        break;
    }
    case 3: {
        if (this->state_step >= 40) {
            sub_800E7268();
            s32 r = TObjEneDD::collect_target_candidates(this, 40000.0f);
            if (r > 0) {
                enemy_set_target_id(this, enemy_target_candidate_table[r - 1].id);
                this->transition_enemy_state(4);
            } else {
                this->transition_enemy_state(11);
            }
        }
        break;
    }
    case 0:
        this->advance_animation();
        this->state_step++;
        if (is_target_unobstructed_from((TObjEneDD *)this, this->current_target) != 0) {
            if ((s16)this->get_room() == (s16)this->current_target->get_room()) {
                this->enemy_copy_target_destination();
            }
        }
        this->update_velocity();
        rotate_xz_pair_by_angle(&this->destination_direction.x, &this->destination_direction.z, this->target_angle);
        v = this->destination_distance;
        if (v > 80.0f) {
            v -= 3.0f;
            if (v < 80.0f) {
                v = 80.0f;
            }
        } else if (v < 80.0f) {
            v += 3.0f;
            if (v > 80.0f) {
                v = 80.0f;
            }
        }
        VecCopy(&save_pos, &this->position);
        VecCopy(&save_center, &this->body_center);
        VecCopy(&this->position, &this->destination);
        VecCopy(&this->body_center, &this->position);
        this->body_center.y += 20.0f;
        v *= this->move_speed;
        calc_wall_clamped_destination(this, &dest, -this->destination_direction.x, -this->destination_direction.z, v);
        if (this->update_actor_ground_y_at(&dest) == 0) {
            this->move_speed *= 0.8f;
            VecCopy(&this->position, &save_pos);
            VecCopy(&this->body_center, &save_center);
        } else {
            this->move_speed = 1.0f;
            VecCopy(&this->position, &save_pos);
            VecCopy(&this->body_center, &save_center);
            subtract_vector(&dest, &this->position);
            f32 len = normalize_vector_xz(&dest);
            this->move_clamped_on_ground(dest.x, dest.z, len);
        }
        this->rotation_y = (s32)(10430.38043493439 * atan2_float(this->destination_direction.x, this->destination_direction.z));
        if (this->target_angle != 0) {
            rot[0] = 0;
            if (this->target_angle > 0) {
                rot[1] = this->rotation_y;
            } else {
                rot[1] = this->rotation_y - 0x8000;
            }
            rot[2] = -0x4000;
            if (this->particle_emitters[0] == NULL) {
                this->particle_emitters[0] = (TParticleCtrl *)create_particle_emitter(&this->position, 0x115);
                if (this->particle_emitters[0] != NULL) {
                    this->particle_emitters[0]->enable();
                    this->particle_emitters[0]->set_flags(2);
                }
            } else {
                this->particle_emitters[0]->set_direction(rot);
                this->particle_emitters[0]->set_position(&this->position);
            }
            if (this->particle_emitters[1] == NULL) {
                this->particle_emitters[1] = (TParticleCtrl *)create_particle_emitter(&this->position, 0x116);
                if (this->particle_emitters[1] != NULL) {
                    this->particle_emitters[1]->enable();
                    this->particle_emitters[1]->set_flags(2);
                }
            } else {
                this->particle_emitters[1]->set_direction(rot);
                this->particle_emitters[1]->set_position(&this->position);
            }
        }
        this->update_body_colliders();
        break;
    case 5:
        this->enable_body_collision();
        this->wall_reach = 10.0f;
        if (this->particle_emitters[0] != NULL) {
            this->particle_emitters[0]->queue_destruction();
            this->particle_emitters[0] = NULL;
        }
        if (this->particle_emitters[1] != NULL) {
            this->particle_emitters[1]->queue_destruction();
            this->particle_emitters[1] = NULL;
        }
        this->clear_field_388();
        break;
    }
}

void TObjEneMe3Shinowa::state_cast_support(s32 reason) {
    switch (reason) {
    case 4:
        requested_action = 7;
        set_field_378(0xA);
        clear_intangible();
        behavior_flags &= ~3;
        state_step = 0;
        state_timer = 0;
        break;
    case 3:
        if (state_timer > TObjEneMe3ShinowaMirage__mirage_info_table[kind_index]->m_1c) {
            transition_enemy_state(4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        switch (state_step) {
        case 0:
            if (get_flag_b4() != 0) {
                cast_resta();
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
                TTecSifta::create(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[kind_index]->support_tech_level));
            } else if (state_timer == 0xA) {
                TTecDeband::create(this, &position, (s32)(TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[kind_index]->support_tech_level)));
                state_step = 1;
                state_timer = 0;
            }
            break;
        }
        update_ground_contact();
        break;
    }
}

void TObjEneMe3Shinowa::state_wait(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(0xB);
        this->behavior_flags &= ~3;
        this->set_intangible();
        this->attack_count = 0;
        this->state_step = 0;
        return;
    case 3:
        if (this->update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(4);
        } else if (this->state_step >= 0x5A) {
            this->transition_enemy_state(9);
        }
        return;
    case 0:
        this->state_step++;
        this->advance_animation();
        this->update_ground_contact();
        break;
    case 5:
        break;
    }
}

void TObjEneMe3Shinowa::sub_800E50D8(s32 reason) {
    u32 flags;
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(4);
        this->set_intangible();
        this->behavior_flags &= ~3;
        flags = this->behavior_flags;
        if (flags & 0x80000) {
            this->behavior_flags = flags & ~0x80000;
            this->state_step = 2;
            return;
        }
        this->fade.reset_color();
        this->state_step = 1;
        return;
    case 3:
        if (this->state_step == 2) {
            this->transition_enemy_state(0);
        }
    case 5:
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
        break;
    }
}

void TObjEneMe3Shinowa::state_damage(s32 reason) {
    Vec dir;
    f32 len;
    switch (reason) {
    case 4:
        this->requested_action = 3;
        this->advance_animation();
        this->set_active();
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            this->transition_enemy_state(this->next_mode);
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&dir, &this->velocity);
        len = normalize_vector_xz(&dir);
        this->move_clamped_on_ground(dir.x, dir.z, len);
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
void TObjEneMe3Shinowa::state_break_apart(s32 reason) {
    Vec effect_pos;
    Vec pos;
    switch (reason) {
    case 4:
        requested_action = 4;
        refresh_and_send_entity_flags();
        disable_body_collision();
        behavior_flags &= ~3;
        state_step = 0;
        break;
    case 3:
    case 5:
        break;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (is_passing_frame(13.0f) != 0 || is_passing_frame(25.0f) != 0) {
                play_sound_effect(remap_sound_for_area(0x4003AD12), &position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                state_step = 1;
                state_timer = 0;
                effect_pos.x = 0.0f;
                effect_pos.y = 10.0f;
                effect_pos.z = 20.0f;
                rotate_y_and_translate(&effect_pos, &position, rotation_y);
                spawn_effect_f8(&effect_pos, 0x14);
            }
            break;
        case 1:
            state_timer++;
            if (state_timer >= 0x14) {
                state_step = 2;
                behavior_flags |= 2;
                TBoss3Volopt::create_breakup_mdl(TObjEneMe3ShinowaMirage__breakup_model, &shinowa_mirage_breakup_params,
                                   texlist, &position, rotation_y);
                VecCopy(&pos, &position);
                pos.x += 20.0f * sin_table_lookup(rotation_y);
                pos.z += 20.0f * cos_table_lookup(rotation_y);
                trigger_dell_biter_events(&pos);
                play_sound_effect(remap_sound_for_area(0x4003AD16), &position, 0, 0);
            }
            update_ground_contact();
            break;
        case 2:
            queue_destruction();
            break;
        }
        break;
    }
}
#pragma pop
void TObjEneMe3Shinowa::state_split_mirages(s32) {  }

void TObjEneMe3Shinowa::state_fade_out(s32) {  }

void TObjEneMe3Shinowa::state_toggle_cloak(s32) {  }

void TObjEneMe3ShinowaMirage::advance_camera_ctrl_step(NJS_OBJECT *) {
    if ((s32) TObjEneMe3ShinowaMirage__render_node_index == 1) {
        forward_transform_to_view(&TObjEneMe3ShinowaMirage__node_origin, &TObjEneMe3ShinowaMirage__body_node_position);
    }
    TObjEneMe3ShinowaMirage__render_node_index += 1;
}

void TObjEneMe3Shinowa::render() {
    s32 detail;
    s32 draw;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    is_gold_enabled();
    if (behavior_flags & 2) {
        detail = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        detail = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        update_player_state_default();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 3; i++) {
            if (TObjEneMe3ShinowaMirage__material_color_pointers[i] != NULL) {
                *TObjEneMe3ShinowaMirage__material_color_pointers[i] = material_color;
            }
        }
        draw = 1;
        if ((update_effect() != 0) && (defer_render() != 0)) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&position.x);
            translate_matrix(0, 0.0f, body_offset_y, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneMe3ShinowaMirage__render_node_index = 0;
            set_chunk_model_node_callback(TObjEneMe3ShinowaMirage::advance_camera_ctrl_step);
            if (detail == 1) {
                TObjMotion::draw();
            } else {
                draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        dispatch_if_active();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        VecCopy(&body_center, &TObjEneMe3ShinowaMirage__body_node_position);
    } else if ((get_main_phase() == 0xF) || (is_split_screen() == 0)) {
        VecCopy(&body_center, &position);
    }
    TParticleCtrl::end_effect_render();
}

void TObjEneMe3Shinowa::update_mirage() { if (get_target_info() != 0) { fn_800E762C(); select_gold_or_normal_variant(); } }
#pragma push
#pragma pool_data off
// Debug viewer: the mirage and gold-texture switches, then the model posed in
// action parameters[2] at frame parameters[3] (unposed when mode is not 0).
void TObjEneMe3Shinowa::render_demo() {
    s32 gold;
    NJS_TEXNAME *textures;
    GinjaTextureState *saved_texaddr[3];
    s32 i;
    if (get_target_info() != 0) {
        if (is_mirage_enabled() != 0) {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:ENABLE");
        } else {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:DISABLE");
        }
        if (is_gold_enabled() != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:GOLD");
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:NORMAL");
        }
    }
    gold = is_gold_enabled();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        TObjPlayer::toggle_particle_effect();
        if (gold != 0) {
            textures = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            for (i = 0; i < 3; i++) {
                saved_texaddr[i] = textures[i + 3].texture;
            }
            for (i = 0; i < 3; i++) {
                textures[i + 3].texaddr = textures[i].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 1.0f, 1.0f,
                     1.0f);
        for (i = 0; i < 3; i++) {
            if (TObjEneMe3ShinowaMirage__material_color_pointers[i] != NULL) {
                *TObjEneMe3ShinowaMirage__material_color_pointers[i] = 0xB000FFB0;
            }
        }
        if (mode == 0) {
            s32 action = (s32)parameters[2];
            AnimationMotion *motion;
            f32 at_frame;
            if (action < 0) {
                action = 0;
            } else if (action >= 11) {
                action = 10;
            }
            motion = motion_list[action_table[action].motion].motion;
            at_frame = parameters[3];
            if (at_frame < 0.0f) {
                at_frame = 0.0f;
            } else if (at_frame > (motion->frameCount - 1)) {
                at_frame = (motion->frameCount - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion(model, motion, at_frame);
            clear_motion_packed_rotation();
            current_motion = (NJS_MOTION *)motion;
            frame = at_frame;
            print_float_padded(pack_debug_text_position(0, 4), 5, get_node_world_y());
        } else {
            model_render_flags &= ~0x400;
            draw_chunk_object(model);
        }
        pop_matrix();
        if (gold != 0) {
            textures = reinterpret_cast<NJS_TEXLIST *>(texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i + 3].texture = saved_texaddr[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
#pragma pop
TObjEneMe3ShinowaReal *TObjEneMe3ShinowaReal::create() {
    return new TObjEneMe3ShinowaReal(tl_04, this);
}

TObjEneMe3ShinowaReal::TObjEneMe3ShinowaReal(TObject *parent, void *set_data) : TObjEneMe3Shinowa(parent) {
    s32 i;
    m_name = TObjEneMe3ShinowaReal_class_name;
    invoke_initialization_hook(set_data);
    fn_800E762C();
    init_enemy();
    mirage_index = 0;
    behavior_flags &= ~0x1000;
    for (i = 0; i < 4; i++) {
        mirage_ids[i] = 0xFFFF;
    }
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneMe3ShinowaReal::~TObjEneMe3ShinowaReal() {}

void TObjEneMe3ShinowaReal::run_death_reaction() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::run_death_reaction();
}

void TObjEneMe3ShinowaReal::run_hit_reaction() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::run_hit_reaction();
}

void TObjEneMe3ShinowaReal::try_spawn_mirages() {
    if (behavior_flags & 0x10) {
        consume_spawn_request();
        spawn_mirages();
    }
}

u16 TObjEneMe3ShinowaReal::get_target_id() { return this->target_id; }

TObjEneMe3ShinowaMirage *TObjEneMe3ShinowaReal::get_or_create_mirage(s32 index) {
    TObjEneMe3ShinowaMirage *mirage;
    if (mirage_ids[index] == 0xFFFF) {
        mirage = TObjEneMe3ShinowaMirage::create(this, (u16)(entity_id + index + 1), set_index + index + 1);
        if (mirage != NULL) {
            mirage_ids[index] = mirage->get_entity_id();
        }
    } else {
        mirage = (TObjEneMe3ShinowaMirage *)find_entity_by_id(mirage_ids[index]);
    }
    return mirage;
}

void TObjEneMe3ShinowaReal::select_next_attack_state() {
    attack_count++;
    if (attack_count >= 2) {
        try_spawn_mirages();
        transition_enemy_state(7);
        return;
    }
    transition_enemy_state(4);
}

void TObjEneMe3ShinowaReal::on_target_lost() { try_spawn_mirages(); }

void TObjEneMe3ShinowaReal::spawn_mirages() {
    int i;
    for (i = 0; i < 4; i++) {
        get_or_create_mirage(i)->init_mirage();
    }
}
#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaReal::state_split_mirages(s32 mode) {
    s32 i;
    s32 n;
    Vec pos;
    switch (mode) {
    case 4:
        requested_action = 7;
        set_field_378(0xE);
        clear_intangible();
        behavior_flags &= ~3;
        particle_emitters[0] = NULL;
        break;
    case 3:
        if (get_flag_b4() != 0) {
            validate_counter = validate_period;
            i = 0;
            if (is_confused() != 0 || is_player_entity_id(target_id) != 0) {
                if (is_target_unobstructed_from(this, current_target) != 0) {
                    i = 1;
                }
            } else {
                ((TObjEneDD_ST *)(this))->enemy_clear_target();
            }
            if (i == 1) {
                enemy_copy_target_destination();
                mirage_index = (s32)(5.0f * random_ratio());
                i = 0;
                n = 0;
                for (; i < 5; i++) {
                    if (mirage_index != i) {
                        get_or_create_mirage(n++)->activate_mirage(i);
                    }
                }
                transition_enemy_state(8);
                play_sound_effect(remap_sound_for_area(0x4003AD15), &position, 0, 0);
            } else {
                try_spawn_mirages();
                transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        if (frame >= 12.0f) {
            if (particle_emitters[0] == NULL) {
                particle_emitters[0] = create_particle_emitter(&position, 0x114);
                if (particle_emitters[0] != NULL) {
                    particle_emitters[0]->enable();
                }
            } else {
                VecCopy(&pos, &position);
                pos.x = 15.0f * sin_table_lookup(rotation_y) + pos.x;
                pos.y += 17.0f;
                pos.z = 15.0f * cos_table_lookup(rotation_y) + pos.z;
                particle_emitters[0]->set_position(&pos);
            }
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        if (particle_emitters[0] != NULL) {
            particle_emitters[0]->queue_destruction();
            particle_emitters[0] = NULL;
        }
        break;
    }
}

void TObjEneMe3ShinowaReal::state_toggle_cloak(s32 mode) {
    Vec pos;
    u32 flags;
    TParticleCtrl *emitter;
    switch (mode) {
    case 4:
        requested_action = 7;
        set_field_378(0x10);
        clear_intangible();
        behavior_flags &= ~2;
        behavior_flags |= 1;
        state_step = 0;
        particle_emitters[0] = NULL;
        return;
    case 3:
        if (state_step == 3) {
            try_spawn_mirages();
            transition_enemy_state(4);
        }
        return;
    case 0:
        switch (state_step) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                flags = behavior_flags;
                if (flags & 0x80000) {
                    fade.reset_obstruction_fade();
                    state_step = 1;
                } else {
                    behavior_flags = flags | 0x80000;
                    fade.reset_color();
                    state_step = 2;
                }
            }
            if (frame >= 12.0f) {
                if (particle_emitters[0] == NULL) {
                    particle_emitters[0] = create_particle_emitter(&position, 0x114);
                    emitter = particle_emitters[0];
                    if (emitter != NULL) {
                        emitter->enable();
                    }
                } else {
                    VecCopy(&pos, &position);
                    pos.x += 15.0f * sin_table_lookup(rotation_y);
                    pos.y += 17.0f;
                    pos.z += 15.0f * cos_table_lookup(rotation_y);
                    particle_emitters[0]->set_position(&pos);
                }
            }
            break;
        case 1:
            if (fade.advance_toward_max() != 0) {
                state_step = 3;
                behavior_flags &= ~0x80000;
            }
            break;
        case 2:
            if (fade.decay_value_toward_floor() != 0) {
                state_step = 3;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        return;
    case 5:
        emitter = particle_emitters[0];
        if (emitter != NULL) {
            emitter->queue_destruction();
            particle_emitters[0] = NULL;
        }
        break;
    }
}
#pragma pop
TObjEneMe3ShinowaMirage *TObjEneMe3ShinowaMirage::create(TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index) {
    return new TObjEneMe3ShinowaMirage(tl_04, owner, entity_id, set_index);
}

TObjEneMe3ShinowaMirage::TObjEneMe3ShinowaMirage(TObject *parent, TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index) : TObjEneMe3Shinowa(parent) {
    CollisionBody *body;

    m_name = TObjEneMe3ShinowaMirage__class_name;
    owner_id = owner->get_entity_id();
    init_common_from(owner);
    parameters[1] = owner->parameters[1];
    fn_800E762C();
    this->entity_id = entity_id;
    this->set_index = set_index;
    init_enemy();
    mirage_index = 0;
    behavior_flags |= 0x1000;
    set_flag_0x100();
    material_color = 0xB000FFB0;
    position.y = -500.0f;
    prev_position.y = -500.0f;
    body = bodies;
    body->center.y = -500.0f;
    actorFlags |= 0x800;
    fade_color.a = 0.0f;
    fade_color.r = 0.0f;
    fade_color.g = 0.0f;
    fade_color.b = 0.0f;
    fade.set_rate_from_divisor(0);
    fade.reset_color();
    mode = 8;
    dispatch_action(mode, 4);
}

TObjEneMe3ShinowaMirage::~TObjEneMe3ShinowaMirage() {}

void TObjEneMe3ShinowaMirage::run_task() {
    TObjCollidable *owner;

    if ((owner = find_entity_by_id(owner_id)) == NULL || owner->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    if (!(behavior_flags & 0x100)) {
        TObjEneMe3Shinowa::run_task();
    }
}

void TObjEneMe3ShinowaMirage::run_death_reaction() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
}

void TObjEneMe3ShinowaMirage::run_hit_reaction() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
    clear_attack_receipts();
}

void TObjEneMe3ShinowaMirage::apply_sword_hits() {  }

s32 TObjEneMe3ShinowaMirage::can_hit_same_target() { return 0; }

void TObjEneMe3ShinowaMirage::select_next_attack_state() { transition_enemy_state(4); }

void TObjEneMe3ShinowaMirage::update_player_state_default() {  }

void TObjEneMe3ShinowaMirage::activate_mirage(s32 index) {
    TObjEneMe3ShinowaReal *owner;

    owner = (TObjEneMe3ShinowaReal *)find_entity_by_id(owner_id);
    if (owner != NULL) {
        VecCopy(&position, &owner->position);
        VecCopy(&prev_position, &position);
        VecCopy(&bodies->center, &position);
        copy_xyz(&rotation_x, &owner->rotation_x);
        actorFlags &= ~0x800;
        actorFlags = 0x20000000;
        hp = hpmax;
        mirage_index = index;
        enemy_set_target_id(this, owner->get_target_id());
        fade_color.a = 0.0f;
        behavior_flags &= ~0x200;
        requested_action = 10;
        advance_animation();
        frame = (f32)(u32)(current_motion->nbFrame - 1);
        transition_enemy_state(8);
        clear_mirage();
    }
}

void TObjEneMe3ShinowaMirage::init_mirage() { transition_enemy_state(15); }

void TObjEneMe3ShinowaMirage::set_flag_0x100() {
    behavior_flags |= 0x100;
    disable_body_collision();
}

void TObjEneMe3ShinowaMirage::clear_mirage() {
    behavior_flags &= ~0x100;
    enable_body_collision();
}

s32 TObjEneMe3ShinowaMirage::update_effect() {
    model_render_flags |= 0x820;
    set_constant_material(&fade_color);
    set_chunk_material_override_pair(0xFF00, 0x800);
    return 0;
}

void TObjEneMe3ShinowaMirage::dispatch_if_active() {
    fade.clear_flag_and_notify();
}

void TObjEneMe3ShinowaMirage::apply_effect_pair() {  }

void TObjEneMe3ShinowaMirage::render() {
    if (!(behavior_flags & 0x100)) {
        TObjEneMe3Shinowa::render();
    }
}

void TObjEneMe3ShinowaMirage::state_fade_out(s32 mode) {
    switch (mode) {
    case 4:
        behavior_flags &= ~3;
        behavior_flags |= 0x200;
        disable_body_collision();
        fade_color.a = 0.0f;
        return;
    case 3:
        if (fade_color.a <= -1.0f) {
            behavior_flags &= ~0x200;
            set_flag_0x100();
            position.y = -500.0f;
            prev_position.y = -500.0f;
            bodies->center.y = -500.0f;
            actorFlags |= 0x800;
        }
    case 5:
        return;
    case 0:
        fade_color.a -= 0.1f;
        update_ground_contact();
        break;
    }
}
}
