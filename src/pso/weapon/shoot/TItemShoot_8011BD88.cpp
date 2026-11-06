#include "types.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/weapon/shoot/TItemShoot.h"

extern "C" {

s32 spawn_shoot_particle__10TObjPlayerFUlllf();

s32 TItemShoot::spawn_shoot_particle() {
    s32 temp_r3;

    temp_r3 = spawn_shoot_particle__10TObjPlayerFUlllf();
    if (temp_r3 != 0) {
        ((TItemShootParticle *)temp_r3)->spawn_slot_emitter(0x12, 0);
    }
    return temp_r3;
}

}
