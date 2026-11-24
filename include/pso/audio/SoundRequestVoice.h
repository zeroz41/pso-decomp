#ifndef PSO_SOUND_REQUEST_VOICE_H
#define PSO_SOUND_REQUEST_VOICE_H
#include "types.h"

struct Vec;

class SoundControlState;

struct SoundRequestVoice {
    SoundRequestVoice();
    ~SoundRequestVoice();

    void set_field0(SoundControlState *owner);
    void clamp_reverb(f32 scale);
    void clamp_params();
    void update();

    SoundControlState *owner;
    s32 state;
    u32 flags;
    s32 kind, bank, index, effect;
    const void *actor;
    u32 token;
    s32 previousVolume, volume, previousPan, pan, previousSurround, surround;
    s32 base, extra, spatial, fade, fadeStep;
    s32 panExtra, panSpatial, surroundExtra, unused5C, surroundSpatial;
    s32 pitch, previousPitch, pitchStatic, pitchMoving, pitchVelocity;
    s32 pitchSlide, pitchTarget, pitchDuration, pitchRemaining;
    const Vec *position;
    s16 pitchLimit;
    u8 previousReverb, unused8F;
    s16 delay, refresh;
    s32 studio, age;
    f32 reverb;
};
#include <stddef.h>
LAYOUT_ASSERT(SoundRequestVoice_size, sizeof(SoundRequestVoice) == 0xA0);
LAYOUT_ASSERT(SoundRequestVoice_actor_offset, offsetof(SoundRequestVoice, actor) == 0x1C);
LAYOUT_ASSERT(SoundRequestVoice_position_offset, offsetof(SoundRequestVoice, position) == 0x88);
LAYOUT_ASSERT(SoundRequestVoice_previousReverb_offset, offsetof(SoundRequestVoice, previousReverb) == 0x8E);
LAYOUT_ASSERT(SoundRequestVoice_studio_offset, offsetof(SoundRequestVoice, studio) == 0x94);
LAYOUT_ASSERT(SoundRequestVoice_reverb_offset, offsetof(SoundRequestVoice, reverb) == 0x9C);

void send_sound_request_reverb(SoundRequestVoice* voice);
#endif
