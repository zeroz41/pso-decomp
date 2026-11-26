#ifndef PSO_AUDIO_SOUNDREQUESTS_H
#define PSO_AUDIO_SOUNDREQUESTS_H

#include "types.h"

void set_cue_stream_user_gain(s32 gain);
int init_lobby_sound_mode(void);
void reset_sound_pitch_requests(void);
void TTecRaFoie__sub_80226254(void);
void stop_sound_request(s32 idx);
void set_sound_pitch_request(s32 slot, s32 pitch, s32 duration);
void update_music_stream_gain(s32 user);
// Nonzero while a lobby music request is pending (SoundRequests.cpp).
extern int lbl_805D62B8;

#endif
