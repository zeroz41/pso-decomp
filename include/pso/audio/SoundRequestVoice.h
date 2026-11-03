#ifndef PSO_SOUND_REQUEST_VOICE_H
#define PSO_SOUND_REQUEST_VOICE_H
#include "types.h"

struct SoundRequestOwner {
    u8 pad000[0x27C];
    f32 reverb;
};

struct SoundRequestVoice {
    SoundRequestVoice();
    ~SoundRequestVoice();

    SoundRequestOwner* owner;
    s32 state;
    u32 flags;
    s32 kind, bank, index, effect;
    void* actor;
    u32 token;
    s32 previousVolume, volume, previousPan, pan, previousSurround, surround;
    s32 base, extra, spatial, fade, fadeStep;
    s32 panExtra, panSpatial, surroundExtra, unused5C, surroundSpatial;
    s32 pitch, previousPitch, pitchStatic, pitchMoving, pitchVelocity;
    s32 pitchSlide, pitchTarget, pitchDuration, pitchRemaining;
    const void* position;
    s16 pitchLimit;
    u8 previousReverb, unused8F;
    s16 delay, refresh;
    s32 studio, age;
    f32 reverb;
};
#include <stddef.h>
typedef char SoundRequestVoice_size[sizeof(SoundRequestVoice) == 0xA0 ? 1 : -1];
typedef char SoundRequestVoice_previousReverb_offset[offsetof(SoundRequestVoice, previousReverb) == 0x8E ? 1 : -1];
typedef char SoundRequestVoice_studio_offset[offsetof(SoundRequestVoice, studio) == 0x94 ? 1 : -1];
typedef char SoundRequestVoice_reverb_offset[offsetof(SoundRequestVoice, reverb) == 0x9C ? 1 : -1];
typedef char SoundRequestOwner_reverb_offset[offsetof(SoundRequestOwner, reverb) == 0x27C ? 1 : -1];

void send_sound_request_reverb(SoundRequestVoice* voice);
#endif
