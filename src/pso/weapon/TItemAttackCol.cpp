#pragma readonly_strings on
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemAttackColBase.h"
#include <stddef.h>
#include "pso/weapon/TItemAttackCol.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/AngleLookup.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include <string.h>
#include "pso/technique/TTecCtrl.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/map/CsnQuery.h"
#include "pso/item/item_pmt.h"
#include "pso/render/render_util.h"

// The collider render() is drawing, and how many of its model's nodes have been drawn.
TItemAttackCol *attack_collider_render_owner;

int attack_collider_active_count;


extern "C" void apply_extra_node_transform(TItemAttackCol *col, NJS_OBJECT *node);


const char *TItemAttackCol::name = "TItemAttackCol";

// The particle's direction before the collider's heading is added.
static Angle3 particle_direction = {0x4000, 0, 0x4000};
TItemAttackColBase::TItemAttackColBase(TObject *parent, AttackColParams *params) : TObject(parent) {
    TObjPlayer *player;
    body.offset.x = 0.0f;
    body.offset.y = 0.0f;
    body.offset.z = 0.0f;
    body.radius = params->radius;
    body.half_width = 0.0f;
    body.shape = 0;
    body.flags = 0x41F07;
    body.center.x = 0.0f;
    body.center.y = 0.0f;
    body.center.z = 0.0f;
    body.defense = 0.0f;
    bodies = &body;
    body_count = 1;
    VecCopy(&position, &params->position);
    memset(hits, 0, sizeof(hits));
    hit_count = 0;
    hits_left = params->hits;
    client_id = params->client_id;
    room = params->room;
    item_id = params->item_id;
    accuracy = params->accuracy;
    damage_scale = params->damage_scale;
    attack_kind = params->attack_kind;
    hits_objects = 1;
    player = get_player_by_client_id(params->client_id);
    if (player != NULL) {
        if (player->pk_state.is_enabled() != 0) {
            hits_players = 1;
        } else {
            hits_players = 0;
        }
    } else {
        hits_players = 0;
    }
}

TItemAttackColBase::~TItemAttackColBase() {}

void TItemAttackColBase::check_hits() {
    s32 i;
    ActorBodyHit *hit;
    reset_global_table();
    collect_enemy_body_contacts((CollisionBodySet *)&bodies);
    if (hits_objects != 0) {
        collect_object_body_contacts((CollisionBodySet *)&bodies);
    }
    if (hits_players != 0) {
        collect_player_body_contacts((CollisionBodySet *)&bodies);
    }
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        hit = TObjOnlineEnding::get_attack_entry(i);
        if (try_add_hit_target(hit) != 0) {
            on_hit(hit);
            hits_left -= 1;
            if (hits_left == 0) {
                queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

void copy_actor_body_hit(ActorBodyHit *destination, const ActorBodyHit *source) {
    volatile ActorBodyHit *output = destination;
    const volatile ActorBodyHit *input = source;
    output->target = input->target;
    output->body = input->body;
}

s32 TItemAttackColBase::try_add_hit_target(const ActorBodyHit *hit) {
    s32 ok;
    ActorBodyHit *previous;
    s32 i;
    s32 flags;
    if (hit_count >= 8) {
        return 0;
    }
    if (client_id == hit->target->get_entity_id()) {
        return 0;
    }
    ok = 1;
    if (is_technique_ready() == 0 && hit->target->test_actor_flags(0x60000000) == 0x20000000
        && this->room != hit->target->get_room()) {
        ok = 0;
    }
    if (hit->target->test_actor_flags(0x04000000) != 0
        || ((flags = hit->target->bodies[hit->body].flags) & 0x02000000)
        || (flags & 0x1000) || (flags & 0x80)) {
        ok = 0;
    }
    if (ok != 0) {
        previous = hits;
        for (i = 0; i != hit_count; i++) {
            if (previous->target == hit->target && previous->body == hit->body) {
                return 0;
            }
            previous++;
        }
        if (obj_is_hit_receivable(hit->target) != 0) {
            copy_actor_body_hit(previous, hit);
            hit_count += 1;
            return 1;
        }
    }
    return 0;
}

void TItemAttackColBase::on_hit(ActorBodyHit *hit) { resolve_attack_col_hit(hit); }

s32 TItemAttackColBase::has_game_join_id() {
    return find_equipped_item(item_id) != 0;
}

s32 TItemAttackColBase::resolve_attack_col_hit(ActorBodyHit *hit) {
    ItemSoundRequest sound;
    CollisionBody *target_body;
    s32 damage;
    TObjChara *target;
    TObjPlayer *player;
    TItem *item;
    s32 kind;
    f32 dealt;
    target = (TObjChara *)hit->target;
    player = get_player_by_client_id(this->client_id);
    item = find_item_by_id((this->item_id));
    target_body = &hit->target->bodies[hit->body];
    if ((player != NULL) && (item != 0U) && (target->calc_distance_accuracy_penalty(player, target_body, NULL, this->accuracy) != 0)) {
        kind = this->attack_kind;
        dealt = 0.0f;
        switch (kind) {
        case 0:
            dealt = target->receive_physical_attack(player, this->damage_scale);
            break;
        case 1:
            dealt = target->receive_physical_attack(player, this->damage_scale);
            target->apply_knockback_from_attacker(player, 0.1f * dealt);
            break;
        case 2:
            target->receive_weapon_special_attack(player, target_body);
            break;
        }
        damage = (s32) dealt;
        player->gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(player, damage));
        player->apply_camera_shake(target, damage);
        sound.clear();
        sound.group = item->get_item_group();
        sound.index = item->get_item_index();
        sound.player = player;
        sound.target = target;
        sound.collider = hit->body;
        play_weapon_hit_sound(&sound);
        return 1;
    }
    return 0;
}

void reset_attack_params(AttackColParams *params) {
    params->position.x = 0.0f;
    params->position.y = 0.0f;
    params->position.z = 0.0f;
    params->radius = 5.0f;
    params->hits = 1;
    params->client_id = 0xFFFF;
    params->room = -1;
    params->item_id = -1;
    params->accuracy = 0.0f;
    params->damage_scale = 1.0f;
    params->attack_kind = 0;
}

WeaponEffectDescriptor *reset_weapon_effect_descriptor(WeaponEffectDescriptor *params) {
    reset_attack_params(params);
    params->flags = 0;
    params->model = NULL;
    params->texlist = 0;
    params->scale = 1.0f;
    params->spin[0] = 0;
    params->spin[1] = 0;
    params->spin[2] = 0;
    params->star_width = 3.0f;
    params->color.a = 1.0f;
    params->color.r = 1.0f;
    params->color.g = 1.0f;
    params->color.b = 1.0f;
    params->wall_effect = NULL;
    params->hit_effect = NULL;
    params->particle = -1;
    params->trail_particle = -1;
    return params;
}

void TItemAttackCol::create(TObject *parent, WeaponEffectDescriptor *params) {
    new TItemAttackCol(parent, params);
}

TItemAttackCol::TItemAttackCol(TObject *parent, WeaponEffectDescriptor *params) : TItemAttackColBase(parent, params) {
    m_name = TItemAttackCol::name;
    VecCopy(&start_position, &params->position);
    if (params->flags & 1) {
        VecCopy(&velocity, &params->direction);
        normalize_vector(&velocity);
        rotation[0] = -(s32)(10430.38043493439 * atan2_float(velocity.y, newton_sqrtf(velocity.x * velocity.x + velocity.z * velocity.z)));
        rotation[1] = (s32)(10430.38043493439 * atan2_float(velocity.x, velocity.z));
        rotation[2] = 0;
    } else {
        velocity.x = sin_table_lookup(params->rotation_y);
        velocity.y = 0.0f;
        velocity.z = cos_table_lookup(params->rotation_y);
        rotation[0] = 0;
        rotation[1] = params->rotation_y;
        rotation[2] = 0;
    }
    velocity.x *= params->speed;
    velocity.y *= params->speed;
    velocity.z *= params->speed;
    rotation_y = rotation[1];
    range_sq = params->range * params->range;
    model = params->model;
    texlist = params->texlist;
    scale.x = params->scale;
    scale.y = params->scale;
    scale.z = params->scale;
    copy_xyz(spin, params->spin);
    extra_rotation[0] = 0;
    extra_rotation[1] = 0;
    extra_rotation[2] = 0;
    extra_scale[0] = 1.0f;
    extra_scale[1] = 1.0f;
    extra_scale[2] = 1.0f;
    hit_wall_flags.reset();
    if (params->flags & 2) {
        const StarLightParameters star = {
            params->star_width,
            7.0f,
            {{0, 255.0f * params->color.r, 255.0f * params->color.g, 255.0f * params->color.b}},
            0,
            20.0f,
        };
        star_light = spawn_star_light_2d(&position, &star, this);
    } else {
        star_light = NULL;
    }
    hit_wall = reinterpret_cast<TItemAttackColHitWall>(params->wall_effect);
    hit_object = reinterpret_cast<TItemAttackColHitObject>(params->hit_effect);
    flags = params->flags;
    if (params->flags & 0x800) {
        check_object_hits();
        if (hit_wall != NULL) {
            hit_wall(item_id, &position, &velocity);
        }
        particle = NULL;
        trail_particle = NULL;
        continuous_particle = NULL;
        queue_destruction();
        disallow_rendering();
    } else {
        check_hits();
        if (params->particle != -1) {
            particle = create_particle_emitter(&position, params->particle);
            if (particle != NULL) {
                s32 yaw = params->rotation_y;
                Angle3 direction = particle_direction;
                direction.x += yaw;
                particle->set_direction(&direction);
            }
        } else {
            particle = NULL;
        }
        if (params->trail_particle != -1) {
            trail_particle = create_particle_emitter(&position, params->trail_particle);
        } else {
            trail_particle = NULL;
        }
        if (params->flags & 0x10) {
            continuous_particle = spawn_continuous_particle_effect_with_flags(&position, 0x19E, 0x2000);
        } else {
            continuous_particle = NULL;
        }
    }
}

TItemAttackCol::~TItemAttackCol() {
    if (star_light != NULL) {
        star_light->queue_destruction();
        star_light = NULL;
    }
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
    if (trail_particle != NULL) {
        trail_particle->queue_destruction();
        trail_particle = NULL;
    }
    if (continuous_particle != NULL) {
        continuous_particle->queue_destruction();
        continuous_particle = NULL;
    }
}

void TItemAttackCol::run_task() {
    if (has_game_join_id() == 0) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (flags & 4) {
        shift_collision_bounds();
    }
    if (flags & 0x20) {
        spin[1] += 0x888;
    }
    this->move_by_velocity();
    if (star_light != NULL) {
        star_light->copy_position(&position);
    }
    if (particle != NULL) {
        particle->set_position(&position);
    }
    if (trail_particle != NULL) {
        trail_particle->set_position(&position);
    }
    if (continuous_particle != NULL) {
        continuous_particle->set_position(&position);
    }
    check_hits();
    if ((range_sq <= vec_distance_squared(&position, &start_position)) || (hit_wall_flags.test_flags_any(1) != 0)) {
        queue_destruction();
    }
}

void TItemAttackCol::render() {
    if ((s32)this->all_parents_unqueued_for_destruction() == 0 || find_equipped_item(item_id) == 0U) {
        return;
    }
    {
        if (model != NULL) {
            if (texlist != 0U) {
                set_texlist(texlist);
            }
            begin_effect_render();
            attack_collider_render_owner = this;
            attack_collider_active_count = 0;
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_by_node_angles(rotation, 1);
            rotate_matrix_by_node_angles(spin, 1);
            scale_current_matrix(&scale.x);
            draw_node_tree_with_callback(model, TItemAttackCol::add_to_active_list);
            pop_matrix();
            attack_collider_render_owner = 0;
            end_effect_render();
        }
    }
}

void TItemAttackCol::move_with_collision(Vec *to) {
    CsnHit *hit;
    hit = csnVector(&position, to, 0x8100);
    if (hit != NULL) {
        hit_wall_flags.set(1);
        VecCopy(&position, &hit->contact->point);
        if (hit_wall != NULL) {
            hit_wall(item_id, &position, &velocity);
        }
    } else {
        VecCopy(&position, to);
    }
}

void TItemAttackCol::move_by_velocity() {
    Vec next;

    VecCopy(&next, &velocity);
    vec3_add_to(&next, &position);
    move_with_collision(&next);
}

void TItemAttackCol::on_hit(ActorBodyHit *hit) {
    if (!(flags & 0x80)) {
        if (resolve_attack_col_hit(hit) != 0) {
            if (hit_object != NULL) {
                hit_object(item_id, hit, &velocity);
            }
            if (flags & 0x100) {
                damage_scale *= 0.75f;
            }
        }
    } else {
        if (hit_object != NULL) {
            hit_object(item_id, hit, &velocity);
        }
        if (flags & 0x200) {
            TItemWeapon *weapon = (TItemWeapon *)find_item_by_id(item_id);
            TObjPlayer *attacker = get_player_by_client_id(client_id);
            if (weapon != NULL) {
                weapon->deliver_hit(attacker, (TObjChara *)hit->target, attack_kind, damage_scale, hit->body);
            }
        }
    }
}

void TItemAttackCol::shift_collision_bounds() {
    spin[2] += 0xCCC;
    extra_rotation[2] -= 0xCCC;
}

void TItemAttackCol::add_to_active_list(NJS_OBJECT *node) { apply_extra_node_transform(attack_collider_render_owner, node); attack_collider_active_count = (attack_collider_active_count + 0x1); }

// Called for each node of the model before add_to_active_list counts it:
// with flag 8 the second node drawn gets the collider's extra rotation and scale.
void apply_extra_node_transform(TItemAttackCol *col, NJS_OBJECT *node) {
    if ((col->flags & 8) && attack_collider_active_count == 1) {
        rotate_matrix_by_node_angles(col->extra_rotation, 1);
        scale_current_matrix(col->extra_scale);
    }
}

void TItemAttackCol::check_object_hits() {
    s32 i;
    ActorBodyHit *hit;
    reset_global_table();
    collect_object_body_contacts((CollisionBodySet *)&bodies);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        hit = TObjOnlineEnding::get_attack_entry(i);
        if (try_add_hit_target(hit) != 0) {
            this->on_hit(hit);
            this->hits_left -= 1;
            if (this->hits_left == 0) {
                queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}
