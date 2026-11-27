#ifndef PSO_AUDIO_SOUNDCONTROLSTATE_H
#define PSO_AUDIO_SOUNDCONTROLSTATE_H

struct AdxfHandle;
struct AdxtPlayer;
struct Vec;

#include "types.h"
#include "musyx/musyx.h"
#include "pso/audio/SoundReverb.h"
#include <stddef.h>

// One sound group's bank files, as sndPushGroup takes them.
struct SoundBankGroup {
    void *file_data[4];
    s32 file_index[4];
    s32 pad20;
};

// The sound control object (sound_control_state, set up by init_sound_aux_effects).
// SoundControlState: name inferred from the global sound_control_state; no symbol or string names it.
class SoundControlState {
public:
    SoundControlState();
    ~SoundControlState();
    void set_output_mode(s32 mode);
    // Clamps the mix to 0..0x7F and sets the stream mix; surround only in output mode 2.
    void set_stream_mix(AdxtPlayer *tracks, s32 vol, s32 pan, s32 span, s32 fxvol);
    s32 is_ready();
    s32 get_ms();
    // Steps the sound random generator (x * 0x10DCD + 1) and returns it.
    s32 advance_rng();
    f32 get_surround_scale();
    s32 get_voice_volume_adjustment();
    void set_voice_volume_adjustment(s32 adjustment);
    // Clamps to 0..1.
    void set_reverb_level(f32 level);
    s32 reset_sound_state();
    // Pops the pushed sound groups and frees their buffers: all of them when pop_all is set,
    // otherwise down to the four resident banks.
    s32 pop_sound_groups(s32 pop_all);
    s32 validate_and_set_selection(s32 bank);
    // Steps the pending bank route: loads the next group's bank files, then marks the state ready.
    void update_sound_bank_load();
    // Frees bank id's buffers and starts reading its four AFS files; 0, or 2/3 when an open or
    // allocation fails.
    s32 start_sound_bank_load(int id);
    int sound_retrace_stub();
    s32 update_sound_frame();
    s32 init_sound_aux_effects();

    SoundReverb reverb;
    SND_AUX_CHORUS chorus;
    f32 reverb_level;
    s32 voice_volume_adjustment;
    s32 age;
    s32 group_state;
    u8 pad_28C[0x290 - 0x28C];
    s32 f290;
    s32 f294;
    s32 load_state;
    s32 next_group_state;
    s32 output_mode;              // 0, 1 or 2: what set_output_mode gave sndOutputMode
    f32 surround_scale;           // weight of the surround term of a voice's spatial mix
    s32 f2A8;
    s32 rng_seed;
    s32 route_pos;
    s16 *route;
    s32 depth;
    s32 stack[17]; /* pushed group ids, stack[1..depth] */
    s32 tick;
    u32 elapsed;
    u32 ms;
    u8 pad_30C[4];
    SoundBankGroup ents[(0xC14 - 0x310) / 0x24];
    u8 padC10[4];
    AdxfHandle *bank_file_handles[4];
    s32 bank_file_sizes[4];
    u8 pad_C34[0xC3C - 0xC34];
};

LAYOUT_ASSERT(SoundControlState_reverb_level_offset, offsetof(SoundControlState, reverb_level) == 0x27C);
LAYOUT_ASSERT(SoundControlState_voice_volume_adjustment_offset, offsetof(SoundControlState, voice_volume_adjustment) == 0x280);

LAYOUT_ASSERT(SoundControlState_ms_offset, offsetof(SoundControlState, ms) == 0x308);

extern SoundControlState sound_control_state;

void set_sound_voice_position(s32 slot, const Vec *position);
s32 get_sound_voice_state(s32 voice);
// Keeps a looping voice alive for five more updates.
void sound_request_voice_set_refresh(struct SoundRequestVoice *voice);
// Sends the voice's pitch to the sound driver when it changed.
void sound_request_voice_update_pitch(struct SoundRequestVoice *v);
void reset_com_card_list_callback(void);
s32 resolve_sound_effect_bank(SoundControlState *owner, s32 kind, s32 bank, s32 index);
s32 start_voice_fade(SoundRequestVoice *v, s32 step);
void fade_out_sound_slot(s32 slot, s32 step);
s32 alloc_looping_sound_slot(u32 id, const void *actor, const Vec *position, s32 base, s32 flags);
s32 alloc_one_shot_sound_slot(u32 id, const Vec *position, s32 base, s32 flags);
void reset_sound_group_fade();
void fade_voice_channels(s32 step);
void set_sound_slot_pitch(s32 slot, s32 pitch, s32 duration);
void set_sound_slot_special_scale(s32 slot, f32 scale);
u16 update_crc16_ccitt(u16 crc, u8 c);

s32 set_voice_pitch_slide(struct SoundRequestVoice *voice, s32 target, s32 duration);
s32 tick_sound_voice(struct SoundRequestVoice *v);



typedef struct ResolveSoundEffectBankRange {
    s32 start;
    s32 end;
} ResolveSoundEffectBankRange;


#endif
