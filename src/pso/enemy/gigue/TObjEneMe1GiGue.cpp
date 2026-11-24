#include "pso/enemy/EnemyMovement.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/EnemyTargeting.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/AreaSound.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/technique/TTecZarua.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/unk/text_800DC420.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueBarrier.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

s32 get_gigue_int_parameter(TObjEneMe1GiGue *, s32);
f32 get_gigue_float_parameter(TObjEneMe1GiGue *, s32);
player_stats *ene_me1_gigue_boss_id;
AttackParams *gigue_attack_params;
ActorParamBlock *gigue_resistance_params;
GiGueParameters *TObjEneMe1GiGue__param_table;
BmlResource *gigue_resource;
TBreakUpMdlData *gigue_breakup_model;
f32 gigue_missile_speed;
f32 gigue_shot_speed;
f32 gigue_shot_homing;
f32 gigue_shot_homing_step;
s32 gigue_missile_power;
s32 gigue_shot_power;
extern "C" {
s32 create__9TTecJelinFllll(void *, void *, void *, s32);
}

// What movementParameters points at: EnemyMoveParams and four more words.
struct GiGueMoveParams {
    EnemyMoveParams move;
    s32 unk_c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
};

const char *TObjEneMe1GiGue__model_filename_table[4] = {
    "gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *me1_gi_gue_motion_filename_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor gigue_bml_descriptor = {
    "bm_ene_gi_gue.bml", TObjEneMe1GiGue__model_filename_table, me1_gi_gue_motion_filename_table, 3, 9,
};

const char *gigue_low_model_names[4] = {
    "lo_gi_gue_all.nj", "gi_gue_missile.nj", "gi_gue_barrier.nj", NULL,
};

const char *gi_gue_njm_name_table[10] = {
    "damage_gi_gue_all.njm", "fire_gi_gue_all.njm", "missile_gi_gue_all.njm", "move_gi_gue_all.njm",
    "wait_gi_gue_all.njm", "rot_gi_gue_missile.njm", "exp_exp_barrier.njm", "on_on_barrier.njm",
    "redu_redu_barrier.njm", NULL,
};

BmlResourceDescriptor gigue_low_bml_descriptor = {
    "bm_ene_gi_gue_low.bml", gigue_low_model_names, gi_gue_njm_name_table, 3, 9,
};

TObjMotionAction gigue_enemy_param_table[9] = {
    {2, 0, 4, 0.7f, 0},
    {1, 1, 3, 0.7f, 1},
    {2, 0, 2, 0.6f, 4},
    {2, 7, 1, 0.6f, 4},
    {2, 0, 0, 0.5f, 8},
    {2, 7, 0, 0.5f, 8},
    {2, 7, 3, 0.7f, 1},
    {1, 7, 3, 0.7f, 1},
    {2, 0, 3, 0.7f, 1},
};

GiGueMoveParams gigue_move_params = {
    {150.0f, 0.46296296f, 0x300}, 0x1E0000, 0, 1, 0,
};

CollisionBody gigue_collision_bodies[2] = {
    {{0.0f, 15.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 12.0f, 0.0f, 0, 0xA000002, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TObjEneMe1GiGue__name = "TObjEneMe1GiGue";

void TObjEneMe1GiGue::load_params_from_table(s32 i) {
    model = (void *)gigue_resource->models[i].model;
    texlist = gigue_resource->models[i].texlist;
}

void TObjEneMe1GiGue::update_attack() {  }

f32 get_gigue_float_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->floats[i];
}

s32 get_gigue_int_parameter(TObjEneMe1GiGue *self, s32 i) {
    return TObjEneMe1GiGue__param_table->ints[i];
}


void TObjEneMe1GiGue::run_miss_reaction() {  }

void TObjEneMe1GiGue::run_move_action() {  }

void TObjEneMe1GiGue::run_attack_action() {  }

void TObjEneMe1GiGue::run_idle_action() {  }

TObjEneMe1GiGue::TObjEneMe1GiGue(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TObjEneMe1GiGue__name;
    apply_set_data(set_data);
    VecCopy(&move_origin, VecCopy(&move_destination, &position));
    motion_list = gigue_resource->motions;
    variant = 0;
    add_flags_2e4(0x11);
    state36C = *(s16 *)((s8 *)set_data + 0x3E);
    load_params_from_table(variant);
    action_table = gigue_enemy_param_table;
    set_action_table(action_table);
    init_collision_body_parts(this, gigue_collision_bodies, 2);
    bodies[1].flags &= ~1;
    movementParameters = &gigue_move_params;
    bind_enemy_combat_stats(ene_me1_gigue_boss_id, gigue_attack_params, gigue_resistance_params);
    update_direction();
    load_params();
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    m_38c = 0;
    scale.x = 1.0f;
    moveSpeed = ((EnemyMoveParams *)movementParameters)->min_distance * scale.x;
    VecCopy(&home_position, &position);
    VecCopy(&moveDestination, &position);
    barrierChance = 0.5f + parameters[3];
    techniqueChance = 0.5f + parameters[4];
    entryHeight = 150.0f + parameters[2];
    if (entryHeight < 0.0f) {
        entryHeight = 0.0f;
    }
    if ((s32)parameters[0] >= 1) {
        behavior_flags |= 0x40000;
        if (parameters[1] < 1.0f) {
            parameters[1] = 50.0f;
        }
        set_flags_30();
    }
    cameraShakeCooldown = 0;
    approachCount = 0;
    set_param(0x37);
    sinkingOffset = 0.0f;
    volleyCount = 0;
    if (behavior_flags & 0x40000) {
        init_move();
    } else {
        start_appear();
    }
    project_actor_to_ground(this, &position, 0);
    flightHeight = 0.0f;
    cameraFade.activate_and_dispatch();
    set_actor_flags(0x01000000);
    VecCopy(&prev_position, &position);
    clear_lobby_object_state();
}

TObjEneMe1GiGue::~TObjEneMe1GiGue() {
    free_collision_body_parts(this);
}

void TObjEneMe1GiGue::load_resources() {
    void *o;

    if (is_split_screen() != 0) {
        o = new BmlResource(1, &gigue_low_bml_descriptor, 0, 0, NULL);
        gigue_resource = (BmlResource *)o;
    } else {
        o = new BmlResource(1, &gigue_bml_descriptor, 0, 0, NULL);
        gigue_resource = (BmlResource *)o;
    }
    ene_me1_gigue_boss_id = TLobby::register_boss(0x1A);
    gigue_attack_params = TLobby::dispatch_shared_handler_b(0x1A);
    gigue_resistance_params = TLobby::register_object(0x1A);
    TObjEneMe1GiGue__param_table = (GiGueParameters *)TLobby::dispatch_shared_handler_a(0x1A);
    o = new TBreakUpMdlData(gigue_resource->models->model);
    gigue_breakup_model = (TBreakUpMdlData *)o;
    TObjEneMe1GiGueMissile::init_global();
    TObjEneMe1GiGueBarrier::init_global();
    {
    NpcAnimationBinding binding = { gigue_resource->motions, gigue_enemy_param_table, 0, 1, 9 };
    TObjNpcEnemy::register_animated_chunk(0x41, gigue_resource->models->model, gigue_resource->models->texlist, &binding, gigue_collision_bodies[0].radius, 15.0f);
    }
}

void TObjEneMe1GiGue::delete_barrier() {
    TObjEneMe1GiGueBarrier::free_global();
    TObjEneMe1GiGueMissile::free_global();
    if (gigue_breakup_model != NULL) {
        delete gigue_breakup_model;
        gigue_breakup_model = NULL;
    }
    if (gigue_resource != NULL) {
        delete gigue_resource;
        gigue_resource = NULL;
    }
}

void *TObjEneMe1GiGue::create(void *set_data) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneMe1GiGue(parent, set_data);
}

void TObjEneMe1GiGue::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        load_params();
        run_demo_task();
        return;
    }
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    release_destroyed_target();
    update_proximity_state();
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            dispatch_state();
        }
        mode = next_action;
        state = 0;
    }
    dispatch_state();
    if ((s32)state == -1) {
        state = -1;
        dispatch_state();
        mode = next_action;
        state = 0;
    }
    VecCopy(&body_center, &position);
    body_center.y += 15.0f + flightHeight;
    bodies[0].offset.y = 25.0f + flightHeight;
    if (!(behavior_flags & 0x40000)) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
    if (cameraShakeCooldown > 0) {
        cameraShakeCooldown--;
    }
    bodies[0].flags &= ~6;
    if (flightHeight > 5.0f) {
        bodies[0].flags |= 4;
    } else {
        bodies[0].flags |= 2;
    }
    cameraFade.update();
    if (xz_distance_squared(&position, &prev_position) > 2500.0f) {
        VecCopy(&position, &prev_position);
    }
    VecCopy(&prev_position, &position);
}

void TObjEneMe1GiGue::dispatch_state() {
    switch (mode) {
    case 0:
        update_idle_state();
        return;
    case 1:
        update_circling_state();
        return;
    case 2:
        update_attack();
        return;
    case 3:
        update_state_machine();
        return;
    case 4:
        update_hit_reaction();
        return;
    case 5:
        break_apart();
        return;
    case 9:
        update_multi_shot_state();
        return;
    case 10:
        update_missile_state();
        return;
    case 11:
        update_technique_state();
        return;
    case 12:
        action();
        return;
    case 13:
        update_rush_attack();
        return;
    case 7:
        init();
        return;
    case 14:
        update_landing_state();
        break;
    }
}

void TObjEneMe1GiGue::render() {
    s32 vis;
    s32 ok;

    if (actorFlags & 0x2000000) {
        return;
    }
    if (get_current_floor_area() == AREA_TOWER) {
        vis = classify_actor_view_detail(600.0f, 600.0f, 20.0f);
    } else {
        vis = classify_actor_view_detail(150.0f, 400.0f, 20.0f);
    }
    if (vis == 0) {
        return;
    }
    if (TObjPlayer::check_demo_mode() != 1 && (behavior_flags & 0x40000)) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    if (cameraFade.updateFromCamera(&body_center.x) != 0) {
        cameraFade.set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            model_render_flags = saved_model_render_flags;
            return;
        }
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    select_actor_lighting(this);
    TObjPlayer::toggle_particle_effect();
    ok = 1;
    push_matrix();
    translate_matrix(0, position.x, flightHeight + (position.y + sinkingOffset), position.z);
    rotate_matrix_y(NULL, rotation_y);
    model_render_flags &= ~0x400;
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else if (behavior_flags & 4) {
        if (appearFade.has_visible_opacity() != 0) {
            appearFade.set_flags_and_apply_damage_color();
            if (vis == 1) {
                set_motion_packed_rotation();
                draw();
                clear_motion_packed_rotation();
            } else {
                set_motion_packed_rotation();
                draw_motion_model();
                clear_motion_packed_rotation();
            }
            appearFade.clear_flag_and_notify();
        } else {
            ok = 0;
        }
    } else {
        if (vis == 1) {
            set_motion_packed_rotation();
            draw();
            clear_motion_packed_rotation();
        } else {
            set_motion_packed_rotation();
            draw_motion_model();
            clear_motion_packed_rotation();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    TParticleCtrl::end_effect_render();
    if (!(actorFlags & 0x800) && ok != 0) {
        Vec v;
        v.x = v.y = v.z = (1.0f - 0.01f * flightHeight) * (5.0f * scale.x);
        draw_ground_shadow(&v, 0);
    }
    cameraFade.clear_flag_and_notify();
    model_render_flags = saved_model_render_flags;
}

void TObjEneMe1GiGue::run_demo_task() {  }

void TObjEneMe1GiGue::update_idle_state() {
    if (behavior_flags & 0x40000) {
        return;
    }
    switch (state) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        state = 1;
        state_timer = 150;
        clear_flags_30();
    case 1:
        advance_animation();
        move_around_center(&home_position, parameters[1]);
        state_timer -= 1;
        if (state_timer <= 0) {
            requested_action = 0;
            state = 2;
            state_timer = 90;
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation();
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        state_timer -= 1;
        if (state_timer <= 0) {
            state = 0;
        }
        break;
    }
}

void TObjEneMe1GiGue::run_hit_reaction() {
    switch (mode) {
    case 10:
    case 11:
    case 13:
        referenceHp = hp;
        actorFlags &= ~0x200;
        return;
    }
    set_state(4);
    previous_action = resume_action;
    resume_action = 4;
    behavior_flags |= 0x10000 | 1;
}

void TObjEneMe1GiGue::run_death_reaction() {
    set_state(5);
    previous_action = resume_action;
    resume_action = 5;
    behavior_flags |= 1;
}

void TObjEneMe1GiGue::update_circling_state() {
    actorFlags &= ~0x01000000;
    switch (state) {
    case 0:
        behavior_flags &= ~0x00040000;
        clear_flags_30();
        requested_action = 1;
        circlingAngle = 0;
        if (target != NULL) {
            VecCopy(&move_destination, &((TObjChara *)target)->body_center);
        }
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        if (target != NULL) {
            Vec d = ((TObjBase *)target)->position;
            subtract_vector(&d, &position);
            if (d.x * d.x + d.z * d.z <= attackRange * attackRange &&
                angle_difference_abs(-(s32)(10430.38043493439 * atan2_float(d.z, d.x)) + 0x4000, rotation_y) < attackAngle / 2) {
                s32 next;
                approachCount++;
                if (approachCount > 2) {
                    approachCount = 0;
                    next = 13;
                } else {
                    volleyCount = 0;
                    next = 9;
                }
                update_if_active(next);
                break;
            }
        }
        rotation_y += ((EnemyMoveParams *)movementParameters)->turn_speed / 2;
        enemy_set_heading_velocity(moveSpeed, this, rotation_y);
        move_with_wall_slide(this);
        circlingAngle += ((EnemyMoveParams *)movementParameters)->turn_speed / 2;
        if (circlingAngle > 0x10000) {
            wanderDistance = 0.0f;
            state = 2;
        }
        break;
    case -1:
        break;
    case 2:
        enemy_wander_home(moveSpeed, 100.0f, 50.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        wanderDistance += moveSpeed;
        if (wanderDistance > 100.0f) {
            if (find_target_in_range(((EnemyMoveParams *)movementParameters)->max_distance) != 0) {
                circlingAngle = 0;
                state = 1;
            } else {
                update_if_active(0);
            }
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        update_enemy_collision_flags();
        break;
    }
}

void TObjEneMe1GiGue::update_missile_state() {
    TParticleCtrl *particle;

    switch (state) {
    case 0:
        clear_flags_30();
        state_timer = attackDuration;
        if (state_timer <= 40) {
            state_timer = 40;
        }
        if (!(actorFlags & 0x01000000)) {
            requested_action = 2;
            goto start;
        }
        update_if_active(13);
        behavior_flags &= ~0x40000;
        break;
    start:
        state = 1;
        advance_animation();
        behavior_flags &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        if (target == NULL) {
            state = 4;
            break;
        }
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                capture_shot_origins();
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(remap_sound_id(0x3A81D)), this, &position, (s32)(0), (s32)(0));
            if (frame >= 20.0f) {
                capture_shot_origins();
                if ((particle = spawn_particle_effect(&missileOrigin, 0x203)) != NULL) {
                    GiGueShotAngles dir = {0x4000, 0, 0};
                    particle->set_direction(&dir);
                }
                TObjEneMe1GiGueMissile::create(this, &missileOrigin, &((TObjChara *)target)->body_center, gigue_missile_speed, (f32)gigue_missile_power);
                play_sound_effect(remap_sound_id(0x3A31E), &position, 0, 0);
                state = 3;
            }
            break;
        }
        VecCopy(&move_destination, &((TObjChara *)target)->body_center);
        enemy_turn_half_toward_dest(this);
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            apply_actor_gravity(this, 0, 0.0f);
        }
        update_collisions();
        if (--state_timer <= 0) {
            state = 4;
        }
        break;
    case 4:
        if (actorFlags & 0x01000000) {
            resume_action = 0;
            update_if_active(13);
        } else if (!(behavior_flags & 0x80000) && random_ratio() <= barrierChance) {
            update_if_active(12);
        } else {
            update_if_active(0);
        }
        break;
    case -1:
        break;
    }
}

void TObjEneMe1GiGue::update_multi_shot_state() {
    s32 n;
    s32 count;

    switch (state) {
    case -1:
        break;
    case 0:
        clear_flags_30();
        count = 0;
        if (!(actorFlags & 0x01000000)) {
            count = collect_shot_targets();
        }
        if (count > 0) {
            requested_action = 3;
            state_timer = attackDuration;
            if (state_timer <= 20) {
                state_timer = 20;
            }
            state = 1;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
        } else if (!(behavior_flags & 0x80000) && random_ratio() <= barrierChance) {
            update_if_active(12);
        } else {
            update_if_active(0);
        }
        behavior_flags &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                capture_shot_origins();
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound((s32)(remap_sound_id(0x3A820)), this, &position, (s32)(0), (s32)(0));
            if (frame >= 10.0f) {
                capture_shot_origins();
                n = targetCount;
                spawn_targeted_shot((s32)((f32)n * random_ratio()) % n);
                state = 3;
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        state_timer--;
        if (state_timer <= 0) {
            volleyCount++;
            if (volleyCount >= 3) {
                state_timer = 45;
                requested_action = 1;
                state = 4;
            } else {
                state = 0;
                frame = 0.0f;
            }
        }
        break;
    case 4:
        enemy_wander_home(moveSpeed, 100.0f, 100.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        state_timer--;
        if (state_timer <= 0) {
            if (!(behavior_flags & 0x80000) && random_ratio() <= barrierChance) {
                update_if_active(12);
            } else {
                update_if_active(0);
            }
        }
        break;
    }
}

void TObjEneMe1GiGue::update_technique_state() {
    s32 count;
    switch (state) {
    case -1:
        break;
    case 0:
        clear_flags_30();
        count = 0;
        if (!(actorFlags & 0x01000000)) {
            count = collect_shot_targets();
        }
        if (count > 0) {
            state = 1;
            requested_action = 3;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
        } else {
            update_if_active(0);
        }
        behavior_flags &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                capture_shot_origins();
                spawn_particle_effect(&shotOrigin, 0x204);
                state = 2;
            }
            break;
        case 2:
            play_sound_effect(remap_sound_id(0x3A344), &position, 0, 0);
            if (frame >= 10.0f) {
                capture_shot_origins();
                state = 3;
                TTecZarua::create_instance((saddr)this, &body_center, &body_center, get_gigue_int_parameter(this, 2));
                create__9TTecJelinFllll(this, &body_center, &body_center, get_gigue_int_parameter(this, 2));
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        if (requested_action != 3) {
            update_if_active(13);
        }
        break;
    }
}

void TObjEneMe1GiGue::action() {
    switch (state) {
    case 0:
        clear_flags_30();
        behavior_flags &= ~0x40000;
        requested_action = 1;
        state = 1;
        return;
    case 1:
        TObjEneMe1GiGueBarrier::create(this, this);
        state = 2;
        state_timer = 45;
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        return;
    case 2:
        enemy_wander_home(moveSpeed, 100.0f, 100.0f, ((EnemyMoveParams *)movementParameters)->turn_speed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        state_timer = state_timer - 1;
        if (state_timer <= 0) {
            update_if_active(0);
        }
    case -1:
        return;
    }
}

void TObjEneMe1GiGue::update_rush_attack() {
    switch (this->state) {
    case 0:
        this->actorFlags |= 0x800000;
        this->actorFlags &= ~0x1000000;
        this->requested_action = this->state = 1;
        this->flightHeight = 0.0f;
        this->rushDelay = 60;
        this->clear_flags_30();
        break;
    case 1:
        this->actorFlags &= ~0x1000000;
        this->enemy_wander_home(this->moveSpeed, 100.0f, 50.0f, ((EnemyMoveParams *)this->movementParameters)->turn_speed);
        this->advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        this->rushDelay--;
        if (this->rushDelay <= 0) {
            this->state = 2;
            play_sound_effect(remap_sound_id(0x3A818), &this->position, 0, 0);
            this->actorFlags |= 0x1000000;
            this->actorFlags &= ~0x800000;
            this->find_target_in_range(((EnemyMoveParams *)this->movementParameters)->max_distance);
            if (this->target != NULL) {
                Vec d;
                VecCopy(&d, &this->position);
                subtract_vector(&d, &((TObjBase *)this->target)->position);
                find_open_direction(&d);
                calc_velocity_toward_destination(this, this->position, this->moveDestination, this->moveSpeed);
            } else {
                VecCopy(&this->moveDestination, &this->home_position);
                calc_velocity_toward_destination(this, this->position, this->moveDestination, this->moveSpeed);
            }
        }
        this->check_object_collisions();
        check_enemy_body_collisions(this);
        this->update_enemy_collision_flags();
        break;
    case 2: {
        s32 rising;
        this->actorFlags &= ~0x800000;
        this->advance_animation();
        calc_velocity_toward_destination(this, this->position, this->moveDestination, get_gigue_float_parameter(this, 0));
        rising = 1;
        if (this->requested_action == 6 && this->frame < 22.0f) {
            rising = 0;
        }
        if (rising) {
            this->flightHeight += 2.2f;
        }
        update_collisions();
        if (TObjPlayer__sub_800DC478((u8 *)this, 1, 22.0f) != 0 && this->check_vector_bit(&this->position) != 0) {
            spawn_particle_effect(&this->position, 0xF0);
        }
        if (this->flightHeight >= 50.0f) {
            this->state = 3;
        }
        play_persistent_sound((s32)(remap_sound_id(0x3A819)), this, &this->position, (s32)(0), (s32)(0));
        break;
    }
    case 3:
        this->advance_animation();
        calc_velocity_toward_destination(this, this->position, this->moveDestination, get_gigue_float_parameter(this, 0));
        this->velocity.y = 0.0f;
        VecCopy(&this->prev_position, &this->position);
        vec3_add_to(&this->position, &this->velocity);
        if (csnVector(&this->prev_position, &this->position, 0x88E0) != 0) {
            VecCopy(&this->position, &this->prev_position);
            this->state = 4;
            this->velocity.x = this->velocity.z = 0.0f;
        } else {
            if (xz_distance_squared(&this->position, &this->moveDestination) <= (10.0f + this->moveSpeed) * (10.0f + this->moveSpeed)) {
                this->state = 4;
                this->velocity.x = this->velocity.z = 0.0f;
            }
        }
        if (this->is_passing_frame(10.0f) != 0 && this->check_vector_bit(&this->position) != 0) {
            spawn_particle_effect(&this->position, 0xF0);
        }
        this->refresh_collision_body_centers();
        if (this->flightHeight > 15.0f) {
            this->turn_toward_direction(((EnemyMoveParams *)this->movementParameters)->turn_speed * 2, &this->velocity);
        }
        play_persistent_sound((s32)(remap_sound_id(0x3A819)), this, &this->position, (s32)(0), (s32)(0));
        project_actor_to_ground(this, &this->position, 0);
        break;
    case 4:
        this->actorFlags &= ~0x800000;
        this->bodies[1].flags |= 1;
        this->advance_animation();
        this->flightHeight += -2.3f;
        if (this->flightHeight <= 0.0f) {
            this->flightHeight = 0.0f;
            this->actorFlags |= 0x800000;
            this->actorFlags &= ~0x1000000;
            this->velocity.y = 0.0f;
            if (this->requested_action != 8) {
                if (!(this->behavior_flags & 0x80000) && this->random_ratio() <= this->barrierChance) {
                    this->update_if_active(12);
                } else {
                    this->update_if_active(0);
                }
            }
        } else if (this->requested_action == 7) {
            if (this->flightHeight <= 2.3f * (40.0f + 1.0f / this->blend_speed)) {
                this->requested_action = 8;
            }
        } else {
            s32 frame = (s32)this->frame;
            if ((frame == 0x14 || frame == 0x28) && this->check_vector_bit(&this->position) != 0) {
                spawn_particle_effect(&this->position, 0xF0);
            }
        }
        play_persistent_sound((s32)(remap_sound_id(0x3A819)), this, &this->position, (s32)(0), (s32)(0));
        this->check_object_collisions();
        check_enemy_body_collisions(this);
        this->update_enemy_collision_flags();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case -1:
        if (this->next_action != 4 && this->next_action != 5) {
            this->flightHeight = 0.0f;
        }
        this->bodies[1].flags &= ~1;
        this->behavior_flags &= ~0x40000;
        this->approachCount = 0;
        break;
    }
}

void TObjEneMe1GiGue::update_hit_reaction() {
    s16 action;
    s16 ref_hp;
    saddr entity;
    s32 retaliate;
    switch (state) {
    case 0:
        action = 4;
        actorFlags &= ~0x200000;
        if (actorFlags & 0x01000000) {
            action = 5;
        }
        requested_action = action;
        spawn_particle_effect(&body_center, 0xF2);
        state = 1;
    case 1:
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            Vec v = body_center;
            v.x += velocity.x;
            v.z += velocity.z;
            if (check_path_obstructed(this, &v) == 0) {
                move_with_wall_slide(this);
            } else {
                velocity.x = velocity.z = 0.0f;
            }
            velocity.x *= 0.5f;
            velocity.z *= 0.5f;
        }
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        if (action_flags != 8) {
            state = -1;
        }
        break;
    case -1:
        retaliate = 0;
        actorFlags &= ~0x200;
        behavior_flags &= ~1;
        resume_action = 1;
        ref_hp = referenceHp;
        if (ref_hp - hp > ref_hp / 4 && !(actorFlags & 2)) {
            entity = (saddr)find_entity_by_id(attacker_id);
            if (entity != 0) {
                retaliate = 1;
                if ((actorFlags & 0x01000000) && xz_distance_squared(&position, &((TObjBase *)entity)->position) > 400.0f) {
                    retaliate = 0;
                }
            }
        }
        if (retaliate == 1) {
            targetId = attacker_id;
            next_action = 9;
        } else if (actorFlags & 0x01000000) {
            update_if_active(13);
            resume_action = previous_action;
        } else {
            update_if_active(0);
        }
        referenceHp = hp;
        break;
    }
}

void TObjEneMe1GiGue::break_apart() {
    Vec pos;
    VecCopy(&pos, &position);
    pos.y += 40.0f + flightHeight;
    TBoss3Volopt::create_breakup_mdl(gigue_breakup_model, NULL,
                       texlist, &pos, rotation_y);
    refresh_lobby_state();
    send_entity_set_flags();
    spawn_particle_effect(&pos, 0x205);
    spawn_particle_effect(&pos, 0x206);
    play_sound_effect(remap_sound_id(0x3AF1C), &pos, 0, 0);
    queue_destruction();
}

void TObjEneMe1GiGue::move_around_center(const Vec *center, f32 radius) {
    if (xz_distance_squared(&this->position, &this->moveDestination) < 400.0f) {
        s32 angle = (s32)(182.04445f * (360.0f * this->random_ratio()));
        f32 d = 0.4f * (radius * (1.0f + this->random_ratio()));
        this->moveDestination.x = d * cos_table_lookup(angle) + center->x;
        this->moveDestination.z = d * sin_table_lookup(angle) + center->z;
    }
    VecCopy(&this->move_destination, &this->moveDestination);
    enemy_turn_toward_dest(((EnemyMoveParams *)this->movementParameters)->turn_speed);
    enemy_set_heading_velocity(this->moveSpeed, this, this->rotation_y);
    move_with_wall_slide(this);
}

void TObjEneMe1GiGue::spawn_targeted_shot(s32 index) {
    if (find_entity_by_id(targetIds[index]) != 0) {
        GiGueShotAngles angles;
        angles.x = 0;
        angles.y = rotation_y + ((index & 1) ? -0x2000 : 0x2000);
        angles.z = 0;
        new TUnk_804E14E8(&shotOrigin, targetIds[index], &angles, index * 3,
                          random_ratio() <= get_gigue_float_parameter(this, 5),
                          entity_id);
    }
}

void TObjEneMe1GiGue::update_proximity_state() {
    switch (mode) {
    case 0:
        if (is_actor_cadence_frame(30) != 0) {
            if (find_nearest_visible_player(this, NULL, ((EnemyMoveParams *)movementParameters)->max_distance) != 0xFFFF) {
                find_target_in_range(((EnemyMoveParams *)movementParameters)->max_distance);
                if (behavior_flags & 0x40000) {
                    init_move();
                } else {
                    update_if_active(1);
                }
            }
        }
        break;
    case 1:
        if (find_nearest_visible_player(this, NULL, 50.0f) != 0xFFFF) {
            if (random_ratio() <= techniqueChance) {
                update_if_active(11);
            } else {
                update_if_active(13);
                resume_action = 1;
            }
        } else if (find_nearest_visible_player(this, NULL, 50.0f + ((EnemyMoveParams *)movementParameters)->max_distance) == 0xFFFF) {
            update_if_active(0);
        }
        break;
    case 13:
        break;
    }
}

void TObjEneMe1GiGue::init_move() {
    VecCopy(&prev_position, &position);
    actorFlags |= 0x01000000;
    update_if_active(14);
    resume_action = 1;
    refresh_collision_body_centers();
}

void TObjEneMe1GiGue::apply_hit_shake(TObjChara *player) {
    if (player == get_player_by_client_id(0) && cameraShakeCooldown <= 0) {
        cameraShakeCooldown = 30;
        TCameraCtrl::set_shake_preset(1);
    }
}

s32 TObjEneMe1GiGue::remap_sound_id(s32 id) {
    s32 area = get_current_floor_area();
    if (id == 0x3A344) return area == AREA_TOWER ? 0x40039E14 : id;
    if (id == 0x3A345) return area == AREA_TOWER ? 0x40039415 : id;
    return remap_sound_for_area(id);
}


void TObjEneMe1GiGue::update_landing_state() {
    f32 height;
    s32 whole_frame;
    switch (state) {
    case 0:
        VecCopy(&moveDestination, &home_position);
        calc_velocity_toward_destination(this, position, moveDestination, moveSpeed);
        behavior_flags &= ~0x40000;
        clear_flags_30();
        flightHeight = entryHeight;
        requested_action = 7;
        state = 1;
    case 1:
        advance_animation();
        bodies[1].flags |= 1;
        flightHeight += -2.3f;
        height = flightHeight;
        if (height <= 0.0f) {
            flightHeight = 0.0f;
            actorFlags |= 0x800000;
            actorFlags &= ~0x1000000;
            velocity.y = 0.0f;
            if (requested_action != 8) {
                state = -1;
                play_sound_effect(remap_sound_id(0x3A345), &position, 0, 0);
            }
        } else if (requested_action == 7) {
            if (height <= 2.3f * (40.0f + 1.0f / blend_speed)) {
                requested_action = 8;
            }
        } else {
            whole_frame = (s32)frame;
            if ((whole_frame == 0x14 || whole_frame == 0x28) && check_vector_bit(&position) != 0) {
                spawn_particle_effect(&position, 0xF0);
            }
        }
        play_persistent_sound((s32)(remap_sound_id(0x3A819)), this, &position, (s32)(0), (s32)(0));
        update_collisions();
        break;
    case -1:
        update_if_active(1);
        break;
    }
    apply_actor_gravity(this, 0, 0.0f);
}

void TObjEneMe1GiGue::init() {
    u32 flags;

    switch (state) {
    case 0:
        behavior_flags |= 4;
        flags = actorFlags | 0x04000000;
        actorFlags = flags;
        requested_action = 0;
        play_area_sound_effect(&body_center);
        appearFade.start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        if (appearFade.advance_toward_max() == 1) {
            state = -1;
            play_sound_effect(remap_sound_id(0x3A345), &position, 0, 0);
        }
        update_collisions();
        return;
    case -1:
        flags = behavior_flags;
        behavior_flags = flags & ~5;
        actorFlags &= ~0x04000000;
        update_if_active(0);
        return;
    }
}


void TObjEneMe1GiGue::add_target_in_cone(TObjChara *target) {
    int angle;
    if (this->targetCount < 12 && target != NULL && (void *)target != (void *)this && !(target->actorFlags & 0x06000800)) {
        Vec v = target->position;
        subtract_vector(&v, &this->position);
        if (!(v.x * v.x + v.z * v.z > this->attackRange * this->attackRange)) {
            angle = -(s32)(10430.38043493439 * atan2_float(v.z, v.x)) + 0x4000;
            if (angle_difference_abs(angle, this->rotation_y) <= this->attackAngle / 2) {
                this->targetIds[this->targetCount++] = target->get_entity_id();
            }
        }
    }
}

s32 TObjEneMe1GiGue::collect_shot_targets() {
    s32 i;
    targetCount = 0;
    for (i = 0; i < registered_player_count; i++) {
        TObjChara *player = (TObjChara *)TObjPlayer::get_player_data(i);
        add_target_in_cone(player);
    }
    return targetCount;
}

void TObjEneMe1GiGue::capture_shot_origins() {
    push_matrix_from(&identity_matrix);
    translate_matrix(0, position.x, flightHeight + (position.y + sinkingOffset), position.z);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    get_anim_node_position(0, &rootPosition);
    get_anim_node_position(0x2A, &missileOrigin);
    get_anim_node_position(0x16, &shotOrigin);
}

void TObjEneMe1GiGue::update_direction() {
    attackRange = attack_params->get_attack_range();
    attackAngle = attack_params->get_attack_angle();
}

void TObjEneMe1GiGue::load_params() {
    gigue_missile_speed = get_gigue_float_parameter(this, 1);
    gigue_shot_speed = get_gigue_float_parameter(this, 2);
    gigue_shot_homing = get_gigue_float_parameter(this, 3);
    gigue_shot_homing_step = get_gigue_float_parameter(this, 4);
    gigue_missile_power = get_gigue_int_parameter(this, 0);
    gigue_shot_power = get_gigue_int_parameter(this, 1);
    barrierDuration = (s32)(30.0f * (f32)get_gigue_int_parameter(this, 3));
    attackDuration = get_gigue_int_parameter(this, 4);
}

#pragma pool_data off
void TObjEneMe1GiGue::find_open_direction(Vec *dir) {
    f32 best;
    s32 ang;
    s32 best_ang;
    s32 i;
    CsnHit *hit;
    f32 d;
    ang = (s32)(10430.38043493439 * atan2_float(dir->x, dir->z));
    best = 0.0f;
    best_ang = ang;
    push_matrix_from(&identity_matrix);
    Vec v = {200.0f, 0.0f, 0.0f};
    rotate_matrix_y(0, ang);
    for (i = 0; i < 3; i++) {
        matrix_mult_vec(0, &v, &moveDestination);
        vec3_add_to(&moveDestination, &body_center);
        hit = csnVector(&body_center, &moveDestination, -1);
        if (hit == NULL) {
            pop_matrix();
            return;
        }
        d = vec_xz_distance(&position, &hit->contact->point) - 20.0f;
        if (best < d) {
            best = d;
            best_ang = ang;
        }
        rotate_matrix_y(0, 0x5555);
        ang += 0x5555;
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    Vec w = {0.0f, 0.0f, 0.0f};
    w.x = best;
    rotate_matrix_y(0, best_ang);
    matrix_mult_vec(0, &w, &moveDestination);
    vec3_add_to(&moveDestination, &body_center);
    pop_matrix();
}
#pragma pool_data reset

s32 TObjEneMe1GiGue::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

void TObjEneMe1GiGue::clear_state7_flag() {
    s32 flags = behavior_flags;
    if (flags & 0x40000) {
        behavior_flags = flags & ~0x40000;
        VecCopy(&position, &home_position);
        project_actor_to_ground(this, &position, 0);
        return;
    }
    if (next_action == 7) {
        behavior_flags = flags & ~1;
        update_if_active(0);
    }
}

s32 TObjEneMe1GiGue::check_vector_bit(Vec *pos) {
    CsnHit *hit = csnVectorUnder(pos, ground_candidates.groups, 5);
    if (hit == NULL) {
        return 0;
    }
    return (u32)__cntlzw(hit->hit_mask & 4) >> 5;
}

BmlResource *TObjEneMe1GiGue::get_resource() { return gigue_resource; }


Vec *TObjEneMe1GiGue::update_and_get_pos() {
    capture_shot_origins();
    return &rootPosition;
}

s32 TObjEneMe1GiGue::get_rotation_y() { return rotation_y; }

s32 TObjEneMe1GiGue::get_barrier_duration() { return barrierDuration; }

s32 TObjEneMe1GiGue::is_active_state() {
    s32 r = 0;
    s16 v = mode;
    if (v == 9) goto yes;
    if (v == 10) goto yes;
    if (v == 11) goto yes;
    if (v == 4) goto yes;
    if (v != 5) goto done;
yes:
    r = 1;
done:
    return (u8)r;
}

void TObjEneMe1GiGue::set_barrier_active() { behavior_flags |= 0x80000; }

void TObjEneMe1GiGue::clear_barrier_active() { behavior_flags &= ~0x80000; }


f32 TObjEneMe1GiGue::receive_physical_attack(void *attacker, f32 power) {
    f32 damage = 0.0f;
    if (behavior_flags & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_physical_attack(attacker, power);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_direct_attack(void *attacker, DirectAttackPayload hit, void *source, s32, s32) {
    f32 damage = 0.0f;
    if (behavior_flags & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_direct_attack(attacker, hit, source, -1, -1);
    }
    return damage;
}

f32 TObjEneMe1GiGue::receive_weapon_special_attack(void *attacker, void *weapon) {
    f32 damage = 0.0f;
    if (behavior_flags & 0x80000) {
        show_miss_popup(&body_center.x);
        set_state(10);
    } else {
        damage = TObjChara::receive_weapon_special_attack(attacker, weapon);
    }
    return damage;
}
