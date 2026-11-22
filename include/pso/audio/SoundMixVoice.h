#ifndef PSO_SOUND_MIX_VOICE_H
#define PSO_SOUND_MIX_VOICE_H
#include "types.h"
#include "musyx/musyx.h"

struct SoundMixCoefficients {
    u16 left, right, surround;
};
struct SoundMixCurveOutput {
    f32 left, right, surround;
};
struct SoundStudioMixView {
    u8 unknown0[0x54];
    s32 mode;
    u8 unknown58[0xAC - 0x58];
    SND_AUX_CALLBACK auxAHandler;
    SND_AUX_CALLBACK auxBHandler;
    void *auxAUser;
    void *auxBUser;
};
struct SoundMixVoice {
    u8 unknown0[0x24];
    u32 changed;
    u8 unknown28[0x4C - 0x28];
    SoundMixCoefficients coefficients[3];
    u8 unknown5E[0xD0 - 0x5E];
    u16 leftDelay, rightDelay;
    u8 unknownD4[0xE5 - 0xD4];
    u8 dirty[3];
    u8 unknownE8[0xEF - 0xE8];
    u8 studio;
    u32 flags;
};
LAYOUT_ASSERT(SoundMixVoiceSize, sizeof(SoundMixVoice) == 0xF4);
LAYOUT_ASSERT(SoundStudioMixViewSize, sizeof(SoundStudioMixView) == 0xBC);

extern "C" void hwSetVolume(s32 voice, u32 volumeCurve, u32 pan,
    s32 surroundPan, f32 direct, f32 auxiliaryA, f32 auxiliaryB);
#endif
