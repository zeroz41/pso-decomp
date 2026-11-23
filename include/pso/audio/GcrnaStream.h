#ifndef PSO_AUDIO_GCRNA_STREAM_H
#define PSO_AUDIO_GCRNA_STREAM_H

#include "pso/audio/SjRingBuffer.h"
#include "pso/audio/GcrnaError.h"

struct GcrnaStream {
    u8 in_use;
    s8 callback_phase;
    u8 unknown02[2];
    u32 samples_ready;
    u32 flags;
    s32 allocated_channels;
    s32 stream_count;
    s32 frequency;
    s32 sample_bits;
    u32 buffer_size;
    u8* buffers[2];
    SjRingBuffer* ring_buffers[2];
    SjRingBuffer* input_buffers[2];
    u32 callback_ids[2];
    u32 stream_ids[2];
    s32 stream_started[2];
    u8 unknown50[4];
    u32 silence_samples;
    s32 pan[2];
    s32 volume;
    s32 output_volume;
    s32 aux_a_send;
    s32 aux_b_send;
    s32 surround_pan;
    s32 frequency_mode;
    u8 unknown78[8];
};

#include <stddef.h>
LAYOUT_ASSERT(GcrnaStream_size, sizeof(GcrnaStream) == 0x80);
LAYOUT_ASSERT(GcrnaStream_flags_offset, offsetof(GcrnaStream, flags) == 0x08);
LAYOUT_ASSERT(GcrnaStream_channels_offset, offsetof(GcrnaStream, allocated_channels) == 0x0C);
LAYOUT_ASSERT(GcrnaStream_rings_offset, offsetof(GcrnaStream, ring_buffers) == 0x28);
LAYOUT_ASSERT(GcrnaStream_ids_offset, offsetof(GcrnaStream, stream_ids) == 0x40);
LAYOUT_ASSERT(GcrnaStream_silence_offset, offsetof(GcrnaStream, silence_samples) == 0x54);

extern "C" {
void GCRNA_SetPlaySw(GcrnaStream* stream, s32 enabled);
u32 gcrna_stream_callback(void* buffer1, u32 length1, void* buffer2, u32 length2, u32 user);
void GCRNA_SetTransSw(GcrnaStream* stream, s32 enabled);
void gcrna_destroy_stream(GcrnaStream* stream);
GcrnaStream* GCRNA_Create(SjRingBuffer** inputs, s32 channels);
void gcrna_shutdown(void);
void gcrna_initialize(void);
void gcrna_set_error_callback(GcrnaErrorCallback callback, void* context);
void gcrna_set_audio_buffer_storage(u8* buffer, u32 size, s32 count);
}

extern "C" {
u32 gcrna_get_stream_id(GcrnaStream *stream, s32 channel);
void set_stream_channel_pan(GcrnaStream *stream, s32 channel, s32 pan);
void set_stream_frequency(GcrnaStream *stream, s32 frequency);
void update_active_streams(void);
void update_stream_buffers(GcrnaStream *stream);
}

// --- C functions defined in GcrnaStream.cpp ---
extern "C" {
GcrnaStream *GCRNA_Create(SjRingBuffer * *inputs, s32 channels);
void GCRNA_SetPlaySw(GcrnaStream *stream, s32 enabled);
void GCRNA_SetTransSw(GcrnaStream *stream, s32 enabled);
void gcrna_destroy_stream(GcrnaStream *stream);
void gcrna_initialize(void);
void gcrna_set_audio_buffer_storage(u8 *buffer, u32 size, s32 count);
void gcrna_shutdown(void);
u32 gcrna_stream_callback(void *buffer1, u32 length1, void *buffer2, u32 length2, u32 user);
}
// --- end of C functions

#endif
