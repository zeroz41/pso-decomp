#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/GroundContactSound.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/render/reflection.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnGroundQuery.h"

#include "pso/system/BmlResourceDescriptor.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter_Eff_Rush.h"
#include <stddef.h>
#include "pso/enemy/dellbiter/TObjEneDellBiter_Eff_TpAbsorb1.h"

#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/item/TItemData.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/map/CsnQuery.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


extern "C" {
player_stats *dellbiter_boss_stat_handle;
AttackParams *TObjEneDellBiter__shared_handler_param;
ActorParamBlock *dellbiter_object_stat_handle;
DelbiterMovementParameters * TObjEneDellBiter__movement_params;
BmlResource *TObjEneDellBiter__shared_model_resource;
s32 TObjEneDellBiter__demo_script_step;
s32 TObjEneDellBiter__demo_rotate_x_angle;
Vec *TObjEneDellBiter__demo_script_cursor;
saddr TObjEneDellBiter__scrolling_uv_polygon_list;
s32 TObjEneDellBiter__last_uv_scroll_tick;

Vec dellbiter_demo_camera_vec;


extern const char *dell_biter_model_names[2];
extern const char *TObjEneDellBiter__resource_descriptor[11];
extern const char *dell_biter_low_model_names[2];
extern const char *dell_biter_low_motion_names[11];

DelbiterInitialParameters TObjEneDellBiter__param_table = {
    225.0f, 0.0f, 0x600, {0, 0, 0, 0}
};
CollisionBody dell_biter_collision_bodies[4] = {
    {{0.0f, 12.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
__declspec(section ".data") const char *dell_biter_model_names[2] = {
    "biter_body.nj", NULL,
};
const char *TObjEneDellBiter__resource_descriptor[11] = {
    "attack_biter_body.njm", "beam_biter_body.njm", "damage_biter_body.njm", "dead_biter_body.njm",
    "kamae_biter_body.njm", "run_biter_body.njm", "stop_biter_body.njm", "tpkyu_biter_body.njm",
    "wait_biter_body.njm", "walk_biter_body.njm", NULL,
};
BmlResourceDescriptor dell_biter_bml_resource = {
    "bm_ene_biter_body.bml", dell_biter_model_names, TObjEneDellBiter__resource_descriptor, 1, 10
};
__declspec(section ".data") const char *dell_biter_low_model_names[2] = {
    "lo_biter_body.nj", NULL,
};
const char *dell_biter_low_motion_names[11] = {
    "attack_biter_body.njm", "beam_biter_body.njm", "damage_biter_body.njm", "dead_biter_body.njm",
    "kamae_biter_body.njm", "run_biter_body.njm", "stop_biter_body.njm", "tpkyu_biter_body.njm",
    "wait_biter_body.njm", "walk_biter_body.njm", NULL,
};
BmlResourceDescriptor dell_biter_low_bml_resource = {
    "bm_ene_biter_body_low.bml", dell_biter_low_model_names, dell_biter_low_motion_names, 1, 10
};
TObjMotionAction dell_biter_param_table[10] = {
    {1, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.7f, 0},
    {1, 0, 5, 0.8f, 0},
    {3, 0, 6, 0.9f, 0},
    {3, 0, 0, 0.6f, 0},
    {3, 0, 1, 0.6f, 0},
    {3, 0, 2, 1.0f, 0},
    {3, 0, 4, 0.7f, 0},
    {3, 0, 7, 1.0f, 0},
    {3, 0, 3, 0.7f, 0}
};

const char *TObjEneDellBiter__class_name = "TObjEneDellBiter";
}
#pragma fp_contract on

void TObjEneDellBiter::load_resources() {
    dellbiter_demo_camera_vec.x = 0.0f;
    dellbiter_demo_camera_vec.y = 0.0f;
    dellbiter_demo_camera_vec.z = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneDellBiter__shared_model_resource = load_enemy_bml_resource(&dell_biter_low_bml_resource);
    } else {
        TObjEneDellBiter__shared_model_resource = load_enemy_bml_resource(&dell_biter_bml_resource);
    }
    dellbiter_boss_stat_handle = TLobby::register_boss(0xD);
    TObjEneDellBiter__shared_handler_param = TLobby::dispatch_shared_handler_b(0xD);
    dellbiter_object_stat_handle = TLobby::register_object(0xD);
    TObjEneDellBiter__movement_params = (DelbiterMovementParameters *)TLobby::dispatch_shared_handler_a(0xD);
    TObjEneDellBiter__demo_script_step = 0;
    TObjEneDellBiter__demo_rotate_x_angle = 0;
    TObjEneDellBiter__demo_script_cursor = 0;
    TObjEneDellBiter::set_min_clamped_entry_value(4, TObjEneDellBiter__movement_params->animation_speed_4);
    TObjEneDellBiter::set_min_clamped_entry_value(5, TObjEneDellBiter__movement_params->animation_speed_5);
    {
        BmlResource *resource = TObjEneDellBiter__shared_model_resource;
        NJS_OBJECT *object = resource->models->model;
        TObjEneDellBiter__scrolling_uv_polygon_list = (saddr)((NJS_CNK_MODEL *)object->child->model)->polygon_list;
        TObjEneDellBiter__last_uv_scroll_tick = 0;
        NpcAnimationBinding attack = { resource->motions, dell_biter_param_table, 0, 1, 10 };
        TObjNpcEnemy::register_animated_chunk((s16)0x46, resource->models->model, resource->models->texlist,
            &attack, dell_biter_collision_bodies[0].radius, 0.0f);
    }
}

void *TObjEneDellBiter::create(void *set_data) {
    return new TObjEneDellBiter(tl_04, set_data);
}

void TObjEneDellBiter::destroy_static_instance() {
    if (TObjEneDellBiter__shared_model_resource != NULL) {
        delete TObjEneDellBiter__shared_model_resource;
        TObjEneDellBiter__shared_model_resource = NULL;
    }
}

void TObjEneDellBiter::set_min_clamped_entry_value(s32 index, f32 speed) {
    if (speed < 0.1f) {
        speed = 0.1f;
    }
    dell_biter_param_table[index].speed = speed;
}

TObjEneDellBiter::TObjEneDellBiter(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = TObjEneDellBiter__class_name;
    invoke_initialization_hook(set_data);
    init_target_offsets();
    init_params();
}

void TObjEneDellBiter::init_params() {
    s32 i;
    init_position_vectors();
    model = TObjEneDellBiter__shared_model_resource->models->model;
    texlist = TObjEneDellBiter__shared_model_resource->models->texlist;
    init_model((CollisionBody *)dell_biter_collision_bodies, 1);
    bodies->flags |= 0x400000;
    set_action_table(dell_biter_param_table);
    set_motion_list(TObjEneDellBiter__shared_model_resource->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    reset_hp(dellbiter_boss_stat_handle, TObjEneDellBiter__shared_handler_param, dellbiter_object_stat_handle);
    set_state_8();
    movementParameters = &TObjEneDellBiter__param_table;
    initialize_enemy_state(0x48);
    wall_reach = 20.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    flags = 0;
    flags_3c4 = 0;
    VecCopy(&reflection_position, &position);
    flags |= 1;
    fade.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    for (i = 0; i < 3; i++) {
        VecCopy(&part_positions[i], &position);
    }
    part_rotation_x = 0;
    combo_count = 0;
    rush_count = 0;
    effect_timer = 0;
    attack_bodies[0] = new TUnk_804928CC(this, this, &dell_biter_collision_bodies[1], 1);
    attack_bodies[1] = new TUnk_804928CC(this, this, &dell_biter_collision_bodies[2], 1);
    rush_body = new TObjCollidable(NULL);
    init_collision_body_parts(rush_body, &dell_biter_collision_bodies[3], 1);
    attack_history = new AreaAttackHistory(8);
    saver = TAttackTraceStrip::create(0xFF5050FF, 0x80000080);
    state_timer = 0;
    step = 0;
    drained_tp = 0;
    target_angle = 0;
    current_speed = 0.0f;
    rush_traveled = 0.0f;
    mode = 1;
    dispatch_action(mode, 4);
    effect = NULL;
    status_effects[0] = NULL;
    status_effects[1] = NULL;
}

TObjEneDellBiter::~TObjEneDellBiter() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
    if (status_effects[0] != NULL) {
        status_effects[0]->queue_destruction();
        status_effects[0] = NULL;
    }
    if (status_effects[1] != NULL) {
        status_effects[1]->queue_destruction();
        status_effects[1] = NULL;
    }
    if (saver != NULL) {
        saver->queue_destruction();
        saver = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (attack_bodies[1] != NULL) {
        delete attack_bodies[1];
        attack_bodies[1] = NULL;
    }
    if (attack_bodies[0] != NULL) {
        delete attack_bodies[0];
        attack_bodies[0] = NULL;
    }
    if (rush_body != NULL) {
        free_collision_body_parts(rush_body);
        delete rush_body;
        rush_body = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneDellBiter::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        if ((s32) TObjEneDellBiter__last_uv_scroll_tick != (s32) actor_frame_tick) {
            TObjEneDellBiter__last_uv_scroll_tick = actor_frame_tick;
            TObjPlayer__sub_8023DEE0((s16 *)TObjEneDellBiter__scrolling_uv_polygon_list, 0xC, 0, 0);
        }
    }
    this->update_particle_emitters();
    if (flags_3c4 & 0x4000) {
        request_reflection_render();
    }
    this->set_effect_pos_above_self();
    submit_default_cursor_candidate();
    this->render_minimap_dot();
}

void TObjEneDellBiter::refresh_target() {  }

void TObjEneDellBiter::run_death_reaction() {
    if (mode != 11) {
        transition_enemy_state(11);
    }
}

void TObjEneDellBiter::run_hit_reaction() {
    if ((s16) mode != 0xA) {
        retarget_attacker();
        if (flags & 0x14) {
            this->clear_attack_receipts();
            return;
        }
        transition_enemy_state(10);
    }
}

void TObjEneDellBiter::run_miss_reaction() {  }

void TObjEneDellBiter::set_effect_pos_above_self() {
    VecCopy(&body_center, &position);
    body_center.y += 12.0f;
    VecCopy(&center, &body_center);
}

void TObjEneDellBiter::update_body_colliders() {  }

void TObjEneDellBiter::update_particle_emitters() {
    Vec emission_position;
    s32 active_flags = flags;
    if (active_flags & 0x10) {
        if (effect_timer <= 0) {
            flags = active_flags & ~0x10;
        } else {
            VecCopy(&emission_position, &position);
            emission_position.y += 10.0f;
            if (game_difficulty_selection == 3) {
                TParticleCtrl *emitter = status_effects[0];
                if (emitter == NULL) {
                    status_effects[0] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x216);
                } else {
                    emitter->set_position(&emission_position);
                }
            } else {
                TParticleCtrl *emitter = status_effects[0];
                if (emitter == NULL) {
                    status_effects[0] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x215);
                } else {
                    emitter->set_position(&emission_position);
                }
                emitter = status_effects[1];
                if (emitter == NULL) {
                    status_effects[1] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x219);
                } else {
                    emitter->set_position(&emission_position);
                }
            }
        }
        effect_timer--;
        return;
    }
    TParticleCtrl *emitter = status_effects[0];
    if (emitter != NULL) {
        emitter->queue_destruction();
        status_effects[0] = NULL;
    }
    emitter = status_effects[1];
    if (emitter != NULL) {
        emitter->queue_destruction();
        status_effects[1] = NULL;
    }
}

void TObjEneDellBiter::init_target_offsets() {
    howl_chance = 0.3f + parameters[0];
    confuse_chance = 0.3f + parameters[1];
    confuse_distance = 30.0f + parameters[2];
    if (confuse_distance < 10.0f) {
        confuse_distance = 10.0f;
    }
    laser_chance = 0.3f + parameters[3];
    change_chance = 0.05f + parameters[4];
    if ((s32)variant >= 1) {
        run_type = 1;
        return;
    }
    run_type = 0;
}

void TObjEneDellBiter::update_contact_attacks() {
    f32 frame = this->frame;
    if (frame >= 10.8f && frame <= 13.0f) {
        attack_bodies[0]->rotation_y = rotation_y;
        VecCopy(&attack_bodies[0]->position, &part_positions[1]);
        attack_bodies[0]->refresh_collision_body_centers();
        attack_bodies[1]->rotation_y = rotation_y;
        VecCopy(&attack_bodies[1]->position, &part_positions[1]);
        attack_bodies[1]->refresh_collision_body_centers();
        DelbiterContactAttack attack = { get_attack_params_atp_min(TObjEneDellBiter__shared_handler_param), 1 };
        if (is_confused() != 0) {
            attack.flags |= 2;
        }
        attack_bodies[0]->call_vt16_with_default(&attack, attack_history);
        attack_bodies[1]->call_vt16_with_default(&attack, attack_history);
    }
}

s32 TObjEneDellBiter::check_rush_collisions() {
    s32 hit;
    TObjChara *target;
    s32 i;
    DirectAttackPayload attack;
    hit = 0;
    VecCopy(&rush_body->position, &position);
    TObjPlayer::init_all_slots();
    rush_body->check_object_collisions();
    if (rush_body->bodies->flags & 0x180000) {
        hit = 1;
        for (i = 0; i < 0x10; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(target) != 0 && attack_target_history_add(attack_history, target) != 0) {
                if (flags & 0x10) {
                    if (game_difficulty_selection == 3) {
                        attack.kind = 5;
                        attack.power = TObjEneDellBiter__movement_params->powered_attack_power;
                    } else {
                        attack.kind = 3;
                        attack.power = TObjEneDellBiter__movement_params->powered_attack_power;
                    }
                } else {
                    attack.kind = 0;
                    attack.power = TObjEneDellBiter__movement_params->attack_power;
                }
                target->receive_direct_attack(this, attack, NULL, -1, -1);
                if (target->test_actor_flags(0x04000000) == 0) {
                    target->set_actor_flags(0x600);
                }
                new TObjEneDellBiter_Eff_Rush(this, this, target, 12.0f);
            }
        }
    }
    return hit;
}

void TObjEneDellBiter::update_attack_effect() {
    if (fn_803059BC(&position) != 0) {
        play_ground_contact_sound(&position);
        return;
    }
    play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039E11)), &position, 0, 0);
}

void TObjEneDellBiter::spawn_front_particle() {
    Vec front;
    front.x = -5.0f;
    front.y = 0.0f;
    front.z = 7.0f;
    rotate_xz_pair_by_angle(&front.x, &front.z, rotation_y);
    vec3_add_to(&front, &position);
    if (fn_803059BC(&front) == 0) {
        spawn_particle_effect(&front, 0xF3);
    }
}

s32 TObjEneDellBiter::fn_803059BC(const Vec *origin) {
    Vec pos;
    CsnHit *hit;
    TParticleCtrl *e;
    VecCopy(&pos, origin);
    pos.y += 15.0f;
    hit = csnVectorUnder(&pos, ground_candidates.groups, 0x4007);
    if (hit != NULL) {
        flags_3c4 = hit->contact[0].flags;
        if (flags_3c4 & 0x4000) {
            VecCopy(&reflection_position, &hit->contact[0].point);
        } else {
            VecCopy(&reflection_position, &position);
        }
        if (hit->hit_mask & 4) {
            e = spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (e != NULL) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
                e->set_scale(3.0f, 3.0f);
            }
            e = spawn_particle_effect(&hit->contact[2].point, 0xA4);
            if (e != NULL) {
                e->set_scale(3.0f, 3.0f);
            }
            return 1;
        }
        if (hit->hit_mask & 2) {
            e = spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (e != NULL) {
                attach_particle_model(e, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
                e->set_scale(3.0f, 3.0f);
            }
            e = spawn_particle_effect(&hit->contact[3].point, 0xA4);
            if (e != NULL) {
                e->set_scale(3.0f, 3.0f);
            }
            return 1;
        }
    }
    return 0;
}

void TObjEneDellBiter::play_step_effect() {
    if (is_passing_frame(0.0f) != 0 || is_passing_frame(8.0f) != 0) {
        if (fn_803059BC(&position) != 0) {
            play_ground_step_sound(this, &position);
            return;
        }
        play_persistent_sound(this->remap_sound_for_area((saddr)((void *)0x40039E13)), this, &position, 0, 0);
        spawn_particle_effect(&position, 0xF0);
    }
}

void TObjEneDellBiter::fn_803058DC() {
    if (is_passing_frame(21.0f) != 0) {
        spawn_front_particle();
    }
}

s32 TObjEneDellBiter::validate_or_update_target() {
    if (!(flags & 8)) {
        return update_linked_position(300.0f);
    }
    s32 valid = enemy_validate_retained_target(this);
    if (valid == 0) {
        flags &= ~8;
    }
    return valid;
}

s32 TObjEneDellBiter::select_farthest_visible_player() {
    s32 count;
    TObjChara *player;
    u16 id;
    s32 i;
    f32 distance;
    f32 best;
    best = 0.0f;
    id = 0xFFFF;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            distance = horizontal_distance_squared(&body_center, &player->position);
            if (distance < 90000.0f && distance > best &&
                csnLookAt(&body_center, &player->body_center) == 0) {
                id = player->get_entity_id();
                best = distance;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    this->enemy_clear_target();
    return 0;
}

void TObjEneDellBiter::confuse_nearby_players() {
    s32 count;
    TObjChara *player;
    s32 i;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            f32 distance = horizontal_distance_squared(&body_center, &player->position);
            if (csnLookAt(&body_center, &player->body_center) == 0 &&
                distance <= confuse_distance * confuse_distance && random_ratio() <= confuse_chance) {
                DirectAttackPayload attack;
                attack.kind = 18;
                attack.power = 1.0f;
                player->receive_direct_attack(this, attack, NULL, -1, -1);
            }
        }
    }
}

void TObjEneDellBiter::fn_80305684() {}

s32 TObjEneDellBiter::acquire_target(f32 distance) {
    if (is_confused() != 0) {
        return select_and_apply_target(distance);
    }
    return select_nearest_target(distance);
}

void TObjEneDellBiter::retarget_attacker() {
    u16 id = attacker_id;
    if (id < 0x1000U) {
        void *player = get_player_by_client_id(id);
        if (player != NULL) {
            set_target_player(player);
        }
        flags |= 8;
    }
}

s32 TObjEneDellBiter::check_low_hp_transition() {
    if (!(flags & 0x10) && hp <= hpmax / 2 &&
        random_ratio() <= change_chance) {
        transition_enemy_state(12);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter::try_laser() {
    if (random_ratio() <= laser_chance) {
        transition_enemy_state(9);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter::try_howl() {
    if (random_ratio() <= howl_chance) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}

void TObjEneDellBiter::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        update_state(reason);
        return;
    case 1:
        update_hidden_state(reason);
        return;
    case 2:
        update_emerge_walk_state(reason);
        return;
    case 3:
        update_emerge_run_state(reason);
        return;
    case 4:
        update_wait_state(reason);
        return;
    case 5:
        update_walk_state(reason);
        return;
    case 6:
        update_rush_state(reason);
        return;
    case 7:
        update_attack_state(reason);
        return;
    case 8:
        update_howl_state(reason);
        return;
    case 9:
        update_laser_state(reason);
        return;
    case 12:
        update_change_state(reason);
        return;
    case 10:
        update_damage_state(reason);
        return;
    case 11:
        state_death(reason);
    default:
        return;
    }
}

void TObjEneDellBiter::update_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(0);
        state_timer = 0;
        return;
    case 3:
        transition_enemy_state(1);
        return;
    case 0:
        state_timer = (state_timer + 1);
    case 5:
        return;
    }
}

void TObjEneDellBiter::update_hidden_state(s32 reason) {
    switch (reason) {
    case 4:
        this->set_field_378(1);
        flags = (s32) (flags | 1);
        this->set_intangible();
        VecCopy(&position, &home_position);
        return;
    case 3:
        if (update_linked_position(300.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            rotation_y = (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
            if ((s32) run_type == 1) {
                transition_enemy_state(3);
                return;
            }
            transition_enemy_state(2);
        } else {
        case 5:
        case 0:
            return;
        }
        break;
    }
}

void TObjEneDellBiter::update_emerge_walk_state(s32 reason) {

    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFE);
        flags = (s32) (flags | 2);
        this->set_intangible();
        fade.reset_obstruction_fade();
        state_timer = 0;
        step = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy(&body_center, &position);
        combo_count = 0;
        rush_count = 0;
        play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039E12)), &position, 0, 0);
        return;
    case 3:
        if ((s32) step == 2) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        advance_animation();
        update_linked_position(300.0f);
        state_timer = (state_timer + 1);
        switch (step) {
        case 0:
            if ((s32) state_timer > 0x14) {
                step = 1;
                this->requested_action = 3;
                play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039B14)), &position, 0, 0);
            }
            play_step_effect();
            this->move_with_wall_slide_on_ground(destination_direction.x, destination_direction.z, 1.2f);
            fn_80305684();
            break;
        case 1:
            fn_803058DC();
            if (this->get_flag_b4() != 0) {
                step = 2;
            }
            break;
        }
        if (fade.advance_toward_max() != 0) {
            flags = (s32) (flags & 0xFFFFFFFD);
            this->clear_intangible();
            this->check_collisions();
            return;
        }
        break;
    case 5:
        this->clear_intangible();
        break;
    }
}

void TObjEneDellBiter::update_emerge_run_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(5);
        flags &= ~1;
        flags |= 6;
        bodies->flags |= 0x700;
        clear_intangible();
        fade.reset_obstruction_fade();
        current_speed = TObjEneDellBiter__movement_params->rush_speed;
        step = 0;
        play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039E12)), &position, 0, 0);
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy(&body_center, &position);
        position.x -= 100.0f * sin_table_lookup(rotation_y);
        position.z -= 100.0f * cos_table_lookup(rotation_y);
        state_timer = (s32)(100.0f / TObjEneDellBiter__movement_params->rush_speed);
        combo_count = 0;
        rush_count = 0;
        this->set_active();
        break;
    case 3:
        if (step == 2) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            play_step_effect();
            position.x = current_speed * sin_table_lookup(rotation_y) + position.x;
            position.z = current_speed * cos_table_lookup(rotation_y) + position.z;
            check_rush_collisions();
            state_timer--;
            if (state_timer <= 0) {
                step = 1;
                state_timer = 0;
                flags &= ~4;
                this->set_field_378(5);
                play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039B14)), &position, 0, 0);
            }
            update_ground_contact();
            break;
        case 1:
            state_timer++;
            if (state_timer >= 10) {
                this->requested_action = 3;
                fn_803058DC();
                if (this->get_flag_b4() != 0) {
                    step = 2;
                }
                current_speed *= 0.9f;
            }
            check_rush_collisions();
            this->move_clamped_on_ground(destination_direction.x, destination_direction.z, current_speed);
            break;
        }
        if (fade.advance_toward_max() != 0) {
            flags &= ~2;
            check_collisions();
        }
        break;
    case 5:
        flags &= ~4;
        bodies->flags &= ~0x700;
        this->clear_field_388();
        break;
    }
}

void TObjEneDellBiter::update_wait_state(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        flags = (s32) (flags & 0xFFFFFFF8);
        this->set_intangible();
        state_timer = 0;
        step = 0;
        break;
    case 3:
        if (state_timer == 2) {
            transition_enemy_state(5);
        } else if (state_timer == 3) {
            transition_enemy_state(1);
        }
        break;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (update_linked_position(300.0f) != 0) {
                state_timer = 2;
            } else {
                step = step + 1;
                if (step >= 0x3C) {
                    state_timer = 1;
                    fade.reset_color();
                    flags = (s32) (flags | 2);
                }
            }
            break;
        case 1:
            if (fade.decay_value_toward_floor() != 0) {
                state_timer = 3;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        break;
    }
}

void TObjEneDellBiter::update_walk_state(s32 reason) {
    f32 facing;
    s32 angle;
    DelbiterMovementParameters *delbiter_movement_parameters;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        this->clear_intangible();
        flags = (s32) (flags & 0xFFFFFFF8);
        state_timer = 0;
        return;
    case 3:
        if ((uaddr) current_target == 0U) {
            transition_enemy_state(4);
        } else if ((destination_distance >= TObjEneDellBiter__movement_params->rush_start_distance) && ((s32) rush_count < 2)) {
            transition_enemy_state(6);
        } else if ((s32) state_timer == 1) {
            transition_enemy_state(7);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (validate_or_update_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        }
        rotation_y = approach_angle_limited(rotation_y, angle = (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x300);
        part_rotation_x = TObjBoss2Tunnel::turn_toward_angle_limited((s32)rotation_y, (s32)part_rotation_x, (s32)angle, 0x200, 0x2000);
        delbiter_movement_parameters = TObjEneDellBiter__movement_params;
        if (destination_distance <= (f32) delbiter_movement_parameters->attack_distance) {
            facing = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
            if (facing >= cos_table_lookup(0x1800)) {
                state_timer = 1;
            }
        } else {
            this->move_clamped_on_ground(sin_table_lookup(rotation_y), cos_table_lookup(rotation_y), delbiter_movement_parameters->walk_speed);
        }
        this->check_collisions();
        fn_80305684();
        if ((is_passing_frame(7.0f) != 0) || (is_passing_frame(21.0f) != 0)) {
            this->update_attack_effect();
        }
        break;
    }
}

void TObjEneDellBiter::update_rush_state(s32 reason) {
    s32 hit;
    f32 t;
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(5);
        flags &= ~3;
        flags |= 4;
        state_timer = 0;
        step = 0;
        current_speed = TObjEneDellBiter__movement_params->rush_speed;
        rush_traveled = 0.0f;
        fill_value_array(attack_history);
        this->set_active();
        break;
    case 3:
        if (state_timer == 3) {
            combo_count = 0;
            rush_count++;
            flags &= ~8;
            if (this->try_howl() == 0 && this->try_laser() == 0) {
                transition_enemy_state(5);
            }
        }
        break;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (is_passing_frame(16.0f) != 0 || is_passing_frame(26.0f) != 0) {
                play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039E12)), &position, 0, 0);
                this->spawn_front_particle();
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 2;
                state_timer = 1;
                bodies->flags |= 0x700;
            }
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            rotation_y = approach_angle_limited(rotation_y, (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)), 0x280);
            part_rotation_x = TObjBoss2Tunnel::turn_toward_angle_limited((s32)rotation_y, (s32)part_rotation_x, (s32)rotation_y, 0x200, 0x2000);
            this->check_collisions();
            break;
        case 1:
            play_step_effect();
            if (validate_or_update_target() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            hit = 0;
            if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 30.0f * TObjEneDellBiter__movement_params->rush_speed) != 0) {
                hit = 1;
            }
            this->move_clamped_on_ground(destination_direction.x, destination_direction.z, TObjEneDellBiter__movement_params->rush_speed);
            rush_traveled += TObjEneDellBiter__movement_params->rush_speed;
            if (this->has_move_failures(1) != 0) {
                hit = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit = 1;
            }
            if (check_rush_collisions() != 0) {
                hit = 1;
            }
            if (enemy_validate_retained_target(this) != 0) {
                Vec v;
                VecCopy(&v, &current_target->position);
                subtract_vector(&v, &position);
                if (normalize_vector_xz(&v) >= 30.0f) {
                    if (v.x * sin_table_lookup(rotation_y) + v.z * cos_table_lookup(rotation_y) < 0.0f) {
                        hit = 1;
                    }
                }
            }
            if (hit != 0 || rush_traveled >= TObjEneDellBiter__movement_params->rush_distance) {
                state_timer = 2;
                step = 0;
                this->set_field_378(5);
                play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039B14)), &position, 0, 0);
            }
            break;
        case 2:
            step++;
            if (step >= 10) {
                this->requested_action = 3;
                fn_803058DC();
                if (this->get_flag_b4() != 0) {
                    flags &= ~4;
                    state_timer = 3;
                }
                current_speed *= 0.9f;
            }
            check_rush_collisions();
            this->move_clamped_on_ground(destination_direction.x, destination_direction.z, current_speed);
            break;
        }
        break;
    case 5:
        flags &= ~4;
        bodies->flags &= ~0x700;
        this->clear_field_388();
        break;
    }
}

#pragma fp_contract off

void TObjEneDellBiter::update_attack_state(s32 reason) {
    int angle;

    switch (reason) {
    case 4:
        this->requested_action = 4;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        fill_value_array(attack_history);
        saver->clear_segments();
        state_timer = 0;
        step = 0;
        rush_count = 0;
        return;
    case 3:
        if ((s32) step == 2) {
            combo_count = (combo_count + 1);
            if ((s32) combo_count >= 2) {
                combo_count = 0;
                flags = (s32) (flags & 0xFFFFFFF7);
            }
            if (this->try_laser() == 0) {
                transition_enemy_state(5);
            }
        }
        break;
    case 0:
        advance_animation();
        angle = rotation_y;
        part_rotation_x = TObjBoss2Tunnel::turn_toward_angle_limited((s32)angle, (s32)part_rotation_x, (s32)angle, 0x200, 0x2000);
        switch (step) {
        case 0:
            if (is_passing_frame(11.0f) != 0) {
                this->spawn_front_particle();
            }
            update_contact_attacks();
            if (is_passing_frame(10.8f) != 0) {
                play_sound_effect((int) (this->remap_sound_for_area((saddr)((void *) (0x40039E16)))), &position, 0, 0);
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0;
                step = 1;
                state_timer = 0;
            }
            break;
        case 1:
            state_timer = (state_timer + 1);
            if ((s32) state_timer >= (s32) TObjEneDellBiter__movement_params->state_duration) {
                step = 2;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        break;
    }
}

void TObjEneDellBiter::update_howl_state(s32 reason) {
    Vec effect_position;
    f32 current_frame;
    TParticleCtrl *emitter;
    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 1) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        (advance_animation());
        if (this->get_flag_b4() != 0) {
            state_timer = 1;
        } else {
            if (effect != NULL) {
                if (is_passing_frame(45.0f) != 0) {
                    effect->queue_destruction();
                    effect = NULL;
                } else {
                    current_frame = this->frame;
                    if ((current_frame >= 1.0f) && (current_frame <= 45.0f)) {
                        VecCopy(&effect_position, &position);
                        effect_position.y += 10.0f;
                        effect->set_position(&effect_position);
                    }
                }
            } else if (is_passing_frame(1.0f) != 0) {
                effect = (TParticleCtrl *)create_particle_emitter((&position), 0x211);
            }
            if (is_passing_frame(11.0f) != 0) {
                this->confuse_nearby_players();
                play_sound_effect(this->remap_sound_for_area(0x40039E15), &position, 0, 0);
            }
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        emitter = effect;
        if (emitter != NULL) {
            emitter->queue_destruction();
            effect = NULL;
        }
        break;
    }
}

void TObjEneDellBiter::update_change_state(s32 reason) {
    Vec effect_position;

    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 1) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (is_passing_frame(23.0f) != 0) {
            VecCopy(&effect_position, &position);
            effect_position.y += 10.0f;
            if ((s32) game_difficulty_selection == 3) {
                spawn_particle_effect(&effect_position, 0x21D);
                spawn_particle_effect(&effect_position, 0x21E);
            } else {
                spawn_particle_effect(&effect_position, 0x21B);
                spawn_particle_effect(&effect_position, 0x21C);
            }
        }
        if (is_passing_frame(11.0f) != 0) {
            play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039E15)), &position, 0, 0);
        }
        if (this->get_flag_b4() != 0) {
            state_timer = 1;
            flags = (s32) (flags | 0x10);
            effect_timer = (s32) (30.0f * (f32) TObjEneDellBiter__movement_params->effect_duration);
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneDellBiter::update_laser_state(s32 reason) {
    f32 power;
    s32 drained;
    void *p;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        step = 0;
        drained_tp = 0;
        target_angle = 0;
        return;
    case 3:
        if ((s32) state_timer == 4) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (select_farthest_visible_player() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                target_angle = (s32) (u16) (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                state_timer = 1;
            } else {
                state_timer = 4;
            }
            break;
        case 1:
            rotation_y = approach_angle_limited(rotation_y, target_angle, 0x300);
            if ((s32) (u16) rotation_y == (s32) target_angle) {
                state_timer = 2;
                this->requested_action = 5;
            }
            fn_80305684();
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    step = (step + 1);
                    if ((s32) step < 3) {
                        if (select_farthest_visible_player() != 0) {
                            this->enemy_copy_target_destination();
                            this->update_velocity();
                            target_angle = (s32) (u16) (s32) (10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z));
                            state_timer = 0;
                            this->requested_action = 1;
                        } else {
                            state_timer = 4;
                        }
                    } else {
                        state_timer = 4;
                    }
                } else {
                    state_timer = 4;
                }
            }
            if (is_passing_frame(14.0f) != 0) {
                drained = drained_tp;
                power = (f32) TObjEneDellBiter__movement_params->tp_attack_power;
                if (drained > 0x96) {
                    power *= 2.0f;
                } else if (drained > 0x46) {
                    power *= 1.5f;
                }
                new TObjEneDellBiter_Eff_TpAbsorb1(this, this, &part_positions[0], target_angle, attack_history, power);
                play_sound_effect(this->remap_sound_for_area((saddr)((void *)0x40039F17)), &position, 0, 0);
            }
            if (is_passing_frame(1.0f) != 0) {
                spawn_particle_effect(&part_positions[0], 0x21F);
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        flags = (s32) (flags & 0xFFFFFFF7);
        break;
    }
}

void TObjEneDellBiter::update_damage_state(s32 reason) {
    Vec v;
    f32 len;
    switch (reason) {
    case 4:
        this->requested_action = 6;
        advance_animation();
        this->set_active();
        break;
    case 3:
        if (this->get_flag_b4() != 0 && this->check_low_hp_transition() == 0 &&
            this->try_howl() == 0 && this->try_laser() == 0) {
            transition_enemy_state(next_mode);
        }
        break;
    case 0:
        advance_animation();
        VecCopy(&v, (const Vec *)&velocity.x);
        len = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, len);
        velocity.x *= 0.8f;
        velocity.z *= 0.8f;
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneDellBiter::state_death(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 9;
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 2);
        this->disable_body_collision();
        refresh_and_send_entity_flags();
        fade.start_fade_out();
        if (get_current_floor_area() == AREA_TOWER) {
            play_sound_effect(0x4003A358, &position, 0, 0);
        } else {
            play_sound_effect((int)(this->remap_sound_for_area((saddr)((void *)(0x4003A31A)))), &position, 0, 0);
        }
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 2) {
            queue_destruction();
        }
        return;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (this->get_flag_b4() != 0) {
                fn_800D911C(&body_center);
                play_sound_effect(0x4003A830, &body_center, 0, 0);
                state_timer = 1;
                return;
            }
            break;
        case 1:
            if (fade.decay_value_toward_floor() != 0) {
                TObjPlayer::apply_effect_variant_b(&position, 0);
                state_timer = 2;
                return;
            }
            break;
        default:
            state_timer = 2;
            return;
        }
        break;
    case 5:
        queue_destruction();
        break;
    }
}

void TObjEneDellBiter::step_demo_script(NJS_OBJECT *) {
    Vec *pos;
    switch (TObjEneDellBiter__demo_script_step) {
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    case 8:
        rotate_matrix_x(0, TObjEneDellBiter__demo_rotate_x_angle);
        break;
    case 12:
    case 22:
    case 32:
        pos = TObjEneDellBiter__demo_script_cursor;
        TObjEneDellBiter__demo_script_cursor = pos + 1;
        forward_transform_to_view((const Vec *)&dellbiter_demo_camera_vec, pos);
        break;
    }
    TObjEneDellBiter__demo_script_step += 1;
}

void TObjEneDellBiter::render() {
    s32 cam;
    s32 vis;
    RenderFadeState *camera_fade;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (flags & 1) {
        vis = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        if (get_current_floor_area() == AREA_TOWER) {
            vis = classify_actor_view_detail(600.0f, 600.0f, 15.0f);
        } else {
            vis = classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
        }
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0) {
        if (render_model_if_visible() != 0) {
            return;
        }
        if (!(flags_3c4 & 0x4000)) {
            Vec v = { 2.0f, 1.0f, 5.0f };
            TObjEneDD::draw_ground_shadow(&v, 0);
        }
        update_secondary_light();
        TObjEneDellBiter__demo_script_step = 0;
        TObjEneDellBiter__demo_rotate_x_angle = part_rotation_x;
        TObjEneDellBiter__demo_script_cursor = part_positions;
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw = 1;
        camera_fade = &camera_fades[cam];
        camera_fade->update();
        cam = camera_fade->updateFromCamera((const f32*)(&body_center));
        if (flags & 2) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw = 0;
            }
        } else if (cam != 0) {
            camera_fade->set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw = 0;
            }
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, 0.6f, 0.6f, 0.6f);
            set_chunk_model_node_callback(TObjEneDellBiter::step_demo_script);
            if (vis == 1) {
                this->draw();
            } else {
                draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        if (flags & 2) {
            fade.clear_flag_and_notify();
        } else if (cam != 0) {
            camera_fade->clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
    } else if (is_split_screen() == 0) {
        for (i = 0; i < 3; i++) {
            VecCopy(&part_positions[i], (const Vec *)(&body_center));
        }
    }
}

void TObjEneDellBiter::run_demo_task() { if (get_target_info() != 0) { this->init_target_offsets(); } }

#pragma pool_data off
void TObjEneDellBiter::render_demo() {
    if (this->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), "HOWL PER(+0.3f)");
        debug_printf_at(pack_debug_text_position(0, 3), "CONFUSE PER(+0.3f)");
        debug_printf_at(pack_debug_text_position(0, 4), "CONFUSE DIST(+30.f)");
        debug_printf_at(pack_debug_text_position(0, 5), "LASER PER(+0.3f)");
        debug_printf_at(pack_debug_text_position(0, 6), "CHANGE PER(+0.05f)");
        if ((s32) run_type == 1) {
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE:RUN");
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), "TYPE:STAND");
        }
    }
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        Vec v = { 1.0f, 1.0f, 3.0f };
        TObjEneDD::draw_ground_shadow(&v, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 0.6f, 0.6f, 0.6f);
        set_motion_packed_rotation();
        draw_chunk_object(model);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
#pragma pool_data reset

s32 TObjEneDellBiter::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&reflection_position) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, 0.6f, 0.6f, 0.6f);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}
