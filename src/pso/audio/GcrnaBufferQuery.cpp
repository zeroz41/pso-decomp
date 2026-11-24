#include "types.h"
#include "pso/audio/GcrnaBufferQuery.h"

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
