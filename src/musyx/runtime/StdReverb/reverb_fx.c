#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

void sndAuxCallbackReverbHI(u8 reason, Info_803BF884 *info, S_803BF408 *rev) {
    switch (reason) {
    case 0:
        if (rev->disabled == 0) {
            ReverbHICallback(info->left, info->right, info->surround, rev);
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
