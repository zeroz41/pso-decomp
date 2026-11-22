#ifndef PSO_UNK_TLOBBY_80226070_H
#define PSO_UNK_TLOBBY_80226070_H

#include "types.h"

extern "C" {
void TLobby__sub_8022614C(s32 gain);
int TLobby__sub_80226308(void);
void TLobby__sub_8022644C(void);
void TTecRaFoie__sub_80226254(void);
void stop_sound_request(s32 idx);
void set_sound_pitch_request(s32 slot, s32 pitch, s32 duration);
void update_music_stream_gain(s32 user);
}

#endif
