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
// Nonzero while a lobby music request is pending (SoundRequests.cpp).
extern int lbl_805D62B8;

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

#endif
