#ifndef PSO_AUDIO_ADXTALK_H
#define PSO_AUDIO_ADXTALK_H

#include "pso/audio/AdxCallbacks.h"
#include "types.h"

// --- C functions defined in AdxTalk.cpp ---
extern "C" {
void TLobby__sub_803C9350(u8 *player_buf, s32 offset);
s32 TLobby__sub_803C9358(u8 *player_buf);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(u8 *player_buf, s32 paused);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(u8 *player_buf, s32 freq);
s16 TLobby__sub_803C96B0(u8 *player_buf);
s32 TLobby__sub_803C9740(u8 *player_buf);
s32 TLobby__sub_803C97B8(u8 *player_buf);
void TLobby__sub_803C97F4(u8 *player_buf, s32 *pos, s32 *rate);
s8 TLobby__sub_803C9CB0(u8 *player_buf);
void TLobby__sub_803C9DB4(u8 *player_buf);
s32 adx_get_data_start_offset(u16 *hdr, s32 size, s32 *out_offset);
void inl_803C9608(void);
}
// --- end of C functions

#endif
