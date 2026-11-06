#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemEffHeaven.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"

const char *TItemEffHeaven__class_name = "TItemEffHeaven";

void TItemEffHeaven::run_task() {
    s32 i;
    s32 j;

    if (target == NULL) {
        target = resolve_hittable_target(target_id, body_index);
        if (target != NULL) {
            VecCopy(&position, &target->bodies[body_index].center);
        }
    }
    if (frame == 0) {
        emitters[0] = spawn_continuous_particle_effect_with_flags(&position, 0x13B, 0x40);
    }
    if (frame == 15) {
        play_sound_effect(0x4002A408, &position, 0, 0);
        emitters[1] = spawn_continuous_particle_effect_with_flags(&position, 0x134, 0x40);
        rise_speed = 200.0f;
    }
    if (frame >= 15 && frame < 25) {
        rise_speed -= 20.0f;
        position.y += rise_speed;
    }
    if (frame == 25) {
        for (i = 0; i != 2; i++) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = NULL;
        }
        if (attacker != NULL && target != NULL) {
            DirectAttackPayload payload;
            payload.kind = 4;
            payload.power = 2000.0f;
            target->receive_direct_attack(attacker, payload, NULL, -1, -1);
        }
    }
    if (frame == 20) {
        emitters[2] = spawn_continuous_particle_effect_with_flags(&position, 0x139, 0x40);
    }
    if (frame == 40) {
        TParticleCtrl::release(emitters[2]);
        emitters[2] = NULL;
        queue_destruction();
        return;
    }
    for (j = 0; j != 3; j++) {
        if (emitters[j] != NULL) {
            emitters[j]->set_position(&position);
        }
    }
    target = NULL;
    frame++;
}

TItemEffHeaven::~TItemEffHeaven() {
    for (int i = 0; i != 3; i++) {
        TParticleCtrl::release(emitters[i]);
    }
}

TItemEffHeaven::TItemEffHeaven(TObject *parent, TObjPlayer *attacker, u16 target_id, s32 body_index)
    : TObject(parent) {
    s32 i;
    m_name = TItemEffHeaven__class_name;
    this->target_id = target_id;
    target = NULL;
    this->attacker = attacker;
    this->body_index = body_index;
    position.z = 0.0f;
    position.y = 0.0f;
    position.x = 0.0f;
    frame = 0;
    for (i = 0; i < 3; i++) {
        emitters[i] = NULL;
    }
    disallow_rendering();
}

void spawn_heaven_effect(TObject *parent, TObjPlayer *attacker, u16 target_id, s32 body_index) {
    if (parent != NULL && target_id != 0xFFFF && attacker != NULL) {
        new TItemEffHeaven(parent, attacker, target_id, body_index);
    }
}
