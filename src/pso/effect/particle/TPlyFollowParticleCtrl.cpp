// Built with -inline off,deferred (GAME_EXCEPTIONS in configure.py), which emits functions
// in reverse source order: bodies here run from the highest address down.

#pragma readonly_strings on
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/memory.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerCommands.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/quest/GlobalNewDelete.h"
#include "pso/effect/particle/TPlyFollowParticleCtrl.h"
#include "pso/player/TPlyPtclObjectLeftHand.h"
#include "pso/player/TPlyPtclObjectRightHand.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

const char *TPlyFollowParticleCtrl::class_name = "TPlyFollowParticleCtrl";
const char *TPlyPtclObjectLeftHand::class_name = "TPlyPtclObjectLeftHand";
const char *TPlyPtclObjectRightHand::class_name = "TPlyPtclObjectRightHand";
// The follow controller's one collision body: a sphere of radius 20.
CollisionBody ply_follow_collision_body = {
    { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

Vec *TPlyFollowParticleCtrl::get_center() { return 0; }

u16 TPlyFollowParticleCtrl::get_owner_id() { return owner_id; }

PlayerHandParticlesBase::PlayerHandParticlesBase() {}

PlayerHandParticlesBase::~PlayerHandParticlesBase() {}

void PlayerFollowParticles::set_owner_id(u16 id) { owner_id = id; }

TPlyFollowParticleCtrl::TPlyFollowParticleCtrl(TObjBase *owner) : TObjCollidable(tl_06) {
    m_name = TPlyFollowParticleCtrl::class_name;
    set_collision_body(&ply_follow_collision_body);
    register_object_by_id();
    bodies->flags &= ~1;
    owner_id = owner->get_entity_id();
    pad_AE = 0xFFFF;
    set_position_from(&owner->center);
}

TPlyFollowParticleCtrl::~TPlyFollowParticleCtrl() {
    unregister_object_by_id();
    clear_collision_bodies();
}

// Ends itself once its player is gone.
void TPlyFollowParticleCtrl::run_task() {
    if (get_player_by_client_id(get_owner_id()) == NULL) {
        queue_destruction();
    }
}

TPlyPtclObjectLeftHand::TPlyPtclObjectLeftHand(TObjBase *owner) : TPlyFollowParticleCtrl(owner) {
    m_name = TPlyPtclObjectLeftHand::class_name;
}

TPlyPtclObjectLeftHand::~TPlyPtclObjectLeftHand() {}

// Follows the left hand (node 0x23).
Vec *TPlyPtclObjectLeftHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_owner_id());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x23, get_position_ptr());
    return get_position_ptr();
}

TPlyPtclObjectRightHand::TPlyPtclObjectRightHand(TObjBase *owner) : TPlyFollowParticleCtrl(owner) {
    m_name = TPlyPtclObjectRightHand::class_name;
}

TPlyPtclObjectRightHand::~TPlyPtclObjectRightHand() {}

// Follows the right hand (node 0x30) of the player it belongs to.
Vec *TPlyPtclObjectRightHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_owner_id());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x30, get_position_ptr());
    return get_position_ptr();
}

TParticleCtrl *emit_player_particle(void *owner, const Vec *position, s32 id) { return spawn_particle_effect(position, id); }

// The emitters below take target_id as an int while find_entity_by_id and set_owner_id
// take u16, and the int is passed on unconverted, so both are called through int prototypes.

s32 PlayerHandParticles::check_hit_by_id(u16 target_id, s32 id) {
    TObjCollidable *target = find_entity_by_id(target_id);
    if (target == NULL) {
        return 0;
    }
    TParticleCtrl *particle = spawn_particle_effect_with_flags(&target->center, id, 0x50);
    if (particle != NULL) {
        particle->set_owner_id(target_id);
    }
    return (saddr)particle;
}

TParticleCtrl *create_attached_oneshot_emitter(void *owner, u16 target_id, s32 id) {
    Angle3 direction;
    TObjCollidable *target = find_entity_by_id(target_id);
    if (target == NULL) {
        return NULL;
    }
    direction.y = 0;
    direction.x = 0;
    direction.z = -0x8000;
    TParticleCtrl *particle = (TParticleCtrl *)create_oneshot_particle_emitter(&target->center, &direction, id, 0x50);
    if (particle != NULL) {
        particle->set_owner_id(target_id);
    }
    return particle;
}

TParticleCtrl *emit_player_model_particle(PlayerHandParticles *owner, const Vec *position, s32 id, s32 model) {
    TParticleCtrl *emitter = emit_player_particle(owner, position, id);
    if (emitter) {
        attach_particle_model(emitter, TParticleCtrl::get_particle_model(model), TParticleCtrl::get_instance(), 0, 1, 1.0f);
    }
    return emitter;
}

void emit_player_sprite_particle(PlayerHandParticles *owner, const Vec *position, s32 id) {
    spawn_particle_effect_with_flags(position, id, 0x2000);
}

PlayerHandParticles::PlayerHandParticles() {
    left_hand = 0;
    right_hand = 0;
}

PlayerHandParticles::~PlayerHandParticles() {}

void PlayerHandParticles::create_left_hand(TObjBase *owner) {
    left_hand = new TPlyPtclObjectLeftHand(owner);
}

void PlayerHandParticles::create_right_hand(TObjBase *owner) {
    right_hand = new TPlyPtclObjectRightHand(owner);
}

void emit_water_step_particles(PlayerHandParticles *owner, const Vec *position) {
    emit_player_model_particle(owner, position, 0x237, 2);
    emit_player_model_particle(owner, position, 0x239, 0);
    emit_player_particle(owner, position, 0x238);
}

void emit_sand_step_particles(PlayerHandParticles *owner, const Vec *position) {
    emit_player_model_particle(owner, position, 0x23D, 2);
    emit_player_model_particle(owner, position, 0x23F, 0);
    emit_player_particle(owner, position, 0x23E);
}

void emit_idle_water_splash(PlayerHandParticles *owner, const Vec *position) {
    emit_player_sprite_particle(owner, position, 0xA2);
    emit_player_model_particle(owner, position, 0xA6, 2);
}


s32 PlayerHandParticles::check_hit_by_id_431(u16 target_id) { return check_hit_by_id(target_id, 431); }

PlayerFollowParticles::PlayerFollowParticles() {
    s32 i;
    Vec *p;
    pad_2 = 0xFFFF;
    owner_id = 0xFFFF;
    for (i = 0; i < 3; i++) {
        p = &contact_points[i];
        p->z = 0.0f;
        p->y = 0.0f;
        p->x = 0.0f;
    }
}

PlayerFollowParticles::~PlayerFollowParticles() {}

void PlayerFollowParticles::set_owner(TObjBase *owner) {
    set_owner_id(owner->get_entity_id());
}

void PlayerFollowParticles::create_hand_particles(TObjBase *owner) {
    hands.create_left_hand(owner);
    hands.create_right_hand(owner);
}

void TObjPlayer::clear_foot_stamp(PlayerFollowParticles *particles, TObjPlayer *player) {
    TPlayerFootStamp::create(player, 0);
}

void TObjPlayer::enable_foot_stamp(PlayerFollowParticles *particles, TObjPlayer *player) {
    TPlayerFootStamp::create(player, 1);
}

