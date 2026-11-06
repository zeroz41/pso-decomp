#include "pso/effect/TEffHit.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#pragma readonly_strings on
const char* TEffHit__class_name = "TEffHit";

void TEffHit::run_task() {
    Vec shifted_position;
    s32 particle;
    switch (state) {
    case 0:
        particle = 0;
        state = 1;
        do {
            if (particle == 2) {
                shifted_position.x = position.x;
                shifted_position.y = position.y - 15.0f;
                shifted_position.z = position.z;
                spawn_particle_effect(&shifted_position, particle + 4);
            } else if (particle == 3) {
                spawn_particle_effect(&position, 0xD);
            } else {
                spawn_particle_effect(&position, particle + 4);
            }
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

TEffHit::~TEffHit() {}

TEffHit::TEffHit(const Vec* initial_position) : TEffect() {
    m_name = TEffHit__class_name;
    VecCopy(&position, initial_position);
    state = 0;
}
