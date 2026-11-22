#ifndef PSO_UNK_TLOBBY_803BFE50_H
#define PSO_UNK_TLOBBY_803BFE50_H

#include "types.h"

extern "C" {
void sub_803C0018(void);
void TLobby__sub_803BFE58(u8 *arg0);
void TLobby__sub_803BFEE8(u8 *arg0);
void audio_stream_get_format(u8 *arg0);
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, s32 arg2);
s32 audio_stream_get_output_samples(u8 *lobby);
void audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
void audio_stream_start(u8 *lobby);
void decode_adxb_pcm_stream(u8 *lobby);
}

// --- C functions defined in TLobby_803BFE50.cpp ---
extern "C" {
void sub_803C0018(void);
void TLobby__sub_803BFE58(u8 *arg0);
void TLobby__sub_803BFEE8(u8 *arg0);
void audio_stream_get_format(u8 *arg0);
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, s32 arg2);
s32 audio_stream_get_output_samples(u8 *lobby);
void audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
void audio_stream_start(u8 *lobby);
void decode_adxb_pcm_stream(u8 *lobby);
}
// --- end of C functions

// lbl_80570AC0: layout known from its uses only.
struct RecoveredGlobal_lbl_80570AC0 { s32 value; u8 remaining[0x9BC]; };
extern RecoveredGlobal_lbl_80570AC0 lbl_80570AC0;

#endif
