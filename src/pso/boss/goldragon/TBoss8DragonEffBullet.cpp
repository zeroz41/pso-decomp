#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/goldragon/TBoss8DragonEffBullet.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/TObjControl.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {
extern const DragonBulletParticles lbl_80474B68 = {0x224, 0x226, 0x229};
extern const DragonBulletParticles lbl_80474B74 = {0x21A, 0x218, 0x229};
extern const DragonBulletParticles lbl_80474B80 = {0x20A, 0x206, 0x209};
extern const char TBoss8DragonEffBullet__class_name_string[] = "TBoss8DragonEffBullet";
const char *TBoss8DragonEffBullet__name = TBoss8DragonEffBullet__class_name_string;
}

void TBoss8DragonEffBullet::render() {}

#pragma push
#pragma fp_contract on
void TBoss8DragonEffBullet::run_task() {
    switch (state) {
    case 0: {
        f32 step = 25.0f;
        traveled_distance += step;
        f32 current_distance = traveled_distance;
        f32 target = target_distance;
        if (current_distance > target) {
            lifetime = 0;
            step = target - (current_distance - step);
            state = 1;
        }
        position.x += direction.x * step;
        position.y += direction.y * step;
        position.z += direction.z * step;
        if (trail == NULL) {
            trail = spawn_continuous_particle_effect_with_flags(&position, particles->trail, 0x40);
        }
        if (mode == 3 && secondary_emitter == NULL) {
            secondary_emitter = spawn_continuous_particle_effect_with_flags(&position, 0x204, 0x40);
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
        lifetime++;
        if (lifetime == 1) {
            spawn_particle_effect_with_flags(&position, particles->impact, 0x40);
            if (secondary_emitter != NULL) {
                secondary_emitter->queue_destruction();
                secondary_emitter = NULL;
            }
            if (trail != NULL) {
                trail->queue_destruction();
                trail = NULL;
            }
            play_sound_effect(0x4003AD0C, &position, 0, 0);
            ((TBoss8Dragon *)get_enemy_entity(owner_id))->apply_fireball_impact_damage(&position, mode);
        }
        if (lifetime <= 2) {
            spawn_particle_effect_with_flags(&position, particles->burst, 0x40);
            return;
        }
        state = 2;
        return;
    case 2:
        lifetime++;
        if (lifetime > 100) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TBoss8DragonEffBullet::~TBoss8DragonEffBullet() {
    if (secondary_emitter != NULL) {
        secondary_emitter->queue_destruction();
        secondary_emitter = NULL;
    }
    if (trail != NULL) {
        trail->queue_destruction();
        trail = NULL;
    }
}

#pragma push
#pragma pool_data off
TBoss8DragonEffBullet::TBoss8DragonEffBullet(TObject *parent, const Vec *source,
                                           const Vec *target, s32 bullet_mode,
                                           u16 entity_id) : TObject(parent) {
    m_name = TBoss8DragonEffBullet__name;
    VecCopy(&position, source);
    VecCopy(&direction, target);
    subtract_vector(&direction, &position);
    target_distance = normalize_vector_safe(&direction);
    traveled_distance = 0.0f;
    lifetime = 0;
    state = 0;
    mode = bullet_mode;
    owner_id = entity_id;
    trail = NULL;
    secondary_emitter = NULL;
    play_sound_effect(0x4003B20B, &position, 0, 0);
    switch (mode) {
    case 1:
        particles = &lbl_80474B68;
        break;
    case 2:
        particles = &lbl_80474B74;
        break;
    case 3:
        particles = &lbl_80474B80;
        break;
    }
}

#pragma pop
