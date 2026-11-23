#include "musyx/runtime/musyx_runtime_a.h"

extern "C" {

void sndSeqSpeed(u32 seqId, u16 speed) {
    hwDisableIrq();
    seqSpeed(seqId, speed);
    hwEnableIrq();
}

void sndSeqContinue(s32 seqId) {
    hwDisableIrq();
    seqContinue((s32)(seqId));
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
u16 seqGetMIDIPriority(u8 arg0, u8 arg1) {
    extern RecoveredGlobal_803AA0C0_lbl_80556E88 lbl_80556E88;
    return *(u16 *)((s8 *)((u8 *)(((u8 *)(&lbl_80556E88.value) + ((arg0 << 5) & 0x1FE0))) + ((arg1 * 2) & 0x1FE)) + 0);
}

}
