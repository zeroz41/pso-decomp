#include "pso/boss/barbaray/TObjBoss7RaftSplash.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/system/task/TObject.h"
#include <stdlib.h>
#include "pso/camera/TCameraCtrl.h"

#pragma readonly_strings on

// Defined without a shared declaration (TCameraCtrl.cpp).
extern "C" {
}

const char *TObjBoss7RaftSplash__name = "TObjBoss7RaftSplash";


void TObjBoss7RaftSplash::run_task() {
    Vec splash_position;
    if (TCameraCtrl::get_active_controller() != 5) {
        elapsed += *step;
        f32 timer = elapsed;
        f32 period = interval;
        if (timer >= period) {
            elapsed = timer - period;
            VecCopy(&splash_position, &position);
            splash_position.y += *step - boss7_tunnel_max_scroll_speed;
            spawn_splash(&splash_position, 0x200, &splash_offset);
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

void TObjBoss7Tunnel::create_particle(const Vec *position, s32 particle_index) {
    create_particle_effect(position, particle_index, -5.0f);
}

// The particle helpers below share this TU's .sdata2 pool: -5.0f (0x805DEC90) is used by
// TObjBoss7Tunnel::create_particle and TObjBoss7Tunnel::release_splash_children, and the .text runs on without a pool of its own.

void TObjBoss7RaftSplash::spawn_splash(const Vec *position, s32 particle_index, const Vec *offset) {
    TParticleCtrl *particle;

    particle = new TParticleCtrl(position, TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, 0x40);
    if (particle != NULL) {
        particle->run_task();
        TObjBoss7Tunnel::detach_children(particle, offset);
    }
}

void TObjBoss7Tunnel::create_particle_effect(const Vec *position, s32 particle_index, f32 speed) {
    TParticleCtrl *particle;

    particle = new TParticleCtrl(static_cast<const Vec *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, 0x40);
    if (particle != NULL) {
        particle->run_task();
        release_children(particle, speed);
    }
}

void TObjBoss7Tunnel::release_splash_children(TParticleCtrl *particle) {
    release_children(particle, -5.0f);
}
