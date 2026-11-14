#include "musyx/runtime/musyx_runtime_a.h"

extern "C" {

#define synthInfo (*(SynthInfo_803BAB54 *)&synthInfo)
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline s32 DoInit_803BAB54(u32 mixFrq, u32 aramSize, u32 numVoices, u32 flags) {
    u32 ret;
    ret = 0;
    dataInitStack();
    dataInit(0, (void *)aramSize);
    seqInit();
    synthIdleWaitActive = 0;
    synthInit(mixFrq, numVoices);
    streamInit();
    vsInit();
    s3dInit(flags);
    sndActive = 1;
    return ret;
}
s32 sndInit(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize) {
    s32 ret;
    u32 frq;
    ret = 0;
    sndActive = 0;
    if (voices <= 64) {
        synthInfo.voiceNum = voices;
    } else {
        synthInfo.voiceNum = 64;
    }
    if (studios <= 8) {
        synthInfo.studioNum = studios;
    } else {
        synthInfo.studioNum = 8;
    }
    synthInfo.maxMusic = music;
    synthInfo.maxSFX = sfx;
    frq = 32000;
    if ((ret = hwInit(&frq, synthInfo.voiceNum, synthInfo.studioNum, flags)) == 0) {
        ret = DoInit_803BAB54(32000, aramSize, synthInfo.voiceNum, flags);
    }
    return ret;
}
#pragma pop

}
