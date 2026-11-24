#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/enemy/dolmolm/TObjEneDolmOlm.h"
#include "pso/render/reflection.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D853C.h"
#pragma defer_codegen on

#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/system/vector.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"

#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"

extern const f64 dolmolm_radians_to_angle[];
extern int lbl_805D69E8;

extern const char dolmolm_model_name_abgc01_wola_body_nj[0x14];
__declspec(section ".rodata") const char dolmolm_model_name_abgc01_wola_body_nj[0x14] ATTRIBUTE_ALIGN(4) = "abgc01_wola_body.nj";
extern const char dolmolm_model_name_abgc01l_wola_body_nj[0x15];
__declspec(section ".rodata") const char dolmolm_model_name_abgc01l_wola_body_nj[0x15] ATTRIBUTE_ALIGN(4) = "abgc01l_wola_body.nj";
extern const char dolmolm_motion_name_atack_l_abgc01_wola_body_njm[0x1D];
__declspec(section ".rodata") const char dolmolm_motion_name_atack_l_abgc01_wola_body_njm[0x1D] ATTRIBUTE_ALIGN(4) = "atack_l_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_atack_r_abgc01_wola_body_njm[0x1D];
__declspec(section ".rodata") const char dolmolm_motion_name_atack_r_abgc01_wola_body_njm[0x1D] ATTRIBUTE_ALIGN(4) = "atack_r_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_damage_abgc01_wola_body_njm[0x1C];
__declspec(section ".rodata") const char dolmolm_motion_name_damage_abgc01_wola_body_njm[0x1C] ATTRIBUTE_ALIGN(4) = "damage_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_dead_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const char dolmolm_motion_name_dead_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "dead_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_odori_abgc01_wola_body_njm[0x1B];
__declspec(section ".rodata") const char dolmolm_motion_name_odori_abgc01_wola_body_njm[0x1B] ATTRIBUTE_ALIGN(4) = "odori_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_wait_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const char dolmolm_motion_name_wait_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "wait_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_wait2_abgc01_wola_body_njm[0x1B];
__declspec(section ".rodata") const char dolmolm_motion_name_wait2_abgc01_wola_body_njm[0x1B] ATTRIBUTE_ALIGN(4) = "wait2_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_wake_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const char dolmolm_motion_name_wake_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "wake_abgc01_wola_body.njm";
extern const char dolmolm_motion_name_walk_abgc01_wola_body_njm[0x1A];
__declspec(section ".rodata") const char dolmolm_motion_name_walk_abgc01_wola_body_njm[0x1A] ATTRIBUTE_ALIGN(4) = "walk_abgc01_wola_body.njm";
extern const char bm_ene_abgc01_wola_body_bml_filename[0x1C];
__declspec(section ".rodata") const char bm_ene_abgc01_wola_body_bml_filename[0x1C] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body.bml";
extern const char dolmolm_model_name_lo_abgc01_wola_body_nj[0x17];
__declspec(section ".rodata") const char dolmolm_model_name_lo_abgc01_wola_body_nj[0x17] ATTRIBUTE_ALIGN(4) = "lo_abgc01_wola_body.nj";
extern const char dolmolm_model_name_lo_abgc01l_wola_body_nj[0x18];
__declspec(section ".rodata") const char dolmolm_model_name_lo_abgc01l_wola_body_nj[0x18] ATTRIBUTE_ALIGN(4) = "lo_abgc01l_wola_body.nj";
extern const char bm_ene_abgc01_wola_body_low_bml_filename[0x20];
__declspec(section ".rodata") const char bm_ene_abgc01_wola_body_low_bml_filename[0x20] ATTRIBUTE_ALIGN(4) = "bm_ene_abgc01_wola_body_low.bml";
extern const char TObjEneDolmOlm__class_name_string[0xF];
__declspec(section ".rodata") const char TObjEneDolmOlm__class_name_string[0xF] ATTRIBUTE_ALIGN(4) = "TObjEneDolmOlm";

const char *dolmolm_model_names[3] = {
    dolmolm_model_name_abgc01_wola_body_nj, dolmolm_model_name_abgc01l_wola_body_nj, NULL,
};
const char *dolmolm_motion_names[10] = {
    dolmolm_motion_name_atack_l_abgc01_wola_body_njm, dolmolm_motion_name_atack_r_abgc01_wola_body_njm, dolmolm_motion_name_damage_abgc01_wola_body_njm, dolmolm_motion_name_dead_abgc01_wola_body_njm,
    dolmolm_motion_name_odori_abgc01_wola_body_njm, dolmolm_motion_name_wait_abgc01_wola_body_njm, dolmolm_motion_name_wait2_abgc01_wola_body_njm, dolmolm_motion_name_wake_abgc01_wola_body_njm,
    dolmolm_motion_name_walk_abgc01_wola_body_njm, NULL,
};
BmlResourceDescriptor dolmolm_resource_descriptor = { bm_ene_abgc01_wola_body_bml_filename, dolmolm_model_names, dolmolm_motion_names, 2, 9 };
const char *dolmolm_low_model_names[3] = {
    dolmolm_model_name_lo_abgc01_wola_body_nj, dolmolm_model_name_lo_abgc01l_wola_body_nj, NULL,
};
const char *dolmolm_low_motion_names[10] = {
    dolmolm_motion_name_atack_l_abgc01_wola_body_njm, dolmolm_motion_name_atack_r_abgc01_wola_body_njm, dolmolm_motion_name_damage_abgc01_wola_body_njm, dolmolm_motion_name_dead_abgc01_wola_body_njm,
    dolmolm_motion_name_odori_abgc01_wola_body_njm, dolmolm_motion_name_wait_abgc01_wola_body_njm, dolmolm_motion_name_wait2_abgc01_wola_body_njm, dolmolm_motion_name_wake_abgc01_wola_body_njm,
    dolmolm_motion_name_walk_abgc01_wola_body_njm, NULL,
};
BmlResourceDescriptor dolmolm_low_resource_descriptor = { bm_ene_abgc01_wola_body_low_bml_filename, dolmolm_low_model_names, dolmolm_low_motion_names, 2, 9 };
TObjMotionAction TObjEneDolmOlm__param_table[13] = {
    {1, 0, 5, 0.8f, 1},
    {1, 0, 6, 0.6f, 0x20},
    {1, 2, 8, 0.8f, 1},
    {2, 0, 0, 0.8f, 4},
    {2, 0, 1, 0.8f, 4},
    {1, 0, 8, 0.8f, 1},
    {2, 0, 2, 0.8f, 8},
    {2, 0, 7, 0.8f, 0x20},
    {3, 0, 3, 0.7f, 0x10},
    {3, 0, 3, 0.7f, 0x10},
    {2, 0, 5, 0.8f, 0x20},
    {1, 0, 5, 0.8f, 0x20},
    {2, 0, 4, 0.8f, 4},
};
BeastMovementParams dolmolm_movement_params[2] = {
    {225.0f, 0.75f, 0x400, {0, 0x1E0000, 1, 0}},
    {300.0f, 1.0f, 0x400, {0, 0x1E0000, 1, 0}},
};
CollisionBody dolmolm_collision_bodies[2] = {
    {{0.0f, 12.5f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.5f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};


void TObjEneDolmOlm::load_params_from_table(s32 i) {
    model = TObjEneDolmOlm__resource_bundle->models[i].model;
    texlist = TObjEneDolmOlm__resource_bundle->models[i].texlist;
}
TObjEneDolmOlm::TObjEneDolmOlm(TObject *parent, void *set_data) : TUnk_80493450(parent) {
    u32 col;
    m_name = obj_ene_dolm_olm_class_name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_variant();
    action_table = TObjEneDolmOlm__param_table;
    set_action_table(action_table);
    motion_list = TObjEneDolmOlm__resource_bundle->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &dolmolm_collision_bodies[variant], 1);
    bind_enemy_combat_stats(dolm_olm_combat_stat_id_pair[variant], TObjEneDolmOlm__shared_handler_ids[variant], TObjEneDolmOlm__registered_object_ids[variant]);
    movementParameters = &dolmolm_movement_params[variant];
    referenceHp = hp;
    advance_position();
    copy_position();
    initialize_enemy_photon_effect(this);
    m_2ac = (s32)(182.04445f * (360.0f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    retreat_timer = 0;
    pad_376 = 0;
    floor_flags = 0;
    VecCopy(&floor_point, &position);
    in_group = 0;
    child_count = 0;
    add_flags_2e4(2);
    actorFlags |= 0x40000;
    switch (variant) {
    default:
        col = 0xFFDE20BD;
        break;
    case 1:
        col = 0xFFCDDE62;
        break;
    }
    fade.reset_obstruction_fade();
    appearing = 1;
    attack_traces[0] = TAttackTraceStrip::create(0xA0303030, col);
    attack_traces[1] = TAttackTraceStrip::create(0xA0303030, col);
    far_move_speed = TObjEneDolmOlm__behavior_params_by_variant[variant]->params[0];
    far_anim_speed = TObjEneDolmOlm__behavior_params_by_variant[variant]->params[1];
    near_move_speed = TObjEneDolmOlm__behavior_params_by_variant[variant]->params[2];
    near_anim_speed = TObjEneDolmOlm__behavior_params_by_variant[variant]->params[3];
    requested_action = 1;
    retreat_distance = 0.0f;
    enable_motion_blend();
    clear_lobby_object_state();
}
TObjEneDolmOlm::~TObjEneDolmOlm() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (attack_traces[i] != NULL) {
            attack_traces[i]->queue_destruction();
            attack_traces[i] = NULL;
        }
    }
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}

void TObjEneDolmOlm::load_shared_resources() {
    BmlResource *p;
    s32 i;
    if (is_split_screen() != 0) {
        p = new BmlResource(1, &dolmolm_low_resource_descriptor, 0, 0, NULL);
        TObjEneDolmOlm__resource_bundle = p;
    } else {
        p = new BmlResource(1, &dolmolm_resource_descriptor, 0, 0, NULL);
        TObjEneDolmOlm__resource_bundle = p;
    }
    TObjEneDolmOlm__left_attack_samples = new SampledMotionPoints(2, 0.0f, 20.0f, 0.8f);
    TObjEneDolmOlm__right_attack_samples = new SampledMotionPoints(2, 0.0f, 20.0f, 0.8f);
    set_motion_packed_rotation();
    TObjEneDolmOlm__left_attack_samples->sample_two_nodes(TObjEneDolmOlm__resource_bundle->models->model, (NJS_MOTION *)TObjEneDolmOlm__resource_bundle->motions[TObjEneDolmOlm__param_table[3].motion].motion, 0x1C, 0x1D);
    TObjEneDolmOlm__right_attack_samples->sample_two_nodes(TObjEneDolmOlm__resource_bundle->models->model, (NJS_MOTION *)TObjEneDolmOlm__resource_bundle->motions[TObjEneDolmOlm__param_table[4].motion].motion, 0x14, 0x15);
    clear_motion_packed_rotation();
    dolm_olm_combat_stat_id_pair = static_cast<player_stats **>(mem_alloc(8));
    TObjEneDolmOlm__shared_handler_ids = static_cast<AttackParams **>(mem_alloc(8));
    TObjEneDolmOlm__registered_object_ids = static_cast<ActorParamBlock **>(mem_alloc(8));
    TObjEneDolmOlm__behavior_params_by_variant = (DolmOlmBehaviorParams **)mem_alloc(8);
    dolm_olm_combat_stat_id_pair[0] = TLobby::register_boss(0x4F);
    dolm_olm_combat_stat_id_pair[1] = TLobby::register_boss(0x50);
    TObjEneDolmOlm__shared_handler_ids[0] = TLobby::dispatch_shared_handler_b(0x54);
    TObjEneDolmOlm__shared_handler_ids[1] = TLobby::dispatch_shared_handler_b(0x55);
    TObjEneDolmOlm__registered_object_ids[0] = TLobby::register_object(0x4E);
    TObjEneDolmOlm__registered_object_ids[1] = TLobby::register_object(0x4F);
    TObjEneDolmOlm__behavior_params_by_variant[0] = (DolmOlmBehaviorParams *)TLobby::dispatch_shared_handler_a(0x4E);
    TObjEneDolmOlm__behavior_params_by_variant[1] = (DolmOlmBehaviorParams *)TLobby::dispatch_shared_handler_a(0x4F);
    TObjEneDolmOlm__effect_render_state = 0;
    {
        s16 ids[2] = { 69, 79 };
        NpcAnimationBinding d = { TObjEneDolmOlm__resource_bundle->motions, TObjEneDolmOlm__param_table, 0, 2, 12 };
        for (i = 0; i < 2; i++) {
            BmlModelEntry *e = &TObjEneDolmOlm__resource_bundle->models[i];
            TObjNpcEnemy::register_animated_chunk(ids[i], e->model, e->texlist, &d, dolmolm_collision_bodies[i].radius, 0.0f);
        }
    }
}
void TObjEneDolmOlm::free_shared_resources() {
    if (dolm_olm_combat_stat_id_pair != NULL) {
        mem_free(dolm_olm_combat_stat_id_pair);
        dolm_olm_combat_stat_id_pair = NULL;
    }
    if (TObjEneDolmOlm__shared_handler_ids != NULL) {
        mem_free(TObjEneDolmOlm__shared_handler_ids);
        TObjEneDolmOlm__shared_handler_ids = NULL;
    }
    if (TObjEneDolmOlm__registered_object_ids != NULL) {
        mem_free(TObjEneDolmOlm__registered_object_ids);
        TObjEneDolmOlm__registered_object_ids = NULL;
    }
    if (TObjEneDolmOlm__behavior_params_by_variant != NULL) {
        mem_free(TObjEneDolmOlm__behavior_params_by_variant);
        TObjEneDolmOlm__behavior_params_by_variant = NULL;
    }
    if (TObjEneDolmOlm__right_attack_samples != NULL) {
        delete TObjEneDolmOlm__right_attack_samples;
        TObjEneDolmOlm__right_attack_samples = NULL;
    }
    if (TObjEneDolmOlm__left_attack_samples != NULL) {
        delete TObjEneDolmOlm__left_attack_samples;
        TObjEneDolmOlm__left_attack_samples = NULL;
    }
    if (TObjEneDolmOlm__resource_bundle != NULL) {
        delete TObjEneDolmOlm__resource_bundle;
        TObjEneDolmOlm__resource_bundle = NULL;
    }
}
void *TObjEneDolmOlm::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneDolmOlm(control, set_data);
}
void TObjEneDolmOlm::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    switch (mode) {
    case 0:
        beast_update_appear();
        break;
    case 1:
        beast_idle_update();
        break;
    case 2:
        update_turn_toward_target();
        break;
    case 3:
        beast_update_approach();
        init_body_sub();
        break;
    case 4:
        beast_update_group_chase();
        init_body_sub();
        break;
    case 5:
        beast_update_attack();
        break;
    case 6:
        vfunc_89();
        break;
    case 7:
        beast_update_hurt();
        break;
    case 8:
        beast_update_dead();
        break;
    case 9:
        beast_retire_corpse();
        break;
    case 10:
        update_retreat();
        init_body_sub();
        break;
    case 11:
        update_special_attack();
        init_body_sub();
        break;
    }
    advance_position();
    copy_position();
    submit_cursor_candidate(this, -1);
    if (floor_flags & 0x4000) {
        request_reflection_render();
    }
    frame_timer += 1.0f;
}
void TObjEneDolmOlm::render() {
    s32 vis;
    s16 saved;
    if (actorFlags & 0x02000000) {
        return;
    }
    if (is_split_screen() != 0) {
        TCameraCtrl::get_camera_mode();
    }
    vis = classify_actor_view_detail(200.0f, 400.0f, 30.0f);
    if (vis != 0 && render_model_if_visible() == 0) {
    select_actor_lighting(this);
    model_render_flags |= 1;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    push_matrix();
    translate_matrix(0, 0.0f, corpse_offset_y, 0.0f);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else {
        switch (mode) {
        case 0:
        case 1:
        case 8:
        case 9: {
            s16 t;
            s16 *chunk = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->model)->polygon_list;
            t = chunk[3];
            saved = t;
            chunk[3] = (u8)t;
            break;
        }
        }
        TObjPlayer::toggle_particle_effect();
        TObjEneDolmOlm__effect_render_state = 0;
        set_chunk_model_node_callback(TObjEneDolmOlm::toggle_effect_render);
        if (appearing == 1) {
            if (fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                fade.set_flags_and_apply_damage_color();
                if (defer_render() == 0) {
                    model_render_flags |= 1;
                    draw();
                    model_render_flags &= ~1;
                }
                fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (vis == 1) {
            draw();
        } else {
            draw_motion_model();
        }
        set_chunk_model_node_callback(NULL);
        TParticleCtrl::end_effect_render();
        switch (mode) {
        case 0:
        case 1:
        case 8:
        case 9:
            ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->model)->polygon_list[3] = saved;
            break;
        }
    }
    pop_matrix();
    model_render_flags &= ~1;
    restore_scene_lighting();
    switch (mode) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default:
        if (!(floor_flags & 0x4000)) {
            Vec v;
            v.x = 1.5f;
            v.y = 1.0f;
            v.z = 2.0f;
            draw_ground_shadow(&v, 0);
        }
        break;
    }
    }
}
s32 TObjEneDolmOlm::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&floor_point) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}
void TObjEneDolmOlm::toggle_effect_render(NJS_OBJECT *) {
    switch (TObjEneDolmOlm__effect_render_state) {
    case 0x15:
    case 0x1d:
    case 0x49:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    TObjEneDolmOlm__effect_render_state += 1;
}
void TObjEneDolmOlm::beast_update_appear() {
    advance_animation();
    switch (phase) {
    case 0:
    default:
        if (appearing != 0) {
            fade.start_fade_in();
            play_area_sound_effect(&position);
            phase = 1;
            return;
        }
        phase = 2;
        return;
    case 1:
        if (fade.advance_toward_max() == 1) {
            phase = 2;
            appearing = 0;
        }
        break;
    case 2:
        mode = 1;
        phase = 0;
        break;
    }
}
void TObjEneDolmOlm::select_post_attack_mode() {
    if (random_ratio() < retreat_chance) {
        mode = 0xA;
        phase = 0;
    }
}
#pragma push
#pragma opt_common_subs off
// Mode 10: backs away from the target (heading turned 0x8000) at four times its speed until it has gone 50 units or
// is out of the target's reach, then goes back to mode 3.
void TObjEneDolmOlm::update_retreat() {
    Vec v;
    f32 f;

    switch (phase) {
    case 0:
        apply_actor_gravity(this, NULL, 0.0f);
        advance_animation();
        phase = 1;
        requested_action = 2;
        retreat_distance = 0.0f;
        play_speed *= 2.0f;
        break;
    default:
    case 1:
        if (target != NULL) {
            if (test_elt_flag(0, 0x300000) != 0) {
                if ((f32)home_chase_frames++ < 60.0f) {
                    VecCopy(&v, &home_position);
                } else {
                    VecCopy(&v, &((TObjChara *)target)->body_center);
                }
            } else {
                home_chase_frames = 0;
                VecCopy(&v, &((TObjChara *)target)->body_center);
            }
            advance_animation();
            play_sound_effect(remap_sound_for_area(0x4003B205), &position, 0, 0);
            if (horizontal_distance_squared(&move_destination, &position) < 0.00001f || is_actor_cadence_frame(0x1E) != 0) {
                if (select_enemy_destination(this, v, 1) != 0) {
                    copy_position_if_valid(this, body_center);
                }
            }
            f = 4.0f * move_speed;
            if (check_path_ahead(rotation_y + 0x8000, f) == 0) {
                enemy_turn_toward_dest(((BeastMovementParams *)movementParameters)->turnSpeed);
                enemy_set_heading_velocity(f, this, rotation_y + 0x8000);
                move_with_wall_slide(this);
                retreat_distance += f;
                if (retreat_distance >= 50.0f) {
                    phase = 2;
                }
                f32 d = horizontal_distance_squared(&((TObjChara *)target)->body_center, &position);
                for (s32 i = 0; i < ((TObjChara *)target)->body_count; i++) {
                    if (d > (((TObjChara *)target)->bodies[i].radius + get_attack_range()) * (((TObjChara *)target)->bodies[i].radius + get_attack_range())) {
                        phase = 2;
                        break;
                    }
                }
            } else {
                phase = 2;
            }
        } else {
            phase = 2;
        }
        break;
    case 2:
        mode = 3;
        requested_action = 2;
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        update_target_near_flag();
        select_move_speed();
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x200000);
}
#pragma pop
#pragma push
#pragma opt_common_subs off
// Mode 11: turns to the player, plays action 12 (the odori motion) and hits a player in front of it and in range
// with TObjPlayer::play_effect(kind 2).
void TObjEneDolmOlm::update_special_attack() {
    if (targetId < 0x1000) {
        TObjPlayer *tgt = get_player_by_client_id(targetId);
        f32 d = horizontal_distance_squared(&tgt->position, &position);
        if (tgt != 0 && tgt->get_floor() == get_current_floor() &&
            d < TObjEneDolmOlm__behavior_params_by_variant[variant]->special_range * TObjEneDolmOlm__behavior_params_by_variant[variant]->special_range) {
            target = tgt;
        } else {
            target = 0;
        }
    } else {
        targetId = 0xFFFF;
        target = 0;
    }
    clear_actor_flags(0x4040000);
    advance_animation();
    switch (phase) {
    case 0:
        if (target == 0 || ((TObjBase *)target)->get_entity_id() >= 0x1000) {
            actorFlags &= ~0x200000;
            phase = 2;
            requested_action = 2;
        } else {
            TObjPlayer *p = (TObjPlayer *)target;
            if (p->check_player_flag1() != 0) {
                if (fabs_float(p->position.y - position.y) < 20.0f) {
                    mode = 5;
                    phase = 1;
                    if (0.5f < random_ratio()) {
                        requested_action = 3;
                    } else {
                        requested_action = 4;
                    }
                } else {
                    mode = 3;
                    phase = 1;
                    requested_action = 2;
                    actorFlags &= ~0x200000;
                    clear_actor_flags(0x4040000);
                    clear_player_status_flag(0, 0xA000000);
                }
            } else {
                phase = 1;
            }
        }
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 1:
        if (target != 0) {
            Vec v;
            VecCopy(&v, &((TObjChara *)target)->body_center);
            subtract_vector(&v, &body_center);
            if (turn_toward_direction(((BeastMovementParams *)movementParameters)->turnSpeed, &v) < TObjEneDolmOlm__behavior_params_by_variant[variant]->special_angle) {
                phase = 3;
                requested_action = 0xC;
                play_sound_effect(remap_sound_for_area(0x4003A804), &position, 0, 0);
                spawn_particle_effect(&position, 0x20E);
            }
        } else {
            requested_action = phase = 2;
        }
        apply_actor_gravity(this, NULL, 0.0f);
        break;
    case 3:
        apply_actor_gravity(this, NULL, 0.0f);
        if (target != 0) {
            Vec v;
            s32 a;
            f32 d;
            DolmOlmBehaviorParams *t;
            VecCopy(&v, &((TObjChara *)target)->body_center);
            subtract_vector(&v, &body_center);
            a = angle_difference_abs(rotation_y, (s32)(dolmolm_radians_to_angle[0] * atan2_float(v.x, v.z)));
            d = horizontal_distance_squared(&((TObjChara *)target)->position, &position);
            t = TObjEneDolmOlm__behavior_params_by_variant[variant];
            if (a < t->special_angle && d < t->special_range * t->special_range) {
                u16 id = ((TObjBase *)target)->get_entity_id();
                if (((TObjCollidable *)target)->test_actor_flags(0x4000000) == 0) {
                    TObjPlayer *pl = get_player_by_client_id(id);
                    if (pl != 0 && TObjPlayer::is_locally_controlled(pl) != 0 &&
                        pl->all_parents_unqueued_for_destruction() != 0 &&
                        pl->test_actor_flags(0x800) == 0 && pl->check_player_flag1() == 0) {
                        TObjPlayer::play_effect(pl, (s32)(30.0f * (f32)TObjEneDolmOlm__behavior_params_by_variant[variant]->special_power), 2);
                    }
                }
            }
        }
        if (is_passing_frame((f32)(frame_count - 1.0f - play_speed)) != 0) {
            requested_action = phase = 2;
        }
        break;
    case 2:
        apply_actor_gravity(this, NULL, 0.0f);
        actorFlags &= ~0x200000;
        mode = 3;
        phase = 1;
        requested_action = 2;
        clear_actor_flags(0x4040000);
        clear_player_status_flag(0, 0xA000000);
        break;
    }
    update_collisions();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
#pragma pop
void TObjEneDolmOlm::run_idle_action() {

    switch (this->mode) {
    case 1:
        if ((s32) this->appearing != 0) {
            this->mode = 0;
            this->phase = 0;
        }
        break;
    case 10:
        break;
    case 0:
        switch ((s16) this->phase) {
        case 2:
            if ((s32) this->appearing != 0) {
                this->phase = 0;
            }
            break;
        }
        break;
    default:
        if ((s32) this->appearing != 0) {
            this->mode = 0;
        } else {
            this->mode = 1;
        }
        this->phase = 0;
        request_stand_action();
        set_actor_flags(0x04040000);
        set_indexed_flags(0, 0x0A000000);
        break;
    }
}
void TObjEneDolmOlm::run_move_action() {
    if (test_actor_flags(0x1000U) != 0) {
        mode = 4;
    }
    switch (mode) {
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 0xA;
        }
        clear_actor_flags(0x04040000U);
        clear_player_status_flag(0, 0x0A000000U);
        return;
    case 4:
        requested_action = 5;
        return;
    default:
        mode = 3;
        phase = 1;
        requested_action = 2;
        clear_actor_flags(0x04040000U);
        clear_player_status_flag(0, 0x0A000000U);
        return;
    case 2:
    case 3:
    case 10:
        return;
    }
}
void TObjEneDolmOlm::run_attack_action() {
    f32 dist_sq;
    f32 height_diff;
    u16 id;
    s32 start_special;
    TObjPlayer *player;
    TObjBase *enemy;
    switch (mode) {
    case 0:
    case 2:
    case 10:
    case 11:
        break;
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 0xA;
        }
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    default:
        id = targetId;
        start_special = 0;
        height_diff = 20.0f;
        if (id < 0x1000U) {
            player = get_player_by_client_id(id);
            if (player != NULL) {
                dist_sq = horizontal_distance_squared(&player->position, &position);
                height_diff = fabs_float(player->position.y - position.y);
                if (player->get_floor() == get_current_floor()) {
                    if (dist_sq < TObjEneDolmOlm__behavior_params_by_variant[variant]->special_range * TObjEneDolmOlm__behavior_params_by_variant[variant]->special_range &&
                        random_ratio() < special_attack_chance) {
                        start_special = 1;
                    }
                }
            }
        } else if (id < 0x4000U) {
            enemy = (TObjBase *)get_enemy_entity(id);
            if (enemy != NULL) {
                height_diff = fabs_float(enemy->position.y - position.y);
            }
        }
        if (start_special == 1) {
            mode = 0xB;
            phase = 0;
            set_actor_flags(0x200000);
            clear_actor_flags(0x04040000);
            clear_player_status_flag(0, 0x0A000000);
            return;
        }
        if (height_diff < 20.0f) {
            mode = 5;
            phase = 1;
            if (0.5f < random_ratio()) {
                requested_action = 3;
            } else {
                requested_action = 4;
            }
            set_actor_flags(0x200000);
            clear_actor_flags(0x04040000);
            clear_player_status_flag(0, 0x0A000000);
        }
        break;
    }
}
void TObjEneDolmOlm::advance_position() {
    VecCopy(&body_center, &position);
    body_center.y += 20.0f;
}
void TObjEneDolmOlm::request_stand_action() { this->requested_action = 1; }
#pragma push
#pragma fp_contract on
s32 TObjEneDolmOlm::check_path_ahead(s32 angle, f32 speed) {
    Vec stack;
    stack.y = 0.0f;
    stack.x = 0.0f;
    stack.z = (2.0f * speed) + bodies->radius;
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, angle);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrices(1);
    vec3_add_to(&stack, &body_center);
    return check_path_obstructed(this, &stack);
}
#pragma pop
void TObjEneDolmOlm::apply_variant() {
    if (variant < 1) {
        subtype = 0;
        variant = 0;
        set_param(0x40);
    } else {
        subtype = 2;
        variant = 1;
        set_param(0x41);
    }
    load_params_from_table(variant);
    set_motion_packed_rotation();
    TObjEneDolmOlm__left_attack_samples->sample_two_nodes(TObjEneDolmOlm__resource_bundle->models[variant].model, (NJS_MOTION *)TObjEneDolmOlm__resource_bundle->motions[TObjEneDolmOlm__param_table[3].motion].motion, 0x1C, 0x1D);
    TObjEneDolmOlm__right_attack_samples->sample_two_nodes(TObjEneDolmOlm__resource_bundle->models[variant].model, (NJS_MOTION *)TObjEneDolmOlm__resource_bundle->motions[TObjEneDolmOlm__param_table[4].motion].motion, 0x14, 0x15);
    clear_motion_packed_rotation();
    retreat_chance = 0.3f + parameters[2];
    special_attack_chance = 0.3f + parameters[3];
}
void TObjEneDolmOlm::update_attack_trail() {
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    TAttackTraceStrip *eff;
    if (!(this->frame < 12.0f)) {
        return;
    }
    switch (this->requested_action) {
    case 3:
        e = TObjEneDolmOlm__left_attack_samples->lookup(frame);
        idx = 0;
        break;
    case 4:
        e = TObjEneDolmOlm__right_attack_samples->lookup(frame);
        idx = 1;
        break;
    default:
        e = 0;
        break;
    }
    if (e == 0) {
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, this->rotation_y);
    matrix_mult_vec_array(NULL, e, &a, 2);
    pop_matrix();
    eff = attack_traces[idx];
    if (eff != NULL) {
        eff->add_segment(&a, &b);
    }
}
void TObjEneDolmOlm::spawn_death_effect() {
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * this->stat_block->proportions;
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrix();
    vec3_add_to(&stack, &position);
    spawn_ground_effect(&stack, 0x23);
    TObjPlayer__sub_800D92BC(&stack, 0xF);
}
void TObjEneDolmOlm::play_alert_sound() {
    play_sound_effect(remap_sound_for_area(0x4003AD00), &position, 0, 0);
}
void TObjEneDolmOlm::play_attack_sound() {
    play_sound_effect(remap_sound_for_area(0x4003B203), &position, 0, 0);
}
void TObjEneDolmOlm::play_hurt_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A802), &position, 0, 0);
}
void TObjEneDolmOlm::play_death_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A801), &position, 0, 0);
}
void TObjEneDolmOlm::init_body_sub() {
    spawn_ground_effects(&position);
}
void TObjEneDolmOlm::spawn_ground_effects(Vec *pos) {
    Vec v;
    CsnHit *hit;
    TParticleCtrl *e;
    VecCopy(&v, pos);
    v.y += 15.0f;
    hit = csnVectorUnder(&v, ground_candidates.groups, 0x4007);
    if (hit != NULL) {
        if (hit->hit_mask & 4) {
            if (actor_frame_tick % 5 == 0) {
                play_ground_landing_sound(&position);
            }
            e = spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (e != NULL) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
        } else if (hit->hit_mask & 2) {
            if (actor_frame_tick % 10 == 0) {
                play_ground_landing_sound(&position);
            }
            e = spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (e != NULL) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[3].point, 0xA4);
        }
        floor_flags = hit->contact->flags;
        if (floor_flags & 0x4000) {
            VecCopy(&floor_point, &hit->contact->point);
        } else {
            VecCopy(&floor_point, &position);
        }
    }
}
void TObjEneDolmOlm::run_demo_task() {  }
s32 TObjEneDolmOlm__sub_80300CF0(void) {
    return 0x7FFFFFFF;
}
void TObjEneDolmOlm::reset_count() { lbl_805D69E8 = 0; }

__declspec(section ".rodata") const f64 dolmolm_radians_to_angle[] = {10430.38043493439};
const char *obj_ene_dolm_olm_class_name = TObjEneDolmOlm__class_name_string;


player_stats **dolm_olm_combat_stat_id_pair;
AttackParams **TObjEneDolmOlm__shared_handler_ids;
ActorParamBlock **TObjEneDolmOlm__registered_object_ids;
DolmOlmBehaviorParams **TObjEneDolmOlm__behavior_params_by_variant;
BmlResource *TObjEneDolmOlm__resource_bundle;
SampledMotionPoints *TObjEneDolmOlm__left_attack_samples;
SampledMotionPoints *TObjEneDolmOlm__right_attack_samples;
s32 TObjEneDolmOlm__effect_render_state;
