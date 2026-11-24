#include "pso/system/memory.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/merilllia/TObjEneMerillLia.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"


#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/technique/TTecKafun.h"

#include "pso/system/vector.h"

#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/effect/GroundContactSound.h"
#include "pso/math/ScratchVectors.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TPlyDispData.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

// TObjPlayer member defined in TObjControl.cpp with no declaration in TObjPlayer.h.

player_stats **merill_lia_rock_stats_table;
AttackParams **merill_lia_rock_buffer;
ActorParamBlock **merill_lia_rock_aux_buffer;
MerillLiaBehaviorParams **merill_lia_behavior_params;
BmlResource *merill_lia_bml_resource;

const char *merill_lia_model_names[3] = {
    "re8_b_beast_wola_body.nj", "re8_b_srbeast_wola_body.nj", 0,
};
const char *merill_lia_motion_names[13] = {
    "appear_re8_b_beast_wola_body.njm", "atk_a_re8_b_beast_wola_body.njm", "atk_b_re8_b_beast_wola_body.njm", "damage_re8_b_beast_wola_body.njm",
    "dead_re8_b_beast_wola_body.njm", "stand_re8_b_beast_wola_body.njm", "wait_re8_b_beast_wola_body.njm", "wakeup_re8_b_beast_wola_body.njm",
    "walk_re8_b_beast_wola_body.njm", "run_bm1_s_wala_body.njm", "kahun_re8_b_beast_wola_body.njm", "umari_re8_b_beast_wola_body.njm",
    0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_resource_descriptor = {
    "bm_ene_re8_merill_lia.bml", merill_lia_model_names, merill_lia_motion_names, 2, 12,
};
const char *merill_lia_low_model_names[3] = {
    "lo_re8_b_beast_wola_body.nj", "lo_re8_b_srbeast_wola_body.nj", 0,
};
const char *merill_lia_low_motion_names[13] = {
    "appear_re8_b_beast_wola_body.njm", "atk_a_re8_b_beast_wola_body.njm", "atk_b_re8_b_beast_wola_body.njm", "damage_re8_b_beast_wola_body.njm",
    "dead_re8_b_beast_wola_body.njm", "stand_re8_b_beast_wola_body.njm", "wait_re8_b_beast_wola_body.njm", "wakeup_re8_b_beast_wola_body.njm",
    "walk_re8_b_beast_wola_body.njm", "run_bm1_s_wala_body.njm", "kahun_re8_b_beast_wola_body.njm", "umari_re8_b_beast_wola_body.njm",
    0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_low_resource_descriptor = {
    "bm_ene_re8_merill_lia_low.bml", merill_lia_low_model_names, merill_lia_low_motion_names, 2, 12,
};
const char *merill_lia_class_name = "TObjEneMerillLia";
TObjMotionAction merill_lia_action_table[14] = {
    {1, 0, 5, 0.6f, 1},
    {1, 1, 6, 0.8f, 1},
    {1, 2, 8, 0.6f, 1},
    {2, 0, 1, 0.8f, 4},
    {2, 0, 2, 1.0f, 4},
    {1, 0, 9, 1.0f, 1},
    {2, 0, 3, 0.8f, 8},
    {2, 0, 7, 0.8f, 0x20},
    {3, 0, 4, 0.6f, 0x10},
    {3, 0, 4, 0.6f, 0x10},
    {2, 0, 5, 0.6f, 0x20},
    {2, 0, 0, 0.5f, 0x20},
    {2, 0, 0xA, 0.7f, 4},
    {2, 1, 0xB, 0.6f, 0x20},
};
BeastMovementParams merill_lia_movement_params[3] = {
    {225.0f, 0.4f, 0x400, {0, 0x1E0000, 1, 0}},
    {250.0f, 0.55f, 0x400, {0, 0x1E0000, 1, 0}},
    {300.0f, 0.7f, 0x400, {0, 0x1E0000, 1, 0}},
};
CollisionBody merill_lia_collision_bodies[3] = {
    {{0.0f, 7.5f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 7.5f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 10.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

// This unit is built with -inline off,deferred: CW then emits .text in reverse definition order, so the
// functions below are defined from the last one in the DOL (select_model_record) back to the first (run_demo_task).
void TObjEneMerillLia::select_model_record(s32 i) {
    model = merill_lia_bml_resource->models[i].model;
    texlist = merill_lia_bml_resource->models[i].texlist;
}

TObjEneMerillLia::TObjEneMerillLia(TObject *parent, void *setData) : TUnk_80493450(parent) {
    m_name = merill_lia_class_name;
    apply_set_data(setData);
    init_behavior_params();
    init_position_vectors();
    subtype = variant;
    select_subtype();
    select_model_record(variant);
    action_table = merill_lia_action_table;
    set_action_table(action_table);
    motion_list = merill_lia_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &merill_lia_collision_bodies[subtype], 1);
    bind_enemy_combat_stats(merill_lia_rock_stats_table[subtype], merill_lia_rock_buffer[subtype], merill_lia_rock_aux_buffer[subtype]);
    movementParameters = &merill_lia_movement_params[subtype];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    register_object_by_id();
    m_2ac = (s32)(182.04445f * (360.0f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    retreat_timer = 0;
    pad_376 = 0;
    in_group = 0;
    child_count = 0;
    add_flags_2e4(2);
    set_actor_flags(0x40000);
    corpse_offset_y = 0.0f;
    far_move_speed = merill_lia_behavior_params[subtype]->far_move_speed;
    far_anim_speed = merill_lia_behavior_params[subtype]->far_anim_speed;
    near_move_speed = merill_lia_behavior_params[subtype]->near_move_speed;
    near_anim_speed = merill_lia_behavior_params[subtype]->near_anim_speed;
    retreat_speed = merill_lia_behavior_params[subtype]->retreat_speed;
    react_hp_ratio = merill_lia_behavior_params[subtype]->react_hp_percent / 100.0f;
    appearing = 1;
    mode = 0xD;
    requested_action = 1;
    clear_lobby_object_state();
}

TObjEneMerillLia::~TObjEneMerillLia() {
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneMerillLia::load_resources() {
    s32 i;
    BmlResource *res;

    if (is_split_screen() != 0) {
        res = new BmlResource(1, &bm_ene_re8_merill_lia_low_resource_descriptor, 0, 0, NULL);
        merill_lia_bml_resource = res;
    } else {
        res = new BmlResource(1, &bm_ene_re8_merill_lia_resource_descriptor, 0, 0, NULL);
        merill_lia_bml_resource = res;
    }
    merill_lia_collision_bodies[0].radius = 7.0f;
    merill_lia_collision_bodies[1].radius = 7.0f;
    merill_lia_collision_bodies[2].radius = 8.0f;
    merill_lia_rock_stats_table = static_cast<player_stats **>(mem_alloc(2 * sizeof(*merill_lia_rock_stats_table)));
    merill_lia_rock_buffer = static_cast<AttackParams **>(mem_alloc(2 * sizeof(*merill_lia_rock_buffer)));
    merill_lia_rock_aux_buffer = static_cast<ActorParamBlock **>(mem_alloc(2 * sizeof(*merill_lia_rock_aux_buffer)));
    merill_lia_behavior_params = (MerillLiaBehaviorParams **)mem_alloc(8);
    merill_lia_rock_stats_table[0] = TLobby::register_boss(75);
    merill_lia_rock_stats_table[1] = TLobby::register_boss(76);
    merill_lia_rock_buffer[0] = TLobby::dispatch_shared_handler_b(78);
    merill_lia_rock_buffer[1] = TLobby::dispatch_shared_handler_b(79);
    merill_lia_rock_aux_buffer[0] = TLobby::register_object(74);
    merill_lia_rock_aux_buffer[1] = TLobby::register_object(75);
    merill_lia_behavior_params[0] = (MerillLiaBehaviorParams *)TLobby::dispatch_shared_handler_a(74);
    merill_lia_behavior_params[1] = (MerillLiaBehaviorParams *)TLobby::dispatch_shared_handler_a(75);
    {
        s16 ids[2] = {44, 46};
        NpcAnimationBinding motions = { NULL, merill_lia_action_table, 0, 2, 12 };
        motions.motions = merill_lia_bml_resource->motions;
        for (i = 0; i < 2; i++) {
            TObjNpcEnemy::register_animated_chunk(ids[i], merill_lia_bml_resource->models[i].model,
                merill_lia_bml_resource->models[i].texlist, &motions, merill_lia_collision_bodies[i].radius, 0.0f);
        }
    }
}
#pragma pop

void TObjEneMerillLia::free_resources() {
    if (merill_lia_rock_stats_table != NULL) {
        mem_free(merill_lia_rock_stats_table);
        merill_lia_rock_stats_table = NULL;
    }
    if (merill_lia_rock_buffer != NULL) {
        mem_free(merill_lia_rock_buffer);
        merill_lia_rock_buffer = NULL;
    }
    if (merill_lia_rock_aux_buffer != NULL) {
        mem_free(merill_lia_rock_aux_buffer);
        merill_lia_rock_aux_buffer = NULL;
    }
    if (merill_lia_behavior_params != NULL) {
        mem_free(merill_lia_behavior_params);
        merill_lia_behavior_params = NULL;
    }
    if (merill_lia_bml_resource != NULL) {
        delete merill_lia_bml_resource;
        merill_lia_bml_resource = NULL;
    }
}

void *TObjEneMerillLia::create(void *setData) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneMerillLia(parent, setData);
}

void TObjEneMerillLia::run_task() {
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
        break;
    case 4:
        beast_update_group_chase();
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
        update_kafun_attack();
        break;
    case 11:
        update_burrow();
        break;
    case 12:
        search_target();
        break;
    case 13:
        update_fade_in();
        break;
    }
    update_prev_position();
    copy_position();
    submit_cursor_candidate(this, -1);
    frame_timer += 1.0f;
}

void TObjEneMerillLia::select_hurt_action() {
    if (random_ratio() <= retreat_chance) {
        start_retreat();
        return;
    }
    if (random_ratio() <= kafun_chance) {
        start_kafun_attack();
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneMerillLia::init_behavior_params() {
    retreat_frames = (s16)((s32)parameters[3] + 300);
    retreat_chance = parameters[0] - 0.2f;
    if (retreat_chance < 0.0f) {
        retreat_chance = 0.0f;
    }
    kafun_chance = parameters[2] - 0.2f;
    if (kafun_chance < 0.0f) {
        kafun_chance = 0.0f;
    }
    notice_range = 100.0f + parameters[4];
    if (notice_range < 15.0f) {
        notice_range = 15.0f;
    }
}
#pragma pop

void TObjEneMerillLia::render() {
    Vec scale;
    s32 visible;
    s16 state;
    s32 detail;
    s32 fading;

    detail = classify_actor_view_detail(200.0f, 400.0f, 30.0f);
    if (detail != 0) {
        saved_model_render_flags = model_render_flags;
        select_actor_lighting(this);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        translate_matrix(0, 0.0f, corpse_offset_y, 0.0f);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            TObjPlayer::toggle_particle_effect();
            visible = 1;
            fading = 0;
            if (mode == 0xD) {
                fading = 1;
                visible = fade.has_visible_opacity();
            }
            if (fading != 0) {
                fade.set_flags_and_apply_damage_color();
                if (defer_render() != 0) {
                    visible = 0;
                }
            }
            if (visible != 0) {
                if (detail == 1) {
                    set_motion_packed_rotation();
                    draw();
                    clear_motion_packed_rotation();
                } else {
                    set_motion_packed_rotation();
                    draw_motion_model();
                    clear_motion_packed_rotation();
                }
            }
            TParticleCtrl::end_effect_render();
            if (fading != 0) {
                fade.clear_flag_and_notify();
            }
        }
        pop_matrix();
        restore_scene_lighting();
        state = mode;
        if (state >= 0xA || state < 8) {
            scale.x = 1.5f;
            scale.y = 1.0f;
            scale.z = 2.0f;
            draw_ground_shadow(&scale, 0);
        }
    }
}

void TObjEneMerillLia::beast_update_approach() {
    Vec dest;
    f32 r;
    switch (phase) {
    case 0:
        apply_actor_gravity(this, NULL, 0.0f);
        advance_animation();
        if (action_flags != 0x20) {
            phase = 1;
            requested_action = 2;
        }
        break;
    default:
        spawn_ground_effect();
        if (target != NULL) {
            if (test_elt_flag(0, 0x300000) != 0) {
                if (home_chase_frames++ < 60.0f) {
                    VecCopy(&dest, &home_position);
                } else {
                    VecCopy(&dest, &((TObjChara *)target)->body_center);
                }
            } else {
                home_chase_frames = 0;
                VecCopy(&dest, &((TObjChara *)target)->body_center);
            }
            update_target_near_flag();
            select_move_speed();
            advance_animation();
            enemy_move_toward(this, ((BeastMovementParams *)movementParameters)->turnSpeed, dest, 0, move_speed);
            if (targetId == 0xFFFF) {
                if (horizontal_distance_squared(&move_destination, &position) < (r = move_speed + bodies->radius) * r ||
                    150.0f < (f32)(*(s32 *)&m_2ac)++) {
                    target = NULL;
                    m_2ac = 0;
                }
            }
        }
        break;
    }
    update_collisions();
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x200000);
}

void TObjEneMerillLia::beast_update_appear() {
    switch (phase) {
    case 0:
    default:
        if (appearing != 1) {
            phase = 2;
        } else {
            phase = 1;
            requested_action = 0xB;
            set_indexed_flags(0, 0xA000000);
            set_actor_flags(0x4000000);
            play_hurt_sound();
        }
        break;
    case 1:
        spawn_ground_effect();
        if (is_passing_frame(10.0f) != 0) {
            play_dig_sound();
        }
        if (action_flags != 0x20) {
            phase = 2;
            appearing = 0;
            requested_action = 0;
            clear_player_status_flag(0, 0xA000000);
            clear_actor_flags(0x4000000);
        }
        break;
    case 2:
        targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
        mode = 1;
        break;
    }
    advance_animation();
}

#pragma push
#pragma fp_contract on
void TObjEneMerillLia::beast_update_group_chase() {
    Vec save;
    Vec to;
    Vec d;
    f32 dist;
    advance_animation();
    switch (phase) {
    case 0:
        phase = 1;
        play_group_chase_sound();
        break;
    case 1:
        if (target != NULL) {
            spawn_ground_effect();
            save.x = position.x;
            save.y = position.y;
            save.z = position.z;
            if (retreat_speed <= 0.0f) {
                dist = enemy_backstep_from_point(this, ((TObjChara *)target)->body_center, far_move_speed);
            } else {
                dist = enemy_backstep_from_point(this, ((TObjChara *)target)->body_center, retreat_speed);
            }
            turn_toward_direction(((BeastMovementParams *)movementParameters)->turnSpeed, &velocity);
            retreat_timer--;
            if (dist < (far_move_speed + bodies->radius) * (far_move_speed + bodies->radius) || retreat_timer < 0) {
                phase = 2;
                retreat_timer = 0;
            }
            update_collisions();
            update_enemy_collision_flags();
            if (bodies->flags & 0x380000) {
                phase = 2;
                retreat_timer = 0;
                break;
            }
            d.x = position.x - save.x;
            d.y = position.y - save.y;
            d.z = position.z - save.z;
            normalize_vector(&d);
            to.x = 30.0f * d.x + position.x;
            to.y = 30.0f * d.y + position.y;
            to.z = 30.0f * d.z + position.z;
            if (csnVector(&save, &to, 0x88E0) != NULL) {
                phase = 2;
                retreat_timer = 0;
            }
            break;
        }
        if (is_actor_cadence_frame(0x1E) != 0) {
            targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
        }
        if (targetId < 0x1000) {
            TObjPlayer *p = get_player_by_client_id(targetId);
            if (p != NULL && p->get_floor() == get_current_floor()) {
                target = p;
                break;
            }
            target = NULL;
            start_burrow();
            break;
        }
        target = NULL;
        start_burrow();
        break;
    case 2:
        clear_actor_flags(0x1000);
        if (is_actor_cadence_frame(0x1E) != 0) {
            targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
        }
        if (targetId < 0x1000) {
            TObjPlayer *p = get_player_by_client_id(targetId);
            if (p != NULL && p->get_floor() == get_current_floor() &&
                xz_distance_squared(&p->position, &position) < 10000.0f) {
                mode = 1;
                phase = 0;
                requested_action = 0xA;
                clear_actor_flags(0x4040000);
                clear_player_status_flag(0, 0xA000000);
                break;
            }
            start_burrow();
        } else {
            start_burrow();
        }
        break;
    }
    update_collisions();
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TObjEneMerillLia::beast_idle_update() {
    update_target_near_flag();
    select_move_speed();
    advance_animation();
    if (phase != 1) {
        phase = 1;
        link_into_group_chain();
        in_group = has_group();
    }
    child_count = countChildren();
    {
        TUnk_80493450 *other = (TUnk_80493450 *)next;
        if (other != NULL) {
            s32 diff = other->child_count - child_count;
            if (diff > 1) {
                link_chain_nodes(other, this);
                child_count++;
                other->child_count--;
            } else if (diff < -1) {
                link_chain_nodes(this, other);
                child_count--;
                other->child_count++;
            }
        }
    }
    {
    f32 dist = horizontal_distance_squared(&position, &home_position);
    f32 r = parameters[1] + (((BeastMovementParams *)movementParameters)->wanderSpeed + bodies->radius);
    if (r * r < dist) {
        Vec *d;
        Vec *v;
        s32 ang;
        VecCopy(&move_destination, &home_position);
        VecCopy(&move_origin, &body_center);
        VecCopy(&prev_position, &position);
        VecCopy(&scratch_vec, &home_position);
        subtract_vector(&scratch_vec, &position);
        d = &scratch_vec;
        ang = (s32)(10430.38043493439 * atan2_float(d->x, d->z));
        v = &lbl_8050BF00;
        v->x = v->y = 0.0f;
        v->z = move_speed;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, ang);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &position);
        if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
            requested_action = 2;
            VecCopy(&position, &lbl_8050BF00);
            rotation_y = approach_angle_limited(rotation_y, ang, ((BeastMovementParams *)movementParameters)->turnSpeed);
        } else {
            f32 rr = fabs_float(d->z);
            if (fabs_float(scratch_vec.x) < rr) {
                ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
            } else {
                ang = (s32)(10430.38043493439 * atan2_float(0.0f, d->z));
            }
            v->y = 0.0f;
            lbl_8050BF00.x = 0.0f;
            v->z = move_speed;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, ang);
            rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
            pop_matrices(1);
            vec3_add_to(&lbl_8050BF00, &position);
            if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
                requested_action = 2;
                VecCopy(&position, &lbl_8050BF00);
                rotation_y = approach_angle_limited(rotation_y, ang, ((BeastMovementParams *)movementParameters)->turnSpeed);
            } else {
                s32 ang2;
                rr = fabs_float(d->z);
                if (fabs_float(scratch_vec.x) < rr) {
                    ang2 = (s32)(10430.38043493439 * atan2_float(0.0f, d->z));
                } else {
                    ang2 = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
                }
                v->y = 0.0f;
                lbl_8050BF00.x = 0.0f;
                v->z = move_speed;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang2);
                rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                pop_matrices(1);
                vec3_add_to(&lbl_8050BF00, &position);
                if (project_actor_to_ground(this, &lbl_8050BF00, 0) == 1) {
                    requested_action = 2;
                    VecCopy(&position, &lbl_8050BF00);
                    rotation_y = approach_angle_limited(rotation_y, ang2, ((BeastMovementParams *)movementParameters)->turnSpeed);
                } else {
                    requested_action = 2;
                }
            }
        }
    } else if (child_count == 0 && 0.0f < parameters[1]) {
        f32 w;
        requested_action = 2;
        w = parameters[1];
        enemy_wander_home(((BeastMovementParams *)movementParameters)->wanderSpeed, w, w, ((BeastMovementParams *)movementParameters)->turnSpeed);
    } else {
        start_burrow();
    }
    }
    if (test_actor_flags(0x800000) == 0) {
        apply_actor_gravity(this, NULL, 0.0f);
    }
    refresh_collision_body_centers();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    clear_actor_flags(0x04240000);
    clear_player_status_flag(0, 0x0A000000);
}
#pragma pop

void TObjEneMerillLia::beast_update_hurt() {
    Vec pos;

    advance_animation();
    VecCopy(&pos, &body_center);
    scratch_vec.y = 0.0f;
    scratch_vec.x = 0.0f;
    scratch_vec.z = get_collision_body_radius(0);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, -rotation_y);
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&pos, &scratch_vec);
    pos.x = pos.x + velocity.x;
    pos.z = pos.z + velocity.z;
    if (check_path_obstructed(this, &pos) == 0) {
        move_with_wall_slide(this);
        velocity.x *= 0.5f;
        velocity.z *= 0.5f;
    } else {
        velocity.z = 0.0f;
        velocity.x = 0.0f;
    }
    update_collisions();
    update_enemy_collision_flags();
    if (is_passing_frame(0.0f) != 0) {
        play_hurt_sound();
    }
    if (action_flags != 8) {
        clear_actor_flags(0x600);
        clear_player_status_flag(0, 0x04000000);
        if ((f32)hp <= (f32)hpmax * react_hp_ratio) {
            select_hurt_action();
        }
        referenceHp = hp;
    }
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneMerillLia::update_kafun_attack() {
    Vec pos;
    advance_animation();
    switch (phase) {
    default:
    case 0:
        phase = 1;
        requested_action = 0xC;
        set_actor_flags(0x200000);
        clear_actor_flags(0x04040000);
        clear_player_status_flag(0, 0x0A000000);
        break;
    case 1:
        if (is_passing_frame(13.0f) != 0) {
            advance_animation();
            push_matrix_from(identity_matrix);
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            calc_joint_matrices(13.0f);
            pop_matrix();
            push_matrix_from(anim_model_matrix_array[23]);
            {
                Vec offset = {0.0f, 0.0f, 0.0f};
                matrix_mult_vec(0, &offset, &pos);
            }
            pop_matrix();
            TTecKafun::create((saddr)this, (saddr)&pos, 0xF, 0xD3, get_clamped_level(), merill_lia_behavior_params[subtype]->kafun_value, 20.0f);
            play_kafun_sound();
        }
        if (action_flags != 4) {
            phase = 2;
            requested_action = 0;
            timer = 0xF;
        }
        break;
    case 2:
        timer--;
        if (timer < 0) {
            clear_actor_flags(0x200000);
            timer = 0;
            if (random_ratio() <= retreat_chance) {
                start_retreat();
            } else {
                mode = 1;
                phase = 0;
                set_actor_flags(0x04040000);
                set_indexed_flags(0, 0x0A000000);
            }
        }
        break;
    }
    update_collisions();
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneMerillLia::update_burrow() {
    advance_animation();
    switch (phase) {
    case 0:
    default:
        if (appearing == 1) {
            phase = 2;
        } else {
            phase = 1;
            requested_action = 0xD;
            set_indexed_flags(0, 0x0A000000);
            set_actor_flags(0x04000000);
            play_dig_sound();
        }
        break;
    case 1:
        spawn_ground_effect();
        if (action_flags != 0x20) {
            phase = 2;
            appearing = 1;
            clear_player_status_flag(0, 0x0A000000);
            clear_actor_flags(0x04040000);
        }
        break;
    case 2:
        mode = 0xC;
        requested_action = 1;
        break;
    }
    update_collisions();
    update_enemy_collision_flags();
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TObjEneMerillLia::search_target() {
    TObjPlayer *p;
    s32 floor;
    targetId = find_nearest_visible_player(this, NULL, ((BeastMovementParams *)movementParameters)->detectionRadius);
    if (targetId < 0x1000) {
        p = get_player_by_client_id(targetId);
        if (p != NULL) {
            s32 player_floor;
            floor = get_current_floor();
            player_floor = p->get_floor();
            if (player_floor == floor) {
                if (xz_distance_squared(&p->position, &position) < notice_range * notice_range) {
                    target = p;
                    mode = 0;
                    phase = 0;
                }
            }
        }
    }
    advance_animation();
}

void TObjEneMerillLia::update_fade_in() {
    switch (phase) {
    case 0:
    default:
        phase = 1;
        requested_action = 1;
        fade.start_fade_in();
        play_area_sound_effect(&position);
        break;
    case 1:
        spawn_ground_effect();
        if (fade.advance_toward_max() != 0) {
            phase = 2;
        }
        break;
    case 2:
        mode = 12;
        break;
    }
    advance_animation();
}

void TObjEneMerillLia::start_kafun_attack() {
    mode = 0xA;
    phase = 0;
    set_actor_flags(0x200000);
    clear_actor_flags(0x04040000);
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::start_retreat() {
    mode = 4;
    phase = 0;
    retreat_timer = retreat_frames;
    clear_actor_flags(0x04240000);
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::start_burrow() {
    mode = 0xB;
    phase = 0;
    target = NULL;
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::run_idle_action() {
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 11:
    case 12:
    case 13:
        break;
    default:
        if (appearing != 0) {
            mode = 0;
        } else {
            mode = 1;
        }
        phase = 0;
        set_actor_flags(0x04040000);
        set_indexed_flags(0, 0x0A000000);
        break;
    }
}

void TObjEneMerillLia::run_attack_action() {
    switch (mode) {
    case 0:
    case 2:
    case 4:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 10;
        }
        clear_actor_flags(0x4040000);
        clear_player_status_flag(0, 0xA000000);
        break;
    default:
        mode = 5;
        phase = 1;
        if (0.5f < random_ratio()) {
            requested_action = 3;
        } else {
            requested_action = 4;
        }
        set_actor_flags(0x200000);
        clear_actor_flags(0x4040000);
        clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::run_move_action() {
    if (test_actor_flags(0x1000) != 0) {
        mode = 4;
    }
    switch (mode) {
    case 0:
    case 2:
    case 3:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        phase = 0;
        if (children == NULL) {
            mode = 3;
            requested_action = 7;
        } else {
            mode = 2;
            requested_action = 10;
        }
        clear_actor_flags(0x4040000);
        clear_player_status_flag(0, 0xA000000);
        break;
    case 4:
        requested_action = 5;
        break;
    default:
        mode = 3;
        phase = 1;
        requested_action = 2;
        clear_actor_flags(0x4040000);
        clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::select_subtype() {
    if ((s32)subtype < 0) {
        subtype = 0;
    } else if ((s32)subtype > 1) {
        subtype = 1;
    }
    switch (subtype) {
    case 1:
        variant = 1;
        set_param(0x35);
        break;
    default:
        variant = 0;
        set_param(0x34);
        break;
    }
}

s32 TObjEneMerillLia::get_clamped_level() {
    player_stats *p = stat_block;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

void TObjEneMerillLia::update_attack_trail() {  }

void TObjEneMerillLia::spawn_death_effect() {
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * stat_block->proportions;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrix();
    vec3_add_to(&stack, &position);
    ::spawn_ground_effect(&stack, 0x23);
    TObjPlayer__sub_800D92BC(&stack, 0xF);
}

void TObjEneMerillLia::play_dig_sound() {
    play_sound_effect(remap_sound_for_area(0x3B206), &position, 0, 0);
}

void TObjEneMerillLia::play_attack_sound() {
    play_sound_effect(remap_sound_for_area(0x3AB02), &position, 0, 0);
}

void TObjEneMerillLia::play_hurt_sound() {
    play_sound_effect(remap_sound_for_area(0x3B201), &position, 0, 0);
}

void TObjEneMerillLia::play_death_sound() {
    play_sound_effect(remap_sound_for_area(0x3AD00), &position, 0, 0);
}

void TObjEneMerillLia::play_group_chase_sound() {
    play_sound_effect(remap_sound_for_area(0x3B205), &position, 0, 0);
}

void TObjEneMerillLia::play_kafun_sound() {
    play_sound_effect(remap_sound_for_area(0x3AD04), &position, 0, 0);
}

void TObjEneMerillLia::spawn_ground_effect() {
    Vec pos;
    TParticleCtrl *particle;
    CsnHit *hit;
    VecCopy(&pos, &position);
    pos.y += 15.0f;
    hit = csnVectorUnder(&pos, ground_candidates.groups, 5);
    if ((hit != NULL) && (hit->hit_mask & 4)) {
        if (((s32)((f32)actor_frame_tick * (3.0517578125e-05f * (f32)rand())) % 5) == 0) {
            particle = spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (particle != NULL) {
                attach_particle_model(particle, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
        }
        if ((is_passing_frame(7.0f) != 0) || (is_passing_frame(22.0f) != 0)) {
            play_ground_landing_sound(&position);
        }
    }
}

void TObjEneMerillLia::run_demo_task() {  }
