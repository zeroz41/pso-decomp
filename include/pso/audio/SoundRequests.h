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
int get_lobby_data();
void set_sound_output_mode(s32 mode);
void update_lobby_subsystems();
void set_and_notify(int a0);
void init_layout_positions();
void reset_global();
int init_sound_mode();

// sound-request flag mask, defined in SoundRequests.cpp and read from memory there
extern const u32 lbl_805DC748;
void clear_sound_listener_position(void);
int enable_sound_requests(s32);
void turn_on_bgm_p2(void);
void turn_off_bgm_p2(void);
// Plays an ADX file on the cue stream.
void play_cue_stream_file(const char *name);
void set_cue_stream_gain(s32 gain);
void init_music_sequencer(s32 program);
void set_dark_falz_music_request(s32 request);
void set_music_streams_volume(s32 total);
void stop_cue_stream(void);
void update_music_sequencer(void);
void update_sound_request_slots(void);

#endif
