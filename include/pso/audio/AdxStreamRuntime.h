#ifndef PSO_AUDIO_ADXSTREAMRUNTIME_H
#define PSO_AUDIO_ADXSTREAMRUNTIME_H

#include "pso/audio/AdxStream.h"
#include "types.h"
#include "pso/audio/AdxCallbacks.h"

struct AudioStreamInputState;
struct LscStream;
struct SjRingBuffer;

// One ADX stream player slot (adx_stream_player_pool).
typedef struct AdxStreamPlayer {
    char state;
    s8 stat;
    s8 play_mode;
    u8 pad_3;
    AudioStreamInputState *input_state;
    AdxStreamFile *file;
    saddr fC;
    s32 file_buffer;
    SjRingBuffer *input;
    SjRingBuffer *f18[2]; // one per channel; 2 is inferred (stereo), the code only proves the index
    u8 pad_20[0x3E - 0x20];
    s16 min_sectors;
    u8 pad_40[0x48 - 0x40];
    s32 f48;
    u8 pad_4C[0x60 - 0x4C];
    s16 f60;
    u8 pad_62[0x6C - 0x62];
    s8 loop_flag;
    u8 pad_6D[0x70 - 0x6D];
    s8 f70;
    u8 f71;
    s8 f72;
    u8 pad_73[0x94 - 0x73];
    LscStream *lsc;
    s8 lsc_started;
    u8 pad_99[0x9C - 0x99];
    s32 f9C;
    s32 fA0;
    u8 pad_A4[0xA8 - 0xA4];
} AdxStreamPlayer;
LAYOUT_ASSERT(AdxStreamPlayerSize, sizeof(AdxStreamPlayer) == 0xA8);
LAYOUT_ASSERT(AdxStreamPlayerFileOffset, offsetof(AdxStreamPlayer, file) == 8);

extern "C" {
AdxStreamFile *ADXSTM_OpenFnameEx(const char *name, s32 arg);
AdxStreamFile *adxstm_open_fname_attr(const char *name, s32 mode, s32 arg);
AdxStreamFile *adxstm_open_fname_range__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg);
AdxStreamFile *adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, saddr arg);
void TLobby__sub_803C5D00(AdxStreamPlayer *player);
void TLobby__sub_803C5D24(AdxStreamPlayer *player);
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
void TLobby__sub_803C5D00(AdxStreamPlayer *player);
void TLobby__sub_803C5D24(AdxStreamPlayer *player);
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
