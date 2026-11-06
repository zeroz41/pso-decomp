#include "types.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TObject.h"

extern "C" {

u32 create_shoot_model__10TObjPlayerFUiiif();
u32 spawn_shoot_particle__10TObjPlayerFUlllf(s32, s32, s32, f32);

u32 TItemShoot::spawn_shoot_particle_attached(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    u32 temp_r31;
    u32 temp_r30;

    temp_r31 = create_shoot_model__10TObjPlayerFUiiif();
    temp_r30 = spawn_shoot_particle__10TObjPlayerFUlllf(arg0, arg1, arg2, farg0);
    if ((temp_r31 != 0U) && (temp_r30 != 0U)) {
        ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BD, 0);
        ((TObject *)temp_r30)->set_parent((TObject *)temp_r31);
    }
    return temp_r31;
}

}
