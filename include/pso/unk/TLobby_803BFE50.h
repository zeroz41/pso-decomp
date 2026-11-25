#ifndef PSO_UNK_TLOBBY_803BFE50_H
#define PSO_UNK_TLOBBY_803BFE50_H

#include "types.h"

struct AudioStreamInputState;

extern "C" {
void sub_803C0018(void);
s16 *audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
}

// --- C functions defined in TLobby_803BFE50.cpp ---
extern "C" {
void sub_803C0018(void);
s32 get_stream_loop_end_byte(AudioStreamInputState *st);
s32 get_stream_loop_type(AudioStreamInputState *st);
s32 audio_stream_get_format(AudioStreamInputState *st);
void audio_stream_set_notify_callback(AudioStreamInputState *st, void (*callback)(void *), void *context);
s32 audio_stream_get_output_samples(AudioStreamInputState *st);
void audio_stream_start(AudioStreamInputState *st);
s32 audio_stream_get_state(AudioStreamInputState *st);
void process_audio_stream_input(AudioStreamInputState *st);
s16 *audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
}
// --- end of C functions

// lbl_80570AC0: layout known from its uses only.
struct RecoveredGlobal_lbl_80570AC0 { s32 value; u8 remaining[0x9BC]; };
extern RecoveredGlobal_lbl_80570AC0 lbl_80570AC0;

#endif
