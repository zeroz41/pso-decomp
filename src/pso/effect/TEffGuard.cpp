#include "pso/effect/TEffGuard.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#pragma readonly_strings on
const char* TEffGuard__class_name = "TEffGuard";
extern "C" {
s32 play_sound_effect(u32, const Vec*, s32, s32);
}

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
            queue_destruction__7TObjectFv(this);
        }
        return;
    }
}

TEffGuard::~TEffGuard() {}

TEffGuard::TEffGuard(const Vec* initial_position) : TEffect() {
    m_name = TEffGuard__class_name;
    VecCopy(&position, initial_position);
    state = 0;
}

void TEffGuard::create(const Vec* position) {
    new TEffGuard(position);
    play_sound_effect(0x4001AA00, position, 0, 0);
}
