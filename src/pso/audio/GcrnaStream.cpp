#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaError.h"
#include <dolphin/os/OSAlloc.h>
#include "pso/misc/TLobby_803D43C8.h"

#define OS_CORE_CLOCK (*(u32 *)0x800000FC)

#pragma readonly_strings on

extern "C" {
void sndStreamMixParameterEx(u32 stream_id, u8 volume, u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b);
u32 sndStreamActivate(u32 stream_id);
void sndStreamDeactivate(u32 stream_id);
void sndStreamFree(u32 stream_id);
void sndStreamFrq(u32 stream_id, s32 frequency);
struct SND_ADPCMSTREAM_INFO;
u32 sndStreamAllocEx(u8 priority, void *buffer, u32 samples, u32 frequency, u8 volume,
                     u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b, u8 studio, u32 flags,
                     u32 (*callback)(void *, u32, void *, u32, u32), u32 user,
                     SND_ADPCMSTREAM_INFO *adpcm_info);
void DCFlushRange(void *buffer, u32 size);
void *memset(void *, int, unsigned long);
}

extern u8 gcrna_volume_table[1000];
extern u32 gcrna_pan_table[31];
extern GcrnaStream gcrna_stream_pool[16];
extern u8 *gcrna_audio_buffers[32];
extern u32 gcrna_init_count;
extern u32 gcrna_audio_buffer_count;
extern u32 lbl_805D7688;
extern u8 *gcrna_audio_allocation;
extern s32 gcrna_uses_caller_buffer;
extern u32 gcrna_aligned_audio_storage;
extern s32 lbl_805D7694;

extern "C" const char *const volatile gcrna_version_pointer = "\nGCRNA Ver.0.97 Build:Jun 13 2002 19:01:27\n";

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 gcrna_get_play_switch(GcrnaStream *stream) {
    if (stream == 0) {
        return -1;
    }
    return (stream->flags >> 1) & 1;
}

inline s32 gcrna_is_playback_settled(GcrnaStream *stream) {
    s32 settled = 0;
    if (gcrna_get_play_switch(stream) == 0) {
        settled = 1;
    } else if (stream->stream_count == 1) {
        if (stream->stream_started[0] == 1) {
            settled = 1;
        }
    } else if (stream->stream_started[0] == 1 && stream->stream_started[1] == 1) {
        settled = 1;
    }
    return settled;
}

void GCRNA_SetPlaySw(GcrnaStream *stream, s32 enabled) {
    s32 i;
    if (stream == 0) {
        return;
    }
    if (enabled == gcrna_get_play_switch(stream)) {
        return;
    }
    if (enabled == 1) {
        stream->samples_ready = 0;
        stream->callback_phase = 0;
        for (i = 0; i < stream->stream_count; i++) {
            sndStreamMixParameterEx(stream->stream_ids[i], gcrna_volume_table[-stream->output_volume],
                                    gcrna_pan_table[stream->pan[i] + 15], 127 - stream->surround_pan,
                                    (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                                    (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
        }
        gcrna_interrupt_lock_enter();
        for (i = 0; i < stream->stream_count; i++) {
            if (sndStreamActivate(stream->stream_ids[i]) == 0) {
                gcrna_report_error("E1080502:sndStreamActivate fail.(GCRNA_SetPlaySw)\n");
                return;
            }
            stream->stream_started[i] = 0;
        }
        stream->flags |= 2;
        gcrna_interrupt_lock_leave();
    } else if (enabled == 0) {
        u32 wait;
        for (wait = 0; wait < OS_CORE_CLOCK; wait++) {
            if (gcrna_is_playback_settled(stream) == 1) {
                break;
            }
        }
        gcrna_interrupt_lock_enter();
        for (i = 0; i < stream->stream_count; i++) {
            if (stream->stream_ids[i] != 0xFFFFFFFF) {
                if (stream->stream_started[i] == 1) {
                    sndStreamDeactivate(stream->stream_ids[i]);
                    stream->stream_started[i] = 0;
                } else {
                    gcrna_report_error("E2011101:Illigal timing of STOP.(GCRNA_SetPlaySw)\n");
                }
            }
        }
        for (i = 0; i < stream->allocated_channels; i++) {
            SjRingBuffer *ring = stream->ring_buffers[i];
            ring->interface->reset(ring);
            memset(stream->buffers[i], 0, stream->buffer_size);
        }
        stream->flags &= 1;
        gcrna_interrupt_lock_leave();
    } else {
        gcrna_report_error("E1042603:Illigal prameter 'sw'.(GCRNA_SetPlaySw)\n");
    }
}

u32 gcrna_stream_callback(void *buffer1, u32 length1, void *buffer2, u32 length2, u32 user) {
    s32 index;
    GcrnaStream *stream;
    s32 i;
    gcrna_interrupt_lock_enter();
    index = user & 0x7FFFFFFF;
    stream = &gcrna_stream_pool[index / 2];
    if (stream->callback_phase == 0) {
        for (i = 0; i < stream->stream_count; i++) {
            SjChunk chunk;
            u32 bytes = length1 * 2;
            bytes &= ~0x1F;
            stream->ring_buffers[i]->interface->get_chunk(stream->ring_buffers[i], 1, bytes, &chunk);
            stream->ring_buffers[i]->interface->put_chunk(stream->ring_buffers[i], 0, &chunk);
            stream->samples_ready = (u32)chunk.size >> 1;
        }
        if (stream->stream_count == 2) {
            stream->callback_phase = 1;
        }
    } else {
        stream->callback_phase = 0;
    }
    gcrna_interrupt_lock_leave();
    stream->stream_started[index % 2] = 1;
    return stream->samples_ready;
}

inline s32 gcrna_get_transfer_switch(GcrnaStream *stream) {
    if (stream == 0) {
        return -1;
    }
    return stream->flags & 1;
}

#pragma auto_inline on
void GCRNA_SetTransSw(GcrnaStream *stream, s32 enabled) {
    if (stream == 0) {
        return;
    }
    if (enabled == gcrna_get_transfer_switch(stream)) {
        return;
    }
    if (enabled == 1) {
        for (s32 channel = 0; channel < stream->allocated_channels; ++channel) {
            SjRingBuffer *ring = stream->ring_buffers[channel];
            ring->interface->reset(ring);
        }
        stream->silence_samples = 0;
        stream->flags |= 1;
    } else if (enabled == 0) {
        stream->flags &= 2;
    } else {
        gcrna_report_error("E1042601:Illigal prameter 'sw'.(GCRNA_SetTransSw)\n");
    }
}

inline void gcrna_release_stream_channels(GcrnaStream *stream) {
    for (s32 channel = 0; channel < stream->allocated_channels; ++channel) {
        if (stream->ring_buffers[channel] != 0) {
            stream->ring_buffers[channel]->interface->destroy(stream->ring_buffers[channel]);
        }
    }
    for (s32 channel = 0; channel < stream->allocated_channels; ++channel) {
        if (stream->stream_ids[channel] != 0xFFFFFFFF) {
            sndStreamFree(stream->stream_ids[channel]);
        }
    }
}

void gcrna_destroy_stream(GcrnaStream *stream) {
    if (stream == 0) {
        return;
    }
    GCRNA_SetPlaySw(stream, 0);
    GCRNA_SetTransSw(stream, 0);
    gcrna_release_stream_channels(stream);
    memset(stream, 0, sizeof(*stream));
}

inline s32 gcrna_clamp_upper(s32 value, s32 maximum) {
    return value < maximum ? value : maximum;
}

inline s32 gcrna_get_frequency(GcrnaStream *stream) {
    if (stream == 0) {
        return -1;
    }
    return stream->frequency;
}

inline void gcrna_set_frequency_mode(GcrnaStream *stream, s32 mode) {
    if (stream != 0) {
        stream->frequency_mode = mode;
    }
}

inline void gcrna_set_frequency(GcrnaStream *stream, s32 frequency) {
    if (stream == 0) {
        return;
    }
    stream->frequency = frequency;
    for (s32 channel = 0; channel < stream->allocated_channels; ++channel) {
        if (stream->frequency_mode == 1) {
            sndStreamFrq(stream->stream_ids[channel], (stream->frequency * 1124 + 1124) / 1125);
        } else {
            sndStreamFrq(stream->stream_ids[channel], stream->frequency);
        }
    }
}

inline void gcrna_set_sample_bits(GcrnaStream *stream, s32 bits) {
    if (stream != 0) {
        stream->sample_bits = bits;
    }
}

inline void gcrna_update_mix(GcrnaStream *stream) {
    if (gcrna_get_play_switch(stream) != 1) {
        return;
    }
    for (s32 channel = 0; channel < stream->stream_count; ++channel) {
        sndStreamMixParameterEx(stream->stream_ids[channel], gcrna_volume_table[-stream->output_volume],
                               gcrna_pan_table[stream->pan[channel] + 15], 127 - stream->surround_pan,
                               (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                               (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
    }
}

inline void gcrna_set_volume(GcrnaStream *stream, s32 value) {
    if (stream == 0) {
        return;
    }
    value = gcrna_clamp_upper(value, 0);
    value = value > -999 ? value : -999;
    if (value == stream->volume) {
        return;
    }
    stream->volume = value;
    stream->output_volume = stream->volume;
    gcrna_update_mix(stream);
}

inline void gcrna_set_output_volume(GcrnaStream *stream, s32 value) {
    if (stream == 0) {
        return;
    }
    value = gcrna_clamp_upper(value, 0);
    value = value > -999 ? value : -999;
    if (value == stream->output_volume) {
        return;
    }
    stream->output_volume = value;
    gcrna_update_mix(stream);
}

inline void gcrna_set_surround_pan(GcrnaStream *stream, s32 value) {
    if (stream == 0) {
        return;
    }
    value = gcrna_clamp_upper(value, 127);
    value = value > 0 ? value : 0;
    if (value == stream->surround_pan) {
        return;
    }
    stream->surround_pan = value;
    gcrna_update_mix(stream);
}

inline void gcrna_set_aux_a_send(GcrnaStream *stream, s32 value) {
    if (stream == 0) {
        return;
    }
    value = gcrna_clamp_upper(value, 0);
    value = value > -999 ? value : -999;
    if (value == stream->aux_a_send) {
        return;
    }
    stream->aux_a_send = value;
    gcrna_update_mix(stream);
}

inline void gcrna_set_aux_b_send(GcrnaStream *stream, s32 value) {
    if (stream == 0) {
        return;
    }
    value = gcrna_clamp_upper(value, 0);
    value = value > -999 ? value : -999;
    if (value == stream->aux_b_send) {
        return;
    }
    stream->aux_b_send = value;
    gcrna_update_mix(stream);
}

inline void gcrna_set_channel_pan(GcrnaStream *stream, s32 channel, s32 pan) {
    if (stream == 0) {
        return;
    }
    pan = gcrna_clamp_upper(pan, 15);
    pan = pan > -15 ? pan : -15;
    if (pan == stream->pan[channel]) {
        return;
    }
    stream->pan[channel] = pan;
    if (gcrna_get_play_switch(stream) != 1) {
        return;
    }
    sndStreamMixParameterEx(stream->stream_ids[channel], gcrna_volume_table[-stream->output_volume],
                           gcrna_pan_table[stream->pan[channel] + 15], 127 - stream->surround_pan,
                           (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                           (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
}

GcrnaStream *GCRNA_Create(SjRingBuffer **inputs, s32 channels) {
    if (channels <= 0) {
        return 0;
    }
    if (inputs == 0) {
        return 0;
    }
    for (u32 channel = 0; channel < channels; ++channel) {
        if (inputs[channel] == 0) {
            return 0;
        }
    }
    u32 index;
    for (index = 0; index < 16; ++index) {
        if ((s8)gcrna_stream_pool[index].in_use == 0) {
            break;
        }
    }
    if (index == 16) {
        return 0;
    }
    GcrnaStream *stream = &gcrna_stream_pool[index];
    stream->stream_count = channels;
    stream->allocated_channels = channels;
    stream->stream_ids[0] = 0xFFFFFFFF;
    stream->stream_ids[1] = 0xFFFFFFFF;
    for (u32 channel = 0; channel < stream->allocated_channels; ++channel) {
        stream->input_buffers[channel] = inputs[channel];
    }
    stream->buffer_size = 0x2000;
    for (u32 channel = 0; channel < stream->allocated_channels; ++channel) {
        stream->callback_ids[channel] = (index * 2 + channel) | 0x80000000;
        stream->buffers[channel] = gcrna_audio_buffers[stream->callback_ids[channel] & 0x7FFFFFFF];
        DCFlushRange(stream->buffers[channel], stream->buffer_size);
        SjRingBuffer *ring = sj_ring_buffer_create(stream->buffers[channel], stream->buffer_size, 0);
        stream->ring_buffers[channel] = ring;
        if (ring == 0) {
            gcrna_destroy_stream(stream);
            return 0;
        }
        u8 volume = gcrna_volume_table[-stream->output_volume];
        u8 pan = gcrna_pan_table[stream->pan[channel] + 15];
        u8 surround_pan = 127 - stream->surround_pan;
        u8 aux_a = gcrna_volume_table[-stream->aux_a_send];
        u8 aux_b = gcrna_volume_table[-stream->aux_b_send];
        stream->stream_ids[channel] = sndStreamAllocEx(255, stream->buffers[channel], stream->buffer_size / 2,
            gcrna_get_frequency(stream), volume, pan, surround_pan, aux_a, aux_b,
            0, 0x30000, gcrna_stream_callback, stream->callback_ids[channel], 0);
        if (stream->stream_ids[channel] == 0xFFFFFFFF) {
            gcrna_report_error("E1090501:sndStreamAllocEx return error ID.(GCRNA_Create)\n");
            gcrna_destroy_stream(stream);
            return 0;
        }
    }
    gcrna_set_frequency_mode(stream, lbl_805D7694);
    gcrna_set_frequency(stream, 48000);
    gcrna_set_sample_bits(stream, 16);
    gcrna_set_volume(stream, 0);
    gcrna_set_output_volume(stream, 0);
    if (stream->allocated_channels == 2) {
        gcrna_set_channel_pan(stream, 0, -15);
        gcrna_set_channel_pan(stream, 1, 15);
    } else {
        gcrna_set_channel_pan(stream, 0, 0);
    }
    gcrna_set_surround_pan(stream, 127);
    gcrna_set_aux_a_send(stream, -999);
    gcrna_set_aux_b_send(stream, -999);
    stream->flags = 0;
    stream->in_use = 1;
    return stream;
}

void gcrna_shutdown(void) {
    if (--gcrna_init_count == 0) {
        for (s32 index = 0; index < 16; ++index) {
            if ((s32)gcrna_stream_pool[index].in_use == 1) {
                gcrna_destroy_stream(&gcrna_stream_pool[index]);
            }
        }
        memset(gcrna_stream_pool, 0, sizeof(gcrna_stream_pool));
        gcrna_error_shutdown();
    }
}

inline void gcrna_initialize_buffer_table(void) {
    for (s32 index = 0; index < gcrna_audio_buffer_count; ++index) {
        gcrna_audio_buffers[index] = (u8 *)(gcrna_aligned_audio_storage + index * 0x2000);
    }
}

void gcrna_initialize(void) {
    gcrna_version_pointer;
    if (gcrna_init_count == 0) {
        gcrna_error_initialize();
        if (gcrna_uses_caller_buffer == 0) {
            gcrna_audio_buffer_count = 32;
            lbl_805D7688 = 0x2000;
            gcrna_audio_allocation = (u8 *)OSAlloc(32 * 0x2000 + 32);
        }
        gcrna_aligned_audio_storage = ((u32)gcrna_audio_allocation + 31) & ~31ULL;
        gcrna_initialize_buffer_table();
        memset(gcrna_stream_pool, 0, sizeof(gcrna_stream_pool));
    }
    ++gcrna_init_count;
}
void gcrna_set_error_callback(GcrnaErrorCallback callback, void *context) {
    gcrna_error_set_callback(callback, context);
}

void gcrna_set_audio_buffer_storage(u8 *buffer, u32 size, s32 count) {
    if (buffer == 0) {
        gcrna_report_error("E1070310:Illigal parameter(buf=null).\n");
        return;
    }
    if (size == 0) {
        gcrna_report_error("E1070311:Illigal parameter(bsize<=0).\n");
        return;
    }
    if (size < (u32)(count << 13)) {
        gcrna_report_error("E1070312:Not enough bsize.\n");
        return;
    }
    gcrna_audio_buffer_count = count;
    lbl_805D7688 = size;
    gcrna_audio_allocation = buffer;
    gcrna_uses_caller_buffer = 1;
}
#pragma pop

u8* gcrna_audio_buffers[32];
GcrnaStream gcrna_stream_pool[16];
u8 gcrna_volume_table[1000] = {
    127, 126, 126, 125, 125, 124, 123, 123, 122, 122, 121, 120, 120, 119, 119, 118, 117, 117, 116, 116,
    115, 115, 114, 113, 113, 112, 112, 111, 111, 110, 110, 109, 108, 108, 107, 107, 106, 106, 105, 105,
    104, 104, 103, 103, 102, 102, 101, 101, 100, 100, 99, 99, 98, 98, 97, 97, 96, 96, 95, 95,
    94, 94, 93, 93, 92, 92, 91, 91, 90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85,
    85, 85, 84, 84, 83, 83, 82, 82, 81, 81, 81, 80, 80, 79, 79, 79, 78, 78, 77, 77,
    77, 76, 76, 75, 75, 75, 74, 74, 73, 73, 73, 72, 72, 72, 71, 71, 70, 70, 70, 69,
    69, 69, 68, 68, 67, 67, 67, 66, 66, 66, 65, 65, 65, 64, 64, 64, 63, 63, 63, 62,
    62, 62, 61, 61, 61, 60, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 57, 57, 56, 56,
    56, 55, 55, 55, 54, 54, 54, 54, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 50, 50,
    50, 50, 49, 49, 49, 49, 48, 48, 48, 48, 47, 47, 47, 47, 46, 46, 46, 46, 45, 45,
    45, 45, 44, 44, 44, 44, 43, 43, 43, 43, 42, 42, 42, 42, 41, 41, 41, 41, 41, 40,
    40, 40, 40, 39, 39, 39, 39, 39, 38, 38, 38, 38, 38, 37, 37, 37, 37, 37, 36, 36,
    36, 36, 36, 35, 35, 35, 35, 35, 34, 34, 34, 34, 34, 33, 33, 33, 33, 33, 32, 32,
    32, 32, 32, 32, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 29, 29, 29, 29,
    29, 29, 28, 28, 28, 28, 28, 28, 27, 27, 27, 27, 27, 27, 27, 26, 26, 26, 26, 26,
    26, 26, 25, 25, 25, 25, 25, 25, 25, 24, 24, 24, 24, 24, 24, 24, 24, 23, 23, 23,
    23, 23, 23, 23, 22, 22, 22, 22, 22, 22, 22, 22, 21, 21, 21, 21, 21, 21, 21, 21,
    21, 20, 20, 20, 20, 20, 20, 20, 20, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18,
    18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

u32 gcrna_pan_table[31] = {
    0, 4, 8, 12, 16, 20, 24, 28,
    33, 37, 41, 45, 49, 53, 57, 64,
    68, 72, 76, 81, 85, 89, 93, 98,
    102, 106, 110, 115, 119, 123, 127,
};
