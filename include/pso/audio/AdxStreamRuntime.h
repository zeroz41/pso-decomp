#ifndef PSO_AUDIO_ADXSTREAMRUNTIME_H
#define PSO_AUDIO_ADXSTREAMRUNTIME_H

#include "pso/audio/AdxStream.h"
#include "types.h"
#include "pso/audio/AdxCallbacks.h"

struct AudioStreamInputState;
struct LscStream;
struct SjRingBuffer;

struct AdxtPlayer;
struct AdxDecoderChannel;

extern "C" {
AdxStreamFile *ADXSTM_OpenFnameEx(const char *name, s32 arg);
AdxStreamFile *adxstm_open_fname_attr(const char *name, s32 mode, s32 arg);
AdxStreamFile *ADXSTM_OpenFnameRange(const char *name, s32 mode, s32 off, s32 nsect, s32 arg);
AdxStreamFile *ADXSTM_OpenFnameRangeExRt(const char *name, s32 mode, s32 off, s32 nsect, saddr arg);
s32 TLobby__sub_803C5D00(AdxtPlayer *player);
void TLobby__sub_803C5D24(AdxtPlayer *player);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C9350(AdxtPlayer *player, s32 offset);
s32 TLobby__sub_803C9358(AdxtPlayer *player);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(AdxtPlayer *player, s32 paused);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(AdxtPlayer *player, s32 freq);
s16 TLobby__sub_803C96B0(AdxtPlayer *player);
s32 TLobby__sub_803C9740(AdxtPlayer *player);
s32 TLobby__sub_803C97B8(AdxtPlayer *player);
s32 TLobby__sub_803C9CB0(AdxtPlayer *player);
void TLobby__sub_803C9DB4(AdxtPlayer *player);
void TLobby__sub_803CB194(void *context);
void TLobby__sub_803CB4A4(AdxDecoderChannel *channel);
void TLobby__sub_803CB570(AdxDecoderChannel *channel, u8 *header, s16 *out_coefs);
void setup_adx_file_systems(s32 *arg0);
void fs_error_notify(s32 context, const char *message, void *detail);
void exec_adx_server(void);
s32 is_adxm_initialized(void);
void adxm_set_error_callback(AdxMessageCallback callback, s32 context);
void exec_vsync_servers(void);
void vblank_thread_loop(void);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
}
void ADXT_EntryAfs(AdxtPlayer *player, s32 partition_id, s32 file_id);
extern "C" {
void inl_803C9608(void);
}
void update_active_stream_reads(void);

// --- C functions of the ADX stream, talk and manager files (AdxStream.cpp to AdxManager.cpp) ---
extern "C" {
s32 TLobby__sub_803C5D00(AdxtPlayer *player);
void TLobby__sub_803C5D24(AdxtPlayer *player);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
void TLobby__sub_803C9350(AdxtPlayer *player, s32 offset);
s32 TLobby__sub_803C9358(AdxtPlayer *player);
void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C94DC(AdxtPlayer *player, s32 paused);
void TLobby__sub_803C9608(void);
void TLobby__sub_803C96A8(AdxtPlayer *player, s32 freq);
s16 TLobby__sub_803C96B0(AdxtPlayer *player);
s32 TLobby__sub_803C9740(AdxtPlayer *player);
s32 TLobby__sub_803C97B8(AdxtPlayer *player);
s32 TLobby__sub_803C9CB0(AdxtPlayer *player);
void TLobby__sub_803C9DB4(AdxtPlayer *player);
void TLobby__sub_803CB194(void *context);
void TLobby__sub_803CB4A4(AdxDecoderChannel *channel);
void TLobby__sub_803CB570(AdxDecoderChannel *channel, u8 *header, s16 *out_coefs);
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
