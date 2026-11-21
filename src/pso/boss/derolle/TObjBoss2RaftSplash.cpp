#include "pso/boss/derolle/TObjBoss2RaftSplash.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8003B138.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include <stdlib.h>

#pragma readonly_strings on

struct Stack_8003AED4 {
    s32 sp8;
    f32 spC;
};

void TObjBoss2RaftSplash::run_task() {
    u8 *arg0 = (u8 *)this;
    Stack_8003AED4 stack;
    f32 timer;
    f32 interval;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + **(f32 **)((s8 *)arg0 + 0x24));
    timer = *(f32 *)((s8 *)arg0 + 0x1C);
    interval = *(f32 *)((s8 *)arg0 + 0x20);
    if (timer >= interval) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (timer - interval);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
        stack.spC += **(f32 **)((s8 *)arg0 + 0x24) - boss2_tunnel_max_scroll_speed;
        TObjBoss2RaftSplash::spawn_splash((saddr) &stack.sp8, 0x170, (saddr)(arg0 + 0x34));
    }
}
TObjBoss2RaftSplash::~TObjBoss2RaftSplash() {}

extern "C" {
const char *lbl_805D2700 = "TObjBoss2RaftSplash";
}
#define object ((u8 *)this)
TObjBoss2RaftSplash::TObjBoss2RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed) : TObject(parent) {
    ((TObjBoss2RaftSplash *)object)->m_name = lbl_805D2700;
    *(f32 *)((s8 *)object + 0x20) = (f32) (boss2_tunnel_max_scroll_speed * (3.0f + rand_signed_unit()));
    *(f32 *)((s8 *)object + 0x1C) = (f32) (*(f32 *)((s8 *)object + 0x20) * (3.0517578e-05f * (f32) rand()));
    VecCopy((Vec *)(object + 0x28), position);
    VecCopy((Vec *)(object + 0x34), offset);
    *(f32 **)((s8 *)object + 0x24) = speed;
}
#undef object

// The particle helpers below share this TU's .sdata2 pool: -5.0f (0x805D85D8, before the pad that
// ends the pool) is used by TObjBoss2CeilJunk::create_particle and TObjBoss2Tunnel__sub_8003B1D8,
// and the .text runs on without a pool of its own (twin: TObjBoss7RaftSplash.cpp).
void TObjBoss2CeilJunk::create_particle(const void *position, s32 particle_index) {
    TObjBoss2Tunnel::create_particle_effect(position, particle_index, -5.0f);
}

void TObjBoss2RaftSplash::spawn_splash(saddr position, s32 particle_index, saddr offset) {
    void *particle;

    particle = TObject::operator new(0x78);
    if (particle != NULL) {
        particle = initialize_flagged_particle(particle, reinterpret_cast<const void *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, (u16)0x40);
    }
    if (particle != NULL) {
        ((TObject *)particle)->run_task();
        ((TObjBoss2Tunnel *)particle)->detach_children((void *)offset);
    }
}

void TObjBoss2Tunnel::create_particle_effect(const void *position, s32 particle_index, f32 speed) {
    void *particle;

    particle = TObject::operator new(0x78);
    if (particle != NULL) {
        particle = initialize_flagged_particle(particle, reinterpret_cast<const void *>(position), TParticleCtrl::get_particle_by_index(particle_index), 1, 0, 0, 1, (u16)0x40);
    }
    if (particle != NULL) {
        ((TObject *)particle)->run_task();
        release_children(particle, speed);
    }
}

void TObjBoss2Tunnel__sub_8003B1D8(void *particle) {
    TObjBoss2Tunnel::release_children(particle, -5.0f);
}
