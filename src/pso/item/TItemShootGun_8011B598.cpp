#include "pso/TItemShootGun.h"
#include "pso/TItemShoot.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/unk/text_80087278.h"

u32 TItemShootGun::create(s32 owner, s32 pos, s32 endpoint, f32 life) {
    TItemShootGun* result;

    spawn_particle_effect((void *)pos, 0x1BF);
    result = new TItemShootGun((void *)owner, (const Vec *)pos,
                              (const Vec *)endpoint, life);
    if (result != 0) {
        result->set_texture_id(4);
    }
    return (u32) result;
}
