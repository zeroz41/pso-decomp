// Built with -inline off,deferred (GAME_EXCEPTIONS in configure.py), which emits functions
// in reverse source order: bodies here run from the highest address down.

#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/memory.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
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

void *TPlyFollowParticleCtrl::get_center() { return 0; }

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
void *TPlyPtclObjectLeftHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_owner_id());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x23, ((TObjPlayer *)this)->get_position_ptr());
    return ((TObjPlayer *)this)->get_position_ptr();
}

TPlyPtclObjectRightHand::TPlyPtclObjectRightHand(TObjBase *owner) : TPlyFollowParticleCtrl(owner) {
    m_name = TPlyPtclObjectRightHand::class_name;
}

TPlyPtclObjectRightHand::~TPlyPtclObjectRightHand() {}

// Follows the right hand (node 0x30) of the player it belongs to.
void *TPlyPtclObjectRightHand::get_center() {
    TObjPlayer *player = get_player_by_client_id(get_owner_id());
    if (player == NULL) {
        return NULL;
    }
    player->get_anim_node_position(0x30, ((TObjPlayer *)this)->get_position_ptr());
    return ((TObjPlayer *)this)->get_position_ptr();
}

TParticleCtrl *emit_player_particle(void *owner, const Vec *position, s32 id) { return spawn_particle_effect(position, id); }

// The emitters below take target_id as an int while find_entity_by_id and set_owner_id
// take u16, and the int is passed on unconverted, so both are called through int prototypes.

s32 TObjPlayer::check_hit_by_id(saddr owner, u16 target_id, s32 id) {
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
    ParticleAngles direction;
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

s32 emit_player_model_particle(saddr owner, saddr position, saddr entry, s32 model) {
    TParticleCtrl *emitter = emit_player_particle((void *)owner, (const Vec *)position, entry);
    if (emitter) {
        attach_particle_model(emitter, TParticleCtrl::get_particle_model(model), TParticleCtrl::get_instance(), 0, 1, 1.0f);
    }
    return (saddr)emitter;
}

void emit_player_sprite_particle(s32 owner, saddr position, s32 id) {
    spawn_particle_effect_with_flags((const Vec *)position, id, 0x2000);
}

PlayerHandParticles::PlayerHandParticles() {
    left_hand = 0;
    right_hand = 0;
}

PlayerHandParticles::~PlayerHandParticles() {}

void TObjPlayer::create_left_hand_ptcl(void *owner) {
    ((PlayerHandParticles *)this)->left_hand = new TPlyPtclObjectLeftHand((TObjBase *)owner);
}

void TObjPlayer::create_right_hand_ptcl(void *owner) {
    ((PlayerHandParticles *)this)->right_hand = new TPlyPtclObjectRightHand((TObjBase *)owner);
}

void emit_water_step_particles(saddr owner, saddr position) {
    emit_player_model_particle(owner, position, 0x237, 2);
    emit_player_model_particle(owner, position, 0x239, 0);
    emit_player_particle((void *)owner, (const Vec *)position, 0x238);
}

void emit_sand_step_particles(saddr owner, saddr position) {
    emit_player_model_particle(owner, position, 0x23D, 2);
    emit_player_model_particle(owner, position, 0x23F, 0);
    emit_player_particle((void *)owner, (const Vec *)position, 0x23E);
}

void emit_idle_water_splash(s32 owner, s32 position) {
    emit_player_sprite_particle(owner, position, 0xA2);
    emit_player_model_particle(owner, position, 0xA6, 2);
}


s32 TObjPlayer::check_hit_by_id_431(void* p, u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)p, target_id, 431); }

PlayerFollowParticles::PlayerFollowParticles() {
    s32 i;
    Vec *p;
    pad_2 = 0xFFFF;
    owner_id = 0xFFFF;
    for (i = 0; i < 3; i++) {
        p = &pad_C[i];
        p->z = 0.0f;
        p->y = 0.0f;
        p->x = 0.0f;
    }
}

PlayerFollowParticles::~PlayerFollowParticles() {}

void TObjPlayer::update_follow_particle(saddr owner) {
    ((PlayerFollowParticles *)this)->set_owner_id(((TObjBase *)owner)->get_entity_id());
}

void TObjPlayer::update_child(void *owner) {
    PlayerFollowParticles *state = (PlayerFollowParticles *)this;
    ((TObjPlayer *)&state->hands)->create_left_hand_ptcl(owner);
    ((TObjPlayer *)&state->hands)->create_right_hand_ptcl(owner);
}

void TObjPlayer::clear_foot_stamp(saddr owner, saddr player) {
    TPlayerFootStamp::create((void *)player, (void *)0);
}

void TObjPlayer::enable_foot_stamp(saddr owner, saddr player) {
    TPlayerFootStamp::create((void *)player, (void *)1);
}

