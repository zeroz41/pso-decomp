#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyPlacement.h"
#include <stddef.h>
#include "types.h"
#include "dolphin/mtx.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/EnemyTargetCandidate.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/model_render_state.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/gibon/TObjEneBm5GibonU.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/gyaranzo/TObjEneGyaranzo.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/vector.h"
#include "pso/object/TUnk_8049442C.h"
#include "pso/object/TObjChip.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"

LAYOUT_ASSERT(GyaranzoPositionOffset, offsetof(TObjEneGyaranzo, position) == 0x38);

LAYOUT_ASSERT(GyaranzoYawOffset, offsetof(TObjEneGyaranzo, rotation_y) == 0x60);

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

NJS_OBJECT *gyaranzo_model_resources[0x16];

NJS_OBJECT *gyaranzo_resource_ptrs[13];

EnemyTargetCandidate TObjGyaranzoMissile_target_slots[4];


const char *bm_ene_gyaranzo_model_names[8] = {
    "me4_y_hahen01.nj", "me4_y_hahen02.nj", "me4_y_hahen03.nj", "me4_y_me4.nj",
    "me4_y_me4p.nj", "me4_y_mine.nj", "me4_y_missile.nj", NULL,
};

const char *bm_ene_gyaranzo_motion_names[9] = {
    "attack_me4_y_me4.njm", "damage01_me4_y_me4.njm", "damage02_me4_y_me4.njm", "deth_me4_y_me4.njm",
    "wait_me4_y_me4.njm", "walk01_me4_y_me4.njm", "walk02_me4_y_me4.njm", "walk03_me4_y_me4.njm",
    NULL,
};

BmlResourceDescriptor bm_ene_gyaranzo_resource_descriptor = {
    "bm_ene_gyaranzo.bml", bm_ene_gyaranzo_model_names, bm_ene_gyaranzo_motion_names, 7, 8,
};

const char *TObjEneGyaranzo__class_name = "TObjEneGyaranzo";

TObjMotionAction gyaranzo_action_table[8] = {
    {2, 0, 4, 0.7f, 0},
    {2, 5, 5, 0.7f, 1},
    {2, 0, 0, 1.0f, 4},
    {2, 0, 2, 0.8f, 8},
    {3, 4, 3, 1.0f, 0x10},
    {1, 5, 6, 0.7f, 1},
    {2, 0, 7, 0.8f, 1},
    {2, 0, 1, 1.0f, 8},
};

// What movementParameters points at: EnemyMoveParams and four more words (as on the GiGue).
struct GyaranzoMoveParams {
    EnemyMoveParams move;
    s32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

GyaranzoMoveParams gyaranzo_move_params = {
    {150.0f, 0.5555555f, 0x400}, 0x1E0000, 0, 1, 0,
};

CollisionBody gyaranzo_collision_bodies[1] = {
    {{0.0f, 18.0f, 0.0f}, 18.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

// Node indices of the me4 model: the first 13 are the parts that break off.
s16 gyaranzo_resource_index_table[22] = {
    6, 7, 10, 11, 12, 15, 14, 9, 8, 0x25, 0x21,
    0x36, 0x2C, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
};

// The order in which the parts break off (break_off_parts, hide_broken_parts).
s16 gyaranzo_flagged_resource_index_table[14] = {
    2, 3, 4, 11, 12, 0, 1, 5, 6, 7, 8, 9, 10, 0,
};

BreakUpParamRow gyaranzo_death_breakup_params = {
    0x14, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f,
};

player_stats *gyaranzo_boss_stats_handle;

AttackParams *gyaranzo_boss_stats_ptr_b;

ActorParamBlock *gyaranzo_object_handle;

GyaranzoParameters *gyaranzo_missile_param_table;

// Missile float parameter 2 (init_params_from_table); nothing reads it.
f32 TObjGyaranzoMissile__float_param2;

f32 TObjGyaranzoMissile__speed_scale;

f32 TObjGyaranzoMissile__max_range;

BmlResource *gyaranzo_bml_resource;

// Nodes 25 and 13 of model 3; hide_broken_parts hides them.
NJS_OBJECT *gyaranzo_broken_node25;

NJS_OBJECT *gyaranzo_broken_node13;

TBreakUpMdlData *gyaranzo_breakup_model_obj;

s32 gyaranzo_missile_volley_end_time;

TObjEneGyaranzo::TObjEneGyaranzo(TObject *parent, EnemyPlacement *set_data) : TObjEnemyCustom(parent) {
    s32 i;

    m_name = TObjEneGyaranzo__class_name;
    apply_set_data(set_data);
    VecCopy(&move_origin, VecCopy(&move_destination, &position));
    motion_list = gyaranzo_bml_resource->motions;
    action_table = gyaranzo_action_table;
    set_action_table(action_table);
    init_collision_body_parts(this, gyaranzo_collision_bodies, 1);
    variant = 0;
    movementParameters = &gyaranzo_move_params;
    bind_enemy_combat_stats(gyaranzo_boss_stats_handle, gyaranzo_boss_stats_ptr_b, gyaranzo_object_handle);
    init_params_from_table();
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    low_hp_threshold = hp / 3;
    broken_part_count = 0;
    break_stage = 0;
    pad_3AC = 0;
    mine_chase_count = 0;
    fragment_cooldown = 0;
    set_param(0x19);
    add_flags_2e4(4);
    update_prev_position();
    initialize_enemy_photon_effect(this);
    actorFlags |= 0x40000;
    model = gyaranzo_bml_resource->models[3].model;
    texlist = gyaranzo_bml_resource->models[3].texlist;
    if (set_data->wave != 0) {
        start_appear();
    }
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneGyaranzo::~TObjEneGyaranzo() {
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_propagation off
void TLobby::load_gyaranzo_resources() {
    s32 i;
    void *p;

    if (TObjEneDD::check_v2_mode() != 0) {
        gyaranzo_bml_resource = load_enemy_bml_resource_named(&bm_ene_gyaranzo_resource_descriptor, "bm_ene_gyaranzo_a.bml");
    } else {
        p = new BmlResource(5, &bm_ene_gyaranzo_resource_descriptor, 0, 0, NULL);
        gyaranzo_bml_resource = (BmlResource *)p;
    }
    for (i = 0; i < 0x16; i++) {
        gyaranzo_model_resources[i] = find_model_node(gyaranzo_bml_resource->models[3].model, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        gyaranzo_resource_ptrs[i] = find_model_node(gyaranzo_bml_resource->models[4].model, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        gyaranzo_resource_ptrs[i]->sibling = NULL;
    }
    gyaranzo_broken_node25 = find_model_node(gyaranzo_bml_resource->models[3].model, 0x19);
    gyaranzo_broken_node13 = find_model_node(gyaranzo_bml_resource->models[3].model, 0xD);
    p = new TBreakUpMdlData(gyaranzo_bml_resource->models[3].model, (NJS_MOTION *)get_bml_motion(gyaranzo_bml_resource, 3), 54.0f);
    gyaranzo_breakup_model_obj = (TBreakUpMdlData *)p;
    gyaranzo_boss_stats_handle = TLobby::register_boss(0x1D);
    gyaranzo_boss_stats_ptr_b = TLobby::dispatch_shared_handler_b(0x1D);
    gyaranzo_object_handle = TLobby::register_object(0x1D);
    gyaranzo_missile_param_table = (GyaranzoParameters *)TLobby::dispatch_shared_handler_a(0x1D);
    {
        NpcAnimationBinding pos = { NULL, gyaranzo_action_table, 0, 1, 8 };
        pos.motions = gyaranzo_bml_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x20, gyaranzo_bml_resource->models[3].model, gyaranzo_bml_resource->models[3].texlist, &pos, 18.0f, 0.0f);
        TObjNpcEnemy::register_animated_chunk(0x21, gyaranzo_bml_resource->models[4].model, gyaranzo_bml_resource->models[3].texlist, &pos, 18.0f, 0.0f);
    }
}
#pragma pop

void TObjEneGyaranzo::free_static_instances() {
    if (gyaranzo_bml_resource != NULL) {
        delete gyaranzo_bml_resource;
        gyaranzo_bml_resource = NULL;
    }
    if (gyaranzo_breakup_model_obj != NULL) {
        delete gyaranzo_breakup_model_obj;
        gyaranzo_breakup_model_obj = NULL;
    }
}

void *TObjEneGyaranzo::create(void *set) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneGyaranzo(control, static_cast<EnemyPlacement *>(set));
}

void TObjEneGyaranzo::run_task() {
    s32 cooldown;

    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    sub_800D37F4();
    cooldown = fragment_cooldown;
    if (cooldown >= 0) {
        fragment_cooldown = cooldown - 1;
    }
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            dispatch_state_update();
        }
        mode = next_action;
        state = 0;
    }
    dispatch_state_update();
    update_prev_position();
    copy_position();
    submit_cursor_candidate(this, -1);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneGyaranzo::dispatch_state_update() {
    switch (mode) {
    case 0:
        update_state();
        return;
    case 1:
        update_chase_target();
        return;
    case 2:
        update_aim_and_fire();
        return;
    case 4:
        update_damaged();
        return;
    case 5:
        update_death_breakup();
        return;
    case 7:
        update_fade_in();
        return;
    case 9:
        update_chase_target();
        return;
    case 8:
        update_walk_to_target();
        break;
    }
}

void TObjEneGyaranzo::sub_800D37F4() {
    s32 next;
    u16 found;
    switch (mode) {
    case 0:
    case 8:
        if (is_actor_cadence_frame(0x1E) != 0) {
            select_targets();
            if (target_count > 0) {
                switch (break_stage) {
                case 0:
                    if (hp <= low_hp_threshold) {
                        targetId = target_ids[3];
                        next = 9;
                    } else {
                        targetId = target_ids[1];
                        next = 1;
                    }
                    if (targetId != 0xFFFF) {
                        update_if_active(next);
                        resume_action = 2;
                    }
                    break;
                case 1:
                    targetId = target_ids[1];
                    if (targetId != 0xFFFF) {
                        update_if_active(9);
                        resume_action = 2;
                    }
                    break;
                case 2:
                    targetId = target_ids[0];
                    if (targetId != 0xFFFF) {
                        update_if_active(9);
                        resume_action = 2;
                    }
                    break;
                }
            } else if (is_actor_cadence_frame(0x1E) != 0 &&
                       xz_distance_squared(&position, &home_position) > 100.0f) {
                update_if_active(8);
            }
        }
        break;
    case 1:
        if (is_actor_cadence_frame(0x1E) != 0) {
            found = find_nearest_visible_player(this, NULL, 50.0f + ((EnemyMoveParams *)movementParameters)->max_distance);
            if (targetId == 0xFFFF) {
                targetId = found;
            }
            if (targetId == 0xFFFF) {
                update_if_active(8);
            }
        }
        break;
    }
}

#pragma push
void TObjEneGyaranzo::render() {
    s32 detail;
    RenderFadeState *fade;
    s32 draw_shadow;
    if (!(actorFlags & 0x02000000)) {
        saddr camera = 0;
        if (is_split_screen() != 0) {
            camera = TCameraCtrl::get_camera_mode();
        }
        draw_shadow = 1;
        detail = classify_actor_view_detail(200.0f, 400.0f, 40.0f);
        if (detail != 0) {
            saved_model_render_flags = model_render_flags;
            fade = &camera_fades[camera];
            fade->update_fast();
            if (fade->updateFromCamera(&body_center.x) != 0) {
                fade->set_flags_and_apply_damage_color();
                if (defer_render() != 0) {
                    model_render_flags = saved_model_render_flags;
                    return;
                }
            }
            hide_broken_parts();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object(model);
            } else if (behavior_flags & 4) {
                if (appear_fade.has_visible_opacity() != 0) {
                    appear_fade.set_flags_and_apply_damage_color();
                    if (detail == 1) {
                        draw();
                    } else {
                        draw_motion_model();
                    }
                    appear_fade.clear_flag_and_notify();
                } else {
                    draw_shadow = 0;
                }
            } else if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(actorFlags & 0x800) && (draw_shadow != 0)) {
                Vec shadow_scale = {3.0f, 3.0f, 3.0f};
                TObjEnemy::draw_ground_shadow(&shadow_scale, 0);
            }
            fade->clear_flag_and_notify();
        }
    }
}
#pragma pop

void TObjEneGyaranzo::run_demo_task() {  }

void TObjEneGyaranzo::update_chase_target() {
    Vec node;
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    switch ((s32)state) {
    case 0:
        bodies->flags &= ~0x380000;
        actorFlags &= ~0x100;
        clear_flags_30();
        chase_distance = 0.0f;
        mine_drop_distance = 0.0f;
        requested_action = 1;
        if (mode == 1) {
            chase_distance_limit = get_gyaranzo_missile_float_parameter(0);
        } else {
            chase_distance_limit = 120.0f;
            mine_chase_count++;
        }
        play_sound_effect(remap_sound_for_area(remap_sound_for_area(0x4003B209)), &position, 0, 0);
        if (target != NULL) {
            VecCopy(&move_destination, &target->body_center);
        }
        state = 1;
        break;
    case 1:
        if (target != NULL) {
            VecCopy(&chase_destination, &target->body_center);
            VecCopy(&move_destination, &target->body_center);
        } else {
            run_idle_action();
            return;
        }
        enemy_turn_toward_dest(((EnemyMoveParams *)movementParameters)->turn_speed);
        move_along_ground_avoiding_walls(chase_destination, ((EnemyMoveParams *)movementParameters)->min_distance, bodies->radius);
        chase_distance += ((EnemyMoveParams *)movementParameters)->min_distance;
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        if (mode == 9) {
            mine_drop_distance += ((EnemyMoveParams *)movementParameters)->min_distance;
            if (mine_drop_distance >= 20.0f) {
                mine_drop_distance -= 20.0f;
                spawn_missile();
            }
        }
        if (!(actor_frame_tick & 3)) {
            render_anim_model_at_pos();
            get_anim_node_position(0x1F, &node);
            spawn_particle_effect(&node, 0xF3);
            get_anim_node_position(0x27, &node);
            spawn_particle_effect(&node, 0xF3);
        }
        update_collisions();
        if (bodies->flags & 0x380000) {
            state = -1;
        } else if (chase_distance >= chase_distance_limit) {
            state = -1;
        }
        break;
    case -1:
        update_if_active(resume_action);
        break;
    }
}

void TObjEneGyaranzo::run_hit_reaction() {
    unsigned long low_hp;
    if (mode != 4) {
        if (fragment_cooldown <= 0) {
            fragment_cooldown = 0x3C;
            spawn_hit_fragments();
        }
        low_hp = 0;
        switch (break_stage) {
        case 0:
            low_hp = hp <= hpmax / 3;
            break;
        case 1:
            low_hp = hp <= hpmax / 4;
            break;
        }
        if ((s32)low_hp != 0) {
            break_off_parts();
        }
        referenceHp = hp;
        play_sound_effect(remap_sound_for_area(0x4003AD0F), &position, 0, 0);
        if (!(behavior_flags & 0x40000)) {
            set_state(4);
            behavior_flags |= 1;
            return;
        }
        clear_actor_flags(0x200200);
    }
}

void TObjEneGyaranzo::update_damaged() {
    switch ((s32)state) {
    case 0:
        actorFlags &= ~0x200000;
        requested_action = 3;
        state = 1;
    case 1: {
        advance_animation();
        Vec next = body_center;
        next.x += velocity.x;
        next.z += velocity.z;
        if (check_path_obstructed(this, &next) == 0) {
            move_with_wall_slide(this);
        } else {
            velocity.x = velocity.z = 0.0f;
        }
        velocity.x *= 0.5f;
        velocity.z *= 0.5f;
        apply_actor_gravity(this, NULL, 0.0f);
        update_collisions();
        if (action_flags != 8) {
            state = -1;
        }
        break;
    }
    case -1:
        actorFlags &= ~0x200;
        behavior_flags &= ~1;
        next_action = 1;
        break;
    }
}

void TObjEneGyaranzo::run_death_reaction() {
    set_state(5);
    behavior_flags |= 1;
}

void TObjEneGyaranzo::update_death_breakup() {
    switch ((s32)state) {
    case 0:
        requested_action = 4;
        refresh_lobby_state();
        timer = 0x5A;
        create_dead_spot(&body_center, 0x5A, 20.0f);
        create_dead_spot(&body_center, 0x5A, 20.0f);
        state = 1;
    case 1:
        advance_animation();
        timer--;
        if (timer < 0) {
            TBoss3Volopt::create_breakup_mdl(gyaranzo_breakup_model_obj, &gyaranzo_death_breakup_params,
                               texlist, &body_center, rotation_y);
            send_entity_set_flags();
            trigger_dell_biter_events(&body_center);
            play_sound_effect(remap_sound_for_area(0x4003AD10), &position, 0, 0);
            queue_destruction();
        }
        break;
    case -1:
        return;
    }
}

void TObjEneGyaranzo::hide_broken_parts() {
    s32 i;
    for (i = 0; i < broken_part_count; i++) {
        gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]]->evalflags |= NJD_EVAL_HIDE;
    }
    for (; i < 13; i++) {
        gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]]->evalflags &= ~NJD_EVAL_HIDE;
    }
    if (break_stage >= 1) {
        gyaranzo_broken_node25->evalflags |= NJD_EVAL_HIDE;
        gyaranzo_broken_node13->evalflags |= NJD_EVAL_HIDE;
    } else {
        gyaranzo_broken_node25->evalflags &= ~NJD_EVAL_HIDE;
        gyaranzo_broken_node13->evalflags &= ~NJD_EVAL_HIDE;
    }
}

void TObjEneGyaranzo::update_aim_and_fire() {
    s32 turn;
    s32 aimed;
    switch ((s32)state) {
    case 0:
        behavior_flags |= 0x40000;
        requested_action = 0;
        state = 1;
    case 1:
        aimed = 0;
        if (is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range(300.0f);
        }
        if (target != NULL) {
            Vec to_target = target->position;
            subtract_vector(&to_target, &position);
            turn = turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &to_target);
            if (__abs(turn) < 0xE38) {
                aimed = 1;
            }
        } else {
            aimed = 1;
        }
        if (aimed != 0) {
            timer = get_gyaranzo_missile_int_parameter(0);
            requested_action = 2;
            state = 2;
        }
        break;
    case 2:
        if (frame >= 28.0f) {
            spawn_missile_volley();
            state = 3;
        }
        break;
    case 3:
        timer--;
        if (timer <= 0) {
            state = -1;
            update_if_active(0);
        }
        break;
    case -1:
        behavior_flags &= ~0x40000;
        break;
    }
    advance_animation();
    apply_actor_gravity(this, NULL, 0.0f);
    update_collisions();
}

#pragma push
#pragma fp_contract on
void TObjEneGyaranzo::spawn_missile() {
    Vec launch_position;
    s32 spin;
    render_anim_model_at_pos();
    this->get_anim_node_position(0x18, &launch_position);
    spin = (s32) (182.04445f * ((240.0f * random_ratio()) - 120.0f));
    new TUnk_8049442C(this, &launch_position, rotation_y, spin);
    spawn_particle_effect(&launch_position, 0xF3);
    play_sound_effect(this->remap_sound_for_area(0x4003B20D), &position, 0, 0);
}
#pragma pop

// pool_data off: each chip's initializer template is reached with its own lis/addi.
#pragma pool_data off
void TObjEneGyaranzo::spawn_hit_fragments() {
    Vec pos = position;
    pos.y += 25.0f;
    const TObjChipParams first = {
        0.5f, 0.04f, 0.28f, {pos.x, pos.y, pos.z}, {6.0f, 7.0f, 6.0f},
        {0x400, 0x100, 0x400}, 5, 50, position.y, 1.0f,
        gyaranzo_bml_resource->models[0].model, gyaranzo_bml_resource->models[0].texlist, 2,
    };
    const TObjChipParams second = {
        0.5f, 0.04f, 0.2f, {pos.x, pos.y, pos.z}, {5.5f, 6.5f, 5.5f},
        {0x400, 0x100, 0x400}, 4, 50, position.y, 1.0f,
        gyaranzo_bml_resource->models[1].model, gyaranzo_bml_resource->models[1].texlist, 2,
    };
    const TObjChipParams third = {
        0.5f, 0.04f, 0.22f, {pos.x, pos.y, pos.z}, {5.5f, 7.0f, 5.5f},
        {0x400, 0x100, 0x400}, 5, 50, position.y, 1.0f,
        gyaranzo_bml_resource->models[2].model, gyaranzo_bml_resource->models[2].texlist, 2,
    };

    new TObjChip((TObject *)tl_05, &first);
    new TObjChip((TObject *)tl_05, &second);
    new TObjChip((TObject *)tl_05, &third);
}
#pragma pool_data reset

void TObjEneGyaranzo::break_off_parts() {
    s32 start;
    s32 end;
    s32 i;
    s32 part;
    Vec node;
    if (break_stage < 2) {
        break_stage++;
        switch (break_stage) {
        case 1:
            start = 0;
            broken_part_count = 5;
            end = 5;
            break;
        case 2:
            start = 5;
            broken_part_count = 0xD;
            end = 0xD;
            break;
        }
        render_anim_model_at_pos();
        for (i = start; i < end; i++) {
            part = gyaranzo_flagged_resource_index_table[i];
            get_anim_node_position(gyaranzo_resource_index_table[part], &node);
            {
                TObjChipParams p = {
                    0.5f, 0.03f, 0.15f, {0.0f, 0.0f, 0.0f}, {3.5f, 5.0f, 3.5f},
                    {0x400, 0x100, 0x400}, 3, 50, 0.0f, 1.0f, 0, 0, 2,
                };
                p.pos.x = node.x;
                p.pos.y = node.y;
                p.pos.z = node.z;
                p.floor_y = position.y;
                p.model = gyaranzo_resource_ptrs[part];
                p.textures = gyaranzo_bml_resource->models[3].texlist;
                new TObjChip(tl_05, &p);
            }
        }
    }
}

#pragma pool_data off
void TObjEneGyaranzo::spawn_missile_volley() {
    Vec pos;
    s32 i;
    gyaranzo_missile_volley_end_time = get_gyaranzo_missile_int_parameter(1) + 0x96;
    render_anim_model_at_pos();
    {
        GyaranzoMissileLaunch high_left = { &pos, -0x1000, rotation_y + 0x800, 1024.0f, 3.0f, 0.0f };
        GyaranzoMissileLaunch low_left = { &pos, -0x2000, rotation_y + 0x800, 2048.0f, 10.0f, 0.4f };
        GyaranzoMissileLaunch high_right = { &pos, -0x1000, rotation_y - 0x800, 1024.0f, 3.0f, 0.0f };
        GyaranzoMissileLaunch low_right = { &pos, -0x2000, rotation_y - 0x800, 2048.0f, 10.0f, 0.4f };
        u16 ids[4] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
        s32 order[4] = { 0, 3, 1, 2 };
        for (i = 0; i < 4; i++) {
            ids[i] = target_ids[order[i]];
        }
        get_anim_node_position(0x10, &pos);
        new TObjGyaranzoMissile(this, &high_left, ids[0]);
        new TObjGyaranzoMissile(this, &low_left, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        get_anim_node_position(0x14, &pos);
        new TObjGyaranzoMissile(this, &high_right, ids[0]);
        new TObjGyaranzoMissile(this, &low_right, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        if (break_stage >= 1) {
            get_anim_node_position(0x11, &pos);
            new TObjGyaranzoMissile(this, &high_left, ids[0]);
            new TObjGyaranzoMissile(this, &low_left, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            get_anim_node_position(0x15, &pos);
            new TObjGyaranzoMissile(this, &high_right, ids[2]);
            new TObjGyaranzoMissile(this, &low_right, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
        if (break_stage >= 2) {
            get_anim_node_position(0x12, &pos);
            new TObjGyaranzoMissile(this, &high_left, ids[0]);
            new TObjGyaranzoMissile(this, &low_left, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            get_anim_node_position(0x16, &pos);
            new TObjGyaranzoMissile(this, &high_right, ids[2]);
            new TObjGyaranzoMissile(this, &low_right, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            get_anim_node_position(0x13, &pos);
            new TObjGyaranzoMissile(this, &high_left, ids[2]);
            new TObjGyaranzoMissile(this, &low_left, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            get_anim_node_position(0x17, &pos);
            new TObjGyaranzoMissile(this, &high_right, ids[2]);
            new TObjGyaranzoMissile(this, &low_right, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
    }
    play_sound_effect(remap_sound_for_area(0x4003AD0A), &position, 0, 0);
}
#pragma pool_data reset

#pragma push
#pragma scheduling off
void EnemyTargetCandidate::copy_from(const EnemyTargetCandidate *source) {
    id = source->id;
    distance_squared = source->distance_squared;
}
#pragma pop

void TObjEneGyaranzo::select_targets() {
    s32 count;
    s32 n;
    s32 best;
    s32 i;
    TObjChara *p;
    s32 j;
    s32 k;
    f32 dist;
    Vec d;
    TObjGyaranzoMissile_target_slots[0].id = 0xFFFF;
    TObjGyaranzoMissile_target_slots[0].distance_squared = 0.0f;
    n = 0;
    best = 0;
    k = test_actor_flags(0x10);
    count = registered_player_count;
    if (k != 0) {
        count += registered_enemy_count;
    }
    for (i = 0; i < count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)p) == 0) continue;
        if (p == this) continue;
        if (p->actorFlags & 0x2000800) continue;
        VecCopy(&d, &p->body_center);
        subtract_vector(&d, &body_center);
        dist = d.x * d.x + d.z * d.z;
        if (!(dist < 90000.0f)) continue;
        if (check_path_obstructed(this, &p->body_center) == 1) continue;
        TObjGyaranzoMissile_target_slots[n].distance_squared = dist;
        TObjGyaranzoMissile_target_slots[n].id = p->get_entity_id();
        if (n > 0 && TObjGyaranzoMissile_target_slots[n].distance_squared > TObjGyaranzoMissile_target_slots[best].distance_squared) {
            best = n;
        }
        n++;
        if (n >= 4) break;
    }
    {
        EnemyTargetCandidate def = { 0xFFFF, 0.0f };
        switch (n) {
        case 0:
            for (i = 0; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&def);
            }
            break;
        case 2:
            for (i = n; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[i % n]);
            }
            break;
        default:
            for (i = n; i < 4; i++) {
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[best]);
            }
            break;
        }
    }
    target_count = n;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (TObjGyaranzoMissile_target_slots[i].distance_squared > TObjGyaranzoMissile_target_slots[j].distance_squared) {
                EnemyTargetCandidate tmp;
                tmp.copy_from(&TObjGyaranzoMissile_target_slots[i]);
                TObjGyaranzoMissile_target_slots[i].copy_from(&TObjGyaranzoMissile_target_slots[j]);
                TObjGyaranzoMissile_target_slots[j].copy_from(&tmp);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        target_ids[i] = TObjGyaranzoMissile_target_slots[i].id;
    }
}

void TObjEneGyaranzo::update_fade_in() {
    switch ((s32)state) {
    case 0:
        behavior_flags |= 4;
        actorFlags |= 0x04000000;
        requested_action = 0;
        TBoss3Volopt__sub_800D8D88((saddr)&body_center);
        appear_fade.start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        if (appear_fade.advance_toward_max() == 1) {
            state = -1;
        }
        return;
    case -1:
        behavior_flags &= ~5;
        actorFlags &= ~0x04000000;
        update_if_active(0);
        break;
    }
}

void TObjEneGyaranzo::init_params_from_table() {
    ((EnemyMoveParams *)movementParameters)->min_distance = get_gyaranzo_missile_float_parameter(1);
    TObjGyaranzoMissile__float_param2 = get_gyaranzo_missile_float_parameter(2);
    TObjGyaranzoMissile__speed_scale = get_gyaranzo_missile_float_parameter(3);
    TObjGyaranzoMissile__max_range = get_gyaranzo_missile_float_parameter(4);
}

// Mode 8: walk back to home_position, then resume through update_if_active.
void TObjEneGyaranzo::update_walk_to_target() {
    switch ((s32)state) {
    case -1:
        break;
    case 0:
        bodies->flags &= ~0x380000;
        actorFlags &= ~0x100;
        requested_action = 1;
        VecCopy(&move_destination, &home_position);
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, NULL, 0.0f);
        VecCopy(&move_origin, &body_center);
        calc_velocity_toward_destination(this, move_origin, move_destination, ((EnemyMoveParams *)movementParameters)->min_distance);
        turn_toward_direction(((EnemyMoveParams *)movementParameters)->turn_speed, &velocity);
        move_with_wall_slide(this);
        update_collisions();
        if (xz_distance_squared(&position, &home_position) <= 100.0f) {
            update_if_active(0);
        }
        break;
    }
}

s32 TObjEneGyaranzo::update_shock_clock() {
    if (TObjChara::update_shock_clock() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

s32 TObjEneGyaranzo::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

void TObjEneGyaranzo::clear_flag_and_update() {
    if (next_action == 7) {
        behavior_flags &= ~1;
        update_if_active(0);
    }
}
