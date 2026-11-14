#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

void sndAuxCallbackReverbHI(u8 arg0, u8 *arg1, u8 *arg2) {
    switch ((s32) arg0) {
    case 0:
        if ((u8) *(u8 *)((s8 *)arg2 + 0x1C4) == 0) {
            ReverbHICallback((void *)((int) (*(s32 *)((s8 *)arg1 + 0))), (void *)((int) (*(s32 *)((s8 *)arg1 + 4))), (void *)((int) (*(s32 *)((s8 *)arg1 + 8))), (S_803BF408 *)((void *) (arg2)));
        }
    case 1:
        return;
    }
}

void sndAuxCallbackPrepareReverbHI(Obj_803BE860 *self) {
    self->flag = 0;
    ReverbHICreate((SoundReverb*)self, self->a, self->c, self->b, self->d, self->e, self->f);
}

}
