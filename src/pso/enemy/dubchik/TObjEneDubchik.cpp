#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/effect/TAttackTrace.h"
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
#include "pso/player/TObjPlayer_800D8FDC.h"
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
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D853C.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
BmlResource *dubchik_resource;
NJS_TEXLIST *dubchik_texlist;
NJS_TEXLIST *dubchik_variant_texlist;
}
NJS_OBJECT *lbl_805D509C;
NJS_OBJECT *lbl_805D50A0;
TBreakUpMdlData *breakup_model_ptr;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {

// What TLobby::register_boss / dispatch_shared_handler_b / register_object / dispatch_shared_handler_a
// (0x1B + variant) return; the behavior table spans 0x50 bytes in the original, only [0] and [1] are read.
__declspec(section ".data") player_stats *dubchik_base_params_by_variant[2];
__declspec(section ".data") AttackParams *dubchik_attack_params_by_variant[2];
__declspec(section ".data") ActorParamBlock *dubchik_resistance_params_by_variant[2];
TObjEneDubchikBehaviorParams *dubchik_behavior_params_by_variant[20];
NJS_OBJECT *dubchik_part0_nodes[4];
NJS_OBJECT *dubchik_part1_nodes[12];
NJS_OBJECT *dubchik_part2_nodes[42];
// The two claw edges (nodes 0x1C/0x24 and 0x2E/0x32) sampled over scratch01 [0] and scratch02 [1].
__declspec(section ".data") SampledMotionPoints *dubchik_scratch_trail0_points[2];
__declspec(section ".data") SampledMotionPoints *dubchik_scratch_trail1_points[2];



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

__declspec(section ".data") f32 dubchik_walk_speed_by_variant[2] = { 0.37037036f, 0.5703704f };
__declspec(section ".data") s32 dubchik_walk_action_by_variant[2] = { 1, 19 };

// Installed as TObjMotion::action_table by the constructor.
TObjMotionAction dubchik_action_table[20] = {
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

BreakUpParamRow dubchik_breakup_params = { 0x14, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f };

TBoss3VoloptP01Movement dubchik_movement = { 150.0f, 0.37037036f, 0x400, 0x1E0000, 0, 1, 0 };

__declspec(section ".data") s16 dubchik_part0_node_ids[3] = { 0x14, 0x15, -1 };
s16 dubchik_part1_node_ids[6] = { 0x2B, 0x31, 0x32, 0x33, 0x34, -1 };
s16 dubchik_part2_node_ids[9] = { 0x17, 0x1A, 0x1D, 0x1F, 0x20, 0x21, 0x23, 0x24, -1 };
__declspec(section ".data") s16 dubchik_part_root_node_ids[3] = { 0x14, 0x2B, 0x17 };





}




s32 TObjEneDubchik::undo_large_move() {
    if (fabs_float(position.x - prev_position.x) + fabs_float(position.z - prev_position.z) > 50.0f) {
        VecCopy(&position, &prev_position);
        return 1;
    }
    return 0;
}

void TObjEneDubchik::set_invuln_flags() {
    bodies->flags |= 0x0A000000;
    set_actor_flags(0x04000000U);
}

void TObjEneDubchik::clear_flag_04000000() {
    bodies->flags &= 0xF5FFFFFF;
    clear_actor_flags(0x04000000U);
}

void AttackParams::set_attack_range(f32 range) { attack_range = range; }

void TObjEneDubchik::init_level_stats(s32 variant) {
    model = dubchik_resource->models[0].model;
    texlist = variant == 0 ? dubchik_resource->models[0].texlist : dubchik_variant_texlist;
}

s32 TObjEneDubchik::get_int_parameter(s32 i) {
    return dubchik_behavior_params_by_variant[variant]->int_params[i];
}

f32 TObjEneDubchik::get_float_parameter(s32 i) {
    return dubchik_behavior_params_by_variant[variant]->float_params[i];
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
    action_table = dubchik_action_table;
    set_action_table(action_table);
    init_collision_body_parts(this, dubchik_collision_body, 1);
    movementParameters = &dubchik_movement;
    bind_enemy_combat_stats(dubchik_base_params_by_variant[variant], dubchik_attack_params_by_variant[variant], dubchik_resistance_params_by_variant[variant]);
    load_params();
    requested_action = 5;
    set_animation(requested_action);
    set_requested_action(requested_action);
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
    saver = TAttackTraceStrip::create(0x00FFFFFF, 0xA0707070);
    if (*(s16 *)((u8 *)set_data + 0xA) != 0) {
        start_appear();
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
    SampledMotionPoints **t;
    NJS_OBJECT *nodes[3];
    void *p;
    s32 m;
    s32 i;
    NJS_OBJECT *mdl;
    NJS_OBJECT *n;
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_resource = load_enemy_bml_resource_named(&bm_ene_dubchik_resource_descriptor, (const char *)dubchik_bml_filename());
    } else {
        dubchik_resource = new BmlResource(5, &bm_ene_dubchik_resource_descriptor, 0, 0, NULL);
    }
    dubchik_texlist = dubchik_resource->models[1].texlist;
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_variant_texlist = load_gvm_texture_file(dubchik_v2_gvm_filename());
    } else {
        dubchik_variant_texlist = load_gvm_texture_file(dubchik_gvm_filename());
    }
    n = find_model_node(dubchik_resource->models[1].model, 0x17);
    n->sibling = NULL;
    init_fake_tec_texlist();
    lbl_805D509C = find_model_node(dubchik_resource->models[0].model, 0x15);
    lbl_805D50A0 = find_model_node(dubchik_resource->models[0].model, 0x2A);
    find_model_node(dubchik_resource->models[1].model, 0x15)->evalflags |= NJD_EVAL_HIDE;
    p = new TBreakUpMdlData(dubchik_resource->models[0].model);
    breakup_model_ptr = static_cast<TBreakUpMdlData *>(p);
    p = new SampledMotionPoints(2, 28.0f, 35.0f, 1.0f);
    dubchik_scratch_trail0_points[0] = (SampledMotionPoints *)p;
    dubchik_scratch_trail0_points[0]->sample_two_nodes(get_bml_model(dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 6), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 36.0f, 40.0f, 1.0f);
    dubchik_scratch_trail1_points[0] = (SampledMotionPoints *)p;
    dubchik_scratch_trail1_points[0]->sample_two_nodes(get_bml_model(dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 6), 0x2E, 0x32);
    p = new SampledMotionPoints(2, 30.0f, 38.0f, 1.0f);
    t = dubchik_scratch_trail0_points;
    t[1] = (SampledMotionPoints *)p;
    t[1]->sample_two_nodes(get_bml_model(dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 7), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 50.0f, 58.0f, 1.0f);
    t = dubchik_scratch_trail1_points;
    t[1] = (SampledMotionPoints *)p;
    t[1]->sample_two_nodes(get_bml_model(dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 7), 0x2E, 0x32);
    for (i = 0; i < 2; i++) {
        dubchik_base_params_by_variant[i] = TLobby::register_boss(i + 0x1B);
        dubchik_attack_params_by_variant[i] = TLobby::dispatch_shared_handler_b(i + 0x1B);
        dubchik_resistance_params_by_variant[i] = TLobby::register_object(i + 0x1B);
        dubchik_behavior_params_by_variant[i] = (TObjEneDubchikBehaviorParams *)TLobby::dispatch_shared_handler_a(i + 0x1B);
    }
    mdl = dubchik_resource->models[0].model;
    for (i = 0; i < 3; i++) {
        nodes[i] = find_model_node(mdl, dubchik_part_root_node_ids[i]);
    }
    collect_visible_nodes(nodes[0], dubchik_part0_nodes);
    collect_visible_nodes(nodes[1], dubchik_part1_nodes);
    collect_visible_nodes(nodes[2], dubchik_part2_nodes);
    {
        s16 ids[2] = {0x1E, 0x1F};
        NpcAnimationBinding d = { NULL, dubchik_action_table, 0, 1, 20 };
        s32 j;
        d.motions = dubchik_resource->motions;
        for (j = 0; j < 2; j++) {
            BmlModelEntry *e = &dubchik_resource->models[j];
            TObjNpcEnemy::register_animated_chunk(ids[j], e->model, e->texlist, &d, 5.0f, 0.0f);
        }
    }
}
#pragma pop

void TObjEneDubchik::free_resources() {
    if (breakup_model_ptr != NULL) {
        delete (TBreakUpMdlData *)breakup_model_ptr;
        breakup_model_ptr = NULL;
    }
    if (dubchik_resource != NULL) {
        delete dubchik_resource;
        dubchik_resource = NULL;
    }
    dubchik_texlist = NULL;
    if (dubchik_variant_texlist != NULL) {
        TObjPlayer::free_if_valid((saddr)dubchik_variant_texlist);
        dubchik_variant_texlist = NULL;
    }
    TObjPlayer::reset_effect_count();
    if (dubchik_scratch_trail0_points[0] != NULL) {
        delete dubchik_scratch_trail0_points[0];
        dubchik_scratch_trail0_points[0] = NULL;
    }
    if (dubchik_scratch_trail1_points[0] != NULL) {
        delete dubchik_scratch_trail1_points[0];
        dubchik_scratch_trail1_points[0] = NULL;
    }
    if (dubchik_scratch_trail0_points[1] != NULL) {
        delete dubchik_scratch_trail0_points[1];
        dubchik_scratch_trail0_points[1] = NULL;
    }
    if (dubchik_scratch_trail1_points[1] != NULL) {
        delete dubchik_scratch_trail1_points[1];
        dubchik_scratch_trail1_points[1] = NULL;
    }
}

void *TObjEneDubchik::create(void *set_data) {
    void *o;
    void *o2;
    o = new TObjControl(tl_04);
    o2 = new TObjEneDubchik((TObject *)o, set_data);
    return o2;
}

void TObjEneDubchik::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    load_params();
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    release_destroyed_target();
    update_proximity_state();
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            run_synced_state_handler();
        }
        mode = next_action;
        state = 0;
    }
    run_synced_state_handler();
    undo_large_move();
    update_prev_position();
    VecCopy(&center, &body_center);
    if (test_actor_flags(0x04000000) == 0) {
        submit_cursor_candidate(this, -1);
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
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
    case 8: update_return_home(); break;
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
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            if (collapsed != 0) {
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(dubchik_texlist));
            } else {
                TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            }
            drew = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            apply_broken_part_visibility();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, 1.3f, 1.3f, 1.3f);
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object(model);
            } else if (behavior_flags & 4) {
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

void TObjEneDubchik::run_demo_task() {}

void TObjEneDubchik::update_proximity_state() {
    f32 temp_f31;
    TObjChara *current_target;
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
                    target = static_cast<TObjChara *>(find_active_entity_by_id(this->targetId));
                    this->update_if_active(9);
                    return;
                }
                find_target_in_range((f32) (50.0f + this->search_range));
                return;
            }
        } else if (current_target != NULL) {
            if (xz_distance_squared(&position, &target->position) < (this->attack_params->get_attack_range() * this->attack_params->get_attack_range())) {
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
        behavior_flags |= 0x01800000;
        clear_flags_30();
        if ((s32)previous_action != 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (collapsed != 0) {
                    action = 7;
                } else {
                    action = dubchik_walk_action_by_variant[variant];
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
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
        }
        break;
    case 1:
        advance_animation();
        if (requested_action == 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (collapsed != 0) {
                    action = 7;
                } else {
                    action = dubchik_walk_action_by_variant[variant];
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
        play_persistent_sound(action, this, &position, 0, 0);
        if (target != NULL) {
            if (collapsed != 0) {
                speed = get_float_parameter(2);
            } else {
                speed = dubchik_walk_speed_by_variant[variant];
            }
            update_enemy_wander_move(this, ((TObjChara *)target)->body_center, 1, speed);
            chase_distance += speed;
            turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
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
            knockback_timer = get_int_parameter(2);
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
        pos.x += velocity.x;
        pos.z += velocity.z;
        if (check_path_obstructed(this, &pos) == 0) {
            move_with_wall_slide(this);
        } else {
            velocity.x = velocity.z = 0.0f;
        }
        }
        velocity.x *= 0.75f;
        velocity.z *= 0.75f;
        if (requested_action == 0xE) {
            velocity.x = velocity.z = 0.0f;
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
        state_timer--;
        if (state_timer <= 0) {
            state = -1;
        }
        break;
    case -1:
        clear_flag_04000000();
        clear_actor_flags(0x200);
        behavior_flags &= ~1;
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

    if (behavior_flags & 0x02000000) {
        update_dying();
        return;
    }
    switch ((s32)state) {
    case 0:
        actorFlags &= ~0x200000;
        behavior_flags &= ~0x800000;
        set_invuln_flags();
        requested_action = 4;
        enemy_set_heading_velocity(-7.0f, this, rotation_y);
        render_model_and_set_attach_points();
        for (i = 0; i < 3; i++) {
            if (parts[i] == NULL && random_ratio() >= 0.5f) {
                parts[i] = new TUnk_80491478(i, this, (s32)variant != 0 ? dubchik_variant_texlist : dubchik_texlist, &part_offsets[i]);
                behavior_flags |= 0x20000 << i;
            }
        }
        play_sound_effect(remap_sound_for_area(0x4003A806), &position, 0, 0);
        set_invuln_flags();
        reassemble_count++;
        state = 1;
    case 1: {
        advance_animation();
        Vec pos = body_center;
        pos.x += velocity.x;
        pos.z += velocity.z;
        if (check_path_obstructed(this, &pos) == 0) {
            move_with_wall_slide(this);
        } else {
            velocity.x = velocity.z = 0.0f;
        }
        velocity.x *= 0.75f;
        velocity.z *= 0.75f;
        if (requested_action == 0xE) {
            if ((s32)variant != 0 || reassemble_count >= 5) {
                start_dying();
            } else {
                velocity.x = velocity.z = 0.0f;
                collapsed = 1;
                state_timer = get_int_parameter(0);
                state = 2;
            }
        }
        break;
    }
    case 2:
        state_timer--;
        if (state_timer <= 0) {
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
            behavior_flags |= 0x800000;
            state = 3;
        }
        break;
    case 3: {
        s32 all_done;
        render_model_and_set_attach_points();
        play_persistent_sound(remap_sound_for_area(0x4003AD07), this, &position, 0, 0);
        all_done = 1;
        for (i = 0; i < 3; i++) {
            if (part_hit[i] != 0 && parts[i] != NULL) {
                if (parts[i]->get_action_priority() != 0) {
                    parts[i]->queue_destruction();
                    parts[i] = NULL;
                    behavior_flags &= ~(0x20000 << i);
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
        if (test_actor_flags(0x800) == 0 && frame >= 25.0f) {
            clear_flag_04000000();
        }
        if (action_flags != 8) {
            clear_actor_flags(0xA00);
            hp = referenceHp = hpmax;
            clear_harmful_statuses();
            behavior_flags &= ~1;
            update_if_active(1);
            clear_flag_04000000();
        }
        break;
    case -1:
        clear_actor_flags(0x200);
        break;
    }
    apply_actor_gravity(this, NULL, 0.0f);
    check_object_collisions();
    check_enemy_body_collisions(this);
}

extern "C" const f32 dubchik_scratch_hit_frames[6] = { 20.0f, 34.0f, 28.0f, 54.0f, 0.7f, 0.8f };

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
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
            enemy_turn_toward_dest(((EnemyMoveParams *)movementParameters)->turn_speed);
        }
        advance_animation();
        act = -1;
        if (is_passing_frame(dubchik_scratch_hit_frames[collapsed]) != 0) {
            if (parts[2] == NULL) {
                act = 4;
            }
        } else if (is_passing_frame(dubchik_scratch_hit_frames[collapsed + 2]) != 0 && parts[1] == NULL) {
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
        h0 = dubchik_scratch_trail0_points[collapsed]->lookup((f32)frame);
        h1 = dubchik_scratch_trail1_points[collapsed]->lookup((f32)frame);
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        if (h0 != 0) {
            matrix_mult_vec_array(NULL, h0, &a1, 2);
            saver->add_segment(&a1, &b1);
        }
        if (h1 != 0) {
            saddr start = (saddr)&a2;
            matrix_mult_vec_array(NULL, h1, (Vec *)start, 2);
            saver->add_segment((Vec *)start, &b2);
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
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
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
            timer = get_int_parameter(1);
            state = 3;
        }
        break;
    case 3:
        if (target != NULL) {
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
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
            new TUnk_80491460(&muzzle_position, rotation_y, (saddr)this, get_int_parameter(3));
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
        requested_action = (behavior_flags & 0x1000000) ? 0 : 5;
        behavior_flags |= 0x800000;
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
        behavior_flags |= 4;
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
        behavior_flags &= ~5;
        actorFlags &= 0xFBFFFFFF;
        update_if_active(0);
        break;
    }
}

void TObjEneDubchik::update_return_home() {
    f32 speed;
    s32 action;
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        if (TObjEneDD::check_v2_mode() == 0) {
            if (collapsed != 0) {
                action = 7;
            } else {
                action = dubchik_walk_action_by_variant[variant];
            }
            requested_action = action;
        } else {
            requested_action = 0;
        }
        VecCopy(&move_destination, &home_position);
        state = 1;
        return;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        check_object_collisions();
        check_enemy_body_collisions(this);
        if (collapsed != 0) {
            speed = get_float_parameter(2);
        } else {
            speed = dubchik_walk_speed_by_variant[variant];
        }
        VecCopy(&move_origin, &body_center);
        calc_velocity_toward_destination(this, move_origin, move_destination, speed);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        move_with_wall_slide(this);
        if (xz_distance_squared(&position, &home_position) < 100.0f) {
            requested_action = 5;
            advance_animation();
            behavior_flags &= 0xFE7FFFFF;
            update_if_active(0);
        }
        return;
    }
}

void TObjEneDubchik::start_dying() {
    behavior_flags |= 0x02000000;
    set_actor_flags(0x800U);
}

void TObjEneDubchik::load_params() {
    dubchik_action_table[2].speed = get_float_parameter(0);
    dubchik_action_table[7].speed = get_float_parameter(3);
    dubchik_action_table[12].speed = get_float_parameter(4);
    attack_params->set_attack_range(get_float_parameter(collapsed ? 5 : 1));
}

void TObjEneDubchik::render_model_and_set_attach_points() {
    render_anim_model_at_pos();
    get_anim_node_position(0x13, &part_offsets[0]);
    get_anim_node_position(0x28, &part_offsets[1]);
    get_anim_node_position(0x29, &part_offsets[2]);
}

void TObjEneDubchik::apply_broken_part_visibility() {
    u8 *g = (u8 *)dubchik_base_params_by_variant;
    if (behavior_flags & 0x20000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x68));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x68));
    }
    if (behavior_flags & 0x40000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x78));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x78));
    }
    if (behavior_flags & 0x80000) {
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
    if (next_action == 7) {
        behavior_flags &= 0xFFFFFFFE;
        update_if_active(0);
    }
}

void TObjEneDubchik::set_flag_start_effect() {
    u32 flags = behavior_flags;
    if (!(flags & 0x04000000)) {
        behavior_flags = flags | 0x04000000;
        behavior_flags |= 1;
        behavior_flags &= 0xFF7FFFFF;
        timer = 0x1E;
        create_dead_spot(&body_center, timer, 2.0f);
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
        TBoss3Volopt::create_breakup_mdl(breakup_model_ptr, &dubchik_breakup_params,
                           texlist, &body_center, rotation_y);
        refresh_lobby_state();
        send_entity_set_flags();
        trigger_dell_biter_events(&body_center);
        set_actor_flags(0x800);
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
