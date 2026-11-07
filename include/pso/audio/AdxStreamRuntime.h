#ifndef PSO_AUDIO_ADXSTREAMRUNTIME_H
#define PSO_AUDIO_ADXSTREAMRUNTIME_H

#include "types.h"

struct AdxStreamFile;

// One ADX stream player slot (adx_stream_player_pool).
typedef struct Ent_803C9608 {
    char state;
    u8 pad[0xA7];
} Ent_803C9608;

extern "C" {
AdxStreamFile *TLobby__sub_803C8BAC(const char *name, s32 arg);
void TLobby__sub_803C5D00(u8 *arg0);
void TLobby__sub_803C5D24(u8 *arg0);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C8514(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2);
s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1);
void TLobby__sub_803C89C4(u8 *arg0);
short TLobby__sub_803C8B2C(u8 *arg0);
void TLobby__sub_803C8B38(u8 *arg0);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94B8(void);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803C9DB4(u8 *arg0);
void TLobby__sub_803CB194(u8 *arg0);
void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
void TLobby__sub_803CB74C(s32 *arg0);
void TLobby__sub_803CB7F8(s32 arg0, s32 arg1);
void TLobby__sub_803CB81C(void);
s32 TLobby__sub_803CB844(void);
void TLobby__sub_803CBA18(void);
void TLobby__sub_803CBA38(void);
void TLobby__sub_803CBB14(void);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
}
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2);
extern "C" {
void inl_803C9608(void);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
}
void stop_audio_stream(u8 *arg0);
void update_active_stream_reads(void);

// --- C functions defined in AdxStreamRuntime.cpp ---
extern "C" {
void TLobby__sub_803C5D00(u8 *arg0);
void TLobby__sub_803C5D24(u8 *lobby);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C8514(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2);
s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1);
void TLobby__sub_803C89C4(u8 *arg0);
short TLobby__sub_803C8B2C(u8 *arg0);
void TLobby__sub_803C8B38(u8 *arg0);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94B8(void);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803C9DB4(u8 *arg0);
void TLobby__sub_803CB194(u8 *arg0);
void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
void TLobby__sub_803CB74C(s32 *arg0);
void TLobby__sub_803CB7F8(s32 arg0, s32 arg1);
void TLobby__sub_803CB81C(void);
s32 TLobby__sub_803CB844(void);
void TLobby__sub_803CBA18(void);
void TLobby__sub_803CBA38(void);
void TLobby__sub_803CBB14(void);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
void inl_803C9608(void);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
}
// --- end of C functions

#endif
