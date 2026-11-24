#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/epsilon/TObjEneEpsilonBody.h"
#include "pso/render/render_util.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/enemy/EnemyTargetCandidate.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/TUnk_80484840.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/model_render_state.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma inline_depth(1)
// Joint index per guard slot and the joint-local point the guard angle is measured from (update_guard_anchor).
// 20 rows of per-guard attack flags (update_attack_pattern).
// Guard slot visiting order {2, 0, 1, 3} (select_slot_target).
// Per-colour value {1, 2, 3, 5} (get_table_value_by_index).
// Per-colour value {9, 7, 10, 11} (get_immune_special_kind).


player_stats *epsilon_body_boss_stat_handle;
AttackParams *epsilon_body_shared_handler_b;
ActorParamBlock *epsilon_body_registered_object_handle;
EpsilonBodySharedParams *epsilon_body_shared_params;
extern "C" {
void draw_line_list(VoloptLineList *, s32, u32);
}
s32 epsilon_guard_camera_sample_phase;
s32 *epsilon_guard_angle_sample_write_ptr;
Vec *epsilon_guard_camera_sample_read_ptr;
Vec *epsilon_guard_camera_sample_end_ptr;
s16 obj_getS16_118(u8 *p);
extern TObject *tl_04;

Vec epsilon_body_node_origin;
Vec epsilon_body_debug_line_points[2];


// The body's action table, movement parameters and collision bodies.
TObjMotionAction epsilon_body_action_table[2] = {
    {1, 0, 0, 0.3f, 0},
    {1, 1, 1, 0.6f, 0},
};
TObjEneEpsilonMovement epsilon_body_movement_params = {
    150.0f, 0.5555555f, 0x400, { 0x1E0000, 0, 1, 0 },
};
CollisionBody epsilon_body_collision_bodies[2] = {
    {{0.0f, 12.0f, 0.0f}, 12.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 20.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
VoloptLineColor epsilon_body_debug_line_colors[2] = {{0x80, 0xFF, 0x40, 0x40}, {0x80, 0xFF, 0x40, 0x40}};
VoloptLineList TObjEneEpsilonGuard__debug_line_list = {epsilon_body_debug_line_points, epsilon_body_debug_line_colors, 0, 4};

const BreakUpParamRow epsilon_guard_destroy_breakup_params = { 0x14, 0.05f, 1.2f, 0.9f, 0.12f, 0.55f, 0.5f };
// Body colour per color_index, copied into the guard parts.
const NJS_ARGB epsilon_body_colors[4] = {
    {255.0f, 255.0f, 0.0f, 0.0f},
    {255.0f, 0.0f, 0.0f, 255.0f},
    {255.0f, 255.0f, 255.0f, 0.0f},
    {255.0f, 255.0f, 0.0f, 255.0f},
};
const char *TObjEneEpsilonBody__class_name = "TObjEneEpsilonBody";


// Writes the body's colour into the material colour bytes of the nine guard parts.
void TObjEneEpsilonBody::set_guard_part_colors(NJS_ARGB *color) {
    s32 i;
    for (i = 0; i < 9; i++) {
        epsilon_guard_part_color_table[i][7] = color->r;
        epsilon_guard_part_color_table[i][4] = color->g;
        epsilon_guard_part_color_table[i][5] = color->b;
    }
}

TObjEneEpsilonBody::TObjEneEpsilonBody(TObject *parent, void *set_data) : TObjEneEpsilon(parent) {
    s32 i;
    m_name = TObjEneEpsilonBody__class_name;
    invoke_initialization_hook(set_data);
    init_params();
    set_param(0x54);
    init_position_vectors();
    init_model(epsilon_body_collision_bodies, 2);
    flags = 0;
    flags |= 2;
    set_guard_state();
    texlist = get_bml_texlist(epsilon_bml_resource, 0);
    set_action_table(epsilon_body_action_table);
    set_motion_list(epsilon_bml_resource->motions);
    set_animation(requested_action);
    set_requested_action(requested_action);
    reset_hp(epsilon_body_boss_stat_handle, epsilon_body_shared_handler_b, epsilon_body_registered_object_handle);
    set_state_flag_4();
    movementParameters = &epsilon_body_movement_params;
    wall_reach = 10.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    color_index = (s32)(4.0f * random_ratio()) % 4;
    copy_argb(&color, (NJS_ARGB *)&epsilon_body_colors[color_index]);
    fire_phase_timer = fire_phase_frames;
    guard_phase_timer = guard_phase_frames;
    attack_pattern_timer = epsilon_body_shared_params->attack_pattern_frames;
    action_step = 0;
    action_timer = 0;
    fire_timer = 0;
    target_player = 0;
    target_slot = 0;
    effect_scale = 0.0f;
    fire_position.x = 0.0f;
    fire_position.y = 0.0f;
    fire_position.z = 0.0f;
    target_position.x = 0.0f;
    target_position.y = 0.0f;
    target_position.z = 0.0f;
    for (i = 0; i < 4; i++) {
        TObjEneEpsilonGuard *guard = TObjEneEpsilonGuard::create(this, (u16)(entity_id + 1 + i), set_index + 1 + i, &position, rotation_y);
        if (guard != NULL) {
            guard_ids[i] = guard->get_entity_id();
        }
        VecCopy(&guard_position[i], &position);
        guard_rotation_y[i] = rotation_y;
    }
    mode = 0;
    dispatch_action(mode, 4);
    for (s32 j = 0; j < 4; j++) {
        fades[j].activate_and_dispatch();
    }
    warp_emitter = NULL;
    emitter = NULL;
    sub_800F5874(0x3F);
}

TObjEneEpsilonBody::~TObjEneEpsilonBody() {
    s32 i;
    free_collision_body_parts(this);
    if (warp_emitter != NULL) {
        warp_emitter->queue_destruction();
        warp_emitter = NULL;
    }
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    for (i = 0; i < 4; i++) {
        if (guard_ids[i] != 0) {
            TObjCollidable *guard = (TObjCollidable *)find_entity_by_id(guard_ids[i]);
            if (guard != NULL) {
                guard->queue_destruction();
            }
        }
    }
}

void *create_TObjEneEpsilonBody(void *set_data) {
    return new TObjEneEpsilonBody(tl_04, set_data);
}

void TObjEneEpsilonBody::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    if (update_status_effects() != 4) {
        update_guard_flag();
        update_action_state();
    } else if (mode == 1) {
        transition_enemy_state(0);
    }
    if (mode != 9) {
        play_persistent_sound(0x4003AD43, this, &position, 0, 0);
    }
    update_body_colliders();
    update_position();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneEpsilonBody::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_wait_state(reason);
        return;
    case 1:
        handle_fade_in_state(reason);
        return;
    case 2:
        handle_fire_state(reason);
        return;
    case 3:
        handle_guard_action_state(reason);
        return;
    case 4:
        action(reason);
        return;
    case 5:
        handle_pre_warp_state(reason);
        return;
    case 6:
        handle_warp_state(reason);
        return;
    case 7:
        handle_return_home_state(reason);
        return;
    case 8:
        update_fade(reason);
        return;
    case 9:
        action_destroy(reason);
    default:
        return;
    }
}
void TObjEneEpsilonBody::refresh_target() {  }
void TObjEneEpsilonBody::run_death_reaction() { if (this->mode != 9) { transition_enemy_state(9); } }
void TObjEneEpsilonBody::run_hit_reaction() {
    if ((s16) this->mode != 8) {
        if (!(flags & 2) && !(flags & 0x40)) {
            transition_enemy_state(8);
        }
    }
}

void TObjEneEpsilonBody::run_miss_reaction() {  }

void TObjEneEpsilonBody::update_position() {
    body_center.x = position.x;
    body_center.y = 24.0f + position.y;
    body_center.z = position.z;
    VecCopy(&center, &body_center);
}
void TObjEneEpsilonBody::update_body_colliders() {  }

void TObjEneEpsilonBody::check_collisions() {
    TObjEneDD::check_collisions();
    update_position();
}
#pragma push
#pragma opt_common_subs off
void TObjEneEpsilonBody::init_params() {
    move_speed = 0.5f + parameters[0];
    if (move_speed < 0.0f) {
        move_speed = 0.0f;
    }
    turn_step = 512.0f + parameters[1];
    if (move_speed <= 0.0f) {
        move_speed = 0.0f;
    }
    fire_phase_frames = 20.0f + parameters[2];
    if (fire_phase_frames < 5) {
        fire_phase_frames = 5;
    }
    fire_phase_frames *= 30.0f;
    guard_phase_frames = 20.0f + parameters[3];
    if (guard_phase_frames < 5) {
        guard_phase_frames = 5;
    }
    guard_phase_frames *= 30.0f;
}
#pragma pop

void TObjEneEpsilonBody::update_guard_flag() {
    if (update_linked_position(400.0f) == 1) {
        this->flags = (s32) (this->flags & 0xFFFFFF7F);
        return;
    }
    this->flags = (s32) (this->flags | 0x80);
}

void TObjEneEpsilonBody::run_demo_task() {  }

void TObjEneEpsilonBody::handle_wait_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(0);
        set_intangible();
        flags |= 0x43;
        flags &= ~0x200;
        set_guard_state();
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        fire_phase_timer = fire_phase_frames;
        guard_phase_timer = guard_phase_frames;
        return;
    case 3:
        if (!(flags & 0x80)) {
            transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneEpsilonBody::handle_fade_in_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(0);
        clear_intangible();
        flags |= 0x42;
        flags &= ~0x201;
        set_guard_state();
        fade.start_fade_in();
        break;
    case 3:
        if (fade.advance_toward_max() != 0) {
            transition_enemy_state(2);
            break;
        }
    case 5:
        break;
    case 0:
        advance_animation();
        check_collisions();
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneEpsilonBody::handle_fire_state(s32 reason) {
    Vec *d;
    Vec *tgt;
    d = &fire_position;
    tgt = &target_position;
    switch (reason) {
    case 4:
        set_field_378(2);
        clear_intangible();
        flags |= 0x42;
        flags &= ~0x309;
        set_guard_state();
        action_step = 0;
        action_timer = 0;
        fire_timer = 0;
        target_player = 0xFFFF;
        target_slot = 0;
        break;
    case 3:
        if (flags & 0x80) {
            transition_enemy_state(7);
        } else if (action_step == 1) {
            fire_phase_timer = fire_phase_frames;
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        tick_timer_set_flag();
        if (!(flags & 0x80)) {
            enemy_copy_target_destination();
            update_velocity();
            effect_scale = destination_direction.x * sin_table_lookup(rotation_y) + destination_direction.z * cos_table_lookup(rotation_y);
            if (effect_scale < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(turn_step);
                update_ground_contact();
            } else {
                enemy_turn_and_move_on_ground(this, turn_step, move_speed);
            }
            if (target_player != 0xFFFF) {
                TObjPlayer *player = TObjPlayer::get_player_data(target_player);
                if (TObjPlayer::is_valid_and_active((uaddr)player) != 0) {
                    if (check_path_obstructed(this, &player->body_center) == 1) {
                        action_timer = 0;
                        target_player = 0xFFFF;
                    } else {
                        VecCopy(tgt, &player->position);
                    }
                } else {
                    action_timer = 0;
                    target_player = 0xFFFF;
                }
            } else {
                action_timer = 0;
            }
        } else {
            action_timer = 0;
        }
        switch (action_timer) {
        case 0:
            flags &= ~0x100;
            if (flags & 8) {
                action_step = 1;
            } else {
                target_slot++;
                target_player = select_slot_target(target_slot);
                if (target_player != 0xFFFF) {
                    if (TObjPlayer::is_valid_and_active((uaddr)TObjPlayer::get_player_data(target_player)) != 0) {
                        VecCopy(d, &position);
                        d->y += 10.0f;
                        if (project_actor_to_ground(this, d, 0) != 0) {
                            action_timer = 1;
                            fire_timer = epsilon_body_shared_params->fire_travel_frames;
                        }
                    }
                }
            }
            break;
        case 1: {
            Vec b;
            Vec a;
            f32 s;
            flags |= 0x100;
            VecCopy(&a, tgt);
            VecCopy(&b, d);
            subtract_vector(&a, d);
            normalize_vector_xz(&a);
            s = epsilon_body_shared_params->fire_step;
            b.x += a.x * s;
            b.y += 10.0f;
            b.z += a.z * s;
            if (project_actor_to_ground(this, &b, 0) != 0 && csnVector(d, &b, 0x88E0) == 0) {
                VecCopy(d, &b);
            }
            fire_timer--;
            if (fire_timer <= 0) {
                action_timer = 2;
                fire_timer = epsilon_body_shared_params->fire_fuse_frames;
            }
            play_persistent_sound(0x4003BC47, this, &position, 0, 0);
            break;
        }
        case 2:
            flags |= 0x100;
            fire_timer--;
            if (fire_timer <= 0) {
                TObjPlayer *player;
                s32 i;
                new TUnk_804CCB28(40.0f, d, 0, (TObject *)tl_07);
                play_sound_effect(0x4003A348, &position, 0, 0);
                for (i = 0; i < 4; i++) {
                    player = get_player_by_client_id(i);
                    if (player != 0 && horizontal_distance_squared(&player->position, d) <= 1600.0f) {
                        DirectAttackPayload t;
                        t.kind = 1;
                        t.power = epsilon_body_shared_params->fire_power;
                        if (player->receive_direct_attack(this, t, 0, -1, -1) > 0.0f) {
                            player->set_actor_flags(0x600);
                        }
                        play_sound_effect(0x4002A828, &player->position, 0, 0);
                    }
                }
                fire_timer = 30;
                action_timer = 3;
            }
            break;
        case 3:
            flags &= ~0x100;
            fire_timer--;
            if (fire_timer <= 0) {
                action_timer = 0;
                target_player = 0xFFFF;
            }
            break;
        default:
            flags &= ~0x100;
            action_timer = 0;
            target_player = 0xFFFF;
            break;
        }
        check_collisions();
        break;
    }
}
#pragma pop

void TObjEneEpsilonBody::handle_guard_action_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(3);
        clear_intangible();
        flags |= 0x42;
        flags &= ~0x201;
        set_guard_state();
        action_step = 0;
        action_timer = 0xF;
        play_sound_effect(0x4003A64B, &position, 0, 0);
        break;
    case 3:
        if (action_step == 3) {
            set_guards_flag_2();
            flags &= ~0x10;
            transition_enemy_state(4);
        } else if (action_step == 2) {
            transition_enemy_state(2);
        }
        break;
    case 0:
        advance_animation();
        switch (action_step) {
        case 0:
            action_timer--;
            if (assign_guard_targets() == 1) {
                flags &= ~2;
                set_guard_state();
                action_step = 1;
                action_timer = 0x3C;
            } else if (action_timer <= 0) {
                action_step = 2;
            }
            break;
        case 1:
            action_timer--;
            if (action_timer == 0xF) {
                play_sound_effect(0x4003A345, &position, 0, 0);
            }
            if (all_guards_active() != 0 || action_timer <= 0) {
                action_step = 3;
            }
            break;
        }
        check_collisions();
        break;
    case 5:
        return;
    }
}

void TObjEneEpsilonBody::action(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(4);
        clear_intangible();
        flags |= 0x400;
        flags &= ~0x247;
        set_guard_state();
        action_step = 0;
        return;
    case 3:
        if (action_step == 2) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        tick_stun_timer();
        switch (action_step) {
        case 0:
            if (((flags & 4) || (flags & 0x80)) && (all_guards_ready() != 0)) {
                action_step = 2;
                guard_phase_timer = guard_phase_frames;
            } else {
                update_flag_20();
                update_attack_pattern();
                if (flags & 0x10) {
                    action_step = 1;
                    action_timer = epsilon_body_shared_params->rest_frames;
                }
            }
            break;
        case 1:
            action_timer--;
            if (action_timer <= 0) {
                flags &= ~0x10;
                action_step = 0;
            }
            break;
        }
        check_collisions();
        break;
    }
}

void TObjEneEpsilonBody::handle_pre_warp_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(4);
        clear_intangible();
        flags &= ~0x253;
        set_guard_state();
        action_step = 0;
        action_timer = 0xF;
        emitter = create_particle_emitter(&position, 0x225);
        if (emitter != 0) {
            emitter->enable();
        }
        play_sound_effect(0x4003A64B, &position, 0, 0);
        break;
    case 3:
        if (action_step == 5) {
            transition_enemy_state(6);
        } else if (action_step == 4) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (action_step) {
        case 0:
            action_timer--;
            if (notify_guards_if_ready() == 1) {
                set_field_378(5);
                flags |= 0x40;
                action_step = 1;
                action_timer = 0x3C;
            } else if (action_timer <= 0) {
                action_step = 4;
            }
            if (emitter != 0) {
                emitter->enable();
            }
            break;
        case 1:
            action_timer--;
            if (all_guards_ready() != 0 || action_timer <= 0) {
                action_step = 2;
                action_timer = 8;
            }
            if (emitter != 0) {
                emitter->enable();
            }
            break;
        case 2:
            action_timer--;
            if (action_timer <= 0) {
                flags |= 2;
                set_guard_state();
                action_step = 3;
                action_timer = 8;
                play_sound_effect(0x4003A344, &position, 0, 0);
            }
            if (emitter != 0) {
                emitter->set_position(&position);
            }
            break;
        case 3:
            action_timer--;
            if (action_timer <= 0) {
                action_step = 5;
            }
            if (emitter != 0) {
                emitter->set_position(&position);
            }
            break;
        }
        check_collisions();
        break;
    case 5:
        if (emitter != 0) {
            emitter->queue_destruction();
            emitter = 0;
        }
        break;
    }
}

void TObjEneEpsilonBody::handle_warp_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(4);
        clear_intangible();
        flags |= 0x242;
        flags &= ~1;
        set_guard_state();
        action_step = 0;
        action_timer = 0;
        effect_scale = 0.0f;
        warp_emitter = create_particle_emitter(&body_center, 0x220);
        break;
    case 3:
        if (action_step == 3) {
            transition_enemy_state(2);
        }
        break;
    case 0:
        advance_animation();
        if (warp_emitter != 0) {
            warp_emitter->set_position(&body_center);
        }
        switch (action_step) {
        case 0:
            effect_scale += 0.033333335f;
            if (effect_scale >= 1.0f) {
                effect_scale = 1.0f;
                action_step = 1;
                action_timer = 0x1E;
                copy_argb(&color, (NJS_ARGB *)&epsilon_body_colors[color_index]);
                color_index = (color_index + 1) % 4;
                color_step.r = (epsilon_body_colors[color_index].r - color.r) / 30.0f;
                color_step.g = (epsilon_body_colors[color_index].g - color.g) / 30.0f;
                color_step.b = (epsilon_body_colors[color_index].b - color.b) / 30.0f;
            }
            play_persistent_sound(0x4003A349, this, &position, 0, 0);
            break;
        case 1:
            action_timer--;
            color.r += color_step.r;
            color.g += color_step.g;
            color.b += color_step.b;
            if (action_timer <= 0) {
                copy_argb(&color, (NJS_ARGB *)&epsilon_body_colors[color_index]);
                effect_scale = 1.0f;
                action_step = 2;
            }
            play_persistent_sound(0x4003A349, this, &position, 0, 0);
            break;
        case 2:
            effect_scale = effect_scale - 0.033333335f;
            if (effect_scale <= 0.0f) {
                effect_scale = 0.0f;
                action_step = 3;
                play_sound_effect(0x40039F4A, &position, 0, 0);
            } else {
                play_persistent_sound(0x4003A349, this, &position, 0, 0);
            }
            break;
        }
        check_collisions();
        break;
    case 5:
        if (warp_emitter != 0) {
            warp_emitter->queue_destruction();
            warp_emitter = 0;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TObjEneEpsilonBody::handle_return_home_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(4);
        clear_intangible();
        flags |= 0x42;
        flags &= ~0x201;
        set_guard_state();
        action_step = 0;
        action_timer = 0x3C;
        return;
    case 5:
        break;
    case 3:
        if (action_step == 3) {
            transition_enemy_state(0);
            set_intangible();
        }
        break;
    case 0:
        advance_animation();
        switch (action_step) {
        case 0:
            if (!(flags & 0x80)) {
                action_step = 2;
            } else {
                action_timer--;
                if (action_step <= 0) {
                    flags |= 0x40;
                    set_field_378(4);
                    action_step = 1;
                    fade.reset_color();
                }
            }
            break;
        case 1:
            if (fade.decay_value_toward_floor() != 0) {
                VecCopy(&position, &home_position);
                flags |= 1;
                action_step = 3;
            }
            break;
        }
        check_collisions();
        break;
    }
}
#pragma pop

void TObjEneEpsilonBody::update_fade(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(2);
        clear_intangible();
        flags |= 0x10;
        flags &= ~0x243;
        set_guard_state();
        action_step = 0;
        flash_level = -0x22U;
        return;
    case 3:
        if (action_step == 2) {
            transition_enemy_state(4);
        }
        break;
    case 0:
        advance_animation();
        switch (action_step) {
        case 0:
            flash_level += 0x22;
            if (flash_level > 0xFFU) {
                flash_level = 0xFFU;
                action_step = 1;
            }
            break;
        case 1:
            flash_level -= 0x22;
            if (flash_level <= 0x22U) {
                flash_level = 0U;
                action_step = 2;
            }
            break;
        default:
            flash_level = 0U;
            action_step = 2;
            break;
        }
        check_collisions();
        return;
    case 5:
        clear_attack_receipts();
        break;
    }
}

void TObjEneEpsilonBody::action_destroy(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(9);
        clear_intangible();
        flags |= 0x800;
        flags &= ~0x243;
        set_guard_state();
        refresh_and_send_entity_flags();
        action_step = 0;
        action_timer = 0;
        break;
    case 3:
        if (action_step == 1 && all_children_gone() != 0) {
            queue_destruction();
        }
        break;
    case 5:
        break;
    case 0:
        if (action_step == 0) {
            advance_animation();
            action_timer++;
            if (action_timer >= 0x14) {
                set_intangible();
                TBoss3Volopt::create_breakup_mdl(epsilon_body_breakup_model, &epsilon_guard_destroy_breakup_params,
                                   texlist, &body_center, rotation_y);
                play_sound_effect(0x4003AD4C, &body_center, 0, 0);
                trigger_dell_biter_events(&body_center);
                flags |= 1;
                action_step = 1;
            }
        }
        break;
    }
}
#pragma push
void TObjEneEpsilonBody::render() {
    s32 detail;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (!(this->actorFlags & 0x02000000)) {
        if (is_split_screen() != 0) {
            TCameraCtrl::get_camera_mode();
        }
        if (this->flags & 1) {
            detail = 0;
        } else if (TObjEneDD::is_main_phase_15() != 0) {
            detail = classify_actor_view_detail(650.0f, 650.0f, 30.0f);
        } else if (update_object_view_visibility(600.0f, 30.0f) != 0) {
            detail = 1;
        } else {
            detail = 0;
        }
        if (detail != 0) {
            TObjEneDD::draw_ground_shadow(0, 0);
            this->defer_render();
            draw_with_fade(detail);
            if ((s16) this->mode == 6) {
                if (this->flags & 0x200) {
                    this->render_body_effect();
                }
            }
        } else {
            i = 0;
            do {
                update_guard_anchor(i);
                i += 1;
            } while (i < 4);
        }
        if ((s16) this->mode == 2) {
            if (this->flags & 0x100) {
                draw_debug_line();
            }
        }
    }
}
#pragma pop

#pragma pool_data off
void TObjEneEpsilonBody::update_guard_anchor(s32 i) {
    // Joint index per guard slot.
    EpsilonGuardSlotValues t = {{28, 38, 48, 58}};

    if (i < 0) {
        i = 0;
    } else if (i > 3) {
        i = 3;
    }
    push_matrix_from(identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[t.v[i]]);
    {
        Vec v = {0.0f, 0.0f, 0.0f};
        matrix_mult_vec(0, &v, &guard_position[i]);
    }
    pop_matrix();
    guard_rotation_y[i] = (s32)(10430.38043493439 * atan2_float(guard_position[i].x - position.x, guard_position[i].z - position.z));
}
#pragma pool_data reset

void TObjEneEpsilonBody::draw_debug_line() {
    VecCopy(&epsilon_body_debug_line_points[0], &body_center);
    VecCopy(&epsilon_body_debug_line_points[1], &fire_position);
    set_additive_blend();
    draw_line_list(&TObjEneEpsilonGuard__debug_line_list, 1, 5);
    set_default_alpha_blend();
}

void TObjEneEpsilonBody::draw_with_fade(s32 detail) {
    s32 i;
    RenderFadeState *r;
    i = 0;
    if (is_split_screen() != 0) {
        i = TCameraCtrl::get_camera_mode();
    }
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    set_guard_part_colors(&color);
    r = &fades[i];
    r->update();
    if (r->updateFromCamera(&body_center.x) != 0) {
        r->set_flags_and_apply_damage_color();
        if (!((s32)main_task.get_task_flags() & 0x200)) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else if (fade.has_visible_opacity() != 0) {
        if (fade.has_partial_opacity() != 0) {
            fade.set_flags_and_apply_damage_color();
            if (!((s32)main_task.get_task_flags() & 0x200)) {
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                return;
            }
        } else if ((s32)main_task.get_task_flags() & 0x200) {
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            return;
        }
    } else {
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        return;
    }
    update_secondary_light();
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    push_matrix();
    post_translate_matrix(&position.x);
    translate_matrix(0, 0.0f, 24.0f, 0.0f);
    rotate_matrix_y(0, rotation_y);
    TObjEneDD::clear_global_flag_400();
    if (flags & 2) {
        set_chunk_model_node_callback(TObjEneEpsilonBody::record_camera_angle_samples);
    }
    TObjPlayer::toggle_particle_effect();
    epsilon_guard_camera_sample_read_ptr = guard_position;
    epsilon_guard_angle_sample_write_ptr = guard_rotation_y;
    epsilon_guard_camera_sample_end_ptr = &position;
    if (mode == 8) {
        s32 c = (flash_level & 0xFF) << 0x10;
        epsilon_guard_camera_sample_phase = -1;
        draw_with_alt_model(c | 0xFF000000);
    } else {
        epsilon_guard_camera_sample_phase = 0;
        if (detail == 1) {
            draw();
        } else {
            draw_motion_model();
        }
    }
    TParticleCtrl::end_effect_render();
    if (flags & 2) {
        set_chunk_model_node_callback(NULL);
    }
    pop_matrix();
    update_primary_light();
    if (r->updateFromCamera(&body_center.x) != 0) {
        r->clear_flag_and_notify();
    } else if ((fade.has_visible_opacity() != 0) && (fade.has_partial_opacity() != 0)) {
        fade.clear_flag_and_notify();
    }
    model_render_flags = saved_model_render_flags;
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
}

void TObjEneEpsilonBody::render_body_effect() {
    if ((s32)main_task.get_task_flags() & 0x200) {
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, 24.0f, 0.0f);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, effect_scale, 1.0f, effect_scale);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(get_bml_model(epsilon_bml_resource, 4));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjEneEpsilonBody::record_camera_angle_samples(NJS_OBJECT *) {
    switch (epsilon_guard_camera_sample_phase) {
    case 0x1C:
    case 0x26:
    case 0x30:
    case 0x3A:
        forward_transform_to_view(&epsilon_body_node_origin, epsilon_guard_camera_sample_read_ptr);
        *epsilon_guard_angle_sample_write_ptr = (s32)(10430.38043493439 * atan2_float(
            epsilon_guard_camera_sample_read_ptr->x - epsilon_guard_camera_sample_end_ptr->x,
            epsilon_guard_camera_sample_read_ptr->z - epsilon_guard_camera_sample_end_ptr->z));
        epsilon_guard_camera_sample_read_ptr++;
        epsilon_guard_angle_sample_write_ptr++;
        break;
    }
    epsilon_guard_camera_sample_phase++;
}
void TObjEneEpsilonBody::render_demo() {  }
void TObjEneEpsilonBody::set_guard_state() {
    if (flags & 2) {
        guarded = 1;
        model = (void *)get_bml_model(epsilon_bml_resource, 0);
        requested_action = 0;
        set_indexed_flags(1, 1);
        clear_player_status_flag(0, 1);
    } else {
        guarded = 0;
        model = (void *)get_bml_model(epsilon_bml_resource, 1);
        requested_action = 1;
        set_indexed_flags(0, 1);
        clear_player_status_flag(1, 1);
    }
    advance_animation();
}

void TObjEneEpsilonBody::tick_timer_set_flag() {
    fire_phase_timer--;
    if (fire_phase_timer <= 0) {
        flags |= 8;
    }
}

void TObjEneEpsilonBody::tick_stun_timer() {
    guard_phase_timer--;
    if (guard_phase_timer <= 0) {
        flags |= 4;
    }
}
void TObjEneEpsilonBody::update_attack_pattern() {
    // 20 rows of per-guard attack flags.
    EpsilonGuardAttackPatterns t = {{
        {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
        {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},
        {0, 0, 0, 1}, {1, 1, 0, 0}, {1, 0, 1, 0}, {1, 0, 0, 1},
        {0, 1, 1, 0}, {0, 1, 0, 1}, {0, 0, 1, 1}, {1, 1, 1, 0},
        {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 1},
    }};
    s32 *row;
    s32 i;
    if (flags & 0x400) {
        attack_pattern_timer--;
        if (attack_pattern_timer <= 0) {
            row = t.v[(s32)(20.0f * random_ratio()) % 20];
            for (i = 0; i < 4; i++) {
                if (row[i] == 1) {
                    clear_guard_state_flag(i);
                }
            }
            flags &= ~0x400;
        }
    } else if (all_guard_state_flags_set() != 0) {
        flags |= 0x400;
        attack_pattern_timer = epsilon_body_shared_params->attack_pattern_frames;
    }
}

// Picks the player for guard slot `slot`: the up to four nearest players in
// range with a clear path, sorted by distance and repeated to fill four slots.
u32 TObjEneEpsilonBody::select_slot_target(s32 slot) {
    EpsilonGuardSlotValues order = {{2, 0, 1, 3}};
    EnemyTargetCandidate list[4];
    Vec d;
    EnemyTargetCandidate tmp;
    s32 n;
    s32 id;
    s32 extra;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    TObjPlayer *player;
    f32 dist;

    list[0].id = 0xFFFF;
    list[0].distance_squared = 0.0f;
    n = 0;
    extra = is_confused();
    count = registered_player_count;
    if (extra != 0) {
        count += registered_enemy_count;
    }
    for (id = 0; id < count; id++) {
        player = TObjPlayer::get_player_data(id);
        if (TObjPlayer::is_valid_and_active((uaddr)player) == 0) continue;
        if (player->actorFlags & 0x2000800) continue;
        VecCopy(&d, &player->body_center);
        subtract_vector(&d, &body_center);
        dist = d.x * d.x + d.z * d.z;
        if (!(dist < 160000.0f)) continue;
        if (check_path_obstructed(this, &player->body_center) == 1) continue;
        list[n].distance_squared = dist;
        list[n].id = id;
        n++;
        if (n >= 4) break;
    }
    if (n <= 0) {
        return 0xFFFF;
    }
    if (n >= 2) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (list[i].distance_squared > list[j].distance_squared) {
                    tmp.copy_from(&list[i]);
                    list[i].copy_from(&list[j]);
                    list[j].copy_from(&tmp);
                }
            }
        }
    }
    for (k = n; k < 4; k++) {
        list[k].copy_from(&list[k % n]);
    }
    return list[order.v[slot % 4]].id;
}

s32 TObjEneEpsilonBody::all_guards_ready() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i]))->is_guard_ready() == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonBody::all_children_gone() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (find_entity_by_id(guard_ids[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonBody::all_guard_state_flags_set() {
    s32 i;
    TObjEneEpsilonGuard *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i])) != 0 && guard->is_state_flag_set() == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TObjEneEpsilonBody::all_guards_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i]))->is_guard_active() == 0) {
            return 0;
        }
    }
    return 1;
}

void TObjEneEpsilonBody::update_flag_20() {
    s32 i;
    TObjCollidable *guard;
    flags &= ~0x20;
    for (i = 0; i < 4; i++) {
        if ((guard = find_entity_by_id(guard_ids[i])) != 0 && ((TObjEneEpsilonGuard *)guard)->test_flag_80() == 1) {
            flags |= 0x20;
        }
    }
}
s32 TObjEneEpsilonBody::notify_guards_if_ready() {
    s32 i;
    TObjEneEpsilonGuard *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i])) != 0 && guard->is_guard_ready() == 0) {
            return 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i])) != 0) {
            guard->set_flag_8_and_notify();
        }
    }
    return 1;
}

void TObjEneEpsilonBody::set_guards_flag_2() {
    s32 i;
    TObjCollidable *guard;
    for (i = 0; i < 4; i++) {
        if ((guard = find_entity_by_id(guard_ids[i])) != 0) {
            ((TObjEneEpsilonGuard *)guard)->set_flag_2_and_clear_status();
        }
    }
}

s32 TObjEneEpsilonBody::assign_guard_targets() {
    s32 i;
    s32 reverse;
    TObjEneEpsilonGuard *guard;
    for (i = 0; i < 4; i++) {
        guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i]);
        if (guard != 0 && guard->is_following_body() == 0) {
            return 0;
        }
    }
    reverse = random_ratio() < 0.5;
    for (i = 0; i < 4; i++) {
        guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[i]);
        if (guard != 0) {
            guard->set_target(&guard_position[i], guard_rotation_y[i], reverse);
        }
    }
    return 1;
}
s32 TObjEneEpsilonBody::is_orbit_paused() { return 0; }
s32 TObjEneEpsilonBody::test_flag_20() { return ((u32)flags >> 5) & 1; }

s32 TObjEneEpsilonBody::test_flag_800() { return ((u32)flags >> 11) & 1; }

s16 TObjEneEpsilonBody::get_table_value_by_index() {
    s16 i = this->color_index;
    EpsilonGuardSlotValues t = {{1, 2, 3, 5}};
    if (i < 0 || i > 3) {
        return 0;
    }
    return t.v[i];
}

s16 TObjEneEpsilonBody::get_immune_special_kind() {
    s16 i = this->color_index;
    EpsilonGuardSlotValues16 t = {{9, 7, 10, 11}};
    if (i < 0 || i > 3) {
        return 0;
    }
    return t.v[i];
}

void TObjEneEpsilonBody::clear_guard_state_flag(s32 slot) {
    TObjEneEpsilonGuard *guard;
    if (slot < 0 || slot >= 4) {
        return;
    }
    guard = (TObjEneEpsilonGuard *)find_entity_by_id(guard_ids[slot]);
    if (guard != 0 && guard->is_state_flag_set() == 1) {
        guard->clear_and_flag_state();
    }
}

f32 TObjEneEpsilonBody::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *source, s32 tech, s32 attack_flags) {
    s32 flags = this->flags;
    if (!(flags & 2) && !(flags & 0x40)) {
        if (payload.kind != get_table_value_by_index()) {
            return TObjChara::receive_direct_attack(attacker, payload, source, tech, attack_flags);
        }
    } else if (payload.kind == 0x14) {
        return TObjChara::receive_direct_attack(attacker, payload, source, tech, attack_flags);
    }
    try_apply_damage(&body_center, 0);
    return 0.0f;
}

f32 TObjEneEpsilonBody::receive_physical_attack(void *attacker, f32 scale) {
    if (!(flags & 2) && !(flags & 0x40)) {
        return TObjChara::receive_physical_attack(attacker, scale);
    }
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
f32 TObjEneEpsilonBody::receive_weapon_special_attack(void *src, void *hit) {
    if (!(flags & 2) && !(flags & 0x40)) {
        s16 kind = ((TObjPlayer *)src)->obj_getS16_116();
        s32 strong;
        obj_getS16_118((u8 *)src);
        strong = 0;
        if (src == NULL || ((TObjBase *)src)->get_entity_id() == 0xFFFF) {
            show_miss_popup(&position.x);
            return 0.0f;
        }
        if (test_actor_flags(0x04000000) != 0) {
            strong = 1;
        }
        if (hit != NULL && (((CollisionBody *)hit)->flags & 0x02000000)) {
            strong = 1;
        }
        if (strong != 0) {
            switch (kind) {
            case 0:
                break;
            case 1:
            case 2:
            case 5:
            case 6:
            case 7:
            case 9:
            case 10:
                try_apply_damage(&body_center, 0);
                break;
            case 3:
            case 4:
            case 8:
            case 11:
            case 12:
            case 13:
                show_miss_popup(&body_center.x);
                break;
            }
            return 0.0f;
        }
        if (((TObjPlayer *)src)->obj_getS16_116() != get_immune_special_kind()) {
            return TObjChara::receive_weapon_special_attack(src, hit);
        }
    }
    try_apply_damage(&body_center, 0);
    return 0.0f;
}
