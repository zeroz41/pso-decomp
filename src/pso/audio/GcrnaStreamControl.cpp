#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/GcrnaControlBridge.h"
#include "pso/audio/GcrnaStream.h"
#include "types.h"
#include "pso/audio/GcrnaStatusBridge.h"
#include "pso/audio/GcrnaChannelBridge.h"
#include <string.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/audio/GcrnaBufferQuery.h"

void gcrna_interrupt_lock_leave(void) {
    middleware_interrupt_lock_leave();
}

void gcrna_interrupt_lock_enter(void) {
    middleware_interrupt_lock_enter();
}

void gcrna_set_loop_flag(GcrnaStream *stream, s32 enabled) {
    if (stream != NULL) {
        stream->frequency_mode = enabled;
    }
}

extern "C" {
u32 gcrna_get_stream_id(GcrnaStream *stream, s32 channel) {
    return stream->stream_ids[channel];
}

}

s32 gcrna_bridge_is_ready(void) {
    return 0;
}

s32 gcrna_bridge_get_status(void) {
    return 0;
}

void gcrna_set_sample_bits(GcrnaStream *stream, s32 sample_bits) {
    if (stream != NULL) {
        stream->sample_bits = sample_bits;
    }
}

extern "C" {
void sndStreamMixParameterEx(u32 stream_id, u8 volume, u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b);
void sndStreamFrq(u32 stream_id, s32 frequency);
extern u8 gcrna_volume_table[1000];
extern u32 gcrna_pan_table[31];

inline s32 gcrna_get_play_switch(GcrnaStream *stream) {
    if (stream == 0) {
        return -1;
    }
    return (stream->flags >> 1) & 1;
}

void set_stream_channel_pan(GcrnaStream *stream, s32 channel, s32 pan) {
    if (stream == 0) {
        return;
    }
    pan = (pan < 15) ? pan : 15;
    pan = (pan > -15) ? pan : -15;
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

void set_sound_stream_volume(GcrnaStream *stream, s32 volume) {
    s32 channel;
    if (stream == 0) {
        return;
    }
    volume = (volume < 0) ? volume : 0;
    volume = (volume > -999) ? volume : -999;
    if (volume == stream->volume) {
        return;
    }
    stream->volume = volume;
    stream->output_volume = stream->volume;
    if (gcrna_get_play_switch(stream) != 1) {
        return;
    }
    for (channel = 0; channel < stream->stream_count; channel++) {
        sndStreamMixParameterEx(stream->stream_ids[channel], gcrna_volume_table[-stream->output_volume],
                                gcrna_pan_table[stream->pan[channel] + 15], 127 - stream->surround_pan,
                                (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                                (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
    }
}

void set_stream_frequency(GcrnaStream *stream, s32 frequency) {
    s32 channel;
    if (stream == 0) {
        return;
    }
    stream->frequency = frequency;
    for (channel = 0; channel < stream->allocated_channels; channel++) {
        if (stream->frequency_mode == 1) {
            sndStreamFrq(stream->stream_ids[channel], (stream->frequency * 1124 + 1124) / 1125);
        } else {
            sndStreamFrq(stream->stream_ids[channel], stream->frequency);
        }
    }
}

}

void TLobby__sub_803D4704(GcrnaStream *stream, s32 stream_count) {
    if (stream != NULL) {
        stream->stream_count = stream_count;
    }
}

extern "C" {
void sndStreamARAMUpdate(u32 stream_id, u32 offset1, u32 samples1, u32 offset2, u32 samples2);
extern GcrnaStream gcrna_stream_pool[16];

inline s32 gcrna_get_transfer_switch(GcrnaStream *stream) {
    if (stream == NULL) {
        return -1;
    }
    return stream->flags & 1;
}

inline void gcrna_transfer_input(GcrnaStream *stream) {
    SjChunk data;
    SjChunk free_chunk;
    SjChunk head;
    SjChunk tail;
    for (s32 i = 0; i < stream->stream_count; i++) {
        stream->ring_buffers[i]->interface->get_chunk(stream->ring_buffers[i], 0, 0x2000, &free_chunk);
        stream->input_buffers[i]->interface->get_chunk(stream->input_buffers[i], 1, free_chunk.size, &data);
        memcpy(free_chunk.data, data.data, data.size);
        TLobby__sub_803D3130(&data, data.size, &head, &tail);
        stream->input_buffers[i]->interface->put_chunk(stream->input_buffers[i], 0, &head);
        stream->input_buffers[i]->interface->unget_chunk(stream->input_buffers[i], 1, &tail);
        TLobby__sub_803D3130(&free_chunk, data.size, &head, &tail);
        stream->ring_buffers[i]->interface->put_chunk(stream->ring_buffers[i], 1, &head);
        stream->ring_buffers[i]->interface->unget_chunk(stream->ring_buffers[i], 0, &tail);
        sndStreamARAMUpdate(stream->stream_ids[i], (u32)(free_chunk.data - stream->buffers[i]) >> 1,
                            (u32)data.size >> 1, 0, 0);
    }
}

void update_active_streams(void) {
    u32 i;
    for (i = 0; i < 16; i++) {
        if ((s32)gcrna_stream_pool[i].in_use == 1) {
            update_stream_buffers(&gcrna_stream_pool[i]);
        }
    }
}

void update_stream_buffers(GcrnaStream *stream) {
    SjChunk output;
    SjChunk input;
    s32 i;
    s32 filled;
    if (stream == NULL) {
        return;
    }
    if (gcrna_get_transfer_switch(stream) == 1 && gcrna_get_play_switch(stream) == 0) {
        gcrna_transfer_input(stream);
    }
    if (gcrna_get_play_switch(stream) == 1) {
        if (gcrna_get_transfer_switch(stream) == 1) {
            for (s32 i = 0; i < stream->stream_count; i++) {
                stream->ring_buffers[i]->interface->get_chunk(stream->ring_buffers[i], 0, 0x2000, &input);
                stream->input_buffers[i]->interface->get_chunk(stream->input_buffers[i], 1, input.size, &output);
                memcpy(input.data, output.data, output.size);
                stream->input_buffers[i]->interface->put_chunk(stream->input_buffers[i], 0, &output);
                filled = output.size;
                stream->input_buffers[i]->interface->get_chunk(stream->input_buffers[i], 1, input.size - filled, &output);
                memcpy(input.data + filled, output.data, output.size);
                stream->input_buffers[i]->interface->put_chunk(stream->input_buffers[i], 0, &output);
                filled += output.size;
                memset(input.data + filled, 0, input.size - filled);
                stream->ring_buffers[i]->interface->put_chunk(stream->ring_buffers[i], 1, &input);
                sndStreamARAMUpdate(stream->stream_ids[i], (u32)(input.data - stream->buffers[i]) >> 1,
                                    (u32)input.size >> 1, 0, 0);
            }
        } else if (stream->silence_samples < 0x1000) {
            for (i = 0; i < stream->stream_count; i++) {
                stream->ring_buffers[i]->interface->get_chunk(stream->ring_buffers[i], 0, 0x1000, &input);
                memset(input.data, 0, input.size);
                stream->ring_buffers[i]->interface->put_chunk(stream->ring_buffers[i], 1, &input);
                sndStreamARAMUpdate(stream->stream_ids[i], (u32)(input.data - stream->buffers[i]) >> 1,
                                    (u32)input.size >> 1, 0, 0);
                if (i == 0) {
                    stream->silence_samples += (u32)input.size >> 1;
                }
            }
        }
    }
}

}

static inline s32 gcrna_query_stream_bytes(GcrnaStream *stream, s32 mode) {
    SjRingBuffer *sj = stream->ring_buffers[0];
    return sj->interface->get_available(sj, mode);
}

static inline s32 gcrna_query_is_active(GcrnaStream *stream) {
    if (stream == NULL) {
        return -1;
    }
    return stream->flags & 1;
}

static inline s32 gcrna_query_is_looping(GcrnaStream *stream) {
    if (stream == NULL) {
        return -1;
    }
    return (stream->flags >> 1U) & 1;
}

u32 get_packet_size(GcrnaStream *stream) {
    s32 bytes;

    if (stream == NULL) {
        return -1U;
    }
    bytes = gcrna_query_stream_bytes(stream, 0);
    if (gcrna_query_is_active(stream) == 1) {
        if ((gcrna_query_is_looping(stream) == 0) && (bytes > 0)) {
            bytes = 0x2000;
        }
    }
    return (u32)bytes >> 1U;
}

u32 get_available_size(GcrnaStream *stream) {
    s32 bytes;

    if (stream == NULL) {
        return -1U;
    }
    bytes = gcrna_query_stream_bytes(stream, 1);
    if (gcrna_query_is_active(stream) == 1) {
        if ((gcrna_query_is_looping(stream) == 0) && (bytes < 0x2000)) {
            bytes = 0;
        }
    }
    return (u32)bytes >> 1U;
}
