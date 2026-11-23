#include "types.h"
#include <string.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {
void sndStreamARAMUpdate(u32 stream_id, u32 offset1, u32 samples1, u32 offset2, u32 samples2);
extern GcrnaStream gcrna_stream_pool[16];

inline s32 gcrna_get_transfer_switch(GcrnaStream *stream) {
    if (stream == NULL) {
        return -1;
    }
    return stream->flags & 1;
}

inline s32 gcrna_get_play_switch(GcrnaStream *stream) {
    if (stream == NULL) {
        return -1;
    }
    return (stream->flags >> 1) & 1;
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
