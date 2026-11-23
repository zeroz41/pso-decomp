#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/object/base/TObjBase.h"

const char *TItemEffFlame::class_name = "TItemEffFlame";

static void release_flame(TObject *flame);

void spawn_flame_wall_impact(TObject *parent, TItemEquipBase *weapon, const Vec *from, Vec *hit) {
    spawn_particle_effect(hit, 0x45);
    play_sound_effect(0x4001C112, NULL, 0, 0);
}

#pragma fp_contract on
void TItemEffFlame::run_task() {
    if (emitter == NULL) {
        return;
    }
    TObjCollidable *target = find_entity_by_id(target_id);
    if (target == NULL) {
        return;
    }
    CollisionBody *body = &target->bodies[body_index];
    Vec pos = body->center;
    pos.x += 5.0f * ((1.0f / 32768.0f) * rand());
    pos.y += 5.0f * ((1.0f / 32768.0f) * rand());
    pos.z += 5.0f * ((1.0f / 32768.0f) * rand());
    emitter->set_position(&pos);
}

TItemEffFlame::~TItemEffFlame() {
    TParticleCtrl::release(emitter);
}

TItemEffFlame::TItemEffFlame(TObject *parent, ActorBodyHit *hit) : TObject(parent) {
    m_name = class_name;
    target_id = hit->target->get_entity_id();
    body_index = hit->body;
    emitter = create_particle_emitter(&hit->target->bodies[body_index].center, 0x1BB);
    disallow_rendering();
}

void spawn_flame_effect(void *unused, ActorBodyHit *hit) {
    if (hit != NULL) {
        TItemEffFlame *flame = new TItemEffFlame(tl_05, hit);
        TItemAttacker::spawn_item_timer(flame, release_flame, 30);
    }
}

static void release_flame(TObject *flame) {
    flame->queue_destruction();
}
