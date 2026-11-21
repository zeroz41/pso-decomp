#include "pso/boss/barbaray/TObjBoss7RaftSplash.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/barbaray/TObjBoss7RaftSplash_802F18E8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include <stdlib.h>

#pragma readonly_strings on

// Defined without a shared declaration (TCameraCtrl.cpp, text_802F190C.cpp).
extern "C" {
u16 TCameraCtrl__sub_8006A5DC();
s32 fn_802F190C(void *particle, saddr offset);
s32 fn_802F1960(void *particle, f32 height);
}

const char *TObjBoss7RaftSplash__name = "TObjBoss7RaftSplash";


void TObjBoss7RaftSplash::run_task() {
    Vec splash_position;
    if (TCameraCtrl__sub_8006A5DC() != 5) {
        elapsed += *step;
        f32 timer = elapsed;
        f32 period = interval;
        if (timer >= period) {
            elapsed = timer - period;
            VecCopy(&splash_position, &position);
            splash_position.y += *step - boss7_tunnel_max_scroll_speed;
            TObjFish::create_splash_particle((saddr)&splash_position, 0x200, (saddr)&splash_offset);
        }
    }
}

TObjBoss7RaftSplash::~TObjBoss7RaftSplash() {}
TObjBoss7RaftSplash::TObjBoss7RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed)
    : TObject(parent) {
    m_name = TObjBoss7RaftSplash__name;
    interval = boss7_tunnel_max_scroll_speed * (3.0f + rand_signed_unit());
    elapsed = interval * (3.0517578e-05f * (f32)rand());
    VecCopy(&this->position, position);
    VecCopy(&splash_offset, offset);
    step = speed;
}

void TObjFish::spawn_default_particle(s32 position, s32 particle_index) {
    spawn_particle(position, particle_index, -5.0f);
}

// The TObjFish particle helpers below share this TU's .sdata2 pool: -5.0f (0x805DEC90) is used by
// spawn_default_particle and TObjFish__sub_802F18E8, and the .text runs on without a pool of its own.

void TObjFish::create_splash_particle(saddr position, s32 particle_index, saddr offset) {
    void *particle;

    particle = TObject::operator new(0x78);
    if (particle != NULL) {
        particle = initialize_flagged_particle(particle, reinterpret_cast<const void *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, (u16)0x40);
    }
    if (particle != NULL) {
        ((TObject *)particle)->run_task();
        fn_802F190C(particle, offset);
    }
}

void TObjFish::spawn_particle(saddr position, s32 particle_index, f32 height) {
    void *particle;

    particle = TObject::operator new(0x78);
    if (particle != NULL) {
        particle = initialize_flagged_particle(particle, reinterpret_cast<const void *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, (u16)0x40);
    }
    if (particle != NULL) {
        ((TObject *)particle)->run_task();
        fn_802F1960(particle, height);
    }
}

extern "C" void TObjFish__sub_802F18E8(void *particle) {
    fn_802F1960(particle, -5.0f);
}
