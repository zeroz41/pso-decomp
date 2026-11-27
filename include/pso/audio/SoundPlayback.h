#ifndef PSO_AUDIO_SOUNDPLAYBACK_H
#define PSO_AUDIO_SOUNDPLAYBACK_H

#include "types.h"
#include "pso/system/SoundEffect.h"

struct Vec;
struct AdxtPlayer;

// --- C functions defined in SoundPlayback.cpp ---
void update_voice_stream_mix(AdxtPlayer *tracks);
void set_sound_request_position(s32 slot, const Vec *position);
void fade_all_voice_channels(void);
void run_sound_retrace(void);
void reset_sound_control_state(void);
void set_sound_reverb_level(f32 level);
s32 get_sound_voice_volume_adjustment(void);
int get_music_base_gain(void);
void is_sound_enabled(void);
s32 is_special_sound_id(u32 x);
extern "C" {
void load_floor_sound_bank(s32 floor);
}
s32 normalize_sound_request(u32 id, const void *actor, const Vec *position, s32 offset, s32 options);
s32 play_packed_sound_once(u32 id, const Vec *position, s32 offset, s32 options);
void release_sound_with_fade(s32 slot);
void update_global_sound_frame(void);
void wait_for_sound_init();
void refresh_render_state();
void set_menu_index_main(s32 index);
s32 is_camera_state_active();
// --- end of C functions

// Output mode 0 mono, 1 stereo, 2 surround: sets the ADX mono flag and the sound state's mode.
void apply_sound_output_mode(s32 mode);

#endif
