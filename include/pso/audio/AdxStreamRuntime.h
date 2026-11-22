#ifndef PSO_AUDIO_ADXSTREAMRUNTIME_H
#define PSO_AUDIO_ADXSTREAMRUNTIME_H

#include "pso/audio/AdxStream.h"
#include "types.h"
#include "pso/audio/AdxCallbacks.h"

struct LscStream;
struct SjRingBuffer;

// One ADX stream player slot (adx_stream_player_pool).
typedef struct Ent_803C9608 {
    char state;
    s8 stat;
    u8 pad_2[0x4 - 0x2];
    saddr f4;
    AdxStreamFile *f8;
    s32 fC;
    u8 pad_10[0x18 - 0x10];
    SjRingBuffer *f18[2]; // one per channel; 2 is inferred (stereo), the code only proves the index
    u8 pad_20[0x48 - 0x20];
    s32 f48;
    u8 pad_4C[0x60 - 0x4C];
    s16 f60;
    u8 pad_62[0x70 - 0x62];
    s8 f70;
    u8 f71;
    s8 f72;
    u8 pad_73[0x94 - 0x73];
    LscStream *f94;
    u8 pad_98[0x9C - 0x98];
    s32 f9C;
    s32 fA0;
    u8 pad_A4[0xA8 - 0xA4];
} Ent_803C9608;
LAYOUT_ASSERT(AdxStreamPlayerSize, sizeof(Ent_803C9608) == 0xA8);
LAYOUT_ASSERT(AdxStreamPlayerFileOffset, offsetof(Ent_803C9608, f8) == 8);

extern "C" {
AdxStreamFile *ADXSTM_OpenFnameEx(const char *name, s32 arg);
AdxStreamFile *adxstm_open_fname_attr(const char *name, s32 mode, s32 arg);
AdxStreamFile *adxstm_open_fname_range__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg);
AdxStreamFile *adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, saddr arg);
void TLobby__sub_803C5D00(u8 *arg0);
void TLobby__sub_803C5D24(u8 *arg0);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803C9DB4(u8 *arg0);
void TLobby__sub_803CB194(void *context);
void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
void setup_adx_file_systems(s32 *arg0);
void fs_error_notify(s32 context, const char *message, void *detail);
void exec_adx_server(void);
s32 is_adxm_initialized(void);
void adxm_set_error_callback(AdxMessageCallback callback, s32 context);
void exec_vsync_servers(void);
void vblank_thread_loop(void);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
}
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2);
extern "C" {
void inl_803C9608(void);
}
void stop_audio_stream(u8 *arg0);
void update_active_stream_reads(void);

// --- C functions of the ADX stream, talk and manager files (AdxStream.cpp to AdxManager.cpp) ---
extern "C" {
void TLobby__sub_803C5D00(u8 *arg0);
void TLobby__sub_803C5D24(u8 *lobby);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803C9DB4(u8 *arg0);
void TLobby__sub_803CB194(void *context);
void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
void setup_adx_file_systems(s32 *arg0);
void fs_error_notify(s32 context, const char *message, void *detail);
void exec_adx_server(void);
s32 is_adxm_initialized(void);
void adxm_set_error_callback(AdxMessageCallback callback, s32 context);
void exec_vsync_servers(void);
void vblank_thread_loop(void);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
void inl_803C9608(void);
}
// --- end of C functions

#endif
