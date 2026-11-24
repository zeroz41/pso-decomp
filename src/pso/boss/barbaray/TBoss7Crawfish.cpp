#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/system/BmlResourceDescriptor.h"


#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/ui/hud/TRaderMapCore.h"

const char *bm_boss7_crawfish_model_names[3] = { "minibaru_body.nj", "minibaru_body_b.nj", NULL };
const char *bm_boss7_crawfish_motion_names[7] = {
    "begin_begin_body.njm", "damage_damage_body.njm", "ride_ride_body.njm", "walk_walk_body.njm",
    "dive_dive_body.njm", "wait_wait_body.njm", NULL
};
BmlResourceDescriptor bm_boss7_crawfish_resource_descriptor = {
    "bm_boss7_crawfish.bml", bm_boss7_crawfish_model_names, bm_boss7_crawfish_motion_names, 2, 6
};
// The action table the ctor installs (name inferred).
TObjMotionAction crawfish_action_table[6] = {
    { 2, 3, 0, 0.6f, 0x0 },
    { 3, 0, 1, 0.6f, 0x0 },
    { 2, 5, 2, 0.7f, 0x0 },
    { 1, 0, 3, 0.6f, 0x0 },
    { 3, 0, 4, 0.6f, 0x0 },
    { 1, 0, 5, 1.9f, 0x0 },
};
const char *TBoss7Crawfish__class_name = "TBoss7Crawfish";
const CollisionBody crawfish_collision_body_desc = {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};
// is_visible measures the crawfish's distance from here (the arena centre is inferred).
const Vec boss7_arena_center = {0.0f, 0.0f, 0.0f};

// The record exchange_object_state reads and writes.
struct Boss7CrawfishStateRecord {
    s32 flags;
    u8 unk_4[0x2];
    s16 value;
};

// Defined without a shared declaration in their owners' headers.

BmlResource *TBoss7Crawfish__shared_resource;

s32 TBoss7Crawfish::is_within_x_limit() {
    return (u32) __cntlzw((u32) (75.0f < position.x)) >> 5;
}

void TBoss7Crawfish::register_attack_hits() {
    CollisionBodySet set;
    s32 i;
    ActorBodyHit *entry;
    s32 j;
    reset_global_table();
    set.colliders = &collision_body;
    set.count = 1;
    VecCopy(&set.position, &position);
    set.facing = rotation_y;
    TObjPlayer::apply_status_effect((saddr)&set);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        if ((u32)hit_count < 4) {
            entry = (ActorBodyHit *)TObjOnlineEnding::get_attack_entry(i);
            for (j = 0; j != hit_count; j++) {
                if (hits[j].target == entry->target && hits[j].body == entry->body) {
                    break;
                }
            }
            if (j == hit_count && obj_is_hit_receivable(entry->target) != 0) {
                hits[hit_count].target = entry->target;
                hits[hit_count].body = entry->body;
                hit_count++;
                apply_hit_to_target(entry);
            }
        }
    }
    reset_global_table();
}

void TBoss7Crawfish::play_persistent_sound_at_position(s32 sound_id) {
    play_persistent_sound(sound_id, this, &position, 0, 0);
}

void TBoss7Crawfish::spawn_effect(s32 sound_id) {
    play_sound_effect(sound_id, &position, 0, 0);
}

s32 TBoss7Crawfish::is_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (3600.0f < horizontal_distance_squared(&boss7_arena_center, &position)) {
            return 0;
        }
    } else if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return 0;
    }
    return 1;
}

void TBoss7Crawfish::free_child() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

void TBoss7Crawfish::spawn_ground_effects() {
    Vec ground;
    ground.x = position.x;
    ground.y = 0.0f;
    ground.z = position.z;
    spawn_particle_effect(&ground, 0x20D);
    spawn_particle_effect(&ground, 0x20E);
}

void TBoss7Crawfish::apply_hit_to_target(ActorBodyHit *hit) {
    DirectAttackPayload attack;
    TObjChara *target;

    if (hit != NULL) {
        target = (TObjChara *)hit->target;
        if (sub_80308AA8() != 0) {
            if (target->select_melee_contact_body(this, 1.0f) != 0) {
                target->receive_physical_attack(this, 1.0f);
            }
        } else if (target->obj_isState2_324() == 0) {
            if (game_difficulty_selection == 3) {
                if ((3.0517578125e-05f * (f32) rand()) <= 0.5f) {
                    attack.kind = 0x10;
                } else {
                    attack.kind = 0x10;
                }
            } else {
                attack.kind = 0x12;
            }
            attack.power = 100.0f;
            target->receive_direct_attack(this, attack, &hit->target->bodies[hit->body], -1, -1);
        }
    }
}

s32 TBoss7Crawfish::sub_80308AA8() {
    return 0.0f == parameters[0];
}

void TBoss7Crawfish::render() {
    if (is_visible() != 0) {
        set_texlist(texlist);
        set_motion_packed_rotation();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_yxz(0, rotation_x, rotation_y, rotation_z);
        scale_current_matrix(&scale.x);
        draw();
        pop_matrix();
        clear_motion_packed_rotation();
    }
}

void TBoss7Crawfish::clear_object_state_exchange() {
    Boss7CrawfishStateRecord record;
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
}

void TBoss7Crawfish::check_band_and_destroy() {
    if (is_passing_frame(14.0f) != 0) {
        spawn_ground_effects();
    }
    if (0.0f == get_health()) {
        queue_destruction();
    }
}

void TBoss7Crawfish::advance_to_band_check() { change_state(5); }

void TBoss7Crawfish::update() {
    if (is_passing_frame(8.0f) != 0) {
        spawn_ground_effects();
        spawn_effect(0x39E0D);
    }
    register_attack_hits();
    if (0.0f == get_health()) {
        queue_destruction();
    }
}

void TBoss7Crawfish::update_motion_and_release() {
    play_speed = 0.1f * (1.0f + params->speed);
    register_attack_hits();
    if (effect != NULL) {
        effect->set_position(&position);
    }
    if (try_move_by_delta(&velocity) == 0) {
        free_child();
        change_state(3);
        return;
    }
    play_persistent_sound_at_position(0x3A80C);
}

void TBoss7Crawfish::aim_at_nearest_player() {
    u16 player = find_nearest_visible_player(this, &velocity, 400.0f);
    f32 speed = 1.0f + params->speed;
    if (player != 0xFFFF) {
        normalize_vector(&velocity);
        velocity.x *= speed;
        velocity.y *= speed;
        velocity.z *= speed;
    } else {
        velocity.x = speed * sin_table_lookup(rotation_y);
        velocity.y = 0.0f;
        velocity.z = speed * cos_table_lookup(rotation_y);
    }
    rotation_y = 10430.38043493439 * atan2_float(velocity.x, velocity.z);
    change_state(2);
}

void TBoss7Crawfish::update_attack_state() {
    if (--attack_timer < 0) {
        change_state(1);
    }
    if ((get_floor() == 2) && (is_passing_frame(9.0f) != 0)) {
        CollisionBody *body = bodies;
        if (body->flags & 0x02000000) {
            body->flags &= ~0x02000000;
        }
        if (sub_80308AA8() != 0) {
            spawn_effect(0x3A80A);
        } else {
            spawn_effect(0x3A80B);
        }
    }
    if (bodies->flags & 0x02000000) {
        register_attack_hits();
    }
}

// Moves by delta when the new position is free and still inside the arena (names inferred); returns 1 if moved.
s32 TBoss7Crawfish::try_move_by_delta(const Vec *delta) {
    Vec next;
    s32 moved;

    next.x = position.x + delta->x;
    next.y = position.y + delta->y;
    next.z = position.z + delta->z;
    if (update_actor_ground_y_at(&next) != 0) {
        if (is_within_x_limit() != 0) {
            moved = 1;
            position.x = next.x;
            position.z = next.z;
        } else {
            moved = 0;
        }
    } else {
        moved = 0;
    }
    update_prev_position();
    return moved;
}

void TBoss7Crawfish::change_state(s32 state) {
    s32 i;
    mode = state;
    bodies->flags |= 0x02000000;
    switch (mode) {
    case 0:
        attack_timer = params->wait_time - 10;
        break;
    case 1:
        break;
    case 2:
        set_anim_timer(0);
        for (i = 0; i < 4; i++) {
            hits[i].target = NULL;
            hits[i].body = 0;
        }
        hit_count = 0;
        free_child();
        effect = create_particle_emitter(&position, 0x20B);
        break;
    case 3:
        set_anim_timer(4);
        break;
    case 4:
        spawn_effect(0x3990E);
        set_anim_timer(1);
        break;
    case 5:
        break;
    }
}

void TBoss7Crawfish::run_task() {
    if ((mode != 5) && (test_actor_flags(0x800) != 0)) {
        change_state(4);
    }
    switch (mode) {
    case 0:
        update_attack_state();
        break;
    case 1:
        aim_at_nearest_player();
        break;
    case 2:
        update_motion_and_release();
        break;
    case 3:
        update();
        break;
    case 4:
        advance_to_band_check();
        break;
    case 5:
        check_band_and_destroy();
        break;
    }
    refresh_collision_body_centers();
    if (!(bodies->flags & 0x02000000)) {
        submit_cursor_candidate(this, -1);
    }
    add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 2.0f);
    advance_animation();
}

TBoss7Crawfish::~TBoss7Crawfish() {
    unregister_object_by_id();
    clear_collision_bodies();
    free_child();
}

TBoss7Crawfish::TBoss7Crawfish(TObject *parent, void *set) : TObjEnemy(parent) {
    Vec still;
    m_name = TBoss7Crawfish__class_name;
    texlist = get_bml_texlist(TBoss7Crawfish__shared_resource, 0);
    copy_collision_body(&collision_body, &crawfish_collision_body_desc);
    set_collision_body(&collision_body);
    set_action_table(crawfish_action_table);
    set_motion_list(TBoss7Crawfish__shared_resource->motions);
    set_anim_timer(2);
    set_animation(requested_action);
    set_requested_action(requested_action);
    add_flags_2e4(2);
    apply_set_data(set);
    if (sub_80308AA8() != 0) {
        set_param(0x4A);
        bind_enemy_combat_stats(TLobby::register_boss(8), TLobby::dispatch_shared_handler_b(8), TLobby::register_object(8));
        params = (Boss7CrawfishParams *)TLobby::dispatch_shared_handler_a(8);
        model = get_bml_model(TBoss7Crawfish__shared_resource, 0);
    } else {
        set_param(0x4B);
        bind_enemy_combat_stats(TLobby::register_boss(9), TLobby::dispatch_shared_handler_b(9), TLobby::register_object(9));
        params = (Boss7CrawfishParams *)TLobby::dispatch_shared_handler_a(9);
        model = get_bml_model(TBoss7Crawfish__shared_resource, 1);
    }
    get_or_assign_entity_id(0);
    register_object_by_id();
    clear_object_state_exchange();
    change_state(0);
    still.z = 0.0f;
    still.y = 0.0f;
    still.x = 0.0f;
    try_move_by_delta(&still);
    if (sub_80308AA8() != 0) {
        scale.z = 0.8f;
        scale.y = 0.8f;
        scale.x = 0.8f;
    } else {
        scale.z = 1.0f;
        scale.y = 1.0f;
        scale.x = 1.0f;
    }
    effect = NULL;
}

void TBoss7Crawfish::destroy_instance() {
    if (TBoss7Crawfish__shared_resource != NULL) {
        delete TBoss7Crawfish__shared_resource;
        TBoss7Crawfish__shared_resource = NULL;
    }
}

void TBoss7Crawfish::load_static_resource() {
    TBoss7Crawfish__shared_resource = new BmlResource(5, &bm_boss7_crawfish_resource_descriptor, 0, 0, NULL);
}

void TBoss7Crawfish::apply_poison_status() {  }
void TBoss7Crawfish::apply_paralysis() {  }
void TBoss7Crawfish::apply_slow_status() {  }
void TBoss7Crawfish::apply_confusion_status() {  }
void TBoss7Crawfish::apply_movement_ailment(s32) {  }
void TBoss7Crawfish::apply_shock_status() {  }
void TBoss7Crawfish::clear_harmful_statuses() {  }
f32 TBoss7Crawfish::get_health() { return this->play_speed; }
void TBoss7Crawfish::set_anim_timer(s16 v) { this->requested_action = v; }
