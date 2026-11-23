#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/dragon/TBoss1DragonEffBullet.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"

extern "C" {
extern const s32 lbl_80435410[] = {0x224, 0x226, 0x229};
extern const s32 lbl_8043541C[] = {0x20A, 0x208, 0xC9};
extern const char TBoss1DragonEffBullet__class_name_string[] = "TBoss1DragonEffBullet";
const char *TBoss1DragonEffBullet__name = TBoss1DragonEffBullet__class_name_string;
const s32 *dragon_fireball_particle_ids;
}

void TBoss1DragonEffBullet::render() {}

#pragma push
#pragma fp_contract on
void TBoss1DragonEffBullet::run_task() {
    switch (state) {
    case 0: {
        f32 step = 25.0f;
        traveled_distance += step;
        f32 distance = traveled_distance;
        f32 target = target_distance;
        if (distance > target) {
            lifetime = 0;
            step = target - (distance - step);
            state = 1;
        }
        position.x += direction.x * step;
        position.y += direction.y * step;
        position.z += direction.z * step;
        if (trail == NULL) {
            trail = spawn_continuous_particle_effect_with_flags(&position, dragon_fireball_particle_ids[0], 0x40);
        }
        if (trail != NULL) {
            trail->set_position(&position);
        }
        if (secondary_emitter != NULL) {
            secondary_emitter->set_position(&position);
        }
        return;
    }
    case 1:
        lifetime += 1;
        if (lifetime == 1) {
            spawn_particle_effect_with_flags(&position, dragon_fireball_particle_ids[1], 0x40);
            if (secondary_emitter != NULL) {
                secondary_emitter->queue_destruction();
                secondary_emitter = NULL;
            }
            if (trail != NULL) {
                trail->queue_destruction();
                trail = NULL;
            }
            play_sound_effect(0x4003AD0C, &position, 0, 0);
            ((TBoss1Dragon *)TBoss1Dragon::get_instance())->apply_fireball_impact_damage(&position);
        }
        if (lifetime <= 2) {
            spawn_particle_effect_with_flags(&position, dragon_fireball_particle_ids[2], 0x40);
            return;
        }
        state = 2;
        return;
    case 2:
        lifetime += 1;
        if (lifetime > 100) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TBoss1DragonEffBullet::~TBoss1DragonEffBullet() {
    if (secondary_emitter != NULL) {
        secondary_emitter->queue_destruction();
        secondary_emitter = NULL;
    }
    if (trail != NULL) {
        trail->queue_destruction();
        trail = NULL;
    }
}

TBoss1DragonEffBullet::TBoss1DragonEffBullet(TObject *parent, const Vec *start, const Vec *target)
    : TObject(parent) {
    m_name = TBoss1DragonEffBullet__name;
    VecCopy(&position, start);
    VecCopy(&direction, target);
    subtract_vector(&direction, &position);
    target_distance = normalize_vector_safe(&direction);
    traveled_distance = 0.0f;
    lifetime = 0;
    state = 0;
    trail = NULL;
    secondary_emitter = NULL;
    play_sound_effect(0x4003B20B, &position, 0, 0);
}

void TBoss1Dragon::select_fireball_particle_table() {
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        dragon_fireball_particle_ids = lbl_80435410;
        return;
    case 1:
        dragon_fireball_particle_ids = lbl_8043541C;
        return;
    }
}
