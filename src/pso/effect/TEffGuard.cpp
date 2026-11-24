#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/TEffGuard.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/system/SoundEffect.h"
#pragma readonly_strings on
const char *TEffGuard::class_name = "TEffGuard";

void TEffGuard::run_task() {
    s32 particle;
    switch (state) {
    case 0:
        particle = 0;
        state = 1;
        do {
            spawn_particle_effect(&position, particle);
            particle++;
        } while (particle < 4);
        return;
    case 1:
        age++;
        if (age > 60) {
            queue_destruction();
        }
        return;
    }
}

TEffGuard::~TEffGuard() {}

TEffGuard::TEffGuard(const Vec* initial_position) : TEffect() {
    m_name = class_name;
    VecCopy(&position, initial_position);
    state = 0;
}

void TEffGuard::create(Vec *position) {
    new TEffGuard(position);
    play_sound_effect(0x4001AA00, position, 0, 0);
}
