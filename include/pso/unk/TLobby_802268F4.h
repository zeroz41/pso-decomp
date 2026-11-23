#ifndef PSO_UNK_TLOBBY_802268F4_H
#define PSO_UNK_TLOBBY_802268F4_H

#include "types.h"

// sound-request flag mask, defined in TLobby_80226070.cpp and read from memory there
extern const u32 lbl_805DC748;
extern "C" {
void clear_sound_listener_position(void);
int TLobby__sub_80226B64(void);
void TLobby__sub_802272B4(void);
void TLobby__sub_8022733C(void);
}
// Plays an ADX file on the cue stream.
void play_cue_stream_file(const char *name);
void set_cue_stream_gain(s32 arg0);
void init_music_sequencer(s32 program);
void set_dark_falz_music_request(s32 arg0);
void set_music_streams_volume(s32 total);
void stop_cue_stream(void);
void update_music_sequencer(void);
void update_sound_request_slots(void);

#endif
