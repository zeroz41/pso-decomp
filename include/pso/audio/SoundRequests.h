#ifndef PSO_AUDIO_SOUNDREQUESTS_H
#define PSO_AUDIO_SOUNDREQUESTS_H

#include "types.h"
#include "dolphin/mtx.h"

void set_cue_stream_user_gain(s32 gain);
int init_sound_output_mode(void);
void reset_sound_pitch_requests(void);
void cleanup_city_area_stub(void);
void stop_sound_request(s32 idx);
void set_sound_pitch_request(s32 slot, s32 pitch, s32 duration);
void update_music_stream_gain(s32 user);
// While set, every music fade update drops the music gain to -999 (silent).
extern int music_muted;
extern s32 music_stream_base_gain;

struct SetSoundPitchRequestSndEnt {
    s32 flags;
    s32 id;
    const Vec *src;
    Vec pos;
    s16 timer; // frames left: 0x96 when played, 5 to fade out; the same id is not replayed while >= 0x94
    s16 volume;
    const void *actor;
    u8 pad[8];
};

void close_option_window();
int get_music_user_gain();
void set_sound_output_mode(s32 mode);
void update_lobby_subsystems();
void set_and_notify(int a0);
void init_layout_positions();
void reset_global();
int init_sound_mode();

// The flag bits a sound pitch request keeps when it is cleared (bit 0)
extern const u32 sound_pitch_request_keep_mask;
void clear_sound_listener_position(void);
int enable_sound_requests(s32);
void update_sound_request_slots(void);

void play_effect_if_v2(s32 pitch);

#endif
