#include "musyx/musyx.h"
#include "pso/audio/SoundReverb.h"
#include "musyx/runtime/musyx_internal.h"

extern "C" {

void sndAuxCallbackReverbHI(u8 reason, SND_AUX_INFO *info, void *user) {
    switch (reason) {
    case 0:
        if (((SoundReverb *)user)->disabled == 0) {
            ReverbHICallback(info->data.bufferUpdate.left, info->data.bufferUpdate.right,
                             info->data.bufferUpdate.surround, (SoundReverb *)user);
        }
    case 1:
        return;
    }
}

void sndAuxCallbackPrepareReverbHI(SoundReverb *rev) {
    rev->disabled = 0;
    ReverbHICreate(rev, rev->parameterColoration, rev->parameterTime, rev->parameterMix,
                   rev->parameterDamping, rev->parameterPreDelay, rev->parameterCrossTalk);
}

}
