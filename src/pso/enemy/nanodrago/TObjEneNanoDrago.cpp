#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/unk/text_800DC420.h"
#include "pso/object/TObjControl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"

#include "pso/render/TUnk_80494938.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/AngleUnits.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/render/model_render_state.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"


#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/object/base/TObjBase.h"
LAYOUT_ASSERT(NanoGrow_scale, offsetof(TObjEneNanoDrago, scale.x) == 0x68);
LAYOUT_ASSERT(NanoGrow_target_scale, offsetof(TObjEneNanoDrago, scale.y) == 0x6c);
LAYOUT_ASSERT(NanoGrow_base_atp, offsetof(TObjEneNanoDrago, base_atp) == 0x2c0);
LAYOUT_ASSERT(NanoGrow_atp, offsetof(TObjEneNanoDrago, atp) == 0x2c8);
LAYOUT_ASSERT(NanoGrow_body_center, offsetof(TObjEneNanoDrago, body_center) == 0x2fc);
LAYOUT_ASSERT(NanoGrow_params, offsetof(TObjEneNanoDrago, movementParameters) == 0x350);
LAYOUT_ASSERT(NanoGrow_next_action, offsetof(TObjEneNanoDrago, next_action) == 0x374);
LAYOUT_ASSERT(NanoGrow_state, offsetof(TObjEneNanoDrago, state) == 0x37c);
LAYOUT_ASSERT(NanoGrow_growth_count, offsetof(TObjEneNanoDrago, growth_count) == 0x38c);
LAYOUT_ASSERT(NanoGrow_speed, offsetof(TObjEneNanoDrago, speed) == 0x3d8);
LAYOUT_ASSERT(NanoDrago_flags30_offset, offsetof(TObjEneNanoDrago, actorFlags) == 0x30);
LAYOUT_ASSERT(NanoDrago_pos_offset, offsetof(TObjEneNanoDrago, position) == 0x38);
LAYOUT_ASSERT(NanoDrago_angle_offset, offsetof(TObjEneNanoDrago, rotation_y) == 0x60);
LAYOUT_ASSERT(NanoDrago_fb8_offset, offsetof(TObjEneNanoDrago, requested_action) == 0xb8);
LAYOUT_ASSERT(NanoDrago_home_offset, offsetof(TObjEneNanoDrago, move_destination) == 0x29c);
LAYOUT_ASSERT(NanoDrago_target_offset, offsetof(TObjEneNanoDrago, target) == 0x2a8);
LAYOUT_ASSERT(NanoDrago_hpmax_offset, offsetof(TObjEneNanoDrago, hpmax) == 0x2b8);
LAYOUT_ASSERT(NanoDrago_hp_offset, offsetof(TObjEneNanoDrago, hp) == 0x32c);
LAYOUT_ASSERT(NanoDrago_params_offset, offsetof(TObjEneNanoDrago, movementParameters) == 0x350);
LAYOUT_ASSERT(NanoDrago_state_offset, offsetof(TObjEneNanoDrago, state) == 0x37c);
LAYOUT_ASSERT(NanoDrago_flags388_offset, offsetof(TObjEneNanoDrago, behavior_flags) == 0x388);
LAYOUT_ASSERT(NanoDrago_accum_offset, offsetof(TObjEneNanoDrago, circlingAngle) == 0x3d0);
LAYOUT_ASSERT(NanoDrago_t_offset, offsetof(TObjEneNanoDrago, wanderDistance) == 0x3d4);
LAYOUT_ASSERT(NanoDrago_speed_offset, offsetof(TObjEneNanoDrago, speed) == 0x3d8);
LAYOUT_ASSERT(NanoDrago_toggle_offset, offsetof(TObjEneNanoDrago, alternateBeam) == 0x3e0);




struct BeamRotation { s32 x, y, z; };


extern "C" void TObjPlayer__sub_800DCD04(void *, void *, int, void *, s32, int);
extern "C" s32 construct_beam_effect__10TObjPlayerFPvPvPviPv(u32, void *, void *, u8, void *);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 max_float(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}

inline f32 xz_length_squared(Vec *v) { return v->x * v->x + v->z * v->z; }

#pragma pop

#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3VoloptMonitor.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/player/PlayerSlots.h"






// inferred: the per-variant tables load_resources fetches from TLobby (register_boss,
// dispatch_shared_handler_b, register_object; boss5_gryphon_base/attack/resistance_params twins)
player_stats *nano_drago_base_params;
AttackParams *nano_drago_attack_params;
ActorParamBlock *nano_drago_resistance_params;
s32 lbl_805D5254;
BmlResource *nano_drago_entry_params_resource;
// Filled by update_attack_parameters, read by the NanoDrago projectiles.
f32 lbl_805D525C;
f32 lbl_805D5260;
f32 lbl_805D5264;
f32 lbl_805D5268;
s32 lbl_805D526C;
s32 lbl_805D5270;

__declspec(section ".data") const char *bm_ene_nanodrago_model_names[2] = {
    "bm6_s_drc_body.nj", NULL,
};
const char *bm_ene_nanodrago_motion_names[13] = {
    "beam_bm6_s_drc_body.njm", "damfly_bm6_s_drc_body.njm", "damgrd_bm6_s_drc_body.njm", "deadg_bm6_s_drc_body.njm",
    "deads_bm6_s_drc_body.njm", "fly_bm6_s_drc_body.njm", "joy_bm6_s_drc_body.njm", "land_bm6_s_drc_body.njm",
    "lasfly_bm6_s_drc_body.njm", "lift_bm6_s_drc_body.njm", "wait_bm6_s_drc_body.njm", "walk_bm6_s_drc_body.njm",
    NULL,
};
BmlResourceDescriptor bm_ene_nanodrago_resource_descriptor = {
    "bm_ene_nanodrago.bml", bm_ene_nanodrago_model_names, bm_ene_nanodrago_motion_names, 1, 12
};
TObjMotionAction nanodrago_action_table[12] = {
    {2, 0, 10, 0.8f, 0},
    {1, 1, 11, 0.8f, 1},
    {2, 0, 0, 0.7f, 4},
    {2, 0, 2, 0.8f, 8},
    {3, 4, 3, 0.5f, 0x10},
    {2, 0, 6, 0.8f, 1},
    {2, 7, 9, 0.9f, 1},
    {1, 7, 5, 1.4f, 1},
    {2, 0, 7, 1.4f, 1},
    {2, 7, 8, 0.7f, 4},
    {2, 7, 1, 0.8f, 8},
    {3, 11, 4, 0.5f, 0x10},
};
NanoDragoMovementParams nano_drago_movement = {
    150.0f, 0.46296296f, 0x300, {0x1E0000, 0, 1, 0}
};
CollisionBody nano_drago_bodies[2] = {
    {{0.0f, 15.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8001, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 12.0f, 0.0f, 0, 0xA000002, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *nano_drago_name = "TObjEneNanoDrago";

// Deferred code generation emits these methods in address order.
void TObjEneNanoDrago::run_miss_reaction() {  }
void TObjEneNanoDrago::run_move_action() {  }
void TObjEneNanoDrago::run_attack_action() {  }
void TObjEneNanoDrago::run_idle_action() {  }
TObjEneNanoDrago::TObjEneNanoDrago(TObject *parent, void *setData) : TObjEnemyCustom(parent) {
    s32 i;
    m_name = nano_drago_name;
    apply_set_data(setData);
    VecCopy(&move_origin, (const Vec *)(VecCopy(&move_destination, (const Vec *)(&position))));
    motion_list = nano_drago_entry_params_resource->motions;
    variant = 0;
    add_flags_2e4(2);
    state36C = *(s16 *)((s8 *)setData + 0x3E);
    load_entry_params_nanodrago(variant);
    action_table = nanodrago_action_table;
    set_action_table(action_table);
    init_collision_body_parts(this, nano_drago_bodies, 2);
    bodies[1].flags &= ~1;
    movementParameters = &nano_drago_movement;
    bind_enemy_combat_stats(nano_drago_base_params, nano_drago_attack_params, nano_drago_resistance_params);
    update_attack_parameters();
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    growth_count = 0;
    scale.x = 0.6f;
    speed = ((NanoDragoMovementParams *)movementParameters)->baseSpeed * scale.x;
    VecCopy((Vec *)(&home_position), (const Vec *)(&position));
    VecCopy((Vec *)(&moveDestination), (const Vec *)(&position));
    if ((s32)parameters[0] == 1) {
        behavior_flags |= 0x40000;
        if (parameters[1] < 1.0f) {
            parameters[1] = 50.0f;
        }
        set_flags_30();
    }
    cameraShakeCooldown = 0;
    alternateBeam = 0;
    set_param(0xF);
    sinkingOffset = 0.0f;
    if (*(s16 *)((s8 *)setData + 0xA) != 0 && !(behavior_flags & 0x40000)) {
        start_appear();
    }
    flightHeight = 0.0f;
    for (i = 0; i < 4; i++) {
        cameraFades[i].activate_and_dispatch();
    }
    set_actor_flags(0x1000000);
    VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
    clear_lobby_object_state();
}
TObjEneNanoDrago::~TObjEneNanoDrago() {
    free_collision_body_parts(this);
}
void TObjEneNanoDrago::load_resources() {
    BmlModelEntry *modelEntries;
    u8 *resource;

    resource = (u8 *)new BmlResource(1, &bm_ene_nanodrago_resource_descriptor, 0, 0, NULL);
    nano_drago_entry_params_resource = (BmlResource *)resource;
    nano_drago_base_params = TLobby::register_boss(0x1A);
    nano_drago_attack_params = TLobby::dispatch_shared_handler_b(0x1A);
    nano_drago_resistance_params = TLobby::register_object(0x1A);
    lbl_805D5254 = (saddr)TLobby::dispatch_shared_handler_a(0x1A);
    NpcAnimationBinding binding = { nano_drago_entry_params_resource->motions, nanodrago_action_table, 0, 1, 12 };
    modelEntries = nano_drago_entry_params_resource->models;
    TObjNpcEnemy::register_animated_chunk((s16)(0x22), modelEntries[0].model, modelEntries[0].texlist, &binding, (f32)(15.0f), (f32)(0.0f));
}
void TObjEneNanoDrago::free_resources() {
    if ((uaddr) nano_drago_entry_params_resource != 0U) {
        delete nano_drago_entry_params_resource;
        nano_drago_entry_params_resource = NULL;
    }
}
void *TObjEneNanoDrago::create(void *setData) {
    void *o;
    void *o2;
    o = new TObjControl(tl_04);
    o2 = new TObjEneNanoDrago((TObject *)o, setData);
    return o2;
}
void TObjEneNanoDrago::run_task() {
    s32 cooldown;

    if (TObjPlayer::check_demo_mode() == 1) {
        update_attack_parameters();
        run_demo_task();
        return;
    }
    target = static_cast<TObjChara *>(find_active_entity_by_id(targetId));
    release_destroyed_target();
    update_proximity_state();
    if ((s16) mode != next_action) {
        if ((s32) state != -1) {
            state = -1;
            dispatch_action_state();
        }
        mode = (s16) next_action;
        state = 0;
    }
    dispatch_action_state();
    if ((s32) state == -1) {
        state = -1;
        dispatch_action_state();
        mode = (s16) next_action;
        state = 0;
    }
    VecCopy((Vec *)(&body_center), (const Vec *)(&position));
    body_center.y = (f32) (body_center.y + (15.0f + flightHeight));
    bodies[0].offset.y = (f32) (15.0f + flightHeight);
    if (!(behavior_flags & 0x40000)) {
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
    }
    cooldown = cameraShakeCooldown;
    if (cooldown > 0) {
        cameraShakeCooldown = (cooldown - 1);
    }
    bodies[0].flags &= ~6;
    if (flightHeight > 5.0f) {
        bodies[0].flags |= 4;
    } else {
        bodies[0].flags |= 2;
    }
    if (xz_distance_squared(&position, &prev_position) > 2500.0f) {
        VecCopy((Vec *)(&position), (const Vec *)(&prev_position));
    }
    VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
}
void TObjEneNanoDrago::dispatch_action_state() {
  s16 action;
  action = mode;
  {
    switch (action)
    {
      case 0:
        update_idle_state();
        return;
      case 1:
        update_circling_state();
        return;
      case 2:
        TObjPlayer__sub_800DC444();
        return;
      case 3:
        update_state_machine();
        return;
      case 4:
        update_knockback_state();
        return;
      case 5:
        update_dying_state();
        return;
      case 9:
        update_multi_beam_state();
        return;
      case 10:
        update_single_beam_state();
        return;
      case 11:
        update_flight_state();
        return;
      case 12:
        update_growth_state();
        return;
      case 7:
        update_fade_in_state();
        break;
    }
  }
}

#pragma push
#pragma fp_contract on
void TObjEneNanoDrago::render() {
    Vec shadowScale;
    f32 shadowRadius;
    f32 modelScale;
    s32 cameraIndex;
    RenderFadeState *fade;
    s32 viewDetail;
    s32 rendered;
    cameraIndex = 0;
    if (is_split_screen() != 0) {
        cameraIndex = TCameraCtrl::get_camera_mode();
    }
    if (!(actorFlags & 0x02000000) && (viewDetail = classify_actor_view_detail(150.0f, 400.0f, 20.0f), viewDetail != 0) && ((TObjPlayer::check_demo_mode() == 1) || !(behavior_flags & 0x40000))) {
        saved_model_render_flags = model_render_flags;
        fade = &cameraFades[cameraIndex];
        fade->update();
        if (fade->updateFromCamera((const f32*)(&body_center)) != 0) {
            fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        select_actor_lighting(this);
        TObjPlayer::toggle_particle_effect();
        rendered = 1;
        push_matrix();
        translate_matrix(0, position.x, (f32) (flightHeight + (position.y + sinkingOffset)), position.z);
        rotate_matrix_y(0, rotation_y);
        modelScale = scale.x;
        scale_matrix(0, modelScale, modelScale, modelScale);
        model_render_flags &= 0xFFFFFBFF;
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else if (behavior_flags & 4) {
            if (appearFade.has_visible_opacity() != 0) {
                appearFade.set_flags_and_apply_damage_color();
                if (viewDetail == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
                appearFade.clear_flag_and_notify();
            } else {
                rendered = 0;
            }
        } else if (viewDetail == 1) {
            draw();
        } else {
            draw_motion_model();
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        if (!(actorFlags & 0x800) && (rendered != 0)) {
            shadowRadius = -(0.01f * flightHeight - 1.0f) * (5.0f * scale.x);
            shadowScale.z = shadowRadius;
            shadowScale.y = shadowRadius;
            shadowScale.x = shadowRadius;
            TObjEnemy::draw_ground_shadow(&shadowScale, 0);
        }
        fade->clear_flag_and_notify();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma pop
void TObjEneNanoDrago::run_demo_task() {
  }
void TObjEneNanoDrago::update_idle_state() {
    if ((behavior_flags) & 0x40000) {
        return;
    }
    switch ((state)) {
    case -1:
        break;
    case 0:
        requested_action = 1;
        (state) = 1;
        state_timer = 0x96;
        clear_flags_30();
    case 1:
        advance_animation();
        wander_around(&home_position, parameters[1]);
        if (is_passing_frame(4.0f) != 0 || is_passing_frame(20.0f) != 0) {
            play_sound_effect(0x4003AD23, &position, 0, 0);
        }
        state_timer = state_timer - 1;
        if (state_timer <= 0) {
            requested_action = 0;
            (state) = 2;
            state_timer = 0x5A;
        }
        check_object_collisions();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation();
        check_object_collisions();
        state_timer = state_timer - 1;
        if (state_timer <= 0) {
            (state) = 0;
        }
        break;
    }
}
void TObjEneNanoDrago::run_hit_reaction() {
    this->set_state(4);
    previous_action = (s32) resume_action;
    resume_action = 4;
    behavior_flags = (s32) (behavior_flags | 0x10000 | 1);
}
void TObjEneNanoDrago::run_death_reaction() {
    this->set_state(5);
    previous_action = (s32) resume_action;
    resume_action = 5;
    behavior_flags = (s32) (behavior_flags | 1);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TObjEneNanoDrago::update_circling_state() {
    (actorFlags) &= ~0x01000000;
    switch (state) {
    case -1:
        break;
    case 0:
        (behavior_flags) &= ~0x00040000;
        clear_flags_30();
        requested_action = 1;
        circlingAngle = 0;
        if (target != NULL) {
            VecCopy(&move_destination, &target->body_center);
        }
        state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        if (is_passing_frame(4.0f) != 0 || is_passing_frame(20.0f) != 0) {
            play_sound_effect(0x4003AD23, (Vec *)&position, 0, 0);
        }
        if (target != NULL) {
            Vec d = ((TObjBase *)target)->position;
            subtract_vector(&d, (Vec *)&position);
            if (xz_length_squared(&d) <= 160000.0f &&
                angle_difference_abs(-(s32)(RADIANS_TO_ANGLE * atan2_float(d.z, d.x)) + 0x4000, rotation_y) < 0xAAA) {
                s32 next;
                if (hp <= hpmax / 4) {
                    next = 10;
                } else {
                    s32 n = 9;
                    if (alternateBeam != 0) {
                        n = 10;
                    }
                    next = n;
                    alternateBeam ^= 1;
                }
                this->update_if_active(next);
                break;
            }
        }
        rotation_y += ((NanoDragoMovementParams *)movementParameters)->turnSpeed / 2;
        enemy_set_heading_velocity(speed, this, rotation_y);
        move_with_wall_slide(this);
        circlingAngle += ((NanoDragoMovementParams *)movementParameters)->turnSpeed / 2;
        if (circlingAngle > 0x10000) {
            wanderDistance = 0.0f;
            state = 2;
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        break;
    case 2:
        enemy_wander_home(speed, 100.0f, 50.0f, ((NanoDragoMovementParams *)movementParameters)->turnSpeed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        if (is_passing_frame(4.0f) != 0 || is_passing_frame(20.0f) != 0) {
            play_sound_effect(0x4003AD23, (Vec *)&position, 0, 0);
        }
        wanderDistance += speed;
        if (wanderDistance > 100.0f) {
            if (select_nearest_target(((NanoDragoMovementParams *)movementParameters)->detectionRadius) != 0) {
                circlingAngle = 0;
                state = 1;
            } else {
                this->update_if_active(0);
            }
        }
        check_object_collisions();
        check_enemy_body_collisions(this);
        break;
    }
}
#pragma pop
void TObjEneNanoDrago::update_single_beam_state() {
    s32 remainingFrames;
    s32 phase;
    phase = state;
    switch (phase) {
    case -1:
        break;
    case 0:
        clear_flags_30();
        state_timer = 0x5A;
        if (!(actorFlags & 0x01000000)) {
            requested_action = 2;
        } else {
            requested_action = 9;
        }
        state = 1;
        advance_animation();
        behavior_flags = (s32) (behavior_flags & 0xFFFBFFFF);
        break;
    case 3:
    case 2:
    case 1:
        if ((uaddr) target == 0U) {
            state = 4;
            return;
        }
        switch (phase) {
        case 1:
            if (frame >= 5.0f) {
                capture_beam_origins();
                spawn_particle_effect((&beamOrigins[0]), 0xF7);
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, this, &position, 0, 0);
            if (frame >= 20.0f) {
                capture_beam_origins();
                u32 obj = (uaddr)TObject::operator new(0x100);
                if (obj != 0U) {
                    construct_beam_effect__10TObjPlayerFPvPvPviPv(obj, &beamOrigins[0], &target->body_center, (u8) !(actorFlags & 0x01000000), this);
                }
                spawn_beam_particle(0);
                play_sound_effect(0x4003A527, &position, 0, 0);
                state = 3;
            }
            break;
        }
        VecCopy(&move_destination, &target->body_center);
        enemy_turn_half_toward_dest(this);
        advance_animation();
        if (!(actorFlags & 0x01000000)) {
            apply_actor_gravity(this, 0, 0.0f);
        }
        update_collisions();
        remainingFrames = state_timer - 1;
        state_timer = remainingFrames;
        if (remainingFrames <= 0) {
            state = 4;
        }
        break;
    case 4:
        if (actorFlags & 0x01000000) {
            resume_action = 0;
            this->update_if_active(0xB);
            return;
        }
        this->update_if_active(0);
        break;
    }
}
void TObjEneNanoDrago::update_multi_beam_state() {
    s32 r;
    s32 i;
    switch (state) {
    case 0:
        clear_flags_30();
        r = 0;
        if (!(actorFlags & 0x01000000)) {
            r = collect_beam_targets();
        }
        if (r > 0) {
            requested_action = 2;
            state_timer = 0x5A;
            state = 1;
        } else if (actorFlags & 0x01000000) {
            this->update_if_active(0xB);
        } else {
            this->update_if_active(0);
        }
        behavior_flags &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (state) {
        case 1:
            if (frame >= 5.0f) {
                capture_beam_origins();
                spawn_particle_effect(&beamOrigins[0], 0xF7);
                spawn_particle_effect(&beamOrigins[1], 0xF7);
                state = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, this, &position, 0, 0);
            if (frame >= 20.0f) {
                capture_beam_origins();
                for (i = 0; i < beamTargetCount; i++) {
                    spawn_targeted_beam(i);
                }
                state = 3;
            }
            break;
        }
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        state_timer--;
        if (state_timer <= 0) {
            state_timer = 0x2D;
            requested_action = 1;
            state = 4;
        }
        break;
    case 4:
        enemy_wander_home(speed, 100.0f, 100.0f, ((NanoDragoMovementParams *)movementParameters)->turnSpeed);
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        if (is_passing_frame(4.0f) != 0 || is_passing_frame(20.0f) != 0) {
            play_sound_effect(0x4003AD23, &position, 0, 0);
        }
        if (find_nearest_visible_player(this, NULL, 50.0f) != 0xFFFF) {
            this->update_if_active(0xB);
        } else {
            state_timer--;
            if (state_timer <= 0) {
                this->update_if_active(0);
            }
        }
        break;
    case -1:
        break;
    }
}
void TObjEneNanoDrago::update_flight_state() {
    Vec v;
    actorFlags &= ~0x800000;
    switch (state) {
    case 0:
        state = 1;
        if (actorFlags & 0x01000000) {
            if (behavior_flags & 0x40000) {
                VecCopy((Vec *)(&moveDestination), (const Vec *)(&home_position));
                calc_velocity_toward_destination(this, position, moveDestination, speed);
                behavior_flags &= ~0x40000;
                clear_flags_30();
                flightHeight = 50.0f;
            } else {
                find_target_in_range(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
                calc_velocity_toward_destination(this, position, moveDestination, speed);
            }
            requested_action = 7;
        } else {
            actorFlags |= 0x01000000;
            requested_action = 6;
            flightHeight = 0.0f;
            find_target_in_range(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
            if (target != 0) {
                VecCopy((Vec *)&v, (const Vec *)(&position));
                subtract_vector(&v, &target->position);
                find_open_direction(&v);
                calc_velocity_toward_destination(this, position, moveDestination, speed);
            } else {
                VecCopy((Vec *)(&moveDestination), (const Vec *)(&home_position));
                calc_velocity_toward_destination(this, position, moveDestination, speed);
            }
        }
        break;
    case 1:
        advance_animation();
        calc_velocity_toward_destination(this, position, moveDestination, TObjPlayer__sub_800DC434((saddr)this, 0));
        if (flightHeight < 50.0f) {
            s32 ok = 1;
            if (requested_action == 6 && frame < 22.0f) {
                ok = 0;
            }
            if (ok != 0) {
                flightHeight += 2.2f;
            }
            update_collisions();
            if (TObjPlayer__sub_800DC478(((u8 *)this), 6, 22.0f) != 0) {
                spawn_particle_effect(&position, 0xF0);
                play_sound_effect(0x4003AD20, &position, 0, 0);
            }
        } else {
            velocity.y = 0.0f;
            VecCopy((Vec *)(&prev_position), (const Vec *)(&position));
            vec3_add_to(&position, &velocity);
            if (xz_distance_squared((Vec *)(&position), (Vec *)(&moveDestination)) <= (10.0f + speed) * (10.0f + speed)) {
                state = 2;
                velocity.z = 0.0f;
                velocity.x = 0.0f;
            }
            if (is_passing_frame(10.0f) != 0) {
                spawn_particle_effect(&position, 0xF0);
                play_sound_effect(0x4003AD20, &position, 0, 0);
            }
            refresh_collision_body_centers();
        }
        if (flightHeight > 15.0f) {
            turn_toward_direction(((NanoDragoMovementParams *)movementParameters)->turnSpeed * 2, &velocity);
        }
        project_actor_to_ground(this, &position, 0);
        break;
    case 2:
        bodies[1].flags |= 1;
        advance_animation();
        flightHeight += -2.3f;
        if (flightHeight <= 0.0f) {
            flightHeight = 0.0f;
            actorFlags |= 0x800000;
            actorFlags &= ~0x01000000;
            velocity.y = 0.0f;
            if (requested_action != 8) {
                this->update_if_active(0);
            }
        } else if (requested_action == 7) {
            if (flightHeight <= 2.3f * (40.0f + 1.0f / blend_speed)) {
                requested_action = 8;
            }
        } else {
            s32 t = (s32)frame;
            if (t == 20 || t == 40) {
                spawn_particle_effect(&position, 0xF0);
            }
        }
        if (TObjPlayer__sub_800DC478(((u8 *)this), 8, 42.0f) != 0) {
            play_sound_effect(0x4003AD23, &position, 0, 0);
        }
        check_object_collisions();
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case -1:
        if (next_action != 4 && next_action != 5) {
            flightHeight = 0.0f;
        }
        bodies[1].flags &= ~1;
        behavior_flags &= ~0x40000;
        break;
    }
}
void TObjEneNanoDrago::update_growth_state() {
    f32 t;
    f32 v;

    switch (state) {
    case 0:
        if (!((actorFlags) & 0x01000000) && growth_count < 4) {
            growth_count++;
            requested_action = 5;
            state = 1;
            scale.y = 0.1f + scale.x;
            spawn_particle_effect(&body_center, 0xFA);
            speed = ((NanoDragoMovementParams *)movementParameters)->baseSpeed * scale.x;
            play_sound_effect(0x4003A824, (Vec *)&position, 0, 0);
            atp += 8;
            base_atp += 8;
        } else {
            scale.y = scale.x;
            state = -1;
        }
    case 1:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        update_collisions();
        t = scale.y;
        v = 0.0016000001f + scale.x;
        scale.x = (v < t) ? v : t;
        if (requested_action != 5) {
            (state) = -1;
        }
        break;
    case -1:
        scale.x = scale.y;
        (behavior_flags) &= 0xFFFDFFFE;
        (next_action) = 1;
        break;
    }
}
void TObjEneNanoDrago::update_knockback_state() {
    s16 previousHp;
    s16 animation;
    uaddr entity;
    s32 retaliate;
    switch (state) {
    case 0:
        animation = 3;
        actorFlags = (s32) (actorFlags & 0xFFDFFFFF);
        if (actorFlags & 0x01000000) {
            animation = 0xA;
        }
        requested_action = animation;
        spawn_particle_effect(&body_center, 0xF2);
        play_sound_effect(0x40039E22, &position, 0, 0);
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
        if ((u32) action_flags != 8U) {
            state = -1;
        }
        break;
    case -1:
        retaliate = 0;
        actorFlags = (s32) (actorFlags & 0xFFFFFDFF);
        behavior_flags = (s32) (behavior_flags & 0xFFFFFFFE);
        resume_action = 1;
        previousHp = referenceHp;
        if (((s32) (previousHp - hp) > (s32) (previousHp / 4)) && !(actorFlags & 2)) {
            entity = (uaddr)find_entity_by_id(attacker_id);
            if (entity != 0) {
                retaliate = 1;
                if ((actorFlags & 0x01000000) && (xz_distance_squared((Vec *)(&position), &((TObjBase *)entity)->position) > 400.0f)) {
                    retaliate = 0;
                }
            }
        }
        if (retaliate == 1) {
            targetId = (u16) attacker_id;
            next_action = 0xA;
        } else if (actorFlags & 0x01000000) {
            this->update_if_active(0xB);
            resume_action = (s32) previous_action;
        } else {
            this->update_if_active(0);
        }
        referenceHp = (s16) hp;
        break;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TObjEneNanoDrago::update_dying_state() {
    switch (state) {
    case 0:
        refresh_lobby_state();
        send_entity_set_flags();
        timer = 0x1E;
        play_sound_effect(0x4003A825, &position, 0, 0);
        if (actorFlags & 0x01000000) {
            descentSpeed = (f32) (0.015384615f * -flightHeight);
            requested_action = 0xB;
            state = 2;
            return;
        }
        requested_action = 4;
        state = 1;
        return;
    case 1:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        if (frame >= 30.0f) {
            spawn_particle_effect((&position), 0xF0);
            state = 3;
            return;
        }
        break;
    case 2:
        advance_animation();
        apply_actor_gravity(this, 0, 0.0f);
        {
        f32 lim = 0.0f;
        flightHeight = max_float(flightHeight + descentSpeed, lim);
        }
        if (frame >= 30.0f) {
            spawn_particle_effect((&position), 0xF0);
            play_sound_effect(0x40039E22, &position, 0, 0);
            state = 3;
            return;
        }
        break;
    case 3:
        timer = (timer - 1);
        if (timer <= 0) {
            spawn_ground_effect(&position, 0x1E);
            TObjPlayer__sub_800D92BC(&position, 0xF);
            state = 4;
            return;
        }
        break;
    case 4:
        sinkingOffset = (f32) (sinkingOffset - 0.3f);
        if (sinkingOffset < (-15.0f)) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneNanoDrago::wander_around(Vec *center, f32 radius) {
    TObjEneNanoDrago *actor = this;
    s32 ang;
    f32 r;
    if (xz_distance_squared((Vec *)&actor->position, (Vec *)&actor->moveDestination) < 400.0f) {
        ang = (s32)(182.04445f * (360.0f * random_ratio()));
        r = 0.4f * (radius * (1.0f + random_ratio()));
        actor->moveDestination.x = r * cos_table_lookup(ang) + center->x;
        actor->moveDestination.z = r * sin_table_lookup(ang) + center->z;
    }
    VecCopy(&actor->move_destination, (const Vec *)&actor->moveDestination);
    ((TObjEnemy *)actor)->enemy_turn_toward_dest(((NanoDragoMovementParams *)actor->movementParameters)->turnSpeed);
    enemy_set_heading_velocity(actor->speed, actor, actor->rotation_y);
    move_with_wall_slide(actor);
}
#pragma pop
void TObjEneNanoDrago::spawn_beam_particle(s32 i) {
    BeamRotation v;
    v.x = rotation_y + 0x4000;
    v.y = 0;
    v.z = 0x4000;
    spawn_directional_particle(&beamOrigins[i], &v, 0xfd);
}
void TObjEneNanoDrago::spawn_targeted_beam(s32 targetIndex) {
    BeamRotation rotation;
    s32 originIndex;
    s32 spreadAngle;
    void *beam;
    if (find_entity_by_id(beamTargetIds[targetIndex]) != 0) {
        originIndex = targetIndex & 1;
        rotation.x = 0;
        spreadAngle = 0x2000;
        if (originIndex != 0) {
            spreadAngle = -0x2000;
        }
        rotation.y = rotation_y + spreadAngle;
        rotation.z = 0;
        beam = (void *)TObject::operator new(0x104);
        if (beam != 0) {
            TObjPlayer__sub_800DCD04(beam, &beamOrigins[originIndex], beamTargetIds[targetIndex], &rotation, targetIndex * 3, entity_id);
        }
    }
}
void TObjEneNanoDrago::request_growth() {
    if (!(behavior_flags & 0x20000)) {
        this->update_if_active(0xC);
        behavior_flags = (s32) (behavior_flags | 0x20000 | 1);
    }
}
void TObjEneNanoDrago::update_proximity_state() {
    switch (mode) {
    case 0:
        if (is_actor_cadence_frame(0x1E) != 0) {
            if (find_nearest_visible_player(this, NULL, ((NanoDragoMovementParams *)movementParameters)->detectionRadius) != 0xFFFF) {
                select_nearest_target(((NanoDragoMovementParams *)movementParameters)->detectionRadius);
                if (behavior_flags & 0x40000) {
                    begin_hidden_flight();
                } else {
                    this->update_if_active(1);
                }
            }
        }
        break;
    case 11:
        break;
    case 1:
        if (find_nearest_visible_player(this, NULL, 50.0f) != 0xFFFF) {
            this->update_if_active(0xB);
            resume_action = 1;
        } else if (find_nearest_visible_player(this, NULL, 50.0f + ((NanoDragoMovementParams *)movementParameters)->detectionRadius) == 0xFFFF) {
            this->update_if_active(0);
        }
        break;
    }
}
void TObjEneNanoDrago::begin_hidden_flight() {
    Vec v;
    v.y = 0.0f;
    v.x = 0.0f;
    v.z = (-150.0f);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    vec3_add_to(&position, &v);
    VecCopy((Vec *)&prev_position, (const Vec *)&position);
    actorFlags |= 0x01000000;
    this->update_if_active(0xB);
    resume_action = 1;
    refresh_collision_body_centers();
}
void TObjEneNanoDrago::trigger_hit_camera_shake(u32 victim) {
    if ((victim == (uaddr)get_player_by_client_id(0)) && ((s32) cameraShakeCooldown <= 0)) {
        cameraShakeCooldown = 0x1E;
        TCameraCtrl::set_shake_preset(1);
    }
}
void TObjEneNanoDrago::update_fade_in_state() {
    s32 flags;
    s32 stateFlags;

    switch (state) {
    case 0:
        behavior_flags = (s32) (behavior_flags | 4);
        flags = actorFlags | 0x04000000;
        actorFlags = flags;
        requested_action = 0;
        play_area_sound_effect(&body_center);
        ((TUnk_80494938 *)(&appearFade))->start_fade_in();
        state = 1;
    case 1:
        advance_animation();
        if (appearFade.advance_toward_max() == 1) {
            state = -1;
        }
        update_collisions();
        return;
    case -1:
        stateFlags = behavior_flags;
        behavior_flags = (s32) (stateFlags & ~5);
        actorFlags = (s32) (actorFlags & 0xFBFFFFFF);
        this->update_if_active(0);
        break;
    }
}
void TObjEneNanoDrago::add_target_in_front_arc(TObjChara *candidate) {
  f32 dx;
  int heading;
  if ((((beamTargetCount < 12) && (candidate != 0)) && (candidate != this)) && (!(candidate->actorFlags & 0x6000800)))
  {
    Vec v = candidate->position;
    subtract_vector(&v, &position);
    if (!(((v.x * v.x) + (v.z * v.z)) > 160000.0f))
    {
      dx = v.x;
      heading = (-((s32) (RADIANS_TO_ANGLE * atan2_float(v.z, dx)))) + 0x4000;
      if (angle_difference_abs(heading, rotation_y) <= 0xAAA)
      {
        s16 id = candidate->get_entity_id();
        u16 *ids = beamTargetIds;
        ids[beamTargetCount++] = id;
      }
    }
  }
}
s32 TObjEneNanoDrago::collect_beam_targets() {
    s32 i;
    TObjPlayer *candidate;
    beamTargetCount = 0;
    for (i = 0; i < registered_player_count + registered_enemy_count; i++) {
        candidate = TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)candidate) != 0) {
            add_target_in_front_arc(candidate);
        }
    }
    return beamTargetCount;
}
void TObjEneNanoDrago::capture_beam_origins() {
    f32 modelScale;
    push_matrix_from(&identity_matrix);
    translate_matrix(0, position.x, (f32) (flightHeight + (position.y + sinkingOffset)), position.z);
    rotate_matrix_y(0, rotation_y);
    modelScale = scale.x;
    scale_matrix(0, modelScale, modelScale, modelScale);
    calc_joint_matrices(frame);
    pop_matrix();
    get_anim_node_position(0x55, &beamOrigins[0]);
    get_anim_node_position(0x54, &beamOrigins[1]);
}
void TObjEneNanoDrago::update_attack_parameters() {
    saddr self = (saddr)this;
    lbl_805D525C = TObjPlayer__sub_800DC434((self), 1);
    lbl_805D5260 = TObjPlayer__sub_800DC434((self), 2);
    lbl_805D5264 = TObjPlayer__sub_800DC434((self), 3);
    lbl_805D5268 = TObjPlayer__sub_800DC434((self), 4);
    lbl_805D526C = TObjPlayer__sub_800DC420((void *)self, 0);
    lbl_805D5270 = TObjPlayer__sub_800DC420((void *)self, 1);
}

#pragma push
#pragma opt_common_subs off
// pool_data off: find_open_direction reaches its two Vecs and the angle double with a lis/addi each.
#pragma pool_data off
// The probe step and the zeroed offset find_open_direction rotates around the drago.
const Vec find_open_direction_probe_step = { 200.0f, 0.0f, 0.0f };
const Vec find_open_direction_zero_vec = { 0.0f, 0.0f, 0.0f };
void TObjEneNanoDrago::find_open_direction(Vec *direction) {
    s32 ang;
    s32 best;
    s32 i;
    f32 bias;
    f32 bestv;
    f32 d;
    CsnHit *h;
    ang = (s32)(RADIANS_TO_ANGLE * atan2_float(direction->x, direction->z));
    bestv = 0.0f;
    best = ang;
    push_matrix_from(&identity_matrix);
    {
        Vec v = find_open_direction_probe_step;
        rotate_matrix_y(0, ang);
        i = 0;
        bias = 20.0f;
        for (; i < 3; i++) {
            matrix_mult_vec(0, &v, &moveDestination);
            vec3_add_to(&moveDestination, &body_center);
            h = csnVector(&body_center, &moveDestination, -1);
            if (h == NULL) {
                pop_matrix();
                return;
            }
            d = vec_xz_distance((Vec *)(&position), &h->contact->point) - bias;
            if (bestv < d) {
                bestv = d;
                best = ang;
            }
            rotate_matrix_y(0, 0x5555);
            ang += 0x5555;
        }
    }
    pop_matrix();
    push_matrix_from(&identity_matrix);
    {
        Vec v2 = find_open_direction_zero_vec;
        v2.x = bestv;
        rotate_matrix_y(0, best);
        matrix_mult_vec(0, &v2, &moveDestination);
        vec3_add_to(&moveDestination, &body_center);
        pop_matrix();
    }
}
#pragma pop
s32 TObjEneNanoDrago::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}
