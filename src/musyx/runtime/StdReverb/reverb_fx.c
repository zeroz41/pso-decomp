#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

void sndAuxCallbackReverbHI(u8 reason, SND_AUX_INFO *info, void *user) {
    switch (reason) {
    case 0:
        if (((S_803BF408 *)user)->disabled == 0) {
            ReverbHICallback(info->data.bufferUpdate.left, info->data.bufferUpdate.right,
                             info->data.bufferUpdate.surround, (S_803BF408 *)user);
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
