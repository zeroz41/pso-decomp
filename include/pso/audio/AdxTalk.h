#ifndef PSO_AUDIO_ADXTALK_H
#define PSO_AUDIO_ADXTALK_H

#include "pso/audio/AdxCallbacks.h"
#include "types.h"

struct AdxtPlayer;

// --- C functions defined in AdxTalk.cpp ---
extern "C" {
void adxt_set_time_offset(AdxtPlayer *player, s32 offset);
s32 TLobby__sub_803C9358(AdxtPlayer *player);
void adxt_set_error_callback(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void adxt_pause(AdxtPlayer *player, s32 paused);
void adxt_exec_server(void);
void adxt_set_server_freq(AdxtPlayer *player, s32 freq);
s16 adxt_get_out_vol(AdxtPlayer *player);
s32 adxt_get_num_channels(AdxtPlayer *player);
s32 TLobby__sub_803C97B8(AdxtPlayer *player);
void adxt_get_play_position(AdxtPlayer *player, s32 *pos, s32 *rate);
s32 adxt_get_stat(AdxtPlayer *player);
void TLobby__sub_803C9DB4(AdxtPlayer *player);
void adx_destroy_stream_player(AdxtPlayer *player);
AdxtPlayer *adx_create_stream_player(s32 n, void *work, s32 size);
s32 adx_get_data_start_offset(u16 *hdr, s32 size, s32 *out_offset);
void inl_803C9608(void);
}
// --- end of C functions

extern "C" {
void adxt_set_output_mono(s32 mode);
s32 adx_check_packet_header(u16 *p, s32 size, s32 *out);
void adx_talk_set_rate_mode(s32 rate_mode);
}

#endif
