#include "types.h"
#include "pso/player/TObjPlayer_8011BA54.h"
#include "pso/unk/text_8011BE50.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 spawn_shoot_particle__10TObjPlayerFUlllf(u32, s32, s32, f32);
s32 create_shoot_model_with_particles(u32 owner, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = create_shoot_model__10TObjPlayerFUiiif(owner, arg1, arg2, farg0);
    temp_r3 = spawn_shoot_particle__10TObjPlayerFUlllf(owner, arg1, arg2, farg0);
    temp_r30 = temp_r3;
    if (((u32) temp_r31 != 0U) && ((u32) temp_r30 != 0U)) {
        *(s32 *)((s8 *)temp_r31 + 0x60) = 0x4000;
        ((TItemShootParticle *)temp_r3)->spawn_slot_emitter(0x1BB, 0);
        ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BC, 1);
        ((TObject *)temp_r30)->set_parent((TObject *)temp_r31);
    }
    return temp_r31;
}

}
