#include "types.h"
#include "pso/unk/text_8011BEF0.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/weapon/shoot/TItemShoot.h"

extern "C" {

s32 spawn_shoot_particle__10TObjPlayerFUlllf();

s32 spawn_shoot_particle_9f(void) {
    s32 temp_r3;

    temp_r3 = spawn_shoot_particle__10TObjPlayerFUlllf();
    if (temp_r3 != 0) {
        ((TItemShoot *)temp_r3)->set_particle_flags(4);
        ((TItemShootParticle *)temp_r3)->spawn_slot_emitter(0x9F, 0);
    }
    return temp_r3;
}

}
