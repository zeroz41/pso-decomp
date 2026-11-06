#include "types.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
struct TItemShootParticle_8011B694 { u8 pad[0x1c]; f32 pos[3]; u8 pad28[0x58 - 0x28]; void *parts[2]; };

void TItemShootParticle::hook() {
    TItemShootParticle_8011B694 *self = (TItemShootParticle_8011B694 *)this;
    s32 i;
    for (i = 0; i != 2; i++) {
        if (self->parts[i] != 0) {
            ((TParticleCtrl *)self->parts[i])->set_position(self->pos);
            if (((TObject *)(self->parts[i]))->all_parents_unqueued_for_destruction() == 0) {
                self->parts[i] = 0;
            }
        }
    }
}
