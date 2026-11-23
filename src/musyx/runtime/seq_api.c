#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

extern "C" {

void sndSeqSpeed(u32 seqId, u16 speed) {
    hwDisableIrq();
    seqSpeed(seqId, speed);
    hwEnableIrq();
}

void sndSeqContinue(s32 seqId) {
    hwDisableIrq();
    seqContinue(seqId);
    hwEnableIrq();
}

void sndSeqMute(s32 seqId, s32 mask1, s32 mask2) {
    hwDisableIrq();
    seqMute(seqId, mask1, mask2);
    hwEnableIrq();
}

void sndSeqVolume(u8 volume, u16 time, u32 seqId, u8 mode) {
    hwDisableIrq();
    seqVolume(volume, time, seqId, mode);
    hwEnableIrq();
}

u16 seqGetMIDIPriority(u8 midiSet, u8 midi) {
    return seqMIDIPriority[midiSet][midi];
}

}
