#ifndef PSO_AUDIO_ADXSTREAM_H
#define PSO_AUDIO_ADXSTREAM_H

#include "types.h"

// --- C functions defined in AdxStream.cpp ---
extern "C" {
void TLobby__sub_803C8514(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2);
s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1);
void TLobby__sub_803C89C4(u8 *arg0);
s32 TLobby__sub_803C8B2C(u8 *arg0);
void TLobby__sub_803C8B38(u8 *arg0);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
}
// --- end of C functions

// adx_stream_read_requests: layout known from its uses only.
struct AdxStreamReadRequests { s32 value; u8 remaining[0x9FC]; };
extern AdxStreamReadRequests adx_stream_read_requests;

#endif
