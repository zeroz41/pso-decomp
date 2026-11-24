#ifndef PSO_AUDIO_AUDIOSTREAMINPUT_H
#define PSO_AUDIO_AUDIOSTREAMINPUT_H

#include "pso/audio/SjRingBuffer.h"

class TLobby;
struct AudioStreamSource;

// Names inferred from the decode step (decode_audio_stream_step) and the setup in alloc_audio_stream_state.
struct AudioStreamInputState {
    s8 in_use;
    s8 state;
    u8 channels;
    char stop_when_drained;
    TLobby *decoder;
    AudioStreamSource *source;
    SjRingBuffer *rings[2];
    SjChunk src_chunk;
    SjChunk out_chunks[2];
    s32 output_samples;
    s32 consumed_bytes;
    s32 decoded_samples;
    s32 max_samples;
    s32 notify_samples;
    s32 notify_count;
    s32 notify_bytes;
    void (*notify_callback)(void *);
    void *notify_context;
    void (*output_callback)(void *, s32, u8 *, s32);
    void *output_context;
    u8 header[0x40];
    s32 header_size;

    s32 get_loop_start_byte();
    s32 get_loop_end_sample();
    s32 get_loop_start_sample();
    void set_notify_bytes(s32 bytes);
    void set_notify_count(s32 samples);
    void set_decoded_samples(s32 samples);
    void set_notify_sample_count(s32 samples);
};

#endif
