#include "pso/boss/derolle/TObjBoss2RaftSplash.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include <stdlib.h>

#pragma readonly_strings on

void TObjBoss2RaftSplash::run_task() {
    Vec splash_position;
    elapsed += *step;
    f32 timer = elapsed;
    f32 period = interval;
    if (timer >= period) {
        elapsed = timer - period;
        VecCopy(&splash_position, &position);
        splash_position.y += *step - boss2_tunnel_max_scroll_speed;
        spawn_splash(&splash_position, 0x170, &splash_offset);
    }
}
TObjBoss2RaftSplash::~TObjBoss2RaftSplash() {}

extern "C" {
const char *TObjBoss2RaftSplash__name = "TObjBoss2RaftSplash";
}
TObjBoss2RaftSplash::TObjBoss2RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed)
    : TObject(parent) {
    m_name = TObjBoss2RaftSplash__name;
    interval = boss2_tunnel_max_scroll_speed * (3.0f + rand_signed_unit());
    elapsed = interval * (3.0517578e-05f * (f32)rand());
    VecCopy(&this->position, position);
    VecCopy(&splash_offset, offset);
    step = speed;
}

// The particle helpers below share this TU's .sdata2 pool: -5.0f (0x805D85D8, before the pad that
// ends the pool) is used by TObjBoss2CeilJunk::create_particle and TObjBoss2Tunnel::release_splash_children,
// and the .text runs on without a pool of its own (twin: TObjBoss7RaftSplash.cpp).
void TObjBoss2CeilJunk::create_particle(const Vec *position, s32 particle_index) {
    TObjBoss2Tunnel::create_particle_effect(position, particle_index, -5.0f);
}

void TObjBoss2RaftSplash::spawn_splash(const Vec *position, s32 particle_index, const Vec *offset) {
    TParticleCtrl *particle;

    particle = new TParticleCtrl(position, TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, 0x40);
    if (particle != NULL) {
        particle->run_task();
        TObjBoss2Tunnel::detach_children(particle, offset);
    }
}

void TObjBoss2Tunnel::create_particle_effect(const Vec *position, s32 particle_index, f32 speed) {
    TParticleCtrl *particle;

    particle = new TParticleCtrl(static_cast<const Vec *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, 0x40);
    if (particle != NULL) {
        particle->run_task();
        release_children(particle, speed);
    }
}

void TObjBoss2Tunnel::release_splash_children(TParticleCtrl *particle) {
    release_children(particle, -5.0f);
}
