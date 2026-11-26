#ifndef PSO_AUDIO_AUDIOSTREAMINPUT_H
#define PSO_AUDIO_AUDIOSTREAMINPUT_H

#include "pso/audio/SjRingBuffer.h"

struct AdxbDecoder;

// Names inferred from the decode step (decode_audio_stream_step) and the setup in alloc_audio_stream_state.
struct AudioStreamInputState {
    s8 in_use;
    s8 state;
    u8 channels;
    char stop_when_drained;
    AdxbDecoder *decoder;
    SjRingBuffer *source;
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
    u8 *get_offset_58();
    s32 send_packet_by_id();
    s32 notify_field_4_alt();
    s32 send_packet_by_id_2();
    s32 send_with_offset4();
    s32 notify_field_4();
    void reset_flag();
    void set_network_result(s32 result);
    void set_param_and_notify(SjRingBuffer *sj);
    void reset_entry();
};

extern "C" {
AudioStreamInputState *alloc_audio_stream_state(SjRingBuffer *source, s32 channels, SjRingBuffer **rings);
void sub_803C0018(void);
s32 get_stream_loop_end_byte(AudioStreamInputState *st);
s32 get_stream_loop_type(AudioStreamInputState *st);
s32 audio_stream_get_format(AudioStreamInputState *st);
void audio_stream_set_notify_callback(AudioStreamInputState *st, void (*callback)(void *), void *context);
s32 audio_stream_get_output_samples(AudioStreamInputState *st);
void audio_stream_start(AudioStreamInputState *st);
s32 audio_stream_get_state(AudioStreamInputState *st);
void process_audio_stream_input(AudioStreamInputState *st);
s16 *audio_stream_get_write_window(void *state_ptr, s32 *out_offset, s32 *out_available, s32 *out_remaining);
}

// audio_stream_input_pool: layout known from its uses only.
struct AudioStreamInputPool { s32 value; u8 remaining[0x9BC]; };
extern AudioStreamInputPool audio_stream_input_pool;

#endif
